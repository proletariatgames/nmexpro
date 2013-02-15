package com.openfeint.internal.offline;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Date;
import java.util.concurrent.atomic.AtomicBoolean;

import android.content.Context;

import com.openfeint.api.Notification;
import com.openfeint.api.OpenFeint;
import com.openfeint.api.resource.Leaderboard;
import com.openfeint.api.resource.Score;
import com.openfeint.internal.Encryption;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.Util;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.notifications.SimpleNotification;
import com.openfeint.internal.request.BaseRequest;
import com.openfeint.internal.request.OrderedArgList;
import com.openfeint.internal.resource.DateResourceProperty;
import com.openfeint.internal.vendor.org.apache.commons.codec.binary.Hex;

public class OfflineSupport {
	private static final String TEMPORARY_USER_ID = "0";
	private static final String TAG = "OfflineSupport";
	
	private static boolean streq(String lhs, String rhs) {
		return (lhs == null) ? (rhs == null) : lhs.equals(rhs);
	}
	
	// I miss C++'s automatic copy constructors and value equality operators :(
	// public only for purposes of testing
	public static class OfflineAchievement {
		public OfflineAchievement dup() {
			OfflineAchievement rv = new OfflineAchievement();
			rv.resourceID = this.resourceID;
			rv.clientCompletionPercentage = this.clientCompletionPercentage;
			rv.serverCompletionPercentage = this.serverCompletionPercentage;
			rv.timestamp = this.timestamp;
			return rv;
		}
		public boolean eq(OfflineAchievement rhs) {
		return
			streq(this.resourceID, rhs.resourceID) &&
			this.clientCompletionPercentage == rhs.clientCompletionPercentage &&
			this.serverCompletionPercentage == rhs.serverCompletionPercentage &&
			streq(this.timestamp, rhs.timestamp);
		}
		public String resourceID;
		public float clientCompletionPercentage;
		public float serverCompletionPercentage;
		public String timestamp;
	}

	// public only for purposes of testing
	public static class OfflineScore {
		public OfflineScore dup() {
	    OfflineScore rv = new OfflineScore();
			rv.leaderboardID = this.leaderboardID;
			rv.score = this.score;
			rv.displayText = this.displayText;
			rv.customData = this.customData;
			rv.blobFileName = this.blobFileName;
			rv.timestamp = this.timestamp;
    	return rv;
		}
		public boolean eq(OfflineScore rhs) {
		return
			streq(this.leaderboardID, rhs.leaderboardID) &&
			this.score == rhs.score &&
			streq(this.displayText, rhs.displayText) &&
			streq(this.customData, rhs.customData) &&
			streq(this.blobFileName, rhs.blobFileName) &&
			streq(this.timestamp, rhs.timestamp);
		}
		public String leaderboardID;
		public long score;
		public String displayText;
		public String customData;
		public String blobFileName;
		public String timestamp;
	}

	// public only for purposes of testing
	public static class DB {
		private static final int STREAM_VERSION = 0;

		public ArrayList<OfflineAchievement> achievements = new ArrayList<OfflineAchievement>();
		public ArrayList<OfflineScore> scores = new ArrayList<OfflineScore>();
		
		// Deep copy this DB for syncing.
		public DB dup() {
			DB rv = new DB();
			for (OfflineScore s : scores) { rv.scores.add(s.dup()); }
			for (OfflineAchievement a : achievements) { rv.achievements.add(a.dup()); }
			return rv;
		}
		
