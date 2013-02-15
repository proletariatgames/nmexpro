// DO NOT EDIT
//   Generated from javascripts/dashboard/user.coffee
//
(function() {
  var achievementsNode, achievementsSubtitleNode, actionBannerNode, actionUrl, avatarNode, completeProfileNode, findFriendsNode, friendsNotificationNode, gameNameNodes, headerNode, headerReplacementNode, infoCellLoadingNode, infoCellNode, leaderboardsNode, numberTrim, pendingFriendsNode, playingNode, unapprovedNode, updateWhoIsPlaying, userNameNode, wallNotificationNode, wallPostsNode, winHeight, winWidth;
  var __indexOf = Array.prototype.indexOf || function(item) {
    for (var i = 0, l = this.length; i < l; i++) {
      if (this[i] === item) return i;
    }
    return -1;
  };
  headerReplacementNode = $('#header_replacement');
  headerNode = $('#header');
  infoCellNode = $('#info_cell');
  infoCellLoadingNode = infoCellNode.find('.loading');
  gameNameNodes = $('.game_name');
  userNameNode = infoCellNode.find('.user_name');
  playingNode = infoCellNode.find('.playing');
  avatarNode = infoCellNode.find('.avatar');
  pendingFriendsNode = $('#pending_friends');
  friendsNotificationNode = $('#friends_notification');
  wallPostsNode = $('#wall_posts');
  wallNotificationNode = $('#wall_notification');
  actionBannerNode = $('#action_banner');
  findFriendsNode = actionBannerNode.find('.find_friends');
  completeProfileNode = actionBannerNode.find('.complete_profile');
  actionUrl = '';
  leaderboardsNode = $('#leaderboards');
  achievementsNode = $('#achievements');
  achievementsSubtitleNode = achievementsNode.find('.subtitle');
  unapprovedNode = $('#unapproved');
  winWidth = $(window).width();
  winHeight = $(window).height();
  if (headerReplacementNode.length > 0) {
    headerNode.remove();
    headerReplacementNode.attr('id', 'header');
  }
  infoCellNode.touch(function() {
    return OF.push('dashboard/profile', {
      params: {
        user: OF.user
      }
    });
  });
  friendsNotificationNode.touch(function() {
    return OF.push('dashboard/friend_requests');
  });
  wallNotificationNode.touch(function() {
    return OF.push('dashboard/profile', {
      params: {
        user: OF.user
      }
    });
  });
  actionBannerNode.touch(function() {
    return setTimeout(function() {
      return OF.push(actionUrl);
    }, 300);
  });
  achievementsNode.touch(function() {
    return OF.push('dashboard/achievements', {
      params: {
        user: OF.user
      }
    });
  });
  numberTrim = function(num) {
    if (num > 999) {
      num = 999;
    }
    return num;
  };
  OF.page.update = function() {
    var friendNum, wallNum;
    if (OF.user.profile_picture_url != null) {
      avatarNode.css('background-image', "url(" + (userPicUrl(OF.user.profile_picture_url)) + ")");
    } else {
      avatarNode.css('background-image', null);
    }
    userNameNode.html(OF.user.name);
    gameNameNodes.html(OF.game.name);
    playingNode.unhide();
    friendNum = OF.user.received_friend_requests_pending_count;
    if (friendNum > 0) {
      friendNum = numberTrim(friendNum);
      pendingFriendsNode.html(friendNum);
      friendsNotificationNode.unhide();
    } else {
      pendingFriendsNode.html('');
      friendsNotificationNode.addClass('hidden');
    }
    wallNum = OF.user.not_viewed_wall_items_count;
    if (wallNum > 0) {
      wallNum = numberTrim(wallNum);
      wallPostsNode.html(wallNum);
      wallNotificationNode.unhide();
    } else {
      wallPostsNode.html('');
      wallNotificationNode.addClass('hidden');
    }
    if (OF.user.has_set_name && OF.user.profile_picture_url) {
      completeProfileNode.addClass('hidden');
      findFriendsNode.unhide();
      actionUrl = 'dashboard/me/friends?find_friends=true';
    } else {
      completeProfileNode.unhide();
      actionUrl = 'settings/profile_configuration';
    }
    return actionBannerNode.unhide();
  };
  OF.localUserLoaded(function() {
    infoCellLoadingNode.hide();
    OF.page.update();
    if ((OF.user.features != null) && __indexOf.call(OF.user.features, 'who_is_playing') >= 0 && !OF.page.params.spotlight) {
      return OF.api("/xp/games/" + OF.game.id + "/users", {
        background: true,
        success: function(data) {
          return updateWhoIsPlaying(data.users);
        }
      });
    }
  });
  updateWhoIsPlaying = function(users) {
    var displayCount, player, playerHtml, playerTmpl, players, playersNode, threshold, whoElsePlayingNode, _i, _len;
    players = users.items;
    whoElsePlayingNode = $('#who_else_playing');
    if (players.length > 0) {
      whoElsePlayingNode.unhide();
    } else {
      whoElsePlayingNode.addClass('hidden');
      return;
    }
    playersNode = $('#players');
    playerTmpl = tmpl('player');
    playerHtml = '';
    displayCount = 0;
    threshold = 4;
    for (_i = 0, _len = players.length; _i < _len; _i++) {
      player = players[_i];
      displayCount++;
      player.class_name = 'offline';
      player.style = '';
      player.data_href = "data-href='dashboard/profile?user_id=" + player.id + "'";
      if (player.online === true) {
        player.class_name = 'online';
      }
      if (player.profile_picture_url != null) {
        player.style = "background-image: url(" + player.profile_picture_url + ")";
      }
      if (displayCount > threshold) {
        player.class_name += ' additional';
      }
      playerHtml += playerTmpl(player);
    }
    return playersNode.html(playerHtml);
  };
  if (OF.page.params.spotlight != null) {
    leaderboardsNode.hide();
    achievementsNode.hide();
  } else {
    OF.api("/xp/games/" + OF.game.id, {
      background: true,
      success: function(data) {
        if (data.game.leaderboards.total < 1) {
          leaderboardsNode.hide();
        }
        if (data.game.achievements.total < 1) {
          achievementsNode.hide();
        }
        if (!data.game.approved_for_current_platform) {
          return unapprovedNode.removeClass('hidden').hide().slideDown();
        }
      }
    });
    OF.api("/xp/users/" + OF.user.id + "/games/" + OF.game.id + "/achievements", {
      background: true,
      failure: $.noop,
      success: function(data) {
        var total, unlocked;
        total = data.achievements.length;
        unlocked = 0;
        $.each(data.achievements, function() {
          if (this.achievement.is_unlocked) {
            return unlocked++;
          }
        });
        return achievementsSubtitleNode.hide().text("" + unlocked + " out of " + total + " unlocked").fadeIn();
      }
    });
  }
}).call(this);
