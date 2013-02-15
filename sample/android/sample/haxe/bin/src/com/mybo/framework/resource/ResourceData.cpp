#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_resource_ResourceData
#include <com/mybo/framework/resource/ResourceData.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace resource{

Void ResourceData_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",13)
	this->tileWidth = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",14)
	this->tileHeight = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",15)
	this->cols = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",16)
	this->frameNumber = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",17)
	this->id = Array_obj< ::String >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",18)
	this->folder = Array_obj< ::String >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",19)
	this->optimized = Array_obj< bool >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",20)
	this->scale = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/ResourceData.hx",21)
	this->url = Array_obj< Array< ::String > >::__new();
}
;
	return null();
}

ResourceData_obj::~ResourceData_obj() { }

Dynamic ResourceData_obj::__CreateEmpty() { return  new ResourceData_obj; }
hx::ObjectPtr< ResourceData_obj > ResourceData_obj::__new()
{  hx::ObjectPtr< ResourceData_obj > result = new ResourceData_obj();
	result->__construct();
	return result;}

Dynamic ResourceData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ResourceData_obj > result = new ResourceData_obj();
	result->__construct();
	return result;}


ResourceData_obj::ResourceData_obj()
{
}

void ResourceData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ResourceData);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(tileWidth,"tileWidth");
	HX_MARK_MEMBER_NAME(tileHeight,"tileHeight");
	HX_MARK_MEMBER_NAME(cols,"cols");
	HX_MARK_MEMBER_NAME(frameNumber,"frameNumber");
	HX_MARK_MEMBER_NAME(folder,"folder");
	HX_MARK_MEMBER_NAME(optimized,"optimized");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_END_CLASS();
}

Dynamic ResourceData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cols") ) { return cols; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"folder") ) { return folder; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { return tileWidth; }
		if (HX_FIELD_EQ(inName,"optimized") ) { return optimized; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tileHeight") ) { return tileHeight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frameNumber") ) { return frameNumber; }
	}
	return super::__Field(inName);
}

Dynamic ResourceData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< Array< Array< ::String > > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cols") ) { cols=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"folder") ) { folder=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { tileWidth=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"optimized") ) { optimized=inValue.Cast< Array< bool > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tileHeight") ) { tileHeight=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frameNumber") ) { frameNumber=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ResourceData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("tileWidth"));
	outFields->push(HX_CSTRING("tileHeight"));
	outFields->push(HX_CSTRING("cols"));
	outFields->push(HX_CSTRING("frameNumber"));
	outFields->push(HX_CSTRING("folder"));
	outFields->push(HX_CSTRING("optimized"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("url"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("tileWidth"),
	HX_CSTRING("tileHeight"),
	HX_CSTRING("cols"),
	HX_CSTRING("frameNumber"),
	HX_CSTRING("folder"),
	HX_CSTRING("optimized"),
	HX_CSTRING("scale"),
	HX_CSTRING("url"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ResourceData_obj::__mClass;

void ResourceData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.resource.ResourceData"), hx::TCanCast< ResourceData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ResourceData_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource
