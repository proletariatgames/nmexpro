#ifndef INCLUDED_nmex_Device
#define INCLUDED_nmex_Device

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nmex,Device)
namespace nmex{


class Device_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Device_obj OBJ_;
		Device_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Device_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Device_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Device"); }

		static int contentScaleFactor; /* REM */ 
		static bool forceRetina; /* REM */ 
		static ::String uniqueId( );
		static Dynamic uniqueId_dyn();

		static ::String osName( );
		static Dynamic osName_dyn();

		static ::String osVersion( );
		static Dynamic osVersion_dyn();

		static ::String deviceName( );
		static Dynamic deviceName_dyn();

		static ::String model( );
		static Dynamic model_dyn();

		static bool networkAvailable( );
		static Dynamic networkAvailable_dyn();

		static Void vibrate( double time);
		static Dynamic vibrate_dyn();

		static bool isRetina( );
		static Dynamic isRetina_dyn();

		static double scaleFactor( );
		static Dynamic scaleFactor_dyn();

		static ::String getDocPath( );
		static Dynamic getDocPath_dyn();

		static ::String getRecPath( );
		static Dynamic getRecPath_dyn();

};

} // end namespace nmex

#endif /* INCLUDED_nmex_Device */ 
