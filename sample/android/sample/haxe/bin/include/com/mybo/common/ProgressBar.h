#ifndef INCLUDED_com_mybo_common_ProgressBar
#define INCLUDED_com_mybo_common_ProgressBar

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,ProgressBar)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class ProgressBar_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef ProgressBar_obj OBJ_;
		ProgressBar_obj();
		Void __construct(::nme::display::BitmapData bitmapData);

	public:
		static hx::ObjectPtr< ProgressBar_obj > __new(::nme::display::BitmapData bitmapData);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ProgressBar_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ProgressBar"); }

		::nme::display::BitmapData texture; /* REM */ 
		::com::mybo::framework::tweener::MTween mtween; /* REM */ 
		double maxWidth; /* REM */ 
		double maxHeight; /* REM */ 
		double targetWidth; /* REM */ 
		double barWidth; /* REM */ 
		virtual Void update( double percent);
		Dynamic update_dyn();

		virtual double getMaxWidthInPoint( );
		Dynamic getMaxWidthInPoint_dyn();

		virtual Void onComplete( );
		Dynamic onComplete_dyn();

		virtual Void onUpdate( double percent);
		Dynamic onUpdate_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_ProgressBar */ 
