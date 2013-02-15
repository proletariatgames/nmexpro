#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_ProgressBar
#include <com/mybo/common/ProgressBar.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapNumber
#include <com/mybo/framework/display/BitmapNumber.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_ui_TouchLeftBar
#include <com/mybo/ui/TouchLeftBar.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
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
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace ui{

Void TouchLeftBar_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",25)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",27)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",28)
	this->touchLeftBG = facade->getBitmap(HX_CSTRING("tiao_bg"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",29)
	this->addChild(this->touchLeftBG);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",31)
	this->touchLeftBar = ::com::mybo::common::ProgressBar_obj::__new(facade->getBitmap(HX_CSTRING("tiao"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",32)
	this->touchLeftBar->nmeSetX((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",33)
	this->touchLeftBar->nmeSetY((int)2);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",34)
	this->addChild(this->touchLeftBar);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",36)
	this->touchLeftText = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",37)
	this->touchLeftText->addChild(facade->getBitmap(HX_CSTRING("game_tl"),null()));
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",38)
	this->touchLeftText->nmeSetX((this->touchLeftBG->nmeGetX() + (int)2));
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",39)
	this->touchLeftText->nmeSetY((int)8);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",40)
	this->addChild(this->touchLeftText);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",42)
	this->touchLeftNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(facade->getTile(HX_CSTRING("num2")),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",43)
	this->touchLeftNum->nmeSetY((int)-1);
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",44)
	this->touchLeftNum->nmeSetX((::Std_obj::_int((double(this->touchLeftText->nmeGetWidth()) / double((int)2))) * (int)2));
	HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",45)
	this->touchLeftText->addChild(this->touchLeftNum);
}
;
	return null();
}

TouchLeftBar_obj::~TouchLeftBar_obj() { }

Dynamic TouchLeftBar_obj::__CreateEmpty() { return  new TouchLeftBar_obj; }
hx::ObjectPtr< TouchLeftBar_obj > TouchLeftBar_obj::__new()
{  hx::ObjectPtr< TouchLeftBar_obj > result = new TouchLeftBar_obj();
	result->__construct();
	return result;}

Dynamic TouchLeftBar_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchLeftBar_obj > result = new TouchLeftBar_obj();
	result->__construct();
	return result;}

Void TouchLeftBar_obj::update( int touches,double maxTouches){
{
		HX_SOURCE_PUSH("TouchLeftBar_obj::update")
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",49)
		double percent = (double(touches) / double(maxTouches));
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",50)
		if (((percent > (int)1))){
			HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",50)
			percent = (int)1;
		}
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",52)
		this->touchLeftBar->update(percent);
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",53)
		this->touchLeftNum->drawNumber(touches);
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",55)
		double w = (this->touchLeftBar->getMaxWidthInPoint() * percent);
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",56)
		double tw = this->touchLeftText->nmeGetWidth();
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",58)
		double posX;
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",59)
		if (((w > tw))){
			HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",59)
			posX = ((double(w) / double((int)2)) - (double(tw) / double((int)2)));
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",61)
			posX = (int)90;
		}
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",65)
		if (((null() != this->tween))){
			HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",65)
			this->tween->stop();
		}
		struct _Function_1_1{
			inline static Dynamic Block( double &posX){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , posX,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/TouchLeftBar.hx",69)
		this->tween = ::com::mybo::framework::tweener::MTween_obj::to(this->touchLeftText,0.3,_Function_1_1::Block(posX),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TouchLeftBar_obj,update,(void))


TouchLeftBar_obj::TouchLeftBar_obj()
{
}

void TouchLeftBar_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchLeftBar);
	HX_MARK_MEMBER_NAME(touchLeftBG,"touchLeftBG");
	HX_MARK_MEMBER_NAME(touchLeftBar,"touchLeftBar");
	HX_MARK_MEMBER_NAME(touchLeftText,"touchLeftText");
	HX_MARK_MEMBER_NAME(touchLeftNum,"touchLeftNum");
	HX_MARK_MEMBER_NAME(tween,"tween");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TouchLeftBar_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"tween") ) { return tween; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"touchLeftBG") ) { return touchLeftBG; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchLeftBar") ) { return touchLeftBar; }
		if (HX_FIELD_EQ(inName,"touchLeftNum") ) { return touchLeftNum; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"touchLeftText") ) { return touchLeftText; }
	}
	return super::__Field(inName);
}

Dynamic TouchLeftBar_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"tween") ) { tween=inValue.Cast< ::com::mybo::framework::tweener::MTween >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"touchLeftBG") ) { touchLeftBG=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchLeftBar") ) { touchLeftBar=inValue.Cast< ::com::mybo::common::ProgressBar >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchLeftNum") ) { touchLeftNum=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"touchLeftText") ) { touchLeftText=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TouchLeftBar_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("touchLeftBG"));
	outFields->push(HX_CSTRING("touchLeftBar"));
	outFields->push(HX_CSTRING("touchLeftText"));
	outFields->push(HX_CSTRING("touchLeftNum"));
	outFields->push(HX_CSTRING("tween"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("touchLeftBG"),
	HX_CSTRING("touchLeftBar"),
	HX_CSTRING("touchLeftText"),
	HX_CSTRING("touchLeftNum"),
	HX_CSTRING("tween"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class TouchLeftBar_obj::__mClass;

void TouchLeftBar_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.TouchLeftBar"), hx::TCanCast< TouchLeftBar_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TouchLeftBar_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
