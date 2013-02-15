#ifndef INCLUDED_com_mybo_framework_scenemotions_FadeMotion
#define INCLUDED_com_mybo_framework_scenemotions_FadeMotion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/interfaces/ISceneMotion.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,Controller)
HX_DECLARE_CLASS4(com,mybo,framework,interfaces,ISceneMotion)
HX_DECLARE_CLASS4(com,mybo,framework,scenemotions,FadeMotion)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,Shape)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace scenemotions{


class FadeMotion_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FadeMotion_obj OBJ_;
		FadeMotion_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FadeMotion_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FadeMotion_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::com::mybo::framework::interfaces::ISceneMotion_obj *()
			{ return new ::com::mybo::framework::interfaces::ISceneMotion_delegate_< FadeMotion_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FadeMotion"); }

		::nme::display::Shape mask; /* REM */ 
		::com::mybo::framework::core::Controller controller; /* REM */ 
		virtual Void run( );
		Dynamic run_dyn();

		virtual Void nextStep( );
		Dynamic nextStep_dyn();

		virtual Void doNext( );
		Dynamic doNext_dyn();

		virtual Void complete( );
		Dynamic complete_dyn();

		virtual Void config( Dynamic args);
		Dynamic config_dyn();

		virtual Void motionComplete( );
		Dynamic motionComplete_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace scenemotions

#endif /* INCLUDED_com_mybo_framework_scenemotions_FadeMotion */ 
