package com.openfeint.internal.analytics.internal;

import java.util.HashMap;
import java.util.Map;

import com.openfeint.internal.analytics.IAnalyticsLogger;

public class Client_sdk_AnalyticsDecorator extends BaseAnalyticsDecorator {
    protected Map<String, Object> client_sdk;

    public Client_sdk_AnalyticsDecorator(IAnalyticsLogger eventLog) {
        super(eventLog);
        client_sdk = new HashMap<String, Object>();
        eventLog.makeEvent("client_sdk", client_sdk);
    }

    @Override
    public Map<String, Object> getMap() {
        return logger.getMap();
    }

    @Override
    public void makeEvent(String key, Object value) {
        client_sdk.put(key, value);
    }

    @Override
    public String getName() {
        return "client_sdk";
    }

}
