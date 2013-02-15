#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_nme_JNIMethod
#include <nme/JNIMethod.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
namespace nme{

Void JNIMethod_obj::__construct(Dynamic method)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",81)
	this->method = method;
}
;
	return null();
}

JNIMethod_obj::~JNIMethod_obj() { }

Dynamic JNIMethod_obj::__CreateEmpty() { return  new JNIMethod_obj; }
hx::ObjectPtr< JNIMethod_obj > JNIMethod_obj::__new(Dynamic method)
{  hx::ObjectPtr< JNIMethod_obj > result = new JNIMethod_obj();
	result->__construct(method);
	return result;}

Dynamic JNIMethod_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JNIMethod_obj > result = new JNIMethod_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic JNIMethod_obj::callMember( Dynamic args){
	HX_SOURCE_PUSH("JNIMethod_obj::callMember")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",88)
	Dynamic jobject = args->__Field(HX_CSTRING("shift"))();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",89)
	return ::nme::JNIMethod_obj::nme_jni_call_member(this->method,jobject,args);
}


HX_DEFINE_DYNAMIC_FUNC1(JNIMethod_obj,callMember,return )

Dynamic JNIMethod_obj::callStatic( Dynamic args){
	HX_SOURCE_PUSH("JNIMethod_obj::callStatic")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",94)
	return ::nme::JNIMethod_obj::nme_jni_call_static(this->method,args);
}


HX_DEFINE_DYNAMIC_FUNC1(JNIMethod_obj,callStatic,return )

Dynamic JNIMethod_obj::getMemberMethod( bool useArray){
	HX_SOURCE_PUSH("JNIMethod_obj::getMemberMethod")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",100)
	if ((useArray)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",102)
		return this->callMember_dyn();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",107)
		this->callMemberArgs = ::Reflect_obj::makeVarArgs(this->callMember_dyn());
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",108)
		return this->callMemberArgs;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(JNIMethod_obj,getMemberMethod,return )

Dynamic JNIMethod_obj::getStaticMethod( bool useArray){
	HX_SOURCE_PUSH("JNIMethod_obj::getStaticMethod")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",114)
	if ((useArray)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",116)
		return this->callStatic_dyn();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",121)
		this->callStaticArgs = ::Reflect_obj::makeVarArgs(this->callStatic_dyn());
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,1,1/nme/JNI.hx",122)
		return this->callStaticArgs;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(JNIMethod_obj,getStaticMethod,return )

Dynamic JNIMethod_obj::nme_jni_call_member;

Dynamic JNIMethod_obj::nme_jni_call_static;


JNIMethod_obj::JNIMethod_obj()
{
}

void JNIMethod_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JNIMethod);
	HX_MARK_MEMBER_NAME(callMemberArgs,"callMemberArgs");
	HX_MARK_MEMBER_NAME(callStaticArgs,"callStaticArgs");
	HX_MARK_MEMBER_NAME(method,"method");
	HX_MARK_END_CLASS();
}

Dynamic JNIMethod_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { return method; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"callMember") ) { return callMember_dyn(); }
		if (HX_FIELD_EQ(inName,"callStatic") ) { return callStatic_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"callMemberArgs") ) { return callMemberArgs; }
		if (HX_FIELD_EQ(inName,"callStaticArgs") ) { return callStaticArgs; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getMemberMethod") ) { return getMemberMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"getStaticMethod") ) { return getStaticMethod_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_jni_call_member") ) { return nme_jni_call_member; }
		if (HX_FIELD_EQ(inName,"nme_jni_call_static") ) { return nme_jni_call_static; }
	}
	return super::__Field(inName);
}

Dynamic JNIMethod_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { method=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"callMemberArgs") ) { callMemberArgs=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"callStaticArgs") ) { callStaticArgs=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_jni_call_member") ) { nme_jni_call_member=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_jni_call_static") ) { nme_jni_call_static=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void JNIMethod_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("callMemberArgs"));
	outFields->push(HX_CSTRING("callStaticArgs"));
	outFields->push(HX_CSTRING("method"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_jni_call_member"),
	HX_CSTRING("nme_jni_call_static"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("callMemberArgs"),
	HX_CSTRING("callStaticArgs"),
	HX_CSTRING("method"),
	HX_CSTRING("callMember"),
	HX_CSTRING("callStatic"),
	HX_CSTRING("getMemberMethod"),
	HX_CSTRING("getStaticMethod"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JNIMethod_obj::nme_jni_call_member,"nme_jni_call_member");
	HX_MARK_MEMBER_NAME(JNIMethod_obj::nme_jni_call_static,"nme_jni_call_static");
};

Class JNIMethod_obj::__mClass;

void JNIMethod_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.JNIMethod"), hx::TCanCast< JNIMethod_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void JNIMethod_obj::__boot()
{
	hx::Static(nme_jni_call_member) = ::nme::Loader_obj::load(HX_CSTRING("nme_jni_call_member"),(int)3);
	hx::Static(nme_jni_call_static) = ::nme::Loader_obj::load(HX_CSTRING("nme_jni_call_static"),(int)2);
}

} // end namespace nme
