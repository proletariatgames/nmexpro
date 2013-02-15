package com.openfeint.internal.request;

import com.openfeint.internal.Util;

public class Signer {
	private String mKey;
	public String getKey() { return mKey; }
	
	private String mSecret;
	
	private String mSigningKey;
	
	private String mAccessToken;
	
	public Signer(String key, String secret) {
		mKey = key;
		mSecret = secret;
		mSigningKey = mSecret + "&";
	}
	
	public void setAccessToken(String token, String tokenSecret) {
		mAccessToken = token;
		mSigningKey = mSecret + "&" + tokenSecret;
	}
	
	public String sign(String path, String method, long secondsSinceEpoch, OrderedArgList unsignedParams) {
		
		if (mAccessToken != null) { unsignedParams.put("token", mAccessToken); }
		
		StringBuilder sigbase = new StringBuilder();
		sigbase.append(path);
		sigbase.append('+');
		sigbase.append(mSecret);
		sigbase.append('+');
		sigbase.append(method);
		sigbase.append('+');
		
		final String argString = unsignedParams.getArgString();
		sigbase.append(argString == null ? "" : argString);
		
        return Util.base64HMACSHA1(mSigningKey, sigbase.toString());
    }
};
