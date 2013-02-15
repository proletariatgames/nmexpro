#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
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
#ifndef INCLUDED_com_mybo_ui_GameOverUI
#include <com/mybo/ui/GameOverUI.h>
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

Void GameOverUI_obj::__construct(int inScore,int inBestScore,int inLevel,Dynamic __o_inStar)
{
int inStar = __o_inStar.Default(3);
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",44)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",46)
	this->score = inScore;
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",47)
	this->bestScore = inBestScore;
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",48)
	this->rewardStar = inStar;
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",49)
	this->level = inLevel;
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",51)
	this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",52)
	this->stageWidth = this->facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",53)
	this->stageHeight = this->facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",55)
	this->background = this->facade->getBitmap(HX_CSTRING("ui_bg"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",56)
	this->background->nmeSetHeight(this->facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",57)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",59)
	this->menuButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_menu"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",60)
	this->retryButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_retry"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",62)
	this->nmeSetAlpha((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("alpha") , (int)1,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",63)
	::com::mybo::framework::tweener::MTween_obj::to(hx::ObjectPtr<OBJ_>(this),0.8,_Function_1_1::Block(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",65)
	::haxe::Timer_obj::delay(this->startMotion_dyn(),(int)800);
}
;
	return null();
}

GameOverUI_obj::~GameOverUI_obj() { }

Dynamic GameOverUI_obj::__CreateEmpty() { return  new GameOverUI_obj; }
hx::ObjectPtr< GameOverUI_obj > GameOverUI_obj::__new(int inScore,int inBestScore,int inLevel,Dynamic __o_inStar)
{  hx::ObjectPtr< GameOverUI_obj > result = new GameOverUI_obj();
	result->__construct(inScore,inBestScore,inLevel,__o_inStar);
	return result;}

Dynamic GameOverUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameOverUI_obj > result = new GameOverUI_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void GameOverUI_obj::startMotion( ){
{
		HX_SOURCE_PUSH("GameOverUI_obj::startMotion")
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",68)
		Array< ::com::mybo::ui::GameOverUI > me = Array_obj< ::com::mybo::ui::GameOverUI >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",70)
		::nmex::display::Bitmap levelLable = this->facade->getBitmap(HX_CSTRING("ui_level_text"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",71)
		levelLable->nmeSetX(((double(this->stageWidth) / double((int)2)) - (int)60));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",72)
		levelLable->nmeSetY((int)55);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",73)
		this->addChild(levelLable);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",75)
		::com::mybo::framework::display::BitmapNumber levelNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(this->facade->getTile(HX_CSTRING("num10")),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",76)
		levelNum->drawNumber(this->level);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",77)
		levelNum->nmeSetX(((levelLable->nmeGetX() + levelLable->nmeGetWidth()) + (int)5));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",78)
		levelNum->nmeSetY(levelLable->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",79)
		this->addChild(levelNum);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",82)
		::nmex::display::Bitmap titleStar = this->facade->getBitmap(HX_CSTRING("ui_star"),true);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",83)
		double titleStarX = ((double(this->stageWidth) / double((int)2)) - (double(titleStar->nmeGetWidth()) / double((int)2)));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",84)
		titleStar->nmeSetScaleX((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",85)
		titleStar->nmeSetScaleY((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",86)
		titleStar->nmeSetAlpha((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",87)
		titleStar->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(titleStar->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",88)
		titleStar->nmeSetY((int)80);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",90)
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
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",91)
		::com::mybo::framework::tweener::MTween_obj::to(titleStar,0.3,_Function_1_1::Block(titleStarX),_Function_1_2::Block());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",93)
		if (((this->score > this->bestScore))){
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",94)
			this->title = this->facade->getBitmap(HX_CSTRING("gameover_title_nr"),null());
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",95)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameover"),null(),null());
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",97)
			this->title = this->facade->getBitmap(HX_CSTRING("gameover_title"),null());
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",98)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("levelFailed"),null(),null());
		}
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",101)
		double titleX = ((double(this->stageWidth) / double((int)2)) - (double(this->title->nmeGetWidth()) / double((int)2)));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",102)
		this->title->nmeSetScaleX(0.5);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",103)
		this->title->nmeSetScaleY(0.5);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",104)
		this->title->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(this->title->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",105)
		this->title->nmeSetY((int)95);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",106)
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
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",107)
		::com::mybo::framework::tweener::MTween_obj::to(this->title,(int)1,_Function_1_3::Block(titleX),_Function_1_4::Block());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",110)
		this->scoreNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(this->facade->getTile(HX_CSTRING("num9")),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",111)
		this->scoreNum->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(this->scoreNum->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",112)
		this->scoreNum->nmeSetY((this->title->nmeGetY() + (int)90));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",114)
		Array< int > i = Array_obj< int >::__new().Add((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",115)
		Array< ::haxe::Timer > timer = Array_obj< ::haxe::Timer >::__new().Add(::haxe::Timer_obj::__new((int)30));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",116)
		Array< int > step = Array_obj< int >::__new().Add((::Std_obj::_int((double(this->score) / double((int)30))) + (int)1));

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_5,Array< ::haxe::Timer >,timer,Array< ::com::mybo::ui::GameOverUI >,me,Array< int >,i,Array< int >,step)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",119)
				me->__get((int)0)->addChild(me->__get((int)0)->scoreNum);
				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",120)
				if (((me->__get((int)0)->score != (int)0))){
					HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",120)
					::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("countSFX"),null(),null());
				}

				HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_2_1,Array< ::haxe::Timer >,timer,Array< int >,i,Array< int >,step,Array< ::com::mybo::ui::GameOverUI >,me)
				Void run(){
{
						HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",124)
						i[(int)0] = (  ((((i->__get((int)0) + step->__get((int)0)) < me->__get((int)0)->score))) ? int((i->__get((int)0) + step->__get((int)0))) : int(me->__get((int)0)->score) );
						HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",125)
						me->__get((int)0)->scoreNum->drawNumber(i->__get((int)0));
						HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",126)
						me->__get((int)0)->scoreNum->nmeSetX(((double(me->__get((int)0)->stageWidth) / double((int)2)) - (double(me->__get((int)0)->scoreNum->nmeGetWidth()) / double((int)2))));
						HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",128)
						if (((i->__get((int)0) == me->__get((int)0)->score))){
							HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",129)
							timer->__get((int)0)->stop();
							HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",130)
							me->__get((int)0)->scoreMotionComplete();
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",123)
				timer->__get((int)0)->run =  Dynamic(new _Function_2_1(timer,i,step,me));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",118)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_5(timer,me,i,step)),(int)1000);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameOverUI_obj,startMotion,(void))

Void GameOverUI_obj::scoreMotionComplete( ){
{
		HX_SOURCE_PUSH("GameOverUI_obj::scoreMotionComplete")
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",137)
		if (((this->score > this->bestScore))){
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",138)
			this->newRecord = this->facade->getBitmap(HX_CSTRING("gameover_newrecord"),true);
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",139)
			this->newRecord->nmeSetX(((this->scoreNum->nmeGetX() + this->scoreNum->nmeGetWidth()) + (int)40));
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",140)
			this->newRecord->nmeSetY((this->title->nmeGetY() + (int)90));
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",141)
			this->newRecord->nmeSetScaleX((int)10);
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",142)
			this->newRecord->nmeSetScaleY((int)10);
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",144)
			this->addChild(this->newRecord);
			struct _Function_2_1{
				inline static Dynamic Block( ::com::mybo::ui::GameOverUI_obj *__this){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("scaleX") , (int)1,false);
					__result->Add(HX_CSTRING("scaleY") , (int)1,false);
					__result->Add(HX_CSTRING("x") , (__this->scoreNum->nmeGetX() + (double((__this->scoreNum->nmeGetWidth() * (int)2)) / double((int)3))),false);
					__result->Add(HX_CSTRING("y") , (__this->title->nmeGetY() + (int)50),false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",145)
			::com::mybo::framework::tweener::MTween_obj::to(this->newRecord,0.08,_Function_2_1::Block(this),null());
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",146)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("newScore"),null(),null());
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",148)
			this->bestScoreTitle = this->facade->getBitmap(HX_CSTRING("gameover_best"),true);
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",149)
			this->bestScoreNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(this->facade->getTile(HX_CSTRING("num11")),null());
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",150)
			this->bestScoreNum->drawNumber(this->bestScore);
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",151)
			this->bestScoreTitle->nmeSetX(((double(this->stageWidth) / double((int)2)) - this->bestScoreTitle->nmeGetWidth()));
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",152)
			this->bestScoreNum->nmeSetX(((double(this->stageWidth) / double((int)2)) + (int)5));
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",153)
			this->bestScoreTitle->nmeSetY((this->title->nmeGetY() + (int)145));
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",154)
			this->bestScoreNum->nmeSetY((this->title->nmeGetY() + (int)145));
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",156)
			this->addChild(this->bestScoreTitle);
			HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",157)
			this->addChild(this->bestScoreNum);
		}
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",161)
		::nmex::display::Bitmap rewardStarBar = this->facade->getBitmap(HX_CSTRING("ui_bar"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",163)
		Array< ::nme::display::Sprite > rewardStarContainer = Array_obj< ::nme::display::Sprite >::__new().Add(::nme::display::Sprite_obj::__new());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",164)
		rewardStarContainer->__get((int)0)->addChild(rewardStarBar);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",165)
		rewardStarContainer->__get((int)0)->nmeSetY(this->stageHeight);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",166)
		this->addChild(rewardStarContainer->__get((int)0));
		struct _Function_1_1{
			inline static Dynamic Block( ::com::mybo::ui::GameOverUI_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("y") , ((double(__this->stageHeight) / double((int)2)) + (int)20),false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 0.3,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",168)
		::com::mybo::framework::tweener::MTween_obj::to(rewardStarContainer->__get((int)0),0.5,_Function_1_1::Block(this),_Function_1_2::Block());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",170)
		::nmex::display::Bitmap starSlot = this->facade->getBitmap(HX_CSTRING("ui_star_hide"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",171)
		starSlot->nmeSetX(((double(this->stageWidth) / double((int)2)) - starSlot->nmeGetWidth()));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",172)
		starSlot->nmeSetY((int)20);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",173)
		rewardStarContainer->__get((int)0)->addChild(starSlot);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",175)
		Array< ::nme::display::Sprite > plusStar = Array_obj< ::nme::display::Sprite >::__new().Add(::nme::display::Sprite_obj::__new());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",177)
		::nmex::display::Bitmap star = this->facade->getBitmap(HX_CSTRING("ui_star_show"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",178)
		plusStar->__get((int)0)->addChild(star);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",180)
		::nmex::display::Bitmap plus = this->facade->getBitmap(HX_CSTRING("ui_plus"),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",181)
		plus->nmeSetX(star->nmeGetWidth());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",182)
		plus->nmeSetY(((double(star->nmeGetHeight()) / double((int)2)) - (int)7));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",183)
		plusStar->__get((int)0)->addChild(plus);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",185)
		::com::mybo::framework::display::BitmapNumber num = ::com::mybo::framework::display::BitmapNumber_obj::__new(this->facade->getTile(HX_CSTRING("num15")),null());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",186)
		num->drawNumber(this->rewardStar);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",187)
		num->nmeSetX((plus->nmeGetX() + plus->nmeGetWidth()));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",188)
		num->nmeSetY(plus->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",189)
		plusStar->__get((int)0)->addChild(num);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",192)
		plusStar->__get((int)0)->nmeSetX(((double(this->stageWidth) / double((int)4)) - (double(plusStar->__get((int)0)->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",193)
		plusStar->__get((int)0)->nmeSetY((this->stageHeight * 0.7));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",194)
		plusStar->__get((int)0)->nmeSetScaleX((int)10);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",195)
		plusStar->__get((int)0)->nmeSetScaleY((int)10);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",196)
		Array< double > starX = Array_obj< double >::__new().Add((starSlot->nmeGetX() + (int)1));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",197)
		Array< double > starY = Array_obj< double >::__new().Add((int)20);

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_3,Array< ::nme::display::Sprite >,plusStar,Array< double >,starX,Array< ::nme::display::Sprite >,rewardStarContainer,Array< double >,starY)
		Void run(){
{
				struct _Function_2_1{
					inline static Dynamic Block( Array< double > &starX,Array< double > &starY){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("scaleX") , (int)1,false);
						__result->Add(HX_CSTRING("scaleY") , (int)1,false);
						__result->Add(HX_CSTRING("x") , starX->__get((int)0),false);
						__result->Add(HX_CSTRING("y") , starY->__get((int)0),false);
						return __result;
					}
				};
				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",200)
				::com::mybo::framework::tweener::MTween_obj::to(plusStar->__get((int)0),0.08,_Function_2_1::Block(starX,starY),null());
				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",201)
				::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("clearStar"),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",202)
				rewardStarContainer->__get((int)0)->addChild(plusStar->__get((int)0));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",199)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_3(plusStar,starX,rewardStarContainer,starY)),(int)900);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",205)
		Array< ::com::mybo::effects::BurstParticle > particle = Array_obj< ::com::mybo::effects::BurstParticle >::__new().Add(::com::mybo::effects::BurstParticle_obj::__new());
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",206)
		particle->__get((int)0)->nmeSetX((int)180);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",207)
		particle->__get((int)0)->nmeSetY(((double(this->stageHeight) / double((int)2)) + (int)10));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",208)
		this->addChild(particle->__get((int)0));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_4,Array< ::com::mybo::effects::BurstParticle >,particle)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",210)
				particle->__get((int)0)->run();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",210)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_4(particle)),(int)970);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",253)
		this->retryButton->nmeSetX((this->menuButton->nmeGetWidth() + (int)20));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",255)
		::nme::display::Sprite menuContainer = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",256)
		menuContainer->addChild(this->menuButton);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",257)
		menuContainer->addChild(this->retryButton);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",259)
		menuContainer->nmeSetX(((double(this->stageWidth) / double((int)2)) - (double(menuContainer->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",260)
		menuContainer->nmeSetY(this->stageHeight);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",261)
		this->addChild(menuContainer);
		struct _Function_1_5{
			inline static Dynamic Block( ::com::mybo::ui::GameOverUI_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("y") , ((double(__this->stageHeight) / double((int)2)) + (int)130),false);
				return __result;
			}
		};
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 1.5,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameOverUI.hx",263)
		::com::mybo::framework::tweener::MTween_obj::to(menuContainer,0.5,_Function_1_5::Block(this),_Function_1_6::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameOverUI_obj,scoreMotionComplete,(void))


GameOverUI_obj::GameOverUI_obj()
{
}

void GameOverUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameOverUI);
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(menuButton,"menuButton");
	HX_MARK_MEMBER_NAME(retryButton,"retryButton");
	HX_MARK_MEMBER_NAME(newRecord,"newRecord");
	HX_MARK_MEMBER_NAME(bestScoreTitle,"bestScoreTitle");
	HX_MARK_MEMBER_NAME(bestScoreNum,"bestScoreNum");
	HX_MARK_MEMBER_NAME(scoreNum,"scoreNum");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(bestScore,"bestScore");
	HX_MARK_MEMBER_NAME(rewardStar,"rewardStar");
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(facade,"facade");
	HX_MARK_MEMBER_NAME(stageWidth,"stageWidth");
	HX_MARK_MEMBER_NAME(stageHeight,"stageHeight");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic GameOverUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		if (HX_FIELD_EQ(inName,"score") ) { return score; }
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"scoreNum") ) { return scoreNum; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"newRecord") ) { return newRecord; }
		if (HX_FIELD_EQ(inName,"bestScore") ) { return bestScore; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		if (HX_FIELD_EQ(inName,"menuButton") ) { return menuButton; }
		if (HX_FIELD_EQ(inName,"rewardStar") ) { return rewardStar; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { return stageWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { return retryButton; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { return stageHeight; }
		if (HX_FIELD_EQ(inName,"startMotion") ) { return startMotion_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bestScoreNum") ) { return bestScoreNum; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bestScoreTitle") ) { return bestScoreTitle; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"scoreMotionComplete") ) { return scoreMotionComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic GameOverUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"score") ) { score=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"scoreNum") ) { scoreNum=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"newRecord") ) { newRecord=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bestScore") ) { bestScore=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"menuButton") ) { menuButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rewardStar") ) { rewardStar=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { stageWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { retryButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { stageHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bestScoreNum") ) { bestScoreNum=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bestScoreTitle") ) { bestScoreTitle=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameOverUI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("menuButton"));
	outFields->push(HX_CSTRING("retryButton"));
	outFields->push(HX_CSTRING("newRecord"));
	outFields->push(HX_CSTRING("bestScoreTitle"));
	outFields->push(HX_CSTRING("bestScoreNum"));
	outFields->push(HX_CSTRING("scoreNum"));
	outFields->push(HX_CSTRING("score"));
	outFields->push(HX_CSTRING("bestScore"));
	outFields->push(HX_CSTRING("rewardStar"));
	outFields->push(HX_CSTRING("level"));
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
	HX_CSTRING("menuButton"),
	HX_CSTRING("retryButton"),
	HX_CSTRING("newRecord"),
	HX_CSTRING("bestScoreTitle"),
	HX_CSTRING("bestScoreNum"),
	HX_CSTRING("scoreNum"),
	HX_CSTRING("score"),
	HX_CSTRING("bestScore"),
	HX_CSTRING("rewardStar"),
	HX_CSTRING("level"),
	HX_CSTRING("facade"),
	HX_CSTRING("stageWidth"),
	HX_CSTRING("stageHeight"),
	HX_CSTRING("startMotion"),
	HX_CSTRING("scoreMotionComplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class GameOverUI_obj::__mClass;

void GameOverUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.GameOverUI"), hx::TCanCast< GameOverUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameOverUI_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
