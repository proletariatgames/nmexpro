#ifndef INCLUDED_com_mybo_framework_core_SceneNode
#define INCLUDED_com_mybo_framework_core_SceneNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

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


class SceneNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SceneNode_obj OBJ_;
		SceneNode_obj();
		Void __construct(::Class sceneRef,Dynamic args);

	public:
		static hx::ObjectPtr< SceneNode_obj > __new(::Class sceneRef,Dynamic args);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SceneNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SceneNode"); }

		::Class sceneRef; /* REM */ 
		Dynamic initArgs; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core

#endif /* INCLUDED_com_mybo_framework_core_SceneNode */ 
