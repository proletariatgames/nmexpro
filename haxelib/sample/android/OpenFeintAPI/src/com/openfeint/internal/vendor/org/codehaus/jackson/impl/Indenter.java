/*
 * This file modified by Aurora Feint solely for the purpose of moving it
 * into the com.openfeint.internal.vendor package hierarchy.  No copyright
 * is claimed on this modification; and this file retains its original
 * License, as described below.
 */

package com.openfeint.internal.vendor.org.codehaus.jackson.impl;

import java.io.IOException;

import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerationException;
import com.openfeint.internal.vendor.org.codehaus.jackson.JsonGenerator;

/**
 * Interface that defines objects that can produce indentation used
 * to separate object entries and array values. Indentation in this
 * context just means insertion of white space, independent of whether
 * linefeeds are output.
 */
public interface Indenter
{
    public void writeIndentation(JsonGenerator jg, int level)
        throws IOException, JsonGenerationException;

    /**
     * @return True if indenter is considered inline (does not add linefeeds),
     *   false otherwise
     */
    public boolean isInline();
}
