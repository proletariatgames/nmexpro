package com.openfeint.api.resource;

import com.openfeint.internal.APICallback;
import com.openfeint.internal.request.JSONRequest;
import com.openfeint.internal.resource.DateResourceProperty;
import com.openfeint.internal.resource.LongResourceProperty;
import com.openfeint.internal.resource.Resource;
import com.openfeint.internal.resource.ResourceClass;

/**
 * An object representing an authoritative timestamp according to the OpenFeint server.
 * You can use this class to ask OpenFeint what time it is for purposes of filtering
 * leaderboards, or whatever you like.
 */
public class ServerTimestamp extends Resource {

	/**
	 * The timestamp according to the server, in java.util.Date format.
	 */
	public java.util.Date timestamp;
	
	/**
	 * The timestamp according to the server, in POSIX time.
	 */
	public long secondsSinceEpoch;
	
	/**
	 * A callback class you can extend for calling ServerTimestamp.get().
	 */
	public abstract static class GetCB extends APICallback {
		/**
		 * When ServerTimestamp.get() completes, this will be called with
		 * the current time according to the server.
		 * 
		 * @param currentTime The ServerTimestamp object representing 'now'.
		 */
		public abstract void onSuccess(ServerTimestamp currentTime);
	}
	
	/**
	 * Call this method to get a ServerTimestamp from the OpenFeint server.
	 * Note that this is asynchronous and therefore inherently coarse-grained;
	 * it is not recommended to use this for profiling your code or the like.
	 * However this is a very handy way to check what day it is in
	 * a way that players can't hack around simply by changing their system clock.
	 * 
	 * @param cb The callback object that will be called when get() completes.
	 */
	public static void get(final GetCB cb) {
		JSONRequest req = new JSONRequest() {
			@Override public String method() { return "GET"; }
			@Override public String path() { return "/xp/server_timestamp"; }
			@Override public void onSuccess(Object responseBody) {
				if (cb != null) {
					cb.onSuccess((ServerTimestamp)responseBody);
				}
			}
			
			@Override public void onFailure(String exceptionMessage) {
				super.onFailure(exceptionMessage);
				if (cb != null) {
					cb.onFailure(exceptionMessage);
				}
			}
		};

		req.launch();
	}
	
	/**
	 * This constructor is for use by the parser only.
	 */
	public ServerTimestamp() { }
	
	/**
	 * This method is used internally by OpenFeint.
	 */
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (ServerTimestamp.class, "server_timestamp") { public Resource factory () { return new ServerTimestamp (); } };

		klass.mProperties.put("timestamp", new DateResourceProperty() { public void set(Resource obj, java.util.Date val) { ((ServerTimestamp)obj).timestamp = val; } public java.util.Date get(Resource obj) { return ((ServerTimestamp)obj).timestamp; } });
		klass.mProperties.put("seconds_since_epoch", new LongResourceProperty() { public void set(Resource obj, long val) { ((ServerTimestamp)obj).secondsSinceEpoch = val; } public long get(Resource obj) { return ((ServerTimestamp)obj).secondsSinceEpoch; } });

		return klass;
	}

}
