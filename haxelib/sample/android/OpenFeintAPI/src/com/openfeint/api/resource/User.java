package com.openfeint.api.resource;

import java.util.List;

import android.graphics.Bitmap;
import android.net.Uri;

import com.openfeint.internal.APICallback;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.request.BitmapRequest;
import com.openfeint.internal.request.JSONRequest;
import com.openfeint.internal.request.OrderedArgList;
import com.openfeint.internal.resource.BooleanResourceProperty;
import com.openfeint.internal.resource.DoubleResourceProperty;
import com.openfeint.internal.resource.IntResourceProperty;
import com.openfeint.internal.resource.Resource;
import com.openfeint.internal.resource.ResourceClass;
import com.openfeint.internal.resource.StringResourceProperty;


/**
 * The resource class that represents a User in OpenFeint.
 * You use this class to get information about users, 
 * such as their profile picture and name, and make friend requests.
 */
public class User extends Resource {
	
	/**
	 * Create a User object with the given resource ID.  This won't automatically
	 * fill the other fields out - see User.load() if you want to consult other
	 * fields of the User.
	 * 
	 * @param resourceID The resource ID of the User.
	 */
	public User(String resourceID) { setResourceID(resourceID); }

	/**
	 * The User's name.
	 */
	public String name;
	/**
	 * User's unique ID.
	 */
	public String userID() { return resourceID(); }
	/**
	 * The URL of the User's profile picture.
	 */
	public String profilePictureUrl;
	public String profilePictureSource;
	public boolean usesFacebookProfilePicture;
	/**
	 * The resource ID of the last game the user played.
	 */
	public String lastPlayedGameId;
	/**
	 * The name of the last game the user played.
	 */
	public String lastPlayedGameName;
	public boolean followsLocalUser;
	public boolean followedByLocalUser;
	/**
	 * The User's gamer score (Feint Points). 
	 */
	public int gamerScore; // unsigned
	/**
	 * Whether the User was online or not when this resource was fetched.
	 */
	public boolean online;
	/**
	 * User's last reported latitude.
	 */
	public double latitude;
	/**
	 * User's last reported longitude.
	 */
	public double longitude;

	/**
	 * A callback class you can extend for calling User.load().
	 */
	public abstract static class LoadCB extends APICallback {
		/**
		 * when User.load() completes, this will be called to let you know
		 * that the fields in the User object on which load() was called
		 * are ready to be read.
		 */
		public abstract void onSuccess();
	}
	
