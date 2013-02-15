#ifndef INCLUDED_nme_ui_MultitouchInputMode
#define INCLUDED_nme_ui_MultitouchInputMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,ui,MultitouchInputMode)
namespace nme{
namespace ui{


class MultitouchInputMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef MultitouchInputMode_obj OBJ_;

	public:
		MultitouchInputMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.ui.MultitouchInputMode"); }
		::String __ToString() const { return HX_CSTRING("MultitouchInputMode.") + tag; }

		static ::nme::ui::MultitouchInputMode GESTURE;
		static inline ::nme::ui::MultitouchInputMode GESTURE_dyn() { return GESTURE; }
		static ::nme::ui::MultitouchInputMode NONE;
		static inline ::nme::ui::MultitouchInputMode NONE_dyn() { return NONE; }
		static ::nme::ui::MultitouchInputMode TOUCH_POINT;
		static inline ::nme::ui::MultitouchInputMode TOUCH_POINT_dyn() { return TOUCH_POINT; }
};

} // end namespace nme
} // end namespace ui

#endif /* INCLUDED_nme_ui_MultitouchInputMode */ 
