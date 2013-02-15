#ifndef INCLUDED_com_mybo_framework_resource_ResourceData
#define INCLUDED_com_mybo_framework_resource_ResourceData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,resource,ResourceData)
namespace com{
namespace mybo{
namespace framework{
namespace resource{


class ResourceData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ResourceData_obj OBJ_;
		ResourceData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ResourceData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ResourceData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ResourceData"); }

		Array< ::String > id; /* REM */ 
		Array< int > tileWidth; /* REM */ 
		Array< int > tileHeight; /* REM */ 
		Array< int > cols; /* REM */ 
		Array< int > frameNumber; /* REM */ 
		Array< ::String > folder; /* REM */ 
		Array< bool > optimized; /* REM */ 
		Array< int > scale; /* REM */ 
		Array< Array< ::String > > url; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace resource

#endif /* INCLUDED_com_mybo_framework_resource_ResourceData */ 
