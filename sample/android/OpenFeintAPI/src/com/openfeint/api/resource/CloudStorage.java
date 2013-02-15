package com.openfeint.api.resource;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;
import java.util.regex.PatternSyntaxException;

import org.apache.http.client.methods.HttpPut;
import org.apache.http.client.methods.HttpUriRequest;
import org.apache.http.entity.ByteArrayEntity;

import com.openfeint.internal.APICallback;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.Util;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.request.CompressedBlobDownloadRequest;
import com.openfeint.internal.request.Compression;
import com.openfeint.internal.request.JSONRequest;
import com.openfeint.internal.resource.ServerException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonFactory;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonToken;

/**
 * The resource class that represents the static CloudStorage repository in OpenFeint.
 * A CloudStorage blob is just a binary blob with a name (its <code>key</code>) that a game assigns to a specific user. Each CloudStorage blob can hold up to 250 KB of data.
 * Once a CloudStorage blob is persisted in the repository, it can be accessed by the user who owns it regardless of which device the user is using to playing the game.
 * If the user who "owns" the CloudStorage blob is logged in and is running the game in which the blob was created, the game can:
 * <ul>
 * <li>Write data to the CloudStorage blob and in that way persist that data in the cloud. This blob will be retrievable only by the currently logged-in user running the current game.</li>
 * <li>Retrieve the list of all CloudStorage blobs owned by the currently logged-in user and game.</li>
 * <li>Retrieve data owned by the currently logged-in user and game from a specified CloudStorage blob so it can be used locally.</li>
 * <li>Delete a specified CloudStorage blob (which deletes all of its data stored in the cloud).</li>
 * </ul>
 * You can structure the data in a CloudStorage blob in any way you like: as a filesystem or as a structure with a known memory layout or just as a long string of bytes. 
 * There's no way to transfer just part of the data - when saving and loading, the entire blob is transferred. 
 * Changes you make to data in device memory are not automatically saved to the CloudStorage blob in the cloud.  If you load the data from the CloudStorage blob, 
 * then make changes to that data locally, then load the CloudStorage blob again, you will lose your changes. 
 */
public class CloudStorage {
	
	public static int MAX_SIZE = 256*1024;

	/**
	 * A callback class you can extend for calling {@link list(ListCB)}.
	 */
	public abstract static class ListCB extends APICallback {
		/**
		 * If {@link list(ListCB)} completes successfully, this method will be called
		 * with the list of keys of CloudStorage blobs that belong to the currently logged-in user.
		 * @param cloudStores A list of keys of CloudStorage blobs that belong to the currently logged-in user and were stored by this game. Note that
		 * if the user owns no CloudStorage blobs from this game, this list is empty.
		 */
		public abstract void onSuccess(final List<String> cloudStores);
	}
	
