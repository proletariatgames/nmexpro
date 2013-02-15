// DO NOT EDIT
//   Generated from javascripts/dashboard/players.coffee
//
(function() {
  var currentPage, loadMoreNode, perPageCount, playerTmpl, updateWhoIsPlaying, willShowContainerNode, willShowLoadMoreNode;
  perPageCount = 7;
  currentPage = 2;
  loadMoreNode = $('#load_more');
  playerTmpl = tmpl('playerTmpl');
  willShowContainerNode = function(containerNode, length) {
    if (length > 0) {
      containerNode.unhide();
      return true;
    } else {
      containerNode.addClass('hidden');
      return false;
    }
  };
  willShowLoadMoreNode = function(length) {
    if (length === perPageCount) {
      return loadMoreNode.unhide();
    } else {
      return loadMoreNode.addClass('hidden');
    }
  };
  updateWhoIsPlaying = function(players, containerNode) {
    var player, playerHtml, _i, _len;
    playerHtml = '';
    for (_i = 0, _len = players.length; _i < _len; _i++) {
      player = players[_i];
      player.class_name = 'offline';
      player.style = '';
      player.data_href = "data-href='dashboard/profile?user_id=" + player.id + "'";
      if (player.online === true) {
        player.class_name = 'online';
      }
      if (player.profile_picture_url != null) {
        player.style = "background-image: url(" + player.profile_picture_url + ")";
      }
      playerHtml += playerTmpl(player);
    }
    return playerHtml;
  };
  OF.api("/xp/games/" + OF.game.id + "/users/more", {
    background: true,
    success: function(data) {
      var friends, friendsContainerNode, newContent, strangers, strangersContainerNode;
      friends = data.users.friends;
      friendsContainerNode = $('#friends');
      if (willShowContainerNode(friendsContainerNode, friends.length)) {
        newContent = updateWhoIsPlaying(friends, friendsContainerNode);
        friendsContainerNode.find(".section_title").after(newContent);
      }
      strangers = data.users.strangers;
      strangersContainerNode = $('#everyone');
      if (willShowContainerNode(strangersContainerNode, strangers.length)) {
        newContent = updateWhoIsPlaying(strangers, strangersContainerNode);
        loadMoreNode.before(newContent);
        return willShowLoadMoreNode(strangers.length);
      }
    }
  });
  loadMoreNode.touch(function() {
    OF.GA.page('/webui/dashboard/players_loadMorePlayers');
    return OF.api("/xp/games/" + OF.game.id + "/users/more", {
      background: true,
      params: {
        page: currentPage
      },
      success: function(data) {
        var newContent, strangers, strangersContainerNode;
        strangers = data.users.strangers;
        strangersContainerNode = $('#everyone');
        willShowLoadMoreNode(strangers.length);
        newContent = updateWhoIsPlaying(strangers, strangersContainerNode);
        loadMoreNode.before(newContent);
        return currentPage++;
      }
    });
  });
}).call(this);
