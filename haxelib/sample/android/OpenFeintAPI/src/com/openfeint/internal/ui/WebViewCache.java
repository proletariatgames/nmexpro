package com.openfeint.internal.ui;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URI;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDiskIOException;
import android.database.sqlite.SQLiteStatement;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;

import com.openfeint.api.ui.Dashboard;
import com.openfeint.internal.InternalSettings;
import com.openfeint.internal.OpenFeintInternal;
import com.openfeint.internal.Util;
import com.openfeint.internal.db.DB;
import com.openfeint.internal.logcat.OFLog;
import com.openfeint.internal.request.BaseRequest;
import com.openfeint.internal.request.CacheRequest;
import com.openfeint.internal.request.OrderedArgList;

public class WebViewCache {
	final static String TAG = "WebViewCache";
	
	//PUBLIC API
	public static URI serverOverride;  //set before initialization
	public static String manifestProductOverride;  //set before initialization
	
	public static WebViewCache initialize(Context context) {
		if (sInstance != null) {
			// stop any loading in progress.
			sInstance.finishWithoutLoading();
		}
		sInstance = new WebViewCache(context);
		return sInstance;
	}
	
	public static void prioritize(String path) {
	    sInstance.prioritizeInner(path);
	}
	
	public static boolean trackPath(String path, WebViewCacheCallback cb) {
		return sInstance.trackPathInner(path, cb);
	}

	public static boolean isLoaded(String path) {
		return sInstance.isLoadedInner(path);
	}
	
	private static final String WEBUI = "webui";
	public final void setRootUriSdcard(final File path) {
    	final File webui = new File(path, WEBUI);
    	final boolean copyDefault = !webui.exists();
    	if (copyDefault) {
		    File noMedia = new File(path, ".nomedia");
		    try {
		      noMedia.createNewFile();
            } catch (IOException e) {
    	    }

    		if (!webui.mkdirs()) {
    			setRootUriInternal();
    	        return;
    		}
    	}
    	rootPath = webui.getAbsolutePath() + "/";
		rootUri = "file://"+ rootPath;
    	if (copyDefault) {
			final File baseDir = appContext.getFilesDir();
			final File inPhoneWebui = new File(baseDir, WEBUI);
    		if (inPhoneWebui.isDirectory()) {
    			try {
    				// move copy db here so that 
    				// we could create db out of WebViewCache
					Util.copyFile(appContext.getDatabasePath(DB.DBNAME), 
							new File(webui, DB.DBNAME));
				} catch (IOException e) {
				}
    		}    		
    		Thread t = new Thread(new Runnable() {
    			public void run() {
    				try {
		        		if (inPhoneWebui.isDirectory()) {
		        			Util.copyDirectory(inPhoneWebui, webui);
		        			deleteAll();
		        			OFLog.i(TAG, "copy in phone data finish");
		        			clientManifestReady();
		        		} else {
		        		    OFLog.i(TAG, "copy from asset");
		    				copyDefaultBackground(baseDir);
		        		}
					} catch (IOException e) {
					    OFLog.e(TAG, e.getMessage());
				        setRootUriInternal();
				        return;
					}
    			}
    		});
    		t.start();
    		return;
    	} else {
    		clientManifestReady();
    	}
    	
    	deleteAll();
	}
	
	public final void setRootUriInternal() {
		OFLog.e(TAG, "can't use sdcard");
		final File baseDir = appContext.getFilesDir();
		File rootDir = new File(baseDir, WEBUI);
		rootPath = rootDir.getAbsolutePath() +"/";
		rootUri = "file://"+ rootPath;
		final File inPhoneWebui = new File(baseDir, WEBUI);
		boolean hasInPhoneData = inPhoneWebui.isDirectory();
		if (!hasInPhoneData) {
			Thread t = new Thread(new Runnable() {
				public void run() {
					copyDefaultBackground(baseDir);
				}
			});
			t.start();
		} else {
			clientManifestReady();
		}
	}
	
    public static final String getItemUri(String itemPath) {
        return rootUri + itemPath;
    }
    
    public static final String getItemAbsolutePath(String itemPath) {
        return rootPath + itemPath;
    }
    
	public static void start() {
	    sInstance.updateExternalStorageState();
	    sInstance.sync();
	}
	
	//PRIVATE API
	
	static WebViewCache sInstance;
	private static String rootUri;
	private static String rootPath;
	Handler mHandler;
	Handler mDelayHandler;
	Set<PathAndCallback> trackedPaths;
	Map<String, ItemAndCallback> trackedItems;
	static final int kServerManifestReady = 0;
	static final int kDataLoaded = 1;
	static final int kBatchLoaded = 2;
	static final int kClientManifestReady = 3;
	static final int kFinishWhenClientReady = 4;
	static final int kNumBatchRetries = 3;
	static final long kBatchRetryDelayMillis = 5000;
	boolean loadingFinished = false;
	boolean globalsFinished = false;
	WebViewCacheCallback delegate;
	ManifestData serverManifest;
	Map<String, String> clientManifest;
	Set<String> pathsToLoad;	
	Set<String> prioritizedPaths;
	boolean batchesAreBroken = false;
	boolean finishWhenClientManifestDone = false;
	
	//determining state:
	//  not loaded manifest yet:    serverManifest == null, loadingFinished == NO
	//  manifest failed:  serverManifest == null, loadingFinished = YES
	//  in process of loading items, serverManifest != null, loadingFinished = NO
	//  all done loading serverManifest != null, loadingFinished = YES
	
	final URI serverURI = getServerURI();
	
	Context appContext;
	//INNER CLASSES
	private static class ManifestItem {
		public String path;
		public String hash;
		public Set<String> dependentObjects;
		ManifestItem(String _path, String _hash) { path = _path; hash = _hash; dependentObjects = new HashSet<String>(); }
		ManifestItem(ManifestItem item) {
			path = item.path;
			dependentObjects  = new HashSet<String>(item.dependentObjects);
		}
	}

	private static boolean diskError = false;

	public static void diskError() {
        diskError = true;
        for(PathAndCallback pathAndCb : sInstance.trackedPaths) {
            pathAndCb.callback.failLoaded();
        }
        sInstance.trackedPaths.clear();
        sInstance.finishWithoutLoading();
    }

    private static class ManifestData {
		Set<String> globals = new HashSet<String>();
		Map<String, ManifestItem> objects = new HashMap<String, ManifestItem>();
		ManifestData(SQLiteDatabase db) {
			Cursor result = null;
			try {
				result = db.rawQuery("SELECT path, hash, is_global FROM server_manifest", null);
				if(result.getCount() > 0) {
					result.moveToFirst();
					do {
						String path = result.getString(0);
						String hash = result.getString(1);
						boolean isGlobal = result.getInt(2) != 0;
						
						objects.put(path, new ManifestItem(path, hash));
						if (isGlobal) globals.add(path);
					} while (result.moveToNext());
				}
				result.close();
				
				for (String path: objects.keySet()) {
					// I can't compile this query because it returns multiple rows.  Thanks, inexplicable Java limitations
					result = db.rawQuery("SELECT has_dependency FROM dependencies WHERE path = ?", new String[] {path});
					if(result.getCount() > 0) {
						final ManifestItem manifestItem = objects.get(path);
						if (null != manifestItem) {
							Set<String> deps = manifestItem.dependentObjects;
							result.moveToFirst();
							do {
								deps.add(result.getString(0));
							} while (result.moveToNext());
						}
					}
					result.close();
				}
	        } catch (SQLiteDiskIOException e) {
	            WebViewCache.diskError();
			} catch (Exception e) {
			    OFLog.e(TAG, "SQLite exception. " + e.toString());
			} finally {
				try { result.close(); } catch (Exception jeez) {}
			}
		}
		
		void saveTo(SQLiteDatabase db) {
			try {
				db.beginTransaction();
				db.execSQL("DELETE FROM server_manifest;");
				db.execSQL("DELETE FROM dependencies;");
				SQLiteStatement insertIntoManifest = db.compileStatement("INSERT INTO server_manifest(path, hash, is_global) VALUES(?, ?, ?)");
				SQLiteStatement insertIntoDependencies = db.compileStatement("INSERT INTO dependencies(path, has_dependency) VALUES(?, ?)");
				for (String path : objects.keySet()) {
					final ManifestItem item = objects.get(path);

					insertIntoManifest.bindString(1, path);
					insertIntoManifest.bindString(2, item.hash);
					insertIntoManifest.bindLong(3, globals.contains(path) ? 1 : 0);
					insertIntoManifest.execute();

					insertIntoDependencies.bindString(1, path);
					for (String dep : item.dependentObjects) {
						insertIntoDependencies.bindString(2, dep);
						insertIntoDependencies.execute();
					}
				}
				db.setTransactionSuccessful();
			} catch (SQLiteDiskIOException e) {
			    diskError();
			} catch (Exception e) {
			    OFLog.e(TAG, "SQLite exception. " + e.toString());
			} finally {
				try { db.endTransaction(); } catch (Exception whatever_man) {}
			}
		}

		ManifestData(byte[] stm) throws Exception {
			String line;
			ManifestItem item = null;			
			try {
				InputStreamReader reader = new InputStreamReader(new ByteArrayInputStream(stm));
				BufferedReader buffered = new BufferedReader(reader, 8192);
				while((line = buffered.readLine()) != null) {
					line = line.trim();
					if(line.length() == 0) continue;
					switch(line.charAt(0)) {
					case '#':
						//comment, do nothing
						break;
					case '-':
						if(item != null) {
							item.dependentObjects.add(line.substring(1).trim());
						} else {
							throw new Exception("Manifest Syntax Error: Dependency without an item");
						}
						break;
					default:
						String[] pieces = line.split(" ");
						String path;
						if(pieces.length >= 2) {
							if(pieces[0].charAt(0) == '@') {
								path = pieces[0].substring(1);
								globals.add(path);
							}
							else {
								path = pieces[0];
							}
							item = new ManifestItem(path, pieces[1]);
							objects.put(path, item);
						} else {
							throw new Exception("Manifest Syntax Error: Extra items in line");							
						}
						//new object
						break;
					}
				}	
			}  catch (Exception e) {
				throw new Exception(e);  //this will tell the loader it failed
			}
		}
	}
	//structures for use inside collections
	private static class ItemAndCallback {
		public final ManifestItem item;
		public final WebViewCacheCallback callback;
		public ItemAndCallback(ManifestItem _item, WebViewCacheCallback _cb) {
			item = _item;
			callback = _cb;
		}
	}
	
