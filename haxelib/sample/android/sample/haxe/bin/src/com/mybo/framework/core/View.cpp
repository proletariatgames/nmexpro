#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
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
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_FPS
#include <nme/display/FPS.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_text_TextField
#include <nme/text/TextField.h>
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
namespace core{

Void View_obj::__construct(::nme::display::Stage stage)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",24)
	this->stage = stage;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",27)
	this->motionRef = hx::ClassOf< ::com::mybo::framework::scenemotions::FadeMotion >();
}
;
	return null();
}

View_obj::~View_obj() { }

Dynamic View_obj::__CreateEmpty() { return  new View_obj; }
hx::ObjectPtr< View_obj > View_obj::__new(::nme::display::Stage stage)
{  hx::ObjectPtr< View_obj > result = new View_obj();
	result->__construct(stage);
	return result;}

Dynamic View_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< View_obj > result = new View_obj();
	result->__construct(inArgs[0]);
	return result;}

Void View_obj::showFPS( ){
{
		HX_SOURCE_PUSH("View_obj::showFPS")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",31)
		this->isShowFPS = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",32)
		this->fps = ::nme::display::FPS_obj::__new(null(),null(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",33)
		this->stage->addChild(this->fps);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(View_obj,showFPS,(void))

Void View_obj::setPageMotion( ::Class pageMotionRef){
{
		HX_SOURCE_PUSH("View_obj::setPageMotion")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",36)
		if (((null() != pageMotionRef))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",37)
			this->motionRef = pageMotionRef;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_obj,setPageMotion,(void))

Void View_obj::runPageMotion( ){
{
		HX_SOURCE_PUSH("View_obj::runPageMotion")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",40)
		::com::mybo::framework::interfaces::ISceneMotion motion = ::Type_obj::createInstance(this->motionRef,null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",41)
		motion->run();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(View_obj,runPageMotion,(void))

Void View_obj::addPage( ::com::mybo::framework::core::Scene page){
{
		HX_SOURCE_PUSH("View_obj::addPage")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",44)
		if (((bool((null() != this->prePage)) && bool(this->stage->contains(this->prePage))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",44)
			this->stage->removeChild(this->prePage);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",45)
		if (((null() != this->currentPage))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",45)
			this->prePage = this->currentPage;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",46)
		this->currentPage = page;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",47)
		this->stage->addChild(page);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",49)
		this->drawAndroidMask();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_obj,addPage,(void))

Void View_obj::removePage( ::com::mybo::framework::core::Scene page){
{
		HX_SOURCE_PUSH("View_obj::removePage")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",52)
		if (((bool((null() != page)) && bool(this->stage->contains(page))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",53)
			this->stage->removeChild(page);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_obj,removePage,(void))

Void View_obj::switchPage( ::com::mybo::framework::core::Scene page){
{
		HX_SOURCE_PUSH("View_obj::switchPage")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",56)
		if (((bool((null() != this->currentPage)) && bool(this->stage->contains(this->currentPage))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",56)
			this->stage->removeChild(this->currentPage);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",57)
		this->currentPage = page;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",58)
		this->stage->addChild(page);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",60)
		if ((this->isShowFPS)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",60)
			this->showFPS();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",65)
		this->drawAndroidMask();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_obj,switchPage,(void))

::nme::display::Stage View_obj::getStage( ){
	HX_SOURCE_PUSH("View_obj::getStage")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",68)
	return this->stage;
}


HX_DEFINE_DYNAMIC_FUNC0(View_obj,getStage,return )

Void View_obj::cleanStage( ){
{
		HX_SOURCE_PUSH("View_obj::cleanStage")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",71)
		while(((this->stage->nmeGetNumChildren() >= (int)1))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",72)
			this->stage->removeChildAt((this->stage->nmeGetNumChildren() - (int)1));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(View_obj,cleanStage,(void))

Void View_obj::drawAndroidMask( ){
{
		HX_SOURCE_PUSH("View_obj::drawAndroidMask")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",79)
		this->androidMask = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",80)
		double width = ::com::mybo::framework::core::Facade_obj::getInstance()->getStageWidthInPoint();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",81)
		double height = ::com::mybo::framework::core::Facade_obj::getInstance()->getStageHeightInPoint();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",82)
		this->androidMask->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",83)
		this->androidMask->nmeGetGraphics()->beginFill((int)0,(int)1);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",84)
		this->androidMask->nmeGetGraphics()->drawRect((int)0,height,width,(int)60);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",85)
		this->androidMask->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",87)
		if ((this->stage->contains(this->androidMask))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",87)
			this->stage->removeChild(this->androidMask);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/View.hx",88)
		this->stage->addChildAt(this->androidMask,this->stage->nmeGetNumChildren());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(View_obj,drawAndroidMask,(void))


View_obj::View_obj()
{
}

void View_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(View);
	HX_MARK_MEMBER_NAME(currentPage,"currentPage");
	HX_MARK_MEMBER_NAME(prePage,"prePage");
	HX_MARK_MEMBER_NAME(stage,"stage");
	HX_MARK_MEMBER_NAME(motionRef,"motionRef");
	HX_MARK_MEMBER_NAME(isShowFPS,"isShowFPS");
	HX_MARK_MEMBER_NAME(fps,"fps");
	HX_MARK_MEMBER_NAME(androidMask,"androidMask");
	HX_MARK_END_CLASS();
}

Dynamic View_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { return fps; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { return stage; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"prePage") ) { return prePage; }
		if (HX_FIELD_EQ(inName,"showFPS") ) { return showFPS_dyn(); }
		if (HX_FIELD_EQ(inName,"addPage") ) { return addPage_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getStage") ) { return getStage_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"motionRef") ) { return motionRef; }
		if (HX_FIELD_EQ(inName,"isShowFPS") ) { return isShowFPS; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"removePage") ) { return removePage_dyn(); }
		if (HX_FIELD_EQ(inName,"switchPage") ) { return switchPage_dyn(); }
		if (HX_FIELD_EQ(inName,"cleanStage") ) { return cleanStage_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentPage") ) { return currentPage; }
		if (HX_FIELD_EQ(inName,"androidMask") ) { return androidMask; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setPageMotion") ) { return setPageMotion_dyn(); }
		if (HX_FIELD_EQ(inName,"runPageMotion") ) { return runPageMotion_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"drawAndroidMask") ) { return drawAndroidMask_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic View_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { fps=inValue.Cast< ::nme::display::FPS >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"prePage") ) { prePage=inValue.Cast< ::com::mybo::framework::core::Scene >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"motionRef") ) { motionRef=inValue.Cast< ::Class >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isShowFPS") ) { isShowFPS=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentPage") ) { currentPage=inValue.Cast< ::com::mybo::framework::core::Scene >(); return inValue; }
		if (HX_FIELD_EQ(inName,"androidMask") ) { androidMask=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void View_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentPage"));
	outFields->push(HX_CSTRING("prePage"));
	outFields->push(HX_CSTRING("stage"));
	outFields->push(HX_CSTRING("motionRef"));
	outFields->push(HX_CSTRING("isShowFPS"));
	outFields->push(HX_CSTRING("fps"));
	outFields->push(HX_CSTRING("androidMask"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("currentPage"),
	HX_CSTRING("prePage"),
	HX_CSTRING("stage"),
	HX_CSTRING("motionRef"),
	HX_CSTRING("isShowFPS"),
	HX_CSTRING("fps"),
	HX_CSTRING("showFPS"),
	HX_CSTRING("setPageMotion"),
	HX_CSTRING("runPageMotion"),
	HX_CSTRING("addPage"),
	HX_CSTRING("removePage"),
	HX_CSTRING("switchPage"),
	HX_CSTRING("getStage"),
	HX_CSTRING("cleanStage"),
	HX_CSTRING("androidMask"),
	HX_CSTRING("drawAndroidMask"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class View_obj::__mClass;

void View_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.core.View"), hx::TCanCast< View_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void View_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core
