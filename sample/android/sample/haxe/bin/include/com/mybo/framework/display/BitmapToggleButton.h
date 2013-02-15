#ifndef INCLUDED_com_mybo_framework_display_BitmapToggleButton
#define INCLUDED_com_mybo_framework_display_BitmapToggleButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/display/BitmapButton.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapToggleButton)
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


class BitmapToggleButton_obj : public ::com::mybo::framework::display::BitmapButton_obj{
	public:
		typedef ::com::mybo::framework::display::BitmapButton_obj super;
		typedef BitmapToggleButton_obj OBJ_;
		BitmapToggleButton_obj();
		Void __construct(::com::mybo::framework::resource::BitmapTile tile);

	public:
		static hx::ObjectPtr< BitmapToggleButton_obj > __new(::com::mybo::framework::resource::BitmapTile tile);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapToggleButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapToggleButton"); }

		int currentState; /* REM */ 
		virtual Void toggle( int index);
		Dynamic toggle_dyn();

		virtual Void onMouseDown( ::nme::events::Event e);
		Dynamic onMouseDown_dyn();

		virtual Void onMouseUp( ::nme::events::Event e);
		Dynamic onMouseUp_dyn();

		virtual Void onMouseOut( ::nme::events::Event e);
		Dynamic onMouseOut_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapToggleButton */ 
