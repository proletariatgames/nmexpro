package com.openfeint.api;

import java.util.Map;

/**
 * All Notifications (popups that give the user information) in OpenFeint derive from this class.
 * You can control what Notifications get displayed, or display them in your own in-game way, by
 * deriving from Notification.Delegate and calling Notification.setDelegate() to set the default
 * handler.
 */
public abstract class Notification {

	/**
	 * This class provides the basic behavior for filtering and displaying notifications.
	 * If you want to change the behavior for your application, extend this class and then
	 * call Notification.setDelegate() with an instance of your derived class.
	 */
	public static class Delegate {
		/**
		 * OpenFeint calls this method to determine whether a specific Notification can be shown
		 * using the default OpenFeint overlays.
		 * <p>The default implementation will always return true (thus showing all Notifications in
		 * a default manner).  If you'd like to display Notifications using your own UI, or
		 * simply filter out some of them, override this method to return false in those instances.
		 * @param notification The Notification that's about to be shown or not.
		 * @return Whether the system should display the Notification.
		 */
		public boolean canShowNotification(Notification notification) { return true; }
		
		/**
		 * OpenFeint calls this method if canShowNotification() returned false.  By overriding
		 * this method, you can display Notifications using your own UI.  The default behavior
		 * is to not show the Notification to the user at all.
		 * @param notification the Notification to display.
		 */
		public void displayNotification(Notification notification) {}
		
		/**
		 * OpenFeint calls this method if canShowNotification() returned true, just before
		 * it actually displays the notification.  The default behavior is to do nothing.
		 * @param notification the Notification about to be displayed.
		 */
		public void notificationWillShow(Notification notification) {}
	}
	
	private static Delegate sDelegate = new Delegate();
	public static Delegate getDelegate() { return sDelegate; }

	/**
	 * setDelegate sets the default Notification.Delegate that OpenFeint will use to make
	 * decisions about what Notifications to show or hide.  Call this method with an
	 * instance that you've extended from Notification.Delegate to define your own
	 * Notification behavior for your application.
	 * @param delegate The Delegate to use going forward.
	 */
	public static void setDelegate(Delegate delegate) { sDelegate = delegate;}

	/**
	 * The Category enum describes what category a Notification belongs to.  By
	 * filtering on this field and Type, you can decide what Notifications you want
	 * to show or hide.
	 */
	public enum Category {
		Foreground,
		Login,
		Challenge,
		HighScore,
		Leaderboard,
		Achievement,
		SocialNotification,
		Presence,
		Multiplayer
	}
	
	/**
	 * The Type enum describes what type of Notification this is.  By
	 * filtering on this field and Category, you can decide what Notifications you want
	 * to show or hide.
	 */
	public enum Type {
		None,
		Submitting,
		Downloading,
		Error,
		Success,
		NewResources,
		UserPresenceOnLine,
		UserPresenceOffline,
		NewMessage,
		Multiplayer,
		NetworkOffline
	}

	/**
	 * Gets the text of this Notification.
	 * @return The text of this Notification.
	 */
	public abstract String getText();

	/**
	 * Gets the Category of this Notification.
	 * @return The Category of this Notification.
	 */
	public abstract Category getCategory();

	/**
	 * Gets the Category of this Notification.
	 * @return The Category of this Notification.
	 */
	public abstract Type getType();

	/**
	 * Gets the user data of this Notification.  This is usually internal to the
	 * specific Notification, but if you're implementing your own display tech, you
	 * may want to extract this data for your own use.
	 * @return The user data of this Notification.
	 */
	public abstract Map<String,Object> getUserData();

}
