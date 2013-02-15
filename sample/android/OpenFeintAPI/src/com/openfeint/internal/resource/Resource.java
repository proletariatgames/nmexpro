package com.openfeint.internal.resource;

import java.io.IOException;
import java.io.OutputStream;
import java.io.StringWriter;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.openfeint.api.resource.Achievement;
import com.openfeint.api.resource.CurrentUser;
import com.openfeint.api.resource.Leaderboard;
import com.openfeint.api.resource.Score;
import com.openfeint.api.resource.ServerTimestamp;
import com.openfeint.api.resource.User;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonEncoding;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonFactory;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;

public abstract class Resource {
    private static final String TAG = "Resource";
	String mID;
	
	public String resourceID() { return mID; }
	public void setResourceID(String id) { mID = id; }
	
	private static HashMap<Class<? extends Resource>, ResourceClass> sSubclassMap = new HashMap<Class<? extends Resource>, ResourceClass>();
	private static HashMap<String, ResourceClass> sNameMap = new HashMap<String, ResourceClass>();
	
	public static void registerSubclass(ResourceClass klass) {
		sSubclassMap.put(klass.mObjectClass, klass);
		if (null != klass.mResourceName) {
			sNameMap.put(klass.mResourceName, klass);
		}
	}
	
	public static ResourceClass getKlass(Class<?> subclass) {
		return sSubclassMap.get(subclass);
	}
	
	public static ResourceClass getKlass(String klassName) {
		return sNameMap.get(klassName);
	}
	
	// This guy's a little different: he has no name, and you can never instantiate him.  He's just here for the mixin.
	public static ResourceClass getResourceClass() {
		ResourceClass klass = new ResourceClass (Resource.class, null) { public Resource factory () { return null; } };
		klass.mProperties.put("id", new StringResourceProperty() { public void set(Resource obj, String val) { obj.mID = val; } public String get(Resource obj) { return obj.mID; } });
		return klass;
	}

	public final void generateToStream(OutputStream out) throws IOException {
        JsonFactory jf = new JsonFactory();
        JsonGenerator jg = jf.createJsonGenerator(out, JsonEncoding.UTF8);
        generate(jg);
        jg.close();
	}

	public final String generate() {
		StringWriter sw = new StringWriter();
		JsonFactory jf = new JsonFactory();
		try {
			JsonGenerator jg = jf.createJsonGenerator(sw);
			generate(jg);
			jg.close();
		} catch (IOException e) {
			OFLog.e(TAG, e.getMessage());
		    return null;
		}
		return sw.toString();
	}
	
	public final void generate(JsonGenerator generator) throws JsonGenerationException, IOException {
		ResourceClass rc = getKlass(getClass());
		generator.writeStartObject();
		generator.writeFieldName(rc.mResourceName);
        generator.writeStartObject();
		for(Map.Entry<String,ResourceProperty> e:rc.mProperties.entrySet()) {
			ResourceProperty rp = e.getValue();
			if (rp instanceof PrimitiveResourceProperty) {
                ((PrimitiveResourceProperty)rp).generate(this, generator, e.getKey());
			} else if (rp instanceof ArrayResourceProperty) {
				ArrayResourceProperty arp = (ArrayResourceProperty)rp;
				List<? extends Resource> resources = arp.get(this);
				if (null != resources) {
		            generator.writeFieldName(e.getKey());
					ResourceClass erc = getKlass(arp.elementType());

					generator.writeStartObject();
					generator.writeFieldName(erc.mResourceName + "s");
					generator.writeStartArray();
					
					for (Resource r : resources) {
						r.generate(generator);
					}
					
					generator.writeEndArray();
					generator.writeEndObject();
				}
			} else if (rp instanceof NestedResourceProperty) {
				Resource r = ((NestedResourceProperty)rp).get(this);
				if (null != r) {
                    generator.writeFieldName(e.getKey());
					r.generate(generator);
				}
			} else if (rp instanceof HashIntResourceProperty) {
		         HashMap<String, Integer> r = ((HashIntResourceProperty)rp).get(this);
                 if (null != r && r.size() > 0) {
                     generator.writeFieldName(e.getKey());
                     generator.writeStartObject();
                     for (Map.Entry<String, Integer> entry : r.entrySet()) {
                         generator.writeFieldName(entry.getKey());
                         generator.writeNumber(entry.getValue());
                     }
                     generator.writeEndObject();
                 }
			}
		}
		generator.writeEndObject();
		generator.writeEndObject();
	}
	
	public final void shallowCopy(Resource otherResource) {
		if (otherResource.getClass() != getClass()) {
			throw new UnsupportedOperationException("You can only shallowCopy the same type of resource");
		}

		unguardedShallowCopy(otherResource);
	}
	
	public final void shallowCopyAncestorType(Resource otherResource) {
		Class<?> c = getClass();
		final Class<?> o = otherResource.getClass();
		if (o != Resource.class) {
			while (c != o && c != Resource.class) {
				c = c.getSuperclass();
			}
			if (c == Resource.class) {
				throw new UnsupportedOperationException(o.getName() + " is not a superclass of " + getClass().getName());
			}
		}
		
		unguardedShallowCopy(otherResource);
	}
		
	private final void unguardedShallowCopy(Resource otherResource) {
		ResourceClass rc = getKlass(otherResource.getClass());
		for(Map.Entry<String,ResourceProperty> e:rc.mProperties.entrySet()) {
			ResourceProperty rp = e.getValue();
			if (rp instanceof PrimitiveResourceProperty) {
				((PrimitiveResourceProperty) rp).copy(this, otherResource);
			} else if (rp instanceof ArrayResourceProperty) {
				((ArrayResourceProperty) rp).set(this, ((ArrayResourceProperty) rp).get(otherResource));
			} else if (rp instanceof NestedResourceProperty) {
				((NestedResourceProperty) rp).set(this, ((NestedResourceProperty) rp).get(otherResource));
			}
		}
	}
		
	static {
		// Register all subclasses, for OFX, since it is not in same project
		// all OFX resources will register itself
		registerSubclass(Resource.getResourceClass());
        registerSubclass(ServerException.getResourceClass());
        registerSubclass(Device.getResourceClass());
        registerSubclass(ParentalControl.getResourceClass());
		registerSubclass(ServerTimestamp.getResourceClass());
		registerSubclass(BlobUploadParameters.getResourceClass());

		registerSubclass(Achievement.getResourceClass());
		registerSubclass(Leaderboard.getResourceClass());
		registerSubclass(Score.getResourceClass());
		registerSubclass(User.getResourceClass());
		
		// CurrentUser after User, due to inheritance
		registerSubclass(CurrentUser.getResourceClass());
	
	}
}
