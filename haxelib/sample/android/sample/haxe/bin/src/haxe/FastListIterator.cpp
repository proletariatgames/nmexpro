#include <hxcpp.h>

#ifndef INCLUDED_haxe_FastCell
#include <haxe/FastCell.h>
#endif
#ifndef INCLUDED_haxe_FastListIterator
#include <haxe/FastListIterator.h>
#endif
namespace haxe{

Void FastListIterator_obj::__construct(::haxe::FastCell head)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",39)
	this->current = head;
}
;
	return null();
}

FastListIterator_obj::~FastListIterator_obj() { }

Dynamic FastListIterator_obj::__CreateEmpty() { return  new FastListIterator_obj; }
hx::ObjectPtr< FastListIterator_obj > FastListIterator_obj::__new(::haxe::FastCell head)
{  hx::ObjectPtr< FastListIterator_obj > result = new FastListIterator_obj();
	result->__construct(head);
	return result;}

Dynamic FastListIterator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FastListIterator_obj > result = new FastListIterator_obj();
	result->__construct(inArgs[0]);
	return result;}

bool FastListIterator_obj::hasNext( ){
	HX_SOURCE_PUSH("FastListIterator_obj::hasNext")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",36)
	return (this->current != null());
}


HX_DEFINE_DYNAMIC_FUNC0(FastListIterator_obj,hasNext,return )

Dynamic FastListIterator_obj::next( ){
	HX_SOURCE_PUSH("FastListIterator_obj::next")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",37)
	Dynamic result = this->current->elt;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",37)
	this->current = this->current->next;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",37)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(FastListIterator_obj,next,return )


FastListIterator_obj::FastListIterator_obj()
{
}

void FastListIterator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FastListIterator);
	HX_MARK_MEMBER_NAME(current,"current");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FastListIterator_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return current; }
		if (HX_FIELD_EQ(inName,"hasNext") ) { return hasNext_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FastListIterator_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::haxe::FastCell >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FastListIterator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("current"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("current"),
	HX_CSTRING("hasNext"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FastListIterator_obj::__mClass;

void FastListIterator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.FastListIterator"), hx::TCanCast< FastListIterator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FastListIterator_obj::__boot()
{
}

} // end namespace haxe
