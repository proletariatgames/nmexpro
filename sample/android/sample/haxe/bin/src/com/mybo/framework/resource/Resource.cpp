#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_AssetObject
#include <com/mybo/framework/resource/AssetObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_Resource
#include <com/mybo/framework/resource/Resource.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_ResourceData
#include <com/mybo/framework/resource/ResourceData.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_PixelSnapping
#include <nme/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace resource{

Void Resource_obj::__construct(::String path,::String xmlFilePath)
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",22)
	this->data = ::com::mybo::framework::resource::ResourceData_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",23)
	this->rootPath = path;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",24)
	this->bitmapTileHash = ::Hash_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",25)
	::nme::utils::ByteArray bytes = ::nme::utils::ByteArray_obj::readFile(xmlFilePath);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",26)
	::Xml xml = ::Xml_obj::parse(bytes->readUTFBytes(bytes->length))->firstElement();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",27)
	::String id = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",28)
	::String tileWidth = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",29)
	::String tileHeight = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",30)
	::String cols = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",31)
	::String frameNumber = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",32)
	::String folder = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",33)
	::String optimized = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",34)
	::String scale = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",35)
	::String url = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",36)
	::String alphaUrl = HX_CSTRING("");
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",38)
	for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml->elementsNamed(HX_CSTRING("item")));  __it->hasNext(); ){
		::Xml item = __it->next();
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",39)
			for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(item->elements());  __it->hasNext(); ){
				::Xml ele = __it->next();
				{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",40)
					if (((bool((ele->getNodeName() == HX_CSTRING("id"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",40)
						id = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",40)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",41)
					if (((bool((ele->getNodeName() == HX_CSTRING("tileWidth"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",41)
						tileWidth = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",41)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",42)
					if (((bool((ele->getNodeName() == HX_CSTRING("tileHeight"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",42)
						tileHeight = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",42)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",43)
					if (((bool((ele->getNodeName() == HX_CSTRING("cols"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",43)
						cols = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",43)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",44)
					if (((bool((ele->getNodeName() == HX_CSTRING("frameNumber"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",44)
						frameNumber = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",44)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",45)
					if (((bool((ele->getNodeName() == HX_CSTRING("folder"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",45)
						folder = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",45)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",46)
					if (((bool((ele->getNodeName() == HX_CSTRING("optimized"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",46)
						optimized = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",46)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",47)
					if (((bool((ele->getNodeName() == HX_CSTRING("scale"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",47)
						scale = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",47)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",48)
					if (((bool((ele->getNodeName() == HX_CSTRING("url"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",48)
						url = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",48)
						HX_CSTRING("");
					}
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",49)
					if (((bool((ele->getNodeName() == HX_CSTRING("alphaUrl"))) && bool((ele->firstChild() != null()))))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",49)
						alphaUrl = ele->firstChild()->toString();
					}
					else{
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",49)
						HX_CSTRING("");
					}
				}
;
			}
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",51)
			this->data->id->push(id);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",52)
			this->data->tileWidth->push(::Std_obj::parseInt(tileWidth));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",53)
			this->data->tileHeight->push(::Std_obj::parseInt(tileHeight));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",54)
			this->data->cols->push(::Std_obj::parseInt(cols));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",55)
			this->data->frameNumber->push(::Std_obj::parseInt(frameNumber));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",56)
			this->data->folder->push(folder);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",57)
			this->data->optimized->push((  (((optimized == HX_CSTRING("true")))) ? bool(true) : bool(false) ));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",58)
			this->data->scale->push(::Std_obj::parseInt(scale));
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",59)
			if (((HX_CSTRING("true") == optimized))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",59)
				this->data->url->push(Array_obj< ::String >::__new().Add(url).Add(alphaUrl));
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",61)
				this->data->url->push(Array_obj< ::String >::__new().Add(url));
			}
		}
;
	}
}
;
	return null();
}

Resource_obj::~Resource_obj() { }

Dynamic Resource_obj::__CreateEmpty() { return  new Resource_obj; }
hx::ObjectPtr< Resource_obj > Resource_obj::__new(::String path,::String xmlFilePath)
{  hx::ObjectPtr< Resource_obj > result = new Resource_obj();
	result->__construct(path,xmlFilePath);
	return result;}

Dynamic Resource_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Resource_obj > result = new Resource_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Resource_obj::loadAll( ){
{
		HX_SOURCE_PUSH("Resource_obj::loadAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",67)
		int _g1 = (int)0;
		int _g = this->data->id->length;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",67)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",67)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",68)
			this->loadBitmap(this->data->id->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,loadAll,(void))

::nmex::display::Bitmap Resource_obj::getBitmap( ::String id,Dynamic __o_smooth){
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Resource_obj::getBitmap");
{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",73)
		smooth = true;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",76)
		if (((::nmex::Device_obj::deviceName() == HX_CSTRING("iPad")))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",76)
			smooth = true;
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",80)
		::com::mybo::framework::resource::BitmapTile tile = this->loadBitmap(id);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",81)
		::nmex::display::Bitmap bitmap = ::nmex::display::Bitmap_obj::__new(tile->bitmapData,null(),smooth);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",82)
		bitmap->nmeSetScaleX(tile->scale);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",83)
		bitmap->nmeSetScaleY(tile->scale);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",84)
		return bitmap;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Resource_obj,getBitmap,return )

Void Resource_obj::mergeAlpha( ::nme::display::BitmapData src,::nme::display::BitmapData des){
{
		HX_SOURCE_PUSH("Resource_obj::mergeAlpha")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",87)
		int width = ::Std_obj::_int(::Math_obj::min(src->nmeGetWidth(),des->nmeGetWidth()));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",88)
		int height = ::Std_obj::_int(::Math_obj::min(src->nmeGetHeight(),des->nmeGetHeight()));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",90)
		int i = (int)0;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",91)
		int j = (int)0;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",92)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",92)
			int _g = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",92)
			while(((_g < width))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",92)
				int i1 = (_g)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",93)
				{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",93)
					int _g1 = (int)0;
					HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",93)
					while(((_g1 < height))){
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",93)
						int j1 = (_g1)++;
						HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",94)
						des->setPixel32(i1,j1,(int((int(des->getPixel(i1,j1)) & int((int)16777215))) | int((int((int(src->getPixel(i1,j1)) >> int((int)16))) << int((int)24)))));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Resource_obj,mergeAlpha,(void))

::com::mybo::framework::resource::BitmapTile Resource_obj::getTile( ::String id){
	HX_SOURCE_PUSH("Resource_obj::getTile")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",98)
	return this->loadBitmap(id);
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,getTile,return )

::com::mybo::framework::resource::BitmapTile Resource_obj::loadBitmap( ::String id){
	HX_SOURCE_PUSH("Resource_obj::loadBitmap")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",105)
	::nme::geom::Point point = ::nme::geom::Point_obj::__new((int)0,(int)0);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",106)
	::nme::geom::Rectangle rec = ::nme::geom::Rectangle_obj::__new((int)0,(int)0,(int)0,(int)0);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",108)
	if ((!(this->bitmapTileHash->exists(id)))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",109)
		::com::mybo::framework::resource::AssetObject obj = this->getAssetObject(id);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",110)
		if ((obj->optimized)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",112)
			this->a1 = ::nme::display::BitmapData_obj::load((this->rootPath + obj->url->__get((int)0)),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",113)
			this->a2 = ::nme::display::BitmapData_obj::load((this->rootPath + obj->url->__get((int)1)),null());
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",115)
			rec->width = this->a1->nmeGetWidth();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",116)
			rec->height = this->a1->nmeGetHeight();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",118)
			this->a3 = ::nme::display::BitmapData_obj::__new(this->a1->nmeGetWidth(),this->a1->nmeGetHeight(),true,(int)-1);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",120)
			this->a3->copyPixels(this->a1,rec,point,null(),null(),false);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",124)
			this->a3->copyChannel(this->a2,rec,point,(int)1,(int)8);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",125)
			obj->bitmapData = this->a3;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",126)
			this->a1->dispose();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",127)
			this->a2->dispose();
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",128)
			obj->bitmapData = ::nme::display::BitmapData_obj::load((this->rootPath + obj->url->__get((int)0)),null());
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",131)
		::com::mybo::framework::resource::BitmapTile bitmapTile = ::com::mybo::framework::resource::BitmapTile_obj::__new(obj->id,obj->tileWidth,obj->tileHeight,obj->bitmapData);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",132)
		bitmapTile->scale = obj->scale;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",134)
		obj->bitmapData->createHardwareSurface();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",135)
		obj->bitmapData->dumpBits();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",137)
		double x;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",138)
		double y;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",139)
		::nme::geom::Rectangle rect;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",140)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",140)
			int _g1 = (int)0;
			int _g = obj->frameNumber;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",140)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",140)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",141)
				x = (obj->tileWidth * (hx::Mod(i,obj->cols)));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",142)
				y = (double((obj->tileHeight * ((i - hx::Mod(i,obj->cols))))) / double(obj->cols));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",143)
				rect = ::nme::geom::Rectangle_obj::__new(x,y,obj->tileWidth,obj->tileHeight);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",144)
				bitmapTile->addTileRect(rect);
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",147)
		bitmapTile->bitmapData->createHardwareSurface();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",148)
		bitmapTile->bitmapData->dumpBits();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",149)
		this->bitmapTileHash->set(id,bitmapTile);
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",151)
	return this->bitmapTileHash->get(id);
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,loadBitmap,return )

::com::mybo::framework::resource::AssetObject Resource_obj::getAssetObject( ::String id){
	HX_SOURCE_PUSH("Resource_obj::getAssetObject")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",154)
	int flag = (int)0;
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",155)
	{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",155)
		int _g1 = (int)0;
		int _g = this->data->id->length;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",155)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",155)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",156)
			flag = i;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",157)
			if (((this->data->id->__get(i) == id))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",157)
				break;
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",157)
				HX_CSTRING("");
			}
		}
	}
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",159)
	::com::mybo::framework::resource::AssetObject obj = ::com::mybo::framework::resource::AssetObject_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",160)
	obj->tileWidth = this->data->tileWidth->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",161)
	obj->tileHeight = this->data->tileHeight->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",162)
	obj->cols = this->data->cols->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",163)
	obj->frameNumber = this->data->frameNumber->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",164)
	obj->id = this->data->id->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",165)
	obj->folder = this->data->folder->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",166)
	obj->optimized = this->data->optimized->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",167)
	obj->scale = this->data->scale->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",168)
	obj->url = this->data->url->__get(flag);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",169)
	return obj;
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,getAssetObject,return )

Void Resource_obj::unLoadAllByFolder( ::String folder){
{
		HX_SOURCE_PUSH("Resource_obj::unLoadAllByFolder")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",173)
		int _g1 = (int)0;
		int _g = this->data->id->length;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",173)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",173)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",174)
			if (((this->data->folder->__get(i) == folder))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",175)
				this->destroyResource(this->data->id->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,unLoadAllByFolder,(void))

Void Resource_obj::loadAllByFolder( ::String folder){
{
		HX_SOURCE_PUSH("Resource_obj::loadAllByFolder")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",180)
		int _g1 = (int)0;
		int _g = this->data->id->length;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",180)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",180)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",181)
			if (((this->data->folder->__get(i) == folder))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",182)
				this->loadBitmap(this->data->id->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,loadAllByFolder,(void))

Void Resource_obj::destroyResource( ::String id){
{
		HX_SOURCE_PUSH("Resource_obj::destroyResource")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",186)
		if ((this->bitmapTileHash->exists(id))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",188)
			this->bitmapTileHash->get(id)->__Field(HX_CSTRING("bitmapData"))->__Field(HX_CSTRING("destroyHardwareSurface"))();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",189)
			this->bitmapTileHash->get(id)->__Field(HX_CSTRING("bitmapData"))->__Field(HX_CSTRING("dispose"))();
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",190)
			this->bitmapTileHash->remove(id);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,destroyResource,(void))

Void Resource_obj::unLoadAll( ){
{
		HX_SOURCE_PUSH("Resource_obj::unLoadAll")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",194)
		int _g1 = (int)0;
		int _g = this->data->id->length;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",194)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",194)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/resource/Resource.hx",195)
			this->destroyResource(this->data->id->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,unLoadAll,(void))


Resource_obj::Resource_obj()
{
}

void Resource_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Resource);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(rootPath,"rootPath");
	HX_MARK_MEMBER_NAME(sparePath,"sparePath");
	HX_MARK_MEMBER_NAME(bitmapTileHash,"bitmapTileHash");
	HX_MARK_MEMBER_NAME(a1,"a1");
	HX_MARK_MEMBER_NAME(a2,"a2");
	HX_MARK_MEMBER_NAME(a3,"a3");
	HX_MARK_END_CLASS();
}

Dynamic Resource_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"a1") ) { return a1; }
		if (HX_FIELD_EQ(inName,"a2") ) { return a2; }
		if (HX_FIELD_EQ(inName,"a3") ) { return a3; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"loadAll") ) { return loadAll_dyn(); }
		if (HX_FIELD_EQ(inName,"getTile") ) { return getTile_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rootPath") ) { return rootPath; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sparePath") ) { return sparePath; }
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"unLoadAll") ) { return unLoadAll_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mergeAlpha") ) { return mergeAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"loadBitmap") ) { return loadBitmap_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bitmapTileHash") ) { return bitmapTileHash; }
		if (HX_FIELD_EQ(inName,"getAssetObject") ) { return getAssetObject_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"loadAllByFolder") ) { return loadAllByFolder_dyn(); }
		if (HX_FIELD_EQ(inName,"destroyResource") ) { return destroyResource_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"unLoadAllByFolder") ) { return unLoadAllByFolder_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Resource_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"a1") ) { a1=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a2") ) { a2=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a3") ) { a3=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::com::mybo::framework::resource::ResourceData >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rootPath") ) { rootPath=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sparePath") ) { sparePath=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bitmapTileHash") ) { bitmapTileHash=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Resource_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("rootPath"));
	outFields->push(HX_CSTRING("sparePath"));
	outFields->push(HX_CSTRING("bitmapTileHash"));
	outFields->push(HX_CSTRING("a1"));
	outFields->push(HX_CSTRING("a2"));
	outFields->push(HX_CSTRING("a3"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("rootPath"),
	HX_CSTRING("sparePath"),
	HX_CSTRING("bitmapTileHash"),
	HX_CSTRING("loadAll"),
	HX_CSTRING("getBitmap"),
	HX_CSTRING("mergeAlpha"),
	HX_CSTRING("getTile"),
	HX_CSTRING("a1"),
	HX_CSTRING("a2"),
	HX_CSTRING("a3"),
	HX_CSTRING("loadBitmap"),
	HX_CSTRING("getAssetObject"),
	HX_CSTRING("unLoadAllByFolder"),
	HX_CSTRING("loadAllByFolder"),
	HX_CSTRING("destroyResource"),
	HX_CSTRING("unLoadAll"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Resource_obj::__mClass;

void Resource_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.resource.Resource"), hx::TCanCast< Resource_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Resource_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource
