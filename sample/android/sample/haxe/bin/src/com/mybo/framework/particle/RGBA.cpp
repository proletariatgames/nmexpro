#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_particle_RGBA
#include <com/mybo/framework/particle/RGBA.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace particle{

Void RGBA_obj::__construct(Dynamic r,Dynamic g,Dynamic b,Dynamic a)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",11)
	this->r = r;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",12)
	this->g = g;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",13)
	this->b = b;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",14)
	this->a = a;
}
;
	return null();
}

RGBA_obj::~RGBA_obj() { }

Dynamic RGBA_obj::__CreateEmpty() { return  new RGBA_obj; }
hx::ObjectPtr< RGBA_obj > RGBA_obj::__new(Dynamic r,Dynamic g,Dynamic b,Dynamic a)
{  hx::ObjectPtr< RGBA_obj > result = new RGBA_obj();
	result->__construct(r,g,b,a);
	return result;}

Dynamic RGBA_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RGBA_obj > result = new RGBA_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void RGBA_obj::mult( double value){
{
		HX_SOURCE_PUSH("RGBA_obj::mult")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",18)
		hx::MultEq(this->r,value);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",19)
		hx::MultEq(this->g,value);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",20)
		hx::MultEq(this->b,value);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",21)
		hx::MultEq(this->a,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RGBA_obj,mult,(void))

Void RGBA_obj::add( ::com::mybo::framework::particle::RGBA rgba){
{
		HX_SOURCE_PUSH("RGBA_obj::add")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",25)
		hx::AddEq(this->r,rgba->r);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",26)
		hx::AddEq(this->g,rgba->g);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",27)
		hx::AddEq(this->b,rgba->b);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",28)
		hx::AddEq(this->a,rgba->a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RGBA_obj,add,(void))

bool RGBA_obj::equal( ::com::mybo::framework::particle::RGBA rgba){
	HX_SOURCE_PUSH("RGBA_obj::equal")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/RGBA.hx",32)
	return (bool((bool((bool((this->r == rgba->r)) && bool((this->g == rgba->g)))) && bool((this->b == rgba->b)))) && bool((this->a == rgba->a)));
}


HX_DEFINE_DYNAMIC_FUNC1(RGBA_obj,equal,return )


RGBA_obj::RGBA_obj()
{
}

void RGBA_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RGBA);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_END_CLASS();
}

Dynamic RGBA_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mult") ) { return mult_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"equal") ) { return equal_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic RGBA_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void RGBA_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("mult"),
	HX_CSTRING("add"),
	HX_CSTRING("equal"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class RGBA_obj::__mClass;

void RGBA_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.particle.RGBA"), hx::TCanCast< RGBA_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RGBA_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle
