#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_tweener_easing_Cubic
#include <com/mybo/framework/tweener/easing/Cubic.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Cubic_obj::__construct()
{
	return null();
}

Cubic_obj::~Cubic_obj() { }

Dynamic Cubic_obj::__CreateEmpty() { return  new Cubic_obj; }
hx::ObjectPtr< Cubic_obj > Cubic_obj::__new()
{  hx::ObjectPtr< Cubic_obj > result = new Cubic_obj();
	result->__construct();
	return result;}

Dynamic Cubic_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Cubic_obj > result = new Cubic_obj();
	result->__construct();
	return result;}

hx::Object *Cubic_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Cubic_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Cubic_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Cubic.hx",4)
	return ((((c * (hx::DivEq(t,d))) * t) * t) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Cubic_obj,easeIn,return )

double Cubic_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Cubic_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Cubic.hx",8)
	return ((c * (((((t = ((double(t) / double(d)) - (int)1)) * t) * t) + (int)1))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Cubic_obj,easeOut,return )

double Cubic_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Cubic_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Cubic.hx",12)
	if ((((hx::DivEq(t,(double(d) / double((int)2)))) < (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Cubic.hx",13)
		return (((((double(c) / double((int)2)) * t) * t) * t) + b);
	}
	else{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Cubic.hx",14)
		return (((double(c) / double((int)2)) * (((((hx::SubEq(t,(int)2)) * t) * t) + (int)2))) + b);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Cubic_obj,easeInOut,return )


Cubic_obj::Cubic_obj()
{
}

void Cubic_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Cubic);
	HX_MARK_END_CLASS();
}

Dynamic Cubic_obj::__Field(const ::String &inName)
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

Dynamic Cubic_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Cubic_obj::__GetFields(Array< ::String> &outFields)
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

Class Cubic_obj::__mClass;

void Cubic_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Cubic"), hx::TCanCast< Cubic_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Cubic_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
