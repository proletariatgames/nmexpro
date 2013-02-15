package com.openfeint.internal.db;

import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

/**
 * A helper class to open sqlite db on sdcard
 */
public abstract class SQLiteOpenHelperX {
    private static final String TAG = SQLiteOpenHelperX.class.getSimpleName();
    private String mName;
    private int mNewVersion;
    private SQLiteOpenHelper mHelper;
    private SQLiteDatabase mDatabase = null;

    public SQLiteOpenHelperX(String path, int version) {
        if (version < 1) throw new IllegalArgumentException("Version must be >= 1, was " + version);
        mName = path;
        mNewVersion = version;
    }
    
    public SQLiteOpenHelperX(SQLiteOpenHelper helper) {
    	mHelper = helper;
    }

    public void setSQLiteOpenHelper(String path, int version) {
        if (version < 1) throw new IllegalArgumentException("Version must be >= 1, was " + version);
        mName = path;
        mNewVersion = version;
        close();
    }
 
    public void setSQLiteOpenHelper(SQLiteOpenHelper helper) {
    	mHelper = helper;
    	close();
    }

    /**
     * Create and/or open a database that will be used for reading and writing.
     * Once opened successfully, the database is cached, so you can call this
     * method every time you need to write to the database.  Make sure to call
     * {@link #close} when you no longer need it.
     *
     * <p>Errors such as bad permissions or a full disk may cause this operation
     * to fail, but future attempts may succeed if the problem is fixed.</p>
     *
     * @throws SQLiteException if the database cannot be opened for writing
     * @return a read/write database object valid until {@link #close} is called
     */
    public synchronized SQLiteDatabase getWritableDatabase() {
    	if (mHelper != null) {
    		return mHelper.getWritableDatabase();
    	}
        if (mDatabase != null && mDatabase.isOpen() && !mDatabase.isReadOnly()) {
            return mDatabase;  // The database is already open for business
        }
        boolean success = false;
        SQLiteDatabase db = null;
        try {
            db = SQLiteDatabase.openOrCreateDatabase(mName, null);

            int version = db.getVersion();
            if (version != mNewVersion) {
                db.beginTransaction();
                try {
                    if (version == 0) {
                        onCreate(db);
                    } else {
                        onUpgrade(db, version, mNewVersion);
                    }
                    db.setVersion(mNewVersion);
                    db.setTransactionSuccessful();
                } finally {
                    db.endTransaction();
                }
            }
            success = true;
            return db;
        } finally {
            if (success) {
                if (mDatabase != null) {
                    try { mDatabase.close(); } catch (Exception e) { }
                }
                mDatabase = db;
            } else {
                if (db != null) db.close();
            }
        }
    }

    /**
     * Create and/or open a database.  This will be the same object returned by
     * {@link #getWritableDatabase} unless some problem, such as a full disk,
     * requires the database to be opened read-only.  In that case, a read-only
     * database object will be returned.  If the problem is fixed, a future call
     * to {@link #getWritableDatabase} may succeed, in which case the read-only
     * database object will be closed and the read/write object will be returned
     * in the future.
     *
     * @throws SQLiteException if the database cannot be opened
     * @return a database object valid until {@link #getWritableDatabase}
     *     or {@link #close} is called.
     */
    public synchronized SQLiteDatabase getReadableDatabase() {
    	if (mHelper != null) {
    		return mHelper.getReadableDatabase();
    	}
        if (mDatabase != null && mDatabase.isOpen()) {
            return mDatabase;  // The database is already open for business
        }

        try {
            return getWritableDatabase();
        } catch (SQLiteException e) {
            if (mName == null) throw e;  // Can't open a temp database read-only!
            Log.e(TAG, "Couldn't open " + mName + " for writing (will try read-only):", e);
        }

        SQLiteDatabase db = null;
        try {
            db = SQLiteDatabase.openDatabase(mName, null, SQLiteDatabase.OPEN_READONLY);
            if (db.getVersion() != mNewVersion) {
                throw new SQLiteException("Can't upgrade read-only database from version " +
                        db.getVersion() + " to " + mNewVersion + ": " + mName);
            }

            Log.w(TAG, "Opened " + mName + " in read-only mode");
            mDatabase = db;
            return mDatabase;
        } finally {
            if (db != null && db != mDatabase) db.close();
        }
    }

    /**
     * Close any open database object.
     */
    public synchronized void close() {
        if (mDatabase != null && mDatabase.isOpen()) {
            mDatabase.close();
            mDatabase = null;
        }
        if (mHelper != null) {
        	mHelper.close();
        }
    }

    public abstract void onCreate(SQLiteDatabase db);
    public abstract void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion);

}
