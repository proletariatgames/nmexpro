#ifndef INCLUDED_com_mybo_effects_BubblesEffect
#define INCLUDED_com_mybo_effects_BubblesEffect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,effects,BubbleCell)
HX_DECLARE_CLASS3(com,mybo,effects,BubblesEffect)
HX_DECLARE_CLASS2(nme,display,BitmapData)
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
namespace effects{


class BubblesEffect_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef BubblesEffect_obj OBJ_;
		BubblesEffect_obj();
		Void __construct(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size,Dynamic __o_picFlag);

	public:
		static hx::ObjectPtr< BubblesEffect_obj > __new(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size,Dynamic __o_picFlag);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BubblesEffect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BubblesEffect"); }

		Array< ::com::mybo::effects::BubbleCell > balls; /* REM */ 
		int length; /* REM */ 
		int staticLength; /* REM */ 
		::nme::display::Sprite view; /* REM */ 
		int time; /* REM */ 
		int staticTime; /* REM */ 
		double xx; /* REM */ 
		double yy; /* REM */ 
		double rate; /* REM */ 
		double delay; /* REM */ 
		double size; /* REM */ 
		int flag; /* REM */ 
		::nme::display::BitmapData texture; /* REM */ 
		double radius; /* REM */ 
		virtual Void start( );
		Dynamic start_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void reStart( );
		Dynamic reStart_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void onEnterFrame( ::nme::events::Event e);
		Dynamic onEnterFrame_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace effects

#endif /* INCLUDED_com_mybo_effects_BubblesEffect */ 
