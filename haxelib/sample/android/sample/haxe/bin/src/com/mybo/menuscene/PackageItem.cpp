#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
#endif
#ifndef INCLUDED_com_mybo_common_ProgressBar
#include <com/mybo/common/ProgressBar.h>
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
#ifndef INCLUDED_com_mybo_menuscene_PackageItem
#include <com/mybo/menuscene/PackageItem.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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

Void PackageItem_obj::__construct(int inIndex,bool locked,int completedLevels,int totalLevels)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",19)
	Array< int > totalLevels1 = Array_obj< int >::__new().Add(totalLevels);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",19)
	Array< int > completedLevels1 = Array_obj< int >::__new().Add(completedLevels);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",19)
	Array< ::com::mybo::menuscene::PackageItem > me = Array_obj< ::com::mybo::menuscene::PackageItem >::__new().Add(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",20)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",22)
	this->index = inIndex;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",23)
	this->isLocked = locked;
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",25)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",27)
	if ((locked)){
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",28)
		::nmex::display::Bitmap item = facade->getBitmap(HX_CSTRING("packs_lock"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",29)
		this->addChild(item);
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",31)
		::nmex::display::Bitmap bg = facade->getBitmap(HX_CSTRING("packs_on"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",32)
		this->addChild(bg);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",34)
		::com::mybo::framework::display::BitmapNumber itemNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(facade->getTile(HX_CSTRING("num1")),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",35)
		itemNum->drawNumber(this->index);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",36)
		itemNum->nmeSetX(((int)32 - (double(itemNum->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",37)
		itemNum->nmeSetY((int)20);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",38)
		this->addChild(itemNum);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",40)
		this->progressBar = ::com::mybo::common::ProgressBar_obj::__new(facade->getBitmap(HX_CSTRING("packs_per"),null())->bitmapData);

		HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_2_1,Array< int >,totalLevels1,Array< ::com::mybo::menuscene::PackageItem >,me,Array< int >,completedLevels1)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",41)
				me->__get((int)0)->progressBar->update((double(completedLevels1->__get((int)0)) / double(totalLevels1->__get((int)0))));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",41)
		::haxe::Timer_obj::delay( Dynamic(new _Function_2_1(totalLevels1,me,completedLevels1)),(int)750);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",44)
		this->progressBar->nmeSetX((int)51);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",45)
		this->progressBar->nmeSetY((int)9);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",46)
		this->addChild(this->progressBar);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",49)
		this->initPercentNum(completedLevels1->__get((int)0),totalLevels1->__get((int)0));
	}
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",52)
	this->addEventListener(::nme::events::MouseEvent_obj::CLICK,this->onClick_dyn(),null(),null(),null());
}
;
	return null();
}

PackageItem_obj::~PackageItem_obj() { }

Dynamic PackageItem_obj::__CreateEmpty() { return  new PackageItem_obj; }
hx::ObjectPtr< PackageItem_obj > PackageItem_obj::__new(int inIndex,bool locked,int completedLevels,int totalLevels)
{  hx::ObjectPtr< PackageItem_obj > result = new PackageItem_obj();
	result->__construct(inIndex,locked,completedLevels,totalLevels);
	return result;}

Dynamic PackageItem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PackageItem_obj > result = new PackageItem_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void PackageItem_obj::onClick( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("PackageItem_obj::onClick")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",56)
		::com::mybo::common::GameEvent e1 = ::com::mybo::common::GameEvent_obj::__new(HX_CSTRING("packSelected"),Array_obj< int >::__new().Add(this->index));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",58)
		this->dispatchEvent(e1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PackageItem_obj,onClick,(void))

Void PackageItem_obj::initPercentNum( int completedLevels,int totalLevels){
{
		HX_SOURCE_PUSH("PackageItem_obj::initPercentNum")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",66)
		::nme::display::Sprite percentLable = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",68)
		::com::mybo::framework::display::BitmapNumber completedNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getTile(HX_CSTRING("num_pack_percent")),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",69)
		completedNum->nmeSetX((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",70)
		completedNum->drawNumber(completedLevels);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",71)
		percentLable->addChild(completedNum);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",73)
		::nmex::display::Bitmap delimiter = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("gang"),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",74)
		delimiter->nmeSetX((::Std_obj::_int((double(completedNum->nmeGetWidth()) / double((int)2))) * (int)2));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",75)
		percentLable->addChild(delimiter);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",77)
		::com::mybo::framework::display::BitmapNumber totalNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getTile(HX_CSTRING("num_pack_percent")),null());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",78)
		totalNum->drawNumber(totalLevels);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",79)
		totalNum->nmeSetX(::Std_obj::_int((delimiter->nmeGetX() + delimiter->nmeGetWidth())));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",80)
		percentLable->addChild(totalNum);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",82)
		percentLable->nmeSetY((int)20);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",84)
		double percent = (double(completedLevels) / double(totalLevels));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",86)
		if (((percent >= 0.6))){
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",86)
			percentLable->nmeSetX(((this->progressBar->nmeGetX() + (double((this->progressBar->getMaxWidthInPoint() * percent)) / double((int)2))) - (double(percentLable->nmeGetWidth()) / double((int)2))));
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",88)
			percentLable->nmeSetX(((this->nmeGetWidth() - percentLable->nmeGetWidth()) - (int)26));
		}
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",92)
		percentLable->nmeSetX(::Std_obj::_int(percentLable->nmeGetX()));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/PackageItem.hx",94)
		this->addChild(percentLable);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PackageItem_obj,initPercentNum,(void))


PackageItem_obj::PackageItem_obj()
{
}

void PackageItem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PackageItem);
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_MEMBER_NAME(isLocked,"isLocked");
	HX_MARK_MEMBER_NAME(progressBar,"progressBar");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PackageItem_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLocked") ) { return isLocked; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"progressBar") ) { return progressBar; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initPercentNum") ) { return initPercentNum_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PackageItem_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLocked") ) { isLocked=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"progressBar") ) { progressBar=inValue.Cast< ::com::mybo::common::ProgressBar >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PackageItem_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("index"));
	outFields->push(HX_CSTRING("isLocked"));
	outFields->push(HX_CSTRING("progressBar"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("index"),
	HX_CSTRING("isLocked"),
	HX_CSTRING("progressBar"),
	HX_CSTRING("onClick"),
	HX_CSTRING("initPercentNum"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PackageItem_obj::__mClass;

void PackageItem_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.PackageItem"), hx::TCanCast< PackageItem_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PackageItem_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
