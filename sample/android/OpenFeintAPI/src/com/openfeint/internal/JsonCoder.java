package com.openfeint.internal;

import java.io.IOException;
import java.io.OutputStream;
import java.io.StringWriter;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TimeZone;

import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonEncoding;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonFactory;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParseException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonParser;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonToken;


public class JsonCoder {
	
	private static final String TAG = "JsonCoder";
	
	/**
	 * Generates JSON as a string from an Object.  May return null, if errors were encountered during generation.
	 * @param objectToGenerate Object to generate JSON from.
	 * @return a String that is the JSON representation of the object passed in.
	 */
	public static String generateJson(Object objectToGenerate) {
		StringWriter stringWriter = new StringWriter();
		JsonFactory jsonFactory = new JsonFactory();
		try {
			JsonGenerator jsonGenerator = jsonFactory.createJsonGenerator(stringWriter);
			generate(objectToGenerate, jsonGenerator);
			jsonGenerator.close();
		} catch (Exception exception) {
			OFLog.e(TAG, exception.getMessage());
		    return null;
		}
		return stringWriter.toString();
	}
	
	/**
	 * Generates JSON to an output stream.  Closes the OutputStream when finished with generation.
	 * @param objectToGenerate Object to generate JSON from.
	 * @param output OutputStream to generate JSON to.
	 * @throws IOException
	 */
	public static void generateJson(Object objectToGenerate, OutputStream output) throws IOException {
		JsonFactory jsonFactory = new JsonFactory();
		JsonGenerator jsonGenerator = null;
		try {
			jsonGenerator = jsonFactory.createJsonGenerator(output, JsonEncoding.UTF8);
			generate(objectToGenerate, jsonGenerator);
		} catch (JsonGenerationException jsonException) {
			OFLog.e(TAG, jsonException.getMessage());
		} catch (ClassCastException castException) {
			OFLog.e(TAG, castException.getMessage());
		} finally {
			try { jsonGenerator.close(); } catch (Exception exception) {}
		}
	}
	
	/**
	 * Recursive private method called by generateJson.
	 * @param objectToGenerate the current object we want to generate JSON from.
	 * @param jsonGenerator The stream we're generating JSON to.
	 * @throws IOException Not likely unless jsonGenerator is streaming to disk and you run out of space.
	 * @throws ClassCastException if the structure of objectToGenerate is not something we can generate JSON from.
	 */
	@SuppressWarnings("unchecked")
	private static void generate(Object objectToGenerate, JsonGenerator jsonGenerator) throws IOException, ClassCastException {
		if (null == objectToGenerate) {
			jsonGenerator.writeNull();
		}else if(objectToGenerate instanceof Date){
		    jsonGenerator.writeString(makeDateParser().format(objectToGenerate));
		}
		else if (objectToGenerate instanceof String) {
			jsonGenerator.writeString((String)objectToGenerate);
		} else if (objectToGenerate instanceof Map<?,?>) {
			jsonGenerator.writeStartObject();
			Map<String,Object> objectAsMap = (Map<String,Object>)objectToGenerate;
			for (String fieldName : objectAsMap.keySet()) {
				jsonGenerator.writeFieldName(fieldName);
				generate(objectAsMap.get(fieldName), jsonGenerator);
			}
			jsonGenerator.writeEndObject();
		} else if (objectToGenerate instanceof List<?>) {
			jsonGenerator.writeStartArray();
			List<Object> objectAsList = (List<Object>)objectToGenerate;
			for (Object nestedObject : objectAsList) {
				generate(nestedObject, jsonGenerator);
			}
			jsonGenerator.writeEndArray();
		} else if (objectToGenerate instanceof Object[]) {
			jsonGenerator.writeStartArray();
			Object[] objectAsArray = (Object[])objectToGenerate;
			for (Object nestedObject : objectAsArray) {
				generate(nestedObject, jsonGenerator);
			}
			jsonGenerator.writeEndArray();
		} else if (objectToGenerate instanceof java.lang.Number) {
			java.lang.Number objectAsNumber = (java.lang.Number)objectToGenerate;
			// Thanks, static type system
			if (objectAsNumber instanceof java.lang.Double)  { jsonGenerator.writeNumber(objectAsNumber.doubleValue()); return; }
			if (objectAsNumber instanceof java.lang.Float)   { jsonGenerator.writeNumber(objectAsNumber.floatValue()); return; }
			if (objectAsNumber instanceof java.lang.Integer) { jsonGenerator.writeNumber(objectAsNumber.intValue()); return; }
			if (objectAsNumber instanceof java.lang.Long)    { jsonGenerator.writeNumber(objectAsNumber.longValue()); return; }
			if (objectAsNumber instanceof java.lang.Byte)    { jsonGenerator.writeNumber(objectAsNumber.longValue()); return; }
			if (objectAsNumber instanceof java.lang.Short)   { jsonGenerator.writeNumber(objectAsNumber.longValue()); return; }
			throw new JsonGenerationException("Unhandled number type " + objectAsNumber.getClass().getCanonicalName());
		
		} else if (objectToGenerate instanceof java.lang.Boolean){
		    jsonGenerator.writeBoolean((Boolean) objectToGenerate); 
		}
		else {
			throw new JsonGenerationException("Can't generate JSON for object of class " + objectToGenerate.getClass().getCanonicalName());
		}
	}
	
