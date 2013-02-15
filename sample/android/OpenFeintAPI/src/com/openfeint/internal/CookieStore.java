package com.openfeint.internal;

import java.util.Date;

import org.apache.http.cookie.Cookie;
import org.apache.http.impl.client.BasicCookieStore;
import org.apache.http.impl.cookie.BasicClientCookie;
import org.apache.http.impl.cookie.DateParseException;

import android.os.Bundle;

import com.openfeint.internal.logcat.OFLog;

public class CookieStore extends BasicCookieStore {

	static final String tag = "CookieStore";
	static final String COOKIE_PREFIX = "_of_cookie_";
	static final int COOKIE_PREFIX_LEN = COOKIE_PREFIX.length();
	static final String COOKIE_VALUE_TAG = "value";
	static final int COOKIE_VALUE_TAG_LEN = COOKIE_VALUE_TAG.length();
	
	SyncedStore mSharedPreferences;
	
	public synchronized void saveInstanceState(Bundle outState) {
		for (Cookie c : super.getCookies()) {
			cookieToBundle(c, outState);
		}
	}
	
	public synchronized void restoreInstanceState(Bundle inState) {
		for (String k : inState.keySet()) {
			if (k.startsWith(COOKIE_PREFIX) && k.endsWith(COOKIE_VALUE_TAG)) {
				String cookieName = k.substring(COOKIE_PREFIX_LEN, k.length() - COOKIE_VALUE_TAG_LEN);
				BasicClientCookie c = cookieFromBundle(inState, cookieName);
				super.addCookie(c);
			}
		}
	}

	public CookieStore(SyncedStore sp) {
 		super();

		mSharedPreferences = sp;
		
		SyncedStore.Reader r = mSharedPreferences.read();
		try {
			for (String k : r.keySet()) {
				if (k.startsWith(COOKIE_PREFIX) && k.endsWith(COOKIE_VALUE_TAG)) {
					String cookieName = k.substring(COOKIE_PREFIX_LEN, k.length() - COOKIE_VALUE_TAG_LEN);
					BasicClientCookie c = cookieFromPrefs(r, cookieName);
					super.addCookie(c);
				}
			}
		} finally {
			r.complete();
		}

	}

	private BasicClientCookie cookieFromBundle(Bundle b, String cookieName) {
		String prefix = COOKIE_PREFIX + cookieName;
		BasicClientCookie c = null;
		
		String cookieValue = b.getString(prefix + "value");
		if (cookieValue == null) return null;

		String cookiePath = b.getString(prefix + "path");
		String cookieDomain = b.getString(prefix + "domain");
		String cookieExpiry = b.getString(prefix + "expiry");
		
		
		c = new BasicClientCookie(cookieName, cookieValue);
		c.setPath(cookiePath);
		c.setDomain(cookieDomain);
		if (cookieExpiry != null) {
			c.setExpiryDate(dateFromString(cookieExpiry));
		}
		
		return c;
	}
	
	private BasicClientCookie cookieFromPrefs(SyncedStore.Reader r, String cookieName) {
		String prefix = COOKIE_PREFIX + cookieName;
		BasicClientCookie c = null;

		String cookieValue = r.getString(prefix + "value", null);
		if (cookieValue == null) return null;

		String cookiePath = r.getString(prefix + "path", null);
		String cookieDomain = r.getString(prefix + "domain", null);
		String cookieExpiry = r.getString(prefix + "expiry", null);
		
		
		c = new BasicClientCookie(cookieName, cookieValue);
		c.setPath(cookiePath);
		c.setDomain(cookieDomain);
		c.setExpiryDate(dateFromString(cookieExpiry));
		
		return c;
	}

	private void cookieToBundle(Cookie cookie, Bundle b) {
		final String name = cookie.getName();
		b.putString(COOKIE_PREFIX + name + "value", cookie.getValue());
		b.putString(COOKIE_PREFIX + name + "path", cookie.getPath());
		b.putString(COOKIE_PREFIX + name + "domain", cookie.getDomain());
		final Date expiryDate = cookie.getExpiryDate();
		if (null != expiryDate) {
			b.putString(COOKIE_PREFIX + name + "expiry", stringFromDate(expiryDate));
		}
	}

	private void cookieToPrefs(Cookie cookie, SyncedStore.Editor e) {
		final String name = cookie.getName();
		e.putString(COOKIE_PREFIX + name + "value", cookie.getValue());
		e.putString(COOKIE_PREFIX + name + "path", cookie.getPath());
		e.putString(COOKIE_PREFIX + name + "domain", cookie.getDomain());
		e.putString(COOKIE_PREFIX + name + "expiry", stringFromDate(cookie.getExpiryDate()));
	}
	
	@Override
	public synchronized void addCookie(Cookie cookie) {
		
		super.addCookie(cookie);
		String name = cookie.getName();
		
		Cookie existing = null;
		SyncedStore.Reader r = mSharedPreferences.read();
		try {
			existing = cookieFromPrefs(r, name);
		} finally {
			r.complete();
		}

		if (existing == null ||
			!existing.getValue().equals(cookie.getValue()) ||
			!existing.getPath().equals(cookie.getPath()) ||
			!existing.getDomain().equals(cookie.getDomain()) ||
			!existing.getExpiryDate().equals(cookie.getExpiryDate())) {

			SyncedStore.Editor e = mSharedPreferences.edit();
			try {
				// clear the existing cookie from prefs.
				String prefix = COOKIE_PREFIX + name;
				for (String k : e.keySet()) {
					if (k.startsWith(prefix)) {
						e.remove(k);
					}
				}
	
				// and then, if new cookie is persistent, then add it!
				if (cookie.getExpiryDate() != null) {
					cookieToPrefs(cookie, e);
				}
			} finally {
				e.commit();
			}
		}
	}

	public synchronized void clearCookies(SyncedStore.Editor e) {
		for (String k : e.keySet()) {
			if (k.startsWith(COOKIE_PREFIX)) {
				e.remove(k);
			}
		}
		super.clear();
	}
	
	private static final String stringFromDate(Date d) {
		return org.apache.http.impl.cookie.DateUtils.formatDate(d);
	}

	private static final Date dateFromString(String s) {
		try {
			return org.apache.http.impl.cookie.DateUtils.parseDate(s);
		} catch (DateParseException e) {
			OFLog.e(tag, "Couldn't parse date: '"+s+"'");
			return null;
		}
	}
}
