#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
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
#ifndef INCLUDED_nmex_NXEvent
#include <nmex/NXEvent.h>
#endif
#ifndef INCLUDED_nmex_NXObject
#include <nmex/NXObject.h>
#endif
namespace nmex{

Void NXObject_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",13)
	super::__construct(null());
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",14)
	::nmex::NXObject_obj::objects->push(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",15)
	if ((!(::nmex::NXObject_obj::eventHandleInit))){
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",16)
		::nmex::NXObject_obj::initEventHandle();
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",17)
		::nmex::NXObject_obj::eventHandleInit = true;
	}
}
;
	return null();
}

NXObject_obj::~NXObject_obj() { }

Dynamic NXObject_obj::__CreateEmpty() { return  new NXObject_obj; }
hx::ObjectPtr< NXObject_obj > NXObject_obj::__new()
{  hx::ObjectPtr< NXObject_obj > result = new NXObject_obj();
	result->__construct();
	return result;}

Dynamic NXObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NXObject_obj > result = new NXObject_obj();
	result->__construct();
	return result;}

::nme::events::EventDispatcher NXObject_obj::eventProxy;

Array< ::nmex::NXObject > NXObject_obj::objects;

bool NXObject_obj::eventHandleInit;

Void NXObject_obj::initEventHandle( ){
{
		HX_SOURCE_PUSH("NXObject_obj::initEventHandle")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",21)
		::nmex::NXObject_obj::nmex_set_event_handle(::nmex::NXObject_obj::externEventHandle_dyn());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(NXObject_obj,initEventHandle,(void))

Void NXObject_obj::externEventHandle( Dynamic inEvent){
{
		HX_SOURCE_PUSH("NXObject_obj::externEventHandle")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",27)
		int type = ::Std_obj::_int(::Reflect_obj::field(inEvent,HX_CSTRING("type")));
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",28)
		int code = ::Std_obj::_int(::Reflect_obj::field(inEvent,HX_CSTRING("code")));
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",29)
		int value = ::Std_obj::_int(::Reflect_obj::field(inEvent,HX_CSTRING("value")));
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",30)
		::String data = ::Std_obj::string(::Reflect_obj::field(inEvent,HX_CSTRING("data")));
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",31)
		::nmex::NXEvent event;
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",32)
		switch( (int)(type)){
			case (int)0: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",33)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("unKnownEvent"),code,value,data);
			}
			;break;
			case (int)1: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",36)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("inAppPurchaseSuccess"),code,value,data);
			}
			;break;
			case (int)2: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",37)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("inAppPurchaseFail"),code,value,data);
			}
			;break;
			case (int)3: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",38)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("inAppPurchaseCancel"),code,value,data);
			}
			;break;
			case (int)4: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",41)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("authSucceeded"),code,value,data);
			}
			;break;
			case (int)5: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",42)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("authFailed"),code,value,data);
			}
			;break;
			case (int)6: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",43)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("leaderboardViewOpened"),code,value,data);
			}
			;break;
			case (int)7: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",44)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("leaderboardViewClosed"),code,value,data);
			}
			;break;
			case (int)8: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",45)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("achievementsViewOpened"),code,value,data);
			}
			;break;
			case (int)9: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",46)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("achievementsViewClosed"),code,value,data);
			}
			;break;
			case (int)10: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",47)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("scoreReportSucceeded"),code,value,data);
			}
			;break;
			case (int)11: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",48)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("scoreReportFailed"),code,value,data);
			}
			;break;
			case (int)12: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",49)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("achievementReportSucceeded"),code,value,data);
			}
			;break;
			case (int)13: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",50)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("achievementReportFailed"),code,value,data);
			}
			;break;
			case (int)14: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",51)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("achievementResetSucceeded"),code,value,data);
			}
			;break;
			case (int)15: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",52)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("achievementResetFailed"),code,value,data);
			}
			;break;
			default: {
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",53)
				event = ::nmex::NXEvent_obj::__new(HX_CSTRING("unKnownEvent"),code,value,data);
			}
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",57)
		{
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",57)
			int _g1 = (int)0;
			int _g = ::nmex::NXObject_obj::objects->length;
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",57)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",57)
				int i = (_g1)++;
				HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXObject.hx",58)
				::nmex::NXObject_obj::objects->__get(i)->dispatchEvent(event);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NXObject_obj,externEventHandle,(void))

Dynamic NXObject_obj::nmex_set_event_handle;


NXObject_obj::NXObject_obj()
{
}

void NXObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NXObject);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic NXObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"objects") ) { return objects; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"eventProxy") ) { return eventProxy; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"eventHandleInit") ) { return eventHandleInit; }
		if (HX_FIELD_EQ(inName,"initEventHandle") ) { return initEventHandle_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"externEventHandle") ) { return externEventHandle_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nmex_set_event_handle") ) { return nmex_set_event_handle; }
	}
	return super::__Field(inName);
}

Dynamic NXObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"objects") ) { objects=inValue.Cast< Array< ::nmex::NXObject > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"eventProxy") ) { eventProxy=inValue.Cast< ::nme::events::EventDispatcher >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"eventHandleInit") ) { eventHandleInit=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nmex_set_event_handle") ) { nmex_set_event_handle=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NXObject_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("eventProxy"),
	HX_CSTRING("objects"),
	HX_CSTRING("eventHandleInit"),
	HX_CSTRING("initEventHandle"),
	HX_CSTRING("externEventHandle"),
	HX_CSTRING("nmex_set_event_handle"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NXObject_obj::eventProxy,"eventProxy");
	HX_MARK_MEMBER_NAME(NXObject_obj::objects,"objects");
	HX_MARK_MEMBER_NAME(NXObject_obj::eventHandleInit,"eventHandleInit");
	HX_MARK_MEMBER_NAME(NXObject_obj::nmex_set_event_handle,"nmex_set_event_handle");
};

Class NXObject_obj::__mClass;

void NXObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.NXObject"), hx::TCanCast< NXObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NXObject_obj::__boot()
{
	hx::Static(eventProxy) = ::nme::events::EventDispatcher_obj::__new(null());
	hx::Static(objects) = Array_obj< ::nmex::NXObject >::__new();
	hx::Static(eventHandleInit) = false;
	hx::Static(nmex_set_event_handle) = ::nme::Loader_obj::load(HX_CSTRING("nmex_set_event_handle"),(int)1);
}

} // end namespace nmex
