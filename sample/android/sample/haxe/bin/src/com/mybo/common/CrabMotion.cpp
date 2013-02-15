#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_CrabMotion
#include <com/mybo/common/CrabMotion.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapMovieClip
#include <com/mybo/framework/display/BitmapMovieClip.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Linear
#include <com/mybo/framework/tweener/easing/Linear.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace common{

Void CrabMotion_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",31)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",32)
	this->start();
}
;
	return null();
}

CrabMotion_obj::~CrabMotion_obj() { }

Dynamic CrabMotion_obj::__CreateEmpty() { return  new CrabMotion_obj; }
hx::ObjectPtr< CrabMotion_obj > CrabMotion_obj::__new()
{  hx::ObjectPtr< CrabMotion_obj > result = new CrabMotion_obj();
	result->__construct();
	return result;}

Dynamic CrabMotion_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CrabMotion_obj > result = new CrabMotion_obj();
	result->__construct();
	return result;}

Void CrabMotion_obj::stop( ){
{
		HX_SOURCE_PUSH("CrabMotion_obj::stop")
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",36)
		this->active = false;
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",37)
		if (((null() != this->timer))){
			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",37)
			this->timer->stop();
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",38)
		if (((null() != this->tweener))){
			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",38)
			this->tweener->stop();
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",40)
		this->timer = null();
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",41)
		this->tweener = null();
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",43)
		this->crab->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",44)
		this->removeChild(this->crab);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,stop,(void))

Void CrabMotion_obj::start( ){
{
		HX_SOURCE_PUSH("CrabMotion_obj::start")
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",48)
		if (((bool((null() != this->crab)) && bool(this->contains(this->crab))))){
			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",48)
			this->removeChild(this->crab);
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",51)
		this->crab = ::com::mybo::framework::display::BitmapMovieClip_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getTile(HX_CSTRING("pangxie")),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",52)
		this->crab->isLoop = true;
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",53)
		this->crab->isSlow = true;
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",54)
		this->addChild(this->crab);
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",56)
		this->active = true;
		struct _Function_1_1{
			inline static Dynamic Block( ::com::mybo::common::CrabMotion_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , __this->randomRight(),false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ::com::mybo::common::CrabMotion_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Linear_obj::easeOut_dyn(),false);
				__result->Add(HX_CSTRING("onComplete") , __this->onComplete_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",57)
		this->tweener = ::com::mybo::framework::tweener::MTween_obj::to(this->crab,(double((int)190) / double((int)30)),_Function_1_1::Block(this),_Function_1_2::Block(this));
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",58)
		this->crab->gotoAndPlay((int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,start,(void))

Void CrabMotion_obj::disableSFX( ){
{
		HX_SOURCE_PUSH("CrabMotion_obj::disableSFX")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,disableSFX,(void))

Void CrabMotion_obj::enableSFX( ){
{
		HX_SOURCE_PUSH("CrabMotion_obj::enableSFX")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,enableSFX,(void))

Void CrabMotion_obj::onComplete( ){
{
		HX_SOURCE_PUSH("CrabMotion_obj::onComplete")
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",69)
		Array< ::com::mybo::common::CrabMotion > me = Array_obj< ::com::mybo::common::CrabMotion >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",70)
		if ((this->active)){
			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",71)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("crabSFX"),null(),null());
			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",72)
			this->crab->gotoAndStop((int)18);
			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",74)
			int time = this->randomDelay();

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::com::mybo::common::CrabMotion >,me)
			Void run(){
{
					HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",76)
					me->__get((int)0)->crab->gotoAndPlay((int)0);
					HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",77)
					if (((me->__get((int)0)->crab->nmeGetX() >= (int)130))){
						struct _Function_4_1{
							inline static Dynamic Block( Array< ::com::mybo::common::CrabMotion > &me){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("x") , me->__get((int)0)->randomLeft(),false);
								return __result;
							}
						};
						struct _Function_4_2{
							inline static Dynamic Block( Array< ::com::mybo::common::CrabMotion > &me){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Linear_obj::easeOut_dyn(),false);
								__result->Add(HX_CSTRING("onComplete") , me->__get((int)0)->onComplete_dyn(),false);
								return __result;
							}
						};
						HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",77)
						me->__get((int)0)->tweener = ::com::mybo::framework::tweener::MTween_obj::to(me->__get((int)0)->crab,(double((int)190) / double((int)30)),_Function_4_1::Block(me),_Function_4_2::Block(me));
					}
					else{
						struct _Function_4_1{
							inline static Dynamic Block( Array< ::com::mybo::common::CrabMotion > &me){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("x") , me->__get((int)0)->randomRight(),false);
								return __result;
							}
						};
						struct _Function_4_2{
							inline static Dynamic Block( Array< ::com::mybo::common::CrabMotion > &me){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Linear_obj::easeOut_dyn(),false);
								__result->Add(HX_CSTRING("onComplete") , me->__get((int)0)->onComplete_dyn(),false);
								return __result;
							}
						};
						HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",79)
						me->__get((int)0)->tweener = ::com::mybo::framework::tweener::MTween_obj::to(me->__get((int)0)->crab,(double((int)190) / double((int)30)),_Function_4_1::Block(me),_Function_4_2::Block(me));
					}
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",75)
			this->timer = ::haxe::Timer_obj::delay( Dynamic(new _Function_2_1(me)),time);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,onComplete,(void))

int CrabMotion_obj::randomDelay( ){
	HX_SOURCE_PUSH("CrabMotion_obj::randomDelay")
	HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",86)
	return (::Std_obj::random((int)3000) + (int)2000);
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,randomDelay,return )

double CrabMotion_obj::randomLeft( ){
	HX_SOURCE_PUSH("CrabMotion_obj::randomLeft")
	HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",90)
	return (::Math_obj::random() * (int)100);
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,randomLeft,return )

double CrabMotion_obj::randomRight( ){
	HX_SOURCE_PUSH("CrabMotion_obj::randomRight")
	HX_SOURCE_POS("../../../src/com/mybo/common/CrabMotion.hx",94)
	return ((int)250 - (::Math_obj::random() * (int)100));
}


HX_DEFINE_DYNAMIC_FUNC0(CrabMotion_obj,randomRight,return )

double CrabMotion_obj::RIGHT_EDGE;

double CrabMotion_obj::LEFT_EDGE;

double CrabMotion_obj::MID_EDGE;

double CrabMotion_obj::EDGE_OFFSET;

double CrabMotion_obj::TWEEN_TIME;


CrabMotion_obj::CrabMotion_obj()
{
}

void CrabMotion_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CrabMotion);
	HX_MARK_MEMBER_NAME(crab,"crab");
	HX_MARK_MEMBER_NAME(tweener,"tweener");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(active,"active");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic CrabMotion_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"crab") ) { return crab; }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tweener") ) { return tweener; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MID_EDGE") ) { return MID_EDGE; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"LEFT_EDGE") ) { return LEFT_EDGE; }
		if (HX_FIELD_EQ(inName,"enableSFX") ) { return enableSFX_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"RIGHT_EDGE") ) { return RIGHT_EDGE; }
		if (HX_FIELD_EQ(inName,"TWEEN_TIME") ) { return TWEEN_TIME; }
		if (HX_FIELD_EQ(inName,"disableSFX") ) { return disableSFX_dyn(); }
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"randomLeft") ) { return randomLeft_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"EDGE_OFFSET") ) { return EDGE_OFFSET; }
		if (HX_FIELD_EQ(inName,"randomDelay") ) { return randomDelay_dyn(); }
		if (HX_FIELD_EQ(inName,"randomRight") ) { return randomRight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic CrabMotion_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"crab") ) { crab=inValue.Cast< ::com::mybo::framework::display::BitmapMovieClip >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tweener") ) { tweener=inValue.Cast< ::com::mybo::framework::tweener::MTween >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MID_EDGE") ) { MID_EDGE=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"LEFT_EDGE") ) { LEFT_EDGE=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"RIGHT_EDGE") ) { RIGHT_EDGE=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TWEEN_TIME") ) { TWEEN_TIME=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"EDGE_OFFSET") ) { EDGE_OFFSET=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void CrabMotion_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("crab"));
	outFields->push(HX_CSTRING("tweener"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("active"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("RIGHT_EDGE"),
	HX_CSTRING("LEFT_EDGE"),
	HX_CSTRING("MID_EDGE"),
	HX_CSTRING("EDGE_OFFSET"),
	HX_CSTRING("TWEEN_TIME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("crab"),
	HX_CSTRING("tweener"),
	HX_CSTRING("timer"),
	HX_CSTRING("active"),
	HX_CSTRING("stop"),
	HX_CSTRING("start"),
	HX_CSTRING("disableSFX"),
	HX_CSTRING("enableSFX"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("randomDelay"),
	HX_CSTRING("randomLeft"),
	HX_CSTRING("randomRight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CrabMotion_obj::RIGHT_EDGE,"RIGHT_EDGE");
	HX_MARK_MEMBER_NAME(CrabMotion_obj::LEFT_EDGE,"LEFT_EDGE");
	HX_MARK_MEMBER_NAME(CrabMotion_obj::MID_EDGE,"MID_EDGE");
	HX_MARK_MEMBER_NAME(CrabMotion_obj::EDGE_OFFSET,"EDGE_OFFSET");
	HX_MARK_MEMBER_NAME(CrabMotion_obj::TWEEN_TIME,"TWEEN_TIME");
};

Class CrabMotion_obj::__mClass;

void CrabMotion_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.CrabMotion"), hx::TCanCast< CrabMotion_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CrabMotion_obj::__boot()
{
	hx::Static(RIGHT_EDGE) = (int)250;
	hx::Static(LEFT_EDGE) = (int)0;
	hx::Static(MID_EDGE) = (int)130;
	hx::Static(EDGE_OFFSET) = (int)100;
	hx::Static(TWEEN_TIME) = (double((int)190) / double((int)30));
}

} // end namespace com
} // end namespace mybo
} // end namespace common
