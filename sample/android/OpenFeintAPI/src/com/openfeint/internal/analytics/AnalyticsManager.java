package com.openfeint.internal.analytics;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import android.content.Context;

import com.openfeint.internal.JsonCoder;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.analytics.db.AnalyticsDBManager;
import com.openfeint.internal.analytics.internal.AnalyticsRequest;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.request.OrderedArgList;

public class AnalyticsManager {
    // batch upload number of log using one network request
    private static final int BATCH_UPLOAD_NUM_MAX = 100;
    
    // batch upload default trigger number, could be set through manifest config.
    private static final int DEFALUT_BATCH_UPLOAD_TRIGGER = 10;
    private static int batch_num_trigger;
    private String tag = "AnalyticsManager";
    private Context mContext;
    private int count;
    private static AnalyticsManager instance;
    private String hardware;
    private String client_application_id;
    private String version;
    private String of_version;
    private String os_version;
    private String platform;
    private String locale;
    private String country;
    private boolean waiting;

    
    private Map<String, Object> info;

    private AnalyticsManager(Context context) {
        mContext = context;
        count = 0;
        if (batch_num_trigger == 0) {
            batch_num_trigger = DEFALUT_BATCH_UPLOAD_TRIGGER;
        }
        waiting = false;
        initInfo();
    }
    private void initInfo(){
        info = new HashMap<String, Object>();
        hardware = OpenFeintInternal.getModelString();
        client_application_id = OpenFeintInternal.getInstance().getAppID();
        version = String.valueOf(OpenFeintInternal.getInstance().getAppVersion());
        of_version = OpenFeintInternal.getInstance().getOFVersion();
        os_version = OpenFeintInternal.getOSVersionString();
        platform = "Android";
        locale = OpenFeintInternal.getInstance().getLocaleString();
        country = OpenFeintInternal.getInstance().getCountryString();
        OFLog.d(tag, "hardware:" + hardware);
        OFLog.d(tag, "client_application_id:" + client_application_id);
        OFLog.d(tag, "version:" + version);
        OFLog.d(tag, "of_version:" + of_version);
        OFLog.d(tag, "os_version:" + os_version);
        OFLog.d(tag, "platform:" + platform);
        OFLog.d(tag, "locale:" + locale);
        OFLog.d(tag, "country:" + country);
        info.put("hardware", hardware);
        info.put("client_application_id", client_application_id);
        info.put("version", version);
        info.put("of_version", of_version);
        info.put("os_version", os_version);
        info.put("platform", platform);
        info.put("locale", locale);
        info.put("country", country);
    }

    public static AnalyticsManager instance(Context context) {
        if (instance == null) {
            instance = new AnalyticsManager(context);
        }
        return instance;
    }

    public static AnalyticsManager instance() {
        return instance;
    }
    
    public void makelog(IAnalyticsLogger event,String loggerTag){
        try {
            OFLog.d(loggerTag, "Log:\n" + log_(event));
        } catch (Exception e) {
            OFLog.e(loggerTag, "log save failed"+e.getLocalizedMessage());
        }
    }
   
    public void makelog(IAnalyticsLogger event,String loggerTag, int level){
        try {
            if (level == OFLog.VERBOSE) {
                OFLog.v(loggerTag, "Log:\n" + log_(event));
            }
            else if (level == OFLog.DEBUG) {
                OFLog.d(loggerTag, "Log:\n" + log_(event));
            } else if (level == OFLog.INFO) {
                OFLog.i(loggerTag, "Log:\n" + log_(event));
            }else if (level == OFLog.WARNING){
                OFLog.w(loggerTag, "Log:\n" + log_(event));
            }
            else if (level == OFLog.ERROR) {
                OFLog.e(loggerTag, "Log:\n" + log_(event));
            } 
        } catch (Exception e) {
            OFLog.e(loggerTag, "log save failed"+e.getLocalizedMessage());
        }
    }

    private String log_(IAnalyticsLogger logger) {
        Map<String, Object> o = logger.getMap();
        String _log = JsonCoder.generateJson(o);
        store(_log);
        count++;
        if (count >= batch_num_trigger) {
            OFLog.d(tag, "log batch upload triggered");
            upload();
            count = 0;
        }
        return _log;
    }

    public Map<String, Object> getInfo(){
        if(info==null || info.isEmpty())
            initInfo();
        return info;
    }
    
