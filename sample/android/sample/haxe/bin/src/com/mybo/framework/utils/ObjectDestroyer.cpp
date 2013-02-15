#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_utils_ObjectDestroyer
#include <com/mybo/framework/utils/ObjectDestroyer.h>
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
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
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
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace utils{

Void ObjectDestroyer_obj::__construct()
{
	return null();
}

ObjectDestroyer_obj::~ObjectDestroyer_obj() { }

Dynamic ObjectDestroyer_obj::__CreateEmpty() { return  new ObjectDestroyer_obj; }
hx::ObjectPtr< ObjectDestroyer_obj > ObjectDestroyer_obj::__new()
{  hx::ObjectPtr< ObjectDestroyer_obj > result = new ObjectDestroyer_obj();
	result->__construct();
	return result;}

Dynamic ObjectDestroyer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectDestroyer_obj > result = new ObjectDestroyer_obj();
	result->__construct();
	return result;}

Void ObjectDestroyer_obj::destroyView( ::nme::display::DisplayObjectContainer a){
{
		HX_SOURCE_PUSH("ObjectDestroyer_obj::destroyView")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",15)
		int n = a->nmeGetNumChildren();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",16)
		::nmex::display::DisplayObject b;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",17)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",17)
			int _g = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",17)
			while(((_g < n))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",17)
				int i = (_g)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",19)
				b = a->getChildAt(((n - i) - (int)1));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",21)
				a->removeChild(b);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",24)
				if ((::Std_obj::is(b,hx::ClassOf< ::nmex::display::Bitmap >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",24)
					(hx::TCast< nmex::display::Bitmap >::cast(b))->nmeSetBitmapData(null());
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",30)
				if ((::Std_obj::is(b,hx::ClassOf< ::com::mybo::framework::display::BitmapObject >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",30)
					(hx::TCast< com::mybo::framework::display::BitmapObject >::cast(b))->destroy();
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",34)
				if ((::Std_obj::is(b,hx::ClassOf< ::nmex::display::DisplayObject >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",34)
					(hx::TCast< nmex::display::DisplayObject >::cast(b))->nmeGetGraphics()->clear();
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",38)
				if ((::Std_obj::is(b,hx::ClassOf< ::nme::display::DisplayObjectContainer >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",38)
					::com::mybo::framework::utils::ObjectDestroyer_obj::destroyView(hx::TCast< nme::display::DisplayObjectContainer >::cast(b));
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",47)
		::com::mybo::framework::utils::ObjectDestroyer_obj::destroyFields(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectDestroyer_obj,destroyView,(void))

Void ObjectDestroyer_obj::destroyFields( Dynamic t){
{
		HX_SOURCE_PUSH("ObjectDestroyer_obj::destroyFields")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",50)
		Array< ::String > fields = ::Reflect_obj::fields(t);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",51)
		Dynamic o;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",52)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",52)
			int _g1 = (int)0;
			int _g = fields->length;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",52)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",52)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",55)
				if (((bool((fields->__get(i) == HX_CSTRING("parent"))) || bool((fields->__get(i) == HX_CSTRING("nmeParent")))))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",55)
					continue;
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",58)
				if (((fields->__get(i) == HX_CSTRING("nmeTarget")))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",58)
					continue;
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",62)
				o = ::Reflect_obj::field(t,fields->__get(i));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",63)
				if (((o == t))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",64)
					o = null();
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",65)
					continue;
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",67)
				if ((::Std_obj::is(o,hx::ClassOf< ::nme::display::Stage >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",67)
					continue;
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",71)
				if ((::Std_obj::is(o,hx::ClassOf< Array<int> >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",71)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",73)
						o = null();
					}
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",76)
				if ((::Std_obj::is(o,hx::ClassOf< ::haxe::Timer >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",76)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",78)
						o->__FieldRef(HX_CSTRING("run")) = null();
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",79)
						o = null();
					}
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",82)
				if ((::Reflect_obj::isFunction(o))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",83)
					o = null();
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",85)
				if ((::Std_obj::is(o,hx::ClassOf< ::nmex::display::Bitmap >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",85)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",87)
						(hx::TCast< nmex::display::Bitmap >::cast(o))->nmeSetBitmapData(null());
					}
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",90)
				if ((::Std_obj::is(o,hx::ClassOf< ::com::mybo::framework::display::BitmapObject >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",90)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",92)
						(hx::TCast< com::mybo::framework::display::BitmapObject >::cast(o))->destroy();
					}
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",95)
				if ((::Std_obj::is(o,hx::ClassOf< ::nme::display::DisplayObjectContainer >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",95)
					if (((bool((o != null())) && bool((o != t))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",96)
						::com::mybo::framework::utils::ObjectDestroyer_obj::destroyView(hx::TCast< nme::display::DisplayObjectContainer >::cast(o));
					}
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",103)
				if ((::Std_obj::is(o,hx::ClassOf< ::nmex::display::DisplayObject >()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",103)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",105)
						(hx::TCast< nmex::display::DisplayObject >::cast(o))->nmeGetGraphics()->clear();
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",107)
						if ((((hx::TCast< nmex::display::DisplayObject >::cast(o))->nmeGetParent() != null()))){
							HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",108)
							(hx::TCast< nmex::display::DisplayObject >::cast(o))->nmeGetParent()->removeChild(hx::TCast< nmex::display::DisplayObject >::cast(o));
						}
					}
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",111)
				if ((::Reflect_obj::isObject(o))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",111)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/ObjectDestroyer.hx",112)
						o = null();
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ObjectDestroyer_obj,destroyFields,(void))


ObjectDestroyer_obj::ObjectDestroyer_obj()
{
}

void ObjectDestroyer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectDestroyer);
	HX_MARK_END_CLASS();
}

Dynamic ObjectDestroyer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"destroyView") ) { return destroyView_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"destroyFields") ) { return destroyFields_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ObjectDestroyer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ObjectDestroyer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("destroyView"),
	HX_CSTRING("destroyFields"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ObjectDestroyer_obj::__mClass;

void ObjectDestroyer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.utils.ObjectDestroyer"), hx::TCanCast< ObjectDestroyer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ObjectDestroyer_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace utils
