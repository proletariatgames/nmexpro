#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_sound_SoundObject
#include <com/mybo/framework/sound/SoundObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundQueue
#include <com/mybo/framework/sound/SoundQueue.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundType
#include <com/mybo/framework/sound/SoundType.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_nme_media_SoundTransform
#include <nme/media/SoundTransform.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace sound{

Void SoundPlayer_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",12)
	this->soundQueue = ::com::mybo::framework::sound::SoundQueue_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",13)
	this->SFXAble = true;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",14)
	this->musicAble = true;
}
;
	return null();
}

SoundPlayer_obj::~SoundPlayer_obj() { }

Dynamic SoundPlayer_obj::__CreateEmpty() { return  new SoundPlayer_obj; }
hx::ObjectPtr< SoundPlayer_obj > SoundPlayer_obj::__new()
{  hx::ObjectPtr< SoundPlayer_obj > result = new SoundPlayer_obj();
	result->__construct();
	return result;}

Dynamic SoundPlayer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundPlayer_obj > result = new SoundPlayer_obj();
	result->__construct();
	return result;}

Void SoundPlayer_obj::play( ::String name,Dynamic startPos,Dynamic loops){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::play")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",25)
		::com::mybo::framework::sound::SoundObject obj = this->soundQueue->getSoundObject(name);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",26)
		if (((null() == obj))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",26)
			::haxe::Log_obj::trace(((HX_CSTRING("Sound ") + name) + HX_CSTRING(" can not be found!")),hx::SourceInfo(HX_CSTRING("SoundPlayer.hx"),27,HX_CSTRING("com.mybo.framework.sound.SoundPlayer"),HX_CSTRING("play")));
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",29)
			if ((!(obj->didLoad))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",29)
				obj->load();
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",31)
			if (((bool((obj->type == ::com::mybo::framework::sound::SoundType_obj::SFX_dyn())) && bool(this->SFXAble)))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",31)
				if (((obj->sound != null()))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",32)
					obj->channel = obj->sound->play(startPos,loops,null());
				}
				else{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",32)
					HX_CSTRING("");
				}
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",33)
				if (((bool((bool((this->currentMusic == null())) || bool((this->currentMusic->name != name)))) || bool((this->currentMusic->channel == null()))))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",35)
					this->stopByType(::com::mybo::framework::sound::SoundType_obj::MUSIC_dyn());
					HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",36)
					if (((obj->sound != null()))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",36)
						obj->channel = obj->sound->play(startPos,loops,null());
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",36)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",37)
					this->currentMusic = obj;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SoundPlayer_obj,play,(void))

Void SoundPlayer_obj::addSound( ::String name,::String fileURL,::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::addSound")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",43)
		this->soundQueue->add(name,fileURL,type);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SoundPlayer_obj,addSound,(void))

Void SoundPlayer_obj::stop( ::String name){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::stop")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",46)
		this->soundQueue->stop(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,stop,(void))

Void SoundPlayer_obj::stopByType( ::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::stopByType")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",49)
		this->soundQueue->stopByType(type);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,stopByType,(void))

Void SoundPlayer_obj::stopAll( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::stopAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",52)
		this->soundQueue->stopAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,stopAll,(void))

Void SoundPlayer_obj::enableMusic( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::enableMusic")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",55)
		this->musicAble = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,enableMusic,(void))

Void SoundPlayer_obj::disableMusic( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::disableMusic")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",59)
		this->musicAble = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",60)
		this->stopByType(::com::mybo::framework::sound::SoundType_obj::MUSIC_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,disableMusic,(void))

Void SoundPlayer_obj::enableSFX( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::enableSFX")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",62)
		this->SFXAble = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,enableSFX,(void))

Void SoundPlayer_obj::disableSFX( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::disableSFX")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",66)
		this->SFXAble = false;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",67)
		this->stopByType(::com::mybo::framework::sound::SoundType_obj::SFX_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,disableSFX,(void))

Void SoundPlayer_obj::loadByName( ::String name){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::loadByName")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",69)
		this->soundQueue->loadByName(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,loadByName,(void))

Void SoundPlayer_obj::loadByType( ::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::loadByType")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",73)
		this->soundQueue->loadByType(type);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,loadByType,(void))

Void SoundPlayer_obj::loadAll( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::loadAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",76)
		this->soundQueue->loadAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,loadAll,(void))

Void SoundPlayer_obj::unloadByName( ::String name){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::unloadByName")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",79)
		this->soundQueue->unloadByName(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,unloadByName,(void))

Void SoundPlayer_obj::unloadByType( ::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::unloadByType")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",83)
		this->soundQueue->unloadByType(type);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,unloadByType,(void))

Void SoundPlayer_obj::unloadAll( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::unloadAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",86)
		this->soundQueue->unloadAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,unloadAll,(void))

