#ifndef INCLUDED_com_mybo_framework_resource_Resource
#define INCLUDED_com_mybo_framework_resource_Resource

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS4(com,mybo,framework,resource,AssetObject)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS4(com,mybo,framework,resource,Resource)
HX_DECLARE_CLASS4(com,mybo,framework,resource,ResourceData)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace resource{


class Resource_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Resource_obj OBJ_;
		Resource_obj();
		Void __construct(::String path,::String xmlFilePath);

	public:
		static hx::ObjectPtr< Resource_obj > __new(::String path,::String xmlFilePath);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Resource_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Resource"); }

		::com::mybo::framework::resource::ResourceData data; /* REM */ 
		::String rootPath; /* REM */ 
		::String sparePath; /* REM */ 
		::Hash bitmapTileHash; /* REM */ 
		virtual Void loadAll( );
		Dynamic loadAll_dyn();

		virtual ::nmex::display::Bitmap getBitmap( ::String id,Dynamic smooth);
		Dynamic getBitmap_dyn();

		virtual Void mergeAlpha( ::nme::display::BitmapData src,::nme::display::BitmapData des);
		Dynamic mergeAlpha_dyn();

		virtual ::com::mybo::framework::resource::BitmapTile getTile( ::String id);
		Dynamic getTile_dyn();

		::nme::display::BitmapData a1; /* REM */ 
		::nme::display::BitmapData a2; /* REM */ 
		::nme::display::BitmapData a3; /* REM */ 
		virtual ::com::mybo::framework::resource::BitmapTile loadBitmap( ::String id);
		Dynamic loadBitmap_dyn();

		virtual ::com::mybo::framework::resource::AssetObject getAssetObject( ::String id);
		Dynamic getAssetObject_dyn();

		virtual Void unLoadAllByFolder( ::String folder);
		Dynamic unLoadAllByFolder_dyn();

		virtual Void loadAllByFolder( ::String folder);
		Dynamic loadAllByFolder_dyn();

		virtual Void destroyResource( ::String id);
		Dynamic destroyResource_dyn();

		virtual Void unLoadAll( );
		Dynamic unLoadAll_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource

#endif /* INCLUDED_com_mybo_framework_resource_Resource */ 