	static DateFormat makeDateParser() {
        /**
         * add by chengc , parse the Zulu Date
         */
        DateFormat p = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss'Z'");
        p.setTimeZone(TimeZone.getTimeZone("Zulu"));
        return p;
    }
	
	/**
	 * Takes JSON as a string, parses it, and returns an Object (which may be hierarchical).
	 * @param json The JSON string we want to parse.
	 * @return an Object representation of json.
	 */
	public static Object parse(String json) {
		try {
			JsonParser jsonParser = new JsonFactory().createJsonParser(json);
			jsonParser.nextToken(); // parse assumes we've primed a token to getCurrentToken()
			return parse(jsonParser);
		} catch (IOException ioException) {
			OFLog.e(TAG, ioException.getMessage());
		}
		
		return null;
	}
	
	/**
	 * Takes JSON as a byte array (UTF-8 encoded please), parses it, and returns an Object (which may be hierarchical).
	 * @param data The JSON string, as UTF-8 bytes, that we want to parse.
	 * @return an Object representation of data.
	 */
	public static Object parse(byte data[]) {
		try {
			JsonParser jsonParser = new JsonFactory().createJsonParser(data);
			jsonParser.nextToken(); // parse assumes we've primed a token to getCurrentToken()
			return parse(jsonParser);
		} catch (IOException ioException) {
			OFLog.e(TAG, ioException.getMessage());
		}
		
		return null;
	}
	
	/**
	 * A recursive private method called by parse.
	 * @param jsonParser The parser stream.
	 * @return an Object representation of the current item of jsonParser.
	 * @throws IOException if we fail to read from jsonParser.
	 * @throws JsonParseException if jsonParser contains non-JSON.
	 */
	private static Object parse(JsonParser jsonParser) throws IOException, JsonParseException {
		final JsonToken currToken = jsonParser.getCurrentToken();
		if (JsonToken.START_ARRAY == currToken) {
			ArrayList<Object> listToReturn = new ArrayList<Object>();
			while (jsonParser.nextToken() != JsonToken.END_ARRAY) {
				listToReturn.add(parse(jsonParser));
			}
			return listToReturn;
		} else if (JsonToken.START_OBJECT == currToken) {
			HashMap<String,Object> mapToReturn = new HashMap<String, Object>();
			while (jsonParser.nextToken() == JsonToken.FIELD_NAME) {
				final String fieldName = jsonParser.getCurrentName();
				jsonParser.nextToken();
				final Object fieldValue = parse(jsonParser);
				mapToReturn.put(fieldName, fieldValue);
			}
			if (jsonParser.getCurrentToken() != JsonToken.END_OBJECT) throw new JsonParseException ("Garbage in object", jsonParser.getCurrentLocation());
			return mapToReturn;
		} else if (JsonToken.VALUE_FALSE == currToken) {
			return new Boolean(false);
		} else if (JsonToken.VALUE_TRUE == currToken) {
			return new Boolean(true);
		} else if (JsonToken.VALUE_NULL == currToken) {
			return null; // hmm
		} else if (JsonToken.VALUE_NUMBER_FLOAT == currToken) {
			return new Double(jsonParser.getDoubleValue());
		} else if (JsonToken.VALUE_NUMBER_INT == currToken) {
			return new Long(jsonParser.getLongValue());
		} else if (JsonToken.VALUE_STRING == currToken) {
			return jsonParser.getText();
		} 
		OFLog.e(TAG, " no idea dude "+jsonParser.getText());
		return null;
	}
}
