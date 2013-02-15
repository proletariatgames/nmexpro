#ifndef INCLUDED_com_mybo_framework_particle_RGBA
#define INCLUDED_com_mybo_framework_particle_RGBA

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,particle,RGBA)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class RGBA_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RGBA_obj OBJ_;
		RGBA_obj();
		Void __construct(Dynamic r,Dynamic g,Dynamic b,Dynamic a);

	public:
		static hx::ObjectPtr< RGBA_obj > __new(Dynamic r,Dynamic g,Dynamic b,Dynamic a);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RGBA_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("RGBA"); }

		double r; /* REM */ 
		double g; /* REM */ 
		double b; /* REM */ 
		double a; /* REM */ 
		virtual Void mult( double value);
		Dynamic mult_dyn();

		virtual Void add( ::com::mybo::framework::particle::RGBA rgba);
		Dynamic add_dyn();

		virtual bool equal( ::com::mybo::framework::particle::RGBA rgba);
		Dynamic equal_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_RGBA */ 
