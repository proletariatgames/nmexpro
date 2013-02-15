#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Alert
#include <com/mybo/common/Alert.h>
#endif
#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
#endif
#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
#endif
#ifndef INCLUDED_com_mybo_data_GameData
#include <com/mybo/data/GameData.h>
#endif
#ifndef INCLUDED_com_mybo_data_Map
#include <com/mybo/data/Map.h>
#endif
#ifndef INCLUDED_com_mybo_data_UserData
#include <com/mybo/data/UserData.h>
#endif
#ifndef INCLUDED_com_mybo_effects_StarUseParticle
#include <com/mybo/effects/StarUseParticle.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
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
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Linear
#include <com/mybo/framework/tweener/easing/Linear.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_MasterScene
#include <com/mybo/gamescene/MasterScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_MasterMenuScene
#include <com/mybo/menuscene/MasterMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#include <com/mybo/menuscene/StartMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_UserStar
#include <com/mybo/menuscene/UserStar.h>
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
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
#ifndef INCLUDED_nmex_Tracker
#include <nmex/Tracker.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace menuscene{

Void MasterMenuScene_obj::__construct(Dynamic __o_masterWinBack)
{
bool masterWinBack = __o_masterWinBack.Default(false);
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",38)
	Array< ::com::mybo::menuscene::MasterMenuScene > me = Array_obj< ::com::mybo::menuscene::MasterMenuScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",39)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",41)
	this->userData = ::com::mybo::data::UserData_obj::getInstance(null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",42)
	this->hasUnlockedMap = (this->userData->getMasterMap() != null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",44)
	this->background = ::com::mybo::common::Background_obj::__new(false,true,null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",45)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",47)
	double stageWidth = this->facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",48)
	double stageHeight = this->facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",50)
	this->backBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("master_menu"),true));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",51)
	this->backBtn->nmeSetX(((double(this->backBtn->nmeGetWidth()) / double((int)2)) - (int)20));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",52)
	this->backBtn->nmeSetY(((double(this->backBtn->nmeGetHeight()) / double((int)2)) - (int)15));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",53)
	this->addChild(this->backBtn);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",54)
	this->backBtn->click(this->onBack_dyn(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",57)
	this->userStar = ::com::mybo::menuscene::UserStar_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",58)
	this->userStar->nmeSetX(((this->facade->getStageWidthInPoint() - this->userStar->nmeGetWidth()) - (int)15));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",59)
	this->userStar->nmeSetY((int)15);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",60)
	this->addChild(this->userStar);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",62)
	if ((masterWinBack)){
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",63)
		this->userData->setMasterMap(null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",65)
		::com::mybo::common::ScaleEffectButton retryBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("master_retry"),true));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",66)
		retryBtn->nmeSetX(((this->backBtn->nmeGetX() + this->backBtn->nmeGetWidth()) + (int)10));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",67)
		retryBtn->nmeSetY(this->backBtn->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",68)
		this->addChild(retryBtn);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",69)
		retryBtn->click(this->retry_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",71)
		this->chestBitmap = this->facade->getBitmap(HX_CSTRING("bx_unlock"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",72)
		this->chestBitmap->nmeSetY(((this->facade->getStageHeightInPoint() - this->chestBitmap->nmeGetHeight()) + (int)1));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",74)
		this->background->addToBackground(this->chestBitmap);

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::com::mybo::menuscene::MasterMenuScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",78)
				Array< ::nme::display::Sprite > sp = Array_obj< ::nme::display::Sprite >::__new().Add(me->__get((int)0)->drawMask((int)0));
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",79)
				me->__get((int)0)->addChild(sp->__get((int)0));
				struct _Function_3_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("alpha") , (int)1,false);
						return __result;
					}
				};
				struct _Function_3_2{
					inline static Dynamic Block( Array< ::com::mybo::menuscene::MasterMenuScene > &me,Array< ::nme::display::Sprite > &sp){
						hx::Anon __result = hx::Anon_obj::Create();

						HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_4_1,Array< ::com::mybo::menuscene::MasterMenuScene >,me,Array< ::nme::display::Sprite >,sp)
						Void run(){
{
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",82)
								me->__get((int)0)->background->removeFromBackground(me->__get((int)0)->chestBitmap);
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",83)
								me->__get((int)0)->chestBitmap = me->__get((int)0)->facade->getBitmap(HX_CSTRING("bx_open"),null());
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",84)
								me->__get((int)0)->chestBitmap->nmeSetY(((me->__get((int)0)->facade->getStageHeightInPoint() - me->__get((int)0)->chestBitmap->nmeGetHeight()) + (int)1));
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",86)
								me->__get((int)0)->background->addToBackground(me->__get((int)0)->chestBitmap);
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",87)
								me->__get((int)0)->addChild(sp->__get((int)0));
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",89)
								::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("chestSFX"),null(),null());
								struct _Function_5_1{
									inline static Dynamic Block( ){
										hx::Anon __result = hx::Anon_obj::Create();
										__result->Add(HX_CSTRING("alpha") , (int)0,false);
										return __result;
									}
								};
								struct _Function_5_2{
									inline static Dynamic Block( Array< ::com::mybo::menuscene::MasterMenuScene > &me,Array< ::nme::display::Sprite > &sp){
										hx::Anon __result = hx::Anon_obj::Create();
										__result->Add(HX_CSTRING("delay") , 0.1,false);
										__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Linear_obj::easeOut_dyn(),false);

										HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_6_1,Array< ::com::mybo::menuscene::MasterMenuScene >,me,Array< ::nme::display::Sprite >,sp)
										Void run(){
{
												HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",92)
												me->__get((int)0)->removeChild(sp->__get((int)0));
												HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",93)
												me->__get((int)0)->showRewardStar();
											}
											return null();
										}
										HX_END_LOCAL_FUNC0((void))

										__result->Add(HX_CSTRING("onComplete") ,  Dynamic(new _Function_6_1(me,sp)),true);
										return __result;
									}
								};
								HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",91)
								::com::mybo::framework::tweener::MTween_obj::to(sp->__get((int)0),0.6,_Function_5_1::Block(),_Function_5_2::Block(me,sp));
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						__result->Add(HX_CSTRING("onComplete") ,  Dynamic(new _Function_4_1(me,sp)),true);
						return __result;
					}
				};
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",81)
				::com::mybo::framework::tweener::MTween_obj::to(sp->__get((int)0),0.3,_Function_3_1::Block(),_Function_3_2::Block(me,sp));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",76)
		::haxe::Timer_obj::delay( Dynamic(new _Function_2_1(me)),(int)500);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",100)
		::nmex::display::Bitmap tip;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",101)
		if ((this->hasUnlockedMap)){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",102)
			tip = this->facade->getBitmap(HX_CSTRING("master_tip_2"),null());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",103)
			this->chestBitmap = this->facade->getBitmap(HX_CSTRING("bx_unlock"),null());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",105)
			::com::mybo::framework::display::BitmapSimpleButton resetBtn = ::com::mybo::framework::display::BitmapSimpleButton_obj::__new(this->facade->getBitmap(HX_CSTRING("master_reset"),true),null(),null(),null());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",106)
			resetBtn->nmeSetX(((this->backBtn->nmeGetX() + this->backBtn->nmeGetWidth()) + (int)10));
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",107)
			resetBtn->nmeSetY(this->backBtn->nmeGetY());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",108)
			this->addChild(resetBtn);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",109)
			resetBtn->click(this->reset_dyn(),null(),null());
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",112)
			tip = this->facade->getBitmap(HX_CSTRING("master_tip_1"),null());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",113)
			this->chestBitmap = this->facade->getBitmap(HX_CSTRING("bx_close"),null());
		}
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",116)
		tip->nmeSetX(((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(tip->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",117)
		tip->nmeSetY((((double(this->facade->getStageHeightInPoint()) / double((int)2)) - (double(tip->nmeGetHeight()) / double((int)2))) - (int)20));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",118)
		this->addChild(tip);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",120)
		this->chestBitmap->nmeSetY(((this->facade->getStageHeightInPoint() - this->chestBitmap->nmeGetHeight()) + (int)1));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",122)
		this->background->addToBackground(this->chestBitmap);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",123)
		this->addTouchEvent();
	}
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",126)
	::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameBG"),(int)0,(int)-1);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",128)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("masterMenu"));
}
;
	return null();
}

