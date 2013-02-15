#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#define INCLUDED_com_mybo_framework_core_TimerRender

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace core{


class TimerRender_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef TimerRender_obj OBJ_;
		TimerRender_obj();
		Void __construct(Dynamic __o_autoRun);

	public:
		static hx::ObjectPtr< TimerRender_obj > __new(Dynamic __o_autoRun);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimerRender_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TimerRender"); }

		bool isRun; /* REM */ 
		virtual Void autoRender( );
		Dynamic autoRender_dyn();

		virtual Void noAutoRender( );
		Dynamic noAutoRender_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		static ::nme::display::Stage stage; /* REM */ 
		static Array< ::com::mybo::framework::core::TimerRender > renderList; /* REM */ 
		static int rate; /* REM */ 
		static Void run( );
		static Dynamic run_dyn();

		static Void onEnterFrame( ::nme::events::Event e);
		static Dynamic onEnterFrame_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core

#endif /* INCLUDED_com_mybo_framework_core_TimerRender */ 
