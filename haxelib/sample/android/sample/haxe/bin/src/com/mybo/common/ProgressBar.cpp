#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_ProgressBar
#include <com/mybo/common/ProgressBar.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
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
#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
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
namespace common{

Void ProgressBar_obj::__construct(::nme::display::BitmapData bitmapData)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",23)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",25)
	this->texture = bitmapData;
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",27)
	this->maxWidth = this->texture->nmeGetWidth();
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",28)
	this->maxHeight = this->texture->nmeGetHeight();
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",30)
	this->targetWidth = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",31)
	this->barWidth = (int)0;
}
;
	return null();
}

ProgressBar_obj::~ProgressBar_obj() { }

Dynamic ProgressBar_obj::__CreateEmpty() { return  new ProgressBar_obj; }
hx::ObjectPtr< ProgressBar_obj > ProgressBar_obj::__new(::nme::display::BitmapData bitmapData)
{  hx::ObjectPtr< ProgressBar_obj > result = new ProgressBar_obj();
	result->__construct(bitmapData);
	return result;}

Dynamic ProgressBar_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ProgressBar_obj > result = new ProgressBar_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ProgressBar_obj::update( double percent){
{
		HX_SOURCE_PUSH("ProgressBar_obj::update")
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",36)
		if (((percent > (int)1))){
			HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",36)
			percent = (int)1;
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",38)
		if (((this->mtween != null()))){
			HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",38)
			this->mtween->stop();
		}
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",42)
		if (((percent == (int)1))){
			HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",42)
			this->targetWidth = this->maxWidth;
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",44)
			this->targetWidth = ::Std_obj::_int((this->maxWidth * percent));
		}
		struct _Function_1_1{
			inline static Dynamic Block( ::com::mybo::common::ProgressBar_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("barWidth") , __this->targetWidth,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ::com::mybo::common::ProgressBar_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("onUpdate") , __this->onUpdate_dyn(),false);
				__result->Add(HX_CSTRING("onComplete") , __this->onComplete_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",47)
		this->mtween = ::com::mybo::framework::tweener::MTween_obj::to(hx::ObjectPtr<OBJ_>(this),0.3,_Function_1_1::Block(this),_Function_1_2::Block(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ProgressBar_obj,update,(void))

double ProgressBar_obj::getMaxWidthInPoint( ){
	HX_SOURCE_PUSH("ProgressBar_obj::getMaxWidthInPoint")
	HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",51)
	return (double(this->maxWidth) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
}


HX_DEFINE_DYNAMIC_FUNC0(ProgressBar_obj,getMaxWidthInPoint,return )

Void ProgressBar_obj::onComplete( ){
{
		HX_SOURCE_PUSH("ProgressBar_obj::onComplete")
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",55)
		this->mtween = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ProgressBar_obj,onComplete,(void))

Void ProgressBar_obj::onUpdate( double percent){
{
		HX_SOURCE_PUSH("ProgressBar_obj::onUpdate")
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",60)
		this->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",61)
		double width = this->barWidth;
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",64)
		double vx = (double(width) / double((int)2));
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",65)
		double vy = this->maxHeight;
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",66)
		Array< double > vertices = Array_obj< double >::__new().Add((int)0).Add((int)0).Add(vx).Add((int)0).Add(vx).Add(vy).Add((int)0).Add(vy);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",67)
		double ux = (double((double(width) / double((int)2))) / double(this->maxWidth));
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",68)
		Array< double > uvdatas = Array_obj< double >::__new().Add((int)0).Add((int)0).Add(ux).Add((int)0).Add(ux).Add((int)1).Add((int)0).Add((int)1);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",70)
		Array< int > indices = Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",72)
		this->nmeGetGraphics()->beginBitmapFill(this->texture,null(),false,true);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",73)
		this->nmeGetGraphics()->drawTriangles(vertices,indices,uvdatas,null(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",75)
		double vx1 = (double(width) / double((int)2));
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",76)
		Array< double > vertices1 = Array_obj< double >::__new().Add(vx1).Add((int)0).Add(width).Add((int)0).Add(width).Add(vy).Add(vx1).Add(vy);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",78)
		double ux2 = ((int)1 - ux);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",79)
		Array< double > uvdatas1 = Array_obj< double >::__new().Add(ux2).Add((int)0).Add((int)1).Add((int)0).Add((int)1).Add((int)1).Add(ux2).Add((int)1);
		HX_SOURCE_POS("../../../src/com/mybo/common/ProgressBar.hx",81)
		this->nmeGetGraphics()->drawTriangles(vertices1,indices,uvdatas1,null(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ProgressBar_obj,onUpdate,(void))


ProgressBar_obj::ProgressBar_obj()
{
}

void ProgressBar_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ProgressBar);
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(mtween,"mtween");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(maxHeight,"maxHeight");
	HX_MARK_MEMBER_NAME(targetWidth,"targetWidth");
	HX_MARK_MEMBER_NAME(barWidth,"barWidth");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ProgressBar_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"mtween") ) { return mtween; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return maxWidth; }
		if (HX_FIELD_EQ(inName,"barWidth") ) { return barWidth; }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return maxHeight; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"targetWidth") ) { return targetWidth; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getMaxWidthInPoint") ) { return getMaxWidthInPoint_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ProgressBar_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"mtween") ) { mtween=inValue.Cast< ::com::mybo::framework::tweener::MTween >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxWidth") ) { maxWidth=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"barWidth") ) { barWidth=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxHeight") ) { maxHeight=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"targetWidth") ) { targetWidth=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ProgressBar_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("texture"));
	outFields->push(HX_CSTRING("mtween"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("maxHeight"));
	outFields->push(HX_CSTRING("targetWidth"));
	outFields->push(HX_CSTRING("barWidth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("texture"),
	HX_CSTRING("mtween"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("maxHeight"),
	HX_CSTRING("targetWidth"),
	HX_CSTRING("barWidth"),
	HX_CSTRING("update"),
	HX_CSTRING("getMaxWidthInPoint"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("onUpdate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ProgressBar_obj::__mClass;

void ProgressBar_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.ProgressBar"), hx::TCanCast< ProgressBar_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ProgressBar_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace common
