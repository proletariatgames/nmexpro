package com.openfeint.internal.eventlog;

import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.analytics.AnalyticsManager;
import com.openfeint.internal.analytics.IAnalyticsLogger;
import com.openfeint.internal.analytics.SDKAnalyticsLogFactory;
import com.openfeint.internal.logcat.OFLog;

public class SDKEventListener implements IEventListener {

    public static String tag = "SDKEventListener";
    private String name;

    public SDKEventListener() {
        name = "SDKEventListener";
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void handleEvent(String eventType, Object value) {
        OFLog.d(tag, "MakeEvent in SDKEventListener:" + eventType);
        // a little bit ugly here
        if (eventType.equals(EventLogDispatcher.NEW_USER)) {
            if (name.equals(value)) {
                OpenFeintInternal.setUserEnableSource("");
            }
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("new_user");
            AnalyticsManager.instance().makelog(event, tag);

        } else if (eventType.equals(EventLogDispatcher.ENABLED_OF)) {
            OFLog.d(tag, "ENABLE OLD USER " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("enabled_of");
            AnalyticsManager.instance().makelog(event, tag);
        } else if (eventType.equals(EventLogDispatcher.PROMPT_ENABLE_OF)) {
            OFLog.d(tag, "PROMPT_ENABLE_OF " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("prompt_enable_of");
            AnalyticsManager.instance().makelog(event, tag);
        } else if (eventType.equals(EventLogDispatcher.ACCEPTED_OF)) {
            OFLog.d(tag, "ACCEPTED_OF " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("accepted_of");
            AnalyticsManager.instance().makelog(event, tag);
        } else if (eventType.equals(EventLogDispatcher.DECLINED_OF)) {
            OFLog.d(tag, "DECLINED_OF " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("declined_of");
            AnalyticsManager.instance().makelog(event, tag);

        }/*  not record dashboard_open and dashboard_close form the sdk level now
        else if (eventType.equals(EventLogDispatcher.DASHBOARD_START)) {
            OFLog.i(tag, "DASHBOARD_START from " + value);
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("dashboard_start");
            AnalyticsManager.instance().makelog(event, tag);
        } else if (eventType.equals(EventLogDispatcher.DASHBOARD_END)) {
            OFLog.i(tag, "DASHBOARD_END from " + value);
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("dashboard_end");
            AnalyticsManager.instance().makelog(event, tag);
        }*/
        else if (eventType.equals(EventLogDispatcher.GAME_START)) {
            OFLog.d(tag, "GAME_START " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("game_launch");
            AnalyticsManager.instance().makelog(event, tag);
        }
        else if (eventType.equals(EventLogDispatcher.GAME_BACKGROUND)) {
            OFLog.d(tag, "GAME_BACKGROUND " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("game_background");
            AnalyticsManager.instance().makelog(event, tag);
        }
        else if (eventType.equals(EventLogDispatcher.GAME_FOREGROUND)) {
            OFLog.d(tag, "GAME_FOREGROUND " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("game_foreground");
            AnalyticsManager.instance().makelog(event, tag);
        }
        else if (eventType.equals(EventLogDispatcher.GAME_EXIT)) {
            OFLog.d(tag, "GAME_EXIT " + (value == null ? "" : "from "+value));
            if (name.equals(value))
                OpenFeintInternal.setUserEnableSource("");
            IAnalyticsLogger event = SDKAnalyticsLogFactory.getNewClientSDKBaseLog("game_exit");
            AnalyticsManager.instance().makelog(event, tag);
        }
    }
}
