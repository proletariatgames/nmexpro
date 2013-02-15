#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_Vector
#include <com/mybo/framework/particle/Vector.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace particle{

Void Vector_obj::__construct(Dynamic x,Dynamic y)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",7)
	super::__construct(x,y);
}
;
	return null();
}

Vector_obj::~Vector_obj() { }

Dynamic Vector_obj::__CreateEmpty() { return  new Vector_obj; }
hx::ObjectPtr< Vector_obj > Vector_obj::__new(Dynamic x,Dynamic y)
{  hx::ObjectPtr< Vector_obj > result = new Vector_obj();
	result->__construct(x,y);
	return result;}

Dynamic Vector_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector_obj > result = new Vector_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::com::mybo::framework::particle::Vector Vector_obj::unitVector( ){
	HX_SOURCE_PUSH("Vector_obj::unitVector")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",12)
	double len = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",13)
	return this->mult((double((int)1) / double(len)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector_obj,unitVector,return )

::com::mybo::framework::particle::Vector Vector_obj::addVector( ::com::mybo::framework::particle::Vector vec){
	HX_SOURCE_PUSH("Vector_obj::addVector")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",15)
	return ::com::mybo::framework::particle::Vector_obj::__new((this->x + vec->x),(this->y + vec->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector_obj,addVector,return )

::com::mybo::framework::particle::Vector Vector_obj::mult( double value){
	HX_SOURCE_PUSH("Vector_obj::mult")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",19)
	return ::com::mybo::framework::particle::Vector_obj::__new((this->x * value),(this->y * value));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector_obj,mult,return )

::com::mybo::framework::particle::Vector Vector_obj::copy( ){
	HX_SOURCE_PUSH("Vector_obj::copy")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",23)
	return ::com::mybo::framework::particle::Vector_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector_obj,copy,return )

::String Vector_obj::toString( ){
	HX_SOURCE_PUSH("Vector_obj::toString")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Vector.hx",27)
	return (((HX_CSTRING("X:") + this->x) + HX_CSTRING(",Y:")) + this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector_obj,toString,return )


Vector_obj::Vector_obj()
{
}

void Vector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Vector_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mult") ) { return mult_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addVector") ) { return addVector_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"unitVector") ) { return unitVector_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Vector_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Vector_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("unitVector"),
	HX_CSTRING("addVector"),
	HX_CSTRING("mult"),
	HX_CSTRING("copy"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Vector_obj::__mClass;

void Vector_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.particle.Vector"), hx::TCanCast< Vector_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Vector_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle
