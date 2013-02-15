#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_tweener_easing_Bounce
#include <com/mybo/framework/tweener/easing/Bounce.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{

Void Bounce_obj::__construct()
{
	return null();
}

Bounce_obj::~Bounce_obj() { }

Dynamic Bounce_obj::__CreateEmpty() { return  new Bounce_obj; }
hx::ObjectPtr< Bounce_obj > Bounce_obj::__new()
{  hx::ObjectPtr< Bounce_obj > result = new Bounce_obj();
	result->__construct();
	return result;}

Dynamic Bounce_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bounce_obj > result = new Bounce_obj();
	result->__construct();
	return result;}

hx::Object *Bounce_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

double Bounce_obj::easeOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Bounce_obj::easeOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",5)
	if ((((hx::DivEq(t,d)) < (double((int)1) / double(2.75))))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",6)
		return ((c * (((7.5625 * t) * t))) + b);
	}
	else{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",7)
		if (((t < (double((int)2) / double(2.75))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",7)
			return ((c * ((((7.5625 * (hx::SubEq(t,(double(1.5) / double(2.75))))) * t) + .75))) + b);
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",8)
			if (((t < (double(2.5) / double(2.75))))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",8)
				return ((c * ((((7.5625 * (hx::SubEq(t,(double(2.25) / double(2.75))))) * t) + .9375))) + b);
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",9)
				return ((c * ((((7.5625 * (hx::SubEq(t,(double(2.625) / double(2.75))))) * t) + .984375))) + b);
			}
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Bounce_obj,easeOut,return )

double Bounce_obj::easeIn( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Bounce_obj::easeIn")
	struct _Function_1_1{
		inline static double Block( double &t,double &d,double &c){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",13)
			double t1 = (d - t);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",13)
			return (  ((((hx::DivEq(t1,d)) < (double((int)1) / double(2.75))))) ? double((c * (((7.5625 * t1) * t1)))) : double((  (((t1 < (double((int)2) / double(2.75))))) ? double((c * ((((7.5625 * (hx::SubEq(t1,(double(1.5) / double(2.75))))) * t1) + .75)))) : double((  (((t1 < (double(2.5) / double(2.75))))) ? double((c * ((((7.5625 * (hx::SubEq(t1,(double(2.25) / double(2.75))))) * t1) + .9375)))) : double((c * ((((7.5625 * (hx::SubEq(t1,(double(2.625) / double(2.75))))) * t1) + .984375)))) )) )) );
		}
	};
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",12)
	return ((c - _Function_1_1::Block(t,d,c)) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Bounce_obj,easeIn,return )

double Bounce_obj::easeInOut( double t,double b,double c,double d){
	HX_SOURCE_PUSH("Bounce_obj::easeInOut")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",16)
	if (((t < (double(d) / double((int)2))))){
		struct _Function_2_1{
			inline static double Block( double &t,double &d,double &c){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",17)
				double t1 = (d - (t * (int)2));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",17)
				return (  ((((hx::DivEq(t1,d)) < (double((int)1) / double(2.75))))) ? double((c * (((7.5625 * t1) * t1)))) : double((  (((t1 < (double((int)2) / double(2.75))))) ? double((c * ((((7.5625 * (hx::SubEq(t1,(double(1.5) / double(2.75))))) * t1) + .75)))) : double((  (((t1 < (double(2.5) / double(2.75))))) ? double((c * ((((7.5625 * (hx::SubEq(t1,(double(2.25) / double(2.75))))) * t1) + .9375)))) : double((c * ((((7.5625 * (hx::SubEq(t1,(double(2.625) / double(2.75))))) * t1) + .984375)))) )) )) );
			}
		};
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",17)
		return ((((c - _Function_2_1::Block(t,d,c))) * .5) + b);
	}
	else{
		struct _Function_2_1{
			inline static double Block( double &t,double &d,double &c){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",18)
				double t1 = ((t * (int)2) - d);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",18)
				return (  ((((hx::DivEq(t1,d)) < (double((int)1) / double(2.75))))) ? double((c * (((7.5625 * t1) * t1)))) : double((  (((t1 < (double((int)2) / double(2.75))))) ? double((c * ((((7.5625 * (hx::SubEq(t1,(double(1.5) / double(2.75))))) * t1) + .75)))) : double((  (((t1 < (double(2.5) / double(2.75))))) ? double((c * ((((7.5625 * (hx::SubEq(t1,(double(2.25) / double(2.75))))) * t1) + .9375)))) : double((c * ((((7.5625 * (hx::SubEq(t1,(double(2.625) / double(2.75))))) * t1) + .984375)))) )) )) );
			}
		};
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/easing/Bounce.hx",18)
		return (((_Function_2_1::Block(t,d,c) * .5) + (c * .5)) + b);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Bounce_obj,easeInOut,return )


Bounce_obj::Bounce_obj()
{
}

void Bounce_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bounce);
	HX_MARK_END_CLASS();
}

Dynamic Bounce_obj::__Field(const ::String &inName)
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

Dynamic Bounce_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Bounce_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("easeOut"),
	HX_CSTRING("easeIn"),
	HX_CSTRING("easeInOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Bounce_obj::__mClass;

void Bounce_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.easing.Bounce"), hx::TCanCast< Bounce_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bounce_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing
