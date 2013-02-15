package com.openfeint.internal;

import android.content.res.Resources;

public final class RR {
    private static Resources _resources = null;
    private static final Resources resources() {
        if (_resources == null) {
            _resources = OpenFeintInternal.getInstance().getContext().getResources();
        }
        return _resources;
    }
    
    private static String _packageName = null;
    private static final String packageName() {
        if (_packageName == null) {
            _packageName = OpenFeintInternal.getInstance().getContext().getPackageName();
        }
        return _packageName;
    }
    
    private static final int identifier(String name, String type) {
        return resources().getIdentifier(name, type, packageName());
    }
    
    public static final int string(String name) {
        return identifier(name, "string");
    }
    
    public static final int drawable(String name) {
        return identifier(name, "drawable");
    }
    
    public static final int id(String name) {
        return identifier(name, "id");
    }
    
    public static final int layout(String name) {
        return identifier(name, "layout");
    }
    
    public static final int menu(String name) {
        return identifier(name, "menu");
    }
    
    public static final int style(String name) {
        return identifier(name, "style");
    }
}
