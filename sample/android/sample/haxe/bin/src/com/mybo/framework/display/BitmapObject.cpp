#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
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
#ifndef INCLUDED_nme_display_Tilesheet
#include <nme/display/Tilesheet.h>
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
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace display{

Void BitmapObject_obj::__construct(::com::mybo::framework::resource::BitmapTile bitmapTile,Dynamic __o_autoRun,Dynamic __o_drawFirst,Dynamic __o_smooth)
{
bool autoRun = __o_autoRun.Default(true);
bool drawFirst = __o_drawFirst.Default(true);
bool smooth = __o_smooth.Default(true);
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",28)
	smooth = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",31)
	if (((::nmex::Device_obj::deviceName() == HX_CSTRING("iPad")))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",31)
		smooth = true;
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",35)
	super::__construct(autoRun);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",36)
	this->tile = bitmapTile;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",37)
	this->currentFrame = (int)0;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",38)
	this->totalFrames = this->tile->totalFrames;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",40)
	this->smooth = smooth;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",41)
	this->nmeSetScaleX(this->tile->scale);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",42)
	this->nmeSetScaleY(this->tile->scale);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",43)
	this->gfx = this->nmeGetGraphics();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",45)
	if ((drawFirst)){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",46)
		this->drawTile((int)0,null(),null(),null());
	}
	else{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",48)
		this->currentFrame = (int)-1;
	}
}
;
	return null();
}

BitmapObject_obj::~BitmapObject_obj() { }

Dynamic BitmapObject_obj::__CreateEmpty() { return  new BitmapObject_obj; }
hx::ObjectPtr< BitmapObject_obj > BitmapObject_obj::__new(::com::mybo::framework::resource::BitmapTile bitmapTile,Dynamic __o_autoRun,Dynamic __o_drawFirst,Dynamic __o_smooth)
{  hx::ObjectPtr< BitmapObject_obj > result = new BitmapObject_obj();
	result->__construct(bitmapTile,__o_autoRun,__o_drawFirst,__o_smooth);
	return result;}

Dynamic BitmapObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapObject_obj > result = new BitmapObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BitmapObject_obj::drawTile( int index,Dynamic __o_x,Dynamic __o_y,Dynamic __o_isClear){
double x = __o_x.Default(0.0);
double y = __o_y.Default(0.0);
bool isClear = __o_isClear.Default(true);
	HX_SOURCE_PUSH("BitmapObject_obj::drawTile");
{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",51)
		if (((this->tile != null()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",53)
			if ((isClear)){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",53)
				this->nmeGetGraphics()->clear();
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",54)
			this->gfx->drawTiles(this->tile->tilesheet,Array_obj< double >::__new().Add((::Std_obj::_int((double(x) / double((int)2))) * 2.0)).Add((::Std_obj::_int((double(y) / double((int)2))) * 2.0)).Add(index),this->smooth,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BitmapObject_obj,drawTile,(void))

Void BitmapObject_obj::clear( ){
{
		HX_SOURCE_PUSH("BitmapObject_obj::clear")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",57)
		this->gfx->clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapObject_obj,clear,(void))

Void BitmapObject_obj::destroy( ){
{
		HX_SOURCE_PUSH("BitmapObject_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",61)
		this->gfx->clear();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",62)
		this->tile = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",63)
		if (((this->nmeGetParent() != null()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",63)
			this->nmeGetParent()->removeChild(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapObject_obj,destroy,(void))

Void BitmapObject_obj::destroyBD( ){
{
		HX_SOURCE_PUSH("BitmapObject_obj::destroyBD")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapObject.hx",65)
		::com::mybo::framework::core::Facade_obj::getInstance()->destroyResource(this->tile->id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapObject_obj,destroyBD,(void))


BitmapObject_obj::BitmapObject_obj()
{
}

void BitmapObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapObject);
	HX_MARK_MEMBER_NAME(tile,"tile");
	HX_MARK_MEMBER_NAME(totalFrames,"totalFrames");
	HX_MARK_MEMBER_NAME(currentFrame,"currentFrame");
	HX_MARK_MEMBER_NAME(smooth,"smooth");
	HX_MARK_MEMBER_NAME(gfx,"gfx");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"gfx") ) { return gfx; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tile") ) { return tile; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"smooth") ) { return smooth; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"drawTile") ) { return drawTile_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyBD") ) { return destroyBD_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalFrames") ) { return totalFrames; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentFrame") ) { return currentFrame; }
	}
	return super::__Field(inName);
}

Dynamic BitmapObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"gfx") ) { gfx=inValue.Cast< ::nmex::display::Graphics >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tile") ) { tile=inValue.Cast< ::com::mybo::framework::resource::BitmapTile >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"smooth") ) { smooth=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalFrames") ) { totalFrames=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentFrame") ) { currentFrame=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tile"));
	outFields->push(HX_CSTRING("totalFrames"));
	outFields->push(HX_CSTRING("currentFrame"));
	outFields->push(HX_CSTRING("smooth"));
	outFields->push(HX_CSTRING("gfx"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("tile"),
	HX_CSTRING("totalFrames"),
	HX_CSTRING("currentFrame"),
	HX_CSTRING("smooth"),
	HX_CSTRING("gfx"),
	HX_CSTRING("drawTile"),
	HX_CSTRING("clear"),
	HX_CSTRING("destroy"),
	HX_CSTRING("destroyBD"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapObject_obj::__mClass;

void BitmapObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapObject"), hx::TCanCast< BitmapObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapObject_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
