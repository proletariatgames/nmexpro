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
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
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
#ifndef INCLUDED_com_mybo_gamescene_PuzzleScene
#include <com/mybo/gamescene/PuzzleScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_PuzzleMenuScene
#include <com/mybo/menuscene/PuzzleMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_ui_GameUI
#include <com/mybo/ui/GameUI.h>
#endif
#ifndef INCLUDED_com_mybo_ui_LevelClearUI
#include <com/mybo/ui/LevelClearUI.h>
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
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
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
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace gamescene{

Void PuzzleScene_obj::__construct(int inPack,int inLevel)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",50)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",54)
	this->userData = ::com::mybo::data::UserData_obj::getInstance(null());
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",55)
	this->page = ::com::mybo::ui::GameUI_obj::__new(::com::mybo::common::GameMode_obj::puzzle_dyn());
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",56)
	this->addChild(this->page);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",58)
	this->pack = inPack;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",59)
	this->level = inLevel;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",60)
	this->init();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",62)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("puzzle"));
}
;
	return null();
}

PuzzleScene_obj::~PuzzleScene_obj() { }

Dynamic PuzzleScene_obj::__CreateEmpty() { return  new PuzzleScene_obj; }
hx::ObjectPtr< PuzzleScene_obj > PuzzleScene_obj::__new(int inPack,int inLevel)
{  hx::ObjectPtr< PuzzleScene_obj > result = new PuzzleScene_obj();
	result->__construct(inPack,inLevel);
	return result;}

Dynamic PuzzleScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PuzzleScene_obj > result = new PuzzleScene_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void PuzzleScene_obj::init( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::init")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",66)
		this->map = ::com::mybo::data::MapFactory_obj::getPuzzleMap(this->pack,this->level);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",67)
		this->score = (this->userData->getPuzzleTotalScore() - this->userData->getLevelScore(this->pack,this->level));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",68)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",69)
		this->touches = this->map->solutionStep;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",70)
		this->maxTouches = this->map->solutionStep;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",71)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",72)
		this->status = ::com::mybo::gamescene::GameStatus_obj::READY_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",73)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("gameBG"),(int)0,(int)-1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",75)
		if (((this->gameBoard != null()))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",75)
			this->showTutorial();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,init,(void))

Void PuzzleScene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::sceneDidAppear")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",81)
		::String bubbleTextureID = HX_CSTRING("bubbleA");
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",82)
		if (((this->level == (int)25))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",82)
			bubbleTextureID = HX_CSTRING("bubbleB");
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",86)
		this->gameBoard = ::com::mybo::gamescene::GameBoard_obj::__new(this->map,this->page->gameBoardView,bubbleTextureID);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",87)
		this->gameBoard->addEventListener(HX_CSTRING("levelComplete"),this->levelComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",88)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTouched"),this->onTouchBubble_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",89)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleBlast"),this->onBubbleBlast_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",90)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTapCompleted"),this->onBubbleTapComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",92)
		this->page->pauseButton->click(this->pause_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",93)
		this->page->hint->click(this->showTip_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",94)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",96)
		this->showTutorial();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",97)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("puzzleEnter4"),(HX_CSTRING("pack_") + this->pack),::Std_obj::string(this->level),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,sceneDidAppear,(void))

Void PuzzleScene_obj::onBubbleTapComplete( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::onBubbleTapComplete")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",101)
		this->blastCombo = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",102)
		if (((this->touches == (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",102)
			this->gameOver();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleScene_obj,onBubbleTapComplete,(void))

Void PuzzleScene_obj::onBubbleBlast( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::onBubbleBlast")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",108)
		hx::AddEq(this->blastCombo,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",109)
		hx::AddEq(this->score,((int)2 * this->blastCombo));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",110)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleScene_obj,onBubbleBlast,(void))

Void PuzzleScene_obj::onTouchBubble( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::onTouchBubble")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",114)
		this->hideTutorial();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",115)
		hx::SubEq(this->touches,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",116)
		this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleScene_obj,onTouchBubble,(void))

Void PuzzleScene_obj::levelComplete( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::levelComplete")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",121)
		this->page->background->stopAnimation();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",122)
		::com::mybo::ui::LevelClearUI levelClearUI = ::com::mybo::ui::LevelClearUI_obj::__new(this->level);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",123)
		levelClearUI->retryButton->click(this->retry_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",124)
		levelClearUI->menuButton->click(this->back_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",125)
		levelClearUI->nextButton->click(this->nextLevel_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",126)
		::com::mybo::common::PopupManager_obj::getInstance()->popup(levelClearUI);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",128)
		int completedLevel = this->userData->getPackCompleted(this->pack);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",130)
		if (((completedLevel < this->level))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",131)
			this->userData->setPackCompleted(this->pack,this->level);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",132)
			this->userData->addStar((int)1);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",135)
		int puzzleTotalScore = this->userData->getPuzzleTotalScore();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",137)
		if (((this->score > puzzleTotalScore))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",138)
			this->userData->setLevelScore(this->pack,this->level,(this->score - puzzleTotalScore));
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",139)
			this->userData->setPuzzleTotalScore(this->score);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",140)
			this->score = (puzzleTotalScore - this->userData->getLevelScore(this->pack,this->level));
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",144)
		if (((bool((this->level == ::com::mybo::data::MapFactory_obj::getPackMapCount(this->pack))) && bool(((this->pack + (int)1) <= ::com::mybo::data::MapFactory_obj::getPuzzlePackConut()))))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",144)
			this->userData->unlockPack((this->pack + (int)1));
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",148)
		this->status = ::com::mybo::gamescene::GameStatus_obj::LEVELCOMPLETE_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleScene_obj,levelComplete,(void))

Void PuzzleScene_obj::nextLevel( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::nextLevel")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",151)
		if ((this->isPackCompleted())){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",153)
			::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",154)
			::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::PuzzleMenuScene >(),null());
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",155)
			::nmex::NativeUI_obj::rate((int)451930431);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",158)
			::nmex::GameCenter_obj::getInstance()->reportScoreForCategory(this->score,HX_CSTRING("1165567"));
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",165)
			::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",167)
			this->blastCombo = (int)0;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",168)
			hx::AddEq(this->level,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",169)
			this->map = ::com::mybo::data::MapFactory_obj::getPuzzleMap(this->pack,this->level);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",170)
			this->touches = this->map->solutionStep;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",171)
			this->maxTouches = this->touches;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",173)
			if (((this->level != (int)25))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",173)
				this->gameBoard->setBubbleTextureID(HX_CSTRING("bubbleA"));
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",175)
				this->gameBoard->setBubbleTextureID(HX_CSTRING("bubbleB"));
			}
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",179)
			this->gameBoard->init(this->map);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",181)
			this->page->updateValue(this->level,this->score,this->touches,this->maxTouches);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",182)
			this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",184)
			this->page->background->startAnimation();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",186)
			this->showTutorial();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",188)
			::nmex::Tracker_obj::trackEvent(HX_CSTRING("puzzleEnter4"),(HX_CSTRING("pack_") + this->pack),::Std_obj::string(this->level),(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,nextLevel,(void))

bool PuzzleScene_obj::isPackCompleted( ){
	HX_SOURCE_PUSH("PuzzleScene_obj::isPackCompleted")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",192)
	return (this->level >= (int)25);
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,isPackCompleted,return )

Void PuzzleScene_obj::pause( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::pause")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",197)
		this->gameBoard->pause();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",199)
		::com::mybo::ui::PauseUI pauseUI = ::com::mybo::ui::PauseUI_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",200)
		pauseUI->resumeButton->click(this->resume_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",201)
		pauseUI->menuButton->click(this->back_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",202)
		pauseUI->retryButton->click(this->retry_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",203)
		::com::mybo::common::PopupManager_obj::getInstance()->popup(pauseUI);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",205)
		this->status = ::com::mybo::gamescene::GameStatus_obj::PAUSE_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,pause,(void))

Void PuzzleScene_obj::resume( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::resume")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",209)
		this->gameBoard->resume();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",210)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",211)
		this->page->pauseButton->click(this->pause_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",212)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,resume,(void))

Void PuzzleScene_obj::retry( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::retry")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",216)
		this->page->background->startAnimation();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",217)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",219)
		this->init();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",220)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",221)
		this->gameBoard->init(this->map);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",222)
		this->status = ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,retry,(void))

Void PuzzleScene_obj::back( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::back")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",226)
		::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",227)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::PuzzleMenuScene >(),Array_obj< int >::__new().Add((int)0));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,back,(void))

Void PuzzleScene_obj::gameOver( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::gameOver")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",230)
		Array< ::com::mybo::gamescene::PuzzleScene > me = Array_obj< ::com::mybo::gamescene::PuzzleScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",231)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->stopAll();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",232)
		this->gameBoard->disable();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",233)
		this->gameBoard->motionClean();

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::gamescene::PuzzleScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",236)
				me->__get((int)0)->page->background->stopAnimation();
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",237)
				::com::mybo::ui::LevelFailedUI gameOverUI = ::com::mybo::ui::LevelFailedUI_obj::__new(me->__get((int)0)->level,null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",238)
				gameOverUI->menuButton->click(me->__get((int)0)->back_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",239)
				gameOverUI->retryButton->click(me->__get((int)0)->retry_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",240)
				gameOverUI->hitButton->click(me->__get((int)0)->showTip_dyn(),null(),null());
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",241)
				::com::mybo::common::PopupManager_obj::getInstance()->popup(gameOverUI);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",235)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(me)),(int)1000);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",244)
		this->status = ::com::mybo::gamescene::GameStatus_obj::OVER_dyn();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",245)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("startGame"),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",246)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("puzzleFailes4"),(HX_CSTRING("pack_") + this->pack),::Std_obj::string(this->level),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,gameOver,(void))

Void PuzzleScene_obj::showTip( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::showTip")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",249)
		Array< ::com::mybo::gamescene::PuzzleScene > me = Array_obj< ::com::mybo::gamescene::PuzzleScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",250)
		this->hideTutorial();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",251)
		if ((this->userData->isTipPaid(this->pack,this->level))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",251)
			this->startHintMode();
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",253)
			if (((this->userData->getStar() >= (int)10))){

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::com::mybo::gamescene::PuzzleScene >,me)
				Void run(){
{
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",256)
						me->__get((int)0)->userData->useStar((int)10);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",257)
						me->__get((int)0)->userData->setTipPaid(me->__get((int)0)->pack,me->__get((int)0)->level);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",258)
						me->__get((int)0)->startHintMode();
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",260)
						::nmex::Tracker_obj::trackEvent(HX_CSTRING("puzzleTips4"),(HX_CSTRING("pack_") + me->__get((int)0)->pack),::Std_obj::string(me->__get((int)0)->level),(int)1);
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",254)
				::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("view_solution"),null()), Dynamic(new _Function_3_1(me)),null(),null());
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",262)
				::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("get_more_star_android"),true),null(),null(),true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,showTip,(void))

Void PuzzleScene_obj::startHintMode( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::startHintMode")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",276)
		::com::mybo::gamescene::GameHint hint = ::com::mybo::gamescene::GameHint_obj::__new(this->gameBoard,this->map->solution);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",277)
		this->retry();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,startHintMode,(void))

Void PuzzleScene_obj::showTutorial( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::showTutorial")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",280)
		Array< ::com::mybo::gamescene::PuzzleScene > me = Array_obj< ::com::mybo::gamescene::PuzzleScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",282)
		if (((bool((this->pack != (int)1)) || bool((this->level > (int)21))))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",282)
			return null();
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",284)
		double stageHeight = this->facade->getStageHeightInPoint();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",286)
		if (((null() == this->tutorial))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",287)
			this->tutorial = ::nme::display::Sprite_obj::__new();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",288)
			this->tutorial->nmeSetMouseEnabled(false);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",289)
			this->hideTutorial();
		}

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::gamescene::PuzzleScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",294)
				me->__get((int)0)->facade->getStage()->addChild(me->__get((int)0)->tutorial);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",295)
				me->__get((int)0)->tutorial->nmeSetAlpha((int)0);
				struct _Function_2_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("alpha") , (int)1,false);
						return __result;
					}
				};
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",296)
				::com::mybo::framework::tweener::MTween_obj::to(me->__get((int)0)->tutorial,0.5,_Function_2_1::Block(),null());
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",293)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(me)),(int)1200);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",299)
		::nmex::display::Bitmap tip;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",300)
		::com::mybo::gamescene::GameHint hint;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",301)
		if (((this->level == (int)1))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",301)
			this->initTutorial(HX_CSTRING("p1-1"),(int)110,(int)83,this->tutorial,true);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",303)
			if (((this->level == (int)2))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",303)
				this->initTutorial(HX_CSTRING("p1-2"),(int)90,(int)83,this->tutorial,true);
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",305)
				if (((this->level == (int)3))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",305)
					this->initTutorial(HX_CSTRING("p1-3"),(int)65,(int)213,this->tutorial,true);
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",307)
					if (((this->level == (int)4))){
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",307)
						this->initTutorial(HX_CSTRING("p1-4"),(int)55,(int)310,this->tutorial,true);
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",313)
						if (((this->level == (int)5))){
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",313)
							this->initTutorial(HX_CSTRING("p1-5"),(int)30,(int)165,this->tutorial,true);
						}
						else{
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",315)
							if (((this->level == (int)6))){
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",315)
								this->initTutorial(HX_CSTRING("p1-6"),(int)105,(int)148,this->tutorial,true);
							}
							else{
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",317)
								if (((this->level == (int)7))){
									HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",317)
									this->initTutorial(HX_CSTRING("p1-7"),(int)50,(int)163,this->tutorial,true);
								}
								else{
									HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",319)
									if (((this->level == (int)8))){
										HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",319)
										this->initTutorial(HX_CSTRING("p1-8"),(int)35,(int)295,this->tutorial,false);
									}
									else{
										HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",321)
										if (((this->level == (int)9))){
											HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",321)
											this->initTutorial(HX_CSTRING("p1-9"),(int)95,(int)258,this->tutorial,false);
										}
										else{
											HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",323)
											if (((this->level == (int)10))){
												HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",323)
												this->initTutorial(HX_CSTRING("p1-10"),(int)35,(int)188,this->tutorial,false);
											}
											else{
												HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",325)
												if (((this->level == (int)11))){
													HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",325)
													this->initTutorial(HX_CSTRING("p1-11"),(int)115,(int)50,this->tutorial,false);
												}
												else{
													HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",327)
													if (((this->level == (int)12))){
														HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",327)
														this->initTutorial(HX_CSTRING("p1-8"),(int)48,(int)240,this->tutorial,false);
													}
													else{
														HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",329)
														if (((this->level == (int)13))){
															HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",329)
															this->initTutorial(HX_CSTRING("p1-13"),(int)160,(int)203,this->tutorial,false);
														}
														else{
															HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",331)
															if (((this->level == (int)14))){
																HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",331)
																this->initTutorial(HX_CSTRING("p1-14"),(int)115,(int)-14,this->tutorial,false);
															}
															else{
																HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",333)
																if (((this->level == (int)15))){
																	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",333)
																	this->initTutorial(HX_CSTRING("p1-15"),(int)95,(int)173,this->tutorial,false);
																}
																else{
																	HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",335)
																	if (((this->level == (int)17))){
																		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",335)
																		this->initTutorial(HX_CSTRING("p1-17"),(int)25,(int)-11,this->tutorial,false);
																	}
																	else{
																		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",337)
																		if (((this->level == (int)21))){
																			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",337)
																			this->initTutorial(HX_CSTRING("p1-21"),(int)60,(int)325,this->tutorial,false);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,showTutorial,(void))

Void PuzzleScene_obj::initTutorial( ::String bitmapID,double x,double y,::nme::display::Sprite container,bool hint){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::initTutorial")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",348)
		if ((hint)){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",349)
			::com::mybo::gamescene::GameHint hint1;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",350)
			hint1 = ::com::mybo::gamescene::GameHint_obj::__new(this->gameBoard,this->map->solution);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",353)
		::nmex::display::Bitmap tip;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",354)
		tip = this->facade->getBitmap(bitmapID,null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",355)
		tip->nmeSetX((this->gameBoard->nmeGetParent()->nmeGetX() + x));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",356)
		tip->nmeSetY((this->gameBoard->nmeGetParent()->nmeGetY() + y));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",358)
		container->addChild(tip);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(PuzzleScene_obj,initTutorial,(void))

Void PuzzleScene_obj::hideTutorial( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::hideTutorial")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",361)
		if (((null() != this->tutorial))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",363)
			while(((this->tutorial->nmeGetNumChildren() > (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",363)
				this->tutorial->removeChildAt((int)0);
			}
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",366)
			this->facade->getStage()->removeChild(this->tutorial);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",368)
			this->facade->unLoadResourceByFolder(HX_CSTRING("tutorial"));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,hideTutorial,(void))

Void PuzzleScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("PuzzleScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",373)
		this->page->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",375)
		this->gameBoard->removeEventListener(HX_CSTRING("levelComplete"),this->levelComplete_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",376)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTouched"),this->onTouchBubble_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",377)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleBlast"),this->onBubbleBlast_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",378)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTapCompleted"),this->onBubbleTapComplete_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",379)
		this->gameBoard->clean();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/PuzzleScene.hx",381)
		::nmex::Tracker_obj::dispatchTracker();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleScene_obj,destroy,(void))


PuzzleScene_obj::PuzzleScene_obj()
{
}

void PuzzleScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PuzzleScene);
	HX_MARK_MEMBER_NAME(gameBoard,"gameBoard");
	HX_MARK_MEMBER_NAME(map,"map");
	HX_MARK_MEMBER_NAME(pack,"pack");
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(touches,"touches");
	HX_MARK_MEMBER_NAME(maxTouches,"maxTouches");
	HX_MARK_MEMBER_NAME(blastCombo,"blastCombo");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(page,"page");
	HX_MARK_MEMBER_NAME(tutorial,"tutorial");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PuzzleScene_obj::__Field(const ::String &inName)
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
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		if (HX_FIELD_EQ(inName,"tutorial") ) { return tutorial; }
		if (HX_FIELD_EQ(inName,"gameOver") ) { return gameOver_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameBoard") ) { return gameBoard; }
		if (HX_FIELD_EQ(inName,"nextLevel") ) { return nextLevel_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxTouches") ) { return maxTouches; }
		if (HX_FIELD_EQ(inName,"blastCombo") ) { return blastCombo; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"showTutorial") ) { return showTutorial_dyn(); }
		if (HX_FIELD_EQ(inName,"initTutorial") ) { return initTutorial_dyn(); }
		if (HX_FIELD_EQ(inName,"hideTutorial") ) { return hideTutorial_dyn(); }
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
	case 15:
		if (HX_FIELD_EQ(inName,"isPackCompleted") ) { return isPackCompleted_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onBubbleTapComplete") ) { return onBubbleTapComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PuzzleScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
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
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< ::com::mybo::data::UserData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tutorial") ) { tutorial=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
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

void PuzzleScene_obj::__GetFields(Array< ::String> &outFields)
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
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("page"));
	outFields->push(HX_CSTRING("tutorial"));
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
	HX_CSTRING("userData"),
	HX_CSTRING("page"),
	HX_CSTRING("tutorial"),
	HX_CSTRING("init"),
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("onBubbleTapComplete"),
	HX_CSTRING("onBubbleBlast"),
	HX_CSTRING("onTouchBubble"),
	HX_CSTRING("levelComplete"),
	HX_CSTRING("nextLevel"),
	HX_CSTRING("isPackCompleted"),
	HX_CSTRING("pause"),
	HX_CSTRING("resume"),
	HX_CSTRING("retry"),
	HX_CSTRING("back"),
	HX_CSTRING("gameOver"),
	HX_CSTRING("showTip"),
	HX_CSTRING("startHintMode"),
	HX_CSTRING("showTutorial"),
	HX_CSTRING("initTutorial"),
	HX_CSTRING("hideTutorial"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PuzzleScene_obj::__mClass;

void PuzzleScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.PuzzleScene"), hx::TCanCast< PuzzleScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PuzzleScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
