#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_particle_RGBA
#include <com/mybo/framework/particle/RGBA.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_RadialModeData
#include <com/mybo/framework/particle/RadialModeData.h>
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

Void RadialModeData_obj::__construct()
{
{
}
;
	return null();
}

RadialModeData_obj::~RadialModeData_obj() { }

Dynamic RadialModeData_obj::__CreateEmpty() { return  new RadialModeData_obj; }
hx::ObjectPtr< RadialModeData_obj > RadialModeData_obj::__new()
{  hx::ObjectPtr< RadialModeData_obj > result = new RadialModeData_obj();
	result->__construct();
	return result;}

Dynamic RadialModeData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RadialModeData_obj > result = new RadialModeData_obj();
	result->__construct();
	return result;}


RadialModeData_obj::RadialModeData_obj()
{
}

void RadialModeData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RadialModeData);
	HX_MARK_MEMBER_NAME(keepSize,"keepSize");
	HX_MARK_MEMBER_NAME(keepColor,"keepColor");
	HX_MARK_MEMBER_NAME(keepRotationAngle,"keepRotationAngle");
	HX_MARK_MEMBER_NAME(maxParticles,"maxParticles");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_MEMBER_NAME(lifespan,"lifespan");
	HX_MARK_MEMBER_NAME(lifespanVariance,"lifespanVariance");
	HX_MARK_MEMBER_NAME(startSize,"startSize");
	HX_MARK_MEMBER_NAME(startSizeVariance,"startSizeVariance");
	HX_MARK_MEMBER_NAME(endSize,"endSize");
	HX_MARK_MEMBER_NAME(endSizeVariance,"endSizeVariance");
	HX_MARK_MEMBER_NAME(startRotation,"startRotation");
	HX_MARK_MEMBER_NAME(startRotationVariance,"startRotationVariance");
	HX_MARK_MEMBER_NAME(endRotation,"endRotation");
	HX_MARK_MEMBER_NAME(endRotationVariance,"endRotationVariance");
	HX_MARK_MEMBER_NAME(startColor,"startColor");
	HX_MARK_MEMBER_NAME(startColorVariance,"startColorVariance");
	HX_MARK_MEMBER_NAME(endColor,"endColor");
	HX_MARK_MEMBER_NAME(endColorVariance,"endColorVariance");
	HX_MARK_MEMBER_NAME(emitterPosition,"emitterPosition");
	HX_MARK_MEMBER_NAME(emitterAngle,"emitterAngle");
	HX_MARK_MEMBER_NAME(emitterAngleVariance,"emitterAngleVariance");
	HX_MARK_MEMBER_NAME(emitRate,"emitRate");
	HX_MARK_MEMBER_NAME(startRadius,"startRadius");
	HX_MARK_MEMBER_NAME(startRadiusVariance,"startRadiusVariance");
	HX_MARK_MEMBER_NAME(endRadius,"endRadius");
	HX_MARK_MEMBER_NAME(endRadiusVariance,"endRadiusVariance");
	HX_MARK_MEMBER_NAME(rotatePerSecond,"rotatePerSecond");
	HX_MARK_MEMBER_NAME(rotatePerSecondVariance,"rotatePerSecondVariance");
	HX_MARK_END_CLASS();
}

Dynamic RadialModeData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"endSize") ) { return endSize; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"keepSize") ) { return keepSize; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"lifespan") ) { return lifespan; }
		if (HX_FIELD_EQ(inName,"endColor") ) { return endColor; }
		if (HX_FIELD_EQ(inName,"emitRate") ) { return emitRate; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"keepColor") ) { return keepColor; }
		if (HX_FIELD_EQ(inName,"startSize") ) { return startSize; }
		if (HX_FIELD_EQ(inName,"endRadius") ) { return endRadius; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"startColor") ) { return startColor; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"endRotation") ) { return endRotation; }
		if (HX_FIELD_EQ(inName,"startRadius") ) { return startRadius; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"maxParticles") ) { return maxParticles; }
		if (HX_FIELD_EQ(inName,"emitterAngle") ) { return emitterAngle; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"startRotation") ) { return startRotation; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"endSizeVariance") ) { return endSizeVariance; }
		if (HX_FIELD_EQ(inName,"emitterPosition") ) { return emitterPosition; }
		if (HX_FIELD_EQ(inName,"rotatePerSecond") ) { return rotatePerSecond; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lifespanVariance") ) { return lifespanVariance; }
		if (HX_FIELD_EQ(inName,"endColorVariance") ) { return endColorVariance; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"keepRotationAngle") ) { return keepRotationAngle; }
		if (HX_FIELD_EQ(inName,"startSizeVariance") ) { return startSizeVariance; }
		if (HX_FIELD_EQ(inName,"endRadiusVariance") ) { return endRadiusVariance; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"startColorVariance") ) { return startColorVariance; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endRotationVariance") ) { return endRotationVariance; }
		if (HX_FIELD_EQ(inName,"startRadiusVariance") ) { return startRadiusVariance; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"emitterAngleVariance") ) { return emitterAngleVariance; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"startRotationVariance") ) { return startRotationVariance; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"rotatePerSecondVariance") ) { return rotatePerSecondVariance; }
	}
	return super::__Field(inName);
}

