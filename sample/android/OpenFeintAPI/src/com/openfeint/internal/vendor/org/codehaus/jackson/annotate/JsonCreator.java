/*
 * This file modified by Aurora Feint solely for the purpose of moving it
 * into the com.openfeint.internal.vendor package hierarchy.  No copyright
 * is claimed on this modification; and this file retains its original
 * License, as described below.
 */

package com.openfeint.internal.vendor.org.codehaus.jackson.annotate;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Marker annotation that can be used to define constructors and factory
 * methods as one to use for instantiating new instances of the associated
 * class.
 */
@Target({ElementType.METHOD, ElementType.CONSTRUCTOR})
@Retention(RetentionPolicy.RUNTIME)
@JacksonAnnotation
public @interface JsonCreator
{
    // no values, since there's no property
}
