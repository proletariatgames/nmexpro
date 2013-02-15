package com.openfeint.internal.resource;

public class BlobUploadParameters extends Resource {

	// Fields
	public String action;
	public String key;
	public String AWSAccessKeyId;
	public String acl;
	public String policy;
	public String signature;

	// For parser use only.
	public BlobUploadParameters() { }
	
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (BlobUploadParameters.class, "blob_upload_parameters") { public Resource factory () { return new BlobUploadParameters (); } };

		klass.mProperties.put("action", new StringResourceProperty() { public void set(Resource obj, String val) { ((BlobUploadParameters)obj).action = val; } public String get(Resource obj) { return ((BlobUploadParameters)obj).action; } });
		klass.mProperties.put("key", new StringResourceProperty() { public void set(Resource obj, String val) { ((BlobUploadParameters)obj).key = val; } public String get(Resource obj) { return ((BlobUploadParameters)obj).key; } });
		klass.mProperties.put("AWSAccessKeyId", new StringResourceProperty() { public void set(Resource obj, String val) { ((BlobUploadParameters)obj).AWSAccessKeyId = val; } public String get(Resource obj) { return ((BlobUploadParameters)obj).AWSAccessKeyId; } });
		klass.mProperties.put("acl", new StringResourceProperty() { public void set(Resource obj, String val) { ((BlobUploadParameters)obj).acl = val; } public String get(Resource obj) { return ((BlobUploadParameters)obj).acl; } });
		klass.mProperties.put("policy", new StringResourceProperty() { public void set(Resource obj, String val) { ((BlobUploadParameters)obj).policy = val; } public String get(Resource obj) { return ((BlobUploadParameters)obj).policy; } });
		klass.mProperties.put("signature", new StringResourceProperty() { public void set(Resource obj, String val) { ((BlobUploadParameters)obj).signature = val; } public String get(Resource obj) { return ((BlobUploadParameters)obj).signature; } });

		return klass;
	}

}