	private static class PathAndCallback {
		public final String path;
		public final WebViewCacheCallback callback;
		public PathAndCallback(String _path, WebViewCacheCallback _cb) {
			path = _path;
			callback = _cb;
		}
	}
	
	private boolean trackPathInner(String path, WebViewCacheCallback cb) {
		if(loadingFinished) {
			cb.pathLoaded(path);
			return false;  //all done, so report as loaded
		}
		if(serverManifest == null) {
			cb.onTrackingNeeded();
			trackedPaths.add(new PathAndCallback(path, cb));  //store for later
			return true;
		}
		else {
			ManifestItem loadedItem = serverManifest.objects.get(path);
			if(loadedItem != null) {
				//this is in fact an item in the manifest
				cb.onTrackingNeeded();
				ManifestItem newItem = new ManifestItem(loadedItem);
				newItem.dependentObjects.retainAll(pathsToLoad);
				trackedItems.put(path, new ItemAndCallback(newItem, cb));
				return true;
			}
			else {
				//not in the manifest
				cb.pathLoaded(path);
				return false;
			}
			
		}
	}
	
	private boolean isLoadedInner(String path) {
		if(serverManifest == null) return loadingFinished;  //if not loaded yet, say No, if no manifest was found say Yes
		if(pathsToLoad.contains(path)) return false;
		return true;
	}
	
	private WebViewCache(Context _appContext) {
		appContext = _appContext;
		trackedPaths = new HashSet<PathAndCallback>();
		trackedItems = new HashMap<String, ItemAndCallback>();
		pathsToLoad = new HashSet<String>();
		prioritizedPaths = new HashSet<String>();
		
		mDelayHandler = new Handler();
		mHandler = new Handler() {
			@Override
			@SuppressWarnings("unchecked")
			public void dispatchMessage(Message msg) {
				//the message will contain things like server manifest loaded and item finished
				//forwards to appropriate method
				//this will send callbacks to the registered delegate
				switch(msg.what) {
				case kServerManifestReady:
				    OFLog.i(TAG, "kServerManifestReady");
					serverManifest = (ManifestData)msg.obj;
					triggerUpdates();
					break;
				case kDataLoaded:
					finishItem((String) msg.obj, msg.arg1 > 0);
					break;
				case kBatchLoaded:
					finishItems((Set<String>) msg.obj, msg.arg1 > 0);
					break;
				case kClientManifestReady:
					clientManifest = (Map<String, String>)msg.obj;
					triggerUpdates();
					break;
				case kFinishWhenClientReady:
			        if (clientManifest != null) {
			            finishWithoutLoading();
			        } else {
			            finishWhenClientManifestDone = true;
			        }
					break;
				}
			}
		};
	}
	
	private static final String OPENFEINT_ROOT = "openfeint";
	
	private void updateExternalStorageState() {
	    if (Util.noSdcardPermission()) {
	        OFLog.e(TAG, "no sdcard permission");
	        setRootUriInternal();
	        return;
	    }
	            
	    String state = Environment.getExternalStorageState();
	    if (Environment.MEDIA_MOUNTED.equals(state)) {
	    	File sdcard = Environment.getExternalStorageDirectory();
	    	File feintRoot = new File(sdcard, OPENFEINT_ROOT);
	    	setRootUriSdcard(feintRoot);	
	    } else {
	        OFLog.i(TAG, state);
	    	setRootUriInternal();
	    }
	}

	// TODO: delay get clientManifest till we have server update
	private void sync() {
	    OFLog.i(TAG, "--- WebViewCache Sync ---");
		//start loading the server manifest on a thread, it will call back to the handle
		ManifestRequest req = new ManifestRequest(ManifestRequestKey);
		req.launch();
	}

	private static final String ManifestRequestKey = "manifest";
	private class ManifestRequest extends CacheRequest {
		private ManifestData data = null;
		
		public ManifestRequest(String key) {
			super(key);
		}
		
		@Override public boolean signed() { return false; }
		@Override public String path() {
			return WebViewCache.getManifestPath(appContext);
		}
		
		// This is a NOP - all the work is done off the main thread.
		@Override public void onResponse(int responseCode, byte[] body) {}

