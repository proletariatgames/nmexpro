#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_tweener_easing_Back
#include <com/mybo/framework/tweener/easing/Back.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Back_obj::__construct()
{
	return null();
}

Back_obj::~Back_obj() { }

Dynamic Back_obj::__CreateEmpty() { return  new Back_obj; }
hx::ObjectPtr< Back_obj > Back_obj::__new()
{  hx::ObjectPtr< Back_obj > result = new Back_obj();
	result->__construct();
	return result;}

Dynamic Back_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Back_obj > result = new Back_obj();
	result->__construct();
	return result;}

hx::Object *Back_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Back_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Back_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",9)
	double s = 1.70158;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",10)
	return ((((c * (hx::DivEq(t,d))) * t) * (((((s + (int)1)) * t) - s))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Back_obj,easeIn,return )

double Back_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Back_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",17)
	double s = 1.70158;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",18)
	return ((c * (((((t = ((double(t) / double(d)) - (int)1)) * t) * (((((s + (int)1)) * t) + s))) + (int)1))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Back_obj,easeOut,return )

double Back_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Back_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",25)
	double s = 1.70158;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",26)
	if ((((hx::DivEq(t,(double(d) / double((int)2)))) < (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",27)
		return (((double(c) / double((int)2)) * (((t * t) * ((((((hx::MultEq(s,1.525)) + (int)1)) * t) - s))))) + b);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Back.hx",28)
	return (((double(c) / double((int)2)) * (((((hx::SubEq(t,(int)2)) * t) * ((((((hx::MultEq(s,1.525)) + (int)1)) * t) + s))) + (int)2))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Back_obj,easeInOut,return )


Back_obj::Back_obj()
{
}

void Back_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Back);
	HX_MARK_END_CLASS();
}

Dynamic Back_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { return easeIn_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { return easeOut_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { return easeInOut_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Back_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Back_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("easeIn"),
	HX_CSTRING("easeOut"),
	HX_CSTRING("easeInOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Back_obj::__mClass;

void Back_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Back"), hx::TCanCast< Back_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Back_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
