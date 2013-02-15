package com.openfeint.internal.ui;

public abstract class WebViewCacheCallback {
	public abstract void pathLoaded(String path);
	public abstract void failLoaded();
	public void onTrackingNeeded() {}
}
