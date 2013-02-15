#ifndef INCLUDED_com_mybo_effects_BurstParticle
#define INCLUDED_com_mybo_effects_BurstParticle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,effects,BurstParticle)
HX_DECLARE_CLASS4(com,mybo,framework,particle,GravityModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,ParticleSystem)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace effects{


class BurstParticle_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef BurstParticle_obj OBJ_;
		BurstParticle_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BurstParticle_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BurstParticle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BurstParticle"); }

		::com::mybo::framework::particle::ParticleSystem particle; /* REM */ 
		virtual Void run( );
		Dynamic run_dyn();

		virtual ::com::mybo::framework::particle::GravityModeData initBounceParticle( );
		Dynamic initBounceParticle_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace effects

#endif /* INCLUDED_com_mybo_effects_BurstParticle */ 
