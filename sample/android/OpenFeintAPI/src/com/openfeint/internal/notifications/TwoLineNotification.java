package com.openfeint.internal.notifications;

import java.util.HashMap;
import java.util.Map;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.request.BitmapRequest;

public class TwoLineNotification extends NotificationBase {
	protected TwoLineNotification(String text, String extra, String imageName, Category cat, Type type, Map<String,Object> userData) {
		super(text, imageName, cat, type, userData);
	}
	
	@Override
	protected boolean createView() {
		
		LayoutInflater inflater = (LayoutInflater)OpenFeintInternal.getInstance().getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		displayView = inflater.inflate(RR.layout("of_two_line_notification"), null);

		((TextView)displayView.findViewById(RR.id("of_text1"))).setText(getText());
		((TextView)displayView.findViewById(RR.id("of_text2"))).setText((String) getUserData().get("extra"));
		
		final ImageView icon = (ImageView)displayView.findViewById(RR.id("of_icon"));

		if(null != imageName) {
			Drawable image = getResourceDrawable(imageName);
			if(null == image) {
				//try to load from Feint server
				BitmapRequest req = new BitmapRequest() {
		
					@Override public String path() { return imageName; }
					
					@Override public void onSuccess(Bitmap responseBody) { 
						icon.setImageDrawable(new BitmapDrawable(responseBody));
						showToast();
					}
					
					@Override public void onFailure(String exceptionMessage) {
						OFLog.e("NotificationImage", "Failed to load image "+ imageName + ":" + exceptionMessage);
						icon.setVisibility(View.INVISIBLE);
						showToast();
					}
				};
		
				req.launch();
				
				return false;
			} else {
				icon.setImageDrawable(image);
			}
		} else {
			icon.setVisibility(View.INVISIBLE);
		}
		
		return true;
		//look for the image...
	}

	@Override
	protected void drawView(Canvas canvas) {
		displayView.draw(canvas);
	}
	
	public static void show(String text, String extra, Category c, Type t) {
		show(text, extra, null, c, t);
	}
	
	public static void show(String text, String extra, String imageName, Category c, Type t) {
		Map<String, Object> userData = new HashMap<String, Object>();
		userData.put("extra", extra);
		TwoLineNotification notification = new TwoLineNotification(text, extra, imageName, c, t, userData);
		notification.checkDelegateAndView();
		
	}


}
