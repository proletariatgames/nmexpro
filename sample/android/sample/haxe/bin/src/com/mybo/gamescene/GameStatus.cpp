#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_gamescene_GameStatus
#include <com/mybo/gamescene/GameStatus.h>
#endif
namespace com{
namespace mybo{
namespace gamescene{

::com::mybo::gamescene::GameStatus GameStatus_obj::EXIT;

::com::mybo::gamescene::GameStatus GameStatus_obj::LEVELCOMPLETE;

::com::mybo::gamescene::GameStatus GameStatus_obj::OVER;

::com::mybo::gamescene::GameStatus GameStatus_obj::PAUSE;

::com::mybo::gamescene::GameStatus GameStatus_obj::READY;

::com::mybo::gamescene::GameStatus GameStatus_obj::RUNNING;

HX_DEFINE_CREATE_ENUM(GameStatus_obj)

int GameStatus_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("EXIT")) return 5;
	if (inName==HX_CSTRING("LEVELCOMPLETE")) return 3;
	if (inName==HX_CSTRING("OVER")) return 4;
	if (inName==HX_CSTRING("PAUSE")) return 2;
	if (inName==HX_CSTRING("READY")) return 0;
	if (inName==HX_CSTRING("RUNNING")) return 1;
	return super::__FindIndex(inName);
}

int GameStatus_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("EXIT")) return 0;
	if (inName==HX_CSTRING("LEVELCOMPLETE")) return 0;
	if (inName==HX_CSTRING("OVER")) return 0;
	if (inName==HX_CSTRING("PAUSE")) return 0;
	if (inName==HX_CSTRING("READY")) return 0;
	if (inName==HX_CSTRING("RUNNING")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GameStatus_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("EXIT")) return EXIT;
	if (inName==HX_CSTRING("LEVELCOMPLETE")) return LEVELCOMPLETE;
	if (inName==HX_CSTRING("OVER")) return OVER;
	if (inName==HX_CSTRING("PAUSE")) return PAUSE;
	if (inName==HX_CSTRING("READY")) return READY;
	if (inName==HX_CSTRING("RUNNING")) return RUNNING;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("READY"),
	HX_CSTRING("RUNNING"),
	HX_CSTRING("PAUSE"),
	HX_CSTRING("LEVELCOMPLETE"),
	HX_CSTRING("OVER"),
	HX_CSTRING("EXIT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameStatus_obj::EXIT,"EXIT");
	HX_MARK_MEMBER_NAME(GameStatus_obj::LEVELCOMPLETE,"LEVELCOMPLETE");
	HX_MARK_MEMBER_NAME(GameStatus_obj::OVER,"OVER");
	HX_MARK_MEMBER_NAME(GameStatus_obj::PAUSE,"PAUSE");
	HX_MARK_MEMBER_NAME(GameStatus_obj::READY,"READY");
	HX_MARK_MEMBER_NAME(GameStatus_obj::RUNNING,"RUNNING");
};

static ::String sMemberFields[] = { ::String(null()) };
Class GameStatus_obj::__mClass;

Dynamic __Create_GameStatus_obj() { return new GameStatus_obj; }

void GameStatus_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.GameStatus"), hx::TCanCast< GameStatus_obj >,sStaticFields,sMemberFields,
	&__Create_GameStatus_obj, &__Create,
	&super::__SGetClass(), &CreateGameStatus_obj, sMarkStatics);
}

void GameStatus_obj::__boot()
{
Static(EXIT) = hx::CreateEnum< GameStatus_obj >(HX_CSTRING("EXIT"),5);
Static(LEVELCOMPLETE) = hx::CreateEnum< GameStatus_obj >(HX_CSTRING("LEVELCOMPLETE"),3);
Static(OVER) = hx::CreateEnum< GameStatus_obj >(HX_CSTRING("OVER"),4);
Static(PAUSE) = hx::CreateEnum< GameStatus_obj >(HX_CSTRING("PAUSE"),2);
Static(READY) = hx::CreateEnum< GameStatus_obj >(HX_CSTRING("READY"),0);
Static(RUNNING) = hx::CreateEnum< GameStatus_obj >(HX_CSTRING("RUNNING"),1);
}


} // end namespace com
} // end namespace mybo
} // end namespace gamescene