MasterMenuScene_obj::~MasterMenuScene_obj() { }

Dynamic MasterMenuScene_obj::__CreateEmpty() { return  new MasterMenuScene_obj; }
hx::ObjectPtr< MasterMenuScene_obj > MasterMenuScene_obj::__new(Dynamic __o_masterWinBack)
{  hx::ObjectPtr< MasterMenuScene_obj > result = new MasterMenuScene_obj();
	result->__construct(__o_masterWinBack);
	return result;}

Dynamic MasterMenuScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MasterMenuScene_obj > result = new MasterMenuScene_obj();
	result->__construct(inArgs[0]);
	return result;}

::nme::display::Sprite MasterMenuScene_obj::drawMask( Dynamic __o_alpha){
double alpha = __o_alpha.Default(1);
	HX_SOURCE_PUSH("MasterMenuScene_obj::drawMask");
{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",132)
		::nme::display::Sprite sp = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",134)
		sp->nmeSetAlpha(alpha);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",136)
		double vx = (this->facade->getStageWidthInPoint() * ::com::mybo::framework::core::Facade_obj::contentScaleFactor);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",137)
		double vy = (this->facade->getStageHeightInPoint() * ::com::mybo::framework::core::Facade_obj::contentScaleFactor);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",139)
		Array< double > vertices = Array_obj< double >::__new().Add((int)0).Add((int)0).Add(vx).Add((int)0).Add(vx).Add(vy).Add((int)0).Add(vy);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",140)
		Array< int > indices = Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",142)
		sp->nmeGetGraphics()->beginFill((int)16777215,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",143)
		sp->nmeGetGraphics()->drawTriangles(vertices,indices,null(),::nme::display::TriangleCulling_obj::NONE_dyn(),null(),(int)9,null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",145)
		return sp;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(MasterMenuScene_obj,drawMask,return )

Void MasterMenuScene_obj::showRewardStar( ){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::showRewardStar")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",149)
		int rewardStar = ::com::mybo::data::GameData_obj::getMasterReward();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",150)
		::com::mybo::data::UserData_obj::getInstance(null())->addStar(rewardStar);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",152)
		::nme::display::Sprite plusStar = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",154)
		::nmex::display::Bitmap star = this->facade->getBitmap(HX_CSTRING("ui_star_show"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",155)
		plusStar->addChild(star);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",157)
		::nmex::display::Bitmap plus = this->facade->getBitmap(HX_CSTRING("ui_plus"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",158)
		plus->nmeSetX(star->nmeGetWidth());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",159)
		plus->nmeSetY(((double(star->nmeGetHeight()) / double((int)2)) - (int)7));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",160)
		plusStar->addChild(plus);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",162)
		::com::mybo::framework::display::BitmapNumber num = ::com::mybo::framework::display::BitmapNumber_obj::__new(this->facade->getTile(HX_CSTRING("num15")),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",163)
		num->drawNumber(rewardStar);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",164)
		num->nmeSetX((plus->nmeGetX() + plus->nmeGetWidth()));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",165)
		num->nmeSetY(plus->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",166)
		plusStar->addChild(num);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",168)
		plusStar->nmeSetX((int)107);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",169)
		plusStar->nmeSetY((int)345);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",171)
		double starY = (int)220;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",172)
		plusStar->nmeSetAlpha((int)1);
		struct _Function_1_1{
			inline static Dynamic Block( double &starY){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("y") , starY,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 0.2,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",173)
		::com::mybo::framework::tweener::MTween_obj::to(plusStar,0.8,_Function_1_1::Block(starY),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("y") , (int)-50,false);
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 1.3,false);
				__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Linear_obj::easeOut_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",174)
		::com::mybo::framework::tweener::MTween_obj::to(plusStar,0.3,_Function_1_3::Block(),_Function_1_4::Block());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",175)
		this->addChild(plusStar);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",177)
		::haxe::Timer_obj::delay(this->userStar->update_dyn(),(int)500);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",179)
		::nmex::display::Bitmap chestMask = this->facade->getBitmap(HX_CSTRING("chest_mask"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",180)
		chestMask->nmeSetX((int)107);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",181)
		chestMask->nmeSetY((this->facade->getStageHeightInPoint() - (int)135));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",182)
		if ((::nmex::Device_obj::isRetina())){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",183)
			::nmex::display::Bitmap _g = chestMask;
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",183)
			_g->nmeSetY((_g->nmeGetY() - 0.5));
		}
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",185)
		this->addChild(chestMask);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterMenuScene_obj,showRewardStar,(void))

Void MasterMenuScene_obj::unlockChest( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::unlockChest")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",188)
		Array< ::com::mybo::menuscene::MasterMenuScene > me = Array_obj< ::com::mybo::menuscene::MasterMenuScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",189)
		int unlockStar = (int)10;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",190)
		if (((this->userData->getStar() >= unlockStar))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",191)
			this->touchLayer->removeEventListener(::nme::events::MouseEvent_obj::CLICK,this->unlockChest_dyn(),null());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",192)
			this->userData->useStar(unlockStar);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",193)
			this->userStar->update();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",194)
			::nme::geom::Point pos = ::nme::geom::Point_obj::__new(null(),null());
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",195)
			pos->x = (this->userStar->nmeGetX() + (int)22);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",196)
			pos->y = (this->userStar->nmeGetY() + (double(this->userStar->nmeGetHeight()) / double((int)2)));
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",197)
			::com::mybo::effects::StarUseParticle particle = ::com::mybo::effects::StarUseParticle_obj::__new(pos);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",198)
			particle->run();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",199)
			this->addChild(particle);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",201)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("useStar"),null(),null());

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::com::mybo::menuscene::MasterMenuScene >,me)
			Void run(){
{
					HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",203)
					me->__get((int)0)->runMaster(null());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",203)
			::haxe::Timer_obj::delay( Dynamic(new _Function_2_1(me)),(int)1200);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",206)
			::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("get_more_star_android"),true),null(),null(),true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MasterMenuScene_obj,unlockChest,(void))

Void MasterMenuScene_obj::addTouchEvent( ){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::addTouchEvent")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",218)
		this->touchLayer = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",219)
		this->touchLayer->nmeGetGraphics()->beginFill((int)0,(int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",220)
		this->touchLayer->nmeGetGraphics()->drawRect((int)60,(this->chestBitmap->nmeGetY() + (int)110),(int)190,(int)120);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",221)
		this->touchLayer->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",222)
		if ((this->hasUnlockedMap)){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",222)
			this->touchLayer->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->runMaster_dyn(),null(),null(),null());
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",224)
			this->touchLayer->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->unlockChest_dyn(),null(),null(),null());
		}
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",228)
		this->addChild(this->touchLayer);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterMenuScene_obj,addTouchEvent,(void))

Void MasterMenuScene_obj::runMaster( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::runMaster")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",232)
		this->touchLayer->removeEventListener(::nme::events::MouseEvent_obj::CLICK,this->runMaster_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",233)
		this->facade->run(hx::ClassOf< ::com::mybo::gamescene::MasterScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MasterMenuScene_obj,runMaster,(void))

Void MasterMenuScene_obj::retry( ){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::retry")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",236)
		this->facade->run(hx::ClassOf< ::com::mybo::menuscene::MasterMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterMenuScene_obj,retry,(void))

Void MasterMenuScene_obj::reset( ){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::reset")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",240)
		Array< ::com::mybo::menuscene::MasterMenuScene > me = Array_obj< ::com::mybo::menuscene::MasterMenuScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::menuscene::MasterMenuScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",242)
				::com::mybo::data::UserData_obj::getInstance(null())->setMasterMap(null());
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",243)
				me->__get((int)0)->retry();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",241)
		::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("reset"),true), Dynamic(new _Function_1_1(me)),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterMenuScene_obj,reset,(void))

Void MasterMenuScene_obj::onBack( ){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::onBack")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",247)
		this->facade->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterMenuScene_obj,onBack,(void))

Void MasterMenuScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("MasterMenuScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",252)
		this->background->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/MasterMenuScene.hx",253)
		this->facade->unLoadResourceByFolder(HX_CSTRING("master"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterMenuScene_obj,destroy,(void))


MasterMenuScene_obj::MasterMenuScene_obj()
{
}

void MasterMenuScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MasterMenuScene);
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(backBtn,"backBtn");
	HX_MARK_MEMBER_NAME(touchLayer,"touchLayer");
	HX_MARK_MEMBER_NAME(chestBitmap,"chestBitmap");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(hasUnlockedMap,"hasUnlockedMap");
	HX_MARK_MEMBER_NAME(userStar,"userStar");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MasterMenuScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"retry") ) { return retry_dyn(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onBack") ) { return onBack_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"backBtn") ) { return backBtn; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		if (HX_FIELD_EQ(inName,"userStar") ) { return userStar; }
		if (HX_FIELD_EQ(inName,"drawMask") ) { return drawMask_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"runMaster") ) { return runMaster_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		if (HX_FIELD_EQ(inName,"touchLayer") ) { return touchLayer; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"chestBitmap") ) { return chestBitmap; }
		if (HX_FIELD_EQ(inName,"unlockChest") ) { return unlockChest_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"addTouchEvent") ) { return addTouchEvent_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"hasUnlockedMap") ) { return hasUnlockedMap; }
		if (HX_FIELD_EQ(inName,"showRewardStar") ) { return showRewardStar_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MasterMenuScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"backBtn") ) { backBtn=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< ::com::mybo::data::UserData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userStar") ) { userStar=inValue.Cast< ::com::mybo::menuscene::UserStar >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::com::mybo::common::Background >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchLayer") ) { touchLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"chestBitmap") ) { chestBitmap=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"hasUnlockedMap") ) { hasUnlockedMap=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MasterMenuScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("backBtn"));
	outFields->push(HX_CSTRING("touchLayer"));
	outFields->push(HX_CSTRING("chestBitmap"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("hasUnlockedMap"));
	outFields->push(HX_CSTRING("userStar"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("background"),
	HX_CSTRING("backBtn"),
	HX_CSTRING("touchLayer"),
	HX_CSTRING("chestBitmap"),
	HX_CSTRING("userData"),
	HX_CSTRING("hasUnlockedMap"),
	HX_CSTRING("userStar"),
	HX_CSTRING("drawMask"),
	HX_CSTRING("showRewardStar"),
	HX_CSTRING("unlockChest"),
	HX_CSTRING("addTouchEvent"),
	HX_CSTRING("runMaster"),
	HX_CSTRING("retry"),
	HX_CSTRING("reset"),
	HX_CSTRING("onBack"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class MasterMenuScene_obj::__mClass;

void MasterMenuScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.MasterMenuScene"), hx::TCanCast< MasterMenuScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MasterMenuScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
