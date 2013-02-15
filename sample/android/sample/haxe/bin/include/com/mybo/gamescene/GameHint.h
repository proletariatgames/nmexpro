#ifndef INCLUDED_com_mybo_gamescene_GameHint
#define INCLUDED_com_mybo_gamescene_GameHint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,common,GameEvent)
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapMovieClip)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameBoard)
HX_DECLARE_CLASS3(com,mybo,gamescene,GameHint)
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


class GameHint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GameHint_obj OBJ_;
		GameHint_obj();
		Void __construct(::com::mybo::gamescene::GameBoard inGameboard,Array< Array< int > > inSolution);

	public:
		static hx::ObjectPtr< GameHint_obj > __new(::com::mybo::gamescene::GameBoard inGameboard,Array< Array< int > > inSolution);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameHint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameHint"); }

		::com::mybo::gamescene::GameBoard gameBoard; /* REM */ 
		Array< Array< int > > solution; /* REM */ 
		int step; /* REM */ 
		int maxStep; /* REM */ 
		::nme::display::Sprite touchArea; /* REM */ 
		::nme::display::Sprite motionLayer; /* REM */ 
		::com::mybo::framework::display::BitmapMovieClip tipMC; /* REM */ 
		::com::mybo::framework::core::Facade facade; /* REM */ 
		virtual Void onTap( ::com::mybo::common::GameEvent e);
		Dynamic onTap_dyn();

		virtual Void onTapComplete( ::com::mybo::common::GameEvent e);
		Dynamic onTapComplete_dyn();

		virtual Void showHint( ::com::mybo::common::GameEvent e);
		Dynamic showHint_dyn();

		virtual double calForInt( double value);
		Dynamic calForInt_dyn();

		virtual Void drawTouchArea( );
		Dynamic drawTouchArea_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void destroy( ::com::mybo::common::GameEvent e);
		Dynamic destroy_dyn();

		static bool running; /* REM */ 
		static ::com::mybo::gamescene::GameHint runningInstance; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_GameHint */ 
