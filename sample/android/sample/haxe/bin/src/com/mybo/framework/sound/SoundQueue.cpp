#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundObject
#include <com/mybo/framework/sound/SoundObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundQueue
#include <com/mybo/framework/sound/SoundQueue.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundType
#include <com/mybo/framework/sound/SoundType.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_media_SoundChannel
#include <nme/media/SoundChannel.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace sound{

Void SoundQueue_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",9)
	this->sounds = ::Hash_obj::__new();
}
;
	return null();
}

SoundQueue_obj::~SoundQueue_obj() { }

Dynamic SoundQueue_obj::__CreateEmpty() { return  new SoundQueue_obj; }
hx::ObjectPtr< SoundQueue_obj > SoundQueue_obj::__new()
{  hx::ObjectPtr< SoundQueue_obj > result = new SoundQueue_obj();
	result->__construct();
	return result;}

Dynamic SoundQueue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundQueue_obj > result = new SoundQueue_obj();
	result->__construct();
	return result;}

Void SoundQueue_obj::add( ::String name,::String fileURL,::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundQueue_obj::add")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",13)
		if ((!(this->hasSound(name)))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",15)
			::com::mybo::framework::sound::SoundObject obj = ::com::mybo::framework::sound::SoundObject_obj::__new();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",16)
			obj->name = name;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",17)
			obj->fileURL = fileURL;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",18)
			obj->type = type;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",19)
			obj->didLoad = false;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",20)
			this->sounds->set(name,obj);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SoundQueue_obj,add,(void))

::com::mybo::framework::sound::SoundObject SoundQueue_obj::getSoundObject( ::String name){
	HX_SOURCE_PUSH("SoundQueue_obj::getSoundObject")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",23)
	return this->sounds->get(name);
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,getSoundObject,return )

