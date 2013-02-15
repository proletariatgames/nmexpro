package com.openfeint.api;

import android.content.Context;

import com.openfeint.api.resource.CurrentUser;
import com.openfeint.api.resource.User;

/**
 * Callback class that you provide to OpenFeint.initialize() to
 * get notified of OpenFeint-related events.  By default, this class
 * just ignores all events, but you can use this to enable or disable
 * OpenFeint-related UI in your Activities if the user logs out, or
 * suspend game updates if the Dashboard opens, for example.
 * 
 * @author Aurora Feint, Inc.
 */
public abstract class OpenFeintDelegate {
	/**
	 * This method is called when a user logs in.  This happens when:
	 * <ul>
	 * <li> A user creates an account from the intro flow
	 * <li> A user logs in with an existing account from the intro flow 
	 * <li> A user switches to a different user account from the Dashboard 
	 * <li> OpenFeint.initialize() validates a previously-logged in user automatically
	 * </ul>
	 * @param user The CurrentUser that just logged in.
	 */
	public void userLoggedIn(CurrentUser user) {}
	
	/**
	 * This method is called when a user logs out.  This happens when
	 * <ul>
	 * <li> A user logs out from the Dashboard
	 * <li> A user switches to a different user account from the Dashboard
	 * <ul>
	 * @param user The User that just logged out.
	 */
	public void userLoggedOut(User user) {}

	/**
	 * This method is called when the dashboard opens.
	 */
	public void onDashboardAppear() {}

	/**
	 * This method is called when the dashboard closes.
	 */
	public void onDashboardDisappear() {}
	
	/**
	 * This method is called the first time OpenFeint is initialized, if it doesn't have any
	 * cached user data.  If you want to show your own Activity that asks the user whether or
	 * not they want to use OpenFeint, override this method to return true; and then show the
	 * user your approval flow.  The default implementation is to return false (thus causing
	 * OpenFeint to use its default approval flow).
	 * <p>Once your intro flow completes, it must call {@link OpenFeint#userApprovedFeint()} or
	 * {@link OpenFeint#userDeclinedFeint()}.
	 * @param ctx the Context for you to start your custom approval Intent from.
	 * @return true if you intend to show a custom approval screen, false otherwise.
	 */
	public boolean showCustomApprovalFlow(Context ctx) { return false; }
}