		@Override public void onResponseOffMainThread(int responseCode, byte[] body) {
			if(responseCode == 200) {
				try {
					data = new ManifestData(body);
				} catch (Exception e) {
				    OFLog.e(TAG, e.toString());
				}
			} else {
				// try to load the old manifest, if there's been no change.
				try {
					data = new ManifestData(DB.storeHelper.getReadableDatabase());
				} catch (Exception e) {
				    OFLog.e(TAG, e.toString());
				}
			}
			
			// 1) if it's a 304 but we've no manifest in the db, we need to download it anyway.
			if (data == null || data.objects.isEmpty()) {
				// get rid of any empty manifest
				data = null;
				
				new BaseRequest() {
					@Override public String method() { return "GET"; }
					@Override public String path() { return ManifestRequest.this.path(); }
					@Override public void onResponse(int responseCode, byte[] body) {} // @NOP, see below.
					@Override public void onResponseOffMainThread(int responseCode, byte[] body) {
						if (200 == responseCode) {
							try {
								data = new ManifestData(body);
								// Update the ManifestRequest's etag from our headers.
								finishManifest();
								ManifestRequest.this.updateLastModifiedFromResponse(getResponse());
							} catch (Exception e) {}
						} else {
							finishWhenClientManifestReady();
						}
					}
				}.launch();
			} else {
				finishManifest();
				ManifestRequest.this.updateLastModifiedFromResponse(getResponse());
			}
		}
		
		private void finishManifest() {
			if (data != null) {
				try {
					data.saveTo(DB.storeHelper.getWritableDatabase());
				} catch (Exception e) {
				    OFLog.e(TAG, e.toString());
				}
				Message msg = Message.obtain(mHandler, kServerManifestReady, data);
				msg.sendToTarget();
			} else {
                finishWhenClientManifestReady();
			}
		}
	}
	
	private void deleteAll() {
		File baseDir = appContext.getFilesDir();
		File webui = new File(baseDir, WEBUI);
		Util.deleteFiles(webui);
		appContext.getDatabasePath(DB.DBNAME).delete();
	}

	private void gatherDefaultItems(String path, Set<String> items) {
		try {
			String [] stuff = appContext.getAssets().list(path);
			for(String s : stuff) {
				String fullpath = path + "/" + s;
				try {
					InputStream check = appContext.getAssets().open(fullpath);
					items.add(fullpath);
					check.close();
				}
				catch (IOException e) {
					//must not have been a file
					gatherDefaultItems(fullpath, items);
				}
			}
		} catch (IOException e) {
		    OFLog.e(TAG, e.toString());
		}

	}

	private void copySingleItem(File baseDir, String path) {
		try {
			File filePath = new File(baseDir, path);
			InputStream  inputStream = appContext.getAssets().open(path);
			DataInputStream reader = new DataInputStream(inputStream);
			
			filePath.getParentFile().mkdirs();
			FileOutputStream fileStream = new FileOutputStream(filePath);
			DataOutputStream writer = new DataOutputStream(fileStream);
			Util.copyStream(reader, writer);
		}
		catch(Exception e) {
		    OFLog.e(TAG, e.toString());
		}
	}
	
	private Set<String> stripUnused(Set<String>table) {
		String currentDpi = Util.getDpiName(appContext);
		String test = currentDpi.equals("mdpi") ? ".hdpi." : ".mdpi.";
		Set<String> reducedSet = new HashSet<String>();
		for(String path : table) {
			if(!path.contains(test)) reducedSet.add(path);
		}
		return reducedSet;
	}
	
	private void copySpecific(File baseDir, String path, Set<String> items) {
		if(items.contains(path)) {
			copySingleItem(baseDir, path);
			items.remove(path);
		}
	}
	
	private void copyDirectory(File baseDir, String root, Set<String> items) {
		Set<String> dirItems = new HashSet<String>();
		for(String path : items) {
			if(path.startsWith(root)) dirItems.add(path);
		}
		for(String path : dirItems) copySpecific(baseDir, path, items);
	}
	
	//TODO: prioritize the manifest and introflow loading
	private void copyDefaultBackground(File baseDir) {
		Set<String> defaultItems = new HashSet<String>();
		gatherDefaultItems(WEBUI, defaultItems);
		defaultItems = stripUnused(defaultItems);
		copySpecific(baseDir, "webui/manifest.plist", defaultItems);
		copyDirectory(baseDir, "webui/javascripts/", defaultItems);
		copyDirectory(baseDir, "webui/stylesheets/", defaultItems);
		copyDirectory(baseDir, "webui/intro/", defaultItems);
		if(Util.getDpiName(appContext).equals("mdpi")) {
			copySpecific(baseDir, "webui/images/space.grid.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.gray.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.gray.hit.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.green.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.green.hit.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/logo.small.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/header_bg.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/loading.spinner.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/input.text.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/frame.small.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/icon.leaf.gray.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/tab.divider.mdpi.png", defaultItems);			
			copySpecific(baseDir, "webui/images/tab.active_indicator.mdpi.png", defaultItems);
			
			copySpecific(baseDir, "webui/images/logo.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/header_bg.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/loading.spinner.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/icon.user.male.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.leaderboards.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.friends.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.achievements.mdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.games.mdpi.png", defaultItems);

		}
		else {
			copySpecific(baseDir, "webui/images/space.grid.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.gray.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.gray.hit.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.green.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/button.green.hit.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/logo.small.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/header_bg.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/loading.spinner.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/input.text.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/frame.small.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/icon.leaf.gray.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/tab.divider.hdpi.png", defaultItems);			
			copySpecific(baseDir, "webui/images/tab.active_indicator.hdpi.png", defaultItems);			
			
			copySpecific(baseDir, "webui/images/logo.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/header_bg.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/loading.spinner.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/icon.user.male.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.leaderboards.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.friends.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.achievements.hdpi.png", defaultItems);
			copySpecific(baseDir, "webui/images/intro.games.hdpi.png", defaultItems);
		}
		
		final boolean delayReadyCall = 
		    (OpenFeintInternal.getInstance().getSettings().get(InternalSettings.WebUIDelayUntilCopyFinished) != null);
		
		if (delayReadyCall) {
	        for(String path : defaultItems) {
	            copySingleItem(baseDir, path);
	        }

	        clientManifestReady();
		} else {
	        clientManifestReady();
	        
	        for(String path : defaultItems) {
	            copySingleItem(baseDir, path);
	        }
		}
	}
	
