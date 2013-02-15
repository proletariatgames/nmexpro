#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_effects_BubbleCell
#include <com/mybo/effects/BubbleCell.h>
#endif
namespace com{
namespace mybo{
namespace effects{

Void BubbleCell_obj::__construct(double xx,double yy,double scale,double a,double vx,double vy)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",175)
	this->xx = xx;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",176)
	this->yy = yy;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",177)
	this->scale = scale;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",178)
	this->a = a;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",179)
	this->vx = vx;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",180)
	this->vy = vy;
}
;
	return null();
}

BubbleCell_obj::~BubbleCell_obj() { }

Dynamic BubbleCell_obj::__CreateEmpty() { return  new BubbleCell_obj; }
hx::ObjectPtr< BubbleCell_obj > BubbleCell_obj::__new(double xx,double yy,double scale,double a,double vx,double vy)
{  hx::ObjectPtr< BubbleCell_obj > result = new BubbleCell_obj();
	result->__construct(xx,yy,scale,a,vx,vy);
	return result;}

Dynamic BubbleCell_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BubbleCell_obj > result = new BubbleCell_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}


BubbleCell_obj::BubbleCell_obj()
{
}

void BubbleCell_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BubbleCell);
	HX_MARK_MEMBER_NAME(xx,"xx");
	HX_MARK_MEMBER_NAME(yy,"yy");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(vx,"vx");
	HX_MARK_MEMBER_NAME(vy,"vy");
	HX_MARK_END_CLASS();
}

Dynamic BubbleCell_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"xx") ) { return xx; }
		if (HX_FIELD_EQ(inName,"yy") ) { return yy; }
		if (HX_FIELD_EQ(inName,"vx") ) { return vx; }
		if (HX_FIELD_EQ(inName,"vy") ) { return vy; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
	}
	return super::__Field(inName);
}

Dynamic BubbleCell_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"xx") ) { xx=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yy") ) { yy=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vx") ) { vx=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vy") ) { vy=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BubbleCell_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("xx"));
	outFields->push(HX_CSTRING("yy"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("vx"));
	outFields->push(HX_CSTRING("vy"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("xx"),
	HX_CSTRING("yy"),
	HX_CSTRING("scale"),
	HX_CSTRING("a"),
	HX_CSTRING("vx"),
	HX_CSTRING("vy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BubbleCell_obj::__mClass;

void BubbleCell_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.effects.BubbleCell"), hx::TCanCast< BubbleCell_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BubbleCell_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace effects
