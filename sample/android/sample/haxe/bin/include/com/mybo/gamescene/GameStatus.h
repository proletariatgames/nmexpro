#ifndef INCLUDED_com_mybo_gamescene_GameStatus
#define INCLUDED_com_mybo_gamescene_GameStatus

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,gamescene,GameStatus)
namespace com{
namespace mybo{
namespace gamescene{


class GameStatus_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GameStatus_obj OBJ_;

	public:
		GameStatus_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("com.mybo.gamescene.GameStatus"); }
		::String __ToString() const { return HX_CSTRING("GameStatus.") + tag; }

		static ::com::mybo::gamescene::GameStatus EXIT;
		static inline ::com::mybo::gamescene::GameStatus EXIT_dyn() { return EXIT; }
		static ::com::mybo::gamescene::GameStatus LEVELCOMPLETE;
		static inline ::com::mybo::gamescene::GameStatus LEVELCOMPLETE_dyn() { return LEVELCOMPLETE; }
		static ::com::mybo::gamescene::GameStatus OVER;
		static inline ::com::mybo::gamescene::GameStatus OVER_dyn() { return OVER; }
		static ::com::mybo::gamescene::GameStatus PAUSE;
		static inline ::com::mybo::gamescene::GameStatus PAUSE_dyn() { return PAUSE; }
		static ::com::mybo::gamescene::GameStatus READY;
		static inline ::com::mybo::gamescene::GameStatus READY_dyn() { return READY; }
		static ::com::mybo::gamescene::GameStatus RUNNING;
		static inline ::com::mybo::gamescene::GameStatus RUNNING_dyn() { return RUNNING; }
};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_GameStatus */ 
