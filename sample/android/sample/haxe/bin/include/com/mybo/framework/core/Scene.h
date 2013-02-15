#ifndef INCLUDED_com_mybo_framework_core_Scene
#define INCLUDED_com_mybo_framework_core_Scene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/DisplayObjectContainer.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
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


class Scene_obj : public ::nme::display::DisplayObjectContainer_obj{
	public:
		typedef ::nme::display::DisplayObjectContainer_obj super;
		typedef Scene_obj OBJ_;
		Scene_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Scene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Scene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Scene"); }

		Dynamic sceneOutCallback; /* REM */ 
		Dynamic sceneOutCallbackArgs; /* REM */ 
		bool sleepAble; /* REM */ 
		bool markAble; /* REM */ 
		::com::mybo::framework::core::Facade facade; /* REM */ 
		virtual Void sceneDidAppear( );
		Dynamic sceneDidAppear_dyn();

		virtual Void sceneWillDisappear( );
		Dynamic sceneWillDisappear_dyn();

		virtual Void setSceneDisappearCallBack( Dynamic onComplete,Dynamic args);
		Dynamic setSceneDisappearCallBack_dyn();

		virtual Void sceneDidDisappear( );
		Dynamic sceneDidDisappear_dyn();

		virtual ::String nmeGetType( );
		Dynamic nmeGetType_dyn();

		virtual Void wakeup( );
		Dynamic wakeup_dyn();

		virtual Void sleep( );
		Dynamic sleep_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core

#endif /* INCLUDED_com_mybo_framework_core_Scene */ 
