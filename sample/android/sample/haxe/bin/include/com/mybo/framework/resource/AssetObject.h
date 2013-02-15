#ifndef INCLUDED_com_mybo_framework_resource_AssetObject
#define INCLUDED_com_mybo_framework_resource_AssetObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,resource,AssetObject)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace com{
namespace mybo{
namespace framework{
namespace resource{


class AssetObject_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AssetObject_obj OBJ_;
		AssetObject_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AssetObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AssetObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AssetObject"); }

		int tileWidth; /* REM */ 
		int tileHeight; /* REM */ 
		int cols; /* REM */ 
		int frameNumber; /* REM */ 
		::String typeInfo; /* REM */ 
		::String id; /* REM */ 
		::String folder; /* REM */ 
		bool optimized; /* REM */ 
		int scale; /* REM */ 
		Array< ::String > url; /* REM */ 
		::nme::display::BitmapData bitmapData; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource

#endif /* INCLUDED_com_mybo_framework_resource_AssetObject */ 
