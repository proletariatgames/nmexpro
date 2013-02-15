#ifndef INCLUDED_com_mybo_common_ScaleEffectButton
#define INCLUDED_com_mybo_common_ScaleEffectButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/display/BitmapSimpleButton.h>
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class ScaleEffectButton_obj : public ::com::mybo::framework::display::BitmapSimpleButton_obj{
	public:
		typedef ::com::mybo::framework::display::BitmapSimpleButton_obj super;
		typedef ScaleEffectButton_obj OBJ_;
		ScaleEffectButton_obj();
		Void __construct(::nmex::display::Bitmap inBitmap);

	public:
		static hx::ObjectPtr< ScaleEffectButton_obj > __new(::nmex::display::Bitmap inBitmap);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ScaleEffectButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ScaleEffectButton"); }

		virtual Void onMouseDown( ::nme::events::Event e);
		Dynamic onMouseDown_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_ScaleEffectButton */ 
