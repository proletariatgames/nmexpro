#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapNumber
#include <com/mybo/framework/display/BitmapNumber.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace display{

Void BitmapNumber_obj::__construct(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_smooth)
{
bool smooth = __o_smooth.Default(true);
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",17)
	super::__construct(tile,false,false,smooth);
	HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",18)
	this->tileWidth = (tile->width - ((int)2 * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
}
;
	return null();
}

BitmapNumber_obj::~BitmapNumber_obj() { }

Dynamic BitmapNumber_obj::__CreateEmpty() { return  new BitmapNumber_obj; }
hx::ObjectPtr< BitmapNumber_obj > BitmapNumber_obj::__new(::com::mybo::framework::resource::BitmapTile tile,Dynamic __o_smooth)
{  hx::ObjectPtr< BitmapNumber_obj > result = new BitmapNumber_obj();
	result->__construct(tile,__o_smooth);
	return result;}

Dynamic BitmapNumber_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapNumber_obj > result = new BitmapNumber_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void BitmapNumber_obj::drawNumber( int num){
{
		HX_SOURCE_PUSH("BitmapNumber_obj::drawNumber")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",21)
		this->clear();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",22)
		this->value = num;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",23)
		Array< int > arr = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",24)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",24)
			int _g = (int)0;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",24)
			while(((_g < (int)8))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",24)
				int i = (_g)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",25)
				arr->unshift(::Std_obj::_int((double(((hx::Mod(num,::Math_obj::pow((int)10,(i + (int)1))) - hx::Mod(num,::Math_obj::pow((int)10,i))))) / double(::Math_obj::pow((int)10,i)))));
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",26)
				if (((num < ::Math_obj::pow((int)10,(i + (int)1))))){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",26)
					break;
				}
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",30)
		::nme::geom::Matrix matrix;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",31)
		::nme::display::BitmapData bd = this->tile->bitmapData;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",32)
		double h = (double(this->tile->height) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",33)
		double w = ((double(this->tile->width) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor)) - (int)1);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",34)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",34)
			int _g1 = (int)0;
			int _g = arr->length;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",34)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",34)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",35)
				matrix = ::nme::geom::Matrix_obj::__new((int)1,(int)0,(int)0,(int)1,((((i * w) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor) - (arr->__get(i) * this->tile->width)) - ::com::mybo::framework::core::Facade_obj::contentScaleFactor),(int)0);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",37)
				this->nmeGetGraphics()->beginBitmapFill(bd,matrix,false,true);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",38)
				this->nmeGetGraphics()->drawRect((i * w),(int)0,w,h);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",39)
				this->nmeGetGraphics()->endFill();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapNumber_obj,drawNumber,(void))

Void BitmapNumber_obj::drawNumberByString( ::String num){
{
		HX_SOURCE_PUSH("BitmapNumber_obj::drawNumberByString")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",49)
		this->clear();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",50)
		this->value = ::Std_obj::parseInt(num);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",51)
		Array< int > arr = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",52)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",52)
			int _g1 = (int)0;
			int _g = num.length;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",52)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",52)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",53)
				arr->push(::Std_obj::parseInt(num.charAt(i)));
			}
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",55)
		{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",55)
			int _g1 = (int)0;
			int _g = arr->length;
			HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",55)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",55)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/display/BitmapNumber.hx",56)
				this->drawTile(arr->__get(i),(double((i * this->tileWidth)) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor)),0.0,false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapNumber_obj,drawNumberByString,(void))


BitmapNumber_obj::BitmapNumber_obj()
{
}

void BitmapNumber_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapNumber);
	HX_MARK_MEMBER_NAME(tileWidth,"tileWidth");
	HX_MARK_MEMBER_NAME(value,"value");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BitmapNumber_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { return tileWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawNumber") ) { return drawNumber_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"drawNumberByString") ) { return drawNumberByString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BitmapNumber_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { tileWidth=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapNumber_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tileWidth"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("tileWidth"),
	HX_CSTRING("value"),
	HX_CSTRING("drawNumber"),
	HX_CSTRING("drawNumberByString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BitmapNumber_obj::__mClass;

void BitmapNumber_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.display.BitmapNumber"), hx::TCanCast< BitmapNumber_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapNumber_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace display