		// Merges another DB into this DB.  The effect is that this DB will now contain
		// 'the best' progress from both DBs.
		public void merge(DB newUserDB) {
			for (OfflineAchievement newUserAchievement : newUserDB.achievements) {
				OfflineAchievement currentUserAchievement = findAchievement(newUserAchievement.resourceID);
				if (currentUserAchievement == null) {
					// If we don't have it, just take it verbatim.
					achievements.add(newUserAchievement.dup());
				} else {
					// Otherwise, take the best client and server completion percentage known.
					if (currentUserAchievement.clientCompletionPercentage < newUserAchievement.clientCompletionPercentage) {
						currentUserAchievement.clientCompletionPercentage = newUserAchievement.clientCompletionPercentage;
						currentUserAchievement.timestamp = newUserAchievement.timestamp;
					}

					currentUserAchievement.serverCompletionPercentage = Math.max
					   (currentUserAchievement.serverCompletionPercentage,
							newUserAchievement.serverCompletionPercentage);
				}
			}
			
			// blob note: this might leave us with two blob scores for the same leaderboard, but
			// since this is only called when we're logging in and online, we'll soon discharge
			// them.  This is better than having to worry about saving blob sort order / deleting
			// blobs on merge / etc.
			scores.addAll(newUserDB.scores);
		}
		
		// Update objects in this DB after otherDB has been uploaded.  The effect is that
		// this DB will now contain only objects that were NOT in the other DB.
		// This means that scores are removed and serverCompletionPercentage is updated.
		// NOTE: this doesn't affect blob scores at all.  Those are handled one at a time.
		public void updateOnUpload(DB otherDB) {
			for (OfflineAchievement otherAchievement : otherDB.achievements) {
				OfflineAchievement myAchievement = findAchievement(otherAchievement.resourceID);
				if (myAchievement == null) {
					// If we don't have it, copy it, and then...
					myAchievement = otherAchievement.dup();
					achievements.add(myAchievement);
				} 

				// ... update the local SERVER completion percentage with the other's CLIENT completion percentage.
				myAchievement.serverCompletionPercentage = Math.max
					(myAchievement.serverCompletionPercentage,
				  otherAchievement.clientCompletionPercentage);
			}

			// now, remove all non-blob scores from local DB that have equivalents in otherDB.
			// we do this by setting scores to an empty array, and adding back in the scores
			// that DON'T have equivalents.
			final ArrayList<OfflineScore> oldScores = scores;
			scores = new ArrayList<OfflineScore>();
			for (OfflineScore myScore : oldScores) {
				// we're only non-blob scores.  which means that we keep all blob scores.
				if (myScore.blobFileName != null) { 
					scores.add(myScore);
					continue;
				}

				// try to find myScore's equivalent in otherDB
				boolean found = false;
				for (OfflineScore otherScore : otherDB.scores) {
					if (myScore.eq(otherScore)) {
						found = true;
						break;
					}
				}

				// If we couldn't find an equivalent, then we keep it.
				if (!found) {
					scores.add(myScore);
				}
			}
		}
		
		public static DB load(String fileName) {
			DB rv = new DB();
			ObjectInputStream ois = null;
			
			if (null != fileName) {
				try {
					InputStream is = Encryption.decryptionWrap(OpenFeintInternal.getInstance().getContext().openFileInput(fileName));
					ois = new ObjectInputStream(is);
					int streamVersion = ois.readInt();
					switch (streamVersion) {
					case 0:
					{
						int numAchievements = ois.readInt();
						for (; 0 < numAchievements; --numAchievements) {
							final OfflineAchievement a   = new OfflineAchievement();
							a.resourceID                 = (String)ois.readObject();
							a.clientCompletionPercentage = ois.readFloat();
							a.serverCompletionPercentage = ois.readFloat();
							a.timestamp                  = (String)ois.readObject();
							rv.achievements.add(a);
						}

						int numScores = ois.readInt();
						for (; 0 < numScores; --numScores) {
							final OfflineScore s   = new OfflineScore();
							s.leaderboardID = (String)ois.readObject();
							s.score         = ois.readLong();
							s.displayText   = (String)ois.readObject();
							s.customData    = (String)ois.readObject();
							s.blobFileName  = (String)ois.readObject();
							s.timestamp     = (String)ois.readObject();
							rv.scores.add(s);
						}
					}
					break;
						
					default:
						throw new Exception (String.format("Unrecognized stream version %d", streamVersion));
					}
				} catch (Exception e) {
					OFLog.e(TAG, "Couldn't load offline achievements - " + e.getMessage());
					rv.achievements.clear();
					rv.scores.clear();
				} finally {
					try { if (ois != null) ois.close(); } catch (IOException e) {}
				}
			}
			
			return rv;
		}
		
