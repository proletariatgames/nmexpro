#ifndef INCLUDED_com_mybo_framework_interfaces_ISceneMotion
#define INCLUDED_com_mybo_framework_interfaces_ISceneMotion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,interfaces,ISceneMotion)
namespace com{
namespace mybo{
namespace framework{
namespace interfaces{


class ISceneMotion_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef ISceneMotion_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		virtual Void run( )=0;
		Dynamic run_dyn();
		virtual Void config( Dynamic args)=0;
		Dynamic config_dyn();
};

#define DELEGATE_com_mybo_framework_interfaces_ISceneMotion \
virtual Void run( ) { return mDelegate->run();}  \
virtual Dynamic run_dyn() { return mDelegate->run_dyn();}  \
virtual Void config( Dynamic args) { return mDelegate->config(args);}  \
virtual Dynamic config_dyn() { return mDelegate->config_dyn();}  \


template<typename IMPL>
class ISceneMotion_delegate_ : public ISceneMotion_obj
{
	protected:
		IMPL *mDelegate;
	public:
		ISceneMotion_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_com_mybo_framework_interfaces_ISceneMotion
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace interfaces

#endif /* INCLUDED_com_mybo_framework_interfaces_ISceneMotion */ 
