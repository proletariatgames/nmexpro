#ifndef INCLUDED_com_mybo_gamescene_Bubble
#define INCLUDED_com_mybo_gamescene_Bubble

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,effects,ScaleButton)
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapMovieClip)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS3(com,mybo,gamescene,Bubble)
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
namespace gamescene{


class Bubble_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef Bubble_obj OBJ_;
		Bubble_obj();
		Void __construct(::nme::geom::Point inPos,int inSize,::String inTextureID);

	public:
		static hx::ObjectPtr< Bubble_obj > __new(::nme::geom::Point inPos,int inSize,::String inTextureID);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bubble_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bubble"); }

		::nme::geom::Point position; /* REM */ 
		int size; /* REM */ 
		bool blasted; /* REM */ 
		::com::mybo::effects::ScaleButton bubbleMC; /* REM */ 
		::com::mybo::framework::display::BitmapMovieClip transformMC; /* REM */ 
		::com::mybo::framework::display::BitmapMovieClip blastMC; /* REM */ 
		::String textureID; /* REM */ 
		virtual Void grow( );
		Dynamic grow_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		static int maxSize; /* REM */ 
		static int maxRadius; /* REM */ 
		static double growSoundPlayTime; /* REM */ 
		static double blastSoundPlayTime; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_Bubble */ 
