#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
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
#ifndef INCLUDED_com_mybo_framework_core_View
#include <com/mybo/framework/core/View.h>
#endif
#ifndef INCLUDED_com_mybo_framework_interfaces_ISceneMotion
#include <com/mybo/framework/interfaces/ISceneMotion.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_Resource
#include <com/mybo/framework/resource/Resource.h>
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
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_StageAlign
#include <nme/display/StageAlign.h>
#endif
#ifndef INCLUDED_nme_display_StageScaleMode
#include <nme/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_system_Capabilities
#include <nme/system/Capabilities.h>
#endif
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace core{

Void Facade_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",26)
	::com::mybo::framework::core::Facade_obj::instance = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",27)
	this->controller = ::com::mybo::framework::core::Controller_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",28)
	this->shareObjects = ::Hash_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",29)
	this->startTime = ::nme::Lib_obj::getTimer();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",30)
	this->initStage(::nme::Lib_obj::nmeGetCurrent()->nmeGetStage());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",33)
	this->getStage()->nmeSetScaleMode(::nme::display::StageScaleMode_obj::SHOW_ALL_dyn());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",34)
	this->getStage()->nmeSetAlign(::nme::display::StageAlign_obj::TOP_dyn());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",35)
	if (((bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionX() == (int)240)) && bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionY() == (int)320))))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",36)
		this->getStage()->nmeSetScaleMode(::nme::display::StageScaleMode_obj::EXACT_FIT_dyn());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",37)
		this->getStage()->nmeSetAlign(::nme::display::StageAlign_obj::TOP_dyn());
	}
}
;
	return null();
}

Facade_obj::~Facade_obj() { }

Dynamic Facade_obj::__CreateEmpty() { return  new Facade_obj; }
hx::ObjectPtr< Facade_obj > Facade_obj::__new()
{  hx::ObjectPtr< Facade_obj > result = new Facade_obj();
	result->__construct();
	return result;}

Dynamic Facade_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Facade_obj > result = new Facade_obj();
	result->__construct();
	return result;}

