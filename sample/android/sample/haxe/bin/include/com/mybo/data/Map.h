#ifndef INCLUDED_com_mybo_data_Map
#define INCLUDED_com_mybo_data_Map

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,data,Map)
namespace com{
namespace mybo{
namespace data{


class Map_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Map_obj OBJ_;
		Map_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Map_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Map_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Map"); }

		Array< Array< int > > data; /* REM */ 
		int solutionStep; /* REM */ 
		Array< Array< int > > solution; /* REM */ 
		bool buyTip; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

		static int ROW; /* REM */ 
		static int COL; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace data

#endif /* INCLUDED_com_mybo_data_Map */ 
