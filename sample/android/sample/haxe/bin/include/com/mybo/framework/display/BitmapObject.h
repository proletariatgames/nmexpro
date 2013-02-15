#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#define INCLUDED_com_mybo_framework_display_BitmapObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/TimerRender.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
HX_DECLARE_CLASS2(nmex,display,Graphics)
namespace com{
namespace mybo{
namespace framework{
namespace display{


class BitmapObject_obj : public ::com::mybo::framework::core::TimerRender_obj{
	public:
		typedef ::com::mybo::framework::core::TimerRender_obj super;
		typedef BitmapObject_obj OBJ_;
		BitmapObject_obj();
		Void __construct(::com::mybo::framework::resource::BitmapTile bitmapTile,Dynamic __o_autoRun,Dynamic __o_drawFirst,Dynamic __o_smooth);

	public:
		static hx::ObjectPtr< BitmapObject_obj > __new(::com::mybo::framework::resource::BitmapTile bitmapTile,Dynamic __o_autoRun,Dynamic __o_drawFirst,Dynamic __o_smooth);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapObject"); }

		::com::mybo::framework::resource::BitmapTile tile; /* REM */ 
		int totalFrames; /* REM */ 
		int currentFrame; /* REM */ 
		bool smooth; /* REM */ 
		::nmex::display::Graphics gfx; /* REM */ 
		virtual Void drawTile( int index,Dynamic x,Dynamic y,Dynamic isClear);
		Dynamic drawTile_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void destroyBD( );
		Dynamic destroyBD_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapObject */ 
