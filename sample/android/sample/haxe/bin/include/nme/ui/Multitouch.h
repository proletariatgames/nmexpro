#ifndef INCLUDED_nme_ui_Multitouch
#define INCLUDED_nme_ui_Multitouch

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,ui,Multitouch)
HX_DECLARE_CLASS2(nme,ui,MultitouchInputMode)
namespace nme{
namespace ui{


class Multitouch_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Multitouch_obj OBJ_;
		Multitouch_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Multitouch_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Multitouch_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("Multitouch"); }

		static ::nme::ui::MultitouchInputMode inputMode; /* REM */ 
		static int maxTouchPoints; /* REM */ 
		static Array< ::String > supportedGestures; /* REM */ 
		static bool supportsGestureEvents; /* REM */ 
		static bool supportsTouchEvents; /* REM */ 
		static ::nme::ui::MultitouchInputMode nmeGetInputMode( );
		static Dynamic nmeGetInputMode_dyn();

		static ::nme::ui::MultitouchInputMode nmeSetInputMode( ::nme::ui::MultitouchInputMode inMode);
		static Dynamic nmeSetInputMode_dyn();

		static bool nmeGetSupportsTouchEvents( );
		static Dynamic nmeGetSupportsTouchEvents_dyn();

		static Dynamic nme_stage_get_multitouch_supported; /* REM */ 
	Dynamic &nme_stage_get_multitouch_supported_dyn() { return nme_stage_get_multitouch_supported;}
		static Dynamic nme_stage_get_multitouch_active; /* REM */ 
	Dynamic &nme_stage_get_multitouch_active_dyn() { return nme_stage_get_multitouch_active;}
		static Dynamic nme_stage_set_multitouch_active; /* REM */ 
	Dynamic &nme_stage_set_multitouch_active_dyn() { return nme_stage_set_multitouch_active;}
};

} // end namespace nme
} // end namespace ui

#endif /* INCLUDED_nme_ui_Multitouch */ 
