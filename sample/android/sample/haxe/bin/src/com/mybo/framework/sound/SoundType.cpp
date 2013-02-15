#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_sound_SoundType
#include <com/mybo/framework/sound/SoundType.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace sound{

::com::mybo::framework::sound::SoundType SoundType_obj::MUSIC;

::com::mybo::framework::sound::SoundType SoundType_obj::SFX;

HX_DEFINE_CREATE_ENUM(SoundType_obj)

int SoundType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("MUSIC")) return 1;
	if (inName==HX_CSTRING("SFX")) return 0;
	return super::__FindIndex(inName);
}

int SoundType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("MUSIC")) return 0;
	if (inName==HX_CSTRING("SFX")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic SoundType_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("MUSIC")) return MUSIC;
	if (inName==HX_CSTRING("SFX")) return SFX;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("SFX"),
	HX_CSTRING("MUSIC"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundType_obj::MUSIC,"MUSIC");
	HX_MARK_MEMBER_NAME(SoundType_obj::SFX,"SFX");
};

static ::String sMemberFields[] = { ::String(null()) };
Class SoundType_obj::__mClass;

Dynamic __Create_SoundType_obj() { return new SoundType_obj; }

void SoundType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.sound.SoundType"), hx::TCanCast< SoundType_obj >,sStaticFields,sMemberFields,
	&__Create_SoundType_obj, &__Create,
	&super::__SGetClass(), &CreateSoundType_obj, sMarkStatics);
}

void SoundType_obj::__boot()
{
Static(MUSIC) = hx::CreateEnum< SoundType_obj >(HX_CSTRING("MUSIC"),1);
Static(SFX) = hx::CreateEnum< SoundType_obj >(HX_CSTRING("SFX"),0);
}


} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound
