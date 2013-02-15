#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
#endif
#ifndef INCLUDED_com_mybo_effects_BurstParticle
#include <com/mybo/effects/BurstParticle.h>
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
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Back
#include <com/mybo/framework/tweener/easing/Back.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Elastic
#include <com/mybo/framework/tweener/easing/Elastic.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Sine
#include <com/mybo/framework/tweener/easing/Sine.h>
#endif
#ifndef INCLUDED_com_mybo_ui_LevelClearUI
#include <com/mybo/ui/LevelClearUI.h>
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
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace ui{

Void LevelClearUI_obj::__construct(int level)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",36)
	Array< ::com::mybo::ui::LevelClearUI > me = Array_obj< ::com::mybo::ui::LevelClearUI >::__new().Add(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",37)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",39)
	this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",40)
	this->stageWidth = this->facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",41)
	this->stageHeight = this->facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",43)
	if (((level == (int)25))){
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",44)
		this->background = this->facade->getBitmap(HX_CSTRING("levelpack_clear_bg"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",45)
		this->addChild(this->background);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",48)
		this->background = this->facade->getBitmap(HX_CSTRING("ui_bg"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",50)
		this->addChild(this->background);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",53)
		::nmex::display::Bitmap levelLable = this->facade->getBitmap(HX_CSTRING("ui_level_text"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",54)
		levelLable->nmeSetX(((double(this->stageWidth) / double((int)2)) - (int)60));
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",55)
		levelLable->nmeSetY((int)40);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",56)
		this->addChild(levelLable);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",58)
		::com::mybo::framework::display::BitmapNumber levelNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(this->facade->getTile(HX_CSTRING("num10")),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",59)
		levelNum->drawNumber(level);
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",60)
		levelNum->nmeSetX(((levelLable->nmeGetX() + levelLable->nmeGetWidth()) + (int)10));
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",61)
		levelNum->nmeSetY(levelLable->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",62)
		this->addChild(levelNum);
	}
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",65)
	this->background->nmeSetHeight(this->facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",69)
	::nmex::display::Bitmap titleStar = this->facade->getBitmap(HX_CSTRING("ui_star"),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",70)
	double titleStarX = ((double(this->stageWidth) / double((int)2)) - (double(titleStar->nmeGetWidth()) / double((int)2)));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",71)
	titleStar->nmeSetScaleX((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",72)
	titleStar->nmeSetScaleY((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",73)
	titleStar->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",74)
	titleStar->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(titleStar->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",75)
	titleStar->nmeSetY((int)80);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",77)
	titleStar->nmeSetY((int)90);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",80)
	this->addChild(titleStar);
	struct _Function_1_1{
		inline static Dynamic Block( double &titleStarX){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("scaleX") , (int)1,false);
			__result->Add(HX_CSTRING("scaleY") , (int)1,false);
			__result->Add(HX_CSTRING("x") , titleStarX,false);
			__result->Add(HX_CSTRING("alpha") , (int)1,false);
			return __result;
		}
	};
	struct _Function_1_2{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.4,false);
			__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Back_obj::easeOut_dyn(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",81)
	::com::mybo::framework::tweener::MTween_obj::to(titleStar,0.3,_Function_1_1::Block(titleStarX),_Function_1_2::Block());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",83)
	this->title = this->facade->getBitmap(HX_CSTRING("clear_title"),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",84)
	double titleX = ((double(this->stageWidth) / double((int)2)) - (double(this->title->nmeGetWidth()) / double((int)2)));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",85)
	this->title->nmeSetScaleX(0.5);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",86)
	this->title->nmeSetScaleY(0.5);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",87)
	this->title->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(this->title->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",88)
	this->title->nmeSetY((int)87);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",90)
	this->title->nmeSetY((int)97);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",92)
	this->addChild(this->title);
	struct _Function_1_3{
		inline static Dynamic Block( double &titleX){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("scaleX") , (int)1,false);
			__result->Add(HX_CSTRING("scaleY") , (int)1,false);
			__result->Add(HX_CSTRING("x") , titleX,false);
			return __result;
		}
	};
	struct _Function_1_4{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.1,false);
			__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Elastic_obj::easeOut_dyn(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",93)
	::com::mybo::framework::tweener::MTween_obj::to(this->title,(int)1,_Function_1_3::Block(titleX),_Function_1_4::Block());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",96)
	::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameover"),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",100)
	::nmex::display::Bitmap rewardStarBar = this->facade->getBitmap(HX_CSTRING("ui_bar"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",102)
	::nme::display::Sprite rewardStarContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",103)
	rewardStarContainer->addChild(rewardStarBar);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",104)
	rewardStarContainer->nmeSetY(this->stageHeight);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",105)
	this->addChild(rewardStarContainer);
	struct _Function_1_5{
		inline static Dynamic Block( ::com::mybo::ui::LevelClearUI_obj *__this){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , ((double(__this->stageHeight) / double((int)2)) - (int)20),false);
			return __result;
		}
	};
	struct _Function_1_6{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.3,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",107)
	::com::mybo::framework::tweener::MTween_obj::to(rewardStarContainer,0.5,_Function_1_5::Block(this),_Function_1_6::Block());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",110)
	Array< ::nme::display::Sprite > plusStar = Array_obj< ::nme::display::Sprite >::__new().Add(::nme::display::Sprite_obj::__new());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",113)
	::nmex::display::Bitmap star = this->facade->getBitmap(HX_CSTRING("ui_star_show"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",115)
	star->nmeSetY(((double(-(star->nmeGetHeight())) / double((int)2)) + (int)5));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",117)
	plusStar->__get((int)0)->addChild(star);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",119)
	plusStar->__get((int)0)->nmeSetX(((double(this->stageWidth) / double((int)4)) - (double(plusStar->__get((int)0)->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",120)
	plusStar->__get((int)0)->nmeSetY((this->stageHeight * 0.7));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",121)
	plusStar->__get((int)0)->nmeSetScaleX((int)10);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",122)
	plusStar->__get((int)0)->nmeSetScaleY((int)10);

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_7,Array< ::nme::display::Sprite >,plusStar,Array< ::com::mybo::ui::LevelClearUI >,me)
	Void run(){
{
			struct _Function_2_1{
				inline static Dynamic Block( Array< ::com::mybo::ui::LevelClearUI > &me){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("scaleX") , (int)1,false);
					__result->Add(HX_CSTRING("scaleY") , (int)1,false);
					__result->Add(HX_CSTRING("x") , (int)125,false);
					__result->Add(HX_CSTRING("y") , ((double(me->__get((int)0)->stageHeight) / double((int)2)) + (int)13),false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",125)
			::com::mybo::framework::tweener::MTween_obj::to(plusStar->__get((int)0),0.08,_Function_2_1::Block(me),null());
			HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",126)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("clearStar"),null(),null());
			HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",127)
			me->__get((int)0)->addChild(plusStar->__get((int)0));
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",124)
	::haxe::Timer_obj::delay( Dynamic(new _Function_1_7(plusStar,me)),(int)1000);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",130)
	Array< ::com::mybo::effects::BurstParticle > particle = Array_obj< ::com::mybo::effects::BurstParticle >::__new().Add(::com::mybo::effects::BurstParticle_obj::__new());
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",131)
	particle->__get((int)0)->nmeSetX((int)150);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",132)
	particle->__get((int)0)->nmeSetY(((double(this->stageHeight) / double((int)2)) + (int)10));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",133)
	this->addChild(particle->__get((int)0));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_8,Array< ::com::mybo::effects::BurstParticle >,particle)
	Void run(){
{
			HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",135)
			particle->__get((int)0)->run();
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",135)
	::haxe::Timer_obj::delay( Dynamic(new _Function_1_8(particle)),(int)1070);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",140)
	this->retryButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_retry"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",141)
	this->menuButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_menu"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",142)
	this->nextButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_next"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",143)
	this->retryButton->nmeSetX((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",144)
	this->menuButton->nmeSetX((int)85);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",145)
	this->nextButton->nmeSetX((int)170);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",147)
	this->buttonContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",148)
	this->buttonContainer->addChild(this->nextButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",149)
	this->buttonContainer->addChild(this->menuButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",150)
	this->buttonContainer->addChild(this->retryButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",151)
	this->buttonContainer->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(this->buttonContainer->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",152)
	this->buttonContainer->nmeSetY(this->stageHeight);
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",153)
	this->addChild(this->buttonContainer);
	struct _Function_1_9{
		inline static Dynamic Block( ::com::mybo::ui::LevelClearUI_obj *__this){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , ((double(__this->stageHeight) / double((int)2)) + (int)110),false);
			return __result;
		}
	};
	struct _Function_1_10{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 1.5,false);
			__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Sine_obj::easeOut_dyn(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/LevelClearUI.hx",155)
	::com::mybo::framework::tweener::MTween_obj::to(this->buttonContainer,0.2,_Function_1_9::Block(this),_Function_1_10::Block());
}
;
	return null();
}

LevelClearUI_obj::~LevelClearUI_obj() { }

Dynamic LevelClearUI_obj::__CreateEmpty() { return  new LevelClearUI_obj; }
hx::ObjectPtr< LevelClearUI_obj > LevelClearUI_obj::__new(int level)
{  hx::ObjectPtr< LevelClearUI_obj > result = new LevelClearUI_obj();
	result->__construct(level);
	return result;}

Dynamic LevelClearUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LevelClearUI_obj > result = new LevelClearUI_obj();
	result->__construct(inArgs[0]);
	return result;}


LevelClearUI_obj::LevelClearUI_obj()
{
}

void LevelClearUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LevelClearUI);
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(levelTitle,"levelTitle");
	HX_MARK_MEMBER_NAME(levelNum,"levelNum");
	HX_MARK_MEMBER_NAME(retryButton,"retryButton");
	HX_MARK_MEMBER_NAME(menuButton,"menuButton");
	HX_MARK_MEMBER_NAME(nextButton,"nextButton");
	HX_MARK_MEMBER_NAME(buttonContainer,"buttonContainer");
	HX_MARK_MEMBER_NAME(facade,"facade");
	HX_MARK_MEMBER_NAME(stageWidth,"stageWidth");
	HX_MARK_MEMBER_NAME(stageHeight,"stageHeight");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic LevelClearUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"levelNum") ) { return levelNum; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		if (HX_FIELD_EQ(inName,"levelTitle") ) { return levelTitle; }
		if (HX_FIELD_EQ(inName,"menuButton") ) { return menuButton; }
		if (HX_FIELD_EQ(inName,"nextButton") ) { return nextButton; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { return stageWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { return retryButton; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { return stageHeight; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"buttonContainer") ) { return buttonContainer; }
	}
	return super::__Field(inName);
}

Dynamic LevelClearUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"levelNum") ) { levelNum=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"levelTitle") ) { levelTitle=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"menuButton") ) { menuButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextButton") ) { nextButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { stageWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { retryButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { stageHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"buttonContainer") ) { buttonContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LevelClearUI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("levelTitle"));
	outFields->push(HX_CSTRING("levelNum"));
	outFields->push(HX_CSTRING("retryButton"));
	outFields->push(HX_CSTRING("menuButton"));
	outFields->push(HX_CSTRING("nextButton"));
	outFields->push(HX_CSTRING("buttonContainer"));
	outFields->push(HX_CSTRING("facade"));
	outFields->push(HX_CSTRING("stageWidth"));
	outFields->push(HX_CSTRING("stageHeight"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("background"),
	HX_CSTRING("title"),
	HX_CSTRING("levelTitle"),
	HX_CSTRING("levelNum"),
	HX_CSTRING("retryButton"),
	HX_CSTRING("menuButton"),
	HX_CSTRING("nextButton"),
	HX_CSTRING("buttonContainer"),
	HX_CSTRING("facade"),
	HX_CSTRING("stageWidth"),
	HX_CSTRING("stageHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class LevelClearUI_obj::__mClass;

void LevelClearUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.LevelClearUI"), hx::TCanCast< LevelClearUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LevelClearUI_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
