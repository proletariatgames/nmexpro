#ifndef INCLUDED_com_mybo_framework_sound_SoundType
#define INCLUDED_com_mybo_framework_sound_SoundType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,mybo,framework,sound,SoundType)
namespace com{
namespace mybo{
namespace framework{
namespace sound{


class SoundType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SoundType_obj OBJ_;

	public:
		SoundType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("com.mybo.framework.sound.SoundType"); }
		::String __ToString() const { return HX_CSTRING("SoundType.") + tag; }

		static ::com::mybo::framework::sound::SoundType MUSIC;
		static inline ::com::mybo::framework::sound::SoundType MUSIC_dyn() { return MUSIC; }
		static ::com::mybo::framework::sound::SoundType SFX;
		static inline ::com::mybo::framework::sound::SoundType SFX_dyn() { return SFX; }
};

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace sound

#endif /* INCLUDED_com_mybo_framework_sound_SoundType */ 
