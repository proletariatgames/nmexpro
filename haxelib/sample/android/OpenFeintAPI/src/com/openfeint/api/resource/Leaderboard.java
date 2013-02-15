package com.openfeint.api.resource;

import java.util.List;

import com.openfeint.internal.APICallback;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.request.JSONRequest;
import com.openfeint.internal.request.OrderedArgList;
import com.openfeint.internal.resource.ArrayResourceProperty;
import com.openfeint.internal.resource.BooleanResourceProperty;
import com.openfeint.internal.resource.NestedResourceProperty;
import com.openfeint.internal.resource.Resource;
import com.openfeint.internal.resource.ResourceClass;
import com.openfeint.internal.resource.ServerException;
import com.openfeint.internal.resource.StringResourceProperty;

/**
 * The resource class that represents a Leaderboard in OpenFeint.
 * You use this class to:
 * <ul>
 * <li>Get the list of Leaderboards that were created on the Developer Dashboard for this 
 * application,</li>
 * <li>Download the list of high Scores for a Leaderboard, or </li>
 * <li>Submit a Score to a Leaderboard.</li>
 * </ul>
 */
public class Leaderboard extends Resource {

	/**
	 * Create a Leaderboard object with the given resource ID.  This won't automatically
	 * fill the other fields out - see Leaderboard.list() or Leaderboard.getScores()
	 * if you want to consult other fields of the Leaderboard.
	 * 
	 * @param resourceID The resource ID of the Leaderboard.
	 */
	public Leaderboard(String resourceID) { setResourceID(resourceID); }

	/**
	 * The user-visible name of the Leaderboard.
	 */
	public String name;
	/**
	 * The Score that the local User has posted to this Leaderboard, if any.
	 */
	public Score localUserScore;
	/**
	 * Whether this Leaderboard sorts ascending or descending.  If true, then
	 * sort order is descending (like basketball); if false, then sort order
	 * is ascending (like golf).
	 */
	public boolean descendingSortOrder = true;
	/**
	 * Whether this Leaderboard allows worse scores.  If true, then submitting a
	 * score will always overwrite the previous score, even if it's not as good
	 * as the player's previous score.  If false, then only the best score will
	 * be kept.
	 */
	public boolean allowsWorseScores;
	/**
	 * The top of the list of high scores.  This field is not filled out in Leaderboards
	 * returned by Leaderboard.list(); it is only filled out if you call Leaderboard.getScores().
	 */
	public List<Score> highScores;

	/**
	 * A callback class you can extend for calling Leaderboard.getScores()
	 * and Leaderboard.getFriendScores().
	 */
	public abstract static class GetScoresCB extends APICallback {
		/**
		 * When Leaderboard.getScores() succeeds, this method will be called with
		 * the list of Scores for this Leaderboard.
		 * @param scores The high Scores for this Leaderboard. 
		 */
		public abstract void onSuccess(List<Score> scores);
	}
	/**
	 * Call this method to get the top of global list of high Scores for this Leaderboard.
	 * @param cb The callback object that will be given the list of Scores.
	 */
	public void getScores(final GetScoresCB cb) {
		getScores(false, cb);
	}
	/**
	 * Call this method to get the top of friend list of high Scores for this Leaderboard.
	 * @param cb The callback object that will be given the list of Scores.
	 */
	public void getFriendScores(final GetScoresCB cb) {
		getScores(true, cb);
	}
	
