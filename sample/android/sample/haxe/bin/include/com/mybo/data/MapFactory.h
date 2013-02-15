#ifndef INCLUDED_com_mybo_data_MapFactory
#define INCLUDED_com_mybo_data_MapFactory

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,data,Map)
HX_DECLARE_CLASS3(com,mybo,data,MapFactory)
namespace com{
namespace mybo{
namespace data{


class MapFactory_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MapFactory_obj OBJ_;
		MapFactory_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MapFactory_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MapFactory_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MapFactory"); }

		int packCount; /* REM */ 
		static int difficulty; /* REM */ 
		static Array< int > difficultyFactor; /* REM */ 
		static int MAX_ITEM; /* REM */ 
		static int mapRows; /* REM */ 
		static int mapCols; /* REM */ 
		static int packID; /* REM */ 
		static Array< Array< ::com::mybo::data::Map > > puzzleMaps; /* REM */ 
		static ::com::mybo::data::Map getClassicModeMap( int level);
		static Dynamic getClassicModeMap_dyn();

		static Void resetClassicModeMap( );
		static Dynamic resetClassicModeMap_dyn();

		static Void raiseDifficulty( );
		static Dynamic raiseDifficulty_dyn();

		static ::com::mybo::data::Map getMasterMap( );
		static Dynamic getMasterMap_dyn();

		static ::com::mybo::data::Map getPuzzleMap( int pack,int index);
		static Dynamic getPuzzleMap_dyn();

		static int getPuzzlePackConut( );
		static Dynamic getPuzzlePackConut_dyn();

		static int getPackMapCount( int pack);
		static Dynamic getPackMapCount_dyn();

		static Void loadMap( );
		static Dynamic loadMap_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace data

#endif /* INCLUDED_com_mybo_data_MapFactory */ 
