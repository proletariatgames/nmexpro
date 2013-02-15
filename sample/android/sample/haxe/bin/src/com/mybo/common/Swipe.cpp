#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_Swipe
#include <com/mybo/common/Swipe.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
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
#ifndef INCLUDED_nme_display_PixelSnapping
#include <nme/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
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
namespace common{

Void Swipe_obj::__construct(Array< ::nmex::display::DisplayObject > views,Array< ::nme::display::BitmapData > indicator)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",41)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",43)
	this->index = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",44)
	this->pages = views;
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",45)
	this->pageLength = this->pages->length;
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",47)
	if (((indicator != null()))){
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",48)
		this->indicatorActive = indicator->__get((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",49)
		this->indicatorInactive = indicator->__get((int)1);
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",53)
	this->pageContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",54)
	this->addChild(this->pageContainer);
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",56)
	this->touchView = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",57)
	this->nmeGetGraphics()->beginFill((int)0,(int)0);
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",58)
	this->nmeGetGraphics()->drawRect((int)0,(int)0,(int)320,(int)360);
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",59)
	this->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",60)
	this->addChild(this->touchView);
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",62)
	{
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",62)
		int _g1 = (int)0;
		int _g = this->pages->length;
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",62)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",62)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",63)
			this->pageContainer->addChild(this->pages->__get(i));
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",64)
			this->pages->__get(i)->nmeSetX(((((int)320 * i) + (double((int)320) / double((int)2))) - (double(this->pages->__get(i)->nmeGetWidth()) / double((int)2))));
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",67)
	this->pageContainer->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onDown_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",68)
	this->pageContainer->addEventListener(::nme::events::MouseEvent_obj::MOUSE_MOVE,this->onMove_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",69)
	this->pageContainer->addEventListener(::nme::events::MouseEvent_obj::MOUSE_OUT,this->onOut_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",70)
	this->pageContainer->addEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onUp_dyn(),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",72)
	this->drawIndicator();
}
;
	return null();
}

Swipe_obj::~Swipe_obj() { }

Dynamic Swipe_obj::__CreateEmpty() { return  new Swipe_obj; }
hx::ObjectPtr< Swipe_obj > Swipe_obj::__new(Array< ::nmex::display::DisplayObject > views,Array< ::nme::display::BitmapData > indicator)
{  hx::ObjectPtr< Swipe_obj > result = new Swipe_obj();
	result->__construct(views,indicator);
	return result;}

Dynamic Swipe_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Swipe_obj > result = new Swipe_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Swipe_obj::drawIndicator( ){
{
		HX_SOURCE_PUSH("Swipe_obj::drawIndicator")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",76)
		if (((null() == this->indicatorContainer))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",77)
			this->indicatorContainer = ::nme::display::Sprite_obj::__new();
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",78)
			this->addChild(this->indicatorContainer);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",79)
			while(((this->indicatorContainer->nmeGetNumChildren() != (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",80)
				this->indicatorContainer->removeChildAt((int)0);
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",85)
		{
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",85)
			int _g1 = (int)0;
			int _g = this->pages->length;
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",85)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",85)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",86)
				::nmex::display::Bitmap point;
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",87)
				if (((this->index != i))){
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",87)
					point = ::nmex::display::Bitmap_obj::__new(this->indicatorInactive,null(),true);
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",90)
					point = ::nmex::display::Bitmap_obj::__new(this->indicatorActive,null(),true);
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",91)
					{
						HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",91)
						::nmex::display::Bitmap _g2 = point;
						HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",91)
						_g2->nmeSetY((_g2->nmeGetY() - (int)2));
					}
				}
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",93)
				{
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",93)
					::nmex::display::Bitmap _g2 = point;
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",93)
					_g2->nmeSetX((_g2->nmeGetX() + (i * (int)20)));
				}
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",94)
				this->indicatorContainer->addChild(point);
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",97)
		this->indicatorContainer->nmeSetX(((double((int)320) / double((int)2)) - (double(this->indicatorContainer->nmeGetWidth()) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",98)
		this->indicatorContainer->nmeSetY((int)380);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Swipe_obj,drawIndicator,(void))

Void Swipe_obj::destroy( ){
{
		HX_SOURCE_PUSH("Swipe_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",103)
		this->pageContainer->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onDown_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",104)
		this->pageContainer->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_MOVE,this->onMove_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",105)
		this->pageContainer->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_OUT,this->onOut_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",106)
		this->pageContainer->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onUp_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Swipe_obj,destroy,(void))

Void Swipe_obj::onDown( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("Swipe_obj::onDown")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",111)
		double mx = this->touchView->nmeGetMouseX();
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",112)
		double my = this->touchView->nmeGetMouseY();
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",113)
		this->mouseDownPos = ::nme::geom::Point_obj::__new(mx,my);
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",114)
		this->isMouseDown = true;
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",115)
		this->preX = this->nmeGetStage()->nmeGetMouseX();
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",117)
		if (((null() != this->mtween))){
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",118)
			this->mtween->stop();
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",119)
			this->pageContainer->nmeSetX((-(this->index) * (int)320));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Swipe_obj,onDown,(void))

Void Swipe_obj::onMove( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("Swipe_obj::onMove")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",123)
		if ((this->isMouseDown)){
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",125)
			this->speed = (this->nmeGetMouseX() - this->preX);
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",126)
			this->preX = this->nmeGetMouseX();
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",127)
			{
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",127)
				::nme::display::Sprite _g = this->pageContainer;
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",127)
				_g->nmeSetX((_g->nmeGetX() + this->speed));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Swipe_obj,onMove,(void))

Void Swipe_obj::onOut( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("Swipe_obj::onOut")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",131)
		this->isMouseDown = false;
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",132)
		this->positionFix();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Swipe_obj,onOut,(void))

Void Swipe_obj::onUp( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("Swipe_obj::onUp")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",135)
		this->isMouseDown = false;
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",136)
		double mx = this->touchView->nmeGetMouseX();
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",137)
		double my = this->touchView->nmeGetMouseY();
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",139)
		this->positionFix();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Swipe_obj,onUp,(void))

Void Swipe_obj::positionFix( ){
{
		HX_SOURCE_PUSH("Swipe_obj::positionFix")
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",143)
		{
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",143)
			int _g1 = (int)0;
			int _g = this->pages->length;
			HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",143)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",143)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",144)
				if (((this->pageContainer->nmeGetX() >= ((int)-320 * ((i + 0.5)))))){
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",145)
					this->index = i;
					HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",146)
					break;
				}
			}
		}
		struct _Function_1_1{
			inline static Dynamic Block( ::com::mybo::common::Swipe_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , (-(__this->index) * (int)320),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",150)
		this->mtween = ::com::mybo::framework::tweener::MTween_obj::to(this->pageContainer,0.2,_Function_1_1::Block(this),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/Swipe.hx",152)
		this->drawIndicator();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Swipe_obj,positionFix,(void))

int Swipe_obj::pageWidth;


Swipe_obj::Swipe_obj()
{
}

void Swipe_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Swipe);
	HX_MARK_MEMBER_NAME(pages,"pages");
	HX_MARK_MEMBER_NAME(indicatorActive,"indicatorActive");
	HX_MARK_MEMBER_NAME(indicatorInactive,"indicatorInactive");
	HX_MARK_MEMBER_NAME(indicatorContainer,"indicatorContainer");
	HX_MARK_MEMBER_NAME(pageContainer,"pageContainer");
	HX_MARK_MEMBER_NAME(touchView,"touchView");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_MEMBER_NAME(pageLength,"pageLength");
	HX_MARK_MEMBER_NAME(isMouseDown,"isMouseDown");
	HX_MARK_MEMBER_NAME(mouseDownPos,"mouseDownPos");
	HX_MARK_MEMBER_NAME(isRunEnterFrame,"isRunEnterFrame");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(preX,"preX");
	HX_MARK_MEMBER_NAME(mtween,"mtween");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Swipe_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"preX") ) { return preX; }
		if (HX_FIELD_EQ(inName,"onUp") ) { return onUp_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pages") ) { return pages; }
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"onOut") ) { return onOut_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mtween") ) { return mtween; }
		if (HX_FIELD_EQ(inName,"onDown") ) { return onDown_dyn(); }
		if (HX_FIELD_EQ(inName,"onMove") ) { return onMove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"pageWidth") ) { return pageWidth; }
		if (HX_FIELD_EQ(inName,"touchView") ) { return touchView; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"pageLength") ) { return pageLength; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isMouseDown") ) { return isMouseDown; }
		if (HX_FIELD_EQ(inName,"positionFix") ) { return positionFix_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mouseDownPos") ) { return mouseDownPos; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pageContainer") ) { return pageContainer; }
		if (HX_FIELD_EQ(inName,"drawIndicator") ) { return drawIndicator_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"indicatorActive") ) { return indicatorActive; }
		if (HX_FIELD_EQ(inName,"isRunEnterFrame") ) { return isRunEnterFrame; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"indicatorInactive") ) { return indicatorInactive; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"indicatorContainer") ) { return indicatorContainer; }
	}
	return super::__Field(inName);
}

Dynamic Swipe_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"preX") ) { preX=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pages") ) { pages=inValue.Cast< Array< ::nmex::display::DisplayObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mtween") ) { mtween=inValue.Cast< ::com::mybo::framework::tweener::MTween >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"pageWidth") ) { pageWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchView") ) { touchView=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"pageLength") ) { pageLength=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isMouseDown") ) { isMouseDown=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mouseDownPos") ) { mouseDownPos=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pageContainer") ) { pageContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"indicatorActive") ) { indicatorActive=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isRunEnterFrame") ) { isRunEnterFrame=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"indicatorInactive") ) { indicatorInactive=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"indicatorContainer") ) { indicatorContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Swipe_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pages"));
	outFields->push(HX_CSTRING("indicatorActive"));
	outFields->push(HX_CSTRING("indicatorInactive"));
	outFields->push(HX_CSTRING("indicatorContainer"));
	outFields->push(HX_CSTRING("pageContainer"));
	outFields->push(HX_CSTRING("touchView"));
	outFields->push(HX_CSTRING("index"));
	outFields->push(HX_CSTRING("pageLength"));
	outFields->push(HX_CSTRING("isMouseDown"));
	outFields->push(HX_CSTRING("mouseDownPos"));
	outFields->push(HX_CSTRING("isRunEnterFrame"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("preX"));
	outFields->push(HX_CSTRING("mtween"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("pageWidth"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pages"),
	HX_CSTRING("indicatorActive"),
	HX_CSTRING("indicatorInactive"),
	HX_CSTRING("indicatorContainer"),
	HX_CSTRING("pageContainer"),
	HX_CSTRING("touchView"),
	HX_CSTRING("index"),
	HX_CSTRING("pageLength"),
	HX_CSTRING("isMouseDown"),
	HX_CSTRING("mouseDownPos"),
	HX_CSTRING("isRunEnterFrame"),
	HX_CSTRING("speed"),
	HX_CSTRING("preX"),
	HX_CSTRING("mtween"),
	HX_CSTRING("drawIndicator"),
	HX_CSTRING("destroy"),
	HX_CSTRING("onDown"),
	HX_CSTRING("onMove"),
	HX_CSTRING("onOut"),
	HX_CSTRING("onUp"),
	HX_CSTRING("positionFix"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Swipe_obj::pageWidth,"pageWidth");
};

Class Swipe_obj::__mClass;

void Swipe_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.Swipe"), hx::TCanCast< Swipe_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Swipe_obj::__boot()
{
	hx::Static(pageWidth) = (int)320;
}

} // end namespace com
} // end namespace mybo
} // end namespace common
