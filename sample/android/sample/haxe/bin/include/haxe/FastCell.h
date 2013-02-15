#ifndef INCLUDED_haxe_FastCell
#define INCLUDED_haxe_FastCell

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,FastCell)
namespace haxe{


class FastCell_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FastCell_obj OBJ_;
		FastCell_obj();
		Void __construct(Dynamic elt,::haxe::FastCell next);

	public:
		static hx::ObjectPtr< FastCell_obj > __new(Dynamic elt,::haxe::FastCell next);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FastCell_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FastCell"); }

		Dynamic elt; /* REM */ 
		::haxe::FastCell next; /* REM */ 
};

} // end namespace haxe

#endif /* INCLUDED_haxe_FastCell */ 
