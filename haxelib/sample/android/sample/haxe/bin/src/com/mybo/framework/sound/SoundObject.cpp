#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundObject
#include <com/mybo/framework/sound/SoundObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundType
#include <com/mybo/framework/sound/SoundType.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_media_Sound
#include <nme/media/Sound.h>
#endif
#ifndef INCLUDED_nme_media_SoundChannel
#include <nme/media/SoundChannel.h>
#endif
#ifndef INCLUDED_nme_media_SoundLoaderContext
#include <nme/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace sound{

Void SoundObject_obj::__construct()
{
{
}
;
	return null();
}

SoundObject_obj::~SoundObject_obj() { }

Dynamic SoundObject_obj::__CreateEmpty() { return  new SoundObject_obj; }
hx::ObjectPtr< SoundObject_obj > SoundObject_obj::__new()
{  hx::ObjectPtr< SoundObject_obj > result = new SoundObject_obj();
	result->__construct();
	return result;}

Dynamic SoundObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundObject_obj > result = new SoundObject_obj();
	result->__construct();
	return result;}

Void SoundObject_obj::load( ){
{
		HX_SOURCE_PUSH("SoundObject_obj::load")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",19)
		if ((!(this->didLoad))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",21)
			double hackTime = (::nme::Lib_obj::getTimer() - ::com::mybo::framework::core::Facade_obj::getInstance()->startTime);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",22)
			if (((hackTime < (int)200))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",22)
				::haxe::Timer_obj::delay(this->load_dyn(),(int)200);
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",25)
				this->sound = ::nme::media::Sound_obj::__new(::nme::net::URLRequest_obj::__new(this->fileURL),null(),(this->type == ::com::mybo::framework::sound::SoundType_obj::MUSIC_dyn()));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",26)
				this->didLoad = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundObject_obj,load,(void))

Void SoundObject_obj::destroy( ){
{
		HX_SOURCE_PUSH("SoundObject_obj::destroy")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",31)
		if ((this->didLoad)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",33)
			if (((null() != this->channel))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",33)
				this->channel->stop();
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",34)
			this->channel = null();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",35)
			this->sound = null();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundObject.hx",36)
			this->didLoad = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundObject_obj,destroy,(void))


SoundObject_obj::SoundObject_obj()
{
}

void SoundObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundObject);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(fileURL,"fileURL");
	HX_MARK_MEMBER_NAME(channel,"channel");
	HX_MARK_MEMBER_NAME(sound,"sound");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(didLoad,"didLoad");
	HX_MARK_END_CLASS();
}

Dynamic SoundObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { return sound; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fileURL") ) { return fileURL; }
		if (HX_FIELD_EQ(inName,"channel") ) { return channel; }
		if (HX_FIELD_EQ(inName,"didLoad") ) { return didLoad; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic SoundObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::com::mybo::framework::sound::SoundType >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { sound=inValue.Cast< ::nme::media::Sound >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"fileURL") ) { fileURL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"channel") ) { channel=inValue.Cast< ::nme::media::SoundChannel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"didLoad") ) { didLoad=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SoundObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("fileURL"));
	outFields->push(HX_CSTRING("channel"));
	outFields->push(HX_CSTRING("sound"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("didLoad"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("fileURL"),
	HX_CSTRING("channel"),
	HX_CSTRING("sound"),
	HX_CSTRING("type"),
	HX_CSTRING("didLoad"),
	HX_CSTRING("load"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class SoundObject_obj::__mClass;

void SoundObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.sound.SoundObject"), hx::TCanCast< SoundObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SoundObject_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound
