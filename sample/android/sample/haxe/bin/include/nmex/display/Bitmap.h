#ifndef INCLUDED_nmex_display_Bitmap
#define INCLUDED_nmex_display_Bitmap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nmex/display/DisplayObject.h>
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,PixelSnapping)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
HX_DECLARE_CLASS2(nmex,display,Graphics)
namespace nmex{
namespace display{


class Bitmap_obj : public ::nmex::display::DisplayObject_obj{
	public:
		typedef ::nmex::display::DisplayObject_obj super;
		typedef Bitmap_obj OBJ_;
		Bitmap_obj();
		Void __construct(::nme::display::BitmapData inBitmapData,::nme::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing);

	public:
		static hx::ObjectPtr< Bitmap_obj > __new(::nme::display::BitmapData inBitmapData,::nme::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bitmap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bitmap"); }

		::nme::display::BitmapData bitmapData; /* REM */ 
		::nme::display::PixelSnapping pixelSnapping; /* REM */ 
		bool smoothing; /* REM */ 
		::nmex::display::Graphics mGraphics; /* REM */ 
		virtual Void nmeRebuid( );
		Dynamic nmeRebuid_dyn();

		virtual ::nme::display::BitmapData nmeSetBitmapData( ::nme::display::BitmapData inBitmapData);
		Dynamic nmeSetBitmapData_dyn();

		virtual bool nmeSetSmoothing( bool inSmooth);
		Dynamic nmeSetSmoothing_dyn();

};

} // end namespace nmex
} // end namespace display

#endif /* INCLUDED_nmex_display_Bitmap */ 
