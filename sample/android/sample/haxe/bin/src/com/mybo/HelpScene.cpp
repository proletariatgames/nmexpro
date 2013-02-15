#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_HelpScene
#include <com/mybo/HelpScene.h>
#endif
#ifndef INCLUDED_com_mybo_common_Background
#include <com/mybo/common/Background.h>
#endif
#ifndef INCLUDED_com_mybo_common_Swipe
#include <com/mybo/common/Swipe.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_StartMenuScene
#include <com/mybo/menuscene/StartMenuScene.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
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

Void HelpScene_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",34)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",36)
	this->background = ::com::mybo::common::Background_obj::__new(true,false,null());
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",37)
	this->addChild(this->background);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",39)
	Array< ::nmex::display::DisplayObject > views = Array_obj< ::nmex::display::DisplayObject >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",40)
	views->push(this->facade->getBitmap(HX_CSTRING("help"),null()));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",41)
	views->push(this->facade->getBitmap(HX_CSTRING("classic"),null()));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",42)
	views->push(this->facade->getBitmap(HX_CSTRING("puzzle"),null()));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",43)
	views->push(this->facade->getBitmap(HX_CSTRING("challenge"),null()));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",45)
	Array< ::nme::display::BitmapData > indicator = Array_obj< ::nme::display::BitmapData >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",46)
	indicator->push(this->facade->getBitmap(HX_CSTRING("point1"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",47)
	indicator->push(this->facade->getBitmap(HX_CSTRING("point2"),null())->bitmapData);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",49)
	this->swipe = ::com::mybo::common::Swipe_obj::__new(views,indicator);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",50)
	this->swipe->nmeSetY((int)15);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",53)
	::haxe::Log_obj::trace(this->facade->getStageHeightInPoint(),hx::SourceInfo(HX_CSTRING("HelpScene.hx"),53,HX_CSTRING("com.mybo.HelpScene"),HX_CSTRING("new")));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",54)
	this->swipe->nmeSetY(((double(this->swipe->nmeGetY()) / double((int)480)) * this->facade->getStageHeightInPoint()));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",57)
	this->addChild(this->swipe);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",59)
	::com::mybo::framework::display::BitmapSimpleButton backBtn = ::com::mybo::framework::display::BitmapSimpleButton_obj::__new(this->facade->getBitmap(HX_CSTRING("button_back"),true),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",60)
	backBtn->nmeSetX(((double(this->facade->getStageWidthInPoint()) / double((int)2)) - (double(backBtn->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",61)
	backBtn->nmeSetY(((this->facade->getStageHeightInPoint() - backBtn->nmeGetHeight()) - (int)10));
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",62)
	this->addChild(backBtn);
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",64)
	backBtn->click(this->backToStartMenu_dyn(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",66)
	::nmex::Tracker_obj::trackPage(HX_CSTRING("help"));
}
;
	return null();
}

HelpScene_obj::~HelpScene_obj() { }

Dynamic HelpScene_obj::__CreateEmpty() { return  new HelpScene_obj; }
hx::ObjectPtr< HelpScene_obj > HelpScene_obj::__new()
{  hx::ObjectPtr< HelpScene_obj > result = new HelpScene_obj();
	result->__construct();
	return result;}

Dynamic HelpScene_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HelpScene_obj > result = new HelpScene_obj();
	result->__construct();
	return result;}

Void HelpScene_obj::backToStartMenu( ){
{
		HX_SOURCE_PUSH("HelpScene_obj::backToStartMenu")
		HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",69)
		this->facade->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HelpScene_obj,backToStartMenu,(void))

Void HelpScene_obj::destroy( ){
{
		HX_SOURCE_PUSH("HelpScene_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",74)
		this->background->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/HelpScene.hx",75)
		this->facade->unLoadResourceByFolder(HX_CSTRING("help"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HelpScene_obj,destroy,(void))


HelpScene_obj::HelpScene_obj()
{
}

void HelpScene_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HelpScene);
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(swipe,"swipe");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HelpScene_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"swipe") ) { return swipe; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backToStartMenu") ) { return backToStartMenu_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic HelpScene_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"swipe") ) { swipe=inValue.Cast< ::com::mybo::common::Swipe >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::com::mybo::common::Background >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HelpScene_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("swipe"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("background"),
	HX_CSTRING("swipe"),
	HX_CSTRING("backToStartMenu"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class HelpScene_obj::__mClass;

void HelpScene_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.HelpScene"), hx::TCanCast< HelpScene_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HelpScene_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
