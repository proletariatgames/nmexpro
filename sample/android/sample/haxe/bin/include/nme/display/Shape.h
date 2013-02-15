#ifndef INCLUDED_nme_display_Shape
#define INCLUDED_nme_display_Shape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nmex/display/DisplayObject.h>
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,Shape)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace nme{
namespace display{


class Shape_obj : public ::nmex::display::DisplayObject_obj{
	public:
		typedef ::nmex::display::DisplayObject_obj super;
		typedef Shape_obj OBJ_;
		Shape_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Shape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Shape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Shape"); }

};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Shape */ 
