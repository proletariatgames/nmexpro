package com.openfeint.internal.resource;

public abstract class NestedResourceProperty extends ResourceProperty {
	private Class<? extends Resource> mType;
	public NestedResourceProperty(Class<? extends Resource> type) {
		mType = type;
	}
	public Class<? extends Resource> getType() {
		return mType;
	}
	public abstract void set(Resource obj, Resource val);
	public abstract Resource get(Resource obj);
}
