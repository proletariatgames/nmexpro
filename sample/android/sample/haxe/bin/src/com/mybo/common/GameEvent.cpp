#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
namespace com{
namespace mybo{
namespace common{

Void GameEvent_obj::__construct(::String type,Array< int > inData)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/common/GameEvent.hx",19)
	super::__construct(type,null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/common/GameEvent.hx",20)
	this->data = inData;
}
;
	return null();
}

GameEvent_obj::~GameEvent_obj() { }

Dynamic GameEvent_obj::__CreateEmpty() { return  new GameEvent_obj; }
hx::ObjectPtr< GameEvent_obj > GameEvent_obj::__new(::String type,Array< int > inData)
{  hx::ObjectPtr< GameEvent_obj > result = new GameEvent_obj();
	result->__construct(type,inData);
	return result;}

Dynamic GameEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameEvent_obj > result = new GameEvent_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String GameEvent_obj::BUBBLE_BLAST;

::String GameEvent_obj::BUBBLE_INITED;

::String GameEvent_obj::BUBBLE_TAP_COMPLETED;

::String GameEvent_obj::LEVEL_COMPLETE;

::String GameEvent_obj::BUBBLE_TOUCHED;

::String GameEvent_obj::LEVEL_SELECTED;

::String GameEvent_obj::PACK_SELECTED;


GameEvent_obj::GameEvent_obj()
{
}

void GameEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameEvent);
	HX_MARK_MEMBER_NAME(data,"data");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic GameEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BUBBLE_BLAST") ) { return BUBBLE_BLAST; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"BUBBLE_INITED") ) { return BUBBLE_INITED; }
		if (HX_FIELD_EQ(inName,"PACK_SELECTED") ) { return PACK_SELECTED; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"LEVEL_COMPLETE") ) { return LEVEL_COMPLETE; }
		if (HX_FIELD_EQ(inName,"BUBBLE_TOUCHED") ) { return BUBBLE_TOUCHED; }
		if (HX_FIELD_EQ(inName,"LEVEL_SELECTED") ) { return LEVEL_SELECTED; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"BUBBLE_TAP_COMPLETED") ) { return BUBBLE_TAP_COMPLETED; }
	}
	return super::__Field(inName);
}

Dynamic GameEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"BUBBLE_BLAST") ) { BUBBLE_BLAST=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"BUBBLE_INITED") ) { BUBBLE_INITED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PACK_SELECTED") ) { PACK_SELECTED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"LEVEL_COMPLETE") ) { LEVEL_COMPLETE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BUBBLE_TOUCHED") ) { BUBBLE_TOUCHED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LEVEL_SELECTED") ) { LEVEL_SELECTED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"BUBBLE_TAP_COMPLETED") ) { BUBBLE_TAP_COMPLETED=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("BUBBLE_BLAST"),
	HX_CSTRING("BUBBLE_INITED"),
	HX_CSTRING("BUBBLE_TAP_COMPLETED"),
	HX_CSTRING("LEVEL_COMPLETE"),
	HX_CSTRING("BUBBLE_TOUCHED"),
	HX_CSTRING("LEVEL_SELECTED"),
	HX_CSTRING("PACK_SELECTED"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameEvent_obj::BUBBLE_BLAST,"BUBBLE_BLAST");
	HX_MARK_MEMBER_NAME(GameEvent_obj::BUBBLE_INITED,"BUBBLE_INITED");
	HX_MARK_MEMBER_NAME(GameEvent_obj::BUBBLE_TAP_COMPLETED,"BUBBLE_TAP_COMPLETED");
	HX_MARK_MEMBER_NAME(GameEvent_obj::LEVEL_COMPLETE,"LEVEL_COMPLETE");
	HX_MARK_MEMBER_NAME(GameEvent_obj::BUBBLE_TOUCHED,"BUBBLE_TOUCHED");
	HX_MARK_MEMBER_NAME(GameEvent_obj::LEVEL_SELECTED,"LEVEL_SELECTED");
	HX_MARK_MEMBER_NAME(GameEvent_obj::PACK_SELECTED,"PACK_SELECTED");
};

Class GameEvent_obj::__mClass;

void GameEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.GameEvent"), hx::TCanCast< GameEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameEvent_obj::__boot()
{
	hx::Static(BUBBLE_BLAST) = HX_CSTRING("bubbleBlast");
	hx::Static(BUBBLE_INITED) = HX_CSTRING("bubbleInited");
	hx::Static(BUBBLE_TAP_COMPLETED) = HX_CSTRING("bubbleTapCompleted");
	hx::Static(LEVEL_COMPLETE) = HX_CSTRING("levelComplete");
	hx::Static(BUBBLE_TOUCHED) = HX_CSTRING("bubbleTouched");
	hx::Static(LEVEL_SELECTED) = HX_CSTRING("levelSelected");
	hx::Static(PACK_SELECTED) = HX_CSTRING("packSelected");
}

} // end namespace com
} // end namespace mybo
} // end namespace common
