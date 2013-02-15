#ifndef INCLUDED_com_mybo_gamescene_GameBoard
#define INCLUDED_com_mybo_gamescene_GameBoard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,data,Map)
HX_DECLARE_CLASS3(com,mybo,gamescene,BlastNode)
HX_DECLARE_CLASS3(com,mybo,gamescene,Bubble)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameBoard)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace gamescene{


class GameBoard_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef GameBoard_obj OBJ_;
		GameBoard_obj();
		Void __construct(::com::mybo::data::Map inMap,::nme::display::Sprite inView,::String inBubbleTextureID);

	public:
		static hx::ObjectPtr< GameBoard_obj > __new(::com::mybo::data::Map inMap,::nme::display::Sprite inView,::String inBubbleTextureID);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameBoard_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameBoard"); }

		::com::mybo::data::Map map; /* REM */ 
		double flySpeed; /* REM */ 
		Array< ::com::mybo::gamescene::Bubble > bubblePool; /* REM */ 
		Array< ::com::mybo::gamescene::BlastNode > blastNodePool; /* REM */ 
		bool touchAble; /* REM */ 
		int frames; /* REM */ 
		::nme::display::Sprite bubbleLayer; /* REM */ 
		::String bubbleTextureID; /* REM */ 
		int genBubbleFlag; /* REM */ 
		int genBubbleCount; /* REM */ 
		virtual Void init( ::com::mybo::data::Map inMap);
		Dynamic init_dyn();

		virtual Void genBubble( ::nme::events::Event e);
		Dynamic genBubble_dyn();

		virtual Void setBubbleTextureID( ::String id);
		Dynamic setBubbleTextureID_dyn();

		virtual Void pause( );
		Dynamic pause_dyn();

		virtual Void resume( );
		Dynamic resume_dyn();

		virtual Void disable( );
		Dynamic disable_dyn();

		virtual Void startTouch( );
		Dynamic startTouch_dyn();

		virtual Void motionClean( );
		Dynamic motionClean_dyn();

		virtual Void clean( );
		Dynamic clean_dyn();

		virtual Void cleanTimers( );
		Dynamic cleanTimers_dyn();

		virtual Array< ::com::mybo::gamescene::Bubble > getBubbles( );
		Dynamic getBubbles_dyn();

		virtual Void onTap( ::nme::events::MouseEvent e);
		Dynamic onTap_dyn();

		virtual Void blast( ::com::mybo::gamescene::Bubble bubble);
		Dynamic blast_dyn();

		virtual Void onEnterFrame( ::nme::events::Event e);
		Dynamic onEnterFrame_dyn();

		virtual Void blastChainCheck( );
		Dynamic blastChainCheck_dyn();

		virtual int nodeSort( ::com::mybo::gamescene::BlastNode nodeA,::com::mybo::gamescene::BlastNode nodeB);
		Dynamic nodeSort_dyn();

		virtual bool isBlastChainComplete( );
		Dynamic isBlastChainComplete_dyn();

		virtual bool checkLevelFinished( );
		Dynamic checkLevelFinished_dyn();

		virtual Void draw( );
		Dynamic draw_dyn();

		virtual bool isLegalBlastNode( ::com::mybo::gamescene::BlastNode node);
		Dynamic isLegalBlastNode_dyn();

		virtual bool collisionDetection( ::com::mybo::gamescene::Bubble bubble,::com::mybo::gamescene::BlastNode blastNode);
		Dynamic collisionDetection_dyn();

		virtual Void emptyArray( Dynamic array);
		Dynamic emptyArray_dyn();

		::nme::display::Sprite touchLayer; /* REM */ 
		virtual Void drawTouchArea( );
		Dynamic drawTouchArea_dyn();

		static int gameBoardWidth; /* REM */ 
		static int gameBoardHeight; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_GameBoard */ 
