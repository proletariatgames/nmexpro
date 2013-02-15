#ifndef INCLUDED_com_mybo_ui_GameOverUI
#define INCLUDED_com_mybo_ui_GameOverUI

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
HX_DECLARE_CLASS3(com,mybo,ui,GameOverUI)
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


class GameOverUI_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef GameOverUI_obj OBJ_;
		GameOverUI_obj();
		Void __construct(int inScore,int inBestScore,int inLevel,Dynamic __o_inStar);

	public:
		static hx::ObjectPtr< GameOverUI_obj > __new(int inScore,int inBestScore,int inLevel,Dynamic __o_inStar);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameOverUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameOverUI"); }

		::nmex::display::Bitmap background; /* REM */ 
		::nmex::display::Bitmap title; /* REM */ 
		::com::mybo::common::ScaleEffectButton menuButton; /* REM */ 
		::com::mybo::common::ScaleEffectButton retryButton; /* REM */ 
		::nmex::display::Bitmap newRecord; /* REM */ 
		::nmex::display::Bitmap bestScoreTitle; /* REM */ 
		::com::mybo::framework::display::BitmapNumber bestScoreNum; /* REM */ 
		::com::mybo::framework::display::BitmapNumber scoreNum; /* REM */ 
		int score; /* REM */ 
		int bestScore; /* REM */ 
		int rewardStar; /* REM */ 
		int level; /* REM */ 
		::com::mybo::framework::core::Facade facade; /* REM */ 
		double stageWidth; /* REM */ 
		double stageHeight; /* REM */ 
		virtual Void startMotion( );
		Dynamic startMotion_dyn();

		virtual Void scoreMotionComplete( );
		Dynamic scoreMotionComplete_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace ui

#endif /* INCLUDED_com_mybo_ui_GameOverUI */ 
