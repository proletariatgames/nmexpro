#ifndef INCLUDED_com_mybo_HelpScene
#define INCLUDED_com_mybo_HelpScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS2(com,mybo,HelpScene)
HX_DECLARE_CLASS3(com,mybo,common,Background)
HX_DECLARE_CLASS3(com,mybo,common,Swipe)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{


class HelpScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef HelpScene_obj OBJ_;
		HelpScene_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HelpScene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HelpScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HelpScene"); }

		::com::mybo::common::Background background; /* REM */ 
		::com::mybo::common::Swipe swipe; /* REM */ 
		virtual Void backToStartMenu( );
		Dynamic backToStartMenu_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo

#endif /* INCLUDED_com_mybo_HelpScene */ 
