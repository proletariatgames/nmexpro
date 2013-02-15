#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_tweener_easing_Quint
#include <com/mybo/framework/tweener/easing/Quint.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Quint_obj::__construct()
{
	return null();
}

Quint_obj::~Quint_obj() { }

Dynamic Quint_obj::__CreateEmpty() { return  new Quint_obj; }
hx::ObjectPtr< Quint_obj > Quint_obj::__new()
{  hx::ObjectPtr< Quint_obj > result = new Quint_obj();
	result->__construct();
	return result;}

Dynamic Quint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Quint_obj > result = new Quint_obj();
	result->__construct();
	return result;}

hx::Object *Quint_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Quint_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Quint_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quint.hx",5)
	return ((((((c * (hx::DivEq(t,d))) * t) * t) * t) * t) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quint_obj,easeIn,return )

double Quint_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Quint_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quint.hx",9)
	return ((c * (((((((t = ((double(t) / double(d)) - (int)1)) * t) * t) * t) * t) + (int)1))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quint_obj,easeOut,return )

double Quint_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Quint_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quint.hx",14)
	if ((((hx::DivEq(t,(double(d) / double((int)2)))) < (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quint.hx",14)
		return (((((((double(c) / double((int)2)) * t) * t) * t) * t) * t) + b);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Quint.hx",16)
	return (((double(c) / double((int)2)) * (((((((hx::SubEq(t,(int)2)) * t) * t) * t) * t) + (int)2))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Quint_obj,easeInOut,return )


Quint_obj::Quint_obj()
{
}

void Quint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Quint);
	HX_MARK_END_CLASS();
}

Dynamic Quint_obj::__Field(const ::String &inName)
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

Dynamic Quint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Quint_obj::__GetFields(Array< ::String> &outFields)
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

Class Quint_obj::__mClass;

void Quint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Quint"), hx::TCanCast< Quint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Quint_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
