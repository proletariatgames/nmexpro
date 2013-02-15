// DO NOT EDIT
//   Generated from javascripts/settings/profile_secure.coffee
//
(function() {
  var backUrl;
  backUrl = OF.page.params.back_url;
  $('#secure_account_form').submit(function() {
    var requestData;
    if ($(this).isLoading()) {
      return false;
    }
    if ($('#secure_account_form').isFormFilled('Please fill out all fields in order to enable retrieval of your account.')) {
      $(this).isLoading(true);
      requestData = {
        method: 'PUT',
        loader: '#Okay',
        params: {
          password: ' ',
          user: {
            http_basic_credential_attributes: {
              email: $('#email').val(),
              password: $('#user_http_basic_credential_attributes_password').val(),
              password_confirmation: $('#user_http_basic_credential_attributes_password_confirmation').val()
            }
          }
        },
        success: function() {
          if (backUrl != null) {
            OF.push(backUrl);
          } else {
            OF.push('dashboard/user');
          }
          return OF.alert('Success', 'You have attached email and password to your account.');
        },
        complete: function() {
          return $('#secure_account_form').isLoading(false);
        }
      };
      OF.api.request("/xp/users/" + OF.user.id, requestData);
    }
    return false;
  });
  $('#Okay').touch(function() {
    OF.GA.page('/webui/dashboard/profile_secure_setEmailPassword');
    return $('#secure_account_form').submit();
  });
  $('#Skip').touch(function() {
    OF.GA.page('/webui/dashboard/profile_secure_skipEmailPassword');
    if (backUrl != null) {
      return OF.push(backUrl);
    } else {
      return OF.push('dashboard/user');
    }
  });
}).call(this);
