#ifndef INCLUDED_com_mybo_framework_particle_GravityModeData
#define INCLUDED_com_mybo_framework_particle_GravityModeData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,particle,GravityModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,RGBA)
HX_DECLARE_CLASS4(com,mybo,framework,particle,Vector)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class GravityModeData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GravityModeData_obj OBJ_;
		GravityModeData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< GravityModeData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GravityModeData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GravityModeData"); }

		bool keepSize; /* REM */ 
		bool keepColor; /* REM */ 
		bool keepRotationAngle; /* REM */ 
		int maxParticles; /* REM */ 
		double duration; /* REM */ 
		double lifespan; /* REM */ 
		double lifespanVariance; /* REM */ 
		double startSize; /* REM */ 
		double startSizeVariance; /* REM */ 
		double endSize; /* REM */ 
		double endSizeVariance; /* REM */ 
		double startRotation; /* REM */ 
		double startRotationVariance; /* REM */ 
		double endRotation; /* REM */ 
		double endRotationVariance; /* REM */ 
		::com::mybo::framework::particle::RGBA startColor; /* REM */ 
		::com::mybo::framework::particle::RGBA startColorVariance; /* REM */ 
		::com::mybo::framework::particle::RGBA endColor; /* REM */ 
		::com::mybo::framework::particle::RGBA endColorVariance; /* REM */ 
		::com::mybo::framework::particle::Vector emitterPosition; /* REM */ 
		::com::mybo::framework::particle::Vector emitterPosVariance; /* REM */ 
		double emitterAngle; /* REM */ 
		double emitterAngleVariance; /* REM */ 
		int emitRate; /* REM */ 
		double speed; /* REM */ 
		double speedVariance; /* REM */ 
		::com::mybo::framework::particle::Vector gravity; /* REM */ 
		double radialAcceleration; /* REM */ 
		double radialAccelVariance; /* REM */ 
		double tangentialAcceleration; /* REM */ 
		double tangentialAccelVariance; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_GravityModeData */ 
