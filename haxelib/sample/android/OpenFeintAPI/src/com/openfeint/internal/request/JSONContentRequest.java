package com.openfeint.internal.request;

import org.apache.http.client.methods.HttpUriRequest;

import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.resource.ServerException;

public abstract class JSONContentRequest extends BaseRequest {

	private static final String CONTENT_TYPE = "application/json";
	public static final String DESIRED_RESPONSE_PREFIX = CONTENT_TYPE + ";";

	protected static ServerException notJSONError(int responseCode) {
		return new ServerException("ServerError", String.format(OpenFeintInternal.getRString(RR.string("of_server_error_code_format")), responseCode));
	}

	public JSONContentRequest() {
		super();
	}

	protected HttpUriRequest generateRequest() {
		final HttpUriRequest req = super.generateRequest();
		req.addHeader("Accept", CONTENT_TYPE);
		return req;
	}

	protected boolean isResponseJSON() {
		String responseType = getResponseType();
		return responseType != null && responseType.startsWith(DESIRED_RESPONSE_PREFIX);
	}

	public JSONContentRequest(OrderedArgList args) {
		super(args);
	}

}