	/**
	 * Call this method to get a list of CloudStorage blobs for the currently logged in user.
	 * @param cb A callback to accept the list of CloudStorage blobs.
	 */
	public static void list(final ListCB cb) {
		final String userID = OpenFeintInternal.getInstance().getUserID();
		if (null == userID || 0 == userID.length()) {
			if (cb != null) {
				cb.onFailure("A user must be logged in to list their persisted CloudStorage blobs.");
			}
		}
		
		final String appID = OpenFeintInternal.getInstance().getAppID();
		
		final String path = "/xp/users/" + userID + "/games/" + appID + "/save_cards";
		new JSONRequest() {
			@Override public boolean wantsLogin() { return true; }
			@Override public String path() { return path; }
			@Override public String method() { return "GET"; }
			@Override protected Object parseJson(byte[] bodyStream) {
				// Check to see if it's a server error first:
				Object o = Util.getObjFromJson(bodyStream);
				if (o != null && o instanceof ServerException) return o;
				
				// Otherwise use the handrolled parser.
				JsonFactory jsonFactory = new JsonFactory(); // for thread safety, we make our own.
				try {
					JsonParser jp = jsonFactory.createJsonParser(bodyStream);

					// {"save_cards":["a","b","c"]}
					if (jp.nextToken() != JsonToken.START_OBJECT) throw new JsonParseException("Couldn't find toplevel wrapper object.", jp.getTokenLocation());
					if (jp.nextToken() != JsonToken.FIELD_NAME) throw new JsonParseException("Couldn't find toplevel wrapper object.", jp.getTokenLocation());
					String hopefullyCloudStorages = jp.getText();
					if (!hopefullyCloudStorages.equals("save_cards")) throw new JsonParseException("Couldn't find toplevel wrapper object.", jp.getTokenLocation());
					if (jp.nextToken() != JsonToken.START_ARRAY) throw new JsonParseException("Couldn't find savecard array.", jp.getTokenLocation());
					ArrayList<String> rv = new ArrayList<String>();
					while (jp.nextToken() != JsonToken.END_ARRAY) {
						if (jp.getCurrentToken() != JsonToken.VALUE_STRING) throw new JsonParseException("Unexpected non-string in savecard array.", jp.getTokenLocation());
						rv.add(jp.getText());
					}
					// ignore trailing tokens
					return rv;
				} catch (Exception e) {
					OFLog.e(TAG, e.getMessage());
				}
				
				return new ServerException("JSONError", "Unexpected response format"); 
			}
			
			@SuppressWarnings("unchecked")
			@Override public void onSuccess(Object responseBody) {
				if (cb != null) {
					cb.onSuccess((List<String>)responseBody);
				}
			}
			
			@Override public void onFailure(String reason) {
				if (cb != null) {
					cb.onFailure(reason);
				}
			}
		}.launch();
	}
	
	/**
	 * A callback class you can extend for calling {@link load(LoadCB)}.
	 */
	public abstract static class LoadCB extends APICallback {
		/**
		 * If {@link load(LoadCB)} completes successfully, this method will be called
		 * with the data retrieved from the requested CloudStorage blob.
		 */
		public abstract void onSuccess(byte data[]);
	}
	
	/**
	 * Call this method to retrieve data from the particular CloudStorage blob identified by the provided key from the cloud.
	 * @param cb A callback to be notified when retrieval completes or fails.
	 */
	public static void load(final String key, final LoadCB cb) {
		final String userID = OpenFeintInternal.getInstance().getUserID();
		if (null == userID || 0 == userID.length()) {
			if (cb != null) {
				cb.onFailure("A user must be logged in to load data from a CloudStorage blob.");
			}
		}
		
		if (!isValidKey(key)) {
			if (cb != null) {
				cb.onFailure("'"+(null==key?"(null)":key)+"' is not a valid CloudStorage key.");
			}
		}
		
		final String appID = OpenFeintInternal.getInstance().getAppID();
		
		final String path = "/xp/users/" + userID + "/games/" + appID + "/save_cards/" + key;
		new CompressedBlobDownloadRequest() {
			@Override public boolean wantsLogin() { return true; }
			@Override public String path() { return path; }
			@Override public void onSuccessDecompress(byte body[]) {
				if (cb != null) cb.onSuccess(body);
			}
			@Override public void onFailure(String exceptionMessage) {
				if (cb != null) cb.onFailure(exceptionMessage);
			}
		}.launch();
	}
	
	/**
	 * A callback class you can extend for calling {@link save(SaveCB)}.
	 */
	public abstract static class SaveCB extends APICallback {
		/**
		 * If {@link save(SaveCB)} completes successfully, this method will be called to let
		 * you know that the data field has been successfully persisted to the CloudStorage blob specified.
		 */
		public abstract void onSuccess();
	}
	
