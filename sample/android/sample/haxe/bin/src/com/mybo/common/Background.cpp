#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
#endif
#ifndef INCLUDED_com_mybo_common_CrabMotion
#include <com/mybo/common/CrabMotion.h>
#endif
#ifndef INCLUDED_com_mybo_common_SwimmingFish
#include <com/mybo/common/SwimmingFish.h>
#endif
#ifndef INCLUDED_com_mybo_effects_BubblesEffect
#include <com/mybo/effects/BubblesEffect.h>
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
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
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

Void Background_obj::__construct(Dynamic __o_isInGame,Dynamic __o_isMasterMenu,Dynamic __o_isInHelp)
{
bool isInGame = __o_isInGame.Default(false);
bool isMasterMenu = __o_isMasterMenu.Default(false);
bool isInHelp = __o_isInHelp.Default(false);
{
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",29)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",31)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",33)
	::nmex::display::Bitmap background;
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",34)
	if ((isMasterMenu)){
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",34)
		background = facade->getBitmap(HX_CSTRING("bg"),null());
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",36)
		if (((bool(isInGame) || bool(isInHelp)))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",36)
			background = facade->getBitmap(HX_CSTRING("ingame_bg"),null());
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",38)
			background = facade->getBitmap(HX_CSTRING("index_bg1"),null());
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",41)
	background->nmeSetHeight(facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",42)
	this->addChild(background);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",44)
	this->effectLayer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",45)
	this->effectLayer->nmeSetMouseEnabled(false);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",46)
	this->addChild(this->effectLayer);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",49)
	this->fishes = ::com::mybo::common::SwimmingFish_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",50)
	if ((isInGame)){
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",50)
		this->fishes->nmeSetAlpha(0.7);
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",53)
	this->addChild(this->fishes);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",55)
	if ((::nmex::Device_obj::isRetina())){
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",55)
		if ((isInGame)){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",57)
			this->bubbles1 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)45,(int)414,(int)1,(int)20,0.35,(int)2500,0.5,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",58)
			this->bubbles2 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)295,(int)403,(int)1,(int)20,0.30,(int)6000,0.3,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",59)
			this->bubbles3 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)140,(int)460,(int)1,(int)20,0.06,(int)3500,0.75,(int)1);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",61)
			this->bubbles1 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)45,(int)414,(int)1,(int)40,0.35,(int)2500,0.5,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",62)
			this->bubbles2 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)295,(int)403,(int)1,(int)40,0.30,(int)6000,0.3,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",63)
			this->bubbles3 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)140,(int)460,(int)1,(int)40,0.06,(int)3500,0.75,(int)1);
		}
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",65)
		if ((isInGame)){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",67)
			this->bubbles1 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)45,(int)414,(int)1,(int)20,0.15,(int)2500,0.5,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",68)
			this->bubbles2 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)295,(int)403,(int)1,(int)20,0.10,(int)6000,0.3,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",69)
			this->bubbles3 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)140,(int)460,(int)1,(int)20,0.02,(int)3500,0.75,(int)1);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",71)
			this->bubbles1 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)45,(int)414,(int)1,(int)40,0.15,(int)2500,0.5,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",72)
			this->bubbles2 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)295,(int)403,(int)1,(int)40,0.10,(int)6000,0.3,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",73)
			this->bubbles3 = ::com::mybo::effects::BubblesEffect_obj::__new(this->effectLayer,(int)140,(int)460,(int)1,(int)40,0.02,(int)3500,0.75,(int)1);
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",77)
	if ((isInGame)){
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",78)
		this->bubbles1->nmeSetAlpha(0.30);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",79)
		this->bubbles2->nmeSetAlpha(0.40);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",80)
		this->bubbles3->nmeSetAlpha(0.20);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",82)
		this->bubbles1->nmeSetAlpha(0.6);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",83)
		this->bubbles2->nmeSetAlpha(0.7);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",84)
		this->bubbles3->nmeSetAlpha(0.5);
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",87)
	if ((!(isMasterMenu))){
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",88)
		::nme::display::Sprite front = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",89)
		front->addChild(facade->getBitmap((  ((isInGame)) ? ::String(HX_CSTRING("ingame_bg_front")) : ::String(HX_CSTRING("index_bg2")) ),null()));
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",90)
		front->nmeSetMouseEnabled(false);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",91)
		front->nmeSetX((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",92)
		front->nmeSetY((facade->getStageHeightInPoint() - front->nmeGetHeight()));
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",93)
		this->addChild(front);
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",95)
		this->crab = ::com::mybo::common::CrabMotion_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",96)
		if ((isInGame)){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",96)
			this->crab->nmeSetY(((facade->getStageHeightInPoint() - this->crab->nmeGetHeight()) - (int)18));
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",98)
			this->crab->nmeSetY((facade->getStageHeightInPoint() - this->crab->nmeGetHeight()));
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",101)
		this->addChild(this->crab);
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",104)
	this->extraLayer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",105)
	this->addChild(this->extraLayer);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",107)
	this->grassLeft = ::com::mybo::framework::display::BitmapMovieClip_obj::__new(facade->getTile(HX_CSTRING("grass_left")),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",108)
	this->grassLeft->nmeSetX((int)-2);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",109)
	this->grassLeft->nmeSetY(((facade->getStageHeightInPoint() - this->grassLeft->nmeGetHeight()) + (int)2));
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",110)
	this->grassLeft->isLoop = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",111)
	this->grassLeft->isSlow = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",113)
	this->grassRight = ::com::mybo::framework::display::BitmapMovieClip_obj::__new(facade->getTile(HX_CSTRING("grass_right")),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",114)
	this->grassRight->nmeSetX(((facade->getStageWidthInPoint() - this->grassRight->nmeGetWidth()) + (int)2));
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",115)
	this->grassRight->nmeSetY(((facade->getStageHeightInPoint() - this->grassRight->nmeGetHeight()) + (int)2));
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",116)
	this->grassRight->isLoop = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",117)
	this->grassRight->isSlow = true;
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",119)
	this->addChild(this->grassLeft);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",120)
	this->addChild(this->grassRight);
	HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",122)
	this->active = true;
}
;
	return null();
}

Background_obj::~Background_obj() { }

Dynamic Background_obj::__CreateEmpty() { return  new Background_obj; }
hx::ObjectPtr< Background_obj > Background_obj::__new(Dynamic __o_isInGame,Dynamic __o_isMasterMenu,Dynamic __o_isInHelp)
{  hx::ObjectPtr< Background_obj > result = new Background_obj();
	result->__construct(__o_isInGame,__o_isMasterMenu,__o_isInHelp);
	return result;}

Dynamic Background_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Background_obj > result = new Background_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Background_obj::addToBackground( ::nmex::display::DisplayObject child){
{
		HX_SOURCE_PUSH("Background_obj::addToBackground")
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",125)
		this->extraLayer->addChild(child);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Background_obj,addToBackground,(void))

Void Background_obj::removeFromBackground( ::nmex::display::DisplayObject child){
{
		HX_SOURCE_PUSH("Background_obj::removeFromBackground")
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",129)
		if ((this->extraLayer->contains(child))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",130)
			this->extraLayer->removeChild(child);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Background_obj,removeFromBackground,(void))

Void Background_obj::stopAnimation( ){
{
		HX_SOURCE_PUSH("Background_obj::stopAnimation")
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",135)
		if ((this->active)){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",137)
			this->bubbles1->stop();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",138)
			this->bubbles2->stop();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",139)
			this->bubbles3->stop();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",141)
			this->fishes->stop();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",143)
			if (((null() != this->crab))){
				HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",143)
				this->crab->stop();
			}
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",147)
			this->active = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Background_obj,stopAnimation,(void))

Void Background_obj::startAnimation( ){
{
		HX_SOURCE_PUSH("Background_obj::startAnimation")
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",151)
		if ((!(this->active))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",153)
			this->bubbles1->start();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",154)
			this->bubbles2->start();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",155)
			this->bubbles3->start();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",157)
			this->fishes->start();
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",159)
			if (((null() != this->crab))){
				HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",159)
				this->crab->start();
			}
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",163)
			this->active = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Background_obj,startAnimation,(void))

Void Background_obj::destroy( ){
{
		HX_SOURCE_PUSH("Background_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",169)
		this->bubbles1->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",170)
		this->bubbles2->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",171)
		this->bubbles3->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",173)
		this->grassLeft->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",174)
		this->grassRight->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",176)
		this->fishes->stop();
		HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",178)
		if (((null() != this->crab))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Background.hx",178)
			this->crab->stop();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Background_obj,destroy,(void))


Background_obj::Background_obj()
{
}

void Background_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Background);
	HX_MARK_MEMBER_NAME(effectLayer,"effectLayer");
	HX_MARK_MEMBER_NAME(extraLayer,"extraLayer");
	HX_MARK_MEMBER_NAME(bubbles1,"bubbles1");
	HX_MARK_MEMBER_NAME(bubbles2,"bubbles2");
	HX_MARK_MEMBER_NAME(bubbles3,"bubbles3");
	HX_MARK_MEMBER_NAME(crab,"crab");
	HX_MARK_MEMBER_NAME(grassLeft,"grassLeft");
	HX_MARK_MEMBER_NAME(grassRight,"grassRight");
	HX_MARK_MEMBER_NAME(fishes,"fishes");
	HX_MARK_MEMBER_NAME(active,"active");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Background_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"crab") ) { return crab; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fishes") ) { return fishes; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"bubbles1") ) { return bubbles1; }
		if (HX_FIELD_EQ(inName,"bubbles2") ) { return bubbles2; }
		if (HX_FIELD_EQ(inName,"bubbles3") ) { return bubbles3; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"grassLeft") ) { return grassLeft; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"extraLayer") ) { return extraLayer; }
		if (HX_FIELD_EQ(inName,"grassRight") ) { return grassRight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"effectLayer") ) { return effectLayer; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"stopAnimation") ) { return stopAnimation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"startAnimation") ) { return startAnimation_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"addToBackground") ) { return addToBackground_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"removeFromBackground") ) { return removeFromBackground_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Background_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"crab") ) { crab=inValue.Cast< ::com::mybo::common::CrabMotion >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fishes") ) { fishes=inValue.Cast< ::com::mybo::common::SwimmingFish >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"bubbles1") ) { bubbles1=inValue.Cast< ::com::mybo::effects::BubblesEffect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bubbles2") ) { bubbles2=inValue.Cast< ::com::mybo::effects::BubblesEffect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bubbles3") ) { bubbles3=inValue.Cast< ::com::mybo::effects::BubblesEffect >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"grassLeft") ) { grassLeft=inValue.Cast< ::com::mybo::framework::display::BitmapMovieClip >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"extraLayer") ) { extraLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"grassRight") ) { grassRight=inValue.Cast< ::com::mybo::framework::display::BitmapMovieClip >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"effectLayer") ) { effectLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Background_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("effectLayer"));
	outFields->push(HX_CSTRING("extraLayer"));
	outFields->push(HX_CSTRING("bubbles1"));
	outFields->push(HX_CSTRING("bubbles2"));
	outFields->push(HX_CSTRING("bubbles3"));
	outFields->push(HX_CSTRING("crab"));
	outFields->push(HX_CSTRING("grassLeft"));
	outFields->push(HX_CSTRING("grassRight"));
	outFields->push(HX_CSTRING("fishes"));
	outFields->push(HX_CSTRING("active"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("effectLayer"),
	HX_CSTRING("extraLayer"),
	HX_CSTRING("bubbles1"),
	HX_CSTRING("bubbles2"),
	HX_CSTRING("bubbles3"),
	HX_CSTRING("crab"),
	HX_CSTRING("grassLeft"),
	HX_CSTRING("grassRight"),
	HX_CSTRING("fishes"),
	HX_CSTRING("active"),
	HX_CSTRING("addToBackground"),
	HX_CSTRING("removeFromBackground"),
	HX_CSTRING("stopAnimation"),
	HX_CSTRING("startAnimation"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Background_obj::__mClass;

void Background_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.Background"), hx::TCanCast< Background_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Background_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace common
