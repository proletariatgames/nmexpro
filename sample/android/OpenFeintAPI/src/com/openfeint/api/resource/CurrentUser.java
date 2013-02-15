package com.openfeint.api.resource;

import com.openfeint.internal.APICallback;
import com.openfeint.internal.request.JSONRequest;
import com.openfeint.internal.request.OrderedArgList;
import com.openfeint.internal.resource.Resource;
import com.openfeint.internal.resource.ResourceClass;

/**
 * The resource class that represents the current logged-in User in OpenFeint.
 * 
 */
public class CurrentUser extends User {
	
	/**
	 * A callback class you can extend for calling User.befriend().
	 */
	public abstract static class BefriendCB extends APICallback {
		/**
		 * when User.befriend() completes, this will be notified.
		 */
		public abstract void onSuccess();
	}
	
	/**
	 * Call this method to have the local User send a friend request to
	 * this User.
	 * @param userToBefriend the User to send a friend request to.
	 * @param cb The callback object that will be notified when befriend() completes.
	 */
	public void befriend(User userToBefriend, final BefriendCB cb) {
		OrderedArgList args = new OrderedArgList();
		args.put("friend_id", userToBefriend.resourceID());
		JSONRequest req = new JSONRequest(args) {
			@Override public boolean wantsLogin() { return true; }
			@Override public String method() { return "POST"; }
			@Override public String path() { return "/xp/friend_requests"; }
			@Override public void onSuccess(Object responseBody) {
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
	 * This constructor is used internally by OpenFeint.
	 * To get access to the CurrentUser, call OpenFeint.getCurrentUser().
	 */
	public CurrentUser() {
		super();
	}
	
	/**
	 * This method is used internally by OpenFeint.
	 */
	public static ResourceClass getResourceClass() {
		return new ResourceClass (CurrentUser.class, "current_user") { public Resource factory () { return new CurrentUser (); } };
	}
}
