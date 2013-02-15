#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_effects_BubbleCell2
#include <com/mybo/effects/BubbleCell2.h>
#endif
#ifndef INCLUDED_com_mybo_effects_LevelUpEffect
#include <com/mybo/effects/LevelUpEffect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
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
#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
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
namespace effects{

Void LevelUpEffect_obj::__construct(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",35)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",36)
	this->staticLength = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",37)
	this->staticTime = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",38)
	this->view = _view;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",39)
	this->balls = Array_obj< ::com::mybo::effects::BubbleCell2 >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",41)
	this->view->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",43)
	this->xx = x;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",44)
	this->yy = y;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",46)
	this->rate = rate;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",47)
	this->delay = delay;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",48)
	this->size = size;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",50)
	this->length = n;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",51)
	if (((this->staticLength == (int)0))){
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",52)
		this->staticLength = n;
	}
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",54)
	this->time = t;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",55)
	if (((this->staticTime == (int)0))){
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",56)
		this->staticTime = t;
	}
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",59)
	this->levelup = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",60)
	::nme::display::BitmapData texture = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("level_fish_03"),null())->bitmapData;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",61)
	double w = texture->nmeGetWidth();
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",62)
	double h = texture->nmeGetHeight();
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",64)
	Array< double > vertices = Array_obj< double >::__new().Add((int)0).Add((int)0).Add(w).Add((int)0).Add(w).Add(h).Add((int)0).Add(h);
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",65)
	Array< double > uvdatas = Array_obj< double >::__new().Add(0.0).Add((int)0).Add((int)1).Add((int)0).Add((int)1).Add((int)1).Add((int)0).Add((int)1);
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",66)
	Array< int > indices = Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3);
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",68)
	this->levelup->nmeGetGraphics()->beginBitmapFill(texture,null(),null(),null());
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",69)
	this->levelup->nmeGetGraphics()->drawTriangles(vertices,indices,uvdatas,::nme::display::TriangleCulling_obj::NONE_dyn(),null(),(int)9,null());
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",71)
	::nmex::display::Bitmap levelupTitle = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("level3"),null());
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",72)
	levelupTitle->nmeSetX((int)50);
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",73)
	levelupTitle->nmeSetY((int)390);
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",74)
	this->levelup->addChild(levelupTitle);
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",76)
	this->levelup->nmeSetX(((double(::com::mybo::framework::core::Facade_obj::getInstance()->getStageWidthInPoint()) / double((int)2)) - (double(this->levelup->nmeGetWidth()) / double((int)2))));
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",77)
	this->levelup->nmeSetY(::com::mybo::framework::core::Facade_obj::getInstance()->getStageHeightInPoint());
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",78)
	this->view->addChild(this->levelup);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , (int)-500,false);
			return __result;
		}
	};
	struct _Function_1_2{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.5,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",80)
	::com::mybo::framework::tweener::MTween_obj::to(this->levelup,(int)4,_Function_1_1::Block(),_Function_1_2::Block());
	struct _Function_1_3{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("y") , (int)120,false);
			return __result;
		}
	};
	struct _Function_1_4{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("delay") , 0.5,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",82)
	::com::mybo::framework::tweener::MTween_obj::to(levelupTitle,(int)4,_Function_1_3::Block(),_Function_1_4::Block());
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",84)
	this->bubbleTexture = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("pp5"),null())->bitmapData;
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",85)
	this->radius = ::Std_obj::_int((double((double(this->bubbleTexture->nmeGetWidth()) / double((int)2))) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor)));
	HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",87)
	this->start();
}
;
	return null();
}

LevelUpEffect_obj::~LevelUpEffect_obj() { }

Dynamic LevelUpEffect_obj::__CreateEmpty() { return  new LevelUpEffect_obj; }
hx::ObjectPtr< LevelUpEffect_obj > LevelUpEffect_obj::__new(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size)
{  hx::ObjectPtr< LevelUpEffect_obj > result = new LevelUpEffect_obj();
	result->__construct(_view,x,y,n,t,rate,delay,size);
	return result;}

Dynamic LevelUpEffect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LevelUpEffect_obj > result = new LevelUpEffect_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

