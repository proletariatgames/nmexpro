#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
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

Void Scene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",20)
	super::__construct(::nme::display::DisplayObjectContainer_obj::nme_create_display_object_container(),this->nmeGetType());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",21)
	this->sleepAble = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",22)
	this->markAble = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",23)
	this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
}
;
	return null();
}

Scene_obj::~Scene_obj() { }

Dynamic Scene_obj::__CreateEmpty() { return  new Scene_obj; }
hx::ObjectPtr< Scene_obj > Scene_obj::__new()
{  hx::ObjectPtr< Scene_obj > result = new Scene_obj();
	result->__construct();
	return result;}

Dynamic Scene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Scene_obj > result = new Scene_obj();
	result->__construct();
	return result;}

Void Scene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("Scene_obj::sceneDidAppear")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,sceneDidAppear,(void))

Void Scene_obj::sceneWillDisappear( ){
{
		HX_SOURCE_PUSH("Scene_obj::sceneWillDisappear")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",30)
		this->sceneDidDisappear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,sceneWillDisappear,(void))

Void Scene_obj::setSceneDisappearCallBack( Dynamic onComplete,Dynamic args){
{
		HX_SOURCE_PUSH("Scene_obj::setSceneDisappearCallBack")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",35)
		this->sceneOutCallback = onComplete;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",36)
		this->sceneOutCallbackArgs = args;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Scene_obj,setSceneDisappearCallBack,(void))

Void Scene_obj::sceneDidDisappear( ){
{
		HX_SOURCE_PUSH("Scene_obj::sceneDidDisappear")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",39)
		if (((null() != this->sceneOutCallback))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",40)
			::Reflect_obj::callMethod(null(),this->sceneOutCallback,this->sceneOutCallbackArgs);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,sceneDidDisappear,(void))

::String Scene_obj::nmeGetType( ){
	HX_SOURCE_PUSH("Scene_obj::nmeGetType")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Scene.hx",45)
	return HX_CSTRING("Scene");
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,nmeGetType,return )

Void Scene_obj::wakeup( ){
{
		HX_SOURCE_PUSH("Scene_obj::wakeup")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,wakeup,(void))

Void Scene_obj::sleep( ){
{
		HX_SOURCE_PUSH("Scene_obj::sleep")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,sleep,(void))

Void Scene_obj::destroy( ){
{
		HX_SOURCE_PUSH("Scene_obj::destroy")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scene_obj,destroy,(void))


Scene_obj::Scene_obj()
{
}

void Scene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Scene);
	HX_MARK_MEMBER_NAME(sceneOutCallback,"sceneOutCallback");
	HX_MARK_MEMBER_NAME(sceneOutCallbackArgs,"sceneOutCallbackArgs");
	HX_MARK_MEMBER_NAME(sleepAble,"sleepAble");
	HX_MARK_MEMBER_NAME(markAble,"markAble");
	HX_MARK_MEMBER_NAME(facade,"facade");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Scene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sleep") ) { return sleep_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		if (HX_FIELD_EQ(inName,"wakeup") ) { return wakeup_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"markAble") ) { return markAble; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sleepAble") ) { return sleepAble; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sceneDidAppear") ) { return sceneDidAppear_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"sceneOutCallback") ) { return sceneOutCallback; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"sceneDidDisappear") ) { return sceneDidDisappear_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"sceneWillDisappear") ) { return sceneWillDisappear_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"sceneOutCallbackArgs") ) { return sceneOutCallbackArgs; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"setSceneDisappearCallBack") ) { return setSceneDisappearCallBack_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Scene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"markAble") ) { markAble=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sleepAble") ) { sleepAble=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"sceneOutCallback") ) { sceneOutCallback=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"sceneOutCallbackArgs") ) { sceneOutCallbackArgs=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Scene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sceneOutCallback"));
	outFields->push(HX_CSTRING("sceneOutCallbackArgs"));
	outFields->push(HX_CSTRING("sleepAble"));
	outFields->push(HX_CSTRING("markAble"));
	outFields->push(HX_CSTRING("facade"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sceneOutCallback"),
	HX_CSTRING("sceneOutCallbackArgs"),
	HX_CSTRING("sleepAble"),
	HX_CSTRING("markAble"),
	HX_CSTRING("facade"),
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("sceneWillDisappear"),
	HX_CSTRING("setSceneDisappearCallBack"),
	HX_CSTRING("sceneDidDisappear"),
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("wakeup"),
	HX_CSTRING("sleep"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Scene_obj::__mClass;

void Scene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.core.Scene"), hx::TCanCast< Scene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Scene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core
