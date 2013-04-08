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

#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
#import <GameKit/GameKit.h>
#include <ctype.h>
#include "Events.h"

namespace nme {
  void PauseAnimation();
  void ResumeAnimation();
}

/** ViewDelegate Objective-C Wrappers
 *
 * As far as I can tell it is not possible to let a vanilla c function
 * take a delegate callback, so we need to create these obj-c objects
 * to wrap the callbacks in.
 *
 */
typedef void (*FunctionType)();
typedef void (*MatchFunctionType)(GKMatch*);
typedef void (*TurnBasedMatchFunctionType)(GKTurnBasedMatch*);
typedef void (*TurnEventFunctionType)(GKTurnBasedMatch*, BOOL);
typedef void (*MatchPlayerFunctionType)(GKMatch*, NSString*);
typedef void (*DataFunctionType)(NSString*, NSString*);
typedef void (*InviteFunctionType)(NSArray*);

@interface GKViewDelegate 
  : NSObject <GKAchievementViewControllerDelegate,
              GKLeaderboardViewControllerDelegate,
              GKMatchmakerViewControllerDelegate,
              GKTurnBasedMatchmakerViewControllerDelegate,
              GKMatchDelegate,
              GKTurnBasedEventHandlerDelegate,
              GKFriendRequestComposeViewControllerDelegate>{
}

- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController;
- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController;
- (void)matchmakerViewControllerWasCancelled:(GKMatchmakerViewController*)viewController;
- (void)matchmakerViewController:(GKMatchmakerViewController *)viewController didFailWithError:(NSError *)error;
- (void)turnBasedMatchmakerViewController:(GKTurnBasedMatchmakerViewController *)viewController didFailWithError:(NSError *)error;
- (void)turnBasedMatchmakerViewController:(GKTurnBasedMatchmakerViewController *)viewController didFindMatch:(GKTurnBasedMatch *)match;
- (void)turnBasedMatchmakerViewController:(GKTurnBasedMatchmakerViewController *)viewController playerQuitForMatch:(GKTurnBasedMatch *)match;
- (void)turnBasedMatchmakerViewControllerWasCancelled:(GKTurnBasedMatchmakerViewController *)viewController;
- (void)match:(GKMatch *)match player:(NSString *)playerID didChangeState:(GKPlayerConnectionState)state;
- (void)match:(GKMatch *)match didReceiveData:(NSData *)data fromPlayer:(NSString *)playerID;
- (void)handleInviteFromGameCenter:(NSArray *)playersToInvite;
- (void)handleMatchEnded:(GKTurnBasedMatch *)match;
- (void)handleTurnEventForMatch:(GKTurnBasedMatch *)match didBecomeActive:(BOOL)didBecomeActive;
- (void)friendRequestComposeViewControllerDidFinish:(GKFriendRequestComposeViewController *)viewController;

@property (nonatomic) FunctionType onAchievementFinished;
@property (nonatomic) FunctionType onLeaderboardFinished;
@property (nonatomic) MatchFunctionType onPlayerConnectedToMatch;
@property (nonatomic) MatchPlayerFunctionType onPlayerDisconnectedFromMatch;
@property (nonatomic) MatchFunctionType onMatchmakingFinished;
@property (nonatomic) TurnBasedMatchFunctionType onTurnBasedMatchmakingFinished;
@property (nonatomic) DataFunctionType onDataReceived;
@property (nonatomic) InviteFunctionType onTurnBasedInviteReceived;
@property (nonatomic) TurnBasedMatchFunctionType onTurnBasedMatchEnd;
@property (nonatomic) TurnEventFunctionType onTurnEventForMatch;

@end

@implementation GKViewDelegate

@synthesize onAchievementFinished;
@synthesize onLeaderboardFinished;
@synthesize onMatchmakingFinished;
@synthesize onPlayerConnectedToMatch;
@synthesize onPlayerDisconnectedFromMatch;
@synthesize onDataReceived;
@synthesize onTurnBasedMatchmakingFinished;
@synthesize onTurnBasedInviteReceived;
@synthesize onTurnBasedMatchEnd;
@synthesize onTurnEventForMatch;

- (id)init {
    self = [super init];
    return self;
}

- (void)dealloc {
    [super dealloc];
}

- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController{
    [viewController dismissModalViewControllerAnimated:YES];
	[viewController.view.superview removeFromSuperview];
	[viewController release];
	onAchievementFinished();
}

- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController{
    [viewController dismissModalViewControllerAnimated:YES];
	[viewController.view.superview removeFromSuperview];
	[viewController release];
	onLeaderboardFinished();
}

- (void)matchmakerViewControllerWasCancelled:(GKMatchmakerViewController*)viewController {
  printf("matchmakerViewController wasCancelled!\n");
  [viewController dismissViewControllerAnimated:YES completion:nil];
	[viewController release];
  nme::ResumeAnimation();
  onMatchmakingFinished(nil);
}

- (void)matchmakerViewController:(GKMatchmakerViewController *)viewController didFailWithError:(NSError *)error
{
  printf("matchmakerViewController didFailWithError: %s\n", [[error localizedDescription] UTF8String]);
  [viewController dismissViewControllerAnimated:YES completion:nil];
	[viewController release];
  nme::ResumeAnimation();
  onMatchmakingFinished(nil);
}

- (void)matchmakerViewController:(GKMatchmakerViewController *)viewController didFindMatch:(GKMatch *)match
{
  printf("matchmakerViewController didFindMatch OK\n");
  [viewController dismissViewControllerAnimated:YES completion:nil];
  match.delegate = self;
  nme::ResumeAnimation();
  if ( match.expectedPlayerCount == 0 && [match.playerIDs count] != 0 ) {
    onMatchmakingFinished(match);
  } else {
    printf("matchmakerViewController found match, but no players!\n");
    if ( match != nil ) {
      [match disconnect];
    }
    onMatchmakingFinished(nil);
  }
}

- (void)match:(GKMatch *)match player:(NSString *)playerID didChangeState:(GKPlayerConnectionState)state
{
  switch ( state ) {
  case GKPlayerStateConnected:
    printf("GKPlayerStateConnected\n");
    onPlayerConnectedToMatch(match);
  break;

  case GKPlayerStateDisconnected:
    printf("GKPlayerStateDisconnected\n");
    onPlayerDisconnectedFromMatch(match, playerID);
  break;
  }
}

- (void)match:(GKMatch *)match didReceiveData:(NSData *)data fromPlayer:(NSString *)playerID
{
  NSString *string = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];
  onDataReceived(playerID, string);
}

