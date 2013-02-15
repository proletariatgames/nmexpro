package com.openfeint.internal.request;

import com.openfeint.internal.request.multipart.ByteArrayPartSource;
import com.openfeint.internal.resource.BlobUploadParameters;

public class CompressedBlobPostRequest extends BlobPostRequest {
	
	BlobUploadParameters mParameters;
	String mFilename;
	byte mUncompressedData;
	
	public CompressedBlobPostRequest(BlobUploadParameters parameters, String filename, byte[] uncompressedData) {
		super(parameters, new ByteArrayPartSource(filename, Compression.compress(uncompressedData)), "application/octet-stream");
	}
}
