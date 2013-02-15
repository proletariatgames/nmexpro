package com.openfeint.internal;

/**
 * Most OpenFeint API methods take callback arguments that extend this class.
 * They all have their own onSuccess() methods that you may override.  This class
 * exists mainly so that onFailure() isn't repeated in every callback class.
 *  
 * @author Aurora Feint, Inc.
 */
public abstract class APICallback {
	/**
	 * This method is called when the API request fails.
	 * @param exceptionMessage The message from the server giving the reason for the failure.
	 */
	public void onFailure(String exceptionMessage) { }
}
