#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
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
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_ui_StartMenuUI
#include <com/mybo/ui/StartMenuUI.h>
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
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_system_Capabilities
#include <nme/system/Capabilities.h>
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

Void StartMenuUI_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",42)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",43)
	this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",45)
	this->background = ::com::mybo::common::Background_obj::__new(null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",46)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",48)
	this->logo = this->facade->getBitmap(HX_CSTRING("index_logo_03"),true);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",49)
	this->logo->nmeSetX((((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(this->logo->nmeGetWidth()) / double((int)2))) - (int)2));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",50)
	this->logo->nmeSetY((int)27);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",51)
	this->addChild(this->logo);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",54)
	this->logo->nmeSetY(((double(this->logo->nmeGetY()) / double((int)480)) * this->facade->getStageHeightInPoint()));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",56)
	if (((bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionX() == (int)480)) && bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionY() > (int)800))))){
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",57)
		::nmex::display::Bitmap _g = this->logo;
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",57)
		_g->nmeSetY((_g->nmeGetY() + (int)10));
	}
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",61)
	this->classicButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("index_classic"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",62)
	this->puzzleButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("index_puzzle"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",63)
	this->challengeButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("index_Ch"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",65)
	this->classicButton->nmeSetX(((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(this->classicButton->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",66)
	this->classicButton->nmeSetY((int)212);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",68)
	this->classicButton->nmeSetY(((double(this->classicButton->nmeGetY()) / double((int)480)) * this->facade->getStageHeightInPoint()));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",70)
	this->puzzleButton->nmeSetX(((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(this->classicButton->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",71)
	this->puzzleButton->nmeSetY((this->classicButton->nmeGetY() + (int)57));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",72)
	this->challengeButton->nmeSetX(((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(this->classicButton->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",73)
	this->challengeButton->nmeSetY((this->puzzleButton->nmeGetY() + (int)57));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",75)
	this->addChild(this->classicButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",76)
	this->addChild(this->puzzleButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",77)
	this->addChild(this->challengeButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",80)
	this->settingContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",81)
	this->settingBG = this->facade->getBitmap(HX_CSTRING("option_bg"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",82)
	this->settingButton = ::com::mybo::common::ScaleEffectButton_obj::__new(this->facade->getBitmap(HX_CSTRING("index_option"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",83)
	this->facebook = ::com::mybo::framework::display::BitmapButton_obj::__new(this->facade->getTile(HX_CSTRING("option_facetime")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",84)
	this->twitter = ::com::mybo::framework::display::BitmapButton_obj::__new(this->facade->getTile(HX_CSTRING("option_twitter")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",85)
	this->vol = ::com::mybo::framework::display::BitmapToggleButton_obj::__new(this->facade->getTile(HX_CSTRING("option_sound")));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",86)
	this->rank = ::com::mybo::framework::display::BitmapButton_obj::__new(this->facade->getTile(HX_CSTRING("option_top")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",87)
	this->help = ::com::mybo::framework::display::BitmapButton_obj::__new(this->facade->getTile(HX_CSTRING("option_help")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",89)
	this->settingBG->nmeSetX((int)10);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",90)
	this->settingBG->nmeSetY((int)5);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",92)
	this->facebook->nmeSetX((int)20);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",93)
	this->twitter->nmeSetX((int)58);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",94)
	this->vol->nmeSetX((int)99);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",95)
	this->rank->nmeSetX((int)134);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",96)
	this->help->nmeSetX((int)170);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",98)
	this->facebook->nmeSetY((int)8);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",99)
	this->twitter->nmeSetY((int)8);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",100)
	this->vol->nmeSetY((int)8);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",101)
	this->rank->nmeSetY((int)8);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",102)
	this->help->nmeSetY((int)8);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",104)
	this->settingButton->nmeSetX((int)200);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",106)
	this->settingBG->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",107)
	this->facebook->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",108)
	this->twitter->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",109)
	this->vol->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",110)
	this->rank->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",111)
	this->help->nmeSetAlpha((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",113)
	this->addChild(this->settingContainer);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",114)
	this->settingContainer->addChild(this->settingBG);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",115)
	this->settingContainer->addChild(this->facebook);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",116)
	this->settingContainer->addChild(this->twitter);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",117)
	this->settingContainer->addChild(this->vol);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",118)
	this->settingContainer->addChild(this->rank);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",119)
	this->settingContainer->addChild(this->help);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",120)
	this->settingContainer->addChild(this->settingButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",122)
	this->settingContainer->nmeSetX(((this->facade->getStageWidthInPoint() - this->settingContainer->nmeGetWidth()) - (int)15));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",123)
	this->settingContainer->nmeSetY(((this->facade->getStageHeightInPoint() - this->settingContainer->nmeGetHeight()) - (int)9));
	HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",125)
	this->settingButton->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->showMenu_dyn(),null(),null(),null());
}
;
	return null();
}

StartMenuUI_obj::~StartMenuUI_obj() { }

Dynamic StartMenuUI_obj::__CreateEmpty() { return  new StartMenuUI_obj; }
hx::ObjectPtr< StartMenuUI_obj > StartMenuUI_obj::__new()
{  hx::ObjectPtr< StartMenuUI_obj > result = new StartMenuUI_obj();
	result->__construct();
	return result;}

Dynamic StartMenuUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StartMenuUI_obj > result = new StartMenuUI_obj();
	result->__construct();
	return result;}

Void StartMenuUI_obj::showMenu( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("StartMenuUI_obj::showMenu")
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",129)
		this->settingContainer->nmeSetMouseEnabled(false);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",131)
		::com::mybo::framework::tweener::MTween_obj::to(this->settingBG,0.1,_Function_1_1::Block(),null());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",133)
		::com::mybo::framework::tweener::MTween_obj::to(this->help,0.2,_Function_1_2::Block(),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 0.05,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",134)
		::com::mybo::framework::tweener::MTween_obj::to(this->rank,0.2,_Function_1_4::Block(),_Function_1_5::Block());
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		struct _Function_1_7{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 0.1,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",135)
		::com::mybo::framework::tweener::MTween_obj::to(this->vol,0.2,_Function_1_6::Block(),_Function_1_7::Block());
		struct _Function_1_8{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		struct _Function_1_9{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 0.15,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",136)
		::com::mybo::framework::tweener::MTween_obj::to(this->twitter,0.2,_Function_1_8::Block(),_Function_1_9::Block());
		struct _Function_1_10{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		struct _Function_1_11{
			inline static Dynamic Block( ::com::mybo::ui::StartMenuUI_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("delay") , 0.2,false);
				__result->Add(HX_CSTRING("onComplete") , __this->showComplete_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",137)
		::com::mybo::framework::tweener::MTween_obj::to(this->facebook,0.2,_Function_1_10::Block(),_Function_1_11::Block(this));
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",139)
		this->settingButton->removeEventListener(::nme::events::MouseEvent_obj::CLICK,this->showMenu_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StartMenuUI_obj,showMenu,(void))

Void StartMenuUI_obj::hideMenu( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("StartMenuUI_obj::hideMenu")
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",143)
		this->settingContainer->nmeSetMouseEnabled(false);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",145)
		::com::mybo::framework::tweener::MTween_obj::to(this->settingBG,0.1,_Function_1_1::Block(),null());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",147)
		::com::mybo::framework::tweener::MTween_obj::to(this->help,0.3,_Function_1_2::Block(),null());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",148)
		::com::mybo::framework::tweener::MTween_obj::to(this->rank,0.3,_Function_1_3::Block(),null());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",149)
		::com::mybo::framework::tweener::MTween_obj::to(this->vol,0.3,_Function_1_4::Block(),null());
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",150)
		::com::mybo::framework::tweener::MTween_obj::to(this->twitter,0.3,_Function_1_5::Block(),null());
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)0,false);
				return __result;
			}
		};
		struct _Function_1_7{
			inline static Dynamic Block( ::com::mybo::ui::StartMenuUI_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("onComplete") , __this->hideComplete_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",151)
		::com::mybo::framework::tweener::MTween_obj::to(this->facebook,0.3,_Function_1_6::Block(),_Function_1_7::Block(this));
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",153)
		this->settingButton->removeEventListener(::nme::events::MouseEvent_obj::CLICK,this->hideMenu_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StartMenuUI_obj,hideMenu,(void))

Void StartMenuUI_obj::showComplete( ){
{
		HX_SOURCE_PUSH("StartMenuUI_obj::showComplete")
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",157)
		this->settingContainer->nmeSetMouseEnabled(true);
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",158)
		this->settingButton->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->hideMenu_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuUI_obj,showComplete,(void))

Void StartMenuUI_obj::hideComplete( ){
{
		HX_SOURCE_PUSH("StartMenuUI_obj::hideComplete")
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",162)
		this->settingContainer->nmeSetMouseEnabled(true);
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",163)
		this->settingButton->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->showMenu_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuUI_obj,hideComplete,(void))

Void StartMenuUI_obj::destroy( ){
{
		HX_SOURCE_PUSH("StartMenuUI_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/ui/StartMenuUI.hx",166)
		this->background->destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StartMenuUI_obj,destroy,(void))


StartMenuUI_obj::StartMenuUI_obj()
{
}

void StartMenuUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StartMenuUI);
	HX_MARK_MEMBER_NAME(classicButton,"classicButton");
	HX_MARK_MEMBER_NAME(puzzleButton,"puzzleButton");
	HX_MARK_MEMBER_NAME(challengeButton,"challengeButton");
	HX_MARK_MEMBER_NAME(settingContainer,"settingContainer");
	HX_MARK_MEMBER_NAME(settingBG,"settingBG");
	HX_MARK_MEMBER_NAME(facebook,"facebook");
	HX_MARK_MEMBER_NAME(twitter,"twitter");
	HX_MARK_MEMBER_NAME(rank,"rank");
	HX_MARK_MEMBER_NAME(vol,"vol");
	HX_MARK_MEMBER_NAME(help,"help");
	HX_MARK_MEMBER_NAME(settingButton,"settingButton");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(logo,"logo");
	HX_MARK_MEMBER_NAME(facade,"facade");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic StartMenuUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"vol") ) { return vol; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rank") ) { return rank; }
		if (HX_FIELD_EQ(inName,"help") ) { return help; }
		if (HX_FIELD_EQ(inName,"logo") ) { return logo; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"twitter") ) { return twitter; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"facebook") ) { return facebook; }
		if (HX_FIELD_EQ(inName,"showMenu") ) { return showMenu_dyn(); }
		if (HX_FIELD_EQ(inName,"hideMenu") ) { return hideMenu_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"settingBG") ) { return settingBG; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"puzzleButton") ) { return puzzleButton; }
		if (HX_FIELD_EQ(inName,"showComplete") ) { return showComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"hideComplete") ) { return hideComplete_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"classicButton") ) { return classicButton; }
		if (HX_FIELD_EQ(inName,"settingButton") ) { return settingButton; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"challengeButton") ) { return challengeButton; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"settingContainer") ) { return settingContainer; }
	}
	return super::__Field(inName);
}

Dynamic StartMenuUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"vol") ) { vol=inValue.Cast< ::com::mybo::framework::display::BitmapToggleButton >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rank") ) { rank=inValue.Cast< ::com::mybo::framework::display::BitmapButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"help") ) { help=inValue.Cast< ::com::mybo::framework::display::BitmapButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"logo") ) { logo=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"twitter") ) { twitter=inValue.Cast< ::com::mybo::framework::display::BitmapButton >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"facebook") ) { facebook=inValue.Cast< ::com::mybo::framework::display::BitmapButton >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"settingBG") ) { settingBG=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::com::mybo::common::Background >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"puzzleButton") ) { puzzleButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"classicButton") ) { classicButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"settingButton") ) { settingButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"challengeButton") ) { challengeButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"settingContainer") ) { settingContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StartMenuUI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("classicButton"));
	outFields->push(HX_CSTRING("puzzleButton"));
	outFields->push(HX_CSTRING("challengeButton"));
	outFields->push(HX_CSTRING("settingContainer"));
	outFields->push(HX_CSTRING("settingBG"));
	outFields->push(HX_CSTRING("facebook"));
	outFields->push(HX_CSTRING("twitter"));
	outFields->push(HX_CSTRING("rank"));
	outFields->push(HX_CSTRING("vol"));
	outFields->push(HX_CSTRING("help"));
	outFields->push(HX_CSTRING("settingButton"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("logo"));
	outFields->push(HX_CSTRING("facade"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("classicButton"),
	HX_CSTRING("puzzleButton"),
	HX_CSTRING("challengeButton"),
	HX_CSTRING("settingContainer"),
	HX_CSTRING("settingBG"),
	HX_CSTRING("facebook"),
	HX_CSTRING("twitter"),
	HX_CSTRING("rank"),
	HX_CSTRING("vol"),
	HX_CSTRING("help"),
	HX_CSTRING("settingButton"),
	HX_CSTRING("background"),
	HX_CSTRING("logo"),
	HX_CSTRING("facade"),
	HX_CSTRING("showMenu"),
	HX_CSTRING("hideMenu"),
	HX_CSTRING("showComplete"),
	HX_CSTRING("hideComplete"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class StartMenuUI_obj::__mClass;

void StartMenuUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.StartMenuUI"), hx::TCanCast< StartMenuUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StartMenuUI_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
