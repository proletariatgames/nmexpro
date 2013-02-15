#ifndef INCLUDED_com_mybo_ui_GameUI
#define INCLUDED_com_mybo_ui_GameUI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,Background)
HX_DECLARE_CLASS3(com,mybo,common,GameMode)
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapNumber)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS3(com,mybo,ui,GameUI)
HX_DECLARE_CLASS3(com,mybo,ui,TouchLeftBar)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace ui{


class GameUI_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef GameUI_obj OBJ_;
		GameUI_obj();
		Void __construct(::com::mybo::common::GameMode gameMode);

	public:
		static hx::ObjectPtr< GameUI_obj > __new(::com::mybo::common::GameMode gameMode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameUI"); }

		::com::mybo::common::ScaleEffectButton pauseButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton hint; /* REM */ 
		::com::mybo::framework::display::BitmapNumber level; /* REM */ 
		::com::mybo::framework::display::BitmapNumber score; /* REM */ 
		::com::mybo::ui::TouchLeftBar touchLeft; /* REM */ 
		::nme::display::Sprite gameBoardView; /* REM */ 
		::nme::display::Sprite effectLayer; /* REM */ 
		::nme::display::Sprite uiLayer; /* REM */ 
		::com::mybo::common::Background background; /* REM */ 
		virtual Void updateValue( int level,int score,int touches,double maxTouches);
		Dynamic updateValue_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_GameUI */ 
