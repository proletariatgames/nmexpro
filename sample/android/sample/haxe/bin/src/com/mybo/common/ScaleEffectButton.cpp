#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#include <com/mybo/common/ScaleEffectButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
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
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace common{

Void ScaleEffectButton_obj::__construct(::nmex::display::Bitmap inBitmap)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/ScaleEffectButton.hx",16)
	super::__construct(inBitmap,null(),null(),null());
}
;
	return null();
}

ScaleEffectButton_obj::~ScaleEffectButton_obj() { }

Dynamic ScaleEffectButton_obj::__CreateEmpty() { return  new ScaleEffectButton_obj; }
hx::ObjectPtr< ScaleEffectButton_obj > ScaleEffectButton_obj::__new(::nmex::display::Bitmap inBitmap)
{  hx::ObjectPtr< ScaleEffectButton_obj > result = new ScaleEffectButton_obj();
	result->__construct(inBitmap);
	return result;}

Dynamic ScaleEffectButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScaleEffectButton_obj > result = new ScaleEffectButton_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ScaleEffectButton_obj::onMouseDown( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("ScaleEffectButton_obj::onMouseDown")
		HX_SOURCE_POS("../../../src/com/mybo/common/ScaleEffectButton.hx",21)
		this->super::onMouseDown(e);
		HX_SOURCE_POS("../../../src/com/mybo/common/ScaleEffectButton.hx",22)
		::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("modeSelect"),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ScaleEffectButton_obj,onMouseDown,(void))


ScaleEffectButton_obj::ScaleEffectButton_obj()
{
}

void ScaleEffectButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScaleEffectButton);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ScaleEffectButton_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ScaleEffectButton_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ScaleEffectButton_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onMouseDown"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ScaleEffectButton_obj::__mClass;

void ScaleEffectButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.ScaleEffectButton"), hx::TCanCast< ScaleEffectButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ScaleEffectButton_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace common
