package com.openfeint.internal.request;

import org.apache.http.HttpEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpUriRequest;

import com.openfeint.internal.request.multipart.FilePart;
import com.openfeint.internal.request.multipart.MultipartHttpEntity;
import com.openfeint.internal.request.multipart.Part;
import com.openfeint.internal.request.multipart.PartSource;
import com.openfeint.internal.request.multipart.StringPart;
import com.openfeint.internal.resource.BlobUploadParameters;

public class BlobPostRequest extends BaseRequest {

	@Override public boolean signed() { return false; } 

	BlobUploadParameters mParams;
	protected PartSource mPartSource;
	String mContentType;
	
	@Override
	public String method() {
		return "POST";
	}
	
	// Since blob posts go to another server, you have to overload url as well as path.
	public String url() {
		return mParams.action;
	}
	
	public void sign() {
		// lol nop
	}
	
	public String path() { return ""; }
	
	protected HttpUriRequest generateRequest() {
		if (null == mPartSource) {
			// This will generate a servercode 0 failure.
			return null;
		}
		
		HttpPost retval = new HttpPost(url());
		
		int idx = 0;
		Part parts[] = new Part[6];
		parts[idx++] = new StringPart("AWSAccessKeyId", mParams.AWSAccessKeyId);
		parts[idx++] = new StringPart("acl", mParams.acl);
		parts[idx++] = new StringPart("key", mParams.key);
		parts[idx++] = new StringPart("policy", mParams.policy);
		parts[idx++] = new StringPart("signature", mParams.signature);
		parts[idx++] = new FilePart("file", mPartSource, mContentType, null);
		
		HttpEntity e = new MultipartHttpEntity(parts);
		retval.setEntity(e);
		
		addParams(retval);
		
		return retval;
	}

	private IRawRequestDelegate mDelegate;

	public BlobPostRequest(BlobUploadParameters params, PartSource partSource, String contentType) {
		super(null);
		
		mParams = params;
		mPartSource = partSource;
		mContentType = contentType;
	}

	@Override public void onResponse(int responseCode, byte[] body) {
		if (mDelegate != null) {
			mDelegate.onResponse(responseCode, new String(body));
		}
	}

	public void setDelegate(IRawRequestDelegate mDelegate) {
		this.mDelegate = mDelegate;
	}
}
