package com.openfeint.internal.analytics.internal;

import java.util.HashMap;
import java.util.Map;

import com.openfeint.internal.analytics.IAnalyticsLogger;

public class EventDecorator extends BaseAnalyticsDecorator {
    protected Map<String, Object> event;

    public EventDecorator(IAnalyticsLogger eventLog) {
        super(eventLog);
        event = new HashMap<String, Object>();

        eventLog.makeEvent("event", event);
    }

    @Override
    public Map<String, Object> getMap() {
        return logger.getMap();
    }

    @Override
    public void makeEvent(String key, Object value) {
        event.put(key, value);
    }

    @Override
    public String getName() {
        return "EventLogDecorator";
    }

}
