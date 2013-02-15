package com.openfeint.internal.request;

public class ExternalBitmapRequest extends BitmapRequest {

	private String mURL;
	public ExternalBitmapRequest(String url) { super(); mURL = url; }
	
	@Override public boolean signed() { return false; }
	@Override public String url() { return mURL; }
	@Override public String path() { return ""; }

}