	private void clientManifestReady() {
		Object obj = getDefaultClientManifest();
		Message msg = Message.obtain(mHandler, kClientManifestReady);
		msg.obj = obj;
		msg.sendToTarget();		
	}
	
	private class SaxHandler extends DefaultHandler {
		String loadingString;
		String key;
		Map<String, String> outputMap = new HashMap<String, String>();
		public Map<String, String> getOutputMap() { return outputMap; }
		@Override
		public void startElement(String uri, String name, String qName, Attributes attr) {
			loadingString = "";
		}
		@Override
		public void endElement(String uri, String name, String qName) {
			String clipped = name.trim();
			if(clipped.equals("key")) key = loadingString;
			else if(clipped.equals("string")) {
				outputMap.put(key, loadingString);
				DB.setClientManifest(key, loadingString);
			}
		}
		@Override
		public void characters(char ch[], int start, int length) {
			loadingString = new String(ch).substring(start, start + length);
		}
	}

    static public boolean isDiskError() {
        return diskError;
    }

    static public boolean recover() {
	    if (diskError) return false;
		return sInstance.recoverInternal();
	}
	
    void markSyncRequired() {
		loadingFinished = false;
		globalsFinished = false;
		finishWhenClientManifestDone = false;
    }
    
	boolean recoverInternal() {
		boolean success = DB.recover(appContext);
		serverManifest = null;
		if (success) {
		    clientManifest = getDefaultClientManifestFromAsset();
		    success = !clientManifest.isEmpty();
		}
		markSyncRequired();
		sync();
		return success;
	}
	
	// This doesn't throw.  It'll return an empty manifest if there's a problem.
	private Map<String, String> getDefaultClientManifest() {
		Cursor result = null;
		SQLiteDatabase db = null;
		try {
			db = DB.storeHelper.getReadableDatabase();
			result = db.rawQuery("SELECT * FROM manifest", null);
			if(result.getCount() > 0) {
				//database exists, use it
				final Map<String, String> outManifest =  new HashMap<String, String>();
				result.moveToFirst();
				do {
					String path = result.getString(0);
					String hash = result.getString(1);
					outManifest.put(path, hash);
				} while (result.moveToNext());
				result.close();
				OFLog.i(TAG, "create client Manifest from db");
				return outManifest;
			}
        } catch (SQLiteDiskIOException e) {
            WebViewCache.diskError();
		} catch (Exception e) {
			// Some SQLite exception, doesn't matter.  We'll fall through and return the asset manifest.
		    OFLog.e(TAG, "SQLite exception. " + e.toString()); // @TEMP
		} finally {
			try { result.close(); } catch (Exception jeez) {}
		}
			
		return getDefaultClientManifestFromAsset();
	}
	
	// This doesn't throw.  It'll return an empty manifest if there's a problem.
	private Map<String, String> getDefaultClientManifestFromAsset() {
		//read from the file
		File manifestFile = new File(rootPath, "manifest.plist");
		if(manifestFile.isFile()) {
			try {
				SAXParserFactory spf = SAXParserFactory.newInstance();
				SAXParser sp = spf.newSAXParser();
				XMLReader xr = sp.getXMLReader();
				SaxHandler handler = new SaxHandler();
				xr.setContentHandler(handler);
				InputStream  inputStream = new FileInputStream(manifestFile.getPath());
				xr.parse(new InputSource(inputStream));
				return handler.getOutputMap();
			}
			catch(Exception e) {
			    OFLog.e(TAG, e.toString());
			}
		}
		return new HashMap<String, String>();
	}
	static private final URI getServerURI() {
		try {
			if(serverOverride != null) return serverOverride;
			return new URI(OpenFeintInternal.getInstance().getServerUrl());
		} catch(Exception e) {
			return null;
		}
	}
	
	static private final String getManifestPath(Context ctx) {
		final String platform = "android";
		final String product = manifestProductOverride != null ? manifestProductOverride : "embed";
		return String.format("/webui/manifest/%s.%s.%s", platform, product, Util.getDpiName(ctx));
	}
	
