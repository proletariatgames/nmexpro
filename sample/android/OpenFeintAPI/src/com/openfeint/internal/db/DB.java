package com.openfeint.internal.db;

import java.io.File;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDiskIOException;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteStatement;
import android.os.Environment;

import com.openfeint.internal.Util;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.ui.WebViewCache;

public class DB {
	private static final String TAG = "SQL";
	public static DataStorageHelperX storeHelper;
	
	private static boolean removeDB(Context ctx) {
        if (Util.noSdcardPermission()) {
            return ctx.getDatabasePath(DBNAME).delete();
        }
	    String state = Environment.getExternalStorageState();
	    if (Environment.MEDIA_MOUNTED.equals(state)) {
	    	File sdcard = Environment.getExternalStorageDirectory();
		    File db = new File(sdcard, DBPATH);
		    return db.delete();
		} else {
		    return ctx.getDatabasePath(DBNAME).delete();
		}		
		
	}
	
	public static void createDB(Context ctx) {
        if (Util.noSdcardPermission()) {
            storeHelper = new DataStorageHelperX(ctx);
            return;
        }
	    String state = Environment.getExternalStorageState();
	    if (Environment.MEDIA_MOUNTED.equals(state)) {
	    	File sdcard = Environment.getExternalStorageDirectory();
		    storeHelper = new DataStorageHelperX(sdcard.getAbsolutePath() + DBPATH);
		} else {
			storeHelper = new DataStorageHelperX(ctx);
		}		
	}
	
	public static boolean recover(Context ctx) {
		if (storeHelper != null) {
			storeHelper.close();
		}
		boolean success = removeDB(ctx);
		if (success) {
		    createDB(ctx);
		    success = storeHelper != null;
		}
		return success;
	}
	
	public static void setClientManifestBatch(String paths[], String clientHashes[]) {
		SQLiteDatabase db = null;
		if (paths.length == clientHashes.length) try {
			db = storeHelper.getWritableDatabase();
			SQLiteStatement statement = db.compileStatement("INSERT OR REPLACE INTO manifest(path, hash) VALUES(?,?)");
			db.beginTransaction();
			for (int i=0; i<paths.length; ++i) {
				statement.bindString(1, paths[i]);
				statement.bindString(2, clientHashes[i]);
				statement.execute();
			}
			statement.close();
			db.setTransactionSuccessful();

        } catch (SQLiteDiskIOException e) {
            WebViewCache.diskError();
        } catch (Exception e) {
			OFLog.e(TAG, e.toString());
		} finally {
			try { db.endTransaction(); } catch (Exception e) {}
		}
	}

	public static void setClientManifest(String path, String clientHash) {
		try {
			SQLiteDatabase db = storeHelper.getWritableDatabase();
			db.execSQL("INSERT OR REPLACE INTO manifest(path, hash) VALUES(?,?)", new String[] {path, clientHash});

        } catch (SQLiteDiskIOException e) {
            WebViewCache.diskError();
		} catch (Exception e) {
			OFLog.e(TAG, e.toString());
		}
	}

	public static final String DBNAME = "manifest.db";
	private static final int VERSION = 3;
	private static final String DBPATH = "/openfeint/webui/manifest.db";
	
    private static void onCreate(SQLiteDatabase db) {
    	onUpgrade(db, 0, VERSION);
    }
	
    // NOTE: since this db may live on /sdcard, and old code lives indefinitely in the wild, you must be careful
    // to not change the schema or the semantics of existing tables, and only add new tables to the db.
    // In short, the data needs to remain backwards compatible with old versions of the code.
    private static void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
    	if (oldVersion == 0) {
            db.execSQL("CREATE TABLE IF NOT EXISTS manifest (path TEXT PRIMARY KEY, hash TEXT);");
	        ++oldVersion;
    	}
    	if (oldVersion == 1) {
	        db.execSQL("CREATE TABLE IF NOT EXISTS store (ID TEXT PRIMARY KEY, VALUE TEXT);");
	        ++oldVersion;
    	}
    	if (oldVersion == 2) {
            db.execSQL("CREATE TABLE IF NOT EXISTS server_manifest (path TEXT PRIMARY KEY NOT NULL, hash TEXT DEFAULT NULL, is_global INTEGER DEFAULT 0);");
            db.execSQL("CREATE TABLE IF NOT EXISTS dependencies (path TEXT NOT NULL, has_dependency TEXT NOT NULL);");
	        ++oldVersion;
    	}
    	if (oldVersion != newVersion) 
    	    OFLog.e(TAG, String.format("Unable to upgrade DB from %d to %d.", oldVersion, newVersion));
    }

	public static class DataStorageHelperX extends SQLiteOpenHelperX {
		DataStorageHelperX(Context context) {
	        super(new DataStorageHelper(context));
	    }
		DataStorageHelperX(String path) {
	        super(path, VERSION);
	    }

	    @Override
	    public void onCreate(SQLiteDatabase db) {
	    	DB.onCreate(db);
	    }
	    
	    @Override
	    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
	    	DB.onUpgrade(db, oldVersion, newVersion);
	    }
	}
	
	public static class DataStorageHelper extends SQLiteOpenHelper {

	    DataStorageHelper(Context context) {
	        super(context, DBNAME, null, VERSION);
	    }

	    @Override
	    public void onCreate(SQLiteDatabase db) {
	    	DB.onCreate(db);
	    }
	    
	    @Override
	    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
	    	DB.onUpgrade(db, oldVersion, newVersion);
	    }
	}
}
