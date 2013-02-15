#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nmex_InAppPurchase
#include <nmex/InAppPurchase.h>
#endif
#ifndef INCLUDED_nmex_NXObject
#include <nmex/NXObject.h>
#endif
namespace nmex{

Void InAppPurchase_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",13)
	super::__construct();
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",14)
	::nmex::InAppPurchase_obj::nmex_system_in_app_purchase_init();
}
;
	return null();
}

InAppPurchase_obj::~InAppPurchase_obj() { }

Dynamic InAppPurchase_obj::__CreateEmpty() { return  new InAppPurchase_obj; }
hx::ObjectPtr< InAppPurchase_obj > InAppPurchase_obj::__new()
{  hx::ObjectPtr< InAppPurchase_obj > result = new InAppPurchase_obj();
	result->__construct();
	return result;}

Dynamic InAppPurchase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InAppPurchase_obj > result = new InAppPurchase_obj();
	result->__construct();
	return result;}

bool InAppPurchase_obj::canPurchase( ){
	HX_SOURCE_PUSH("InAppPurchase_obj::canPurchase")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",24)
	return ::nmex::InAppPurchase_obj::nmex_system_in_app_purchase_can_purchase();
}


HX_DEFINE_DYNAMIC_FUNC0(InAppPurchase_obj,canPurchase,return )

Void InAppPurchase_obj::purchase( ::String productID){
{
		HX_SOURCE_PUSH("InAppPurchase_obj::purchase")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",28)
		::nmex::InAppPurchase_obj::nmex_system_in_app_purchase_purchase(productID);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InAppPurchase_obj,purchase,(void))

Void InAppPurchase_obj::destroy( ){
{
		HX_SOURCE_PUSH("InAppPurchase_obj::destroy")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",33)
		::nmex::InAppPurchase_obj::nmex_system_in_app_purchase_release();
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",34)
		::nmex::InAppPurchase_obj::instance = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InAppPurchase_obj,destroy,(void))

::nmex::InAppPurchase InAppPurchase_obj::instance;

::nmex::InAppPurchase InAppPurchase_obj::getInstance( ){
	HX_SOURCE_PUSH("InAppPurchase_obj::getInstance")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",18)
	if (((::nmex::InAppPurchase_obj::instance == null()))){
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",18)
		::nmex::InAppPurchase_obj::instance = ::nmex::InAppPurchase_obj::__new();
	}
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/InAppPurchase.hx",21)
	return ::nmex::InAppPurchase_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(InAppPurchase_obj,getInstance,return )

Dynamic InAppPurchase_obj::nmex_system_in_app_purchase_init;

Dynamic InAppPurchase_obj::nmex_system_in_app_purchase_purchase;

Dynamic InAppPurchase_obj::nmex_system_in_app_purchase_can_purchase;

Dynamic InAppPurchase_obj::nmex_system_in_app_purchase_release;


InAppPurchase_obj::InAppPurchase_obj()
{
}

void InAppPurchase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InAppPurchase);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InAppPurchase_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance; }
		if (HX_FIELD_EQ(inName,"purchase") ) { return purchase_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"canPurchase") ) { return canPurchase_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_init") ) { return nmex_system_in_app_purchase_init; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_release") ) { return nmex_system_in_app_purchase_release; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_purchase") ) { return nmex_system_in_app_purchase_purchase; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_can_purchase") ) { return nmex_system_in_app_purchase_can_purchase; }
	}
	return super::__Field(inName);
}

Dynamic InAppPurchase_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::nmex::InAppPurchase >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_init") ) { nmex_system_in_app_purchase_init=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_release") ) { nmex_system_in_app_purchase_release=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_purchase") ) { nmex_system_in_app_purchase_purchase=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"nmex_system_in_app_purchase_can_purchase") ) { nmex_system_in_app_purchase_can_purchase=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void InAppPurchase_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("getInstance"),
	HX_CSTRING("nmex_system_in_app_purchase_init"),
	HX_CSTRING("nmex_system_in_app_purchase_purchase"),
	HX_CSTRING("nmex_system_in_app_purchase_can_purchase"),
	HX_CSTRING("nmex_system_in_app_purchase_release"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("canPurchase"),
	HX_CSTRING("purchase"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InAppPurchase_obj::instance,"instance");
	HX_MARK_MEMBER_NAME(InAppPurchase_obj::nmex_system_in_app_purchase_init,"nmex_system_in_app_purchase_init");
	HX_MARK_MEMBER_NAME(InAppPurchase_obj::nmex_system_in_app_purchase_purchase,"nmex_system_in_app_purchase_purchase");
	HX_MARK_MEMBER_NAME(InAppPurchase_obj::nmex_system_in_app_purchase_can_purchase,"nmex_system_in_app_purchase_can_purchase");
	HX_MARK_MEMBER_NAME(InAppPurchase_obj::nmex_system_in_app_purchase_release,"nmex_system_in_app_purchase_release");
};

Class InAppPurchase_obj::__mClass;

void InAppPurchase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.InAppPurchase"), hx::TCanCast< InAppPurchase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InAppPurchase_obj::__boot()
{
	hx::Static(instance);
	hx::Static(nmex_system_in_app_purchase_init) = ::nme::Loader_obj::load(HX_CSTRING("nmex_system_in_app_purchase_init"),(int)0);
	hx::Static(nmex_system_in_app_purchase_purchase) = ::nme::Loader_obj::load(HX_CSTRING("nmex_system_in_app_purchase_purchase"),(int)1);
	hx::Static(nmex_system_in_app_purchase_can_purchase) = ::nme::Loader_obj::load(HX_CSTRING("nmex_system_in_app_purchase_can_purchase"),(int)0);
	hx::Static(nmex_system_in_app_purchase_release) = ::nme::Loader_obj::load(HX_CSTRING("nmex_system_in_app_purchase_release"),(int)0);
}

} // end namespace nmex
