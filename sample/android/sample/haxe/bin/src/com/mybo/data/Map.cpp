#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_data_Map
#include <com/mybo/data/Map.h>
#endif
namespace com{
namespace mybo{
namespace data{

Void Map_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/data/Map.hx",15)
	this->data = Array_obj< Array< int > >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/Map.hx",16)
	this->solution = Array_obj< Array< int > >::__new();
}
;
	return null();
}

Map_obj::~Map_obj() { }

Dynamic Map_obj::__CreateEmpty() { return  new Map_obj; }
hx::ObjectPtr< Map_obj > Map_obj::__new()
{  hx::ObjectPtr< Map_obj > result = new Map_obj();
	result->__construct();
	return result;}

Dynamic Map_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Map_obj > result = new Map_obj();
	result->__construct();
	return result;}

::String Map_obj::toString( ){
	HX_SOURCE_PUSH("Map_obj::toString")
	HX_SOURCE_POS("../../../src/com/mybo/data/Map.hx",20)
	return this->data->toString();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,toString,return )

int Map_obj::ROW;

int Map_obj::COL;


Map_obj::Map_obj()
{
}

void Map_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Map);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(solutionStep,"solutionStep");
	HX_MARK_MEMBER_NAME(solution,"solution");
	HX_MARK_MEMBER_NAME(buyTip,"buyTip");
	HX_MARK_END_CLASS();
}

Dynamic Map_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ROW") ) { return ROW; }
		if (HX_FIELD_EQ(inName,"COL") ) { return COL; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"buyTip") ) { return buyTip; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"solution") ) { return solution; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"solutionStep") ) { return solutionStep; }
	}
	return super::__Field(inName);
}

Dynamic Map_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ROW") ) { ROW=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"COL") ) { COL=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Array< Array< int > > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"buyTip") ) { buyTip=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"solution") ) { solution=inValue.Cast< Array< Array< int > > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"solutionStep") ) { solutionStep=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Map_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("solutionStep"));
	outFields->push(HX_CSTRING("solution"));
	outFields->push(HX_CSTRING("buyTip"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ROW"),
	HX_CSTRING("COL"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("solutionStep"),
	HX_CSTRING("solution"),
	HX_CSTRING("buyTip"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Map_obj::ROW,"ROW");
	HX_MARK_MEMBER_NAME(Map_obj::COL,"COL");
};

Class Map_obj::__mClass;

void Map_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.data.Map"), hx::TCanCast< Map_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Map_obj::__boot()
{
	hx::Static(ROW) = (int)6;
	hx::Static(COL) = (int)5;
}

} // end namespace com
} // end namespace mybo
} // end namespace data
