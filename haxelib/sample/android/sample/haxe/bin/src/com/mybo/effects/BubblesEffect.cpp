#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_effects_BubbleCell
#include <com/mybo/effects/BubbleCell.h>
#endif
#ifndef INCLUDED_com_mybo_effects_BubblesEffect
#include <com/mybo/effects/BubblesEffect.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
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

Void BubblesEffect_obj::__construct(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size,Dynamic __o_picFlag)
{
int picFlag = __o_picFlag.Default(0);
{
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",33)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",35)
	this->staticLength = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",36)
	this->staticTime = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",37)
	this->view = _view;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",38)
	this->balls = Array_obj< ::com::mybo::effects::BubbleCell >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",40)
	this->xx = x;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",41)
	this->yy = y;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",43)
	this->rate = rate;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",44)
	this->delay = delay;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",45)
	this->size = size;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",47)
	this->length = n;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",48)
	if (((this->staticLength == (int)0))){
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",49)
		this->staticLength = n;
	}
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",50)
	this->time = t;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",51)
	if (((this->staticTime == (int)0))){
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",52)
		this->staticTime = t;
	}
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",54)
	this->flag = picFlag;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",57)
	this->texture = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("inside_bubble"),true)->bitmapData;
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",58)
	this->radius = (double((double(this->texture->nmeGetWidth()) / double((int)8))) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",60)
	{
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",60)
		int _g = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",60)
		while(((_g < (int)60))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",60)
			int i = (_g)++;
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",61)
			this->onEnterFrame(null());
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",64)
	this->start();
	HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",66)
	this->view->addChild(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

BubblesEffect_obj::~BubblesEffect_obj() { }

Dynamic BubblesEffect_obj::__CreateEmpty() { return  new BubblesEffect_obj; }
hx::ObjectPtr< BubblesEffect_obj > BubblesEffect_obj::__new(::nme::display::Sprite _view,double x,double y,int n,int t,double rate,double delay,double size,Dynamic __o_picFlag)
{  hx::ObjectPtr< BubblesEffect_obj > result = new BubblesEffect_obj();
	result->__construct(_view,x,y,n,t,rate,delay,size,__o_picFlag);
	return result;}

Dynamic BubblesEffect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BubblesEffect_obj > result = new BubblesEffect_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8]);
	return result;}

Void BubblesEffect_obj::start( ){
{
		HX_SOURCE_PUSH("BubblesEffect_obj::start")
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",69)
		this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BubblesEffect_obj,start,(void))

Void BubblesEffect_obj::stop( ){
{
		HX_SOURCE_PUSH("BubblesEffect_obj::stop")
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",72)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BubblesEffect_obj,stop,(void))

Void BubblesEffect_obj::reStart( ){
{
		HX_SOURCE_PUSH("BubblesEffect_obj::reStart")
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",77)
		this->length = (int)1;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",78)
		this->time = (::Std_obj::_int((this->staticTime * ((::Math_obj::random() + 0.5)))) + (int)5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BubblesEffect_obj,reStart,(void))

Void BubblesEffect_obj::destroy( ){
{
		HX_SOURCE_PUSH("BubblesEffect_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",81)
		this->balls = Array_obj< ::com::mybo::effects::BubbleCell >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",83)
		this->view->removeChild(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",84)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BubblesEffect_obj,destroy,(void))

Void BubblesEffect_obj::onEnterFrame( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("BubblesEffect_obj::onEnterFrame")
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",87)
		double vr = (int)2;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",88)
		double r = (int)15;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",90)
		if (((this->time > (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",91)
			::com::mybo::effects::BubbleCell b;
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",92)
			{
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",92)
				int _g1 = (int)0;
				int _g = this->length;
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",92)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",92)
					int i = (_g1)++;
					HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",93)
					if (((::Math_obj::random() < this->rate))){
						HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",94)
						b = ::com::mybo::effects::BubbleCell_obj::__new(this->xx,this->yy,this->size,(0.01 + (0.99 * ::Math_obj::random())),(0.1 - (::Math_obj::random() * 0.2)),(-(::Math_obj::random()) * (int)4));
						HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",95)
						this->balls->push(b);
					}
				}
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",98)
			(this->time)--;
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",99)
			if (((this->time == (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",100)
				this->time = (int)-1;
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",101)
				::haxe::Timer_obj::delay(this->reStart_dyn(),::Std_obj::_int((this->delay * ((::Math_obj::random() + 0.3)))));
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",104)
		::com::mybo::effects::BubbleCell b;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",105)
		int l = this->balls->length;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",107)
		int i = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",108)
		while(((i < l))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",109)
			b = this->balls->__get(i);
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",110)
			hx::SubEq(b->vy,0.007);
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",112)
			hx::MultEq(b->scale,1.0029);
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",113)
			hx::AddEq(b->xx,b->vx);
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",114)
			hx::AddEq(b->yy,b->vy);
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",116)
			if ((((this->yy + b->yy) <= (int)-50))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",117)
				this->balls->remove(b);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",118)
				(i)--;
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",119)
				(l)--;
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",121)
			(i)++;
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",124)
		Array< int > indices = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",125)
		Array< double > vertices = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",126)
		Array< double > uvdatas = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",128)
		this->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",129)
		this->nmeGetGraphics()->beginBitmapFill(this->texture,null(),false,true);
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",132)
		::com::mybo::effects::BubbleCell bbb;
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",133)
		{
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",133)
			int _g1 = (int)0;
			int _g = this->balls->length;
			HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",133)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",133)
				int m = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",134)
				bbb = this->balls->__get(m);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",136)
				indices->push(((int)4 * m));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",137)
				indices->push((((int)4 * m) + (int)1));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",138)
				indices->push((((int)4 * m) + (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",139)
				indices->push(((int)4 * m));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",140)
				indices->push((((int)4 * m) + (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",141)
				indices->push((((int)4 * m) + (int)3));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",143)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",144)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",145)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",146)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",147)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",148)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",149)
				uvdatas->push((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",150)
				uvdatas->push((int)1);
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",152)
				vertices->push((((bbb->xx - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",153)
				vertices->push((((bbb->yy - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",154)
				vertices->push((((bbb->xx + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",155)
				vertices->push((((bbb->yy - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",156)
				vertices->push((((bbb->xx + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",157)
				vertices->push((((bbb->yy + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",158)
				vertices->push((((bbb->xx - ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",159)
				vertices->push((((bbb->yy + ((bbb->scale * this->radius) * (int)2))) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",161)
		this->nmeGetGraphics()->drawTriangles(vertices,indices,uvdatas,::nme::display::TriangleCulling_obj::NONE_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/effects/BubblesEffect.hx",162)
		this->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BubblesEffect_obj,onEnterFrame,(void))


BubblesEffect_obj::BubblesEffect_obj()
{
}

void BubblesEffect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BubblesEffect);
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
	HX_MARK_MEMBER_NAME(flag,"flag");
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(radius,"radius");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BubblesEffect_obj::__Field(const ::String &inName)
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
		if (HX_FIELD_EQ(inName,"flag") ) { return flag; }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
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
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		if (HX_FIELD_EQ(inName,"reStart") ) { return reStart_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"staticTime") ) { return staticTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"staticLength") ) { return staticLength; }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BubblesEffect_obj::__SetField(const ::String &inName,const Dynamic &inValue)
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
		if (HX_FIELD_EQ(inName,"flag") ) { flag=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"balls") ) { balls=inValue.Cast< Array< ::com::mybo::effects::BubbleCell > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"staticTime") ) { staticTime=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"staticLength") ) { staticLength=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BubblesEffect_obj::__GetFields(Array< ::String> &outFields)
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
	outFields->push(HX_CSTRING("flag"));
	outFields->push(HX_CSTRING("texture"));
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
	HX_CSTRING("flag"),
	HX_CSTRING("texture"),
	HX_CSTRING("radius"),
	HX_CSTRING("start"),
	HX_CSTRING("stop"),
	HX_CSTRING("reStart"),
	HX_CSTRING("destroy"),
	HX_CSTRING("onEnterFrame"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BubblesEffect_obj::__mClass;

void BubblesEffect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.effects.BubblesEffect"), hx::TCanCast< BubblesEffect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BubblesEffect_obj::__boot()
{
}

} // end namespace com
} // end namespace mybo
} // end namespace effects
