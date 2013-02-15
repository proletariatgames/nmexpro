#include <hxcpp.h>

#ifndef INCLUDED_haxe_FastCell
#include <haxe/FastCell.h>
#endif
namespace haxe{

Void FastCell_obj::__construct(Dynamic elt,::haxe::FastCell next)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",30)
	this->elt = elt;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",30)
	this->next = next;
}
;
	return null();
}

FastCell_obj::~FastCell_obj() { }

Dynamic FastCell_obj::__CreateEmpty() { return  new FastCell_obj; }
hx::ObjectPtr< FastCell_obj > FastCell_obj::__new(Dynamic elt,::haxe::FastCell next)
{  hx::ObjectPtr< FastCell_obj > result = new FastCell_obj();
	result->__construct(elt,next);
	return result;}

Dynamic FastCell_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FastCell_obj > result = new FastCell_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


FastCell_obj::FastCell_obj()
{
}

void FastCell_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FastCell);
	HX_MARK_MEMBER_NAME(elt,"elt");
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_END_CLASS();
}

Dynamic FastCell_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"elt") ) { return elt; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
	}
	return super::__Field(inName);
}

Dynamic FastCell_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"elt") ) { elt=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::haxe::FastCell >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FastCell_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("elt"));
	outFields->push(HX_CSTRING("next"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("elt"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FastCell_obj::__mClass;

void FastCell_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.FastCell"), hx::TCanCast< FastCell_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FastCell_obj::__boot()
{
}

} // end namespace haxe
