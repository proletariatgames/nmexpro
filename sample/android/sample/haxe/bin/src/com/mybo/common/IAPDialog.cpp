#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_IAPDialog
#include <com/mybo/common/IAPDialog.h>
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
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
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
#ifndef INCLUDED_nmex_InAppPurchase
#include <nmex/InAppPurchase.h>
#endif
#ifndef INCLUDED_nmex_NXObject
#include <nmex/NXObject.h>
#endif
#ifndef INCLUDED_nmex_NativeUI
#include <nmex/NativeUI.h>
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

Void IAPDialog_obj::__construct(Dynamic successHandle)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",28)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",31)
	return null();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",34)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",35)
	double stageWidth = facade->getStageWidthInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",36)
	double stageHeight = facade->getStageHeightInPoint();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",38)
	this->nmeGetGraphics()->beginFill((int)928102,0.91);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",39)
	this->nmeGetGraphics()->drawRect((int)0,(int)0,stageWidth,stageHeight);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",40)
	this->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",42)
	this->successHandleFun = successHandle;
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",44)
	this->motionContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",45)
	this->addChild(this->motionContainer);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",46)
	::nmex::display::Bitmap background = facade->getBitmap(HX_CSTRING("board"),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",47)
	this->motionContainer->addChild(background);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",49)
	::com::mybo::framework::display::BitmapButton buyButtonA = ::com::mybo::framework::display::BitmapButton_obj::__new(facade->getTile(HX_CSTRING("buy_35")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",50)
	::com::mybo::framework::display::BitmapButton buyButtonB = ::com::mybo::framework::display::BitmapButton_obj::__new(facade->getTile(HX_CSTRING("buy_125")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",51)
	::com::mybo::framework::display::BitmapButton buyButtonC = ::com::mybo::framework::display::BitmapButton_obj::__new(facade->getTile(HX_CSTRING("buy_265")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",52)
	::com::mybo::framework::display::BitmapButton buyButtonD = ::com::mybo::framework::display::BitmapButton_obj::__new(facade->getTile(HX_CSTRING("buy_1000")),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",54)
	buyButtonA->nmeSetX((((double(stageWidth) / double((int)2)) - buyButtonA->nmeGetWidth()) - (int)15));
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",55)
	buyButtonC->nmeSetX(buyButtonA->nmeGetX());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",56)
	buyButtonB->nmeSetX(((double(stageWidth) / double((int)2)) + (int)15));
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",57)
	buyButtonD->nmeSetX(buyButtonB->nmeGetX());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",59)
	buyButtonA->nmeSetY((int)30);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",60)
	buyButtonB->nmeSetY((int)30);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",61)
	buyButtonC->nmeSetY((int)120);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",62)
	buyButtonD->nmeSetY((int)120);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",64)
	buyButtonA->click(this->buy_dyn(),Array_obj< ::String >::__new().Add(HX_CSTRING("com.mybogame.bubbleblast.35star")),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",65)
	buyButtonB->click(this->buy_dyn(),Array_obj< ::String >::__new().Add(HX_CSTRING("com.mybogame.bubbleblast.125star")),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",66)
	buyButtonC->click(this->buy_dyn(),Array_obj< ::String >::__new().Add(HX_CSTRING("com.mybogame.bubbleblast.265star")),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",67)
	buyButtonD->click(this->buy_dyn(),Array_obj< ::String >::__new().Add(HX_CSTRING("com.mybogame.bubbleblast.1000star")),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",69)
	this->motionContainer->addChild(buyButtonA);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",70)
	this->motionContainer->addChild(buyButtonB);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",71)
	this->motionContainer->addChild(buyButtonC);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",72)
	this->motionContainer->addChild(buyButtonD);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",74)
	::com::mybo::framework::display::BitmapSimpleButton cancelBtn = ::com::mybo::common::ScaleEffectButton_obj::__new(facade->getBitmap(HX_CSTRING("cancel"),true));
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",75)
	cancelBtn->nmeSetX(((double(stageWidth) / double((int)2)) - (double(cancelBtn->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",76)
	cancelBtn->nmeSetY((int)200);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",77)
	cancelBtn->click(this->onCancel_dyn(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",78)
	this->motionContainer->addChild(cancelBtn);
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",80)
	::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",82)
	this->motionContainer->nmeSetY(stageHeight);
	struct _Function_1_1{
		inline static Dynamic Block( double &stageHeight,::com::mybo::common::IAPDialog_obj *__this){
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
	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",83)
	::com::mybo::framework::tweener::MTween_obj::to(this->motionContainer,0.3,_Function_1_1::Block(stageHeight,this),_Function_1_2::Block());

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
	Void run(){
{
			HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",85)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("boardRaise"),null(),null());
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",85)
	::haxe::Timer_obj::delay( Dynamic(new _Function_1_3()),(int)100);
}
;
	return null();
}

IAPDialog_obj::~IAPDialog_obj() { }

Dynamic IAPDialog_obj::__CreateEmpty() { return  new IAPDialog_obj; }
hx::ObjectPtr< IAPDialog_obj > IAPDialog_obj::__new(Dynamic successHandle)
{  hx::ObjectPtr< IAPDialog_obj > result = new IAPDialog_obj();
	result->__construct(successHandle);
	return result;}

Dynamic IAPDialog_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IAPDialog_obj > result = new IAPDialog_obj();
	result->__construct(inArgs[0]);
	return result;}

Void IAPDialog_obj::buy( ::String id){
{
		HX_SOURCE_PUSH("IAPDialog_obj::buy")
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",92)
		if ((!(::nmex::Device_obj::networkAvailable()))){
			HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",92)
			::nmex::NativeUI_obj::showAlert(HX_CSTRING("ERROR"),HX_CSTRING("Network is unavailable."));
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",96)
		::nmex::NativeUI_obj::showSystemLoadingView();
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",98)
		this->currentProductID = id;
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",99)
		::nmex::InAppPurchase iap = ::nmex::InAppPurchase_obj::getInstance();
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",100)
		iap->addEventListener(HX_CSTRING("inAppPurchaseSuccess"),this->onSuccess_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",101)
		iap->addEventListener(HX_CSTRING("inAppPurchaseFail"),this->onFail_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",102)
		iap->addEventListener(HX_CSTRING("inAppPurchaseCancel"),this->onFail_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",104)
		iap->purchase(this->currentProductID);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(IAPDialog_obj,buy,(void))

Void IAPDialog_obj::onCancel( ){
{
		HX_SOURCE_PUSH("IAPDialog_obj::onCancel")
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",108)
		::nmex::NativeUI_obj::hideSystemLoadingView();
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",109)
		::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->removeChild(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(IAPDialog_obj,onCancel,(void))

Void IAPDialog_obj::onFail( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("IAPDialog_obj::onFail")
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",113)
		::nmex::NativeUI_obj::hideSystemLoadingView();
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",114)
		::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->removeChild(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(IAPDialog_obj,onFail,(void))

Void IAPDialog_obj::onSuccess( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("IAPDialog_obj::onSuccess")
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",119)
		::nmex::NativeUI_obj::hideSystemLoadingView();
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",121)
		::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->removeChild(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",123)
		if (((this->currentProductID == HX_CSTRING("com.mybogame.bubbleblast.35star")))){
			HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",123)
			::com::mybo::data::UserData_obj::getInstance(null())->addStar((int)35);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",125)
			if (((this->currentProductID == HX_CSTRING("com.mybogame.bubbleblast.125star")))){
				HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",125)
				::com::mybo::data::UserData_obj::getInstance(null())->addStar((int)125);
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",127)
				if (((this->currentProductID == HX_CSTRING("com.mybogame.bubbleblast.265star")))){
					HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",127)
					::com::mybo::data::UserData_obj::getInstance(null())->addStar((int)265);
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",129)
					if (((this->currentProductID == HX_CSTRING("com.mybogame.bubbleblast.1000star")))){
						HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",129)
						::com::mybo::data::UserData_obj::getInstance(null())->addStar((int)1000);
					}
				}
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",133)
		if (((this->successHandleFun_dyn() != null()))){
			HX_SOURCE_POS("../../../src/com/mybo/common/IAPDialog.hx",133)
			this->successHandleFun();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(IAPDialog_obj,onSuccess,(void))

::String IAPDialog_obj::PRODUCT_ID_BUY_35;

::String IAPDialog_obj::PRODUCT_ID_BUY_125;

::String IAPDialog_obj::PRODUCT_ID_BUY_265;

::String IAPDialog_obj::PRODUCT_ID_BUY_1000;


IAPDialog_obj::IAPDialog_obj()
{
}

void IAPDialog_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IAPDialog);
	HX_MARK_MEMBER_NAME(currentProductID,"currentProductID");
	HX_MARK_MEMBER_NAME(successHandleFun,"successHandleFun");
	HX_MARK_MEMBER_NAME(motionContainer,"motionContainer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic IAPDialog_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buy") ) { return buy_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onFail") ) { return onFail_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onCancel") ) { return onCancel_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onSuccess") ) { return onSuccess_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"motionContainer") ) { return motionContainer; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"currentProductID") ) { return currentProductID; }
		if (HX_FIELD_EQ(inName,"successHandleFun") ) { return successHandleFun; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_35") ) { return PRODUCT_ID_BUY_35; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_125") ) { return PRODUCT_ID_BUY_125; }
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_265") ) { return PRODUCT_ID_BUY_265; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_1000") ) { return PRODUCT_ID_BUY_1000; }
	}
	return super::__Field(inName);
}

Dynamic IAPDialog_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"motionContainer") ) { motionContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"currentProductID") ) { currentProductID=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"successHandleFun") ) { successHandleFun=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_35") ) { PRODUCT_ID_BUY_35=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_125") ) { PRODUCT_ID_BUY_125=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_265") ) { PRODUCT_ID_BUY_265=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"PRODUCT_ID_BUY_1000") ) { PRODUCT_ID_BUY_1000=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IAPDialog_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentProductID"));
	outFields->push(HX_CSTRING("motionContainer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PRODUCT_ID_BUY_35"),
	HX_CSTRING("PRODUCT_ID_BUY_125"),
	HX_CSTRING("PRODUCT_ID_BUY_265"),
	HX_CSTRING("PRODUCT_ID_BUY_1000"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("currentProductID"),
	HX_CSTRING("successHandleFun"),
	HX_CSTRING("motionContainer"),
	HX_CSTRING("buy"),
	HX_CSTRING("onCancel"),
	HX_CSTRING("onFail"),
	HX_CSTRING("onSuccess"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IAPDialog_obj::PRODUCT_ID_BUY_35,"PRODUCT_ID_BUY_35");
	HX_MARK_MEMBER_NAME(IAPDialog_obj::PRODUCT_ID_BUY_125,"PRODUCT_ID_BUY_125");
	HX_MARK_MEMBER_NAME(IAPDialog_obj::PRODUCT_ID_BUY_265,"PRODUCT_ID_BUY_265");
	HX_MARK_MEMBER_NAME(IAPDialog_obj::PRODUCT_ID_BUY_1000,"PRODUCT_ID_BUY_1000");
};

Class IAPDialog_obj::__mClass;

void IAPDialog_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.IAPDialog"), hx::TCanCast< IAPDialog_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IAPDialog_obj::__boot()
{
	hx::Static(PRODUCT_ID_BUY_35) = HX_CSTRING("com.mybogame.bubbleblast.35star");
	hx::Static(PRODUCT_ID_BUY_125) = HX_CSTRING("com.mybogame.bubbleblast.125star");
	hx::Static(PRODUCT_ID_BUY_265) = HX_CSTRING("com.mybogame.bubbleblast.265star");
	hx::Static(PRODUCT_ID_BUY_1000) = HX_CSTRING("com.mybogame.bubbleblast.1000star");
}

} // end namespace com
} // end namespace mybo
} // end namespace common
