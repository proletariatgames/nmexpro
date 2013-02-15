#include <hxcpp.h>

#ifndef INCLUDED_nme_JNI
#include <nme/JNI.h>
#endif
#ifndef INCLUDED_nmex_AD
#include <nmex/AD.h>
#endif
namespace nmex{

Void AD_obj::__construct()
{
	return null();
}

AD_obj::~AD_obj() { }

Dynamic AD_obj::__CreateEmpty() { return  new AD_obj; }
hx::ObjectPtr< AD_obj > AD_obj::__new()
{  hx::ObjectPtr< AD_obj > result = new AD_obj();
	result->__construct();
	return result;}

Dynamic AD_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AD_obj > result = new AD_obj();
	result->__construct();
	return result;}

Dynamic AD_obj::_showAd_func;

Void AD_obj::showAd( ::String id,Dynamic __o_x,Dynamic __o_y,Dynamic __o_size,Dynamic __o_preLoad){
int x = __o_x.Default(0);
int y = __o_y.Default(0);
int size = __o_size.Default(0);
int preLoad = __o_preLoad.Default(0);
	HX_SOURCE_PUSH("AD_obj::showAd");
{
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",13)
		if (((::nmex::AD_obj::_showAd_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",14)
			::nmex::AD_obj::_showAd_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("showAd"),HX_CSTRING("(Ljava/lang/String;IIII)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",15)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",16)
		a->__Field(HX_CSTRING("push"))(id);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",17)
		a->__Field(HX_CSTRING("push"))(x);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",18)
		a->__Field(HX_CSTRING("push"))(y);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",19)
		a->__Field(HX_CSTRING("push"))(size);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",20)
		a->__Field(HX_CSTRING("push"))(preLoad);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",21)
		::nmex::AD_obj::_showAd_func(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(AD_obj,showAd,(void))

Dynamic AD_obj::_hideAd_func;

Void AD_obj::hideAd( ){
{
		HX_SOURCE_PUSH("AD_obj::hideAd")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",26)
		if (((::nmex::AD_obj::_hideAd_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",27)
			::nmex::AD_obj::_hideAd_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("hideAd"),HX_CSTRING("()V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",28)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/AD.hx",29)
		::nmex::AD_obj::_hideAd_func(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AD_obj,hideAd,(void))


AD_obj::AD_obj()
{
}

void AD_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AD);
	HX_MARK_END_CLASS();
}

Dynamic AD_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"showAd") ) { return showAd_dyn(); }
		if (HX_FIELD_EQ(inName,"hideAd") ) { return hideAd_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_showAd_func") ) { return _showAd_func; }
		if (HX_FIELD_EQ(inName,"_hideAd_func") ) { return _hideAd_func; }
	}
	return super::__Field(inName);
}

Dynamic AD_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_showAd_func") ) { _showAd_func=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hideAd_func") ) { _hideAd_func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AD_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_showAd_func"),
	HX_CSTRING("showAd"),
	HX_CSTRING("_hideAd_func"),
	HX_CSTRING("hideAd"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AD_obj::_showAd_func,"_showAd_func");
	HX_MARK_MEMBER_NAME(AD_obj::_hideAd_func,"_hideAd_func");
};

Class AD_obj::__mClass;

void AD_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.AD"), hx::TCanCast< AD_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AD_obj::__boot()
{
	hx::Static(_showAd_func);
	hx::Static(_hideAd_func);
}

} // end namespace nmex
