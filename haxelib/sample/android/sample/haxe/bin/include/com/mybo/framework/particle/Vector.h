#ifndef INCLUDED_com_mybo_framework_particle_Vector
#define INCLUDED_com_mybo_framework_particle_Vector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/geom/Point.h>
HX_DECLARE_CLASS4(com,mybo,framework,particle,Vector)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class Vector_obj : public ::nme::geom::Point_obj{
	public:
		typedef ::nme::geom::Point_obj super;
		typedef Vector_obj OBJ_;
		Vector_obj();
		Void __construct(Dynamic x,Dynamic y);

	public:
		static hx::ObjectPtr< Vector_obj > __new(Dynamic x,Dynamic y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vector_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector"); }

		virtual ::com::mybo::framework::particle::Vector unitVector( );
		Dynamic unitVector_dyn();

		virtual ::com::mybo::framework::particle::Vector addVector( ::com::mybo::framework::particle::Vector vec);
		Dynamic addVector_dyn();

		virtual ::com::mybo::framework::particle::Vector mult( double value);
		Dynamic mult_dyn();

		virtual ::com::mybo::framework::particle::Vector copy( );
		Dynamic copy_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_Vector */ 
