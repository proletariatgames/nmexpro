// DO NOT EDIT
//   Generated from javascripts/webui-touch.coffee
//
(function() {
  jQuery.fn.touch = function(func) {
    var $this;
    $this = $(this);
    if (func) {
      OF.touch.bindHandlers(this, func);
    } else {
      OF.touch(this);
    }
    return $this;
  };
  OF.touch = (function() {
    var dataAction, dataController, dataEvent, dataHref;
    dataEvent = function(element, eventString) {
      var _ref;
      if (eventString) {
        return (_ref = OF.GA).event.apply(_ref, eventString.split(','));
      }
    };
    dataHref = function(element, path) {
      var options, title;
      if (path) {
        options = {};
        if (title = element.attr('title')) {
          options.title = title;
        }
        return OF.push($.jsonifyUrl(path), options);
      }
    };
    dataAction = function(element, actionString) {
      return OF.action(actionString);
    };
    dataController = function(element, controllerString) {
      return OF.pushController(controllerString);
    };
    return function(element) {
      var data;
      if (OF.touch.disabled) {
        return;
      }
      element = $(element);
      data = element.data();
      dataEvent(element, data != null ? data.event : void 0);
      dataHref(element, data != null ? data.href : void 0);
      dataAction(element, data != null ? data.action : void 0);
      dataController(element, data != null ? data.controller : void 0);
      element.trigger('touch');
      OF.touch.disabled = true;
      return setTimeout(function() {
        return OF.touch.disabled = false;
      }, 500);
    };
  })();
  OF.touch.element = null;
  OF.touch.x = null;
  OF.touch.y = null;
  OF.touch.isScrolling = false;
  OF.touch.bindHandlers = (function() {
    var ValidSelectorWithParenthesis, jQueryPushStackSelectorPattern, selectorIsInvalid, touchend, touchstart;
    touchstart = function(event) {
      var $this, aTouch, ofTouch, ofTouchEl, _ref;
      $this = $(this);
      ofTouch = OF.touch;
      ofTouchEl = ofTouch.element;
      if (ofTouchEl && $(ofTouchEl).parents($this).length > 0) {
        return;
      } else if (ofTouchEl || ofTouch.isScrolling) {
        ofTouch.cancel();
        return;
      }
      event.stopPropagation();
      event = event.originalEvent;
      aTouch = ((_ref = event.targetTouches) != null ? _ref[0] : void 0) || {
        screenX: 0,
        screenY: 0
      };
      ofTouch.element = this;
      ofTouch.x = aTouch.screenX;
      ofTouch.y = aTouch.screenY;
      if (OF.page.scrolling) {
        return this.onTouchTimer = setTimeout(function() {
          return $this.addClass('touched');
        }, 75);
      } else {
        return $this.addClass('touched');
      }
    };
    touchend = function(event) {
      var touchEl, touchMethod;
      touchMethod = OF.touch;
      touchEl = touchMethod.element;
      event.stopPropagation();
      event = event.originalEvent;
      if (touchEl) {
        if (touchEl === this) {
          touchMethod(this);
        }
        return touchMethod.cancel();
      }
    };
    jQueryPushStackSelectorPattern = /[\(|\)]/;
    ValidSelectorWithParenthesis = /:(nth-[\w|\-]+)|(not)|(lang)|([l|g]t)|(has)|(eq)|(contains)\s*\(/i;
    selectorIsInvalid = function(sel) {
      return jQueryPushStackSelectorPattern.test(sel) && !ValidSelectorWithParenthesis.test(sel);
    };
    return function(elems, onTouch) {
      var ctx, sel, touchHandler;
      if (elems) {
        ctx = OF.topPage().eventContext;
        sel = typeof elems === 'string' ? elems : elems.selector;
        if (selectorIsInvalid(sel)) {
          throw new Error("Can't bind touch event on a element which is using JQuery pushStack selector '" + sel + "'");
        }
        elems = $(sel, ctx);
      } else {
        elems = $('*[data-href], *[data-event], *[data-action], *[data-controller]');
      }
      touchHandler = function(e) {
        e.stopPropagation();
        return onTouch.apply(this, arguments);
      };
      if (onTouch) {
        elems.die('touch').unbind('touch');
        elems.live('touch', touchHandler).bind('touch', touchHandler);
      }
      if (OF.isDevice) {
        elems.die('touchstart').die('touchend').unbind('touchstart').unbind('touchend');
        return elems.live('touchstart', touchstart).live('touchend', touchend).bind('touchstart', touchstart).bind('touchend', touchend);
      } else {
        elems.die('mousedown').die('mouseup').die('click');
        return elems.live('mousedown', function() {
          return $(this).addClass('touched');
        }).live('mouseup', function() {
          return $(this).removeClass('touched');
        }).live('click', function() {
          return OF.touch(this);
        });
      }
    };
  })();
  OF.touch.cancel = function() {
    var $ofTouchEl, ofTouchEl;
    ofTouchEl = OF.touch.element;
    if (ofTouchEl) {
      $ofTouchEl = $(ofTouchEl);
      clearTimeout(ofTouchEl.onTouchTimer);
      $ofTouchEl.removeClass('touched');
    }
    OF.touch.element = null;
    OF.touch.x = null;
    return OF.touch.y = null;
  };
  jQuery.fn.pretouch = function() {
    var $this;
    $this = $(this);
    $this.addClass('touched');
    U.defer(function() {
      return $this.removeClass('touched');
    });
    return $this;
  };
  $(document).ready(function() {
    return document.ontouchmove = function(event) {
      var aTouch, limit, ofPage, ofTouch, x, y;
      ofTouch = OF.touch;
      ofPage = OF.page;
      limit = ofPage.scrolling ? 5 : 25;
      aTouch = event.targetTouches[0];
      x = Math.abs(aTouch.screenX - ofTouch.x);
      y = Math.abs(aTouch.screenY - ofTouch.y);
      if (ofTouch.element && (x > limit || y > limit)) {
        ofTouch.cancel();
      }
      if (!ofPage.scrolling) {
        return event.preventDefault();
      }
    };
  });
}).call(this);
