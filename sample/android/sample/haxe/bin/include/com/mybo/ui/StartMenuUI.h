#ifndef INCLUDED_com_mybo_ui_StartMenuUI
#define INCLUDED_com_mybo_ui_StartMenuUI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,Background)
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapToggleButton)
HX_DECLARE_CLASS3(com,mybo,ui,StartMenuUI)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace ui{


class StartMenuUI_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef StartMenuUI_obj OBJ_;
		StartMenuUI_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StartMenuUI_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StartMenuUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("StartMenuUI"); }

		::com::mybo::common::ScaleEffectButton classicButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton puzzleButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton challengeButton; /* REM */ 
		::nme::display::Sprite settingContainer; /* REM */ 
		::nmex::display::Bitmap settingBG; /* REM */ 
		::com::mybo::framework::display::BitmapButton facebook; /* REM */ 
		::com::mybo::framework::display::BitmapButton twitter; /* REM */ 
		::com::mybo::framework::display::BitmapButton rank; /* REM */ 
		::com::mybo::framework::display::BitmapToggleButton vol; /* REM */ 
		::com::mybo::framework::display::BitmapButton help; /* REM */ 
		::com::mybo::common::ScaleEffectButton settingButton; /* REM */ 
		::com::mybo::common::Background background; /* REM */ 
		::nmex::display::Bitmap logo; /* REM */ 
		::com::mybo::framework::core::Facade facade; /* REM */ 
		virtual Void showMenu( ::nme::events::Event e);
		Dynamic showMenu_dyn();

		virtual Void hideMenu( ::nme::events::Event e);
		Dynamic hideMenu_dyn();

		virtual Void showComplete( );
		Dynamic showComplete_dyn();

		virtual Void hideComplete( );
		Dynamic hideComplete_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_StartMenuUI */ 
