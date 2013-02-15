#ifndef INCLUDED_com_mybo_ui_TouchLeftBar
#define INCLUDED_com_mybo_ui_TouchLeftBar

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,ProgressBar)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapNumber)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS3(com,mybo,ui,TouchLeftBar)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace ui{


class TouchLeftBar_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef TouchLeftBar_obj OBJ_;
		TouchLeftBar_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TouchLeftBar_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchLeftBar_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchLeftBar"); }

		::nmex::display::Bitmap touchLeftBG; /* REM */ 
		::com::mybo::common::ProgressBar touchLeftBar; /* REM */ 
		::nme::display::Sprite touchLeftText; /* REM */ 
		::com::mybo::framework::display::BitmapNumber touchLeftNum; /* REM */ 
		::com::mybo::framework::tweener::MTween tween; /* REM */ 
		virtual Void update( int touches,double maxTouches);
		Dynamic update_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_TouchLeftBar */ 
