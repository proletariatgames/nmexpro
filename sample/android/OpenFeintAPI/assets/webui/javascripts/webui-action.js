// DO NOT EDIT
//   Generated from javascripts/webui-action.coffee
//
(function() {
  var actionArgsToJSON, actionStrategies;
  OF.action = function(actionName, options, callback, immediate) {
    var actionObj, key, spec, uri, value, _ref, _ref2;
    uri = "" + actionName + "?";
    if ((_ref = OF.supports) != null ? _ref.actionJSON : void 0) {
      uri += encodeURIComponent(actionArgsToJSON(options));
    } else {
      for (key in options) {
        value = options[key];
        if ($.isFunction(value)) {
          options[key] = OF.page.saveFunction(value);
        }
      }
      uri += $.urlEncode(options);
    }
    actionObj = {
      name: actionName,
      options: options,
      uri: uri,
      callback: callback,
      immediate: immediate,
      ignore: OF.action.willIgnoreNext
    };
    if (!immediate) {
      OF.action.queue.push(actionObj);
    }
    if (immediate) {
      OF.action.queue.unshift(actionObj);
    }
    if ((actionName != null) && actionName !== "log") {
      OF.action.willIgnoreNext = false;
    }
    OF.action.sendController.start();
    if (OF.isBrowser && actionObj.callback) {
      U.defer(actionObj.callback);
    }
    if (OF.isBrowser && actionObj.name !== 'log') {
      console.log('ACTION:', actionObj.name, options);
    }
    if (spec = typeof jasmine !== "undefined" && jasmine !== null ? jasmine.getEnv().currentSpec : void 0) {
            if ((_ref2 = spec.sentActions) != null) {
        _ref2;
      } else {
        spec.sentActions = [];
      };
      return spec.sentActions.push({
        name: actionName,
        options: options
      });
    }
  };
  OF.action.now = function(actionName, options, callback) {
    return OF.action(actionName, options, callback, true);
  };
  OF.action.isSupported = function(actionName) {
    return OF.actions.indexOf(actionName) > -1;
  };
  OF.action.ignoreNext = function() {
    return OF.action.willIgnoreNext = true;
  };
  OF.action.queue = [];
  OF.action.lastActionSentAt = 0;
  actionArgsToJSON = function(object) {
    if (object == null) {
      object = {};
    }
    return JSON.stringify(object, function(key, value) {
      if ($.isFunction(value)) {
        return OF.page.saveFunction(value);
      } else {
        return value;
      }
    });
  };
  actionStrategies = {
    "native": function(actionObj) {
      var uri;
      if (actionObj.ignore) {
        return;
      }
      uri = "openfeint://action/" + actionObj.uri;
      NativeInterface.action(uri);
      OF.action.sendController.busy();
      return window.setTimeout(OF.action.sendController.ready, this.delay);
    },
    single: function(actionObj) {
      var uri;
      if (actionObj.ignore) {
        return;
      }
      uri = "openfeint://action/" + actionObj.uri;
      $('#action_frame').attr('src', uri);
      OF.action.sendController.busy();
      return window.setTimeout(OF.action.sendController.ready, this.delay);
    },
    batch: (function() {
      var batchList, debouncedSend, immediate, send;
      batchList = [];
      debouncedSend = null;
      send = function() {
        var actionObj, actions, json, uri;
        if (batchList.length === 1 && (this.fallback != null)) {
          this.fallback.method(batchList.pop());
          return;
        }
        actions = (function() {
          var _i, _len, _results;
          _results = [];
          for (_i = 0, _len = batchList.length; _i < _len; _i++) {
            actionObj = batchList[_i];
            if (!actionObj.ignore) {
              _results.push({
                name: actionObj.name,
                options: actionObj.options || {}
              });
            }
          }
          return _results;
        })();
        json = actionArgsToJSON({
          actions: actions
        });
        uri = "openfeint://action/batch?" + (encodeURIComponent(json));
        U.defer(function() {
          return $('#action_frame').attr('src', uri);
        });
        batchList = [];
        OF.action.sendController.busy();
        return window.setTimeout(OF.action.sendController.ready, this.delay);
      };
      immediate = function(actionObj) {
        batchList.push(actionObj);
        if (debouncedSend == null) {
          debouncedSend = U.debounce(send, this.debounceDelay);
        }
        return debouncedSend.call(this);
      };
      return immediate;
    })(),
    browser: function(actionObj) {}
  };
  OF.action.sendController = (function() {
    var busy, init, isReady, ready, send, start, strategy;
    isReady = true;
    strategy = null;
    init = function() {
      strategy = {};
      if (OF.isBrowser) {
        strategy.method = actionStrategies.browser;
      } else if (OF.hasNativeInterface) {
        strategy.method = actionStrategies["native"];
      } else if (OF.action.isSupported('batch')) {
        strategy.method = actionStrategies.batch;
        strategy.fallback = {
          method: actionStrategies.single,
          delay: 1
        };
        strategy.debounceDelay = 1;
      } else {
        strategy.method = actionStrategies.single;
      }
      return strategy.delay = OF.platform === 'ios' ? 1 : 1;
    };
    start = function() {
      if (isReady) {
        return send();
      }
    };
    ready = function() {
      isReady = true;
      return send();
    };
    busy = function() {
      return isReady = false;
    };
    send = function() {
      var actionObj, _results;
      _results = [];
      while (isReady && OF.action.queue.length > 0) {
        actionObj = OF.action.queue.shift();
        strategy.method(actionObj);
        _results.push((function() {
          try {
            if (actionObj.callback) {
              return U.defer(actionObj.callback);
            }
          } catch (e) {
            return OF.log(e);
          }
        })());
      }
      return _results;
    };
    return {
      start: start,
      ready: ready,
      busy: busy,
      init: init
    };
  })();
  OF.sendAction = OF.action;
  OF.actionIsSupported = $.deprecate(OF.action.isSupported, 'OF.actionIsSupported()', 'OF.action.isSupported()');
}).call(this);
