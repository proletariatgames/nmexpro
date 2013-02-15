package com.openfeint.internal.request;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.RR;

public abstract class BitmapRequest extends DownloadRequest {

	// Override me
	public void onSuccess(Bitmap responseBody) { }

	@Override protected void onSuccess(byte[] body) {
		Bitmap b = BitmapFactory.decodeByteArray(body, 0, body.length);
		if (b != null) {
			onSuccess(b);
		} else {
			onFailure(OpenFeintInternal.getRString(RR.string("of_bitmap_decode_error")));
		}
	}

}
