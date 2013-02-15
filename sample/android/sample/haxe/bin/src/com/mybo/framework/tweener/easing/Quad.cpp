#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_tweener_easing_Quad
#include <com/mybo/framework/tweener/easing/Quad.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Quad_obj::__construct()
{
	return null();
}

Quad_obj::~Quad_obj() { }

Dynamic Quad_obj::__CreateEmpty() { return  new Quad_obj; }
hx::ObjectPtr< Quad_obj > Quad_obj::__new()
{  hx::ObjectPtr< Quad_obj > result = new Quad_obj();
	result->__construct();
	return result;}

Dynamic Quad_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Quad_obj > result = new Quad_obj();
	result->__construct();
	return result;}

hx::Object *Quad_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Quad_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Quad_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quad.hx",5)
	return (((c * (hx::DivEq(t,d))) * t) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quad_obj,easeIn,return )

double Quad_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Quad_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quad.hx",9)
	return (((-(c) * (hx::DivEq(t,d))) * ((t - (int)2))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quad_obj,easeOut,return )

double Quad_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Quad_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quad.hx",14)
	if ((((hx::DivEq(t,(double(d) / double((int)2)))) < (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quad.hx",14)
		return ((((double(c) / double((int)2)) * t) * t) + b);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quad.hx",15)
	return (((double(-(c)) / double((int)2)) * (((--(t) * ((t - (int)2))) - (int)1))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quad_obj,easeInOut,return )


Quad_obj::Quad_obj()
{
}

void Quad_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Quad);
	HX_MARK_END_CLASS();
}

Dynamic Quad_obj::__Field(const ::String &inName)
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

Dynamic Quad_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Quad_obj::__GetFields(Array< ::String> &outFields)
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

Class Quad_obj::__mClass;

void Quad_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Quad"), hx::TCanCast< Quad_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Quad_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
