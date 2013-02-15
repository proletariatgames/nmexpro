package com.openfeint.internal.resource;

public class ParentalControl extends Resource {

    // Fields
    public boolean enabled;

    // For parser use only.
    public ParentalControl() { }
    
    public static ResourceClass getResourceClass() {
        ResourceClass klass = new ResourceClass (ParentalControl.class, "parental_control") { public Resource factory () { return new ParentalControl (); } };

        klass.mProperties.put("enabled", new BooleanResourceProperty() { public void set(Resource obj, boolean val) { ((ParentalControl)obj).enabled = val; } public boolean get(Resource obj) { return ((ParentalControl)obj).enabled; } });

        return klass;
    }


}
