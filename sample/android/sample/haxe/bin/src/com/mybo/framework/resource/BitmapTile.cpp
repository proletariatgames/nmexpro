#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_Tilesheet
#include <nme/display/Tilesheet.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace resource{

Void BitmapTile_obj::__construct(::String id,double tileWidth,double tileHeight,::nme::display::BitmapData data)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",52)
	this->id = id;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",53)
	this->width = tileWidth;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",54)
	this->height = tileHeight;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",55)
	this->totalFrames = (int)0;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",56)
	this->bitmapData = data;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",57)
	this->tilesheet = ::nme::display::Tilesheet_obj::__new(data);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",58)
	this->rects = Array_obj< ::nme::geom::Rectangle >::__new();
}
;
	return null();
}

BitmapTile_obj::~BitmapTile_obj() { }

Dynamic BitmapTile_obj::__CreateEmpty() { return  new BitmapTile_obj; }
hx::ObjectPtr< BitmapTile_obj > BitmapTile_obj::__new(::String id,double tileWidth,double tileHeight,::nme::display::BitmapData data)
{  hx::ObjectPtr< BitmapTile_obj > result = new BitmapTile_obj();
	result->__construct(id,tileWidth,tileHeight,data);
	return result;}

Dynamic BitmapTile_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapTile_obj > result = new BitmapTile_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BitmapTile_obj::addTileRect( ::nme::geom::Rectangle rect){
{
		HX_SOURCE_PUSH("BitmapTile_obj::addTileRect")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",61)
		this->rects->push(rect);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",62)
		this->tilesheet->addTileRect(rect,null());
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/BitmapTile.hx",63)
		(this->totalFrames)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapTile_obj,addTileRect,(void))


BitmapTile_obj::BitmapTile_obj()
{
}

void BitmapTile_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapTile);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(totalFrames,"totalFrames");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(tilesheet,"tilesheet");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(rects,"rects");
	HX_MARK_END_CLASS();
}

Dynamic BitmapTile_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		if (HX_FIELD_EQ(inName,"rects") ) { return rects; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tilesheet") ) { return tilesheet; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalFrames") ) { return totalFrames; }
		if (HX_FIELD_EQ(inName,"addTileRect") ) { return addTileRect_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BitmapTile_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rects") ) { rects=inValue.Cast< Array< ::nme::geom::Rectangle > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tilesheet") ) { tilesheet=inValue.Cast< ::nme::display::Tilesheet >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalFrames") ) { totalFrames=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapTile_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("totalFrames"));
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("tilesheet"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("rects"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("totalFrames"),
	HX_CSTRING("bitmapData"),
	HX_CSTRING("tilesheet"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("scale"),
	HX_CSTRING("rects"),
	HX_CSTRING("addTileRect"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapTile_obj::__mClass;

void BitmapTile_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.resource.BitmapTile"), hx::TCanCast< BitmapTile_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapTile_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource
