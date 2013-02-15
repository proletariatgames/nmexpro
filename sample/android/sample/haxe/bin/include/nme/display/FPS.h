#ifndef INCLUDED_nme_display_FPS
#define INCLUDED_nme_display_FPS

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/text/TextField.h>
HX_DECLARE_CLASS2(nme,display,FPS)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,text,TextField)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace nme{
namespace display{


class FPS_obj : public ::nme::text::TextField_obj{
	public:
		typedef ::nme::text::TextField_obj super;
		typedef FPS_obj OBJ_;
		FPS_obj();
		Void __construct(Dynamic __o_inX,Dynamic __o_inY,Dynamic __o_inCol);

	public:
		static hx::ObjectPtr< FPS_obj > __new(Dynamic __o_inX,Dynamic __o_inY,Dynamic __o_inCol);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FPS_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FPS"); }

		Array< double > times; /* REM */ 
		virtual Void onEnter( Dynamic _);
		Dynamic onEnter_dyn();

};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_FPS */ 
