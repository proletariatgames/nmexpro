#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nmex_NXEvent
#include <nmex/NXEvent.h>
#endif
namespace nmex{

Void NXEvent_obj::__construct(::String type,int code,int value,::String data)
{
{
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/NXEvent.hx",34)
	super::__construct(type,null(),null());
}
;
	return null();
}

NXEvent_obj::~NXEvent_obj() { }

Dynamic NXEvent_obj::__CreateEmpty() { return  new NXEvent_obj; }
hx::ObjectPtr< NXEvent_obj > NXEvent_obj::__new(::String type,int code,int value,::String data)
{  hx::ObjectPtr< NXEvent_obj > result = new NXEvent_obj();
	result->__construct(type,code,value,data);
	return result;}

Dynamic NXEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NXEvent_obj > result = new NXEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::String NXEvent_obj::UN_KNOWN_EVENT;

::String NXEvent_obj::IN_APP_PURCHASE_SUCCESS;

::String NXEvent_obj::IN_APP_PURCHASE_FAIL;

::String NXEvent_obj::IN_APP_PURCHASE_CANCEL;

::String NXEvent_obj::AUTH_SUCCEEDED;

::String NXEvent_obj::AUTH_FAILED;

::String NXEvent_obj::LEADERBOARD_VIEW_OPENED;

::String NXEvent_obj::LEADERBOARD_VIEW_CLOSED;

::String NXEvent_obj::ACHIEVEMENTS_VIEW_OPENED;

::String NXEvent_obj::ACHIEVEMENTS_VIEW_CLOSED;

::String NXEvent_obj::SCORE_REPORT_SUCCEEDED;

::String NXEvent_obj::SCORE_REPORT_FAILED;

::String NXEvent_obj::ACHIEVEMENT_REPORT_SUCCEEDED;

::String NXEvent_obj::ACHIEVEMENT_REPORT_FAILED;

::String NXEvent_obj::ACHIEVEMENT_RESET_SUCCEEDED;

::String NXEvent_obj::ACHIEVEMENT_RESET_FAILED;


NXEvent_obj::NXEvent_obj()
{
}

void NXEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NXEvent);
	HX_MARK_MEMBER_NAME(EventID,"EventID");
	HX_MARK_MEMBER_NAME(code,"code");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(data,"data");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic NXEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"code") ) { return code; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EventID") ) { return EventID; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"AUTH_FAILED") ) { return AUTH_FAILED; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UN_KNOWN_EVENT") ) { return UN_KNOWN_EVENT; }
		if (HX_FIELD_EQ(inName,"AUTH_SUCCEEDED") ) { return AUTH_SUCCEEDED; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"SCORE_REPORT_FAILED") ) { return SCORE_REPORT_FAILED; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"IN_APP_PURCHASE_FAIL") ) { return IN_APP_PURCHASE_FAIL; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"IN_APP_PURCHASE_CANCEL") ) { return IN_APP_PURCHASE_CANCEL; }
		if (HX_FIELD_EQ(inName,"SCORE_REPORT_SUCCEEDED") ) { return SCORE_REPORT_SUCCEEDED; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"IN_APP_PURCHASE_SUCCESS") ) { return IN_APP_PURCHASE_SUCCESS; }
		if (HX_FIELD_EQ(inName,"LEADERBOARD_VIEW_OPENED") ) { return LEADERBOARD_VIEW_OPENED; }
		if (HX_FIELD_EQ(inName,"LEADERBOARD_VIEW_CLOSED") ) { return LEADERBOARD_VIEW_CLOSED; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENTS_VIEW_OPENED") ) { return ACHIEVEMENTS_VIEW_OPENED; }
		if (HX_FIELD_EQ(inName,"ACHIEVEMENTS_VIEW_CLOSED") ) { return ACHIEVEMENTS_VIEW_CLOSED; }
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_RESET_FAILED") ) { return ACHIEVEMENT_RESET_FAILED; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_REPORT_FAILED") ) { return ACHIEVEMENT_REPORT_FAILED; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_RESET_SUCCEEDED") ) { return ACHIEVEMENT_RESET_SUCCEEDED; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_REPORT_SUCCEEDED") ) { return ACHIEVEMENT_REPORT_SUCCEEDED; }
	}
	return super::__Field(inName);
}

