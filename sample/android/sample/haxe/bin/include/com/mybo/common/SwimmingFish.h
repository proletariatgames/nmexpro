#ifndef INCLUDED_com_mybo_common_SwimmingFish
#define INCLUDED_com_mybo_common_SwimmingFish

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,SwimmingFish)
HX_DECLARE_CLASS4(com,mybo,framework,particle,GravityModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,ParticleSystem)
HX_DECLARE_CLASS1(haxe,Timer)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace common{


class SwimmingFish_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef SwimmingFish_obj OBJ_;
		SwimmingFish_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SwimmingFish_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SwimmingFish_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SwimmingFish"); }

		::com::mybo::framework::particle::ParticleSystem smallFishLeft; /* REM */ 
		::com::mybo::framework::particle::ParticleSystem smallFishRight; /* REM */ 
		::com::mybo::framework::particle::ParticleSystem bigFishLeft; /* REM */ 
		::com::mybo::framework::particle::ParticleSystem bigFishRight; /* REM */ 
		::haxe::Timer delayTimer; /* REM */ 
		virtual ::com::mybo::framework::particle::GravityModeData initSmallLeftFishParticle( );
		Dynamic initSmallLeftFishParticle_dyn();

		virtual ::com::mybo::framework::particle::GravityModeData initSmallRightFishParticle( );
		Dynamic initSmallRightFishParticle_dyn();

		virtual ::com::mybo::framework::particle::GravityModeData initBigLeftFishParticle( );
		Dynamic initBigLeftFishParticle_dyn();

		virtual ::com::mybo::framework::particle::GravityModeData initBigRightFishParticle( );
		Dynamic initBigRightFishParticle_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void start( );
		Dynamic start_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_SwimmingFish */ 
