#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_HelpScene
#include <com/mybo/HelpScene.h>
#endif
#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
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
#ifndef INCLUDED_com_mybo_framework_display_BitmapButton
#include <com/mybo/framework/display/BitmapButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapToggleButton
#include <com/mybo/framework/display/BitmapToggleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_ClassicScene
#include <com/mybo/gamescene/ClassicScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_MasterMenuScene
#include <com/mybo/menuscene/MasterMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_PuzzleMenuScene
#include <com/mybo/menuscene/PuzzleMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#include <com/mybo/menuscene/StartMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_ui_StartMenuUI
#include <com/mybo/ui/StartMenuUI.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
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
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
#ifndef INCLUDED_nmex_AD
#include <nmex/AD.h>
#endif
#ifndef INCLUDED_nmex_GameCenter
#include <nmex/GameCenter.h>
#endif
#ifndef INCLUDED_nmex_NXObject
#include <nmex/NXObject.h>
#endif
#ifndef INCLUDED_nmex_Tracker
#include <nmex/Tracker.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace menuscene{

Void StartMenuScene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",29)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",30)
	this->startPage = ::com::mybo::ui::StartMenuUI_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",31)
	this->addChild(this->startPage);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",33)
	if (((::com::mybo::data::UserData_obj::getInstance(null())->getMusic() == true))){
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",34)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("titleBG"),(int)0,(int)-1);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",35)
		this->startPage->vol->toggle((int)0);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",37)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->disableMusic();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",38)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->disableSFX();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",39)
		this->startPage->vol->toggle((int)1);
	}
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",42)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("startMenu"));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",45)
	::nmex::AD_obj::showAd(HX_CSTRING("a14faa14de9f235"),(int)0,(int)-1,(int)0,(int)1);
}
;
	return null();
}

StartMenuScene_obj::~StartMenuScene_obj() { }

Dynamic StartMenuScene_obj::__CreateEmpty() { return  new StartMenuScene_obj; }
hx::ObjectPtr< StartMenuScene_obj > StartMenuScene_obj::__new()
{  hx::ObjectPtr< StartMenuScene_obj > result = new StartMenuScene_obj();
	result->__construct();
	return result;}

Dynamic StartMenuScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StartMenuScene_obj > result = new StartMenuScene_obj();
	result->__construct();
	return result;}

Void StartMenuScene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::sceneDidAppear")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",56)
		this->startPage->classicButton->click(this->runClassic_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",57)
		this->startPage->puzzleButton->click(this->runPuzzle_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",58)
		this->startPage->challengeButton->click(this->runMaster_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",60)
		this->startPage->vol->click(this->toggleVol_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",62)
		this->startPage->rank->click(this->showLeaderBoard_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",63)
		this->startPage->facebook->click(this->facebook_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",64)
		this->startPage->twitter->click(this->twitter_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",65)
		this->startPage->help->click(this->runHelp_dyn(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,sceneDidAppear,(void))

Void StartMenuScene_obj::runClassic( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::runClassic")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",69)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::gamescene::ClassicScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,runClassic,(void))

Void StartMenuScene_obj::runPuzzle( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::runPuzzle")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",73)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::PuzzleMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,runPuzzle,(void))

Void StartMenuScene_obj::runMaster( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::runMaster")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",77)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::MasterMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,runMaster,(void))

Void StartMenuScene_obj::runHelp( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::runHelp")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",81)
		::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::HelpScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,runHelp,(void))

Void StartMenuScene_obj::showLeaderBoard( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::showLeaderBoard")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",85)
		::nmex::GameCenter_obj::getInstance()->showLeaderboardForCategory(HX_CSTRING("1044127"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,showLeaderBoard,(void))

Void StartMenuScene_obj::moreGame( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::moreGame")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",96)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("moregame"),HX_CSTRING("bbx"),HX_CSTRING(""),(int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",99)
		::nme::Lib_obj::getURL(::nme::net::URLRequest_obj::__new(HX_CSTRING("http://tetrismobile.com#bbx_android")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,moreGame,(void))

Void StartMenuScene_obj::facebook( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::facebook")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",106)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("facebook"),HX_CSTRING("bbx"),HX_CSTRING(""),(int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",107)
		::nme::Lib_obj::getURL(::nme::net::URLRequest_obj::__new(HX_CSTRING("http://www.facebook.com/bubbleblastmybo")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,facebook,(void))

Void StartMenuScene_obj::twitter( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::twitter")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",111)
		::nmex::Tracker_obj::trackEvent(HX_CSTRING("twitter"),HX_CSTRING("bbx"),HX_CSTRING(""),(int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",112)
		::nme::Lib_obj::getURL(::nme::net::URLRequest_obj::__new(HX_CSTRING("http://twitter.com/bubbleblastmybo")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,twitter,(void))

Void StartMenuScene_obj::toggleVol( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::toggleVol")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",115)
		if (((::com::mybo::data::UserData_obj::getInstance(null())->getMusic() == true))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",117)
			::com::mybo::data::UserData_obj::getInstance(null())->setMusic(false);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",118)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->disableMusic();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",119)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->disableSFX();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",120)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->stopAll();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",121)
			this->startPage->vol->toggle((int)1);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",123)
			::com::mybo::data::UserData_obj::getInstance(null())->setMusic(true);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",124)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->enableMusic();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",125)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->enableSFX();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",126)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->stopAll();
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",127)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("titleBG"),(int)0,(int)-1);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",128)
			this->startPage->vol->toggle((int)0);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,toggleVol,(void))

Void StartMenuScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("StartMenuScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",149)
		this->startPage->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/StartMenuScene.hx",150)
		this->facade->unLoadResourceByFolder(HX_CSTRING("index"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuScene_obj,destroy,(void))


StartMenuScene_obj::StartMenuScene_obj()
{
}

void StartMenuScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StartMenuScene);
	HX_MARK_MEMBER_NAME(startPage,"startPage");
	HX_MARK_MEMBER_NAME(packSelected,"packSelected");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic StartMenuScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"runHelp") ) { return runHelp_dyn(); }
		if (HX_FIELD_EQ(inName,"twitter") ) { return twitter_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"moreGame") ) { return moreGame_dyn(); }
		if (HX_FIELD_EQ(inName,"facebook") ) { return facebook_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startPage") ) { return startPage; }
		if (HX_FIELD_EQ(inName,"runPuzzle") ) { return runPuzzle_dyn(); }
		if (HX_FIELD_EQ(inName,"runMaster") ) { return runMaster_dyn(); }
		if (HX_FIELD_EQ(inName,"toggleVol") ) { return toggleVol_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"runClassic") ) { return runClassic_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"packSelected") ) { return packSelected; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sceneDidAppear") ) { return sceneDidAppear_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"showLeaderBoard") ) { return showLeaderBoard_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StartMenuScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"startPage") ) { startPage=inValue.Cast< ::com::mybo::ui::StartMenuUI >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"packSelected") ) { packSelected=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StartMenuScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("startPage"));
	outFields->push(HX_CSTRING("packSelected"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("startPage"),
	HX_CSTRING("packSelected"),
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("runClassic"),
	HX_CSTRING("runPuzzle"),
	HX_CSTRING("runMaster"),
	HX_CSTRING("runHelp"),
	HX_CSTRING("showLeaderBoard"),
	HX_CSTRING("moreGame"),
	HX_CSTRING("facebook"),
	HX_CSTRING("twitter"),
	HX_CSTRING("toggleVol"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class StartMenuScene_obj::__mClass;

void StartMenuScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.StartMenuScene"), hx::TCanCast< StartMenuScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StartMenuScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
