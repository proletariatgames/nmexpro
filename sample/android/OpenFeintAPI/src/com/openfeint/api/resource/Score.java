package com.openfeint.api.resource;

import java.util.List;

import android.content.res.Resources;

import com.openfeint.api.Notification;
import com.openfeint.internal.APICallback;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.notifications.SimpleNotification;
import com.openfeint.internal.offline.OfflineSupport;
import com.openfeint.internal.request.BlobPostRequest;
import com.openfeint.internal.request.CompressedBlobDownloadRequest;
import com.openfeint.internal.request.CompressedBlobPostRequest;
import com.openfeint.internal.request.DownloadRequest;
import com.openfeint.internal.request.IRawRequestDelegate;
import com.openfeint.internal.request.JSONRequest;
import com.openfeint.internal.request.OrderedArgList;
import com.openfeint.internal.resource.BlobUploadParameters;
import com.openfeint.internal.resource.DoubleResourceProperty;
import com.openfeint.internal.resource.IntResourceProperty;
import com.openfeint.internal.resource.LongResourceProperty;
import com.openfeint.internal.resource.NestedResourceProperty;
import com.openfeint.internal.resource.Resource;
import com.openfeint.internal.resource.ResourceClass;
import com.openfeint.internal.resource.ScoreBlobDelegate;
import com.openfeint.internal.resource.StringResourceProperty;

/**
 * The resource class that represents a Score posted to OpenFeint.
 * This class is used to post high scores. The list of current high scores
 * for a given Leaderboard is contained in its highScores field.
 * 
 */
public class Score extends Resource {

	/**
	 * When posting a score to a Leaderboard, use this constructor.  No other fields need be
	 * filled out before calling submitTo(Leaderboard).
	 * @param score The user's score.
	 */
	public Score(long score) { this.score = score; }

	/**
	 * If you will be posting a score to a Leaderboard and you want to have the Leaderboard display a
	 * string other than just the numeric score, use this constructor.  No other fields
	 * need be filled out before calling submitTo(Leaderboard).
	 * @param score The user's score.  (Ranking is calculated using this value!)
	 * @param displayText The string that should show on the leaderboard, if desired to be different than score. 
	 */
	public Score(long score, String displayText) { this.score = score; this.displayText = displayText; }

	/**
	 * The User who posted this score.
	 */
	public User user;
	/**
	 * The numeric value of the score.
	 */
	public long score;
	/**
	 * Approximate rank in the Leaderboard.
	 */
	public int rank;
	/**
	 * The resource ID of the Leaderboard that this score came from. 
	 */
	public int leaderboardId; // unsigned
	/**
	 * The text displayed on the leaderboard.  If this is empty or null,
	 * the text displayed on the leaderboard will be this.score.
	 */
	public String displayText;
	/**
	 * A bit of custom data you can attach to a Score before submission,
	 * and ideally get it back later.  This field is currently unsupported.
	 */
	public String customData;
	/**
	 * The submitting User's latitude at the time they submitted this score.
	 */
	public double latitude;
	/**
	 * The submitting User's longitude at the time they submitted this score.
	 */
	public double longitude;
	/**
	 * A blob of data associated with this score.  You can use this field to store replays
	 * associated with the high score, among other things.  If you set this before calling
	 * {@link submitTo()}, this blob will be uploaded to the server.  However, it is not
	 * downloaded by default - you need to call {@link downloadBlob()} if you want to
	 * retrieve the data.
	 * You can tell if a score has a blob to download by calling the hasBlob() method,
	 * regardless of whether the blob has been downloaded yet.
	 */
	public byte blob[];

	// Internal fields:
	
	/**
	 * If this score has a blob of data associated with it, like a replay
	 * or screenshot, this is the URL to that data blob.  This field is
	 * currently unsupported.
	 */
	private String blobUrl;
	/**
	 * If this score has a blob of data associated with it, like a replay
	 * or screenshot, these are the parameters used to upload the blob.
	 * This field is currently unsupported.
	 */
	private BlobUploadParameters blobUploadParameters;
	
	/**
	 * This method can be called to determine whether a Score object retrieved from
	 * a Leaderboard method has a blob available for downloading.  If it's true, you
	 * can call {@link downloadBlob()} to retrieve the blob, and store it in the {@link blob}
	 * member variable.
	 * @return whether this Score has an associated blob that can be downloaded.
	 */
	public boolean hasBlob() {
		return blobUrl != null;
	}
	
