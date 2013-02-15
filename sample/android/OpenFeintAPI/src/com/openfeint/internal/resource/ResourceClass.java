package com.openfeint.internal.resource;

import java.util.HashMap;

public abstract class ResourceClass {
	public Class<? extends Resource> mObjectClass;
	public HashMap<String, ResourceProperty> mProperties;
	public String mResourceName;
	abstract public Resource factory();
	
	private void mixinParentProperties(Class<?> objectClass) {
		if (objectClass != Resource.class) {
			Class<?> superClass = objectClass.getSuperclass();
			// get super first, add our stuff on the way back down.
			mixinParentProperties(superClass);
			
			ResourceClass klass = Resource.getKlass(superClass);
			for (String propName : klass.mProperties.keySet()) {
				mProperties.put(propName, klass.mProperties.get(propName));
			}
		}
	}
	
	public ResourceClass(Class<? extends Resource> objectClass, String resourceName) {
		mObjectClass = objectClass;
		mResourceName = resourceName;
		mProperties = new HashMap<String, ResourceProperty>();
		
		// add properties from parent classes, all the way up to the top.
		mixinParentProperties(objectClass);
	}
}
