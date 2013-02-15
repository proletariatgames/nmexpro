package com.openfeint.internal.request;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.zip.DeflaterOutputStream;
import java.util.zip.InflaterInputStream;

import com.openfeint.api.OpenFeintSettings;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.Util;
import com.openfeint.internal.logcat.OFLog;

public class Compression {
	
	private static String TAG = "Compression";

	public static byte[] compress(byte uncompressedData[]) {
		byte uploadData[] = uncompressedData;
		
		try {
			switch (compressionMethod()) {
			case Default:
			{
				byte tenativeData[] = _compress(uncompressedData);
				byte[] uncompressedSize = integerToLittleEndianByteArray(uncompressedData.length);
				final int compressedLength = tenativeData.length + MagicHeader.length + uncompressedSize.length;
				if (compressedLength < uncompressedData.length) {
					uploadData = new byte[compressedLength];
					System.arraycopy(MagicHeader, 0, uploadData, 0, MagicHeader.length);
					System.arraycopy(uncompressedSize, 0, uploadData, MagicHeader.length, uncompressedSize.length);
					System.arraycopy(tenativeData, 0, uploadData, MagicHeader.length + 4, tenativeData.length);
					OFLog.i(TAG, String.format("Using Default strategy: orig %d bytes, compressed %d bytes (%.2f%% of original size)", uncompressedData.length, compressedLength, 100.f*((float)compressedLength/(float)uncompressedData.length)));
				} else {
					OFLog.i(TAG, "Using Default strategy: compression declined");
				}
			}
				break;
			case LegacyHeaderless:
				uploadData = _compress(uncompressedData);
				OFLog.i(TAG, String.format("Using Default strategy: orig %d bytes, compressed %d bytes (%.2f%% of original size)", uncompressedData.length, uploadData.length, 100.f*((float)uploadData.length/(float)uncompressedData.length)));
				break;
			default:
				// default in this case is uncompressed, so just use the uncompressedData.
				OFLog.i(TAG, "Using Uncompressed strategy");
				break;
			}
		} catch (IOException e) {
			return null;
		}
		
		return uploadData;
	}
	
	public static byte[] decompress(byte body[]) throws IOException {
		switch (compressionMethod()) {
		case Default:
		{
			int i=0;
			if (MagicHeader.length < body.length) {
				for (; i<MagicHeader.length; ++i) {
					if (MagicHeader[i] != body[i])
						break;
				}
			}
			
			if (i == MagicHeader.length) {
				// skip four bytes for the size_t that we don't need
				int skip = MagicHeader.length + 4;
				final ByteArrayInputStream postHeaderStream = new ByteArrayInputStream(body,
						skip,
						body.length - skip);
				final InputStream decompressedStream = new InflaterInputStream(postHeaderStream);
				body = Util.toByteArray(decompressedStream);
			}
		}
			break;
		
		case LegacyHeaderless:
			body = Util.toByteArray(new InflaterInputStream(new ByteArrayInputStream(body)));
			break;
			
		default:
			// no compression.
		}
		
		return body;
	}
	
	private static final byte[] MagicHeader = "OFZLHDR0".getBytes();
	
	private enum CompressionMethod {
		Default,
		Uncompressed,
		LegacyHeaderless,
	};
	
	private static CompressionMethod compressionMethod() {
		String s = (String)OpenFeintInternal.getInstance().getSettings().get(OpenFeintSettings.SettingCloudStorageCompressionStrategy);
		if (s != null) {
			if (s.equals(OpenFeintSettings.CloudStorageCompressionStrategyLegacyHeaderlessCompression))
				return CompressionMethod.LegacyHeaderless;
			if (s.equals(OpenFeintSettings.CloudStorageCompressionStrategyNoCompression))
				return CompressionMethod.Uncompressed;
		}
		return CompressionMethod.Default;
	}
	
	private static byte[] _compress(byte data[]) throws IOException {
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		DeflaterOutputStream dos = new DeflaterOutputStream(baos);

		dos.write(data);
		dos.close();
		return baos.toByteArray();
	}
	
	// This is little endian for compatibility with the iOS api.  in a better world we'd use network byte order.
	private static byte[] integerToLittleEndianByteArray(int i) {
		byte rv[] = new byte[4];
		rv[0] = (byte)(i >>  0);
		rv[1] = (byte)(i >>  8);
		rv[2] = (byte)(i >> 16);
		rv[3] = (byte)(i >> 24);
		return rv;
	}
}
