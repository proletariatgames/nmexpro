#include <hxcpp.h>

#ifndef INCLUDED_nme_JNI
#include <nme/JNI.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nmex_GameCenter
#include <nmex/GameCenter.h>
#endif
#ifndef INCLUDED_nmex_NXObject
#include <nmex/NXObject.h>
#endif
namespace nmex{

Void GameCenter_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",9)
	super::__construct();
}
;
	return null();
}

GameCenter_obj::~GameCenter_obj() { }

Dynamic GameCenter_obj::__CreateEmpty() { return  new GameCenter_obj; }
hx::ObjectPtr< GameCenter_obj > GameCenter_obj::__new()
{  hx::ObjectPtr< GameCenter_obj > result = new GameCenter_obj();
	result->__construct();
	return result;}

Dynamic GameCenter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameCenter_obj > result = new GameCenter_obj();
	result->__construct();
	return result;}

Void GameCenter_obj::authenticateLocalUser( ){
{
		HX_SOURCE_PUSH("GameCenter_obj::authenticateLocalUser")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameCenter_obj,authenticateLocalUser,(void))

Void GameCenter_obj::showAchievements( ){
{
		HX_SOURCE_PUSH("GameCenter_obj::showAchievements")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",27)
		if (((::nmex::GameCenter_obj::_showAchievements_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",28)
			::nmex::GameCenter_obj::_showAchievements_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("showAchievements"),HX_CSTRING("()V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",29)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",30)
		::nmex::GameCenter_obj::_showAchievements_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameCenter_obj,showAchievements,(void))

Void GameCenter_obj::showLeaderboardForCategory( ::String category){
{
		HX_SOURCE_PUSH("GameCenter_obj::showLeaderboardForCategory")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",35)
		if (((::nmex::GameCenter_obj::_showLeaderboardForCategory_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",36)
			::nmex::GameCenter_obj::_showLeaderboardForCategory_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("showLeaderboardForCategory"),HX_CSTRING("(Ljava/lang/String;)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",37)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",38)
		a->__Field(HX_CSTRING("push"))(category);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",39)
		::nmex::GameCenter_obj::_showLeaderboardForCategory_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameCenter_obj,showLeaderboardForCategory,(void))

Void GameCenter_obj::reportScoreForCategory( int score,::String category){
{
		HX_SOURCE_PUSH("GameCenter_obj::reportScoreForCategory")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",44)
		if (((::nmex::GameCenter_obj::_reportScoreForCategory_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",45)
			::nmex::GameCenter_obj::_reportScoreForCategory_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("reportScoreForCategory"),HX_CSTRING("(ILjava/lang/String;)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",46)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",47)
		a->__Field(HX_CSTRING("push"))(score);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",48)
		a->__Field(HX_CSTRING("push"))(category);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",49)
		::nmex::GameCenter_obj::_reportScoreForCategory_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameCenter_obj,reportScoreForCategory,(void))

Void GameCenter_obj::reportAchievement( ::String achievementId){
{
		HX_SOURCE_PUSH("GameCenter_obj::reportAchievement")
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",55)
		if (((::nmex::GameCenter_obj::_reportAchievement_func == null()))){
			HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",56)
			::nmex::GameCenter_obj::_reportAchievement_func = ::nme::JNI_obj::createStaticMethod(HX_CSTRING("org.haxe.nme.GameActivity"),HX_CSTRING("reportAchievement"),HX_CSTRING("(Ljava/lang/String;)V"),true);
		}
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",57)
		Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",58)
		a->__Field(HX_CSTRING("push"))(achievementId);
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",59)
		::nmex::GameCenter_obj::_reportAchievement_func(a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameCenter_obj,reportAchievement,(void))

Void GameCenter_obj::resetAchievements( ){
{
		HX_SOURCE_PUSH("GameCenter_obj::resetAchievements")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameCenter_obj,resetAchievements,(void))

::nmex::GameCenter GameCenter_obj::instance;

::nmex::GameCenter GameCenter_obj::getInstance( ){
	HX_SOURCE_PUSH("GameCenter_obj::getInstance")
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",14)
	if (((::nmex::GameCenter_obj::instance == null()))){
		HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",14)
		::nmex::GameCenter_obj::instance = ::nmex::GameCenter_obj::__new();
	}
	HX_SOURCE_POS("/Users/yann/works/nmex/trunk/nmex/GameCenter.hx",18)
	return ::nmex::GameCenter_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GameCenter_obj,getInstance,return )

Dynamic GameCenter_obj::_showAchievements_func;

Dynamic GameCenter_obj::_showLeaderboardForCategory_func;

Dynamic GameCenter_obj::_reportScoreForCategory_func;

Dynamic GameCenter_obj::_reportAchievement_func;


GameCenter_obj::GameCenter_obj()
{
}

void GameCenter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameCenter);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic GameCenter_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"showAchievements") ) { return showAchievements_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"reportAchievement") ) { return reportAchievement_dyn(); }
		if (HX_FIELD_EQ(inName,"resetAchievements") ) { return resetAchievements_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"authenticateLocalUser") ) { return authenticateLocalUser_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_showAchievements_func") ) { return _showAchievements_func; }
		if (HX_FIELD_EQ(inName,"reportScoreForCategory") ) { return reportScoreForCategory_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_reportAchievement_func") ) { return _reportAchievement_func; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"showLeaderboardForCategory") ) { return showLeaderboardForCategory_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_reportScoreForCategory_func") ) { return _reportScoreForCategory_func; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"_showLeaderboardForCategory_func") ) { return _showLeaderboardForCategory_func; }
	}
	return super::__Field(inName);
}

Dynamic GameCenter_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::nmex::GameCenter >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_showAchievements_func") ) { _showAchievements_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_reportAchievement_func") ) { _reportAchievement_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_reportScoreForCategory_func") ) { _reportScoreForCategory_func=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"_showLeaderboardForCategory_func") ) { _showLeaderboardForCategory_func=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameCenter_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("instance"),
	HX_CSTRING("getInstance"),
	HX_CSTRING("_showAchievements_func"),
	HX_CSTRING("_showLeaderboardForCategory_func"),
	HX_CSTRING("_reportScoreForCategory_func"),
	HX_CSTRING("_reportAchievement_func"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("authenticateLocalUser"),
	HX_CSTRING("showAchievements"),
	HX_CSTRING("showLeaderboardForCategory"),
	HX_CSTRING("reportScoreForCategory"),
	HX_CSTRING("reportAchievement"),
	HX_CSTRING("resetAchievements"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameCenter_obj::instance,"instance");
	HX_MARK_MEMBER_NAME(GameCenter_obj::_showAchievements_func,"_showAchievements_func");
	HX_MARK_MEMBER_NAME(GameCenter_obj::_showLeaderboardForCategory_func,"_showLeaderboardForCategory_func");
	HX_MARK_MEMBER_NAME(GameCenter_obj::_reportScoreForCategory_func,"_reportScoreForCategory_func");
	HX_MARK_MEMBER_NAME(GameCenter_obj::_reportAchievement_func,"_reportAchievement_func");
};

Class GameCenter_obj::__mClass;

void GameCenter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nmex.GameCenter"), hx::TCanCast< GameCenter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameCenter_obj::__boot()
{
	hx::Static(instance);
	hx::Static(_showAchievements_func);
	hx::Static(_showLeaderboardForCategory_func);
	hx::Static(_reportScoreForCategory_func);
	hx::Static(_reportAchievement_func);
}

} // end namespace nmex
