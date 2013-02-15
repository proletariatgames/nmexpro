package com.openfeint.internal;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.net.Uri;
import android.provider.MediaStore;
import android.widget.Toast;

import com.openfeint.internal.logcat.OFLog;

// All of the methods in here are static because this class invokes another activity
// that frequently evicts the game process.  We can't really expect ImagePicker to stay around, and
// none of this really requires state, so it is better to just make it non-stateful.
public class ImagePicker {
	public static final int IMAGE_PICKER_REQ_ID = 10009;
	protected static final String TAG = "ImagePicker";

	public static void show(Activity currentActivity) {
		ActivityManager am = (ActivityManager)currentActivity.getSystemService(Activity.ACTIVITY_SERVICE);
		ActivityManager.MemoryInfo mi = new ActivityManager.MemoryInfo();
		am.getMemoryInfo(mi);

		Intent intent = new Intent(Intent.ACTION_PICK, android.provider.MediaStore.Images.Media.INTERNAL_CONTENT_URI);
		intent.setType("image/*");
		currentActivity.startActivityForResult(intent, IMAGE_PICKER_REQ_ID);
	}
	
	//note: this must be forwarded into by mActivity
	//return a true if the image picker detects the proper request code
	public static boolean isImagePickerActivityResult(int requestCode) {
		return requestCode == IMAGE_PICKER_REQ_ID;
	}
	
	public static Bitmap onImagePickerActivityResult(Activity currentActivity, int resultCode, int maxLength, Intent returnedIntent) {
		if (resultCode == Activity.RESULT_OK) {  
			Uri selectedImage = returnedIntent.getData();
	        String[] columns = {MediaStore.Images.ImageColumns.DATA, MediaStore.Images.ImageColumns.ORIENTATION};

	        Cursor cursor = currentActivity.getContentResolver().query(selectedImage, columns, null, null, null);
	        if (cursor != null) {
		        cursor.moveToFirst();
	
		        int columnIndex = cursor.getColumnIndex(columns[0]);
		        String filePath = cursor.getString(columnIndex);
				int rotation = cursor.getInt(cursor.getColumnIndex(columns[1]));
		        cursor.close();

		        Bitmap image = resize(filePath, maxLength, rotation);
		        OFLog.e(TAG, "image! "+ image.getWidth() +"x"+ image.getHeight());

		        return image;
	        } else {
	        	final String msg = OpenFeintInternal.getRString(RR.string("of_profile_picture_download_failed"));
	        	Toast.makeText(OpenFeintInternal.getInstance().getContext(), msg, Toast.LENGTH_LONG).show();
	        }
        }

        return null;
	}

	public static void compressAndUpload(Bitmap image, String apiPath, OpenFeintInternal.IUploadDelegate delegate) {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        image.compress(Bitmap.CompressFormat.PNG, 100, out);
    	upload(apiPath, out, delegate);
	}
	
	private static Bitmap resize(String filePath, int maxLength, int rotation) {
		Bitmap image = preScaleImage(filePath, maxLength);
		
		int width  = image.getWidth();
		int height = image.getHeight();
		boolean tall = height > width; 
		
		// Crop the center and make it square
		int _x = tall ? 0 : (width-height)/2;
		int _y = tall ? (height-width)/2 : 0;
		int _length = (tall ? width : height);
		
		float scale = (float)maxLength / (float)_length;

		Matrix transform = new Matrix();
		transform.postScale(scale, scale);
		transform.postRotate(rotation);

		return Bitmap.createBitmap(image, _x, _y, _length, _length, transform, false);
	}
	
	// http://stackoverflow.com/questions/477572/android-strange-out-of-memory-issue
	private static Bitmap preScaleImage(String filePath, int maxLength) {
		File f = new File(filePath);
		
		try {
	        //Decode image size
	        BitmapFactory.Options o = new BitmapFactory.Options();
	        o.inJustDecodeBounds = true;
	        BitmapFactory.decodeStream(new FileInputStream(f), null, o);

	        //Find the correct scale value. It should be the power of 2.
	        int minDim = Math.min(o.outWidth, o.outHeight);
	        int scale = 1;
	        while (minDim/2 > maxLength) {
	            minDim /= 2;
	            scale++;
	        }

	        //Decode with inSampleSize
	        BitmapFactory.Options o2 = new BitmapFactory.Options();
	        o2.inSampleSize = scale;
	        return BitmapFactory.decodeStream(new FileInputStream(f), null, o2);
	        
	    } catch (FileNotFoundException e) {
	    	OFLog.e(TAG, e.toString());
	    }
	    return null;
	}
	
	private static void upload(String apiPath, ByteArrayOutputStream stream, final OpenFeintInternal.IUploadDelegate delegate) {
   		OpenFeintInternal.getInstance().uploadFile(apiPath, "profile.png", stream.toByteArray(), "image/png", delegate);
	}
}
