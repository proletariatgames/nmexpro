#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_effects_ScaleButton
#include <com/mybo/effects/ScaleButton.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapMovieClip
#include <com/mybo/framework/display/BitmapMovieClip.h>
#endif
#ifndef INCLUDED_com_mybo_framework_display_BitmapObject
#include <com/mybo/framework/display/BitmapObject.h>
#endif
#ifndef INCLUDED_com_mybo_framework_resource_BitmapTile
#include <com/mybo/framework/resource/BitmapTile.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_Bubble
#include <com/mybo/gamescene/Bubble.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nmex_display_Bitmap
#include <nmex/display/Bitmap.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nmex_display_Graphics
#include <nmex/display/Graphics.h>
#endif
namespace com{
namespace mybo{
namespace gamescene{

Void Bubble_obj::__construct(::nme::geom::Point inPos,int inSize,::String inTextureID)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",32)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",33)
	this->position = inPos;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",34)
	this->size = inSize;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",35)
	this->textureID = inTextureID;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",36)
	this->blasted = false;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",38)
	if (((inSize == (int)0))){
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",38)
		return null();
	}
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",40)
	this->bubbleMC = ::com::mybo::effects::ScaleButton_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap((this->textureID + inSize),true),(int)53,(int)53,null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",41)
	this->bubbleMC->nmeSetMouseEnabled(false);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",43)
	this->addChild(this->bubbleMC);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",44)
	this->bubbleMC->nmeSetX((int)2);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",45)
	this->bubbleMC->nmeSetY((int)3);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",47)
	this->blastMC = ::com::mybo::framework::display::BitmapMovieClip_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getTile(HX_CSTRING("blast")),null());
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",48)
	this->blastMC->stop();
}
;
	return null();
}

Bubble_obj::~Bubble_obj() { }

Dynamic Bubble_obj::__CreateEmpty() { return  new Bubble_obj; }
hx::ObjectPtr< Bubble_obj > Bubble_obj::__new(::nme::geom::Point inPos,int inSize,::String inTextureID)
{  hx::ObjectPtr< Bubble_obj > result = new Bubble_obj();
	result->__construct(inPos,inSize,inTextureID);
	return result;}

