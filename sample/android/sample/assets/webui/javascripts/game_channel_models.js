// DO NOT EDIT
//   Generated from javascripts/game_channel_models.coffee
//
(function() {
  var CacheItem, ClientApplication, Comments, Game, MemoryCaching, ModelBase, Models, PromotedGame, Promotion, PromotionList, caching;
  var __hasProp = Object.prototype.hasOwnProperty, __slice = Array.prototype.slice, __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; }, __extends = function(child, parent) {
    for (var key in parent) { if (__hasProp.call(parent, key)) child[key] = parent[key]; }
    function ctor() { this.constructor = child; }
    ctor.prototype = parent.prototype;
    child.prototype = new ctor;
    child.__super__ = parent.prototype;
    return child;
  };
  Models = {
    PLATFORM: 'ios'
  };
  Models.setPlatform = function(platform) {
    return Models.PLATFORM = platform;
  };
  CacheItem = (function() {
    function CacheItem(url, params, object, maxAge, cacheTime) {
      this.url = url;
      this.params = params;
      this.object = object;
      this.maxAge = maxAge;
      this.cacheTime = cacheTime;
      this.id = this.constructor.getIdentifier(this.url, this.params);
    }
    CacheItem.prototype.isExpired = function(onTime) {
      return this.cacheTime + this.maxAge <= onTime;
    };
    CacheItem.getIdentifier = function(url, params) {
      return url + JSON.stringify(params);
    };
    CacheItem.prototype.destroy = function() {
      this.url = null;
      this.params = null;
      return this.object = null;
    };
    return CacheItem;
  })();
  MemoryCaching = (function() {
    MemoryCaching.maxAge = 30 * 60 * 1000;
    function MemoryCaching() {
      this.items = {};
    }
    MemoryCaching.prototype.has = function(identifier) {
      return this.items.hasOwnProperty(identifier);
    };
    MemoryCaching.prototype.setItem = function(url, params, data, maxAge, onTime) {
      var item;
      if (maxAge == null) {
        maxAge = this.constructor.maxAge;
      }
      if (onTime == null) {
        onTime = $.now();
      }
      item = new CacheItem(url, params, data, maxAge, onTime);
      if (this.has(item.id)) {
        this.items[item.id].destroy();
      }
      return this.items[item.id] = item;
    };
    MemoryCaching.prototype.getItem = function(url, params, onTime) {
      var id, item;
      if (onTime == null) {
        onTime = $.now();
      }
      id = CacheItem.getIdentifier(url, params);
      if (this.has(id)) {
        item = this.items[id];
        if (item.isExpired(onTime)) {
          this.removeItem(url, params);
          throw new Error("" + id + " is expired");
        }
        item.object.cacheHit = true;
        return item.object;
      } else {
        throw new Error("" + id + " is not found");
      }
    };
    MemoryCaching.prototype.removeItem = function(url, params) {
      var id, item;
      id = CacheItem.getIdentifier(url, params);
      if (this.items.hasOwnProperty(id)) {
        item = this.items[id];
        delete this.items[id];
        item.destroy();
        return item = null;
      }
    };
    MemoryCaching.prototype.clear = function() {
      var key, value, _ref;
      _ref = this.items;
      for (key in _ref) {
        if (!__hasProp.call(_ref, key)) continue;
        value = _ref[key];
        delete this.items[key];
        value.destroy();
      }
      return this.items = {};
    };
    return MemoryCaching;
  })();
  MemoryCaching.CacheItem = CacheItem;
  caching = new MemoryCaching();
  Models.clearCache = function() {
    return caching.clear();
  };
  ModelBase = (function() {
    function ModelBase() {}
    ModelBase.prototype.setParams = function(params) {
      this.params = params;
    };
    ModelBase.prototype.getParams = function() {
      var params;
      params = {
        platform: Models.PLATFORM
      };
      $.extend(params, this.params);
      return params;
    };
    ModelBase.prototype.prepareCallbacks = function(callbacks) {
      var defaultCallback, mergedCallback;
      defaultCallback = {
        success: $.noop,
        failure: $.noop,
        complete: $.noop
      };
      mergedCallback = $.extend(defaultCallback, callbacks);
      return mergedCallback;
    };
    ModelBase.prototype.useCache = function(options) {
      var useCache;
      useCache = true;
      if (options != null ? options.hasOwnProperty('useCache') : void 0) {
        useCache = options.useCache;
        delete options.useCache;
      }
      return useCache;
    };
    ModelBase.prototype.load = function() {
      var callbacks, options, parameters, path, response, success_callback, url, useCache;
      options = 1 <= arguments.length ? __slice.call(arguments, 0) : [];
      path = options[0], callbacks = options[1];
      if (typeof path !== 'string') {
        callbacks = path;
        path = '';
      }
      url = this.endPoint(path);
      parameters = this.getParams();
      useCache = this.useCache(callbacks);
      if (!useCache) {
        caching.removeItem(url, parameters);
      }
      callbacks = this.prepareCallbacks(callbacks);
      try {
        response = caching.getItem(url, parameters);
        callbacks.success(response, 200);
        return callbacks.complete(response, 200);
      } catch (error) {
        success_callback = callbacks.success;
        $.extend(callbacks, {
          params: parameters,
          success: __bind(function(data, status) {
            caching.setItem(url, this.getParams(), data);
            if (this.cascading) {
              this.cascading(data, useCache);
            }
            return success_callback(data, status);
          }, this)
        });
        return OF.api(url, callbacks);
      }
    };
    return ModelBase;
  })();
  Promotion = (function() {
    function Promotion(id, params) {
      this.id = id;
      this.params = params != null ? params : {};
    }
    __extends(Promotion, ModelBase);
    Promotion.prototype.endPoint = function(subpath) {
      var path;
      path = subpath ? "/" + subpath : "";
      return "/xp/promotions/" + this.id + "/games" + path;
    };
    Promotion.prototype.limit = function(limit) {
      return this.params.limit = limit;
    };
    Promotion.prototype.price = function(price) {
      return this.params.price = price;
    };
    Promotion.prototype.preload = function(callback) {
      return this.load({
        success: callback ? callback : $.noop
      });
    };
    Promotion.prototype.cascading = function(responseData, useCache) {
      var game, gameModel, promotedGame, _i, _len, _ref, _results;
      _ref = responseData.promoted_games;
      _results = [];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        promotedGame = _ref[_i];
        promotedGame = promotedGame.promoted_game;
        game = new Models.ClientApplication(promotedGame.game);
        promotedGame.game = game;
        gameModel = new Game(game.id);
        caching.setItem(gameModel.endPoint(), gameModel.getParams(), {
          game: game
        });
        _results.push(caching.setItem(gameModel.endPoint('descriptions'), gameModel.getParams(), {
          description: game.description
        }));
      }
      return _results;
    };
    return Promotion;
  })();
  Models.Promotion = Promotion;
  PromotionList = (function() {
    function PromotionList(id, params) {
      this.id = id;
      this.params = params != null ? params : {};
    }
    __extends(PromotionList, ModelBase);
    PromotionList.prototype.endPoint = function(subpath) {
      var path;
      path = subpath ? "/" + subpath : "";
      return "/xp/promotions/" + this.id;
    };
    return PromotionList;
  })();
  Models.PromotionList = PromotionList;
  PromotedGame = (function() {
    function PromotedGame(id) {
      this.id = id;
      this.params = {};
      this.comments = new Comments(this);
    }
    __extends(PromotedGame, ModelBase);
    PromotedGame.prototype.endPoint = function(resource) {
      resource = resource ? "/" + resource : "";
      return "/xp/promoted_games/" + this.id + resource;
    };
    PromotedGame.prototype.loadComments = function(pageNumber, callbacks) {
      return this.comments.page(pageNumber).load(callbacks);
    };
    return PromotedGame;
  })();
  Models.PromotedGame = PromotedGame;
  Comments = (function() {
    function Comments(host) {
      this.host = host;
      this.params = {
        page: 1
      };
    }
    __extends(Comments, ModelBase);
    Comments.prototype.endPoint = function() {
      return "" + (this.host.endPoint()) + "/comments";
    };
    Comments.prototype.page = function(pageNumber) {
      this.params.page = pageNumber;
      return this;
    };
    Comments.prototype.useCache = function(options) {
      return false;
    };
    Comments.prototype.create = function(content, callbacks) {
      callbacks = this.prepareCallbacks(callbacks);
      $.extend(callbacks, {
        params: {
          body: content
        }
      });
      return OF.api.post(this.endPoint(), callbacks);
    };
    return Comments;
  })();
  Models.Comments = Comments;
  Game = (function() {
    function Game(id) {
      this.id = id;
      this.params = {};
    }
    __extends(Game, ModelBase);
    Game.prototype.endPoint = function(resource) {
      resource = resource ? "/" + resource + "/" + Models.PLATFORM : "";
      return "/xp/games/" + this.id + resource;
    };
    Game.prototype.loadDescription = function(callbacks) {
      return this.load('descriptions', callbacks);
    };
    return Game;
  })();
  Models.Game = Game;
  ClientApplication = (function() {
    function ClientApplication(json_data) {
      if ('application_description' in json_data) {
        json_data.description = json_data.application_description;
      }
      $.extend(this, json_data);
    }
    ClientApplication.prototype.marketIdentifier = function() {
      var identifier;
      if (Models.PLATFORM === 'ios') {
        identifier = "" + OF.serverUrl + "client_applications/" + this.id + "/buy_now";
      } else {
        identifier = this.description.package_identifier;
      }
      return identifier;
    };
    return ClientApplication;
  })();
  Models.ClientApplication = ClientApplication;
  this.Models = Models;
  this.MemoryCaching = MemoryCaching;
}).call(this);