	/**
	 * Call this method to write data to the CloudStorage blob identified by the specified {@link key}.  
	 * (This will overwrite any data already stored in the blob specified.)
	 * @param cb A callback to be notified when the save completes or fails.
	 */
	public static void save(final String key, final byte data[], final SaveCB cb) {
		final String userID = OpenFeintInternal.getInstance().getUserID();
		if (null == userID || 0 == userID.length()) {
			if (cb != null) {
				cb.onFailure("Cannot save because the owner of this CloudStorage blob is not logged in.");
			}
			return;
		}
		
		if (!isValidKey(key)) {
			if (cb != null) {
				cb.onFailure("'"+(null==key?"(null)":key)+"' is not a valid CloudStorage key.");
			} 
			return;
		}
		
		if (null == data || 0 == data.length) {
			if (cb != null) {
				cb.onFailure("data is empty.  data must be set before saving.");
			}
			return;
		}
		
		if (MAX_SIZE < data.length) {
			if (cb != null) {
				// This message helpfully scraped from the OFServer codebase
				cb.onFailure("You cannot exceed 256 kB per save card");
			}
			return;			
		}
		
		final String appID = OpenFeintInternal.getInstance().getAppID();
		
		final String path = "/xp/users/" + userID + "/games/" + appID + "/save_cards/" + key;

		new JSONRequest() {
			@Override public boolean wantsLogin() { return true; }
			@Override public String path() { return path; }
			@Override public String method() { return "PUT"; }
			@Override protected HttpUriRequest generateRequest() {
				HttpPut retval = new HttpPut(url());
				retval.setEntity(new ByteArrayEntity(Compression.compress(data)));
				addParams(retval);
				return retval;
			}
			@Override public void onSuccess(Object body) {
				if (cb != null) { cb.onSuccess(); }
			}
			@Override public void onFailure(String reason) {
				if (cb != null) { cb.onFailure(reason); }
			}
		}.launch();
	}
	
	/**
	 * A callback class you can extend for calling {@link delete(DeleteCB)}.
	 */
	public abstract static class DeleteCB extends APICallback {
		/**
		 * If {@link delete(DeleteCB)} completes successfully, this method will be called to let
		 * you know that this CloudStorage blob has been successfully deleted from the cloud.
		 */
		public abstract void onSuccess();
	}
	
	/**
	 * Call this method to delete the CloudStorage blob identified by the specified key from the cloud.
	 * @param cb A callback to be notified when the delete completes or fails.
	 */
	public static void delete(final String key, final DeleteCB cb) {
		final String userID = OpenFeintInternal.getInstance().getUserID();
		if (null == userID || 0 == userID.length()) {
			if (cb != null) {
				cb.onFailure("The user who owns this CloudStorage blob is not logged in. The CloudStorage blob specified was not deleted.");
			}
		}
		
		if (!isValidKey(key)) {
			if (cb != null) {
				cb.onFailure("'"+(null==key?"(null)":key)+"' is not a valid CloudStorage key.");
			}
		}
		
		final String appID = OpenFeintInternal.getInstance().getAppID();
		
		final String path = "/xp/users/" + userID + "/games/" + appID + "/save_cards/" + key;

		new JSONRequest() {
			@Override public boolean wantsLogin() { return true; }
			@Override public String path() { return path; }
			@Override public String method() { return "DELETE"; }
			@Override public void onSuccess(Object body) {
				if (cb != null) { cb.onSuccess(); }
			}
			@Override public void onFailure(String reason) {
				if (cb != null) { cb.onFailure(reason); }
			}
		}.launch();
	}

	/**
	 * A helper method that determines if a key is valid or not.
	 * A valid key must start with an alphabetical character and can be followed by any number
	 * of alphanumeric characters or dashes or underscores.
	 * @param key The key to be tested for validity.
	 * @return true if the supplied key is valid.  Otherwise, returns false.
	 */
	public static boolean isValidKey(String key) {
		if (key == null) return false;
		if (null == sValidKeyPattern) {
			try {
				sValidKeyPattern = Pattern.compile("[a-zA-Z][a-zA-Z0-9-_]*");
			} catch (PatternSyntaxException e) {
				return false;  // abandon ship, nothing makes sense
			}
		}
		return sValidKeyPattern.matcher(key).matches();
	}

	static private Pattern sValidKeyPattern;
}
