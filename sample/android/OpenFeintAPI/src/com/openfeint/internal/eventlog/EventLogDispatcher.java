package com.openfeint.internal.eventlog;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import com.openfeint.internal.logcat.OFLog;

public class EventLogDispatcher {
    public static final String tag = "EventLogDispatcher";

    // -- General subject--
    public static final String GAME_START = "game_start.openfeint.com";
    public static final String DASHBOARD_START = "dashboard_start.openfeint.com";
    public static final String DASHBOARD_END = "dashboard_end.openfeint.com";
    public static final String NEW_USER = "new_user.openfeint.com";
    public static final String ENABLED_OF = "enabled_of.openfeint.com";
    public static final String PROMPT_ENABLE_OF = "prompt_enable_of.openfeint.com";
    public static final String ACCEPTED_OF = "accepted_of.openfeint.com";
    public static final String DECLINED_OF = "declined_of.openfeint.com";
    public static final String LOGIN_SUCESS = "login_success.openfeint.com";
    public static final String LOGOUT_SUCESS = "logout_success.openfeint.com";
    public static final String GAME_BACKGROUND = "game_background.openfeint.com";
    public static final String GAME_FOREGROUND = "game_foreground.openfeint.com";
    public static final String GAME_EXIT = "game_exit.openfeint.com";
    
    private Map<String, Map<String, IEventListener>> subscription;

    private EventLogDispatcher() {
        subscription = new HashMap<String, Map<String, IEventListener>>();
    }

    private static EventLogDispatcher instance;

    public static EventLogDispatcher getInstance() {
        if (instance == null)
            instance = new EventLogDispatcher();
        return instance;
    }

    public void postEvent(String type, Object body) {

        if (subscription.containsKey(type)) {
            Map<String, IEventListener> goodListeners = subscription.get(type);
            Iterator<String> itor = goodListeners.keySet().iterator();
            while (itor.hasNext()) {
                String key = itor.next();
                IEventListener listener = goodListeners.get(key);
                OFLog.d(tag, "posteEvent:" + type + " to listener: " + listener.getName());
                listener.handleEvent(type, body);
            }
        }
    }

    public boolean subscribe(String type, IEventListener listener) {

        if (listener == null || listener.getName() == null || type == null)
            return false;
        OFLog.d(tag, "subscribe:" + type + " from: " + listener.getName());
        Map<String, IEventListener> eventMapping = subscription.get(type);
        if (eventMapping == null) {
            eventMapping = new HashMap<String, IEventListener>();
            eventMapping.put(listener.getName(), listener);
        } else {
            eventMapping.put(listener.getName(), listener);
        }
        subscription.put(type, eventMapping);
        return true;
    }

    public boolean unSubscribe(String type, IEventListener listener) {
        if (listener == null || listener.getName() == null || type == null)
            return false;
        OFLog.d(tag, "unsubscribe:" + type + " from: " + listener.getName());
        Map<String, IEventListener> eventMapping = subscription.get(type);
        if (eventMapping == null) {
            // just ok
        } else {
            eventMapping.remove(listener.getName());
        }
        return true;
    }

}
