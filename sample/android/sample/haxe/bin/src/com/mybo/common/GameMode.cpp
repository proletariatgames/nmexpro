#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_common_GameMode
#include <com/mybo/common/GameMode.h>
#endif
namespace com{
namespace mybo{
namespace common{

::com::mybo::common::GameMode GameMode_obj::classic;

::com::mybo::common::GameMode GameMode_obj::master;

::com::mybo::common::GameMode GameMode_obj::puzzle;

HX_DEFINE_CREATE_ENUM(GameMode_obj)

int GameMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("classic")) return 0;
	if (inName==HX_CSTRING("master")) return 2;
	if (inName==HX_CSTRING("puzzle")) return 1;
	return super::__FindIndex(inName);
}

int GameMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("classic")) return 0;
	if (inName==HX_CSTRING("master")) return 0;
	if (inName==HX_CSTRING("puzzle")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GameMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("classic")) return classic;
	if (inName==HX_CSTRING("master")) return master;
	if (inName==HX_CSTRING("puzzle")) return puzzle;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("classic"),
	HX_CSTRING("puzzle"),
	HX_CSTRING("master"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameMode_obj::classic,"classic");
	HX_MARK_MEMBER_NAME(GameMode_obj::master,"master");
	HX_MARK_MEMBER_NAME(GameMode_obj::puzzle,"puzzle");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GameMode_obj::__mClass;

Dynamic __Create_GameMode_obj() { return new GameMode_obj; }

void GameMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.common.GameMode"), hx::TCanCast< GameMode_obj >,sStaticFields,sMemberFields,
	&__Create_GameMode_obj, &__Create,
	&super::__SGetClass(), &CreateGameMode_obj, sMarkStatics);
}

void GameMode_obj::__boot()
{
Static(classic) = hx::CreateEnum< GameMode_obj >(HX_CSTRING("classic"),0);
Static(master) = hx::CreateEnum< GameMode_obj >(HX_CSTRING("master"),2);
Static(puzzle) = hx::CreateEnum< GameMode_obj >(HX_CSTRING("puzzle"),1);
}


} // end namespace com
} // end namespace mybo
} // end namespace common
