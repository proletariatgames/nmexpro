package com.openfeint.internal.request;

import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.Util;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.resource.ServerException;

public abstract class JSONRequest extends JSONContentRequest {
	
	// Note: responseBody may be null (if the server responds with head :ok, etc).
	public void onSuccess(Object responseBody) { }
	public void onFailure(String exceptionMessage) { }

	public JSONRequest() {
		super();
	}
	
	public JSONRequest(OrderedArgList args) {
		super(args);
	}
	
	public void onResponse(int responseCode, byte[] bodyStream) {
		// HEAD (no body contents, or a single space) are OK to go through even if there's no Content-Type header, hence the length>0 test.
		if (bodyStream.length == 0 || (bodyStream.length == 1 && bodyStream[0] == ' ') || isResponseJSON()) {
			Object responseBody = parseJson(bodyStream);
			onResponse(responseCode, responseBody);
		} else {
			// Server screwed up.
			onResponse(responseCode, notJSONError(responseCode));
		}
	}
	
	protected Object parseJson(byte[] bodyStream) {
		return Util.getObjFromJson(bodyStream);
	}

	protected void onResponse(int responseCode, Object responseBody) {
		if (200 <= responseCode && responseCode < 300 && (responseBody == null || !(responseBody instanceof ServerException))) {
			onSuccess(responseBody);
		} else {
			onFailure(responseBody);
		}
	}

	protected void onFailure(Object responseBody) {
		String exceptionMessage = OpenFeintInternal.getRString(RR.string("of_unknown_server_error"));
		
		if (responseBody != null && responseBody instanceof ServerException) {
			ServerException e = (ServerException)responseBody;
			exceptionMessage = e.message;
			
			if (e.needsDeveloperAttention) {
				OFLog.e("ServerException", exceptionMessage);
				OpenFeintInternal.getInstance().displayErrorDialog(exceptionMessage);
			}
		}

		onFailure(exceptionMessage);
	}
}
