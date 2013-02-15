#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
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
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Back
#include <com/mybo/framework/tweener/easing/Back.h>
#endif
#ifndef INCLUDED_com_mybo_ui_PauseUI
#include <com/mybo/ui/PauseUI.h>
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
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace ui{

Void PauseUI_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",25)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",27)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",28)
	this->nmeGetGraphics()->beginFill((int)928102,0.91);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",29)
	this->nmeGetGraphics()->drawRect((int)0,(int)0,facade->getStageWidthInPoint(),facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",30)
	this->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",32)
	this->title = facade->getBitmap(HX_CSTRING("pause_bar"),null());
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",34)
	this->resumeButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_continu"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",35)
	this->menuButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_menu"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",36)
	this->retryButton = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_retry"),true));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",38)
	this->resumeButton->nmeSetX((((double(facade->getStageWidthInPoint()) / double((int)2)) - (double(this->resumeButton->nmeGetWidth()) / double((int)2))) - (int)95));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",39)
	this->menuButton->nmeSetX(((double(facade->getStageWidthInPoint()) / double((int)2)) - (double(this->menuButton->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",40)
	this->retryButton->nmeSetX((((double(facade->getStageWidthInPoint()) / double((int)2)) - (double(this->retryButton->nmeGetWidth()) / double((int)2))) + (int)95));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",42)
	this->resumeButton->nmeSetY((int)80);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",43)
	this->menuButton->nmeSetY((int)80);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",44)
	this->retryButton->nmeSetY((int)80);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",47)
	this->menuContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",48)
	this->menuContainer->addChild(this->title);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",49)
	this->menuContainer->addChild(this->resumeButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",50)
	this->menuContainer->addChild(this->menuButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",51)
	this->menuContainer->addChild(this->retryButton);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",53)
	this->menuContainer->nmeSetX((int)0);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",54)
	this->menuContainer->nmeSetY(facade->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",55)
	this->addChild(this->menuContainer);
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",57)
	double targetY = ((double(facade->getStageHeightInPoint()) / double((int)2)) - (double(this->menuContainer->nmeGetHeight()) / double((int)2)));
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",59)
	this->nmeSetAlpha((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("alpha") , (int)1,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",60)
	::com::mybo::framework::tweener::MTween_obj::to(hx::ObjectPtr<OBJ_>(this),0.1,_Function_1_1::Block(),null());
	struct _Function_1_2{
		inline static Dynamic Block( double &targetY){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , targetY,false);
			return __result;
		}
	};
	struct _Function_1_3{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.1,false);
			__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Back_obj::easeOut_dyn(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",62)
	::com::mybo::framework::tweener::MTween_obj::to(this->menuContainer,0.3,_Function_1_2::Block(targetY),_Function_1_3::Block());

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_4)
	Void run(){
{
			HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",64)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("boardRaise"),null(),null());
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("../../../src/com/mybo/ui/PauseUI.hx",64)
	::haxe::Timer_obj::delay( Dynamic(new _Function_1_4()),(int)100);
}
;
	return null();
}

PauseUI_obj::~PauseUI_obj() { }

Dynamic PauseUI_obj::__CreateEmpty() { return  new PauseUI_obj; }
hx::ObjectPtr< PauseUI_obj > PauseUI_obj::__new()
{  hx::ObjectPtr< PauseUI_obj > result = new PauseUI_obj();
	result->__construct();
	return result;}

Dynamic PauseUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PauseUI_obj > result = new PauseUI_obj();
	result->__construct();
	return result;}


PauseUI_obj::PauseUI_obj()
{
}

void PauseUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PauseUI);
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(resumeButton,"resumeButton");
	HX_MARK_MEMBER_NAME(menuButton,"menuButton");
	HX_MARK_MEMBER_NAME(retryButton,"retryButton");
	HX_MARK_MEMBER_NAME(menuContainer,"menuContainer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PauseUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"menuButton") ) { return menuButton; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { return retryButton; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resumeButton") ) { return resumeButton; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"menuContainer") ) { return menuContainer; }
	}
	return super::__Field(inName);
}

Dynamic PauseUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"menuButton") ) { menuButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"retryButton") ) { retryButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resumeButton") ) { resumeButton=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"menuContainer") ) { menuContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PauseUI_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("resumeButton"));
	outFields->push(HX_CSTRING("menuButton"));
	outFields->push(HX_CSTRING("retryButton"));
	outFields->push(HX_CSTRING("menuContainer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("title"),
	HX_CSTRING("resumeButton"),
	HX_CSTRING("menuButton"),
	HX_CSTRING("retryButton"),
	HX_CSTRING("menuContainer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PauseUI_obj::__mClass;

void PauseUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.ui.PauseUI"), hx::TCanCast< PauseUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PauseUI_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace ui
