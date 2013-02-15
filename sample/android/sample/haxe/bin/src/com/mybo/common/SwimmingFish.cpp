#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_SwimmingFish
#include <com/mybo/common/SwimmingFish.h>
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
#ifndef INCLUDED_com_mybo_framework_particle_Vector
#include <com/mybo/framework/particle/Vector.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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
namespace common{

Void SwimmingFish_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",33)
	Array< ::com::mybo::common::SwimmingFish > me = Array_obj< ::com::mybo::common::SwimmingFish >::__new().Add(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",34)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",36)
	this->smallFishLeft = ::com::mybo::framework::particle::ParticleSystem_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",37)
	this->smallFishLeft->setTextureBitmapData(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("fish1"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",38)
	this->smallFishLeft->initWitdGravityData(this->initSmallLeftFishParticle());
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",39)
	this->addChild(this->smallFishLeft->canvas);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",40)
	this->smallFishLeft->canvas->nmeSetAlpha(0.5);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",42)
	this->smallFishRight = ::com::mybo::framework::particle::ParticleSystem_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",43)
	this->smallFishRight->setTextureBitmapData(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("fish2"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",44)
	this->smallFishRight->initWitdGravityData(this->initSmallRightFishParticle());
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",45)
	this->smallFishRight->canvas->nmeSetAlpha(0.3);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",46)
	this->addChild(this->smallFishRight->canvas);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",47)
	this->smallFishRight->runSystem();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",49)
	this->bigFishLeft = ::com::mybo::framework::particle::ParticleSystem_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",50)
	this->bigFishLeft->setTextureBitmapData(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("fish3"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",51)
	this->bigFishLeft->initWitdGravityData(this->initBigLeftFishParticle());
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",52)
	this->addChild(this->bigFishLeft->canvas);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",53)
	this->bigFishLeft->disableBlendMode = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",54)
	this->bigFishLeft->runSystem();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",57)
	this->bigFishRight = ::com::mybo::framework::particle::ParticleSystem_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",58)
	this->bigFishRight->setTextureBitmapData(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("fish4"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",59)
	this->bigFishRight->initWitdGravityData(this->initBigRightFishParticle());
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",60)
	this->bigFishRight->disableBlendMode = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",61)
	this->addChild(this->bigFishRight->canvas);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::common::SwimmingFish >,me)
	Void run(){
{
			HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",64)
			me->__get((int)0)->smallFishLeft->runSystem();
			HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",65)
			me->__get((int)0)->bigFishRight->runSystem();
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",63)
	this->delayTimer = ::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(me)),(int)15000);
}
;
	return null();
}

SwimmingFish_obj::~SwimmingFish_obj() { }

Dynamic SwimmingFish_obj::__CreateEmpty() { return  new SwimmingFish_obj; }
hx::ObjectPtr< SwimmingFish_obj > SwimmingFish_obj::__new()
{  hx::ObjectPtr< SwimmingFish_obj > result = new SwimmingFish_obj();
	result->__construct();
	return result;}

Dynamic SwimmingFish_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SwimmingFish_obj > result = new SwimmingFish_obj();
	result->__construct();
	return result;}

::com::mybo::framework::particle::GravityModeData SwimmingFish_obj::initSmallLeftFishParticle( ){
	HX_SOURCE_PUSH("SwimmingFish_obj::initSmallLeftFishParticle")
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",71)
	::com::mybo::framework::particle::GravityModeData data = ::com::mybo::framework::particle::GravityModeData_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",73)
	data->maxParticles = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",74)
	data->duration = (int)-1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",75)
	data->lifespan = (int)20;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",76)
	data->lifespanVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",77)
	data->startSize = (int)15;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",78)
	data->startSizeVariance = (int)8;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",79)
	data->keepSize = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",80)
	data->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new((int)-20,(int)100);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",81)
	data->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)40);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",82)
	data->emitterAngle = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",83)
	data->emitRate = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",86)
	data->speed = (int)40;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",87)
	data->speedVariance = (int)10;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",89)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(SwimmingFish_obj,initSmallLeftFishParticle,return )

::com::mybo::framework::particle::GravityModeData SwimmingFish_obj::initSmallRightFishParticle( ){
	HX_SOURCE_PUSH("SwimmingFish_obj::initSmallRightFishParticle")
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",93)
	::com::mybo::framework::particle::GravityModeData data = ::com::mybo::framework::particle::GravityModeData_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",95)
	data->maxParticles = (int)2;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",96)
	data->duration = (int)-1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",97)
	data->lifespan = (int)20;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",98)
	data->lifespanVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",99)
	data->startSize = (int)15;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",100)
	data->startSizeVariance = (int)8;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",101)
	data->keepSize = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",102)
	data->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new((int)420,(int)230);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",103)
	data->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new((int)100,(int)60);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",104)
	data->emitterAngle = (int)180;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",105)
	data->emitRate = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",108)
	data->speed = (int)40;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",109)
	data->speedVariance = (int)20;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",111)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(SwimmingFish_obj,initSmallRightFishParticle,return )

::com::mybo::framework::particle::GravityModeData SwimmingFish_obj::initBigLeftFishParticle( ){
	HX_SOURCE_PUSH("SwimmingFish_obj::initBigLeftFishParticle")
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",116)
	::com::mybo::framework::particle::GravityModeData data = ::com::mybo::framework::particle::GravityModeData_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",118)
	data->maxParticles = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",119)
	data->duration = (int)-1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",120)
	data->lifespan = (int)25;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",121)
	data->lifespanVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",122)
	data->startSize = (int)35;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",123)
	data->startSizeVariance = (int)5;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",124)
	data->keepSize = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",125)
	data->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new((int)-30,(int)370);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",126)
	data->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)20);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",127)
	data->emitterAngle = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",128)
	data->emitRate = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",131)
	data->speed = (int)30;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",132)
	data->speedVariance = (int)10;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",134)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(SwimmingFish_obj,initBigLeftFishParticle,return )

::com::mybo::framework::particle::GravityModeData SwimmingFish_obj::initBigRightFishParticle( ){
	HX_SOURCE_PUSH("SwimmingFish_obj::initBigRightFishParticle")
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",138)
	::com::mybo::framework::particle::GravityModeData data = ::com::mybo::framework::particle::GravityModeData_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",140)
	data->maxParticles = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",141)
	data->duration = (int)-1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",142)
	data->lifespan = (int)25;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",143)
	data->lifespanVariance = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",144)
	data->startSize = (int)30;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",145)
	data->startSizeVariance = (int)5;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",146)
	data->keepSize = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",147)
	data->emitterPosition = ::com::mybo::framework::particle::Vector_obj::__new((int)350,(int)400);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",148)
	data->emitterPosVariance = ::com::mybo::framework::particle::Vector_obj::__new((int)0,(int)10);
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",149)
	data->emitterAngle = (int)180;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",150)
	data->emitRate = (int)1;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",153)
	data->speed = (int)30;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",154)
	data->speedVariance = (int)10;
	HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",156)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(SwimmingFish_obj,initBigRightFishParticle,return )

Void SwimmingFish_obj::stop( ){
{
		HX_SOURCE_PUSH("SwimmingFish_obj::stop")
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",160)
		this->smallFishRight->stopSystem();
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",161)
		this->bigFishLeft->stopSystem();
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",162)
		this->smallFishLeft->stopSystem();
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",163)
		this->bigFishRight->stopSystem();
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",165)
		this->delayTimer->stop();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SwimmingFish_obj,stop,(void))

Void SwimmingFish_obj::start( ){
{
		HX_SOURCE_PUSH("SwimmingFish_obj::start")
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",168)
		Array< ::com::mybo::common::SwimmingFish > me = Array_obj< ::com::mybo::common::SwimmingFish >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",169)
		this->smallFishRight->runSystem();
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",170)
		this->bigFishLeft->runSystem();
		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",172)
		if (((null() != this->delayTimer))){
			HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",172)
			this->delayTimer->stop();
		}

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::common::SwimmingFish >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",175)
				me->__get((int)0)->smallFishLeft->runSystem();
				HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",176)
				me->__get((int)0)->bigFishRight->runSystem();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/common/SwimmingFish.hx",174)
		this->delayTimer = ::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(me)),(int)15000);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SwimmingFish_obj,start,(void))


SwimmingFish_obj::SwimmingFish_obj()
{
}

void SwimmingFish_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SwimmingFish);
	HX_MARK_MEMBER_NAME(smallFishLeft,"smallFishLeft");
	HX_MARK_MEMBER_NAME(smallFishRight,"smallFishRight");
	HX_MARK_MEMBER_NAME(bigFishLeft,"bigFishLeft");
	HX_MARK_MEMBER_NAME(bigFishRight,"bigFishRight");
	HX_MARK_MEMBER_NAME(delayTimer,"delayTimer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic SwimmingFish_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"delayTimer") ) { return delayTimer; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bigFishLeft") ) { return bigFishLeft; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bigFishRight") ) { return bigFishRight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"smallFishLeft") ) { return smallFishLeft; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"smallFishRight") ) { return smallFishRight; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"initBigLeftFishParticle") ) { return initBigLeftFishParticle_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"initBigRightFishParticle") ) { return initBigRightFishParticle_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"initSmallLeftFishParticle") ) { return initSmallLeftFishParticle_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"initSmallRightFishParticle") ) { return initSmallRightFishParticle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic SwimmingFish_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"delayTimer") ) { delayTimer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bigFishLeft") ) { bigFishLeft=inValue.Cast< ::com::mybo::framework::particle::ParticleSystem >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bigFishRight") ) { bigFishRight=inValue.Cast< ::com::mybo::framework::particle::ParticleSystem >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"smallFishLeft") ) { smallFishLeft=inValue.Cast< ::com::mybo::framework::particle::ParticleSystem >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"smallFishRight") ) { smallFishRight=inValue.Cast< ::com::mybo::framework::particle::ParticleSystem >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SwimmingFish_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("smallFishLeft"));
	outFields->push(HX_CSTRING("smallFishRight"));
	outFields->push(HX_CSTRING("bigFishLeft"));
	outFields->push(HX_CSTRING("bigFishRight"));
	outFields->push(HX_CSTRING("delayTimer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("smallFishLeft"),
	HX_CSTRING("smallFishRight"),
	HX_CSTRING("bigFishLeft"),
	HX_CSTRING("bigFishRight"),
	HX_CSTRING("delayTimer"),
	HX_CSTRING("initSmallLeftFishParticle"),
	HX_CSTRING("initSmallRightFishParticle"),
	HX_CSTRING("initBigLeftFishParticle"),
	HX_CSTRING("initBigRightFishParticle"),
	HX_CSTRING("stop"),
	HX_CSTRING("start"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class SwimmingFish_obj::__mClass;

void SwimmingFish_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.SwimmingFish"), hx::TCanCast< SwimmingFish_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SwimmingFish_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace common
