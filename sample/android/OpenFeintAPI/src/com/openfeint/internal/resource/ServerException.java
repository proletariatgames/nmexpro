package com.openfeint.internal.resource;

public class ServerException extends Resource {

	// Fields
	public String exceptionClass;
	public String message;
	public boolean needsDeveloperAttention;

	public ServerException(String klass, String message) {
		this.exceptionClass = klass;
		this.message = message;
	}

	// For parser use only.
	public ServerException() { }
	
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (ServerException.class, "exception") { public Resource factory () { return new ServerException (); } };

		klass.mProperties.put("class", new StringResourceProperty() { public void set(Resource obj, String val) { ((ServerException)obj).exceptionClass = val; } public String get(Resource obj) { return ((ServerException)obj).exceptionClass; } });
		klass.mProperties.put("message", new StringResourceProperty() { public void set(Resource obj, String val) { ((ServerException)obj).message = val; } public String get(Resource obj) { return ((ServerException)obj).message; } });
		klass.mProperties.put("needs_developer_attention", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((ServerException)obj).needsDeveloperAttention = val; } public boolean get(Resource obj) { return ((ServerException)obj).needsDeveloperAttention; } });

		return klass;
	}
}
