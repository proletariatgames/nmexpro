#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
#endif
#ifndef INCLUDED_com_mybo_data_MapFactory
#include <com/mybo/data/MapFactory.h>
#endif
#ifndef INCLUDED_com_mybo_data_UserData
#include <com/mybo/data/UserData.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_TouchUpDownContainer
#include <com/mybo/framework/display/TouchUpDownContainer.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_PackageItem
#include <com/mybo/menuscene/PackageItem.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_PackageSelector
#include <com/mybo/menuscene/PackageSelector.h>
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
#ifndef INCLUDED_nme_system_Capabilities
#include <nme/system/Capabilities.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace menuscene{

Void PackageSelector_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",28)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",29)
	this->content = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",30)
	this->items = Array_obj< ::com::mybo::menuscene::PackageItem >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",31)
	int length = ::com::mybo::data::MapFactory_obj::getPuzzlePackConut();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",33)
	{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",33)
		int _g = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",33)
		while(((_g < length))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",33)
			int i = (_g)++;
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",34)
			int packID = (i + (int)1);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",35)
			bool locked = !(::com::mybo::data::UserData_obj::getInstance(null())->isPackUnlocked(packID));
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",36)
			int completedLevel = ::com::mybo::data::UserData_obj::getInstance(null())->getPackCompleted(packID);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",38)
			::com::mybo::menuscene::PackageItem item = ::com::mybo::menuscene::PackageItem_obj::__new(packID,locked,completedLevel,(int)25);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",39)
			item->nmeSetY((i * item->nmeGetHeight()));
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",40)
			this->content->addChild(item);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",41)
			this->items->push(item);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",43)
			item->addEventListener(HX_CSTRING("packSelected"),this->onSelect_dyn(),null(),null(),null());
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",46)
	if (((bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionX() == (int)480)) && bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionY() > (int)800))))){
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",46)
		this->touchUpDownContainer = ::com::mybo::framework::display::TouchUpDownContainer_obj::__new((int)269,(int)300,this->content);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",48)
		this->touchUpDownContainer = ::com::mybo::framework::display::TouchUpDownContainer_obj::__new((int)269,(int)260,this->content);
	}
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",52)
	this->addChild(this->touchUpDownContainer);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",54)
	this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
}
;
	return null();
}

PackageSelector_obj::~PackageSelector_obj() { }

Dynamic PackageSelector_obj::__CreateEmpty() { return  new PackageSelector_obj; }
hx::ObjectPtr< PackageSelector_obj > PackageSelector_obj::__new()
{  hx::ObjectPtr< PackageSelector_obj > result = new PackageSelector_obj();
	result->__construct();
	return result;}

Dynamic PackageSelector_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PackageSelector_obj > result = new PackageSelector_obj();
	result->__construct();
	return result;}

Void PackageSelector_obj::onEnterFrame( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("PackageSelector_obj::onEnterFrame")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",58)
		int length = this->items->length;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",59)
		double itemY;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",60)
		::com::mybo::menuscene::PackageItem item;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",62)
		{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",62)
			int _g = (int)0;
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",62)
			while(((_g < length))){
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",62)
				int i = (_g)++;
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",63)
				item = this->items->__get(i);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",64)
				itemY = (this->content->nmeGetY() + item->nmeGetY());
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",66)
				if (((bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionX() == (int)480)) && bool((::nme::system::Capabilities_obj::nmeGetScreenResolutionY() > (int)800))))){
					HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",66)
					if (((bool((itemY >= (int)-10)) && bool((itemY < (int)245))))){
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",67)
						item->nmeSetAlpha((int)1);
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",69)
						item->nmeSetAlpha((  (((itemY < (int)-10))) ? double(((int)1 + (double(itemY) / double((int)45)))) : double(((int)1 - (double(((itemY - (int)250))) / double((int)57)))) ));
					}
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",72)
					if (((bool((itemY >= (int)-10)) && bool((itemY < (int)188))))){
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",73)
						item->nmeSetAlpha((int)1);
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",75)
						item->nmeSetAlpha((  (((itemY < (int)-10))) ? double(((int)1 + (double(itemY) / double((int)45)))) : double(((int)1 - (double(((itemY - (int)190))) / double((int)57)))) ));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PackageSelector_obj,onEnterFrame,(void))

Void PackageSelector_obj::onSelect( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("PackageSelector_obj::onSelect")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",84)
		this->dispatchEvent(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PackageSelector_obj,onSelect,(void))

Void PackageSelector_obj::destroy( ){
{
		HX_SOURCE_PUSH("PackageSelector_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageSelector.hx",88)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PackageSelector_obj,destroy,(void))


PackageSelector_obj::PackageSelector_obj()
{
}

void PackageSelector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PackageSelector);
	HX_MARK_MEMBER_NAME(touchUpDownContainer,"touchUpDownContainer");
	HX_MARK_MEMBER_NAME(content,"content");
	HX_MARK_MEMBER_NAME(items,"items");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PackageSelector_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"items") ) { return items; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { return content; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onSelect") ) { return onSelect_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"touchUpDownContainer") ) { return touchUpDownContainer; }
	}
	return super::__Field(inName);
}

Dynamic PackageSelector_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"items") ) { items=inValue.Cast< Array< ::com::mybo::menuscene::PackageItem > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { content=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"touchUpDownContainer") ) { touchUpDownContainer=inValue.Cast< ::com::mybo::framework::display::TouchUpDownContainer >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PackageSelector_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("touchUpDownContainer"));
	outFields->push(HX_CSTRING("content"));
	outFields->push(HX_CSTRING("items"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("touchUpDownContainer"),
	HX_CSTRING("content"),
	HX_CSTRING("items"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("onSelect"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PackageSelector_obj::__mClass;

void PackageSelector_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.PackageSelector"), hx::TCanCast< PackageSelector_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PackageSelector_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
