#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_TouchUpDownContainer
#include <com/mybo/framework/display/TouchUpDownContainer.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
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
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
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

Void TouchUpDownContainer_obj::__construct(double width,double height,::nmex::display::DisplayObject view)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",28)
	super::__construct();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",29)
	this->visualWidth = width;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",30)
	this->visualHeight = height;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",31)
	this->view = view;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",32)
	this->isMouseDown = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",33)
	this->isRunEnterFrame = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",34)
	this->isActive = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",35)
	this->speed = (int)0;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",37)
	this->addChild(view);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",39)
	this->touchContainer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",41)
	this->touchContainer->nmeGetGraphics()->beginFill((int)0,(int)0);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",42)
	this->touchContainer->nmeGetGraphics()->drawRect((int)0,(int)0,view->nmeGetWidth(),view->nmeGetHeight());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",43)
	this->touchContainer->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",45)
	if (((this->visualHeight < view->nmeGetHeight()))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",46)
		this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onDown_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",47)
		this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_MOVE,this->onMove_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",49)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onUp_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",50)
		this->isActive = true;
	}
}
;
	return null();
}

TouchUpDownContainer_obj::~TouchUpDownContainer_obj() { }

Dynamic TouchUpDownContainer_obj::__CreateEmpty() { return  new TouchUpDownContainer_obj; }
hx::ObjectPtr< TouchUpDownContainer_obj > TouchUpDownContainer_obj::__new(double width,double height,::nmex::display::DisplayObject view)
{  hx::ObjectPtr< TouchUpDownContainer_obj > result = new TouchUpDownContainer_obj();
	result->__construct(width,height,view);
	return result;}

Dynamic TouchUpDownContainer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchUpDownContainer_obj > result = new TouchUpDownContainer_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void TouchUpDownContainer_obj::onDown( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::onDown")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",55)
		this->isMouseDown = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",56)
		this->pre = this->nmeGetMouseY();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",57)
		this->preTime = ::haxe::Timer_obj::stamp();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",60)
		if ((this->isRunEnterFrame)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",61)
			this->isRunEnterFrame = false;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",62)
			this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchUpDownContainer_obj,onDown,(void))

Void TouchUpDownContainer_obj::onMove( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::onMove")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",67)
		if (((::Math_obj::abs((this->pre - this->nmeGetMouseY())) <= (int)2))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",68)
			return null();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",70)
		this->addChild(this->touchContainer);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",72)
		if ((this->moveAble())){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",73)
			this->speed = (double(((this->nmeGetMouseY() - this->pre))) / double(((((::haxe::Timer_obj::stamp() - this->preTime)) * (int)60))));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",74)
			{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",74)
				::nmex::display::DisplayObject _g = this->view;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",74)
				_g->nmeSetY((_g->nmeGetY() + ((this->nmeGetMouseY() - this->pre))));
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",75)
			this->touchContainer->nmeSetY(this->view->nmeGetY());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",76)
			this->positionFix();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",78)
		this->pre = this->nmeGetMouseY();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",79)
		this->preTime = ::haxe::Timer_obj::stamp();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchUpDownContainer_obj,onMove,(void))

Void TouchUpDownContainer_obj::onOut( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::onOut")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",82)
		this->removeChild(this->touchContainer);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",84)
		this->isMouseDown = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",85)
		this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchUpDownContainer_obj,onOut,(void))

Void TouchUpDownContainer_obj::onUp( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::onUp")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",88)
		this->removeChild(this->touchContainer);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",90)
		this->isMouseDown = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchUpDownContainer_obj,onUp,(void))

