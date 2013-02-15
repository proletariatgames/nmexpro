package com.openfeint.internal.resource;

import java.util.HashMap;

public abstract class HashIntResourceProperty extends ResourceProperty {

    public abstract HashMap<String, Integer> get(Resource obj);
    public abstract void set(Resource obj, HashMap<String, Integer> vals);
}