    public void store(String eventJSON) {
        if (eventJSON == null)
            return;
        AnalyticsDBManager manager = AnalyticsDBManager.instance(mContext);
        manager.insertLog(eventJSON);
    }

    @SuppressWarnings("unchecked")
    public void upload() {
        if(waiting ==true)
        {
            OFLog.d(tag, "Waiting for response,skip upload this time");
            return;
        }
        //lock
        waiting = true;
        List<Map<String, Object>> readyLog = AnalyticsDBManager.instance(mContext).getAllItems();
        int len = readyLog.size();
        Long startid = null;
        Long endid = null;
        Iterator<Map<String, Object>> itor = readyLog.iterator();
        List<Map<String, Object>> array = new ArrayList<Map<String, Object>>(BATCH_UPLOAD_NUM_MAX);
        int count = 0;
        while (itor.hasNext()) {

            Map<String, Object> item = itor.next();
            String logJson = (String) item.get(AnalyticsDBManager.KEY_JSON);
            OFLog.v(tag, logJson);
            OFLog.v(tag, "--------");

            // add time_delta when upload
            Long logTime = (Long) item.get(AnalyticsDBManager.KEY_TIME);
            Long deltaMillis = System.currentTimeMillis() - logTime;
            double deltaSeconds = deltaMillis / 1000.f;

            Map<String, Object> single = (Map<String, Object>) JsonCoder.parse(logJson);
            // There should only be one wrapper, but in order to avoid assuming
            // the name of the wrapper key
            // (could be game_feed, could be client_sdk, etc), we'll loop over
            // the key set.
            for (String wrapperKey : single.keySet()) {
                Map<String, Object> wrapperObject = (Map<String, Object>) single.get(wrapperKey);
                Map<String, Object> event = (Map<String, Object>) wrapperObject.get("event");
                if (event != null) {
                    event.put("time_delta", deltaSeconds);
                }
            }
            // add single log to the array
            array.add(single);
            count++;

            // decide whether to upload
            if (count == 1) {
                // first in the batch
                startid = (Long) item.get(AnalyticsDBManager.KEY_ID);
            }
            if (count == BATCH_UPLOAD_NUM_MAX) {
                // make a request
                endid = (Long) item.get(AnalyticsDBManager.KEY_ID);
                OrderedArgList arguments = new OrderedArgList();

                // prepare the request;
                arguments.put("event", JsonCoder.generateJson(array));
                arguments.put("info",JsonCoder.generateJson(getInfo()));

                // launch the request;
                if (OFLog.willLog(OFLog.DEBUG)) {
                    OFLog.d(tag, String.format("try upload from %d to %d :", startid, endid));
                    OFLog.d(tag,  JsonCoder.generateJson(getInfo()));
                    OFLog.d(tag,  JsonCoder.generateJson(array));
                }

                AnalyticsRequest req = new AnalyticsRequest(startid, endid, arguments);
                req.launch();

                // reset count;
                array = new ArrayList<Map<String, Object>>(BATCH_UPLOAD_NUM_MAX);
                count = 0;
            }
        }//send the rest anyway
        
        if (len > 0) {
            // last batch
            Map<String, Object> item = readyLog.get(len - 1);
            endid = (Long) item.get(AnalyticsDBManager.KEY_ID);
            OrderedArgList arguments = new OrderedArgList();
            // prepare the request;
            arguments.put("event", JsonCoder.generateJson(array));
            arguments.put("info",JsonCoder.generateJson(getInfo()));

            // launch the request;
            OFLog.d(tag, String.format("try upload from %d to %d :", startid, endid));
            OFLog.d(tag,  JsonCoder.generateJson(getInfo()));
            OFLog.d(tag,  JsonCoder.generateJson(array));

            AnalyticsRequest req = new AnalyticsRequest(startid, endid, arguments);
            req.launch();
        }
    }

    public void deleteLog(Long id) {
        AnalyticsDBManager.instance(mContext).removeLog(id);
    }

    public void deleteLog(Long startid, Long endid) {
        AnalyticsDBManager.instance(mContext).removeLog(startid, endid);
    }

    public static void setBatch_num_trigger(int batch_num_trigger) {
        AnalyticsManager.batch_num_trigger = batch_num_trigger;
    }

    public static int getBatch_num_trigger() {
        return batch_num_trigger;
    }
    
    public void unlock(){
        waiting = false;
    }
}
