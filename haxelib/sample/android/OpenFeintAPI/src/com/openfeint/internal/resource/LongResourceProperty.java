package com.openfeint.internal.resource;

import java.io.IOException;

import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;

public abstract class LongResourceProperty extends PrimitiveResourceProperty {
	public abstract void set(Resource obj, long val);
	public abstract long get(Resource obj);

	@Override public void copy(Resource lhs, Resource rhs) {
		set(lhs, get(rhs));
	}

	@Override
	public void parse(Resource obj, JsonParser jp) throws JsonParseException, IOException {
		set(obj, jp.getLongValue());
	}

	public void set(Resource obj, String val) {
		set(obj, Long.valueOf(val).longValue());
	}

	@Override public void generate(Resource obj, JsonGenerator generator, String key) throws JsonGenerationException, IOException {
        generator.writeFieldName(key);
		generator.writeNumber(get(obj));
	}
}
