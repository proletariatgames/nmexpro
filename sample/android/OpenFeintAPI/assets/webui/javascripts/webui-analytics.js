// DO NOT EDIT
//   Generated from javascripts/webui-analytics.coffee
//
(function() {
  var hash, initComplete, now, rand, trackingPixelBaseURL;
  var __slice = Array.prototype.slice;
  OF.GA = {};
  OF.GA.setAccount = function(account, domain) {
    OF.GA.account = account;
    OF.GA.domain = domain;
    return OF.GA.domainHash = hash(domain);
  };
  OF.GA.page = function(url) {
    if (!url) {
      url = OF.page.url;
    }
    OF.GA.sessionViews++;
    return OF.GA.track(url, 'page');
  };
  OF.GA.event = function(category, action, label, value) {
    OF.log("GA EVENT: " + category + ", " + action + ", " + label + ", " + value);
    return OF.GA.track(OF.page.url, 'event', category, action, label, value);
  };
  trackingPixelBaseURL = "http://www.google-analytics.com/__utm.gif";
  initComplete = false;
  rand = function() {
    return $.random(1, 0x7fffffff);
  };
  now = function() {
    return Math.floor(new Date().getTime() / 1000).toString();
  };
  hash = function(d) {
  var a=1,c=0,h,o;
  if(d) {
    a=0;
    for(h=d.length-1;h>=0;h--){
      o=d.charCodeAt(h);
      a=(a<<6&268435455)+o+(o<<14);
      c=a&266338304;
      a=c!=0?a^c>>21:a;
    }
  }
  return a;
};;
  OF.GA.trackingUrl = function(url, type, cat, act, lbl, val) {
    var result;
    result = {};
    if (url.indexOf('/webui/') !== 0) {
      url = "/webui/" + url;
    }
    result.utmac = OF.GA.account;
    result.utmdt = OF.page.title;
    result.utmcs = 'UTF-8';
    result.utmhn = OF.GA.domain;
    result.utmn = rand();
    result.utmhid = rand();
    result.utmp = url.replace(/\?.*$/, '');
    result.utmr = '-';
    result.utmwv = '4.8.6';
    if (type === 'event') {
      result.utmt = type;
            if (cat != null) {
        cat;
      } else {
        cat = '';
      };
            if (act != null) {
        act;
      } else {
        act = '';
      };
            if (lbl != null) {
        lbl;
      } else {
        lbl = '';
      };
            if (val != null) {
        val;
      } else {
        val = '';
      };
      if (val.toString().length > 0 && isNaN(parseInt(val, 10))) {
        console.warn("GA EVENT: value is not an integer: " + cat + ", " + act + ", " + lbl + ", " + val);
      }
      result.utme = "5(" + cat + "*" + act + "*" + lbl + ")(" + val + ")";
    }
    result.utmcc = [];
    result.utmcc.push('__utma=' + [OF.GA.domainHash, OF.GA.cookie.id, OF.GA.cookie.initialDate, OF.GA.cookie.lastDate, now(), OF.GA.sessions].join('.'));
    result.utmcc.push('__utmb=' + [OF.GA.domainHash, OF.GA.sessionViews, 10, now()].join('.'));
    if (OF.GA.sessionViews > 1) {
      result.utmcc.push("__utmc=" + OF.GA.domainHash);
    }
    result.utmcc.push('__utmz=' + [OF.GA.domainHash, OF.GA.cookie.lastDate, OF.GA.sessions, 1, ['utmccn=(organic)', 'utmcsr=(organic)', 'utmctr=-', 'utmcmd=organic'].join('|') + ';'].join('.'));
    result.utmcc = result.utmcc.join(';+');
    return "" + trackingPixelBaseURL + "?" + ($.urlEncode(result));
  };
  OF.GA.track = function(url, type, cat, act, lbl, val) {
    var trackingPixel, trackingUrl;
    OF.api.post('/xp/events', {
      params: {
        event: {
          webui: {
            title: OF.page.title,
            url: url,
            type: type,
            cat: cat,
            act: act,
            lbl: lbl,
            val: val
          }
        }
      }
    });
    trackingUrl = OF.GA.trackingUrl(url, type, cat, act, lbl, val);
    if (OF.GA.enabled) {
      trackingPixel = new Image();
      trackingPixel.src = trackingUrl;
    }
    return trackingUrl;
  };
  OF.GA.init = function() {
    if (initComplete) {
      return;
    }
    initComplete = true;
    if (!OF.GA.domain) {
      OF.GA.setAccount('UA-3107048-15', 'xp.openfeint.com');
    }
    OF.GA.enabled = OF.isDevice && OF.settings.enabled && !OF.disableGA;
    OF.GA.cookie = {};
    OF.GA.sessionStart = now();
    OF.GA.sessions = 0;
    OF.GA.sessionViews = 0;
    OF.settings.read('ga_cookie_first_session_date', function(val) {
      if (!val) {
        val = now();
        OF.settings.write('ga_cookie_first_session_date', val);
      }
      return OF.GA.cookie.initialDate = val;
    });
    OF.settings.read('ga_cookie_last_session_date', function(val) {
      var _base;
      (_base = OF.GA.cookie).lastDate || (_base.lastDate = now());
      return OF.settings.write('ga_cookie_last_session_date', OF.GA.sessionStart);
    });
    OF.settings.read('ga_cookie_user_id', function(val) {
      if (!val) {
        val = rand();
        OF.settings.write('ga_cookie_user_id', val.toString());
      }
      return OF.GA.cookie.id = val;
    });
    return OF.settings.read('ga_cookie_sessions', function(val) {
      OF.GA.sessions = (parseInt(val, 10) || 0) + 1;
      return OF.settings.write('ga_cookie_sessions', OF.GA.sessions);
    });
  };
  OF.pushGACall = OF.GA.push = function() {
    var args, type, _ref, _ref2;
    type = arguments[0], args = 2 <= arguments.length ? __slice.call(arguments, 1) : [];
    if (type === '_trackPageview') {
      return (_ref = OF.GA).page.apply(_ref, args);
    } else if (type === '_trackEvent') {
      return (_ref2 = OF.GA).event.apply(_ref2, args);
    }
  };
  OF.trackEvent = OF.GA.event;
}).call(this);