Void SoundQueue_obj::stop( ::String name){
{
		HX_SOURCE_PUSH("SoundQueue_obj::stop")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",27)
		::com::mybo::framework::sound::SoundObject obj = this->sounds->get(name);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",28)
		this->stopSound(obj);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,stop,(void))

Void SoundQueue_obj::stopByType( ::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundQueue_obj::stopByType")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",31)
		for(::cpp::FastIterator_obj< ::com::mybo::framework::sound::SoundObject > *__it = ::cpp::CreateFastIterator< ::com::mybo::framework::sound::SoundObject >(this->sounds->iterator());  __it->hasNext(); ){
			::com::mybo::framework::sound::SoundObject obj = __it->next();
			if (((obj->type == type))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",33)
				this->stopSound(obj);
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,stopByType,(void))

Void SoundQueue_obj::stopAll( ){
{
		HX_SOURCE_PUSH("SoundQueue_obj::stopAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",36)
		for(::cpp::FastIterator_obj< ::com::mybo::framework::sound::SoundObject > *__it = ::cpp::CreateFastIterator< ::com::mybo::framework::sound::SoundObject >(this->sounds->iterator());  __it->hasNext(); ){
			::com::mybo::framework::sound::SoundObject obj = __it->next();
			this->stopSound(obj);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundQueue_obj,stopAll,(void))

Void SoundQueue_obj::loadByName( ::String name){
{
		HX_SOURCE_PUSH("SoundQueue_obj::loadByName")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",41)
		if ((this->hasSound(name))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",43)
			::com::mybo::framework::sound::SoundObject obj = this->sounds->get(name);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",44)
			obj->load();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,loadByName,(void))

Void SoundQueue_obj::loadByType( ::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundQueue_obj::loadByType")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",47)
		for(::cpp::FastIterator_obj< ::com::mybo::framework::sound::SoundObject > *__it = ::cpp::CreateFastIterator< ::com::mybo::framework::sound::SoundObject >(this->sounds->iterator());  __it->hasNext(); ){
			::com::mybo::framework::sound::SoundObject obj = __it->next();
			if (((type == obj->type))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",49)
				obj->load();
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,loadByType,(void))

Void SoundQueue_obj::loadAll( ){
{
		HX_SOURCE_PUSH("SoundQueue_obj::loadAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",54)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->sounds->keys());  __it->hasNext(); ){
			::String key = __it->next();
			this->loadByName(key);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundQueue_obj,loadAll,(void))

Void SoundQueue_obj::remove( ::String name){
{
		HX_SOURCE_PUSH("SoundQueue_obj::remove")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",60)
		this->sounds->get(name)->__Field(HX_CSTRING("destroy"))();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",61)
		this->sounds->remove(name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,remove,(void))

Void SoundQueue_obj::removeAll( ){
{
		HX_SOURCE_PUSH("SoundQueue_obj::removeAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",63)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->sounds->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",65)
				this->unloadByName(key);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",66)
				this->sounds->remove(key);
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundQueue_obj,removeAll,(void))

Void SoundQueue_obj::unloadByName( ::String name){
{
		HX_SOURCE_PUSH("SoundQueue_obj::unloadByName")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",69)
		if ((this->hasSound(name))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",71)
			::com::mybo::framework::sound::SoundObject obj = this->sounds->get(name);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",72)
			obj->destroy();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,unloadByName,(void))

Void SoundQueue_obj::unloadByType( ::com::mybo::framework::sound::SoundType type){
{
		HX_SOURCE_PUSH("SoundQueue_obj::unloadByType")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",75)
		for(::cpp::FastIterator_obj< ::com::mybo::framework::sound::SoundObject > *__it = ::cpp::CreateFastIterator< ::com::mybo::framework::sound::SoundObject >(this->sounds->iterator());  __it->hasNext(); ){
			::com::mybo::framework::sound::SoundObject obj = __it->next();
			if (((type == obj->type))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",77)
				obj->destroy();
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,unloadByType,(void))

Void SoundQueue_obj::unloadAll( ){
{
		HX_SOURCE_PUSH("SoundQueue_obj::unloadAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",82)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->sounds->keys());  __it->hasNext(); ){
			::String key = __it->next();
			this->unloadByName(key);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundQueue_obj,unloadAll,(void))

bool SoundQueue_obj::hasSound( ::String name){
	HX_SOURCE_PUSH("SoundQueue_obj::hasSound")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",87)
	return this->sounds->exists(name);
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,hasSound,return )

Void SoundQueue_obj::stopSound( ::com::mybo::framework::sound::SoundObject soundObj){
{
		HX_SOURCE_PUSH("SoundQueue_obj::stopSound")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",90)
		if (((null() != soundObj->channel))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",92)
			soundObj->channel->stop();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/sound/SoundQueue.hx",93)
			soundObj->channel = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundQueue_obj,stopSound,(void))


SoundQueue_obj::SoundQueue_obj()
{
}

void SoundQueue_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundQueue);
	HX_MARK_MEMBER_NAME(sounds,"sounds");
	HX_MARK_END_CLASS();
}

Dynamic SoundQueue_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"sounds") ) { return sounds; }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"stopAll") ) { return stopAll_dyn(); }
		if (HX_FIELD_EQ(inName,"loadAll") ) { return loadAll_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasSound") ) { return hasSound_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"removeAll") ) { return removeAll_dyn(); }
		if (HX_FIELD_EQ(inName,"unloadAll") ) { return unloadAll_dyn(); }
		if (HX_FIELD_EQ(inName,"stopSound") ) { return stopSound_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"stopByType") ) { return stopByType_dyn(); }
		if (HX_FIELD_EQ(inName,"loadByName") ) { return loadByName_dyn(); }
		if (HX_FIELD_EQ(inName,"loadByType") ) { return loadByType_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"unloadByName") ) { return unloadByName_dyn(); }
		if (HX_FIELD_EQ(inName,"unloadByType") ) { return unloadByType_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getSoundObject") ) { return getSoundObject_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic SoundQueue_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"sounds") ) { sounds=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SoundQueue_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sounds"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sounds"),
	HX_CSTRING("add"),
	HX_CSTRING("getSoundObject"),
	HX_CSTRING("stop"),
	HX_CSTRING("stopByType"),
	HX_CSTRING("stopAll"),
	HX_CSTRING("loadByName"),
	HX_CSTRING("loadByType"),
	HX_CSTRING("loadAll"),
	HX_CSTRING("remove"),
	HX_CSTRING("removeAll"),
	HX_CSTRING("unloadByName"),
	HX_CSTRING("unloadByType"),
	HX_CSTRING("unloadAll"),
	HX_CSTRING("hasSound"),
	HX_CSTRING("stopSound"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class SoundQueue_obj::__mClass;

void SoundQueue_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.sound.SoundQueue"), hx::TCanCast< SoundQueue_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SoundQueue_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound
