#include <hxcpp.h>

#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
namespace haxe{


Class Public_obj::__mClass;

void Public_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Public"), hx::TCanCast< Public_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace haxe
