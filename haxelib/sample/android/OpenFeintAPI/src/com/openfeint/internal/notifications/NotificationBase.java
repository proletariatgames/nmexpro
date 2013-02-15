package com.openfeint.internal.notifications;

import java.util.HashMap;
import java.util.Map;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.drawable.Drawable;
import android.view.Gravity;
import android.view.View;
import android.widget.Toast;

import com.openfeint.api.Notification;
import com.openfeint.internal.OpenFeintInternal;

abstract public class NotificationBase extends Notification {

	private String text;
	private Category category;
	private Type type;
	private Map<String,Object> userData;

	protected String imageName;

	View displayView;
	Toast toast;
	
	public String getText() { return text; }
	public Category getCategory() { return category; }
	public Type getType() { return type; }
	public Map<String,Object> getUserData() { return userData; }
	
	protected NotificationBase(String _text, String _imageName, Category _cat, Type _type, Map<String,Object> _userData) {
		text = _text;
		imageName = _imageName;
		category = _cat;
		type = _type;
		userData = _userData;
	}
		
	//override this to create the toast view layout
	//return TRUE if the view creation is completed
	//i you return FALSE, then you must call showToast when you are ready
	abstract protected boolean createView();
	
	protected String clippedText(Paint paint, String text, int length) {
		String outText = text;
		int endLength = paint.breakText(text, true, length, null);
		if(endLength < outText.length()) {
			outText = outText.substring(0, endLength-1) + "...";
		}
		return outText;
	}
	
	protected void showToast() {
		OpenFeintInternal.getInstance().runOnUiThread(new Runnable() {
			public void run() {
				Context appContext = OpenFeintInternal.getInstance().getContext();
				toast = new Toast(appContext);
				toast.setGravity(Gravity.BOTTOM, 0, 0);
				toast.setDuration(Toast.LENGTH_LONG);
				toast.setView(displayView);
				toast.show();
			}			
		});
	}
		
	abstract protected void drawView(Canvas canvas);
	
	static Map<String, Drawable> drawableCache = new HashMap<String, Drawable>();
	static Drawable getResourceDrawable(String name) {
		if(!drawableCache.containsKey(name)) {
			final OpenFeintInternal ofi = OpenFeintInternal.getInstance();
			int bitmapHandle = ofi.getResource(name);
			if(bitmapHandle == 0) {
				drawableCache.put(name, null);				
			}
			else {
				Resources r = ofi.getContext().getResources();		
				drawableCache.put(name, r.getDrawable(bitmapHandle));
			}
		}
		return drawableCache.get(name);
	}
	
	protected void checkDelegateAndView() {
		if(getDelegate().canShowNotification(this)) {
			getDelegate().notificationWillShow(this);
			if(createView()) showToast();
		}
		else {
			//the delegate does the work instead
			getDelegate().displayNotification(this);
		}
	}
}
