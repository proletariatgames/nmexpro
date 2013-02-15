#ifndef INCLUDED_nmex_NativeUI
#define INCLUDED_nmex_NativeUI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nmex,NativeUI)
namespace nmex{


class NativeUI_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeUI_obj OBJ_;
		NativeUI_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeUI_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeUI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeUI"); }

		static Dynamic _showAlert_func; /* REM */ 
		static Void showAlert( ::String title,::String msg);
		static Dynamic showAlert_dyn();

};

} // end namespace nmex

#endif /* INCLUDED_nmex_NativeUI */ 
