#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
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
#ifndef INCLUDED_com_mybo_framework_display_BitmapToggleButton
#include <com/mybo/framework/display/BitmapToggleButton.h>
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
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace display{

Void BitmapToggleButton_obj::__construct(::com::mybo::framework::resource::BitmapTile tile)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",19)
	super::__construct(tile,null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",20)
	this->currentState = (int)0;
}
;
	return null();
}

BitmapToggleButton_obj::~BitmapToggleButton_obj() { }

Dynamic BitmapToggleButton_obj::__CreateEmpty() { return  new BitmapToggleButton_obj; }
hx::ObjectPtr< BitmapToggleButton_obj > BitmapToggleButton_obj::__new(::com::mybo::framework::resource::BitmapTile tile)
{  hx::ObjectPtr< BitmapToggleButton_obj > result = new BitmapToggleButton_obj();
	result->__construct(tile);
	return result;}

Dynamic BitmapToggleButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapToggleButton_obj > result = new BitmapToggleButton_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BitmapToggleButton_obj::toggle( int index){
{
		HX_SOURCE_PUSH("BitmapToggleButton_obj::toggle")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",24)
		if ((((int)0 == index))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",24)
			this->currentState = (int)0;
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",26)
			this->currentState = (int)1;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",29)
		this->drawTile(this->currentState,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapToggleButton_obj,toggle,(void))

Void BitmapToggleButton_obj::onMouseDown( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapToggleButton_obj::onMouseDown")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",32)
		this->downInside = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapToggleButton_obj,onMouseDown,(void))

Void BitmapToggleButton_obj::onMouseUp( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapToggleButton_obj::onMouseUp")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",38)
		if ((this->downInside)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",38)
			if (((bool((this->onClick != null())) && bool(this->_enable)))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",40)
				::Reflect_obj::callMethod(this->onClickObj,this->onClick,this->onClickParams);
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapToggleButton.hx",42)
		this->downInside = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapToggleButton_obj,onMouseUp,(void))

Void BitmapToggleButton_obj::onMouseOut( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapToggleButton_obj::onMouseOut")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapToggleButton_obj,onMouseOut,(void))


BitmapToggleButton_obj::BitmapToggleButton_obj()
{
}

void BitmapToggleButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapToggleButton);
	HX_MARK_MEMBER_NAME(currentState,"currentState");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapToggleButton_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"toggle") ) { return toggle_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return onMouseOut_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentState") ) { return currentState; }
	}
	return super::__Field(inName);
}

Dynamic BitmapToggleButton_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"currentState") ) { currentState=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapToggleButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentState"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("currentState"),
	HX_CSTRING("toggle"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("onMouseOut"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapToggleButton_obj::__mClass;

void BitmapToggleButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapToggleButton"), hx::TCanCast< BitmapToggleButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapToggleButton_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
