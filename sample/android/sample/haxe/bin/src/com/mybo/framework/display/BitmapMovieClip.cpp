#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapMovieClip
#include <com/mybo/framework/display/BitmapMovieClip.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
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
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace display{

Void BitmapMovieClip_obj::__construct(::com::mybo::framework::resource::BitmapTile tile,Array< int > index)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",26)
	super::__construct(tile,true,true,false);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",28)
	this->isLoop = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",29)
	this->isPlay = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",31)
	this->flag = (int)0;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",32)
	this->isSlow = false;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",34)
	this->index = index;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",36)
	if (((index != null()))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",37)
		this->totalFrames = index->length;
	}
}
;
	return null();
}

BitmapMovieClip_obj::~BitmapMovieClip_obj() { }

Dynamic BitmapMovieClip_obj::__CreateEmpty() { return  new BitmapMovieClip_obj; }
hx::ObjectPtr< BitmapMovieClip_obj > BitmapMovieClip_obj::__new(::com::mybo::framework::resource::BitmapTile tile,Array< int > index)
{  hx::ObjectPtr< BitmapMovieClip_obj > result = new BitmapMovieClip_obj();
	result->__construct(tile,index);
	return result;}

Dynamic BitmapMovieClip_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapMovieClip_obj > result = new BitmapMovieClip_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void BitmapMovieClip_obj::gotoAndPlay( int frame){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::gotoAndPlay")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",41)
		this->currentFrame = (  (((frame >= this->totalFrames))) ? int(this->totalFrames) : int(frame) );
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",42)
		this->isPlay = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",43)
		this->autoRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMovieClip_obj,gotoAndPlay,(void))

Void BitmapMovieClip_obj::gotoAndStop( int frame){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::gotoAndStop")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",47)
		this->isPlay = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",48)
		if (((this->currentFrame != frame))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",49)
			this->currentFrame = (  (((frame >= this->totalFrames))) ? int(this->totalFrames) : int(frame) );
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",50)
			if (((this->index == null()))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",51)
				this->drawTile(this->currentFrame,null(),null(),null());
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",53)
				this->drawTile(this->index->__get(this->currentFrame),null(),null(),null());
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",55)
		this->noAutoRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapMovieClip_obj,gotoAndStop,(void))

Void BitmapMovieClip_obj::play( ){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::play")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",59)
		this->isPlay = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",60)
		this->autoRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMovieClip_obj,play,(void))

Void BitmapMovieClip_obj::stop( ){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::stop")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",64)
		this->isPlay = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",65)
		this->noAutoRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMovieClip_obj,stop,(void))

Void BitmapMovieClip_obj::render( ){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::render")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",69)
		if (((this->currentFrame >= this->totalFrames))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",69)
			if ((!(this->isLoop))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",71)
				if (((null() != this->completeFun))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",71)
					::Reflect_obj::callMethod(this->callbackObject,this->completeFun,this->callbackPara);
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",74)
				this->stop();
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",75)
				return null();
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",76)
				this->currentFrame = (int)0;
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",81)
		if ((this->isSlow)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",82)
			(this->flag)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",83)
			if (((this->flag > (int)100))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",83)
				this->flag = (int)0;
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",86)
			if (((hx::Mod(this->flag,(int)2) == (int)0))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",87)
				if (((this->index == null()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",88)
					this->drawTile(this->currentFrame,null(),null(),null());
				}
				else{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",90)
					this->drawTile(this->index->__get(this->currentFrame),null(),null(),null());
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",91)
				(this->currentFrame)++;
			}
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",94)
			if (((this->index == null()))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",95)
				this->drawTile(this->currentFrame,null(),null(),null());
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",97)
				this->drawTile(this->index->__get(this->currentFrame),null(),null(),null());
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",98)
			(this->currentFrame)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMovieClip_obj,render,(void))

Void BitmapMovieClip_obj::onComplete( Dynamic func,Dynamic para,Dynamic obj){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::onComplete")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",104)
		this->callbackObject = obj;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",105)
		this->callbackPara = para;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",106)
		this->completeFun = func;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapMovieClip_obj,onComplete,(void))

Void BitmapMovieClip_obj::destroy( ){
{
		HX_SOURCE_PUSH("BitmapMovieClip_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",110)
		this->super::destroy();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",111)
		this->completeFun = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",112)
		this->callbackObject = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",113)
		this->callbackPara = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapMovieClip.hx",114)
		this->noAutoRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapMovieClip_obj,destroy,(void))


BitmapMovieClip_obj::BitmapMovieClip_obj()
{
}

void BitmapMovieClip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapMovieClip);
	HX_MARK_MEMBER_NAME(isLoop,"isLoop");
	HX_MARK_MEMBER_NAME(isPlay,"isPlay");
	HX_MARK_MEMBER_NAME(completeFun,"completeFun");
	HX_MARK_MEMBER_NAME(callbackObject,"callbackObject");
	HX_MARK_MEMBER_NAME(callbackPara,"callbackPara");
	HX_MARK_MEMBER_NAME(isSlow,"isSlow");
	HX_MARK_MEMBER_NAME(flag,"flag");
	HX_MARK_MEMBER_NAME(index,"index");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapMovieClip_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"flag") ) { return flag; }
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isLoop") ) { return isLoop; }
		if (HX_FIELD_EQ(inName,"isPlay") ) { return isPlay; }
		if (HX_FIELD_EQ(inName,"isSlow") ) { return isSlow; }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"completeFun") ) { return completeFun; }
		if (HX_FIELD_EQ(inName,"gotoAndPlay") ) { return gotoAndPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoAndStop") ) { return gotoAndStop_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callbackPara") ) { return callbackPara; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"callbackObject") ) { return callbackObject; }
	}
	return super::__Field(inName);
}

Dynamic BitmapMovieClip_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"flag") ) { flag=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isLoop") ) { isLoop=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isPlay") ) { isPlay=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isSlow") ) { isSlow=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"completeFun") ) { completeFun=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callbackPara") ) { callbackPara=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"callbackObject") ) { callbackObject=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapMovieClip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isLoop"));
	outFields->push(HX_CSTRING("isPlay"));
	outFields->push(HX_CSTRING("completeFun"));
	outFields->push(HX_CSTRING("callbackObject"));
	outFields->push(HX_CSTRING("callbackPara"));
	outFields->push(HX_CSTRING("isSlow"));
	outFields->push(HX_CSTRING("flag"));
	outFields->push(HX_CSTRING("index"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isLoop"),
	HX_CSTRING("isPlay"),
	HX_CSTRING("completeFun"),
	HX_CSTRING("callbackObject"),
	HX_CSTRING("callbackPara"),
	HX_CSTRING("isSlow"),
	HX_CSTRING("flag"),
	HX_CSTRING("index"),
	HX_CSTRING("gotoAndPlay"),
	HX_CSTRING("gotoAndStop"),
	HX_CSTRING("play"),
	HX_CSTRING("stop"),
	HX_CSTRING("render"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapMovieClip_obj::__mClass;

void BitmapMovieClip_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapMovieClip"), hx::TCanCast< BitmapMovieClip_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapMovieClip_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
