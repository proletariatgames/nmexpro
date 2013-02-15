#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapButton
#include <com/mybo/framework/display/BitmapButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
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
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
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
namespace display{

Void BitmapButton_obj::__construct(::com::mybo::framework::resource::BitmapTile tile,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",27)
	super::__construct(tile,false,true,null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",29)
	this->totalFrames = (int)2;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",31)
	this->hit = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",32)
	this->hit->nmeGetGraphics()->beginFill((int)0,(int)0);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",33)
	this->hit->nmeGetGraphics()->drawRect((int)0,(int)0,(double(tile->width) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor)),(double(tile->height) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",34)
	this->hit->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",35)
	this->addChild(this->hit);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",37)
	this->onClick = onClick;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",38)
	this->onClickObj = onClickObj;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",39)
	this->onClickParams = onClickParams;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",41)
	this->hit->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",42)
	this->hit->addEventListener(::nme::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",43)
	this->hit->addEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",45)
	this->downInside = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",46)
	this->enable(null());
}
;
	return null();
}

BitmapButton_obj::~BitmapButton_obj() { }

Dynamic BitmapButton_obj::__CreateEmpty() { return  new BitmapButton_obj; }
hx::ObjectPtr< BitmapButton_obj > BitmapButton_obj::__new(::com::mybo::framework::resource::BitmapTile tile,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj)
{  hx::ObjectPtr< BitmapButton_obj > result = new BitmapButton_obj();
	result->__construct(tile,onClick,onClickParams,onClickObj);
	return result;}

Dynamic BitmapButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapButton_obj > result = new BitmapButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BitmapButton_obj::onMouseDown( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapButton_obj::onMouseDown")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",50)
		this->downInside = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",51)
		if (((this->tile->totalFrames > (int)1))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",51)
			this->drawTile((int)1,null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapButton_obj,onMouseDown,(void))

Void BitmapButton_obj::onMouseUp( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapButton_obj::onMouseUp")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",57)
		if ((this->downInside)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",57)
			if (((bool((this->onClick != null())) && bool(this->_enable)))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",59)
				::Reflect_obj::callMethod(this->onClickObj,this->onClick,this->onClickParams);
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",61)
		this->downInside = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",62)
		this->drawTile((int)0,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapButton_obj,onMouseUp,(void))

Void BitmapButton_obj::onMouseOut( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapButton_obj::onMouseOut")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",64)
		this->drawTile((int)0,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapButton_obj,onMouseOut,(void))

Void BitmapButton_obj::click( Dynamic onClick,Dynamic params,Dynamic onClickObj){
{
		HX_SOURCE_PUSH("BitmapButton_obj::click")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",69)
		this->onClick = onClick;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",70)
		this->onClickObj = onClickObj;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",71)
		this->onClickParams = params;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapButton_obj,click,(void))

Void BitmapButton_obj::enable( Dynamic __o_value){
bool value = __o_value.Default(true);
	HX_SOURCE_PUSH("BitmapButton_obj::enable");
{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",73)
		this->_enable = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapButton_obj,enable,(void))

Void BitmapButton_obj::destroy( ){
{
		HX_SOURCE_PUSH("BitmapButton_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",77)
		this->super::destroy();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",78)
		this->onClick = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",79)
		this->onClickObj = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",80)
		this->onClickParams = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",81)
		this->hit->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",82)
		this->removeChild(this->hit);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",83)
		this->hit->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",84)
		this->hit->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapButton.hx",85)
		this->hit->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapButton_obj,destroy,(void))


BitmapButton_obj::BitmapButton_obj()
{
}

void BitmapButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapButton);
	HX_MARK_MEMBER_NAME(hit,"hit");
	HX_MARK_MEMBER_NAME(onClick,"onClick");
	HX_MARK_MEMBER_NAME(onClickObj,"onClickObj");
	HX_MARK_MEMBER_NAME(onClickParams,"onClickParams");
	HX_MARK_MEMBER_NAME(_enable,"_enable");
	HX_MARK_MEMBER_NAME(downInside,"downInside");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapButton_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hit") ) { return hit; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"click") ) { return click_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"enable") ) { return enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick; }
		if (HX_FIELD_EQ(inName,"_enable") ) { return _enable; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onClickObj") ) { return onClickObj; }
		if (HX_FIELD_EQ(inName,"downInside") ) { return downInside; }
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return onMouseOut_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onClickParams") ) { return onClickParams; }
	}
	return super::__Field(inName);
}

Dynamic BitmapButton_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hit") ) { hit=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { onClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_enable") ) { _enable=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onClickObj") ) { onClickObj=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"downInside") ) { downInside=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onClickParams") ) { onClickParams=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hit"));
	outFields->push(HX_CSTRING("onClick"));
	outFields->push(HX_CSTRING("onClickObj"));
	outFields->push(HX_CSTRING("onClickParams"));
	outFields->push(HX_CSTRING("_enable"));
	outFields->push(HX_CSTRING("downInside"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("hit"),
	HX_CSTRING("onClick"),
	HX_CSTRING("onClickObj"),
	HX_CSTRING("onClickParams"),
	HX_CSTRING("_enable"),
	HX_CSTRING("downInside"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("onMouseOut"),
	HX_CSTRING("click"),
	HX_CSTRING("enable"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapButton_obj::__mClass;

void BitmapButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapButton"), hx::TCanCast< BitmapButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapButton_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
