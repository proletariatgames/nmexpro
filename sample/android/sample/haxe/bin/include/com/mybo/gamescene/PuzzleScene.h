#ifndef INCLUDED_com_mybo_gamescene_PuzzleScene
#define INCLUDED_com_mybo_gamescene_PuzzleScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS3(com,mybo,data,Map)
HX_DECLARE_CLASS3(com,mybo,data,UserData)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameBoard)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameStatus)
HX_DECLARE_CLASS3(com,mybo,gamescene,PuzzleScene)
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


class PuzzleScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef PuzzleScene_obj OBJ_;
		PuzzleScene_obj();
		Void __construct(int inPack,int inLevel);

	public:
		static hx::ObjectPtr< PuzzleScene_obj > __new(int inPack,int inLevel);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PuzzleScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PuzzleScene"); }

		::com::mybo::gamescene::GameBoard gameBoard; /* REM */ 
		::com::mybo::data::Map map; /* REM */ 
		int pack; /* REM */ 
		int level; /* REM */ 
		int score; /* REM */ 
		int touches; /* REM */ 
		int maxTouches; /* REM */ 
		int blastCombo; /* REM */ 
		::com::mybo::gamescene::GameStatus status; /* REM */ 
		::com::mybo::data::UserData userData; /* REM */ 
		::com::mybo::ui::GameUI page; /* REM */ 
		::nme::display::Sprite tutorial; /* REM */ 
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

		virtual Void nextLevel( );
		Dynamic nextLevel_dyn();

		virtual bool isPackCompleted( );
		Dynamic isPackCompleted_dyn();

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

		virtual Void showTip( );
		Dynamic showTip_dyn();

		virtual Void startHintMode( );
		Dynamic startHintMode_dyn();

		virtual Void showTutorial( );
		Dynamic showTutorial_dyn();

		virtual Void initTutorial( ::String bitmapID,double x,double y,::nme::display::Sprite container,bool hint);
		Dynamic initTutorial_dyn();

		virtual Void hideTutorial( );
		Dynamic hideTutorial_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_PuzzleScene */ 
