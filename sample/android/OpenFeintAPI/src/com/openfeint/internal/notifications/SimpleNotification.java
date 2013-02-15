package com.openfeint.internal.notifications;

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

//The basic notification, only displays a simple text field

public class SimpleNotification extends NotificationBase {
	protected SimpleNotification(String text, String imageName, Category cat, Type type, Map<String,Object> userData) {
		super(text, imageName, cat, type, userData);
	}

	@Override
	protected boolean createView() {
		
		LayoutInflater inflater = (LayoutInflater)OpenFeintInternal.getInstance().getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		displayView = inflater.inflate(RR.layout("of_simple_notification"), null);

		((TextView)displayView.findViewById(RR.id("of_text"))).setText(getText());
		
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
	
	public static void show(String text, Category c, Type t) {
		show(text, null, c, t);
	}
	
	public static void show(String text, String imageName, Category c, Type t) {
		SimpleNotification notification = new SimpleNotification(text, imageName, c, t, null);
		notification.checkDelegateAndView();
		
	}
}
