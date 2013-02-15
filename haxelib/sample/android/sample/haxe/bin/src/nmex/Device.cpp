#include <hxcpp.h>

#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
namespace nmex{

Void Device_obj::__construct()
{
	return null();
}

Device_obj::~Device_obj() { }

Dynamic Device_obj::__CreateEmpty() { return  new Device_obj; }
hx::ObjectPtr< Device_obj > Device_obj::__new()
{  hx::ObjectPtr< Device_obj > result = new Device_obj();
	result->__construct();
	return result;}

Dynamic Device_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Device_obj > result = new Device_obj();
	result->__construct();
	return result;}

int Device_obj::contentScaleFactor;

bool Device_obj::forceRetina;

::String Device_obj::uniqueId( ){
	HX_SOURCE_PUSH("Device_obj::uniqueId")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",87)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,uniqueId,return )

::String Device_obj::osName( ){
	HX_SOURCE_PUSH("Device_obj::osName")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",91)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,osName,return )

::String Device_obj::osVersion( ){
	HX_SOURCE_PUSH("Device_obj::osVersion")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",95)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,osVersion,return )

::String Device_obj::deviceName( ){
	HX_SOURCE_PUSH("Device_obj::deviceName")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",99)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,deviceName,return )

::String Device_obj::model( ){
	HX_SOURCE_PUSH("Device_obj::model")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",103)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,model,return )

bool Device_obj::networkAvailable( ){
	HX_SOURCE_PUSH("Device_obj::networkAvailable")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",107)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,networkAvailable,return )

Void Device_obj::vibrate( double time){
{
		HX_SOURCE_PUSH("Device_obj::vibrate")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Device_obj,vibrate,(void))

bool Device_obj::isRetina( ){
	HX_SOURCE_PUSH("Device_obj::isRetina")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",114)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,isRetina,return )

double Device_obj::scaleFactor( ){
	HX_SOURCE_PUSH("Device_obj::scaleFactor")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",118)
	return ::nmex::Device_obj::contentScaleFactor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,scaleFactor,return )

::String Device_obj::getDocPath( ){
	HX_SOURCE_PUSH("Device_obj::getDocPath")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",123)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,getDocPath,return )

::String Device_obj::getRecPath( ){
	HX_SOURCE_PUSH("Device_obj::getRecPath")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/Device.hx",127)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Device_obj,getRecPath,return )


Device_obj::Device_obj()
{
}

void Device_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Device);
	HX_MARK_END_CLASS();
}

Dynamic Device_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"model") ) { return model_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"osName") ) { return osName_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"vibrate") ) { return vibrate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"uniqueId") ) { return uniqueId_dyn(); }
		if (HX_FIELD_EQ(inName,"isRetina") ) { return isRetina_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"osVersion") ) { return osVersion_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deviceName") ) { return deviceName_dyn(); }
		if (HX_FIELD_EQ(inName,"getDocPath") ) { return getDocPath_dyn(); }
		if (HX_FIELD_EQ(inName,"getRecPath") ) { return getRecPath_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"forceRetina") ) { return forceRetina; }
		if (HX_FIELD_EQ(inName,"scaleFactor") ) { return scaleFactor_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"networkAvailable") ) { return networkAvailable_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"contentScaleFactor") ) { return contentScaleFactor; }
	}
	return super::__Field(inName);
}

Dynamic Device_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"forceRetina") ) { forceRetina=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"contentScaleFactor") ) { contentScaleFactor=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Device_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("contentScaleFactor"),
	HX_CSTRING("forceRetina"),
	HX_CSTRING("uniqueId"),
	HX_CSTRING("osName"),
	HX_CSTRING("osVersion"),
	HX_CSTRING("deviceName"),
	HX_CSTRING("model"),
	HX_CSTRING("networkAvailable"),
	HX_CSTRING("vibrate"),
	HX_CSTRING("isRetina"),
	HX_CSTRING("scaleFactor"),
	HX_CSTRING("getDocPath"),
	HX_CSTRING("getRecPath"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Device_obj::contentScaleFactor,"contentScaleFactor");
	HX_MARK_MEMBER_NAME(Device_obj::forceRetina,"forceRetina");
};

Class Device_obj::__mClass;

void Device_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.Device"), hx::TCanCast< Device_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Device_obj::__boot()
{
	hx::Static(contentScaleFactor) = (int)1;
	hx::Static(forceRetina) = false;
}

} // end namespace nmex
