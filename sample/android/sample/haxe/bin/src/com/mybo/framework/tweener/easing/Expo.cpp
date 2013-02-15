#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Expo
#include <com/mybo/framework/tweener/easing/Expo.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Expo_obj::__construct()
{
	return null();
}

Expo_obj::~Expo_obj() { }

Dynamic Expo_obj::__CreateEmpty() { return  new Expo_obj; }
hx::ObjectPtr< Expo_obj > Expo_obj::__new()
{  hx::ObjectPtr< Expo_obj > result = new Expo_obj();
	result->__construct();
	return result;}

Dynamic Expo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Expo_obj > result = new Expo_obj();
	result->__construct();
	return result;}

hx::Object *Expo_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Expo_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Expo_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",4)
	return (  (((t == (int)0))) ? double(b) : double(((c * ::Math_obj::pow((int)2,((int)10 * (((double(t) / double(d)) - (int)1))))) + b)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Expo_obj,easeIn,return )

double Expo_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Expo_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",8)
	return (  (((t == d))) ? double((b + c)) : double(((c * ((-(::Math_obj::pow((int)2,(double(((int)-10 * t)) / double(d)))) + (int)1))) + b)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Expo_obj,easeOut,return )

double Expo_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Expo_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",13)
	if (((t == (int)0))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",13)
		return b;
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",14)
	if (((t == d))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",14)
		return (b + c);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",15)
	if ((((hx::DivEq(t,(double(d) / double((int)2)))) < (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",15)
		return (((double(c) / double((int)2)) * ::Math_obj::pow((int)2,((int)10 * ((t - (int)1))))) + b);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Expo.hx",16)
	return (((double(c) / double((int)2)) * ((-(::Math_obj::pow((int)2,((int)-10 * --(t)))) + (int)2))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Expo_obj,easeInOut,return )


Expo_obj::Expo_obj()
{
}

void Expo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Expo);
	HX_MARK_END_CLASS();
}

Dynamic Expo_obj::__Field(const ::String &inName)
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

Dynamic Expo_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Expo_obj::__GetFields(Array< ::String> &outFields)
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

Class Expo_obj::__mClass;

void Expo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Expo"), hx::TCanCast< Expo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Expo_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
