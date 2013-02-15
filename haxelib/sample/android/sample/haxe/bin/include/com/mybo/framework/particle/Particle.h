#ifndef INCLUDED_com_mybo_framework_particle_Particle
#define INCLUDED_com_mybo_framework_particle_Particle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,particle,Particle)
HX_DECLARE_CLASS4(com,mybo,framework,particle,RGBA)
HX_DECLARE_CLASS4(com,mybo,framework,particle,Vector)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class Particle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Particle_obj OBJ_;
		Particle_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Particle_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Particle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Particle"); }

		::com::mybo::framework::particle::Vector pos; /* REM */ 
		double lifeSpan; /* REM */ 
		::com::mybo::framework::particle::RGBA color; /* REM */ 
		::com::mybo::framework::particle::RGBA deltaColor; /* REM */ 
		double size; /* REM */ 
		double deltaSize; /* REM */ 
		double rotation; /* REM */ 
		double deltaRotation; /* REM */ 
		double speedX_or_angle; /* REM */ 
		double speedY_or_anglePerSecond; /* REM */ 
		double radialAccel_or_radius; /* REM */ 
		double tangentialAccel_or_deltaRadius; /* REM */ 
		virtual double getSpeedX( );
		Dynamic getSpeedX_dyn();

		virtual Void setSpeedX( double value);
		Dynamic setSpeedX_dyn();

		virtual double getSpeedY( );
		Dynamic getSpeedY_dyn();

		virtual Void setSpeedY( double value);
		Dynamic setSpeedY_dyn();

		virtual double getRadialAccel( );
		Dynamic getRadialAccel_dyn();

		virtual Void setRadialAccel( double value);
		Dynamic setRadialAccel_dyn();

		virtual double getTangentialAccel( );
		Dynamic getTangentialAccel_dyn();

		virtual Void setTangentialAccel( double value);
		Dynamic setTangentialAccel_dyn();

		virtual double getAngle( );
		Dynamic getAngle_dyn();

		virtual Void setAngle( double value);
		Dynamic setAngle_dyn();

		virtual double getAnglePerSecond( );
		Dynamic getAnglePerSecond_dyn();

		virtual Void setAnglePerSecond( double value);
		Dynamic setAnglePerSecond_dyn();

		virtual double getRadius( );
		Dynamic getRadius_dyn();

		virtual Void setRadius( double value);
		Dynamic setRadius_dyn();

		virtual double getDeltaRadius( );
		Dynamic getDeltaRadius_dyn();

		virtual Void setDeltaRadius( double value);
		Dynamic setDeltaRadius_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_Particle */ 
