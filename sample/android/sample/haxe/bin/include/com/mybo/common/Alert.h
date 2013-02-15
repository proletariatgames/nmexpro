#ifndef INCLUDED_com_mybo_common_Alert
#define INCLUDED_com_mybo_common_Alert

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,Alert)
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class Alert_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef Alert_obj OBJ_;
		Alert_obj();
		Void __construct(::nmex::display::Bitmap bitmap,Dynamic yesHandle,Dynamic noHandle,Dynamic useOK);

	public:
		static hx::ObjectPtr< Alert_obj > __new(::nmex::display::Bitmap bitmap,Dynamic yesHandle,Dynamic noHandle,Dynamic useOK);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Alert_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Alert"); }

		::com::mybo::common::ScaleEffectButton yesBtn; /* REM */ 
		::com::mybo::common::ScaleEffectButton noBtn; /* REM */ 
		Dynamic yesHandleFun; /* REM */ 
	Dynamic &yesHandleFun_dyn() { return yesHandleFun;}
		Dynamic noHandleFun; /* REM */ 
	Dynamic &noHandleFun_dyn() { return noHandleFun;}
		::nme::display::Sprite motionContainer; /* REM */ 
		virtual Void onYes( );
		Dynamic onYes_dyn();

		virtual Void onNo( );
		Dynamic onNo_dyn();

		static ::com::mybo::common::Alert show( ::nmex::display::Bitmap bitmap,Dynamic yesHandle,Dynamic noHandle,Dynamic useOK);
		static Dynamic show_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_Alert */ 
