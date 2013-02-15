#ifndef INCLUDED_com_mybo_gamescene_MasterScene
#define INCLUDED_com_mybo_gamescene_MasterScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS3(com,mybo,data,Map)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameBoard)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameStatus)
HX_DECLARE_CLASS3(com,mybo,gamescene,MasterScene)
HX_DECLARE_CLASS3(com,mybo,ui,GameUI)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace gamescene{


class MasterScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef MasterScene_obj OBJ_;
		MasterScene_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MasterScene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MasterScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MasterScene"); }

		::com::mybo::gamescene::GameBoard gameBoard; /* REM */ 
		::com::mybo::data::Map map; /* REM */ 
		int pack; /* REM */ 
		int level; /* REM */ 
		int score; /* REM */ 
		int touches; /* REM */ 
		int maxTouches; /* REM */ 
		int blastCombo; /* REM */ 
		::com::mybo::gamescene::GameStatus status; /* REM */ 
		::com::mybo::ui::GameUI page; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void sceneDidAppear( );
		Dynamic sceneDidAppear_dyn();

		virtual Void onBubbleTapComplete( ::nme::events::Event e);
		Dynamic onBubbleTapComplete_dyn();

		virtual Void onBubbleBlast( ::nme::events::Event e);
		Dynamic onBubbleBlast_dyn();

		virtual Void onTouchBubble( ::nme::events::Event e);
		Dynamic onTouchBubble_dyn();

		virtual Void levelComplete( ::nme::events::Event e);
		Dynamic levelComplete_dyn();

		virtual Void pause( );
		Dynamic pause_dyn();

		virtual Void resume( );
		Dynamic resume_dyn();

		virtual Void retry( );
		Dynamic retry_dyn();

		virtual Void back( );
		Dynamic back_dyn();

		virtual Void gameOver( );
		Dynamic gameOver_dyn();

		virtual Void resetMaster( );
		Dynamic resetMaster_dyn();

		virtual Void showTip( );
		Dynamic showTip_dyn();

		virtual Void startHintMode( );
		Dynamic startHintMode_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_MasterScene */ 
