#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapNumber
#include <com/mybo/framework/display/BitmapNumber.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
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
#ifndef INCLUDED_com_mybo_ui_LevelFailedUI
#include <com/mybo/ui/LevelFailedUI.h>
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
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace ui{

Void LevelFailedUI_obj::__construct(int level,Dynamic __o_inMaster)
{
bool inMaster = __o_inMaster.Default(false);
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",28)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",30)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",31)
	double stageWidth = facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",32)
	double stageHeight = facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",34)
	this->background = facade->getBitmap(HX_CSTRING("ui_bg"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",35)
	this->background->nmeSetHeight(facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",36)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",38)
	this->nmeSetAlpha((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("alpha") , (int)1,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",39)
	::com::mybo::framework::tweener::MTween_obj::to(hx::ObjectPtr<OBJ_>(this),0.8,_Function_1_1::Block(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",40)
	::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("levelFailed"),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",43)
	if ((!(inMaster))){
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",44)
		::nmex::display::Bitmap levelLable = facade->getBitmap(HX_CSTRING("ui_level_text"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",45)
		levelLable->nmeSetX(((double(stageWidth) / double((int)2)) - (int)60));
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",46)
		levelLable->nmeSetY((int)55);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",47)
		this->addChild(levelLable);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",49)
		::com::mybo::framework::display::BitmapNumber levelNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(facade->getTile(HX_CSTRING("num10")),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",50)
		levelNum->drawNumber(level);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",51)
		levelNum->nmeSetX(((levelLable->nmeGetX() + levelLable->nmeGetWidth()) + (int)5));
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",52)
		levelNum->nmeSetY(levelLable->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",53)
		this->addChild(levelNum);
	}
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",57)
	this->title = facade->getBitmap(HX_CSTRING("failed_title"),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",58)
	this->title->nmeSetX(((double(facade->getStageWidthInPoint()) / double((int)2)) - (double(this->title->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",59)
	this->title->nmeSetY(facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",60)
	this->addChild(this->title);
	struct _Function_1_2{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , (int)90,false);
			return __result;
		}
	};
	struct _Function_1_3{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.2,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",61)
	::com::mybo::framework::tweener::MTween_obj::to(this->title,(int)1,_Function_1_2::Block(),_Function_1_3::Block());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",65)
	::nmex::display::Bitmap tipBar = facade->getBitmap(HX_CSTRING("tip_bar"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",66)
	tipBar->nmeSetY(stageHeight);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",67)
	this->addChild(tipBar);
	struct _Function_1_4{
		inline static Dynamic Block( double &stageHeight){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , ((double(stageHeight) / double((int)2)) - (int)20),false);
			return __result;
		}
	};
	struct _Function_1_5{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.9,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",69)
	::com::mybo::framework::tweener::MTween_obj::to(tipBar,0.5,_Function_1_4::Block(stageHeight),_Function_1_5::Block());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",71)
	this->menuButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_menu"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",72)
	this->retryButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_retry"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",73)
	this->hitButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap((  ((inMaster)) ? ::String(HX_CSTRING("button_reset")) : ::String(HX_CSTRING("button_hint")) ),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",75)
	this->retryButton->nmeSetX((int)90);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",76)
	this->hitButton->nmeSetX((int)180);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",78)
	this->buttonContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",79)
	this->buttonContainer->addChild(this->menuButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",80)
	this->buttonContainer->addChild(this->retryButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",81)
	this->buttonContainer->addChild(this->hitButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",82)
	this->buttonContainer->nmeSetX(((double(facade->getStageWidthInPoint()) / double((int)2)) - (double(this->buttonContainer->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",83)
	this->buttonContainer->nmeSetY(facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",84)
	this->addChild(this->buttonContainer);
	struct _Function_1_6{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , (int)380,false);
			return __result;
		}
	};
	struct _Function_1_7{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 1.5,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelFailedUI.hx",87)
	::com::mybo::framework::tweener::MTween_obj::to(this->buttonContainer,0.2,_Function_1_6::Block(),_Function_1_7::Block());
}
;
	return null();
}

LevelFailedUI_obj::~LevelFailedUI_obj() { }

Dynamic LevelFailedUI_obj::__CreateEmpty() { return  new LevelFailedUI_obj; }
hx::ObjectPtr< LevelFailedUI_obj > LevelFailedUI_obj::__new(int level,Dynamic __o_inMaster)
{  hx::ObjectPtr< LevelFailedUI_obj > result = new LevelFailedUI_obj();
	result->__construct(level,__o_inMaster);
	return result;}

Dynamic LevelFailedUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LevelFailedUI_obj > result = new LevelFailedUI_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


LevelFailedUI_obj::LevelFailedUI_obj()
{
}

void LevelFailedUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LevelFailedUI);
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(menuButton,"menuButton");
	HX_MARK_MEMBER_NAME(retryButton,"retryButton");
	HX_MARK_MEMBER_NAME(hitButton,"hitButton");
	HX_MARK_MEMBER_NAME(tipContainer,"tipContainer");
	HX_MARK_MEMBER_NAME(buttonContainer,"buttonContainer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic LevelFailedUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hitButton") ) { return hitButton; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		if (HX_FIELD_EQ(inName,"menuButton") ) { return menuButton; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { return retryButton; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"tipContainer") ) { return tipContainer; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"buttonContainer") ) { return buttonContainer; }
	}
	return super::__Field(inName);
}

Dynamic LevelFailedUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hitButton") ) { hitButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"menuButton") ) { menuButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { retryButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"tipContainer") ) { tipContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"buttonContainer") ) { buttonContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LevelFailedUI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("menuButton"));
	outFields->push(HX_CSTRING("retryButton"));
	outFields->push(HX_CSTRING("hitButton"));
	outFields->push(HX_CSTRING("tipContainer"));
	outFields->push(HX_CSTRING("buttonContainer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("background"),
	HX_CSTRING("title"),
	HX_CSTRING("menuButton"),
	HX_CSTRING("retryButton"),
	HX_CSTRING("hitButton"),
	HX_CSTRING("tipContainer"),
	HX_CSTRING("buttonContainer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class LevelFailedUI_obj::__mClass;

void LevelFailedUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.LevelFailedUI"), hx::TCanCast< LevelFailedUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LevelFailedUI_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
