// DO NOT EDIT
//   Generated from javascripts/webui-helper.coffee
//
(function() {
  var __hasProp = Object.prototype.hasOwnProperty, __slice = Array.prototype.slice;
  this.U = _.noConflict();
  jQuery.fn.unhide = function(fadeSpeed) {
    return $(this).removeClass('hidden').hide().fadeIn(fadeSpeed);
  };
  jQuery.fn.isLoading = function(value) {
    return $(this).data('isLoading', value);
  };
  jQuery.fn.isFormFilled = function(failureMessage) {
    var field, _i, _len, _ref;
    _ref = $(this).find(':input');
    for (_i = 0, _len = _ref.length; _i < _len; _i++) {
      field = _ref[_i];
      if ($(field).val().trim().length === 0) {
        OF.alert('Missing Data', failureMessage || 'Please fill out all form fields.');
        return false;
      }
    }
    return true;
  };
  jQuery.lazyLoad = function(options) {
    var isEmpty, isFinished, nextPageLoaded, nextPageShouldLoad, pageHandler, self, startPage, threshold;
    self = OF.page.eventHandle();
    startPage = options.startPage || 1;
    threshold = options.threshold || 0.5;
    nextPageLoaded = options.nextPageLoaded;
    nextPageShouldLoad = options.nextPageShouldLoad;
    isEmpty = options.isEmpty;
    isFinished = options.isFinished;
    pageHandler = function(page, data, forceFinish) {
      var finished;
      finished = forceFinish || data.length === 0;
      if (finished) {
        if (page === 1) {
          if (typeof isEmpty === "function") {
            isEmpty();
          }
        }
        if (typeof isFinished === "function") {
          isFinished();
        }
        jQuery(self).unbind("scroll.lazyLoader");
      }
      if (data != null) {
        nextPageLoaded(page, data);
      }
      jQuery(self).data("lazyLoader-lastLoadedPage", page);
      return U.defer(function() {
        return jQuery(self).data("lazyLoader-isLoading", false);
      });
    };
    jQuery(self).data("lazyLoader-isLoading", true);
    nextPageShouldLoad(startPage, pageHandler.curry(startPage));
    return jQuery(self).bind("scroll.lazyLoader", function() {
      var nextPage, scrollBottom, triggerLine;
      scrollBottom = jQuery(document).scrollTop() + jQuery(window).height();
      triggerLine = jQuery(document).height() - (jQuery(window).height() * threshold);
      if (scrollBottom < triggerLine) {
        return;
      }
      if (jQuery(self).data("lazyLoader-isLoading")) {
        return;
      }
      nextPage = (jQuery(self).data("lazyLoader-lastLoadedPage") || startPage) + 1;
      jQuery(self).data("lazyLoader-isLoading", true);
      return nextPageShouldLoad(nextPage, pageHandler.curry(nextPage));
    });
  };
  jQuery.renderCollection = function(partialName, items, innerKey) {
    var html, index, item, key, keys, obj, theTmpl;
    if (!(items.length > 0)) {
      return '';
    }
    theTmpl = tmpl(partialName);
    if (!innerKey) {
      keys = (function() {
        var _ref, _results;
        _ref = items[0];
        _results = [];
        for (key in _ref) {
          if (!__hasProp.call(_ref, key)) continue;
          _results.push(key);
        }
        return _results;
      })();
      if (keys.length > 1) {
        OF.log("ERROR: Ambiguous inner keys [" + (keys.join(', ')) + "]. Specify what key to use if there is more than one.");
        return;
      }
      if (keys.length === 0) {
        OF.log('ERROR: Cannot render empty object.');
      }
      innerKey = keys[0];
    }
    index = 0;
    html = (function() {
      var _i, _len, _results;
      _results = [];
      for (_i = 0, _len = items.length; _i < _len; _i++) {
        item = items[_i];
        obj = item[innerKey];
        obj.index || (obj.index = index);
        obj.position || (obj.position = obj.index + 1);
        index += 1;
        _results.push(theTmpl(obj));
      }
      return _results;
    })();
    return $(html.join(''));
  };
  jQuery.htmlEncode = function(value) {
    return $('<div/>').text(value).html();
  };
  jQuery.htmlDecode = function(value) {
    return $('<div/>').html(value).text();
  };
  jQuery.ensureUpdate = function(selector, fn) {
    var html;
    fn();
    html = $(selector).html();
    if (!(html != null) || $.trim(html).length === 0) {
      return setTimeout(function() {
        return jQuery.ensureUpdate(selector, fn);
      }, 100);
    }
  };
  jQuery.fn.hasLive = function(type, ctx) {
    var events, handler, handlers, _i, _len;
    if (ctx == null) {
      ctx = document;
    }
    events = $(ctx).data('events');
    if (handlers = events && events[type]) {
      for (_i = 0, _len = handlers.length; _i < _len; _i++) {
        handler = handlers[_i];
        if (this.is(handler.selector)) {
          return true;
        }
      }
    }
    return false;
  };
  jQuery.loadScript = function(path) {
    return $.ajax({
      url: "javascripts/" + path + ".js?" + (new Date().getTime()),
      dataType: 'script',
      async: false
    });
  };
  jQuery.loadCss = function(path, async) {
    return $.ajax({
      url: "stylesheets/" + path + ".css?" + (new Date().getTime()),
      async: async != null ? async : true,
      success: function(data) {
        return $('<style></style>').attr('type', 'text/css').attr('id', "" + path + "_css").html(data).appendTo('head');
      }
    });
  };
  jQuery.urlEncode = function(options, prefix) {
    var key, paramName, result, value, values;
    result = '';
    if (options) {
      values = [];
      for (key in options) {
        if (!__hasProp.call(options, key)) continue;
        value = options[key];
        if (value != null) {
          paramName = prefix ? "" + prefix + "[" + key + "]" : key;
          if ($.isPlainObject(value)) {
            values.push($.urlEncode(value, paramName));
          } else {
            values.push("" + paramName + "=" + (encodeURIComponent(value)));
          }
        }
      }
      result = values.join('&');
    }
    return result;
  };
  jQuery.urlDecode = function(queryString) {
    var pair, pairs, result, _i, _len;
    if (queryString == null) {
      return;
    }
    queryString = queryString.replace(/^\?/, '');
    result = {};
    pairs = queryString.split('&');
    for (_i = 0, _len = pairs.length; _i < _len; _i++) {
      pair = pairs[_i];
      pair = pair.split('=');
      result[pair[0]] = decodeURIComponent(pair[1]);
    }
    return result;
  };
  jQuery.jsonifyUrl = function(url) {
    if (!url.match(/\.json/)) {
      if (url.match(/\?/)) {
        url = url.replace(/\?/, '.json?');
      } else {
        url += '.json';
      }
    }
    return url;
  };
  jQuery.functionize = (function() {
    var errorLocation;
    errorLocation = function(file, name) {
      return "" + (file.replace('.json', '')) + ":" + name;
    };
    return function(js, file, name) {
      if ($.isFunction(js)) {
        return js;
      } else if (typeof js === 'string') {
        if (js.match(/^\s*function/)) {
          js = ['(', js, ')'].join('');
        } else {
          js = ['(function($) { $ = $ || jQuery; ', js, '})'].join('');
        }
        try {
          return eval(js);
        } catch (e) {
          throw "" + (e.toString()) + " in " + (errorLocation(file, name));
        }
      } else {
        throw "ERROR: " + (errorLocation(file, name)) + " Must be a string or function but was: " + js;
      }
    };
  })();
  jQuery.defer = function() {
    var args, fn, js;
    js = arguments[0], args = 2 <= arguments.length ? __slice.call(arguments, 1) : [];
    fn = function() {
      return $.functionize(js, 'anonymous', 'defer').apply(null, args);
    };
    return U.defer(fn);
  };
  jQuery.profile = function(name, fn) {
    var end, retVal, start;
    start = new Date();
    retVal = fn();
    end = new Date();
    OF.log("JS PROFILE: " + name + " - " + (end - start) + "ms");
    return retVal;
  };
  jQuery.random = function(min, max) {
    return Math.floor(Math.random() * (max + 1 - min)) + min;
  };
  jQuery.deprecate = function(fn, oldName, newName) {
    return function() {
      OF.log("DEPRECATION WARNING: " + oldName + " has been replaced by " + newName);
      return fn.apply(this, arguments);
    };
  };
  Function.prototype.curry = function() {
    var args;
    args = 1 <= arguments.length ? __slice.call(arguments, 0) : [];
    if (args.length === 0) {
      return this;
    }
    return U.bind.apply(U, [this, this].concat(__slice.call(args)));
  };
}).call(this);
