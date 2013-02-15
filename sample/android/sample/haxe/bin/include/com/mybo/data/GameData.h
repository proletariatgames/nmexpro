#ifndef INCLUDED_com_mybo_data_GameData
#define INCLUDED_com_mybo_data_GameData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,data,GameData)
namespace com{
namespace mybo{
namespace data{


class GameData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GameData_obj OBJ_;
		GameData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< GameData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameData"); }

		static int PUZZLE_TIP_VALUE; /* REM */ 
		static int MASTER_TIP_VALUE; /* REM */ 
		static int MASTER_UNLOCK_VALUE; /* REM */ 
		static int PUZZLE_PACK_VALUE; /* REM */ 
		static ::String bubbleTextureID; /* REM */ 
		static int getMasterReward( );
		static Dynamic getMasterReward_dyn();

		static int getClassicReward( int score);
		static Dynamic getClassicReward_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace data

#endif /* INCLUDED_com_mybo_data_GameData */ 
