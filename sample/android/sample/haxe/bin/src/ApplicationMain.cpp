#include <hxcpp.h>

#ifndef INCLUDED_ApplicationMain
#include <ApplicationMain.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
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
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_StageScaleMode
#include <nme/display/StageScaleMode.h>
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
#ifndef INCLUDED_nme_text_TextField
#include <nme/text/TextField.h>
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
#ifndef INCLUDED_nmex_NativeUI
#include <nmex/NativeUI.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif

Void ApplicationMain_obj::__construct()
{
{
	HX_SOURCE_POS("ApplicationMain.hx",10)
	::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetScaleMode(::nme::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_SOURCE_POS("ApplicationMain.hx",12)
	::nme::text::TextField text = ::nme::text::TextField_obj::__new();
	HX_SOURCE_POS("ApplicationMain.hx",13)
	text->nmeSetTextColor((int)16777215);
	HX_SOURCE_POS("ApplicationMain.hx",14)
	text->nmeSetText(HX_CSTRING("Hello nmex!"));
	HX_SOURCE_POS("ApplicationMain.hx",15)
	text->nmeSetWidth((int)320);
	HX_SOURCE_POS("ApplicationMain.hx",16)
	text->nmeSetHTMLText(HX_CSTRING("<font size='36'>Hello nmex!</font>"));
	HX_SOURCE_POS("ApplicationMain.hx",18)
	text->nmeSetSelectable(false);
	HX_SOURCE_POS("ApplicationMain.hx",20)
	text->nmeSetX(((double(::nme::system::Capabilities_obj::nmeGetScreenResolutionX()) / double((int)2)) - (double(text->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("ApplicationMain.hx",21)
	text->nmeSetY(((double(::nme::system::Capabilities_obj::nmeGetScreenResolutionY()) / double((int)2)) - (double(text->nmeGetHeight()) / double((int)2))));
	HX_SOURCE_POS("ApplicationMain.hx",23)
	::nme::Lib_obj::nmeGetCurrent()->addChild(text);
	HX_SOURCE_POS("ApplicationMain.hx",25)
	::nmex::GameCenter_obj::getInstance()->authenticateLocalUser();
	HX_SOURCE_POS("ApplicationMain.hx",27)
	::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->onClick_dyn(),null(),null(),null());
	HX_SOURCE_POS("ApplicationMain.hx",29)
	::nmex::AD_obj::showAd(HX_CSTRING("a14cb4262caea88"),null(),null(),null(),null());
}
;
	return null();
}

ApplicationMain_obj::~ApplicationMain_obj() { }

Dynamic ApplicationMain_obj::__CreateEmpty() { return  new ApplicationMain_obj; }
hx::ObjectPtr< ApplicationMain_obj > ApplicationMain_obj::__new()
{  hx::ObjectPtr< ApplicationMain_obj > result = new ApplicationMain_obj();
	result->__construct();
	return result;}

Dynamic ApplicationMain_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ApplicationMain_obj > result = new ApplicationMain_obj();
	result->__construct();
	return result;}

Void ApplicationMain_obj::onClick( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("ApplicationMain_obj::onClick")
		HX_SOURCE_POS("ApplicationMain.hx",32)
		::nmex::NativeUI_obj::showAlert(HX_CSTRING("nmex"),HX_CSTRING("Please try other APIs by yourself!"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ApplicationMain_obj,onClick,(void))

Void ApplicationMain_obj::main( ){
{
		HX_SOURCE_PUSH("ApplicationMain_obj::main")

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(){
{
				HX_SOURCE_POS("ApplicationMain.hx",63)
				::ApplicationMain_obj::__new();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("ApplicationMain.hx",45)
		::nme::Lib_obj::create( Dynamic(new _Function_1_1()),(int)320,(int)480,(int)60,(int)0,(int(::nme::Lib_obj::HARDWARE) | int(::nme::Lib_obj::RESIZABLE)),HX_CSTRING("Bubble Blast"),HX_CSTRING("com.mybogame.bbx2"),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(ApplicationMain_obj,main,(void))

Dynamic ApplicationMain_obj::getAsset( ::String inName){
	HX_SOURCE_PUSH("ApplicationMain_obj::getAsset")
	HX_SOURCE_POS("ApplicationMain.hx",76)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ApplicationMain_obj,getAsset,return )


ApplicationMain_obj::ApplicationMain_obj()
{
}

void ApplicationMain_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ApplicationMain);
	HX_MARK_END_CLASS();
}

Dynamic ApplicationMain_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAsset") ) { return getAsset_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ApplicationMain_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ApplicationMain_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	HX_CSTRING("getAsset"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onClick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ApplicationMain_obj::__mClass;

void ApplicationMain_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("ApplicationMain"), hx::TCanCast< ApplicationMain_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ApplicationMain_obj::__boot()
{
}

