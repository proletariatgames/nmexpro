#ifndef INCLUDED_nmex_NXObject
#define INCLUDED_nmex_NXObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/EventDispatcher.h>
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS1(nmex,NXObject)
namespace nmex{


class NXObject_obj : public ::nme::events::EventDispatcher_obj{
	public:
		typedef ::nme::events::EventDispatcher_obj super;
		typedef NXObject_obj OBJ_;
		NXObject_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NXObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NXObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NXObject"); }

		static ::nme::events::EventDispatcher eventProxy; /* REM */ 
		static Array< ::nmex::NXObject > objects; /* REM */ 
		static bool eventHandleInit; /* REM */ 
		static Void initEventHandle( );
		static Dynamic initEventHandle_dyn();

		static Void externEventHandle( Dynamic inEvent);
		static Dynamic externEventHandle_dyn();

		static Dynamic nmex_set_event_handle; /* REM */ 
	Dynamic &nmex_set_event_handle_dyn() { return nmex_set_event_handle;}
};

} // end namespace nmex

#endif /* INCLUDED_nmex_NXObject */ 
