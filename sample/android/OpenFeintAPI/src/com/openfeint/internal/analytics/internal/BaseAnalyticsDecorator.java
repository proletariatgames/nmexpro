package com.openfeint.internal.analytics.internal;

import java.util.Map;

import com.openfeint.internal.analytics.IAnalyticsLogger;

abstract public class BaseAnalyticsDecorator implements IAnalyticsLogger {
    protected IAnalyticsLogger logger;

    public BaseAnalyticsDecorator(IAnalyticsLogger logger) {
        this.logger = logger;
    }

    @Override
    public Map<String, Object> getMap() {
        return logger.getMap();
    }

    @Override
    public void makeEvent(String key, Object value) {
        logger.makeEvent(key, value);
    }

}
