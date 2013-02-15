#ifndef INCLUDED_com_mybo_common_CrabMotion
#define INCLUDED_com_mybo_common_CrabMotion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,CrabMotion)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapMovieClip)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS1(haxe,Timer)
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


class CrabMotion_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef CrabMotion_obj OBJ_;
		CrabMotion_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CrabMotion_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CrabMotion_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("CrabMotion"); }

		::com::mybo::framework::display::BitmapMovieClip crab; /* REM */ 
		::com::mybo::framework::tweener::MTween tweener; /* REM */ 
		::haxe::Timer timer; /* REM */ 
		bool active; /* REM */ 
		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void disableSFX( );
		Dynamic disableSFX_dyn();

		virtual Void enableSFX( );
		Dynamic enableSFX_dyn();

		virtual Void onComplete( );
		Dynamic onComplete_dyn();

		virtual int randomDelay( );
		Dynamic randomDelay_dyn();

		virtual double randomLeft( );
		Dynamic randomLeft_dyn();

		virtual double randomRight( );
		Dynamic randomRight_dyn();

		static double RIGHT_EDGE; /* REM */ 
		static double LEFT_EDGE; /* REM */ 
		static double MID_EDGE; /* REM */ 
		static double EDGE_OFFSET; /* REM */ 
		static double TWEEN_TIME; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_CrabMotion */ 
