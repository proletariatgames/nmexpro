#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
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
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameBoard
#include <com/mybo/gamescene/GameBoard.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameHint
#include <com/mybo/gamescene/GameHint.h>
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
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
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

Void GameHint_obj::__construct(::com::mybo::gamescene::GameBoard inGameboard,Array< Array< int > > inSolution)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",30)
	if ((!(::com::mybo::gamescene::GameHint_obj::running))){
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",33)
		this->facade = ::com::mybo::framework::core::Facade_obj::getInstance();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",34)
		this->facade->disable();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",35)
		this->gameBoard = inGameboard;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",36)
		this->solution = inSolution;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",38)
		this->step = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",39)
		this->touchArea = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",42)
		this->facade->getStage()->addChild(this->touchArea);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",44)
		this->motionLayer = ::nme::display::Sprite_obj::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",45)
		this->motionLayer->nmeSetMouseEnabled(false);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",46)
		this->facade->getStage()->addChild(this->motionLayer);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",48)
		this->maxStep = (this->solution->length - (int)1);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",49)
		this->gameBoard->nmeSetMouseEnabled(false);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",51)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleInited"),this->showHint_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",52)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTouched"),this->onTap_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",53)
		this->gameBoard->addEventListener(HX_CSTRING("bubbleTapCompleted"),this->onTapComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",54)
		this->gameBoard->addEventListener(HX_CSTRING("levelComplete"),this->destroy_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",56)
		::com::mybo::gamescene::GameHint_obj::running = true;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",57)
		::com::mybo::gamescene::GameHint_obj::runningInstance = hx::ObjectPtr<OBJ_>(this);
	}
}
;
	return null();
}

GameHint_obj::~GameHint_obj() { }

Dynamic GameHint_obj::__CreateEmpty() { return  new GameHint_obj; }
hx::ObjectPtr< GameHint_obj > GameHint_obj::__new(::com::mybo::gamescene::GameBoard inGameboard,Array< Array< int > > inSolution)
{  hx::ObjectPtr< GameHint_obj > result = new GameHint_obj();
	result->__construct(inGameboard,inSolution);
	return result;}

Dynamic GameHint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameHint_obj > result = new GameHint_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void GameHint_obj::onTap( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("GameHint_obj::onTap")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",65)
		this->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",66)
		if (((bool(!(((this->solution->__get(this->step)->__get((int)1) == e->data->__get((int)1))))) || bool(!(((this->solution->__get(this->step)->__get((int)0) == e->data->__get((int)0)))))))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",66)
			this->destroy(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHint_obj,onTap,(void))

Void GameHint_obj::onTapComplete( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("GameHint_obj::onTapComplete")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",71)
		if (((this->step < this->maxStep))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",73)
			hx::AddEq(this->step,(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",74)
			this->showHint(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHint_obj,onTapComplete,(void))

Void GameHint_obj::showHint( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("GameHint_obj::showHint")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",78)
		Array< ::com::mybo::gamescene::GameHint > me = Array_obj< ::com::mybo::gamescene::GameHint >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",79)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleInited"),this->showHint_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",80)
		this->gameBoard->nmeSetMouseEnabled(false);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",82)
		double w = this->facade->getStageWidthInPoint();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",83)
		double h = (this->facade->getStageHeightInPoint() - (int)29);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",84)
		int r = (int)30;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",85)
		::nme::geom::Point point = ::nme::geom::Point_obj::__new(((((this->solution->__get(this->step)->__get((int)1) * (int)2) + (int)1)) * r),((((this->solution->__get(this->step)->__get((int)0) * (int)2) + (int)1)) * r));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",87)
		::nme::geom::Point gPoint = ::nme::geom::Point_obj::__new((this->gameBoard->nmeGetParent()->nmeGetX() + point->x),(this->gameBoard->nmeGetParent()->nmeGetY() + point->y));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",88)
		::nmex::display::Bitmap mask = this->facade->getBitmap(HX_CSTRING("tip_mask"),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",91)
		mask->nmeSetX(this->calForInt(((gPoint->x - ((mask->nmeGetWidth() - r))) + (int)8)));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",92)
		mask->nmeSetY(this->calForInt(((gPoint->y - r) - (int)13)));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",94)
		this->motionLayer->addChild(mask);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",96)
		bool needReverse = (mask->nmeGetX() < (int)0);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",97)
		if ((needReverse)){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",98)
			mask->nmeSetX(this->calForInt(((gPoint->x - r) - (int)5)));
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",99)
			mask->nmeSetY(this->calForInt(((gPoint->y - r) - (int)10)));
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",102)
		r = (int)55;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",103)
		point = gPoint;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",105)
		::nme::geom::Point a = ::nme::geom::Point_obj::__new(mask->nmeGetX(),mask->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",106)
		::nme::geom::Point b = ::nme::geom::Point_obj::__new((mask->nmeGetX() + mask->nmeGetWidth()),mask->nmeGetY());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",107)
		::nme::geom::Point c = ::nme::geom::Point_obj::__new(mask->nmeGetX(),(mask->nmeGetY() + mask->nmeGetHeight()));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",108)
		::nme::geom::Point d = ::nme::geom::Point_obj::__new((mask->nmeGetX() + mask->nmeGetWidth()),(mask->nmeGetY() + mask->nmeGetHeight()));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",110)
		this->motionLayer->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",111)
		this->motionLayer->nmeGetGraphics()->beginFill((int)9572,0.64);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",112)
		this->motionLayer->nmeGetGraphics()->drawRect((int)0,(int)0,this->calForInt(w),this->calForInt(a->y));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",113)
		this->motionLayer->nmeGetGraphics()->drawRect((int)0,this->calForInt(a->y),this->calForInt(a->x),this->calForInt(((int)2 * r)));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",114)
		this->motionLayer->nmeGetGraphics()->drawRect(this->calForInt(b->x),this->calForInt(a->y),this->calForInt((w - b->x)),this->calForInt(((int)2 * r)));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",115)
		this->motionLayer->nmeGetGraphics()->drawRect((int)0,this->calForInt(c->y),this->calForInt(w),this->calForInt((h - c->y)));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",116)
		this->motionLayer->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",118)
		this->motionLayer->nmeSetAlpha((int)0);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("alpha") , (int)1,false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",119)
		::com::mybo::framework::tweener::MTween_obj::to(this->motionLayer,0.3,_Function_1_1::Block(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",121)
		this->tipMC = ::com::mybo::framework::display::BitmapMovieClip_obj::__new(this->facade->getTile(HX_CSTRING("star_hint")),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)7).Add((int)9).Add((int)9).Add((int)9).Add((int)8).Add((int)7).Add((int)6).Add((int)5).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9).Add((int)9).Add((int)9).Add((int)8).Add((int)7).Add((int)6).Add((int)5).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9).Add((int)9).Add((int)9).Add((int)8).Add((int)7).Add((int)6).Add((int)5).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9).Add((int)9).Add((int)9).Add((int)9).Add((int)9).Add((int)9).Add((int)9).Add((int)9).Add((int)9).Add((int)8).Add((int)7).Add((int)6).Add((int)5).Add((int)4).Add((int)3).Add((int)2).Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",124)
		this->tipMC->nmeSetX((mask->nmeGetX() + (int)8));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",125)
		this->tipMC->nmeSetY(this->facade->getStageHeightInPoint());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",126)
		this->tipMC->isLoop = true;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",127)
		this->tipMC->gotoAndStop((int)0);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",128)
		this->motionLayer->addChild(this->tipMC);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",130)
		if ((needReverse)){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",131)
			this->tipMC->nmeSetScaleX((int)-1);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",132)
			this->tipMC->nmeSetX(((mask->nmeGetX() + mask->nmeGetWidth()) - (int)8));
		}
		struct _Function_1_2{
			inline static Dynamic Block( ::nmex::display::Bitmap &mask){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("y") , (mask->nmeGetY() + (int)42),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",135)
		::com::mybo::framework::tweener::MTween_obj::to(this->tipMC,0.5,_Function_1_2::Block(mask),null());

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_3,Array< ::com::mybo::gamescene::GameHint >,me)
		Void run(){
{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",138)
				me->__get((int)0)->tipMC->play();
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",139)
				me->__get((int)0)->drawTouchArea();
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",140)
				me->__get((int)0)->gameBoard->nmeSetMouseEnabled(true);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",141)
				me->__get((int)0)->facade->enable();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",137)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_3(me)),(int)700);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHint_obj,showHint,(void))

double GameHint_obj::calForInt( double value){
	HX_SOURCE_PUSH("GameHint_obj::calForInt")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",147)
	double s = (double(this->facade->getStageWidthInPoint()) / double((int)320));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",148)
	double sd = (double((((value * s) - ::Std_obj::_int((value * s))))) / double(s));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",150)
	return (value - sd);
}


HX_DEFINE_DYNAMIC_FUNC1(GameHint_obj,calForInt,return )

Void GameHint_obj::drawTouchArea( ){
{
		HX_SOURCE_PUSH("GameHint_obj::drawTouchArea")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",160)
		double xx = this->gameBoard->nmeGetParent()->nmeGetX();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",161)
		double yy = this->gameBoard->nmeGetParent()->nmeGetY();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",162)
		double w = this->facade->getStageWidthInPoint();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",163)
		double h = this->facade->getStageHeightInPoint();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",165)
		int r = (int)30;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",166)
		::nme::geom::Point point = ::nme::geom::Point_obj::__new(((((this->solution->__get(this->step)->__get((int)1) * (int)2) + (int)1)) * r),((((this->solution->__get(this->step)->__get((int)0) * (int)2) + (int)1)) * r));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",168)
		::nme::geom::Point a = ::nme::geom::Point_obj::__new(((point->x - r) + xx),((point->y - r) + yy));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",169)
		::nme::geom::Point b = ::nme::geom::Point_obj::__new(((point->x + r) + xx),((point->y - r) + yy));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",170)
		::nme::geom::Point c = ::nme::geom::Point_obj::__new(((point->x - r) + xx),((point->y + r) + yy));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",171)
		::nme::geom::Point d = ::nme::geom::Point_obj::__new(((point->x + r) + xx),((point->y + r) + yy));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",173)
		this->touchArea->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",174)
		this->touchArea->nmeGetGraphics()->beginFill((int)16711680,(int)0);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",175)
		this->touchArea->nmeGetGraphics()->drawRect((int)0,(int)0,w,a->y);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",176)
		this->touchArea->nmeGetGraphics()->drawRect((int)0,a->y,a->x,((int)2 * r));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",177)
		this->touchArea->nmeGetGraphics()->drawRect(b->x,a->y,(w - b->x),((int)2 * r));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",178)
		this->touchArea->nmeGetGraphics()->drawRect((int)0,c->y,w,(h - c->y));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",179)
		this->touchArea->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameHint_obj,drawTouchArea,(void))

Void GameHint_obj::clear( ){
{
		HX_SOURCE_PUSH("GameHint_obj::clear")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",183)
		if (((null() != this->tipMC))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",185)
			this->tipMC->destroy();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",186)
			this->tipMC = null();
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",188)
		if (((null() != this->motionLayer))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",188)
			while(((this->motionLayer->nmeGetNumChildren() > (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",190)
				this->motionLayer->removeChildAt((int)0);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",191)
				this->motionLayer->nmeGetGraphics()->clear();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameHint_obj,clear,(void))

Void GameHint_obj::destroy( ::com::mybo::common::GameEvent e){
{
		HX_SOURCE_PUSH("GameHint_obj::destroy")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",198)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleInited"),this->showHint_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",199)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTouched"),this->onTap_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",200)
		this->gameBoard->removeEventListener(HX_CSTRING("bubbleTapCompleted"),this->onTapComplete_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",201)
		this->gameBoard->removeEventListener(HX_CSTRING("levelComplete"),this->destroy_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",202)
		this->facade->getStage()->removeChild(this->touchArea);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",203)
		this->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",205)
		if (((bool((null() != this->motionLayer)) && bool(this->facade->getStage()->contains(this->motionLayer))))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",206)
			this->facade->getStage()->removeChild(this->motionLayer);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",207)
			this->motionLayer = null();
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",210)
		this->gameBoard = null();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",211)
		this->solution = null();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",212)
		this->touchArea = null();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameHint.hx",214)
		::com::mybo::gamescene::GameHint_obj::running = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameHint_obj,destroy,(void))

bool GameHint_obj::running;

::com::mybo::gamescene::GameHint GameHint_obj::runningInstance;


GameHint_obj::GameHint_obj()
{
}

void GameHint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameHint);
	HX_MARK_MEMBER_NAME(gameBoard,"gameBoard");
	HX_MARK_MEMBER_NAME(solution,"solution");
	HX_MARK_MEMBER_NAME(step,"step");
	HX_MARK_MEMBER_NAME(maxStep,"maxStep");
	HX_MARK_MEMBER_NAME(touchArea,"touchArea");
	HX_MARK_MEMBER_NAME(motionLayer,"motionLayer");
	HX_MARK_MEMBER_NAME(tipMC,"tipMC");
	HX_MARK_MEMBER_NAME(facade,"facade");
	HX_MARK_END_CLASS();
}

Dynamic GameHint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { return step; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"tipMC") ) { return tipMC; }
		if (HX_FIELD_EQ(inName,"onTap") ) { return onTap_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { return facade; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"running") ) { return running; }
		if (HX_FIELD_EQ(inName,"maxStep") ) { return maxStep; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"solution") ) { return solution; }
		if (HX_FIELD_EQ(inName,"showHint") ) { return showHint_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameBoard") ) { return gameBoard; }
		if (HX_FIELD_EQ(inName,"touchArea") ) { return touchArea; }
		if (HX_FIELD_EQ(inName,"calForInt") ) { return calForInt_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"motionLayer") ) { return motionLayer; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onTapComplete") ) { return onTapComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTouchArea") ) { return drawTouchArea_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"runningInstance") ) { return runningInstance; }
	}
	return super::__Field(inName);
}

Dynamic GameHint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { step=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"tipMC") ) { tipMC=inValue.Cast< ::com::mybo::framework::display::BitmapMovieClip >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"facade") ) { facade=inValue.Cast< ::com::mybo::framework::core::Facade >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"running") ) { running=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxStep") ) { maxStep=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"solution") ) { solution=inValue.Cast< Array< Array< int > > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameBoard") ) { gameBoard=inValue.Cast< ::com::mybo::gamescene::GameBoard >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchArea") ) { touchArea=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"motionLayer") ) { motionLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"runningInstance") ) { runningInstance=inValue.Cast< ::com::mybo::gamescene::GameHint >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameHint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gameBoard"));
	outFields->push(HX_CSTRING("solution"));
	outFields->push(HX_CSTRING("step"));
	outFields->push(HX_CSTRING("maxStep"));
	outFields->push(HX_CSTRING("touchArea"));
	outFields->push(HX_CSTRING("motionLayer"));
	outFields->push(HX_CSTRING("tipMC"));
	outFields->push(HX_CSTRING("facade"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("running"),
	HX_CSTRING("runningInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("gameBoard"),
	HX_CSTRING("solution"),
	HX_CSTRING("step"),
	HX_CSTRING("maxStep"),
	HX_CSTRING("touchArea"),
	HX_CSTRING("motionLayer"),
	HX_CSTRING("tipMC"),
	HX_CSTRING("facade"),
	HX_CSTRING("onTap"),
	HX_CSTRING("onTapComplete"),
	HX_CSTRING("showHint"),
	HX_CSTRING("calForInt"),
	HX_CSTRING("drawTouchArea"),
	HX_CSTRING("clear"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameHint_obj::running,"running");
	HX_MARK_MEMBER_NAME(GameHint_obj::runningInstance,"runningInstance");
};

Class GameHint_obj::__mClass;

void GameHint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.GameHint"), hx::TCanCast< GameHint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameHint_obj::__boot()
{
	hx::Static(running) = false;
	hx::Static(runningInstance);
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
