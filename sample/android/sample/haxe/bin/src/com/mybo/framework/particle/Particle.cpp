#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_particle_Particle
#include <com/mybo/framework/particle/Particle.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_RGBA
#include <com/mybo/framework/particle/RGBA.h>
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

Void Particle_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",25)
	this->pos = ::com::mybo::framework::particle::Vector_obj::__new(null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",26)
	this->color = ::com::mybo::framework::particle::RGBA_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",27)
	this->deltaColor = ::com::mybo::framework::particle::RGBA_obj::__new(null(),null(),null(),null());
}
;
	return null();
}

Particle_obj::~Particle_obj() { }

Dynamic Particle_obj::__CreateEmpty() { return  new Particle_obj; }
hx::ObjectPtr< Particle_obj > Particle_obj::__new()
{  hx::ObjectPtr< Particle_obj > result = new Particle_obj();
	result->__construct();
	return result;}

Dynamic Particle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Particle_obj > result = new Particle_obj();
	result->__construct();
	return result;}

double Particle_obj::getSpeedX( ){
	HX_SOURCE_PUSH("Particle_obj::getSpeedX")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",31)
	return this->speedX_or_angle;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getSpeedX,return )

Void Particle_obj::setSpeedX( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setSpeedX")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",34)
		this->speedX_or_angle = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setSpeedX,(void))

double Particle_obj::getSpeedY( ){
	HX_SOURCE_PUSH("Particle_obj::getSpeedY")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",37)
	return this->speedY_or_anglePerSecond;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getSpeedY,return )

Void Particle_obj::setSpeedY( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setSpeedY")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",40)
		this->speedY_or_anglePerSecond = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setSpeedY,(void))

double Particle_obj::getRadialAccel( ){
	HX_SOURCE_PUSH("Particle_obj::getRadialAccel")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",43)
	return this->radialAccel_or_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getRadialAccel,return )

Void Particle_obj::setRadialAccel( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setRadialAccel")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",46)
		this->radialAccel_or_radius = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setRadialAccel,(void))

double Particle_obj::getTangentialAccel( ){
	HX_SOURCE_PUSH("Particle_obj::getTangentialAccel")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",49)
	return this->tangentialAccel_or_deltaRadius;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getTangentialAccel,return )

Void Particle_obj::setTangentialAccel( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setTangentialAccel")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",52)
		this->tangentialAccel_or_deltaRadius = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setTangentialAccel,(void))

double Particle_obj::getAngle( ){
	HX_SOURCE_PUSH("Particle_obj::getAngle")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",56)
	return this->speedX_or_angle;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getAngle,return )

Void Particle_obj::setAngle( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setAngle")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",59)
		this->speedX_or_angle = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setAngle,(void))

double Particle_obj::getAnglePerSecond( ){
	HX_SOURCE_PUSH("Particle_obj::getAnglePerSecond")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",62)
	return this->speedY_or_anglePerSecond;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getAnglePerSecond,return )

Void Particle_obj::setAnglePerSecond( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setAnglePerSecond")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",65)
		this->speedY_or_anglePerSecond = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setAnglePerSecond,(void))

double Particle_obj::getRadius( ){
	HX_SOURCE_PUSH("Particle_obj::getRadius")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",68)
	return this->radialAccel_or_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getRadius,return )

Void Particle_obj::setRadius( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setRadius")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",71)
		this->radialAccel_or_radius = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setRadius,(void))

double Particle_obj::getDeltaRadius( ){
	HX_SOURCE_PUSH("Particle_obj::getDeltaRadius")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",74)
	return this->tangentialAccel_or_deltaRadius;
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,getDeltaRadius,return )

Void Particle_obj::setDeltaRadius( double value){
{
		HX_SOURCE_PUSH("Particle_obj::setDeltaRadius")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/Particle.hx",77)
		this->tangentialAccel_or_deltaRadius = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,setDeltaRadius,(void))


Particle_obj::Particle_obj()
{
}

void Particle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Particle);
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_MEMBER_NAME(lifeSpan,"lifeSpan");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(deltaColor,"deltaColor");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(deltaSize,"deltaSize");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(deltaRotation,"deltaRotation");
	HX_MARK_MEMBER_NAME(speedX_or_angle,"speedX_or_angle");
	HX_MARK_MEMBER_NAME(speedY_or_anglePerSecond,"speedY_or_anglePerSecond");
	HX_MARK_MEMBER_NAME(radialAccel_or_radius,"radialAccel_or_radius");
	HX_MARK_MEMBER_NAME(tangentialAccel_or_deltaRadius,"tangentialAccel_or_deltaRadius");
	HX_MARK_END_CLASS();
}

