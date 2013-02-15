package com.openfeint.api;

import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;
import com.openfeint.internal.logcat.OFLog;

/**
 * Object exposing all available application settings for use during OpenFeint initialization.
 * 
 * @author Aurora Feint, Inc.
 */
public class OpenFeintSettings {
	
    public static String tag = "OpenFeintSettings";
	/**
	 * Create an OpenFeintSettings object with default values for all settings. The constructor
	 * parameters establish the only required settings.
	 * 
	 * @param _name		Human-readable name for this application
	 * @param _key		'Product Key' for this application. Available on the OpenFeint Developer Dashboard.
	 * @param _secret	'Product Secret' for this application. Available on the OpenFeint Developer Dashboard.
	 * @param _id		'Client Application ID' for this application. Available on the OpenFeint Developer Dashboard.
	 */
	public OpenFeintSettings(String _name, String _key, String _secret, String _id) { 
		name = _name;
		key = _key;
		secret = _secret;
		id = _id;
		settings = new HashMap<String, Object>();
	}

	/**
	 * Create an OpenFeintSettings object with default values for all settings. The constructor
	 * parameters establish the only required settings.
	 * 
	 * @param _name		Human-readable name for this application
	 * @param _key		'Product Key' for this application. Available on the OpenFeint Developer Dashboard.
	 * @param _secret	'Product Secret' for this application. Available on the OpenFeint Developer Dashboard.
	 * @param _id		'Client Application ID' for this application. Available on the OpenFeint Developer Dashboard.
	 * @param _settings	Any settings that you want to configure.  See the static String members of this class whose names start with "OpenFeintSetting".
	 */
	public OpenFeintSettings(String _name, String _key, String _secret, String _id, Map<String, Object> _settings) { 
		name = _name;
		key = _key;
		secret = _secret;
		id = _id;
		settings = _settings;
	}

	/**
	 * The name of this Application.
	 */
	public String name;
	
	/**
	 * The 'Product Key' for this application. Available on the OpenFeint Developer Dashboard.
	 */
	public String key;

	/**
	 * The 'Product Secret' for this application. Available on the OpenFeint Developer Dashboard.
	 */
	public String secret;

	/**
	 * The 'Client Application ID' for this application. Available on the OpenFeint Developer Dashboard.
	 */
	public String id;
	
	/**
	 * The settings for this application.
	 */
	public Map<String, Object> settings;
	
	/**
	 * Used for internal development.
	 */
	public void applyOverrides(Properties settings) {
		if (settings == null) return;
		
		String property;
		
		property = settings.getProperty("app-id");
		if (property != null) id = property;

		property = settings.getProperty("game-name");
		if (property != null) name = property;

		property = settings.getProperty("app-key");
		if (property != null) key = property;

		property = settings.getProperty("app-secret");
		if (property != null) secret = property;
	}
	
	public void verify() {
		String verificationError = null;
		
		if (key == null)
			verificationError = 
				OpenFeintInternal.getRString(RR.string("of_key_cannot_be_null"));
		else if (secret == null)
			verificationError = OpenFeintInternal.getRString(RR.string("of_secret_cannot_be_null"));
		else if (id == null)
			verificationError = OpenFeintInternal.getRString(RR.string("of_id_cannot_be_null"));
		else if (name == null)
			verificationError = OpenFeintInternal.getRString(RR.string("of_name_cannot_be_null"));

		if (verificationError != null) {
            OFLog.e(tag, verificationError);
			OpenFeintInternal.getInstance().displayErrorDialog(verificationError);
		}			
	}

	/**
	 * This setting controls what could storage compression strategy to use.  Valid values are:
	 * <ul>
	 * <li> {@link CloudStorageCompressionStrategyDefault}
	 * <li> {@link CloudStorageCompressionStrategyNoCompression}
	 * <li> {@link CloudStorageCompressionStrategyLegacyHeaderlessCompression}
	 * </ul>
	 */
	public static final String SettingCloudStorageCompressionStrategy = "SettingCloudStorageCompressionStrategy";
	
	/**
	 * This is a valid value of the key {@link SettingCloudStorageCompressionStrategy}.  By using this as your strategy,
	 * uploaded and downloaded blobs will automatically compress and decompress themselves if they achieve a compression
	 * ratio large enough to overcome the size of the additional header.  It is strongly recommended that you use this
	 * strategy; this will ensure transparent interoperation with iOS clients.
	 */
	public static final String CloudStorageCompressionStrategyDefault = "CloudStorageCompressionStrategyDefault";
	
	/**
	 * This is a valid value of the key {@link SettingCloudStorageCompressionStrategy}.  By using this as your strategy,
	 * uploaded and downloaded blobs will not compress or decompress at all.  There is no setting on iOS that corresponds
	 * to this.  It is not recommended to use this strategy if you ever expect to interoperate with an iOS client; however,
	 * if you used the score blobs functionality in the 1.5 Android SDK, this is the strategy that was used, so you'll
	 * need to specify this strategy going forward.
	 */
	public static final String CloudStorageCompressionStrategyNoCompression = "CloudStorageCompressionStrategyNoCompression";
	
	/**
	 * This is a valid value of the key {@link SettingCloudStorageCompressionStrategy}.  By using this as your strategy,
	 * uploaded and downloaded blobs will always compress and decompress, regardless of whether compression actually
	 * reduces file size.  It is strongly recommended to NOT use this strategy, unless you have been specifically using
	 * OpenFeintSettingCloudStorageLegacyHeaderlessCompression on iOS and need to maintain compatibility with those iOS
	 * clients. 
	 */
	public static final String CloudStorageCompressionStrategyLegacyHeaderlessCompression = "CloudStorageCompressionStrategyLegacyHeaderlessCompression";


    /**
     * Change the desired orientation of openfeint activity
     * An orientation constant as used in ActivityInfo.screenOrientation.
     **/
    public static final String RequestedOrientation = "RequestedOrientation";
}
