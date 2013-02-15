// DO NOT EDIT
//   Generated from javascripts/dashboard/models.coffee
//
(function() {
  var Game, ModelBase, User;
  var __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; }, __hasProp = Object.prototype.hasOwnProperty, __extends = function(child, parent) {
    for (var key in parent) { if (__hasProp.call(parent, key)) child[key] = parent[key]; }
    function ctor() { this.constructor = child; }
    ctor.prototype = parent.prototype;
    child.prototype = new ctor;
    child.__super__ = parent.prototype;
    return child;
  };
  ModelBase = (function() {
    ModelBase.find = function(id, callback) {
      var model;
      model = new this({
        id: id
      });
      model.fetch(callback);
      return model;
    };
    function ModelBase(modelData) {
      this.setData(modelData);
    }
    ModelBase.prototype.path = function() {
      throw 'This method must be overriden';
    };
    ModelBase.prototype.fetch = function(callback) {
      OF.api(this.path(), {
        success: __bind(function(data) {
          var key;
          this.loaded = true;
          key = U.keys(data)[0];
          this.setData(data[key]);
          return typeof callback === "function" ? callback(this) : void 0;
        }, this)
      });
      return this;
    };
    ModelBase.prototype.setData = function(modelData) {
      this.sourceObj = modelData;
      this.id = modelData.id;
      return this;
    };
    ModelBase.prototype.loaded = false;
    return ModelBase;
  })();
  Game = (function() {
    function Game() {
      Game.__super__.constructor.apply(this, arguments);
    }
    __extends(Game, ModelBase);
    Game.prototype.path = function() {
      return "/xp/games/" + this.id;
    };
    Game.prototype.setData = function(gameData) {
      Game.__super__.setData.apply(this, arguments);
      this.name = gameData.name;
      this.iconUrl = gameData["" + OF.platform + "_icon_url"];
      return this;
    };
    return Game;
  })();
  User = (function() {
    function User(userData) {
      if (userData == null) {
        userData = {};
      }
      User.__super__.constructor.apply(this, arguments);
      this.achievements = {};
    }
    __extends(User, ModelBase);
    User.prototype.path = function() {
      return "/xp/users/" + this.id;
    };
    User.prototype.setData = function(userData) {
      User.__super__.setData.apply(this, arguments);
      this.name = userData.name;
      if (userData.profile_picture_url) {
        this.profilePictureUrl = userPicUrl(userData.profile_picture_url);
      }
      this.gamesCount = userData.gamesCount;
      this.hasSetName = userData.has_set_name;
      this.friendshipCount = userData.friendship_count;
      this.gamerScore = userData.gamer_score;
      this.receivedFriendRequestsPendingCount = userData.received_friend_requests_pending_count;
      this.notViewedWallItemsCount = userData.not_viewed_wall_items_count;
      return this;
    };
    User.prototype.getAchievements = function(gameID, callback) {
      var achievements;
      achievements = this.achievements[gameID];
      if (achievements) {
        if (typeof callback === "function") {
          callback(achievements);
        }
        return achievements;
      } else {
        this.achievementsRequest || (this.achievementsRequest = OF.api("/xp/users/" + this.id + "/games/" + gameID + "/achievements", {
          success: __bind(function(data) {
            this.achievementsRequest = null;
            this.achievements[gameID] = data.achievements;
            return typeof callback === "function" ? callback(this.achievements[gameID]) : void 0;
          }, this)
        }));
      }
    };
    return User;
  })();
  window.ModelBase = ModelBase;
  window.Game = Game;
  window.User = User;
}).call(this);
