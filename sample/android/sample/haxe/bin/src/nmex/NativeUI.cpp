#include <hxcpp.h>

#ifndef INCLUDED_nme_JNI
#include <nme/JNI.h>
#endif
#ifndef INCLUDED_nmex_NativeUI
#include <nmex/NativeUI.h>
#endif
namespace nmex{

Void NativeUI_obj::__construct()
{
	return null();
}

NativeUI_obj::~NativeUI_obj() { }

Dynamic NativeUI_obj::__CreateEmpty() { return  new NativeUI_obj; }
hx::ObjectPtr< NativeUI_obj > NativeUI_obj::__new()
{  hx::ObjectPtr< NativeUI_obj > result = new NativeUI_obj();
	result->__construct();
	return result;}

Dynamic NativeUI_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeUI_obj > result = new NativeUI_obj();
	result->__construct();
	return result;}

Dynamic NativeUI_obj::_showAlert_func;

Void NativeUI_obj::showAlert( ::String title,::String msg){
{
		HX_SOURCE_PUSH("NativeUI_obj::showAlert")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NativeUI.hx",8)
		if (((::nmex::NativeUI_obj::_showAlert_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NativeUI.hx",9)
			::nmex::NativeUI_obj::_showAlert_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("showDialog"),HX_CSTRING("(Ljava/lang/String;Ljava/lang/String;)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NativeUI.hx",10)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NativeUI.hx",11)
		a->__Field(HX_CSTRING("push"))(title);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NativeUI.hx",12)
		a->__Field(HX_CSTRING("push"))(msg);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NativeUI.hx",14)
		::nmex::NativeUI_obj::_showAlert_func(a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NativeUI_obj,showAlert,(void))


NativeUI_obj::NativeUI_obj()
{
}

void NativeUI_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeUI);
	HX_MARK_END_CLASS();
}

Dynamic NativeUI_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"showAlert") ) { return showAlert_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_showAlert_func") ) { return _showAlert_func; }
	}
	return super::__Field(inName);
}

Dynamic NativeUI_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"_showAlert_func") ) { _showAlert_func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NativeUI_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_showAlert_func"),
	HX_CSTRING("showAlert"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeUI_obj::_showAlert_func,"_showAlert_func");
};

Class NativeUI_obj::__mClass;

void NativeUI_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.NativeUI"), hx::TCanCast< NativeUI_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NativeUI_obj::__boot()
{
	hx::Static(_showAlert_func);
}

} // end namespace nmex
