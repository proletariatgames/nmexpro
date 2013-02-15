#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_com_mybo_Application
#include <com/mybo/Application.h>
#endif
#ifndef INCLUDED_com_mybo_HelpScene
#include <com/mybo/HelpScene.h>
#endif
#ifndef INCLUDED_com_mybo_LoadingScene
#include <com/mybo/LoadingScene.h>
#endif
#ifndef INCLUDED_com_mybo_common_PopupManager
#include <com/mybo/common/PopupManager.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Controller
#include <com/mybo/framework/core/Controller.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_ClassicScene
#include <com/mybo/gamescene/ClassicScene.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameHint
#include <com/mybo/gamescene/GameHint.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameStatus
#include <com/mybo/gamescene/GameStatus.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_MasterScene
#include <com/mybo/gamescene/MasterScene.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_PuzzleScene
#include <com/mybo/gamescene/PuzzleScene.h>
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
#ifndef INCLUDED_nme_events_KeyboardEvent
#include <nme/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{

Void Application_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/Application.hx",31)
	this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/Application.hx",32)
	::String resourcePath = HX_CSTRING("");
	HX_SOURCE_POS("../../../src/com/mybo/Application.hx",34)
	if ((::nmex::Device_obj::isRetina())){
		HX_SOURCE_POS("../../../src/com/mybo/Application.hx",34)
		this->facade->initResource(resourcePath,(resourcePath + HX_CSTRING("RD_Retina.xml")));
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/Application.hx",36)
		this->facade->initResource(resourcePath,(resourcePath + HX_CSTRING("RD_HVGA.xml")));
	}
	HX_SOURCE_POS("../../../src/com/mybo/Application.hx",46)
	this->facade->run(hx::ClassOf< ::com::mybo::LoadingScene >(),null());
	HX_SOURCE_POS("../../../src/com/mybo/Application.hx",48)
	this->facade->getStage()->addEventListener(::nme::events::KeyboardEvent_obj::KEY_DOWN,this->onAndroidBack_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/Application.hx",49)
	this->facade->getStage()->addEventListener(::nme::events::Event_obj::ACTIVATE,this->onDeactive_dyn(),null(),null(),null());
}
;
	return null();
}

Application_obj::~Application_obj() { }

Dynamic Application_obj::__CreateEmpty() { return  new Application_obj; }
hx::ObjectPtr< Application_obj > Application_obj::__new()
{  hx::ObjectPtr< Application_obj > result = new Application_obj();
	result->__construct();
	return result;}

Dynamic Application_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Application_obj > result = new Application_obj();
	result->__construct();
	return result;}

