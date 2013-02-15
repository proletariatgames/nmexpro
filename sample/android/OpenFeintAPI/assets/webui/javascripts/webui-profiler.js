// DO NOT EDIT
//   Generated from javascripts/webui-profiler.coffee
//
(function() {
  /*
    This is a tool for profiling performance. It is very rough around the edges at the moment.
    Add it to webui.coffee's scripts array to load it.
    Add `profiler.tap "message"` commands at key points during the execution.
    If you want to get rid of the timeout/interval spam, uncomment it at the bottom of this file.
  */  OF.profiler = (function() {
    var ProfilerEvent, alert, clear, dump, events, format, getStr, init, jsRunning, loaded, outputDiv, setAutoAlert, tap, timeoutOverride, _setInterval, _setTimeout;
    events = [];
    loaded = false;
    _setTimeout = window.setTimeout;
    _setInterval = window.setInterval;
    outputDiv = null;
    ProfilerEvent = (function() {
      function ProfilerEvent(message) {
        this.time = Date.now();
        this.message = message;
      }
      return ProfilerEvent;
    })();
    init = function() {
      outputDiv = $("<div id=\"out\"></div>");
      outputDiv.css({
        'background-color': '#eee',
        'white-space': 'pre',
        'border': 'solid black 1px'
      });
      return $("body").prepend(outputDiv);
    };
    jsRunning = false;
    tap = function(message) {
      events.push(new ProfilerEvent(message));
      if (!jsRunning) {
        jsRunning = true;
        return _setTimeout(function() {
          OF.profiler.tap(">-----------------------");
          return jsRunning = false;
        }, 1);
      }
    };
    dump = function() {
      return console.log(getStr());
    };
    getStr = function() {
      var event, start, str, time, _i, _len;
      time = events[0].time;
      start = events[0].time;
      str = "";
      for (_i = 0, _len = events.length; _i < _len; _i++) {
        event = events[_i];
        str = ("" + (format(event.time - time)) + "," + (format(event.time - start)) + "|" + event.message + "\n") + str;
        time = event.time;
      }
      return str;
    };
    alert = function() {
      if (outputDiv != null) {
        outputDiv.html(getStr());
      }
      if (!loaded) {
        loaded = true;
        return OF.profiler.tap("Loading");
      }
    };
    format = function(diff) {
      var isolate, pos, seconds, str, _ref;
      str = "";
      seconds = diff / 1000;
      for (pos = 2, _ref = -3; 2 <= _ref ? pos <= _ref : pos >= _ref; 2 <= _ref ? pos++ : pos--) {
        isolate = Math.floor(seconds / Math.pow(10, pos)) % 10;
        if (pos <= 0 || seconds > Math.pow(10, pos)) {
          str += isolate;
        } else {
          str += " ";
        }
        if (pos === 0) {
          str += '.';
        }
      }
      return str;
    };
    setAutoAlert = function(delay) {
      if (events.length > 0) {
        return alert();
      } else {
        return _setTimeout(setAutoAlert, delay, delay);
      }
    };
    clear = function() {
      events = [];
      return OF.profiler.setAutoAlert(10000);
    };
    timeoutOverride = function() {
      var idSeed;
      console.warn("This is some pretty heavy stuff you just turned on. Maybe you should reconsider.");
      idSeed = 0;
      window.setTimeout = function() {
        var fnc, id, timeoutArgs;
        id = idSeed++;
        timeoutArgs = arguments;
        OF.profiler.tap("Timeout id: " + id + " time: " + timeoutArgs[1] + "ms code:" + (timeoutArgs[0].toString().replace(/[\n\s]+/g, ' ')));
        console.log("Timeout Created, " + id + ":");
        console.log(timeoutArgs);
        fnc = function() {
          OF.profiler.tap("Timeout " + id + " Ran time: " + timeoutArgs[1] + "ms");
          timeoutArgs[0].apply(this, Array.prototype.slice.call(timeoutArgs, 2));
          return OF.profiler.tap("Timeout " + id + " Done");
        };
        return _setTimeout(fnc, timeoutArgs[1]);
      };
      U.defer = function() {
        var fnc, id, timeoutArgs;
        id = idSeed++;
        timeoutArgs = arguments;
        OF.profiler.tap("Defer id: " + id + " code:" + (timeoutArgs[0].toString().replace(/[\n\s]+/g, ' ')));
        console.log("Defer Created, " + id + ":");
        console.log(timeoutArgs);
        fnc = function() {
          OF.profiler.tap("Defer " + id + " Ran");
          timeoutArgs[0].apply(this, Array.prototype.slice.call(timeoutArgs, 1));
          return OF.profiler.tap("Defer " + id + " Done");
        };
        return _setTimeout(fnc, 1);
      };
      return window.setInterval = function() {
        var fnc, id, intervalArgs;
        id = idSeed++;
        intervalArgs = arguments;
        OF.profiler.tap("Interval id: " + id + " time: " + intervalArgs[1] + "ms");
        console.log("Interval Created, " + id + ":");
        console.log(intervalArgs);
        fnc = function() {
          OF.profiler.tap("Interval " + id + " Ran time: " + intervalArgs[1] + "ms");
          intervalArgs[0].apply(this, Array.prototype.slice.call(intervalArgs, 2));
          return OF.profiler.tap("Interval " + id + " Done");
        };
        return _setInterval(fnc, intervalArgs[1]);
      };
    };
    return {
      init: init,
      dump: dump,
      tap: tap,
      alert: alert,
      setAutoAlert: setAutoAlert,
      clear: clear,
      timeoutOverride: timeoutOverride
    };
  })();
  $(function() {
    return OF.profiler.init();
  });
  OF.profiler.setAutoAlert(10000);
}).call(this);
