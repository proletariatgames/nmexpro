#ifndef INCLUDED_com_mybo_menuscene_PackageSelector
#define INCLUDED_com_mybo_menuscene_PackageSelector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,GameEvent)
HX_DECLARE_CLASS4(com,mybo,framework,display,TouchUpDownContainer)
HX_DECLARE_CLASS3(com,mybo,menuscene,PackageItem)
HX_DECLARE_CLASS3(com,mybo,menuscene,PackageSelector)
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
namespace menuscene{


class PackageSelector_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef PackageSelector_obj OBJ_;
		PackageSelector_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PackageSelector_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PackageSelector_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PackageSelector"); }

		::com::mybo::framework::display::TouchUpDownContainer touchUpDownContainer; /* REM */ 
		::nme::display::Sprite content; /* REM */ 
		Array< ::com::mybo::menuscene::PackageItem > items; /* REM */ 
		virtual Void onEnterFrame( ::nme::events::Event e);
		Dynamic onEnterFrame_dyn();

		virtual Void onSelect( ::com::mybo::common::GameEvent e);
		Dynamic onSelect_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_PackageSelector */ 
