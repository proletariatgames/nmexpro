#ifndef INCLUDED_com_mybo_effects_StarUseParticle
#define INCLUDED_com_mybo_effects_StarUseParticle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,effects,StarUseParticle)
HX_DECLARE_CLASS4(com,mybo,framework,particle,GravityModeData)
HX_DECLARE_CLASS4(com,mybo,framework,particle,ParticleSystem)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace effects{


class StarUseParticle_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef StarUseParticle_obj OBJ_;
		StarUseParticle_obj();
		Void __construct(::nme::geom::Point pos);

	public:
		static hx::ObjectPtr< StarUseParticle_obj > __new(::nme::geom::Point pos);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StarUseParticle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("StarUseParticle"); }

		::com::mybo::framework::particle::ParticleSystem particle; /* REM */ 
		::nme::geom::Point position; /* REM */ 
		virtual Void run( );
		Dynamic run_dyn();

		virtual ::com::mybo::framework::particle::GravityModeData initBounceParticle( );
		Dynamic initBounceParticle_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace effects

#endif /* INCLUDED_com_mybo_effects_StarUseParticle */ 
