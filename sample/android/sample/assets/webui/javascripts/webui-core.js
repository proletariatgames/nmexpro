// DO NOT EDIT
//   Generated from javascripts/webui-core.coffee
//
(function() {
  var OF;
  var __slice = Array.prototype.slice;
  if (this.runSpecs == null) {
    this.runSpecs = false;
  }
  this.OF = OF = {};
  OF.isDevice = navigator.userAgent.match(/iPhone|iPad|Android/);
  OF.isBrowser = !OF.isDevice;
  ({
    deviceType: {
      iOS: navigator.userAgent.match(/iPhone|iPad/),
      Android: navigator.userAgent.match(/Android/)
    }
  });
  OF.hasNativeInterface = false;
  OF.page = null;
  OF.global = {};
  OF.orientation = null;
  OF.pages = [];
  OF.pages.replace = function(path) {
    OF.pages.splice(0, OF.pages.length);
    return OF.push(path);
  };
  OF.log = function(data) {
    var message;
    if (OF.isBrowser) {
      console.log('WEBLOG:', data);
    }
    if (OF.device.ios3) {
      return;
    }
    if (OF.isDevice) {
      if (typeof data === 'object') {
        message = $.urlEncode(data);
      } else {
        message = "" + data;
      }
      return OF.action('log', {
        message: message
      });
    }
  };
  OF.time = function() {
    var checkPointNames, now;
    checkPointNames = 1 <= arguments.length ? __slice.call(arguments, 0) : [];
    if (OF.device.ios3) {
      return;
    }
    now = Date.now();
    if (OF.isBrowser) {
      console.log("PROFILE " + now + " " + (checkPointNames.join('::')));
    }
    if (OF.isDevice) {
      return OF.action('profile', {
        time: now,
        checkPointNames: checkPointNames.join('::')
      });
    }
  };
  OF.setOrientation = function(newOrientation) {
    var _ref;
    if (newOrientation) {
      OF.orientation = newOrientation;
      $('body').removeClass('orientation_portrait').removeClass('orientation_landscape').addClass("orientation_" + OF.orientation);
      return (_ref = OF.topPage()) != null ? typeof _ref.orientationChanged === "function" ? _ref.orientationChanged(OF.orientation) : void 0 : void 0;
    }
  };
  OF.DEBUG = {
    enableWeinre: function(host) {
      var e;
      e = document.createElement("script");
      e.setAttribute("src", "http://" + host + "/target/target-script-min.js#anonymous");
      return document.getElementsByTagName("body")[0].appendChild(e);
    }
  };
  OF.init = {
    isLoaded: false,
    flowIsLoaded: false,
    firstPage: function() {
      var options, pushParams;
      if (OF.isBrowser) {
        options = $.urlDecode(location.href.split('?')[1]);
        pushParams = $.extend({}, options);
        delete pushParams.url;
        $('html, body').css('-webkit-user-select', 'auto');
        if (options.url) {
          $.ajax({
            url: '/webui/browser_config.json',
            dataType: 'json',
            complete: function(xhr) {
              var browserConfig;
              browserConfig = JSON.parse(xhr.responseText);
              if (browserConfig.remoteDebugHost) {
                OF.DEBUG.enableWeinre(browserConfig.remoteDebugHost);
              }
              OF.init.clientBoot(browserConfig);
              return OF.push(options.url, {
                params: pushParams
              });
            }
          });
        } else {
          OF.alert('ERROR', 'No Content to Load! This page must be called with a url like /webui/index.html?url=some/content_path');
        }
      }
      OF.touch.bindHandlers();
      return $(window).scroll(function(ev) {
        var time, _ref;
        if (ev.target !== ev.currentTarget) {
          return;
        }
        time = new Date().getTime();
        if (window._lastScrollingTime && (time - window._lastScrollingTime) < 249) {
          return false;
        }
        window._lastScrollingTime = time;
        OF.touch.isScrolling = true;
        clearTimeout(window._stopScrollingCallback);
        if ((_ref = OF.page.eventHandle()) != null) {
          _ref.trigger('scroll');
        }
        return window._stopScrollingCallback = setTimeout(function() {
          return OF.touch.isScrolling = false;
        }, 250);
      });
    },
    clientBoot: function(options) {
      var body;
      OF.hasNativeInterface = options.hasNativeInterface;
      OF.user = options.user;
      if (!OF.user.name) {
        OF.user.name = null;
      }
      if (!OF.user.id || OF.user.id.toString() === '0') {
        OF.user.id = null;
      }
      OF.game = options.game;
      OF.serverUrl = options.serverUrl;
      OF.actions = options.actions;
      OF.settings.enabled = OF.action.isSupported('readSetting') && OF.action.isSupported('writeSetting');
      OF.clientVersion = options.clientVersion;
      OF.platform = options.platform;
      OF.device = options.device;
      OF.device.ios3 = !!OF.device.os.match(/iPhone.*3\.\d\.\d/);
      if (OF.device.ios3) {
        OF.action.delay = 250;
      }
      OF.dpi = options.dpi;
      OF.setOrientation(options.orientation);
      OF.disableGA = options.disableGA;
      OF.supports = options.supports || {};
      OF.supports.fixedPosition = OF.platform === 'android' && OF.device.os.match(/v2\.2/) || OF.device.hardware === 'browser';
      OF.action.sendController.init();
      OF.manifestUrl = options.manifestUrl;
      OF.log("Client Booted - userID: " + OF.user.id + " gameID: " + OF.game.id + " platform: " + OF.platform + " dpi: " + OF.dpi);
      body = $('body');
      body.addClass(OF.dpi).addClass(OF.platform);
      if (OF.supports.fixedPosition) {
        body.addClass('fixed_position');
      }
      return true;
    },
    start: function() {
      var buttonTitle, options, pageRoot, sub$, _base, _ref;
      OF.init.isLoaded = false;
      OF.init.scripts();
      OF.init.browser();
      OF.init.params();
      if (!OF.init.flowIsLoaded && OF.page.loadflow) {
        OF.page.loadflow();
        OF.init.flowIsLoaded = true;
      }
      sub$ = jQuery.sub();
      pageRoot = OF.page.eventContext;
      sub$.fn.init = function(selector, context, root) {
        if (context == null) {
          context = pageRoot;
        }
        return new jQuery.fn.init(selector, context, root);
      };
            if ((_ref = (_base = OF.page).init) != null) {
        _ref;
      } else {
        _base.init = $.noop;
      };
      if (OF.page.init.complete) {
        if (OF.page.resume) {
          U.defer(function() {
            try {
              return OF.page.resume(sub$);
            } catch (e) {
              return OF.alert('ERROR', "A script on this screen caused an error.\n resume: " + (e.toString()));
            }
          });
        }
      } else {
        U.defer(function() {
          try {
            OF.page.init(sub$);
          } catch (e) {
            OF.alert('ERROR', "A script on this screen caused an error.\n init: " + (e.toString()));
          }
          return OF.page.init.complete = true;
        });
      }
      U.defer(function() {
        if (OF.page.appear) {
          try {
            return OF.page.appear(sub$);
          } catch (e) {
            return OF.alert('ERROR', "A script on this screen caused an error.\n appear: " + (e.toString()));
          }
        }
      });
      U.defer(OF.init.pageViewTracking);
      OF.init.isLoaded = true;
      buttonTitle = OF.page.barButton || OF.page.globalBarButton;
      options = {};
      if (buttonTitle) {
        options.barButton = buttonTitle;
      }
      return U.defer(function() {
        if (!OF.device.ios3 || (OF.device.ios3 && OF.api.activeRequestIDs.length === 0)) {
          document.title = OF.page.title;
          return OF.contentLoaded(options);
        }
      });
    },
    scripts: function() {
      if ((OF.page.init != null) && !$.isFunction(OF.page.init)) {
        OF.page.init = $.functionize(OF.page.init, OF.page.url, 'init');
        OF.page.init.complete = false;
      }
      if ((OF.page.appear != null) && !$.isFunction(OF.page.appear)) {
        OF.page.appear = $.functionize(OF.page.appear, OF.page.url, 'appear');
      }
      if ((OF.page.resume != null) && !$.isFunction(OF.page.resume)) {
        OF.page.resume = $.functionize(OF.page.resume, OF.page.url, 'resume');
      }
      if (!OF.init.flowIsLoaded && (OF.page.loadflow != null) && !$.isFunction(OF.page.loadflow)) {
        return OF.page.loadflow = $.functionize(OF.page.loadflow, OF.page.url, 'loadflow');
      }
    },
    browser: function() {
      if (OF.isBrowser && $('#browser_toolbar').length === 0) {
        $.loadCss('browser_toolbar', false);
        return $.get('browser_toolbar.html', function(data) {
          return $(document.body).append(data);
        });
      }
    },
    barButton: function() {
      var buttonName, options;
      options = {};
      buttonName = OF.page.barButton || OF.page.globalBarButton;
      if (OF.page.barButton) {
        options.barButton = buttonName;
      }
      if (OF.page.barButtonImage) {
        options.barButtonImage = OF.page.barButtonImage;
      }
      return OF.action('addBarButton', options);
    },
    pageViewTracking: function() {
      if (OF.topPage()) {
        return OF.GA.page("/webui/" + (OF.topPage().url));
      }
    },
    params: function() {
      var page, _ref;
      page = OF.topPage();
            if ((_ref = page.params) != null) {
        _ref;
      } else {
        page.params = {};
      };
      if (page.url.match(/\?/)) {
        return $.extend(page.params, $.urlDecode(page.url.split('?')[1]));
      }
    }
  };
  OF.forceSetTitle = function(title) {
    var titleElement;
    if ((titleElement = $('#header .title')).length > 0) {
      return titleElement.html(title);
    }
  };
  OF.topPage = function() {
    return OF.pages[OF.pages.length - 1];
  };
  OF.loadTopPage = (function() {
    var htmlReady;
    htmlReady = function(page, completionCallback) {
      page.showContent();
      return setTimeout(function() {
        if ($.trim($('#page').html() || '').length === 0) {
          OF.log("Retrying... HTML not yet ready.");
          return htmlReady(page);
        } else {
          OF.topPage().eventContext = $('#event_context')[0];
          OF.init.start();
          if (completionCallback) {
            U.defer(completionCallback, page);
          }
          U.defer(function() {
            return window.scroll(0, page.scrollPosition);
          });
          if (window.runSpecs) {
            return OF.specs.run();
          }
        }
      }, 100);
    };
    return function(completionCallback) {
      OF.page = OF.topPage();
      $('#page').html('&nbsp;');
      return setTimeout(function() {
        return htmlReady(OF.page, completionCallback);
      }, 50);
    };
  })();
  OF.push = function(url, options) {
    var onComplete, params;
    if (options == null) {
      options = {};
    }
    OF.init.isLoaded = false;
    onComplete = options.complete;
    options.complete = null;
    url = $.jsonifyUrl(url);
    options.path = url;
    OF.log("Loading content: " + url);
    params = options.params || {};
    options.params = null;
    OF.push.loadingPage = {
      url: url,
      onComplete: onComplete,
      params: params
    };
    if (OF.pages.length > 0) {
      OF.topPage().scrollPosition = window.scrollY;
    }
    OF.specs.load(url);
    OF.action.now('startLoading', options);
    OF.loader.show();
    if (OF.isBrowser) {
      return OF.push.ready();
    }
  };
  OF.push.ready = (function() {
    var loadPage;
    loadPage = function(url, data, params, onComplete) {
      var page, _ref;
      if (OF.init.isLoaded) {
        return;
      }
      if ((_ref = OF.page) != null) {
        _ref.detach();
      }
      page = new OF.Page(data, url, params);
      OF.pages.push(page);
      OF.loadTopPage(onComplete);
      return OF.GA.init();
    };
    return function(pageJSON) {
      return U.defer(function() {
        var onComplete, params, url;
        url = OF.push.loadingPage.url;
        onComplete = OF.push.loadingPage.onComplete;
        params = OF.push.loadingPage.params;
        OF.push.loadingPage = null;
        if (pageJSON) {
          return loadPage(url, pageJSON, params, onComplete);
        } else {
          return $.ajax({
            url: url,
            dataType: 'json',
            success: function(pageJSON) {
              return loadPage(url, pageJSON, params, onComplete);
            },
            error: function(xhr) {
              OF.init.isLoaded = true;
              OF.alert("Error", "Screen loading (" + url + ") failed:\n" + xhr.status + " " + xhr.statusText);
              return OF.loader.hide();
            }
          });
        }
      });
    };
  })();
  OF.refresh = function() {
    if (OF.page) {
      OF.page.nodes = null;
      OF.page.init.complete = false;
      return U.defer(OF.loadTopPage);
    }
  };
  OF.pushController = function(controllerName, options) {
    controllerName = "" + controllerName + "?" + ($.urlEncode(options));
    if (OF.isDevice) {
      location.href = "openfeint://controller/" + controllerName;
    }
    return OF.log("CONTROLLER: " + controllerName);
  };
  OF.contentLoaded = function(options) {
    var _ref;
    if (options == null) {
      options = {};
    }
        if ((_ref = options.title) != null) {
      _ref;
    } else {
      options.title = document.title || OF.page.title;
    };
    if (OF.page.titleImage) {
      options.titleImage = OF.page.titleImage;
    }
    if (OF.page.barButton) {
      options.barButton = OF.page.barButton;
    }
    if (OF.page.barButtonImage) {
      options.barButtonImage = OF.page.barButtonImage;
    }
    OF.loader.hide();
    return OF.action.now('contentLoaded', options);
  };
  OF.barButton = function(title, onTouch) {
    var options;
    options = {};
    if (title.match(/\.png$/)) {
      options.image = title.replace('xdpi.png', "" + OF.dpi + ".png");
    } else {
      options.title = title;
    }
    OF.page.barButtonTouch = onTouch;
    return OF.action('addBarButton', options);
  };
  OF.goBack = function(options) {
    var onComplete;
    if (options == null) {
      options = {};
    }
    OF.touch.cancel();
    if (OF.init.isLoaded && OF.pages.length >= 1) {
      if (options.root) {
        OF.pages.splice(1, OF.pages.length - 1);
      } else if (OF.pages.length === 1) {
        OF.action.now('dismiss');
        return;
      } else {
        OF.pages.pop();
      }
      onComplete = options.complete;
      delete options.complete;
      OF.action.now('back', options, function() {
        return OF.loadTopPage(onComplete);
      });
    } else {
      if (!OF.device.ios3 || (OF.device.ios3 && OF.api.activeRequestIDs.length === 0)) {
        OF.contentLoaded(options);
      }
    }
    OF.init.isLoaded = true;
    return OF.loader.hide();
  };
  OF.alert = function(title, message, options) {
    if (options == null) {
      options = {};
    }
    options.title = title;
    options.message = message;
    OF.action('alert', options);
    if (OF.isBrowser) {
      return alert("" + options.title + "\n\n" + options.message);
    }
  };
  OF.confirm = function(title, message, positive, negative, positiveCallback, negativeCallback) {
    var confirmMessage;
    if (OF.isBrowser || !OF.action.isSupported('confirm')) {
      confirmMessage = title.length > 0 ? "" + title + "\n\n" + message : "" + message;
      if (confirm(confirmMessage)) {
        return positiveCallback();
      } else {
        return typeof negativeCallback === "function" ? negativeCallback() : void 0;
      }
    } else {
      return OF.action('confirm', {
        title: title,
        message: message,
        positive: positive,
        negative: negative,
        callback: function(result) {
          if (result) {
            return positiveCallback();
          } else {
            return typeof negativeCallback === "function" ? negativeCallback() : void 0;
          }
        }
      });
    }
  };
  OF.loader = {
    count: 0,
    show: function() {
      if (OF.device.ios3) {
        return;
      }
      $('#header .loading').show();
      return OF.loader.count += 1;
    },
    hide: function() {
      if (OF.device.ios3) {
        return;
      }
      OF.loader.count -= 1;
      if (OF.loader.count < 0) {
        OF.loader.count = 0;
      }
      if (OF.loader.count === 0) {
        return $('#header .loading').hide();
      }
    }
  };
  OF.userDidLogin = function(user) {
    var _base, _ref;
    if ((user != null ? (_ref = user.id) != null ? _ref.toString().length : void 0 : void 0) && user.id.toString() !== '0') {
      OF.user = user;
    } else {
      OF.user = {
        name: null,
        id: null
      };
    }
    return typeof (_base = OF.page).userDidLogin === "function" ? _base.userDidLogin(user) : void 0;
  };
  OF.settings = {
    enabled: false,
    expectJsonAsString: null,
    clear: function(key) {
      return OF.settings.write(key, null);
    },
    write: function(key, value) {
      OF.action('writeSetting', {
        key: key,
        value: JSON.stringify(value)
      });
      if (OF.isBrowser) {
        return OF.settings.browser.write(key, value);
      }
    },
    read: function(key, callback) {
      var clientVersion, origCallback;
      if (OF.settings.expectJsonAsString == null) {
        clientVersion = OF.clientVersion ? OF.clientVersion.split('.') : [0, 0, 0];
        OF.settings.expectJsonAsString = OF.platform === 'android' && (parseInt(clientVersion[0], 10) || 0) <= 1 && (parseInt(clientVersion[1], 10) || 0) <= 7 && (parseInt(clientVersion[2], 10) || 0) <= 5;
      }
      if (OF.settings.expectJsonAsString) {
        origCallback = callback;
        callback = function(jsonStringVal) {
          return origCallback(jsonStringVal ? JSON.parse(jsonStringVal) : null);
        };
      }
      OF.action('readSetting', {
        key: key,
        callback: callback
      });
      if (OF.isBrowser || !OF.settings.enabled) {
        return callback(OF.settings.browser.read(key));
      }
    },
    browser: (function() {
      var obj, save, settingsObj;
      if (OF.isDevice) {
        obj = {};
        obj.clearAll = obj.write = obj.read = $.noop;
        return obj;
      }
      settingsObj = null;
      U.each(document.cookie.split('; '), function(cookie) {
        if (cookie.split('=')[0] === 'WEBUI_SETTINGS') {
          try {
            return settingsObj = JSON.parse(decodeURIComponent(cookie.split('=')[1]));
          } catch (e) {
            return settingsObj = {};
          }
        }
      });
      settingsObj || (settingsObj = {});
      save = function() {
        return document.cookie = "WEBUI_SETTINGS=" + (encodeURIComponent(JSON.stringify(settingsObj)));
      };
      return {
        clearAll: function() {
          settingsObj = {};
          return save();
        },
        write: function(key, value) {
          settingsObj[key] = value;
          return save();
        },
        read: function(key) {
          var val;
          if ((val = settingsObj[key]) != null) {
            return val;
          } else {
            return null;
          }
        }
      };
    })()
  };
  OF.specs = {
    load: function(pagePath) {
      var flow;
      if (window.runSpecs) {
        OF.api.allow = false;
        flow = pagePath.split('/')[0];
        $.loadScript("../spec/" + flow + "/index");
        jasmine.WaitsForBlock.TIMEOUT_INCREMENT = OF.isDevice ? 500 : 100;
        if (OF.device.ios3) {
          jasmine.WaitsForBlock.TIMEOUT_INCREMENT = 1000;
          return jasmine.DEFAULT_TIMEOUT_INTERVAL = 10000;
        }
      }
    },
    run: function() {
      if (window.runSpecs && OF.pages.length === 1) {
        return window.runSpecs = false;
      }
    }
  };
  if (typeof NativeInterface !== "undefined" && NativeInterface !== null) {
    if (typeof NativeInterface.frameworkLoaded === "function") {
      NativeInterface.frameworkLoaded();
    }
  }
  $(document).ready(OF.init.firstPage);
  OF.navigationStack = OF.pages;
  OF.navigateToUrlCallback = OF.push.ready;
  OF.topNavigationItem = $.deprecate(OF.topPage, 'OF.topNavigationItem()', 'OF.topPage()');
  OF.navigateToUrl = $.deprecate(OF.push, 'OF.navigateToUrl()', 'OF.push()');
}).call(this);
