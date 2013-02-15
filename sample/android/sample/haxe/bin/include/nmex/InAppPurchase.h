#ifndef INCLUDED_nmex_InAppPurchase
#define INCLUDED_nmex_InAppPurchase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nmex/NXObject.h>
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS1(nmex,InAppPurchase)
HX_DECLARE_CLASS1(nmex,NXObject)
namespace nmex{


class InAppPurchase_obj : public ::nmex::NXObject_obj{
	public:
		typedef ::nmex::NXObject_obj super;
		typedef InAppPurchase_obj OBJ_;
		InAppPurchase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InAppPurchase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InAppPurchase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InAppPurchase"); }

		virtual bool canPurchase( );
		Dynamic canPurchase_dyn();

		virtual Void purchase( ::String productID);
		Dynamic purchase_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		static ::nmex::InAppPurchase instance; /* REM */ 
		static ::nmex::InAppPurchase getInstance( );
		static Dynamic getInstance_dyn();

		static Dynamic nmex_system_in_app_purchase_init; /* REM */ 
	Dynamic &nmex_system_in_app_purchase_init_dyn() { return nmex_system_in_app_purchase_init;}
		static Dynamic nmex_system_in_app_purchase_purchase; /* REM */ 
	Dynamic &nmex_system_in_app_purchase_purchase_dyn() { return nmex_system_in_app_purchase_purchase;}
		static Dynamic nmex_system_in_app_purchase_can_purchase; /* REM */ 
	Dynamic &nmex_system_in_app_purchase_can_purchase_dyn() { return nmex_system_in_app_purchase_can_purchase;}
		static Dynamic nmex_system_in_app_purchase_release; /* REM */ 
	Dynamic &nmex_system_in_app_purchase_release_dyn() { return nmex_system_in_app_purchase_release;}
};

} // end namespace nmex

#endif /* INCLUDED_nmex_InAppPurchase */ 
