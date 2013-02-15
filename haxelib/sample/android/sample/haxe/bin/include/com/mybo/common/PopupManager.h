#ifndef INCLUDED_com_mybo_common_PopupManager
#define INCLUDED_com_mybo_common_PopupManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,common,PopupManager)
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class PopupManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PopupManager_obj OBJ_;
		PopupManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PopupManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PopupManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PopupManager"); }

		::com::mybo::framework::core::Facade facade; /* REM */ 
		double stageWidth; /* REM */ 
		double stageHeight; /* REM */ 
		::nme::display::Sprite popupUIContainer; /* REM */ 
		virtual Void setMask( Dynamic maskColor,Dynamic alpha);
		Dynamic setMask_dyn();

		virtual Void popup( ::nmex::display::DisplayObject displayObject);
		Dynamic popup_dyn();

		virtual Void removePopupUI( ::nmex::display::DisplayObject displayObject);
		Dynamic removePopupUI_dyn();

		virtual Void cleanup( );
		Dynamic cleanup_dyn();

		static ::com::mybo::common::PopupManager instance; /* REM */ 
		static ::com::mybo::common::PopupManager getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_PopupManager */ 