	/**
	 * A callback class you can extend for calling Score.submitTo().
	 */
	public abstract static class SubmitToCB extends APICallback {
		/**
		 * When Score.submitTo() completes, this method will be called to
		 * let you know if the Score submission succeeded. 
		 * @param newHighScore Will be true if this was a new high Score for this user.
		 */
		public abstract void onSuccess(boolean newHighScore);
		/**
		 * If you supplied a blob (via setting the {@link blob} member variable),
		 * and the score submitted was a new high score, then we'll attempt to upload the blob.
		 * This will be called if the blob upload succeeds.  This will happen after the normal
		 * onSuccess/onFailure.
		 */
		public void onBlobUploadSuccess() {}
		/**
		 * If you supplied a blob (via setting the {@link blob} member variable),
		 * and the score submitted was a new high score, then we'll attempt to upload the blob.
		 * This will be called if the blob upload fails.  This will happen after the normal
		 * onSuccess/onFailure.
		 */
		public void onBlobUploadFailure(String exceptionMessage) {}
	}
	/**
	 * Call this method to submit a Score you created to a given Leaderboard.
	 * For example, to submit a local user score of 123 to the Leaderboard with
	 * the resource ID 456, and report to the SubmitToCB object cb, you would do:
	 * <pre>new Score(123).submitTo(new Leaderboard("456"), cb);</pre>
	 * @param cb The callback object that will be notified on request completion.
	 */
	public void submitTo(final Leaderboard leaderboard, final SubmitToCB cb) {
		submitToInternal(leaderboard, null, cb, false);
	}
	/**
	 * This method is used internally by OpenFeint, you shouldn't need to call this.
	 */
	public void submitToFromOffline(final Leaderboard leaderboard, final String timestamp, final SubmitToCB cb) {
		submitToInternal(leaderboard, timestamp, cb, true);
	}
	
