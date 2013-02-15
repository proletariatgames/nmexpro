#ifndef INCLUDED_com_mybo_menuscene_PackageItem
#define INCLUDED_com_mybo_menuscene_PackageItem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS3(com,mybo,common,ProgressBar)
HX_DECLARE_CLASS3(com,mybo,menuscene,PackageItem)
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


class PackageItem_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef PackageItem_obj OBJ_;
		PackageItem_obj();
		Void __construct(int inIndex,bool locked,int completedLevels,int totalLevels);

	public:
		static hx::ObjectPtr< PackageItem_obj > __new(int inIndex,bool locked,int completedLevels,int totalLevels);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PackageItem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PackageItem"); }

		int index; /* REM */ 
		bool isLocked; /* REM */ 
		::com::mybo::common::ProgressBar progressBar; /* REM */ 
		virtual Void onClick( ::nme::events::MouseEvent e);
		Dynamic onClick_dyn();

		virtual Void initPercentNum( int completedLevels,int totalLevels);
		Dynamic initPercentNum_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace menuscene

#endif /* INCLUDED_com_mybo_menuscene_PackageItem */ 
