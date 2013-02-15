package com.openfeint.internal.resource;

import java.io.IOException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;

public abstract class DateResourceProperty extends PrimitiveResourceProperty {
	public abstract void set(Resource obj, Date val);
	public abstract Date get(Resource obj);

	@Override public void copy(Resource lhs, Resource rhs) {
		set(lhs, get(rhs));
	}

	static public DateFormat sDateParser = makeDateParser();
	
	static DateFormat makeDateParser()
	{ 
		DateFormat p = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		p.setTimeZone(TimeZone.getTimeZone("UTC"));
		return p;
	}

	@Override
	public void parse(Resource obj, JsonParser jp) throws JsonParseException, IOException {
		final String text = jp.getText();
		if (text.equals("null")) {
			set(obj, null);
		} else try {
			set(obj, sDateParser.parse(text));
		} catch (ParseException e) {
			set(obj, null);
		}
	}
	
	@Override public void generate(Resource obj, JsonGenerator generator, String key) throws JsonGenerationException, IOException {
		Date o = get(obj);
		if (null != o) {
            generator.writeFieldName(key);
			generator.writeString(sDateParser.format(o));
		}
	}
}
