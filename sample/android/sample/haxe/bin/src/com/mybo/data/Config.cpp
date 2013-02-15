#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_data_Config
#include <com/mybo/data/Config.h>
#endif
namespace com{
namespace mybo{
namespace data{

Void Config_obj::__construct()
{
	return null();
}

Config_obj::~Config_obj() { }

Dynamic Config_obj::__CreateEmpty() { return  new Config_obj; }
hx::ObjectPtr< Config_obj > Config_obj::__new()
{  hx::ObjectPtr< Config_obj > result = new Config_obj();
	result->__construct();
	return result;}

Dynamic Config_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Config_obj > result = new Config_obj();
	result->__construct();
	return result;}

int Config_obj::maxTouches;

int Config_obj::bubbleKind;

int Config_obj::initLevel;

int Config_obj::initScore;

int Config_obj::initTouches;

int Config_obj::scoreUnit;

int Config_obj::puzzleScoreUnit;

int Config_obj::comboToTouchUnit;

int Config_obj::rateLevel;

int Config_obj::levelPassGift;

::String Config_obj::mapPackURL;

int Config_obj::maxMapPackItem;

int Config_obj::classicLevelForStarBubble;

::String Config_obj::adID;

::String Config_obj::gAnalyticsID;

::String Config_obj::resourcePath;

::String Config_obj::docmentsPath;

::String Config_obj::gameCenterLeaderBoardID;

::String Config_obj::gameCenterPuzzleLeaderBoardID;


Config_obj::Config_obj()
{
}

void Config_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Config);
	HX_MARK_END_CLASS();
}

Dynamic Config_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"adID") ) { return adID; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initLevel") ) { return initLevel; }
		if (HX_FIELD_EQ(inName,"initScore") ) { return initScore; }
		if (HX_FIELD_EQ(inName,"scoreUnit") ) { return scoreUnit; }
		if (HX_FIELD_EQ(inName,"rateLevel") ) { return rateLevel; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxTouches") ) { return maxTouches; }
		if (HX_FIELD_EQ(inName,"bubbleKind") ) { return bubbleKind; }
		if (HX_FIELD_EQ(inName,"mapPackURL") ) { return mapPackURL; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initTouches") ) { return initTouches; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gAnalyticsID") ) { return gAnalyticsID; }
		if (HX_FIELD_EQ(inName,"resourcePath") ) { return resourcePath; }
		if (HX_FIELD_EQ(inName,"docmentsPath") ) { return docmentsPath; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"levelPassGift") ) { return levelPassGift; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxMapPackItem") ) { return maxMapPackItem; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"puzzleScoreUnit") ) { return puzzleScoreUnit; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"comboToTouchUnit") ) { return comboToTouchUnit; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"gameCenterLeaderBoardID") ) { return gameCenterLeaderBoardID; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"classicLevelForStarBubble") ) { return classicLevelForStarBubble; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"gameCenterPuzzleLeaderBoardID") ) { return gameCenterPuzzleLeaderBoardID; }
	}
	return super::__Field(inName);
}

