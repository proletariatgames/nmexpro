package com.openfeint.internal.analytics;

import java.util.Map;

public interface IAnalyticsLogger {
    String getName();
    
    //retrieve the log item
    Map<String, Object> getMap();
    
    //add the log item
    void makeEvent(String key, Object value);
}
