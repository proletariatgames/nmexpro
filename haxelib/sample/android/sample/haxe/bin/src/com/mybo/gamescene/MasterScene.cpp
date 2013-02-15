#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_Alert
#include <com/mybo/common/Alert.h>
#endif
#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameMode
#include <com/mybo/common/GameMode.h>
#endif
#ifndef INCLUDED_com_mybo_common_PopupManager
#include <com/mybo/common/PopupManager.h>
#endif
#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
#endif
#ifndef INCLUDED_com_mybo_data_Map
#include <com/mybo/data/Map.h>
#endif
#ifndef INCLUDED_com_mybo_data_MapFactory
#include <com/mybo/data/MapFactory.h>
#endif
#ifndef INCLUDED_com_mybo_data_UserData
#include <com/mybo/data/UserData.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameBoard
#include <com/mybo/gamescene/GameBoard.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameHint
#include <com/mybo/gamescene/GameHint.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameStatus
#include <com/mybo/gamescene/GameStatus.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_MasterScene
#include <com/mybo/gamescene/MasterScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_MasterMenuScene
#include <com/mybo/menuscene/MasterMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_ui_GameUI
#include <com/mybo/ui/GameUI.h>
#endif
#ifndef INCLUDED_com_mybo_ui_LevelFailedUI
#include <com/mybo/ui/LevelFailedUI.h>
#endif
#ifndef INCLUDED_com_mybo_ui_PauseUI
#include <com/mybo/ui/PauseUI.h>
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
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
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
namespace com{
namespace mybo{
namespace gamescene{

Void MasterScene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",48)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",50)
	this->facade->loadResourceByFolder(HX_CSTRING("hintStar"));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",52)
	this->page = ::com::mybo::ui::GameUI_obj::__new(::com::mybo::common::GameMode_obj::master_dyn());
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",53)
	this->addChild(this->page);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",55)
	this->init();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",57)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("master"));
}
;
	return null();
}

MasterScene_obj::~MasterScene_obj() { }

Dynamic MasterScene_obj::__CreateEmpty() { return  new MasterScene_obj; }
hx::ObjectPtr< MasterScene_obj > MasterScene_obj::__new()
{  hx::ObjectPtr< MasterScene_obj > result = new MasterScene_obj();
	result->__construct();
	return result;}

Dynamic MasterScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MasterScene_obj > result = new MasterScene_obj();
	result->__construct();
	return result;}

Void MasterScene_obj::init( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::init")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",61)
		this->map = ::com::mybo::data::UserData_obj::getInstance(null())->getMasterMap();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",62)
		if (((null() == this->map))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",63)
			this->map = ::com::mybo::data::MapFactory_obj::getMasterMap();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",64)
			::com::mybo::data::UserData_obj::getInstance(null())->setMasterMap(this->map);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",67)
		this->score = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",68)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",69)
		this->touches = this->map->solutionStep;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",70)
		this->maxTouches = this->map->solutionStep;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",71)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",72)
		this->status = ::com::mybo::gamescene::GameStatus_obj::READY_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",74)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameBG"),(int)0,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,init,(void))

Void MasterScene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::sceneDidAppear")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",78)
		this->gameBoard = ::com::mybo::gamescene::GameBoard_obj::__new(this->map,this->page->gameBoardView,null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",80)
		this->gameBoard->addEventListener(HX_CSTRING("levelComplete"),this->levelComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",81)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTouched"),this->onTouchBubble_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",82)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleBlast"),this->onBubbleBlast_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",83)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTapCompleted"),this->onBubbleTapComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",85)
		this->page->hint->click(this->showTip_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",86)
		this->page->pauseButton->click(this->pause_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",87)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,sceneDidAppear,(void))

Void MasterScene_obj::onBubbleTapComplete( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("MasterScene_obj::onBubbleTapComplete")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",91)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",92)
		if (((this->touches == (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",92)
			this->gameOver();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MasterScene_obj,onBubbleTapComplete,(void))

Void MasterScene_obj::onBubbleBlast( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("MasterScene_obj::onBubbleBlast")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",98)
		hx::AddEq(this->blastCombo,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",99)
		hx::AddEq(this->score,((int)15 * this->blastCombo));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",100)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MasterScene_obj,onBubbleBlast,(void))

Void MasterScene_obj::onTouchBubble( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("MasterScene_obj::onTouchBubble")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",103)
		if (((this->touches > (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",105)
			hx::SubEq(this->touches,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",106)
			this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MasterScene_obj,onTouchBubble,(void))

Void MasterScene_obj::levelComplete( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("MasterScene_obj::levelComplete")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",111)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("master"),HX_CSTRING("winMaps"),this->map->toString(),(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",112)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::MasterMenuScene >(),Array_obj< bool >::__new().Add(true));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MasterScene_obj,levelComplete,(void))

Void MasterScene_obj::pause( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::pause")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",116)
		this->gameBoard->pause();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",118)
		::com::mybo::ui::PauseUI pauseUI = ::com::mybo::ui::PauseUI_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",119)
		pauseUI->resumeButton->click(this->resume_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",120)
		pauseUI->menuButton->click(this->back_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",121)
		pauseUI->retryButton->click(this->retry_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",122)
		::com::mybo::common::PopupManager_obj::getInstance()->popup(pauseUI);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",124)
		this->status = ::com::mybo::gamescene::GameStatus_obj::PAUSE_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,pause,(void))

Void MasterScene_obj::resume( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::resume")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",129)
		this->gameBoard->resume();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",130)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",131)
		this->page->pauseButton->click(this->pause_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",132)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,resume,(void))

Void MasterScene_obj::retry( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::retry")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",137)
		this->page->background->startAnimation();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",138)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameBG"),(int)0,(int)-1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",139)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",141)
		this->init();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",142)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",143)
		this->gameBoard->init(this->map);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",144)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",145)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,retry,(void))

Void MasterScene_obj::back( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::back")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",149)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",150)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::MasterMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,back,(void))

Void MasterScene_obj::gameOver( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::gameOver")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",153)
		Array< ::com::mybo::gamescene::MasterScene > me = Array_obj< ::com::mybo::gamescene::MasterScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",154)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->stopAll();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",155)
		this->gameBoard->disable();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",156)
		this->gameBoard->motionClean();

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::gamescene::MasterScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",161)
				me->__get((int)0)->page->background->stopAnimation();
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",163)
				::com::mybo::ui::LevelFailedUI gameOverUI = ::com::mybo::ui::LevelFailedUI_obj::__new((int)0,true);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",164)
				gameOverUI->menuButton->click(me->__get((int)0)->back_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",165)
				gameOverUI->retryButton->click(me->__get((int)0)->retry_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",166)
				gameOverUI->hitButton->click(me->__get((int)0)->resetMaster_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",167)
				::com::mybo::common::PopupManager_obj::getInstance()->popup(gameOverUI);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",160)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(me)),(int)1000);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",170)
		this->status = ::com::mybo::gamescene::GameStatus_obj::OVER_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",171)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("startGame"),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",172)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("master"),HX_CSTRING("failedLevels"),::Std_obj::string(this->level),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,gameOver,(void))

Void MasterScene_obj::resetMaster( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::resetMaster")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",176)
		Array< ::com::mybo::gamescene::MasterScene > me = Array_obj< ::com::mybo::gamescene::MasterScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::gamescene::MasterScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",178)
				::com::mybo::data::UserData_obj::getInstance(null())->setMasterMap(null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",179)
				me->__get((int)0)->back();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",177)
		::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("reset"),true), Dynamic(new _Function_1_1(me)),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,resetMaster,(void))

Void MasterScene_obj::showTip( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::showTip")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",183)
		Array< ::com::mybo::gamescene::MasterScene > me = Array_obj< ::com::mybo::gamescene::MasterScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",184)
		Array< ::com::mybo::data::UserData > userData = Array_obj< ::com::mybo::data::UserData >::__new().Add(::com::mybo::data::UserData_obj::getInstance(null()));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",185)
		if ((this->map->buyTip)){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",185)
			this->startHintMode();
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",187)
			if (((userData->__get((int)0)->getStar() >= (int)70))){

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,Array< ::com::mybo::data::UserData >,userData,Array< ::com::mybo::gamescene::MasterScene >,me)
				Void run(){
{
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",190)
						userData->__get((int)0)->useStar((int)70);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",191)
						me->__get((int)0)->map->buyTip = true;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",192)
						me->__get((int)0)->startHintMode();
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",188)
				::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("challenge_solution"),null()), Dynamic(new _Function_3_1(userData,me)),null(),null());
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",194)
				::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("get_more_star_android"),true),null(),null(),true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,showTip,(void))

Void MasterScene_obj::startHintMode( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::startHintMode")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",207)
		this->retry();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",208)
		::com::mybo::gamescene::GameHint hint = ::com::mybo::gamescene::GameHint_obj::__new(this->gameBoard,this->map->solution);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,startHintMode,(void))

Void MasterScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("MasterScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",213)
		this->page->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",214)
		this->gameBoard->removeEventListener(HX_CSTRING("levelComplete"),this->levelComplete_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",215)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTouched"),this->onTouchBubble_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",216)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleBlast"),this->onBubbleBlast_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",217)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTapCompleted"),this->onBubbleTapComplete_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",218)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",220)
		::nmex::Tracker_obj::dispatchTracker();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",222)
		this->facade->unLoadResourceByFolder(HX_CSTRING("game"));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",223)
		this->facade->unLoadResourceByFolder(HX_CSTRING("gameover"));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/MasterScene.hx",224)
		this->facade->unLoadResourceByFolder(HX_CSTRING("hintStar"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MasterScene_obj,destroy,(void))


MasterScene_obj::MasterScene_obj()
{
}

void MasterScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MasterScene);
	HX_MARK_MEMBER_NAME(gameBoard,"gameBoard");
	HX_MARK_MEMBER_NAME(map,"map");
	HX_MARK_MEMBER_NAME(pack,"pack");
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(touches,"touches");
	HX_MARK_MEMBER_NAME(maxTouches,"maxTouches");
	HX_MARK_MEMBER_NAME(blastCombo,"blastCombo");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(page,"page");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MasterScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { return map; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"pack") ) { return pack; }
		if (HX_FIELD_EQ(inName,"page") ) { return page; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"back") ) { return back_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		if (HX_FIELD_EQ(inName,"score") ) { return score; }
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"retry") ) { return retry_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"touches") ) { return touches; }
		if (HX_FIELD_EQ(inName,"showTip") ) { return showTip_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameOver") ) { return gameOver_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameBoard") ) { return gameBoard; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxTouches") ) { return maxTouches; }
		if (HX_FIELD_EQ(inName,"blastCombo") ) { return blastCombo; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"resetMaster") ) { return resetMaster_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onBubbleBlast") ) { return onBubbleBlast_dyn(); }
		if (HX_FIELD_EQ(inName,"onTouchBubble") ) { return onTouchBubble_dyn(); }
		if (HX_FIELD_EQ(inName,"levelComplete") ) { return levelComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"startHintMode") ) { return startHintMode_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sceneDidAppear") ) { return sceneDidAppear_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onBubbleTapComplete") ) { return onBubbleTapComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MasterScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { map=inValue.Cast< ::com::mybo::data::Map >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"pack") ) { pack=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"page") ) { page=inValue.Cast< ::com::mybo::ui::GameUI >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"score") ) { score=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< ::com::mybo::gamescene::GameStatus >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"touches") ) { touches=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameBoard") ) { gameBoard=inValue.Cast< ::com::mybo::gamescene::GameBoard >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxTouches") ) { maxTouches=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blastCombo") ) { blastCombo=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MasterScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gameBoard"));
	outFields->push(HX_CSTRING("map"));
	outFields->push(HX_CSTRING("pack"));
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("score"));
	outFields->push(HX_CSTRING("touches"));
	outFields->push(HX_CSTRING("maxTouches"));
	outFields->push(HX_CSTRING("blastCombo"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("page"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("gameBoard"),
	HX_CSTRING("map"),
	HX_CSTRING("pack"),
	HX_CSTRING("level"),
	HX_CSTRING("score"),
	HX_CSTRING("touches"),
	HX_CSTRING("maxTouches"),
	HX_CSTRING("blastCombo"),
	HX_CSTRING("status"),
	HX_CSTRING("page"),
	HX_CSTRING("init"),
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("onBubbleTapComplete"),
	HX_CSTRING("onBubbleBlast"),
	HX_CSTRING("onTouchBubble"),
	HX_CSTRING("levelComplete"),
	HX_CSTRING("pause"),
	HX_CSTRING("resume"),
	HX_CSTRING("retry"),
	HX_CSTRING("back"),
	HX_CSTRING("gameOver"),
	HX_CSTRING("resetMaster"),
	HX_CSTRING("showTip"),
	HX_CSTRING("startHintMode"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class MasterScene_obj::__mClass;

void MasterScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.MasterScene"), hx::TCanCast< MasterScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MasterScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
