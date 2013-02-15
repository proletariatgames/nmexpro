package com.openfeint.internal.request;

import org.apache.http.Header;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpUriRequest;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDiskIOException;

import com.openfeint.internal.db.DB;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.ui.WebViewCache;

public abstract class CacheRequest extends BaseRequest {
	private static final String TAG = "CacheRequest";
	private static final String IF_MODIFIED_SINCE = "If-Modified-Since";
	private String key_;
	
	public CacheRequest(String key) {
		key_ = key;
	}
	
	@Override public String method() { return "GET"; }
	@Override protected HttpUriRequest generateRequest() {
		HttpUriRequest req = super.generateRequest();
		String date = getLastModified();
		if (date != null) {
			req.addHeader(IF_MODIFIED_SINCE, date);
		}
		return req;
	}

	private String getLastModified() {
		Cursor result = null;
		String value = null;
		try {
			SQLiteDatabase db = DB.storeHelper.getReadableDatabase();
			String[] key = new String[]{key_};
			result = db.rawQuery("SELECT VALUE FROM store where id=?", key);
			if(result.getCount() > 0) {
				result.moveToFirst();
				value = result.getString(0);
			}
			db.close();
        } catch (SQLiteDiskIOException e) {
            WebViewCache.diskError();
		} catch (Exception e) {
			OFLog.e(TAG, e.getMessage());
		}
		if (result != null) result.close();

		return value;
	}

	private void storeLastModified(String value) {
		if (value == null) return;
		String[] values = new String[] {key_, value};
		try {
			SQLiteDatabase db = DB.storeHelper.getWritableDatabase();
			db.execSQL("INSERT OR REPLACE INTO store VALUES(?, ?)", values);
			db.close();
        } catch (SQLiteDiskIOException e) {
            WebViewCache.diskError();
		} catch (Exception e) {
			OFLog.e(TAG, e.getMessage());
		}
	}
	private static final String LastModified = "Last-Modified";
	
	protected void updateLastModifiedFromResponse(HttpResponse response) {
		Header h = response != null ? response.getFirstHeader(LastModified) : null;
		if (h != null) {
		    storeLastModified(h.getValue());
		}
	}
	
	public void on200Response() {
		updateLastModifiedFromResponse(getResponse());
	}
}
