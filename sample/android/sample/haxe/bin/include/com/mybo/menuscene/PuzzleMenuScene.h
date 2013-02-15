#ifndef INCLUDED_com_mybo_menuscene_PuzzleMenuScene
#define INCLUDED_com_mybo_menuscene_PuzzleMenuScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS3(com,mybo,common,Background)
HX_DECLARE_CLASS3(com,mybo,common,GameEvent)
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS3(com,mybo,menuscene,LevelSelector)
HX_DECLARE_CLASS3(com,mybo,menuscene,PackageSelector)
HX_DECLARE_CLASS3(com,mybo,menuscene,PuzzleMenuScene)
HX_DECLARE_CLASS3(com,mybo,menuscene,UserStar)
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
namespace menuscene{


class PuzzleMenuScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef PuzzleMenuScene_obj OBJ_;
		PuzzleMenuScene_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PuzzleMenuScene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PuzzleMenuScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PuzzleMenuScene"); }

		int selectPack; /* REM */ 
		int selectLevel; /* REM */ 
		::nmex::display::Bitmap title; /* REM */ 
		::com::mybo::common::Background background; /* REM */ 
		::com::mybo::common::ScaleEffectButton backBtn; /* REM */ 
		::com::mybo::menuscene::PackageSelector packSelector; /* REM */ 
		::com::mybo::menuscene::LevelSelector levelSelector; /* REM */ 
		::nme::display::Sprite content; /* REM */ 
		::com::mybo::menuscene::UserStar userStar; /* REM */ 
		virtual Void back( );
		Dynamic back_dyn();

		virtual Void sceneDidAppear( );
		Dynamic sceneDidAppear_dyn();

		virtual Void backToStartMenu( );
		Dynamic backToStartMenu_dyn();

		virtual Void onPackSelect( ::com::mybo::common::GameEvent e);
		Dynamic onPackSelect_dyn();

		virtual Void runLevelSelector( );
		Dynamic runLevelSelector_dyn();

		virtual Void backToPackSelector( );
		Dynamic backToPackSelector_dyn();

		virtual Void showLevelSelector( int id);
		Dynamic showLevelSelector_dyn();

		virtual Void showPackSelector( );
		Dynamic showPackSelector_dyn();

		virtual Void onLevelSelected( ::com::mybo::common::GameEvent e);
		Dynamic onLevelSelected_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_PuzzleMenuScene */ 
