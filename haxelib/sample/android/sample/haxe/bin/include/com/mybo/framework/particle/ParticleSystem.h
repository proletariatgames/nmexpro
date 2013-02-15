#ifndef INCLUDED_com_mybo_framework_particle_ParticleSystem
#define INCLUDED_com_mybo_framework_particle_ParticleSystem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,particle,EmitterMode)
HX_DECLARE_CLASS4(com,mybo,framework,particle,GravityModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,Particle)
HX_DECLARE_CLASS4(com,mybo,framework,particle,ParticleSystem)
HX_DECLARE_CLASS4(com,mybo,framework,particle,RGBA)
HX_DECLARE_CLASS4(com,mybo,framework,particle,RadialModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,Vector)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace particle{


class ParticleSystem_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParticleSystem_obj OBJ_;
		ParticleSystem_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ParticleSystem_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ParticleSystem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleSystem"); }

		::nme::display::Sprite canvas; /* REM */ 
		bool active; /* REM */ 
		Array< ::com::mybo::framework::particle::Particle > particles; /* REM */ 
		Array< ::com::mybo::framework::particle::Particle > deadParticles; /* REM */ 
		double elapsed; /* REM */ 
		double startTime; /* REM */ 
		double updateTime; /* REM */ 
		::com::mybo::framework::particle::EmitterMode emitterMode; /* REM */ 
		::nme::display::BitmapData textureBitmapData; /* REM */ 
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
		bool allSameSize; /* REM */ 
		bool allRotationZero; /* REM */ 
		bool allSameColor; /* REM */ 
		double speed; /* REM */ 
		double speedVariance; /* REM */ 
		::com::mybo::framework::particle::Vector gravity; /* REM */ 
		double radialAcceleration; /* REM */ 
		double radialAccelVariance; /* REM */ 
		double tangentialAcceleration; /* REM */ 
		double tangentialAccelVariance; /* REM */ 
		double startRadius; /* REM */ 
		double startRadiusVariance; /* REM */ 
		double endRadius; /* REM */ 
		double endRadiusVariance; /* REM */ 
		double rotatePerSecond; /* REM */ 
		double rotatePerSecondVariance; /* REM */ 
		bool disableBlendMode; /* REM */ 
		virtual Void initWitdGravityData( ::com::mybo::framework::particle::GravityModeData data);
		Dynamic initWitdGravityData_dyn();

		virtual Void initWitdRadialData( ::com::mybo::framework::particle::RadialModeData data);
		Dynamic initWitdRadialData_dyn();

		virtual Void runSystem( );
		Dynamic runSystem_dyn();

		virtual Void stopSystem( );
		Dynamic stopSystem_dyn();

		virtual Void setSpeed( double speed,double variance);
		Dynamic setSpeed_dyn();

		virtual Void setTextureBitmapData( ::nme::display::BitmapData bd);
		Dynamic setTextureBitmapData_dyn();

		virtual Void setEmitterMode( ::com::mybo::framework::particle::EmitterMode mode);
		Dynamic setEmitterMode_dyn();

		virtual bool shouldGenerateParticle( );
		Dynamic shouldGenerateParticle_dyn();

		double particeNeedGenerate; /* REM */ 
		virtual Void generateParticle( double dt);
		Dynamic generateParticle_dyn();

		virtual Void initParticle( );
		Dynamic initParticle_dyn();

		double dt; /* REM */ 
		int index; /* REM */ 
		::com::mybo::framework::particle::Particle aParticle; /* REM */ 
		::com::mybo::framework::particle::Vector unit; /* REM */ 
		::com::mybo::framework::particle::Vector radialSpeed; /* REM */ 
		::com::mybo::framework::particle::Vector tangentialSpeed; /* REM */ 
		::com::mybo::framework::particle::Vector temp; /* REM */ 
		virtual Void update( ::nme::events::Event e);
		Dynamic update_dyn();

		int _i; /* REM */ 
		double size; /* REM */ 
		double rotation; /* REM */ 
		Array< double > vertices; /* REM */ 
		Array< double > uvdatas; /* REM */ 
		Array< int > indices; /* REM */ 
		Array< int > colors; /* REM */ 
		int abgr; /* REM */ 
		::com::mybo::framework::particle::Particle particle; /* REM */ 
		virtual Void draw( );
		Dynamic draw_dyn();

		virtual double random( );
		Dynamic random_dyn();

		virtual double autoScaleValue( double value);
		Dynamic autoScaleValue_dyn();

		static double sin45; /* REM */ 
		static double scale; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle

#endif /* INCLUDED_com_mybo_framework_particle_ParticleSystem */ 
