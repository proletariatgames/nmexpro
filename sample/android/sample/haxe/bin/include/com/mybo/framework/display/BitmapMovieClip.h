#ifndef INCLUDED_com_mybo_framework_display_BitmapMovieClip
#define INCLUDED_com_mybo_framework_display_BitmapMovieClip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/display/BitmapObject.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapMovieClip)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace display{


class BitmapMovieClip_obj : public ::com::mybo::framework::display::BitmapObject_obj{
	public:
		typedef ::com::mybo::framework::display::BitmapObject_obj super;
		typedef BitmapMovieClip_obj OBJ_;
		BitmapMovieClip_obj();
		Void __construct(::com::mybo::framework::resource::BitmapTile tile,Array< int > index);

	public:
		static hx::ObjectPtr< BitmapMovieClip_obj > __new(::com::mybo::framework::resource::BitmapTile tile,Array< int > index);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapMovieClip_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapMovieClip"); }

		bool isLoop; /* REM */ 
		bool isPlay; /* REM */ 
		Dynamic completeFun; /* REM */ 
		Dynamic callbackObject; /* REM */ 
		Dynamic callbackPara; /* REM */ 
		bool isSlow; /* REM */ 
		int flag; /* REM */ 
		Array< int > index; /* REM */ 
		virtual Void gotoAndPlay( int frame);
		Dynamic gotoAndPlay_dyn();

		virtual Void gotoAndStop( int frame);
		Dynamic gotoAndStop_dyn();

		virtual Void play( );
		Dynamic play_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual Void onComplete( Dynamic func,Dynamic para,Dynamic obj);
		Dynamic onComplete_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display

#endif /* INCLUDED_com_mybo_framework_display_BitmapMovieClip */ 