		public void save(String fileName) {
			ObjectOutputStream oos = null;
			OutputStream os = null;
			try {
				// @TODO atomic
				// @TODO run on worker thread
				os = Encryption.encryptionWrap(OpenFeintInternal.getInstance().getContext().openFileOutput(fileName, Context.MODE_PRIVATE));
				oos = new ObjectOutputStream(os);
				oos.writeInt(STREAM_VERSION);
				oos.writeInt(achievements.size());
				for (OfflineAchievement a : achievements) {
					oos.writeObject(a.resourceID);
					oos.writeFloat(a.clientCompletionPercentage);
					oos.writeFloat(a.serverCompletionPercentage);
					oos.writeObject(a.timestamp);
				}
				oos.writeInt(scores.size());
				for (OfflineScore s : scores) {
					oos.writeObject(s.leaderboardID);
					oos.writeLong(s.score);
					oos.writeObject(s.displayText);
					oos.writeObject(s.customData);
					oos.writeObject(s.blobFileName);
					oos.writeObject(s.timestamp);
				}
				oos.close();
			} catch (Exception e) {
			} finally {
				try { if (oos != null) oos.close(); } catch (IOException e) {}
				try { if (os != null) os.close(); } catch (IOException e) {}
			}
		}

		public void removeReferencedBlobs() {
			for (OfflineScore os: scores) {
				deleteDataFile(os.blobFileName);
			}
		}
		
		public void clear() {
			achievements.clear();
			scores.clear();
		}
		
		public OfflineAchievement findAchievement(String resourceID) {
			for (OfflineAchievement a : achievements) {
				if (a.resourceID.equals(resourceID)) {
					return a;
				}
			}
			return null;
		}
	}
	
	private static void deleteDataFile(String fileName) {
		try {
			final Context context = OpenFeintInternal.getInstance().getContext();
			context.deleteFile(context.getFileStreamPath(fileName).getPath());
		} catch (Exception e) {
		}
	}
	
	private static String fullPath(String fileName) {
		final Context context = OpenFeintInternal.getInstance().getContext();
		return context.getFileStreamPath(fileName).getPath();
	}
	
	private static DB db = null;
	private static String userID = null;
	private static AtomicBoolean updateInProgress = new AtomicBoolean(false);

	private static String filename(String forUserID) {
		if (null == forUserID) return null;
		final String appID = OpenFeintInternal.getInstance().getAppID();
		if (null == appID) return null;
		return "of.offline." + forUserID + "." + appID;
	}
	
	private static String now() {
		return DateResourceProperty.sDateParser.format(new Date());
	}
	
	public static void setUserDeclined() {
		setUserID(null);
	}
	
	public static void setUserTemporary() {
		setUserID(TEMPORARY_USER_ID);
	}
	
	private static boolean isUserTemporary() {
		return TEMPORARY_USER_ID.equals(userID);
	}
	
	// NB: this doesn't remove the blob files that this DB points to.
	private static void removeDBForUser(String forUserID) {
		deleteDataFile(filename(forUserID));
	}
	
	public static void setUserID(String newUserID) {
		// Short out on no-op.
		if (newUserID != null && newUserID.equals(userID)) return;
		
		DB newUserDB = DB.load(filename(newUserID));

		if (isUserTemporary()) {
			// if we're currently tracking a temporary user, merge with what we've already got.
			db.merge(newUserDB);
			removeDBForUser(TEMPORARY_USER_ID);
		} else {
			// start with a fresh db.
			db = newUserDB;			
		}
		userID = newUserID;
		
		trySubmitOfflineData();
	}

	static public void trySubmitOfflineData() {
		if (userID != null && !userID.equals(TEMPORARY_USER_ID) && OpenFeint.isUserLoggedIn()) {
			updateToServer();
		}
	}

	// mutual recursion <3
	final static void removeAndUploadNext(final OfflineScore os) {
		db.scores.remove(os);
		save();
		uploadScoresWithBlobs();
	}
	
	private static void uploadScoresWithBlobs() {
		for (final OfflineScore os : db.scores) {
			if (os.blobFileName != null) {
				// got one.
				Score s = new Score(os.score);
				s.customData = os.customData;
				s.displayText = os.displayText;
				try {
					s.blob = Util.readWholeFile(fullPath(os.blobFileName));
				} catch (IOException e) {
				}

				if (s.blob == null) {
					// This score is potentially broken without the blob.  We'd best not submit it.
					removeAndUploadNext(os);
				} else {
					s.submitToFromOffline(new Leaderboard(os.leaderboardID), os.timestamp, new Score.SubmitToCB() {
						@Override public void onSuccess(boolean newHighScore) {
							// This worked out!  We can remove it and move on to the next one.
							removeAndUploadNext(os);
						}
						@Override public void onFailure(String failureMessage) {
							// If there's a failure, we're probably offline again.  Wait till next login.
							updateInProgress.set(false);
						}
					});
				}
				
				// That's the one score we're willing to handle this loop.  Return so we don't
				// clear the updateInProgress flag prematurely.
				return;
			}
		}
		
		// If we got here, we're done!
		updateInProgress.set(false);
	}
	
	private synchronized static void updateToServer() {
		if (!updateInProgress.compareAndSet(false, true)) return;
		
		final DB clonedDB = db.dup();
		
		OrderedArgList oal = new OrderedArgList();
    	int currAchievement = 0;
		for (OfflineAchievement oa : clonedDB.achievements) {
			if (oa.clientCompletionPercentage != oa.serverCompletionPercentage) {
				OFLog.d(TAG, String.format("Updating achievement %s from known %f to %f completion", oa.resourceID, oa.serverCompletionPercentage, oa.clientCompletionPercentage));
				oal.put(String.format("achievements[%d][id]", currAchievement), oa.resourceID);
				oal.put(String.format("achievements[%d][percent_complete]", currAchievement), Float.toString(oa.clientCompletionPercentage));
				oal.put(String.format("achievements[%d][timestamp]", currAchievement), oa.timestamp);
				++currAchievement;
			}
		}
		
		int currScore = 0;
		for (OfflineScore os : clonedDB.scores) {
			if (os.blobFileName == null) {
				OFLog.d(TAG, String.format("Posting score %d to leaderboard %s", os.score, os.leaderboardID));
				oal.put(String.format("high_scores[%d][leaderboard_id]", currScore), os.leaderboardID);
				oal.put(String.format("high_scores[%d][score]", currScore), Long.toString(os.score));
				if (os.displayText != null) {
    				oal.put(String.format("high_scores[%d][display_text]", currScore), os.displayText);
				}
				if (os.customData != null) {
    				oal.put(String.format("high_scores[%d][custom_data]", currScore), os.customData);
				}
				oal.put(String.format("high_scores[%d][timestamp]", currScore), os.timestamp);
				++currScore;
			}
		}

        // Don't bother making the request if it's not gonna do anything.
        if (currAchievement == 0 && currScore == 0) {
        	uploadScoresWithBlobs();
        	return;
        }
        
        final String path = "/xp/games/" + OpenFeintInternal.getInstance().getAppID() + "/offline_syncs";
        
        new BaseRequest(oal) {
        	@Override public String method() { return "POST"; }
        	@Override public String path() { return path; }
        	@Override public void onResponse(int responseCode, byte[] body) {}
        	@Override public void onResponseOffMainThread(int responseCode, byte[] body) {
        		if (200 <= responseCode && responseCode < 300) {
        			// Update local stuff and save it.
        			db.updateOnUpload(clonedDB);
        			save();
        			
        			// we can start working on blobs now.
        			uploadScoresWithBlobs();
        		} else {
        			 if (0 == responseCode || 500 <= responseCode) {
        				 // This is a transient offline / internal server error.  keep the log around.
        			 } else {
	        			// dude I don't know what the deal is but this ain't good.  I shouldn't try to repeat it.
	        			db.removeReferencedBlobs();
	        			db.clear();
	        			save();
        			 }
         			// Regardless, we're done for now, clear the flag so we can embark on another sync later.
         			updateInProgress.set(false);
        		}
        	}
        }.launch();
	}
	
