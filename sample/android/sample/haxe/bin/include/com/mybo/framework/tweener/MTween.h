#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#define INCLUDED_com_mybo_framework_tweener_MTween

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/TimerRender.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,tweener,MTween)
HX_DECLARE_CLASS1(haxe,Timer)
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
namespace tweener{


class MTween_obj : public ::com::mybo::framework::core::TimerRender_obj{
	public:
		typedef ::com::mybo::framework::core::TimerRender_obj super;
		typedef MTween_obj OBJ_;
		MTween_obj();
		Void __construct(Dynamic target,Dynamic __o_duration,Dynamic values,Dynamic props);

	public:
		static hx::ObjectPtr< MTween_obj > __new(Dynamic target,Dynamic __o_duration,Dynamic values,Dynamic props);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MTween_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MTween"); }

		int time; /* REM */ 
		::haxe::Timer timer; /* REM */ 
		::Hash tweens; /* REM */ 
		Dynamic target; /* REM */ 
		bool isInit; /* REM */ 
		double duration; /* REM */ 
		Dynamic values; /* REM */ 
		Dynamic valuesOld; /* REM */ 
		Dynamic props; /* REM */ 
		double startTime; /* REM */ 
		double currentTime; /* REM */ 
		double endTime; /* REM */ 
		double delay; /* REM */ 
		Dynamic ease; /* REM */ 
		Dynamic onUpdate; /* REM */ 
	Dynamic &onUpdate_dyn() { return onUpdate;}
		Dynamic onComplete; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void copyProp( Dynamic props);
		Dynamic copyProp_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual double caculateValue( double currTime);
		Dynamic caculateValue_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		static ::com::mybo::framework::tweener::MTween to( Dynamic target,Dynamic duration,Dynamic values,Dynamic props);
		static Dynamic to_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener

#endif /* INCLUDED_com_mybo_framework_tweener_MTween */ 
