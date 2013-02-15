package com.openfeint.internal.logcat;

import android.util.Log;

public class OFLog {

    /*
     * ERROR = 6 
     * WARNING = 5 
     * INFO = 4 
     * DEBUG = 3 
     * VERBOSE = 2
     */
    public static final int ERROR = 6;
    public static final int WARNING = 5;
    public static final int INFO = 4;
    public static final int DEBUG = 3;
    public static final int VERBOSE = 2;
    
    
    public static int LEVEL = 4;

    // The higher LEVEL have, the more strict the policy is.
    // set LEVEL >9, nothing will be log;
    // by default it should be set to 4
    
    /*
     * Return true if the given log level would be logged.
     * Useful for short-circuiting expensive log generation. 
     */
    public static boolean willLog(int logLevel) {
        return LEVEL <= logLevel;
    }

    /*
     * e, just for exception ,error
     */
    public static void e(String tag, String msg) {
        if (LEVEL <= Log.ERROR) {
            Log.e("Openfeint", tag + ':' + (msg != null ? msg : "(null)"));
        }
    }

    /*
     * w, warning may use on corner case happen , or minor error
     */
    public static void w(String tag, String msg) {
        if (LEVEL <= Log.WARN) {
            Log.w("Openfeint", tag + ':' + (msg != null ? msg : "(null)"));
        }
    }

    /*
     * info, critical info that should be log
     */
    public static void i(String tag, String msg) {
        if (LEVEL <= Log.INFO) {
            Log.i("Openfeint", tag + ':' + (msg != null ? msg : "(null)"));
        }
    }

    /*
     * debug , log only for debug, should be disable when launch
     */
    public static void d(String tag, String msg) {
        if (LEVEL <= Log.DEBUG) {
            Log.d("Openfeint", tag + ':' + (msg != null ? msg : "(null)"));
        }
    }

    /*
     * very very noisy
     */

    public static void v(String tag, String msg) {
        if (LEVEL <= Log.VERBOSE) {
            Log.v("Openfeint", tag + ':' + (msg != null ? msg : "(null)"));
        }
    }
}