- (void)turnBasedMatchmakerViewController:(GKTurnBasedMatchmakerViewController *)viewController didFailWithError:(NSError *)error
{
  printf("matchmakerViewController didFailWithError: %s\n", [[error localizedDescription] UTF8String]);
  [viewController dismissViewControllerAnimated:YES completion:nil];
	[viewController release];
  nme::ResumeAnimation();
  onTurnBasedMatchmakingFinished(nil);
}

- (void)turnBasedMatchmakerViewController:(GKTurnBasedMatchmakerViewController *)viewController didFindMatch:(GKTurnBasedMatch *)match
{
  printf("turnBasedMatchmakerViewController didFindMatch\n");
  [viewController dismissViewControllerAnimated:YES completion:nil];
	[viewController release];
  nme::ResumeAnimation();
  onTurnBasedMatchmakingFinished(match);
}

- (void)turnBasedMatchmakerViewController:(GKTurnBasedMatchmakerViewController *)viewController playerQuitForMatch:(GKTurnBasedMatch *)match
{
  // !!FIXME!! this is not handled currently
  printf("turnBasedMatchmakerViewController playerQuitForMatch\n");
  [viewController dismissViewControllerAnimated:YES completion:nil];
	[viewController release];
  nme::ResumeAnimation();
}

- (void)turnBasedMatchmakerViewControllerWasCancelled:(GKTurnBasedMatchmakerViewController *)viewController
{
  printf("turnBasedMatchmakerViewControllerWasCancelled\n");
  [viewController dismissViewControllerAnimated:YES completion:nil];
	[viewController release];
  nme::ResumeAnimation();
  onTurnBasedMatchmakingFinished(nil);
}

- (void)handleInviteFromGameCenter:(NSArray *)playersToInvite
{
  printf("handleInviteFromGameCenter\n");
  onTurnBasedInviteReceived(playersToInvite);
}

- (void)handleMatchEnded:(GKTurnBasedMatch *)match
{
  printf("handleMatchEnded\n");
  onTurnBasedMatchEnd(match);
}

- (void)handleTurnEventForMatch:(GKTurnBasedMatch *)match didBecomeActive:(BOOL)didBecomeActive
{
  printf("handleTurnEventForMatch\n");
  onTurnEventForMatch(match, didBecomeActive);
}

- (void)friendRequestComposeViewControllerDidFinish:(GKFriendRequestComposeViewController *)viewController
{
  printf("friendRequestComposeViewControllerDidFinish\n");
  if (![viewController isBeingDismissed]) {
    [viewController dismissViewControllerAnimated:YES completion:nil];
  }
	[viewController release];
  nme::ResumeAnimation();
}

@end

namespace nmeExtensions{

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
  void hxStartTurnBasedMatch(const char *inviteUserID);
  void hxRematch(const char* matchID, int requestID);
  void hxLoadTurnBasedMatches(int requestID);
  void hxBroadcastMatchData(const char* data);
  bool hxIsMatchStarted();
  bool hxInLiveMatch();
  bool hxInTurnBasedMatch();
  void hxSetCurrentTurnBasedMatch(const char* matchID);
  void hxGetPlayerID(char* output, int maxLen);
  void hxGetPlayerAlias(char* output, int maxLen);
  void hxLoadPlayerData(const char* ids, int requestID);
  char* hxGetPlayerPhotoPNG(const char* idStr, int* len);
  void hxDisconnectMatch();
  int hxGetNumMatchPlayers();
  bool hxGetMatchPlayerID(int index, char* output, int maxLen);
  void hxGetMatchData(const char* matchID, int requestID);
  void hxAdvanceTurnBasedMatch(const char* matchID, const char* message, const char* matchData, int matchDataLen, int requestID);
  void hxPauseTurnBasedMatch(const char* matchID, const char* matchData, int matchDataLen, int requestID);
  void hxEndTurnBasedMatch(const char* matchID, const char* winningPlayerID, const char* message, const char* matchData, int matchDataLen, int requestID);
  void hxQuitTurnBasedMatch(const char* matchID, const char* message, const char* matchData, int matchDataLen, int requestID);
  void hxRemoveTurnBasedMatch(const char* matchID, int requestID);
  void trackTurnBasedMatch(GKTurnBasedMatch* match);
  void hxLoadFriendIDs();
  void hxSendFriendRequest(const char* idsStr);

	static void authenticationChanged(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo);
	void achievementViewDismissed();
	void leaderboardViewDismissed();
  void matchmakingFinished(GKMatch* match);
  void playerConnectToMatch(GKMatch* match);
  void playerDisconnectFromMatch(GKMatch* match, NSString* player);
  void matchDataReceived(NSString* player, NSString* data);
  void turnBasedMatchmakingFinished(GKTurnBasedMatch* match);
  void turnBasedInviteReceived(NSArray* playerIds);
  void turnBasedMatchEnded(GKTurnBasedMatch* match);
  void turnEvent(GKTurnBasedMatch* match, BOOL didBecomeActive);
	void dispatchHaxeEvent(EventType eventId);
	extern "C" void nme_extensions_send_event(Event &inEvent);
	extern "C" void nme_extensions_send_event_with_len(Event &inEvent, int len);
	
	//
	// Variables
	//
	
	/** Initialization State */
	static int isInitialized=0;
  static int registeredAuthHandler=0;
	
	/** View Delegate */
	static GKViewDelegate *ViewDelegate;
	
  static GKMatch* currentMatch;
  static NSMutableDictionary* playerPhotos = nil;
  static GKTurnBasedMatch* currentTurnBasedMatch;
  static bool currentMatchStarted = false;
  
  static UIViewController* s_authViewController = nil;
  static NSMutableArray* loadedTurnBasedMatches;

  static int MAX_PACKET_SIZE = 64*1024;
	
	//
	// Public Methods
	//
	