Dynamic Config_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"adID") ) { adID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initLevel") ) { initLevel=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initScore") ) { initScore=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scoreUnit") ) { scoreUnit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rateLevel") ) { rateLevel=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxTouches") ) { maxTouches=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bubbleKind") ) { bubbleKind=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mapPackURL") ) { mapPackURL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"initTouches") ) { initTouches=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gAnalyticsID") ) { gAnalyticsID=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resourcePath") ) { resourcePath=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"docmentsPath") ) { docmentsPath=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"levelPassGift") ) { levelPassGift=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"maxMapPackItem") ) { maxMapPackItem=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"puzzleScoreUnit") ) { puzzleScoreUnit=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"comboToTouchUnit") ) { comboToTouchUnit=inValue.Cast< int >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"gameCenterLeaderBoardID") ) { gameCenterLeaderBoardID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"classicLevelForStarBubble") ) { classicLevelForStarBubble=inValue.Cast< int >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"gameCenterPuzzleLeaderBoardID") ) { gameCenterPuzzleLeaderBoardID=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Config_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("maxTouches"),
	HX_CSTRING("bubbleKind"),
	HX_CSTRING("initLevel"),
	HX_CSTRING("initScore"),
	HX_CSTRING("initTouches"),
	HX_CSTRING("scoreUnit"),
	HX_CSTRING("puzzleScoreUnit"),
	HX_CSTRING("comboToTouchUnit"),
	HX_CSTRING("rateLevel"),
	HX_CSTRING("levelPassGift"),
	HX_CSTRING("mapPackURL"),
	HX_CSTRING("maxMapPackItem"),
	HX_CSTRING("classicLevelForStarBubble"),
	HX_CSTRING("adID"),
	HX_CSTRING("gAnalyticsID"),
	HX_CSTRING("resourcePath"),
	HX_CSTRING("docmentsPath"),
	HX_CSTRING("gameCenterLeaderBoardID"),
	HX_CSTRING("gameCenterPuzzleLeaderBoardID"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Config_obj::maxTouches,"maxTouches");
	HX_MARK_MEMBER_NAME(Config_obj::bubbleKind,"bubbleKind");
	HX_MARK_MEMBER_NAME(Config_obj::initLevel,"initLevel");
	HX_MARK_MEMBER_NAME(Config_obj::initScore,"initScore");
	HX_MARK_MEMBER_NAME(Config_obj::initTouches,"initTouches");
	HX_MARK_MEMBER_NAME(Config_obj::scoreUnit,"scoreUnit");
	HX_MARK_MEMBER_NAME(Config_obj::puzzleScoreUnit,"puzzleScoreUnit");
	HX_MARK_MEMBER_NAME(Config_obj::comboToTouchUnit,"comboToTouchUnit");
	HX_MARK_MEMBER_NAME(Config_obj::rateLevel,"rateLevel");
	HX_MARK_MEMBER_NAME(Config_obj::levelPassGift,"levelPassGift");
	HX_MARK_MEMBER_NAME(Config_obj::mapPackURL,"mapPackURL");
	HX_MARK_MEMBER_NAME(Config_obj::maxMapPackItem,"maxMapPackItem");
	HX_MARK_MEMBER_NAME(Config_obj::classicLevelForStarBubble,"classicLevelForStarBubble");
	HX_MARK_MEMBER_NAME(Config_obj::adID,"adID");
	HX_MARK_MEMBER_NAME(Config_obj::gAnalyticsID,"gAnalyticsID");
	HX_MARK_MEMBER_NAME(Config_obj::resourcePath,"resourcePath");
	HX_MARK_MEMBER_NAME(Config_obj::docmentsPath,"docmentsPath");
	HX_MARK_MEMBER_NAME(Config_obj::gameCenterLeaderBoardID,"gameCenterLeaderBoardID");
	HX_MARK_MEMBER_NAME(Config_obj::gameCenterPuzzleLeaderBoardID,"gameCenterPuzzleLeaderBoardID");
};

Class Config_obj::__mClass;

void Config_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.data.Config"), hx::TCanCast< Config_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Config_obj::__boot()
{
	hx::Static(maxTouches) = (int)15;
	hx::Static(bubbleKind) = (int)5;
	hx::Static(initLevel) = (int)1;
	hx::Static(initScore) = (int)0;
	hx::Static(initTouches) = (int)15;
	hx::Static(scoreUnit) = (int)15;
	hx::Static(puzzleScoreUnit) = (int)2;
	hx::Static(comboToTouchUnit) = (int)3;
	hx::Static(rateLevel) = (int)15;
	hx::Static(levelPassGift) = (int)1;
	hx::Static(mapPackURL) = (HX_CSTRING("") + HX_CSTRING("maps"));
	hx::Static(maxMapPackItem) = (int)25;
	hx::Static(classicLevelForStarBubble) = (int)6;
	hx::Static(adID) = HX_CSTRING("a14faa14de9f235");
	hx::Static(gAnalyticsID) = HX_CSTRING("UA-19790825-15");
	hx::Static(resourcePath) = HX_CSTRING("");
	hx::Static(docmentsPath) = HX_CSTRING("/data/data/com.mybogame.bbx2/");
	hx::Static(gameCenterLeaderBoardID) = HX_CSTRING("1044127");
	hx::Static(gameCenterPuzzleLeaderBoardID) = HX_CSTRING("1165567");
}

} // end namespace com
} // end namespace mybo
} // end namespace data
