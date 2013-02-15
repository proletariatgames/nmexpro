// DO NOT EDIT
//   Generated from javascripts/settings/privacy_settings.coffee
//
(function() {
  var initPermissionStatus, privacySettingsForm;
  privacySettingsForm = $('#privacy_settings');
  privacySettingsForm.submit(function() {
    var postPermission, requestData, viewPermission;
    postPermission = $('#post_permission').find('.on').data('checked_value');
    viewPermission = $('#see_permission').find('.on').data('checked_value');
    requestData = {
      method: 'PUT',
      loader: '#submit',
      params: {
        wall: {
          who_can_view: viewPermission,
          who_can_post: postPermission
        }
      },
      success: function() {
        return OF.goBack();
      },
      failure: function() {
        return OF.alert('Oops', 'Oops! An error has occured.');
      }
    };
    OF.api.request("/xp/users/" + OF.user.id + "/wall", requestData);
    return false;
  });
  $('#submit').touch(function() {
    return privacySettingsForm.submit();
  });
  $('#see_permission .radio_container').touch(function() {
    var currentNode, postPerMissionOnButton, radioButtonNode;
    currentNode = $(this);
    radioButtonNode = currentNode.parent().find('.radio_button');
    radioButtonNode.toggleClass('on');
    postPerMissionOnButton = $('#post_permission').find('.radio_button.on');
    if (currentNode.find('.radio_button').data('checked_value') === 'friends' && postPerMissionOnButton.data('checked_value') === 'everyone') {
      return $('#post_permission').find('.radio_button').toggleClass('on');
    }
  });
  $('#post_permission .radio_container').touch(function() {
    var currentNode;
    if ($('#see_permission').find('.radio_button.on').data('checked_value') === 'friends') {
      return;
    }
    currentNode = $(this);
    return currentNode.parent().find('.radio_button').toggleClass('on');
  });
  initPermissionStatus = function(data) {
    $('#post_permission').find(".radio_button[data-checked_value=" + data.who_can_post + "]").addClass('on');
    return $('#see_permission').find(".radio_button[data-checked_value=" + data.who_can_view + "]").addClass('on');
  };
  OF.api.request("/xp/users/" + OF.user.id + "/wall", {
    success: function(data) {
      privacySettingsForm.unhide();
      return initPermissionStatus(data.wall);
    }
  });
}).call(this);
