#ifndef INCLUDED_nmex_NXEvent
#define INCLUDED_nmex_NXEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS1(nmex,NXEvent)
namespace nmex{


class NXEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef NXEvent_obj OBJ_;
		NXEvent_obj();
		Void __construct(::String type,int code,int value,::String data);

	public:
		static hx::ObjectPtr< NXEvent_obj > __new(::String type,int code,int value,::String data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NXEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NXEvent"); }

		int EventID; /* REM */ 
		int code; /* REM */ 
		int value; /* REM */ 
		::String data; /* REM */ 
		static ::String UN_KNOWN_EVENT; /* REM */ 
		static ::String IN_APP_PURCHASE_SUCCESS; /* REM */ 
		static ::String IN_APP_PURCHASE_FAIL; /* REM */ 
		static ::String IN_APP_PURCHASE_CANCEL; /* REM */ 
		static ::String AUTH_SUCCEEDED; /* REM */ 
		static ::String AUTH_FAILED; /* REM */ 
		static ::String LEADERBOARD_VIEW_OPENED; /* REM */ 
		static ::String LEADERBOARD_VIEW_CLOSED; /* REM */ 
		static ::String ACHIEVEMENTS_VIEW_OPENED; /* REM */ 
		static ::String ACHIEVEMENTS_VIEW_CLOSED; /* REM */ 
		static ::String SCORE_REPORT_SUCCEEDED; /* REM */ 
		static ::String SCORE_REPORT_FAILED; /* REM */ 
		static ::String ACHIEVEMENT_REPORT_SUCCEEDED; /* REM */ 
		static ::String ACHIEVEMENT_REPORT_FAILED; /* REM */ 
		static ::String ACHIEVEMENT_RESET_SUCCEEDED; /* REM */ 
		static ::String ACHIEVEMENT_RESET_FAILED; /* REM */ 
};

} // end namespace nmex

#endif /* INCLUDED_nmex_NXEvent */ 