Void SoundPlayer_obj::remove( ::String name){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::remove")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",89)
		this->soundQueue->remove(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundPlayer_obj,remove,(void))

Void SoundPlayer_obj::removeAll( ){
{
		HX_SOURCE_PUSH("SoundPlayer_obj::removeAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",92)
		this->soundQueue->removeAll();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,removeAll,(void))

::com::mybo::framework::sound::SoundPlayer SoundPlayer_obj::instance;

::com::mybo::framework::sound::SoundPlayer SoundPlayer_obj::getInstance( ){
	HX_SOURCE_PUSH("SoundPlayer_obj::getInstance")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",18)
	if (((null() == ::com::mybo::framework::sound::SoundPlayer_obj::instance))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",18)
		::com::mybo::framework::sound::SoundPlayer_obj::instance = ::com::mybo::framework::sound::SoundPlayer_obj::__new();
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundPlayer.hx",21)
	return ::com::mybo::framework::sound::SoundPlayer_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundPlayer_obj,getInstance,return )


SoundPlayer_obj::SoundPlayer_obj()
{
}

void SoundPlayer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundPlayer);
	HX_MARK_MEMBER_NAME(soundQueue,"soundQueue");
	HX_MARK_MEMBER_NAME(SFXAble,"SFXAble");
	HX_MARK_MEMBER_NAME(musicAble,"musicAble");
	HX_MARK_MEMBER_NAME(currentMusic,"currentMusic");
	HX_MARK_END_CLASS();
}

Dynamic SoundPlayer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SFXAble") ) { return SFXAble; }
		if (HX_FIELD_EQ(inName,"stopAll") ) { return stopAll_dyn(); }
		if (HX_FIELD_EQ(inName,"loadAll") ) { return loadAll_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance; }
		if (HX_FIELD_EQ(inName,"addSound") ) { return addSound_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"musicAble") ) { return musicAble; }
		if (HX_FIELD_EQ(inName,"enableSFX") ) { return enableSFX_dyn(); }
		if (HX_FIELD_EQ(inName,"unloadAll") ) { return unloadAll_dyn(); }
		if (HX_FIELD_EQ(inName,"removeAll") ) { return removeAll_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"soundQueue") ) { return soundQueue; }
		if (HX_FIELD_EQ(inName,"stopByType") ) { return stopByType_dyn(); }
		if (HX_FIELD_EQ(inName,"disableSFX") ) { return disableSFX_dyn(); }
		if (HX_FIELD_EQ(inName,"loadByName") ) { return loadByName_dyn(); }
		if (HX_FIELD_EQ(inName,"loadByType") ) { return loadByType_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"enableMusic") ) { return enableMusic_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentMusic") ) { return currentMusic; }
		if (HX_FIELD_EQ(inName,"disableMusic") ) { return disableMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"unloadByName") ) { return unloadByName_dyn(); }
		if (HX_FIELD_EQ(inName,"unloadByType") ) { return unloadByType_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic SoundPlayer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"SFXAble") ) { SFXAble=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::com::mybo::framework::sound::SoundPlayer >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"musicAble") ) { musicAble=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"soundQueue") ) { soundQueue=inValue.Cast< ::com::mybo::framework::sound::SoundQueue >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentMusic") ) { currentMusic=inValue.Cast< ::com::mybo::framework::sound::SoundObject >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SoundPlayer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("soundQueue"));
	outFields->push(HX_CSTRING("SFXAble"));
	outFields->push(HX_CSTRING("musicAble"));
	outFields->push(HX_CSTRING("currentMusic"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("soundQueue"),
	HX_CSTRING("SFXAble"),
	HX_CSTRING("musicAble"),
	HX_CSTRING("currentMusic"),
	HX_CSTRING("play"),
	HX_CSTRING("addSound"),
	HX_CSTRING("stop"),
	HX_CSTRING("stopByType"),
	HX_CSTRING("stopAll"),
	HX_CSTRING("enableMusic"),
	HX_CSTRING("disableMusic"),
	HX_CSTRING("enableSFX"),
	HX_CSTRING("disableSFX"),
	HX_CSTRING("loadByName"),
	HX_CSTRING("loadByType"),
	HX_CSTRING("loadAll"),
	HX_CSTRING("unloadByName"),
	HX_CSTRING("unloadByType"),
	HX_CSTRING("unloadAll"),
	HX_CSTRING("remove"),
	HX_CSTRING("removeAll"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundPlayer_obj::instance,"instance");
};

Class SoundPlayer_obj::__mClass;

void SoundPlayer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.sound.SoundPlayer"), hx::TCanCast< SoundPlayer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SoundPlayer_obj::__boot()
{
	hx::Static(instance);
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound
