#ifndef INCLUDED_com_mybo_framework_core_View
#define INCLUDED_com_mybo_framework_core_View

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS4(com,mybo,framework,core,View)
HX_DECLARE_CLASS4(com,mybo,framework,interfaces,ISceneMotion)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,FPS)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,text,TextField)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace core{


class View_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef View_obj OBJ_;
		View_obj();
		Void __construct(::nme::display::Stage stage);

	public:
		static hx::ObjectPtr< View_obj > __new(::nme::display::Stage stage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~View_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("View"); }

		::com::mybo::framework::core::Scene currentPage; /* REM */ 
		::com::mybo::framework::core::Scene prePage; /* REM */ 
		::nme::display::Stage stage; /* REM */ 
		::Class motionRef; /* REM */ 
		bool isShowFPS; /* REM */ 
		::nme::display::FPS fps; /* REM */ 
		virtual Void showFPS( );
		Dynamic showFPS_dyn();

		virtual Void setPageMotion( ::Class pageMotionRef);
		Dynamic setPageMotion_dyn();

		virtual Void runPageMotion( );
		Dynamic runPageMotion_dyn();

		virtual Void addPage( ::com::mybo::framework::core::Scene page);
		Dynamic addPage_dyn();

		virtual Void removePage( ::com::mybo::framework::core::Scene page);
		Dynamic removePage_dyn();

		virtual Void switchPage( ::com::mybo::framework::core::Scene page);
		Dynamic switchPage_dyn();

		virtual ::nme::display::Stage getStage( );
		Dynamic getStage_dyn();

		virtual Void cleanStage( );
		Dynamic cleanStage_dyn();

		::nme::display::Sprite androidMask; /* REM */ 
		virtual Void drawAndroidMask( );
		Dynamic drawAndroidMask_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core

#endif /* INCLUDED_com_mybo_framework_core_View */ 
