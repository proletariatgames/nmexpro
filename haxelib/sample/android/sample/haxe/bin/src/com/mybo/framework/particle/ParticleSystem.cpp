#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_EmitterMode
#include <com/mybo/framework/particle/EmitterMode.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_GravityModeData
#include <com/mybo/framework/particle/GravityModeData.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_Particle
#include <com/mybo/framework/particle/Particle.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_ParticleSystem
#include <com/mybo/framework/particle/ParticleSystem.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_RGBA
#include <com/mybo/framework/particle/RGBA.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_RadialModeData
#include <com/mybo/framework/particle/RadialModeData.h>
#endif
#ifndef INCLUDED_com_mybo_framework_particle_Vector
#include <com/mybo/framework/particle/Vector.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
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
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace particle{

Void ParticleSystem_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",77)
	this->canvas = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",78)
	this->particles = Array_obj< ::com::mybo::framework::particle::Particle >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",79)
	this->deadParticles = Array_obj< ::com::mybo::framework::particle::Particle >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",81)
	this->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new(null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",82)
	this->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new(null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",83)
	this->startColor = ::com::mybo::framework::particle::RGBA_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",84)
	this->startColorVariance = ::com::mybo::framework::particle::RGBA_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",85)
	this->endColor = ::com::mybo::framework::particle::RGBA_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",86)
	this->endColorVariance = ::com::mybo::framework::particle::RGBA_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",87)
	this->gravity = ::com::mybo::framework::particle::Vector_obj::__new(null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",89)
	this->keepRotationAngle = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",90)
	this->keepSize = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",91)
	this->keepColor = false;
}
;
	return null();
}

ParticleSystem_obj::~ParticleSystem_obj() { }

Dynamic ParticleSystem_obj::__CreateEmpty() { return  new ParticleSystem_obj; }
hx::ObjectPtr< ParticleSystem_obj > ParticleSystem_obj::__new()
{  hx::ObjectPtr< ParticleSystem_obj > result = new ParticleSystem_obj();
	result->__construct();
	return result;}

Dynamic ParticleSystem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleSystem_obj > result = new ParticleSystem_obj();
	result->__construct();
	return result;}

Void ParticleSystem_obj::initWitdGravityData( ::com::mybo::framework::particle::GravityModeData data){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::initWitdGravityData")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",95)
		this->emitterMode = ::com::mybo::framework::particle::EmitterMode_obj::gravityMode_dyn();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",97)
		this->keepRotationAngle = data->keepRotationAngle;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",98)
		this->keepSize = data->keepSize;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",99)
		this->keepColor = data->keepColor;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",101)
		this->maxParticles = data->maxParticles;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",102)
		this->duration = data->duration;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",103)
		this->lifespan = data->lifespan;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",104)
		this->lifespanVariance = data->lifespanVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",105)
		this->startSize = data->startSize;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",106)
		this->startSizeVariance = data->startSizeVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",107)
		this->endSize = data->endSize;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",108)
		this->endSizeVariance = data->endSizeVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",109)
		this->startRotation = data->startRotation;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",110)
		this->startRotationVariance = data->startRotationVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",111)
		this->endRotation = data->endRotation;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",112)
		this->endRotationVariance = data->endRotationVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",113)
		this->emitterAngle = data->emitterAngle;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",114)
		this->emitterAngleVariance = data->emitterAngleVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",116)
		if (((null() != data->startColor))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",116)
			this->startColor = data->startColor;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",117)
		if (((null() != data->startColorVariance))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",117)
			this->startColorVariance = data->startColorVariance;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",118)
		if (((null() != data->endColor))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",118)
			this->endColor = data->endColor;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",119)
		if (((null() != data->endColorVariance))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",119)
			this->endColorVariance = data->endColorVariance;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",120)
		if (((null() != data->emitterPosition))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",120)
			this->emitterPosition = data->emitterPosition;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",121)
		if (((null() != data->emitterPosVariance))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",121)
			this->emitterPosVariance = data->emitterPosVariance;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",123)
		this->emitRate = (  (((data->emitRate == (int)0))) ? int(::Std_obj::_int((double(this->maxParticles) / double(this->lifespan)))) : int(data->emitRate) );
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",126)
		this->speed = data->speed;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",127)
		this->speedVariance = data->speedVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",128)
		if (((null() != data->gravity))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",128)
			this->gravity = data->gravity;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",129)
		this->radialAcceleration = data->radialAcceleration;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",130)
		this->radialAccelVariance = data->radialAccelVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",131)
		this->tangentialAcceleration = data->tangentialAcceleration;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",132)
		this->tangentialAccelVariance = data->tangentialAccelVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",135)
		this->allSameSize = (bool((bool((this->startSize == this->endSize)) && bool((this->startSizeVariance == (int)0)))) && bool((this->endSizeVariance == (int)0)));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",136)
		this->allRotationZero = (bool((bool((bool((this->startRotation == (int)0)) && bool((this->endRotation == (int)0)))) && bool((this->startRotationVariance == (int)0)))) && bool((this->endRotationVariance == (int)0)));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",138)
		::com::mybo::framework::particle::RGBA zeroColor = ::com::mybo::framework::particle::RGBA_obj::__new(0.0,0.0,0.0,0.0);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",139)
		this->allSameColor = (bool((bool(this->startColor->equal(this->endColor)) && bool(this->startColorVariance->equal(zeroColor)))) && bool(this->endColorVariance->equal(zeroColor)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,initWitdGravityData,(void))

Void ParticleSystem_obj::initWitdRadialData( ::com::mybo::framework::particle::RadialModeData data){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::initWitdRadialData")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",145)
		this->emitterMode = ::com::mybo::framework::particle::EmitterMode_obj::radialMode_dyn();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",147)
		this->keepRotationAngle = data->keepRotationAngle;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",148)
		this->keepSize = data->keepSize;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",149)
		this->keepColor = data->keepColor;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",151)
		this->maxParticles = data->maxParticles;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",152)
		this->duration = data->duration;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",153)
		this->lifespan = data->lifespan;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",154)
		this->lifespanVariance = data->lifespanVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",155)
		this->startSize = data->startSize;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",156)
		this->startSizeVariance = data->startSizeVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",157)
		this->endSize = data->endSize;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",158)
		this->endSizeVariance = data->endSizeVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",159)
		this->startRotation = data->startRotation;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",160)
		this->startRotationVariance = data->startRotationVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",161)
		this->endRotation = data->endRotation;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",162)
		this->endRotationVariance = data->endRotationVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",163)
		this->emitterAngle = data->emitterAngle;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",164)
		this->emitterAngleVariance = data->emitterAngleVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",166)
		if (((null() != data->startColor))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",166)
			this->startColor = data->startColor;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",167)
		if (((null() != data->startColorVariance))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",167)
			this->startColorVariance = data->startColorVariance;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",168)
		if (((null() != data->endColor))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",168)
			this->endColor = data->endColor;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",169)
		if (((null() != data->endColorVariance))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",169)
			this->endColorVariance = data->endColorVariance;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",170)
		if (((null() != data->emitterPosition))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",170)
			this->emitterPosition = data->emitterPosition;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",172)
		this->emitRate = (  (((data->emitRate == (int)0))) ? int(::Std_obj::_int((double(this->maxParticles) / double(this->lifespan)))) : int(data->emitRate) );
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",174)
		this->startRadius = data->startRadius;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",175)
		this->startRadiusVariance = data->startRadiusVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",176)
		this->endRadius = data->endRadius;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",177)
		this->endRadiusVariance = data->endRadiusVariance;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",178)
		this->rotatePerSecond = data->rotatePerSecond;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",179)
		this->rotatePerSecondVariance = data->rotatePerSecondVariance;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,initWitdRadialData,(void))

Void ParticleSystem_obj::runSystem( ){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::runSystem")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",182)
		if ((!(this->active))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",184)
			this->startTime = this->updateTime = ::nme::Lib_obj::getTimer();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",185)
			::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->update_dyn(),null(),null(),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",186)
			this->active = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleSystem_obj,runSystem,(void))

Void ParticleSystem_obj::stopSystem( ){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::stopSystem")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",190)
		if ((this->active)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",192)
			this->startTime = this->updateTime = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",193)
			::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->update_dyn(),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",194)
			this->canvas->nmeGetGraphics()->clear();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",195)
			this->active = false;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",196)
			this->elapsed = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",197)
			while(((this->particles->length > (int)0))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",197)
				this->particles->pop();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleSystem_obj,stopSystem,(void))

Void ParticleSystem_obj::setSpeed( double speed,double variance){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::setSpeed")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",203)
		if (((this->emitterMode == ::com::mybo::framework::particle::EmitterMode_obj::gravityMode_dyn()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",205)
			this->speed = speed;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",206)
			this->speedVariance = variance;
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",207)
			::haxe::Log_obj::trace(HX_CSTRING("EmitterMode.radialMode can't set Speed!"),hx::SourceInfo(HX_CSTRING("ParticleSystem.hx"),208,HX_CSTRING("com.mybo.framework.particle.ParticleSystem"),HX_CSTRING("setSpeed")));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ParticleSystem_obj,setSpeed,(void))

Void ParticleSystem_obj::setTextureBitmapData( ::nme::display::BitmapData bd){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::setTextureBitmapData")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",215)
		this->textureBitmapData = bd;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,setTextureBitmapData,(void))

Void ParticleSystem_obj::setEmitterMode( ::com::mybo::framework::particle::EmitterMode mode){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::setEmitterMode")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",218)
		this->emitterMode = mode;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,setEmitterMode,(void))

bool ParticleSystem_obj::shouldGenerateParticle( ){
	HX_SOURCE_PUSH("ParticleSystem_obj::shouldGenerateParticle")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",224)
	this->elapsed = (double(((::nme::Lib_obj::getTimer() - this->startTime))) / double((int)1000));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",225)
	return (bool((this->particles->length < this->maxParticles)) && bool(((bool((this->duration == (int)-1)) || bool((this->elapsed < this->duration))))));
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleSystem_obj,shouldGenerateParticle,return )

Void ParticleSystem_obj::generateParticle( double dt){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::generateParticle")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",231)
		hx::AddEq(this->particeNeedGenerate,(dt * this->emitRate));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",232)
		int emitCounter = (int)0;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",233)
		while(((bool((bool((this->particeNeedGenerate > (int)1)) && bool((emitCounter < this->particeNeedGenerate)))) && bool((this->particles->length < this->maxParticles))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",234)
			this->initParticle();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",235)
			(emitCounter)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",236)
			(this->particeNeedGenerate)--;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,generateParticle,(void))

Void ParticleSystem_obj::initParticle( ){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::initParticle")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",241)
		if (((this->deadParticles->length > (int)0))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",241)
			this->particle = this->deadParticles->pop();
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",243)
			this->particle = ::com::mybo::framework::particle::Particle_obj::__new();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",247)
		this->particle->lifeSpan = ::Math_obj::max((int)0,(this->lifespan + (this->lifespanVariance * this->random())));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",249)
		this->particle->pos->x = (this->emitterPosition->x + (this->emitterPosVariance->x * this->random()));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",250)
		this->particle->pos->y = (this->emitterPosition->y + (this->emitterPosVariance->y * this->random()));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",252)
		this->particle->color->r = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->startColor->r + (this->startColorVariance->r * this->random()))));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",253)
		this->particle->color->g = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->startColor->g + (this->startColorVariance->g * this->random()))));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",254)
		this->particle->color->b = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->startColor->b + (this->startColorVariance->b * this->random()))));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",255)
		this->particle->color->a = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->startColor->a + (this->startColorVariance->a * this->random()))));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",256)
		if ((!(this->keepColor))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",257)
			double r;
			double g;
			double b;
			double a;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",258)
			r = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->endColor->r + (this->endColorVariance->r * this->random()))));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",259)
			g = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->endColor->g + (this->endColorVariance->g * this->random()))));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",260)
			b = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->endColor->b + (this->endColorVariance->b * this->random()))));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",261)
			a = ::Math_obj::min((int)1,::Math_obj::max((int)0,(this->endColor->a + (this->endColorVariance->a * this->random()))));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",263)
			this->particle->deltaColor->r = (double(((r - this->particle->color->r))) / double(this->particle->lifeSpan));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",264)
			this->particle->deltaColor->g = (double(((g - this->particle->color->g))) / double(this->particle->lifeSpan));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",265)
			this->particle->deltaColor->b = (double(((b - this->particle->color->b))) / double(this->particle->lifeSpan));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",266)
			this->particle->deltaColor->a = (double(((a - this->particle->color->a))) / double(this->particle->lifeSpan));
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",269)
		this->particle->size = ::Math_obj::max((int)0,(this->startSize + (this->startSizeVariance * this->random())));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",270)
		if ((!(this->keepSize))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",271)
			double finishSize = ::Math_obj::max((int)0,(this->endSize + (this->endSizeVariance * this->random())));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",272)
			this->particle->deltaSize = (double(((finishSize - this->particle->size))) / double(this->particle->lifeSpan));
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",275)
		this->particle->rotation = (this->startRotation + (this->startRotationVariance * this->random()));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",276)
		if ((!(this->keepRotationAngle))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",277)
			double endR = (this->endRotation + (this->endRotationVariance * this->random()));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",278)
			this->particle->deltaRotation = (double(((endR - this->particle->rotation))) / double(this->particle->lifeSpan));
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",281)
		double direction = (double((::Math_obj::PI * ((this->emitterAngle + (this->emitterAngleVariance * this->random()))))) / double((int)180));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",282)
		if (((this->emitterMode == ::com::mybo::framework::particle::EmitterMode_obj::gravityMode_dyn()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",283)
			double s = (this->speed + (this->speedVariance * this->random()));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",285)
			this->particle->setSpeedX((s * ::Math_obj::cos(direction)));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",286)
			this->particle->setSpeedY((-(s) * ::Math_obj::sin(direction)));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",287)
			this->particle->setRadialAccel((this->radialAcceleration + (this->radialAccelVariance * this->random())));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",288)
			this->particle->setTangentialAccel((this->tangentialAcceleration + (this->tangentialAccelVariance * this->random())));
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",290)
			double startRadius = (this->startRadius + (this->startRadiusVariance * this->random()));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",291)
			double endRadius = (this->endRadius + (this->endRadiusVariance * this->random()));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",293)
			this->particle->setRadius(startRadius);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",294)
			this->particle->setDeltaRadius((double(((endRadius - startRadius))) / double(this->particle->lifeSpan)));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",296)
			this->particle->setAngle(direction);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",297)
			this->particle->setAnglePerSecond((double((::Math_obj::PI * ((this->rotatePerSecond + (this->rotatePerSecondVariance * this->random()))))) / double((int)180)));
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",300)
		this->particles->push(this->particle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleSystem_obj,initParticle,(void))

Void ParticleSystem_obj::update( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::update")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",312)
		this->index = (int)0;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",313)
		if (((null() == this->unit))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",313)
			this->unit = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",314)
		if (((null() == this->radialSpeed))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",314)
			this->radialSpeed = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",315)
		if (((null() == this->tangentialSpeed))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",315)
			this->tangentialSpeed = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",316)
		if (((null() == this->temp))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",316)
			this->temp = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)0);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",318)
		this->dt = (double((int)1) / double((int)60));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",321)
		if ((this->shouldGenerateParticle())){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",321)
			this->generateParticle(this->dt);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",324)
		int length = this->particles->length;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",325)
		while(((this->index < length))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",326)
			this->aParticle = this->particles->__get(this->index);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",327)
			hx::SubEq(this->aParticle->lifeSpan,this->dt);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",328)
			if (((this->aParticle->lifeSpan > (int)0))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",329)
				if (((this->emitterMode == ::com::mybo::framework::particle::EmitterMode_obj::gravityMode_dyn()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",330)
					if (((bool(((this->aParticle->pos->x - this->emitterPosition->x) != (int)0)) || bool(((this->aParticle->pos->x - this->emitterPosition->x) != (int)0))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",332)
						this->unit->x = (this->aParticle->pos->x - this->emitterPosition->x);
						HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",333)
						this->unit->y = (this->aParticle->pos->y - this->emitterPosition->y);
						HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",335)
						this->unit->normalize(1.0);
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",337)
						this->unit->x = ::Math_obj::sin((::Math_obj::random() * (int)360));
						HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",338)
						this->unit->y = (::Math_obj::pow((int)-1,::Std_obj::random((int)2)) * ::Math_obj::sqrt(::Math_obj::abs(((int)1 - ::Math_obj::pow(this->unit->x,2.0)))));
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",342)
					this->radialSpeed->x = this->unit->x;
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",343)
					this->radialSpeed->y = this->unit->y;
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",346)
					hx::MultEq(this->radialSpeed->x,this->aParticle->getRadialAccel());
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",347)
					hx::MultEq(this->radialSpeed->y,this->aParticle->getRadialAccel());
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",350)
					this->tangentialSpeed->x = -(this->unit->y);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",351)
					this->tangentialSpeed->y = this->unit->x;
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",354)
					hx::MultEq(this->tangentialSpeed->x,this->aParticle->getTangentialAccel());
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",355)
					hx::MultEq(this->tangentialSpeed->y,this->aParticle->getTangentialAccel());
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",361)
					this->temp->x = ((this->radialSpeed->x + this->tangentialSpeed->x) + this->gravity->x);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",362)
					this->temp->y = ((this->radialSpeed->y + this->tangentialSpeed->y) + this->gravity->y);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",365)
					hx::MultEq(this->temp->x,this->dt);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",366)
					hx::MultEq(this->temp->y,this->dt);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",370)
					this->aParticle->setSpeedX((this->aParticle->getSpeedX() + this->temp->x));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",371)
					this->aParticle->setSpeedY((this->aParticle->getSpeedY() + this->temp->y));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",374)
					this->temp->x = (this->aParticle->getSpeedX() * this->dt);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",375)
					this->temp->y = (this->aParticle->getSpeedY() * this->dt);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",378)
					hx::AddEq(this->aParticle->pos->x,this->temp->x);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",379)
					hx::AddEq(this->aParticle->pos->y,this->temp->y);
				}
				else{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",382)
					this->aParticle->setAngle((this->aParticle->getAngle() + (this->aParticle->getAnglePerSecond() * this->dt)));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",383)
					this->aParticle->setRadius((this->aParticle->getRadius() + (this->aParticle->getDeltaRadius() * this->dt)));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",385)
					this->aParticle->pos->x = (this->emitterPosition->x - (this->aParticle->getRadius() * ::Math_obj::cos(this->aParticle->getAngle())));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",386)
					this->aParticle->pos->y = (this->emitterPosition->y - (this->aParticle->getRadius() * ::Math_obj::sin(this->aParticle->getAngle())));
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",390)
				if ((!(this->keepColor))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",391)
					hx::AddEq(this->aParticle->color->r,(this->aParticle->deltaColor->r * this->dt));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",392)
					hx::AddEq(this->aParticle->color->g,(this->aParticle->deltaColor->g * this->dt));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",393)
					hx::AddEq(this->aParticle->color->b,(this->aParticle->deltaColor->b * this->dt));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",394)
					hx::AddEq(this->aParticle->color->a,(this->aParticle->deltaColor->a * this->dt));
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",397)
				if ((!(this->keepSize))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",398)
					hx::AddEq(this->aParticle->size,(this->aParticle->deltaSize * this->dt));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",399)
					this->aParticle->size = ::Math_obj::max((int)0,this->aParticle->size);
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",402)
				if ((!(this->keepRotationAngle))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",402)
					hx::AddEq(this->aParticle->rotation,(this->aParticle->deltaRotation * this->dt));
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",403)
				(this->index)++;
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",405)
				this->deadParticles->push(this->particles->__get(this->index));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",406)
				if (((this->index != (length - (int)1)))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",407)
					this->particles[this->index] = this->particles->pop();
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",408)
					(length)--;
				}
				else{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",410)
					this->particles->pop();
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",411)
					(length)--;
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",414)
				if (((bool((length == (int)0)) && bool((this->duration != (int)-1))))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",414)
					this->stopSystem();
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",420)
		this->draw();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,update,(void))

Void ParticleSystem_obj::draw( ){
{
		HX_SOURCE_PUSH("ParticleSystem_obj::draw")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",447)
		this->vertices = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",448)
		this->indices = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",449)
		this->uvdatas = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",450)
		this->colors = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",452)
		this->_i = (int)0;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",453)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",453)
			int _g1 = (int)0;
			int _g = this->particles->length;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",453)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",453)
				int _i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",455)
				this->particle = this->particles->__get(_i);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",456)
				this->size = this->particle->size;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",458)
				this->rotation = ((double((this->particle->rotation * ::Math_obj::PI)) / double((int)180)) - (double(::Math_obj::PI) / double((int)4)));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",460)
				double sin = ::Math_obj::sin(this->rotation);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",461)
				double cos = ::Math_obj::cos(this->rotation);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",464)
				this->vertices->push((((this->particle->pos->x - (((cos * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",465)
				this->vertices->push((((this->particle->pos->y + (((sin * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",467)
				this->vertices->push((((this->particle->pos->x + (((cos * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",468)
				this->vertices->push((((this->particle->pos->y + (((sin * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",470)
				this->vertices->push((((this->particle->pos->x + (((cos * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",471)
				this->vertices->push((((this->particle->pos->y - (((sin * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",473)
				this->vertices->push((((this->particle->pos->x - (((cos * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",474)
				this->vertices->push((((this->particle->pos->y - (((sin * ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)))) * this->size) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",478)
				this->indices->push(((int)4 * _i));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",479)
				this->indices->push((((int)4 * _i) + (int)1));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",480)
				this->indices->push((((int)4 * _i) + (int)2));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",481)
				this->indices->push(((int)4 * _i));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",482)
				this->indices->push((((int)4 * _i) + (int)2));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",483)
				this->indices->push((((int)4 * _i) + (int)3));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",485)
				this->uvdatas->push((int)0);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",486)
				this->uvdatas->push((int)0);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",487)
				this->uvdatas->push((int)1);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",488)
				this->uvdatas->push((int)0);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",489)
				this->uvdatas->push((int)1);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",490)
				this->uvdatas->push((int)1);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",491)
				this->uvdatas->push((int)0);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",492)
				this->uvdatas->push((int)1);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",494)
				if ((!(this->allSameColor))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",495)
					this->abgr = (int((int((int((int(::Std_obj::_int(((int)255 * this->particle->color->a))) << int((int)24))) | int((int(::Std_obj::_int(((int)255 * this->particle->color->b))) << int((int)16))))) | int((int(::Std_obj::_int(((int)255 * this->particle->color->g))) << int((int)8))))) | int(::Std_obj::_int(((int)255 * this->particle->color->r))));
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",499)
					this->colors->push(this->abgr);
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",502)
				if (((bool((this->particles->length > (int)0)) && bool((this->textureBitmapData != null()))))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",503)
					this->canvas->nmeGetGraphics()->clear();
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",504)
					this->canvas->nmeGetGraphics()->beginBitmapFill(this->textureBitmapData,null(),false,true);
					HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",505)
					this->canvas->nmeGetGraphics()->drawTriangles(this->vertices,this->indices,this->uvdatas,::nme::display::TriangleCulling_obj::NONE_dyn(),null(),(  ((this->disableBlendMode)) ? int((int)0) : int((int)9) ),null());
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleSystem_obj,draw,(void))

double ParticleSystem_obj::random( ){
	HX_SOURCE_PUSH("ParticleSystem_obj::random")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",557)
	return (((int)2 * ::Math_obj::random()) - (int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleSystem_obj,random,return )

double ParticleSystem_obj::autoScaleValue( double value){
	HX_SOURCE_PUSH("ParticleSystem_obj::autoScaleValue")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/particle/ParticleSystem.hx",561)
	return (  ((::nmex::Device_obj::isRetina())) ? double(((int)2 * value)) : double(value) );
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleSystem_obj,autoScaleValue,return )

double ParticleSystem_obj::sin45;

double ParticleSystem_obj::scale;


ParticleSystem_obj::ParticleSystem_obj()
{
}

void ParticleSystem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleSystem);
	HX_MARK_MEMBER_NAME(canvas,"canvas");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(particles,"particles");
	HX_MARK_MEMBER_NAME(deadParticles,"deadParticles");
	HX_MARK_MEMBER_NAME(elapsed,"elapsed");
	HX_MARK_MEMBER_NAME(startTime,"startTime");
	HX_MARK_MEMBER_NAME(updateTime,"updateTime");
	HX_MARK_MEMBER_NAME(emitterMode,"emitterMode");
	HX_MARK_MEMBER_NAME(textureBitmapData,"textureBitmapData");
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
	HX_MARK_MEMBER_NAME(emitterPosVariance,"emitterPosVariance");
	HX_MARK_MEMBER_NAME(emitterAngle,"emitterAngle");
	HX_MARK_MEMBER_NAME(emitterAngleVariance,"emitterAngleVariance");
	HX_MARK_MEMBER_NAME(emitRate,"emitRate");
	HX_MARK_MEMBER_NAME(allSameSize,"allSameSize");
	HX_MARK_MEMBER_NAME(allRotationZero,"allRotationZero");
	HX_MARK_MEMBER_NAME(allSameColor,"allSameColor");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(speedVariance,"speedVariance");
	HX_MARK_MEMBER_NAME(gravity,"gravity");
	HX_MARK_MEMBER_NAME(radialAcceleration,"radialAcceleration");
	HX_MARK_MEMBER_NAME(radialAccelVariance,"radialAccelVariance");
	HX_MARK_MEMBER_NAME(tangentialAcceleration,"tangentialAcceleration");
	HX_MARK_MEMBER_NAME(tangentialAccelVariance,"tangentialAccelVariance");
	HX_MARK_MEMBER_NAME(startRadius,"startRadius");
	HX_MARK_MEMBER_NAME(startRadiusVariance,"startRadiusVariance");
	HX_MARK_MEMBER_NAME(endRadius,"endRadius");
	HX_MARK_MEMBER_NAME(endRadiusVariance,"endRadiusVariance");
	HX_MARK_MEMBER_NAME(rotatePerSecond,"rotatePerSecond");
	HX_MARK_MEMBER_NAME(rotatePerSecondVariance,"rotatePerSecondVariance");
	HX_MARK_MEMBER_NAME(disableBlendMode,"disableBlendMode");
	HX_MARK_MEMBER_NAME(particeNeedGenerate,"particeNeedGenerate");
	HX_MARK_MEMBER_NAME(dt,"dt");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_MEMBER_NAME(aParticle,"aParticle");
	HX_MARK_MEMBER_NAME(unit,"unit");
	HX_MARK_MEMBER_NAME(radialSpeed,"radialSpeed");
	HX_MARK_MEMBER_NAME(tangentialSpeed,"tangentialSpeed");
	HX_MARK_MEMBER_NAME(temp,"temp");
	HX_MARK_MEMBER_NAME(_i,"_i");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(vertices,"vertices");
	HX_MARK_MEMBER_NAME(uvdatas,"uvdatas");
	HX_MARK_MEMBER_NAME(indices,"indices");
	HX_MARK_MEMBER_NAME(colors,"colors");
	HX_MARK_MEMBER_NAME(abgr,"abgr");
	HX_MARK_MEMBER_NAME(particle,"particle");
	HX_MARK_END_CLASS();
}

Dynamic ParticleSystem_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dt") ) { return dt; }
		if (HX_FIELD_EQ(inName,"_i") ) { return _i; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"unit") ) { return unit; }
		if (HX_FIELD_EQ(inName,"temp") ) { return temp; }
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		if (HX_FIELD_EQ(inName,"abgr") ) { return abgr; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sin45") ) { return sin45; }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"canvas") ) { return canvas; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"colors") ) { return colors; }
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"elapsed") ) { return elapsed; }
		if (HX_FIELD_EQ(inName,"endSize") ) { return endSize; }
		if (HX_FIELD_EQ(inName,"gravity") ) { return gravity; }
		if (HX_FIELD_EQ(inName,"uvdatas") ) { return uvdatas; }
		if (HX_FIELD_EQ(inName,"indices") ) { return indices; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"keepSize") ) { return keepSize; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"lifespan") ) { return lifespan; }
		if (HX_FIELD_EQ(inName,"endColor") ) { return endColor; }
		if (HX_FIELD_EQ(inName,"emitRate") ) { return emitRate; }
		if (HX_FIELD_EQ(inName,"setSpeed") ) { return setSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		if (HX_FIELD_EQ(inName,"particle") ) { return particle; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"particles") ) { return particles; }
		if (HX_FIELD_EQ(inName,"startTime") ) { return startTime; }
		if (HX_FIELD_EQ(inName,"keepColor") ) { return keepColor; }
		if (HX_FIELD_EQ(inName,"startSize") ) { return startSize; }
		if (HX_FIELD_EQ(inName,"endRadius") ) { return endRadius; }
		if (HX_FIELD_EQ(inName,"runSystem") ) { return runSystem_dyn(); }
		if (HX_FIELD_EQ(inName,"aParticle") ) { return aParticle; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateTime") ) { return updateTime; }
		if (HX_FIELD_EQ(inName,"startColor") ) { return startColor; }
		if (HX_FIELD_EQ(inName,"stopSystem") ) { return stopSystem_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"emitterMode") ) { return emitterMode; }
		if (HX_FIELD_EQ(inName,"endRotation") ) { return endRotation; }
		if (HX_FIELD_EQ(inName,"allSameSize") ) { return allSameSize; }
		if (HX_FIELD_EQ(inName,"startRadius") ) { return startRadius; }
		if (HX_FIELD_EQ(inName,"radialSpeed") ) { return radialSpeed; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"maxParticles") ) { return maxParticles; }
		if (HX_FIELD_EQ(inName,"emitterAngle") ) { return emitterAngle; }
		if (HX_FIELD_EQ(inName,"allSameColor") ) { return allSameColor; }
		if (HX_FIELD_EQ(inName,"initParticle") ) { return initParticle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"deadParticles") ) { return deadParticles; }
		if (HX_FIELD_EQ(inName,"startRotation") ) { return startRotation; }
		if (HX_FIELD_EQ(inName,"speedVariance") ) { return speedVariance; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setEmitterMode") ) { return setEmitterMode_dyn(); }
		if (HX_FIELD_EQ(inName,"autoScaleValue") ) { return autoScaleValue_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"endSizeVariance") ) { return endSizeVariance; }
		if (HX_FIELD_EQ(inName,"emitterPosition") ) { return emitterPosition; }
		if (HX_FIELD_EQ(inName,"allRotationZero") ) { return allRotationZero; }
		if (HX_FIELD_EQ(inName,"rotatePerSecond") ) { return rotatePerSecond; }
		if (HX_FIELD_EQ(inName,"tangentialSpeed") ) { return tangentialSpeed; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lifespanVariance") ) { return lifespanVariance; }
		if (HX_FIELD_EQ(inName,"endColorVariance") ) { return endColorVariance; }
		if (HX_FIELD_EQ(inName,"disableBlendMode") ) { return disableBlendMode; }
		if (HX_FIELD_EQ(inName,"generateParticle") ) { return generateParticle_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"textureBitmapData") ) { return textureBitmapData; }
		if (HX_FIELD_EQ(inName,"keepRotationAngle") ) { return keepRotationAngle; }
		if (HX_FIELD_EQ(inName,"startSizeVariance") ) { return startSizeVariance; }
		if (HX_FIELD_EQ(inName,"endRadiusVariance") ) { return endRadiusVariance; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"startColorVariance") ) { return startColorVariance; }
		if (HX_FIELD_EQ(inName,"emitterPosVariance") ) { return emitterPosVariance; }
		if (HX_FIELD_EQ(inName,"radialAcceleration") ) { return radialAcceleration; }
		if (HX_FIELD_EQ(inName,"initWitdRadialData") ) { return initWitdRadialData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endRotationVariance") ) { return endRotationVariance; }
		if (HX_FIELD_EQ(inName,"radialAccelVariance") ) { return radialAccelVariance; }
		if (HX_FIELD_EQ(inName,"startRadiusVariance") ) { return startRadiusVariance; }
		if (HX_FIELD_EQ(inName,"initWitdGravityData") ) { return initWitdGravityData_dyn(); }
		if (HX_FIELD_EQ(inName,"particeNeedGenerate") ) { return particeNeedGenerate; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"emitterAngleVariance") ) { return emitterAngleVariance; }
		if (HX_FIELD_EQ(inName,"setTextureBitmapData") ) { return setTextureBitmapData_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"startRotationVariance") ) { return startRotationVariance; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"tangentialAcceleration") ) { return tangentialAcceleration; }
		if (HX_FIELD_EQ(inName,"shouldGenerateParticle") ) { return shouldGenerateParticle_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"tangentialAccelVariance") ) { return tangentialAccelVariance; }
		if (HX_FIELD_EQ(inName,"rotatePerSecondVariance") ) { return rotatePerSecondVariance; }
	}
	return super::__Field(inName);
}

Dynamic ParticleSystem_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dt") ) { dt=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_i") ) { _i=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"unit") ) { unit=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"abgr") ) { abgr=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sin45") ) { sin45=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"canvas") ) { canvas=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colors") ) { colors=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"elapsed") ) { elapsed=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endSize") ) { endSize=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gravity") ) { gravity=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"uvdatas") ) { uvdatas=inValue.Cast< Array< double > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indices") ) { indices=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"keepSize") ) { keepSize=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lifespan") ) { lifespan=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endColor") ) { endColor=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitRate") ) { emitRate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vertices") ) { vertices=inValue.Cast< Array< double > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"particle") ) { particle=inValue.Cast< ::com::mybo::framework::particle::Particle >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"particles") ) { particles=inValue.Cast< Array< ::com::mybo::framework::particle::Particle > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startTime") ) { startTime=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keepColor") ) { keepColor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startSize") ) { startSize=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRadius") ) { endRadius=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"aParticle") ) { aParticle=inValue.Cast< ::com::mybo::framework::particle::Particle >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateTime") ) { updateTime=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startColor") ) { startColor=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"emitterMode") ) { emitterMode=inValue.Cast< ::com::mybo::framework::particle::EmitterMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRotation") ) { endRotation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"allSameSize") ) { allSameSize=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startRadius") ) { startRadius=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radialSpeed") ) { radialSpeed=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"maxParticles") ) { maxParticles=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitterAngle") ) { emitterAngle=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"allSameColor") ) { allSameColor=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"deadParticles") ) { deadParticles=inValue.Cast< Array< ::com::mybo::framework::particle::Particle > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startRotation") ) { startRotation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speedVariance") ) { speedVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"endSizeVariance") ) { endSizeVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitterPosition") ) { emitterPosition=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"allRotationZero") ) { allRotationZero=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotatePerSecond") ) { rotatePerSecond=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tangentialSpeed") ) { tangentialSpeed=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lifespanVariance") ) { lifespanVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endColorVariance") ) { endColorVariance=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disableBlendMode") ) { disableBlendMode=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"textureBitmapData") ) { textureBitmapData=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keepRotationAngle") ) { keepRotationAngle=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startSizeVariance") ) { startSizeVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRadiusVariance") ) { endRadiusVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"startColorVariance") ) { startColorVariance=inValue.Cast< ::com::mybo::framework::particle::RGBA >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitterPosVariance") ) { emitterPosVariance=inValue.Cast< ::com::mybo::framework::particle::Vector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radialAcceleration") ) { radialAcceleration=inValue.Cast< double >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endRotationVariance") ) { endRotationVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radialAccelVariance") ) { radialAccelVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startRadiusVariance") ) { startRadiusVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"particeNeedGenerate") ) { particeNeedGenerate=inValue.Cast< double >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"emitterAngleVariance") ) { emitterAngleVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"startRotationVariance") ) { startRotationVariance=inValue.Cast< double >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"tangentialAcceleration") ) { tangentialAcceleration=inValue.Cast< double >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"tangentialAccelVariance") ) { tangentialAccelVariance=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotatePerSecondVariance") ) { rotatePerSecondVariance=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ParticleSystem_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("canvas"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("particles"));
	outFields->push(HX_CSTRING("deadParticles"));
	outFields->push(HX_CSTRING("elapsed"));
	outFields->push(HX_CSTRING("startTime"));
	outFields->push(HX_CSTRING("updateTime"));
	outFields->push(HX_CSTRING("emitterMode"));
	outFields->push(HX_CSTRING("textureBitmapData"));
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
	outFields->push(HX_CSTRING("emitterPosVariance"));
	outFields->push(HX_CSTRING("emitterAngle"));
	outFields->push(HX_CSTRING("emitterAngleVariance"));
	outFields->push(HX_CSTRING("emitRate"));
	outFields->push(HX_CSTRING("allSameSize"));
	outFields->push(HX_CSTRING("allRotationZero"));
	outFields->push(HX_CSTRING("allSameColor"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("speedVariance"));
	outFields->push(HX_CSTRING("gravity"));
	outFields->push(HX_CSTRING("radialAcceleration"));
	outFields->push(HX_CSTRING("radialAccelVariance"));
	outFields->push(HX_CSTRING("tangentialAcceleration"));
	outFields->push(HX_CSTRING("tangentialAccelVariance"));
	outFields->push(HX_CSTRING("startRadius"));
	outFields->push(HX_CSTRING("startRadiusVariance"));
	outFields->push(HX_CSTRING("endRadius"));
	outFields->push(HX_CSTRING("endRadiusVariance"));
	outFields->push(HX_CSTRING("rotatePerSecond"));
	outFields->push(HX_CSTRING("rotatePerSecondVariance"));
	outFields->push(HX_CSTRING("disableBlendMode"));
	outFields->push(HX_CSTRING("particeNeedGenerate"));
	outFields->push(HX_CSTRING("dt"));
	outFields->push(HX_CSTRING("index"));
	outFields->push(HX_CSTRING("aParticle"));
	outFields->push(HX_CSTRING("unit"));
	outFields->push(HX_CSTRING("radialSpeed"));
	outFields->push(HX_CSTRING("tangentialSpeed"));
	outFields->push(HX_CSTRING("temp"));
	outFields->push(HX_CSTRING("_i"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("vertices"));
	outFields->push(HX_CSTRING("uvdatas"));
	outFields->push(HX_CSTRING("indices"));
	outFields->push(HX_CSTRING("colors"));
	outFields->push(HX_CSTRING("abgr"));
	outFields->push(HX_CSTRING("particle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sin45"),
	HX_CSTRING("scale"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("canvas"),
	HX_CSTRING("active"),
	HX_CSTRING("particles"),
	HX_CSTRING("deadParticles"),
	HX_CSTRING("elapsed"),
	HX_CSTRING("startTime"),
	HX_CSTRING("updateTime"),
	HX_CSTRING("emitterMode"),
	HX_CSTRING("textureBitmapData"),
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
	HX_CSTRING("emitterPosVariance"),
	HX_CSTRING("emitterAngle"),
	HX_CSTRING("emitterAngleVariance"),
	HX_CSTRING("emitRate"),
	HX_CSTRING("allSameSize"),
	HX_CSTRING("allRotationZero"),
	HX_CSTRING("allSameColor"),
	HX_CSTRING("speed"),
	HX_CSTRING("speedVariance"),
	HX_CSTRING("gravity"),
	HX_CSTRING("radialAcceleration"),
	HX_CSTRING("radialAccelVariance"),
	HX_CSTRING("tangentialAcceleration"),
	HX_CSTRING("tangentialAccelVariance"),
	HX_CSTRING("startRadius"),
	HX_CSTRING("startRadiusVariance"),
	HX_CSTRING("endRadius"),
	HX_CSTRING("endRadiusVariance"),
	HX_CSTRING("rotatePerSecond"),
	HX_CSTRING("rotatePerSecondVariance"),
	HX_CSTRING("disableBlendMode"),
	HX_CSTRING("initWitdGravityData"),
	HX_CSTRING("initWitdRadialData"),
	HX_CSTRING("runSystem"),
	HX_CSTRING("stopSystem"),
	HX_CSTRING("setSpeed"),
	HX_CSTRING("setTextureBitmapData"),
	HX_CSTRING("setEmitterMode"),
	HX_CSTRING("shouldGenerateParticle"),
	HX_CSTRING("particeNeedGenerate"),
	HX_CSTRING("generateParticle"),
	HX_CSTRING("initParticle"),
	HX_CSTRING("dt"),
	HX_CSTRING("index"),
	HX_CSTRING("aParticle"),
	HX_CSTRING("unit"),
	HX_CSTRING("radialSpeed"),
	HX_CSTRING("tangentialSpeed"),
	HX_CSTRING("temp"),
	HX_CSTRING("update"),
	HX_CSTRING("_i"),
	HX_CSTRING("size"),
	HX_CSTRING("rotation"),
	HX_CSTRING("vertices"),
	HX_CSTRING("uvdatas"),
	HX_CSTRING("indices"),
	HX_CSTRING("colors"),
	HX_CSTRING("abgr"),
	HX_CSTRING("particle"),
	HX_CSTRING("draw"),
	HX_CSTRING("random"),
	HX_CSTRING("autoScaleValue"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleSystem_obj::sin45,"sin45");
	HX_MARK_MEMBER_NAME(ParticleSystem_obj::scale,"scale");
};

Class ParticleSystem_obj::__mClass;

void ParticleSystem_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.particle.ParticleSystem"), hx::TCanCast< ParticleSystem_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ParticleSystem_obj::__boot()
{
	hx::Static(sin45) = ::Math_obj::sin((double(::Math_obj::PI) / double((int)4)));
	hx::Static(scale) = ::com::mybo::framework::core::Facade_obj::contentScaleFactor;
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle
