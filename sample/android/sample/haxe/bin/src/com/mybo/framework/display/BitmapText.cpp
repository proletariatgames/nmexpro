#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapText
#include <com/mybo/framework/display/BitmapText.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_nme_events_KeyboardEvent
#include <nme/events/KeyboardEvent.h>
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

Void BitmapText_obj::__construct(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_editAllowed,Dynamic __o_editlimit)
{
bool editAllowed = __o_editAllowed.Default(false);
int editlimit = __o_editlimit.Default(0);
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",26)
	super::__construct(tile,false,null(),null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",28)
	this->editAllowed = editAllowed;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",29)
	this->lengthLimit = editlimit;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",31)
	if ((editAllowed)){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",32)
		this->touchLayer = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",33)
		this->addChild(this->touchLayer);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",34)
		this->touchLayer->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onClick_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",35)
		this->anchorCenter = false;
	}
}
;
	return null();
}

BitmapText_obj::~BitmapText_obj() { }

Dynamic BitmapText_obj::__CreateEmpty() { return  new BitmapText_obj; }
hx::ObjectPtr< BitmapText_obj > BitmapText_obj::__new(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_editAllowed,Dynamic __o_editlimit)
{  hx::ObjectPtr< BitmapText_obj > result = new BitmapText_obj();
	result->__construct(tile,__o_editAllowed,__o_editlimit);
	return result;}

Dynamic BitmapText_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapText_obj > result = new BitmapText_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void BitmapText_obj::draw( ::String content){
{
		HX_SOURCE_PUSH("BitmapText_obj::draw")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",41)
		this->clear();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",43)
		if (((bool((content == HX_CSTRING(""))) || bool((content == null()))))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",43)
			return null();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",45)
		this->text = content;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",47)
		double offsetX = (int)0;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",48)
		if ((this->anchorCenter)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",48)
			offsetX = (double((double((-(this->tile->width) * this->text.length)) / double((int)2))) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",52)
		if ((this->editAllowed)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",53)
			double w = (double((this->text.length * this->tile->width)) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",54)
			double h = (double(this->tile->height) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",55)
			this->touchLayer->nmeGetGraphics()->clear();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",56)
			this->touchLayer->nmeGetGraphics()->beginFill((int)0,0.5);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",57)
			this->touchLayer->nmeGetGraphics()->drawRect(offsetX,(int)0,w,h);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",58)
			this->touchLayer->nmeGetGraphics()->endFill();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",61)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",61)
			int _g1 = (int)0;
			int _g = content.length;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",61)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",61)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",62)
				if (((::com::mybo::framework::display::BitmapText_obj::index.indexOf(content.charAt(i),null()) >= (int)0))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",62)
					this->drawTile(::com::mybo::framework::display::BitmapText_obj::index.indexOf(content.charAt(i),null()),((double((i * this->tile->width)) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor)) + offsetX),(int)0,false);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapText_obj,draw,(void))

Void BitmapText_obj::setAnchorCenter( bool enable){
{
		HX_SOURCE_PUSH("BitmapText_obj::setAnchorCenter")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",68)
		this->anchorCenter = enable;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapText_obj,setAnchorCenter,(void))

Void BitmapText_obj::setEditCompleteHandle( Dynamic onComplete,Dynamic onCompleteParams,Dynamic onCompleteObj){
{
		HX_SOURCE_PUSH("BitmapText_obj::setEditCompleteHandle")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",73)
		this->onComplete = onComplete;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",74)
		this->onCompleteObj = onCompleteObj;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",75)
		this->onCompleteParams = onCompleteParams;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapText_obj,setEditCompleteHandle,(void))

Void BitmapText_obj::onClick( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("BitmapText_obj::onClick")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",78)
		if ((!(::com::mybo::framework::display::BitmapText_obj::hasKeyBoard))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",80)
			this->requestSoftKeyboard();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",81)
			::com::mybo::framework::core::Facade_obj::getInstance()->getStage()->addEventListener(::nme::events::KeyboardEvent_obj::KEY_UP,this->onKeyDown_dyn(),null(),null(),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",82)
			::com::mybo::framework::display::BitmapText_obj::hasKeyBoard = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapText_obj,onClick,(void))

Void BitmapText_obj::onKeyDown( ::nme::events::KeyboardEvent e){
{
		HX_SOURCE_PUSH("BitmapText_obj::onKeyDown")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",86)
		if (((bool(((int)1000 == e->charCode)) && bool(::com::mybo::framework::display::BitmapText_obj::hasKeyBoard)))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",89)
			::com::mybo::framework::display::BitmapText_obj::hasKeyBoard = false;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",91)
			::nme::Lib_obj::nmeGetStage()->removeEventListener(::nme::events::KeyboardEvent_obj::KEY_UP,this->onKeyDown_dyn(),null());
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",94)
			if (((bool(((int)13 == e->charCode)) && bool(::com::mybo::framework::display::BitmapText_obj::hasKeyBoard)))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",95)
				::com::mybo::framework::display::BitmapText_obj::hasKeyBoard = false;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",97)
				::nme::Lib_obj::nmeGetStage()->removeEventListener(::nme::events::KeyboardEvent_obj::KEY_UP,this->onKeyDown_dyn(),null());
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",99)
				this->updateText(e->charCode);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapText_obj,onKeyDown,(void))

Void BitmapText_obj::updateText( int charCode){
{
		HX_SOURCE_PUSH("BitmapText_obj::updateText")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",105)
		if ((((int)8 == charCode))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",105)
			if (((this->text.length > (int)0))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",106)
				this->text = this->text.substr((int)0,(this->text.length - (int)1));
			}
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",107)
			if (((this->text.length < this->lengthLimit))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",109)
				::String _char = ::String::fromCharCode(charCode);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",110)
				::haxe::Log_obj::trace(_char,hx::SourceInfo(HX_CSTRING("BitmapText.hx"),110,HX_CSTRING("com.mybo.framework.display.BitmapText"),HX_CSTRING("updateText")));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",111)
				if ((((int)-1 != ::com::mybo::framework::display::BitmapText_obj::index.indexOf(_char,null())))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",111)
					hx::AddEq(this->text,_char);
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapText.hx",114)
		this->draw(this->text);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapText_obj,updateText,(void))

::String BitmapText_obj::index;

bool BitmapText_obj::hasKeyBoard;


BitmapText_obj::BitmapText_obj()
{
}

void BitmapText_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapText);
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(editAllowed,"editAllowed");
	HX_MARK_MEMBER_NAME(touchLayer,"touchLayer");
	HX_MARK_MEMBER_NAME(anchorCenter,"anchorCenter");
	HX_MARK_MEMBER_NAME(lengthLimit,"lengthLimit");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	HX_MARK_MEMBER_NAME(onCompleteObj,"onCompleteObj");
	HX_MARK_MEMBER_NAME(onCompleteParams,"onCompleteParams");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapText_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return text; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return onClick_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"touchLayer") ) { return touchLayer; }
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete; }
		if (HX_FIELD_EQ(inName,"updateText") ) { return updateText_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasKeyBoard") ) { return hasKeyBoard; }
		if (HX_FIELD_EQ(inName,"editAllowed") ) { return editAllowed; }
		if (HX_FIELD_EQ(inName,"lengthLimit") ) { return lengthLimit; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"anchorCenter") ) { return anchorCenter; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onCompleteObj") ) { return onCompleteObj; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setAnchorCenter") ) { return setAnchorCenter_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onCompleteParams") ) { return onCompleteParams; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"setEditCompleteHandle") ) { return setEditCompleteHandle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BitmapText_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { text=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"touchLayer") ) { touchLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"hasKeyBoard") ) { hasKeyBoard=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"editAllowed") ) { editAllowed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lengthLimit") ) { lengthLimit=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"anchorCenter") ) { anchorCenter=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onCompleteObj") ) { onCompleteObj=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onCompleteParams") ) { onCompleteParams=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapText_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("text"));
	outFields->push(HX_CSTRING("editAllowed"));
	outFields->push(HX_CSTRING("touchLayer"));
	outFields->push(HX_CSTRING("anchorCenter"));
	outFields->push(HX_CSTRING("lengthLimit"));
	outFields->push(HX_CSTRING("onComplete"));
	outFields->push(HX_CSTRING("onCompleteObj"));
	outFields->push(HX_CSTRING("onCompleteParams"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("index"),
	HX_CSTRING("hasKeyBoard"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("text"),
	HX_CSTRING("editAllowed"),
	HX_CSTRING("touchLayer"),
	HX_CSTRING("anchorCenter"),
	HX_CSTRING("lengthLimit"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("onCompleteObj"),
	HX_CSTRING("onCompleteParams"),
	HX_CSTRING("draw"),
	HX_CSTRING("setAnchorCenter"),
	HX_CSTRING("setEditCompleteHandle"),
	HX_CSTRING("onClick"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("updateText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapText_obj::index,"index");
	HX_MARK_MEMBER_NAME(BitmapText_obj::hasKeyBoard,"hasKeyBoard");
};

Class BitmapText_obj::__mClass;

void BitmapText_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapText"), hx::TCanCast< BitmapText_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapText_obj::__boot()
{
	hx::Static(index) = HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890,.!':()?\"/\\");
	hx::Static(hasKeyBoard) = false;
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
