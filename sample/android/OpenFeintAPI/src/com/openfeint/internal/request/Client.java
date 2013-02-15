package com.openfeint.internal.request;

import java.io.IOException;
import java.io.InputStream;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.RejectedExecutionHandler;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.zip.GZIPInputStream;

import org.apache.http.Header;
import org.apache.http.HeaderElement;
import org.apache.http.HttpEntity;
import org.apache.http.HttpException;
import org.apache.http.HttpRequest;
import org.apache.http.HttpRequestInterceptor;
import org.apache.http.HttpResponse;
import org.apache.http.HttpResponseInterceptor;
import org.apache.http.conn.ClientConnectionManager;
import org.apache.http.conn.scheme.PlainSocketFactory;
import org.apache.http.conn.scheme.Scheme;
import org.apache.http.conn.scheme.SchemeRegistry;
import org.apache.http.conn.ssl.SSLSocketFactory;
import org.apache.http.entity.HttpEntityWrapper;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.impl.conn.tsccm.ThreadSafeClientConnManager;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.protocol.HttpContext;

import android.os.Bundle;
import android.os.Handler;

import com.openfeint.internal.CookieStore;
import com.openfeint.internal.SyncedStore;
import com.openfeint.internal.logcat.OFLog;

public class Client extends DefaultHttpClient {

	private static final int MIN_THREADS = 2;
	private static final int MAX_THREADS = 4;
	private static final int EXCESS_THREAD_LIFETIME = 30;
	private static final String TAG = "HTTPClient";
	
	private Signer mSigner;
	private Handler mMainThreadHandler;
	private CookieStore mCookieStore;
	private boolean mForceOffline;

	final ExecutorService mExecutor;
	
	public void saveInstanceState(Bundle outState) {
		mCookieStore.saveInstanceState(outState);
		outState.putBoolean("mForceOffline", mForceOffline);
	}
	
	public void restoreInstanceState(Bundle inState) {
		mCookieStore.restoreInstanceState(inState);
		mForceOffline = inState.getBoolean("mForceOffline");
	}
	
	public boolean toggleForceOffline() {
		if (mForceOffline) {
			mForceOffline = false;
			OFLog.i(TAG, "forceOffline = FALSE");
		} else {
			mForceOffline = true;
			OFLog.i(TAG, "forceOffline = TRUE");			
		}
		return mForceOffline;
	}

    private static class GzipDecompressingEntity extends HttpEntityWrapper {

        public GzipDecompressingEntity(final HttpEntity entity) {
            super(entity);
        }
    
        @Override public InputStream getContent() throws IOException, IllegalStateException {
            // the wrapped entity's getContent() decides about repeatability
            InputStream wrappedin = wrappedEntity.getContent();
            return new GZIPInputStream(wrappedin);
        }

        @Override public long getContentLength() {
            // length of ungzipped content is not known
            return -1;
        }
    }

	static final ClientConnectionManager makeCCM() {
		SchemeRegistry sr = new SchemeRegistry();
		sr.register(new Scheme("http", PlainSocketFactory.getSocketFactory(), 80));
		sr.register(new Scheme("https", SSLSocketFactory.getSocketFactory(), 443));
		
		ClientConnectionManager ccm = new ThreadSafeClientConnManager(new BasicHttpParams(), sr);

		return ccm;
	}
	
	private final class Executor extends ThreadPoolExecutor {
		Executor() {
			super(MIN_THREADS, MAX_THREADS, EXCESS_THREAD_LIFETIME, TimeUnit.SECONDS, new LinkedBlockingQueue<Runnable>(), new RejectedExecutionHandler() {
				@Override public void rejectedExecution(Runnable arg0, ThreadPoolExecutor arg1) {
					OFLog.e(TAG, "Can't submit runnable " + arg0.toString());
				}
			});
		}
	}
	
	public Client(String key, String secret, SyncedStore prefs) {
		super(makeCCM(), new BasicHttpParams());
		
		mExecutor = new Executor();

		mSigner = new Signer(key, secret);
		mMainThreadHandler = new Handler();
		mCookieStore = new CookieStore(prefs);
		
		setCookieStore(mCookieStore);
		
		// gzip stream support
		addRequestInterceptor(new HttpRequestInterceptor() {
            public void process(final HttpRequest request, final HttpContext context) throws HttpException, IOException {
                if (!request.containsHeader("Accept-Encoding")) {
                    request.addHeader("Accept-Encoding", "gzip");
                }
            }
        });
        
		addResponseInterceptor(new HttpResponseInterceptor() {
            public void process(final HttpResponse response, final HttpContext context) throws HttpException, IOException {
                HttpEntity entity = response.getEntity();
                if (entity != null) {
	                Header ceheader = entity.getContentEncoding();
	                if (ceheader != null) {
	                    HeaderElement[] codecs = ceheader.getElements();
	                    if (codecs != null) {
		                    for (int i = 0; i < codecs.length; i++) {
		                        if (codecs[i].getName().equalsIgnoreCase("gzip")) {
		                            response.setEntity(new GzipDecompressingEntity(response.getEntity())); 
		                            return;
		                        }
		                    }
	                    }
	                }
                }
            }
        });
	}
	
	public final void makeRequest(final BaseRequest req) {
		makeRequest(req, req.timeout());
	}
	
	public final void makeRequest(final BaseRequest req, final long timeoutMillis) {

		final Runnable onResponse = new Runnable() {
			@Override public void run() {
				req.onResponse();
			}
		};
		
		final Runnable onTimeout = new Runnable() {
			@Override public void run() {
				// If it's finished its reponse, let it continue with its response handling.
				if (req.getResponse() == null) {
					boolean victory = req.getFuture().cancel(true);
					if (victory) {
						req.postTimeoutCleanup();
						mMainThreadHandler.post(onResponse);
					}
				}
			}
		};
		
		final Runnable requestRunnable = new Runnable() {
			@Override public void run() {
				// Timeout starts NOW.
				mMainThreadHandler.postDelayed(onTimeout, timeoutMillis);
				req.sign(mSigner);
				req.exec(mForceOffline);
				mMainThreadHandler.removeCallbacks(onTimeout);
				mMainThreadHandler.post(onResponse);
			}
		};
		
		req.setFuture(mExecutor.submit(requestRunnable));
	}
}
