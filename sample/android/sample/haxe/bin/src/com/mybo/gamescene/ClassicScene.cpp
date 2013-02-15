#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_com_mybo_data_GameData
#include <com/mybo/data/GameData.h>
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
#ifndef INCLUDED_com_mybo_effects_LevelUpEffect
#include <com/mybo/effects/LevelUpEffect.h>
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
#ifndef INCLUDED_com_mybo_gamescene_ClassicScene
#include <com/mybo/gamescene/ClassicScene.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameBoard
#include <com/mybo/gamescene/GameBoard.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameStatus
#include <com/mybo/gamescene/GameStatus.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#include <com/mybo/menuscene/StartMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_ui_GameOverUI
#include <com/mybo/ui/GameOverUI.h>
#endif
#ifndef INCLUDED_com_mybo_ui_GameUI
#include <com/mybo/ui/GameUI.h>
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
#ifndef INCLUDED_nme_display_Shape
#include <nme/display/Shape.h>
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
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
#ifndef INCLUDED_nmex_GameCenter
#include <nmex/GameCenter.h>
#endif
#ifndef INCLUDED_nmex_NXObject
#include <nmex/NXObject.h>
#endif
#ifndef INCLUDED_nmex_NativeUI
#include <nmex/NativeUI.h>
#endif
#ifndef INCLUDED_nmex_Tracker
#include <nmex/Tracker.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace gamescene{

Void ClassicScene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",44)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",45)
	this->page = ::com::mybo::ui::GameUI_obj::__new(::com::mybo::common::GameMode_obj::classic_dyn());
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",46)
	this->addChild(this->page);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",47)
	this->init();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",49)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("classic"));
}
;
	return null();
}

ClassicScene_obj::~ClassicScene_obj() { }

Dynamic ClassicScene_obj::__CreateEmpty() { return  new ClassicScene_obj; }
hx::ObjectPtr< ClassicScene_obj > ClassicScene_obj::__new()
{  hx::ObjectPtr< ClassicScene_obj > result = new ClassicScene_obj();
	result->__construct();
	return result;}

Dynamic ClassicScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ClassicScene_obj > result = new ClassicScene_obj();
	result->__construct();
	return result;}

Void ClassicScene_obj::init( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::init")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",53)
		this->level = (int)1;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",54)
		this->score = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",55)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",56)
		this->touches = (int)15;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",57)
		this->maxTouches = (int)15;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",58)
		::com::mybo::data::MapFactory_obj::resetClassicModeMap();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",59)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",61)
		this->status = ::com::mybo::gamescene::GameStatus_obj::READY_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",63)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameBG"),(int)0,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,init,(void))

Void ClassicScene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::sceneDidAppear")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",67)
		this->gameBoard = ::com::mybo::gamescene::GameBoard_obj::__new(::com::mybo::data::MapFactory_obj::getClassicModeMap(this->level),this->page->gameBoardView,null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",68)
		this->gameBoard->addEventListener(HX_CSTRING("levelComplete"),this->levelUp_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",69)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTouched"),this->onTouchBubble_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",70)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleBlast"),this->onBubbleBlast_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",71)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTapCompleted"),this->onBubbleTapComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",73)
		this->page->pauseButton->click(this->pause_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",74)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,sceneDidAppear,(void))

Void ClassicScene_obj::onBubbleTapComplete( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("ClassicScene_obj::onBubbleTapComplete")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",78)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",79)
		if (((this->touches == (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",79)
			this->gameOver();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ClassicScene_obj,onBubbleTapComplete,(void))

Void ClassicScene_obj::onBubbleBlast( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("ClassicScene_obj::onBubbleBlast")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",85)
		hx::AddEq(this->score,((int)15 + this->level));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",86)
		hx::AddEq(this->blastCombo,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",87)
		if (((this->blastCombo >= (int)3))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",88)
			hx::SubEq(this->blastCombo,(int)3);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",89)
			hx::AddEq(this->touches,(int)1);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",91)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ClassicScene_obj,onBubbleBlast,(void))

Void ClassicScene_obj::onTouchBubble( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("ClassicScene_obj::onTouchBubble")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",94)
		if (((this->touches > (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",96)
			hx::SubEq(this->touches,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",97)
			this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ClassicScene_obj,onTouchBubble,(void))

Void ClassicScene_obj::levelUp( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("ClassicScene_obj::levelUp")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",103)
		if ((::nmex::Device_obj::isRetina())){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",103)
			::com::mybo::effects::LevelUpEffect_obj::__new(this->page->effectLayer,(int)0,(int)480,(int)1,(int)80,0.5,(int)0,0.7);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",105)
			::com::mybo::effects::LevelUpEffect_obj::__new(this->page->effectLayer,(int)0,(int)480,(int)1,(int)80,0.5,(int)0,0.7);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",109)
		int rad = (::Std_obj::random((int)4) + (int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",110)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play((HX_CSTRING("levelUp") + ::Std_obj::string(rad)),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",112)
		::haxe::Timer_obj::delay(this->nextLevel_dyn(),(int)1800);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ClassicScene_obj,levelUp,(void))

Void ClassicScene_obj::nextLevel( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::nextLevel")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",116)
		if (((this->status == ::com::mybo::gamescene::GameStatus_obj::EXIT_dyn()))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",116)
			return null();
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",118)
		hx::AddEq(this->level,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",119)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",121)
		if (((hx::Mod(this->level,(int)6) != (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",121)
			this->gameBoard->setBubbleTextureID(HX_CSTRING("bubbleA"));
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",123)
			this->gameBoard->setBubbleTextureID(HX_CSTRING("bubbleB"));
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",127)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",128)
		this->gameBoard->init(::com::mybo::data::MapFactory_obj::getClassicModeMap(this->level));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",130)
		this->touches = (this->touches + (int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",131)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,nextLevel,(void))

Void ClassicScene_obj::pause( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::pause")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",135)
		this->gameBoard->pause();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",137)
		::com::mybo::ui::PauseUI pauseUI = ::com::mybo::ui::PauseUI_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",138)
		pauseUI->resumeButton->click(this->resume_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",139)
		pauseUI->menuButton->click(this->back_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",140)
		pauseUI->retryButton->click(this->retry_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",141)
		::com::mybo::common::PopupManager_obj::getInstance()->popup(pauseUI);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",143)
		this->status = ::com::mybo::gamescene::GameStatus_obj::PAUSE_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,pause,(void))

Void ClassicScene_obj::resume( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::resume")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",147)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",148)
		this->gameBoard->resume();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",149)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,resume,(void))

Void ClassicScene_obj::retry( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::retry")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",153)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameBG"),(int)0,(int)-1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",154)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",155)
		this->page->background->startAnimation();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",156)
		this->init();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",157)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",158)
		::com::mybo::data::MapFactory_obj::resetClassicModeMap();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",159)
		this->gameBoard->init(::com::mybo::data::MapFactory_obj::getClassicModeMap(this->level));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,retry,(void))

Void ClassicScene_obj::back( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::back")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",164)
		this->status = ::com::mybo::gamescene::GameStatus_obj::EXIT_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",165)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",167)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,back,(void))

Void ClassicScene_obj::gameOver( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::gameOver")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",170)
		Array< ::com::mybo::gamescene::ClassicScene > me = Array_obj< ::com::mybo::gamescene::ClassicScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",171)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->stopAll();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",173)
		this->gameBoard->motionClean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",175)
		Array< int > star = Array_obj< int >::__new().Add(::com::mybo::data::GameData_obj::getClassicReward(this->score));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",176)
		if (((star->__get((int)0) > (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",176)
			::com::mybo::data::UserData_obj::getInstance(null())->setStar((::com::mybo::data::UserData_obj::getInstance(null())->getStar() + star->__get((int)0)));
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",180)
		Array< int > bestScore = Array_obj< int >::__new().Add(::com::mybo::data::UserData_obj::getInstance(null())->getBestScore());

		HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_1,Array< int >,bestScore,Array< int >,star,Array< ::com::mybo::gamescene::ClassicScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",183)
				me->__get((int)0)->page->background->stopAnimation();
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",184)
				::com::mybo::ui::GameOverUI gameOverUI = ::com::mybo::ui::GameOverUI_obj::__new(me->__get((int)0)->score,bestScore->__get((int)0),me->__get((int)0)->level,star->__get((int)0));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",185)
				gameOverUI->menuButton->click(me->__get((int)0)->back_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",186)
				gameOverUI->retryButton->click(me->__get((int)0)->retry_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",187)
				::com::mybo::common::PopupManager_obj::getInstance()->popup(gameOverUI);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",182)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(bestScore,star,me)),(int)1000);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",190)
		if (((this->score > bestScore->__get((int)0)))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",191)
			::com::mybo::data::UserData_obj::getInstance(null())->setBestScore(this->score);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",193)
			::nmex::GameCenter_obj::getInstance()->reportScoreForCategory(this->score,HX_CSTRING("1044127"));
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",200)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("startGame"),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",201)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("classic"),HX_CSTRING("failedlevels"),::Std_obj::string(this->level),(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",203)
		if (((this->level > (int)15))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",203)
			::nmex::NativeUI_obj::rate((int)451930431);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",207)
		this->status = ::com::mybo::gamescene::GameStatus_obj::OVER_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,gameOver,(void))

Void ClassicScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("ClassicScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",212)
		this->page->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",214)
		this->gameBoard->removeEventListener(HX_CSTRING("levelComplete"),this->levelUp_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",215)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTouched"),this->onTouchBubble_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",216)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleBlast"),this->onBubbleBlast_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",217)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTapCompleted"),this->onBubbleTapComplete_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",218)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/ClassicScene.hx",220)
		::nmex::Tracker_obj::dispatchTracker();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ClassicScene_obj,destroy,(void))


ClassicScene_obj::ClassicScene_obj()
{
}

void ClassicScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ClassicScene);
	HX_MARK_MEMBER_NAME(gameBoard,"gameBoard");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(touches,"touches");
	HX_MARK_MEMBER_NAME(blastCombo,"blastCombo");
	HX_MARK_MEMBER_NAME(maxTouches,"maxTouches");
	HX_MARK_MEMBER_NAME(page,"page");
	HX_MARK_MEMBER_NAME(maskShape,"maskShape");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ClassicScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
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
		if (HX_FIELD_EQ(inName,"levelUp") ) { return levelUp_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameOver") ) { return gameOver_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameBoard") ) { return gameBoard; }
		if (HX_FIELD_EQ(inName,"maskShape") ) { return maskShape; }
		if (HX_FIELD_EQ(inName,"nextLevel") ) { return nextLevel_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"blastCombo") ) { return blastCombo; }
		if (HX_FIELD_EQ(inName,"maxTouches") ) { return maxTouches; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onBubbleBlast") ) { return onBubbleBlast_dyn(); }
		if (HX_FIELD_EQ(inName,"onTouchBubble") ) { return onTouchBubble_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sceneDidAppear") ) { return sceneDidAppear_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onBubbleTapComplete") ) { return onBubbleTapComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ClassicScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
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
		if (HX_FIELD_EQ(inName,"maskShape") ) { maskShape=inValue.Cast< ::nme::display::Shape >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"blastCombo") ) { blastCombo=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxTouches") ) { maxTouches=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ClassicScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gameBoard"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("score"));
	outFields->push(HX_CSTRING("touches"));
	outFields->push(HX_CSTRING("blastCombo"));
	outFields->push(HX_CSTRING("maxTouches"));
	outFields->push(HX_CSTRING("page"));
	outFields->push(HX_CSTRING("maskShape"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("gameBoard"),
	HX_CSTRING("status"),
	HX_CSTRING("level"),
	HX_CSTRING("score"),
	HX_CSTRING("touches"),
	HX_CSTRING("blastCombo"),
	HX_CSTRING("maxTouches"),
	HX_CSTRING("page"),
	HX_CSTRING("maskShape"),
	HX_CSTRING("init"),
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("onBubbleTapComplete"),
	HX_CSTRING("onBubbleBlast"),
	HX_CSTRING("onTouchBubble"),
	HX_CSTRING("levelUp"),
	HX_CSTRING("nextLevel"),
	HX_CSTRING("pause"),
	HX_CSTRING("resume"),
	HX_CSTRING("retry"),
	HX_CSTRING("back"),
	HX_CSTRING("gameOver"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ClassicScene_obj::__mClass;

void ClassicScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.ClassicScene"), hx::TCanCast< ClassicScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ClassicScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
