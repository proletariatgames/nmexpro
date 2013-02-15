package com.openfeint.internal.request;

public interface IRawRequestDelegate {
	public void onResponse(int responseCode, String responseBody);
}
