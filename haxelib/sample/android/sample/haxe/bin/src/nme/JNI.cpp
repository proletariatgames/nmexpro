#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cpp_zip_Uncompress
#include <cpp/zip/Uncompress.h>
#endif
#ifndef INCLUDED_haxe_BaseCode
#include <haxe/BaseCode.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_JNI
#include <nme/JNI.h>
#endif
#ifndef INCLUDED_nme_JNIMethod
#include <nme/JNIMethod.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
namespace nme{

Void JNI_obj::__construct()
{
	return null();
}

JNI_obj::~JNI_obj() { }

Dynamic JNI_obj::__CreateEmpty() { return  new JNI_obj; }
hx::ObjectPtr< JNI_obj > JNI_obj::__new()
{  hx::ObjectPtr< JNI_obj > result = new JNI_obj();
	result->__construct();
	return result;}

Dynamic JNI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JNI_obj > result = new JNI_obj();
	result->__construct();
	return result;}

::Hash JNI_obj::alreadyCreated;

::String JNI_obj::base64;

Dynamic JNI_obj::createInterface( Dynamic haxeClass,::String className,::String classDef){
	HX_SOURCE_PUSH("JNI_obj::createInterface")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",20)
	::haxe::io::Bytes bytes = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",21)
	if ((!(::nme::JNI_obj::alreadyCreated->get(className)))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",23)
		bytes = ::haxe::io::Bytes_obj::ofString(::haxe::BaseCode_obj::decode(classDef,::nme::JNI_obj::base64));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",24)
		bytes = ::cpp::zip::Uncompress_obj::run(bytes,(int)9);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",25)
		::nme::JNI_obj::alreadyCreated->set(className,true);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",27)
	return ::nme::JNI_obj::nme_jni_create_interface(haxeClass,className,(  (((bytes == null()))) ? Array< unsigned char >(null()) : Array< unsigned char >(bytes->b) ));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(JNI_obj,createInterface,return )

Dynamic JNI_obj::createMemberMethod( ::String className,::String memberName,::String signature,Dynamic __o_useArray){
bool useArray = __o_useArray.Default(false);
	HX_SOURCE_PUSH("JNI_obj::createMemberMethod");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",41)
		::nme::JNIMethod method = ::nme::JNIMethod_obj::__new(::nme::JNI_obj::nme_jni_create_method(className,memberName,signature,false));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",42)
		return method->getMemberMethod(useArray);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(JNI_obj,createMemberMethod,return )

Dynamic JNI_obj::createStaticMethod( ::String className,::String memberName,::String signature,Dynamic __o_useArray){
bool useArray = __o_useArray.Default(false);
	HX_SOURCE_PUSH("JNI_obj::createStaticMethod");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",56)
		::nme::JNIMethod method = ::nme::JNIMethod_obj::__new(::nme::JNI_obj::nme_jni_create_method(className,memberName,signature,true));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",57)
		return method->getStaticMethod(useArray);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(JNI_obj,createStaticMethod,return )

Dynamic JNI_obj::nme_jni_create_method;

Dynamic JNI_obj::nme_jni_create_interface;


JNI_obj::JNI_obj()
{
}

void JNI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JNI);
	HX_MARK_END_CLASS();
}

Dynamic JNI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"base64") ) { return base64; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"alreadyCreated") ) { return alreadyCreated; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"createInterface") ) { return createInterface_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createMemberMethod") ) { return createMemberMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"createStaticMethod") ) { return createStaticMethod_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_jni_create_method") ) { return nme_jni_create_method; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_jni_create_interface") ) { return nme_jni_create_interface; }
	}
	return super::__Field(inName);
}

Dynamic JNI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"base64") ) { base64=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"alreadyCreated") ) { alreadyCreated=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_jni_create_method") ) { nme_jni_create_method=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_jni_create_interface") ) { nme_jni_create_interface=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void JNI_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("alreadyCreated"),
	HX_CSTRING("base64"),
	HX_CSTRING("createInterface"),
	HX_CSTRING("createMemberMethod"),
	HX_CSTRING("createStaticMethod"),
	HX_CSTRING("nme_jni_create_method"),
	HX_CSTRING("nme_jni_create_interface"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JNI_obj::alreadyCreated,"alreadyCreated");
	HX_MARK_MEMBER_NAME(JNI_obj::base64,"base64");
	HX_MARK_MEMBER_NAME(JNI_obj::nme_jni_create_method,"nme_jni_create_method");
	HX_MARK_MEMBER_NAME(JNI_obj::nme_jni_create_interface,"nme_jni_create_interface");
};

Class JNI_obj::__mClass;

void JNI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.JNI"), hx::TCanCast< JNI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void JNI_obj::__boot()
{
	hx::Static(alreadyCreated) = ::Hash_obj::__new();
	hx::Static(base64) = HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
	hx::Static(nme_jni_create_method) = ::nme::Loader_obj::load(HX_CSTRING("nme_jni_create_method"),(int)4);
	hx::Static(nme_jni_create_interface) = ::nme::Loader_obj::load(HX_CSTRING("nme_jni_create_interface"),(int)3);
}

} // end namespace nme