Void LevelUpEffect_obj::start( ){
{
		HX_SOURCE_PUSH("LevelUpEffect_obj::start")
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",90)
		this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LevelUpEffect_obj,start,(void))

Void LevelUpEffect_obj::destroy( ){
{
		HX_SOURCE_PUSH("LevelUpEffect_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",95)
		{
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",95)
			int _g1 = (int)0;
			int _g = this->balls->length;
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",95)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",95)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",96)
				this->balls[i] = null();
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",99)
		this->balls = Array_obj< ::com::mybo::effects::BubbleCell2 >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",101)
		this->levelup->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",102)
		while(((this->levelup->nmeGetNumChildren() != (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",102)
			this->levelup->removeChildAt((int)0);
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",103)
		this->view->removeChild(this->levelup);
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",104)
		this->levelup = null();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",106)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LevelUpEffect_obj,destroy,(void))

Void LevelUpEffect_obj::onEnterFrame( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("LevelUpEffect_obj::onEnterFrame")
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",111)
		double vr = (int)2;
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",112)
		double r = (int)15;
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",114)
		if (((this->time > (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",115)
			::com::mybo::effects::BubbleCell2 b;
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",116)
			{
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",116)
				int _g1 = (int)0;
				int _g = this->length;
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",116)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",116)
					int i = (_g1)++;
					HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",117)
					if (((::Math_obj::random() < this->rate))){
						HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",118)
						b = ::com::mybo::effects::BubbleCell2_obj::__new(((int)320 * ::Math_obj::random()),this->yy,this->size,(0.2 + (0.8 * ::Math_obj::random())),(0.1 - (::Math_obj::random() * 0.34)),((int)-5 - ((int)4 * ::Math_obj::random())));
						HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",119)
						this->balls->push(b);
					}
				}
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",122)
			(this->time)--;
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",125)
		::com::mybo::effects::BubbleCell2 b;
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",126)
		int l = this->balls->length;
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",128)
		int i = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",129)
		while(((i < l))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",130)
			b = this->balls->__get(i);
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",132)
			hx::SubEq(b->vy,0.007);
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",134)
			hx::MultEq(b->scale,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",135)
			hx::AddEq(b->xx,b->vx);
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",136)
			hx::AddEq(b->yy,b->vy);
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",138)
			if (((b->yy <= (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",139)
				this->balls->remove(b);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",140)
				(i)--;
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",141)
				(l)--;
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",142)
				if (((this->balls->length <= (int)0))){
					HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",143)
					this->destroy();
				}
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",145)
			(i)++;
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",148)
		Array< int > indices = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",149)
		Array< double > vertices = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",150)
		Array< double > uvdatas = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",152)
		this->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",153)
		this->nmeGetGraphics()->beginBitmapFill(this->bubbleTexture,null(),false,true);
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",154)
		::com::mybo::effects::BubbleCell2 bbb;
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",155)
		{
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",155)
			int _g1 = (int)0;
			int _g = this->balls->length;
			HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",155)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",155)
				int m = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",157)
				bbb = this->balls->__get(m);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",159)
				indices->push(((int)4 * m));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",160)
				indices->push((((int)4 * m) + (int)1));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",161)
				indices->push((((int)4 * m) + (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",162)
				indices->push(((int)4 * m));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",163)
				indices->push((((int)4 * m) + (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",164)
				indices->push((((int)4 * m) + (int)3));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",166)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",167)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",168)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",169)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",170)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",171)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",172)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",173)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",175)
				vertices->push((((bbb->xx - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",176)
				vertices->push((((bbb->yy - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",177)
				vertices->push((((bbb->xx + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",178)
				vertices->push((((bbb->yy - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",179)
				vertices->push((((bbb->xx + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",180)
				vertices->push((((bbb->yy + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",181)
				vertices->push((((bbb->xx - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",182)
				vertices->push((((bbb->yy + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/LevelUpEffect.hx",185)
		this->nmeGetGraphics()->drawTriangles(vertices,indices,uvdatas,::nme::display::TriangleCulling_obj::NONE_dyn(),null(),(int)9,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LevelUpEffect_obj,onEnterFrame,(void))


LevelUpEffect_obj::LevelUpEffect_obj()
{
}

void LevelUpEffect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LevelUpEffect);
	HX_MARK_MEMBER_NAME(balls,"balls");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(staticLength,"staticLength");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_MEMBER_NAME(staticTime,"staticTime");
	HX_MARK_MEMBER_NAME(xx,"xx");
	HX_MARK_MEMBER_NAME(yy,"yy");
	HX_MARK_MEMBER_NAME(rate,"rate");
	HX_MARK_MEMBER_NAME(delay,"delay");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(levelup,"levelup");
	HX_MARK_MEMBER_NAME(bubbleTexture,"bubbleTexture");
	HX_MARK_MEMBER_NAME(radius,"radius");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic LevelUpEffect_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"xx") ) { return xx; }
		if (HX_FIELD_EQ(inName,"yy") ) { return yy; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		if (HX_FIELD_EQ(inName,"rate") ) { return rate; }
		if (HX_FIELD_EQ(inName,"size") ) { return size; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"balls") ) { return balls; }
		if (HX_FIELD_EQ(inName,"delay") ) { return delay; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"levelup") ) { return levelup; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"staticTime") ) { return staticTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"staticLength") ) { return staticLength; }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bubbleTexture") ) { return bubbleTexture; }
	}
	return super::__Field(inName);
}

Dynamic LevelUpEffect_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"xx") ) { xx=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yy") ) { yy=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rate") ) { rate=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"size") ) { size=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"balls") ) { balls=inValue.Cast< Array< ::com::mybo::effects::BubbleCell2 > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"levelup") ) { levelup=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"staticTime") ) { staticTime=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"staticLength") ) { staticLength=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"bubbleTexture") ) { bubbleTexture=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LevelUpEffect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("balls"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("staticLength"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("staticTime"));
	outFields->push(HX_CSTRING("xx"));
	outFields->push(HX_CSTRING("yy"));
	outFields->push(HX_CSTRING("rate"));
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("levelup"));
	outFields->push(HX_CSTRING("bubbleTexture"));
	outFields->push(HX_CSTRING("radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("balls"),
	HX_CSTRING("length"),
	HX_CSTRING("staticLength"),
	HX_CSTRING("view"),
	HX_CSTRING("time"),
	HX_CSTRING("staticTime"),
	HX_CSTRING("xx"),
	HX_CSTRING("yy"),
	HX_CSTRING("rate"),
	HX_CSTRING("delay"),
	HX_CSTRING("size"),
	HX_CSTRING("levelup"),
	HX_CSTRING("bubbleTexture"),
	HX_CSTRING("radius"),
	HX_CSTRING("start"),
	HX_CSTRING("destroy"),
	HX_CSTRING("onEnterFrame"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class LevelUpEffect_obj::__mClass;

void LevelUpEffect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.effects.LevelUpEffect"), hx::TCanCast< LevelUpEffect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LevelUpEffect_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace effects
