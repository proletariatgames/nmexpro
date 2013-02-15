#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_effects_BurstParticle
#include <com/mybo/effects/BurstParticle.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_GravityModeData
#include <com/mybo/framework/particle/GravityModeData.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_ParticleSystem
#include <com/mybo/framework/particle/ParticleSystem.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_RGBA
#include <com/mybo/framework/particle/RGBA.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_Vector
#include <com/mybo/framework/particle/Vector.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace effects{

Void BurstParticle_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",18)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",19)
	this->particle = ::com::mybo::framework::particle::ParticleSystem_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",20)
	this->particle->setTextureBitmapData(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("particle_star"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",21)
	this->particle->initWitdGravityData(this->initBounceParticle());
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",22)
	this->addChild(this->particle->canvas);
}
;
	return null();
}

BurstParticle_obj::~BurstParticle_obj() { }

Dynamic BurstParticle_obj::__CreateEmpty() { return  new BurstParticle_obj; }
hx::ObjectPtr< BurstParticle_obj > BurstParticle_obj::__new()
{  hx::ObjectPtr< BurstParticle_obj > result = new BurstParticle_obj();
	result->__construct();
	return result;}

Dynamic BurstParticle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BurstParticle_obj > result = new BurstParticle_obj();
	result->__construct();
	return result;}

Void BurstParticle_obj::run( ){
{
		HX_SOURCE_PUSH("BurstParticle_obj::run")
		HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",25)
		this->particle->runSystem();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BurstParticle_obj,run,(void))

::com::mybo::framework::particle::GravityModeData BurstParticle_obj::initBounceParticle( ){
	HX_SOURCE_PUSH("BurstParticle_obj::initBounceParticle")
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",30)
	::com::mybo::framework::particle::GravityModeData data = ::com::mybo::framework::particle::GravityModeData_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",32)
	data->maxParticles = (int)20;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",36)
	data->duration = 0.1;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",37)
	data->lifespan = 0.5;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",38)
	data->lifespanVariance = 0.126;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",39)
	data->startSize = (int)6;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",40)
	data->startSizeVariance = (int)3;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",41)
	data->endSize = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",42)
	data->endSizeVariance = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",43)
	data->startRotation = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",44)
	data->startRotationVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",45)
	data->endRotation = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",46)
	data->endRotationVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",47)
	data->startColor = ::com::mybo::framework::particle::RGBA_obj::__new((int)1,(int)1,(int)0,(int)1);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",48)
	data->startColorVariance = ::com::mybo::framework::particle::RGBA_obj::__new((int)0,(int)0,(int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",49)
	data->endColor = ::com::mybo::framework::particle::RGBA_obj::__new((int)1,(int)0,(int)0,(int)1);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",50)
	data->endColorVariance = ::com::mybo::framework::particle::RGBA_obj::__new((int)0,(int)0,(int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",51)
	data->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",52)
	data->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new((int)15,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",53)
	data->emitterAngle = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",54)
	data->emitterAngleVariance = (int)360;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",55)
	data->emitRate = (int)800;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",58)
	data->speed = (int)500;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",59)
	data->speedVariance = (int)45;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",60)
	data->gravity = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",61)
	data->radialAcceleration = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",62)
	data->radialAccelVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",63)
	data->tangentialAcceleration = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",64)
	data->tangentialAccelVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BurstParticle.hx",66)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(BurstParticle_obj,initBounceParticle,return )


BurstParticle_obj::BurstParticle_obj()
{
}

void BurstParticle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BurstParticle);
	HX_MARK_MEMBER_NAME(particle,"particle");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BurstParticle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"particle") ) { return particle; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"initBounceParticle") ) { return initBounceParticle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BurstParticle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"particle") ) { particle=inValue.Cast< ::com::mybo::framework::particle::ParticleSystem >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BurstParticle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("particle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("particle"),
	HX_CSTRING("run"),
	HX_CSTRING("initBounceParticle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BurstParticle_obj::__mClass;

void BurstParticle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.effects.BurstParticle"), hx::TCanCast< BurstParticle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BurstParticle_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace effects
