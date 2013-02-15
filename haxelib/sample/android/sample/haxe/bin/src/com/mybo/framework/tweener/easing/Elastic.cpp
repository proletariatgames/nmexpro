#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Elastic
#include <com/mybo/framework/tweener/easing/Elastic.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Elastic_obj::__construct()
{
	return null();
}

Elastic_obj::~Elastic_obj() { }

Dynamic Elastic_obj::__CreateEmpty() { return  new Elastic_obj; }
hx::ObjectPtr< Elastic_obj > Elastic_obj::__new()
{  hx::ObjectPtr< Elastic_obj > result = new Elastic_obj();
	result->__construct();
	return result;}

Dynamic Elastic_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Elastic_obj > result = new Elastic_obj();
	result->__construct();
	return result;}

hx::Object *Elastic_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Elastic_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Elastic_obj::easeIn")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",6)
	if (((t == (int)0))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",6)
		return b;
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",7)
	if ((((hx::DivEq(t,d)) == (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",7)
		return (b + c);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",9)
	double p = (d * .3);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",10)
	double s;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",11)
	double a = c;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",12)
	s = (double(p) / double((int)4));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",14)
	return (-((((a * ::Math_obj::pow((int)2,((int)10 * (hx::SubEq(t,(int)1))))) * ::Math_obj::sin((double(((((t * d) - s)) * (((int)2 * ::Math_obj::PI)))) / double(p)))))) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Elastic_obj,easeIn,return )

double Elastic_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Elastic_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",19)
	if (((t == (int)0))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",19)
		return b;
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",20)
	if ((((hx::DivEq(t,d)) == (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",20)
		return (b + c);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",22)
	double p = (d * .3);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",23)
	double s;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",24)
	double a = c;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",25)
	s = (double(p) / double((int)4));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",27)
	return ((((a * ::Math_obj::pow((int)2,((int)-10 * t))) * ::Math_obj::sin((double(((((t * d) - s)) * (((int)2 * ::Math_obj::PI)))) / double(p)))) + c) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Elastic_obj,easeOut,return )

double Elastic_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Elastic_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",31)
	if (((t == (int)0))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",31)
		return b;
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",32)
	if ((((hx::DivEq(t,(double(d) / double((int)2)))) == (int)2))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",32)
		return (b + c);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",34)
	double s;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",35)
	double p = (d * ((.3 * 1.5)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",36)
	double a = c;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",37)
	s = (double(p) / double((int)4));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",39)
	if (((t < (int)1))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",39)
		return ((-0.5 * (((a * ::Math_obj::pow((int)2,((int)10 * (hx::SubEq(t,(int)1))))) * ::Math_obj::sin((double(((((t * d) - s)) * (((int)2 * ::Math_obj::PI)))) / double(p)))))) + b);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Elastic.hx",40)
	return (((((a * ::Math_obj::pow((int)2,((int)-10 * (hx::SubEq(t,(int)1))))) * ::Math_obj::sin((double(((((t * d) - s)) * (((int)2 * ::Math_obj::PI)))) / double(p)))) * .5) + c) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Elastic_obj,easeInOut,return )


Elastic_obj::Elastic_obj()
{
}

void Elastic_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Elastic);
	HX_MARK_END_CLASS();
}

Dynamic Elastic_obj::__Field(const ::String &inName)
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

Dynamic Elastic_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Elastic_obj::__GetFields(Array< ::String> &outFields)
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

Class Elastic_obj::__mClass;

void Elastic_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Elastic"), hx::TCanCast< Elastic_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Elastic_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
