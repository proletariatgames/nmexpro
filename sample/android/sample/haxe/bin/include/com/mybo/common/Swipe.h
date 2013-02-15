#ifndef INCLUDED_com_mybo_common_Swipe
#define INCLUDED_com_mybo_common_Swipe

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,Swipe)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class Swipe_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef Swipe_obj OBJ_;
		Swipe_obj();
		Void __construct(Array< ::nmex::display::DisplayObject > views,Array< ::nme::display::BitmapData > indicator);

	public:
		static hx::ObjectPtr< Swipe_obj > __new(Array< ::nmex::display::DisplayObject > views,Array< ::nme::display::BitmapData > indicator);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Swipe_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Swipe"); }

		Array< ::nmex::display::DisplayObject > pages; /* REM */ 
		::nme::display::BitmapData indicatorActive; /* REM */ 
		::nme::display::BitmapData indicatorInactive; /* REM */ 
		::nme::display::Sprite indicatorContainer; /* REM */ 
		::nme::display::Sprite pageContainer; /* REM */ 
		::nme::display::Sprite touchView; /* REM */ 
		int index; /* REM */ 
		int pageLength; /* REM */ 
		bool isMouseDown; /* REM */ 
		::nme::geom::Point mouseDownPos; /* REM */ 
		bool isRunEnterFrame; /* REM */ 
		double speed; /* REM */ 
		double preX; /* REM */ 
		::com::mybo::framework::tweener::MTween mtween; /* REM */ 
		virtual Void drawIndicator( );
		Dynamic drawIndicator_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void onDown( ::nme::events::Event e);
		Dynamic onDown_dyn();

		virtual Void onMove( ::nme::events::Event e);
		Dynamic onMove_dyn();

		virtual Void onOut( ::nme::events::Event e);
		Dynamic onOut_dyn();

		virtual Void onUp( ::nme::events::Event e);
		Dynamic onUp_dyn();

		virtual Void positionFix( );
		Dynamic positionFix_dyn();

		static int pageWidth; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_Swipe */ 