	private void triggerUpdates() {
		
	    OFLog.i(TAG, "loadedManifest");

		// If both the server and client manifest are ready, we'll go.  If not, we'll wait on the other.
		if(serverManifest != null && clientManifest != null) {
			//set up the itemsToLoad from the manifest 
			for(ManifestItem item : serverManifest.objects.values()) {
				if(!item.hash.equals(clientManifest.get(item.path))) {
					pathsToLoad.add(item.path);
				}
			}

			loadNextItem();
		} else if (clientManifest != null && finishWhenClientManifestDone) {
		    finishWithoutLoading();
		}
	}
	
	private void finishWhenClientManifestReady() {
        Message msg = Message.obtain(mHandler, kFinishWhenClientReady, null);
        msg.sendToTarget();
	}
	
	private void finishWithoutLoading() {
	    OFLog.i(TAG, "finishWithoutLoading");

		// Actually, finishLoading() BEFORE we notify everyone.  Because if there are
		// people waiting that are going to request more resources, they might get lost
		// in the shuffle.  At least inform them that we are not going to be loading
		// anything anymore.
		finishLoading();

		//no manifest, so tell anyone waiting we are finished
		for(PathAndCallback pathAndCb : trackedPaths) {
			pathAndCb.callback.pathLoaded(pathAndCb.path);
		}
		trackedPaths.clear();
		prioritizedPaths.clear();
		if (serverManifest == null) try {
		    serverManifest = new ManifestData(new byte[]{});
		} catch (Exception e) {}
		serverManifest.globals.clear();
		pathsToLoad.clear();
	}

	private void finishLoading() {
		DB.storeHelper.close();
		loadingFinished = true;
	}
	
	private void batchFetch(final String originalUrl, final String currentUrl, final int retriesLeft, final Set<String> paths) {
		new BaseRequest() {
			@Override public boolean signed() { return false; }
			@Override public String method() { return "GET"; }
			@Override public String path() { return ""; }
			@Override public String url() { return originalUrl; }
			@Override public void onResponse(int responseCode, final byte[] body) {} // nop, interesting stuff happens off main thread. 
			@Override public void onResponseOffMainThread(int responseCode, final byte[] body) {
				handleBatchBody(responseCode, body, originalUrl, currentUrl, retriesLeft, paths);
			}
		}.launch();
	}
	
	private void batchRequest(final Set<String> paths) {
		batchRequest(paths, kNumBatchRetries);
	}
	
	private void batchRequest(final Set<String> paths, final int numRetries) {
	    OFLog.i(TAG, String.format("Syncing %d items", paths.size()));

		OrderedArgList oal = new OrderedArgList();
		
		for (String s : paths) {
			final ManifestItem manifestItem = serverManifest.objects.get(s);
			oal.put("files[][path]", manifestItem.path);
			oal.put("files[][hash]", manifestItem.hash);
		}
		
		new BaseRequest(oal) {
			@Override public boolean signed() { return false; }
			@Override public String method() { return "POST"; }
			@Override public String path() { return "/webui/assets"; }
			@Override protected void onResponseOffMainThread(int responseCode, byte[] body) {
				handleBatchBody(responseCode, body, url(), currentURL(), numRetries, paths);
			}
			@Override public void onResponse(int responseCode, byte[] body) {} // nop, all the interesting this happens off main thread
		}.launch();
	}
	
	private void handleBatchBody(final int responseCode, final byte[] body, final String originalUrl, final String currentUrl, final int retriesLeft, final Set<String> paths) {
		if (200 <= responseCode && responseCode < 300) {
			processBatch(paths, body);
		} else if (302 == responseCode || 303 == responseCode) {
			// redirect without decreasing the retry counter.
			batchFetch(originalUrl, currentUrl, retriesLeft, paths);
		} else if (0 == responseCode || (400 <= responseCode && responseCode < 500)) {
			if (retriesLeft > 0) {
				// sleep and retry
				mDelayHandler.postDelayed(new Runnable() {
					@Override public void run() {
						if (originalUrl.equals(currentUrl)) {
							// We haven't even gotten past the redirect yet!  Do the POST again.
							batchRequest(paths, retriesLeft-1);
						} else {
							batchFetch(originalUrl, currentUrl, retriesLeft-1, paths);
						}
					}
				}, kBatchRetryDelayMillis);
			} else {
				// failure
				Message msg = Message.obtain(mHandler, kBatchLoaded, 0, 0, paths); 
				msg.sendToTarget();
			}
		} else {
			// no good.  give up.
			Message msg = Message.obtain(mHandler, kBatchLoaded, 0, 0, paths); 
			msg.sendToTarget();
		}
	}
	
