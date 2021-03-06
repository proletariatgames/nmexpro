#ifndef INCLUDED_nme_display_DisplayObjectContainer
#define INCLUDED_nme_display_DisplayObjectContainer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/InteractiveObject.h>
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace nme{
namespace display{


class DisplayObjectContainer_obj : public ::nme::display::InteractiveObject_obj{
	public:
		typedef ::nme::display::InteractiveObject_obj super;
		typedef DisplayObjectContainer_obj OBJ_;
		DisplayObjectContainer_obj();
		Void __construct(Dynamic inHandle,::String inType);

	public:
		static hx::ObjectPtr< DisplayObjectContainer_obj > __new(Dynamic inHandle,::String inType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DisplayObjectContainer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("DisplayObjectContainer"); }

		bool mouseChildren; /* REM */ 
		int numChildren; /* REM */ 
		bool tabChildren; /* REM */ 
		Array< ::nmex::display::DisplayObject > nmeChildren; /* REM */ 
		virtual ::nmex::display::DisplayObject addChild( ::nmex::display::DisplayObject child);
		Dynamic addChild_dyn();

		virtual ::nmex::display::DisplayObject addChildAt( ::nmex::display::DisplayObject child,int index);
		Dynamic addChildAt_dyn();

		virtual bool areInaccessibleObjectsUnderPoint( ::nme::geom::Point point);
		Dynamic areInaccessibleObjectsUnderPoint_dyn();

		virtual bool contains( ::nmex::display::DisplayObject child);
		Dynamic contains_dyn();

		virtual ::nmex::display::DisplayObject getChildAt( int index);
		Dynamic getChildAt_dyn();

		virtual ::nmex::display::DisplayObject getChildByName( ::String name);
		Dynamic getChildByName_dyn();

		virtual int getChildIndex( ::nmex::display::DisplayObject child);
		Dynamic getChildIndex_dyn();

		virtual Array< ::nmex::display::DisplayObject > getObjectsUnderPoint( ::nme::geom::Point point);
		Dynamic getObjectsUnderPoint_dyn();

		virtual Void nmeBroadcast( ::nme::events::Event inEvt);
		Dynamic nmeBroadcast_dyn();

		virtual ::nmex::display::DisplayObject nmeFindByID( int inID);
		Dynamic nmeFindByID_dyn();

		virtual Void nmeGetObjectsUnderPoint( ::nme::geom::Point point,Array< ::nmex::display::DisplayObject > result);
		Dynamic nmeGetObjectsUnderPoint_dyn();

		virtual Void nmeOnAdded( ::nmex::display::DisplayObject inObj,bool inIsOnStage);
		Dynamic nmeOnAdded_dyn();

		virtual Void nmeOnRemoved( ::nmex::display::DisplayObject inObj,bool inWasOnStage);
		Dynamic nmeOnRemoved_dyn();

		virtual Void nmeRemoveChildFromArray( ::nmex::display::DisplayObject child);
		Dynamic nmeRemoveChildFromArray_dyn();

		virtual ::nmex::display::DisplayObject removeChild( ::nmex::display::DisplayObject child);
		Dynamic removeChild_dyn();

		virtual ::nmex::display::DisplayObject removeChildAt( int index);
		Dynamic removeChildAt_dyn();

		virtual Void setChildIndex( ::nmex::display::DisplayObject child,int index);
		Dynamic setChildIndex_dyn();

		virtual Void swapChildren( ::nmex::display::DisplayObject child1,::nmex::display::DisplayObject child2);
		Dynamic swapChildren_dyn();

		virtual Void swapChildrenAt( int index1,int index2);
		Dynamic swapChildrenAt_dyn();

		virtual bool nmeGetMouseChildren( );
		Dynamic nmeGetMouseChildren_dyn();

		virtual bool nmeSetMouseChildren( bool inVal);
		Dynamic nmeSetMouseChildren_dyn();

		virtual int nmeGetNumChildren( );
		Dynamic nmeGetNumChildren_dyn();

		virtual bool nmeGetTabChildren( );
		Dynamic nmeGetTabChildren_dyn();

		virtual bool nmeSetTabChildren( bool inValue);
		Dynamic nmeSetTabChildren_dyn();

		static Dynamic nme_create_display_object_container; /* REM */ 
	Dynamic &nme_create_display_object_container_dyn() { return nme_create_display_object_container;}
		static Dynamic nme_doc_add_child; /* REM */ 
	Dynamic &nme_doc_add_child_dyn() { return nme_doc_add_child;}
		static Dynamic nme_doc_remove_child; /* REM */ 
	Dynamic &nme_doc_remove_child_dyn() { return nme_doc_remove_child;}
		static Dynamic nme_doc_set_child_index; /* REM */ 
	Dynamic &nme_doc_set_child_index_dyn() { return nme_doc_set_child_index;}
		static Dynamic nme_doc_get_mouse_children; /* REM */ 
	Dynamic &nme_doc_get_mouse_children_dyn() { return nme_doc_get_mouse_children;}
		static Dynamic nme_doc_set_mouse_children; /* REM */ 
	Dynamic &nme_doc_set_mouse_children_dyn() { return nme_doc_set_mouse_children;}
		static Dynamic nme_doc_swap_children; /* REM */ 
	Dynamic &nme_doc_swap_children_dyn() { return nme_doc_swap_children;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_DisplayObjectContainer */ 
