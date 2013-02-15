/*
 * This file modified by Aurora Feint solely for the purpose of moving it
 * into the com.openfeint.internal.vendor package hierarchy.  No copyright
 * is claimed on this modification; and this file retains its original
 * License, as described below.
 */

package com.openfeint.internal.vendor.org.codehaus.jackson;

/**
 * Exception type for exceptions during JSON writing, such as trying
 * to output  content in wrong context (non-matching end-array or end-object,
 * for example).
 */
public class JsonGenerationException
    extends JsonProcessingException
{
    final static long serialVersionUID = 123; // Stupid eclipse...
    
    public JsonGenerationException(Throwable rootCause)
    {
        super(rootCause);
    }

    public JsonGenerationException(String msg)
    {
        super(msg, (JsonLocation)null);
    }

    public JsonGenerationException(String msg, Throwable rootCause)
    {
        super(msg, (JsonLocation)null, rootCause);
    }
}
