#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#define INCLUDED_com_mybo_framework_display_BitmapSimpleButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace display{


class BitmapSimpleButton_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef BitmapSimpleButton_obj OBJ_;
		BitmapSimpleButton_obj();
		Void __construct(::nmex::display::Bitmap inBitmap,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj);

	public:
		static hx::ObjectPtr< BitmapSimpleButton_obj > __new(::nmex::display::Bitmap inBitmap,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapSimpleButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapSimpleButton"); }

		::nme::display::Sprite hit; /* REM */ 
		Dynamic onClick; /* REM */ 
		Dynamic onClickObj; /* REM */ 
		Dynamic onClickParams; /* REM */ 
		bool downInside; /* REM */ 
		::nme::geom::Point bitmapPos; /* REM */ 
		::nmex::display::Bitmap bitmap; /* REM */ 
		::nme::display::Sprite bitmapWrap; /* REM */ 
		bool scaleAble; /* REM */ 
		::com::mybo::framework::tweener::MTween tweener; /* REM */ 
		virtual Void onMouseDown( ::nme::events::Event e);
		Dynamic onMouseDown_dyn();

		virtual Void onMouseUp( ::nme::events::Event e);
		Dynamic onMouseUp_dyn();

		virtual Void onMouseOut( ::nme::events::Event e);
		Dynamic onMouseOut_dyn();

		virtual Void click( Dynamic onClick,Dynamic params,Dynamic onClickObj);
		Dynamic click_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapSimpleButton */ 
