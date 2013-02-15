#ifndef INCLUDED_com_mybo_gamescene_ClassicScene
#define INCLUDED_com_mybo_gamescene_ClassicScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS3(com,mybo,gamescene,ClassicScene)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameBoard)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameStatus)
HX_DECLARE_CLASS3(com,mybo,ui,GameUI)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Shape)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace gamescene{


class ClassicScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef ClassicScene_obj OBJ_;
		ClassicScene_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ClassicScene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ClassicScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ClassicScene"); }

		::com::mybo::gamescene::GameBoard gameBoard; /* REM */ 
		::com::mybo::gamescene::GameStatus status; /* REM */ 
		int level; /* REM */ 
		int score; /* REM */ 
		int touches; /* REM */ 
		int blastCombo; /* REM */ 
		int maxTouches; /* REM */ 
		::com::mybo::ui::GameUI page; /* REM */ 
		::nme::display::Shape maskShape; /* REM */ 
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

		virtual Void levelUp( ::nme::events::Event e);
		Dynamic levelUp_dyn();

		virtual Void nextLevel( );
		Dynamic nextLevel_dyn();

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

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_ClassicScene */ 
