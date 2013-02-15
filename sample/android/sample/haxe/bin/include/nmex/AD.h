#ifndef INCLUDED_nmex_AD
#define INCLUDED_nmex_AD

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nmex,AD)
namespace nmex{


class AD_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AD_obj OBJ_;
		AD_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AD_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AD_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AD"); }

		static Dynamic _showAd_func; /* REM */ 
		static Void showAd( ::String id,Dynamic x,Dynamic y,Dynamic size,Dynamic preLoad);
		static Dynamic showAd_dyn();

		static Dynamic _hideAd_func; /* REM */ 
		static Void hideAd( );
		static Dynamic hideAd_dyn();

};

} // end namespace nmex

#endif /* INCLUDED_nmex_AD */ 
