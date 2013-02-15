#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_tweener_easing_Linear
#include <com/mybo/framework/tweener/easing/Linear.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Linear_obj::__construct()
{
	return null();
}

Linear_obj::~Linear_obj() { }

Dynamic Linear_obj::__CreateEmpty() { return  new Linear_obj; }
hx::ObjectPtr< Linear_obj > Linear_obj::__new()
{  hx::ObjectPtr< Linear_obj > result = new Linear_obj();
	result->__construct();
	return result;}

Dynamic Linear_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Linear_obj > result = new Linear_obj();
	result->__construct();
	return result;}

hx::Object *Linear_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Linear_obj::easeNone( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Linear_obj::easeNone")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Linear.hx",5)
	return ((double((c * t)) / double(d)) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Linear_obj,easeNone,return )

double Linear_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Linear_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Linear.hx",9)
	return ((double((c * t)) / double(d)) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Linear_obj,easeIn,return )

double Linear_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Linear_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Linear.hx",13)
	return ((double((c * t)) / double(d)) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Linear_obj,easeOut,return )

double Linear_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Linear_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Linear.hx",17)
	return ((double((c * t)) / double(d)) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Linear_obj,easeInOut,return )


Linear_obj::Linear_obj()
{
}

void Linear_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Linear);
	HX_MARK_END_CLASS();
}

Dynamic Linear_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { return easeIn_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { return easeOut_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"easeNone") ) { return easeNone_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { return easeInOut_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Linear_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Linear_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("easeNone"),
	HX_CSTRING("easeIn"),
	HX_CSTRING("easeOut"),
	HX_CSTRING("easeInOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Linear_obj::__mClass;

void Linear_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Linear"), hx::TCanCast< Linear_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Linear_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