	/**
	 * Call this method to fill out the fields of this User object.  If you've
	 * created a User with the (String resourceID) constructor and then call this
	 * method, all the remaining User fields will be filled out for the User
	 * represented by that resource ID.
	 * @param cb The callback object that will be notified when load() completes.
	 */
	public void load(final LoadCB cb) {
		JSONRequest req = new JSONRequest() {
			@Override public String method() { return "GET"; }
			@Override public String path() { return "/xp/users/" + User.this.resourceID(); }
			@Override public void onSuccess(Object responseBody) {
				// Use the Ancestor type method, because CurrentUser.load() needs to work as well.
				User.this.shallowCopyAncestorType((User)responseBody);
				
				if (cb != null) {					
					cb.onSuccess();
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				super.onFailure(exceptionMessage);
				if (cb != null) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}

	/**
	 * A callback class you can extend for calling User.findByName() or User.findByID().
	 */
	public abstract static class FindCB extends APICallback {
		/**
		 * When the find request completes, this method will be called if a User
		 * by the given name or ID is found.  If a User is not found, onFailure()
		 * will be called, so you probably want to override that as well.
		 */
		public abstract void onSuccess(User foundUser);
	}
	
	/**
	 * Call this method to find a User by a given name.  If found, cb
	 * will be called with the User.
	 * @param name The name of the User to find.
	 * @param cb The callback object that will be notified when load() completes.
	 */
	public static void findByName(final String name, final FindCB cb) {
		JSONRequest req = new JSONRequest() {
			@Override public String method() { return "GET"; }
			@Override public String path() { return "/xp/users/" + Uri.encode(name); }
			@Override public void onSuccess(Object responseBody) {
				if (cb != null) {					
					cb.onSuccess((User)responseBody);
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				super.onFailure(exceptionMessage);
				if (cb != null) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}
	
	
	/**
	 * Call this method to find a User with a given resourceID.  If found, cb
	 * will be called with the User.
	 * @param resourceID The resource ID of the user to find.
	 * @param cb The callback object that will be notified when load() completes.
	 */
	public static void findByID(final String resourceID, final FindCB cb) {
		JSONRequest req = new JSONRequest() {
			@Override public String method() { return "GET"; }
			@Override public String path() { return "/xp/users/" + resourceID; }
			@Override public void onSuccess(Object responseBody) {
				if (cb != null) {					
					cb.onSuccess((User)responseBody);
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				super.onFailure(exceptionMessage);
				if (cb != null) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}
	
	/**
	 * A callback class you can extend for calling User.getFriends().
	 */
	public abstract static class GetFriendsCB extends APICallback {
		/**
		 * when User.getFriends() completes, this callback will be called with the
		 * list of the User's friends.
		 */
		public abstract void onSuccess(List<User> friends);
	}
	
	/**
	 * Call this method to get the list of the User's friends.
	 * @param cb The callback object that will be notified when getFriends() completes.
	 */
	public void getFriends(final GetFriendsCB cb) {
		OrderedArgList args = new OrderedArgList();
		args.put("user_id", resourceID());
		JSONRequest req = new JSONRequest(args) {
			@Override public boolean wantsLogin() { return true; }
			@Override public String method() { return "GET"; }
			@Override public String path() { return "/xp/friends"; }
			@Override public void onSuccess(Object responseBody) {
				if (cb != null) {
					try {
						@SuppressWarnings("unchecked") List<User> friends= (List<User>)responseBody;
						cb.onSuccess(friends);
					} catch (Exception e) {
						onFailure(OpenFeintInternal.getRString(RR.string("of_unexpected_response_format")));
					}
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				super.onFailure(exceptionMessage);
				if (cb != null) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}
	
	/**
	 * A callback class you can extend for calling downloadProfilePicture().
	 */
	public abstract static class DownloadProfilePictureCB extends APICallback {
		/**
		 * When downloadProfilePicture() completes, this method will be called with
		 * a Bitmap of the User's profile picture.
		 * @param iconBitmap The Achievement icon in Bitmap format. 
		 */
		public abstract void onSuccess(final Bitmap iconBitmap);
	}
	/**
	 * Call this method to download the profile picture of the given User in
	 * android.graphics.Bitmap format.
	 * @param cb The callback object that will be given the Bitmap of the user's profile picture.
	 */
	public void downloadProfilePicture(final DownloadProfilePictureCB cb) {
        if (OpenFeintInternal.getInstance().parentalControlsEnabled()) {
            if (cb != null) {
                cb.onFailure(OpenFeintInternal.getRString(RR.string("of_operation_not_permitted_due_to_parental_controls")));
            }
            return;
        }
	    
		if (this.profilePictureUrl == null) {
			if (cb != null) {
				cb.onFailure(OpenFeintInternal.getRString(RR.string("of_profile_url_null")));
			}
			return;
		}
		
		BitmapRequest req = new BitmapRequest() {

			@Override public String url() { return User.this.profilePictureUrl; }
			@Override public String path() { return ""; }

			@Override public void onSuccess(Bitmap responseBody) {
				if (null != cb) {
					cb.onSuccess(responseBody);
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				if (null != cb) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}

	/**
	 * This constructor is for use by the parser only.
	 */
	public User() { }
	
	/**
	 * This method is used internally by OpenFeint.
	 */
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (User.class, "user") { public Resource factory () { return new User (); } };

		klass.mProperties.put("name", new StringResourceProperty() { public void set(Resource obj, String val) { ((User)obj).name = val; } public String get(Resource obj) { return ((User)obj).name; } });
		klass.mProperties.put("profile_picture_url", new StringResourceProperty() { public void set(Resource obj, String val) { ((User)obj).profilePictureUrl = val; } public String get(Resource obj) { return ((User)obj).profilePictureUrl; } });
		klass.mProperties.put("profile_picture_source", new StringResourceProperty() { public void set(Resource obj, String val) { ((User)obj).profilePictureSource = val; } public String get(Resource obj) { return ((User)obj).profilePictureSource; } });
		klass.mProperties.put("uses_facebook_profile_picture", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((User)obj).usesFacebookProfilePicture = val; } public boolean get(Resource obj) { return ((User)obj).usesFacebookProfilePicture; } });
		klass.mProperties.put("last_played_game_id", new StringResourceProperty() { public void set(Resource obj, String val) { ((User)obj).lastPlayedGameId = val; } public String get(Resource obj) { return ((User)obj).lastPlayedGameId; } });
		klass.mProperties.put("last_played_game_name", new StringResourceProperty() { public void set(Resource obj, String val) { ((User)obj).lastPlayedGameName = val; } public String get(Resource obj) { return ((User)obj).lastPlayedGameName; } });
		klass.mProperties.put("gamer_score", new IntResourceProperty() { public void set(Resource obj, int val) { ((User)obj).gamerScore = val; } public int get(Resource obj) { return ((User)obj).gamerScore; } });
		klass.mProperties.put("following_local_user", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((User)obj).followsLocalUser = val; } public boolean get(Resource obj) { return ((User)obj).followsLocalUser; } });
		klass.mProperties.put("followed_by_local_user", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((User)obj).followedByLocalUser = val; } public boolean get(Resource obj) { return ((User)obj).followedByLocalUser; } });
		klass.mProperties.put("online", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((User)obj).online = val; } public boolean get(Resource obj) { return ((User)obj).online; } });
		klass.mProperties.put("lat", new DoubleResourceProperty() { public void set(Resource obj, double val) { ((User)obj).latitude = val; } public double get(Resource obj) { return ((User)obj).latitude; } });
		klass.mProperties.put("lng", new DoubleResourceProperty() { public void set(Resource obj, double val) { ((User)obj).longitude = val; } public double get(Resource obj) { return ((User)obj).longitude; } });

		return klass;
	}
}