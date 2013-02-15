#ifndef INCLUDED_com_mybo_framework_particle_EmitterMode
#define INCLUDED_com_mybo_framework_particle_EmitterMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,particle,EmitterMode)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class EmitterMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef EmitterMode_obj OBJ_;

	public:
		EmitterMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("com.mybo.framework.particle.EmitterMode"); }
		::String __ToString() const { return HX_CSTRING("EmitterMode.") + tag; }

		static ::com::mybo::framework::particle::EmitterMode gravityMode;
		static inline ::com::mybo::framework::particle::EmitterMode gravityMode_dyn() { return gravityMode; }
		static ::com::mybo::framework::particle::EmitterMode radialMode;
		static inline ::com::mybo::framework::particle::EmitterMode radialMode_dyn() { return radialMode; }
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_EmitterMode */ 
