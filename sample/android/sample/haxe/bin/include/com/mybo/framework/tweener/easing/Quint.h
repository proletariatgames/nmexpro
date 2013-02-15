#ifndef INCLUDED_com_mybo_framework_tweener_easing_Quint
#define INCLUDED_com_mybo_framework_tweener_easing_Quint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/Public.h>
HX_DECLARE_CLASS5(com,mybo,framework,tweener,easing,Quint)
HX_DECLARE_CLASS1(haxe,Public)
namespace com{
namespace mybo{
namespace framework{
namespace tweener{
namespace easing{


class Quint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Quint_obj OBJ_;
		Quint_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Quint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Quint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::haxe::Public_obj *()
			{ return new ::haxe::Public_delegate_< Quint_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Quint"); }

		static double easeIn( double t,double b,double c,double d);
		static Dynamic easeIn_dyn();

		static double easeOut( double t,double b,double c,double d);
		static Dynamic easeOut_dyn();

		static double easeInOut( double t,double b,double c,double d);
		static Dynamic easeInOut_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace tweener
} // end namespace easing

#endif /* INCLUDED_com_mybo_framework_tweener_easing_Quint */ 
