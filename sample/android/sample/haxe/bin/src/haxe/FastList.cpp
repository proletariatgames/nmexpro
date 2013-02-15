#include <hxcpp.h>

#ifndef INCLUDED_haxe_FastCell
#include <haxe/FastCell.h>
#endif
#ifndef INCLUDED_haxe_FastList
#include <haxe/FastList.h>
#endif
#ifndef INCLUDED_haxe_FastListIterator
#include <haxe/FastListIterator.h>
#endif
namespace haxe{

Void FastList_obj::__construct()
{
{
}
;
	return null();
}

FastList_obj::~FastList_obj() { }

Dynamic FastList_obj::__CreateEmpty() { return  new FastList_obj; }
hx::ObjectPtr< FastList_obj > FastList_obj::__new()
{  hx::ObjectPtr< FastList_obj > result = new FastList_obj();
	result->__construct();
	return result;}

Dynamic FastList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FastList_obj > result = new FastList_obj();
	result->__construct();
	return result;}

Void FastList_obj::add( Dynamic item){
{
		HX_SOURCE_PUSH("FastList_obj::add")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",60)
		this->head = ::haxe::FastCell_obj::__new(item,this->head);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FastList_obj,add,(void))

Dynamic FastList_obj::first( ){
	HX_SOURCE_PUSH("FastList_obj::first")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",68)
	return (  (((this->head == null()))) ? Dynamic(null()) : Dynamic(this->head->elt) );
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_obj,first,return )

Dynamic FastList_obj::pop( ){
	HX_SOURCE_PUSH("FastList_obj::pop")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",78)
	::haxe::FastCell k = this->head;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",79)
	if (((k == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",80)
		return null();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",82)
		this->head = k->next;
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",83)
		return k->elt;
	}
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_obj,pop,return )

bool FastList_obj::isEmpty( ){
	HX_SOURCE_PUSH("FastList_obj::isEmpty")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",90)
	return (this->head == null());
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_obj,isEmpty,return )

bool FastList_obj::remove( Dynamic v){
	HX_SOURCE_PUSH("FastList_obj::remove")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",99)
	Dynamic prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",100)
	::haxe::FastCell l = this->head;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",101)
	while(((l != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",102)
		if (((l->elt == v))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",103)
			if (((prev == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",104)
				this->head = l->next;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",106)
				prev->__FieldRef(HX_CSTRING("next")) = l->next;
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",107)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",109)
		prev = l;
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",110)
		l = l->next;
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",112)
	return (l != null());
}


HX_DEFINE_DYNAMIC_FUNC1(FastList_obj,remove,return )

Dynamic FastList_obj::iterator( ){
	HX_SOURCE_PUSH("FastList_obj::iterator")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",116)
	return ::haxe::FastListIterator_obj::__new(this->head);
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_obj,iterator,return )

::String FastList_obj::toString( ){
	HX_SOURCE_PUSH("FastList_obj::toString")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",142)
	Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",143)
	::haxe::FastCell l = this->head;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",144)
	while(((l != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",145)
		a->__Field(HX_CSTRING("push"))(l->elt);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",146)
		l = l->next;
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/FastList.hx",148)
	return ((HX_CSTRING("{") + a->__Field(HX_CSTRING("join"))(HX_CSTRING(","))) + HX_CSTRING("}"));
}


HX_DEFINE_DYNAMIC_FUNC0(FastList_obj,toString,return )


FastList_obj::FastList_obj()
{
}

void FastList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FastList);
	HX_MARK_MEMBER_NAME(head,"head");
	HX_MARK_END_CLASS();
}

Dynamic FastList_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"head") ) { return head; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"first") ) { return first_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FastList_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"head") ) { head=inValue.Cast< ::haxe::FastCell >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FastList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("head"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("head"),
	HX_CSTRING("add"),
	HX_CSTRING("first"),
	HX_CSTRING("pop"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("remove"),
	HX_CSTRING("iterator"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FastList_obj::__mClass;

void FastList_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.FastList"), hx::TCanCast< FastList_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FastList_obj::__boot()
{
}

} // end namespace haxe
