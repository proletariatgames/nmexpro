package com.openfeint.api.ui;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import android.content.Intent;
import android.content.res.Resources;
import android.view.Menu;
import android.view.MenuItem;

import com.openfeint.api.Notification;
import com.openfeint.api.OpenFeint;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.eventlog.EventLogDispatcher;
import com.openfeint.internal.notifications.TwoLineNotification;
import com.openfeint.internal.ui.Settings;
import com.openfeint.internal.ui.WebNav;

/**
 * The Dashboard is your interface for opening up the OpenFeint Dashboard.
 * Methods are provided to go to the root dashboard, as well as opening up
 * to view specific Leaderboards, or the Achievements list for the current
 * User.
 * 
 * @author Aurora Feint, Inc.
 */
public class Dashboard extends WebNav {
	
	boolean mRootIsHome = true;
	static private String openfrom;

    public static String getOpenfrom() {
        return openfrom;
    }

    public static void setOpenfrom(String openfrom) {
        Dashboard.openfrom = openfrom;
    }

    private static List<Dashboard> sOpenDashboards = new ArrayList<Dashboard>();

	/**
	 * Opens the dashboard to the root page.
	 */
	public static void open() {
		open(null, false);
	}

	public static void openFromSpotlight() {
	    open("user.json?spotlight=true", true);
	}
	/**
	 * Closes any open Dashboard.
	 */
	public static void close() {
		for (Dashboard d : sOpenDashboards) {
			d.finish();
		}
	}
	/**
	 * Opens the dashboard to the list of Leaderboards.
	 */
	public static void openLeaderboards() {
		open("leaderboards", false);
	}
	
	/**
	 * Opens the dashboard to a specific Leaderboard.
	 * @param leaderboardId The resource ID of the Leaderboard to view.  You can
	 * get this from the Developer Dashboard.
	 */
	public static void openLeaderboard(String leaderboardId) {
		open("leaderboard?leaderboard_id="+ leaderboardId, false);
	}
	
	/**
	 * Opens the dashboard to the Achievements list for your application.
	 */
	public static void openAchievements() {
		open("achievements", false);
	}
	
	/**
	 * Opens the dashboard to the Game Detail page for a given application.
	 * @param appId The ID of the application to view.  You can get this from
	 * the Developer Dashboard for that application.
	 */
	public static void openGameDetail(String appId) {
		open("game?game_id="+ appId, false);
	}
	
	/**
	 * This is used internally by OpenFeint.
	 */
	public static void openPath(String path) {
	    open(path, false);
	}
	
	/**
	 * Opens the dashboard to a particular screen.  This screen name might have
	 * a query string with additional data like a resource ID.
	 * @param screenName Screen path which may optionally include a query string
	 * the resulting page has access to.  The path is relative to the webui root.
	 */
	private static void open(String screenName, boolean spotlight) {
		OpenFeint.trySubmitOfflineData();
		
		OpenFeintInternal ofi = OpenFeintInternal.getInstance();
		
		if(!ofi.isFeintServerReachable()) {
			Resources r = OpenFeintInternal.getInstance().getContext().getResources();		
			TwoLineNotification.show(r.getString(RR.string("of_offline_notification")), 
												r.getString(RR.string("of_offline_notification_line2")),
												Notification.Category.Foreground, Notification.Type.NetworkOffline);
			return;
		}
		
        EventLogDispatcher.getInstance().postEvent(EventLogDispatcher.DASHBOARD_START, openfrom);
		Intent intent = new Intent(ofi.getContext(), Dashboard.class);
		if (screenName != null) intent.putExtra("screenName", screenName);
		ofi.submitIntent(intent, spotlight);
	}
	
	@Override
	/**
	 * If we are resuming but are logged out, close the dashboard. 
	 */
	public void onResume() {
        super.onResume();
        if (!sOpenDashboards.contains(this)) sOpenDashboards.add(this);
        if (OpenFeintInternal.getInstance().getCurrentUser() == null) finish();
	}
	
	@Override
	public void onDestroy() {
		super.onDestroy();
		sOpenDashboards.remove(this);
	
	}
	
	@Override
    public void onStop() {
        EventLogDispatcher.getInstance().postEvent(EventLogDispatcher.DASHBOARD_END, openfrom);
        super.onStop();
    }

	@Override
	/**
	 * Load the menu for this activity
	 */
	public boolean onCreateOptionsMenu(Menu menu) {
	    getMenuInflater().inflate(RR.menu("of_dashboard"), menu);
	    return true;
	}
	
	@Override
	/**
	 * If we are already on the home screen, don't show the home menu button
	 */
	public boolean onPrepareOptionsMenu (Menu menu) {
      menu.findItem(RR.id("home")).setVisible(!mRootIsHome || pageStackCount > 1);
		return true;
	}

	
	/**
	 * Tell the Dashboard JavaScript menu handler function that we just
	 * pressed something.
	 */
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		String menuButtonName = null;
		
    if (item.getItemId() == RR.id("home")) {
	    	menuButtonName = "home";
	    	mRootIsHome = true;
	    } else if (item.getItemId() == RR.id("settings")) {
	    	menuButtonName = "settings";
	    } else if (item.getItemId() == RR.id("exit_feint")) {
	    	menuButtonName = "exit";
	    }
	    
	    if (menuButtonName == null) return super.onOptionsItemSelected(item);
	    
	    executeJavascript(String.format("OF.menu('%s')", menuButtonName));
	    return true;
	}
	
	@Override
	/**
	 * Returns the initial page path to load.  Unless otherwise specified,
	 * it will load the current user's profile screen. 
	 */
	protected String initialContentPath() {
		String screenName = getIntent().getStringExtra("screenName");
		if (screenName != null) {
			mRootIsHome = false;
			return "dashboard/"+ screenName;
		} else {
			return "dashboard/user";
		}
	}
	
	@Override
	/**
	 * Add custom Dashboard actions
	 */
	protected ActionHandler createActionHandler(final WebNav webNav) {
		return new DashboardActionHandler(webNav);
    }
	
	private class DashboardActionHandler extends ActionHandler {
		public DashboardActionHandler(WebNav webNav) {
			super(webNav);
		}

		@Override
		protected void populateActionList(List<String> actionList) {
			super.populateActionList(actionList);
			actionList.add("openSettings");
		}
		
		@SuppressWarnings("unused")
		final public void openSettings(final Map<String,String> options) {
			Settings.open();
		}
		
	};
}
