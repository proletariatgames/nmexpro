#ifndef INCLUDED_com_mybo_menuscene_MasterMenuScene
#define INCLUDED_com_mybo_menuscene_MasterMenuScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/mybo/framework/core/Scene.h>
HX_DECLARE_CLASS3(com,mybo,common,Background)
HX_DECLARE_CLASS3(com,mybo,common,ScaleEffectButton)
HX_DECLARE_CLASS3(com,mybo,data,UserData)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS4(com,mybo,framework,display,BitmapSimpleButton)
HX_DECLARE_CLASS3(com,mybo,menuscene,MasterMenuScene)
HX_DECLARE_CLASS3(com,mybo,menuscene,UserStar)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace menuscene{


class MasterMenuScene_obj : public ::com::mybo::framework::core::Scene_obj{
	public:
		typedef ::com::mybo::framework::core::Scene_obj super;
		typedef MasterMenuScene_obj OBJ_;
		MasterMenuScene_obj();
		Void __construct(Dynamic __o_masterWinBack);

	public:
		static hx::ObjectPtr< MasterMenuScene_obj > __new(Dynamic __o_masterWinBack);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MasterMenuScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MasterMenuScene"); }

		::com::mybo::common::Background background; /* REM */ 
		::com::mybo::common::ScaleEffectButton backBtn; /* REM */ 
		::nme::display::Sprite touchLayer; /* REM */ 
		::nmex::display::Bitmap chestBitmap; /* REM */ 
		::com::mybo::data::UserData userData; /* REM */ 
		bool hasUnlockedMap; /* REM */ 
		::com::mybo::menuscene::UserStar userStar; /* REM */ 
		virtual ::nme::display::Sprite drawMask( Dynamic alpha);
		Dynamic drawMask_dyn();

		virtual Void showRewardStar( );
		Dynamic showRewardStar_dyn();

		virtual Void unlockChest( ::nme::events::MouseEvent e);
		Dynamic unlockChest_dyn();

		virtual Void addTouchEvent( );
		Dynamic addTouchEvent_dyn();

		virtual Void runMaster( ::nme::events::MouseEvent e);
		Dynamic runMaster_dyn();

		virtual Void retry( );
		Dynamic retry_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void onBack( );
		Dynamic onBack_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_MasterMenuScene */ 
