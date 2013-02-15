#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
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
namespace nme{
namespace display{

Void FPS_obj::__construct(Dynamic __o_inX,Dynamic __o_inY,Dynamic __o_inCol)
{
double inX = __o_inX.Default(30.0);
double inY = __o_inY.Default(10.0);
int inCol = __o_inCol.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",18)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",20)
	this->nmeSetX(inX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",21)
	this->nmeSetY(inY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",22)
	this->nmeSetSelectable(false);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",24)
	this->nmeSetText(HX_CSTRING("FPS:"));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",25)
	this->nmeSetTextColor(inCol);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",26)
	this->times = Array_obj< double >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",28)
	this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnter_dyn(),null(),null(),null());
}
;
	return null();
}

FPS_obj::~FPS_obj() { }

Dynamic FPS_obj::__CreateEmpty() { return  new FPS_obj; }
hx::ObjectPtr< FPS_obj > FPS_obj::__new(Dynamic __o_inX,Dynamic __o_inY,Dynamic __o_inCol)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(__o_inX,__o_inY,__o_inCol);
	return result;}

Dynamic FPS_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FPS_obj::onEnter( Dynamic _){
{
		HX_SOURCE_PUSH("FPS_obj::onEnter")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",39)
		double now = ::haxe::Timer_obj::stamp();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",40)
		this->times->push(now);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",42)
		while(((this->times->__get((int)0) < (now - (int)1)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",43)
			this->times->shift();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",45)
		if ((this->nmeGetVisible())){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/FPS.hx",46)
			this->nmeSetText((HX_CSTRING("FPS:") + this->times->length));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FPS_obj,onEnter,(void))


FPS_obj::FPS_obj()
{
}

void FPS_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FPS);
	HX_MARK_MEMBER_NAME(times,"times");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FPS_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { return times; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onEnter") ) { return onEnter_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FPS_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { times=inValue.Cast< Array< double > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FPS_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("times"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("times"),
	HX_CSTRING("onEnter"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FPS_obj::__mClass;

void FPS_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.FPS"), hx::TCanCast< FPS_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FPS_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
