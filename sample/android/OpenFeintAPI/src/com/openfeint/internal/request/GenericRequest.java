package com.openfeint.internal.request;

import java.util.Map;

import org.apache.http.params.HttpConnectionParams;



public class GenericRequest extends JSONContentRequest {
	final String mMethod;
	final String mPath;
	private IRawRequestDelegate mDelegate;
	private long mTimeout = super.timeout();
	private int mRetries = super.numRetries();
	
	@Override public long timeout() { return mTimeout; }
	@Override public int numRetries() { return mRetries; } 
	
	public GenericRequest(final String path, final String method,
			final Map<String, Object> args, 
			final Map<String, Object> httpParams, 
			final IRawRequestDelegate delegate) {

		// construct with no args.
		super();
		
		if (httpParams != null) {
			for (Map.Entry<String, Object> e : httpParams.entrySet()) {
				final String k = e.getKey();
				final String v = e.getValue().toString();
				final int i = Integer.parseInt(v);
				if (k.equals("connectionTimeout")) {
					HttpConnectionParams.setConnectionTimeout(getHttpParams(), i);
				} else if (k.equals("socketTimeout")) {
					HttpConnectionParams.setSoTimeout(getHttpParams(), i);
				} else if (k.equals("lingerTimeout")) {
					HttpConnectionParams.setLinger(getHttpParams(), i);
				} else if (k.equals("timeout")) {
					mTimeout = i;
				} else if (k.equals("retries")) {
					mRetries = i;
				}
			}
		}
		

		// We want format json on generic requests...
		OrderedArgList argList = new OrderedArgList(args);
		argList.put("format", "json");
		setArgs(argList);

		mMethod = method;
		mPath = path;
    		
		setDelegate(delegate);
	}

	
	@Override public String method() { return mMethod; }
	@Override public String path() { return mPath; }

	@Override public void onResponse(int responseCode, byte[] body) {
		try {
			String respText;
			if (!isResponseJSON()) {
				respText = notJSONError(responseCode).generate();
			} else {
				respText = body != null ? new String(body) : "";
			}
			
			if(mDelegate != null) {
			  mDelegate.onResponse(responseCode, respText);
			}
			
		} catch (IllegalStateException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}

	public void setDelegate(IRawRequestDelegate mDelegate) {
		this.mDelegate = mDelegate;
	}
}
