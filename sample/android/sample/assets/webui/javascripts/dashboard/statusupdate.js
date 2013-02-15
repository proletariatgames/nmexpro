// DO NOT EDIT
//   Generated from javascripts/dashboard/statusupdate.coffee
//
(function() {
  var newStatusNode, updateButtonNode, updateStatusNode;
  newStatusNode = $('#new_status');
  updateStatusNode = $('#update_status');
  updateButtonNode = $('#update');
  updateStatusNode.submit(function() {
    var newStatus, requestData;
    newStatus = $.trim(newStatusNode.val());
    if (newStatus.length > 0) {
      newStatus = newStatus.replace(/</gi, "&lt;").replace(/>/gi, "&gt;");
      requestData = {
        method: 'PUT',
        loader: '#update',
        params: {
          user: {
            status: newStatus
          }
        },
        success: function() {
          OF.user.status = newStatus;
          return OF.goBack();
        },
        failure: function() {
          return OF.alert('Oops', 'Oops! An error has occured.');
        }
      };
      OF.api.request("/xp/users/" + OF.user.id, requestData);
    } else {
      OF.alert('Missing Data', 'You haven\'t input anything to update yet.');
    }
    return false;
  });
  updateButtonNode.touch(function() {
    OF.GA.page('/webui/dashboard/statusupdate_updateButton');
    return updateStatusNode.submit();
  });
}).call(this);
