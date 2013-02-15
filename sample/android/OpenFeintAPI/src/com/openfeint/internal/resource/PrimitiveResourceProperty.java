package com.openfeint.internal.resource;

import java.io.IOException;

import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;

public abstract class PrimitiveResourceProperty extends ResourceProperty {
	abstract public void parse(Resource obj, JsonParser jp) throws JsonParseException, IOException;
	abstract public void generate(Resource obj, JsonGenerator generator, String key) throws JsonGenerationException, IOException;
	abstract public void copy(Resource lhs, Resource rhs);
}
