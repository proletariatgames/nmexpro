package com.openfeint.internal.ui;

import java.util.List;
import java.util.Map;

import android.content.Intent;
import android.graphics.Bitmap;

import com.openfeint.api.OpenFeint;
import com.openfeint.internal.ImagePicker;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.Util5;
import com.openfeint.internal.request.IRawRequestDelegate;

public class IntroFlow extends WebNav {
	Bitmap cachedImage;
	
	@Override
	protected String initialContentPath() {
		String contentName = getIntent().getStringExtra("content_name");
		if (contentName != null) {
			return "intro/"+ contentName;
		} else {
			return "intro/index";
		}
	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent returnedIntent) {
		if (ImagePicker.isImagePickerActivityResult(requestCode)) {
			cachedImage = ImagePicker.onImagePickerActivityResult(this, resultCode, 152, returnedIntent);
		}
	}

	
	@Override
	protected ActionHandler createActionHandler(WebNav webNav) {
		return new IntroFlowActionHandler(webNav);
    }

	private class IntroFlowActionHandler extends ActionHandler {
		public IntroFlowActionHandler(WebNav webNav) {
			super(webNav);
		}

    		@Override
    		protected void populateActionList(List<String> actionList) {
    			super.populateActionList(actionList);
    			actionList.add("createUser");
    			actionList.add("loginUser");
    			actionList.add("cacheImage");
    			actionList.add("uploadImage");
    			actionList.add("clearImage");
    			actionList.add("decline");
    			actionList.add("getEmail");
    		}
    		
    		@SuppressWarnings("unused")
			final public void createUser(final Map<String,String> options) {
    			OpenFeintInternal.getInstance().createUser(
    				options.get("name"),
    				options.get("email"),
    				options.get("password"),
    				options.get("password_confirmation"),
    				new IRawRequestDelegate() {
    					@Override
    					public void onResponse(int status, String response) {
    						String js = String.format("%s('%d', %s)", options.get("callback"), status, response.trim());
    						mWebNav.executeJavascript(js);
    					}
    				}
    			);
    		}
    		
    		@SuppressWarnings("unused")
			final public void loginUser(final Map<String,String> options) {
    			OpenFeintInternal.getInstance().loginUser(
    				options.get("email"),
    				options.get("password"),
    				options.get("user_id"),
    				new IRawRequestDelegate() {
    					@Override
    					public void onResponse(int status, String response) {
    						String js = String.format("%s('%d', %s)", options.get("callback"), status, response.trim());
    						mWebNav.executeJavascript(js);
    					}
    				}
    			);
    		}
    		
    		@SuppressWarnings("unused")
    		final public void cacheImage(final Map<String,String> options) {
    			ImagePicker.show(IntroFlow.this);
    		}
    		
    		@SuppressWarnings("unused")
    		final public void uploadImage(final Map<String,String> options) {
    			//get the image that was stored and upload it
    			if(null != cachedImage) {
					String apiUrl = "/xp/users/"+ OpenFeintInternal.getInstance().getCurrentUser().resourceID() +"/profile_picture";
					ImagePicker.compressAndUpload(cachedImage, apiUrl, null);
    			}
    		}
    		
    		@SuppressWarnings("unused")
    		final public void clearImage(final Map<String,String> options) {
    			cachedImage = null;
    		}
    		
    		@SuppressWarnings("unused")
    		public void decline(final Map<String, String> options) {
    			OpenFeint.userDeclinedFeint();
    			finish();
    		}
    		
    		@SuppressWarnings("unused")
    		public void getEmail(final Map<String, String> options) {
	    		String account = Util5.getAccountNameEclair(IntroFlow.this);
	    		if (account != null) {
	    			executeJavascript(String.format("%s('%s');", options.get("callback"), account));
	    		}
    		}
    	};
    }
