#ifndef INCLUDED_com_mybo_framework_display_BitmapButton
#define INCLUDED_com_mybo_framework_display_BitmapButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/display/BitmapObject.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
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


class BitmapButton_obj : public ::com::mybo::framework::display::BitmapObject_obj{
	public:
		typedef ::com::mybo::framework::display::BitmapObject_obj super;
		typedef BitmapButton_obj OBJ_;
		BitmapButton_obj();
		Void __construct(::com::mybo::framework::resource::BitmapTile tile,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj);

	public:
		static hx::ObjectPtr< BitmapButton_obj > __new(::com::mybo::framework::resource::BitmapTile tile,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapButton"); }

		::nme::display::Sprite hit; /* REM */ 
		Dynamic onClick; /* REM */ 
		Dynamic onClickObj; /* REM */ 
		Dynamic onClickParams; /* REM */ 
		bool _enable; /* REM */ 
		bool downInside; /* REM */ 
		virtual Void onMouseDown( ::nme::events::Event e);
		Dynamic onMouseDown_dyn();

		virtual Void onMouseUp( ::nme::events::Event e);
		Dynamic onMouseUp_dyn();

		virtual Void onMouseOut( ::nme::events::Event e);
		Dynamic onMouseOut_dyn();

		virtual Void click( Dynamic onClick,Dynamic params,Dynamic onClickObj);
		Dynamic click_dyn();

		virtual Void enable( Dynamic value);
		Dynamic enable_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapButton */ 