Void Application_obj::onAndroidBack( ::nme::events::KeyboardEvent e){
{
		HX_SOURCE_PUSH("Application_obj::onAndroidBack")
		HX_SOURCE_POS("../../../src/com/mybo/Application.hx",53)
		if (((e->keyCode == (int)27))){
			HX_SOURCE_POS("../../../src/com/mybo/Application.hx",56)
			::String scene = ::Type_obj::getClassName(::Type_obj::getClass(this->facade->getController()->currentScene));
			HX_SOURCE_POS("../../../src/com/mybo/Application.hx",58)
			if (((bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::LoadingScene >()))) || bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >())))))){
				HX_SOURCE_POS("../../../src/com/mybo/Application.hx",58)
				::nme::Lib_obj::forceClose();
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/Application.hx",61)
				if (((bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::menuscene::MasterMenuScene >()))) || bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::HelpScene >())))))){
					HX_SOURCE_POS("../../../src/com/mybo/Application.hx",61)
					this->facade->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/Application.hx",63)
					if (((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::menuscene::PuzzleMenuScene >())))){
						HX_SOURCE_POS("../../../src/com/mybo/Application.hx",65)
						Dynamic puzzleScene = this->facade->getController()->currentScene;
						HX_SOURCE_POS("../../../src/com/mybo/Application.hx",66)
						puzzleScene->__Field(HX_CSTRING("back"))();
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/Application.hx",67)
						if (((bool((bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::ClassicScene >()))) || bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::PuzzleScene >()))))) || bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::MasterScene >())))))){
							HX_SOURCE_POS("../../../src/com/mybo/Application.hx",69)
							Dynamic dynamicScene = this->facade->getController()->currentScene;
							HX_SOURCE_POS("../../../src/com/mybo/Application.hx",71)
							if (((bool((dynamicScene->__Field(HX_CSTRING("status")) == ::com::mybo::gamescene::GameStatus_obj::LEVELCOMPLETE_dyn())) || bool((dynamicScene->__Field(HX_CSTRING("status")) == ::com::mybo::gamescene::GameStatus_obj::OVER_dyn()))))){
								HX_SOURCE_POS("../../../src/com/mybo/Application.hx",72)
								::com::mybo::common::PopupManager_obj::getInstance()->cleanup();
								HX_SOURCE_POS("../../../src/com/mybo/Application.hx",73)
								::String name = ::Type_obj::getClassName(::Type_obj::getClass(this->facade->getController()->currentScene));
								HX_SOURCE_POS("../../../src/com/mybo/Application.hx",74)
								if (((name == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::MasterScene >())))){
									HX_SOURCE_POS("../../../src/com/mybo/Application.hx",74)
									this->facade->run(hx::ClassOf< ::com::mybo::menuscene::MasterMenuScene >(),null());
								}
								else{
									HX_SOURCE_POS("../../../src/com/mybo/Application.hx",76)
									if (((name == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::PuzzleScene >())))){
										HX_SOURCE_POS("../../../src/com/mybo/Application.hx",76)
										this->facade->run(hx::ClassOf< ::com::mybo::menuscene::PuzzleMenuScene >(),null());
									}
									else{
										HX_SOURCE_POS("../../../src/com/mybo/Application.hx",78)
										this->facade->run(hx::ClassOf< ::com::mybo::menuscene::StartMenuScene >(),null());
									}
								}
							}
							else{
								HX_SOURCE_POS("../../../src/com/mybo/Application.hx",81)
								if (((bool((dynamicScene->__Field(HX_CSTRING("status")) != ::com::mybo::gamescene::GameStatus_obj::PAUSE_dyn())) && bool(!(::com::mybo::gamescene::GameHint_obj::running))))){
									HX_SOURCE_POS("../../../src/com/mybo/Application.hx",82)
									dynamicScene->__Field(HX_CSTRING("pause"))();
								}
								else{
									HX_SOURCE_POS("../../../src/com/mybo/Application.hx",84)
									dynamicScene->__Field(HX_CSTRING("resume"))();
								}
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Application_obj,onAndroidBack,(void))

Void Application_obj::onDeactive( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("Application_obj::onDeactive")
		HX_SOURCE_POS("../../../src/com/mybo/Application.hx",95)
		::String scene = ::Type_obj::getClassName(::Type_obj::getClass(this->facade->getController()->currentScene));
		HX_SOURCE_POS("../../../src/com/mybo/Application.hx",97)
		if (((bool((bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::ClassicScene >()))) || bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::PuzzleScene >()))))) || bool((scene == ::Type_obj::getClassName(hx::ClassOf< ::com::mybo::gamescene::MasterScene >())))))){
			HX_SOURCE_POS("../../../src/com/mybo/Application.hx",99)
			Dynamic dynamicScene = this->facade->getController()->currentScene;
			HX_SOURCE_POS("../../../src/com/mybo/Application.hx",101)
			if (((bool((dynamicScene->__Field(HX_CSTRING("status")) == ::com::mybo::gamescene::GameStatus_obj::RUNNING_dyn())) && bool(!(::com::mybo::gamescene::GameHint_obj::running))))){
				HX_SOURCE_POS("../../../src/com/mybo/Application.hx",101)
				dynamicScene->__Field(HX_CSTRING("pause"))();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Application_obj,onDeactive,(void))


Application_obj::Application_obj()
{
}

void Application_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Application);
	HX_MARK_MEMBER_NAME(facade,"facade");
	HX_MARK_END_CLASS();
}

Dynamic Application_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onDeactive") ) { return onDeactive_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onAndroidBack") ) { return onAndroidBack_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Application_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Application_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("facade"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("facade"),
	HX_CSTRING("onAndroidBack"),
	HX_CSTRING("onDeactive"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Application_obj::__mClass;

void Application_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.Application"), hx::TCanCast< Application_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Application_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
