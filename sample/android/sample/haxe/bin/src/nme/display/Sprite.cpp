#include <hxcpp.h>

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
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace nme{
namespace display{

Void Sprite_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/Sprite.hx",12)
	super::__construct(::nme::display::DisplayObjectContainer_obj::nme_create_display_object_container(),this->nmeGetType());
}
;
	return null();
}

Sprite_obj::~Sprite_obj() { }

Dynamic Sprite_obj::__CreateEmpty() { return  new Sprite_obj; }
hx::ObjectPtr< Sprite_obj > Sprite_obj::__new()
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

Dynamic Sprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

::String Sprite_obj::nmeGetType( ){
	HX_SOURCE_PUSH("Sprite_obj::nmeGetType")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/Sprite.hx",18)
	return HX_CSTRING("Sprite");
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,nmeGetType,return )

Void Sprite_obj::startDrag( Dynamic __o_lockCenter,::nme::geom::Rectangle bounds){
bool lockCenter = __o_lockCenter.Default(false);
	HX_SOURCE_PUSH("Sprite_obj::startDrag");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/Sprite.hx",24)
		if (((this->nmeGetStage() != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/Sprite.hx",26)
			this->nmeGetStage()->nmeStartDrag(hx::ObjectPtr<OBJ_>(this),lockCenter,bounds);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Sprite_obj,startDrag,(void))

Void Sprite_obj::stopDrag( ){
{
		HX_SOURCE_PUSH("Sprite_obj::stopDrag")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/Sprite.hx",31)
		if (((this->nmeGetStage() != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/display/Sprite.hx",33)
			this->nmeGetStage()->nmeStopDrag(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,stopDrag,(void))


Sprite_obj::Sprite_obj()
{
}

void Sprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sprite);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Sprite_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"stopDrag") ) { return stopDrag_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startDrag") ) { return startDrag_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Sprite_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Sprite_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("startDrag"),
	HX_CSTRING("stopDrag"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Sprite_obj::__mClass;

void Sprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Sprite"), hx::TCanCast< Sprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sprite_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
