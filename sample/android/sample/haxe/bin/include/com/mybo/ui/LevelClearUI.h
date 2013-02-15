#ifndef INCLUDED_com_mybo_ui_LevelClearUI
#define INCLUDED_com_mybo_ui_LevelClearUI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapNumber)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS3(com,mybo,ui,LevelClearUI)
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


class LevelClearUI_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef LevelClearUI_obj OBJ_;
		LevelClearUI_obj();
		Void __construct(int level);

	public:
		static hx::ObjectPtr< LevelClearUI_obj > __new(int level);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LevelClearUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("LevelClearUI"); }

		::nmex::display::Bitmap background; /* REM */ 
		::nmex::display::Bitmap title; /* REM */ 
		::nmex::display::Bitmap levelTitle; /* REM */ 
		::com::mybo::framework::display::BitmapNumber levelNum; /* REM */ 
		::com::mybo::common::ScaleEffectButton retryButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton menuButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton nextButton; /* REM */ 
		::nme::display::Sprite buttonContainer; /* REM */ 
		::com::mybo::framework::core::Facade facade; /* REM */ 
		double stageWidth; /* REM */ 
		double stageHeight; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_LevelClearUI */ 
