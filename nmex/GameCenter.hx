package nmex;

#if android
class GameCenter extends NXObject{


private static var instance:GameCenter;

private function new(){
	super();
}

public static function getInstance():GameCenter{
	if(instance == null){
		instance = new GameCenter();
	}
	
	return instance;
}

public function authenticateLocalUser():Void{
	
}

private static var _showAchievements_func:Dynamic;
public function showAchievements():Void{
	if (_showAchievements_func == null)
		_showAchievements_func = nme.JNI.createStaticMethod("org.haxe.nme.GameActivity", "showAchievements", "()V", true);
	var a = new Array<Dynamic>();
	_showAchievements_func(a);
}

private static var _showLeaderboardForCategory_func:Dynamic;
public function showLeaderboardForCategory(category:String):Void{
	if (_showLeaderboardForCategory_func == null)
		_showLeaderboardForCategory_func = nme.JNI.createStaticMethod("org.haxe.nme.GameActivity", "showLeaderboardForCategory", "(Ljava/lang/String;)V", true);
	var a = new Array<Dynamic>();
	a.push(category);
	_showLeaderboardForCategory_func(a);
}

private static var _reportScoreForCategory_func:Dynamic;
public function reportScoreForCategory(score:Int, category:String):Void{
	if (_reportScoreForCategory_func == null)
		_reportScoreForCategory_func = nme.JNI.createStaticMethod("org.haxe.nme.GameActivity", "reportScoreForCategory", "(ILjava/lang/String;)V", true);
	var a = new Array<Dynamic>();
	a.push(score);
	a.push(category);
	_reportScoreForCategory_func(a);
}

private static var _reportAchievement_func:Dynamic;
public function reportAchievement(achievementId:String):Void{
	
	if (_reportAchievement_func == null)
		_reportAchievement_func = nme.JNI.createStaticMethod("org.haxe.nme.GameActivity", "reportAchievement", "(Ljava/lang/String;)V", true);
	var a = new Array<Dynamic>();
	a.push(achievementId);
	_reportAchievement_func(a);
}

public function resetAchievements():Void{
}
}
#else