	/** Initialize Haxe GK.  Return true if success, false otherwise. */
	bool hxInitGameKit(){
		// don't create twice.
		if(isInitialized==1){
			return false;
		}
		
		if (hxIsGameCenterAvailable()){
			// create the GameCenter object, and get user.
			ViewDelegate=[[GKViewDelegate alloc] init];
			ViewDelegate.onAchievementFinished=&achievementViewDismissed;
			ViewDelegate.onLeaderboardFinished=&leaderboardViewDismissed;
      ViewDelegate.onMatchmakingFinished=&matchmakingFinished;
      ViewDelegate.onTurnBasedMatchmakingFinished=&turnBasedMatchmakingFinished;
      ViewDelegate.onPlayerConnectedToMatch=&playerConnectToMatch;
      ViewDelegate.onPlayerDisconnectedFromMatch=&playerDisconnectFromMatch;
      ViewDelegate.onDataReceived=&matchDataReceived;
      ViewDelegate.onTurnBasedInviteReceived=&turnBasedInviteReceived;
      ViewDelegate.onTurnBasedMatchEnd=&turnBasedMatchEnded;
      ViewDelegate.onTurnEventForMatch=&turnEvent;

      [GKTurnBasedEventHandler sharedTurnBasedEventHandler].delegate = ViewDelegate;

      [GKMatchmaker sharedMatchmaker].inviteHandler = ^(GKInvite *acceptedInvite, NSArray *playersToInvite) {
        // Insert game-specific code here to clean up any game in progress.
        if (acceptedInvite)
        {
          NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
          GKMatchmakerViewController *mmvc = [[GKMatchmakerViewController alloc] initWithInvite:acceptedInvite];
          mmvc.matchmakerDelegate = ViewDelegate;

          nme::PauseAnimation();
          UIWindow* window = [UIApplication sharedApplication].keyWindow;
          [[window rootViewController] presentModalViewController: mmvc animated:NO];
          [pool drain];
        }
        else if (playersToInvite)
        {
          hxShowMatchmakingUI();
        }
      };
			isInitialized=1;
			return true;
		}
		
		return false;
	}
	
	/** Check if Game Center is available on this device. */
	bool hxIsGameCenterAvailable(){
		// Check for presence of GKLocalPlayer API.   
		Class gcClass = (NSClassFromString(@"GKLocalPlayer"));   
		
		// The device must be running running iOS 4.1 or later.   
		NSString *reqSysVer = @"4.1";   
		NSString *currSysVer = [[UIDevice currentDevice] systemVersion];   
		BOOL osVersionSupported = ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending);   
		
