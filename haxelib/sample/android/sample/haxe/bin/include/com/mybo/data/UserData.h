#ifndef INCLUDED_com_mybo_data_UserData
#define INCLUDED_com_mybo_data_UserData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(com,mybo,data,Map)
HX_DECLARE_CLASS3(com,mybo,data,UserData)
namespace com{
namespace mybo{
namespace data{


class UserData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef UserData_obj OBJ_;
		UserData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< UserData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UserData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("UserData"); }

		int packAmount; /* REM */ 
		int bestScore; /* REM */ 
		Array< Array< int > > paidTips; /* REM */ 
		Array< int > completedOfPack; /* REM */ 
		Array< int > unlockedPacks; /* REM */ 
		int stars; /* REM */ 
		bool music; /* REM */ 
		::com::mybo::data::Map masterMap; /* REM */ 
		::Hash levelScoreHash; /* REM */ 
		int puzzleTotalScore; /* REM */ 
		virtual bool isFirstRun( );
		Dynamic isFirstRun_dyn();

		virtual int getLevelScore( int pack,int level);
		Dynamic getLevelScore_dyn();

		virtual Void setLevelScore( int pack,int level,int score);
		Dynamic setLevelScore_dyn();

		virtual int getPuzzleTotalScore( );
		Dynamic getPuzzleTotalScore_dyn();

		virtual Void setPuzzleTotalScore( int score);
		Dynamic setPuzzleTotalScore_dyn();

		virtual ::com::mybo::data::Map getMasterMap( );
		Dynamic getMasterMap_dyn();

		virtual Void setMasterMap( ::com::mybo::data::Map map);
		Dynamic setMasterMap_dyn();

		virtual bool useStar( int star);
		Dynamic useStar_dyn();

		virtual Void addStar( int star);
		Dynamic addStar_dyn();

		virtual Void setStar( int value);
		Dynamic setStar_dyn();

		virtual int getStar( );
		Dynamic getStar_dyn();

		virtual int getPackCompleted( int pack);
		Dynamic getPackCompleted_dyn();

		virtual Void setPackCompleted( int pack,int value);
		Dynamic setPackCompleted_dyn();

		virtual Void unlockPack( int pack);
		Dynamic unlockPack_dyn();

		virtual Void unlockNextPack( );
		Dynamic unlockNextPack_dyn();

		virtual bool isPackUnlocked( int pack);
		Dynamic isPackUnlocked_dyn();

		virtual bool isTipPaid( int pack,int level);
		Dynamic isTipPaid_dyn();

		virtual Void setTipPaid( int pack,int level);
		Dynamic setTipPaid_dyn();

		virtual int getBestScore( );
		Dynamic getBestScore_dyn();

		virtual Void setBestScore( int value);
		Dynamic setBestScore_dyn();

		virtual bool getMusic( );
		Dynamic getMusic_dyn();

		virtual Void setMusic( bool value);
		Dynamic setMusic_dyn();

		virtual ::String creatID( int pack,int level);
		Dynamic creatID_dyn();

		static ::String name; /* REM */ 
		static ::com::mybo::data::UserData instance; /* REM */ 
		static ::com::mybo::data::UserData getInstance( Dynamic reload);
		static Dynamic getInstance_dyn();

		static bool loadFromLocal( );
		static Dynamic loadFromLocal_dyn();

		static Void saveToLocal( );
		static Dynamic saveToLocal_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace data

#endif /* INCLUDED_com_mybo_data_UserData */ 
