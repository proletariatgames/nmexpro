#ifndef INCLUDED_com_mybo_common_IAPDialog
#define INCLUDED_com_mybo_common_IAPDialog

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,IAPDialog)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class IAPDialog_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef IAPDialog_obj OBJ_;
		IAPDialog_obj();
		Void __construct(Dynamic successHandle);

	public:
		static hx::ObjectPtr< IAPDialog_obj > __new(Dynamic successHandle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IAPDialog_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("IAPDialog"); }

		::String currentProductID; /* REM */ 
		Dynamic successHandleFun; /* REM */ 
	Dynamic &successHandleFun_dyn() { return successHandleFun;}
		::nme::display::Sprite motionContainer; /* REM */ 
		virtual Void buy( ::String id);
		Dynamic buy_dyn();

		virtual Void onCancel( );
		Dynamic onCancel_dyn();

		virtual Void onFail( ::nme::events::Event e);
		Dynamic onFail_dyn();

		virtual Void onSuccess( ::nme::events::Event e);
		Dynamic onSuccess_dyn();

		static ::String PRODUCT_ID_BUY_35; /* REM */ 
		static ::String PRODUCT_ID_BUY_125; /* REM */ 
		static ::String PRODUCT_ID_BUY_265; /* REM */ 
		static ::String PRODUCT_ID_BUY_1000; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_IAPDialog */ 
