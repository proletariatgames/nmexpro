#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_effects_StarUseParticle
#include <com/mybo/effects/StarUseParticle.h>
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

Void StarUseParticle_obj::__construct(::nme::geom::Point pos)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",21)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",23)
	this->position = pos;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",25)
	this->particle = ::com::mybo::framework::particle::ParticleSystem_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",26)
	this->particle->disableBlendMode = true;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",27)
	this->particle->setTextureBitmapData(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("partile_star_2"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",28)
	this->particle->initWitdGravityData(this->initBounceParticle());
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",30)
	this->addChild(this->particle->canvas);
}
;
	return null();
}

StarUseParticle_obj::~StarUseParticle_obj() { }

Dynamic StarUseParticle_obj::__CreateEmpty() { return  new StarUseParticle_obj; }
hx::ObjectPtr< StarUseParticle_obj > StarUseParticle_obj::__new(::nme::geom::Point pos)
{  hx::ObjectPtr< StarUseParticle_obj > result = new StarUseParticle_obj();
	result->__construct(pos);
	return result;}

Dynamic StarUseParticle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StarUseParticle_obj > result = new StarUseParticle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void StarUseParticle_obj::run( ){
{
		HX_SOURCE_PUSH("StarUseParticle_obj::run")
		HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",33)
		this->particle->runSystem();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StarUseParticle_obj,run,(void))

::com::mybo::framework::particle::GravityModeData StarUseParticle_obj::initBounceParticle( ){
	HX_SOURCE_PUSH("StarUseParticle_obj::initBounceParticle")
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",38)
	::com::mybo::framework::particle::GravityModeData data = ::com::mybo::framework::particle::GravityModeData_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",40)
	data->maxParticles = (int)15;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",41)
	data->duration = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",42)
	data->lifespan = 0.75;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",43)
	data->lifespanVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",44)
	data->startSize = (int)22;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",45)
	data->startSizeVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",46)
	data->endSize = (int)5;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",47)
	data->endSizeVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",48)
	data->startRotation = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",49)
	data->startRotationVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",50)
	data->endRotation = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",51)
	data->endRotationVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",52)
	data->startColor = ::com::mybo::framework::particle::RGBA_obj::__new((int)1,(int)1,(int)1,(int)1);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",53)
	data->startColorVariance = ::com::mybo::framework::particle::RGBA_obj::__new((int)0,(int)0,(int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",54)
	data->endColor = ::com::mybo::framework::particle::RGBA_obj::__new((int)1,(int)1,(int)1,0.2);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",55)
	data->endColorVariance = ::com::mybo::framework::particle::RGBA_obj::__new((int)0,(int)0,(int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",56)
	data->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new(this->position->x,this->position->y);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",57)
	data->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",58)
	data->emitterAngle = (int)200;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",59)
	data->emitterAngleVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",60)
	data->emitRate = (int)10;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",63)
	data->speed = (int)586;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",64)
	data->speedVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",65)
	data->radialAcceleration = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",66)
	data->radialAccelVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",67)
	data->tangentialAcceleration = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",68)
	data->tangentialAccelVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",70)
	if (((this->position->x == (int)226))){
		HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",70)
		data->gravity = ::com::mybo::framework::particle::Vector_obj::__new((int)1065,(int)765);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",72)
		data->gravity = ::com::mybo::framework::particle::Vector_obj::__new((int)1015,(int)775);
	}
	HX_SOURCE_POS("../../../src/com/mybo/effects/StarUseParticle.hx",76)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(StarUseParticle_obj,initBounceParticle,return )


StarUseParticle_obj::StarUseParticle_obj()
{
}

void StarUseParticle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StarUseParticle);
	HX_MARK_MEMBER_NAME(particle,"particle");
	HX_MARK_MEMBER_NAME(position,"position");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic StarUseParticle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"particle") ) { return particle; }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"initBounceParticle") ) { return initBounceParticle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StarUseParticle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"particle") ) { particle=inValue.Cast< ::com::mybo::framework::particle::ParticleSystem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::nme::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StarUseParticle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("particle"));
	outFields->push(HX_CSTRING("position"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("particle"),
	HX_CSTRING("position"),
	HX_CSTRING("run"),
	HX_CSTRING("initBounceParticle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class StarUseParticle_obj::__mClass;

void StarUseParticle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.effects.StarUseParticle"), hx::TCanCast< StarUseParticle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StarUseParticle_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace effects
