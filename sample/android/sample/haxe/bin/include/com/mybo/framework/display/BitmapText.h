#ifndef INCLUDED_com_mybo_framework_display_BitmapText
#define INCLUDED_com_mybo_framework_display_BitmapText

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/display/BitmapObject.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapText)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,KeyboardEvent)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace display{


class BitmapText_obj : public ::com::mybo::framework::display::BitmapObject_obj{
	public:
		typedef ::com::mybo::framework::display::BitmapObject_obj super;
		typedef BitmapText_obj OBJ_;
		BitmapText_obj();
		Void __construct(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_editAllowed,Dynamic __o_editlimit);

	public:
		static hx::ObjectPtr< BitmapText_obj > __new(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_editAllowed,Dynamic __o_editlimit);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapText_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapText"); }

		::String text; /* REM */ 
		bool editAllowed; /* REM */ 
		::nme::display::Sprite touchLayer; /* REM */ 
		bool anchorCenter; /* REM */ 
		int lengthLimit; /* REM */ 
		Dynamic onComplete; /* REM */ 
		Dynamic onCompleteObj; /* REM */ 
		Dynamic onCompleteParams; /* REM */ 
		virtual Void draw( ::String content);
		Dynamic draw_dyn();

		virtual Void setAnchorCenter( bool enable);
		Dynamic setAnchorCenter_dyn();

		virtual Void setEditCompleteHandle( Dynamic onComplete,Dynamic onCompleteParams,Dynamic onCompleteObj);
		Dynamic setEditCompleteHandle_dyn();

		virtual Void onClick( ::nme::events::MouseEvent e);
		Dynamic onClick_dyn();

		virtual Void onKeyDown( ::nme::events::KeyboardEvent e);
		Dynamic onKeyDown_dyn();

		virtual Void updateText( int charCode);
		Dynamic updateText_dyn();

		static ::String index; /* REM */ 
		static bool hasKeyBoard; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapText */ 
