#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_utils_FileAction
#include <com/mybo/framework/utils/FileAction.h>
#endif
#ifndef INCLUDED_cpp_FileSystem
#include <cpp/FileSystem.h>
#endif
#ifndef INCLUDED_cpp_io_File
#include <cpp/io/File.h>
#endif
#ifndef INCLUDED_cpp_io_FileOutput
#include <cpp/io/FileOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace utils{

Void FileAction_obj::__construct()
{
	return null();
}

FileAction_obj::~FileAction_obj() { }

Dynamic FileAction_obj::__CreateEmpty() { return  new FileAction_obj; }
hx::ObjectPtr< FileAction_obj > FileAction_obj::__new()
{  hx::ObjectPtr< FileAction_obj > result = new FileAction_obj();
	result->__construct();
	return result;}

Dynamic FileAction_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileAction_obj > result = new FileAction_obj();
	result->__construct();
	return result;}

::String FileAction_obj::read( ::String path){
	HX_SOURCE_PUSH("FileAction_obj::read")
	HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/FileAction.hx",10)
	if ((::cpp::FileSystem_obj::exists(path))){
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/FileAction.hx",11)
		return ::cpp::io::File_obj::getContent(path);
	}
	else{
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/FileAction.hx",13)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileAction_obj,read,return )

Void FileAction_obj::write( ::String path,::String content){
{
		HX_SOURCE_PUSH("FileAction_obj::write")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/FileAction.hx",19)
		::cpp::io::FileOutput fileOut = ::cpp::io::File_obj::write(path,true);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/FileAction.hx",20)
		fileOut->writeString(content);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/utils/FileAction.hx",21)
		fileOut->close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FileAction_obj,write,(void))


FileAction_obj::FileAction_obj()
{
}

void FileAction_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileAction);
	HX_MARK_END_CLASS();
}

Dynamic FileAction_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FileAction_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FileAction_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("read"),
	HX_CSTRING("write"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FileAction_obj::__mClass;

void FileAction_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.utils.FileAction"), hx::TCanCast< FileAction_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FileAction_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace utils
