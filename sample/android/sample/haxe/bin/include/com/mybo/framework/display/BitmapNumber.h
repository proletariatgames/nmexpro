#ifndef INCLUDED_com_mybo_framework_display_BitmapNumber
#define INCLUDED_com_mybo_framework_display_BitmapNumber

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/display/BitmapObject.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapNumber)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace display{


class BitmapNumber_obj : public ::com::mybo::framework::display::BitmapObject_obj{
	public:
		typedef ::com::mybo::framework::display::BitmapObject_obj super;
		typedef BitmapNumber_obj OBJ_;
		BitmapNumber_obj();
		Void __construct(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_smooth);

	public:
		static hx::ObjectPtr< BitmapNumber_obj > __new(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_smooth);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapNumber_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapNumber"); }

		double tileWidth; /* REM */ 
		int value; /* REM */ 
		virtual Void drawNumber( int num);
		Dynamic drawNumber_dyn();

		virtual Void drawNumberByString( ::String num);
		Dynamic drawNumberByString_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapNumber */ 