Dynamic RadialModeData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"endSize") ) { endSize=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"keepSize") ) { keepSize=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lifespan") ) { lifespan=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endColor") ) { endColor=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitRate") ) { emitRate=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"keepColor") ) { keepColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startSize") ) { startSize=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRadius") ) { endRadius=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"startColor") ) { startColor=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"endRotation") ) { endRotation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startRadius") ) { startRadius=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"maxParticles") ) { maxParticles=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitterAngle") ) { emitterAngle=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"startRotation") ) { startRotation=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"endSizeVariance") ) { endSizeVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitterPosition") ) { emitterPosition=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotatePerSecond") ) { rotatePerSecond=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lifespanVariance") ) { lifespanVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endColorVariance") ) { endColorVariance=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"keepRotationAngle") ) { keepRotationAngle=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startSizeVariance") ) { startSizeVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRadiusVariance") ) { endRadiusVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"startColorVariance") ) { startColorVariance=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endRotationVariance") ) { endRotationVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startRadiusVariance") ) { startRadiusVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"emitterAngleVariance") ) { emitterAngleVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"startRotationVariance") ) { startRotationVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"rotatePerSecondVariance") ) { rotatePerSecondVariance=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void RadialModeData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("keepSize"));
	outFields->push(HX_CSTRING("keepColor"));
	outFields->push(HX_CSTRING("keepRotationAngle"));
	outFields->push(HX_CSTRING("maxParticles"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("lifespan"));
	outFields->push(HX_CSTRING("lifespanVariance"));
	outFields->push(HX_CSTRING("startSize"));
	outFields->push(HX_CSTRING("startSizeVariance"));
	outFields->push(HX_CSTRING("endSize"));
	outFields->push(HX_CSTRING("endSizeVariance"));
	outFields->push(HX_CSTRING("startRotation"));
	outFields->push(HX_CSTRING("startRotationVariance"));
	outFields->push(HX_CSTRING("endRotation"));
	outFields->push(HX_CSTRING("endRotationVariance"));
	outFields->push(HX_CSTRING("startColor"));
	outFields->push(HX_CSTRING("startColorVariance"));
	outFields->push(HX_CSTRING("endColor"));
	outFields->push(HX_CSTRING("endColorVariance"));
	outFields->push(HX_CSTRING("emitterPosition"));
	outFields->push(HX_CSTRING("emitterAngle"));
	outFields->push(HX_CSTRING("emitterAngleVariance"));
	outFields->push(HX_CSTRING("emitRate"));
	outFields->push(HX_CSTRING("startRadius"));
	outFields->push(HX_CSTRING("startRadiusVariance"));
	outFields->push(HX_CSTRING("endRadius"));
	outFields->push(HX_CSTRING("endRadiusVariance"));
	outFields->push(HX_CSTRING("rotatePerSecond"));
	outFields->push(HX_CSTRING("rotatePerSecondVariance"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("keepSize"),
	HX_CSTRING("keepColor"),
	HX_CSTRING("keepRotationAngle"),
	HX_CSTRING("maxParticles"),
	HX_CSTRING("duration"),
	HX_CSTRING("lifespan"),
	HX_CSTRING("lifespanVariance"),
	HX_CSTRING("startSize"),
	HX_CSTRING("startSizeVariance"),
	HX_CSTRING("endSize"),
	HX_CSTRING("endSizeVariance"),
	HX_CSTRING("startRotation"),
	HX_CSTRING("startRotationVariance"),
	HX_CSTRING("endRotation"),
	HX_CSTRING("endRotationVariance"),
	HX_CSTRING("startColor"),
	HX_CSTRING("startColorVariance"),
	HX_CSTRING("endColor"),
	HX_CSTRING("endColorVariance"),
	HX_CSTRING("emitterPosition"),
	HX_CSTRING("emitterAngle"),
	HX_CSTRING("emitterAngleVariance"),
	HX_CSTRING("emitRate"),
	HX_CSTRING("startRadius"),
	HX_CSTRING("startRadiusVariance"),
	HX_CSTRING("endRadius"),
	HX_CSTRING("endRadiusVariance"),
	HX_CSTRING("rotatePerSecond"),
	HX_CSTRING("rotatePerSecondVariance"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class RadialModeData_obj::__mClass;

void RadialModeData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.particle.RadialModeData"), hx::TCanCast< RadialModeData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RadialModeData_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle
