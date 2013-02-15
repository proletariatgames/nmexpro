#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#define INCLUDED_com_mybo_framework_resource_BitmapTile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,Tilesheet)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace com{
namespace mybo{
namespace framework{
namespace resource{


class BitmapTile_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapTile_obj OBJ_;
		BitmapTile_obj();
		Void __construct(::String id,double tileWidth,double tileHeight,::nme::display::BitmapData data);

	public:
		static hx::ObjectPtr< BitmapTile_obj > __new(::String id,double tileWidth,double tileHeight,::nme::display::BitmapData data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapTile_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapTile"); }

		::String id; /* REM */ 
		int totalFrames; /* REM */ 
		::nme::display::BitmapData bitmapData; /* REM */ 
		::nme::display::Tilesheet tilesheet; /* REM */ 
		double height; /* REM */ 
		double width; /* REM */ 
		int scale; /* REM */ 
		Array< ::nme::geom::Rectangle > rects; /* REM */ 
		virtual Void addTileRect( ::nme::geom::Rectangle rect);
		Dynamic addTileRect_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource

#endif /* INCLUDED_com_mybo_framework_resource_BitmapTile */ 
