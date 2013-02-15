#ifndef INCLUDED_com_mybo_framework_core_Facade
#define INCLUDED_com_mybo_framework_core_Facade

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS4(com,mybo,framework,core,Controller)
HX_DECLARE_CLASS4(com,mybo,framework,core,Facade)
HX_DECLARE_CLASS4(com,mybo,framework,core,Scene)
HX_DECLARE_CLASS4(com,mybo,framework,core,View)
HX_DECLARE_CLASS4(com,mybo,framework,interfaces,ISceneMotion)
HX_DECLARE_CLASS4(com,mybo,framework,resource,BitmapTile)
HX_DECLARE_CLASS4(com,mybo,framework,resource,Resource)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nmex,display,Bitmap)
HX_DECLARE_CLASS2(nmex,display,DisplayObject)
namespace com{
namespace mybo{
namespace framework{
namespace core{


class Facade_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Facade_obj OBJ_;
		Facade_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Facade_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Facade_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Facade"); }

		::nme::display::Stage stage; /* REM */ 
		::com::mybo::framework::core::View view; /* REM */ 
		::com::mybo::framework::core::Controller controller; /* REM */ 
		double startTime; /* REM */ 
		::com::mybo::framework::resource::Resource resource; /* REM */ 
		::Hash shareObjects; /* REM */ 
		virtual Void showFps( );
		Dynamic showFps_dyn();

		virtual Dynamic getShareObject( ::String name);
		Dynamic getShareObject_dyn();

		virtual Void setShareObject( ::String name,Dynamic obj);
		Dynamic setShareObject_dyn();

		virtual Void run( ::Class classRef,Dynamic params);
		Dynamic run_dyn();

		virtual Void noRouteRun( ::Class classRef,Dynamic params);
		Dynamic noRouteRun_dyn();

		virtual Void back( );
		Dynamic back_dyn();

		virtual ::com::mybo::framework::core::Controller getController( );
		Dynamic getController_dyn();

		virtual Void initResource( ::String resourcePath,::String xmlFilePath);
		Dynamic initResource_dyn();

		virtual ::nmex::display::Bitmap getBitmap( ::String id,Dynamic smooth);
		Dynamic getBitmap_dyn();

		virtual ::com::mybo::framework::resource::BitmapTile getTile( ::String id);
		Dynamic getTile_dyn();

		virtual Void destroyResource( ::String id);
		Dynamic destroyResource_dyn();

		virtual Void loadResourceByFolder( ::String folderName);
		Dynamic loadResourceByFolder_dyn();

		virtual Void unLoadResourceByFolder( ::String folderName);
		Dynamic unLoadResourceByFolder_dyn();

		virtual Void unLoadAllResource( );
		Dynamic unLoadAllResource_dyn();

		virtual Void loadAllResource( );
		Dynamic loadAllResource_dyn();

		virtual Void setPageMotion( ::Class motionRef);
		Dynamic setPageMotion_dyn();

		virtual ::nme::display::Stage getStage( );
		Dynamic getStage_dyn();

		virtual Void initStage( ::nme::display::Stage stage);
		Dynamic initStage_dyn();

		virtual ::com::mybo::framework::core::View getView( );
		Dynamic getView_dyn();

		virtual double getStageWidthInPoint( );
		Dynamic getStageWidthInPoint_dyn();

		virtual double getStageHeightInPoint( );
		Dynamic getStageHeightInPoint_dyn();

		virtual Void enable( );
		Dynamic enable_dyn();

		virtual Void disable( );
		Dynamic disable_dyn();

		static ::com::mybo::framework::core::Facade instance; /* REM */ 
		static double contentScaleFactor; /* REM */ 
		static ::com::mybo::framework::core::Facade getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core

#endif /* INCLUDED_com_mybo_framework_core_Facade */ 
