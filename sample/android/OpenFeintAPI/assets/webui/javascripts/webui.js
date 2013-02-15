// DO NOT EDIT
//   Generated from javascripts/webui.coffee
//
(function() {
  var cacheBuster, script, scripts, _i, _len;
  scripts = ['jquery', 'template', 'underscore', 'webui-helper', 'webui-core', 'webui-page', 'webui-api', 'webui-action', 'webui-touch', 'webui-analytics'];
  if (typeof JSON === "undefined" || JSON === null) {
    scripts.push('json2');
  }
  cacheBuster = new Date().getTime();
  for (_i = 0, _len = scripts.length; _i < _len; _i++) {
    script = scripts[_i];
    document.write(("<script type='text/javascript' src='javascripts/" + script + ".js?" + cacheBuster + "'></scr") + "ipt>");
  }
  document.write('<script type="text/javascript"> $.loadCss("webui"); </scr' + 'ipt>');
  document.write('<script type="text/javascript"> $.loadCss("webui3"); </scr' + 'ipt>');
}).call(this);
