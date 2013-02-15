//iOS 4.0.x and under has a bug where OFFSET.TOP() REPORTS WRONG POSITION AFTER SCROLL 
OF.device.ios4_0_x = /iPhone.*4\.0.*/.test(OF.device.os);

// Open the dashboard (or prompt login) when the leaf bar button is tapped.
OF.barButtonTouch = function() {
  OF.trackEvent('game_channel', 'dashboard_button');
  if (OF.user && OF.user.id) {
    OF.action('dashboard');
  } else {
    OF.action('showEnableView', { message: "Join the OpenFeint Community!", button: "Sign me up!" });
  }
};

OF.api.handleDisconnect = function() {
  var inOfflinePage = OF.page && OF.page.url && OF.page.url.indexOf('game_channel/offline') === 0;
  if (!inOfflinePage) {
     OF.push('game_channel/offline');
     OF.action('reload');
  }
};

OF.appStore = function(gameId) {
  OF.action('openMarket', {
    url: OF.serverUrl +'client_applications/'+ gameId +'/buy_now'+
                      '?user_id='+ (OF.user.id ? OF.user.id : '') +
                      '&ga_id='+ OF.GA.cookie.id
  });
};

// Send pings to tapjoy
OF.tapjoy = (function() {
  var params = {
    udid:             OF.device.identifier,
    device_type:      OF.device.hardware,
    os_version:       U.last(OF.device.os.split(' ')),
    app_id:           '00b2897c-eadf-4ac6-a69b-701ca6734214',
    app_version:      OF.game.version,
    library_version:  '7.4.0',
    country_code:     'US',
    language_code:    'en',
    lad:              '0', // '0' for normal, '42' for jailbroken.
  };
  
  var sendReq = function(reqParams) {
    var tapJoyReq = new Image();
    tapJoyReq.src = 'https://ws.tapjoyads.com/connect?'+ $.urlEncode(reqParams);
  };
  
  return {
    install: function() {
      sendReq(params);
    },
    action: function() {
      var actionParams = U.clone(params);
      actionParams.app_id = '7f2d2441-626a-4755-983c-5ece2809c015';
      sendReq(actionParams);
    }
  }
}());

(function($){
  $.fn.countDownOld = function(options) {
    var endHour = (options && options.endHour) || 24; //24:00 UTC is 5:00pm PST
    var el = this;
    
    var intervalID = setInterval(function() {
      
      var now = new Date(); // Get Current Time

      var end = new Date(now.getUTCFullYear(), now.getUTCMonth(), now.getUTCDate()); // get target hour today
      end.setUTCHours(endHour,00,0); //Make sure we are seting 24:00 UTC (5:00pm PST)
      
      if (now > end) end.setDate(end.getDate() + 1);  // ensure target end time is in the future
      
      var nowInMilliseconds = now.getTime(); // Convert Now to millseconds
      var endInMilliseconds = end.getTime(); // Convert end target time to millseconds
      var millsecondsTillEnd = (endInMilliseconds - nowInMilliseconds); // end minus now equals remaining time. Easy math in milli 
      var hoursTillEnd = Math.floor(millsecondsTillEnd / 3600000); // Multiplying buy millseconds in an hour and rounding the number down gives us the hours remaining 
      
       
      var minTillEnd = Math.floor(59 - now.getMinutes());
      var secondsTillEnd = (59 - now.getSeconds());
      secondsTillEnd = (secondsTillEnd < 10 ? '0' : '') + secondsTillEnd;
      
      $(el).html(hoursTillEnd + 'h ' +  minTillEnd + 'm ' +  secondsTillEnd + 's');

    }, 1000);
  }
})(jQuery);

