package com.openfeint.internal.eventlog;

public interface IEventListener {
    String getName();

    void handleEvent(String eventType, Object value);
}
