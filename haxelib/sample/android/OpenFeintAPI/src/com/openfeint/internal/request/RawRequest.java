package com.openfeint.internal.request;


public abstract class RawRequest extends JSONRequest {

	private IRawRequestDelegate mDelegate;

	public RawRequest() {
		super();
	}
	
	public RawRequest(OrderedArgList args) {
		super(args);
	}

	@Override public void onResponse(int responseCode, byte[] body) {
		try {
			super.onResponse(responseCode, body);
			if (mDelegate != null) {
				String respText;
				// now do the delegate, after checking that the content is indeed JSON.
				if (!isResponseJSON()) {
					respText = notJSONError(responseCode).generate();
				} else {
					respText = new String(body);
				}
				
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