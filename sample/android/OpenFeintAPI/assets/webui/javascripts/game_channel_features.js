// DO NOT EDIT
//   Generated from javascripts/game_channel_features.coffee
//
(function() {
  var About, Comments, DummyNewsPost, FeatureGamePromotion, Firesale, FiresalePage, FreeGameOfTheDay, GAME_CHANNEL_FLOW, Game, GameBase, GameChannel, GameListPage, GameListPromotionBase, GamePage, Interstitial, MoreGames, News, NewsPost, Notifications, PhotoNewsPost, PlatformSettings, PreviousFiresale;
  var __hasProp = Object.prototype.hasOwnProperty, __extends = function(child, parent) {
    for (var key in parent) { if (__hasProp.call(parent, key)) child[key] = parent[key]; }
    function ctor() { this.constructor = child; }
    ctor.prototype = parent.prototype;
    child.prototype = new ctor;
    child.__super__ = parent.prototype;
    return child;
  }, __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; }, __indexOf = Array.prototype.indexOf || function(item) {
    for (var i = 0, l = this.length; i < l; i++) {
      if (this[i] === item) return i;
    }
    return -1;
  };
  GAME_CHANNEL_FLOW = 'game_channel';
  PlatformSettings = {
    showEnableView: 'showEnableView'
  };
  this.PlatformSettings = PlatformSettings;
  if (OF.platform === 'android') {
    PlatformSettings = {
      showEnableView: 'dashboard'
    };
  }
  NewsPost = (function() {
    function NewsPost(post) {
      this.post = post;
    }
    NewsPost.prototype.body = function() {
      return this.post.body;
    };
    NewsPost.prototype.photo = function() {
      return '';
    };
    NewsPost.prototype.cssClass = function() {
      return "tumblr_post";
    };
    NewsPost.prototype.title = function() {
      return this.post.title;
    };
    NewsPost.prototype.tags = function() {
      if (this.post.tags) {
        return '#' + this.post.tags.join("&nbsp; #");
      } else {
        return '';
      }
    };
    NewsPost.prototype.html = function() {
      return "<div class=\"section " + (this.cssClass()) + "\">\n  <div class=\"cell title\">" + (this.title()) + "</div>\n  " + (this.photo()) + "\n  <div class=\"cell content\">\n    <div class=\"body\">" + (this.body()) + "</div>\n    <p class=\"comment\" data-tumblr-href=\"" + this.post.post_url + "\">Comment</p>\n    <p class=\"tags\">" + (this.tags()) + "</p>\n    <p class=\"readable_time\">" + (OF.gcTime.humanReadableTimePassed(this.post.timestamp)) + " ago</p>\n  </div>\n</div>";
    };
    return NewsPost;
  })();
  PhotoNewsPost = (function() {
    function PhotoNewsPost() {
      PhotoNewsPost.__super__.constructor.apply(this, arguments);
    }
    __extends(PhotoNewsPost, NewsPost);
    PhotoNewsPost.prototype.body = function() {
      return this.post.caption;
    };
    PhotoNewsPost.prototype.photo = function() {
      var alt_size, photo, photo_html, _i, _j, _len, _len2, _ref, _ref2;
      photo_html = '';
      _ref = this.post.photos;
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        photo = _ref[_i];
        _ref2 = photo.alt_sizes;
        for (_j = 0, _len2 = _ref2.length; _j < _len2; _j++) {
          alt_size = _ref2[_j];
          if (alt_size.width === 400) {
            photo_html += "<div class=\"cell photo\"><img src='" + alt_size.url + "'></div>";
          }
        }
      }
      return photo_html;
    };
    PhotoNewsPost.prototype.cssClass = function() {
      return "tumblr_post photo_post";
    };
    PhotoNewsPost.prototype.title = function() {
      var slug, url;
      url = this.post.post_url;
      slug = url.substring(url.lastIndexOf('/') + '/'.length);
      return slug.replace(/-/g, ' ');
    };
    return PhotoNewsPost;
  })();
  DummyNewsPost = (function() {
    function DummyNewsPost() {
      DummyNewsPost.__super__.constructor.apply(this, arguments);
    }
    __extends(DummyNewsPost, NewsPost);
    DummyNewsPost.prototype.html = function() {
      return '';
    };
    return DummyNewsPost;
  })();
  NewsPost.create = function(post) {
    switch (post.type) {
      case 'photo':
        return new PhotoNewsPost(post);
      case 'text':
        return new NewsPost(post);
      default:
        return new DummyNewsPost(post);
    }
  };
  About = (function() {
    function About(platform) {
      this.platform = platform;
      this.touchListener();
    }
    About.prototype.touchListener = function() {
      return $('#about .cell').touch(__bind(function() {
        OF.push("" + GAME_CHANNEL_FLOW + "/about", {
          params: {
            title: 'About'
          }
        });
        return OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/about");
      }, this));
    };
    return About;
  })();
  News = (function() {
    News.prototype.apiBaseUrl = '/xp/tumblr';
    function News(platform) {
      this.platform = platform;
      this.touchListener();
    }
    News.prototype.touchListener = function() {
      return $('#news').touch(__bind(function() {
        OF.push("" + GAME_CHANNEL_FLOW + "/news", {
          params: {
            title: 'Blog'
          }
        });
        OF.GA.event('index', "new");
        return OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/news");
      }, this));
    };
    News.prototype.showBlog = function() {
      var self;
      self = this;
      return OF.api.get(this.apiBaseUrl, {
        params: {
          platform: this.platform
        },
        success: function(data) {
          var posts;
          posts = data.response.posts;
          return self.render(posts);
        },
        failure: function() {
          return self.showError();
        }
      });
    };
    News.prototype.showError = function() {
      $('#indicator').hide();
      return $('#news_error, #news_header').unhide();
    };
    News.prototype.render = function(posts) {
      var html, newsPost, openUrl, post, _i, _len;
      $('#indicator').hide();
      $('#news_page, #news_header').unhide();
      html = '';
      for (_i = 0, _len = posts.length; _i < _len; _i++) {
        post = posts[_i];
        newsPost = NewsPost.create(post);
        html += newsPost.html();
      }
      $('#news_blog').html(html);
      openUrl = __bind(function(url) {
        if (this.platform === 'ios') {
          OF.action('openMarket', {
            url: url
          });
        }
        if (this.platform === 'android') {
          return OF.action('openBrowser', {
            src: url
          });
        }
      }, this);
      return $('#news_blog .comment').touch(function() {
        var url;
        url = $(this).attr('data-tumblr-href');
        return openUrl(url);
      });
    };
    return News;
  })();
  MoreGames = (function() {
    function MoreGames(platform, variant) {
      this.platform = platform;
      this.variant = variant;
      this.promos();
    }
    MoreGames.prototype.promos = function() {
      var params;
      params = this.variant ? {
        variant: this.variant
      } : {};
      this.promotionList = new Models.PromotionList('more_games', params);
      return this.promotionList.load({
        loader: '#more_games .loading',
        failure: $.noop,
        success: __bind(function(data) {
          var promotions;
          promotions = data.promotions;
          return this.renderList(promotions);
        }, this)
      });
    };
    MoreGames.prototype.renderList = function(promotions) {
      var html, promoTemplate, promotion, _i, _len;
      $('#more_games').unhide();
      promoTemplate = function(promotion) {
        return "      <div id=\"" + promotion.key + "\" class=\"cell\">        <div class=\"image icon_image\" style=\"background-image: url(" + promotion.icon_url + ")\"></div>        <div class=\"cell_content\">          <p>" + promotion.title + "</p>        </div>      </div>    ";
      };
      html = '';
      for (_i = 0, _len = promotions.length; _i < _len; _i++) {
        promotion = promotions[_i];
        html += promoTemplate(promotion);
      }
      $('#more_games .section').html(html);
      return $('#more_games .section .cell').touch(function() {
        var promotionKey;
        promotionKey = $(this).attr('id');
        return MoreGames.prototype.showGameList(promotionKey);
      });
    };
    MoreGames.prototype.showGameList = function(promotionKey) {
      OF.push("" + GAME_CHANNEL_FLOW + "/games", {
        params: {
          promo_key: promotionKey
        }
      });
      OF.GA.event('index', "more_games-" + promotionKey);
      return OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/more_games-" + promotionKey);
    };
    return MoreGames;
  })();
  GameListPromotionBase = (function() {
    function GameListPromotionBase(platform) {
      var params;
      this.platform = platform;
      this.load = __bind(this.load, this);;
      this.promo_container = "#" + this.container_id + "_promo";
      this.games_container = "#" + this.container_id + "_games";
      this.buyButtonText = "Get it Now!";
      params = {
        platform: this.platform,
        limit: this.limit
      };
      if (this.price_tag) {
        params.price = this.price_tag;
      }
      this.promotion = new Models.Promotion(this.promotion_id, params);
      this.load();
    }
    GameListPromotionBase.prototype.load = function() {
      return this.promotion.load({
        loader: "" + this.promo_container + " .loading",
        failure: $.noop,
        success: __bind(function(data) {
          var touchListener;
          this.render(data.promoted_games);
          touchListener = this.createTouchListener();
          $("" + this.games_container + " .cell").touch(touchListener);
          return $("" + this.games_container + " .button").touch(this.buttonListener);
        }, this)
      });
    };
    GameListPromotionBase.prototype.render = function(games) {
      var game, partials, template;
      template = tmpl('game_list_promotion_game');
      partials = (function() {
        var _i, _len, _results;
        _results = [];
        for (_i = 0, _len = games.length; _i < _len; _i++) {
          game = games[_i];
          _results.push(template($.extend(game, {
            buyButtonText: this.buyButtonText
          })));
        }
        return _results;
      }).call(this);
      $(this.games_container).html(partials.join(" "));
      return $(this.promo_container).unhide();
    };
    GameListPromotionBase.prototype.createTouchListener = function() {
      var container_id;
      container_id = this.container_id;
      return function() {
        var $data, $this, index;
        $this = $(this);
        index = $this.parent().index();
        $data = $this.data();
        OF.GA.event('index', "" + (container_id.toUpperCase()) + " cell", 'position', index);
        OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/" + container_id + "_cell/position-" + index);
        return OF.push("" + GAME_CHANNEL_FLOW + "/game", {
          params: {
            game_id: $data.gameid,
            promoted_game_id: $data.promotedgameid
          }
        });
      };
    };
    GameListPromotionBase.prototype.buttonListener = function() {
      var $this, index, marketIdentifer, _ref;
      $this = $(this);
      index = $this.closest('.section').index();
      marketIdentifer = $this.data().marketidentifer;
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index-buy_button");
      OF.GA.event('index', 'buy_button', 'position', index);
      if (((_ref = OF.user) != null ? _ref.id : void 0) != null) {
        return OF.page.timeout(500, function() {
          return GameBase.openMarket(marketIdentifer);
        });
      } else {
        return OF.action(PlatformSettings.showEnableView);
      }
    };
    return GameListPromotionBase;
  })();
  FreeGameOfTheDay = (function() {
    function FreeGameOfTheDay(platform, variant) {
      var prefix;
      this.platform = platform;
      this.variant = variant;
      this.promotion_id = 'free_game_of_the_day';
      this.price_tag = 'free';
      prefix = '';
      if (this.platform === 'android') {
        prefix = 'android_';
        if (this.variant === 'game_world') {
          prefix = 'att_';
        }
        this.price_tag = '';
      }
      this.promotion_id = "" + prefix + this.promotion_id;
      this.limit = 5;
      this.container_id = 'fgotd';
      FreeGameOfTheDay.__super__.constructor.call(this, this.platform);
      this.buyButtonText = 'FREE';
    }
    __extends(FreeGameOfTheDay, GameListPromotionBase);
    return FreeGameOfTheDay;
  })();
  FeatureGamePromotion = (function() {
    function FeatureGamePromotion(platform, variant) {
      this.platform = platform;
      this.variant = variant;
      this.promotion_id = 'featured_android';
      if (this.variant === 'game_world') {
        this.promotion_id = 'att_featured_game';
      }
      this.price_tag = '';
      this.limit = 1;
      this.container_id = 'featured_android';
      FeatureGamePromotion.__super__.constructor.call(this, this.platform);
    }
    __extends(FeatureGamePromotion, GameListPromotionBase);
    return FeatureGamePromotion;
  })();
  Notifications = (function() {
    function Notifications() {
      this.failOnIOS3();
      this.showPushNotification();
      this.hideNewsIfNotSupportSharing();
    }
    Notifications.prototype.failOnIOS3 = function() {
      if (OF.device.ios3) {
        return OF.settings.read('ios3_fail_shown', function(ios3FailShown) {
          if (!ios3FailShown) {
            OF.settings.write('ios3_fail_shown', true);
            return $('#ios3fail').removeClass('hidden');
          }
        });
      }
    };
    Notifications.prototype.showPushNotification = function() {
      return OF.settings.read('push_notification_payload', function(payload) {
        var payloadType;
        OF.page.pushPayload = payload;
        if (payload) {
          payloadType = payload.fire_sale ? 'fire_sale' : 'generic';
          OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/push_notification/" + payloadType);
          return OF.settings.write('push_notification_payload', null);
        }
      });
    };
    Notifications.prototype.hideNewsIfNotSupportSharing = function() {
      if (!OF.action.isSupported('socialPost')) {
        return $('#about_game_channel').hide();
      }
    };
    return Notifications;
  })();
  GameChannel = (function() {
    function GameChannel(platform, variant) {
      this.platform = platform;
      this.variant = variant;
      this.setVariant(this.variant);
      Models.setPlatform(this.platform);
      this.ios = this.platform === 'ios';
      this.android = this.platform === 'android';
      this.fgotd = new FreeGameOfTheDay(this.platform, this.variant);
      this.loadTopPromos();
      this.notifications = new Notifications();
      this.news = new News(this.platform);
      this.moreGames = new MoreGames(this.platform, this.variant);
      this.about = new About(this.platform);
    }
    GameChannel.prototype.appear = function() {
      if (this.ios) {
        return this.firesale.load();
      }
    };
    GameChannel.prototype.setVariant = function(variant) {
      if (variant) {
        OF.variant = variant;
        $('body').attr('id', variant);
      }
      if (variant === 'game_world') {
        $('#featured_android_promo h2 span').text('AT&T Featured Game');
        return $('#fgotd_promo h2 span').text('AT&T Free Games');
      }
    };
    GameChannel.prototype.loadTopPromos = function() {
      if (this.ios) {
        this.firesale = new Firesale(this.platform);
      }
      if (this.android) {
        this.enableLaunchOF();
        return this.feature_game = new FeatureGamePromotion(this.platform, this.variant);
      }
    };
    GameChannel.prototype.enableLaunchOF = function() {
      $('#launch_openfeint').touch(this.launchOpenFeint);
      return this.constructor.showPromosPanesAnd('#launch_openfeint');
    };
    GameChannel.prototype.launchOpenFeint = function() {
      if (OF.actionIsSupported('dashboard')) {
        OF.GA.event('index', 'launchOpenFeint');
        return OF.action('dashboard');
      } else {
        return OF.alert('Whoops... we can\'t launch OpenFeint', 'OpenFeint Dashboard is not supported on your device.');
      }
    };
    GameChannel.showPromosPanesAnd = function(otherPanes) {
      $('#top_promos .loading').hide();
      return $("" + otherPanes + ", #about_promo, #news_promo").removeClass('hidden');
    };
    return GameChannel;
  })();
  Firesale = (function() {
    Firesale.supportedStates = 'voting_on sale_pending sale_on sale_over sale_timeout target_votes_unmet scheduled'.split(' ');
    function Firesale(platform, refresh) {
      this.platform = platform;
      this.refresh = refresh != null ? refresh : true;
      this.firesale_promotion = new Models.Promotion('iphone_fire_sale');
    }
    Firesale.prototype.nextFireSaleDay = function() {
      var nfs, promo;
      promo = this.data.promotion;
      if (promo.next_fire_sale_at) {
        nfs = new Date(promo.next_fire_sale_at.replace(/-/g, "/").replace(/[TZ]/g, " "));
        return nfs.DaysOfTheWeek[nfs.getDay()];
      } else {
        return 'soon';
      }
    };
    Firesale.prototype.setupFeatureGameBackground = function() {
      var _ref;
      if (((_ref = this.promotion.wide_banner_url) != null ? _ref.length : void 0) > 0) {
        return $('#firesale_game .feature').css('background-image', "url(" + this.promotion.wide_banner_url + ")");
      }
    };
    Firesale.prototype.showStickerText = function(voteState) {
      var renderStickerText;
      renderStickerText = function(stickerText) {
        $('#sticker_text').html(stickerText);
        return $('#sticker').show();
      };
      switch (voteState) {
        case 'voting_on':
          return renderStickerText("Vote Now!");
        case 'sale_pending':
          return renderStickerText("Stay Tuned");
        case 'sale_on':
          return renderStickerText("Save<br>$" + (this.getSavings()));
      }
    };
    Firesale.prototype.getSavings = function() {
      return this.promotion.original_price - this.promotion.discount_price;
    };
    Firesale.prototype.load = function() {
      if (this.refresh) {
        this.firesale_promotion.load('current', {
          failure: $.noop,
          success: __bind(function(data) {
            return this.render(data);
          }, this)
        });
      }
      if (OF.device.ios3) {
        return this.refresh = false;
      }
    };
    Firesale.prototype.render = function(data) {
      var _ref;
      this.data = data;
      if (this.data.promoted_games.length === 0) {
        return false;
      }
      this.promotion = this.data.promoted_games[0].promoted_game;
      this.voteState = this.promotion.state;
      this.setupFeatureGameBackground();
      $.defer(__bind(function() {
        return GameChannel.showPromosPanesAnd('#firesale_promo');
      }, this));
      this.setupVotingState(this.voteState);
      this.interstitial = new Interstitial(this);
      this.interstitial.show();
      this.showStickerText(this.voteState);
      if (_ref = this.voteState, __indexOf.call(this.constructor.supportedStates, _ref) < 0) {
        $('#fire_sale').hide();
      }
      $('#firesale_game .feature').touch(__bind(function() {
        return this.openFireSale();
      }, this));
      $('#news_promo div[data-href], #about_promo div[data-href]').touch($.noop);
      OF.GA.event('index', "fire_sale_view_" + this.voteState);
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/fire_sale_view_" + this.voteState);
      if (OF.page.pushPayload && OF.page.pushPayload.fire_sale) {
        OF.page.pushPayload.fire_sale = false;
        return this.openFireSale();
      }
    };
    Firesale.prototype.setupVotingState = function(voteState) {
      return $("#firesale_promo, .buy_button_wrapper").addClass(voteState);
    };
    Firesale.prototype.openFireSale = function() {
      OF.push("" + GAME_CHANNEL_FLOW + "/fire_sale", {
        title: 'Fire Sale',
        params: {
          game_id: this.promotion.game.id,
          price: this.promotion.original_price,
          promotion_type: 'firesale',
          discount_price: this.promotion.discount_price
        }
      });
      OF.GA.event('index', "fire_sale_tap-" + this.voteState);
      return OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/fire_sale_tap-" + this.voteState);
    };
    return Firesale;
  })();
  Interstitial = (function() {
    function Interstitial(firesale) {
      this.firesale = firesale;
      this.interstitialPaneCloseListener = __bind(this.interstitialPaneCloseListener, this);;
      this.interstitialPaneBuyListener = __bind(this.interstitialPaneBuyListener, this);;
      this.voteState = this.firesale.voteState;
      this.promotion = this.firesale.promotion;
      this.indexPane = $('#index');
      this.interstitialPane = $('#firesale_interstitial');
      this.isVotingOn = this.voteState === 'voting_on';
      this.buttonBuy = this.interstitialPane.find('.buy_button');
    }
    Interstitial.prototype.show = function() {
      var _ref;
      if ((_ref = this.voteState) !== 'voting_on' && _ref !== 'sale_on') {
        return false;
      }
      return OF.settings.read('firesale_interstitial_last_viewed', __bind(function(storedTime) {
        var intervalReached, lastShown, lastShownInterval, lastVotingState, minimalLastShownInterval, now, votingStateChanged;
        minimalLastShownInterval = 86400000;
        now = new Date();
        lastShown = new Date(storedTime && storedTime.date);
        lastVotingState = this.voteState;
        if (storedTime != null ? storedTime.state : void 0) {
          lastVotingState = storedTime.state;
        }
        lastShownInterval = now.getTime() - lastShown.getTime();
        intervalReached = lastShownInterval > minimalLastShownInterval;
        votingStateChanged = this.voteState !== lastVotingState;
        if (intervalReached || votingStateChanged) {
          this.showFiresaleInterstitial();
          return OF.settings.write('firesale_interstitial_last_viewed', {
            date: now,
            state: this.voteState
          });
        }
      }, this));
    };
    Interstitial.prototype.showInterstitialPane = function() {
      OF.page.scrolling = false;
      this.indexPane.hide();
      return this.interstitialPane.unhide();
    };
    Interstitial.prototype.hideInterstitialPane = function() {
      OF.page.scrolling = true;
      this.interstitialPane.hide();
      return this.indexPane.unhide();
    };
    Interstitial.prototype.firesaleAnnouncement = function() {
      var html, timeRemaining, timeRemainingFrom;
      timeRemainingFrom = __bind(function(expiresTime) {
        var hourMinutesSecondsLeft;
        hourMinutesSecondsLeft = OF.gcTime.secondsToHoursMinutes(this.promotion.expires_in);
        return OF.gcTime.formatTimeLeft(hourMinutesSecondsLeft);
      }, this);
      html = '';
      if (this.voteState === 'voting_on') {
        html += "<h4>Vote now and save $" + (this.firesale.getSavings()) + " on " + this.promotion.game.name + "!</h4>";
        html += "<p>The sale starts after we reach " + this.promotion.target_votes + "!</p>";
      } else if (this.voteState === 'sale_on') {
        timeRemaining = timeRemainingFrom(this.promotion.expires_in);
        html += "<h4>" + timeRemaining.time + timeRemaining.type + " left to save $" + (this.firesale.getSavings());
        html += " on " + this.promotion.game.name + "!</h4><p>Hurry and get this deal before the sale ends</p>";
      }
      return html;
    };
    Interstitial.prototype.interstitialPaneBuyListener = function() {
      var promotion;
      OF.GA.event('interstitial', typeof isVotingOn !== "undefined" && isVotingOn !== null ? isVotingOn : {
        'vote': 'buy'
      });
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/fire_sale_interstitial_" + this.voteState + "_action_button");
      this.hideInterstitialPane();
      if (this.isVotingOn) {
        return this.firesale.openFireSale();
      } else {
        promotion = this.promotion;
        return OF.page.timeout(500, function() {
          return GameBase.openMarket("" + OF.serverUrl + "client_applications/" + promotion.game.id + "/buy_now");
        });
      }
    };
    Interstitial.prototype.interstitialPaneCloseListener = function() {
      OF.GA.event('interstitial', "" + this.voteState + "_no_thanks");
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/interstitial/" + this.voteState + "_no_thanks_button");
      return this.hideInterstitialPane();
    };
    Interstitial.prototype.showFiresaleInterstitial = function() {
      this.showInterstitialPane();
      if (this.isVotingOn) {
        this.buttonBuy.html("Check It Out!");
        this.interstitialPane.find(".buy_icon_copy").text();
      } else if (this.voteState === 'sale_on') {
        this.buttonBuy.html("Buy!");
        this.interstitialPane.find(".buy_icon_copy").text("Save $" + (this.firesale.getSavings().toFixed(2)));
        this.promotion.votes_count = this.promotion.target_votes;
      }
      this.interstitialPane.find("#screen").css('backgroundImage', "url(" + this.promotion.wide_banner_url + ")");
      this.interstitialPane.find(".announcement").html(this.firesaleAnnouncement(this.voteState, this.promotion));
      this.interstitialPane.find(".price").text("$" + this.promotion.original_price);
      this.interstitialPane.find(".price_target").text("$" + this.promotion.discount_price);
      OF.getTemperature(this.promotion.target_votes, this.promotion.votes_count, true);
      this.buttonBuy.touch(this.interstitialPaneBuyListener);
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/index/fire_sale_interstitial_" + this.voteState);
      return this.interstitialPane.find('.close').touch(this.interstitialPaneCloseListener);
    };
    return Interstitial;
  })();
  GameListPage = (function() {
    function GameListPage(platform) {
      this.platform = platform;
      this.promotion = new Models.Promotion(OF.page.params.promo_key);
      this.setupPageTitle();
      this.load();
    }
    GameListPage.prototype.setupPageTitle = function(title) {
      if (title == null) {
        title = OF.page.params.title;
      }
      if (title) {
        OF.page.title = title;
        return document.title = title;
      }
    };
    GameListPage.prototype.load = function() {
      this.promotion.limit(20);
      return this.promotion.load({
        cache: false,
        loader: '#games_list .loading',
        success: this.render
      });
    };
    GameListPage.prototype.render = function(data) {
      var gameListHtml;
      gameListHtml = $.renderCollection('game_list_cell', data.promoted_games);
      $('#games_list').append(gameListHtml);
      $('#games_list .game_cell').unhide();
      return $('#games_list .section_title').text(data.promotion.name);
    };
    return GameListPage;
  })();
  GamePage = (function() {
    function GamePage(platform) {
      this.platform = platform;
      this.setupPromotion();
      OF.page.userDidLogin = this.loginCallback;
      this.game = new Game(this.platform, 'game');
    }
    GamePage.prototype.setPageTitle = function(title) {
      return document.title = OF.page.title = title;
    };
    GamePage.prototype.setupFreeGame = function() {
      this.setPageTitle('Free Game');
      $('#countdown').unhide();
      return OF.countDown.element = $('.timer span');
    };
    GamePage.prototype.setupGoldGame = function() {
      this.setPageTitle('Gold Game');
      return $('#gold').unhide();
    };
    GamePage.prototype.setupPromotion = function() {
      switch (OF.page.params.promotion_type) {
        case 'fgotd':
          return this.setupFreeGame();
        case 'gold':
          return this.setupGoldGame();
      }
    };
    GamePage.prototype.loginCallback = function() {
      this.game.comments.reset();
      return OF.refresh();
    };
    return GamePage;
  })();
  GameBase = (function() {
    function GameBase() {}
    GameBase.openMarket = function(identifier) {
      var parameter;
      if (OF.platform === 'ios') {
        parameter = {
          url: identifier
        };
      }
      if (OF.platform === 'android') {
        parameter = {
          package_name: identifier
        };
      }
      if (parameter) {
        return OF.action('openMarket', parameter);
      } else {
        throw new Error("Open Market for platform " + OF.platform + " is not supported");
      }
    };
    GameBase.prototype.getUserId = function() {
      var _ref;
      return (_ref = OF.user) != null ? _ref.id : void 0;
    };
    GameBase.prototype.isGameFree = function(price) {
      var parsedPrice;
      parsedPrice = parseFloat(price);
      return parsedPrice === 0 || isNaN(parsedPrice);
    };
    GameBase.prototype.enableComment = function() {
      $('#post_form').unhide();
      return $('#add_comment').unhide().touch(function() {
        OF.GA.event(this.pageId, 'add_comment');
        OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/add_comment_button");
        return $(this).fadeOut(function() {
          return $('#comment_form').unhide();
        });
      });
    };
    GameBase.prototype.userDidntLogIn = function() {
      this.buyButton.unhide();
      $('#take_action_to_post').unhide();
      $('#take_action_to_post .button').text('Log in to Comment!').touch(function() {
        OF.GA.event(this.pageId, 'login_to_comment');
        OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/game/login_to_comment_button");
        return OF.action(PlatformSettings.showEnableView);
      });
      return this.getGameObject();
    };
    GameBase.prototype.enableVideo = function(description) {
      var _ref;
      if ((_ref = description.youtube) != null ? _ref.video_id : void 0) {
        return $('#video').unhide().touch(function() {
          var youtubeUrl;
          OF.GA.event('game', 'youtube');
          youtubeUrl = 'http://www.youtube.com/v/' + description.youtube.video_id;
          return OF.action('openMarket', {
            url: youtubeUrl
          });
        });
      }
    };
    GameBase.prototype.isGameInstalled = function() {
      if (this.getUserId()) {
        return OF.api("/xp/users/" + OF.user.id + "/games/" + OF.page.params.game_id + "/installed", {
          success: this.userHasThisGame,
          failure: this.userDoesntHaveThisGame
        });
      } else {
        return this.userDidntLogIn();
      }
    };
    return GameBase;
  })();
  Game = (function() {
    function Game(platform, pageId, needInstallGameToComment) {
      this.platform = platform;
      this.pageId = pageId;
      this.needInstallGameToComment = needInstallGameToComment != null ? needInstallGameToComment : false;
      this.buyGameListener = __bind(this.buyGameListener, this);;
      this.userDoesntHaveThisGame = __bind(this.userDoesntHaveThisGame, this);;
      this.userHasThisGame = __bind(this.userHasThisGame, this);;
      this.android = this.platform === 'android';
      this.ios = this.platform === 'ios';
      this.buyButton = $('.buy_button');
      this.isGameInstalled();
      this.comments = new Comments(this.pageId);
    }
    __extends(Game, GameBase);
    Game.prototype.userHasThisGame = function(data) {
      this.comments.enableComment();
      this.buyButton.text('Installed').addClass('installed').unhide();
      return this.getGameObject();
    };
    Game.prototype.userDoesntHaveThisGame = function() {
      this.buyButton.unhide();
      if (this.needInstallGameToComment) {
        $('#take_action_to_post').unhide();
        $('#take_action_to_post .button').text('Get Game to Comment!').touch(__bind(function() {
          OF.GA.event(this.pageId, 'get_game_to_comment');
          OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/game/get_game_to_comment_button");
          return this.buyButton.touch();
        }, this));
      } else {
        this.enableComment();
      }
      return this.getGameObject();
    };
    Game.prototype.getGameObject = function() {
      this.model = new Models.Game(OF.page.params.game_id);
      return this.model.load({
        loader: '#game .loading',
        success: __bind(function(data) {
          this.game = data.game;
          $('#game_info .developer').text(data.game.developer_name).unhide();
          $('#game_info .title').text(data.game.name).unhide();
          this.loadGameDescription();
          return $('#game .loading').hide();
        }, this)
      });
    };
    Game.prototype.renderGamePrice = function(price) {
      var isFree;
      isFree = this.isGameFree(price);
      $('.price span').text(!isFree ? "$" + price : 'Free');
      if (OF.page.params.promotion_type === 'fgotd') {
        if (isFree) {
          $('.price').hide();
        } else {
          $('.price span').addClass('strike_through');
        }
        $('.buy_button:not(.installed)').text('Free').unhide();
      } else {
        $('.buy_button:not(.installed)').text(isFree ? 'Free' : 'Buy').unhide();
      }
      if (isFree) {
        return $('.price').hide();
      } else {
        return $('.price span').removeClass('strike_through');
      }
    };
    Game.prototype.renderGameDescription = function(description) {
      var description_text;
      $('#game_info .game_info').unhide();
      $('#game_info .icon_image').css('background-image', "url(" + description.icon.url + ")");
      this.renderGamePrice(description.price);
      description_text = this.android ? description.description : description.description_extended;
      $('#text_description').html(description_text.replace(/\\n/g, '<br>')).unhide();
      return this.enableVideo(description);
    };
    Game.prototype.buyGameListener = function() {
      OF.GA.event('game_detail', 'buy_button');
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/game_detail-buy_button");
      return GameBase.openMarket(this.game.marketIdentifier());
    };
    Game.prototype.renderGameSlides = function(description) {
      var screenshotsPane, slider, swipeOptions;
      screenshotsPane = $('#screenshots');
      if (description.screenshots.length > 0) {
        slider = $('#slides');
        slider.html(tmpl('slides_tmpl', {
          count: description.screenshots.length
        }));
        swipeOptions = {
          animationSteps: 24,
          marginInSlides: 12,
          changeOpacity: false,
          beforeSwitch: function() {
            var scrollTop, sliderScrollTop, sliderScrollTopMinimal;
            if (OF.platform === 'ios') {
              sliderScrollTopMinimal = 80;
              sliderScrollTop = screenshotsPane.offset().top + 5;
              scrollTop = sliderScrollTop > sliderScrollTopMinimal ? sliderScrollTop : sliderScrollTopMinimal;
              window.scroll(0, scrollTop);
            }
            if (OF.platform === 'android') {
              return window.scroll(0, 0);
            }
          }
        };
        if (OF.device.ios3) {
          swipeOptions.animationSteps = 8;
        }
        slider.gSwipe(swipeOptions);
        return $.each(description.screenshots, function(index) {
          var cacheImage;
          cacheImage = new Image();
          $(cacheImage).load(function() {
            var slide;
            slide = $(".slide:eq(" + index + ")");
            slide.find('.img').css('background-image', "url(" + this.src + ")");
            if (this.width > this.height) {
              return slide.addClass('landscape_to_portrait').css('background', 'none');
            }
          });
          return cacheImage.src = this.url;
        });
      } else {
        return screenshotsPane.hide();
      }
    };
    Game.prototype.loadGameDescription = function() {
      return this.model.loadDescription({
        loader: '.loading',
        success: __bind(function(data) {
          var description, game;
          game = new Models.ClientApplication(data);
          $('.section').touch($.noop);
          description = game.description;
          this.renderGameDescription(description);
          $('.buy_button:not(.installed)').touch(this.buyGameListener);
          return this.renderGameSlides(description);
        }, this)
      });
    };
    return Game;
  })();
  Comments = (function() {
    Comments.maxCommentCharacters = 200;
    function Comments(pageId) {
      this.pageId = pageId;
      this.checkBeforeSubmit = __bind(this.checkBeforeSubmit, this);;
      this.loadMorePages = __bind(this.loadMorePages, this);;
      this.reset();
      $('.comment_cell').touch(this.openUserProfileListener);
      $('#load_more').touch(this.loadMorePages);
      this.commentForm = $('#post_form');
      this.commentForm.submit(this.checkBeforeSubmit);
      $('#post_form #submit').touch(__bind(function() {
        return this.commentForm.submit();
      }, this));
      this.limitCommentCharacters();
      $.defer(__bind(function() {
        return this.loadMore();
      }, this));
    }
    Comments.prototype.reset = function() {
      this.page = 0;
      return $('#comments .comment_cell').remove();
    };
    Comments.prototype.currentPromotedGame = function() {
      return new Models.PromotedGame(OF.page.params.promoted_game_id);
    };
    Comments.prototype.loadMore = function(clearAll) {
      var promotedGame;
      if (clearAll) {
        this.reset();
      }
      this.page++;
      promotedGame = this.currentPromotedGame();
      promotedGame.loadComments(this.page, {
        loader: '#comments .loading',
        failure: $.noop,
        success: function(data) {
          var cells, commentsLeft, commentsPane, loadMorePane;
          commentsPane = $('#comments');
          commentsPane.append($.renderCollection('comment_cell', data.posts));
          loadMorePane = $('#load_more');
          commentsPane.append($('#comments .loading')).append(loadMorePane);
          cells = $('.comment_cell');
          if (data.post_count > cells.length) {
            cells.removeClass('last');
            commentsLeft = data.post_count - cells.length;
            loadMorePane.find('p').text("Load " + commentsLeft + " More");
            return loadMorePane.unhide();
          } else {
            return cells.last().addClass('last');
          }
        }
      });
      return $.defer(function() {
        return $('#load_more').hide();
      });
    };
    Comments.prototype.loadMorePages = function() {
      OF.GA.event(this.pageId, 'load_more_comments');
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/load_more_comments");
      return this.loadMore();
    };
    Comments.prototype.openUserProfileListener = function() {
      var user_id, _ref;
      if ((_ref = OF.user) != null ? _ref.id : void 0) {
        user_id = $(this).data().userid;
        OF.GA.event(this.pageId, 'comment_touched');
        return OF.action('dashboardUser', {
          user_id: user_id
        });
      } else {
        return OF.action(PlatformSettings.showEnableView, {
          message: "Join the OpenFeint Community!",
          button: "Sign me up!"
        });
      }
    };
    Comments.prototype.checkBeforeSubmit = function() {
      var commentContent;
      OF.GA.event(this.pageId, 'post_comment');
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/post_comment_button");
      commentContent = $('#comment_body').blur().val();
      if ($.trim(commentContent).length === 0) {
        OF.alert('No comment to post!', 'Enter text in the comment box to post a comment.');
      } else {
        if (!this.commentForm.isLoading()) {
          this.commentForm.isLoading(true);
          this.currentPromotedGame().comments.create(commentContent, {
            loader: '#post_form .button',
            success: __bind(function() {
              this.commentForm.isLoading(false);
              this.loadMore(true);
              return this.resetCommentForm();
            }, this),
            failure: __bind(function() {
              this.commentForm.isLoading(false);
              $('#add_comment').hide();
              $('#submit').text('Post Comment');
              this.loadMore(true);
              return OF.alert('Whoops... something went wrong', 'We met some technical issues when submitting your comment, please try again later.');
            }, this)
          });
        }
      }
      return false;
    };
    Comments.prototype.resetCommentForm = function() {
      $('#comment_body').val('');
      $('#submit').text('Post Comment');
      $('#add_comment, #submit').unhide();
      return $('#comment_form').fadeOut();
    };
    Comments.prototype.enableComment = function() {
      $('#post_form').unhide();
      return $('#add_comment').unhide().touch(function() {
        OF.GA.event(this.pageId, 'add_comment');
        OF.GA.page("/webui/game_channel/" + this.pageId + "/add_comment_button");
        return $(this).fadeOut(function() {
          return $('#comment_form').unhide();
        });
      });
    };
    Comments.prototype.limitCommentCharacters = function() {
      var max;
      max = this.constructor.maxCommentCharacters;
      return $('#comment_body').keyup(function() {
        var field;
        field = $(this);
        if (field.val().length > max) {
          return field.val(field.val().substring(0, max));
        }
      });
    };
    return Comments;
  })();
  PreviousFiresale = (function() {
    function PreviousFiresale(currentFiresale) {
      var _ref;
      this.currentFiresale = currentFiresale;
      this.pageId = 'fire_sale';
      _ref = [null, null, null], this.nextFireSaleDay = _ref[0], this.nextFireSaleMonth = _ref[1], this.nextFireSaleDayOfMonth = _ref[2];
      this.firesale_promotion = new Models.Promotion('iphone_fire_sale');
    }
    PreviousFiresale.prototype.render = function(data) {
      var nfs, openPreviousFiresaleListener, prev_promo, promo;
      prev_promo = data.promoted_games[0].promoted_game;
      promo = data.promotion;
      $('#previous_firesale_info .developer').text(prev_promo.game.developer_name);
      $('#previous_firesale_info .title').text(prev_promo.game.name);
      $('#previous_firesale_info, #previous_firesale_info .developer').unhide();
      $('#game_info').hide();
      if (promo.next_fire_sale_at) {
        $('#sale_over_header').unhide();
        nfs = new Date(OF.gcTime.cleanTime(promo.next_fire_sale_at));
        this.nextFireSaleDayOfMonth = nfs.getDate() ? nfs.getDate() : '?';
        this.nextFireSaleMonth = nfs.abbrMonths[nfs.getMonth()] ? nfs.abbrMonths[nfs.getMonth()] : '?';
        this.nextFireSaleDay = nfs.getDay() ? nfs.DaysOfTheWeek[nfs.getDay()] : '?';
        this.currentFiresale.setHeader(" - Starts " + this.nextFireSaleDay + "!");
        $('.firesale_page .calendar .month').text(this.nextFireSaleMonth);
        $('.firesale_page .calendar .day').text(this.nextFireSaleDayOfMonth);
        $('#sale_over_header .title').text("The next Fire Sale begins this " + this.nextFireSaleDay + ". Which great game will go on sale next?");
      } else {
        $('#sale_over_header').hide();
      }
      openPreviousFiresaleListener = function() {
        return OF.push("" + GAME_CHANNEL_FLOW + "/game", {
          title: 'Previous Fire Sale',
          params: {
            game_id: prev_promo.game.id,
            promoted_game_id: prev_promo.id,
            price: prev_promo.game.price,
            promotion_type: 'firesale',
            discount_price: prev_promo.game.discount_price
          }
        });
      };
      OF.GA.event(this.pageId, 'previous_game');
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/previous_game_button");
      return $('#previous_firesale_info .cell').touch(openPreviousFiresaleListener);
    };
    PreviousFiresale.prototype.showFireSale = function() {
      return this.firesale_promotion.load('previous', {
        loader: '#game_info .loading',
        failure: function() {
          $('#game_info').fadeOut();
          OF.goBack();
          return OF.alert('Whoops... something went wrong', 'Make sure you are connected to the Internet.');
        },
        success: __bind(function(data) {
          return this.render(data);
        }, this)
      });
    };
    return PreviousFiresale;
  })();
  FiresalePage = (function() {
    function FiresalePage(platform, pageId) {
      this.platform = platform;
      this.pageId = pageId != null ? pageId : 'fire_sale';
      this.postVote = __bind(this.postVote, this);;
      this.twitterSHaringListener = __bind(this.twitterSHaringListener, this);;
      this.facebookSharingListener = __bind(this.facebookSharingListener, this);;
      this.userDoesntHaveThisGame = __bind(this.userDoesntHaveThisGame, this);;
      this.userHasThisGame = __bind(this.userHasThisGame, this);;
      this.buyButton = $('.buy_button');
      this.appInstalled = false;
      this.isGameInstalled();
      $('#game').addClass('firesale_page');
      this.renderGamePrice(OF.page.params.price);
      this.previousFiresale = new PreviousFiresale(this);
      this.comments = new Comments(this.pageId);
      this.firesale_promotion = new Models.Promotion('iphone_fire_sale');
      OF.page.userDidLogin = __bind(function() {
        if (this.getUserId()) {
          this.comments.reset();
          return OF.refresh();
        }
      }, this);
      this.load(false);
      this.userCanComment();
    }
    __extends(FiresalePage, GameBase);
    FiresalePage.prototype.userCanComment = function() {
      if (this.getUserId()) {
        return this.comments.enableComment();
      } else {
        return this.userDidntLogIn();
      }
    };
    FiresalePage.prototype.userDidntLogIn = function() {
      $('#take_action_to_post').unhide();
      return $('#take_action_to_post .button').text('Log in to Comment!').touch(function() {
        OF.GA.event(this.pageId, 'login_to_comment');
        OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/game/login_to_comment_button");
        return OF.action(PlatformSettings.showEnableView);
      });
    };
    FiresalePage.prototype.userHasThisGame = function() {
      $('.buy_button').unhide();
      return this.appInstalled = true;
    };
    FiresalePage.prototype.userDoesntHaveThisGame = function() {
      $('.buy_button').unhide();
      this.appInstalled = false;
      return this.getGameObject();
    };
    FiresalePage.prototype.getGameObject = function() {};
    FiresalePage.prototype.renderGamePrice = function(price) {
      if (this.isGameFree(price)) {
        return $('.price span').text("" + (parseFloat(price)));
      } else {
        return $('.price').hide();
      }
    };
    FiresalePage.prototype.load = function(reload) {
      var useCache;
      if (reload == null) {
        reload = false;
      }
      useCache = reload ? false : true;
      return this.firesale_promotion.load('current', {
        useCache: useCache,
        loader: '#game_info .loading',
        failure: function() {
          $('#game_info').fadeOut();
          OF.goBack();
          return OF.alert('Whoops... something went wrong', 'Make sure you are connected to the Internet.');
        },
        success: __bind(function(data) {
          this.render(data);
          return $('.firesale_page .loading').hide();
        }, this)
      });
    };
    FiresalePage.prototype.renderGameInfo = function(game) {
      $('#game_info .developer').text(game.developer_name).unhide();
      return $('#game_info .title').text(game.name).unhide();
    };
    FiresalePage.prototype.renderGameDescription = function(description) {
      var description_content;
      $('.icon_image').css('background-image', "url(" + description.icon.url + ")");
      description_content = description.description_extended.replace(/\\n/g, '<br>');
      $('#game_info #text_description').html(description_content).unhide();
      Game.prototype.renderGameSlides.call(this, description);
      return this.enableVideo(description);
    };
    FiresalePage.prototype.renderPromotionGamePrice = function(promotion) {
      $(".price").text("$" + promotion.original_price).unhide();
      return $(".price_target").text("$" + promotion.discount_price);
    };
    FiresalePage.prototype.displayPageElements = function() {
      document.title = OF.page.title = 'Fire Sale';
      $("#firesale_header,#game_info, #comments, #game_info .game_info_firesale, #game_info .game_info_firesale .cell_content, #game_info .game_info_firesale .icon_image, #firesale_gauge").unhide();
      return $('#previous_firesale_info').hide();
    };
    FiresalePage.prototype.displayHeader = function() {
      return $('#firesale_header').unhide();
    };
    FiresalePage.prototype.setVotingMessage = function(votingMessage) {
      return $("p.message").text(votingMessage);
    };
    FiresalePage.prototype.socialPostOptions = function(firesaleGame) {
      var name, savings;
      savings = firesaleGame.original_price - firesaleGame.discount_price;
      savings = savings.toFixed(2);
      name = firesaleGame.game.name;
      if (name.length > 15) {
        name = name.substring(0, 15) + '...';
      }
      if (firesaleGame.state === 'voting_on') {
        return {
          prompt: "I just voted to make " + name + " drop its price in Game Channel! Vote and we can save $" + savings + "!",
          message: '',
          url: firesaleGame.short_url
        };
      } else {
        return {
          prompt: "I found this great deal on " + name + " for $" + firesaleGame.discount_price + " normally for $" + firesaleGame.original_price + ".",
          message: 'Get it on Game Channel.',
          url: firesaleGame.short_url
        };
      }
    };
    FiresalePage.prototype.facebookSharingListener = function() {
      var options;
      options = this.socialPostOptions(this.firesaleGame);
      options.network = 'facebook';
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/sharing/facebook");
      return OF.action('socialPost', options);
    };
    FiresalePage.prototype.twitterSHaringListener = function() {
      var options;
      options = this.socialPostOptions(this.firesaleGame);
      options.network = 'twitter';
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/sharing/twitter");
      return OF.action('socialPost', options);
    };
    FiresalePage.prototype.loadSharing = function(firesaleGame) {
      this.firesaleGame = firesaleGame;
      if (OF.action.isSupported('socialPost')) {
        if (this.getUserId()) {
          $('#sharing').unhide();
          if (firesaleGame.state === 'sale_on') {
            $('#sharing .cell p.message').html('Tell your friends about this sale!');
          } else {
            $('#sharing .cell p.message').html('Want the game to go on sale sooner?<br>Tell your friends about it!');
          }
          $('#facebook').touch(this.facebookSharingListener);
          return $('#twitter').touch(this.twitterSHaringListener);
        }
      }
    };
    FiresalePage.prototype.postVote = function(notify) {
      return OF.api.post('/xp/promotions/iphone_fire_sale/votes', {
        params: {
          notify_me: notify
        },
        success: __bind(function() {
          return this.load(true);
        }, this),
        failure: $.noop
      });
    };
    FiresalePage.prototype.notifyMe = function() {
      var doNotify, dontNotify;
      doNotify = __bind(function() {
        this.postVote(true);
        OF.GA.event(this.pageId, "" + this.pageId + "_reminder-" + this.currentFiresale.state, 'notify', 1);
        return OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/reminder-" + this.currentFiresale.state + "-true");
      }, this);
      dontNotify = __bind(function() {
        if ((!this.currentFiresale.user.has_voted) || this.currentFiresale.user.notify_me) {
          this.postVote(false);
          $('.buy_button').html('<span>Notify me when the price drops!</span>').removeClass('disabled');
          $('.buy_icon').addClass('clock_icon');
          OF.GA.event(this.pageId, "" + this.pageId + "_reminder-" + this.currentFiresale.state, 'notify', 0);
          return OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/reminder-" + this.currentFiresale.state + "-false");
        }
      }, this);
      return OF.confirm("Reminder?", "Would you like us to remind you when this game goes on sale?", "Yes", "No Thanks", doNotify, dontNotify);
    };
    FiresalePage.prototype.setHeader = function(title) {
      return $('#firesale_header .title em').text(title);
    };
    FiresalePage.prototype.render = function(data) {
      var app_desc, promo, promotion, savings, targetVotes, user;
      $('.section').touch($.noop);
      this.currentFiresale = data.promoted_games[0].promoted_game;
      promo = data.promotion;
      promotion = data.promoted_games[0].promoted_game;
      user = promotion.user;
      app_desc = promotion.game.description;
      OF.page.params.promoted_game_id = promotion.id;
      this.vote_state = promotion.state;
      OF.GA.event(this.pageId, "view_" + this.vote_state);
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/view_" + this.vote_state);
      $('#game').addClass(this.vote_state);
      this.renderPromotionGamePrice(promotion);
      this.renderGameInfo(promotion.game);
      this.renderGameDescription(app_desc);
      this.buttonAction = $.noop;
      switch (this.vote_state) {
        case "voting_on":
          this.displayPageElements();
          this.setVotingMessage("Get this game to " + (addCommas(promotion.target_votes)) + " votes and it will go on sale!");
          if (user.has_voted) {
            this.loadSharing(promotion);
            if (user.notify_me) {
              $('.buy_button').text('You Voted!').addClass('disabled').unhide();
              this.buttonAction = null;
            } else {
              $('.buy_button').html('<span>Notify me when the price drops!</span>').unhide();
              this.buttonAction = this.notifyMe;
            }
          } else {
            this.setHeader(" - Vote Now!");
            $('.buy_button').text('Vote!').unhide();
            this.buttonAction = this.notifyMe;
            $('.thermometer .mercury').text('');
          }
          break;
        case "sale_pending":
          this.displayPageElements();
          this.setHeader(" - Price Dropping Soon");
          this.setVotingMessage("" + (addCommas(promotion.target_votes)) + " players voted! The price is dropping soon!");
          $('p.pending_message').unhide();
          if (user.notify_me) {
            $('.buy_button').html('&nbsp;&nbsp;&nbsp;Reminder Set!').addClass('disabled').unhide();
            this.buttonAction = null;
          } else {
            $('.buy_button').html('<span>Notify me when the price drops!</span>');
            this.buttonAction = this.notifyMe;
          }
          promotion.votes_count = promotion.target_votes;
          break;
        case "sale_on":
          this.setHeader(" - On Now!");
          this.displayPageElements();
          this.setVotingMessage("" + (addCommas(promotion.target_votes)) + " players ignited this sale. Voting is now over - thanks for participating!");
          this.loadSharing(promotion);
          this.buttonAction = function() {
            OF.GA.event(this.pageId, 'buy_button');
            OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "-buy_button");
            return OF.page.timeout(500, function() {
              return GameBase.openMarket("" + OF.serverUrl + "client_applications/" + OF.page.params.game_id + "/buy_now?promotion=" + promo.id);
            });
          };
          $('.buy_button').unhide();
          if (this.appInstalled) {
            $('.buy_button').text('Installed').addClass('installed');
          } else {
            $('.buy_button').text('Buy!').removeClass('installed');
          }
          $('.price').addClass('strike_through');
          promotion.votes_count = promotion.target_votes;
          $(".price").text("$" + promotion.original_price);
          savings = promotion.original_price - promotion.discount_price;
          $(".sale_on .buy_icon_copy").html("Save $" + savings);
          break;
        case "sale_over":
        case "sale_timeout":
        case "scheduled":
          this.displayHeader();
          this.previousFiresale.showFireSale();
          this.buttonAction = null;
          break;
        case "target_votes_unmet":
          this.displayHeader();
          this.previousFiresale.showFireSale();
          targetVotes = promotion.target_votes;
          $('#previous_firesale_info em').text("This game didn't receive " + (addCommas(targetVotes)) + " votes - better luck next time! Stay tuned for the next sale!");
          this.buttonAction = null;
      }
      OF.getTemperature(promotion.target_votes, promotion.votes_count, true);
      return $('.buy_button:not(.disabled)').touch(__bind(function() {
        return this.buyGameListener();
      }, this));
    };
    FiresalePage.prototype.buyGameListener = function() {
      var _ref;
      OF.GA.event(this.pageId, "action_button-" + this.vote_state);
      OF.GA.page("/webui/" + GAME_CHANNEL_FLOW + "/" + this.pageId + "/action_button-" + this.vote_state);
      if ((_ref = OF.user) != null ? _ref.id : void 0) {
        return this.buttonAction();
      } else {
        OF.action(PlatformSettings.showEnableView, {
          message: 'Hold on! You need to log in to an OpenFeint account to do this.',
          button: 'Sign Me Up!'
        });
        return OF.page.userDidLogin.fromVoteButton = true;
      }
    };
    return FiresalePage;
  })();
  this.Firesale = Firesale;
  this.GameChannel = GameChannel;
  this.FreeGameOfTheDay = FreeGameOfTheDay;
  this.GamePage = GamePage;
  this.FiresalePage = FiresalePage;
  this.News = News;
  this.MoreGames = MoreGames;
  this.GameListPage = GameListPage;
  this.About = About;
}).call(this);
