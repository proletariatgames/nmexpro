#ifndef INCLUDED_com_mybo_framework_sound_SoundQueue
#define INCLUDED_com_mybo_framework_sound_SoundQueue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundObject)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundQueue)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundType)
namespace com{
namespace mybo{
namespace framework{
namespace sound{


class SoundQueue_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SoundQueue_obj OBJ_;
		SoundQueue_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SoundQueue_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundQueue_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundQueue"); }

		::Hash sounds; /* REM */ 
		virtual Void add( ::String name,::String fileURL,::com::mybo::framework::sound::SoundType type);
		Dynamic add_dyn();

		virtual ::com::mybo::framework::sound::SoundObject getSoundObject( ::String name);
		Dynamic getSoundObject_dyn();

		virtual Void stop( ::String name);
		Dynamic stop_dyn();

		virtual Void stopByType( ::com::mybo::framework::sound::SoundType type);
		Dynamic stopByType_dyn();

		virtual Void stopAll( );
		Dynamic stopAll_dyn();

		virtual Void loadByName( ::String name);
		Dynamic loadByName_dyn();

		virtual Void loadByType( ::com::mybo::framework::sound::SoundType type);
		Dynamic loadByType_dyn();

		virtual Void loadAll( );
		Dynamic loadAll_dyn();

		virtual Void remove( ::String name);
		Dynamic remove_dyn();

		virtual Void removeAll( );
		Dynamic removeAll_dyn();

		virtual Void unloadByName( ::String name);
		Dynamic unloadByName_dyn();

		virtual Void unloadByType( ::com::mybo::framework::sound::SoundType type);
		Dynamic unloadByType_dyn();

		virtual Void unloadAll( );
		Dynamic unloadAll_dyn();

		virtual bool hasSound( ::String name);
		Dynamic hasSound_dyn();

		virtual Void stopSound( ::com::mybo::framework::sound::SoundObject soundObj);
		Dynamic stopSound_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound

#endif /* INCLUDED_com_mybo_framework_sound_SoundQueue */ 