	private void submitToInternal(final Leaderboard leaderboard, final String timestamp, final SubmitToCB cb, final boolean fromOffline) {

		if (null == leaderboard || null == leaderboard.resourceID() || leaderboard.resourceID().length() == 0) { 
			if (cb != null) {
				cb.onFailure("No leaderboard ID provided.  Please provide a leaderboard ID from the Dev Dashboard.");
			}
			return;
		}
		
		if (!OpenFeintInternal.getInstance().isUserLoggedIn()) {
			// Just write it to the offline cache and return.
			OfflineSupport.postOfflineScore(Score.this, leaderboard);
			if (cb != null) {
				cb.onSuccess(false);
			}
			return;
		}

		final String path =  "/xp/games/" + OpenFeintInternal.getInstance().getAppID() + "/leaderboards/" + leaderboard.resourceID() + "/high_scores";
		
		OrderedArgList args = new OrderedArgList();
		
		args.put("high_score[score]", new Long(this.score).toString());
		if (this.displayText != null) {
			args.put("high_score[display_text]", this.displayText);
		}
		final boolean uploadBlob = (blob != null);
		args.put("high_score[has_blob]", uploadBlob ? "1" : "0");

		if (timestamp != null) {
			args.put("high_score[timestamp]", timestamp);
		}
		
		JSONRequest req = new JSONRequest(args) {
			@Override public String method() { return "POST"; }
			@Override public String path() { return path; }
			
			@Override protected void onResponse(int responseCode, Object responseBody) {
				if (201 == responseCode) {
					if (!fromOffline) {
						Resources r = OpenFeintInternal.getInstance().getContext().getResources();
						SimpleNotification.show(r.getString(RR.string("of_score_submitted_notification")), "@drawable/of_icon_highscore_notification", Notification.Category.HighScore, Notification.Type.Success);
					}
					if (cb != null) cb.onSuccess(true);
					perhapsUploadBlob(uploadBlob, responseBody);
				} else if (200 <= responseCode && responseCode < 300) {
					if (cb != null) cb.onSuccess(false);
				} else if ((0 == responseCode || 500 <= responseCode) && !fromOffline) {
					// We're offline.  Just put it in the offline sync.
					OfflineSupport.postOfflineScore(Score.this, leaderboard);
					if (cb != null) cb.onSuccess(false);
				} else {
					// legit failure.
					onFailure(responseBody);
				}
			}
			
			@SuppressWarnings("unchecked")
			private final void perhapsUploadBlob(final boolean uploadBlob,
					Object responseBody) {
				if (uploadBlob && responseBody instanceof List<?>) {
					List<Score> scores = (List<Score>)responseBody;
					Score s = scores.get(0);
					
					BlobPostRequest postRequest = new CompressedBlobPostRequest(s.blobUploadParameters, String.format("blob.%s.bin", s.resourceID()), Score.this.blob);
					if (cb != null) {
						postRequest.setDelegate(new IRawRequestDelegate() {
							@Override public void onResponse(int responseCode, String responseBody) {
								if (200 <= responseCode && responseCode < 300) {
									cb.onBlobUploadSuccess();
								} else {
									cb.onBlobUploadFailure(responseBody);
								}
							}
						});
					}
					postRequest.launch();
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				super.onFailure(exceptionMessage);
				if (cb != null) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}
	
	/**
	 * A callback class you can extend for calling Score.downloadBlob().
	 */
	public abstract static class DownloadBlobCB extends APICallback {
		/**
		 * When downloadBlob() completes, this method will be called to
		 * let you know if the blob download succeeded. 
		 */
		public abstract void onSuccess();
	};
	
	public void downloadBlob(final DownloadBlobCB cb) {
		
		if (hasBlob()) {
			DownloadRequest req = new CompressedBlobDownloadRequest() {
				@Override public boolean signed() { return false; }
				@Override public String url() { return Score.this.blobUrl; }
				@Override public String path() { return ""; }
				@Override protected void onSuccessDecompress(byte bodyData[]) {
					Score.this.blob = bodyData;
					if (cb != null) cb.onSuccess();
				}
				@Override public void onFailure(String exceptionMessage) {
					super.onFailure(exceptionMessage);
					if (cb != null) cb.onFailure(exceptionMessage);
				}
			};
			req.launch();
		} else if (cb != null) {
			cb.onFailure(OpenFeintInternal.getRString(RR.string("of_no_blob")));
		}
	}
	
	/**
	 * A delegate class you can install to be notified when the user downloads a blob
	 * from the Feint Dashboard.  This will not be invoked if you
	 * manually call {@link downloadBlob}.  Typically, you'll want to implement blobDownloadedForScore()
	 * to start your replay-viewing Activity, or whatever other method you want to use
	 * to display the contents of the blob.
	 */
	public static abstract class BlobDownloadedDelegate {
		/**
		 * This method is called when the user downloads a blob from the Feint Dashboard.
		 * @param score The Score that was downloaded.  When this method is called, the blob field
		 * will have already been downloaded.
		 */
		public void blobDownloadedForScore(Score score) { }
	}
	
	/**
	 * Installs a delegate as the handler to use when the user downloads a blob from the
	 * Feint Dashboard.
	 * @param delegate
	 */
	public static void setBlobDownloadedDelegate(BlobDownloadedDelegate delegate) {
		ScoreBlobDelegate.sBlobDownloadedDelegate = delegate;
	}
	
	/**
	 * This constructor is for use by the parser only.
	 */
	public Score() { }
	
	/**
	 * This method is used internally by OpenFeint.
	 */
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (Score.class, "high_score") { public Resource factory () { return new Score (); } };

		klass.mProperties.put("score", new LongResourceProperty() { public void set(Resource obj, long val) { ((Score)obj).score = val; } public long get(Resource obj) { return ((Score)obj).score; } });
		klass.mProperties.put("rank", new IntResourceProperty() { public void set(Resource obj, int val) { ((Score)obj).rank = val; } public int get(Resource obj) { return ((Score)obj).rank; } });
		klass.mProperties.put("leaderboard_id", new IntResourceProperty() { public void set(Resource obj, int val) { ((Score)obj).leaderboardId = val; } public int get(Resource obj) { return ((Score)obj).leaderboardId; } });
		klass.mProperties.put("display_text", new StringResourceProperty() { public void set(Resource obj, String val) { ((Score)obj).displayText = val; } public String get(Resource obj) { return ((Score)obj).displayText; } });
		klass.mProperties.put("custom_data", new StringResourceProperty() { public void set(Resource obj, String val) { ((Score)obj).customData = val; } public String get(Resource obj) { return ((Score)obj).customData; } });
		klass.mProperties.put("lat", new DoubleResourceProperty() { public void set(Resource obj, double val) { ((Score)obj).latitude = val; } public double get(Resource obj) { return ((Score)obj).latitude; } });
		klass.mProperties.put("lng", new DoubleResourceProperty() { public void set(Resource obj, double val) { ((Score)obj).longitude = val; } public double get(Resource obj) { return ((Score)obj).longitude; } });
		klass.mProperties.put("user", new NestedResourceProperty(User.class) { public void set(Resource obj, Resource val) { ((Score)obj).user = (User)val; } public Resource get(Resource obj) { return ((Score)obj).user; } });
		klass.mProperties.put("blob_url", new StringResourceProperty() { public void set(Resource obj, String val) { ((Score)obj).blobUrl = val; } public String get(Resource obj) { return ((Score)obj).blobUrl; } });
		klass.mProperties.put("blob_upload_parameters", new NestedResourceProperty(BlobUploadParameters.class) { public void set(Resource obj, Resource val) { ((Score)obj).blobUploadParameters = (BlobUploadParameters)val; } public Resource get(Resource obj) { return ((Score)obj).blobUploadParameters; } });

		return klass;
	}
	
}