	public static void updateClientCompletionPercentage(String resourceID, float completionPercentage) {
		if (null == userID) return;
		
		OfflineAchievement a = db.findAchievement(resourceID);
		if (null == a) {
			a                            = new OfflineAchievement();
			a.resourceID                 = resourceID;
			a.serverCompletionPercentage = 0.0f; // as far as we know
			a.clientCompletionPercentage = completionPercentage;
			a.timestamp = now();
			db.achievements.add(a);
			save();
		} else if (a.clientCompletionPercentage < completionPercentage) {
			a.clientCompletionPercentage = completionPercentage;
			a.timestamp = now();
			save();
		}
	}
	
	public static void updateServerCompletionPercentage(String resourceID, float completionPercentage) {
		if (null == userID) return;

		OfflineAchievement a = db.findAchievement(resourceID);
		if (null == a) {
			a                            = new OfflineAchievement();
			a.resourceID                 = resourceID;
			a.clientCompletionPercentage = completionPercentage;  // go by the authority
			db.achievements.add(a);
		}
		a.serverCompletionPercentage = completionPercentage;
		a.timestamp = now();
		save();
	}

	public static float getClientCompletionPercentage(String resourceID) {
		OfflineAchievement a = db.findAchievement(resourceID);
		if (null == a) return 0.0f;
		return a.clientCompletionPercentage;
	}
	
	public static void postOfflineScore(Score s, Leaderboard l) {
		if (null == userID) return;

		OfflineScore os = new OfflineScore();
		os.leaderboardID = l.resourceID();
		os.score = s.score;
		os.displayText = s.displayText;
		os.customData = s.customData;
		os.timestamp = now();
		if (s.blob != null) {
			// First thing: only use this blob if the score's better than any on the same leaderboard.
			OfflineScore existingScore = null;
			for (OfflineScore scan : db.scores) {
				if (os.leaderboardID.equals(scan.leaderboardID)) {
					existingScore = scan;
					break;
				}
			}
			
			if (existingScore != null) {
				if (l.allowsWorseScores ||
						(l.descendingSortOrder && existingScore.score < s.score) ||
						(!l.descendingSortOrder && existingScore.score > s.score)) {
					// replace the score.
					deleteDataFile(existingScore.blobFileName);
					db.scores.remove(existingScore);
				} else {
					// There's a better score in the db.  Drop this score on the floor.
					return;
				}
			}
			
			String filename = "unknown.blob";
			MessageDigest md;
			try {
				md = MessageDigest.getInstance("SHA1");
				md.update(s.blob);
				filename = String.format("%s.blob", new String(Hex.encodeHex(md.digest())));
			} catch (NoSuchAlgorithmException e) {
				// nope, doesn't happen
			}

			try {
				Util.saveFile(s.blob, fullPath(filename));
			} catch (IOException e) {
				// Can't save blob?  score gets dropped on the floor
				return;
			}
			
			os.blobFileName = filename;
		}
		
		db.scores.add(os);
		save();
		
		// We do the notification here, in lieu of copypasta in Score.java.
		if (!isUserTemporary()) {
			SimpleNotification.show(OpenFeintInternal.getRString(RR.string("of_score_submitted_notification")),
					"@drawable/of_icon_highscore_notification", Notification.Category.HighScore, Notification.Type.Success);
		}
	}
	
	private static void save() {
		final String fileName = filename(userID);
		if (fileName != null) db.save(fileName);
	}
}
