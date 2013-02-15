#include <hxcpp.h>

#ifndef INCLUDED_nme_JNI
#include <nme/JNI.h>
#endif
#ifndef INCLUDED_nmex_Tracker
#include <nmex/Tracker.h>
#endif
namespace nmex{

Void Tracker_obj::__construct()
{
	return null();
}

Tracker_obj::~Tracker_obj() { }

Dynamic Tracker_obj::__CreateEmpty() { return  new Tracker_obj; }
hx::ObjectPtr< Tracker_obj > Tracker_obj::__new()
{  hx::ObjectPtr< Tracker_obj > result = new Tracker_obj();
	result->__construct();
	return result;}

Dynamic Tracker_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tracker_obj > result = new Tracker_obj();
	result->__construct();
	return result;}

bool Tracker_obj::init;

Void Tracker_obj::assertInit( ){
{
		HX_SOURCE_PUSH("Tracker_obj::assertInit")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",8)
		if ((!(::nmex::Tracker_obj::init))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",9)
			hx::Throw (HX_CSTRING("Please startTracker() first."));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Tracker_obj,assertInit,(void))

Dynamic Tracker_obj::_startTracker_func;

Void Tracker_obj::startTracker( ::String acountID,Dynamic __o_disPatchPeriod){
int disPatchPeriod = __o_disPatchPeriod.Default(-1);
	HX_SOURCE_PUSH("Tracker_obj::startTracker");
{
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",16)
		if (((::nmex::Tracker_obj::_startTracker_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",17)
			::nmex::Tracker_obj::_startTracker_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("startTracker"),HX_CSTRING("(Ljava/lang/String;I)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",18)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",19)
		a->__Field(HX_CSTRING("push"))(acountID);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",20)
		a->__Field(HX_CSTRING("push"))(disPatchPeriod);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",21)
		::nmex::Tracker_obj::_startTracker_func(a);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",23)
		::nmex::Tracker_obj::init = true;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Tracker_obj,startTracker,(void))

Dynamic Tracker_obj::_trackEvent_func;

Void Tracker_obj::trackEvent( ::String category,::String action,::String label,int value){
{
		HX_SOURCE_PUSH("Tracker_obj::trackEvent")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",29)
		::nmex::Tracker_obj::assertInit();
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",30)
		if (((::nmex::Tracker_obj::_trackEvent_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",31)
			::nmex::Tracker_obj::_trackEvent_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("trackEvent"),HX_CSTRING("(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",32)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",33)
		a->__Field(HX_CSTRING("push"))(category);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",34)
		a->__Field(HX_CSTRING("push"))(action);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",35)
		a->__Field(HX_CSTRING("push"))(label);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",36)
		a->__Field(HX_CSTRING("push"))(value);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",37)
		::nmex::Tracker_obj::_trackEvent_func(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Tracker_obj,trackEvent,(void))

Dynamic Tracker_obj::_trackPage_func;

Void Tracker_obj::trackPage( ::String pageName){
{
		HX_SOURCE_PUSH("Tracker_obj::trackPage")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",43)
		::nmex::Tracker_obj::assertInit();
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",44)
		if (((::nmex::Tracker_obj::_trackPage_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",45)
			::nmex::Tracker_obj::_trackPage_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("trackPage"),HX_CSTRING("(Ljava/lang/String;)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",46)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",47)
		a->__Field(HX_CSTRING("push"))(pageName);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",48)
		::nmex::Tracker_obj::_trackPage_func(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Tracker_obj,trackPage,(void))

Dynamic Tracker_obj::_dispatchTracker_func;

Void Tracker_obj::dispatchTracker( ){
{
		HX_SOURCE_PUSH("Tracker_obj::dispatchTracker")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",54)
		::nmex::Tracker_obj::assertInit();
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",55)
		if (((::nmex::Tracker_obj::_dispatchTracker_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",56)
			::nmex::Tracker_obj::_dispatchTracker_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("dispatchTracker"),HX_CSTRING("()V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",57)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",58)
		::nmex::Tracker_obj::_dispatchTracker_func(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Tracker_obj,dispatchTracker,(void))

Dynamic Tracker_obj::_stopTracker_func;

Void Tracker_obj::stopTracker( ){
{
		HX_SOURCE_PUSH("Tracker_obj::stopTracker")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",64)
		::nmex::Tracker_obj::assertInit();
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",65)
		if (((::nmex::Tracker_obj::_stopTracker_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",66)
			::nmex::Tracker_obj::_stopTracker_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("stopTracker"),HX_CSTRING("()V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",67)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",68)
		::nmex::Tracker_obj::_stopTracker_func(a);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Tracker.hx",69)
		::nmex::Tracker_obj::init = false;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Tracker_obj,stopTracker,(void))


Tracker_obj::Tracker_obj()
{
}

void Tracker_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Tracker);
	HX_MARK_END_CLASS();
}

Dynamic Tracker_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"trackPage") ) { return trackPage_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"assertInit") ) { return assertInit_dyn(); }
		if (HX_FIELD_EQ(inName,"trackEvent") ) { return trackEvent_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"stopTracker") ) { return stopTracker_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startTracker") ) { return startTracker_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_trackPage_func") ) { return _trackPage_func; }
		if (HX_FIELD_EQ(inName,"dispatchTracker") ) { return dispatchTracker_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_trackEvent_func") ) { return _trackEvent_func; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_stopTracker_func") ) { return _stopTracker_func; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_startTracker_func") ) { return _startTracker_func; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_dispatchTracker_func") ) { return _dispatchTracker_func; }
	}
	return super::__Field(inName);
}

Dynamic Tracker_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { init=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_trackPage_func") ) { _trackPage_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_trackEvent_func") ) { _trackEvent_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_stopTracker_func") ) { _stopTracker_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_startTracker_func") ) { _startTracker_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_dispatchTracker_func") ) { _dispatchTracker_func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Tracker_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("init"),
	HX_CSTRING("assertInit"),
	HX_CSTRING("_startTracker_func"),
	HX_CSTRING("startTracker"),
	HX_CSTRING("_trackEvent_func"),
	HX_CSTRING("trackEvent"),
	HX_CSTRING("_trackPage_func"),
	HX_CSTRING("trackPage"),
	HX_CSTRING("_dispatchTracker_func"),
	HX_CSTRING("dispatchTracker"),
	HX_CSTRING("_stopTracker_func"),
	HX_CSTRING("stopTracker"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Tracker_obj::init,"init");
	HX_MARK_MEMBER_NAME(Tracker_obj::_startTracker_func,"_startTracker_func");
	HX_MARK_MEMBER_NAME(Tracker_obj::_trackEvent_func,"_trackEvent_func");
	HX_MARK_MEMBER_NAME(Tracker_obj::_trackPage_func,"_trackPage_func");
	HX_MARK_MEMBER_NAME(Tracker_obj::_dispatchTracker_func,"_dispatchTracker_func");
	HX_MARK_MEMBER_NAME(Tracker_obj::_stopTracker_func,"_stopTracker_func");
};

Class Tracker_obj::__mClass;

void Tracker_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.Tracker"), hx::TCanCast< Tracker_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Tracker_obj::__boot()
{
	hx::Static(init) = false;
	hx::Static(_startTracker_func);
	hx::Static(_trackEvent_func);
	hx::Static(_trackPage_func);
	hx::Static(_dispatchTracker_func);
	hx::Static(_stopTracker_func);
}

} // end namespace nmex
