#ifndef INCLUDED_haxe_FastList
#define INCLUDED_haxe_FastList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,FastCell)
HX_DECLARE_CLASS1(haxe,FastList)
namespace haxe{


class FastList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FastList_obj OBJ_;
		FastList_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FastList_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FastList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FastList"); }

		::haxe::FastCell head; /* REM */ 
		virtual Void add( Dynamic item);
		Dynamic add_dyn();

		virtual Dynamic first( );
		Dynamic first_dyn();

		virtual Dynamic pop( );
		Dynamic pop_dyn();

		virtual bool isEmpty( );
		Dynamic isEmpty_dyn();

		virtual bool remove( Dynamic v);
		Dynamic remove_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_FastList */ 
