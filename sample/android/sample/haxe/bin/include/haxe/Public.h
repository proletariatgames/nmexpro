#ifndef INCLUDED_haxe_Public
#define INCLUDED_haxe_Public

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,Public)
namespace haxe{


class Public_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Public_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
};

#define DELEGATE_haxe_Public \


template<typename IMPL>
class Public_delegate_ : public Public_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Public_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_haxe_Public
};

} // end namespace haxe

#endif /* INCLUDED_haxe_Public */ 
