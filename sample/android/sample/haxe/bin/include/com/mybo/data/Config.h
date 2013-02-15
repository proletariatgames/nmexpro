#ifndef INCLUDED_com_mybo_data_Config
#define INCLUDED_com_mybo_data_Config

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,data,Config)
namespace com{
namespace mybo{
namespace data{


class Config_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Config_obj OBJ_;
		Config_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Config_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Config_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Config"); }

		static int maxTouches; /* REM */ 
		static int bubbleKind; /* REM */ 
		static int initLevel; /* REM */ 
		static int initScore; /* REM */ 
		static int initTouches; /* REM */ 
		static int scoreUnit; /* REM */ 
		static int puzzleScoreUnit; /* REM */ 
		static int comboToTouchUnit; /* REM */ 
		static int rateLevel; /* REM */ 
		static int levelPassGift; /* REM */ 
		static ::String mapPackURL; /* REM */ 
		static int maxMapPackItem; /* REM */ 
		static int classicLevelForStarBubble; /* REM */ 
		static ::String adID; /* REM */ 
		static ::String gAnalyticsID; /* REM */ 
		static ::String resourcePath; /* REM */ 
		static ::String docmentsPath; /* REM */ 
		static ::String gameCenterLeaderBoardID; /* REM */ 
		static ::String gameCenterPuzzleLeaderBoardID; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace data

#endif /* INCLUDED_com_mybo_data_Config */ 
