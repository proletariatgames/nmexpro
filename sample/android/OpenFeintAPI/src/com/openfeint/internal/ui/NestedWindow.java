package com.openfeint.internal.ui;

import android.app.Activity;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.Display;
import android.view.View;
import android.view.Window;
import android.view.animation.AlphaAnimation;
import android.webkit.WebView;

import com.openfeint.internal.RR;
import com.openfeint.internal.Util;

public class NestedWindow extends Activity {

    protected WebView mWebView;
    protected View mLogoImage;
    private boolean mIsVisible = false;
//    private final String tag = "NestedWindow";
    public NestedWindow() {
        super();
    }
    
    protected int layoutResource() {
        return RR.layout("of_nested_window");
    }
    
    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Util.setOrientation(this);
        beforeSetContentView();
        setContentView(layoutResource());
        mWebView = (WebView) findViewById(RR.id("web_view"));
        mLogoImage = findViewById(RR.id("of_ll_logo_image"));
    }

    private boolean isBigScreen(){
        Display d = getWindowManager().getDefaultDisplay();
        int width= d.getWidth();
        int height= d.getHeight();

        if(height>width && width>=800 && height>=1000){
            return true;
        }else if( width>=1000 && height>=800){
            return true;
        }else return false;
    }

    protected void beforeSetContentView() {
        if(isBigScreen()){ // no window
            getWindow().requestFeature(Window.FEATURE_NO_TITLE);
        }
    }
    
    
    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }
    
    /**
     * Fades the webview in or out
     *
     * @param toVisible
     *            true for fade in, false for fade out.
     */
    public void fade(boolean toVisible) {
        if (mWebView != null) {
            if (mIsVisible != toVisible) {
                mIsVisible = toVisible;
                AlphaAnimation anim = new AlphaAnimation(toVisible ? 0.0f : 1.0f,
                        toVisible ? 1.0f : 0.0f);
                anim.setDuration(toVisible ? 200 : 0);
                anim.setFillAfter(true);
                mWebView.startAnimation(anim);
                if (mWebView.getVisibility() == View.INVISIBLE){
                    mWebView.setVisibility(View.VISIBLE);
                    this.findViewById(RR.id("frameLayout")).setVisibility(View.VISIBLE);
                }
            }
        }
    }
}