Dynamic NXEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"code") ) { code=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EventID") ) { EventID=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"AUTH_FAILED") ) { AUTH_FAILED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UN_KNOWN_EVENT") ) { UN_KNOWN_EVENT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"AUTH_SUCCEEDED") ) { AUTH_SUCCEEDED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"SCORE_REPORT_FAILED") ) { SCORE_REPORT_FAILED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"IN_APP_PURCHASE_FAIL") ) { IN_APP_PURCHASE_FAIL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"IN_APP_PURCHASE_CANCEL") ) { IN_APP_PURCHASE_CANCEL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SCORE_REPORT_SUCCEEDED") ) { SCORE_REPORT_SUCCEEDED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"IN_APP_PURCHASE_SUCCESS") ) { IN_APP_PURCHASE_SUCCESS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LEADERBOARD_VIEW_OPENED") ) { LEADERBOARD_VIEW_OPENED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LEADERBOARD_VIEW_CLOSED") ) { LEADERBOARD_VIEW_CLOSED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENTS_VIEW_OPENED") ) { ACHIEVEMENTS_VIEW_OPENED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ACHIEVEMENTS_VIEW_CLOSED") ) { ACHIEVEMENTS_VIEW_CLOSED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_RESET_FAILED") ) { ACHIEVEMENT_RESET_FAILED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_REPORT_FAILED") ) { ACHIEVEMENT_REPORT_FAILED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_RESET_SUCCEEDED") ) { ACHIEVEMENT_RESET_SUCCEEDED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"ACHIEVEMENT_REPORT_SUCCEEDED") ) { ACHIEVEMENT_REPORT_SUCCEEDED=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NXEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("EventID"));
	outFields->push(HX_CSTRING("code"));
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UN_KNOWN_EVENT"),
	HX_CSTRING("IN_APP_PURCHASE_SUCCESS"),
	HX_CSTRING("IN_APP_PURCHASE_FAIL"),
	HX_CSTRING("IN_APP_PURCHASE_CANCEL"),
	HX_CSTRING("AUTH_SUCCEEDED"),
	HX_CSTRING("AUTH_FAILED"),
	HX_CSTRING("LEADERBOARD_VIEW_OPENED"),
	HX_CSTRING("LEADERBOARD_VIEW_CLOSED"),
	HX_CSTRING("ACHIEVEMENTS_VIEW_OPENED"),
	HX_CSTRING("ACHIEVEMENTS_VIEW_CLOSED"),
	HX_CSTRING("SCORE_REPORT_SUCCEEDED"),
	HX_CSTRING("SCORE_REPORT_FAILED"),
	HX_CSTRING("ACHIEVEMENT_REPORT_SUCCEEDED"),
	HX_CSTRING("ACHIEVEMENT_REPORT_FAILED"),
	HX_CSTRING("ACHIEVEMENT_RESET_SUCCEEDED"),
	HX_CSTRING("ACHIEVEMENT_RESET_FAILED"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("EventID"),
	HX_CSTRING("code"),
	HX_CSTRING("value"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NXEvent_obj::UN_KNOWN_EVENT,"UN_KNOWN_EVENT");
	HX_MARK_MEMBER_NAME(NXEvent_obj::IN_APP_PURCHASE_SUCCESS,"IN_APP_PURCHASE_SUCCESS");
	HX_MARK_MEMBER_NAME(NXEvent_obj::IN_APP_PURCHASE_FAIL,"IN_APP_PURCHASE_FAIL");
	HX_MARK_MEMBER_NAME(NXEvent_obj::IN_APP_PURCHASE_CANCEL,"IN_APP_PURCHASE_CANCEL");
	HX_MARK_MEMBER_NAME(NXEvent_obj::AUTH_SUCCEEDED,"AUTH_SUCCEEDED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::AUTH_FAILED,"AUTH_FAILED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::LEADERBOARD_VIEW_OPENED,"LEADERBOARD_VIEW_OPENED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::LEADERBOARD_VIEW_CLOSED,"LEADERBOARD_VIEW_CLOSED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::ACHIEVEMENTS_VIEW_OPENED,"ACHIEVEMENTS_VIEW_OPENED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::ACHIEVEMENTS_VIEW_CLOSED,"ACHIEVEMENTS_VIEW_CLOSED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::SCORE_REPORT_SUCCEEDED,"SCORE_REPORT_SUCCEEDED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::SCORE_REPORT_FAILED,"SCORE_REPORT_FAILED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::ACHIEVEMENT_REPORT_SUCCEEDED,"ACHIEVEMENT_REPORT_SUCCEEDED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::ACHIEVEMENT_REPORT_FAILED,"ACHIEVEMENT_REPORT_FAILED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::ACHIEVEMENT_RESET_SUCCEEDED,"ACHIEVEMENT_RESET_SUCCEEDED");
	HX_MARK_MEMBER_NAME(NXEvent_obj::ACHIEVEMENT_RESET_FAILED,"ACHIEVEMENT_RESET_FAILED");
};

Class NXEvent_obj::__mClass;

void NXEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.NXEvent"), hx::TCanCast< NXEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NXEvent_obj::__boot()
{
	hx::Static(UN_KNOWN_EVENT) = HX_CSTRING("unKnownEvent");
	hx::Static(IN_APP_PURCHASE_SUCCESS) = HX_CSTRING("inAppPurchaseSuccess");
	hx::Static(IN_APP_PURCHASE_FAIL) = HX_CSTRING("inAppPurchaseFail");
	hx::Static(IN_APP_PURCHASE_CANCEL) = HX_CSTRING("inAppPurchaseCancel");
	hx::Static(AUTH_SUCCEEDED) = HX_CSTRING("authSucceeded");
	hx::Static(AUTH_FAILED) = HX_CSTRING("authFailed");
	hx::Static(LEADERBOARD_VIEW_OPENED) = HX_CSTRING("leaderboardViewOpened");
	hx::Static(LEADERBOARD_VIEW_CLOSED) = HX_CSTRING("leaderboardViewClosed");
	hx::Static(ACHIEVEMENTS_VIEW_OPENED) = HX_CSTRING("achievementsViewOpened");
	hx::Static(ACHIEVEMENTS_VIEW_CLOSED) = HX_CSTRING("achievementsViewClosed");
	hx::Static(SCORE_REPORT_SUCCEEDED) = HX_CSTRING("scoreReportSucceeded");
	hx::Static(SCORE_REPORT_FAILED) = HX_CSTRING("scoreReportFailed");
	hx::Static(ACHIEVEMENT_REPORT_SUCCEEDED) = HX_CSTRING("achievementReportSucceeded");
	hx::Static(ACHIEVEMENT_REPORT_FAILED) = HX_CSTRING("achievementReportFailed");
	hx::Static(ACHIEVEMENT_RESET_SUCCEEDED) = HX_CSTRING("achievementResetSucceeded");
	hx::Static(ACHIEVEMENT_RESET_FAILED) = HX_CSTRING("achievementResetFailed");
}

} // end namespace nmex
