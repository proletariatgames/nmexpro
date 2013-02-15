#ifndef INCLUDED_haxe_FastListIterator
#define INCLUDED_haxe_FastListIterator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cpp/FastIterator.h>
HX_DECLARE_CLASS1(haxe,FastCell)
HX_DECLARE_CLASS1(haxe,FastListIterator)
namespace haxe{


class FastListIterator_obj : public ::cpp::FastIterator_obj< Dynamic >{
	public:
		typedef ::cpp::FastIterator_obj< Dynamic > super;
		typedef FastListIterator_obj OBJ_;
		FastListIterator_obj();
		Void __construct(::haxe::FastCell head);

	public:
		static hx::ObjectPtr< FastListIterator_obj > __new(::haxe::FastCell head);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FastListIterator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FastListIterator"); }

		::haxe::FastCell current; /* REM */ 
		virtual bool hasNext( );
		Dynamic hasNext_dyn();

		virtual Dynamic next( );
		Dynamic next_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_FastListIterator */ 