OF.getTemperature = function(vote_target, vote_count, votes_bubble) {
    $('.thermometer .mercury').width(0);
    maxWidth = $('.thermometer').width() - 9;
    var x = vote_target / vote_count;
    var temperature = maxWidth / x;
    temperatureSpeed = 1500 / x;
    $('.thermometer .mercury').animate(
      {
        width: temperature
      }, 
      temperatureSpeed,
      function() {
        if (votes_bubble) {
          var exclamation = (vote_count == vote_target) ? "!" : '';
          $('.ammount span').text(addCommas(vote_count) + " votes" + exclamation);
          if ( vote_count > vote_target - (vote_target * .25)) { //greater than 75% full
            $('.ammount').css({
              'left' : (temperature - 54) + 'px', 
              'font-weight' : 'bolder'
            }).unhide();
            $('.ammount span').css('color', '#ea2929');
            $('.ammount .indicator').css({'left' : '61px'})
          } else if ( vote_count < vote_target * .25) { //less than 25% full
            $('.ammount').css({
              'left' : (temperature + 9) + 'px', 
              'font-weight' : 'bolder'
            }).unhide();
            $('.ammount .indicator').css({'left' : '-2px'})
          } else {
            $('.ammount').css({
              'left' : (temperature - 22) + 'px',
              'font-weight' : 'bolder'
            }).unhide();
          }
        } else {
          var exclamation = (vote_count == vote_target) ? "!" : '';
          $('.thermometer .mercury').text(addCommas(vote_count) + " votes" + exclamation);
        }
    });
};

OF.gcTime = {
  timerID: null,
  totalSecsTillEnd: 0,
  cleanTime : function(ISO8601) {
    // Cleans up ISO8601 time format and makes it work for webkit on iphone
    // For some reason ISO8601 format works on FF, and desktop versions of Webkit
    
    // Only works for dates in this format:
    // 2011-03-18T22:27:14Z
    
    // Returns: 
    // 2008/12/19 16:39:57.67
    return $.trim(ISO8601.replace(/-/g,"/").replace(/[TZ]/g," "));
  },
  formatTimeLeft : function(tL) {
    var r = (tL.hours / 24);
    var t = ' Days';
      if (tL.hours < 48) { 
        r = tL.hours;
        t = ' Hours'; 
        if (tL.hours < 2) {
        var r = (tL.hours * 60) + tL.minutes;
          t = ' min';
        }            
      }
    return {
      time: parseInt(r),
      type: t
    };
  },
  secondsToHoursMinutes : function(totalSecsTillEnd) { // Returns Object {hours : 19, minutes : 23, : seconds : 10}
    if (!totalSecsTillEnd) {
      totalSecsTillEnd = null;
    } else {
      this.totalSecsTillEnd = totalSecsTillEnd;
    }
    if (this.totalSecsTillEnd > 0) {
      var totalSecsTillEnd = this.totalSecsTillEnd;
      var now = new Date(); // Get Current Time
      var hoursTillEnd = Math.floor(totalSecsTillEnd / 3600); //Hours Remaining
      var hoursTillEndInSecs = (hoursTillEnd * 3600);
      var secsTillEndLeft = (totalSecsTillEnd - hoursTillEndInSecs);
      var minTillEnd = Math.floor(secsTillEndLeft / 60);
      var minTillEndLeftInSecs = (minTillEnd * 60);
      var secsTillEnd = Math.floor(secsTillEndLeft - minTillEndLeftInSecs);

      if (totalSecsTillEnd <= -1) {
        OF.stop();
      } else {
        timeRemaining = {
          hours   : hoursTillEnd,
          minutes : minTillEnd,
          seconds : secsTillEnd
        }
      }
    }
    return timeRemaining;
  },
  humanReadableTimePassed: function(timestamp) {
      var now = $.now() / 1000;
      var seconds = now - timestamp;
      var time = OF.gcTime.formatTimeLeft(OF.gcTime.secondsToHoursMinutes(seconds));
      return time.time + time.type;
  }
};

Date.prototype.abbrMonths = [
  'Jan',
  'Feb',
  'Mar',
  'Apr',
  'May',
  'Jun',
  'Jul',
  'Aug',
  'Sep',
  'Oct',
  'Nov',
  'Dec'
];

Date.prototype.DaysOfTheWeek = [
  'Sunday',
  'Monday',
  'Tuesday',
  'Wednesday',
  'Thursday',
  'Friday',
  'Saturday'
];

function addCommas(nStr) {
	nStr += '';
	x = nStr.split('.');
	x1 = x[0];
	x2 = x.length > 1 ? '.' + x[1] : '';
	var rgx = /(\d+)(\d{3})/;
	while (rgx.test(x1)) {
		x1 = x1.replace(rgx, '$1' + ',' + '$2');
	}
	return x1 + x2;
}

