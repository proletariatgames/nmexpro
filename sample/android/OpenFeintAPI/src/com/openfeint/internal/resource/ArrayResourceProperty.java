package com.openfeint.internal.resource;

import java.util.List;

public abstract class ArrayResourceProperty extends ResourceProperty {
	private Class<? extends Resource> mElementType;
	public ArrayResourceProperty(Class<? extends Resource> elementType) {
		mElementType = elementType;
	}
	public Class<? extends Resource> elementType() {
		return mElementType;
	}
	public abstract void set(Resource obj, List<?> vals);
	public abstract List<? extends Resource> get(Resource obj);
}
