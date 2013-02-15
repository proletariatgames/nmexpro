package com.openfeint.internal;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Map;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;

import com.openfeint.api.ui.Dashboard;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.ui.Settings;

public class BaseActionInvoker {

    private static final String TAG = "BaseActionInvoker";

    public BaseActionInvoker() {
        super();
    }

    public void login(Object args, Context ctx) {
        OpenFeintInternal.getInstance().launchIntroFlow(false);
    }

    public void dashboard(Object args, Context ctx) {
        Dashboard.openPath((String)args);
    }

    public void settings(Object args, Context ctx) {
        Settings.open((String)args);
    }

    @SuppressWarnings("unchecked")
    public void intent(Object args, Context ctx) throws Exception {
        Map<String,Object> params = (Map<String,Object>)args;
        Intent i = new Intent();

        String actionType = (String) params.get("action");
        if (actionType != null) {
            Class<?> intentClass = Intent.class;
            Field f = intentClass.getField(actionType);
            if(f!=null){
                Object o = f.get(null);
                i.setAction((String)o);
            }
        } 
        // if uri is null ,then should not trigger View
        String uri = (String) params.get("uri");
        if (uri != null) {
            Uri parsedUri = Uri.parse(uri);
            if (parsedUri != null) {
                if (i.getAction() == null) {
                    i.setAction(Intent.ACTION_VIEW);
                    i.setData(parsedUri);
                }
            } else {
                throw new Exception(String.format("parse url:{%s} failed", uri));
            }
        }
        else 
            throw new Exception("url is null");;

        i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        
        Map<String, Object> extras = (Map<String,Object>)params.get("extras");
        if (extras != null) {
            for (String k : extras.keySet()) {
                // super ugh
                Object o = extras.get(k);
                if (o instanceof String) {
                    i.putExtra(k, (String)o);
                } else if (o instanceof Number) {
                    i.putExtra(k, ((Number) o).intValue());
                }
            }
        }
        ctx.startActivity(i);
    }

    public final void invokeAction(Map<String, Object> action, Context ctx) {
        try {
            if(action==null){
                //here is the null protection.
                OFLog.w(TAG, "action to invoke is null");
                return;
            }
            for (String actionKey : action.keySet()) {
                Object args = action.get(actionKey);
                final Class<? extends BaseActionInvoker> thisClass = this.getClass();
                Method m = thisClass.getMethod(actionKey, Object.class, Context.class);
                if (m != null) {
                    m.invoke(this, args, ctx);
                }else
                    OFLog.d(TAG, "method is null");
            }
        } catch (Exception e) {
            OFLog.e(TAG, "Error invoking action: " + action.toString() + e.getMessage());
        }
    }

}
