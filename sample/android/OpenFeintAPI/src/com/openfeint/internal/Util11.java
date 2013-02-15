package com.openfeint.internal;

import java.lang.reflect.Field;

import android.content.Context;
import android.content.res.Configuration;

/*
 * Class to store code will call sdk 11 or above.  This uses reflection, so it should build cleanly on
 * all SDKs back to 1.6.
 */
public class Util11 {
    public static boolean isPad(Context ctx) {
        try {
            Class<?> configuration = Configuration.class;
            Field f = configuration.getField("SCREENLAYOUT_SIZE_XLARGE");
            int mask = f.getInt(null);
            return (ctx.getResources().getConfiguration().screenLayout & mask) == mask;
        } catch (Exception e) {
        }
        return false;
    }
}
