#include <hxcpp.h>

#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
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
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
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
#ifndef INCLUDED_nme_ui_Multitouch
#include <nme/ui/Multitouch.h>
#endif
#ifndef INCLUDED_nme_ui_MultitouchInputMode
#include <nme/ui/MultitouchInputMode.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace nme{
namespace ui{

Void Multitouch_obj::__construct()
{
	return null();
}

Multitouch_obj::~Multitouch_obj() { }

Dynamic Multitouch_obj::__CreateEmpty() { return  new Multitouch_obj; }
hx::ObjectPtr< Multitouch_obj > Multitouch_obj::__new()
{  hx::ObjectPtr< Multitouch_obj > result = new Multitouch_obj();
	result->__construct();
	return result;}

Dynamic Multitouch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Multitouch_obj > result = new Multitouch_obj();
	result->__construct();
	return result;}

void Multitouch_obj::__init__(){
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",21)
	::nme::ui::Multitouch_obj::maxTouchPoints = (int)2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",22)
	::nme::ui::Multitouch_obj::supportedGestures = Array_obj< ::String >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",23)
	::nme::ui::Multitouch_obj::supportsGestureEvents = false;
}


::nme::ui::MultitouchInputMode Multitouch_obj::inputMode;

int Multitouch_obj::maxTouchPoints;

Array< ::String > Multitouch_obj::supportedGestures;

bool Multitouch_obj::supportsGestureEvents;

bool Multitouch_obj::supportsTouchEvents;

::nme::ui::MultitouchInputMode Multitouch_obj::nmeGetInputMode( ){
	HX_SOURCE_PUSH("Multitouch_obj::nmeGetInputMode")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",33)
	if ((::nme::ui::Multitouch_obj::nme_stage_get_multitouch_active(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeHandle))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",36)
		return ::nme::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",38)
		return ::nme::ui::MultitouchInputMode_obj::NONE_dyn();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Multitouch_obj,nmeGetInputMode,return )

::nme::ui::MultitouchInputMode Multitouch_obj::nmeSetInputMode( ::nme::ui::MultitouchInputMode inMode){
	HX_SOURCE_PUSH("Multitouch_obj::nmeSetInputMode")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",44)
	if (((inMode == ::nme::ui::MultitouchInputMode_obj::GESTURE_dyn()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",45)
		return ::nme::ui::Multitouch_obj::nmeGetInputMode();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",48)
	::nme::ui::Multitouch_obj::nme_stage_set_multitouch_active(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeHandle,(inMode == ::nme::ui::MultitouchInputMode_obj::TOUCH_POINT_dyn()));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",49)
	return inMode;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Multitouch_obj,nmeSetInputMode,return )

bool Multitouch_obj::nmeGetSupportsTouchEvents( ){
	HX_SOURCE_PUSH("Multitouch_obj::nmeGetSupportsTouchEvents")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/ui/Multitouch.hx",53)
	return ::nme::ui::Multitouch_obj::nme_stage_get_multitouch_supported(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeHandle);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Multitouch_obj,nmeGetSupportsTouchEvents,return )

Dynamic Multitouch_obj::nme_stage_get_multitouch_supported;

Dynamic Multitouch_obj::nme_stage_get_multitouch_active;

Dynamic Multitouch_obj::nme_stage_set_multitouch_active;


Multitouch_obj::Multitouch_obj()
{
}

void Multitouch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Multitouch);
	HX_MARK_END_CLASS();
}

Dynamic Multitouch_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"inputMode") ) { return nmeGetInputMode(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxTouchPoints") ) { return maxTouchPoints; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeGetInputMode") ) { return nmeGetInputMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetInputMode") ) { return nmeSetInputMode_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"supportedGestures") ) { return supportedGestures; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { return nmeGetSupportsTouchEvents(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"supportsGestureEvents") ) { return supportsGestureEvents; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nmeGetSupportsTouchEvents") ) { return nmeGetSupportsTouchEvents_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_active") ) { return nme_stage_get_multitouch_active; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_multitouch_active") ) { return nme_stage_set_multitouch_active; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_supported") ) { return nme_stage_get_multitouch_supported; }
	}
	return super::__Field(inName);
}

Dynamic Multitouch_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"inputMode") ) { return nmeSetInputMode(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxTouchPoints") ) { maxTouchPoints=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"supportedGestures") ) { supportedGestures=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"supportsTouchEvents") ) { supportsTouchEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"supportsGestureEvents") ) { supportsGestureEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_active") ) { nme_stage_get_multitouch_active=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_multitouch_active") ) { nme_stage_set_multitouch_active=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"nme_stage_get_multitouch_supported") ) { nme_stage_get_multitouch_supported=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Multitouch_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("inputMode"),
	HX_CSTRING("maxTouchPoints"),
	HX_CSTRING("supportedGestures"),
	HX_CSTRING("supportsGestureEvents"),
	HX_CSTRING("supportsTouchEvents"),
	HX_CSTRING("nmeGetInputMode"),
	HX_CSTRING("nmeSetInputMode"),
	HX_CSTRING("nmeGetSupportsTouchEvents"),
	HX_CSTRING("nme_stage_get_multitouch_supported"),
	HX_CSTRING("nme_stage_get_multitouch_active"),
	HX_CSTRING("nme_stage_set_multitouch_active"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Multitouch_obj::inputMode,"inputMode");
	HX_MARK_MEMBER_NAME(Multitouch_obj::maxTouchPoints,"maxTouchPoints");
	HX_MARK_MEMBER_NAME(Multitouch_obj::supportedGestures,"supportedGestures");
	HX_MARK_MEMBER_NAME(Multitouch_obj::supportsGestureEvents,"supportsGestureEvents");
	HX_MARK_MEMBER_NAME(Multitouch_obj::supportsTouchEvents,"supportsTouchEvents");
	HX_MARK_MEMBER_NAME(Multitouch_obj::nme_stage_get_multitouch_supported,"nme_stage_get_multitouch_supported");
	HX_MARK_MEMBER_NAME(Multitouch_obj::nme_stage_get_multitouch_active,"nme_stage_get_multitouch_active");
	HX_MARK_MEMBER_NAME(Multitouch_obj::nme_stage_set_multitouch_active,"nme_stage_set_multitouch_active");
};

Class Multitouch_obj::__mClass;

void Multitouch_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.ui.Multitouch"), hx::TCanCast< Multitouch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Multitouch_obj::__boot()
{
	hx::Static(inputMode);
	hx::Static(maxTouchPoints);
	hx::Static(supportedGestures);
	hx::Static(supportsGestureEvents);
	hx::Static(supportsTouchEvents);
	hx::Static(nme_stage_get_multitouch_supported) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_multitouch_supported"),(int)1);
	hx::Static(nme_stage_get_multitouch_active) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_multitouch_active"),(int)1);
	hx::Static(nme_stage_set_multitouch_active) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_multitouch_active"),(int)2);
}

} // end namespace nme
} // end namespace ui
