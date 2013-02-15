#ifndef INCLUDED_com_mybo_framework_particle_RadialModeData
#define INCLUDED_com_mybo_framework_particle_RadialModeData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,particle,RGBA)
HX_DECLARE_CLASS4(com,mybo,framework,particle,RadialModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,Vector)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class RadialModeData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RadialModeData_obj OBJ_;
		RadialModeData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< RadialModeData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RadialModeData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("RadialModeData"); }

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
		double emitterAngle; /* REM */ 
		double emitterAngleVariance; /* REM */ 
		int emitRate; /* REM */ 
		double startRadius; /* REM */ 
		double startRadiusVariance; /* REM */ 
		double endRadius; /* REM */ 
		double endRadiusVariance; /* REM */ 
		double rotatePerSecond; /* REM */ 
		double rotatePerSecondVariance; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_RadialModeData */ 
