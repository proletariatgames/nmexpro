/*
 * This file modified by Aurora Feint solely for the purpose of moving it
 * into the com.openfeint.internal.vendor package hierarchy.  No copyright
 * is claimed on this modification; and this file retains its original
 * License, as described below.
 */

package com.openfeint.internal.vendor.org.codehaus.jackson;

/**
 * Exception type for parsing problems, used when non-well-formed content
 * (content that does not conform to JSON syntax as per specification)
 * is encountered.
 */
public class JsonParseException
    extends JsonProcessingException
{
	final static long serialVersionUID = 123; // Stupid eclipse...

	public JsonParseException(String msg, JsonLocation loc)
    {
        super(msg, loc);
    }

    public JsonParseException(String msg, JsonLocation loc, Throwable root)
    {
        super(msg, loc, root);
    }
}
