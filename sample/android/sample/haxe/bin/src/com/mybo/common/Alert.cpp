#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Alert
#include <com/mybo/common/Alert.h>
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
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
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
namespace common{

Void Alert_obj::__construct(::nmex::display::Bitmap bitmap,Dynamic yesHandle,Dynamic noHandle,Dynamic useOK)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",22)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",24)
	this->yesHandleFun = yesHandle;
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",25)
	this->noHandleFun = noHandle;
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",27)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",28)
	double stageWidth = facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",29)
	double stageHeight = facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",31)
	this->motionContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",33)
	this->nmeGetGraphics()->beginFill((int)928102,0.91);
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",34)
	this->nmeGetGraphics()->drawRect((int)0,(int)0,stageWidth,stageHeight);
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",35)
	this->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",38)
	this->motionContainer->addChild(bitmap);
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",40)
	if ((useOK)){
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",41)
		this->yesBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_ok"),true));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",42)
		this->yesBtn->nmeSetX(((double(this->motionContainer->nmeGetWidth()) / double((int)2)) - (double(this->yesBtn->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",43)
		this->yesBtn->nmeSetY((this->motionContainer->nmeGetHeight() - (int)100));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",45)
		this->yesBtn->click(this->onYes_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",46)
		this->motionContainer->addChild(this->yesBtn);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",48)
		this->yesBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_yes"),true));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",49)
		this->noBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("button_no"),true));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",50)
		this->yesBtn->nmeSetX(((double(this->motionContainer->nmeGetWidth()) / double((int)2)) - (int)85));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",51)
		this->yesBtn->nmeSetY((this->motionContainer->nmeGetHeight() - (int)85));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",52)
		this->noBtn->nmeSetX(((double(this->motionContainer->nmeGetWidth()) / double((int)2)) + (int)25));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",53)
		this->noBtn->nmeSetY((this->motionContainer->nmeGetHeight() - (int)85));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",54)
		this->yesBtn->click(this->onYes_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",55)
		this->noBtn->click(this->onNo_dyn(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",56)
		this->motionContainer->addChild(this->yesBtn);
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",57)
		this->motionContainer->addChild(this->noBtn);
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",60)
	this->motionContainer->nmeSetY(stageHeight);
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",61)
	this->addChild(this->motionContainer);
	struct _Function_1_1{
		inline static Dynamic Block( double &stageHeight,::com::mybo::common::Alert_obj *__this){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , ((double(stageHeight) / double((int)2)) - (double(__this->motionContainer->nmeGetHeight()) / double((int)2))),false);
			return __result;
		}
	};
	struct _Function_1_2{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Back_obj::easeOut_dyn(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",63)
	::com::mybo::framework::tweener::MTween_obj::to(this->motionContainer,0.3,_Function_1_1::Block(stageHeight,this),_Function_1_2::Block());
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",65)
	::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->addChild(hx::ObjectPtr<OBJ_>(this));

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
	Void run(){
{
			HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",67)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("boardRaise"),null(),null());
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",67)
	::haxe::Timer_obj::delay( Dynamic(new _Function_1_3()),(int)100);
}
;
	return null();
}

Alert_obj::~Alert_obj() { }

Dynamic Alert_obj::__CreateEmpty() { return  new Alert_obj; }
hx::ObjectPtr< Alert_obj > Alert_obj::__new(::nmex::display::Bitmap bitmap,Dynamic yesHandle,Dynamic noHandle,Dynamic useOK)
{  hx::ObjectPtr< Alert_obj > result = new Alert_obj();
	result->__construct(bitmap,yesHandle,noHandle,useOK);
	return result;}

Dynamic Alert_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Alert_obj > result = new Alert_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Alert_obj::onYes( ){
{
		HX_SOURCE_PUSH("Alert_obj::onYes")
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",73)
		::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->removeChild(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",74)
		if (((this->yesHandleFun_dyn() != null()))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",74)
			this->yesHandleFun();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Alert_obj,onYes,(void))

Void Alert_obj::onNo( ){
{
		HX_SOURCE_PUSH("Alert_obj::onNo")
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",80)
		::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->removeChild(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",81)
		if (((this->noHandleFun_dyn() != null()))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",81)
			this->noHandleFun();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Alert_obj,onNo,(void))

::com::mybo::common::Alert Alert_obj::show( ::nmex::display::Bitmap bitmap,Dynamic yesHandle,Dynamic noHandle,Dynamic useOK){
	HX_SOURCE_PUSH("Alert_obj::show")
	HX_SOURCE_POS("../../../src/com/mybo/common/Alert.hx",86)
	return ::com::mybo::common::Alert_obj::__new(bitmap,yesHandle,noHandle,useOK);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Alert_obj,show,return )


Alert_obj::Alert_obj()
{
}

void Alert_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Alert);
	HX_MARK_MEMBER_NAME(yesBtn,"yesBtn");
	HX_MARK_MEMBER_NAME(noBtn,"noBtn");
	HX_MARK_MEMBER_NAME(yesHandleFun,"yesHandleFun");
	HX_MARK_MEMBER_NAME(noHandleFun,"noHandleFun");
	HX_MARK_MEMBER_NAME(motionContainer,"motionContainer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Alert_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		if (HX_FIELD_EQ(inName,"onNo") ) { return onNo_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"noBtn") ) { return noBtn; }
		if (HX_FIELD_EQ(inName,"onYes") ) { return onYes_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"yesBtn") ) { return yesBtn; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"noHandleFun") ) { return noHandleFun; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"yesHandleFun") ) { return yesHandleFun; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"motionContainer") ) { return motionContainer; }
	}
	return super::__Field(inName);
}

Dynamic Alert_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"noBtn") ) { noBtn=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"yesBtn") ) { yesBtn=inValue.Cast< ::com::mybo::common::ScaleEffectButton >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"noHandleFun") ) { noHandleFun=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"yesHandleFun") ) { yesHandleFun=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"motionContainer") ) { motionContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Alert_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("yesBtn"));
	outFields->push(HX_CSTRING("noBtn"));
	outFields->push(HX_CSTRING("motionContainer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("show"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("yesBtn"),
	HX_CSTRING("noBtn"),
	HX_CSTRING("yesHandleFun"),
	HX_CSTRING("noHandleFun"),
	HX_CSTRING("motionContainer"),
	HX_CSTRING("onYes"),
	HX_CSTRING("onNo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Alert_obj::__mClass;

void Alert_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.Alert"), hx::TCanCast< Alert_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Alert_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace common
