// DO NOT EDIT
//   Generated from javascripts/webui-page.coffee
//
(function() {
  var __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; };
  OF.Page = (function() {
    function Page(pageData, url, params) {
      U.extend(this, pageData);
      this.url = url;
      this.id = "page_" + (url.replace(/\W+/g, '-')) + "_" + (new Date().getTime());
      this.scrollPosition = 0;
      this.savedFunctions = {};
      this.params = U.extend(this.params || {}, params);
    }
    Page.prototype.timeout = function(delay, fn) {
      return setTimeout(__bind(function() {
        if (this.exists()) {
          return fn();
        }
      }, this), delay);
    };
    Page.prototype.exists = function() {
      return OF.pages.indexOf(this) > -1;
    };
    Page.prototype.isCurrent = function() {
      return OF.page === this;
    };
    Page.prototype.detach = function() {
      return this.nodes = $('#page').contents().detach();
    };
    Page.prototype.showContent = function() {
      this.nodes || (this.nodes = ['<div id="event_context">', this.html, '</div>'].join(''));
      return $('#page').html(this.nodes).append($("<div class='eventHandle'>")).attr('data-page_id', this.id);
    };
    Page.prototype.eventHandle = function() {
      return this._eventHandle || (this._eventHandle = $("#page > .eventHandle"));
    };
    Page.prototype.saveFunction = function(fn) {
      var string;
      if ($.isFunction(fn)) {
        string = U.uniqueId('fn');
        this.savedFunctions[string] = fn;
        return "OF.pages[" + (OF.pages.indexOf(this)) + "].savedFunctions." + string;
      }
    };
    return Page;
  })();
}).call(this);
