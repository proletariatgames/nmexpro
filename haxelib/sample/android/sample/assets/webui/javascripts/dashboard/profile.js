// DO NOT EDIT
//   Generated from javascripts/dashboard/profile.coffee
//
(function() {
  var addFriendTouchListener, bindLoadMoreEvent, bindPostMessageEvent, bindSetNameEvent, blockUserTouchListener, deleteMessageTouchListener, friendsBadgeNode, friendsNode, friendsNodeTouchListener, friendsSubtitleNode, gamesNode, gamesNodeTouchListener, gamesSubtitleNode, getProfileData, headerNode, headerTitleNode, infoCellNode, isLocalUser, loadMoreNode, loadMoreTouchListener, messagesContainerNode, moreTitleTouchListener, newMessageNode, postMessageFormNode, postMessageFormSubmitListener, postMessageNode, postNode, removeFriendTouchListener, renderFriendActionArea, renderMoreOptionsArea, reportUserTouchListener, setNameListener, setYourNameNode, statusNode, toggleFriendActionArea, unblockUserTouchListener, updateBasicInfo, updateGameFriendInfo, updateStatusContainerNode, updateStatusNode, updateWallInfo, useNameNode, userProfilePictureNode, userScoreNode, wallMessageTmpl;
  OF.page.user = OF.page.params.user || {
    id: OF.page.params.user_id
  };
  isLocalUser = parseInt(OF.page.user.id) === parseInt(OF.user.id);
  headerNode = $('#header');
  headerTitleNode = headerNode.find('.title');
  infoCellNode = $('#info_cell');
  useNameNode = $('.user_name');
  userScoreNode = infoCellNode.find('.user_score');
  userProfilePictureNode = infoCellNode.find('.avatar');
  statusNode = $('#status');
  updateStatusNode = $('#update_status');
  updateStatusContainerNode = $('.status_container');
  gamesNode = $('#games');
  gamesSubtitleNode = gamesNode.find('.subtitle');
  friendsNode = $('#friends');
  friendsSubtitleNode = friendsNode.find('.subtitle');
  friendsBadgeNode = $('#pending_friends');
  setYourNameNode = $('#set_your_name');
  postMessageNode = $('#post_message');
  postMessageFormNode = postMessageNode.find('form');
  postNode = $('#post');
  newMessageNode = $('#new_message');
  messagesContainerNode = $('#messages_container');
  loadMoreNode = $('#load_more');
  wallMessageTmpl = tmpl('message_tmpl');
  renderFriendActionArea = function(friendship) {
    var addFriendContainer, pendingFriendContainer, status, unblockUserContainer, userBannedByMe;
    addFriendContainer = $('#add_friend');
    pendingFriendContainer = $('#pending_friend');
    unblockUserContainer = $('#unblock_user');
    if (isLocalUser) {
      toggleFriendActionArea({
        add_friend: false,
        pending_friend: false,
        unblock_user: false
      });
      return;
    }
    status = friendship.status;
    userBannedByMe = friendship.ban_user_by_me_for_wall;
    if (userBannedByMe) {
      return toggleFriendActionArea({
        add_friend: false,
        pending_friend: false,
        unblock_user: true
      }, unblockUserContainer.find('.action_button').touch(unblockUserTouchListener));
    } else if (status === 'friends') {
      return toggleFriendActionArea({
        add_friend: false,
        pending_friend: false,
        unblock_user: false
      });
    } else if (status === 'unrelated') {
      toggleFriendActionArea({
        add_friend: true,
        pending_friend: false,
        unblock_user: false
      });
      return addFriendContainer.find('.action_button').touch(addFriendTouchListener);
    } else {
      return toggleFriendActionArea({
        add_friend: false,
        pending_friend: true,
        unblock_user: false
      });
    }
  };
  toggleFriendActionArea = function(areaVisiable) {
    var addFriendContainer, pendingFriendContainer, unblockUserContainer;
    addFriendContainer = $('#add_friend');
    pendingFriendContainer = $('#pending_friend');
    unblockUserContainer = $('#unblock_user');
    if (areaVisiable.add_friend) {
      addFriendContainer.unhide();
    } else {
      addFriendContainer.addClass('hidden');
    }
    if (areaVisiable.pending_friend) {
      pendingFriendContainer.unhide();
    } else {
      pendingFriendContainer.addClass('hidden');
    }
    if (areaVisiable.unblock_user) {
      return unblockUserContainer.unhide();
    } else {
      return unblockUserContainer.addClass('hidden');
    }
  };
  unblockUserTouchListener = function() {
    OF.GA.page('/webui/dashboard/profile_unblockUser');
    return OF.api("/xp/wall/banned_users/" + OF.page.user.id, {
      background: true,
      method: 'DELETE',
      success: function() {
        return OF.refresh();
      },
      failure: function() {
        return OF.alert('Oops', 'Oops! An error has occured.');
      }
    });
  };
  addFriendTouchListener = function() {
    OF.GA.page('/webui/dashboard/profile_addFriend');
    OF.api('/xp/friend_requests', {
      background: true,
      method: 'POST',
      params: {
        friend_id: OF.page.user.id
      },
      failure: function() {
        return OF.alert('Oops', 'Oops! An error has occured.');
      }
    });
    return toggleFriendActionArea({
      add_friend: false,
      pending_friend: true,
      unblock_user: false
    });
  };
  renderMoreOptionsArea = function(friendship) {
    var blockUserContainer, columnNum, moreOptionsContainer, removeFriendContainer, reportUserContainer, status, userBannedByMe;
    moreOptionsContainer = $('#more_options');
    columnNum = 3;
    removeFriendContainer = $('#remove_friend');
    blockUserContainer = $('#block_user');
    reportUserContainer = $('#report_user');
    if (isLocalUser) {
      moreOptionsContainer.addClass('hidden');
      return;
    }
    moreOptionsContainer.unhide();
    $('#more_title').touch(moreTitleTouchListener);
    status = friendship.status;
    userBannedByMe = friendship.ban_user_by_me_for_wall;
    if (status === 'friends') {
      removeFriendContainer.unhide().find('.badge_button').touch(removeFriendTouchListener);
    } else {
      removeFriendContainer.addClass('hidden');
      columnNum -= 1;
    }
    if (userBannedByMe) {
      blockUserContainer.addClass('hidden');
      columnNum -= 1;
    } else {
      blockUserContainer.unhide().find('.badge_button').touch(blockUserTouchListener);
    }
    reportUserContainer.find('.badge_button').touch(reportUserTouchListener);
    return moreOptionsContainer.find('.more_action').addClass("col" + columnNum);
  };
  moreTitleTouchListener = function() {
    return $(this).toggleClass('expanded').next('.more_action').toggleClass('hidden');
  };
  removeFriendTouchListener = function() {
    return OF.confirm('', 'Are you sure you want to remove this user as a friend?', 'Yes', 'No', function() {
      OF.GA.page('/webui/dashboard/profile_confirmRemoveFriend');
      return OF.api("/xp/friends/" + OF.page.user.id, {
        background: true,
        method: 'DELETE',
        success: function() {
          return OF.refresh();
        },
        failure: function() {
          return OF.alert('Oops', 'Oops! An error has occured.');
        }
      });
    }, function() {
      return OF.GA.page('/webui/dashboard/profile_cancelRemoveFriend');
    });
  };
  blockUserTouchListener = function() {
    return OF.confirm('', 'Are you sure you want to block this user so that this user won\'t be able to view your wall?', 'Yes', 'No', function() {
      OF.GA.page('/webui/dashboard/profile_confirmBlockUser');
      return OF.api('/xp/wall/banned_users', {
        background: true,
        method: 'POST',
        params: {
          user_id: OF.page.user.id
        },
        success: function() {
          return OF.refresh();
        },
        failure: function() {
          return OF.alert('Oops', 'Oops! An error has occured.');
        }
      });
    }, function() {
      return OF.GA.page('/webui/dashboard/profile_cancelBlockUser');
    });
  };
  reportUserTouchListener = function() {
    return OF.confirm('', 'Are you sure you want to submit an abuse report?', 'Yes, Report', 'Cancel', function() {
      OF.GA.page('/webui/dashboard/profile_confirmReportUser');
      return OF.api("/xp/users/" + OF.page.user.id + "/abuse_flags", {
        background: true,
        method: 'POST',
        params: {
          abuse_type: 'wall'
        },
        on406: function(data) {
          return OF.alert("Report forbidden", $.htmlDecode(data.exception.message));
        },
        failure: function(data, status) {
          if (!status.match(/^406/)) {
            OF.alert('Oops', 'Oops! An error has occured.');
            return false;
          }
        }
      });
    }, function() {
      return OF.GA.page('/webui/dashboard/profile_cancelReportUser');
    });
  };
  getProfileData = function(bannedMeByUser) {
    return OF.api("/xp/users/" + OF.page.user.id + "/profile", {
      success: function(data) {
        var currentStatus, notViewedWallItemsCount;
        OF.page.user = data.user;
        currentStatus = OF.page.user.status;
        notViewedWallItemsCount = OF.page.user.not_viewed_wall_items_count;
        if (isLocalUser) {
          OF.user = OF.page.user;
          OF.user.not_viewed_wall_items_count = 0;
          if (!(OF.page.user.status != null)) {
            currentStatus = 'What are you up to?';
          }
          setYourNameNode.addClass('hidden');
          postMessageNode.unhide();
          bindPostMessageEvent();
        } else {
          if (OF.user.has_set_name && OF.page.user.can_post) {
            setYourNameNode.addClass('hidden');
            postMessageNode.unhide();
            bindPostMessageEvent();
          } else if (OF.user.has_set_name && !OF.page.user.can_post) {
            setYourNameNode.addClass('hidden');
            postMessageNode.addClass('hidden');
          } else {
            postMessageNode.addClass('hidden');
            setYourNameNode.unhide();
            bindSetNameEvent();
          }
        }
        updateBasicInfo();
        OF.page.updateStatusInfo(currentStatus);
        updateGameFriendInfo();
        if (bannedMeByUser) {
          $('#blocked_on_wall').unhide();
          $('#friend_only_wall').addClass('hidden');
          return $('#view_only_wall').addClass('hidden');
        } else if (!OF.page.user.wall_items) {
          $('#blocked_on_wall').addClass('hidden');
          $('#friend_only_wall').unhide();
          return $('#view_only_wall').addClass('hidden');
        } else {
          if (!OF.page.user.can_post) {
            $('#view_only_wall').unhide();
          } else {
            $('#view_only_wall').addClass('hidden');
          }
          $('#blocked_on_wall').addClass('hidden');
          $('#friend_only_wall').addClass('hidden');
          if (OF.page.user.wall_items.length === 10) {
            loadMoreNode.unhide();
            bindLoadMoreEvent();
          }
          return updateWallInfo(OF.page.user.wall_items, notViewedWallItemsCount, true);
        }
      }
    });
  };
  postMessageFormSubmitListener = function() {
    var firstMessageNode, messageContentNode, newMessage, requestData;
    newMessage = $.trim(newMessageNode.val());
    if (newMessage.length > 0) {
      newMessage = newMessage.replace(/</gi, "&lt;").replace(/>/gi, "&gt;");
      OF.GA.page('/webui/dashboard/profile_postComment');
      firstMessageNode = $('li.message:first');
      messageContentNode = firstMessageNode.find('.center_column');
      requestData = {
        method: 'POST',
        params: {
          status_message: {
            body: newMessage,
            wall_id: OF.page.user.wall_id
          },
          last_item_id: messageContentNode.data('id')
        },
        success: function(data) {
          updateWallInfo(data.wall_items, data.wall_items.length, false);
          return newMessageNode.val('');
        },
        on406: function(data) {
          OF.alert("No access", $.htmlDecode(data.exception.message));
          return postMessageNode.addClass('hidden');
        },
        failure: function(data, status) {
          if (!status.match(/^406/)) {
            OF.alert('Oops', 'Oops! An error has occured.');
            return false;
          }
        }
      };
      OF.api.request('/xp/status_messages', requestData);
    } else {
      OF.alert('Missing Data', 'You haven\'t input anything to update yet.');
    }
    return false;
  };
  bindPostMessageEvent = function() {
    postMessageFormNode.submit(postMessageFormSubmitListener);
    return postNode.touch(function() {
      return postMessageFormNode.submit();
    });
  };
  setNameListener = function() {
    return OF.push('settings/profile_configuration', {
      params: {
        back_url: "dashboard/profile?user_id=" + OF.page.user.id
      }
    });
  };
  bindSetNameEvent = function() {
    return $('#set_name').touch(setNameListener);
  };
  updateBasicInfo = function() {
    useNameNode.html(OF.page.user.name);
    userScoreNode.html(OF.page.user.gamer_score);
    userScoreNode.unhide();
    if (OF.page.user.profile_picture_url != null) {
      return userProfilePictureNode.css('background-image', "url(" + (userPicUrl(OF.page.user.profile_picture_url)) + ")");
    }
  };
  OF.page.updateStatusInfo = function(status) {
    if (status != null) {
      statusNode.parent().removeClass('hidden');
    }
    return statusNode.html(status);
  };
  updateGameFriendInfo = function() {
    var friendNum, friendString, gameNum, gameString, pendingNum;
    gameNum = OF.page.user.games_count;
    gameString = gameNum <= 1 ? 'Game' : 'Games';
    gamesSubtitleNode.html("" + gameNum + " " + gameString);
    friendNum = OF.page.user.friendship_count;
    friendString = friendNum <= 1 ? 'Friend' : 'Friends';
    friendsSubtitleNode.html("" + friendNum + " " + friendString);
    if (isLocalUser) {
      pendingNum = OF.page.user.received_friend_requests_pending_count;
      if (pendingNum > 999) {
        pendingNum = 999;
      }
      if (pendingNum > 0) {
        friendsBadgeNode.html(pendingNum);
        return friendsBadgeNode.unhide();
      } else {
        friendsBadgeNode.html('');
        return friendsBadgeNode.addClass('hidden');
      }
    }
  };
  loadMoreTouchListener = function() {
    var lastMessageNode, messageContentNode, requestData;
    OF.GA.page('/webui/dashboard/profile_loadMoreMessage');
    lastMessageNode = $('li.message:last');
    messageContentNode = lastMessageNode.find('.center_column');
    requestData = {
      method: 'GET',
      params: {
        last_item_id: messageContentNode.data('id'),
        wall_id: OF.page.user.wall_id
      },
      success: function(data) {
        if (data.wall_items.length < 10) {
          loadMoreNode.addClass('hidden');
        }
        return updateWallInfo(data.wall_items, 0, true);
      },
      on406: function(data) {
        OF.alert("No access", $.htmlDecode(data.exception.message));
        $('li.message').addClass('hidden');
        return loadMoreNode.addClass('hidden');
      },
      failure: function(data, status) {
        if (!status.match(/^406/)) {
          OF.alert('Oops', 'Oops! An error has occured.');
          return false;
        }
      }
    };
    return OF.api.request('/xp/wall/items/more', requestData);
  };
  bindLoadMoreEvent = function() {
    return loadMoreNode.touch(loadMoreTouchListener);
  };
  updateWallInfo = function(wallMessages, newItemNum, positionFlag) {
    var currentNode, deleteNode, newMessagesHTML, notProcessNode, notProcessNodes, usernameNode, wallMessage, _i, _j, _len, _len2, _results;
    newMessagesHTML = '';
    for (_i = 0, _len = wallMessages.length; _i < _len; _i++) {
      wallMessage = wallMessages[_i];
      if (wallMessage.profile_picture_url) {
        wallMessage.style = "background-image: url(" + (userPicUrl(wallMessage.profile_picture_url)) + ")";
      } else {
        wallMessage.style = '';
      }
      wallMessage.data_href = "data-href='dashboard/profile?user_id=" + wallMessage.user_id + "'";
      newMessagesHTML += wallMessageTmpl(wallMessage);
    }
    if (positionFlag) {
      messagesContainerNode.append(newMessagesHTML);
    } else {
      messagesContainerNode.prepend(newMessagesHTML);
    }
    $('li.new_message').removeClass('new_message');
    notProcessNodes = $('li.not_process');
    _results = [];
    for (_j = 0, _len2 = notProcessNodes.length; _j < _len2; _j++) {
      notProcessNode = notProcessNodes[_j];
      currentNode = $(notProcessNode);
      deleteNode = currentNode.find('div.message_action');
      usernameNode = currentNode.find('p.username');
      if (isLocalUser || OF.user.id === usernameNode.data('userid')) {
        deleteNode.unhide();
      }
      if (isLocalUser) {
        if (newItemNum > 0) {
          currentNode.addClass('new_message');
          newItemNum--;
        }
      }
      _results.push(currentNode.unhide().removeClass('not_process'));
    }
    return _results;
  };
  deleteMessageTouchListener = function() {
    var messageNode;
    messageNode = $(this).parents('.message');
    return OF.confirm('', 'Do you really want to delete this item?', 'Yes', 'No', function() {
      var messageContentNode, requestData;
      OF.GA.page('/webui/dashboard/profile_confirmDeleteWallItem');
      messageContentNode = messageNode.find('.center_column');
      requestData = {
        method: 'DELETE',
        success: function() {
          return messageNode.remove();
        },
        failure: function() {
          return OF.alert('Oops', 'Oops! An error has occured.');
        }
      };
      return OF.api.request("/xp/wall/items/" + (messageContentNode.data('id')), requestData);
    }, function() {
      return OF.GA.page('/webui/dashboard/profile_cancelDeleteWallItem');
    });
  };
  $('.delete_message').touch(deleteMessageTouchListener);
  gamesNodeTouchListener = function() {
    return OF.push('dashboard/games', {
      params: {
        user_id: OF.page.user.id,
        user_name: OF.page.user.name
      }
    });
  };
  $('#games').touch(gamesNodeTouchListener);
  friendsNodeTouchListener = function() {
    if (isLocalUser) {
      return OF.push('dashboard/me/friends');
    } else {
      return OF.push('dashboard/friends', {
        params: {
          user: OF.page.user
        }
      });
    }
  };
  $('#friends').touch(friendsNodeTouchListener);
  if (isLocalUser) {
    OF.page.title = 'My Profile';
    updateStatusNode.unhide();
    updateStatusContainerNode.touch(function() {
      return OF.push('dashboard/statusupdate');
    });
    renderFriendActionArea();
    renderMoreOptionsArea();
    $('#no_access_wall').addClass('hidden');
    getProfileData(false);
  } else {
    OF.page.title = 'Feint Friends';
    updateStatusNode.addClass('hidden');
    OF.api('/xp/friends/status', {
      background: true,
      method: 'GET',
      params: {
        id: OF.page.user.id
      },
      success: function(data) {
        renderFriendActionArea(data.friendship);
        renderMoreOptionsArea(data.friendship);
        return getProfileData(data.friendship.ban_me_by_user_for_wall);
      }
    });
  }
}).call(this);