Void TouchUpDownContainer_obj::onEnterFrame( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::onEnterFrame")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",95)
		this->isRunEnterFrame = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",97)
		if (((bool((bool(((::Math_obj::abs(this->speed) - (int)5) > (int)0)) && bool((this->view->nmeGetY() < (int)0)))) && bool((this->view->nmeGetY() > (this->visualHeight - this->view->nmeGetHeight())))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",98)
			this->speed = ((double(this->speed) / double(::Math_obj::abs(this->speed))) * ((::Math_obj::abs(this->speed) - (int)5)));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",99)
			{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",99)
				::nmex::display::DisplayObject _g = this->view;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",99)
				_g->nmeSetY((_g->nmeGetY() + this->speed));
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",100)
			this->touchContainer->nmeSetY(this->view->nmeGetY());
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",103)
			this->isRunEnterFrame = false;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",104)
			this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TouchUpDownContainer_obj,onEnterFrame,(void))

bool TouchUpDownContainer_obj::moveAble( ){
	HX_SOURCE_PUSH("TouchUpDownContainer_obj::moveAble")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",110)
	bool able = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",112)
	if (((bool(((this->nmeGetMouseY() - this->pre) > (int)0)) && bool((this->view->nmeGetY() >= (int)0))))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",112)
		able = false;
	}
	else{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",114)
		if (((bool(((this->nmeGetMouseY() - this->pre) < (int)0)) && bool((this->view->nmeGetY() <= (this->visualHeight - this->view->nmeGetHeight())))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",114)
			able = false;
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",116)
			if ((!(this->isMouseDown))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",116)
				able = false;
			}
		}
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",120)
	return able;
}


HX_DEFINE_DYNAMIC_FUNC0(TouchUpDownContainer_obj,moveAble,return )

Void TouchUpDownContainer_obj::positionFix( ){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::positionFix")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",124)
		if (((this->view->nmeGetY() > (int)0))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",124)
			this->view->nmeSetY((int)0);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",128)
		if (((this->view->nmeGetY() < (this->visualHeight - this->view->nmeGetHeight())))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",128)
			this->view->nmeSetY((this->visualHeight - this->view->nmeGetHeight()));
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",132)
		this->touchContainer->nmeSetY(this->view->nmeGetY());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TouchUpDownContainer_obj,positionFix,(void))

Void TouchUpDownContainer_obj::destroy( ){
{
		HX_SOURCE_PUSH("TouchUpDownContainer_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",135)
		if ((this->isActive)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",137)
			this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onDown_dyn(),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",138)
			this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_MOVE,this->onMove_dyn(),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",140)
			::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,this->onUp_dyn(),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",141)
			this->isActive = false;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",142)
			this->touchContainer = null();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/TouchUpDownContainer.hx",143)
			this->view = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TouchUpDownContainer_obj,destroy,(void))

int TouchUpDownContainer_obj::REDUCE_VALUE;


TouchUpDownContainer_obj::TouchUpDownContainer_obj()
{
}

void TouchUpDownContainer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchUpDownContainer);
	HX_MARK_MEMBER_NAME(touchContainer,"touchContainer");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(isMouseDown,"isMouseDown");
	HX_MARK_MEMBER_NAME(isActive,"isActive");
	HX_MARK_MEMBER_NAME(isRunEnterFrame,"isRunEnterFrame");
	HX_MARK_MEMBER_NAME(pre,"pre");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(visualWidth,"visualWidth");
	HX_MARK_MEMBER_NAME(visualHeight,"visualHeight");
	HX_MARK_MEMBER_NAME(preTime,"preTime");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TouchUpDownContainer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pre") ) { return pre; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		if (HX_FIELD_EQ(inName,"onUp") ) { return onUp_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"onOut") ) { return onOut_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onDown") ) { return onDown_dyn(); }
		if (HX_FIELD_EQ(inName,"onMove") ) { return onMove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"preTime") ) { return preTime; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isActive") ) { return isActive; }
		if (HX_FIELD_EQ(inName,"moveAble") ) { return moveAble_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isMouseDown") ) { return isMouseDown; }
		if (HX_FIELD_EQ(inName,"visualWidth") ) { return visualWidth; }
		if (HX_FIELD_EQ(inName,"positionFix") ) { return positionFix_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"REDUCE_VALUE") ) { return REDUCE_VALUE; }
		if (HX_FIELD_EQ(inName,"visualHeight") ) { return visualHeight; }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"touchContainer") ) { return touchContainer; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isRunEnterFrame") ) { return isRunEnterFrame; }
	}
	return super::__Field(inName);
}

Dynamic TouchUpDownContainer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pre") ) { pre=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::nmex::display::DisplayObject >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"preTime") ) { preTime=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isActive") ) { isActive=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isMouseDown") ) { isMouseDown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visualWidth") ) { visualWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"REDUCE_VALUE") ) { REDUCE_VALUE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visualHeight") ) { visualHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"touchContainer") ) { touchContainer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isRunEnterFrame") ) { isRunEnterFrame=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TouchUpDownContainer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("touchContainer"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("isMouseDown"));
	outFields->push(HX_CSTRING("isActive"));
	outFields->push(HX_CSTRING("isRunEnterFrame"));
	outFields->push(HX_CSTRING("pre"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("visualWidth"));
	outFields->push(HX_CSTRING("visualHeight"));
	outFields->push(HX_CSTRING("preTime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("REDUCE_VALUE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("touchContainer"),
	HX_CSTRING("view"),
	HX_CSTRING("isMouseDown"),
	HX_CSTRING("isActive"),
	HX_CSTRING("isRunEnterFrame"),
	HX_CSTRING("pre"),
	HX_CSTRING("speed"),
	HX_CSTRING("visualWidth"),
	HX_CSTRING("visualHeight"),
	HX_CSTRING("preTime"),
	HX_CSTRING("onDown"),
	HX_CSTRING("onMove"),
	HX_CSTRING("onOut"),
	HX_CSTRING("onUp"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("moveAble"),
	HX_CSTRING("positionFix"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchUpDownContainer_obj::REDUCE_VALUE,"REDUCE_VALUE");
};

Class TouchUpDownContainer_obj::__mClass;

void TouchUpDownContainer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.TouchUpDownContainer"), hx::TCanCast< TouchUpDownContainer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TouchUpDownContainer_obj::__boot()
{
	hx::Static(REDUCE_VALUE) = (int)5;
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
