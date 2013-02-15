#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
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
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace core{

Void TimerRender_obj::__construct(Dynamic __o_autoRun)
{
bool autoRun = __o_autoRun.Default(true);
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",14)
	super::__construct();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",15)
	this->isRun = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",16)
	if (((::com::mybo::framework::core::TimerRender_obj::renderList == null()))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",16)
		::com::mybo::framework::core::TimerRender_obj::renderList = Array_obj< ::com::mybo::framework::core::TimerRender >::__new();
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",17)
	if (((::com::mybo::framework::core::TimerRender_obj::stage == null()))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",17)
		::com::mybo::framework::core::TimerRender_obj::stage = ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage();
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",18)
	if ((autoRun)){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",18)
		this->autoRender();
	}
}
;
	return null();
}

TimerRender_obj::~TimerRender_obj() { }

Dynamic TimerRender_obj::__CreateEmpty() { return  new TimerRender_obj; }
hx::ObjectPtr< TimerRender_obj > TimerRender_obj::__new(Dynamic __o_autoRun)
{  hx::ObjectPtr< TimerRender_obj > result = new TimerRender_obj();
	result->__construct(__o_autoRun);
	return result;}

Dynamic TimerRender_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimerRender_obj > result = new TimerRender_obj();
	result->__construct(inArgs[0]);
	return result;}

Void TimerRender_obj::autoRender( ){
{
		HX_SOURCE_PUSH("TimerRender_obj::autoRender")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",22)
		if (((::com::mybo::framework::core::TimerRender_obj::renderList->length == (int)0))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",22)
			::com::mybo::framework::core::TimerRender_obj::stage->addEventListener(::nme::events::Event_obj::ENTER_FRAME,::com::mybo::framework::core::TimerRender_obj::onEnterFrame_dyn(),null(),null(),null());
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",26)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",26)
			int _g = (int)0;
			Array< ::com::mybo::framework::core::TimerRender > _g1 = ::com::mybo::framework::core::TimerRender_obj::renderList;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",26)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",26)
				::com::mybo::framework::core::TimerRender o = _g1->__get(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",26)
				++(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",27)
				if (((o == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",27)
					return null();
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",29)
		::com::mybo::framework::core::TimerRender_obj::renderList->push(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",30)
		this->isRun = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TimerRender_obj,autoRender,(void))

Void TimerRender_obj::noAutoRender( ){
{
		HX_SOURCE_PUSH("TimerRender_obj::noAutoRender")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",34)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",34)
			int _g = (int)0;
			Array< ::com::mybo::framework::core::TimerRender > _g1 = ::com::mybo::framework::core::TimerRender_obj::renderList;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",34)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",34)
				::com::mybo::framework::core::TimerRender o = _g1->__get(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",34)
				++(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",35)
				if (((o == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",35)
					::com::mybo::framework::core::TimerRender_obj::renderList->remove(o);
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",37)
		if (((::com::mybo::framework::core::TimerRender_obj::renderList->length == (int)0))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",37)
			::com::mybo::framework::core::TimerRender_obj::stage->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,::com::mybo::framework::core::TimerRender_obj::onEnterFrame_dyn(),null());
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",40)
		this->isRun = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TimerRender_obj,noAutoRender,(void))

Void TimerRender_obj::render( ){
{
		HX_SOURCE_PUSH("TimerRender_obj::render")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TimerRender_obj,render,(void))

::nme::display::Stage TimerRender_obj::stage;

Array< ::com::mybo::framework::core::TimerRender > TimerRender_obj::renderList;

int TimerRender_obj::rate;

Void TimerRender_obj::run( ){
{
		HX_SOURCE_PUSH("TimerRender_obj::run")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",44)
		int _g = (int)0;
		Array< ::com::mybo::framework::core::TimerRender > _g1 = ::com::mybo::framework::core::TimerRender_obj::renderList;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",44)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",44)
			::com::mybo::framework::core::TimerRender o = _g1->__get(_g);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",44)
			++(_g);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",45)
			o->render();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(TimerRender_obj,run,(void))

Void TimerRender_obj::onEnterFrame( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("TimerRender_obj::onEnterFrame")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",49)
		int _g = (int)0;
		Array< ::com::mybo::framework::core::TimerRender > _g1 = ::com::mybo::framework::core::TimerRender_obj::renderList;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",49)
		while(((_g < _g1->length))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",49)
			::com::mybo::framework::core::TimerRender o = _g1->__get(_g);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",49)
			++(_g);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/TimerRender.hx",50)
			o->render();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TimerRender_obj,onEnterFrame,(void))


TimerRender_obj::TimerRender_obj()
{
}

void TimerRender_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TimerRender);
	HX_MARK_MEMBER_NAME(isRun,"isRun");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TimerRender_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rate") ) { return rate; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { return stage; }
		if (HX_FIELD_EQ(inName,"isRun") ) { return isRun; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"renderList") ) { return renderList; }
		if (HX_FIELD_EQ(inName,"autoRender") ) { return autoRender_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"noAutoRender") ) { return noAutoRender_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TimerRender_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"rate") ) { rate=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isRun") ) { isRun=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"renderList") ) { renderList=inValue.Cast< Array< ::com::mybo::framework::core::TimerRender > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TimerRender_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isRun"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("stage"),
	HX_CSTRING("renderList"),
	HX_CSTRING("rate"),
	HX_CSTRING("run"),
	HX_CSTRING("onEnterFrame"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isRun"),
	HX_CSTRING("autoRender"),
	HX_CSTRING("noAutoRender"),
	HX_CSTRING("render"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TimerRender_obj::stage,"stage");
	HX_MARK_MEMBER_NAME(TimerRender_obj::renderList,"renderList");
	HX_MARK_MEMBER_NAME(TimerRender_obj::rate,"rate");
};

Class TimerRender_obj::__mClass;

void TimerRender_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.core.TimerRender"), hx::TCanCast< TimerRender_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TimerRender_obj::__boot()
{
	hx::Static(stage);
	hx::Static(renderList);
	hx::Static(rate) = (int)40;
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core
