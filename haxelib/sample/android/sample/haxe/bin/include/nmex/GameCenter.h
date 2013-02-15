#ifndef INCLUDED_nmex_GameCenter
#define INCLUDED_nmex_GameCenter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nmex/NXObject.h>
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS1(nmex,GameCenter)
HX_DECLARE_CLASS1(nmex,NXObject)
namespace nmex{


class GameCenter_obj : public ::nmex::NXObject_obj{
	public:
		typedef ::nmex::NXObject_obj super;
		typedef GameCenter_obj OBJ_;
		GameCenter_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< GameCenter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GameCenter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameCenter"); }

		virtual Void authenticateLocalUser( );
		Dynamic authenticateLocalUser_dyn();

		virtual Void showAchievements( );
		Dynamic showAchievements_dyn();

		virtual Void showLeaderboardForCategory( ::String category);
		Dynamic showLeaderboardForCategory_dyn();

		virtual Void reportScoreForCategory( int score,::String category);
		Dynamic reportScoreForCategory_dyn();

		virtual Void reportAchievement( ::String achievementId);
		Dynamic reportAchievement_dyn();

		virtual Void resetAchievements( );
		Dynamic resetAchievements_dyn();

		static ::nmex::GameCenter instance; /* REM */ 
		static ::nmex::GameCenter getInstance( );
		static Dynamic getInstance_dyn();

		static Dynamic _showAchievements_func; /* REM */ 
		static Dynamic _showLeaderboardForCategory_func; /* REM */ 
		static Dynamic _reportScoreForCategory_func; /* REM */ 
		static Dynamic _reportAchievement_func; /* REM */ 
};

} // end namespace nmex

#endif /* INCLUDED_nmex_GameCenter */ 
