#ifndef INCLUDED_com_mybo_ui_LevelFailedUI
#define INCLUDED_com_mybo_ui_LevelFailedUI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS3(com,mybo,ui,LevelFailedUI)
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


class LevelFailedUI_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef LevelFailedUI_obj OBJ_;
		LevelFailedUI_obj();
		Void __construct(int level,Dynamic __o_inMaster);

	public:
		static hx::ObjectPtr< LevelFailedUI_obj > __new(int level,Dynamic __o_inMaster);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LevelFailedUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("LevelFailedUI"); }

		::nmex::display::Bitmap background; /* REM */ 
		::nmex::display::Bitmap title; /* REM */ 
		::com::mybo::common::ScaleEffectButton menuButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton retryButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton hitButton; /* REM */ 
		::nme::display::Sprite tipContainer; /* REM */ 
		::nme::display::Sprite buttonContainer; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_LevelFailedUI */ 
