package com.openfeint.internal.ui;

import java.util.concurrent.atomic.AtomicBoolean;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class NativeBrowser extends NestedWindow {

	public static final String INTENT_ARG_PREFIX = "com.openfeint.internal.ui.NativeBrowser.argument.";

	private Handler mHandler;
	private Runnable mTimeoutWatchdog;
	private AtomicBoolean mFinished = new AtomicBoolean(false);
		
	public final class JSInterface {
		public void returnValue(final String returnValue) {
			runOnUiThread(new Runnable() {
				@Override public void run() {
					if (mFinished.compareAndSet(false, true)) {
						Intent returnIntent = new Intent();
						if (null != returnValue) { returnIntent.putExtra(INTENT_ARG_PREFIX + "result", returnValue); }
						NativeBrowser.this.setResult(Activity.RESULT_OK, returnIntent);
						NativeBrowser.this.finish();
					}
				}
			});
		}
	};
	
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

        final Bundle extras = this.getIntent().getExtras();

        final String src = extras.getString(INTENT_ARG_PREFIX + "src");
        final String timeout = extras.getString(INTENT_ARG_PREFIX + "timeout");

		// Setup WebView
		mWebView.getSettings().setJavaScriptEnabled(true);
		mWebView.addJavascriptInterface(new JSInterface(), "NativeBrowser");
		
		mWebView.setWebViewClient(new WebViewClient() {
			private void clearTimeout() {
				if (mHandler != null && mTimeoutWatchdog != null) {
					mHandler.removeCallbacks(mTimeoutWatchdog);
					mHandler = null;
					mTimeoutWatchdog = null;
				}
			}
			@Override public void onPageFinished(WebView view, String url) {
				clearTimeout();
				super.onPageFinished(view, url);
			}
			@Override public void onReceivedError(WebView view, int errorCode, String description, String failingUrl) {
				clearTimeout();
				super.onReceivedError(view, errorCode, description, failingUrl);
				
				Intent returnIntent = new Intent();
				returnIntent.putExtra(INTENT_ARG_PREFIX + "failed", true);
				returnIntent.putExtra(INTENT_ARG_PREFIX + "failure_code", errorCode);
				returnIntent.putExtra(INTENT_ARG_PREFIX + "failure_desc", description);
				NativeBrowser.this.setResult(Activity.RESULT_OK, returnIntent);
				NativeBrowser.this.finish();
			}
		});
		mWebView.setWebChromeClient(new WebChromeClient());
		
		mWebView.loadUrl(src);
		
		if (timeout != null) {
			mHandler = new Handler();
			mTimeoutWatchdog = new Runnable() {
				@Override public void run() {
					if (mFinished.compareAndSet(false, true)) {
						Intent returnIntent = new Intent();
						returnIntent.putExtra(INTENT_ARG_PREFIX + "failed", true);
						returnIntent.putExtra(INTENT_ARG_PREFIX + "failure_code", 0);
						returnIntent.putExtra(INTENT_ARG_PREFIX + "failure_desc", "Timeout");
						NativeBrowser.this.setResult(Activity.RESULT_OK, returnIntent);
						NativeBrowser.this.finish();
					}
				}
			};
			mHandler.postDelayed(mTimeoutWatchdog, Integer.parseInt(timeout));
		}
		
		fade(true);
	}
}
