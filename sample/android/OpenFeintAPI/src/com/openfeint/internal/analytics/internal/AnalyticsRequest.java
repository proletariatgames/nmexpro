package com.openfeint.internal.analytics.internal;

import com.openfeint.internal.analytics.AnalyticsManager;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.request.BaseRequest;
import com.openfeint.internal.request.OrderedArgList;

public class AnalyticsRequest extends BaseRequest {
    Long startid;
    Long endid;
    public final String tag = "AnalyticsRequest";

    public AnalyticsRequest(Long startid, Long endid, OrderedArgList arg) {
        super(arg);
        this.startid = startid;
        this.endid = endid;
    }

    @Override
    public String method() {
        return "POST";
    }

    @Override
    public String path() {
        return "/xp/events";
    }

    @Override
    public void onResponse(int responseCode, byte[] body) {
        OFLog.v(tag, "ResponseCode:" + responseCode);
        if (200 <= responseCode && responseCode < 300) {

            OFLog.d(tag, String.format("push log num form %d to %d, Success!", startid, endid));
            AnalyticsManager.instance().deleteLog(startid, endid);
            AnalyticsManager.instance().unlock();
        } else {
            OFLog.w(tag, String.format("push log num form %d to %d, Failed!", startid, endid));
            AnalyticsManager.instance().unlock();
        }
    }
}