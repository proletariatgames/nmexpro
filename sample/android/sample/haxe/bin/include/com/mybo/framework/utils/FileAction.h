#ifndef INCLUDED_com_mybo_framework_utils_FileAction
#define INCLUDED_com_mybo_framework_utils_FileAction

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,utils,FileAction)
namespace com{
namespace mybo{
namespace framework{
namespace utils{


class FileAction_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FileAction_obj OBJ_;
		FileAction_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FileAction_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileAction_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileAction"); }

		static ::String read( ::String path);
		static Dynamic read_dyn();

		static Void write( ::String path,::String content);
		static Dynamic write_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace utils

#endif /* INCLUDED_com_mybo_framework_utils_FileAction */ 
