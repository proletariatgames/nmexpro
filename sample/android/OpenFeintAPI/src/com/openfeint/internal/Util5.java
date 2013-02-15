package com.openfeint.internal;

import java.lang.reflect.Method;

import android.content.Context;

/*
 * Class to store code will call sdk 5 or above.  This uses reflection, so it should build cleanly on
 * all SDKs back to 1.6.
 */
public class Util5 {

	public static String getAccountNameEclair(Context ctx) {
		try {
			Class<?> cAccountManager	= Class.forName("android.accounts.AccountManager");
			Method get					= cAccountManager.getMethod("get", Context.class);
			Object accountManager		= get.invoke(cAccountManager, ctx);
			Method getAccountsByType	= cAccountManager.getMethod("getAccountsByType", String.class);
			Object accounts[]			= (Object[])getAccountsByType.invoke(accountManager, "com.google");
			Class<?> cAccount 			= Class.forName("android.accounts.Account");
			return (String)cAccount.getField("name").get(accounts[0]);
		} catch (Exception e) {
		}
		return null;
	}
}
