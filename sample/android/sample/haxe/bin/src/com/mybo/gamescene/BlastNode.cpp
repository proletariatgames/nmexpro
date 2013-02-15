#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_gamescene_BlastNode
#include <com/mybo/gamescene/BlastNode.h>
#endif
namespace com{
namespace mybo{
namespace gamescene{

Void BlastNode_obj::__construct(int inDir,double inX,double inY)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",583)
	this->dir = inDir;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",584)
	this->x = inX;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",585)
	this->y = inY;
}
;
	return null();
}

BlastNode_obj::~BlastNode_obj() { }

Dynamic BlastNode_obj::__CreateEmpty() { return  new BlastNode_obj; }
hx::ObjectPtr< BlastNode_obj > BlastNode_obj::__new(int inDir,double inX,double inY)
{  hx::ObjectPtr< BlastNode_obj > result = new BlastNode_obj();
	result->__construct(inDir,inX,inY);
	return result;}

Dynamic BlastNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlastNode_obj > result = new BlastNode_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


BlastNode_obj::BlastNode_obj()
{
}

void BlastNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlastNode);
	HX_MARK_MEMBER_NAME(dir,"dir");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_END_CLASS();
}

Dynamic BlastNode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { return dir; }
	}
	return super::__Field(inName);
}

Dynamic BlastNode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"dir") ) { dir=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BlastNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("dir"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dir"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BlastNode_obj::__mClass;

void BlastNode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.BlastNode"), hx::TCanCast< BlastNode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BlastNode_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
