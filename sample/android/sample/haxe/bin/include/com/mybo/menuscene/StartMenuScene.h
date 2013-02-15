#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#define INCLUDED_com_mybo_menuscene_StartMenuScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS3(com,mybo,menuscene,StartMenuScene)
HX_DECLARE_CLASS3(com,mybo,ui,StartMenuUI)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace menuscene{


class StartMenuScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef StartMenuScene_obj OBJ_;
		StartMenuScene_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StartMenuScene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StartMenuScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("StartMenuScene"); }

		::com::mybo::ui::StartMenuUI startPage; /* REM */ 
		int packSelected; /* REM */ 
		virtual Void sceneDidAppear( );
		Dynamic sceneDidAppear_dyn();

		virtual Void runClassic( );
		Dynamic runClassic_dyn();

		virtual Void runPuzzle( );
		Dynamic runPuzzle_dyn();

		virtual Void runMaster( );
		Dynamic runMaster_dyn();

		virtual Void runHelp( );
		Dynamic runHelp_dyn();

		virtual Void showLeaderBoard( );
		Dynamic showLeaderBoard_dyn();

		virtual Void moreGame( );
		Dynamic moreGame_dyn();

		virtual Void facebook( );
		Dynamic facebook_dyn();

		virtual Void twitter( );
		Dynamic twitter_dyn();

		virtual Void toggleVol( );
		Dynamic toggleVol_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_StartMenuScene */ 
