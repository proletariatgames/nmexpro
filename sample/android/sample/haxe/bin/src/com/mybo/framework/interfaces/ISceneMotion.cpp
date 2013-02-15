#include <hxcpp.h>

#ifndef INCLUDED_com_mybo_framework_interfaces_ISceneMotion
#include <com/mybo/framework/interfaces/ISceneMotion.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace interfaces{

HX_DEFINE_DYNAMIC_FUNC0(ISceneMotion_obj,run,)

HX_DEFINE_DYNAMIC_FUNC1(ISceneMotion_obj,config,)


Class ISceneMotion_obj::__mClass;

void ISceneMotion_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.interfaces.ISceneMotion"), hx::TCanCast< ISceneMotion_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace interfaces
