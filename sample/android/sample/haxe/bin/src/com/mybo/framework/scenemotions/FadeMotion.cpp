#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Controller
#include <com/mybo/framework/core/Controller.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_View
#include <com/mybo/framework/core/View.h>
#endif
#ifndef INCLUDED_com_mybo_framework_interfaces_ISceneMotion
#include <com/mybo/framework/interfaces/ISceneMotion.h>
#endif
#ifndef INCLUDED_com_mybo_framework_scenemotions_FadeMotion
#include <com/mybo/framework/scenemotions/FadeMotion.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Sine
#include <com/mybo/framework/tweener/easing/Sine.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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
#ifndef INCLUDED_nme_display_Shape
#include <nme/display/Shape.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
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
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace scenemotions{

Void FadeMotion_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",21)
	this->controller = ::com::mybo::framework::core::Facade_obj::getInstance()->getController();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",22)
	this->mask = ::nme::display::Shape_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",23)
	this->mask->nmeGetGraphics()->beginFill((int)0,(int)1);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",24)
	double width = ::Math_obj::max(::com::mybo::framework::core::Facade_obj::getInstance()->getStageWidthInPoint(),::com::mybo::framework::core::Facade_obj::getInstance()->getStageHeightInPoint());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",25)
	this->mask->nmeGetGraphics()->drawRect((int)0,(int)0,width,width);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",26)
	this->mask->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",27)
	this->mask->nmeSetAlpha((int)0);
}
;
	return null();
}

FadeMotion_obj::~FadeMotion_obj() { }

Dynamic FadeMotion_obj::__CreateEmpty() { return  new FadeMotion_obj; }
hx::ObjectPtr< FadeMotion_obj > FadeMotion_obj::__new()
{  hx::ObjectPtr< FadeMotion_obj > result = new FadeMotion_obj();
	result->__construct();
	return result;}

Dynamic FadeMotion_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FadeMotion_obj > result = new FadeMotion_obj();
	result->__construct();
	return result;}

hx::Object *FadeMotion_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::mybo::framework::interfaces::ISceneMotion_obj)) return operator ::com::mybo::framework::interfaces::ISceneMotion_obj *();
	return super::__ToInterface(inType);
}

Void FadeMotion_obj::run( ){
{
		HX_SOURCE_PUSH("FadeMotion_obj::run")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",31)
		this->controller->currentScene->addChild(this->mask);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ::com::mybo::framework::scenemotions::FadeMotion_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("onComplete") , __this->nextStep_dyn(),false);
				__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Sine_obj::easeIn_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",32)
		::com::mybo::framework::tweener::MTween_obj::to(this->mask,0.5,_Function_1_1::Block(),_Function_1_2::Block(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FadeMotion_obj,run,(void))

Void FadeMotion_obj::nextStep( ){
{
		HX_SOURCE_PUSH("FadeMotion_obj::nextStep")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",36)
		this->mask->nmeSetAlpha((int)1);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",37)
		::haxe::Timer_obj::delay(this->doNext_dyn(),(int)50);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FadeMotion_obj,nextStep,(void))

Void FadeMotion_obj::doNext( ){
{
		HX_SOURCE_PUSH("FadeMotion_obj::doNext")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",40)
		this->controller->currentScene->removeChild(this->mask);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",41)
		this->controller->updateCurrentScene();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",42)
		::com::mybo::framework::core::Facade_obj::getInstance()->getView()->switchPage(this->controller->currentScene);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",43)
		this->controller->currentScene->addChild(this->mask);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",45)
		::haxe::Timer_obj::delay(this->complete_dyn(),(int)50);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FadeMotion_obj,doNext,(void))

Void FadeMotion_obj::complete( ){
{
		HX_SOURCE_PUSH("FadeMotion_obj::complete")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ::com::mybo::framework::scenemotions::FadeMotion_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("onComplete") , __this->motionComplete_dyn(),false);
				__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Sine_obj::easeOut_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",48)
		::com::mybo::framework::tweener::MTween_obj::to(this->mask,0.5,_Function_1_1::Block(),_Function_1_2::Block(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FadeMotion_obj,complete,(void))

Void FadeMotion_obj::config( Dynamic args){
{
		HX_SOURCE_PUSH("FadeMotion_obj::config")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FadeMotion_obj,config,(void))

Void FadeMotion_obj::motionComplete( ){
{
		HX_SOURCE_PUSH("FadeMotion_obj::motionComplete")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",55)
		this->controller->currentScene->removeChild(this->mask);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/scenemotions/FadeMotion.hx",56)
		this->controller->runCurrentScene();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FadeMotion_obj,motionComplete,(void))


FadeMotion_obj::FadeMotion_obj()
{
}

void FadeMotion_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FadeMotion);
	HX_MARK_MEMBER_NAME(mask,"mask");
	HX_MARK_MEMBER_NAME(controller,"controller");
	HX_MARK_END_CLASS();
}

Dynamic FadeMotion_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { return mask; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"doNext") ) { return doNext_dyn(); }
		if (HX_FIELD_EQ(inName,"config") ) { return config_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nextStep") ) { return nextStep_dyn(); }
		if (HX_FIELD_EQ(inName,"complete") ) { return complete_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { return controller; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"motionComplete") ) { return motionComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FadeMotion_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { mask=inValue.Cast< ::nme::display::Shape >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { controller=inValue.Cast< ::com::mybo::framework::core::Controller >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FadeMotion_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mask"));
	outFields->push(HX_CSTRING("controller"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mask"),
	HX_CSTRING("controller"),
	HX_CSTRING("run"),
	HX_CSTRING("nextStep"),
	HX_CSTRING("doNext"),
	HX_CSTRING("complete"),
	HX_CSTRING("config"),
	HX_CSTRING("motionComplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FadeMotion_obj::__mClass;

void FadeMotion_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.scenemotions.FadeMotion"), hx::TCanCast< FadeMotion_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FadeMotion_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace scenemotions
