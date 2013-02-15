#ifndef INCLUDED_com_mybo_framework_sound_SoundObject
#define INCLUDED_com_mybo_framework_sound_SoundObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundObject)
HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundType)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,media,Sound)
HX_DECLARE_CLASS2(nme,media,SoundChannel)
namespace com{
namespace mybo{
namespace framework{
namespace sound{


class SoundObject_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SoundObject_obj OBJ_;
		SoundObject_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SoundObject_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundObject"); }

		::String name; /* REM */ 
		::String fileURL; /* REM */ 
		::nme::media::SoundChannel channel; /* REM */ 
		::nme::media::Sound sound; /* REM */ 
		::com::mybo::framework::sound::SoundType type; /* REM */ 
		bool didLoad; /* REM */ 
		virtual Void load( );
		Dynamic load_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound

#endif /* INCLUDED_com_mybo_framework_sound_SoundObject */ 
