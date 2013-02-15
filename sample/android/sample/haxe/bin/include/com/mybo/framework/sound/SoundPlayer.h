#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#define INCLUDED_com_mybo_framework_sound_SoundPlayer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundObject)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundPlayer)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundQueue)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundType)
namespace com{
namespace mybo{
namespace framework{
namespace sound{


class SoundPlayer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SoundPlayer_obj OBJ_;
		SoundPlayer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SoundPlayer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundPlayer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundPlayer"); }

		::com::mybo::framework::sound::SoundQueue soundQueue; /* REM */ 
		bool SFXAble; /* REM */ 
		bool musicAble; /* REM */ 
		::com::mybo::framework::sound::SoundObject currentMusic; /* REM */ 
		virtual Void play( ::String name,Dynamic startPos,Dynamic loops);
		Dynamic play_dyn();

		virtual Void addSound( ::String name,::String fileURL,::com::mybo::framework::sound::SoundType type);
		Dynamic addSound_dyn();

		virtual Void stop( ::String name);
		Dynamic stop_dyn();

		virtual Void stopByType( ::com::mybo::framework::sound::SoundType type);
		Dynamic stopByType_dyn();

		virtual Void stopAll( );
		Dynamic stopAll_dyn();

		virtual Void enableMusic( );
		Dynamic enableMusic_dyn();

		virtual Void disableMusic( );
		Dynamic disableMusic_dyn();

		virtual Void enableSFX( );
		Dynamic enableSFX_dyn();

		virtual Void disableSFX( );
		Dynamic disableSFX_dyn();

		virtual Void loadByName( ::String name);
		Dynamic loadByName_dyn();

		virtual Void loadByType( ::com::mybo::framework::sound::SoundType type);
		Dynamic loadByType_dyn();

		virtual Void loadAll( );
		Dynamic loadAll_dyn();

		virtual Void unloadByName( ::String name);
		Dynamic unloadByName_dyn();

		virtual Void unloadByType( ::com::mybo::framework::sound::SoundType type);
		Dynamic unloadByType_dyn();

		virtual Void unloadAll( );
		Dynamic unloadAll_dyn();

		virtual Void remove( ::String name);
		Dynamic remove_dyn();

		virtual Void removeAll( );
		Dynamic removeAll_dyn();

		static ::com::mybo::framework::sound::SoundPlayer instance; /* REM */ 
		static ::com::mybo::framework::sound::SoundPlayer getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound

#endif /* INCLUDED_com_mybo_framework_sound_SoundPlayer */ 
