#ifndef INCLUDED_com_mybo_common_GameMode
#define INCLUDED_com_mybo_common_GameMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,common,GameMode)
namespace com{
namespace mybo{
namespace common{


class GameMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GameMode_obj OBJ_;

	public:
		GameMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("com.mybo.common.GameMode"); }
		::String __ToString() const { return HX_CSTRING("GameMode.") + tag; }

		static ::com::mybo::common::GameMode classic;
		static inline ::com::mybo::common::GameMode classic_dyn() { return classic; }
		static ::com::mybo::common::GameMode master;
		static inline ::com::mybo::common::GameMode master_dyn() { return master; }
		static ::com::mybo::common::GameMode puzzle;
		static inline ::com::mybo::common::GameMode puzzle_dyn() { return puzzle; }
};

} // end namespace com
} // end namespace mybo
} // end namespace common

#endif /* INCLUDED_com_mybo_common_GameMode */ 
