package com.openfeint.internal.ui;

import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONObject;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.DialogInterface.OnCancelListener;
import android.content.DialogInterface.OnClickListener;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.view.KeyEvent;
import android.webkit.JsResult;
import android.webkit.WebChromeClient;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.openfeint.api.OpenFeintDelegate;
import com.openfeint.api.resource.Score;
import com.openfeint.api.resource.User;
import com.openfeint.api.ui.Dashboard;
import com.openfeint.internal.ImagePicker;
import com.openfeint.internal.JsonResourceParser;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.Util;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.request.IRawRequestDelegate;
import com.openfeint.internal.resource.ScoreBlobDelegate;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonFactory;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;

public class WebNav extends NestedWindow {

	// This is necessary because when we ditch out to the image picker,
	// the game might get evicted.
	@Override
    protected void onSaveInstanceState(Bundle outState) {
		OpenFeintInternal.saveInstanceState(outState);
	}

	// This is necessary because when we ditch out to the image picker,
	// the game might get evicted.
	@Override
    protected void onRestoreInstanceState(Bundle inState) {
		OpenFeintInternal.restoreInstanceState(inState);
	}

	protected static final String TAG = "WebUI";

	// sub-activity request codes go here.  make sure they don't collide in derived classes
	protected static final int REQUEST_CODE_NATIVE_BROWSER = 25565;

	private WebNavClient mWebViewClient;

	ActionHandler mActionHandler;
	public ActionHandler getActionHandler() { return mActionHandler; }

	Dialog mLaunchLoadingView;
	public Dialog getLaunchLoadingView() { return mLaunchLoadingView; }

    boolean mIsPageLoaded      = false;
	boolean mIsFrameworkLoaded = false;
	protected void setFrameworkLoaded(boolean value) { mIsFrameworkLoaded = value; }

	protected int pageStackCount;

	private boolean mShouldRefreshOnResume = true;

	protected ArrayList<String> mPreloadConsoleOutput = new ArrayList<String>();

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		OFLog.i(TAG, "--- WebUI Bootup ---");

		// Setup helper views
		pageStackCount = 0;

		// Setup WebView
		mWebView.getSettings().setJavaScriptEnabled(true);
		mWebView.getSettings().setPluginsEnabled(false);
		mWebView.setScrollBarStyle(WebView.SCROLLBARS_OUTSIDE_OVERLAY);
		mWebView.getSettings().setCacheMode(WebSettings.LOAD_NO_CACHE);

		// Setup native loader to show while we chew on stuff
		mLaunchLoadingView = new Dialog(this, RR.style("OFLoading"));
		mLaunchLoadingView.setOnCancelListener(new DialogInterface.OnCancelListener() {
			@Override
            public void onCancel (DialogInterface dialog) {
				WebNav.this.finish();
			}
		});
		mLaunchLoadingView.setCancelable(true);
		mLaunchLoadingView.setContentView(RR.layout("of_native_loader"));

		ProgressBar progress = (ProgressBar)mLaunchLoadingView.findViewById(RR.id("progress"));
		progress.setIndeterminate(true);
		progress.setIndeterminateDrawable(
			OpenFeintInternal.getInstance().getContext().getResources().getDrawable(
                                                                              RR.drawable("of_native_loader_progress"))
		);

		// Setup the WebViewClient and its ActionHandler
		mActionHandler = createActionHandler(this);
		mWebViewClient = createWebNavClient(mActionHandler);
		mWebView.setWebViewClient(mWebViewClient);
		mWebView.setWebChromeClient(new WebNavChromeClient());

		// Setup the JavaScript bridge
		mWebView.addJavascriptInterface(new Object() {
			@SuppressWarnings("unused")
			public void action(final String actionUri) {
				runOnUiThread(new Runnable() {
					@Override
					public void run() {
						getActionHandler().dispatch(Uri.parse(actionUri));
					}
				});
			}

			@SuppressWarnings("unused")
			public void frameworkLoaded() {
				WebNav.this.setFrameworkLoaded(true);
			}
		}, "NativeInterface");