class GameCenter extends NXObject{


private static var instance:GameCenter;

private function new(){
	super();
	var result:Bool=untyped nmex_init_game_kit();
	if(!result){
		throw "GameCenter init error.";
	}
}

public static function getInstance():GameCenter{
	if(instance == null){
		instance = new GameCenter();
	}
	
	return instance;
}

//
// Authentication/Player data
//

public function authenticateLocalUser():Void{
	untyped nmex_authenticate_local_user();		
}

public function isLoggedIn() : Bool {
  return untyped nmex_is_user_authenticated();
}

public function getPlayerID() : String {
  return untyped nmex_get_player_id();
}

public function loadPlayerData(ids:Array<String>, requestID:Int) : Void {
  untyped nmex_load_player_data(ids.join(","), requestID);
}

public function getLoadedPlayerPNG(id:String) : nme.display.BitmapData {
  var data:String = untyped nmex_get_player_png(id);
  return data != null ? nme.display.BitmapData.loadFromHaxeBytes(haxe.io.Bytes.ofString(data)) : null;
}

//
// Acheivements
//

public function showAchievements():Void{
	untyped nmex_show_achievements();
}

public function reportAchievement(achievementId:String,completion:Float):Void{
	untyped nmex_report_achievement(achievementId,completion);
}

public function resetAchievements():Void{
	untyped nmex_reset_achievements();
}

//
// Leaderboards
//

public function showLeaderboardForCategory(category:String):Void{
	untyped nmex_show_leaderboard_for_category(category);
}

public function reportScoreForCategory(score:Int,category:String):Void{
	untyped nmex_report_score_for_category(score,category);
}

//
// Synchronous (Live) multiplayer
// 

public function showMatchmakingUI() : Void {
  untyped nmex_show_matchmaking_ui();
}

public function broadcastLiveMatchData(data:String) : Void {
  untyped nmex_broadcast_match_data(data);
}

public function isLiveMatchStarted() : Bool {
  return untyped nmex_is_match_started();
}

public function inLiveMatch() : Bool {
  return untyped nmex_in_live_match();
}

public function disconnectLiveMatch() : Void {
  untyped nmex_disconnect_match();
}

public function getLiveMatchPlayers() : Array<String> {
  var players = [];
  var numPlayers:Int = untyped nmex_get_match_num_players();
  for ( i in 0...numPlayers ) {
    players.push( untyped nmex_get_match_player_id(i) );
  }
  return players;
}

//
// Turn-based Multiplayer
//

public function showTurnbasedMatchmakingUI() : Void {
  untyped nmex_start_turn_based_match();
}

public function rematchTurnBasedGame(matchID:String, requestID:Int) : Void {
  untyped nmex_start_rematch(matchID, requestID);
}

public function inTurnBasedMatch() : Bool {
  return untyped nmex_in_turn_based_match();
}

public function setCurrentTurnBasedMatch(matchID:String) : Void {
  untyped nmex_set_current_turn_based_match(matchID);
}

public function loadTurnBasedMatches(requestID:Int) : Void {
  untyped nmex_load_turn_based_matches(requestID);
}

public function advanceTurnBasedMatch(matchID:String, matchMessage:String, matchData:String, requestID:Int) : Void {
  untyped nmex_advance_match(matchID, matchMessage, matchData, requestID);
}

public function pauseTurnBasedMatch(matchID:String, matchData:String, requestID:Int) : Void {
  untyped nmex_pause_match(matchID, matchData, requestID);
}

public function endTurnBasedMatch(matchID:String, winningPlayerID:String, message:String, matchData:String, requestID:Int) : Void {
  untyped nmex_end_match(matchID, winningPlayerID, message, matchData, requestID);
}

public function resignFromTurnBasedMatch(matchID:String, matchData:String, requestID:Int) : Void {
  untyped nmex_quit_match(matchID, matchData, requestID);
}

public function removeTurnBasedMatch(matchID:String, requestID:Int) : Void {
  untyped nmex_remove_match(matchID, requestID);
}

public function loadTurnBasedMatchData(matchID:String, requestID:Int) : Void {
  untyped nmex_get_match_data(matchID, requestID);
}

// CFFI
private static var nmex_is_game_center_available = nme.Loader.load("is_game_center_available",0);
private static var nmex_authenticate_local_user = nme.Loader.load("authenticate_local_user",0);
private static var nmex_init_game_kit = nme.Loader.load("init_game_kit",0);
private static var nmex_show_achievements = nme.Loader.load("show_achievements",0);
private static var nmex_show_leaderboard_for_category = nme.Loader.load("show_leaderboard_for_category",1);
private static var nmex_report_score_for_category = nme.Loader.load("report_score_for_category",2);
private static var nmex_report_achievement = nme.Loader.load("report_achievement",2);
private static var nmex_reset_achievements = nme.Loader.load("reset_achievements",0);
private static var nmex_show_matchmaking_ui = nme.Loader.load("show_matchmaking_ui",0);
private static var nmex_start_turn_based_match = nme.Loader.load("start_turn_based_match",0);
private static var nmex_start_rematch = nme.Loader.load("start_rematch",2);
private static var nmex_load_turn_based_matches = nme.Loader.load("load_turn_based_matches",1);
private static var nmex_load_player_data = nme.Loader.load("load_player_data", 2);
private static var nmex_broadcast_match_data = nme.Loader.load("broadcast_match_data",1);
private static var nmex_is_match_started = nme.Loader.load("is_match_started",0);
private static var nmex_in_live_match = nme.Loader.load("in_live_match",0);
private static var nmex_in_turn_based_match = nme.Loader.load("in_turn_based_match",0);
private static var nmex_set_current_turn_based_match = nme.Loader.load("set_current_turn_based_match",1);
private static var nmex_disconnect_match = nme.Loader.load("disconnect_match",0);
private static var nmex_get_player_id = nme.Loader.load("get_player_id",0);
private static var nmex_get_match_num_players = nme.Loader.load("get_match_num_players",0);
private static var nmex_get_match_player_id = nme.Loader.load("get_match_player_id",1);
private static var nmex_get_match_data = nme.Loader.load("get_match_data",2);
private static var nmex_advance_match = nme.Loader.load("advance_match",4);
private static var nmex_pause_match = nme.Loader.load("pause_match",3);
private static var nmex_end_match = nme.Loader.load("end_match",5);
private static var nmex_quit_match = nme.Loader.load("quit_match",3);
private static var nmex_remove_match = nme.Loader.load("remove_match",2);
private static var nmex_get_player_png = nme.Loader.load("get_player_png",1);
private static var nmex_is_user_authenticated = nme.Loader.load("is_user_authenticated",0);

}
#end
