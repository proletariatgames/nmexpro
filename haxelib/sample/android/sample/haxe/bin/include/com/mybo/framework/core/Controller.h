#ifndef INCLUDED_com_mybo_framework_core_Controller
#define INCLUDED_com_mybo_framework_core_Controller

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS4(com,mybo,framework,core,Controller)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS4(com,mybo,framework,core,SceneNode)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace core{


class Controller_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Controller_obj OBJ_;
		Controller_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Controller_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Controller_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Controller"); }

		::com::mybo::framework::core::Scene currentScene; /* REM */ 
		::Class nextSceneClassRef; /* REM */ 
		Dynamic nextSceneArgs; /* REM */ 
		Array< ::com::mybo::framework::core::SceneNode > nodes; /* REM */ 
		::Hash sleepScenes; /* REM */ 
		bool backStatus; /* REM */ 
		virtual Void run( ::Class classRef,Dynamic args);
		Dynamic run_dyn();

		virtual Void back( Dynamic args);
		Dynamic back_dyn();

		virtual Void updateCurrentScene( );
		Dynamic updateCurrentScene_dyn();

		virtual Void runCurrentScene( );
		Dynamic runCurrentScene_dyn();

		virtual Void markNode( ::Class classRef,Dynamic args);
		Dynamic markNode_dyn();

		virtual Void addSleepScene( ::com::mybo::framework::core::Scene scene);
		Dynamic addSleepScene_dyn();

		static int NODE_LENGTH; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core

#endif /* INCLUDED_com_mybo_framework_core_Controller */ 
