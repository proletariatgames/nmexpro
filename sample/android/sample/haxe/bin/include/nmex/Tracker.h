#ifndef INCLUDED_nmex_Tracker
#define INCLUDED_nmex_Tracker

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nmex,Tracker)
namespace nmex{


class Tracker_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Tracker_obj OBJ_;
		Tracker_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Tracker_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Tracker_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Tracker"); }

		static bool init; /* REM */ 
		static Void assertInit( );
		static Dynamic assertInit_dyn();

		static Dynamic _startTracker_func; /* REM */ 
		static Void startTracker( ::String acountID,Dynamic disPatchPeriod);
		static Dynamic startTracker_dyn();

		static Dynamic _trackEvent_func; /* REM */ 
		static Void trackEvent( ::String category,::String action,::String label,int value);
		static Dynamic trackEvent_dyn();

		static Dynamic _trackPage_func; /* REM */ 
		static Void trackPage( ::String pageName);
		static Dynamic trackPage_dyn();

		static Dynamic _dispatchTracker_func; /* REM */ 
		static Void dispatchTracker( );
		static Dynamic dispatchTracker_dyn();

		static Dynamic _stopTracker_func; /* REM */ 
		static Void stopTracker( );
		static Dynamic stopTracker_dyn();

};

} // end namespace nmex

#endif /* INCLUDED_nmex_Tracker */ 
