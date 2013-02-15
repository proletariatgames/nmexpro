#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Alert
#include <com/mybo/common/Alert.h>
#endif
#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
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
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_PuzzleScene
#include <com/mybo/gamescene/PuzzleScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_LevelSelector
#include <com/mybo/menuscene/LevelSelector.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_PackageSelector
#include <com/mybo/menuscene/PackageSelector.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_PuzzleMenuScene
#include <com/mybo/menuscene/PuzzleMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#include <com/mybo/menuscene/StartMenuScene.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_UserStar
#include <com/mybo/menuscene/UserStar.h>
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
namespace menuscene{

Void PuzzleMenuScene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",40)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",42)
	this->background = ::com::mybo::common::Background_obj::__new(null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",43)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",45)
	double stageWidth = this->facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",46)
	double stageHeight = this->facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",48)
	this->content = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",49)
	this->addChild(this->content);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",51)
	this->title = this->facade->getBitmap(HX_CSTRING("packs_title"),null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",52)
	this->title->nmeSetX(((double(stageWidth) / double((int)2)) - (double(this->title->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",53)
	this->title->nmeSetY((int)20);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",54)
	this->addChild(this->title);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",57)
	this->title->nmeSetY(((double(this->title->nmeGetY()) / double((int)480)) * this->facade->getStageHeightInPoint()));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",60)
	this->backBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_back"),true));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",61)
	this->backBtn->nmeSetX(((double(stageWidth) / double((int)2)) - (int)125));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",62)
	this->backBtn->nmeSetY((stageHeight - (int)65));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",63)
	this->addChild(this->backBtn);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",65)
	this->backBtn->click(this->backToStartMenu_dyn(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",67)
	this->showPackSelector();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",70)
	this->userStar = ::com::mybo::menuscene::UserStar_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",71)
	this->userStar->nmeSetX(((this->facade->getStageWidthInPoint() - this->userStar->nmeGetWidth()) - (int)13));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",72)
	this->userStar->nmeSetY(((this->facade->getStageHeightInPoint() - this->userStar->nmeGetHeight()) - (int)20));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",73)
	this->addChild(this->userStar);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",75)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("puzzleMenu"));
}
;
	return null();
}

PuzzleMenuScene_obj::~PuzzleMenuScene_obj() { }

Dynamic PuzzleMenuScene_obj::__CreateEmpty() { return  new PuzzleMenuScene_obj; }
hx::ObjectPtr< PuzzleMenuScene_obj > PuzzleMenuScene_obj::__new()
{  hx::ObjectPtr< PuzzleMenuScene_obj > result = new PuzzleMenuScene_obj();
	result->__construct();
	return result;}

Dynamic PuzzleMenuScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PuzzleMenuScene_obj > result = new PuzzleMenuScene_obj();
	result->__construct();
	return result;}

Void PuzzleMenuScene_obj::back( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::back")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",78)
		if (((this->packSelector == null()))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",79)
			this->backToPackSelector();
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",81)
			this->backToStartMenu();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,back,(void))

Void PuzzleMenuScene_obj::sceneDidAppear( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::sceneDidAppear")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,sceneDidAppear,(void))

Void PuzzleMenuScene_obj::backToStartMenu( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::backToStartMenu")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",90)
		this->facade->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,backToStartMenu,(void))

Void PuzzleMenuScene_obj::onPackSelect( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::onPackSelect")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",94)
		Array< ::com::mybo::menuscene::PuzzleMenuScene > me = Array_obj< ::com::mybo::menuscene::PuzzleMenuScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",96)
		this->selectPack = e->data->__get((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",98)
		if ((::com::mybo::data::UserData_obj::getInstance(null())->isPackUnlocked(this->selectPack))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",98)
			this->runLevelSelector();
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",101)
			Array< ::com::mybo::data::UserData > userData = Array_obj< ::com::mybo::data::UserData >::__new().Add(::com::mybo::data::UserData_obj::getInstance(null()));
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",102)
			if (((userData->__get((int)0)->getStar() >= (int)50))){

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,Array< ::com::mybo::data::UserData >,userData,Array< ::com::mybo::menuscene::PuzzleMenuScene >,me)
				Void run(){
{
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",104)
						userData->__get((int)0)->useStar((int)50);
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",105)
						userData->__get((int)0)->unlockNextPack();
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",106)
						me->__get((int)0)->userStar->update();
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",107)
						me->__get((int)0)->runLevelSelector();
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",102)
				::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("buy_pack"),null()), Dynamic(new _Function_3_1(userData,me)),null(),null());
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",109)
				::com::mybo::common::Alert_obj::show(this->facade->getBitmap(HX_CSTRING("unlock_pack_android"),true),null(),null(),true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleMenuScene_obj,onPackSelect,(void))

Void PuzzleMenuScene_obj::runLevelSelector( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::runLevelSelector")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",121)
		Array< ::com::mybo::menuscene::PuzzleMenuScene > me = Array_obj< ::com::mybo::menuscene::PuzzleMenuScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",122)
		this->packSelector->removeEventListener(HX_CSTRING("packSelected"),this->onPackSelect_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",124)
		this->content->nmeSetAlpha((int)1);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( Array< ::com::mybo::menuscene::PuzzleMenuScene > &me){
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::com::mybo::menuscene::PuzzleMenuScene >,me)
				Void run(){
{
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",127)
						me->__get((int)0)->content->removeChild(me->__get((int)0)->packSelector);
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",128)
						me->__get((int)0)->packSelector = null();
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",130)
						me->__get((int)0)->showLevelSelector(me->__get((int)0)->selectPack);
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",132)
						me->__get((int)0)->backBtn->click(me->__get((int)0)->backToPackSelector_dyn(),null(),null());
						struct _Function_3_1{
							inline static Dynamic Block( ){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("alpha") , (int)1,false);
								return __result;
							}
						};
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",134)
						::com::mybo::framework::tweener::MTween_obj::to(me->__get((int)0)->content,0.2,_Function_3_1::Block(),null());
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				__result->Add(HX_CSTRING("onComplete") ,  Dynamic(new _Function_2_1(me)),true);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",125)
		::com::mybo::framework::tweener::MTween_obj::to(this->content,0.2,_Function_1_1::Block(),_Function_1_2::Block(me));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,runLevelSelector,(void))

Void PuzzleMenuScene_obj::backToPackSelector( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::backToPackSelector")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",138)
		Array< ::com::mybo::menuscene::PuzzleMenuScene > me = Array_obj< ::com::mybo::menuscene::PuzzleMenuScene >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",139)
		this->levelSelector->removeEventListener(HX_CSTRING("levelSelected"),this->onLevelSelected_dyn(),null());
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( Array< ::com::mybo::menuscene::PuzzleMenuScene > &me){
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::com::mybo::menuscene::PuzzleMenuScene >,me)
				Void run(){
{
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",143)
						me->__get((int)0)->content->removeChild(me->__get((int)0)->levelSelector);
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",144)
						me->__get((int)0)->levelSelector = null();
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",146)
						me->__get((int)0)->showPackSelector();
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",147)
						me->__get((int)0)->backBtn->click(me->__get((int)0)->backToStartMenu_dyn(),null(),null());
						struct _Function_3_1{
							inline static Dynamic Block( ){
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("alpha") , (int)1,false);
								return __result;
							}
						};
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",149)
						::com::mybo::framework::tweener::MTween_obj::to(me->__get((int)0)->content,0.2,_Function_3_1::Block(),null());
					}
					return null();
				}
				HX_END_LOCAL_FUNC0((void))

				__result->Add(HX_CSTRING("onComplete") ,  Dynamic(new _Function_2_1(me)),true);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",141)
		::com::mybo::framework::tweener::MTween_obj::to(this->content,0.2,_Function_1_1::Block(),_Function_1_2::Block(me));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,backToPackSelector,(void))

Void PuzzleMenuScene_obj::showLevelSelector( int id){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::showLevelSelector")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",154)
		this->levelSelector = ::com::mybo::menuscene::LevelSelector_obj::__new(id);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",155)
		this->levelSelector->nmeSetX((((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(this->levelSelector->nmeGetWidth()) / double((int)2))) + (int)2));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",156)
		this->levelSelector->nmeSetY((int)86);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",157)
		this->content->addChild(this->levelSelector);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",160)
		this->levelSelector->nmeSetY((((double(this->levelSelector->nmeGetY()) / double((int)480)) * this->facade->getStageHeightInPoint()) + (int)10));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",163)
		this->levelSelector->addEventListener(HX_CSTRING("levelSelected"),this->onLevelSelected_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleMenuScene_obj,showLevelSelector,(void))

Void PuzzleMenuScene_obj::showPackSelector( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::showPackSelector")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",167)
		this->packSelector = ::com::mybo::menuscene::PackageSelector_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",168)
		this->packSelector->nmeSetX(((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(this->packSelector->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",169)
		this->packSelector->nmeSetY((int)80);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",170)
		this->content->addChild(this->packSelector);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",173)
		this->packSelector->nmeSetY((((double(this->packSelector->nmeGetY()) / double((int)480)) * this->facade->getStageHeightInPoint()) + (int)10));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",176)
		this->packSelector->addEventListener(HX_CSTRING("packSelected"),this->onPackSelect_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,showPackSelector,(void))

Void PuzzleMenuScene_obj::onLevelSelected( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::onLevelSelected")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",180)
		this->selectLevel = e->data->__get((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",181)
		this->facade->run(hx::ClassOf< ::com::mybo::gamescene::PuzzleScene >(),Array_obj< int >::__new().Add(this->selectPack).Add(this->selectLevel));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PuzzleMenuScene_obj,onLevelSelected,(void))

Void PuzzleMenuScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("PuzzleMenuScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",185)
		this->background->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PuzzleMenuScene.hx",186)
		this->facade->unLoadResourceByFolder(HX_CSTRING("packs"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PuzzleMenuScene_obj,destroy,(void))


PuzzleMenuScene_obj::PuzzleMenuScene_obj()
{
}

void PuzzleMenuScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PuzzleMenuScene);
	HX_MARK_MEMBER_NAME(selectPack,"selectPack");
	HX_MARK_MEMBER_NAME(selectLevel,"selectLevel");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(backBtn,"backBtn");
	HX_MARK_MEMBER_NAME(packSelector,"packSelector");
	HX_MARK_MEMBER_NAME(levelSelector,"levelSelector");
	HX_MARK_MEMBER_NAME(content,"content");
	HX_MARK_MEMBER_NAME(userStar,"userStar");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PuzzleMenuScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"back") ) { return back_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"backBtn") ) { return backBtn; }
		if (HX_FIELD_EQ(inName,"content") ) { return content; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userStar") ) { return userStar; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"selectPack") ) { return selectPack; }
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"selectLevel") ) { return selectLevel; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"packSelector") ) { return packSelector; }
		if (HX_FIELD_EQ(inName,"onPackSelect") ) { return onPackSelect_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"levelSelector") ) { return levelSelector; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sceneDidAppear") ) { return sceneDidAppear_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backToStartMenu") ) { return backToStartMenu_dyn(); }
		if (HX_FIELD_EQ(inName,"onLevelSelected") ) { return onLevelSelected_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"runLevelSelector") ) { return runLevelSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"showPackSelector") ) { return showPackSelector_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"showLevelSelector") ) { return showLevelSelector_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backToPackSelector") ) { return backToPackSelector_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PuzzleMenuScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"backBtn") ) { backBtn=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"content") ) { content=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userStar") ) { userStar=inValue.Cast< ::com::mybo::menuscene::UserStar >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"selectPack") ) { selectPack=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::com::mybo::common::Background >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"selectLevel") ) { selectLevel=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"packSelector") ) { packSelector=inValue.Cast< ::com::mybo::menuscene::PackageSelector >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"levelSelector") ) { levelSelector=inValue.Cast< ::com::mybo::menuscene::LevelSelector >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PuzzleMenuScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("selectPack"));
	outFields->push(HX_CSTRING("selectLevel"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("backBtn"));
	outFields->push(HX_CSTRING("packSelector"));
	outFields->push(HX_CSTRING("levelSelector"));
	outFields->push(HX_CSTRING("content"));
	outFields->push(HX_CSTRING("userStar"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("selectPack"),
	HX_CSTRING("selectLevel"),
	HX_CSTRING("title"),
	HX_CSTRING("background"),
	HX_CSTRING("backBtn"),
	HX_CSTRING("packSelector"),
	HX_CSTRING("levelSelector"),
	HX_CSTRING("content"),
	HX_CSTRING("userStar"),
	HX_CSTRING("back"),
	HX_CSTRING("sceneDidAppear"),
	HX_CSTRING("backToStartMenu"),
	HX_CSTRING("onPackSelect"),
	HX_CSTRING("runLevelSelector"),
	HX_CSTRING("backToPackSelector"),
	HX_CSTRING("showLevelSelector"),
	HX_CSTRING("showPackSelector"),
	HX_CSTRING("onLevelSelected"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PuzzleMenuScene_obj::__mClass;

void PuzzleMenuScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.PuzzleMenuScene"), hx::TCanCast< PuzzleMenuScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PuzzleMenuScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
