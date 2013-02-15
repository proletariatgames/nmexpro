package com.openfeint.internal.analytics.internal;

import java.util.HashMap;
import java.util.Map;

import com.openfeint.internal.analytics.IAnalyticsLogger;

public class BaseAnalyticsLog implements IAnalyticsLogger {

    protected Map<String, Object> base;

    public BaseAnalyticsLog() {
        base = new HashMap<String, Object>();
    }

    @Override
    public Map<String, Object> getMap() {
        return base;
    }

    @Override
    public void makeEvent(String key, Object value) {
        base.put(key, value);
    }

    @Override
    public String getName() {
        return "BaseEventLog";
    }
}