	private void getScores(final boolean friends, final GetScoresCB cb) {
		final String path =  "/xp/games/" + OpenFeintInternal.getInstance().getAppID() + "/leaderboards/" + resourceID() + "/high_scores";
		OrderedArgList args = new OrderedArgList();
		if (friends) {
			args.put("friends_leaderboard", "true");
		}
		JSONRequest req = new JSONRequest(args) {
			@Override public boolean wantsLogin() { return friends; } // need to be logged in to know who your friends are.
			@Override public String method() { return "GET"; }
			@Override public String path() { return path; }			
			
			@SuppressWarnings("unchecked")
			@Override public void onSuccess(Object responseBody) {
				if (null != cb) {
					List<Score> scores = (List<Score>)responseBody;
					cb.onSuccess(scores);
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
	 * A callback class you can extend for calling Leaderboard.getUserScore().
	 */
	public abstract static class GetUserScoreCB extends APICallback {
		/**
		 * When Leaderboard.getUserScore() succeeds, this method will be called with
		 * the given User's Score.
		 * <em>NOTE!  If the User has -not- posted a Score to this Leaderboard, your callback's
		 * onSuccess() method will be called with a null Score parameter!</em>
		 * @param score The given User's Score, or null, if they have not posted a score to this Leaderboard.
		 */
		public abstract void onSuccess(Score score);
	}
	/**
	 * Call this method to get the current Score for the specified User on this Leaderboard.
	 * The current Score might be the User's high score for this leaderboard, but if you have 
	 * checked <b>Allow worse scores</b> for this leaderboard, it might simply be the most recently 
	 * posted score for this user on this leaderboard.
	 * <br/><em><b>NOTE</b>:  If the User has -not- posted a Score to this Leaderboard, your callback's
	 * onSuccess() method will be called with a null Score parameter!</em>
	 * onFailure() will only be called if there was a failure communicating with the server.
	 * @param forUser the User to get the Score for.
	 * @param cb The callback object that will be given the Score.
	 */
	public void getUserScore(final User forUser, final GetUserScoreCB cb) {
		final String path =  "/xp/users/" + forUser.resourceID() + "/games/" + OpenFeintInternal.getInstance().getAppID() + "/leaderboards/" + resourceID() + "/current_score";
		OrderedArgList args = new OrderedArgList();

		JSONRequest req = new JSONRequest(args) {
			@Override public String method() { return "GET"; }
			@Override public String path() { return path; }			
			
			@Override public void onResponse(int responseCode, Object responseBody) {
				if (null != cb) {
					if (200 <= responseCode && responseCode < 300) {
						cb.onSuccess((Score)responseBody);
					} else if (404 == responseCode) {
						cb.onSuccess(null);
					} else if (responseBody instanceof ServerException) {
						onFailure(((ServerException)responseBody).message);
					} else {
						onFailure(OpenFeintInternal.getRString(RR.string("of_unknown_server_error")));
					}
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
	 * A callback class you can extend for calling Leaderboard.list().
	 */
	public abstract static class ListCB extends APICallback {
		/**
		 * When Leaderboard.list() succeeds, this method will be called with
		 * the list of Leaderboards for your application.
		 * @param leaderboards the list of Leaderboards for your application. 
		 */
		public abstract void onSuccess(final List<Leaderboard> leaderboards);
	}
	/**
	 * Call this method to get a list of Leaderboards that are available
	 * to your application.  These are the Leaderboards that you've created
	 * on the Developer Dashboard.
	 * @param cb The callback object that will be given the list of Leaderboards.
	 */
	public static void list(final ListCB cb) {
		final String path =  "/xp/games/" + OpenFeintInternal.getInstance().getAppID() + "/leaderboards";
		JSONRequest req = new JSONRequest() {
			@Override public String method() { return "GET"; }
			@Override public String path() { return path; }
			
			@Override public void onSuccess(Object responseBody) {
				if (null != cb) {
					try {
						@SuppressWarnings("unchecked") List<Leaderboard> leaderboards = (List<Leaderboard>)responseBody;
						cb.onSuccess(leaderboards);
					} catch (Exception e) {
						onFailure(OpenFeintInternal.getRString(RR.string("of_unexpected_response_format")));
					}
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

//	/**
//	 * A callback class you can extend for calling Leaderboard.load().
//	 */
//	public abstract static class LoadCB extends APICallback {
//		/**
//		 * When Leaderboard.load() succeeds, this method will be called to
//		 * notify you that you can refer to all fields of the Leaderboard.
//		 */
//		public abstract void onSuccess();
//	}
//	/**
//	 * Call this method to fill out all the fields of this Leaderboard, including
//	 * the highScores field.
//	 * @param cb The callback object that will be notified when all fields are loaded.
//	 */
//	public void load(final LoadCB cb) {
//		final String path =  "/xp/games/" + OpenFeintInternal.getInstance().getAppID() + "/leaderboards/" + resourceID();
//		JSONRequest req = new JSONRequest() {
//			@Override public String method() { return "GET"; }
//			@Override public String path() { return path; }			
//			
//			@Override public void onSuccess(Object responseBody) {
//				shallowCopy((Leaderboard)responseBody);
//					
//				if (null != cb) {
//					cb.onSuccess();
//				}
//			}
//			
//			@Override public void onFailure(String exceptionMessage) {
//				super.onFailure(exceptionMessage);
//				if (cb != null) {
//					cb.onFailure(exceptionMessage);
//				}
//			}
//		};
//
//		OpenFeintInternal.getInstance().makeRequest(req);
//	}

	/**
	 * This constructor is for use by the parser only.
	 */
	public Leaderboard() { }
	
	/**
	 * This method is used internally by OpenFeint.
	 */
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (Leaderboard.class, "leaderboard") { public Resource factory () { return new Leaderboard (); } };

		klass.mProperties.put("name", new StringResourceProperty() { public void set(Resource obj, String val) { ((Leaderboard)obj).name = val; } public String get(Resource obj) { return ((Leaderboard)obj).name; } });
		klass.mProperties.put("current_user_high_score", new NestedResourceProperty(Score.class) { public void set(Resource obj, Resource val) { ((Leaderboard)obj).localUserScore = (Score)val; } public Resource get(Resource obj) { return ((Leaderboard)obj).localUserScore; } });
		klass.mProperties.put("descending_sort_order", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((Leaderboard)obj).descendingSortOrder = val; } public boolean get(Resource obj) { return ((Leaderboard)obj).descendingSortOrder; } });
		klass.mProperties.put("allow_posting_lower_scores", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((Leaderboard)obj).allowsWorseScores = val; } public boolean get(Resource obj) { return ((Leaderboard)obj).allowsWorseScores; } });
		klass.mProperties.put("high_scores", new ArrayResourceProperty(Score.class) { @SuppressWarnings("unchecked") public void set(Resource obj, List<?> vals) { ((Leaderboard)obj).highScores = (List<Score>)vals; } public List<? extends Resource> get(Resource obj) { return ((Leaderboard)obj).highScores; } });

		return klass;
	}
}