Dynamic Particle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"lifeSpan") ) { return lifeSpan; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"setAngle") ) { return setAngle_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"deltaSize") ) { return deltaSize; }
		if (HX_FIELD_EQ(inName,"getSpeedX") ) { return getSpeedX_dyn(); }
		if (HX_FIELD_EQ(inName,"setSpeedX") ) { return setSpeedX_dyn(); }
		if (HX_FIELD_EQ(inName,"getSpeedY") ) { return getSpeedY_dyn(); }
		if (HX_FIELD_EQ(inName,"setSpeedY") ) { return setSpeedY_dyn(); }
		if (HX_FIELD_EQ(inName,"getRadius") ) { return getRadius_dyn(); }
		if (HX_FIELD_EQ(inName,"setRadius") ) { return setRadius_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deltaColor") ) { return deltaColor; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"deltaRotation") ) { return deltaRotation; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getRadialAccel") ) { return getRadialAccel_dyn(); }
		if (HX_FIELD_EQ(inName,"setRadialAccel") ) { return setRadialAccel_dyn(); }
		if (HX_FIELD_EQ(inName,"getDeltaRadius") ) { return getDeltaRadius_dyn(); }
		if (HX_FIELD_EQ(inName,"setDeltaRadius") ) { return setDeltaRadius_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"speedX_or_angle") ) { return speedX_or_angle; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getAnglePerSecond") ) { return getAnglePerSecond_dyn(); }
		if (HX_FIELD_EQ(inName,"setAnglePerSecond") ) { return setAnglePerSecond_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getTangentialAccel") ) { return getTangentialAccel_dyn(); }
		if (HX_FIELD_EQ(inName,"setTangentialAccel") ) { return setTangentialAccel_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"radialAccel_or_radius") ) { return radialAccel_or_radius; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"speedY_or_anglePerSecond") ) { return speedY_or_anglePerSecond; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"tangentialAccel_or_deltaRadius") ) { return tangentialAccel_or_deltaRadius; }
	}
	return super::__Field(inName);
}

Dynamic Particle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"lifeSpan") ) { lifeSpan=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"deltaSize") ) { deltaSize=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deltaColor") ) { deltaColor=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"deltaRotation") ) { deltaRotation=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"speedX_or_angle") ) { speedX_or_angle=inValue.Cast< double >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"radialAccel_or_radius") ) { radialAccel_or_radius=inValue.Cast< double >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"speedY_or_anglePerSecond") ) { speedY_or_anglePerSecond=inValue.Cast< double >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"tangentialAccel_or_deltaRadius") ) { tangentialAccel_or_deltaRadius=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Particle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pos"));
	outFields->push(HX_CSTRING("lifeSpan"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("deltaColor"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("deltaSize"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("deltaRotation"));
	outFields->push(HX_CSTRING("speedX_or_angle"));
	outFields->push(HX_CSTRING("speedY_or_anglePerSecond"));
	outFields->push(HX_CSTRING("radialAccel_or_radius"));
	outFields->push(HX_CSTRING("tangentialAccel_or_deltaRadius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pos"),
	HX_CSTRING("lifeSpan"),
	HX_CSTRING("color"),
	HX_CSTRING("deltaColor"),
	HX_CSTRING("size"),
	HX_CSTRING("deltaSize"),
	HX_CSTRING("rotation"),
	HX_CSTRING("deltaRotation"),
	HX_CSTRING("speedX_or_angle"),
	HX_CSTRING("speedY_or_anglePerSecond"),
	HX_CSTRING("radialAccel_or_radius"),
	HX_CSTRING("tangentialAccel_or_deltaRadius"),
	HX_CSTRING("getSpeedX"),
	HX_CSTRING("setSpeedX"),
	HX_CSTRING("getSpeedY"),
	HX_CSTRING("setSpeedY"),
	HX_CSTRING("getRadialAccel"),
	HX_CSTRING("setRadialAccel"),
	HX_CSTRING("getTangentialAccel"),
	HX_CSTRING("setTangentialAccel"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("setAngle"),
	HX_CSTRING("getAnglePerSecond"),
	HX_CSTRING("setAnglePerSecond"),
	HX_CSTRING("getRadius"),
	HX_CSTRING("setRadius"),
	HX_CSTRING("getDeltaRadius"),
	HX_CSTRING("setDeltaRadius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Particle_obj::__mClass;

void Particle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.particle.Particle"), hx::TCanCast< Particle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Particle_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle
