#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameMode
#include <com/mybo/common/GameMode.h>
#endif
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
#ifndef INCLUDED_com_mybo_ui_GameUI
#include <com/mybo/ui/GameUI.h>
#endif
#ifndef INCLUDED_com_mybo_ui_TouchLeftBar
#include <com/mybo/ui/TouchLeftBar.h>
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
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace ui{

Void GameUI_obj::__construct(::com::mybo::common::GameMode gameMode)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",38)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",40)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",42)
	this->background = ::com::mybo::common::Background_obj::__new(true,null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",43)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",45)
	this->gameBoardView = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",46)
	this->gameBoardView->nmeSetX((int)10);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",47)
	this->gameBoardView->nmeSetY(((int)50 + (double(((facade->getStageHeightInPoint() - (int)480))) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",49)
	this->effectLayer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",51)
	this->addChild(this->effectLayer);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",52)
	this->addChild(this->gameBoardView);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",55)
	this->uiLayer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",56)
	double stageWidth = facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",57)
	double stageHeight = facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",58)
	this->uiLayer->nmeGetGraphics()->beginFill((int)6247,0.52);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",59)
	this->uiLayer->nmeGetGraphics()->drawRect((int)0,(int)0,stageWidth,(int)30);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",60)
	this->uiLayer->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",62)
	this->uiLayer->nmeGetGraphics()->beginFill((int)6247,0.52);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",63)
	this->uiLayer->nmeGetGraphics()->drawRect((int)0,(stageHeight - (int)30),stageWidth,(int)30);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",64)
	this->uiLayer->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",67)
	this->pauseButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("game_pause"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",70)
	this->uiLayer->addChild(this->pauseButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",72)
	::nmex::display::Bitmap scoreLable = facade->getBitmap(HX_CSTRING("game_score"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",73)
	scoreLable->nmeSetX((int)100);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",74)
	scoreLable->nmeSetY((int)9);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",75)
	this->score = ::com::mybo::framework::display::BitmapNumber_obj::__new(facade->getTile(HX_CSTRING("num3")),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",76)
	this->score->nmeSetX((int)148);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",77)
	this->score->nmeSetY((int)7);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",78)
	if (((gameMode != ::com::mybo::common::GameMode_obj::master_dyn()))){
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",79)
		this->uiLayer->addChild(scoreLable);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",80)
		this->uiLayer->addChild(this->score);
	}
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",83)
	::nmex::display::Bitmap levelLabel = facade->getBitmap(HX_CSTRING("game_level"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",84)
	levelLabel->nmeSetX((int)240);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",85)
	levelLabel->nmeSetY((int)10);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",86)
	this->level = ::com::mybo::framework::display::BitmapNumber_obj::__new(facade->getTile(HX_CSTRING("num6")),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",87)
	this->level->nmeSetX((int)287);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",88)
	this->level->nmeSetY((int)7);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",89)
	if (((gameMode != ::com::mybo::common::GameMode_obj::master_dyn()))){
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",90)
		this->uiLayer->addChild(levelLabel);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",91)
		this->uiLayer->addChild(this->level);
	}
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",94)
	this->touchLeft = ::com::mybo::ui::TouchLeftBar_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",95)
	this->touchLeft->nmeSetX(((double(stageWidth) / double((int)2)) - (double(this->touchLeft->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",96)
	this->touchLeft->nmeSetY((stageHeight - (int)29));
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",97)
	this->uiLayer->addChild(this->touchLeft);
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",99)
	if (((gameMode != ::com::mybo::common::GameMode_obj::classic_dyn()))){
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",100)
		this->touchLeft->nmeSetX((int)10);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",101)
		this->hint = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("game_hint"),true));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",102)
		this->hint->nmeSetX((stageWidth - this->hint->nmeGetWidth()));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",103)
		this->hint->nmeSetY((stageHeight - this->hint->nmeGetHeight()));
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",104)
		this->uiLayer->addChild(this->hint);
	}
	HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",107)
	this->addChild(this->uiLayer);
}
;
	return null();
}

GameUI_obj::~GameUI_obj() { }

Dynamic GameUI_obj::__CreateEmpty() { return  new GameUI_obj; }
hx::ObjectPtr< GameUI_obj > GameUI_obj::__new(::com::mybo::common::GameMode gameMode)
{  hx::ObjectPtr< GameUI_obj > result = new GameUI_obj();
	result->__construct(gameMode);
	return result;}

Dynamic GameUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameUI_obj > result = new GameUI_obj();
	result->__construct(inArgs[0]);
	return result;}

Void GameUI_obj::updateValue( int level,int score,int touches,double maxTouches){
{
		HX_SOURCE_PUSH("GameUI_obj::updateValue")
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",111)
		this->level->drawNumber(level);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",112)
		this->score->drawNumber(score);
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",113)
		this->touchLeft->update(touches,maxTouches);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GameUI_obj,updateValue,(void))

Void GameUI_obj::destroy( ){
{
		HX_SOURCE_PUSH("GameUI_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/ui/GameUI.hx",116)
		this->background->destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameUI_obj,destroy,(void))


GameUI_obj::GameUI_obj()
{
}

void GameUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameUI);
	HX_MARK_MEMBER_NAME(pauseButton,"pauseButton");
	HX_MARK_MEMBER_NAME(hint,"hint");
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(touchLeft,"touchLeft");
	HX_MARK_MEMBER_NAME(gameBoardView,"gameBoardView");
	HX_MARK_MEMBER_NAME(effectLayer,"effectLayer");
	HX_MARK_MEMBER_NAME(uiLayer,"uiLayer");
	HX_MARK_MEMBER_NAME(background,"background");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic GameUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"hint") ) { return hint; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		if (HX_FIELD_EQ(inName,"score") ) { return score; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"uiLayer") ) { return uiLayer; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"touchLeft") ) { return touchLeft; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pauseButton") ) { return pauseButton; }
		if (HX_FIELD_EQ(inName,"effectLayer") ) { return effectLayer; }
		if (HX_FIELD_EQ(inName,"updateValue") ) { return updateValue_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"gameBoardView") ) { return gameBoardView; }
	}
	return super::__Field(inName);
}

Dynamic GameUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"hint") ) { hint=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
		if (HX_FIELD_EQ(inName,"score") ) { score=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"uiLayer") ) { uiLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"touchLeft") ) { touchLeft=inValue.Cast< ::com::mybo::ui::TouchLeftBar >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::com::mybo::common::Background >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pauseButton") ) { pauseButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"effectLayer") ) { effectLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"gameBoardView") ) { gameBoardView=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameUI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pauseButton"));
	outFields->push(HX_CSTRING("hint"));
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("score"));
	outFields->push(HX_CSTRING("touchLeft"));
	outFields->push(HX_CSTRING("gameBoardView"));
	outFields->push(HX_CSTRING("effectLayer"));
	outFields->push(HX_CSTRING("uiLayer"));
	outFields->push(HX_CSTRING("background"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pauseButton"),
	HX_CSTRING("hint"),
	HX_CSTRING("level"),
	HX_CSTRING("score"),
	HX_CSTRING("touchLeft"),
	HX_CSTRING("gameBoardView"),
	HX_CSTRING("effectLayer"),
	HX_CSTRING("uiLayer"),
	HX_CSTRING("background"),
	HX_CSTRING("updateValue"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class GameUI_obj::__mClass;

void GameUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.GameUI"), hx::TCanCast< GameUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameUI_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
