/**
 * Copyright (c) 2011 Milkman Games, LLC <http://www.milkmangames.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
#ifndef GAME_CENTER
#define GAME_CENTER

namespace nmeExtensions {
	bool hxInitGameKit();
	bool hxIsGameCenterAvailable();
	bool hxIsUserAuthenticated();
	void hxAuthenticateLocalUser();
	void registerForAuthenticationNotification();
	void hxShowAchievements();
	void hxResetAchievements();
	void hxReportScoreForCategory(int score, const char *category);
	void hxReportAchievement(const char *achievementId, float percent);
	void hxShowLeaderBoardForCategory(const char *category);
  void hxShowMatchmakingUI();
  void hxStartTurnBasedMatch();
  void hxRematch(const char* matchID, int requestID);
  void hxBroadcastMatchData(const char *data);
  bool hxIsMatchStarted();
  bool hxInLiveMatch();
  bool hxInTurnBasedMatch();
  void hxSetCurrentTurnBasedMatch(const char* matchID);
  void hxGetPlayerID(char* output, int maxLen);
  void hxDisconnectMatch();
  int hxGetNumMatchPlayers();
  void hxLoadPlayerData(const char* ids, int requestID);
  char* hxGetPlayerPhotoPNG(const char* idStr, int* len);

  void hxLoadTurnBasedMatches(int requestID);
  bool hxGetMatchPlayerID(int index, char* output, int maxLen);
  void hxGetMatchData(const char* matchID, int requestID);
  void hxAdvanceTurnBasedMatch(const char* matchID, const char* message, const char* matchData, int matchDataLen, int requestID);
  void hxPauseTurnBasedMatch(const char* matchID, const char* matchData, int matchDataLen, int requestID);
  void hxEndTurnBasedMatch(const char* matchID, const char* winningPlayerID, const char* message, const char* matchData, int matchDataLen, int requestID);
  void hxQuitTurnBasedMatch(const char* matchID, const char* matchData, int matchDataLen, int requestID);
  void hxRemoveTurnBasedMatch(const char* matchID, int requestID);
}

#endif


