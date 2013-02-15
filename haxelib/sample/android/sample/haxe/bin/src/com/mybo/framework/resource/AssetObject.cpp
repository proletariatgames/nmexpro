#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_resource_AssetObject
#include <com/mybo/framework/resource/AssetObject.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace resource{

Void AssetObject_obj::__construct()
{
{
}
;
	return null();
}

AssetObject_obj::~AssetObject_obj() { }

Dynamic AssetObject_obj::__CreateEmpty() { return  new AssetObject_obj; }
hx::ObjectPtr< AssetObject_obj > AssetObject_obj::__new()
{  hx::ObjectPtr< AssetObject_obj > result = new AssetObject_obj();
	result->__construct();
	return result;}

Dynamic AssetObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AssetObject_obj > result = new AssetObject_obj();
	result->__construct();
	return result;}


AssetObject_obj::AssetObject_obj()
{
}

void AssetObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AssetObject);
	HX_MARK_MEMBER_NAME(tileWidth,"tileWidth");
	HX_MARK_MEMBER_NAME(tileHeight,"tileHeight");
	HX_MARK_MEMBER_NAME(cols,"cols");
	HX_MARK_MEMBER_NAME(frameNumber,"frameNumber");
	HX_MARK_MEMBER_NAME(typeInfo,"typeInfo");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(folder,"folder");
	HX_MARK_MEMBER_NAME(optimized,"optimized");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_END_CLASS();
}

Dynamic AssetObject_obj::__Field(const ::String &inName)
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
	case 8:
		if (HX_FIELD_EQ(inName,"typeInfo") ) { return typeInfo; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { return tileWidth; }
		if (HX_FIELD_EQ(inName,"optimized") ) { return optimized; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tileHeight") ) { return tileHeight; }
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frameNumber") ) { return frameNumber; }
	}
	return super::__Field(inName);
}

Dynamic AssetObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cols") ) { cols=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"folder") ) { folder=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"typeInfo") ) { typeInfo=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { tileWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"optimized") ) { optimized=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tileHeight") ) { tileHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frameNumber") ) { frameNumber=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AssetObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tileWidth"));
	outFields->push(HX_CSTRING("tileHeight"));
	outFields->push(HX_CSTRING("cols"));
	outFields->push(HX_CSTRING("frameNumber"));
	outFields->push(HX_CSTRING("typeInfo"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("folder"));
	outFields->push(HX_CSTRING("optimized"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("bitmapData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("tileWidth"),
	HX_CSTRING("tileHeight"),
	HX_CSTRING("cols"),
	HX_CSTRING("frameNumber"),
	HX_CSTRING("typeInfo"),
	HX_CSTRING("id"),
	HX_CSTRING("folder"),
	HX_CSTRING("optimized"),
	HX_CSTRING("scale"),
	HX_CSTRING("url"),
	HX_CSTRING("bitmapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AssetObject_obj::__mClass;

void AssetObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.resource.AssetObject"), hx::TCanCast< AssetObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AssetObject_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource
