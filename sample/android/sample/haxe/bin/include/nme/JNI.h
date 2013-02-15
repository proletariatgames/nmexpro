#ifndef INCLUDED_nme_JNI
#define INCLUDED_nme_JNI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS1(nme,JNI)
namespace nme{


class JNI_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef JNI_obj OBJ_;
		JNI_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< JNI_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~JNI_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("JNI"); }

		static ::Hash alreadyCreated; /* REM */ 
		static ::String base64; /* REM */ 
		static Dynamic createInterface( Dynamic haxeClass,::String className,::String classDef);
		static Dynamic createInterface_dyn();

		static Dynamic createMemberMethod( ::String className,::String memberName,::String signature,Dynamic useArray);
		static Dynamic createMemberMethod_dyn();

		static Dynamic createStaticMethod( ::String className,::String memberName,::String signature,Dynamic useArray);
		static Dynamic createStaticMethod_dyn();

		static Dynamic nme_jni_create_method; /* REM */ 
	Dynamic &nme_jni_create_method_dyn() { return nme_jni_create_method;}
		static Dynamic nme_jni_create_interface; /* REM */ 
	Dynamic &nme_jni_create_interface_dyn() { return nme_jni_create_interface;}
};

} // end namespace nme

#endif /* INCLUDED_nme_JNI */ 
