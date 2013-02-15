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
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
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
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nmex_Device
#include <nmex/Device.h>
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

Void ScaleButton_obj::__construct(::nmex::display::Bitmap _view,double centerX,double centerY,Dynamic __o_offsetX,Dynamic __o_offsetY,Dynamic __o_scale,Dynamic onClick,Dynamic __o_inGame)
{
double offsetX = __o_offsetX.Default(0);
double offsetY = __o_offsetY.Default(0);
double scale = __o_scale.Default(0.13);
bool inGame = __o_inGame.Default(false);
{
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",48)
	super::__construct(null());
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",49)
	this->view = _view;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",51)
	this->retina = ::nmex::Device_obj::scaleFactor();
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",53)
	this->addChild(this->view);
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",54)
	this->centerX = centerX;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",55)
	this->centerY = centerY;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",57)
	this->offsetX = offsetX;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",58)
	this->offsetY = offsetY;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",62)
	this->scale = scale;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",64)
	this->ssx = 0.2;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",65)
	this->tMatrix = ::nme::geom::Matrix_obj::__new(this->ssx,(int)0,(int)0,this->ssx,((this->retina * centerX) * (((int)1 - this->ssx))),((this->retina * centerY) * (((int)1 - this->ssx))));
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",69)
	this->view->nmeSetMatrix(this->tMatrix);
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",75)
	this->downInside = false;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",77)
	this->offsetFlag = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",78)
	this->sFlag = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",79)
	this->flag = ::Std_obj::random((int)60);
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",80)
	this->dScaleX = ::com::mybo::effects::ScaleButton_obj::sxs->__get(this->flag);
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",81)
	this->dScaleY = ((scale + (int)1) - ((this->dScaleX - (int)1)));
	HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",90)
	this->destroyed = false;
}
;
	return null();
}

ScaleButton_obj::~ScaleButton_obj() { }

Dynamic ScaleButton_obj::__CreateEmpty() { return  new ScaleButton_obj; }
hx::ObjectPtr< ScaleButton_obj > ScaleButton_obj::__new(::nmex::display::Bitmap _view,double centerX,double centerY,Dynamic __o_offsetX,Dynamic __o_offsetY,Dynamic __o_scale,Dynamic onClick,Dynamic __o_inGame)
{  hx::ObjectPtr< ScaleButton_obj > result = new ScaleButton_obj();
	result->__construct(_view,centerX,centerY,__o_offsetX,__o_offsetY,__o_scale,onClick,__o_inGame);
	return result;}

Dynamic ScaleButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ScaleButton_obj > result = new ScaleButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

Void ScaleButton_obj::render( ){
{
		HX_SOURCE_PUSH("ScaleButton_obj::render")
		HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",94)
		if (((this->sFlag <= (int)30))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",97)
			this->ssx = ::com::mybo::effects::ScaleButton_obj::ssxs->__get(this->sFlag);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",98)
			this->tMatrix->a = (this->ssx * this->dScaleX);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",99)
			this->tMatrix->d = (this->ssx * this->dScaleY);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",102)
			double off = ::Math_obj::sin((double(this->offsetFlag) / double((int)80)));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",103)
			this->tMatrix->tx = (this->retina * (((this->offsetX * off) - (this->centerX * ((this->tMatrix->a - (int)1))))));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",104)
			this->tMatrix->ty = (this->retina * (((this->offsetY * off) - (this->centerY * ((this->tMatrix->d - (int)1))))));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",105)
			this->view->nmeSetMatrix(this->tMatrix);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",106)
			(this->sFlag)++;
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",109)
			if (((this->flag >= (int)60))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",110)
				this->flag = (int)0;
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",112)
			(this->offsetFlag)++;
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",114)
			this->sx = ::com::mybo::effects::ScaleButton_obj::sxs->__get(this->flag);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",115)
			double off = ::Math_obj::sin((double(this->offsetFlag) / double((int)80)));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",116)
			this->tMatrix->a = this->sx;
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",117)
			this->tMatrix->d = ((this->scale + (int)1) - ((this->sx - (int)1)));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",118)
			this->tMatrix->tx = (this->retina * (((this->offsetX * off) - (this->centerX * ((this->sx - (int)1))))));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",119)
			this->tMatrix->ty = (this->retina * (((this->offsetY * off) - (this->centerY * ((this->tMatrix->d - (int)1))))));
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",120)
			this->view->nmeSetMatrix(this->tMatrix);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",122)
			(this->flag)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScaleButton_obj,render,(void))

Void ScaleButton_obj::stop( ){
{
		HX_SOURCE_PUSH("ScaleButton_obj::stop")
		HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",126)
		this->noAutoRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScaleButton_obj,stop,(void))

Void ScaleButton_obj::destroy( ){
{
		HX_SOURCE_PUSH("ScaleButton_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",133)
		if ((!(this->destroyed))){
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",135)
			if (((this->tweener != null()))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",136)
				this->tweener->stop();
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",138)
			this->tweener = null();
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",140)
			this->stop();
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",141)
			if (((this->nmeGetParent() != null()))){
				HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",142)
				this->nmeGetParent()->removeChild(hx::ObjectPtr<OBJ_>(this));
			}
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",144)
			this->view->nmeGetGraphics()->clear();
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",145)
			this->removeChild(this->view);
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",146)
			this->view = null();
			HX_SOURCE_POS("../../../src/com/mybo/effects/ScaleButton.hx",149)
			this->destroyed = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ScaleButton_obj,destroy,(void))

Array< double > ScaleButton_obj::sxs;

Array< double > ScaleButton_obj::ssxs;


ScaleButton_obj::ScaleButton_obj()
{
}

void ScaleButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ScaleButton);
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(centerX,"centerX");
	HX_MARK_MEMBER_NAME(centerY,"centerY");
	HX_MARK_MEMBER_NAME(currentX,"currentX");
	HX_MARK_MEMBER_NAME(currentY,"currentY");
	HX_MARK_MEMBER_NAME(offsetX,"offsetX");
	HX_MARK_MEMBER_NAME(offsetY,"offsetY");
	HX_MARK_MEMBER_NAME(offsetFlag,"offsetFlag");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(tweener,"tweener");
	HX_MARK_MEMBER_NAME(dScaleX,"dScaleX");
	HX_MARK_MEMBER_NAME(dScaleY,"dScaleY");
	HX_MARK_MEMBER_NAME(downInside,"downInside");
	HX_MARK_MEMBER_NAME(destroyed,"destroyed");
	HX_MARK_MEMBER_NAME(delayTimer,"delayTimer");
	HX_MARK_MEMBER_NAME(sx,"sx");
	HX_MARK_MEMBER_NAME(ssx,"ssx");
	HX_MARK_MEMBER_NAME(sssx,"sssx");
	HX_MARK_MEMBER_NAME(tMatrix,"tMatrix");
	HX_MARK_MEMBER_NAME(retina,"retina");
	HX_MARK_MEMBER_NAME(flag,"flag");
	HX_MARK_MEMBER_NAME(sFlag,"sFlag");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ScaleButton_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"sx") ) { return sx; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sxs") ) { return sxs; }
		if (HX_FIELD_EQ(inName,"ssx") ) { return ssx; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ssxs") ) { return ssxs; }
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		if (HX_FIELD_EQ(inName,"sssx") ) { return sssx; }
		if (HX_FIELD_EQ(inName,"flag") ) { return flag; }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		if (HX_FIELD_EQ(inName,"sFlag") ) { return sFlag; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"retina") ) { return retina; }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"centerX") ) { return centerX; }
		if (HX_FIELD_EQ(inName,"centerY") ) { return centerY; }
		if (HX_FIELD_EQ(inName,"offsetX") ) { return offsetX; }
		if (HX_FIELD_EQ(inName,"offsetY") ) { return offsetY; }
		if (HX_FIELD_EQ(inName,"tweener") ) { return tweener; }
		if (HX_FIELD_EQ(inName,"dScaleX") ) { return dScaleX; }
		if (HX_FIELD_EQ(inName,"dScaleY") ) { return dScaleY; }
		if (HX_FIELD_EQ(inName,"tMatrix") ) { return tMatrix; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"currentX") ) { return currentX; }
		if (HX_FIELD_EQ(inName,"currentY") ) { return currentY; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyed") ) { return destroyed; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"offsetFlag") ) { return offsetFlag; }
		if (HX_FIELD_EQ(inName,"downInside") ) { return downInside; }
		if (HX_FIELD_EQ(inName,"delayTimer") ) { return delayTimer; }
	}
	return super::__Field(inName);
}

Dynamic ScaleButton_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"sx") ) { sx=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sxs") ) { sxs=inValue.Cast< Array< double > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ssx") ) { ssx=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ssxs") ) { ssxs=inValue.Cast< Array< double > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::nmex::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sssx") ) { sssx=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flag") ) { flag=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sFlag") ) { sFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"retina") ) { retina=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"centerX") ) { centerX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"centerY") ) { centerY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetX") ) { offsetX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetY") ) { offsetY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweener") ) { tweener=inValue.Cast< ::com::mybo::framework::tweener::MTween >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dScaleX") ) { dScaleX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dScaleY") ) { dScaleY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tMatrix") ) { tMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"currentX") ) { currentX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentY") ) { currentY=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyed") ) { destroyed=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"offsetFlag") ) { offsetFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"downInside") ) { downInside=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delayTimer") ) { delayTimer=inValue.Cast< ::haxe::Timer >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ScaleButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("centerX"));
	outFields->push(HX_CSTRING("centerY"));
	outFields->push(HX_CSTRING("currentX"));
	outFields->push(HX_CSTRING("currentY"));
	outFields->push(HX_CSTRING("offsetX"));
	outFields->push(HX_CSTRING("offsetY"));
	outFields->push(HX_CSTRING("offsetFlag"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("tweener"));
	outFields->push(HX_CSTRING("dScaleX"));
	outFields->push(HX_CSTRING("dScaleY"));
	outFields->push(HX_CSTRING("downInside"));
	outFields->push(HX_CSTRING("destroyed"));
	outFields->push(HX_CSTRING("delayTimer"));
	outFields->push(HX_CSTRING("sx"));
	outFields->push(HX_CSTRING("ssx"));
	outFields->push(HX_CSTRING("sssx"));
	outFields->push(HX_CSTRING("tMatrix"));
	outFields->push(HX_CSTRING("retina"));
	outFields->push(HX_CSTRING("flag"));
	outFields->push(HX_CSTRING("sFlag"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sxs"),
	HX_CSTRING("ssxs"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("view"),
	HX_CSTRING("centerX"),
	HX_CSTRING("centerY"),
	HX_CSTRING("currentX"),
	HX_CSTRING("currentY"),
	HX_CSTRING("offsetX"),
	HX_CSTRING("offsetY"),
	HX_CSTRING("offsetFlag"),
	HX_CSTRING("scale"),
	HX_CSTRING("tweener"),
	HX_CSTRING("dScaleX"),
	HX_CSTRING("dScaleY"),
	HX_CSTRING("downInside"),
	HX_CSTRING("destroyed"),
	HX_CSTRING("delayTimer"),
	HX_CSTRING("sx"),
	HX_CSTRING("ssx"),
	HX_CSTRING("sssx"),
	HX_CSTRING("tMatrix"),
	HX_CSTRING("retina"),
	HX_CSTRING("flag"),
	HX_CSTRING("sFlag"),
	HX_CSTRING("render"),
	HX_CSTRING("stop"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ScaleButton_obj::sxs,"sxs");
	HX_MARK_MEMBER_NAME(ScaleButton_obj::ssxs,"ssxs");
};

Class ScaleButton_obj::__mClass;

void ScaleButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.effects.ScaleButton"), hx::TCanCast< ScaleButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ScaleButton_obj::__boot()
{
	hx::Static(sxs) = Array_obj< double >::__new().Add((int)1).Add(1.000370449).Add(1.001477572).Add(1.0035709).Add(1.005843112).Add(1.009051768).Add(1.012413895).Add(1.017061647).Add(1.021709229).Add(1.027125119).Add(1.032972723).Add(1.038811082).Add(1.044913895).Add(1.052018851).Add(1.05888296).Add(1.065408404).Add(1.071929725).Add(1.079179311).Add(1.085086105).Add(1.091934413).Add(1.097735508).Add(1.104515469).Add(1.108594562).Add(1.113486174).Add(1.117586105).Add(1.121561944).Add(1.124490676).Add(1.126943657).Add(1.128770884).Add(1.129671816).Add(1.13).Add(1.129629551).Add(1.128607759).Add(1.126818674).Add(1.124654051).Add(1.120948232).Add(1.117825121).Add(1.113486174).Add(1.108594562).Add(1.102542226).Add(1.097735508).Add(1.09156219).Add(1.083526252).Add(1.07838107).Add(1.071929725).Add(1.065408404).Add(1.058070275).Add(1.05161893).Add(1.044913895).Add(1.03843781).Add(1.032617968).Add(1.027125119).Add(1.021709229).Add(1.016513826).Add(1.012654987).Add(1.008844978).Add(1.005675047).Add(1.003308751).Add(1.001392241).Add(1.000370449);
	hx::Static(ssxs) = Array_obj< double >::__new().Add(0.2).Add(0.3847782733).Add(0.7657291117).Add(1.083743493).Add(1.286046955).Add(1.278704048).Add(1.126054775).Add(1.025789585).Add(0.9179798224).Add(0.8944860428).Add(0.9204712487).Add(0.970716139).Add(1.014612227).Add(1.034588428).Add(1.034838006).Add(1.019008714).Add(1.003223698).Add(0.9911611652).Add(0.9868425864).Add(0.9900589061).Add(0.9959613799).Add(1.001308492).Add(1.004573707).Add(1.004354751).Add(1.002376089).Add(1.000284367).Add(0.9988322796).Add(0.9983517574).Add(0.9987176305).Add(0.9995424397).Add(1.000196579);
}

} // end namespace com
} // end namespace mybo
} // end namespace effects