	private void finishGlobals() {
		//now scan the trackedPath items and callback any that aren't being loaded
		//this is done second pass so it will find already loaded items or ones not in manifest
		for(PathAndCallback pathAndCb : trackedPaths) {
			if(!pathsToLoad.contains(pathAndCb.path)) {
				pathAndCb.callback.pathLoaded(pathAndCb.path);
			}
			else {
				//still needs loading, move to the item tracking
				ManifestItem item = serverManifest.objects.get(pathAndCb.path);
				ManifestItem newItem = new ManifestItem(item);
				newItem.dependentObjects.retainAll(pathsToLoad);
				trackedItems.put(pathAndCb.path, new ItemAndCallback(newItem, pathAndCb.callback));
			}
		}
		trackedPaths.clear();
					
		//now check the prioritized items and add any dependencies
		Set<String> priorityDependents = new HashSet<String>();
		for(String path : prioritizedPaths) {
			if(!pathsToLoad.contains(path)) continue;
			ManifestItem item = serverManifest.objects.get(path);
			if(item != null) {
				priorityDependents.addAll(item.dependentObjects);
			}
		}
		priorityDependents.retainAll(pathsToLoad);  //keep only the ones we really want
		prioritizedPaths.addAll(priorityDependents);
		
		globalsFinished = true;
	}
	
	private void loadNextItem() {
	    OFLog.i(TAG, "loadNextItem");
		serverManifest.globals.retainAll(pathsToLoad);  //cleanup of anything not in the loading item list
		
		if (!globalsFinished && serverManifest.globals.isEmpty()) {
			finishGlobals();
		}
		
		prioritizedPaths.retainAll(pathsToLoad);  //technically, this should be redundant, but I'm being defensive
		
		int numGlobalsAndPrioritized = serverManifest.globals.size() + prioritizedPaths.size();
		
		if (!batchesAreBroken && numGlobalsAndPrioritized > 1) {
			Set<String> combinedGlobalsAndPrio = new HashSet<String>();
			combinedGlobalsAndPrio.addAll(serverManifest.globals);
			combinedGlobalsAndPrio.addAll(prioritizedPaths);
			batchRequest(combinedGlobalsAndPrio);
		}
		else if(serverManifest.globals.size() > 0) {
			singleRequest(serverManifest.globals.iterator().next());
		}
		else if(prioritizedPaths.size() > 0) {
			singleRequest(prioritizedPaths.iterator().next());
		}			
		else if(!batchesAreBroken && pathsToLoad.size() > 1) {
			batchRequest(pathsToLoad);
		}
		else if(pathsToLoad.size() > 0) {
			singleRequest(pathsToLoad.iterator().next());
		}
		else {
			finishLoading();
		}
	}
	
	private final void singleRequest(final String finalPath) {
	    OFLog.i(TAG, "Syncing item: "+ finalPath);
	    
		new BaseRequest() {
			@Override public boolean signed() { return false; }
			@Override public String method() { return "GET"; }
			@Override public String path() { return "/webui/" + finalPath; }
			@Override public void onResponse(int responseCode, byte[] body) {
				if(responseCode != 200) {
					Message msg = Message.obtain(mHandler, kDataLoaded, 0, 0, finalPath); 
					msg.sendToTarget();
					return;					
				}
				try {
					Util.saveFile(body, rootPath + finalPath);
				} catch (Exception e) {
					//anything goes wrong, just fail out
					Message msg = Message.obtain(mHandler, kDataLoaded, 0, 0, finalPath); 
					msg.sendToTarget();
					return;
				}
				//TODO:  handle thread interruptions?
				Message msg = Message.obtain(mHandler, kDataLoaded, 1, 0, finalPath); 
				msg.sendToTarget();
			}
		}.launch();
	}

	private void finishItem(String path, boolean succeeded) {
		HashSet<String> tiny = new HashSet<String>(1);
		tiny.add(path);
		finishItems(tiny, succeeded, true);
	}

	private void finishItems(Set<String> paths, boolean succeeded) {
		finishItems(paths, succeeded, false);
	}

	private void finishItems(Set<String> paths, boolean succeeded, boolean wasSingular) {
		if (serverManifest == null) return;
		
		if (!succeeded && !wasSingular) {
			// There was a failure in downloading the batch.
			// revert to single-item downloads and continue.
			batchesAreBroken = true;
		} else {
			//first pass, remove from items to load, and dependencies
			for(ItemAndCallback itemAndCb : trackedItems.values()) {
				itemAndCb.item.dependentObjects.removeAll(paths);
			}
			pathsToLoad.removeAll(paths);
			serverManifest.globals.removeAll(paths);
			prioritizedPaths.removeAll(paths);
	
			//second pass, send callbacks if a tracked item doesn't have anything more to load
			if (globalsFinished) {
				HashSet<String> pathsToRemove = new HashSet<String>();		
				for(ItemAndCallback itemAndCb: trackedItems.values()) {
					if(!pathsToLoad.contains(itemAndCb.item.path) && itemAndCb.item.dependentObjects.size() == 0) {
						pathsToRemove.add(itemAndCb.item.path);
						itemAndCb.callback.pathLoaded(itemAndCb.item.path);
					}
				}
		
				for(String removePath: pathsToRemove) {
					trackedItems.remove(removePath);
				}
			}
	
			//update local manifest
			String pathsArray[] = new String[paths.size()];
			String hashArray[] = new String[pathsArray.length];
			int i=0;
			for (String path : paths) {
				final String hashValue = succeeded ? serverManifest.objects.get(path).hash : "INVALID";

				pathsArray[i] = path;
				hashArray[i] = hashValue;
				++i;
				
				clientManifest.put(path, hashValue);
			}
			DB.setClientManifestBatch(pathsArray, hashArray);
		}

		loadNextItem();
	}
	
