#ifndef INCLUDED_com_mybo_common_GameEvent
#define INCLUDED_com_mybo_common_GameEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS3(com,mybo,common,GameEvent)
HX_DECLARE_CLASS2(nme,events,Event)
namespace com{
namespace mybo{
namespace common{


class GameEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef GameEvent_obj OBJ_;
		GameEvent_obj();
		Void __construct(::String type,Array< int > inData);

	public:
		static hx::ObjectPtr< GameEvent_obj > __new(::String type,Array< int > inData);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameEvent"); }

		Array< int > data; /* REM */ 
		static ::String BUBBLE_BLAST; /* REM */ 
		static ::String BUBBLE_INITED; /* REM */ 
		static ::String BUBBLE_TAP_COMPLETED; /* REM */ 
		static ::String LEVEL_COMPLETE; /* REM */ 
		static ::String BUBBLE_TOUCHED; /* REM */ 
		static ::String LEVEL_SELECTED; /* REM */ 
		static ::String PACK_SELECTED; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_GameEvent */ 