//http://james.padolsey.com/javascript/recursive-pretty-date/
var niceTime = function(time) {
  var ints = {
    second: 1,
    minute: 60,
    hour: 3600,
    day: 86400,
    week: 604800,
    month: 2592000,
    year: 31536000
  };

  time = +new Date(time);

  var gap = ((+new Date()) - time) / 1000,
  amount, measure;

  for (var i in ints) {
    if (gap > ints[i]) { measure = i; }
  }

  amount = gap / ints[measure];
  amount = gap > ints.day ? (Math.round(amount * 100) / 100) : Math.round(amount);
  amount = parseInt(amount)
  amount += ' ' + measure + (amount > 1 ? 's' : '') + ' ago';
  return amount;

}

/**
*
*  Secure Hash Algorithm (SHA1)
*  http://www.webtoolkit.info/
*
**/
 
function sha1(msg) {
 
	function rotate_left(n,s) {
		var t4 = ( n<<s ) | (n>>>(32-s));
		return t4;
	};
 
	function lsb_hex(val) {
		var str="";
		var i;
		var vh;
		var vl;
 
		for( i=0; i<=6; i+=2 ) {
			vh = (val>>>(i*4+4))&0x0f;
			vl = (val>>>(i*4))&0x0f;
			str += vh.toString(16) + vl.toString(16);
		}
		return str;
	};
 
	function cvt_hex(val) {
		var str="";
		var i;
		var v;
 
		for( i=7; i>=0; i-- ) {
			v = (val>>>(i*4))&0x0f;
			str += v.toString(16);
		}
		return str;
	};
 
 
	function Utf8Encode(string) {
		string = string.replace(/\r\n/g,"\n");
		var utftext = "";
 
		for (var n = 0; n < string.length; n++) {
 
			var c = string.charCodeAt(n);
 
			if (c < 128) {
				utftext += String.fromCharCode(c);
			}
			else if((c > 127) && (c < 2048)) {
				utftext += String.fromCharCode((c >> 6) | 192);
				utftext += String.fromCharCode((c & 63) | 128);
			}
			else {
				utftext += String.fromCharCode((c >> 12) | 224);
				utftext += String.fromCharCode(((c >> 6) & 63) | 128);
				utftext += String.fromCharCode((c & 63) | 128);
			}
 
		}
 
		return utftext;
	};
 
	var blockstart;
	var i, j;
	var W = new Array(80);
	var H0 = 0x67452301;
	var H1 = 0xEFCDAB89;
	var H2 = 0x98BADCFE;
	var H3 = 0x10325476;
	var H4 = 0xC3D2E1F0;
	var A, B, C, D, E;
	var temp;
 
	msg = Utf8Encode(msg);
 
	var msg_len = msg.length;
 
	var word_array = new Array();
	for( i=0; i<msg_len-3; i+=4 ) {
		j = msg.charCodeAt(i)<<24 | msg.charCodeAt(i+1)<<16 |
		msg.charCodeAt(i+2)<<8 | msg.charCodeAt(i+3);
		word_array.push( j );
	}
 
	switch( msg_len % 4 ) {
		case 0:
			i = 0x080000000;
		break;
		case 1:
			i = msg.charCodeAt(msg_len-1)<<24 | 0x0800000;
		break;
 
		case 2:
			i = msg.charCodeAt(msg_len-2)<<24 | msg.charCodeAt(msg_len-1)<<16 | 0x08000;
		break;
 
		case 3:
			i = msg.charCodeAt(msg_len-3)<<24 | msg.charCodeAt(msg_len-2)<<16 | msg.charCodeAt(msg_len-1)<<8	| 0x80;
		break;
	}
 
	word_array.push( i );
 
	while( (word_array.length % 16) != 14 ) word_array.push( 0 );
 
	word_array.push( msg_len>>>29 );
	word_array.push( (msg_len<<3)&0x0ffffffff );
 
 
	for ( blockstart=0; blockstart<word_array.length; blockstart+=16 ) {
 
		for( i=0; i<16; i++ ) W[i] = word_array[blockstart+i];
		for( i=16; i<=79; i++ ) W[i] = rotate_left(W[i-3] ^ W[i-8] ^ W[i-14] ^ W[i-16], 1);
 
		A = H0;
		B = H1;
		C = H2;
		D = H3;
		E = H4;
 
		for( i= 0; i<=19; i++ ) {
			temp = (rotate_left(A,5) + ((B&C) | (~B&D)) + E + W[i] + 0x5A827999) & 0x0ffffffff;
			E = D;
			D = C;
			C = rotate_left(B,30);
			B = A;
			A = temp;
		}
 
		for( i=20; i<=39; i++ ) {
			temp = (rotate_left(A,5) + (B ^ C ^ D) + E + W[i] + 0x6ED9EBA1) & 0x0ffffffff;
			E = D;
			D = C;
			C = rotate_left(B,30);
			B = A;
			A = temp;
		}
 
		for( i=40; i<=59; i++ ) {
			temp = (rotate_left(A,5) + ((B&C) | (B&D) | (C&D)) + E + W[i] + 0x8F1BBCDC) & 0x0ffffffff;
			E = D;
			D = C;
			C = rotate_left(B,30);
			B = A;
			A = temp;
		}
 
		for( i=60; i<=79; i++ ) {
			temp = (rotate_left(A,5) + (B ^ C ^ D) + E + W[i] + 0xCA62C1D6) & 0x0ffffffff;
			E = D;
			D = C;
			C = rotate_left(B,30);
			B = A;
			A = temp;
		}
 
		H0 = (H0 + A) & 0x0ffffffff;
		H1 = (H1 + B) & 0x0ffffffff;
		H2 = (H2 + C) & 0x0ffffffff;
		H3 = (H3 + D) & 0x0ffffffff;
		H4 = (H4 + E) & 0x0ffffffff;
 
	}
 
	var temp = cvt_hex(H0) + cvt_hex(H1) + cvt_hex(H2) + cvt_hex(H3) + cvt_hex(H4);
 
	return temp.toLowerCase();
 
}


