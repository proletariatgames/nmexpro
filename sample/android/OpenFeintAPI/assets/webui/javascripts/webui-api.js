// DO NOT EDIT
//   Generated from javascripts/webui-api.coffee
//
(function() {
  var Request;
  var __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; };
  OF.api = function(path, options) {
    var method;
    method = options.method ? options.method.toLowerCase() : 'get';
    return OF.api[method](path, options);
  };
  U.each(['get', 'post', 'put', 'delete'], function(httpMethod) {
    return OF.api[httpMethod] = function(path, options) {
      options.method = httpMethod.toUpperCase();
      return OF.api.sendRequest(path, options);
    };
  });
  OF.api.activeRequests = {};
  OF.api.activeRequestIDs = [];
  OF.api.allow = true;
  OF.api.sendRequest = function(path, options) {
    var request;
    if (!OF.api.allow) {
      return;
    }
    request = new Request(path, options);
    OF.api.activeRequests[request.id] = request;
    OF.api.activeRequestIDs.push(request.id);
    if (!OF.device.ios3) {
      request.start();
    }
    if (OF.device.ios3 && OF.api.activeRequestIDs.length === 1) {
      request.start();
    }
    return request;
  };
  Request = (function() {
    function Request(path, options) {
      var deferred, statusCode, _i, _len, _ref;
      this.id = U.uniqueId('api_request_');
      this.page = OF.page;
      this.path = $.jsonifyUrl(path);
      this.obj = null;
      this.params = options.params || {};
      this.httpParams = options.httpParams || {};
      this.method = options.method || 'GET';
      this.loader = $(options.loader);
      this.background = options.background;
      this.isComplete = false;
      this.isCancelled = false;
      this.isStarted = false;
      deferred = $.Deferred();
      deferred.promise(this);
      this.success = this.done;
      this.failure = this.fail;
      this.complete = this.always;
      this.successCallback = function(data, status) {
        if (options.success) {
          options.success(data, status);
        }
        if (options.complete) {
          options.complete(data, status);
        }
        return deferred.resolve(data, status);
      };
      this.failureCallback = function(data, status) {
        if (!(options.failure && (options.failure(data, status) !== false))) {
          OF.api.handleError(data, status);
        }
        if (options.complete) {
          options.complete(data, status);
        }
        return deferred.reject(data, status);
      };
      this.findMock();
      this.statusCallbacks = {};
      _ref = [200, 201, 400, 401, 404, 406, 409, 500, 503];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        statusCode = _ref[_i];
        this.statusCallbacks["on" + statusCode] = options["on" + statusCode];
      }
      if (OF.isBrowser) {
        this.params.session_device_id = OF.device.identifier;
        this.params.session_user_id = OF.user.id;
        this.params.session_game_id = OF.game.id;
      }
    }
    Request.prototype.findMock = function() {
      if (typeof jasmine !== "undefined" && jasmine !== null) {
        if (jasmine.getEnv().currentSpec.mocks) {
          this.mock = jasmine.getEnv().currentSpec.mocks[this.path.replace(/\.json$/, '')];
          if (this.mock) {
            this.originalPath = this.path;
            this.path = this.mock.url;
            this.method = 'GET';
            this.obj = this.mock.obj;
          }
        }
        if (!this.mock) {
          return console.warn(">>> WARNING <<< API request not mocked: " + this.path + "?" + ($.urlEncode(this.params)));
        }
      }
    };
    Request.prototype.start = function() {
      this.isStarted = true;
      OF.log("API Request Started: " + this.method + " " + (this.originalPath || this.path) + " " + ($.urlEncode(this.params)));
      if (!this.background) {
        OF.loader.show();
      }
      if (this.loader) {
        if (this.loader.hasClass('button')) {
          this.loader.data('buttonHtml', this.loader.html()).html('Loading&hellip;');
        } else {
          this.loader.fadeIn();
        }
      }
      if (this.obj != null) {
        U.defer(__bind(function() {
          return OF.api.completeRequest(this.id, "200", JSON.stringify(this.obj));
        }, this));
        return;
      }
      OF.action('apiRequest', {
        path: this.path,
        method: this.method,
        params: $.urlEncode(this.params),
        httpParams: $.urlEncode(this.httpParams),
        request_id: this.id
      });
      if (OF.isBrowser) {
        return $.ajax({
          url: this.path,
          data: this.params,
          type: this.method,
          dataType: 'json',
          complete: __bind(function(xhr, textStatus) {
            return OF.api.completeRequest(this.id, xhr.status.toString(), xhr.responseText);
          }, this)
        });
      }
    };
    Request.prototype.parseResponse = function(response) {
      var data;
      if ($.isPlainObject(response)) {
        data = response;
      } else {
        response = $.trim(response);
        if (response.length > 0) {
          try {
            data = JSON.parse(response);
          } catch (e) {
            data = {};
          }
        }
      }
      return data || {};
    };
    Request.prototype.finalize = function(status, response) {
      var callback, data;
      data = this.parseResponse(response);
      if (this.mock) {
        if (this.mock.callback) {
          this.mock.callback(data);
        }
        if (this.mock.status) {
          status = this.mock.status;
        }
      }
      this.isComplete = true;
      if (!this.background) {
        OF.loader.hide();
      }
      if (this.isCancelled || !this.page.exists()) {
        return;
      }
      if (this.loader) {
        if (this.loader.hasClass('button')) {
          this.loader.html(this.loader.data('buttonHtml'));
        } else {
          this.loader.hide();
        }
      }
      try {
        if (callback = this.statusCallbacks["on" + status]) {
          callback(data, status);
        }
        if (status.match(/^2/)) {
          OF.log("API Request Complete: " + this.path);
          if (OF.isBrowser) {
            console.log("    ", data);
          }
          return this.successCallback(data, status);
        } else {
          OF.log("API Request Failed: " + this.path + "    " + response);
          if (OF.isBrowser) {
            console.log("    ", data);
          }
          if (OF.api.handleDisconnect && status === '0') {
            return OF.api.handleDisconnect();
          } else {
            return this.failureCallback(data, status);
          }
        }
      } catch (e) {
        return OF.log("Error in callback section: " + (JSON.stringify(e)));
      }
    };
    Request.prototype.cancel = function() {
      if (!this.isComplete) {
        return this.isCancelled = true;
      }
    };
    return Request;
  })();
  OF.api.completeRequest = function(requestID, status, response) {
    var req;
    req = OF.api.activeRequests[requestID];
    if (req) {
      req.finalize(status, response);
      delete OF.api.activeRequests[requestID];
      OF.api.activeRequestIDs.splice(OF.api.activeRequestIDs.indexOf(requestID), 1);
      OF.api.completeRequest.count += 1;
    } else {
      OF.log("WARNING: Request ID not found. Maybe it already completed. ID: " + requestID);
    }
    if (OF.device.ios3 && OF.api.activeRequestIDs.length > 0) {
      U.defer(function() {
        return OF.api.activeRequests[OF.api.activeRequestIDs[0]].start();
      });
    }
    if (OF.device.ios3 && OF.api.activeRequestIDs.length === 0) {
      return OF.contentLoaded();
    }
  };
  OF.api.completeRequest.count = 0;
  OF.api.handleError = function(data, status) {
    if (data.exception) {
      return OF.alert("ERROR", "" + data.exception.message);
    } else {
      return OF.alert("ERROR", "" + status + ", 'Oops! There was an error communicating with the server.");
    }
  };
  OF.api.handleDisconnect = function() {
    return OF.alert('Unable to Connect', 'Please check that you have cellular or WiFi service and try again.');
  };
  OF.api.request = $.deprecate(OF.api, 'OF.api.request()', 'OF.api()');
}).call(this);
