package org.haxe.nme;

import android.app.Application;
import android.os.Handler;

import com.openfeint.api.OpenFeint;
import com.openfeint.api.OpenFeintDelegate;
import com.openfeint.api.OpenFeintSettings;

public class OpenFeintApplication extends Application {
	
	
    @Override
    public void onCreate() {
        super.onCreate();
        
        final OpenFeintApplication self = this;

        final Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
          @Override
          public void run() {
              OpenFeintSettings settings = new OpenFeintSettings("BubbleBlast", "kFIDSwHRFud1MwQ1Hd8q9Q", "gKQqSadeqXke3mBeyON26bCneWNHMAEO6RKOfncNLc", "426602");
              OpenFeint.initialize(self, settings, new OpenFeintDelegate() { }); 
          }
        }, 60000);
    }

}
