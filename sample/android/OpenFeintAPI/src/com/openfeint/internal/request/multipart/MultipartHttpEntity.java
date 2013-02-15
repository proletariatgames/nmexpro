/*
 * $Header: /home/jerenkrantz/tmp/commons/commons-convert/cvs/home/cvs/jakarta-commons//httpclient/src/java/org/apache/commons/httpclient/methods/multipart/MultipartRequestEntity.java,v 1.1 2004/10/06 03:39:59 mbecke Exp $
 * $Revision: 502647 $
 * $Date: 2007-02-02 17:22:54 +0100 (Fri, 02 Feb 2007) $
 *
 * ====================================================================
 *
 *  Licensed to the Apache Software Foundation (ASF) under one or more
 *  contributor license agreements.  See the NOTICE file distributed with
 *  this work for additional information regarding copyright ownership.
 *  The ASF licenses this file to You under the Apache License, Version 2.0
 *  (the "License"); you may not use this file except in compliance with
 *  the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 *
 */

package com.openfeint.internal.request.multipart;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Random;

import org.apache.http.Header;
import org.apache.http.HttpEntity;
import org.apache.http.message.BasicHeader;

import com.openfeint.internal.logcat.OFLog;


/**
 * Implements a request entity suitable for an HTTP multipart POST method.
 * <p>
 * The HTTP multipart POST method is defined in section 3.3 of
 * <a href="http://www.ietf.org/rfc/rfc1867.txt">RFC1867</a>:
 * <blockquote>
 * The media-type multipart/form-data follows the rules of all multipart
 * MIME data streams as outlined in RFC 1521. The multipart/form-data contains 
 * a series of parts. Each part is expected to contain a content-disposition 
 * header where the value is "form-data" and a name attribute specifies 
 * the field name within the form, e.g., 'content-disposition: form-data; 
 * name="xxxxx"', where xxxxx is the field name corresponding to that field.
 * Field names originally in non-ASCII character sets may be encoded using 
 * the method outlined in RFC 1522.
 * </blockquote>
 * </p>
 * <p>This entity is designed to be used in conjunction with the 
 * {@link org.apache.commons.httpclient.methods.PostMethod post method} to provide
 * multipart posts.  Example usage:</p>
 * <pre>
 *  File f = new File("/path/fileToUpload.txt");
 *  PostMethod filePost = new PostMethod("http://host/some_path");
 *  Part[] parts = {
 *      new StringPart("param_name", "value"),
 *      new FilePart(f.getName(), f)
 *  };
 *  filePost.setRequestEntity(
 *      new MultipartRequestEntity(parts, filePost.getParams())
 *      );
 *  HttpClient client = new HttpClient();
 *  int status = client.executeMethod(filePost);
 * </pre>
 * 
 * @since 3.0
 */
public class MultipartHttpEntity implements HttpEntity {

    /** The Content-Type for multipart/form-data. */
    private static final String MULTIPART_FORM_CONTENT_TYPE = "multipart/form-data";

	private static final String TAG = "MultipartRequestEntity";
    
    /**
     * The pool of ASCII chars to be used for generating a multipart boundary.
     */
    private static byte[] MULTIPART_CHARS = EncodingUtil.getAsciiBytes(
        "-_1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    
    /**
     * Generates a random multipart boundary string.
     * @return
     */
    private static byte[] generateMultipartBoundary() {
        Random rand = new Random();
        byte[] bytes = new byte[rand.nextInt(11) + 30]; // a random size from 30 to 40
        for (int i = 0; i < bytes.length; i++) {
            bytes[i] = MULTIPART_CHARS[rand.nextInt(MULTIPART_CHARS.length)];
        }
        return bytes;
    }
    
    /** The MIME parts as set by the constructor */
    protected Part[] parts;
    
    private byte[] multipartBoundary;
    
    /**
     * Creates a new multipart entity containing the given parts.
     * @param parts The parts to include.
     */
    public MultipartHttpEntity(Part[] parts) {
        if (parts == null) {
            throw new IllegalArgumentException("parts cannot be null");
        }
        this.parts = parts;
    }

    /**
     * Returns the MIME boundary string that is used to demarcate boundaries of
     * this part. The first call to this method will implicitly create a new
     * boundary string. To create a boundary string first the 
     * HttpMethodParams.MULTIPART_BOUNDARY parameter is considered. Otherwise 
     * a random one is generated.
     * 
     * @return The boundary string of this entity in ASCII encoding.
     */
    protected byte[] getMultipartBoundary() {
        if (multipartBoundary == null) {
            multipartBoundary = generateMultipartBoundary();
        }
        return multipartBoundary;
    }

    /**
     * Returns <code>true</code> if all parts are repeatable, <code>false</code> otherwise.
     * @see org.apache.commons.httpclient.methods.RequestEntity#isRepeatable()
     */
    public boolean isRepeatable() {
        for (int i = 0; i < parts.length; i++) {
            if (!parts[i].isRepeatable()) {
                return false;
            }
        }
        return true;
    }

    /* (non-Javadoc)
     * @see org.apache.commons.httpclient.methods.RequestEntity#writeRequest(java.io.OutputStream)
     */
    @Override public void writeTo(OutputStream out) throws IOException {
        Part.sendParts(out, parts, getMultipartBoundary());
    }

    /* (non-Javadoc)
     * @see org.apache.commons.httpclient.methods.RequestEntity#getContentLength()
     */
    public long getContentLength() {
        try {
            return Part.getLengthOfParts(parts, getMultipartBoundary());            
        } catch (Exception e) {
            OFLog.e(TAG, "An exception occurred while getting the length of the parts"); //, e);
            return 0;
        }
    }

    /* (non-Javadoc)
     * @see org.apache.commons.httpclient.methods.RequestEntity#getContentType()
     */
    public Header getContentType() {
        StringBuffer buffer = new StringBuffer(MULTIPART_FORM_CONTENT_TYPE);
        buffer.append("; boundary=");
        buffer.append(EncodingUtil.getAsciiString(getMultipartBoundary()));
        return new BasicHeader("Content-Type", buffer.toString());
    }

	@Override
	public void consumeContent() throws IOException {
		throw new UnsupportedOperationException();
	}

	@Override public InputStream getContent() throws IOException, IllegalStateException {
		throw new UnsupportedOperationException();
	}

	@Override public Header getContentEncoding() {
		return new BasicHeader("Content-Encoding", "text/html; charset=UTF-8");
	}

	@Override public boolean isChunked() {
		return getContentLength() < 0;
	}

	@Override public boolean isStreaming() {
		return false; // recv unsupported, but this still gets called.
	}
}