		String path = initialContentPath();
		if (path.contains("?")) path = path.split("\\?")[0];
		if (!path.endsWith(".json")) path += ".json";
		WebViewCache.prioritize(path);
		load(false);
        mLaunchLoadingView.show(); // show progress view
	}

	protected String rootPage() {
		return "index.html";
	}

	protected void load(final boolean reload) {
	    mIsPageLoaded = false;
		WebViewCache.trackPath(rootPage(), new WebViewCacheCallback() {
			@Override
            public void pathLoaded(String itemPath) {
				if (mWebView != null) {
					String url = WebViewCache.getItemUri(itemPath);
					OFLog.i(TAG, "Loading URL: " + url);
					if (reload) {
						mWebView.reload();
					} else {
					    mWebView.loadUrl(url);
					}
				}
			}
            @Override
            public void failLoaded() {
                closeForDiskError();
            }
		});
	}

	private void closeForDiskError() {
        // THIS is a hack, since we may rewrite the web cache in next version
        // let's just hack it here.
	    this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                dismissDialog();
                String place = (Util.sdcardReady(WebNav.this))? OpenFeintInternal.getRString(RR.string("of_sdcard")):
                    OpenFeintInternal.getRString(RR.string("of_device"));
                new AlertDialog.Builder(WebNav.this)
                .setMessage(String.format(OpenFeintInternal.getRString(RR.string("of_nodisk")), place))
                .setPositiveButton(OpenFeintInternal.getRString(RR.string("of_no")), new OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        WebNav.this.finish();
                    }
                }).show();
            }
	    });
	}

	private static final String jsQuotedStringLiteral(String unquotedString) {
		if (unquotedString == null) return "''";
		return "'" + unquotedString.replace("\\", "\\\\").replace("'", "\\'") + "'";
	}

	/**
	 * Ensure the current user data is up to date in case it changed since this
	 * activity was last in the foreground.
	 */
	@Override
	public void onResume() {
		super.onResume();

		User localUser = OpenFeintInternal.getInstance().getCurrentUser();
		if (localUser != null && mIsFrameworkLoaded) {
			executeJavascript(
				String.format("if (OF.user) { OF.user.name = %s; OF.user.id = '%s'; }",
					jsQuotedStringLiteral(localUser.name),
					localUser.resourceID()));
			if (mShouldRefreshOnResume) {
				executeJavascript("if (OF.page) OF.refresh();");
			}
		}

		mShouldRefreshOnResume = true;
	}

	@Override
	public void onStop() {
		super.onStop();
		dismissDialog();
	}

	private void dismissDialog() {
		if (mLaunchLoadingView.isShowing())
		    mLaunchLoadingView.dismiss();
	}

	private void showDialog() {
		if (!mLaunchLoadingView.isShowing())
			mLaunchLoadingView.show();
	}

	/**
	 * Tell the WebNav about an orientation change
	 */
	@Override
	public void onConfigurationChanged(Configuration newConfig) {
		super.onConfigurationChanged(newConfig);
		String orientationString = null;
		if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
			orientationString = "landscape";
		} else {
			orientationString = "portrait";
		}

		executeJavascript(String.format("OF.setOrientation('%s');", orientationString));
	}

	/**
	 * After the page context is ready, load the first page of content.
	 */
	public void loadInitialContent() {
		String path = initialContentPath();
		if (path.contains("?"))      path = path.split("\\?")[0];
		if (!path.endsWith(".json")) path += ".json";

		WebViewCache.trackPath(path, new WebViewCacheCallback() {
			@Override
            public void pathLoaded(String itemPath) {
				executeJavascript("OF.navigateToUrl('" + initialContentPath() + "')");
			}

			@Override
            public void failLoaded() {
                closeForDiskError();
            }
		});
	}

	/**
	 * Create the native action handler for this flow. Override in subclasses to
	 * add new actions.
	 *
	 * @param webNav
	 *            the WebNav instance from which actions will be called.
	 * @return an ActionHandler instance on which to call native actions.
	 */
	protected ActionHandler createActionHandler(WebNav webNav) {
		return new ActionHandler(webNav);
	}
	
    /**
     * Create the WebNavClient for this flow. Override in subclasses to
     * add new web view behavior.
     *
     * @param actionHandler the existing ActionHandler.
     * @return a WebNavClient.
     */
	protected WebNavClient createWebNavClient(ActionHandler actionHandler) {
	    return new WebNavClient(actionHandler);
	}

	/**
	 * Override in subclasses to set what template path is loaded as the first
	 * content.
	 *
	 * @return the template path to load when this WebNav appears.
	 */
	protected String initialContentPath() {
		String contentPath = getIntent().getStringExtra("content_path");
		if (contentPath == null) {
			throw new RuntimeException("WebNav intent requires extra value 'content_path'");
		}
		return contentPath;
	}

	/**
	 * Intercept the back button. If there is history to go back to in the
	 * WebNav, then go back. Otherwise, finish the Activity and return.
	 */
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (keyCode == KeyEvent.KEYCODE_SEARCH) {
			executeJavascript(String.format("OF.menu('%s')", "search"));
			return true;
		}

		if (keyCode == KeyEvent.KEYCODE_BACK && pageStackCount > 1) {
			executeJavascript("OF.goBack()");
			return true;
		}

		return super.onKeyDown(keyCode, event);
	}

	/**
	 * Run some JavaScript in the WebView.
	 *
	 * @param js
	 *            the JavaScript to execute.
	 */
	public void executeJavascript(String js) {
		if (mWebView != null) {
			mWebView.loadUrl("javascript:" + js);
		}
	}

	/**
	 * Class to handle action URI navigation events as messages.
	 *
	 * @author Alex Wayne
	 */
	protected class WebNavClient extends WebViewClient {
		ActionHandler mActionHandler;

		/**
		 * Constructor
		 *
		 * @param anActionHandler
		 *            ActionHandler instance to use with the WebNav
		 */
		public WebNavClient(ActionHandler anActionHandler) {
			mActionHandler = anActionHandler;
		}

		/**
		 * Intercept URL loading and inspect for messages being passed to native
		 * code.
		 */
		@Override
		public boolean shouldOverrideUrlLoading(WebView view, String stringUrl) {
			Uri uri = Uri.parse(stringUrl);
			if (uri.getScheme().equals("http")
					|| uri.getScheme().equals("https")) {
				view.loadUrl(stringUrl);
			} else if (uri.getScheme().equals("openfeint")) {
				mActionHandler.dispatch(uri);
			} else {
				OFLog.e(TAG, "UNHANDLED PROTOCOL: " + uri.getScheme());
			}

			return true;
		}

		/**
		 * Make sure the loading is hidden on generic failures so interaction is
		 * not blocked
		 */
		@Override
		public void onReceivedError(WebView view, int errorCode,
				String description, String failingUrl) {
			mActionHandler.hideLoader(null);
		}

		@Override
		public void onPageFinished(WebView view, String url) {
		    if (mIsPageLoaded) return;
		    mIsPageLoaded = true;
		    
			if (mIsFrameworkLoaded) {
				loadInitialContent();
			} else {
			    attemptRecovery(view, url);
			}
		}
		
		protected void attemptRecovery(WebView view, String url) {
            // call onPageFinished after restore
            if (WebViewCache.recover()) {
                load(true);
                new AlertDialog.Builder(view.getContext())
                .setMessage(OpenFeintInternal.getRString(RR.string("of_crash_report_query")))
                .setNegativeButton(OpenFeintInternal.getRString(RR.string("of_no")), new OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        WebNav.this.finish();
                    }
                })
                .setPositiveButton(OpenFeintInternal.getRString(RR.string("of_yes")), new OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        WebNavClient.this.submitCrashReport();
                    }
                })
                .show();
            } else if (!WebViewCache.isDiskError()) {
                finish();
            }
		}

		protected void submitCrashReport() {
			Map<String, Object> crashReport = new HashMap<String, Object>();
			crashReport.put("console", new JSONArray(mPreloadConsoleOutput));

			JSONObject json = new JSONObject(crashReport);

			Map<String, Object> params = new HashMap<String, Object>();
			params.put("crash_report", json.toString());
			OpenFeintInternal.genericRequest("/webui/crash_report","POST", params, null, null);
		}

		/**
		 * Initial HTML/JS framework is loaded, so inject the client
		 * configuration. Then load the initial content
		 */
		public void loadInitialContent() {

			OpenFeintInternal of = OpenFeintInternal.getInstance();
			User localUser = of.getCurrentUser();
			int orientation = getResources().getConfiguration().orientation;

			HashMap<String, Object> user = new HashMap<String, Object>();
			if (localUser != null) {
				user.put("id", localUser.resourceID());
				user.put("name", localUser.name);
			}

			HashMap<String, Object> game = new HashMap<String, Object>();
			game.put("id", of.getAppID());
			game.put("name", of.getAppName());
			game.put("version", Integer.toString(of.getAppVersion()));

			Map<String, Object> device = OpenFeintInternal.getInstance().getDeviceParams();
			device.put("parentalControls", OpenFeintInternal.getInstance().parentalControlsEnabled());

			HashMap<String, Object> config = new HashMap<String, Object>();
			config.put("platform", 	"android");
			config.put("clientVersion", of.getOFVersion());
			config.put("hasNativeInterface", true);
			config.put("dpi", 		Util.getDpiName(WebNav.this));
			config.put("locale", 	getResources().getConfiguration().locale.toString());
			config.put("user", 		new JSONObject(user));
			config.put("game", 		new JSONObject(game));
			config.put("device", 	new JSONObject(device));
			config.put("actions", 	new JSONArray(getActionHandler().getActionList()));

			config.put("orientation",
					orientation == Configuration.ORIENTATION_LANDSCAPE ?
							"landscape" : "portrait");

			config.put("serverUrl", of.getServerUrl());

			JSONObject json = new JSONObject(config);

			// Run the environment variables setup JavaScript
			executeJavascript(String.format("OF.init.clientBoot(%s)", json.toString()));

			// Load the first content
			mActionHandler.mWebNav.loadInitialContent();
		}
	}

	/**
	 * Class to handle browser chrome tasks, like alerts
	 *
	 * @author Alex Wayne
	 */
	private class WebNavChromeClient extends WebChromeClient {
		@Override
        public boolean onJsAlert(WebView view, String url, String message, final JsResult result) {
			new AlertDialog.Builder(view.getContext())
					.setMessage(message)
				.setNegativeButton(OpenFeintInternal.getRString(RR.string("of_ok")), new OnClickListener() {
						@Override
                        public void onClick(DialogInterface dialog, int which) {
							result.cancel();
						}
					}).setOnCancelListener(new OnCancelListener() {
					  @Override
                    public void onCancel(DialogInterface dialog) {
					    result.cancel();
					  }
					}).show();
			return true;
		}

		@Override
        public boolean onJsConfirm(WebView view, String url, String message, final JsResult result) {
			new AlertDialog.Builder(view.getContext()).setMessage(message)
				.setPositiveButton(OpenFeintInternal.getRString(RR.string("of_ok")), new OnClickListener() {
						@Override
                        public void onClick(DialogInterface dialog, int which) {
							result.confirm();
						}
					}).setNegativeButton(OpenFeintInternal.getRString(RR.string("of_cancel")), new OnClickListener() {
						@Override
                        public void onClick(DialogInterface dialog, int which) {
							result.cancel();
						}
					}).setOnCancelListener(new OnCancelListener() {
					  @Override
                    public void onCancel(DialogInterface dialog) {
					    result.cancel();
					  }
					}).show();
			return true;
		}

		// If you build targetting Android SDK 1.6, you'll get a warning about this method
		// being unused.  Don't worry about it - it's used in later SDKs.
		// If we add a @SuppressWarnings("unused") here, we'll get a warning about an
		// unnecessarily suppressed warning when compiling against later Android SDKs -
		// that's the only reason why we didn't add it.
        public void onConsoleMessage(String message, int lineNumber, String sourceID)  {
		  if(!mIsFrameworkLoaded) {
		    String line = String.format("%s at %s:%d)", message, sourceID, lineNumber);
            mPreloadConsoleOutput.add(line);
		  }
		}
	}

	/**
	 * Class to handle native code actions from OF.sendAction("someAction", {options: ... })
	 *
	 * @author Alex Wayne
	 */
	protected class ActionHandler extends Object {

		WebNav mWebNav;

		List<String> mActionList;

		protected List<String> getActionList() {
			return mActionList;
		}

		/**
		 * Constructor
		 *
		 * @param webNav
		 *            WebNav calling the actions
		 */
		public ActionHandler(WebNav webNav) {
			mWebNav = webNav;

			mActionList = new ArrayList<String>();
			populateActionList(mActionList);
		}

		/**
		 * Add action names to the supported actionList. Override this to
		 * support additional actions. Every action you add MUST have a
		 * corresponding method named identically to handle that action.
		 *
		 * @param actionList
		 *            list of actions supported by the superclass. Add your
		 *            custom actions to this list.
		 */
		protected void populateActionList(List<String> actionList) {
			// Available in v1.0 forward
			actionList.add("log");
			actionList.add("apiRequest");
			actionList.add("contentLoaded");
			actionList.add("startLoading");
			actionList.add("back");
			actionList.add("showLoader");
			actionList.add("hideLoader");
			actionList.add("alert");
			actionList.add("dismiss");
			actionList.add("openMarket");
			actionList.add("isApplicationInstalled");
			actionList.add("openYoutubePlayer");
			actionList.add("profilePicture");

			// Available in v1.5 forward
			actionList.add("openBrowser");
			actionList.add("downloadBlob");

			// Available in v1.6 forward
			actionList.add("dashboard");
			
			// Available in v1.7.1 forward
			actionList.add("readSetting");
			actionList.add("writeSetting");

            // Available in 1.10 forward
            actionList.add("setParentalControlsEnabled");
		}

		/**
		 * Dispatch an action URI to an identically named method to handle it
		 *
		 * @param uri
		 *            the action URI to parse
		 */
		public void dispatch(Uri uri) {
			if (uri.getHost().equals("action")) {

				// Prepare action values
				Map<String, Object> options = parseQueryString(uri);
				String actionName = uri.getPath().replaceFirst("/", "");

				// Log the action unless this is an explicit log action
				if (!actionName.equals("log")) {
					Map<String,Object> escapedOptions = new HashMap<String,Object>(options);
					String params = (String)options.get("params");
					if (params != null && params.contains("password")) {
						escapedOptions.put("params", "---FILTERED---");
					}

 					OFLog.i(TAG, "ACTION: " + actionName + " " + escapedOptions.toString());
				}

				// Find the native method to call
				if (mActionList.contains(actionName)) {
					try {
						getClass().getMethod(actionName, Map.class).invoke( this, options);
					} catch (NoSuchMethodException e) {
						OFLog.e(TAG, "mActionList contains this method, but it is not implemented: "+ actionName);
					} catch (Exception e) {
					    OFLog.e(TAG, "Unhandled Exception: " + e.toString() +"   "+ e.getCause());
					}
				} else {
				    OFLog.e(TAG, "UNHANDLED ACTION: " + actionName);
				}

			} else {
			    OFLog.e(TAG, "UNHANDLED MESSAGE TYPE: " + uri.getHost());
			}
		}

		/**
		 * Utility method to turn a URI's query string string into a Map of keys
		 * and values
		 *
		 * @param uri
		 *            Action URI that contains the query string to parse
		 * @return a Map of Strings to Strings containing the parsed query
		 *         string.
		 */
		private Map<String, Object> parseQueryString(Uri uri) {
			return parseQueryString(uri.getEncodedQuery());
		}

		/**
		 * Utility method to turn query string string into a Map of keys and
		 * values
		 *
		 * @param queryString
		 *            The query string to parse
		 * @return a Map of Strings to Strings containing the parsed query
		 *         string.
		 */
		private Map<String, Object> parseQueryString(String queryString) {
			Map<String, Object> options = new HashMap<String, Object>();

			if (queryString != null) {
				String[] pairs = queryString.split("&");

				for (String stringPair : pairs) {
					String[] pair = stringPair.split("=");
					if (pair.length == 2) {
						options.put(pair[0], Uri.decode(pair[1]));
					} else {
						options.put(pair[0], null);
					}
				}
			}

			return options;
		}

		// ---
		// --- Action Methods ---
		// ---

		/**
		 * Make a signed and authenticate generic API request. Return the result
		 * into the WebNav with the status code and response body.
		 */
		public void apiRequest(Map<String, String> options) {
			final String requestID = options.get("request_id");
			Map<String, Object> params = parseQueryString(options.get("params"));
			Map<String, Object> httpParams = parseQueryString(options.get("httpParams"));

			OpenFeintInternal.genericRequest(
				options.get("path"),
				options.get("method"), params, httpParams, new IRawRequestDelegate() {
					@Override
                    public void onResponse(int statusCode, String responseBody) {
						String response = responseBody.trim();
						if (response.length() == 0) response = "{}";
						String js = String
								.format("OF.api.completeRequest(\"%s\", \"%d\", %s)",
										requestID, statusCode, response);
						mWebNav.executeJavascript(js);
					}
				}
			);
		}

		public void contentLoaded(Map<String, String> options) {
			if (!(options.get("keepLoader") != null && options.get("keepLoader").equals("true"))) {
				hideLoader(null);
				setTitle(options.get("title"));
			}

			mWebNav.fade(true);
			dismissDialog();
		}

		public void startLoading(Map<String, String> options) {
			mWebNav.fade(false);
			showLoader(null);

			WebViewCache.trackPath(options.get("path"),
					new WebViewCacheCallback() {
						@Override
                        public void pathLoaded(String itemPath) {
							executeJavascript("OF.navigateToUrlCallback()");
						}

						@Override
			            public void failLoaded() {
			                closeForDiskError();
			            }

						@Override
                        public void onTrackingNeeded() {
							showDialog();
						}
					});

			mWebNav.pageStackCount++;
		}

		public void back(Map<String, String> options) {
			mWebNav.fade(false);
			String root = options.get("root");
			if (root != null && !root.equals("false")) {
				mWebNav.pageStackCount = 1;
			}

			if (mWebNav.pageStackCount > 1) {
				mWebNav.pageStackCount--;
			}
		}

		public void showLoader(Map<String, String> options) {
			// mWebNav.getLoadingView().setVisibility(View.VISIBLE);
		}

		public void hideLoader(Map<String, String> options) {
			// mWebNav.getLoadingView().setVisibility(View.GONE);
		}

		public void log(Map<String, String> options) {
			String message = options.get("message");
			if (message != null)
				OFLog.i(TAG, "WEBLOG: " + options.get("message"));
		}

		public void alert(Map<String, String> options) {
			AlertDialog.Builder builder = new AlertDialog.Builder(mWebNav);
			builder.setTitle(options.get("title"));
			builder.setMessage(options.get("message"));
			builder.setNegativeButton(OpenFeintInternal.getRString(RR.string("of_ok")), null);
			builder.show();
		}

		public void dismiss(Map<String, String> options) {
			finish();
		}

		public void openMarket(final Map<String, String> options) {
			String packageName = options.get("package_name");
			Intent intent = new Intent(Intent.ACTION_VIEW,
					Uri.parse("market://details?id=" + packageName));
			// Intent intent = new Intent(Intent.ACTION_VIEW,
			// Uri.parse("http://market.android.com/details?id=" +
			// packageName));
			mWebNav.startActivity(intent);
		}

		public void isApplicationInstalled(final Map<String, String> options) {
			boolean installed = false;

			PackageManager manager = mWebNav.getPackageManager();
			List<ApplicationInfo> installedApps = manager
					.getInstalledApplications(0);
			String searchString = options.get("package_name");

			for (ApplicationInfo info : installedApps) {
				if (info.packageName.equals(searchString)) {
					installed = true;
				}
			}

			executeJavascript(String.format("%s(%s)",
					options.get("callback"),
					installed ? "true" : "false"));
		}

		public void openYoutubePlayer(Map<String, String> options) {
			final String videoID = options.get("video_id");
			final Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("vnd.youtube:" + videoID));

			 List<ResolveInfo> list = getPackageManager().queryIntentActivities(intent, PackageManager.MATCH_DEFAULT_ONLY);
			 if (list.size() == 0){
				 Toast.makeText(mWebNav, OpenFeintInternal.getRString(RR.string("of_no_video")), Toast.LENGTH_SHORT).show();
			 } else {
				 mWebNav.startActivity(intent);
			 }
		}

		final public void profilePicture(final Map<String,String> options) {
			ImagePicker.show(WebNav.this);
		}

		public void openBrowser(Map<String, String> options) {
			final Intent browserIntent = new Intent(mWebNav, NativeBrowser.class);
			mNativeBrowserParameters = new HashMap<String, String>();
			for(String arg : new String[] {"src", "callback", "on_cancel", "on_failure", "timeout"}) {
				final String val = options.get(arg);
				if (null != val) {
					// save it for the return...
					mNativeBrowserParameters.put(arg, val);
					// ... and send it to the browser.
					browserIntent.putExtra(NativeBrowser.INTENT_ARG_PREFIX + arg,  val);
				}
			}
			startActivityForResult(browserIntent, REQUEST_CODE_NATIVE_BROWSER);
		}

		public void downloadBlob(Map<String, String> options) {
			final String scoreJSON = options.get("score");
			final String onError = options.get("onError");
			final String onSuccess = options.get("onSuccess");

			try {
				JsonFactory jsonFactory = new JsonFactory(); // for thread safety, we make our own.
				JsonParser jp = jsonFactory.createJsonParser(new StringReader(scoreJSON));
				JsonResourceParser jrp = new JsonResourceParser(jp);
				Object scoreObject = jrp.parse();

				if (scoreObject != null && scoreObject instanceof Score) {
					final Score score = (Score)scoreObject;
					score.downloadBlob(new Score.DownloadBlobCB() {
						@Override public void onSuccess() {
							if (onSuccess != null) {
								executeJavascript(String.format("%s()", onSuccess));
							}
							ScoreBlobDelegate.notifyBlobDownloaded(score);
						}
						@Override public void onFailure(String exceptionMessage) {
							if (onError != null) {
								executeJavascript(String.format("%s(%s)", onError, exceptionMessage));
							}
						}
					});
				}
			} catch (Exception e) { // => JsonParseException, IOException
				if (onError != null) {
					executeJavascript(String.format("%s(%s)", onError, e.getLocalizedMessage()));
				}
			}

		}

		public void dashboard(Map<String, String> options) {
			Dashboard.openFromSpotlight();
		}

		private static final String WEBUI_PREFS = "OFWebUI";
		private static final String WEBUI_SETTING_PREFIX = "OFWebUISetting_";

		public void readSetting(final Map<String, String> options) {
			final String k = options.get("key");
			final String cb = options.get("callback");
			if (cb != null) {
				final String key = (k != null ? (WEBUI_SETTING_PREFIX + k) : null);
				final SharedPreferences prefs = OpenFeintInternal.getInstance().getContext().getSharedPreferences(WEBUI_PREFS, Context.MODE_PRIVATE);

				String val = prefs.getString(key, null);
				OFLog.i(TAG, String.format("readSetting(%s) => %s", k, val));
				executeJavascript(String.format("%s(%s)", cb, val != null ? val : "null"));
			}
		}

		public void writeSetting(final Map<String, String> options) {
			final String k = options.get("key");
			final String v = options.get("value");
			if (k != null && v != null) {
				final String key = WEBUI_SETTING_PREFIX + k;
				final SharedPreferences.Editor editor = OpenFeintInternal.getInstance().getContext().getSharedPreferences(WEBUI_PREFS, Context.MODE_PRIVATE).edit();
				editor.putString(key, v);
				editor.commit();
			}
		}

        public void setParentalControlsEnabled(final Map<String, String> options) {
            final String v = options.get("parentalControlsEnabled");
            OpenFeintInternal.getInstance().setParentalControlsEnabled("true".equals(v));
        }
	}
	private Map<String, String> mNativeBrowserParameters = null;

    @Override protected void onActivityResult(int requestCode, int resultCode, Intent data) {
    	super.onActivityResult(requestCode, resultCode, data);


    	if (mNativeBrowserParameters != null && requestCode == REQUEST_CODE_NATIVE_BROWSER) {
	    	if (resultCode != Activity.RESULT_CANCELED) {

	    		// Temporarily, we don't want to refresh.
	    		mShouldRefreshOnResume = false;

	    		if (data.getBooleanExtra(NativeBrowser.INTENT_ARG_PREFIX + "failed", false)) {
		    		final String cb = mNativeBrowserParameters.get("on_failure");
		    		if (cb != null) {
			    		final int code = data.getIntExtra(NativeBrowser.INTENT_ARG_PREFIX + "failure_code", 0);
			    		final String desc = data.getStringExtra(NativeBrowser.INTENT_ARG_PREFIX + "failure_desc");
		    			executeJavascript(String.format("%s(%d, %s)", cb, code, jsQuotedStringLiteral(desc)));
		    		}
	    		}
	    		else
	    		{
		    		final String cb = mNativeBrowserParameters.get("callback");
		    		if (cb != null) {
			    		final String rv = data.getStringExtra(NativeBrowser.INTENT_ARG_PREFIX + "result");
		    			executeJavascript(String.format("%s(%s)", cb, (rv != null ? rv : "")));
		    		}
	    		}
	    	} else {
	    		final String cb = mNativeBrowserParameters.get("on_cancel");
	    		if (cb != null) {
	    			executeJavascript(String.format("%s()", cb));
	    		}
	    	}
	    	mNativeBrowserParameters = null;
    	} else if (ImagePicker.isImagePickerActivityResult(requestCode)) {
    		Bitmap image = ImagePicker.onImagePickerActivityResult(WebNav.this, resultCode, 152, data);
    		if (image != null) {
    			String apiPath = "/xp/users/"+ OpenFeintInternal.getInstance().getCurrentUser().resourceID() +"/profile_picture";
    			ImagePicker.compressAndUpload(image, apiPath, new OpenFeintInternal.IUploadDelegate() {
					@Override public void fileUploadedTo(String url, boolean success) {
						if (success) {
							// OF might not be there, the function might not be there, etc
							// so we try/catch.
							WebNav.this.executeJavascript("try { OF.page.onProfilePictureChanged('" + url + "'); } catch (e) {}");
						}
					}
				});
    		}
    	} else {
    		// hopefully a subclass handled it
    	}
    }

	@Override
	public void onWindowFocusChanged(boolean hasFocus) {
		super.onWindowFocusChanged(hasFocus);
		OpenFeintDelegate d = OpenFeintInternal.getInstance().getDelegate();
		if (d != null) {
			if (hasFocus) {
				d.onDashboardAppear();
			} else {
				d.onDashboardDisappear();
			}
		}
	}

	@Override
	public void onDestroy() {
		mWebView.destroy();
		mWebView = null;
		super.onDestroy();
	}
}