Void Facade_obj::showFps( ){
{
		HX_SOURCE_PUSH("Facade_obj::showFps")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",55)
		this->getView()->showFPS();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,showFps,(void))

Dynamic Facade_obj::getShareObject( ::String name){
	HX_SOURCE_PUSH("Facade_obj::getShareObject")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",61)
	return this->shareObjects->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,getShareObject,return )

Void Facade_obj::setShareObject( ::String name,Dynamic obj){
{
		HX_SOURCE_PUSH("Facade_obj::setShareObject")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",64)
		this->shareObjects->set(name,obj);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Facade_obj,setShareObject,(void))

Void Facade_obj::run( ::Class classRef,Dynamic params){
{
		HX_SOURCE_PUSH("Facade_obj::run")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",70)
		this->getController()->run(classRef,params);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Facade_obj,run,(void))

Void Facade_obj::noRouteRun( ::Class classRef,Dynamic params){
{
		HX_SOURCE_PUSH("Facade_obj::noRouteRun")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",73)
		this->getController()->run(classRef,params);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Facade_obj,noRouteRun,(void))

Void Facade_obj::back( ){
{
		HX_SOURCE_PUSH("Facade_obj::back")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",76)
		this->getController()->back(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,back,(void))

::com::mybo::framework::core::Controller Facade_obj::getController( ){
	HX_SOURCE_PUSH("Facade_obj::getController")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",79)
	return this->controller;
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,getController,return )

Void Facade_obj::initResource( ::String resourcePath,::String xmlFilePath){
{
		HX_SOURCE_PUSH("Facade_obj::initResource")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",85)
		this->resource = ::com::mybo::framework::resource::Resource_obj::__new(resourcePath,xmlFilePath);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Facade_obj,initResource,(void))

::nmex::display::Bitmap Facade_obj::getBitmap( ::String id,Dynamic __o_smooth){
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Facade_obj::getBitmap");
{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",88)
		return this->resource->getBitmap(id,smooth);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Facade_obj,getBitmap,return )

::com::mybo::framework::resource::BitmapTile Facade_obj::getTile( ::String id){
	HX_SOURCE_PUSH("Facade_obj::getTile")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",91)
	return this->resource->getTile(id);
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,getTile,return )

Void Facade_obj::destroyResource( ::String id){
{
		HX_SOURCE_PUSH("Facade_obj::destroyResource")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",94)
		this->resource->destroyResource(id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,destroyResource,(void))

Void Facade_obj::loadResourceByFolder( ::String folderName){
{
		HX_SOURCE_PUSH("Facade_obj::loadResourceByFolder")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",97)
		this->resource->loadAllByFolder(folderName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,loadResourceByFolder,(void))

Void Facade_obj::unLoadResourceByFolder( ::String folderName){
{
		HX_SOURCE_PUSH("Facade_obj::unLoadResourceByFolder")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",100)
		this->resource->unLoadAllByFolder(folderName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,unLoadResourceByFolder,(void))

Void Facade_obj::unLoadAllResource( ){
{
		HX_SOURCE_PUSH("Facade_obj::unLoadAllResource")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",103)
		this->resource->unLoadAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,unLoadAllResource,(void))

Void Facade_obj::loadAllResource( ){
{
		HX_SOURCE_PUSH("Facade_obj::loadAllResource")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",106)
		this->resource->loadAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,loadAllResource,(void))

Void Facade_obj::setPageMotion( ::Class motionRef){
{
		HX_SOURCE_PUSH("Facade_obj::setPageMotion")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",112)
		this->getView()->setPageMotion(motionRef);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,setPageMotion,(void))

::nme::display::Stage Facade_obj::getStage( ){
	HX_SOURCE_PUSH("Facade_obj::getStage")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",115)
	return this->getView()->getStage();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,getStage,return )

Void Facade_obj::initStage( ::nme::display::Stage stage){
{
		HX_SOURCE_PUSH("Facade_obj::initStage")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",118)
		this->view = ::com::mybo::framework::core::View_obj::__new(stage);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Facade_obj,initStage,(void))

::com::mybo::framework::core::View Facade_obj::getView( ){
	HX_SOURCE_PUSH("Facade_obj::getView")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",121)
	return this->view;
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,getView,return )

double Facade_obj::getStageWidthInPoint( ){
	HX_SOURCE_PUSH("Facade_obj::getStageWidthInPoint")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",127)
	return (int)320;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",130)
	return (int)320;
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,getStageWidthInPoint,return )

double Facade_obj::getStageHeightInPoint( ){
	HX_SOURCE_PUSH("Facade_obj::getStageHeightInPoint")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",135)
	if (((::nme::system::Capabilities_obj::nmeGetScreenResolutionX() <= (int)320))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",135)
		return (int)480;
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",138)
	return (double((this->getStage()->nmeGetStageHeight() * (int)320)) / double(this->getStage()->nmeGetStageWidth()));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",140)
	return (int)480;
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,getStageHeightInPoint,return )

Void Facade_obj::enable( ){
{
		HX_SOURCE_PUSH("Facade_obj::enable")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",146)
		this->getView()->currentPage->nmeSetMouseEnabled(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,enable,(void))

Void Facade_obj::disable( ){
{
		HX_SOURCE_PUSH("Facade_obj::disable")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",150)
		this->getView()->currentPage->nmeSetMouseEnabled(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,disable,(void))

::com::mybo::framework::core::Facade Facade_obj::instance;

double Facade_obj::contentScaleFactor;

::com::mybo::framework::core::Facade Facade_obj::getInstance( ){
	HX_SOURCE_PUSH("Facade_obj::getInstance")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",49)
	if (((::com::mybo::framework::core::Facade_obj::instance == null()))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",49)
		::com::mybo::framework::core::Facade_obj::instance = ::com::mybo::framework::core::Facade_obj::__new();
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Facade.hx",52)
	return ::com::mybo::framework::core::Facade_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Facade_obj,getInstance,return )


Facade_obj::Facade_obj()
{
}

void Facade_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Facade);
	HX_MARK_MEMBER_NAME(stage,"stage");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(controller,"controller");
	HX_MARK_MEMBER_NAME(startTime,"startTime");
	HX_MARK_MEMBER_NAME(resource,"resource");
	HX_MARK_MEMBER_NAME(shareObjects,"shareObjects");
	HX_MARK_END_CLASS();
}

Dynamic Facade_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return getView(); }
		if (HX_FIELD_EQ(inName,"back") ) { return back_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { return getStage(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"enable") ) { return enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"showFps") ) { return showFps_dyn(); }
		if (HX_FIELD_EQ(inName,"getTile") ) { return getTile_dyn(); }
		if (HX_FIELD_EQ(inName,"getView") ) { return getView_dyn(); }
		if (HX_FIELD_EQ(inName,"disable") ) { return disable_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance; }
		if (HX_FIELD_EQ(inName,"resource") ) { return resource; }
		if (HX_FIELD_EQ(inName,"getStage") ) { return getStage_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startTime") ) { return startTime; }
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"initStage") ) { return initStage_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { return getController(); }
		if (HX_FIELD_EQ(inName,"noRouteRun") ) { return noRouteRun_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"shareObjects") ) { return shareObjects; }
		if (HX_FIELD_EQ(inName,"initResource") ) { return initResource_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getController") ) { return getController_dyn(); }
		if (HX_FIELD_EQ(inName,"setPageMotion") ) { return setPageMotion_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getShareObject") ) { return getShareObject_dyn(); }
		if (HX_FIELD_EQ(inName,"setShareObject") ) { return setShareObject_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"destroyResource") ) { return destroyResource_dyn(); }
		if (HX_FIELD_EQ(inName,"loadAllResource") ) { return loadAllResource_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"unLoadAllResource") ) { return unLoadAllResource_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"contentScaleFactor") ) { return contentScaleFactor; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"loadResourceByFolder") ) { return loadResourceByFolder_dyn(); }
		if (HX_FIELD_EQ(inName,"getStageWidthInPoint") ) { return getStageWidthInPoint_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getStageHeightInPoint") ) { return getStageHeightInPoint_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"unLoadResourceByFolder") ) { return unLoadResourceByFolder_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Facade_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::com::mybo::framework::core::View >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resource") ) { resource=inValue.Cast< ::com::mybo::framework::resource::Resource >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startTime") ) { startTime=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { controller=inValue.Cast< ::com::mybo::framework::core::Controller >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"shareObjects") ) { shareObjects=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"contentScaleFactor") ) { contentScaleFactor=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Facade_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("stage"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("controller"));
	outFields->push(HX_CSTRING("startTime"));
	outFields->push(HX_CSTRING("resource"));
	outFields->push(HX_CSTRING("shareObjects"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("contentScaleFactor"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stage"),
	HX_CSTRING("view"),
	HX_CSTRING("controller"),
	HX_CSTRING("startTime"),
	HX_CSTRING("resource"),
	HX_CSTRING("shareObjects"),
	HX_CSTRING("showFps"),
	HX_CSTRING("getShareObject"),
	HX_CSTRING("setShareObject"),
	HX_CSTRING("run"),
	HX_CSTRING("noRouteRun"),
	HX_CSTRING("back"),
	HX_CSTRING("getController"),
	HX_CSTRING("initResource"),
	HX_CSTRING("getBitmap"),
	HX_CSTRING("getTile"),
	HX_CSTRING("destroyResource"),
	HX_CSTRING("loadResourceByFolder"),
	HX_CSTRING("unLoadResourceByFolder"),
	HX_CSTRING("unLoadAllResource"),
	HX_CSTRING("loadAllResource"),
	HX_CSTRING("setPageMotion"),
	HX_CSTRING("getStage"),
	HX_CSTRING("initStage"),
	HX_CSTRING("getView"),
	HX_CSTRING("getStageWidthInPoint"),
	HX_CSTRING("getStageHeightInPoint"),
	HX_CSTRING("enable"),
	HX_CSTRING("disable"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Facade_obj::instance,"instance");
	HX_MARK_MEMBER_NAME(Facade_obj::contentScaleFactor,"contentScaleFactor");
};

Class Facade_obj::__mClass;

void Facade_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.core.Facade"), hx::TCanCast< Facade_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Facade_obj::__boot()
{
	hx::Static(instance);
	hx::Static(contentScaleFactor) = ::nmex::Device_obj::scaleFactor();
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core
