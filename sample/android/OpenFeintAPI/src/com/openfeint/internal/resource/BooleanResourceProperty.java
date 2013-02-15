package com.openfeint.internal.resource;

import java.io.IOException;

import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonToken;

public abstract class BooleanResourceProperty extends PrimitiveResourceProperty {
	public abstract void set(Resource obj, boolean val);
	public abstract boolean get(Resource obj);

	@Override public void copy(Resource lhs, Resource rhs) {
		set(lhs, get(rhs));
	}

	@Override
	public void parse(Resource obj, JsonParser jp) throws JsonParseException, IOException {
		if (jp.getCurrentToken() == JsonToken.VALUE_TRUE || jp.getText().equalsIgnoreCase("true") || jp.getText().equalsIgnoreCase("1")  || jp.getText().equalsIgnoreCase("YES"))
			set(obj, true);
		else
			set(obj, false);
	}
	
	@Override public void generate(Resource obj, JsonGenerator generator, String key) throws JsonGenerationException, IOException {
        generator.writeFieldName(key);
		generator.writeBoolean(get(obj));
	}

}