	private void prioritizeInner(String path) {
		if(loadingFinished) return;  
		prioritizedPaths.add(path);
		if(serverManifest != null) {
			//have the manifest, so add all the dependencies			
			ManifestItem item = serverManifest.objects.get(path);
			if(item != null) {				
				Set<String> loadingDependents = new HashSet<String>(item.dependentObjects);
//				OpenFeintInternal.log("WebViewCache", "Dep:" + loadingDependents.toString());
//				OpenFeintInternal.log("WebViewCache", "TOTAL:" + pathsToLoad.toString());
				loadingDependents.retainAll(pathsToLoad);
				prioritizedPaths.addAll(loadingDependents);
				OFLog.i("WebViewCache", "Prioritizing " + path + " deps:" + loadingDependents.toString());
			}
		}

	}

	// run this off the main thread, there is computation that happens here.
	private void processBatch(final Set<String> paths, final byte[] body) {

		// qualified success.
		final HashSet<String> fetchedPaths = new HashSet<String>();
		final ZipInputStream zis = new ZipInputStream(new ByteArrayInputStream(body));
		try {
			ZipEntry ze = null;
			while ((ze = zis.getNextEntry()) != null) {
				if (!ze.isDirectory()) {
					final String finalPath = ze.getName();
					Util.saveStreamAndLeaveInputOpen(zis, rootPath + finalPath);
					fetchedPaths.add(finalPath);
				}
			}
		} catch (Exception e) {
			// That's sad
		    OFLog.e(TAG, e.getMessage());
		}

		if (!fetchedPaths.isEmpty()) {
			Message msg = Message.obtain(mHandler, kBatchLoaded, 1, 0, fetchedPaths); 
			msg.sendToTarget();
		} else {
			Message msg = Message.obtain(mHandler, kBatchLoaded, 0, 0, paths); 
			msg.sendToTarget();
		}
	}	
	
	// For testing use only!
	public static class TestOnlyManifestItem {
		public String path;
		public String clientHash;
		public String serverHash;
		public TestOnlyManifestItem(String _path, String _clientHash, String _serverHash) {
			path = _path;
			clientHash = _clientHash;
			serverHash = _serverHash;
		}
		public enum Status {
			NotYetDownloaded,
			NotOnServer,
			UpToDate,
			OutOfDate,
		}
		public Status status() {
			if (null == clientHash) return Status.NotYetDownloaded;
			if (null == serverHash) return Status.NotOnServer;
			if (serverHash.equals(clientHash)) return Status.UpToDate;
			return Status.OutOfDate;
		}
		public void invalidate() {
			// clear it in the DB
			DB.setClientManifest(path, "INVALID");
			// clear it in the in-memory client manifest
			sInstance.clientManifest.put(path, "INVALID");
			// remove it from the file system
			Util.deleteFiles(new File(rootPath + path));
			// Trigger a sync
			sInstance.markSyncRequired();
		}
		public static void syncAndOpenDashboard() {
			if (!sInstance.loadingFinished) {
				sInstance.serverManifest = null;
				sInstance.sync();
			}
			Dashboard.open();
		}
		
	}
	
	// In sqlite, you simulate a full outer join by UNIONing together two left outer joins with the tables switched.
	// This is just a convenience function for generating this query in a slightly more readable manner.
	private static String fullOuterJoin(String fields, String table1, String table2, String condition) {
		String join1 = String.format("SELECT %s from %s LEFT OUTER JOIN %s ON %s", fields, table1, table2, condition);
		String join2 = String.format("SELECT %s from %s LEFT OUTER JOIN %s ON %s", fields, table2, table1, condition);
		return String.format("%s UNION %s;", join1, join2);
	}
	
	public static TestOnlyManifestItem[] testOnlyManifestItems() {
		final SQLiteDatabase db = DB.storeHelper.getReadableDatabase();

		Cursor result = null;
		
		ArrayList<TestOnlyManifestItem> items = new ArrayList<TestOnlyManifestItem>();
		try {
			result = db.rawQuery(
				fullOuterJoin("server_manifest.path, server_manifest.hash, manifest.hash", "server_manifest", "manifest", "server_manifest.path = manifest.path"), null);

			if(result.getCount() > 0) {
				result.moveToFirst();
				do {
					String path = result.getString(0);
					if (path != null) {  // yes, this actually happened to me
						String serverHash = result.getString(1);
						String clientHash = result.getString(2);
						items.add(new TestOnlyManifestItem(path, clientHash, serverHash));
					}
				} while (result.moveToNext());
			}
		} catch (Exception e) {
		} finally {
			try { result.close(); } catch (Exception e) {}
		}
		
		// sort rv by path
		TestOnlyManifestItem[] rv = items.toArray(new TestOnlyManifestItem[]{});
		Arrays.sort(rv, new Comparator<TestOnlyManifestItem>() {
			@Override public int compare(TestOnlyManifestItem lhs, TestOnlyManifestItem rhs) {
				return lhs.path.compareTo(rhs.path);
			}
		});
		
		return rv;
	}

}
