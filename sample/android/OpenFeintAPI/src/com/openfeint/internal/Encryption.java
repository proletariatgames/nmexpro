package com.openfeint.internal;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;

import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.CipherOutputStream;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.PBEParameterSpec;

import com.openfeint.internal.logcat.OFLog;


public class Encryption {
	// related links http://stackoverflow.com/questions/2256774/android-secretkeyfactory-problems-implementation-not-found
	// http://download.oracle.com/javase/6/docs/technotes/guides/security/SunProviders.html
	// PBEWithMD5AndDES
    private static final String INSTANCE = "PBEWithSHA256And256BitAES-CBC-BC";
    private static final String TAG = "Encryption";
    private static final int SALT_LENGTH     = 10;
    private static final int SALT_ITERATIONS = 10;
    
    private static SecretKey secretKey;
    
    public static CipherOutputStream encryptionWrap(OutputStream os) {
    	try {
        	final byte salt[] = new byte[SALT_LENGTH];
        	new java.security.SecureRandom().nextBytes(salt); // @TEMP
	    	os.write(salt);
	    	
	        PBEParameterSpec pbeParamSpec = new PBEParameterSpec(salt, SALT_ITERATIONS);
	        Cipher c = Cipher.getInstance(INSTANCE);
	        c.init(Cipher.ENCRYPT_MODE, secretKey, pbeParamSpec);
	
	        return new CipherOutputStream(os, c);
    	} catch (Exception e) {
    		OFLog.e(TAG, e.getMessage());
    	}
    	return null;
    }

    public static CipherInputStream decryptionWrap(InputStream is) {
    	try {
    		final byte salt[] = new byte[SALT_LENGTH];
    		if (is.read(salt) != SALT_LENGTH) throw new Exception("Couldn't read entire salt");
	    	
	        PBEParameterSpec pbeParamSpec = new PBEParameterSpec(salt, SALT_ITERATIONS);
	        Cipher c = Cipher.getInstance(INSTANCE);
	        c.init(Cipher.DECRYPT_MODE, secretKey, pbeParamSpec);
	
	        return new CipherInputStream(is, c);
    	} catch (Exception e) {
    		OFLog.e(TAG, e.getMessage());
    	}
    	return null;
    }

    /*
     * if init return false, then this platform does not support
     * secure data store. then can't not use ofx
     */
    public static boolean init(String password) {
        try {
            PBEKeySpec pbeKeySpec = new PBEKeySpec(password.toCharArray());
            SecretKeyFactory keyFac = SecretKeyFactory.getInstance(INSTANCE);
            secretKey = keyFac.generateSecret(pbeKeySpec);

    		// try to make an encrypter and decrypter to see if it works.
        	byte testString[] = INSTANCE.getBytes(); // just write the name of the cipher we're using
        	
	        ByteArrayOutputStream baos = new ByteArrayOutputStream();
	        CipherOutputStream cos = encryptionWrap(baos);
	        cos.write(testString);
	        cos.close();
	        final byte[] encryptedContents = baos.toByteArray();
	        if (encryptedContents.length == 0) throw new Exception();
	        
			CipherInputStream cis = decryptionWrap(new ByteArrayInputStream(encryptedContents));
	        byte decryptedContents[] = Util.toByteArray(cis);
	        if (!Arrays.equals(decryptedContents, testString)) throw new Exception();
	        
        } catch (Exception e) {
			secretKey = null;
			return false;
    	}
        
        return true;
    }
    
    public static boolean initialized() {
    	return secretKey != null;
    }
    
    public static InputStream decrypt(File file) throws FileNotFoundException {
		return decryptionWrap(new FileInputStream(file));
    }
    
    public static byte[] decryptFile(String path) throws FileNotFoundException, IOException {
    	return Util.toByteArray(decrypt(new File(path)));
    }
    
    public static byte[] decrypt(byte input[]) {
    	try {
    		return Util.toByteArray(decryptionWrap(new ByteArrayInputStream(input)));
    	} catch (Exception e) {
    		return null;
    	}
    }
    
    public static boolean encrypt(byte[] in, String path) {
    	try {
    		OutputStream os = encrypt(path);
    		os.write(in);
    		os.close();
    		return true;
    	} catch (Exception e) {
    		// @TODO cleanup?
    	}
    	return false;
    }
    
    public static OutputStream encrypt(String path) throws FileNotFoundException {
    	return encryptionWrap(new FileOutputStream(new File(path)));
    }

    public static byte[] encrypt(byte input[]) {
    	try {
    		ByteArrayOutputStream baos = new ByteArrayOutputStream();
    		final CipherOutputStream enc = encryptionWrap(baos);
			enc.write(input);
    		enc.close();
    		return baos.toByteArray();
    	} catch (Exception e) {
    		return null;
    	}
    }
    
}