//set the session start epoch time in seconds
var sessionStartTime = new Date(); 
sessionStartTime = sessionStartTime.getTime() / 1000; //Epoch Time in Seconds GC app was opened
OF.settings.write('apsalar_session_start_time', sessionStartTime);

//This function relies on heavily on the inner workigns of Google Analytics
var apsalarAnalytics = function(methodType, analyticsData, analyticsKey) {
  var sessionLength = 0;
  
  //Read Apsalar Session Start and calculate time between session start and right now
  OF.settings.read('apsalar_session_start_time', function(val) {
    if (val) {
      var now = new Date();
      now = now.getTime() / 1000;
      sessionLength = (now - val).toFixed(1);
    }
  });
  
  var qs, key, secret, domain, hash, url, trackingPixel;

  key = "raleighvon";
  secret = "00OXbsFm";
  domain = "http://e.apsalar.com/api/v1";
  
  // apsalar api only accepts the os version number as a float so we need to get the version from the OF.device.os 
  var patt = /\d+[\.]*\d*[\.]*\d*$/; //rexeg to get only version # from OF.device.os
  var version = patt.exec(OF.device.os);
  
  switch(methodType) {
      case 'start':
        qs = 'a=' + key + '&u=' + OF.device.identifier + '&rt=json&av=' + OF.game.version + '&c=wifi&i=' + OF.GA.domain + '&p=' + OF.platform + '&s=' + OF.GA.cookie.id + '&v=' + version + '&n=' + analyticsKey;
        break;
      case 'event':
        qs = 'a=' + key + '&u=' + OF.device.identifier + '&rt=json&av=' + OF.game.version + '&i=' + OF.GA.domain + '&p=' + OF.platform + '&s=' + OF.GA.cookie.id + '&t=' + sessionLength + '&v=' + version + '&e=' + analyticsData + '&n=' + analyticsKey;
        break;
  }

  hash = sha1(secret +  '?' + qs);
    
  url = domain + '/' + methodType + '?' + qs + '&h=' + hash;
  
  trackingPixel = new Image();
  trackingPixel.src = url;
};


var GACopy = OF.GA.track;
OF.GA.track = function(analyticsData, analyticsType) {
  GACopy.apply(OF.GA, arguments);
  
  //Get the key from the filepath in analyticsData
  var patt = /[^\/]*$/;
  var extractedKey = patt.exec(analyticsData);
  var analyticsKey = extractedKey
  
  if(analyticsType === 'page') { apsalarAnalytics('event', analyticsData, analyticsKey) } 
};