		return (gcClass && osVersionSupported);
	}

	/** Attempt Authentication of the Player */
	void hxAuthenticateLocalUser() {
		printf("CPP HxgK: Auth user\n");
		if(!hxIsGameCenterAvailable()){
			return;
		}

    if ( s_authViewController != nil ) {
      printf("Displaying auth UI\n");
      UIWindow* window = [UIApplication sharedApplication].keyWindow;
      [[window rootViewController] presentModalViewController: s_authViewController animated:NO];
    } else if ( registeredAuthHandler == 0 && [GKLocalPlayer instancesRespondToSelector:@selector(authenticateHandler)] ) {
      printf("Register for authentication via authenticateHandler\n");
      registeredAuthHandler = 1;
      [GKLocalPlayer localPlayer].authenticateHandler = ^(UIViewController* authViewController, NSError* error) {
        if ( authViewController != nil ) {
          NSLog(@"Retain auth view controller");
          s_authViewController = authViewController; 
          [s_authViewController retain];
        } else {
          if ( error != nil ) {
            NSLog(@"AuthError %@", error);
            dispatchHaxeEvent(AUTH_FAILED);
          } else {
            NSLog(@"Auth success");
            dispatchHaxeEvent(AUTH_SUCCEEDED);
          }
        }
      };
    } else {
      [[GKLocalPlayer localPlayer] authenticateWithCompletionHandler:^(NSError *error) {      
        if (error == nil){
          registerForAuthenticationNotification();
          dispatchHaxeEvent(AUTH_SUCCEEDED);
        }else{
          NSLog(@"  %@", [error userInfo]);
          dispatchHaxeEvent(AUTH_FAILED);
        }
      }];
    }
	}

	/** Return true if the local player is logged in */
	bool hxIsUserAuthenticated(){
		if ([GKLocalPlayer localPlayer].isAuthenticated){
			return true;
		}
		return false;
	}

  void hxGetPlayerID(char* output, int maxLen) {
    [[GKLocalPlayer localPlayer].playerID getCString:output maxLength:maxLen encoding:NSUTF8StringEncoding];
  }

  void hxGetPlayerAlias(char* output, int maxLen) {
    [[GKLocalPlayer localPlayer].alias getCString:output maxLength:maxLen encoding:NSUTF8StringEncoding];
  }

  void hxLoadFriendIDs() {
    GKLocalPlayer *lp = [GKLocalPlayer localPlayer];
    if (lp.authenticated) {
      [lp loadFriendsWithCompletionHandler:^(NSArray *friendIDs, NSError *error) {
        if (error == nil) {
          NSError *jsonError = nil;
          NSData *jsonData = [NSJSONSerialization dataWithJSONObject:friendIDs options:0 error:&jsonError];
          NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
          if (jsonError) {
            NSLog(@"Could not parse player info : %@",jsonError);
            Event evt(LOAD_FRIEND_IDS_FAIL);
            evt.data = "bad data";
            nme_extensions_send_event(evt);
          } else {
            Event evt(LOAD_FRIEND_IDS_SUCCESS);
            evt.data = [jsonString UTF8String];
            nme_extensions_send_event(evt);
          }
          [jsonString release];
        } else {
          NSLog(@"Could not load friends : %@",error);
          Event evt(LOAD_FRIEND_IDS_FAIL);
          evt.data = "couldn't load friend ids";
          nme_extensions_send_event(evt);
        }
      }];
    }
  }

  void hxLoadPlayerData(const char* idsStr, int requestID) {
    if ( !playerPhotos ) {
      playerPhotos = [[NSMutableDictionary alloc] init];
    }

    NSString* strIds = [[NSString alloc] initWithUTF8String:idsStr];
    NSArray* ids = [strIds componentsSeparatedByString:@","];

    [GKPlayer loadPlayersForIdentifiers:ids withCompletionHandler:^(NSArray* players, NSError* error) {
      if ( error == nil ) {
        NSMutableArray* returnData = [[NSMutableArray alloc] init];
        for ( GKPlayer* player in players ) {
          [player loadPhotoForSize:GKPhotoSizeNormal withCompletionHandler:^(UIImage* photo, NSError* picError) {
            if ( picError != nil ) {
              NSLog(@"Could not load photo for player %@ : %@", [player playerID], picError);
            } else if ( photo != nil ) {
              [playerPhotos setValue:photo forKey:[player playerID]];
            }

            NSDictionary* playerData = [[NSDictionary alloc] initWithObjectsAndKeys:
                                          [player playerID], @"id",
                                          [NSNumber numberWithBool:[player isFriend]], @"isFriend",
                                          [player alias], @"alias",
                                          nil];
            [returnData addObject:playerData];
            [playerData release];

            if ( [returnData count] == [players count] ) {
              NSError *jsonError = nil;
              NSData *jsonData = [NSJSONSerialization dataWithJSONObject:returnData options:0 error:&jsonError];
              NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
              if (jsonError) {
                NSLog(@"Could not parse player info : %@",jsonError);
                Event evt(LOAD_PLAYER_DATA_FAIL);
                evt.data = "bad player data";
                evt.code = requestID;
                nme_extensions_send_event(evt);
              } else {
                Event evt(LOAD_PLAYER_DATA_SUCCESS);
                evt.data = [jsonString UTF8String];
                evt.code = requestID;
                nme_extensions_send_event(evt);
              }

              [jsonString release];
              [returnData release];
            }
          }];
        }
      } else {
        NSLog(@"Could not load player info : %@",error);
        Event evt(LOAD_PLAYER_DATA_FAIL);
        evt.data = "couldn't load player data";
        evt.code = requestID;
        nme_extensions_send_event(evt);
      }
    }];

    [strIds release];
  }

  char* hxGetPlayerPhotoPNG(const char* idStr, int* len) {
    *len = 0;
    if ( playerPhotos == nil ) return NULL;
    NSString* str = [[NSString alloc] initWithUTF8String:idStr];
    UIImage* image = [playerPhotos objectForKey:str];
    if ( image == nil ) return NULL;
    NSData* pngData = UIImagePNGRepresentation(image);
    if ( pngData == nil ) return NULL;

    char* buffer = (char*)malloc([pngData length]);
    [pngData getBytes:buffer length:[pngData length]];
    *len = [pngData length];

    [str release];
    return buffer;
  }
	
	/** Report a score to the server for a given category. */
	void hxReportScoreForCategory(int score, const char *category){
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
		NSString *strCategory = [[NSString alloc] initWithUTF8String:category];
		
		GKScore *scoreReporter = [[[GKScore alloc] initWithCategory:strCategory] autorelease];
		if(scoreReporter){
			scoreReporter.value = score;
			
			[scoreReporter reportScoreWithCompletionHandler:^(NSError *error) {   
				if (error != nil){
					printf("CPP Hxgk: Error occurred reporting score-\n");
					NSLog(@"  %@", [error userInfo]);
					dispatchHaxeEvent(SCORE_REPORT_FAILED);
				}else{
					printf("CPP Hxgk: Score was successfully sent\n");
					dispatchHaxeEvent(SCORE_REPORT_SUCCEEDED);
				}
			}];   
		}
		[strCategory release];
		[pool drain];
	}

  /** Brings up the GameCenter UI for starting a new turn-based match. */
  void hxStartTurnBasedMatch(const char* i_inviteUserID) {
    NSString *inviteUserID = [[NSString alloc] initWithUTF8String:i_inviteUserID];
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    UIWindow* window = [UIApplication sharedApplication].keyWindow;
    GKMatchRequest* request = [[GKMatchRequest alloc] init];
    request.minPlayers = 2;
    request.maxPlayers = 2;
    if (inviteUserID && [inviteUserID length] > 0 ) {
      // If we are inviting someone start the match immediately
      request.playersToInvite = [[NSArray alloc]initWithObjects: inviteUserID, nil];
    }

    if ( true ) { // [[GKLocalPlayer localPlayer] friends] && [[[GKLocalPlayer localPlayer] friends] containsObject:inviteUserID]) {
      [GKTurnBasedMatch findMatchForRequest:request withCompletionHandler:^(GKTurnBasedMatch *match, NSError *error) {
        [request.playersToInvite release];
        [request release];
        if (error) {
          NSLog(@"Error starting match");
          turnBasedMatchmakingFinished(nil);
        } else {
          NSLog(@"Found match: %@", match);
          turnBasedMatchmakingFinished(match);
        }
      }];
    } else {
      GKTurnBasedMatchmakerViewController *mmvc = [[GKTurnBasedMatchmakerViewController alloc] initWithMatchRequest:request];
      mmvc.showExistingMatches = NO;
      mmvc.turnBasedMatchmakerDelegate = ViewDelegate;

      nme::PauseAnimation();
      [[window rootViewController] presentModalViewController: mmvc animated:NO];
      [request release];
    }

    [inviteUserID release];
    [pool drain];
  }

  GKTurnBasedMatch* findMatchWithID(const char* idToFind) {
    GKTurnBasedMatch* foundMatch = nil;
    NSString* matchIDStr = [[NSString alloc] initWithUTF8String:idToFind];
    if ( loadedTurnBasedMatches != nil ) {
      for ( GKTurnBasedMatch* match in loadedTurnBasedMatches ) {
        if ( [[match matchID] isEqualToString:matchIDStr] ) {
          foundMatch = match;
          break;
        }
      }
    }

    [matchIDStr release];
    return foundMatch;
  }

  void hxSendFriendRequest(const char* idsStr) {
    NSString* strIds = [[NSString alloc] initWithUTF8String:idsStr];
    NSArray* identifiers = [strIds componentsSeparatedByString:@","];

    GKFriendRequestComposeViewController *friendRequestViewController = [[GKFriendRequestComposeViewController alloc] init];
    friendRequestViewController.composeViewDelegate = ViewDelegate;
    if (identifiers) {
      [friendRequestViewController addRecipientsWithPlayerIDs: identifiers];
    }

    nme::PauseAnimation();
    UIWindow* window = [UIApplication sharedApplication].keyWindow;
    [[window rootViewController] presentModalViewController:friendRequestViewController animated:YES];
  }

  void hxGetMatchData(const char* matchID, int requestID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID); 
    if ( match != nil ) {
      [match loadMatchDataWithCompletionHandler:^(NSData* packet, NSError* error){
        if ( error == nil && packet != nil ) {
          char* data = (char*)malloc(MAX_PACKET_SIZE);
          [packet getBytes:data length:MAX_PACKET_SIZE];

          Event evt(GET_MATCH_DATA_SUCCESS);
          evt.data = data;
          evt.code = requestID;
          // need to specify length here, because the packet could contain null values
          nme_extensions_send_event_with_len(evt, [packet length]);

          free(data);
        } else {
          Event evt(GET_MATCH_DATA_FAIL);
          evt.data = "error getting match data";
          evt.code = requestID;
          nme_extensions_send_event(evt);
        }
      }];
    } else {
      Event evt(GET_MATCH_DATA_FAIL);
      evt.data = "bad match ID";
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  /** Sets the state for the match and advances it to the next player. The local player must be the current player in the match. */
  void hxAdvanceTurnBasedMatch(const char* matchID, const char* message, const char* matchData, int matchDataLen, int requestID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID);
    if ( match != nil ) {
      NSData* packet = [NSData dataWithBytes:matchData length:matchDataLen]; 
      NSMutableArray* nextPlayers = [[NSMutableArray alloc] init];
      for (GKTurnBasedParticipant* player in [match participants]) {
        if ( ![player.playerID isEqualToString:[GKLocalPlayer localPlayer].playerID] ) {
          NSLog(@"Adding player %@ as next player", player.playerID);
          [nextPlayers addObject:player];
        }
      }
      // [nextPlayers addObject:match.currentParticipant];

      NSString* messageStr = [[NSString alloc] initWithUTF8String:message];
      match.message = messageStr;
      [messageStr release];

      [match endTurnWithNextParticipants:nextPlayers turnTimeout:GKTurnTimeoutNone matchData:packet 
        completionHandler:^(NSError* error) {
          [nextPlayers release];
          
          if ( error != nil ) {
            NSLog(@"Could not advance match : %@",error);
            Event evt(UPDATE_MATCH_FAIL);
            evt.data = "failed to save match data";
            evt.code = requestID;
            nme_extensions_send_event(evt);
          } else {
            Event evt(UPDATE_MATCH_SUCCESS);
            evt.data = matchID;
            evt.code = requestID;
            nme_extensions_send_event(evt);
          }
        }
      ];

      if ( currentTurnBasedMatch == match ) {
        [currentTurnBasedMatch release];
        currentTurnBasedMatch = nil;
      }
    } else {
      Event evt(UPDATE_MATCH_FAIL);
      evt.data = "bad match ID";
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  /** Uploads the current state of the match without advancing to the next player. */
  void hxPauseTurnBasedMatch(const char* matchID, const char* matchData, int matchDataLen, int requestID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID);
    if ( match != nil ) {
      NSData* packet = [NSData dataWithBytes:matchData length:matchDataLen];
      [match saveCurrentTurnWithMatchData:packet completionHandler:^(NSError* error) {
        if ( error != nil ) {
          NSLog(@"Could not pause match : %@",error);
          Event evt(UPDATE_MATCH_FAIL);
          evt.data = "failed to save match data";
          evt.code = requestID;
          nme_extensions_send_event(evt);
        } else {
          Event evt(UPDATE_MATCH_SUCCESS);
          evt.data = matchID;
          evt.code = requestID;
          nme_extensions_send_event(evt);
        }
      }];

      if ( currentTurnBasedMatch == match ) {
        [currentTurnBasedMatch release];
        currentTurnBasedMatch = nil;
      }
    } else {
      Event evt(UPDATE_MATCH_FAIL);
      evt.data = "bad match ID";
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  void hxEndTurnBasedMatch(const char* matchID, const char* winningPlayerID, const char* message, const char* matchData, int matchDataLen, int requestID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID);

    if ( match != nil ) {

      NSString* messageStr = [[NSString alloc] initWithUTF8String:message];
      match.message = messageStr;
      [messageStr release];

      NSData* packet = [NSData dataWithBytes:matchData length:matchDataLen];
      // null winning player means a tie
      if ( !winningPlayerID || strlen(winningPlayerID) == 0 ) {
        for ( GKTurnBasedParticipant* player in match.participants ) {
          player.matchOutcome = GKTurnBasedMatchOutcomeTied; 
        }
      } else {
        NSString* winningPlayer = [[NSString alloc] initWithUTF8String:winningPlayerID];
        for ( GKTurnBasedParticipant* player in match.participants ) {
          if ( [player.playerID isEqualToString:winningPlayer] ) {
            player.matchOutcome = GKTurnBasedMatchOutcomeWon;
          } else {
            player.matchOutcome = GKTurnBasedMatchOutcomeLost;
          }
        }
        [winningPlayer release];
      }
      [match endMatchInTurnWithMatchData:packet completionHandler:^(NSError *error){
        if ( error != nil ) {
          NSLog(@"Could not end match : %@",error);
          Event evt(UPDATE_MATCH_FAIL);
          evt.data = "failed to save match data";
          evt.code = requestID;
          nme_extensions_send_event(evt);
        } else {
          Event evt(UPDATE_MATCH_SUCCESS);
          evt.data = matchID;
          evt.code = requestID;
          nme_extensions_send_event(evt);
        }
      }];

      if ( currentTurnBasedMatch == match ) {
        [currentTurnBasedMatch release];
        currentTurnBasedMatch = nil;
      }
    } else {
      Event evt(UPDATE_MATCH_FAIL);
      evt.data = "bad match ID";
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  /** Ends an open match that the player is a participant in. */
  void hxQuitTurnBasedMatch(const char* matchID, const char* message, const char* matchData, int matchDataLen, int requestID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID);
    if ( match != nil ) {
      NSString* messageStr = [[NSString alloc] initWithUTF8String:message];
      match.message = messageStr;
      [messageStr release];

      NSString* localPlayer = [GKLocalPlayer localPlayer].playerID;
      if ( match.currentParticipant != nil && [match.currentParticipant.playerID isEqualToString:localPlayer] ) {
        NSData* packet = [NSData dataWithBytes:matchData length:matchDataLen];
        // We are the current player and we're resigning, **OR** the other player resigned and we're formally ending the match.
        // Set everyone's status and end the game.
        for ( GKTurnBasedParticipant* player in match.participants ) {
          if ( [player.playerID isEqualToString:localPlayer] ) {
            if ( player.matchOutcome == GKTurnBasedMatchOutcomeNone ) {
              player.matchOutcome = GKTurnBasedMatchOutcomeQuit;
            }
          } else {
            if ( player.matchOutcome == GKTurnBasedMatchOutcomeNone ) {
              player.matchOutcome = GKTurnBasedMatchOutcomeWon;
            }
          }
        }
        [match endMatchInTurnWithMatchData:packet completionHandler:^(NSError *error){
          if ( error != nil ) {
            NSLog(@"Could not end match : %@",error);
            Event evt(UPDATE_MATCH_FAIL);
            evt.data = "failed to save match data";
            evt.code = requestID;
            nme_extensions_send_event(evt);
          } else {
            Event evt(UPDATE_MATCH_SUCCESS);
            evt.data = matchID;
            evt.code = requestID;
            nme_extensions_send_event(evt);
          }
        }];
      } else {
        // we are not the current player, and we're resigning.
        // note that this does not end the match. Only the current player can actually end the match.
        [match participantQuitOutOfTurnWithOutcome:GKTurnBasedMatchOutcomeQuit withCompletionHandler:^(NSError* error){
          if ( error != nil ) {
            NSLog(@"Could not resign match : %@",error);
            Event evt(UPDATE_MATCH_FAIL);
            evt.data = "failed to save match data";
            evt.code = requestID;
            nme_extensions_send_event(evt);
          } else {
            Event evt(UPDATE_MATCH_SUCCESS);
            evt.data = matchID;
            evt.code = requestID;
            nme_extensions_send_event(evt);
          }
        }];
      }

      if ( currentTurnBasedMatch == match ) {
        [currentTurnBasedMatch release];
        currentTurnBasedMatch = nil;
      }
    } else {
      Event evt(UPDATE_MATCH_FAIL);
      evt.data = "bad match ID";
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  void hxRemoveTurnBasedMatch(const char* matchID, int requestID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID);
    if ( match != nil ) {
      
      NSString* localPlayer = [GKLocalPlayer localPlayer].playerID;

      bool hasInvite = NO;
      for ( GKTurnBasedParticipant* player in match.participants ) {
        if ( [player.playerID isEqualToString:localPlayer] ) {
          if ( [player status] == GKTurnBasedParticipantStatusInvited ) {
            hasInvite = YES;
          }
          break;
        }
      }

      id completionHandler = ^(NSError* error) {
        if ( error != nil ) {
          NSLog(@"Could not remove match : %@",error);
          Event evt(UPDATE_MATCH_FAIL);
          evt.data = "failed to save match data";
          evt.code = requestID;
          nme_extensions_send_event(evt);
        } else {
          Event evt(UPDATE_MATCH_SUCCESS);
          evt.data = matchID;
          evt.code = requestID;
          nme_extensions_send_event(evt);
        }
      };

      if ( hasInvite ) {
        [match declineInviteWithCompletionHandler:completionHandler];
      } else {
        [match removeWithCompletionHandler:completionHandler];
      }

      if ( currentTurnBasedMatch == match ) {
        [currentTurnBasedMatch release];
        currentTurnBasedMatch = nil;
      }
    } else {
      printf("Could not find match : %s\n",matchID);
      Event evt(UPDATE_MATCH_FAIL);
      evt.data = "bad match ID";
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  NSString* turnBasedStatusToString(GKTurnBasedMatchStatus status) {
    switch(status) {
    case GKTurnBasedMatchStatusOpen: return @"open";
    case GKTurnBasedMatchStatusEnded: return @"ended";
    case GKTurnBasedMatchStatusMatching: return @"matching";
    default: return @"unknown";
    }
  }

  NSString* participantStatusToString(GKTurnBasedParticipantStatus status) {
    switch (status) {
    case GKTurnBasedParticipantStatusInvited: return @"invited";
    case GKTurnBasedParticipantStatusDeclined: return @"declined";
    case GKTurnBasedParticipantStatusMatching: return @"matching";
    case GKTurnBasedParticipantStatusActive: return @"active";
    default: return @"done";
    }
  }

  NSString* participantOutcomeToString(GKTurnBasedMatchOutcome outcome) {
    switch (outcome) {
    case GKTurnBasedMatchOutcomeNone: return @"none";
    case GKTurnBasedMatchOutcomeQuit: return @"quit";
    case GKTurnBasedMatchOutcomeWon: return @"won";
    case GKTurnBasedMatchOutcomeLost: return @"lost";
    case GKTurnBasedMatchOutcomeTied: return @"tied";
    case GKTurnBasedMatchOutcomeTimeExpired: return @"expired";
    case GKTurnBasedMatchOutcomeFirst: return @"first";
    case GKTurnBasedMatchOutcomeSecond: return @"second";
    case GKTurnBasedMatchOutcomeThird: return @"third";
    case GKTurnBasedMatchOutcomeFourth: return @"fourth";
    default: return @"unknown";
    }
  }

  /** Load match participant/status data for all turn-based matches the player is currently in. */
  void hxLoadTurnBasedMatches(int requestID) {
    [GKTurnBasedMatch loadMatchesWithCompletionHandler:^(NSArray *matches, NSError *error) {
      if ( loadedTurnBasedMatches != nil ) {
        [loadedTurnBasedMatches release];
        loadedTurnBasedMatches = nil;
      }

      if ( error != nil ) {
        NSLog(@"Failed to load matches: %@",error);
      }

      NSMutableArray *returnData = [[NSMutableArray alloc] init];
      if ( matches ) {
        loadedTurnBasedMatches = [matches mutableCopyWithZone:NULL];

        for ( GKTurnBasedMatch* match in loadedTurnBasedMatches ) {
          NSMutableArray* participantsData = [[NSMutableArray alloc] init];
          for ( GKTurnBasedParticipant* participant in [match participants] ) {
            NSDictionary* participantData = [[NSDictionary alloc] initWithObjectsAndKeys:
                                [NSNumber numberWithDouble:[[participant lastTurnDate] timeIntervalSince1970]], @"lastTurnDate",
                                participantStatusToString([participant status]), @"status",
                                participantOutcomeToString([participant matchOutcome]), @"outcome",
                                [participant playerID], @"playerID",
                                nil];
            [participantsData addObject:participantData];
            [participantData release];
          }
          NSDictionary *matchData = [[NSDictionary alloc] initWithObjectsAndKeys:
                              [match matchID], @"id",
                              participantsData, @"participants",
                              [NSNumber numberWithDouble:[[match creationDate] timeIntervalSince1970]], @"creationDate", 
                              turnBasedStatusToString([match status]), @"status",
                              [[match currentParticipant] playerID], @"currentPlayerID",
                              [match message], @"message", 
                              nil];
          [returnData addObject:matchData];
          [participantsData release];
          [matchData release];
        }
      }

      NSError *e = nil;
      NSData *jsonData = [NSJSONSerialization dataWithJSONObject:returnData options:0 error:&e];
      NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
      if (e) {
        NSLog(@"Could not parse match info : %@",e);
        Event evt(LOAD_TURN_BASED_MATCHES_FAIL);
        evt.data = "bad match data";
        evt.code = requestID;
        nme_extensions_send_event(evt);
      }  else {
        Event evt(LOAD_TURN_BASED_MATCHES_SUCCESS);
        evt.data = [jsonString UTF8String];
        evt.code = requestID;
        nme_extensions_send_event(evt);
      }

      [jsonString release];
      [returnData release];
    }];
  }
	
  /** Show the Default iOS matchmaking interface */
  void hxShowMatchmakingUI() {
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    UIWindow* window = [UIApplication sharedApplication].keyWindow;
    GKMatchRequest* request = [[GKMatchRequest alloc] init];
    request.minPlayers = 2;
    request.maxPlayers = 2;

    GKMatchmakerViewController *mmvc = [[GKMatchmakerViewController alloc] initWithMatchRequest:request];
    mmvc.matchmakerDelegate = ViewDelegate;

    nme::PauseAnimation();
    [[window rootViewController] presentModalViewController: mmvc animated:NO];
    [pool drain];
  }
	
	/** Show the Default iOS UI Leaderboard for a given category. */
	void hxShowLeaderBoardForCategory(const char *category){
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
		NSString *strCategory = [[NSString alloc] initWithUTF8String:category];
		
		UIWindow* window = [UIApplication sharedApplication].keyWindow;
		GKLeaderboardViewController *leaderboardController = [[GKLeaderboardViewController alloc] init];  
		if (leaderboardController != nil) {
			leaderboardController.category=strCategory;
			leaderboardController.leaderboardDelegate = ViewDelegate;
			
			UIViewController *glView2;
			if([[[UIDevice currentDevice] localizedModel] isEqualToString:@"iPad"]){
				glView2 = [[[UIApplication sharedApplication] keyWindow] rootViewController];
			}else{
				glView2 = [[UIViewController alloc] init];
				[window addSubview: glView2.view];
			}
			
			[glView2 presentModalViewController: leaderboardController animated: YES];
		}
		
		[strCategory release];
		[pool drain];
	}
	
	/** Report achievement progress to the server */
	void hxReportAchievement(const char *achievementId, float percent){
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
		NSString *strAchievement = [[NSString alloc] initWithUTF8String:achievementId];
		
		GKAchievement *achievement = [[[GKAchievement alloc] initWithIdentifier: strAchievement] autorelease];   
		if (achievement){      
			achievement.percentComplete = percent;    
			[achievement reportAchievementWithCompletionHandler:^(NSError *error){
				if (error != nil){
					printf("CPP Hxgk: Error occurred reporting achievement-\n");
					NSLog(@"  %@", [error userInfo]);
					dispatchHaxeEvent(ACHIEVEMENT_REPORT_FAILED);
				}else{
					printf("CPP Hxgk: Achievement report successfully sent\n");
					dispatchHaxeEvent(ACHIEVEMENT_REPORT_SUCCEEDED);
				}

			}];
		}else {
			//TODO: making this callback before function end means it is possible to get in a bad state if you're doing nested calls
			dispatchHaxeEvent(ACHIEVEMENT_REPORT_FAILED);
		}

		
		[strAchievement release];
		[pool drain];
	}
	
	/** Get the available achievements */
	void hxGetAchievements(){
		// TODO: will need to alloc and populate a list in a haxe format and return via another callback
	}
	
  bool hxInLiveMatch() {
    return currentMatch != nil;
  }

  bool hxInTurnBasedMatch() {
    return currentTurnBasedMatch != nil;
  }

  void hxSetCurrentTurnBasedMatch(const char* matchID) {
    GKTurnBasedMatch* match = findMatchWithID(matchID);
    if ( currentTurnBasedMatch != nil ) {
      [currentTurnBasedMatch release];
    }
    currentTurnBasedMatch = match;
    if ( currentTurnBasedMatch != nil ) {
      [currentTurnBasedMatch retain];
    }
  }

  int hxGetNumMatchPlayers() {
    if ( currentMatch == nil ) {
      return 0;
    }

    return [currentMatch.playerIDs count];
  }

  bool hxGetMatchPlayerID(int index, char* output, int maxLen) {
    if ( currentMatch != nil && index < [currentMatch.playerIDs count] ) {
      [[currentMatch.playerIDs objectAtIndex:index] getCString:output maxLength:maxLen encoding:NSUTF8StringEncoding];
      return true;
    }
    return false;
  }

  bool hxIsMatchStarted() {
    return currentMatchStarted;
  }

  void hxBroadcastMatchData(const char* data) {
    if ( currentMatchStarted ) {
      printf("Sending match data: %s\n", data);
      NSError* error;
      NSData* packet = [NSData dataWithBytes:data length:strlen(data)];
      [currentMatch sendDataToAllPlayers:packet withDataMode:GKMatchSendDataReliable error:&error];
      if ( error != nil ) {
        // handle the error
      }
    }
  }

  void hxDisconnectMatch() {
    if ( currentMatch != nil ) {
      [currentMatch disconnect];
      [currentMatch release];
      currentMatch = nil;
    }
  }

	/** Show Achievements with Default UI */
	void hxShowAchievements(){
		UIWindow* window = [UIApplication sharedApplication].keyWindow;
		GKAchievementViewController *achievements = [[GKAchievementViewController alloc] init];   
		if (achievements != nil){
			achievements.achievementDelegate = ViewDelegate;
			//UIViewController *glView2 = [[UIViewController alloc] init];
			//[window addSubview: glView2.view];
			UIViewController *glView2 = [[[UIApplication sharedApplication] keyWindow] rootViewController];
			[glView2 presentModalViewController: achievements animated: YES];
			// TODO: can we get the delegate to invoke a method properly timed for this event?
			dispatchHaxeEvent(ACHIEVEMENTS_VIEW_OPENED);
		}
	}
	
	/** Reset achievements */
	void hxResetAchievements(){
		[GKAchievement resetAchievementsWithCompletionHandler:^(NSError *error){
			 if (error != nil){
				 NSLog(@"  %@", [error userInfo]);
				 dispatchHaxeEvent(ACHIEVEMENT_RESET_FAILED);
			 }else{
				 dispatchHaxeEvent(ACHIEVEMENT_RESET_SUCCEEDED);
			 }
			 
		 }];
	}
	
	
	//
	// Implementation
	//
	
	/** Listen for Authentication Callback */
	void registerForAuthenticationNotification(){
		// TODO: need to REMOVE OBSERVER on dispose
		CFNotificationCenterAddObserver
		(
			CFNotificationCenterGetLocalCenter(),
			NULL,
			&authenticationChanged,
			(CFStringRef)GKPlayerAuthenticationDidChangeNotificationName,
			NULL,
			CFNotificationSuspensionBehaviorDeliverImmediately
		 );
	}
	
	/** Notify haXe of an Event */
	void dispatchHaxeEvent(EventType eventId){
		Event evt(eventId);
		nme_extensions_send_event(evt);
	}
	
	//
	// Callbacks
	//
	
	/** Callback When Achievement View is Closed */
	void achievementViewDismissed(){
		dispatchHaxeEvent(ACHIEVEMENTS_VIEW_CLOSED);
	}
	
	/** Callback When Leaderboard View is Closed */
	void leaderboardViewDismissed(){
		dispatchHaxeEvent(LEADERBOARD_VIEW_CLOSED);
	}
	
  void matchmakingFinished(GKMatch* match){
    printf("matchmakingFinished\n");
    if ( currentMatch != match ) {
      if ( currentMatch != nil ) {
        [currentMatch release];
      }
      currentMatch = match;      
      currentMatchStarted = false;
      if ( currentMatch != nil ) {
        [currentMatch retain];
      }
    }

    dispatchHaxeEvent(MATCHMAKING_VIEW_CLOSED);

    if ( !currentMatchStarted && currentMatch != nil && currentMatch.expectedPlayerCount == 0 ) {
      printf("Sending match started event\n");
      currentMatchStarted = true;
      dispatchHaxeEvent(MATCH_STARTED);
    }
  }

  void turnBasedMatchmakingFinished(GKTurnBasedMatch* match) {
    NSLog(@"turnBasedMatchmakingFinished: %@", match);
    if ( currentTurnBasedMatch != match ) {
      if ( currentTurnBasedMatch != nil ) {
        [currentTurnBasedMatch release];
      }
      currentTurnBasedMatch = match;      
      if ( currentTurnBasedMatch != nil ) {
        [currentTurnBasedMatch retain];
        trackTurnBasedMatch(currentTurnBasedMatch);
      }
    }

    dispatchHaxeEvent(MATCHMAKING_VIEW_CLOSED);

    if ( currentTurnBasedMatch != nil ) {
      Event evt(MATCH_STARTED);
      char matchID[256];
      [currentTurnBasedMatch.matchID getCString:matchID maxLength:256 encoding:NSUTF8StringEncoding];
      evt.data = matchID;
      nme_extensions_send_event(evt);
    }
  }

  void hxRematch(const char* matchID, int requestID) {
    GKTurnBasedMatch* oldMatch = findMatchWithID(matchID);
    if ( oldMatch != nil ) {
      [oldMatch removeWithCompletionHandler:^(NSError* error) {
        if ( error != nil ) {
          NSLog(@"Could not remove old match : %@",error);
        } 
        [oldMatch rematchWithCompletionHandler:^(GKTurnBasedMatch* newMatch, NSError* error) {
          if ( currentTurnBasedMatch != newMatch ) {
            if ( currentTurnBasedMatch != nil ) {
              [currentTurnBasedMatch release];
            }
            currentTurnBasedMatch = newMatch;
            if ( currentTurnBasedMatch != nil ) {
              trackTurnBasedMatch(currentTurnBasedMatch);
              [currentTurnBasedMatch retain];
            }
          }

          if ( currentTurnBasedMatch != nil ) {
            Event evt(REMATCH_STARTED);
            char newMatchID[256];
            [currentTurnBasedMatch.matchID getCString:newMatchID maxLength:256 encoding:NSUTF8StringEncoding];
            evt.code = requestID;
            evt.data = newMatchID;
            nme_extensions_send_event(evt);
          } else {
            Event evt(REMATCH_FAILED);
            evt.code = requestID;
            nme_extensions_send_event(evt);
          }
        }];
      }];
    } else {
      Event evt(REMATCH_FAILED);
      evt.code = requestID;
      nme_extensions_send_event(evt);
    }
  }

  void turnBasedInviteReceived(NSArray* playerIds) {
    NSString* playerId = [playerIds objectAtIndex:0];

    Event evt(TURN_BASED_MATCH_INVITE);
    evt.data = [playerId cStringUsingEncoding:NSUTF8StringEncoding];
    nme_extensions_send_event(evt);
  }

  void trackTurnBasedMatch(GKTurnBasedMatch* match) {
    if ( !loadedTurnBasedMatches ) {
      loadedTurnBasedMatches = [[NSMutableArray alloc] init];
    }
    for ( GKTurnBasedMatch* existingMatch in loadedTurnBasedMatches ) {
      if ( [existingMatch.matchID isEqualToString:match.matchID] ) {
        [loadedTurnBasedMatches removeObject:existingMatch]; 
        break;
      }
    }

    [loadedTurnBasedMatches addObject:match]; 
  }

  void turnBasedMatchEnded(GKTurnBasedMatch* match) {
    trackTurnBasedMatch(match);

    Event evt(TURN_BASED_MATCH_ENDED);
    evt.data = [match.matchID cStringUsingEncoding:NSUTF8StringEncoding];
    nme_extensions_send_event(evt);
  }

  void turnEvent(GKTurnBasedMatch* match, BOOL didBecomeActive) {
    trackTurnBasedMatch(match);

    Event evt(TURN_BASED_MATCH_TURN);
    evt.code = didBecomeActive;
    evt.data = [match.matchID cStringUsingEncoding:NSUTF8StringEncoding];
    nme_extensions_send_event(evt);
  }

  void playerConnectToMatch(GKMatch* match) {
    if ( match == currentMatch ) {
      if ( !currentMatchStarted && match.expectedPlayerCount == 0 ) {
        currentMatchStarted = true;
        dispatchHaxeEvent(MATCH_STARTED);
      }
    }
  }

  void playerDisconnectFromMatch(GKMatch* match, NSString* player){
    if ( match == currentMatch ) {
      Event evt(MATCH_PLAYER_DISCONNECTED);
      evt.data = [player cStringUsingEncoding:NSUTF8StringEncoding];
      nme_extensions_send_event(evt); 
    }
  }

  void matchDataReceived(NSString* player, NSString* data) {
		const char* str = [data cStringUsingEncoding:NSUTF8StringEncoding];
    Event evt(MATCH_DATA_RECEIVED);
    evt.data = str;
    nme_extensions_send_event(evt); 
  }

	/** Callback When Authentication Status Has Changed */
	void authenticationChanged(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo){
		if(!hxIsGameCenterAvailable()){
			return;
		}

		if ([GKLocalPlayer localPlayer].isAuthenticated){      
			printf("CPP Hxgk: You are logged in to game center:onAuthChanged \n");
		}else{
			printf("CPP Hxgk: You are NOT logged in to game center!:onAuthChanged \n");
		}
	}
}


