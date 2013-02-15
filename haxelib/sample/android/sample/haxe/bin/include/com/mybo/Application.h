#ifndef INCLUDED_com_mybo_Application
#define INCLUDED_com_mybo_Application

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(com,mybo,Application)
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,KeyboardEvent)
namespace com{
namespace mybo{


class Application_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Application_obj OBJ_;
		Application_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Application_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Application_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Application"); }

		::com::mybo::framework::core::Facade facade; /* REM */ 
		virtual Void onAndroidBack( ::nme::events::KeyboardEvent e);
		Dynamic onAndroidBack_dyn();

		virtual Void onDeactive( ::nme::events::Event e);
		Dynamic onDeactive_dyn();

};

} // end namespace com
} // end namespace mybo

#endif /* INCLUDED_com_mybo_Application */ 
