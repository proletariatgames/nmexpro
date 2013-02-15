package com.openfeint.internal;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

import com.openfeint.internal.logcat.OFLog;

import com.openfeint.internal.resource.ArrayResourceProperty;
import com.openfeint.internal.resource.HashIntResourceProperty;
import com.openfeint.internal.resource.NestedResourceProperty;
import com.openfeint.internal.resource.PrimitiveResourceProperty;
import com.openfeint.internal.resource.Resource;
import com.openfeint.internal.resource.ResourceClass;
import com.openfeint.internal.resource.ResourceProperty;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonToken;

public class JsonResourceParser {
	private static final String TAG = "JsonResourceParser";
	private JsonParser mParser;
	
	public JsonResourceParser(JsonParser parser) {
		mParser = parser;
	}
	
	public Object parse() throws JsonParseException, IOException
	{
		JsonToken firstTok = mParser.nextToken();
		if (firstTok == null) {
			// this is like, head :created, that's cool.
			// Shouldn't affect our status code.
			return null;
		}
		
		if (firstTok != JsonToken.START_OBJECT) throw new JsonParseException("Couldn't find toplevel wrapper object.", mParser.getTokenLocation());
		if (mParser.nextToken() != JsonToken.FIELD_NAME) throw new JsonParseException("Couldn't find toplevel wrapper object.", mParser.getTokenLocation());
		String classOrArrayName = mParser.getText();
		
		Object rv = null;
		
		JsonToken tok = mParser.nextToken();
		if (tok == JsonToken.START_ARRAY) {
			// just a top-level resources array.
			rv = parseOpenedArray();
		} else if (tok == JsonToken.START_OBJECT) {
			// a singular resource.
			ResourceClass klass = Resource.getKlass(classOrArrayName);
			if (klass == null) throw new JsonParseException("Unknown toplevel class '"+classOrArrayName+"'.", mParser.getTokenLocation());
			rv = parseOpenedResource(klass);
		} else {
			throw new JsonParseException("Expected object or array at top level.", mParser.getTokenLocation());
		}
		
		if (mParser.nextToken() != JsonToken.END_OBJECT) throw new JsonParseException("Expected only one k/v in toplevel wrapper object.", mParser.getTokenLocation());
		
		return rv;
	}

	public Object parse(ResourceClass resourceClass) throws JsonParseException, IOException
    {
        JsonToken firstTok = mParser.nextToken();
        if (firstTok == null) {
            // this is like, head :created, that's cool.
            // Shouldn't affect our status code.
            return null;
        }
        
        if (firstTok != JsonToken.START_OBJECT) throw new JsonParseException("Couldn't find toplevel wrapper object.", mParser.getTokenLocation());
        return parseOpenedResource(resourceClass);
    }

	private Resource parseResource(ResourceClass resourceClass)
			throws JsonParseException, IOException {

		JsonToken tok = mParser.nextToken();
		if (tok == JsonToken.VALUE_NULL) return null;
		
		if (tok != JsonToken.START_OBJECT)
			throw new JsonParseException("Expected START_OBJECT of " + resourceClass.mResourceName, mParser.getCurrentLocation());
		
		return parseOpenedResource(resourceClass);
	}

	private Resource parseOpenedResource(ResourceClass resourceClass)
			throws JsonParseException, IOException {
		Resource resource = resourceClass.factory();

		while (mParser.nextToken() == JsonToken.FIELD_NAME) {
			String name = mParser.getText();
			ResourceProperty prop = resourceClass.mProperties.get(name);
			if (prop == null) {
				// Unknown property
				mParser.nextToken();
				mParser.skipChildren();
			} else if (prop instanceof PrimitiveResourceProperty) {
				PrimitiveResourceProperty pprop = (PrimitiveResourceProperty)prop;
				mParser.nextToken();
				pprop.parse(resource, mParser);
			} else if (prop instanceof NestedResourceProperty) {
				NestedResourceProperty nprop = (NestedResourceProperty)prop;
				ResourceClass rc = Resource.getKlass(nprop.getType());
				if (rc != null) {
				    nprop.set(resource, parseResource(rc));
				} else {
					OFLog.e(TAG, "unknown " + nprop.getType());
				}
			} else if (prop instanceof ArrayResourceProperty) {
				ArrayResourceProperty aprop = (ArrayResourceProperty)prop;
				aprop.set(resource, parseArray());
			} else if (prop instanceof HashIntResourceProperty) {
			    HashIntResourceProperty hprop = (HashIntResourceProperty)prop;
                hprop.set(resource, parseHash());
			} else {
				OFLog.e(TAG, "Totally don't know what to do about this property");
				mParser.skipChildren();
			}
		}
		
		if (mParser.getCurrentToken() != JsonToken.END_OBJECT)
			throw new JsonParseException("Expected END_OBJECT of " + resourceClass.mResourceName, mParser.getCurrentLocation());

		return resource;
	}
	
    private HashMap<String, Integer> parseHash() throws JsonParseException, IOException {
        JsonToken tok = mParser.nextToken();
        if (tok == JsonToken.VALUE_NULL) return null;
        if (tok != JsonToken.START_OBJECT)
            throw new JsonParseException("Expected START_OBJECT", mParser.getCurrentLocation());
        return parseOpenedHash();
    }

    private HashMap<String, Integer> parseOpenedHash() throws JsonParseException, IOException {
        HashMap<String, Integer> resources = new HashMap<String, Integer>();

        while (mParser.nextToken() == JsonToken.FIELD_NAME) {
            String className = mParser.getText();
            mParser.nextToken();
            int v = mParser.getIntValue();
            resources.put(className, v);
        }
        return resources;
    }

    private Resource parseResource() throws JsonParseException, IOException {
		if (mParser.nextToken() != JsonToken.FIELD_NAME) throw new JsonParseException("Couldn't find wrapper object.", mParser.getTokenLocation());
		String className = mParser.getText();
		ResourceClass klass = Resource.getKlass(className);
		if (klass == null) throw new JsonParseException("Don't know class '"+className+"'.", mParser.getTokenLocation());
		Resource rv = parseResource(klass);
		if (mParser.nextToken() != JsonToken.END_OBJECT) throw new JsonParseException("Expected only one k/v in wrapper object.", mParser.getTokenLocation());
		return rv;
	}

	private ArrayList<Resource> parseArray()
			throws JsonParseException, IOException {
		JsonToken tok = mParser.nextToken();
		
		if (tok == JsonToken.VALUE_NULL) return null;
		
		if (tok != JsonToken.START_ARRAY) {
			throw new JsonParseException("Wanted START_ARRAY", mParser.getCurrentLocation());
		}
		
		return parseOpenedArray();
	}

	private ArrayList<Resource> parseOpenedArray()
			throws JsonParseException, IOException {
		ArrayList<Resource> resources = new ArrayList<Resource>();

		while (mParser.nextToken() != JsonToken.END_ARRAY) {
			resources.add(parseResource());
		}

		return resources;
	}
}
