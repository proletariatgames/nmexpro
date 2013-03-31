package nmex;

import nme.events.Event;

class NXEvent extends Event{
	
	/** Event IDs */
	public inline static var UN_KNOWN_EVENT:String = "unKnownEvent"; //0 
	
	/** In App Purchase **/
	public inline static var IN_APP_PURCHASE_SUCCESS:String = "inAppPurchaseSuccess"; //1
	public inline static var IN_APP_PURCHASE_FAIL:String = "inAppPurchaseFail"; //2
	public inline static var IN_APP_PURCHASE_CANCEL:String = "inAppPurchaseCancel"; //3
  public inline static var IN_APP_PURCHASE_DATA:String = "inAppPurchaseData"; // 4
  public inline static var IN_APP_PURCHASE_DATA_FAIL:String = "inAppPurchaseDataFail"; // 5
  public inline static var IN_APP_PURCHASE_RESTORE:String = "inAppPurchaseRestore"; //22
	
	/** game center **/
	public static inline var AUTH_SUCCEEDED:String = "authSucceeded";
	public static inline var AUTH_FAILED:String = "authFailed";
	public static inline var LEADERBOARD_VIEW_OPENED:String = "leaderboardViewOpened";
	public static inline var LEADERBOARD_VIEW_CLOSED:String = "leaderboardViewClosed";
	public static inline var ACHIEVEMENTS_VIEW_OPENED:String = "achievementsViewOpened";
	public static inline var ACHIEVEMENTS_VIEW_CLOSED:String = "achievementsViewClosed";
	public static inline var SCORE_REPORT_SUCCEEDED:String = "scoreReportSucceeded";
	public static inline var SCORE_REPORT_FAILED:String = "scoreReportFailed";
	public static inline var ACHIEVEMENT_REPORT_SUCCEEDED:String = "achievementReportSucceeded";
	public static inline var ACHIEVEMENT_REPORT_FAILED:String = "achievementReportFailed";
	public static inline var ACHIEVEMENT_RESET_SUCCEEDED:String = "achievementResetSucceeded";
	public static inline var ACHIEVEMENT_RESET_FAILED:String = "achievementResetFailed";
  public static inline var MATCHMAKING_VIEW_CLOSED:String = "matchmakingViewClosed";
  public static inline var MATCH_STARTED:String = "matchStarted";
  public static inline var MATCH_DATA_RECEIVED:String = "matchDataReceived";
  public static inline var MATCH_PLAYER_DISCONNECTED:String = "matchPlayerDisconnected";

  public static inline var AUDIO_PLAYBACK_STATE_CHANGED:String ="audioPlaybackStateChanged";

  public static inline var LOAD_TURN_BASED_MATCHES_SUCCESS:String = "loadTurnBasedMatchesSuccess";
  public static inline var LOAD_TURN_BASED_MATCHES_FAIL:String = "loadTurnBasedMatchesFail";
  public static inline var LOAD_PLAYER_DATA_SUCCESS:String = "loadPlayerDataSuccess";
  public static inline var LOAD_PLAYER_DATA_FAIL:String = "loadPlayerDataFail";
  public static inline var UPDATE_MATCH_SUCCESS:String = "updateMatchSuccess";
  public static inline var UPDATE_MATCH_FAIL:String = "updateMatchFail";
  public static inline var GET_MATCH_DATA_SUCCESS:String = "getMatchDataSuccess";
  public static inline var GET_MATCH_DATA_FAIL:String = "getMatchDataFail";
	
  public static inline var TURN_BASED_MATCH_INVITE:String = "turnBasedMatchInvite";
  public static inline var TURN_BASED_MATCH_ENDED:String = "turnBasedMatchEnded";
  public static inline var TURN_BASED_MATCH_TURN:String = "turnBasedMatchTurn";

  public static inline var REMATCH_STARTED:String = "rematchStarted";
  public static inline var REMATCH_FAILED:String = "rematchFailed";

	public var EventID:Int;
	public var code:Int;
	public var value:Int;
	public var data:String;
	
	public function new(type:String, code:Int, value:Int, data:String){
		super(type);
    this.code = code;
    this.value = value;
    this.data = data;
	}
}
