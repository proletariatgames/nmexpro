package com.openfeint.internal.ui;

import java.util.List;
import java.util.Map;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.DialogInterface.OnClickListener;
import android.os.Bundle;
import android.widget.Toast;

import com.openfeint.api.OpenFeint;
import com.openfeint.internal.ImagePicker;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.request.IRawRequestDelegate;

public class Settings extends WebNav {
	private static final String SUBPAGE_KEY = "com.openfeint.internal.ui.Settings.subPage";
    String mOldUserId;
	
	public static void open() {
	    open(null);
	}
	
	public static void open(String subPage) {
		final OpenFeintInternal ofi = OpenFeintInternal.getInstance();
		final Context currentActivity = ofi.getContext();
		final Intent intent = new Intent(currentActivity, Settings.class);
		intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		if (subPage != null) {
		    intent.putExtra(SUBPAGE_KEY, subPage);
		}
		currentActivity.startActivity(intent);
	}
	
	@Override public void onResume() {
		if (mOldUserId == null) {
			mOldUserId = OpenFeint.getCurrentUser().resourceID(); 
		} else if (!mOldUserId.equals(OpenFeint.getCurrentUser().resourceID())) {
			new AlertDialog.Builder(this)
				.setTitle(OpenFeintInternal.getRString(RR.string("of_switched_accounts")))
				.setMessage(String.format(OpenFeintInternal.getRString(RR.string("of_now_logged_in_as_format")), OpenFeint.getCurrentUser().name))
				.setNegativeButton(OpenFeintInternal.getRString(RR.string("of_ok")), new OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						finish();
					}
				})
				.show();
		}
		
		super.onResume();
	}
	
	@Override
	protected String initialContentPath() {
	    final Intent intent = getIntent();
	    if (intent != null) {
            final Bundle extras = intent.getExtras();
            if (extras != null) {
                String subPage = extras.getString(SUBPAGE_KEY);
        	    if (subPage != null) {
        	        return "settings/" + subPage;
        	    }
            }
	    }
		return "settings/index";
	}
	
	@Override
	protected ActionHandler createActionHandler(WebNav webNav) {
		return new SettingsActionHandler(webNav);
    }
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) { 
	    super.onActivityResult(requestCode, resultCode, data); 

	    // Basically, super handles changing the image, but we want to send a message
	    if (requestCode == ImagePicker.IMAGE_PICKER_REQ_ID && data != null) {
	    	Toast.makeText(Settings.this, OpenFeintInternal.getRString(RR.string("of_profile_pic_changed")), Toast.LENGTH_SHORT).show();
	    }
	}

	private class SettingsActionHandler extends ActionHandler {
		public SettingsActionHandler(WebNav webNav) {
			super(webNav);
		}

    		@Override
    		protected void populateActionList(List<String> actionList) {
    			super.populateActionList(actionList);
    			actionList.add("logout");
    			actionList.add("introFlow");
    		}
    		
    		@Override
    		public void apiRequest(final Map<String,String> options) {
    			super.apiRequest(options);
    			OpenFeint.getCurrentUser().load(null);
    		}
    		
    		@SuppressWarnings("unused")
			final public void logout(final Map<String,String> options) {
    			OpenFeintInternal.getInstance().logoutUser(new IRawRequestDelegate() {
    				@Override
    				public void onResponse(int responseCode, String responseBody) {
    					finish();
    				}
    			});
    		}
    		
    		@SuppressWarnings("unused")
			final public void introFlow(final Map<String,String> options) {
    			startActivity(new Intent(Settings.this, IntroFlow.class).putExtra("content_name", "login?mode=switch"));
    		}
    		
    	};
    }
