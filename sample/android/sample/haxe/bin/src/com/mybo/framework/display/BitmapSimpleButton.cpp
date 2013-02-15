#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapSimpleButton
#include <com/mybo/framework/display/BitmapSimpleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
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
#ifndef INCLUDED_nme_events_TouchEvent
#include <nme/events/TouchEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
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
namespace display{

Void BitmapSimpleButton_obj::__construct(::nmex::display::Bitmap inBitmap,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",37)
	super::__construct();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",38)
	this->bitmap = inBitmap;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",39)
	this->bitmapPos = ::nme::geom::Point_obj::__new(this->bitmap->nmeGetX(),this->bitmap->nmeGetY());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",41)
	this->onClick = onClick;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",42)
	this->onClickObj = onClickObj;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",43)
	this->onClickParams = onClickParams;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",47)
	this->downInside = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",49)
	this->bitmapWrap = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",50)
	this->bitmapWrap->nmeSetX((double(this->bitmap->nmeGetWidth()) / double((int)2)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",51)
	this->bitmapWrap->nmeSetY((double(this->bitmap->nmeGetHeight()) / double((int)2)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",52)
	this->bitmap->nmeSetX((double(-(this->bitmap->nmeGetWidth())) / double((int)2)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",53)
	this->bitmap->nmeSetY((double(-(this->bitmap->nmeGetHeight())) / double((int)2)));
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",55)
	this->bitmapWrap->addChild(this->bitmap);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",56)
	this->addChild(this->bitmapWrap);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",58)
	this->scaleAble = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",60)
	this->nmeGetGraphics()->beginFill((int)16777215,(int)0);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",61)
	this->nmeGetGraphics()->drawRect((int)0,(int)0,this->bitmap->nmeGetWidth(),this->bitmap->nmeGetHeight());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",62)
	this->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",65)
	this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",66)
	this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",67)
	this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",70)
	this->addEventListener(::nme::events::TouchEvent_obj::TOUCH_OUT,this->onMouseOut_dyn(),null(),null(),null());
}
;
	return null();
}

BitmapSimpleButton_obj::~BitmapSimpleButton_obj() { }

Dynamic BitmapSimpleButton_obj::__CreateEmpty() { return  new BitmapSimpleButton_obj; }
hx::ObjectPtr< BitmapSimpleButton_obj > BitmapSimpleButton_obj::__new(::nmex::display::Bitmap inBitmap,Dynamic onClick,Dynamic onClickParams,Dynamic onClickObj)
{  hx::ObjectPtr< BitmapSimpleButton_obj > result = new BitmapSimpleButton_obj();
	result->__construct(inBitmap,onClick,onClickParams,onClickObj);
	return result;}

Dynamic BitmapSimpleButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapSimpleButton_obj > result = new BitmapSimpleButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BitmapSimpleButton_obj::onMouseDown( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapSimpleButton_obj::onMouseDown")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",75)
		if (((this->tweener != null()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",76)
			this->tweener->stop();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",77)
		this->downInside = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",78)
		this->bitmapWrap->nmeSetScaleX((int)1);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",79)
		this->bitmapWrap->nmeSetScaleY((int)1);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",80)
		if ((this->scaleAble)){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("scaleX") , 1.1,false);
					__result->Add(HX_CSTRING("scaleY") , 1.1,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",81)
			this->tweener = ::com::mybo::framework::tweener::MTween_obj::to(this->bitmapWrap,0.1,_Function_2_1::Block(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapSimpleButton_obj,onMouseDown,(void))

Void BitmapSimpleButton_obj::onMouseUp( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapSimpleButton_obj::onMouseUp")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",84)
		if ((this->downInside)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",84)
			if (((this->onClick != null()))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",86)
				::Reflect_obj::callMethod(this->onClickObj,this->onClick,this->onClickParams);
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",88)
		this->downInside = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",90)
		if (((this->tweener != null()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",91)
			this->tweener->stop();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",92)
		if ((this->scaleAble)){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("scaleX") , (int)1,false);
					__result->Add(HX_CSTRING("scaleY") , (int)1,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",93)
			this->tweener = ::com::mybo::framework::tweener::MTween_obj::to(this->bitmapWrap,0.1,_Function_2_1::Block(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapSimpleButton_obj,onMouseUp,(void))

Void BitmapSimpleButton_obj::onMouseOut( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BitmapSimpleButton_obj::onMouseOut")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",96)
		if (((this->tweener != null()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",97)
			this->tweener->stop();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",98)
		if ((this->scaleAble)){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("scaleX") , (int)1,false);
					__result->Add(HX_CSTRING("scaleY") , (int)1,false);
					return __result;
				}
			};
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",99)
			this->tweener = ::com::mybo::framework::tweener::MTween_obj::to(this->bitmapWrap,0.1,_Function_2_1::Block(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapSimpleButton_obj,onMouseOut,(void))

Void BitmapSimpleButton_obj::click( Dynamic onClick,Dynamic params,Dynamic onClickObj){
{
		HX_SOURCE_PUSH("BitmapSimpleButton_obj::click")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",124)
		this->onClick = onClick;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",125)
		this->onClickObj = onClickObj;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",126)
		this->onClickParams = params;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapSimpleButton_obj,click,(void))

Void BitmapSimpleButton_obj::destroy( ){
{
		HX_SOURCE_PUSH("BitmapSimpleButton_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",130)
		this->onClick = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",131)
		this->onClickObj = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",132)
		this->onClickParams = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",133)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",134)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_OUT,this->onMouseUp_dyn(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",135)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapSimpleButton.hx",138)
		this->removeEventListener(::nme::events::TouchEvent_obj::TOUCH_OUT,this->onMouseOut_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapSimpleButton_obj,destroy,(void))


BitmapSimpleButton_obj::BitmapSimpleButton_obj()
{
}

void BitmapSimpleButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapSimpleButton);
	HX_MARK_MEMBER_NAME(hit,"hit");
	HX_MARK_MEMBER_NAME(onClick,"onClick");
	HX_MARK_MEMBER_NAME(onClickObj,"onClickObj");
	HX_MARK_MEMBER_NAME(onClickParams,"onClickParams");
	HX_MARK_MEMBER_NAME(downInside,"downInside");
	HX_MARK_MEMBER_NAME(bitmapPos,"bitmapPos");
	HX_MARK_MEMBER_NAME(bitmap,"bitmap");
	HX_MARK_MEMBER_NAME(bitmapWrap,"bitmapWrap");
	HX_MARK_MEMBER_NAME(scaleAble,"scaleAble");
	HX_MARK_MEMBER_NAME(tweener,"tweener");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapSimpleButton_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hit") ) { return hit; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"click") ) { return click_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bitmap") ) { return bitmap; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick; }
		if (HX_FIELD_EQ(inName,"tweener") ) { return tweener; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bitmapPos") ) { return bitmapPos; }
		if (HX_FIELD_EQ(inName,"scaleAble") ) { return scaleAble; }
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onClickObj") ) { return onClickObj; }
		if (HX_FIELD_EQ(inName,"downInside") ) { return downInside; }
		if (HX_FIELD_EQ(inName,"bitmapWrap") ) { return bitmapWrap; }
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return onMouseOut_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onClickParams") ) { return onClickParams; }
	}
	return super::__Field(inName);
}

Dynamic BitmapSimpleButton_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hit") ) { hit=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bitmap") ) { bitmap=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { onClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweener") ) { tweener=inValue.Cast< ::com::mybo::framework::tweener::MTween >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bitmapPos") ) { bitmapPos=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleAble") ) { scaleAble=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onClickObj") ) { onClickObj=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"downInside") ) { downInside=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bitmapWrap") ) { bitmapWrap=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onClickParams") ) { onClickParams=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapSimpleButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hit"));
	outFields->push(HX_CSTRING("onClick"));
	outFields->push(HX_CSTRING("onClickObj"));
	outFields->push(HX_CSTRING("onClickParams"));
	outFields->push(HX_CSTRING("downInside"));
	outFields->push(HX_CSTRING("bitmapPos"));
	outFields->push(HX_CSTRING("bitmap"));
	outFields->push(HX_CSTRING("bitmapWrap"));
	outFields->push(HX_CSTRING("scaleAble"));
	outFields->push(HX_CSTRING("tweener"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("hit"),
	HX_CSTRING("onClick"),
	HX_CSTRING("onClickObj"),
	HX_CSTRING("onClickParams"),
	HX_CSTRING("downInside"),
	HX_CSTRING("bitmapPos"),
	HX_CSTRING("bitmap"),
	HX_CSTRING("bitmapWrap"),
	HX_CSTRING("scaleAble"),
	HX_CSTRING("tweener"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("onMouseOut"),
	HX_CSTRING("click"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapSimpleButton_obj::__mClass;

void BitmapSimpleButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapSimpleButton"), hx::TCanCast< BitmapSimpleButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapSimpleButton_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
