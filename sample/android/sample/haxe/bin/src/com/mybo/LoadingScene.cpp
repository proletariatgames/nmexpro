#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_LoadingScene
#include <com/mybo/LoadingScene.h>
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
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundType
#include <com/mybo/framework/sound/SoundType.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_PuzzleScene
#include <com/mybo/gamescene/PuzzleScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#include <com/mybo/menuscene/StartMenuScene.h>
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

Void LoadingScene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",30)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",32)
	::nmex::display::Bitmap logo = this->facade->getBitmap(HX_CSTRING("loading_logo"),null());
	HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",33)
	this->addChild(logo);
	HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",36)
	logo->nmeSetHeight(this->facade->getStageHeightInPoint());
}
;
	return null();
}

LoadingScene_obj::~LoadingScene_obj() { }

Dynamic LoadingScene_obj::__CreateEmpty() { return  new LoadingScene_obj; }
hx::ObjectPtr< LoadingScene_obj > LoadingScene_obj::__new()
{  hx::ObjectPtr< LoadingScene_obj > result = new LoadingScene_obj();
	result->__construct();
	return result;}

Dynamic LoadingScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoadingScene_obj > result = new LoadingScene_obj();
	result->__construct();
	return result;}

Void LoadingScene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("LoadingScene_obj::sceneDidAppear")
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",40)
		Array< ::com::mybo::LoadingScene > me = Array_obj< ::com::mybo::LoadingScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::mybo::LoadingScene >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",42)
				::nmex::display::Bitmap loading = me->__get((int)0)->facade->getBitmap(HX_CSTRING("loading"),null());
				HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",43)
				me->__get((int)0)->addChild(loading);
				HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",45)
				loading->nmeSetHeight(me->__get((int)0)->facade->getStageHeightInPoint());
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",41)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(me)),(int)500);
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",49)
		::haxe::Timer_obj::delay(this->loadResource_dyn(),(int)1000);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LoadingScene_obj,sceneDidAppear,(void))

Void LoadingScene_obj::loadResource( ){
{
		HX_SOURCE_PUSH("LoadingScene_obj::loadResource")
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",54)
		::String rootPath = HX_CSTRING("/sound/");
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",55)
		::String extention = HX_CSTRING(".mp4");
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",58)
		rootPath = HX_CSTRING("");
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",59)
		extention = HX_CSTRING(".ogg");
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",66)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("titleBG"),((rootPath + HX_CSTRING("title_ver5")) + extention),::com::mybo::framework::sound::SoundType_obj::MUSIC_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",67)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("gameBG"),((rootPath + HX_CSTRING("level_ver5")) + extention),::com::mybo::framework::sound::SoundType_obj::MUSIC_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",70)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("bubble1"),((rootPath + HX_CSTRING("bubble")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",71)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("bubble2"),((rootPath + HX_CSTRING("poring")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",72)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("bubble3"),((rootPath + HX_CSTRING("bubble")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",73)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("bubble4"),((rootPath + HX_CSTRING("poring2")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",74)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("bubble5"),((rootPath + HX_CSTRING("poring3")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",75)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("bubble6"),((rootPath + HX_CSTRING("poring4")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",77)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("grow4"),((rootPath + HX_CSTRING("sfx_bubble_or_grow_1")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",78)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("grow3"),((rootPath + HX_CSTRING("sfx_bubble_or_grow_2")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",79)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("grow2"),((rootPath + HX_CSTRING("sfx_bubble_pu_grow")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",80)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("grow1"),((rootPath + HX_CSTRING("sfx_bubble_gr_grow")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",82)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("levelFailed"),((rootPath + HX_CSTRING("sfx_low_score")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",83)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("gameover"),((rootPath + HX_CSTRING("sfx_high_score")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",85)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("levelUp1"),((rootPath + HX_CSTRING("sfx_level_up_01")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",86)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("levelUp2"),((rootPath + HX_CSTRING("sfx_level_up_02")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",87)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("levelUp3"),((rootPath + HX_CSTRING("sfx_level_up_03")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",88)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("levelUp4"),((rootPath + HX_CSTRING("sfx_level_up_04")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",89)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("levelUp5"),((rootPath + HX_CSTRING("sfx_level_up_05")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",91)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("modeSelect"),((rootPath + HX_CSTRING("ui_mode_select")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",95)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("startGame"),((rootPath + HX_CSTRING("ui_game_start")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",97)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("clearTitle"),((rootPath + HX_CSTRING("clear")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",98)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("clearStar"),((rootPath + HX_CSTRING("seastar")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",100)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("boardRaise"),((rootPath + HX_CSTRING("sfx_board_raise")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",101)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("countSFX"),((rootPath + HX_CSTRING("sfx_count")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",102)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("crabSFX"),((rootPath + HX_CSTRING("sfx_crab")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",103)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("chestSFX"),((rootPath + HX_CSTRING("sfx_chest")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",105)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("useStar"),((rootPath + HX_CSTRING("sfx_use_star")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",106)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("newScore"),((rootPath + HX_CSTRING("newscore")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",108)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->addSound(HX_CSTRING("buttonSFX"),((rootPath + HX_CSTRING("sfx_button")) + extention),::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",110)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->loadByType(::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",114)
		this->facade->loadResourceByFolder(HX_CSTRING("blowEffects"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",115)
		this->facade->loadResourceByFolder(HX_CSTRING("button"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",119)
		this->facade->loadResourceByFolder(HX_CSTRING("pack"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",120)
		this->facade->loadResourceByFolder(HX_CSTRING("IAP"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",121)
		this->facade->loadResourceByFolder(HX_CSTRING("index"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",122)
		this->facade->loadResourceByFolder(HX_CSTRING("num"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",123)
		this->facade->loadResourceByFolder(HX_CSTRING("pangxie"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",124)
		this->facade->loadResourceByFolder(HX_CSTRING("pp"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",128)
		::nmex::Tracker_obj::startTracker(HX_CSTRING("UA-19790825-15"),(int)-1);
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",130)
		if ((::com::mybo::data::UserData_obj::getInstance(null())->isFirstRun())){
			HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",130)
			this->facade->run(hx::ClassOf< ::com::mybo::gamescene::PuzzleScene >(),Array_obj< int >::__new().Add((int)1).Add((int)1));
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",132)
			::com::mybo::framework::core::Facade_obj::getInstance()->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LoadingScene_obj,loadResource,(void))

Void LoadingScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("LoadingScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",138)
		this->facade->destroyResource(HX_CSTRING("loading_logo"));
		HX_SOURCE_POS("../../../src/com/mybo/LoadingScene.hx",139)
		this->facade->destroyResource(HX_CSTRING("loading"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LoadingScene_obj,destroy,(void))


LoadingScene_obj::LoadingScene_obj()
{
}

void LoadingScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoadingScene);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic LoadingScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"loadResource") ) { return loadResource_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sceneDidAppear") ) { return sceneDidAppear_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic LoadingScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void LoadingScene_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("loadResource"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class LoadingScene_obj::__mClass;

void LoadingScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.LoadingScene"), hx::TCanCast< LoadingScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LoadingScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
