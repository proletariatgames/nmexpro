package com.openfeint.internal.analytics;

import java.util.Date;

import com.openfeint.api.resource.User;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.analytics.internal.BaseAnalyticsLog;
import com.openfeint.internal.analytics.internal.Client_sdk_AnalyticsDecorator;
import com.openfeint.internal.analytics.internal.EventDecorator;
import com.openfeint.internal.analytics.internal.TimeUtil;

public class SDKAnalyticsLogFactory {

    public static IAnalyticsLogger getNewClientSDKBaseLog(String action) {
        IAnalyticsLogger base = new BaseAnalyticsLog();
        // sdk
        IAnalyticsLogger sdk = new Client_sdk_AnalyticsDecorator(base);
        IAnalyticsLogger event = new EventDecorator(sdk);
        addBasicEvent(event);
        event.makeEvent("action", action);
        return event;
    }

    //shared event items.
    public static void addBasicEvent(IAnalyticsLogger event) {
        if (event != null) {
            // gsdi
            event.makeEvent("gsdi", OpenFeintInternal.getInstance().getGSDI());
            // session_id
            event.makeEvent("session_id", OpenFeintInternal.getInstance().getSessionID());
            // session_length;
            // fix: the session_length should be in second
            Date date = OpenFeintInternal.getInstance().getSessionStartDate();
            event.makeEvent("session_length", (System.currentTimeMillis() - date.getTime()) / 1000f);

            // user_id:
            User currentUser = OpenFeintInternal.getInstance().getCurrentUser();
            String userId = (currentUser != null) ? currentUser.userID() : "0";
            event.makeEvent("user_id", userId);
            
            long session_play_time_ms = TimeUtil.getAccumulated_ms();
            float session_play_time_second = session_play_time_ms/1000f;
            event.makeEvent("session_play_time", session_play_time_second);
        }
    }

}
