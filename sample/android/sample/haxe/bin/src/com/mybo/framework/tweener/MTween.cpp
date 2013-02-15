#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Cubic
#include <com/mybo/framework/tweener/easing/Cubic.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
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
namespace tweener{

Void MTween_obj::__construct(Dynamic target,Dynamic __o_duration,Dynamic values,Dynamic props)
{
double duration = __o_duration.Default(1.0);
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",40)
	super::__construct(null());
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",41)
	this->target = target;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",42)
	this->values = values;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",43)
	this->duration = duration;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",44)
	this->ease = ::com::mybo::framework::tweener::easing::Cubic_obj::easeOut_dyn();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",45)
	this->copyProp(props);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",46)
	hx::AddEq(this->startTime,(double(::nme::Lib_obj::getTimer()) / double((int)1000)));
}
;
	return null();
}

MTween_obj::~MTween_obj() { }

Dynamic MTween_obj::__CreateEmpty() { return  new MTween_obj; }
hx::ObjectPtr< MTween_obj > MTween_obj::__new(Dynamic target,Dynamic __o_duration,Dynamic values,Dynamic props)
{  hx::ObjectPtr< MTween_obj > result = new MTween_obj();
	result->__construct(target,__o_duration,values,props);
	return result;}

Dynamic MTween_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MTween_obj > result = new MTween_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void MTween_obj::init( ){
{
		HX_SOURCE_PUSH("MTween_obj::init")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
		};
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",50)
		this->valuesOld = _Function_1_1::Block();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",51)
		Array< ::String > keys = ::Reflect_obj::fields(this->values);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",52)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",52)
			int _g = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",52)
			while(((_g < keys->length))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",52)
				::String key = keys->__get(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",52)
				++(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",53)
				Dynamic value = ::Reflect_obj::field(this->target,key);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",54)
				{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",54)
					Dynamic o = this->valuesOld;
					HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",54)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",54)
						o->__SetField(key,value);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MTween_obj,init,(void))

Void MTween_obj::copyProp( Dynamic props){
{
		HX_SOURCE_PUSH("MTween_obj::copyProp")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",59)
		Array< ::String > keys = ::Reflect_obj::fields(props);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",60)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",60)
			int _g = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",60)
			while(((_g < keys->length))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",60)
				::String key = keys->__get(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",60)
				++(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",61)
				if (((HX_CSTRING("ease") == key))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",61)
					this->ease = ::Reflect_obj::field(props,key);
				}
				else{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",63)
					if (((HX_CSTRING("delay") == key))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",64)
						this->delay = ::Reflect_obj::field(props,key);
						HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",65)
						this->startTime = this->delay;
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",66)
						if (((HX_CSTRING("onUpdate") == key))){
							HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",66)
							this->onUpdate = ::Reflect_obj::field(props,key);
						}
						else{
							HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",68)
							if (((HX_CSTRING("onComplete") == key))){
								HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",68)
								this->onComplete = ::Reflect_obj::field(props,key);
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MTween_obj,copyProp,(void))

Void MTween_obj::render( ){
{
		HX_SOURCE_PUSH("MTween_obj::render")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",75)
		this->currentTime = ((double(::nme::Lib_obj::getTimer()) / double((int)1000)) - this->startTime);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",76)
		if ((!(this->isInit))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",77)
			if (((this->currentTime <= (int)0))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",77)
				return null();
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",78)
			this->init();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",79)
			this->isInit = true;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",82)
		double percent;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",84)
		if (((this->currentTime >= this->duration))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",84)
			percent = (int)1;
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",86)
			percent = this->caculateValue(this->currentTime);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",90)
		if (((null() != this->onUpdate_dyn()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",90)
			this->onUpdate(percent);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",94)
		Array< ::String > keys = ::Reflect_obj::fields(this->values);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",95)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",95)
			int _g = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",95)
			while(((_g < keys->length))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",95)
				::String key = keys->__get(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",95)
				++(_g);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",96)
				{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",96)
					Dynamic o = this->target;
					HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",96)
					if (((o != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",96)
						o->__SetField(key,(::Reflect_obj::field(this->valuesOld,key) + (percent * ((::Reflect_obj::field(this->values,key) - ::Reflect_obj::field(this->valuesOld,key))))));
					}
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",99)
		if (((this->currentTime >= this->duration))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",100)
			if (((null() != this->onComplete))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",100)
				this->onComplete();
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",103)
			this->destroy();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MTween_obj,render,(void))

double MTween_obj::caculateValue( double currTime){
	HX_SOURCE_PUSH("MTween_obj::caculateValue")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",107)
	return ::Reflect_obj::callMethod(null(),this->ease,Array_obj< double >::__new().Add(currTime).Add((int)0).Add((int)1).Add(this->duration));
}


HX_DEFINE_DYNAMIC_FUNC1(MTween_obj,caculateValue,return )

Void MTween_obj::destroy( ){
{
		HX_SOURCE_PUSH("MTween_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",112)
		this->noAutoRender();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",113)
		this->target = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",114)
		this->onComplete = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",115)
		this->onUpdate = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",117)
		this->values = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",118)
		this->valuesOld = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",119)
		this->props = null();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",121)
		this->ease = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MTween_obj,destroy,(void))

Void MTween_obj::stop( ){
{
		HX_SOURCE_PUSH("MTween_obj::stop")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",124)
		this->destroy();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MTween_obj,stop,(void))

::com::mybo::framework::tweener::MTween MTween_obj::to( Dynamic target,Dynamic __o_duration,Dynamic values,Dynamic props){
double duration = __o_duration.Default(1.0);
	HX_SOURCE_PUSH("MTween_obj::to");
{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/tweener/MTween.hx",35)
		return ::com::mybo::framework::tweener::MTween_obj::__new(target,duration,values,props);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(MTween_obj,to,return )


MTween_obj::MTween_obj()
{
}

void MTween_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MTween);
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(tweens,"tweens");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(isInit,"isInit");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_MEMBER_NAME(values,"values");
	HX_MARK_MEMBER_NAME(valuesOld,"valuesOld");
	HX_MARK_MEMBER_NAME(props,"props");
	HX_MARK_MEMBER_NAME(startTime,"startTime");
	HX_MARK_MEMBER_NAME(currentTime,"currentTime");
	HX_MARK_MEMBER_NAME(endTime,"endTime");
	HX_MARK_MEMBER_NAME(delay,"delay");
	HX_MARK_MEMBER_NAME(ease,"ease");
	HX_MARK_MEMBER_NAME(onUpdate,"onUpdate");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MTween_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"to") ) { return to_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		if (HX_FIELD_EQ(inName,"ease") ) { return ease; }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		if (HX_FIELD_EQ(inName,"props") ) { return props; }
		if (HX_FIELD_EQ(inName,"delay") ) { return delay; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tweens") ) { return tweens; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"isInit") ) { return isInit; }
		if (HX_FIELD_EQ(inName,"values") ) { return values; }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endTime") ) { return endTime; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate; }
		if (HX_FIELD_EQ(inName,"copyProp") ) { return copyProp_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"valuesOld") ) { return valuesOld; }
		if (HX_FIELD_EQ(inName,"startTime") ) { return startTime; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentTime") ) { return currentTime; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"caculateValue") ) { return caculateValue_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MTween_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ease") ) { ease=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"props") ) { props=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tweens") ) { tweens=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isInit") ) { isInit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"values") ) { values=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endTime") ) { endTime=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { onUpdate=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"valuesOld") ) { valuesOld=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startTime") ) { startTime=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentTime") ) { currentTime=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MTween_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("tweens"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("isInit"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("values"));
	outFields->push(HX_CSTRING("valuesOld"));
	outFields->push(HX_CSTRING("props"));
	outFields->push(HX_CSTRING("startTime"));
	outFields->push(HX_CSTRING("currentTime"));
	outFields->push(HX_CSTRING("endTime"));
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("ease"));
	outFields->push(HX_CSTRING("onComplete"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("to"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("time"),
	HX_CSTRING("timer"),
	HX_CSTRING("tweens"),
	HX_CSTRING("target"),
	HX_CSTRING("isInit"),
	HX_CSTRING("duration"),
	HX_CSTRING("values"),
	HX_CSTRING("valuesOld"),
	HX_CSTRING("props"),
	HX_CSTRING("startTime"),
	HX_CSTRING("currentTime"),
	HX_CSTRING("endTime"),
	HX_CSTRING("delay"),
	HX_CSTRING("ease"),
	HX_CSTRING("onUpdate"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("init"),
	HX_CSTRING("copyProp"),
	HX_CSTRING("render"),
	HX_CSTRING("caculateValue"),
	HX_CSTRING("destroy"),
	HX_CSTRING("stop"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class MTween_obj::__mClass;

void MTween_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.tweener.MTween"), hx::TCanCast< MTween_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MTween_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
