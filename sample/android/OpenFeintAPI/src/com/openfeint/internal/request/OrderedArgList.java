package com.openfeint.internal.request;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.openfeint.internal.vendor.com.google.api.client.escape.PercentEscaper;

public class OrderedArgList {

	ArrayList<NameValuePair> mArgs;
	
	public OrderedArgList() {
		mArgs = new ArrayList<NameValuePair>();
	}
	
	public NameValuePair remove(String key) {
		for (NameValuePair p : mArgs) {
			if (p.getName().equals(key)) {
				mArgs.remove(p);
				return p;
			}
		}
		return null;
	}
	
	public OrderedArgList(Map<String,Object> args) {
		mArgs = new ArrayList<NameValuePair>();
		accumulate(args, null);
	}

	public OrderedArgList(JSONObject j) {
		mArgs = new ArrayList<NameValuePair>();
		try {
			accumulate(j, null);
		} catch (JSONException e) {
		}
	}
	
	public OrderedArgList(OrderedArgList rhs) {
		mArgs = new ArrayList<NameValuePair>();
		mArgs.addAll(rhs.getArgs());
	}

	public List<NameValuePair> getArgs() {
		return mArgs;
	}
	
	public List<NameValuePair> getArgsSorted() {
		List<NameValuePair> s = new ArrayList<NameValuePair>();
		s.addAll(mArgs);
		Collections.sort(s, new NVPComparator());
		return s;
	}
	
	public void put(String k, String v) {
		mArgs.add(new BasicNameValuePair(k,v));
	}
	
	public String getArgString() {
		return getArgString(getArgs());
	}
	
	public String getArgStringSorted() {
		return getArgString(getArgsSorted());
	}
	
	private static String getArgString(List<NameValuePair> pairs) {
		StringBuilder accumulator = null;
		PercentEscaper escaper = new PercentEscaper(PercentEscaper.SAFECHARS_URLENCODER, true);

		for (NameValuePair nvp : pairs) {
			if (accumulator == null) {
				accumulator = new StringBuilder();
			} else {
				accumulator.append('&');
			}

			accumulator.append(escaper.escape(nvp.getName()));
			accumulator.append('=');
			if (nvp.getValue() != null) { accumulator.append(escaper.escape(nvp.getValue())); }
		}

		return accumulator == null ? null : accumulator.toString();
	}
	
	private void accumulate(final JSONArray jsonArray, final String fieldName) throws JSONException {
		final int size = jsonArray.length();
		for (int arrayIndex=0; arrayIndex<size; ++arrayIndex) {
			Object arrayEntry = jsonArray.get(arrayIndex);
			if (arrayEntry instanceof JSONObject) {
				accumulate((JSONObject)arrayEntry, fieldName);
			} else if (arrayEntry instanceof JSONArray) { 
				accumulate((JSONArray)arrayEntry, fieldName);
			} else {
				put(fieldName, arrayEntry.toString());
			}
		}
	}
	
	private void accumulate(final JSONObject jsonObject, final String prefix) throws JSONException {
		final Iterable<String> objectIteratable = new Iterable<String>() {
			@SuppressWarnings("unchecked")
			@Override
			public Iterator<String> iterator() {
				return jsonObject.keys();
			}
		};
		for (String fieldName : objectIteratable) {
			Object fieldObject = jsonObject.get(fieldName);
			String subKey = prefix == null ? fieldName : prefix + "[" + fieldName + "]";
			if (fieldObject instanceof JSONObject) {
				accumulate((JSONObject)fieldObject, subKey);
			} else if (fieldObject instanceof JSONArray) { 
				accumulate((JSONArray)fieldObject, subKey);
			} else {
				put(subKey, fieldObject.toString());
			}
		}
	}
	
	private void accumulate(final Map<String, Object> args, final String prefix) {
		for (Map.Entry<String,Object> me : args.entrySet()) {
			final String k = me.getKey();
			final Object v = me.getValue();

			// not handling arrays right now.
			String subKey = prefix == null ? k : prefix + "[" + k + "]";
			if (v instanceof Map<?,?>) {
				accumulate(stringObjectMap(v), subKey);
			} else {
				put(subKey, v.toString());
			}
		}
	}

	@SuppressWarnings("unchecked")
	final private Map<String, Object> stringObjectMap(final Object v) {
		return (Map<String,Object>)v;
	}

	static class NVPComparator implements Comparator<NameValuePair> {

	    @Override
	    public int compare(NameValuePair a, NameValuePair b) {
	        int r = a.getName().compareTo(b.getName());
	        if (r == 0) {
	            return a.getValue().compareTo(b.getValue());
	        }
	        return r;
	    }
	}
};

