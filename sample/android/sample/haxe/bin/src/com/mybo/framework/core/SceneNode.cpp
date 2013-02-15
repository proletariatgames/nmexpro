#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_SceneNode
#include <com/mybo/framework/core/SceneNode.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace core{

Void SceneNode_obj::__construct(::Class sceneRef,Dynamic args)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/SceneNode.hx",11)
	this->sceneRef = sceneRef;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/SceneNode.hx",12)
	this->initArgs = args;
}
;
	return null();
}

SceneNode_obj::~SceneNode_obj() { }

Dynamic SceneNode_obj::__CreateEmpty() { return  new SceneNode_obj; }
hx::ObjectPtr< SceneNode_obj > SceneNode_obj::__new(::Class sceneRef,Dynamic args)
{  hx::ObjectPtr< SceneNode_obj > result = new SceneNode_obj();
	result->__construct(sceneRef,args);
	return result;}

Dynamic SceneNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SceneNode_obj > result = new SceneNode_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


SceneNode_obj::SceneNode_obj()
{
}

void SceneNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SceneNode);
	HX_MARK_MEMBER_NAME(sceneRef,"sceneRef");
	HX_MARK_MEMBER_NAME(initArgs,"initArgs");
	HX_MARK_END_CLASS();
}

Dynamic SceneNode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"sceneRef") ) { return sceneRef; }
		if (HX_FIELD_EQ(inName,"initArgs") ) { return initArgs; }
	}
	return super::__Field(inName);
}

Dynamic SceneNode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"sceneRef") ) { sceneRef=inValue.Cast< ::Class >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initArgs") ) { initArgs=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SceneNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sceneRef"));
	outFields->push(HX_CSTRING("initArgs"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sceneRef"),
	HX_CSTRING("initArgs"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class SceneNode_obj::__mClass;

void SceneNode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.core.SceneNode"), hx::TCanCast< SceneNode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SceneNode_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core
