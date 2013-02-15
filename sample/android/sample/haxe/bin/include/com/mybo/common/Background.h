#ifndef INCLUDED_com_mybo_common_Background
#define INCLUDED_com_mybo_common_Background

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,Background)
HX_DECLARE_CLASS3(com,mybo,common,CrabMotion)
HX_DECLARE_CLASS3(com,mybo,common,SwimmingFish)
HX_DECLARE_CLASS3(com,mybo,effects,BubblesEffect)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapMovieClip)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class Background_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef Background_obj OBJ_;
		Background_obj();
		Void __construct(Dynamic __o_isInGame,Dynamic __o_isMasterMenu,Dynamic __o_isInHelp);

	public:
		static hx::ObjectPtr< Background_obj > __new(Dynamic __o_isInGame,Dynamic __o_isMasterMenu,Dynamic __o_isInHelp);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Background_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Background"); }

		::nme::display::Sprite effectLayer; /* REM */ 
		::nme::display::Sprite extraLayer; /* REM */ 
		::com::mybo::effects::BubblesEffect bubbles1; /* REM */ 
		::com::mybo::effects::BubblesEffect bubbles2; /* REM */ 
		::com::mybo::effects::BubblesEffect bubbles3; /* REM */ 
		::com::mybo::common::CrabMotion crab; /* REM */ 
		::com::mybo::framework::display::BitmapMovieClip grassLeft; /* REM */ 
		::com::mybo::framework::display::BitmapMovieClip grassRight; /* REM */ 
		::com::mybo::common::SwimmingFish fishes; /* REM */ 
		bool active; /* REM */ 
		virtual Void addToBackground( ::nmex::display::DisplayObject child);
		Dynamic addToBackground_dyn();

		virtual Void removeFromBackground( ::nmex::display::DisplayObject child);
		Dynamic removeFromBackground_dyn();

		virtual Void stopAnimation( );
		Dynamic stopAnimation_dyn();

		virtual Void startAnimation( );
		Dynamic startAnimation_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_Background */ 
