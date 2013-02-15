#ifndef INCLUDED_com_mybo_framework_display_TouchUpDownContainer
#define INCLUDED_com_mybo_framework_display_TouchUpDownContainer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS4(com,mybo,framework,display,TouchUpDownContainer)
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
namespace framework{
namespace display{


class TouchUpDownContainer_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef TouchUpDownContainer_obj OBJ_;
		TouchUpDownContainer_obj();
		Void __construct(double width,double height,::nmex::display::DisplayObject view);

	public:
		static hx::ObjectPtr< TouchUpDownContainer_obj > __new(double width,double height,::nmex::display::DisplayObject view);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TouchUpDownContainer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TouchUpDownContainer"); }

		::nme::display::Sprite touchContainer; /* REM */ 
		::nmex::display::DisplayObject view; /* REM */ 
		bool isMouseDown; /* REM */ 
		bool isActive; /* REM */ 
		bool isRunEnterFrame; /* REM */ 
		double pre; /* REM */ 
		double speed; /* REM */ 
		double visualWidth; /* REM */ 
		double visualHeight; /* REM */ 
		double preTime; /* REM */ 
		virtual Void onDown( ::nme::events::Event e);
		Dynamic onDown_dyn();

		virtual Void onMove( ::nme::events::Event e);
		Dynamic onMove_dyn();

		virtual Void onOut( ::nme::events::Event e);
		Dynamic onOut_dyn();

		virtual Void onUp( ::nme::events::Event e);
		Dynamic onUp_dyn();

		virtual Void onEnterFrame( ::nme::events::Event e);
		Dynamic onEnterFrame_dyn();

		virtual bool moveAble( );
		Dynamic moveAble_dyn();

		virtual Void positionFix( );
		Dynamic positionFix_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		static int REDUCE_VALUE; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_TouchUpDownContainer */ 
