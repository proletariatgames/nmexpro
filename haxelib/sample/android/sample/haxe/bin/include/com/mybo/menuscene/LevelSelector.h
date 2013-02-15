#ifndef INCLUDED_com_mybo_menuscene_LevelSelector
#define INCLUDED_com_mybo_menuscene_LevelSelector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,menuscene,LevelSelector)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace menuscene{


class LevelSelector_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef LevelSelector_obj OBJ_;
		LevelSelector_obj();
		Void __construct(int inPackID);

	public:
		static hx::ObjectPtr< LevelSelector_obj > __new(int inPackID);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LevelSelector_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("LevelSelector"); }

		int packID; /* REM */ 
		int maxItem; /* REM */ 
		int completedItem; /* REM */ 
		virtual Void onItemClick( ::nme::events::MouseEvent e);
		Dynamic onItemClick_dyn();

		static int MAX_LINE_ITEM; /* REM */ 
		static int ITEM_SPACE_WIDTH; /* REM */ 
		static int ITEM_SPACE_HEIGHT; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_LevelSelector */ 
