package com.openfeint.internal.analytics.db;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteDatabase.CursorFactory;

import com.openfeint.internal.logcat.OFLog;

public class AnalyticsDBManager {
    private static final String tag = "AnalyticsDBManager";
    private static final String DATABASE_NAME = "analytics.db";
    private static final String TABLE_NAME = "eventLogs";
    private static final int DATABASE_VERSION = 1;

    public static final String KEY_ID = "log_id";
    public static final String KEY_TIME = "log_time";
    public static final String KEY_JSON = "json";

    private SQLiteDatabase db;
    private DBOpenHelper dbHelper;
    // private Context mContext;

    private static AnalyticsDBManager instance;

    private AnalyticsDBManager(Context context) {
        // this.mContext = context;
        if (dbHelper == null)
            dbHelper = new DBOpenHelper(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    public static AnalyticsDBManager instance(Context context) {
        if (instance == null)
            instance = new AnalyticsDBManager(context);
        return instance;
    }

    // private DBOpenHelper
    private class DBOpenHelper extends SQLiteOpenHelper {

        public DBOpenHelper(Context context, String name, CursorFactory factory, int version) {
            super(context, name, factory, version);
        }

        @Override
        public void onCreate(SQLiteDatabase _db) {
            onUpgrade(_db, 0, DATABASE_VERSION);
        }

        @Override
        public void onUpgrade(SQLiteDatabase _db, int _oldVersion, int _newVersion) {
            if (_oldVersion == 0 && _newVersion == 1) {
                OFLog.i(tag, "Migrating DB form V0 to V1..");
                String V1_DATABASE_CREATE = "create table " + TABLE_NAME + " (" + KEY_ID + " integer primary key autoincrement, " + KEY_TIME + " integer not null, " + KEY_JSON + " text not null " + ");";
                _db.execSQL(V1_DATABASE_CREATE);
                ++_oldVersion;
            }
            if (_oldVersion != _newVersion)
                OFLog.e(tag, String.format("Unable to upgrade DB from %d to %d.", _oldVersion, _newVersion));
            else
                OFLog.i(tag, String.format("Success on upgrade DB from %d to %d.", _oldVersion, _newVersion));
        }
    }

    public void close() {
        OFLog.v(tag, "close db...");
        if (db != null && db.isOpen()) {
            try {
                db.close();
            } catch (Exception e) {
                OFLog.e(tag, "db close failed");
            }
        }
    }

    public void openToWR() {
        OFLog.v(tag, "open db to WR..");
        if (db == null || !db.isOpen()) {
            try {
                db = dbHelper.getWritableDatabase();
            } catch (SQLiteException ex) {
                OFLog.e(tag, "db open failed");
                try {
                    db.close();
                } catch (Exception e) {
                    // just ignore here
                }
            }
        } else {
            OFLog.v(tag, "db already open ");
        }
    }
    
    public void openToRead(){
        OFLog.v(tag, "open db readonly..");
        if (db == null||!db.isOpen()) {
            try {
                db = dbHelper.getWritableDatabase();
            } catch (SQLiteException ex) {
                OFLog.e(tag, "db open failed");
                try{
                db.close();
                }catch(Exception e){
                    //just ignore here
                }
            }
        } else {
            OFLog.v(tag, "db already open ");
        }
    }

    /**
     * Insert the Log
     * 
     * @param achieve
     * @return
     */
    public long insertLog(String log_json) {
        openToWR();
        ContentValues newValues = new ContentValues();
        long now = System.currentTimeMillis();
        newValues.put(KEY_TIME, now);
        newValues.put(KEY_JSON, log_json);
        long success = -1;
        try {
            success = db.insert(TABLE_NAME, null, newValues);
            OFLog.d(tag, "insert " + String.valueOf(success));
        } catch (Exception e) {
            OFLog.e(tag, "insert failed");
        } finally {
            close();
        }
        return success;
    }

    // Remove an achievement based on its index
    public boolean removeLog(long _rowIndex) {
        openToWR();
        boolean success = false;
        try {
            success = db.delete(TABLE_NAME, KEY_ID + "=" + _rowIndex, null) > 0;
            if (success)
                OFLog.d(tag, "removeLog success");
            else
                OFLog.d(tag, "removeLog failed");
        } catch (Exception e) {
            OFLog.e(tag, String.format("remove row %i failed", _rowIndex));
        } finally {
            close();
        }

        return success;
    }
    
    public boolean removeLog(long start_id, long end_id){
        openToWR();
        boolean success = db.delete(TABLE_NAME, KEY_ID + ">=" + start_id + " AND " + KEY_ID + "<=" + end_id, null) > 0;
        if(success)
            OFLog.d(tag, String.format("batch removeLog  success from %d to %d",start_id, end_id));
        else
            OFLog.w(tag, String.format("batch removeLog failed from %d to %d",start_id, end_id));
        close();
        return success;
    }

    public boolean clearValue() {
        return db.delete(TABLE_NAME, KEY_ID + "=*", null) > 0;
    }

    // Update an achievement
    public boolean updateLog(long _rowIndex, String log_json) {
        openToWR();
        ContentValues newValues = new ContentValues();
        newValues.put(KEY_TIME, System.currentTimeMillis());
        newValues.put(KEY_TIME, log_json);

       boolean success = db.update(TABLE_NAME, newValues, KEY_ID + "=" + _rowIndex, null) > 0;
       close();
       return success;
    }

    public List<Map<String, Object>> getAllItems() {
        openToRead();
        final List<Map<String, Object>> listKeyValues = new ArrayList<Map<String, Object>>();
        try {
            Cursor cursor = db.query(TABLE_NAME, null, null, null, null, null, null);
            try {
                cursor.moveToFirst();
                do {
                    Map<String, Object> line = new HashMap<String, Object>(3);
                    Long id = cursor.getLong(cursor.getColumnIndex(AnalyticsDBManager.KEY_ID));
                    line.put(AnalyticsDBManager.KEY_ID, id);
                    Long time = cursor.getLong(cursor.getColumnIndex(AnalyticsDBManager.KEY_TIME));
                    line.put(AnalyticsDBManager.KEY_TIME, time);
                    String json = cursor.getString(cursor.getColumnIndex(AnalyticsDBManager.KEY_JSON));
                    line.put(AnalyticsDBManager.KEY_JSON, json);
                    listKeyValues.add(line);
                } while (cursor.moveToNext());
            }
            catch (Exception e)
            {
                OFLog.e(tag, "Exception in query.");
            }
            finally
            {
                cursor.close();
            }
        }
        catch (Exception e)
        {
            OFLog.e(tag, "Exception creating query.");
        }
        finally
        {
            close();
        }
        return listKeyValues;
    }
}