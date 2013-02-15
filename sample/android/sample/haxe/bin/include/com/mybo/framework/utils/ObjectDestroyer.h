#ifndef INCLUDED_com_mybo_framework_utils_ObjectDestroyer
#define INCLUDED_com_mybo_framework_utils_ObjectDestroyer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,utils,ObjectDestroyer)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace utils{


class ObjectDestroyer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ObjectDestroyer_obj OBJ_;
		ObjectDestroyer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ObjectDestroyer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ObjectDestroyer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ObjectDestroyer"); }

		static Void destroyView( ::nme::display::DisplayObjectContainer a);
		static Dynamic destroyView_dyn();

		static Void destroyFields( Dynamic t);
		static Dynamic destroyFields_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace utils

#endif /* INCLUDED_com_mybo_framework_utils_ObjectDestroyer */ 