Dynamic Bubble_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bubble_obj > result = new Bubble_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Bubble_obj::grow( ){
{
		HX_SOURCE_PUSH("Bubble_obj::grow")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",53)
		hx::AddEq(this->size,(int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",55)
		this->bubbleMC->destroy();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",57)
		if (((null() != this->transformMC))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",57)
			this->transformMC->destroy();
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",59)
		if ((((int)4 < this->size))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",60)
			this->blasted = true;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",61)
			this->size = (int)0;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",62)
			this->nmeGetGraphics()->clear();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",64)
			this->blastMC->stop();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",65)
			this->addChild(this->blastMC);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",66)
			this->blastMC->nmeSetX((int)-20);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",67)
			this->blastMC->nmeSetY((int)-20);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",68)
			this->blastMC->isLoop = false;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",69)
			this->blastMC->onComplete(this->blastMC->destroy_dyn(),null(),null());
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",71)
			this->blastMC->play();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",73)
			double time = ::haxe::Timer_obj::stamp();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",75)
			if ((((time - ::com::mybo::gamescene::Bubble_obj::growSoundPlayTime) > 0.2))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",76)
				::com::mybo::gamescene::Bubble_obj::growSoundPlayTime = time;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",77)
				::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play((HX_CSTRING("bubble") + ::Std_obj::_int(((::Math_obj::random() * (int)5) + (int)1))),null(),null());
			}
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",87)
			this->bubbleMC = ::com::mybo::effects::ScaleButton_obj::__new(::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap((this->textureID + this->size),true),(int)53,(int)53,(int)0,(int)0,0.13,null(),true);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",89)
			this->addChild(this->bubbleMC);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",90)
			this->bubbleMC->nmeSetX((int)2);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",91)
			this->bubbleMC->nmeSetY((int)3);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",94)
			::String soundID = HX_CSTRING("");
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",95)
			if (((bool((this->size == (int)2)) || bool((this->size == (int)3))))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",95)
				soundID = (HX_CSTRING("grow") + ::Std_obj::_int((this->size - (int)1)));
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",97)
				soundID = (  (((::Math_obj::random() > 0.5))) ? ::String(HX_CSTRING("grow3")) : ::String(HX_CSTRING("grow4")) );
			}
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",101)
			double time = ::haxe::Timer_obj::stamp();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",102)
			if ((((time - ::com::mybo::gamescene::Bubble_obj::blastSoundPlayTime) > 0.01))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",103)
				::com::mybo::gamescene::Bubble_obj::blastSoundPlayTime = time;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",104)
				::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(soundID,null(),null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bubble_obj,grow,(void))

Void Bubble_obj::destroy( ){
{
		HX_SOURCE_PUSH("Bubble_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",109)
		if (((this->bubbleMC != null()))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/Bubble.hx",110)
			this->bubbleMC->destroy();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Bubble_obj,destroy,(void))

int Bubble_obj::maxSize;

int Bubble_obj::maxRadius;

double Bubble_obj::growSoundPlayTime;

double Bubble_obj::blastSoundPlayTime;


Bubble_obj::Bubble_obj()
{
}

void Bubble_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bubble);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(blasted,"blasted");
	HX_MARK_MEMBER_NAME(bubbleMC,"bubbleMC");
	HX_MARK_MEMBER_NAME(transformMC,"transformMC");
	HX_MARK_MEMBER_NAME(blastMC,"blastMC");
	HX_MARK_MEMBER_NAME(textureID,"textureID");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Bubble_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		if (HX_FIELD_EQ(inName,"grow") ) { return grow_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxSize") ) { return maxSize; }
		if (HX_FIELD_EQ(inName,"blasted") ) { return blasted; }
		if (HX_FIELD_EQ(inName,"blastMC") ) { return blastMC; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"bubbleMC") ) { return bubbleMC; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxRadius") ) { return maxRadius; }
		if (HX_FIELD_EQ(inName,"textureID") ) { return textureID; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"transformMC") ) { return transformMC; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"growSoundPlayTime") ) { return growSoundPlayTime; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"blastSoundPlayTime") ) { return blastSoundPlayTime; }
	}
	return super::__Field(inName);
}

Dynamic Bubble_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"maxSize") ) { maxSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blasted") ) { blasted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blastMC") ) { blastMC=inValue.Cast< ::com::mybo::framework::display::BitmapMovieClip >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bubbleMC") ) { bubbleMC=inValue.Cast< ::com::mybo::effects::ScaleButton >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxRadius") ) { maxRadius=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textureID") ) { textureID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"transformMC") ) { transformMC=inValue.Cast< ::com::mybo::framework::display::BitmapMovieClip >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"growSoundPlayTime") ) { growSoundPlayTime=inValue.Cast< double >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"blastSoundPlayTime") ) { blastSoundPlayTime=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Bubble_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("blasted"));
	outFields->push(HX_CSTRING("bubbleMC"));
	outFields->push(HX_CSTRING("transformMC"));
	outFields->push(HX_CSTRING("blastMC"));
	outFields->push(HX_CSTRING("textureID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("maxSize"),
	HX_CSTRING("maxRadius"),
	HX_CSTRING("growSoundPlayTime"),
	HX_CSTRING("blastSoundPlayTime"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("position"),
	HX_CSTRING("size"),
	HX_CSTRING("blasted"),
	HX_CSTRING("bubbleMC"),
	HX_CSTRING("transformMC"),
	HX_CSTRING("blastMC"),
	HX_CSTRING("textureID"),
	HX_CSTRING("grow"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bubble_obj::maxSize,"maxSize");
	HX_MARK_MEMBER_NAME(Bubble_obj::maxRadius,"maxRadius");
	HX_MARK_MEMBER_NAME(Bubble_obj::growSoundPlayTime,"growSoundPlayTime");
	HX_MARK_MEMBER_NAME(Bubble_obj::blastSoundPlayTime,"blastSoundPlayTime");
};

Class Bubble_obj::__mClass;

void Bubble_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.Bubble"), hx::TCanCast< Bubble_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bubble_obj::__boot()
{
	hx::Static(maxSize) = (int)4;
	hx::Static(maxRadius) = (int)30;
	hx::Static(growSoundPlayTime) = (int)0;
	hx::Static(blastSoundPlayTime) = (int)0;
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
