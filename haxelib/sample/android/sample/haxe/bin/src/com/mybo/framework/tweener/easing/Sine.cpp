#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Sine
#include <com/mybo/framework/tweener/easing/Sine.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Sine_obj::__construct()
{
	return null();
}

Sine_obj::~Sine_obj() { }

Dynamic Sine_obj::__CreateEmpty() { return  new Sine_obj; }
hx::ObjectPtr< Sine_obj > Sine_obj::__new()
{  hx::ObjectPtr< Sine_obj > result = new Sine_obj();
	result->__construct();
	return result;}

Dynamic Sine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sine_obj > result = new Sine_obj();
	result->__construct();
	return result;}

hx::Object *Sine_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Sine_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Sine_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Sine.hx",5)
	return (((-(c) * ::Math_obj::cos(((double(t) / double(d)) * ((double(::Math_obj::PI) / double((int)2)))))) + c) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Sine_obj,easeIn,return )

double Sine_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Sine_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Sine.hx",9)
	return ((c * ::Math_obj::sin(((double(t) / double(d)) * ((double(::Math_obj::PI) / double((int)2)))))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Sine_obj,easeOut,return )

double Sine_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Sine_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Sine.hx",13)
	return (((double(-(c)) / double((int)2)) * ((::Math_obj::cos((double((::Math_obj::PI * t)) / double(d))) - (int)1))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Sine_obj,easeInOut,return )


Sine_obj::Sine_obj()
{
}

void Sine_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sine);
	HX_MARK_END_CLASS();
}

Dynamic Sine_obj::__Field(const ::String &inName)
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

Dynamic Sine_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Sine_obj::__GetFields(Array< ::String> &outFields)
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

Class Sine_obj::__mClass;

void Sine_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Sine"), hx::TCanCast< Sine_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sine_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
