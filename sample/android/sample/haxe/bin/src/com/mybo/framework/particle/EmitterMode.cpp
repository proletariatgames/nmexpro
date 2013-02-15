#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_particle_EmitterMode
#include <com/mybo/framework/particle/EmitterMode.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace particle{

::com::mybo::framework::particle::EmitterMode EmitterMode_obj::gravityMode;

::com::mybo::framework::particle::EmitterMode EmitterMode_obj::radialMode;

HX_DEFINE_CREATE_ENUM(EmitterMode_obj)

int EmitterMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("gravityMode")) return 0;
	if (inName==HX_CSTRING("radialMode")) return 1;
	return super::__FindIndex(inName);
}

int EmitterMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("gravityMode")) return 0;
	if (inName==HX_CSTRING("radialMode")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic EmitterMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("gravityMode")) return gravityMode;
	if (inName==HX_CSTRING("radialMode")) return radialMode;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("gravityMode"),
	HX_CSTRING("radialMode"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmitterMode_obj::gravityMode,"gravityMode");
	HX_MARK_MEMBER_NAME(EmitterMode_obj::radialMode,"radialMode");
};

static ::String sMemberFields[] = { ::String(null()) };
Class EmitterMode_obj::__mClass;

Dynamic __Create_EmitterMode_obj() { return new EmitterMode_obj; }

void EmitterMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.particle.EmitterMode"), hx::TCanCast< EmitterMode_obj >,sStaticFields,sMemberFields,
	&__Create_EmitterMode_obj, &__Create,
	&super::__SGetClass(), &CreateEmitterMode_obj, sMarkStatics);
}

void EmitterMode_obj::__boot()
{
Static(gravityMode) = hx::CreateEnum< EmitterMode_obj >(HX_CSTRING("gravityMode"),0);
Static(radialMode) = hx::CreateEnum< EmitterMode_obj >(HX_CSTRING("radialMode"),1);
}


} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace particle
