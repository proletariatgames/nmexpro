#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_com_mybo_menuscene_UserStar
#include <com/mybo/menuscene/UserStar.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace menuscene{

Void UserStar_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",24)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",25)
	::com::mybo::framework::core::Facade facade = ::com::mybo::framework::core::Facade_obj::getInstance();
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",26)
	this->addChild(facade->getBitmap(HX_CSTRING("pack_star"),null()));
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",28)
	this->starNum = ::com::mybo::framework::display::BitmapNumber_obj::__new(facade->getTile(HX_CSTRING("num15")),null());
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",29)
	this->starNum->nmeSetX((int)60);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",30)
	this->starNum->nmeSetY((int)15);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",31)
	this->addChild(this->starNum);
	HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",33)
	this->starNum->drawNumber(::com::mybo::data::UserData_obj::getInstance(null())->getStar());
}
;
	return null();
}

UserStar_obj::~UserStar_obj() { }

Dynamic UserStar_obj::__CreateEmpty() { return  new UserStar_obj; }
hx::ObjectPtr< UserStar_obj > UserStar_obj::__new()
{  hx::ObjectPtr< UserStar_obj > result = new UserStar_obj();
	result->__construct();
	return result;}

Dynamic UserStar_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UserStar_obj > result = new UserStar_obj();
	result->__construct();
	return result;}

Void UserStar_obj::update( ){
{
		HX_SOURCE_PUSH("UserStar_obj::update")
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",36)
		Array< ::com::mybo::menuscene::UserStar > me = Array_obj< ::com::mybo::menuscene::UserStar >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",37)
		int oldValue = this->starNum->value;
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",38)
		Array< int > newValue = Array_obj< int >::__new().Add(::com::mybo::data::UserData_obj::getInstance(null())->getStar());
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",39)
		int diff = (newValue->__get((int)0) - oldValue);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",41)
		Array< int > i = Array_obj< int >::__new().Add(oldValue);
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",42)
		Array< ::haxe::Timer > timer = Array_obj< ::haxe::Timer >::__new().Add(::haxe::Timer_obj::__new((int)30));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",43)
		Array< int > step = Array_obj< int >::__new().Add(::Std_obj::_int((double(diff) / double((int)15))));
		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",44)
		step[(int)0] = (  (((diff > (int)0))) ? int((step->__get((int)0) + (int)1)) : int((step->__get((int)0) - (int)1)) );

		HX_BEGIN_LOCAL_FUNC_S5(hx::LocalFunc,_Function_1_1,Array< int >,newValue,Array< ::haxe::Timer >,timer,Array< int >,step,Array< int >,i,Array< ::com::mybo::menuscene::UserStar >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",46)
				if (((step->__get((int)0) > (int)0))){
					HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",46)
					i[(int)0] = (  ((((i->__get((int)0) + step->__get((int)0)) < newValue->__get((int)0)))) ? int((i->__get((int)0) + step->__get((int)0))) : int(newValue->__get((int)0)) );
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",48)
					i[(int)0] = (  ((((i->__get((int)0) + step->__get((int)0)) > newValue->__get((int)0)))) ? int((i->__get((int)0) + step->__get((int)0))) : int(newValue->__get((int)0)) );
				}
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",51)
				me->__get((int)0)->starNum->drawNumber(i->__get((int)0));
				HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",53)
				if (((i->__get((int)0) == newValue->__get((int)0)))){
					HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",53)
					timer->__get((int)0)->stop();
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/menuscene/UserStar.hx",45)
		timer->__get((int)0)->run =  Dynamic(new _Function_1_1(newValue,timer,step,i,me));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(UserStar_obj,update,(void))


UserStar_obj::UserStar_obj()
{
}

void UserStar_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UserStar);
	HX_MARK_MEMBER_NAME(starNum,"starNum");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic UserStar_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"starNum") ) { return starNum; }
	}
	return super::__Field(inName);
}

Dynamic UserStar_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"starNum") ) { starNum=inValue.Cast< ::com::mybo::framework::display::BitmapNumber >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void UserStar_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("starNum"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("starNum"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class UserStar_obj::__mClass;

void UserStar_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.menuscene.UserStar"), hx::TCanCast< UserStar_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void UserStar_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace menuscene
