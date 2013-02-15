#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_PopupManager
#include <com/mybo/common/PopupManager.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
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
#ifndef INCLUDED_nmex_AD
#include <nmex/AD.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace common{

Void PopupManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",25)
	this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",26)
	this->stageWidth = this->facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",27)
	this->stageHeight = this->facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",29)
	this->popupUIContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",30)
	this->setMask(null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",32)
	this->facade->getStage()->addChild(this->popupUIContainer);
}
;
	return null();
}

PopupManager_obj::~PopupManager_obj() { }

Dynamic PopupManager_obj::__CreateEmpty() { return  new PopupManager_obj; }
hx::ObjectPtr< PopupManager_obj > PopupManager_obj::__new()
{  hx::ObjectPtr< PopupManager_obj > result = new PopupManager_obj();
	result->__construct();
	return result;}

Dynamic PopupManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PopupManager_obj > result = new PopupManager_obj();
	result->__construct();
	return result;}

Void PopupManager_obj::setMask( Dynamic __o_maskColor,Dynamic __o_alpha){
int maskColor = __o_maskColor.Default(0);
double alpha = __o_alpha.Default(0);
	HX_SOURCE_PUSH("PopupManager_obj::setMask");
{
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",44)
		this->popupUIContainer->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",45)
		this->popupUIContainer->nmeGetGraphics()->beginFill(maskColor,alpha);
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",46)
		this->popupUIContainer->nmeGetGraphics()->drawRect((int)0,(int)0,this->stageWidth,this->stageHeight);
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",47)
		this->popupUIContainer->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PopupManager_obj,setMask,(void))

Void PopupManager_obj::popup( ::nmex::display::DisplayObject displayObject){
{
		HX_SOURCE_PUSH("PopupManager_obj::popup")
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",53)
		this->popupUIContainer->addChild(displayObject);
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",54)
		this->facade->getStage()->addChild(this->popupUIContainer);
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",57)
		::nmex::AD_obj::showAd(HX_CSTRING("a14faa14de9f235"),(int)0,(int)-1,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PopupManager_obj,popup,(void))

Void PopupManager_obj::removePopupUI( ::nmex::display::DisplayObject displayObject){
{
		HX_SOURCE_PUSH("PopupManager_obj::removePopupUI")
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",63)
		if (((bool((null() != this->popupUIContainer)) && bool(this->popupUIContainer->contains(displayObject))))){
			HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",65)
			this->popupUIContainer->removeChild(displayObject);
			HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",66)
			if (((this->popupUIContainer->nmeGetNumChildren() == (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",66)
				this->facade->getStage()->removeChild(this->popupUIContainer);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PopupManager_obj,removePopupUI,(void))

Void PopupManager_obj::cleanup( ){
{
		HX_SOURCE_PUSH("PopupManager_obj::cleanup")
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",77)
		while(((bool((null() != this->popupUIContainer)) && bool((this->popupUIContainer->nmeGetNumChildren() > (int)0))))){
			HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",77)
			this->popupUIContainer->removeChildAt((int)0);
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",81)
		this->facade->getStage()->removeChild(this->popupUIContainer);
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",84)
		::nmex::AD_obj::hideAd();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PopupManager_obj,cleanup,(void))

::com::mybo::common::PopupManager PopupManager_obj::instance;

::com::mybo::common::PopupManager PopupManager_obj::getInstance( ){
	HX_SOURCE_PUSH("PopupManager_obj::getInstance")
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",36)
	if (((::com::mybo::common::PopupManager_obj::instance == null()))){
		HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",36)
		::com::mybo::common::PopupManager_obj::instance = ::com::mybo::common::PopupManager_obj::__new();
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/PopupManager.hx",40)
	return ::com::mybo::common::PopupManager_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PopupManager_obj,getInstance,return )


PopupManager_obj::PopupManager_obj()
{
}

void PopupManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PopupManager);
	HX_MARK_MEMBER_NAME(facade,"facade");
	HX_MARK_MEMBER_NAME(stageWidth,"stageWidth");
	HX_MARK_MEMBER_NAME(stageHeight,"stageHeight");
	HX_MARK_MEMBER_NAME(popupUIContainer,"popupUIContainer");
	HX_MARK_END_CLASS();
}

Dynamic PopupManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"popup") ) { return popup_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setMask") ) { return setMask_dyn(); }
		if (HX_FIELD_EQ(inName,"cleanup") ) { return cleanup_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"stageWidth") ) { return stageWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { return stageHeight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"removePopupUI") ) { return removePopupUI_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"popupUIContainer") ) { return popupUIContainer; }
	}
	return super::__Field(inName);
}

Dynamic PopupManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::com::mybo::common::PopupManager >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"stageWidth") ) { stageWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stageHeight") ) { stageHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"popupUIContainer") ) { popupUIContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PopupManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("facade"));
	outFields->push(HX_CSTRING("stageWidth"));
	outFields->push(HX_CSTRING("stageHeight"));
	outFields->push(HX_CSTRING("popupUIContainer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("facade"),
	HX_CSTRING("stageWidth"),
	HX_CSTRING("stageHeight"),
	HX_CSTRING("popupUIContainer"),
	HX_CSTRING("setMask"),
	HX_CSTRING("popup"),
	HX_CSTRING("removePopupUI"),
	HX_CSTRING("cleanup"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PopupManager_obj::instance,"instance");
};

Class PopupManager_obj::__mClass;

void PopupManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.PopupManager"), hx::TCanCast< PopupManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PopupManager_obj::__boot()
{
	hx::Static(instance);
}

} // end namespace com
} // end namespace mybo
} // end namespace common
