#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cpp_Sys
#include <cpp/Sys.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
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
#ifndef INCLUDED_nme_display_ManagedStage
#include <nme/display/ManagedStage.h>
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
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace nme{

Void Lib_obj::__construct()
{
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new()
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

int Lib_obj::FULLSCREEN;

int Lib_obj::BORDERLESS;

int Lib_obj::RESIZABLE;

int Lib_obj::HARDWARE;

int Lib_obj::VSYNC;

int Lib_obj::HW_AA;

int Lib_obj::HW_AA_HIRES;

::nme::display::MovieClip Lib_obj::current;

int Lib_obj::initHeight;

int Lib_obj::initWidth;

::nme::display::Stage Lib_obj::stage;

::nme::display::MovieClip Lib_obj::nmeCurrent;

Dynamic Lib_obj::nmeMainFrame;

::nme::display::Stage Lib_obj::nmeStage;

bool Lib_obj::sIsInit;

Void Lib_obj::close( ){
{
		HX_SOURCE_PUSH("Lib_obj::close")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",45)
		Dynamic close = ::nme::Loader_obj::load(HX_CSTRING("nme_close"),(int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",46)
		close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,close,(void))

Void Lib_obj::create( Dynamic inOnLoaded,int inWidth,int inHeight,Dynamic __o_inFrameRate,Dynamic __o_inColour,Dynamic __o_inFlags,Dynamic __o_inTitle,Dynamic __o_inPackage,::nme::display::BitmapData inIcon){
double inFrameRate = __o_inFrameRate.Default(60.0);
int inColour = __o_inColour.Default(16777215);
int inFlags = __o_inFlags.Default(15);
::String inTitle = __o_inTitle.Default(HX_CSTRING("NME"));
::String inPackage = __o_inPackage.Default(HX_CSTRING(""));
	HX_SOURCE_PUSH("Lib_obj::create");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",50)
		Array< int > inColour1 = Array_obj< int >::__new().Add(inColour);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",50)
		Array< double > inFrameRate1 = Array_obj< double >::__new().Add(inFrameRate);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",50)
		Array< int > inHeight1 = Array_obj< int >::__new().Add(inHeight);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",50)
		Array< int > inWidth1 = Array_obj< int >::__new().Add(inWidth);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",50)
		Dynamic inOnLoaded1 = Dynamic( Array_obj<Dynamic>::__new().Add(inOnLoaded));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",52)
		if ((::nme::Lib_obj::sIsInit)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",53)
			hx::Throw (HX_CSTRING("nme.Lib.create called multiple times. This function is automatically called by the project code."));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",56)
		::nme::Lib_obj::sIsInit = true;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",57)
		::nme::Lib_obj::initWidth = inWidth1->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",58)
		::nme::Lib_obj::initHeight = inHeight1->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",59)
		Dynamic create_main_frame = ::nme::Loader_obj::load(HX_CSTRING("nme_create_main_frame"),(int)-1);

		HX_BEGIN_LOCAL_FUNC_S5(hx::LocalFunc,_Function_1_1,Dynamic,inOnLoaded1,Array< int >,inHeight1,Array< int >,inColour1,Array< int >,inWidth1,Array< double >,inFrameRate1)
		Void run(Dynamic inFrameHandle){
{
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",61)
				try{
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",63)
					::nme::Lib_obj::nmeMainFrame = inFrameHandle;
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",64)
					Dynamic stage_handle = ::nme::Lib_obj::nme_get_frame_stage(::nme::Lib_obj::nmeMainFrame);
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",65)
					::nme::Lib_obj::nmeStage = ::nme::display::Stage_obj::__new(stage_handle,inWidth1->__get((int)0),inHeight1->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",66)
					::nme::Lib_obj::nmeStage->nmeSetFrameRate(inFrameRate1->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",67)
					::nme::Lib_obj::nmeStage->nmeSetBG(inColour1->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",68)
					::nme::Lib_obj::nmeStage->onQuit = ::nme::Lib_obj::close_dyn();
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",69)
					if (((::nme::Lib_obj::nmeCurrent != null()))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",70)
						::nme::Lib_obj::nmeStage->addChild(::nme::Lib_obj::nmeCurrent);
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",71)
					inOnLoaded1->__GetItem((int)0)().Cast< Void >();
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",72)
							::haxe::Log_obj::trace((HX_CSTRING("ERROR: ") + e),hx::SourceInfo(HX_CSTRING("Lib.hx"),72,HX_CSTRING("nme.Lib"),HX_CSTRING("create")));
						}
					}
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",60)
		create_main_frame( Dynamic(new _Function_1_1(inOnLoaded1,inHeight1,inColour1,inWidth1,inFrameRate1)),inWidth1->__get((int)0),inHeight1->__get((int)0),inFlags,inTitle,inPackage,(  (((inIcon == null()))) ? Dynamic(null()) : Dynamic(inIcon->nmeHandle) ));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(Lib_obj,create,(void))

::nme::display::ManagedStage Lib_obj::createManagedStage( int inWidth,int inHeight){
	HX_SOURCE_PUSH("Lib_obj::createManagedStage")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",80)
	::nme::Lib_obj::initWidth = inWidth;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",81)
	::nme::Lib_obj::initHeight = inHeight;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",82)
	::nme::display::ManagedStage result = ::nme::display::ManagedStage_obj::__new(inWidth,inHeight);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",83)
	::nme::Lib_obj::nmeStage = result;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",84)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,createManagedStage,return )

Void Lib_obj::exit( ){
{
		HX_SOURCE_PUSH("Lib_obj::exit")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",90)
		Dynamic quit = ::nme::Lib_obj::nmeGetStage()->onQuit_dyn();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",91)
		if (((quit != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",94)
			if (((quit == ::nme::Lib_obj::close_dyn()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",95)
				::cpp::Sys_obj::exit((int)0);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",99)
			quit().Cast< Void >();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,exit,(void))

Void Lib_obj::forceClose( ){
{
		HX_SOURCE_PUSH("Lib_obj::forceClose")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",107)
		Dynamic terminate = ::nme::Loader_obj::load(HX_CSTRING("nme_terminate"),(int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",108)
		terminate();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,forceClose,(void))

int Lib_obj::getTimer( ){
	HX_SOURCE_PUSH("Lib_obj::getTimer")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",113)
	return ::Std_obj::_int((::haxe::Timer_obj::stamp() * 1000.0));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,getTimer,return )

Void Lib_obj::getURL( ::nme::net::URLRequest url,::String target){
{
		HX_SOURCE_PUSH("Lib_obj::getURL")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",120)
		::nme::Lib_obj::nme_get_url(url->url);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,getURL,(void))

Void Lib_obj::nmeSetCurrentStage( ::nme::display::Stage inStage){
{
		HX_SOURCE_PUSH("Lib_obj::nmeSetCurrentStage")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",129)
		::nme::Lib_obj::nmeStage = inStage;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,nmeSetCurrentStage,(void))

Void Lib_obj::postUICallback( Dynamic inCallback){
{
		HX_SOURCE_PUSH("Lib_obj::postUICallback")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",135)
		::nme::Lib_obj::nme_post_ui_callback(inCallback);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,postUICallback,(void))

Void Lib_obj::setAssetBase( ::String inBase){
{
		HX_SOURCE_PUSH("Lib_obj::setAssetBase")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",147)
		::nme::Lib_obj::nme_set_asset_base(inBase);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,setAssetBase,(void))

Void Lib_obj::setIcon( ::String path){
{
		HX_SOURCE_PUSH("Lib_obj::setIcon")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",155)
		Dynamic set_icon = ::nme::Loader_obj::load(HX_CSTRING("nme_set_icon"),(int)1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",156)
		set_icon(path);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,setIcon,(void))

::nme::display::MovieClip Lib_obj::nmeGetCurrent( ){
	HX_SOURCE_PUSH("Lib_obj::nmeGetCurrent")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",167)
	if (((::nme::Lib_obj::nmeCurrent == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",169)
		::nme::Lib_obj::nmeCurrent = ::nme::display::MovieClip_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",170)
		if (((::nme::Lib_obj::nmeStage != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",171)
			::nme::Lib_obj::nmeStage->addChild(::nme::Lib_obj::nmeCurrent);
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",173)
	return ::nme::Lib_obj::nmeCurrent;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,nmeGetCurrent,return )

::nme::display::Stage Lib_obj::nmeGetStage( ){
	HX_SOURCE_PUSH("Lib_obj::nmeGetStage")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",179)
	if (((::nme::Lib_obj::nmeStage == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",180)
		hx::Throw (HX_CSTRING("Error : stage can't be accessed until init is called"));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/Lib.hx",181)
	return ::nme::Lib_obj::nmeStage;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,nmeGetStage,return )

Dynamic Lib_obj::nme_post_ui_callback;

Dynamic Lib_obj::nme_get_frame_stage;

Dynamic Lib_obj::nme_set_asset_base;

Dynamic Lib_obj::nme_get_url;


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lib);
	HX_MARK_END_CLASS();
}

Dynamic Lib_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"exit") ) { return exit_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"VSYNC") ) { return VSYNC; }
		if (HX_FIELD_EQ(inName,"HW_AA") ) { return HW_AA; }
		if (HX_FIELD_EQ(inName,"stage") ) { return nmeGetStage(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"getURL") ) { return getURL_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return nmeGetCurrent(); }
		if (HX_FIELD_EQ(inName,"sIsInit") ) { return sIsInit; }
		if (HX_FIELD_EQ(inName,"setIcon") ) { return setIcon_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { return HARDWARE; }
		if (HX_FIELD_EQ(inName,"nmeStage") ) { return nmeStage; }
		if (HX_FIELD_EQ(inName,"getTimer") ) { return getTimer_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"RESIZABLE") ) { return RESIZABLE; }
		if (HX_FIELD_EQ(inName,"initWidth") ) { return initWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FULLSCREEN") ) { return FULLSCREEN; }
		if (HX_FIELD_EQ(inName,"BORDERLESS") ) { return BORDERLESS; }
		if (HX_FIELD_EQ(inName,"initHeight") ) { return initHeight; }
		if (HX_FIELD_EQ(inName,"nmeCurrent") ) { return nmeCurrent; }
		if (HX_FIELD_EQ(inName,"forceClose") ) { return forceClose_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HW_AA_HIRES") ) { return HW_AA_HIRES; }
		if (HX_FIELD_EQ(inName,"nmeGetStage") ) { return nmeGetStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_get_url") ) { return nme_get_url; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeMainFrame") ) { return nmeMainFrame; }
		if (HX_FIELD_EQ(inName,"setAssetBase") ) { return setAssetBase_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeGetCurrent") ) { return nmeGetCurrent_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"postUICallback") ) { return postUICallback_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createManagedStage") ) { return createManagedStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetCurrentStage") ) { return nmeSetCurrentStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_set_asset_base") ) { return nme_set_asset_base; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_get_frame_stage") ) { return nme_get_frame_stage; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_post_ui_callback") ) { return nme_post_ui_callback; }
	}
	return super::__Field(inName);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"VSYNC") ) { VSYNC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HW_AA") ) { HW_AA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::nme::display::MovieClip >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sIsInit") ) { sIsInit=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { HARDWARE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeStage") ) { nmeStage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"RESIZABLE") ) { RESIZABLE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initWidth") ) { initWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FULLSCREEN") ) { FULLSCREEN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BORDERLESS") ) { BORDERLESS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initHeight") ) { initHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeCurrent") ) { nmeCurrent=inValue.Cast< ::nme::display::MovieClip >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HW_AA_HIRES") ) { HW_AA_HIRES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_get_url") ) { nme_get_url=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeMainFrame") ) { nmeMainFrame=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_set_asset_base") ) { nme_set_asset_base=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_get_frame_stage") ) { nme_get_frame_stage=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_post_ui_callback") ) { nme_post_ui_callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FULLSCREEN"),
	HX_CSTRING("BORDERLESS"),
	HX_CSTRING("RESIZABLE"),
	HX_CSTRING("HARDWARE"),
	HX_CSTRING("VSYNC"),
	HX_CSTRING("HW_AA"),
	HX_CSTRING("HW_AA_HIRES"),
	HX_CSTRING("current"),
	HX_CSTRING("initHeight"),
	HX_CSTRING("initWidth"),
	HX_CSTRING("stage"),
	HX_CSTRING("nmeCurrent"),
	HX_CSTRING("nmeMainFrame"),
	HX_CSTRING("nmeStage"),
	HX_CSTRING("sIsInit"),
	HX_CSTRING("close"),
	HX_CSTRING("create"),
	HX_CSTRING("createManagedStage"),
	HX_CSTRING("exit"),
	HX_CSTRING("forceClose"),
	HX_CSTRING("getTimer"),
	HX_CSTRING("getURL"),
	HX_CSTRING("nmeSetCurrentStage"),
	HX_CSTRING("postUICallback"),
	HX_CSTRING("setAssetBase"),
	HX_CSTRING("setIcon"),
	HX_CSTRING("nmeGetCurrent"),
	HX_CSTRING("nmeGetStage"),
	HX_CSTRING("nme_post_ui_callback"),
	HX_CSTRING("nme_get_frame_stage"),
	HX_CSTRING("nme_set_asset_base"),
	HX_CSTRING("nme_get_url"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lib_obj::FULLSCREEN,"FULLSCREEN");
	HX_MARK_MEMBER_NAME(Lib_obj::BORDERLESS,"BORDERLESS");
	HX_MARK_MEMBER_NAME(Lib_obj::RESIZABLE,"RESIZABLE");
	HX_MARK_MEMBER_NAME(Lib_obj::HARDWARE,"HARDWARE");
	HX_MARK_MEMBER_NAME(Lib_obj::VSYNC,"VSYNC");
	HX_MARK_MEMBER_NAME(Lib_obj::HW_AA,"HW_AA");
	HX_MARK_MEMBER_NAME(Lib_obj::HW_AA_HIRES,"HW_AA_HIRES");
	HX_MARK_MEMBER_NAME(Lib_obj::current,"current");
	HX_MARK_MEMBER_NAME(Lib_obj::initHeight,"initHeight");
	HX_MARK_MEMBER_NAME(Lib_obj::initWidth,"initWidth");
	HX_MARK_MEMBER_NAME(Lib_obj::stage,"stage");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeCurrent,"nmeCurrent");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeMainFrame,"nmeMainFrame");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeStage,"nmeStage");
	HX_MARK_MEMBER_NAME(Lib_obj::sIsInit,"sIsInit");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_post_ui_callback,"nme_post_ui_callback");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_get_frame_stage,"nme_get_frame_stage");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_set_asset_base,"nme_set_asset_base");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_get_url,"nme_get_url");
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.Lib"), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lib_obj::__boot()
{
	hx::Static(FULLSCREEN) = (int)1;
	hx::Static(BORDERLESS) = (int)2;
	hx::Static(RESIZABLE) = (int)4;
	hx::Static(HARDWARE) = (int)8;
	hx::Static(VSYNC) = (int)16;
	hx::Static(HW_AA) = (int)32;
	hx::Static(HW_AA_HIRES) = (int)96;
	hx::Static(current);
	hx::Static(initHeight);
	hx::Static(initWidth);
	hx::Static(stage);
	hx::Static(nmeCurrent) = null();
	hx::Static(nmeMainFrame) = null();
	hx::Static(nmeStage) = null();
	hx::Static(sIsInit) = false;
	hx::Static(nme_post_ui_callback) = ::nme::Loader_obj::load(HX_CSTRING("nme_post_ui_callback"),(int)1);
	hx::Static(nme_get_frame_stage) = ::nme::Loader_obj::load(HX_CSTRING("nme_get_frame_stage"),(int)1);
	hx::Static(nme_set_asset_base) = ::nme::Loader_obj::load(HX_CSTRING("nme_set_asset_base"),(int)1);
	hx::Static(nme_get_url) = ::nme::Loader_obj::load(HX_CSTRING("nme_get_url"),(int)1);
}

} // end namespace nme
