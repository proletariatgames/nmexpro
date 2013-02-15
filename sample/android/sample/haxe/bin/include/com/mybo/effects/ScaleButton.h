#ifndef INCLUDED_com_mybo_effects_ScaleButton
#define INCLUDED_com_mybo_effects_ScaleButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/TimerRender.h>
HX_DECLARE_CLASS3(com,mybo,effects,ScaleButton)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS1(haxe,Timer)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace effects{


class ScaleButton_obj : public ::com::mybo::framework::core::TimerRender_obj{
	public:
		typedef ::com::mybo::framework::core::TimerRender_obj super;
		typedef ScaleButton_obj OBJ_;
		ScaleButton_obj();
		Void __construct(::nmex::display::Bitmap _view,double centerX,double centerY,Dynamic __o_offsetX,Dynamic __o_offsetY,Dynamic __o_scale,Dynamic onClick,Dynamic __o_inGame);

	public:
		static hx::ObjectPtr< ScaleButton_obj > __new(::nmex::display::Bitmap _view,double centerX,double centerY,Dynamic __o_offsetX,Dynamic __o_offsetY,Dynamic __o_scale,Dynamic onClick,Dynamic __o_inGame);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ScaleButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ScaleButton"); }

		::nmex::display::Bitmap view; /* REM */ 
		double centerX; /* REM */ 
		double centerY; /* REM */ 
		double currentX; /* REM */ 
		double currentY; /* REM */ 
		double offsetX; /* REM */ 
		double offsetY; /* REM */ 
		int offsetFlag; /* REM */ 
		double scale; /* REM */ 
		::com::mybo::framework::tweener::MTween tweener; /* REM */ 
		double dScaleX; /* REM */ 
		double dScaleY; /* REM */ 
		bool downInside; /* REM */ 
		bool destroyed; /* REM */ 
		::haxe::Timer delayTimer; /* REM */ 
		double sx; /* REM */ 
		double ssx; /* REM */ 
		double sssx; /* REM */ 
		::nme::geom::Matrix tMatrix; /* REM */ 
		double retina; /* REM */ 
		int flag; /* REM */ 
		int sFlag; /* REM */ 
		virtual Void render( );
		Dynamic render_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		static Array< double > sxs; /* REM */ 
		static Array< double > ssxs; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace effects

#endif /* INCLUDED_com_mybo_effects_ScaleButton */ 
