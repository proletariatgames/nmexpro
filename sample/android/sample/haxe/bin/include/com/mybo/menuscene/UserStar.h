#ifndef INCLUDED_com_mybo_menuscene_UserStar
#define INCLUDED_com_mybo_menuscene_UserStar

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS4(com,mybo,framework,core,TimerRender)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapNumber)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapObject)
HX_DECLARE_CLASS3(com,mybo,menuscene,UserStar)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace menuscene{


class UserStar_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef UserStar_obj OBJ_;
		UserStar_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< UserStar_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UserStar_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("UserStar"); }

		::com::mybo::framework::display::BitmapNumber starNum; /* REM */ 
		virtual Void update( );
		Dynamic update_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_UserStar */ 
