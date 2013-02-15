#ifndef INCLUDED_com_mybo_ui_PauseUI
#define INCLUDED_com_mybo_ui_PauseUI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS3(com,mybo,ui,PauseUI)
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


class PauseUI_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef PauseUI_obj OBJ_;
		PauseUI_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PauseUI_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PauseUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PauseUI"); }

		::nmex::display::Bitmap title; /* REM */ 
		::com::mybo::common::ScaleEffectButton resumeButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton menuButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton retryButton; /* REM */ 
		::nme::display::Sprite menuContainer; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_PauseUI */ 
