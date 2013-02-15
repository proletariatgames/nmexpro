package com.openfeint.internal.resource;

import java.util.List;

import com.openfeint.api.resource.User;

public class Device extends Resource {

    // Fields
    public List<User> users;
    public ParentalControl parental_control;

    // For parser use only.
    public Device() { }
    
    public static ResourceClass getResourceClass() {
        ResourceClass klass = new ResourceClass (Device.class, "device") { public Resource factory () { return new Device (); } };

        klass.mProperties.put("users", new ArrayResourceProperty(User.class) { @SuppressWarnings("unchecked") public void set(Resource obj, List<?> vals) { ((Device)obj).users = (List<User>)vals; } public List<? extends Resource> get(Resource obj) { return ((Device)obj).users; } });
        klass.mProperties.put("parental_control", new NestedResourceProperty(ParentalControl.class) { public void set(Resource obj, Resource val) { ((Device)obj).parental_control = (ParentalControl)val; } public Resource get(Resource obj) { return ((Device)obj).parental_control; } });

        return klass;
    }

}
