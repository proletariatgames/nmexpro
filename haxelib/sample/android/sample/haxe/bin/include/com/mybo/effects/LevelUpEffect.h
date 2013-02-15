#ifndef INCLUDED_com_mybo_effects_LevelUpEffect
#define INCLUDED_com_mybo_effects_LevelUpEffect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,effects,BubbleCell2)
HX_DECLARE_CLASS3(com,mybo,effects,LevelUpEffect)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace effects{


class LevelUpEffect_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef LevelUpEffect_obj OBJ_;
		LevelUpEffect_obj();
		Void __construct(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size);

	public:
		static hx::ObjectPtr< LevelUpEffect_obj > __new(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LevelUpEffect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("LevelUpEffect"); }

		Array< ::com::mybo::effects::BubbleCell2 > balls; /* REM */ 
		int length; /* REM */ 
		int staticLength; /* REM */ 
		::nme::display::Sprite view; /* REM */ 
		int time; /* REM */ 
		int staticTime; /* REM */ 
		double xx; /* REM */ 
		double yy; /* REM */ 
		double rate; /* REM */ 
		double delay; /* REM */ 
		double size; /* REM */ 
		::nme::display::Sprite levelup; /* REM */ 
		::nme::display::BitmapData bubbleTexture; /* REM */ 
		double radius; /* REM */ 
		virtual Void start( );
		Dynamic start_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void onEnterFrame( ::nme::events::Event e);
		Dynamic onEnterFrame_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace effects

#endif /* INCLUDED_com_mybo_effects_LevelUpEffect */ 
