#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
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
#ifndef INCLUDED_com_mybo_framework_display_BitmapNumber
#include <com/mybo/framework/display/BitmapNumber.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_menuscene_LevelSelector
#include <com/mybo/menuscene/LevelSelector.h>
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
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace menuscene{

Void LevelSelector_obj::__construct(int inPackID)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",32)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",33)
	this->packID = inPackID;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",34)
	this->maxItem = (int)25;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",35)
	this->completedItem = ::com::mybo::data::UserData_obj::getInstance(null())->getPackCompleted(this->packID);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",37)
	double x;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",38)
	double y;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",39)
	int index;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",40)
	::nmex::display::Bitmap item;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",41)
	::com::mybo::framework::display::BitmapNumber num;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",42)
	{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",42)
		int _g1 = (int)0;
		int _g = this->maxItem;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",42)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",42)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",43)
			x = (::Std_obj::_int(hx::Mod(i,(int)5)) * (int)57);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",44)
			y = (::Std_obj::_int((double(i) / double((int)5))) * (int)60);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",45)
			index = (i + (int)1);
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",46)
			if (((index > (this->completedItem + (int)1)))){
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",47)
				item = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("select_lock"),null());
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",48)
				item->nmeSetX(x);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",49)
				item->nmeSetY(y);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",50)
				this->addChild(item);
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",52)
				item = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("select_unlock"),null());
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",53)
				item->nmeSetX(x);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",54)
				item->nmeSetY(y);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",55)
				this->addChild(item);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",56)
				num = ::com::mybo::framework::display::BitmapNumber_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getTile(HX_CSTRING("num7")),null());
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",57)
				num->drawNumber(index);
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",58)
				num->nmeSetX(((item->nmeGetX() + ::Std_obj::_int((double(item->nmeGetWidth()) / double((int)2)))) - ::Std_obj::_int((double(num->nmeGetWidth()) / double((int)2)))));
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",59)
				num->nmeSetY((((item->nmeGetY() + ::Std_obj::_int((double(item->nmeGetHeight()) / double((int)2)))) - ::Std_obj::_int((double(num->nmeGetHeight()) / double((int)2)))) - (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",60)
				this->addChild(num);
			}
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",64)
	this->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->onItemClick_dyn(),null(),null(),null());
}
;
	return null();
}

LevelSelector_obj::~LevelSelector_obj() { }

Dynamic LevelSelector_obj::__CreateEmpty() { return  new LevelSelector_obj; }
hx::ObjectPtr< LevelSelector_obj > LevelSelector_obj::__new(int inPackID)
{  hx::ObjectPtr< LevelSelector_obj > result = new LevelSelector_obj();
	result->__construct(inPackID);
	return result;}

Dynamic LevelSelector_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LevelSelector_obj > result = new LevelSelector_obj();
	result->__construct(inArgs[0]);
	return result;}

Void LevelSelector_obj::onItemClick( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("LevelSelector_obj::onItemClick")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",68)
		int index = ((::Std_obj::_int((double(this->nmeGetMouseX()) / double((int)57))) + (::Std_obj::_int((double(this->nmeGetMouseY()) / double((int)60))) * (int)5)) + (int)1);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",70)
		if (((index <= (this->completedItem + (int)1)))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/LevelSelector.hx",70)
			this->dispatchEvent(::com::mybo::common::GameEvent_obj::__new(HX_CSTRING("levelSelected"),Array_obj< int >::__new().Add(index)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LevelSelector_obj,onItemClick,(void))

int LevelSelector_obj::MAX_LINE_ITEM;

int LevelSelector_obj::ITEM_SPACE_WIDTH;

int LevelSelector_obj::ITEM_SPACE_HEIGHT;


LevelSelector_obj::LevelSelector_obj()
{
}

void LevelSelector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LevelSelector);
	HX_MARK_MEMBER_NAME(packID,"packID");
	HX_MARK_MEMBER_NAME(maxItem,"maxItem");
	HX_MARK_MEMBER_NAME(completedItem,"completedItem");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic LevelSelector_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"packID") ) { return packID; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxItem") ) { return maxItem; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onItemClick") ) { return onItemClick_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"MAX_LINE_ITEM") ) { return MAX_LINE_ITEM; }
		if (HX_FIELD_EQ(inName,"completedItem") ) { return completedItem; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"ITEM_SPACE_WIDTH") ) { return ITEM_SPACE_WIDTH; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"ITEM_SPACE_HEIGHT") ) { return ITEM_SPACE_HEIGHT; }
	}
	return super::__Field(inName);
}

Dynamic LevelSelector_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"packID") ) { packID=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxItem") ) { maxItem=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"MAX_LINE_ITEM") ) { MAX_LINE_ITEM=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"completedItem") ) { completedItem=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"ITEM_SPACE_WIDTH") ) { ITEM_SPACE_WIDTH=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"ITEM_SPACE_HEIGHT") ) { ITEM_SPACE_HEIGHT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LevelSelector_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("packID"));
	outFields->push(HX_CSTRING("maxItem"));
	outFields->push(HX_CSTRING("completedItem"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MAX_LINE_ITEM"),
	HX_CSTRING("ITEM_SPACE_WIDTH"),
	HX_CSTRING("ITEM_SPACE_HEIGHT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("packID"),
	HX_CSTRING("maxItem"),
	HX_CSTRING("completedItem"),
	HX_CSTRING("onItemClick"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LevelSelector_obj::MAX_LINE_ITEM,"MAX_LINE_ITEM");
	HX_MARK_MEMBER_NAME(LevelSelector_obj::ITEM_SPACE_WIDTH,"ITEM_SPACE_WIDTH");
	HX_MARK_MEMBER_NAME(LevelSelector_obj::ITEM_SPACE_HEIGHT,"ITEM_SPACE_HEIGHT");
};

Class LevelSelector_obj::__mClass;

void LevelSelector_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.LevelSelector"), hx::TCanCast< LevelSelector_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LevelSelector_obj::__boot()
{
	hx::Static(MAX_LINE_ITEM) = (int)5;
	hx::Static(ITEM_SPACE_WIDTH) = (int)57;
	hx::Static(ITEM_SPACE_HEIGHT) = (int)60;
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
