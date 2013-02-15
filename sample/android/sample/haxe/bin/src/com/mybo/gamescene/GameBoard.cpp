#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_common_GameEvent
#include <com/mybo/common/GameEvent.h>
#endif
#ifndef INCLUDED_com_mybo_data_Map
#include <com/mybo/data/Map.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_TimerRender
#include <com/mybo/framework/core/TimerRender.h>
#endif
#ifndef INCLUDED_com_mybo_framework_sound_SoundPlayer
#include <com/mybo/framework/sound/SoundPlayer.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_MTween
#include <com/mybo/framework/tweener/MTween.h>
#endif
#ifndef INCLUDED_com_mybo_framework_tweener_easing_Expo
#include <com/mybo/framework/tweener/easing/Expo.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_BlastNode
#include <com/mybo/gamescene/BlastNode.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_Bubble
#include <com/mybo/gamescene/Bubble.h>
#endif
#ifndef INCLUDED_com_mybo_gamescene_GameBoard
#include <com/mybo/gamescene/GameBoard.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
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
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
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

Void GameBoard_obj::__construct(::com::mybo::data::Map inMap,::nme::display::Sprite inView,::String inBubbleTextureID)
{
{
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",48)
	super::__construct();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",50)
	this->bubbleTextureID = (  (((inBubbleTextureID == null()))) ? ::String(HX_CSTRING("bubbleA")) : ::String(inBubbleTextureID) );
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",52)
	this->bubbleLayer = ::nme::display::Sprite_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",53)
	this->addChild(this->bubbleLayer);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",57)
	this->init(inMap);
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",58)
	inView->addChild(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

GameBoard_obj::~GameBoard_obj() { }

Dynamic GameBoard_obj::__CreateEmpty() { return  new GameBoard_obj; }
hx::ObjectPtr< GameBoard_obj > GameBoard_obj::__new(::com::mybo::data::Map inMap,::nme::display::Sprite inView,::String inBubbleTextureID)
{  hx::ObjectPtr< GameBoard_obj > result = new GameBoard_obj();
	result->__construct(inMap,inView,inBubbleTextureID);
	return result;}

Dynamic GameBoard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameBoard_obj > result = new GameBoard_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void GameBoard_obj::init( ::com::mybo::data::Map inMap){
{
		HX_SOURCE_PUSH("GameBoard_obj::init")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",62)
		this->map = inMap;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",63)
		this->flySpeed = (int)6;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",64)
		this->emptyArray(this->bubblePool);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",65)
		this->emptyArray(this->blastNodePool);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",66)
		this->bubblePool = Array_obj< ::com::mybo::gamescene::Bubble >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",67)
		this->blastNodePool = Array_obj< ::com::mybo::gamescene::BlastNode >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",68)
		this->frames = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",70)
		this->genBubbleFlag = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",71)
		this->genBubbleCount = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",101)
		this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->genBubble_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,init,(void))

Void GameBoard_obj::genBubble( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("GameBoard_obj::genBubble")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",106)
		int i = ::Std_obj::_int((double(this->genBubbleCount) / double((int)5)));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",107)
		int j = ::Std_obj::_int(hx::Mod(this->genBubbleCount,(int)5));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",110)
		::com::mybo::gamescene::Bubble bubble = ::com::mybo::gamescene::Bubble_obj::__new(::nme::geom::Point_obj::__new(i,j),this->map->data->__get(i)->__get(j),this->bubbleTextureID);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",111)
		bubble->nmeSetX(((j * (int)30) * (int)2));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",112)
		bubble->nmeSetY(::com::mybo::framework::core::Facade_obj::getInstance()->getStageHeightInPoint());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",113)
		double y = ((i * (int)30) * (int)2);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",114)
		this->bubblePool->push(bubble);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",116)
		this->bubbleLayer->addChild(bubble);
		struct _Function_1_1{
			inline static Dynamic Block( double &y){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("y") , y,false);
				return __result;
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Expo_obj::easeOut_dyn(),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",118)
		::com::mybo::framework::tweener::MTween_obj::to(bubble,((int)1 + ::Math_obj::random()),_Function_1_1::Block(y),_Function_1_2::Block());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",120)
		(this->genBubbleCount)++;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",122)
		if (((this->genBubbleCount == (int)30))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",123)
			this->startTouch();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",124)
			this->dispatchEvent(::com::mybo::common::GameEvent_obj::__new(HX_CSTRING("bubbleInited"),null()));
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",125)
			this->drawTouchArea();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",126)
			this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->genBubble_dyn(),null());
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",127)
			::com::mybo::framework::sound::SoundPlayer_obj::getInstance()->play(HX_CSTRING("startGame"),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,genBubble,(void))

Void GameBoard_obj::setBubbleTextureID( ::String id){
{
		HX_SOURCE_PUSH("GameBoard_obj::setBubbleTextureID")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",135)
		if (((this->bubbleTextureID != id))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",136)
			this->bubbleTextureID = id;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,setBubbleTextureID,(void))

Void GameBoard_obj::pause( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::pause")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",139)
		if (((this->frames != (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",140)
			this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,pause,(void))

Void GameBoard_obj::resume( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::resume")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",145)
		if (((this->frames != (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",146)
			this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,resume,(void))

Void GameBoard_obj::disable( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::disable")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",152)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onTap_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",153)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,disable,(void))

Void GameBoard_obj::startTouch( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::startTouch")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",156)
		this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onTap_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,startTouch,(void))

Void GameBoard_obj::motionClean( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::motionClean")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",161)
		this->cleanTimers();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",163)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onTap_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",164)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",166)
		::com::mybo::gamescene::Bubble bubble;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",167)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",167)
			int _g1 = (int)0;
			int _g = this->bubblePool->length;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",167)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",167)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",168)
				bubble = this->bubblePool->__get(i);
				struct _Function_3_1{
					inline static Dynamic Block( ::com::mybo::gamescene::Bubble &bubble){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("y") , (bubble->nmeGetY() - (int)500),false);
						return __result;
					}
				};
				struct _Function_3_2{
					inline static Dynamic Block( int &i){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("delay") , (0.8 + (i * 0.01)),false);
						__result->Add(HX_CSTRING("ease") , ::com::mybo::framework::tweener::easing::Expo_obj::easeOut_dyn(),false);

						HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_4_1)
						Void run(){
{
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						__result->Add(HX_CSTRING("onComplete") ,  Dynamic(new _Function_4_1()),true);
						return __result;
					}
				};
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",169)
				::com::mybo::framework::tweener::MTween_obj::to(bubble,((int)2 + ::Math_obj::random()),_Function_3_1::Block(bubble),_Function_3_2::Block(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,motionClean,(void))

Void GameBoard_obj::clean( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::clean")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",177)
		this->cleanTimers();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",179)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onTap_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",180)
		this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",182)
		this->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",183)
		while((((int)0 != this->bubbleLayer->nmeGetNumChildren()))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",183)
			this->bubbleLayer->removeChildAt((int)0);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",184)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",184)
			int _g1 = (int)0;
			int _g = this->bubblePool->length;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",184)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",184)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",185)
				this->bubblePool->__get(i)->destroy();
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",186)
				this->bubblePool[i] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,clean,(void))

Void GameBoard_obj::cleanTimers( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::cleanTimers")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,cleanTimers,(void))

Array< ::com::mybo::gamescene::Bubble > GameBoard_obj::getBubbles( ){
	HX_SOURCE_PUSH("GameBoard_obj::getBubbles")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",202)
	return this->bubblePool;
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,getBubbles,return )

Void GameBoard_obj::onTap( ::nme::events::MouseEvent e){
{
		HX_SOURCE_PUSH("GameBoard_obj::onTap")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",207)
		::com::mybo::gamescene::Bubble bubble;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",209)
		double x = this->nmeGetMouseX();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",210)
		double y = this->nmeGetMouseY();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",212)
		int index = ((::Std_obj::_int((double((double(y) / double((int)30))) / double((int)2))) * (int)5) + ::Std_obj::_int((double((double(x) / double((int)30))) / double((int)2))));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",214)
		if (((index >= this->bubblePool->length))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",214)
			return null();
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",216)
		bubble = this->bubblePool->__get(index);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",218)
		if (((bubble->size != (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",219)
			Array< int > data = Array_obj< int >::__new().Add(::Std_obj::_int(bubble->position->x)).Add(::Std_obj::_int(bubble->position->y));
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",220)
			this->dispatchEvent(::com::mybo::common::GameEvent_obj::__new(HX_CSTRING("bubbleTouched"),data));
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",222)
			bubble->grow();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",223)
			if ((bubble->blasted)){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",224)
				this->blast(bubble);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",225)
				this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",226)
				this->dispatchEvent(::nme::events::Event_obj::__new(HX_CSTRING("bubbleTapCompleted"),null(),null()));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,onTap,(void))

Void GameBoard_obj::blast( ::com::mybo::gamescene::Bubble bubble){
{
		HX_SOURCE_PUSH("GameBoard_obj::blast")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",233)
		this->removeEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onTap_dyn(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",235)
		double x = (bubble->nmeGetX() + (int)30);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",236)
		double y = (bubble->nmeGetY() + (int)30);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",237)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",237)
			int _g = (int)0;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",237)
			while(((_g < (int)4))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",237)
				int i = (_g)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",238)
				::com::mybo::gamescene::BlastNode node = ::com::mybo::gamescene::BlastNode_obj::__new(i,x,y);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",239)
				if ((this->isLegalBlastNode(node))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",239)
					this->blastNodePool->push(node);
				}
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",242)
		this->dispatchEvent(::nme::events::Event_obj::__new(HX_CSTRING("bubbleBlast"),null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,blast,(void))

Void GameBoard_obj::onEnterFrame( ::nme::events::Event e){
{
		HX_SOURCE_PUSH("GameBoard_obj::onEnterFrame")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",246)
		(this->frames)++;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",247)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",247)
			int _g1 = (int)0;
			int _g = this->blastNodePool->length;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",247)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",247)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",248)
				if ((((int)0 == this->blastNodePool->__get(i)->dir))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",248)
					hx::SubEq(this->blastNodePool->__get(i)->y,this->flySpeed);
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",250)
					if ((((int)1 == this->blastNodePool->__get(i)->dir))){
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",250)
						hx::AddEq(this->blastNodePool->__get(i)->x,this->flySpeed);
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",252)
						if ((((int)2 == this->blastNodePool->__get(i)->dir))){
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",252)
							hx::AddEq(this->blastNodePool->__get(i)->y,this->flySpeed);
						}
						else{
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",254)
							if ((((int)3 == this->blastNodePool->__get(i)->dir))){
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",254)
								hx::SubEq(this->blastNodePool->__get(i)->x,this->flySpeed);
							}
						}
					}
				}
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",259)
		if (((hx::Mod((this->frames * this->flySpeed),(int)60) == (int)0))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",260)
			this->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",261)
			this->blastChainCheck();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",262)
			if ((this->isBlastChainComplete())){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",263)
				this->frames = (int)0;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",264)
				if ((!(this->checkLevelFinished()))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",265)
					this->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,this->onTap_dyn(),null(),null(),null());
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",266)
					this->dispatchEvent(::nme::events::Event_obj::__new(HX_CSTRING("bubbleTapCompleted"),null(),null()));
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",267)
					this->dispatchEvent(::nme::events::Event_obj::__new(HX_CSTRING("levelComplete"),null(),null()));
				}
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",270)
				this->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",274)
		this->draw();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,onEnterFrame,(void))

Void GameBoard_obj::blastChainCheck( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::blastChainCheck")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",278)
		int len = this->blastNodePool->length;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",279)
		int i = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",280)
		while(((i < len))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",281)
			if ((!(this->isLegalBlastNode(this->blastNodePool->__get(i))))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",282)
				this->blastNodePool->remove(this->blastNodePool->__get(i));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",283)
				(len)--;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",284)
				(i)--;
			}
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",286)
			(i)++;
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",288)
		Array< ::com::mybo::gamescene::BlastNode > blastNodes = this->blastNodePool->copy();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",291)
		int len1 = blastNodes->length;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",292)
		int x;
		int y;
		int x1;
		int y1;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",293)
		::com::mybo::gamescene::BlastNode tempNode;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",294)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",294)
			int _g1 = (int)0;
			int _g = (len1 - (int)1);
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",294)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",294)
				int i1 = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",295)
				{
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",295)
					int _g3 = (int)0;
					int _g2 = ((len1 - (int)1) - i1);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",295)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",295)
						int j = (_g3)++;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",296)
						x = ::Std_obj::_int((double(((blastNodes->__get(j)->x - (int)30))) / double((int)60)));
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",297)
						y = ::Std_obj::_int((double(((blastNodes->__get(j)->y - (int)30))) / double((int)60)));
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",298)
						x1 = ::Std_obj::_int((double(((blastNodes->__get((j + (int)1))->x - (int)30))) / double((int)60)));
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",299)
						y1 = ::Std_obj::_int((double(((blastNodes->__get((j + (int)1))->y - (int)30))) / double((int)60)));
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",300)
						int size1 = (int)0;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",301)
						int size2 = (int)0;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",302)
						{
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",302)
							int _g5 = (int)0;
							int _g4 = this->bubblePool->length;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",302)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",302)
								int m = (_g5)++;
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",303)
								if (((bool((this->bubblePool->__get(m)->position->x == y)) && bool((this->bubblePool->__get(m)->position->y == x))))){
									HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",303)
									size1 = this->bubblePool->__get(m)->size;
								}
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",306)
								if (((bool((this->bubblePool->__get(m)->position->x == y1)) && bool((this->bubblePool->__get(m)->position->y == x1))))){
									HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",306)
									size2 = this->bubblePool->__get(m)->size;
								}
							}
						}
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",310)
						if (((size1 < size2))){
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",311)
							tempNode = blastNodes->__get(j);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",312)
							blastNodes[j] = blastNodes->__get((j + (int)1));
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",313)
							blastNodes[(j + (int)1)] = tempNode;
						}
					}
				}
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",332)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",332)
			int _g1 = (int)0;
			int _g = blastNodes->length;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",332)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",332)
				int i1 = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",333)
				if ((!(this->isLegalBlastNode(blastNodes->__get(i1))))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",334)
					this->blastNodePool->remove(blastNodes->__get(i1));
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",335)
					::haxe::Log_obj::trace(HX_CSTRING("remove error"),hx::SourceInfo(HX_CSTRING("GameBoard.hx"),335,HX_CSTRING("com.mybo.gamescene.GameBoard"),HX_CSTRING("blastChainCheck")));
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",336)
					continue;
				}
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",338)
				{
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",338)
					int _g3 = (int)0;
					int _g2 = this->bubblePool->length;
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",338)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",338)
						int j = (_g3)++;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",339)
						if ((this->collisionDetection(this->bubblePool->__get(j),blastNodes->__get(i1)))){
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",339)
							if (((this->bubblePool->__get(j)->size != (int)0))){
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",341)
								this->bubblePool->__get(j)->grow();
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",342)
								if ((this->bubblePool->__get(j)->blasted)){
									HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",342)
									this->blast(this->bubblePool->__get(j));
								}
								HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",345)
								this->blastNodePool->remove(blastNodes->__get(i1));
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,blastChainCheck,(void))

int GameBoard_obj::nodeSort( ::com::mybo::gamescene::BlastNode nodeA,::com::mybo::gamescene::BlastNode nodeB){
	HX_SOURCE_PUSH("GameBoard_obj::nodeSort")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",353)
	int x;
	int y;
	int x1;
	int y1;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",354)
	x = ::Std_obj::_int((double(nodeA->x) / double((int)60)));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",355)
	y = ::Std_obj::_int((double(nodeA->y) / double((int)60)));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",356)
	x1 = ::Std_obj::_int((double(nodeB->x) / double((int)60)));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",357)
	y1 = ::Std_obj::_int((double(nodeB->y) / double((int)60)));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",359)
	if (((this->map->data->__get(y)->__get(x) < this->map->data->__get(y1)->__get(x1)))){
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",359)
		return (int)1;
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",361)
		return (int)-1;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(GameBoard_obj,nodeSort,return )

bool GameBoard_obj::isBlastChainComplete( ){
	HX_SOURCE_PUSH("GameBoard_obj::isBlastChainComplete")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",366)
	return (this->blastNodePool->length == (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,isBlastChainComplete,return )

bool GameBoard_obj::checkLevelFinished( ){
	HX_SOURCE_PUSH("GameBoard_obj::checkLevelFinished")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",371)
	bool rs = true;
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",372)
	{
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",372)
		int _g1 = (int)0;
		int _g = this->bubblePool->length;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",372)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",372)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",373)
			if (((this->bubblePool->__get(i)->size != (int)0))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",374)
				rs = false;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",375)
				break;
			}
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",378)
	return rs;
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,checkLevelFinished,return )

Void GameBoard_obj::draw( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::draw")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",383)
		Array< int > indices = Array_obj< int >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",384)
		Array< double > vertices = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",385)
		Array< double > uvdatas = Array_obj< double >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",387)
		::nme::display::BitmapData texture = ::com::mybo::framework::core::Facade_obj::getInstance()->getBitmap(HX_CSTRING("pp6"),null())->bitmapData;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",388)
		double x;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",389)
		double y;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",390)
		double w;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",391)
		double h;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",392)
		::com::mybo::gamescene::BlastNode node;
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",394)
		double textureWidth = (double(texture->nmeGetWidth()) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",395)
		double textureHeight = (double(texture->nmeGetHeight()) / double(::com::mybo::framework::core::Facade_obj::contentScaleFactor));
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",397)
		this->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",398)
		this->nmeGetGraphics()->beginBitmapFill(texture,null(),false,false);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",401)
		{
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",401)
			int _g1 = (int)0;
			int _g = this->blastNodePool->length;
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",401)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",401)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",402)
				node = this->blastNodePool->__get(i);
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",403)
				x = node->x;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",404)
				y = node->y;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",406)
				indices->push(((int)4 * i));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",407)
				indices->push((((int)4 * i) + (int)1));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",408)
				indices->push((((int)4 * i) + (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",409)
				indices->push(((int)4 * i));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",410)
				indices->push((((int)4 * i) + (int)2));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",411)
				indices->push((((int)4 * i) + (int)3));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",413)
				if ((((int)1 == node->dir))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",414)
					x = (node->x - textureHeight);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",415)
					y = (node->y - (double(textureWidth) / double((int)2)));
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",416)
					w = textureHeight;
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",417)
					h = textureWidth;
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",419)
					uvdatas->push((int)0);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",420)
					uvdatas->push((int)1);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",421)
					uvdatas->push((int)0);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",422)
					uvdatas->push((int)0);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",423)
					uvdatas->push((int)1);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",424)
					uvdatas->push((int)0);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",425)
					uvdatas->push((int)1);
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",426)
					uvdatas->push((int)1);
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",429)
					if ((((int)2 == node->dir))){
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",430)
						x = (node->x - (double(textureWidth) / double((int)2)));
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",431)
						y = (node->y - textureHeight);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",432)
						w = textureWidth;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",433)
						h = textureHeight;
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",435)
						uvdatas->push((int)1);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",436)
						uvdatas->push((int)1);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",437)
						uvdatas->push((int)0);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",438)
						uvdatas->push((int)1);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",439)
						uvdatas->push((int)0);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",440)
						uvdatas->push((int)0);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",441)
						uvdatas->push((int)1);
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",442)
						uvdatas->push((int)0);
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",445)
						if ((((int)3 == node->dir))){
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",446)
							x = node->x;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",447)
							y = (node->y - (double(textureWidth) / double((int)2)));
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",448)
							w = textureHeight;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",449)
							h = textureWidth;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",451)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",452)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",453)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",454)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",455)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",456)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",457)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",458)
							uvdatas->push((int)0);
						}
						else{
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",461)
							x = (node->x - (double(textureWidth) / double((int)2)));
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",462)
							y = node->y;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",463)
							w = textureWidth;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",464)
							h = textureHeight;
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",466)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",467)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",468)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",469)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",470)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",471)
							uvdatas->push((int)1);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",472)
							uvdatas->push((int)0);
							HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",473)
							uvdatas->push((int)1);
						}
					}
				}
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",477)
				vertices->push((x * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",478)
				vertices->push((y * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",479)
				vertices->push((((x + w)) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",480)
				vertices->push((y * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",481)
				vertices->push((((x + w)) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",482)
				vertices->push((((y + h)) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",483)
				vertices->push((x * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",484)
				vertices->push((((y + h)) * ::com::mybo::framework::core::Facade_obj::contentScaleFactor));
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",486)
		this->nmeGetGraphics()->drawTriangles(vertices,indices,uvdatas,::nme::display::TriangleCulling_obj::NONE_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",487)
		this->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,draw,(void))

bool GameBoard_obj::isLegalBlastNode( ::com::mybo::gamescene::BlastNode node){
	HX_SOURCE_PUSH("GameBoard_obj::isLegalBlastNode")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",540)
	return (bool((bool((bool(((int)0 < node->x)) && bool((node->x < (int)300)))) && bool(((int)0 < node->y)))) && bool((node->y < (int)360)));
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,isLegalBlastNode,return )

bool GameBoard_obj::collisionDetection( ::com::mybo::gamescene::Bubble bubble,::com::mybo::gamescene::BlastNode blastNode){
	HX_SOURCE_PUSH("GameBoard_obj::collisionDetection")
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",548)
	int x = ::Std_obj::_int((double(((blastNode->x - (int)30))) / double((int)60)));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",549)
	int y = ::Std_obj::_int((double(((blastNode->y - (int)30))) / double((int)60)));
	HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",550)
	return (bool((bubble->position->x == y)) && bool((bubble->position->y == x)));
}


HX_DEFINE_DYNAMIC_FUNC2(GameBoard_obj,collisionDetection,return )

Void GameBoard_obj::emptyArray( Dynamic array){
{
		HX_SOURCE_PUSH("GameBoard_obj::emptyArray")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",553)
		if (((null() != array))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",555)
			int len = array->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",556)
			{
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",556)
				int _g = (int)0;
				HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",556)
				while(((_g < len))){
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",556)
					int i = (_g)++;
					HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",557)
					hx::IndexRef((array).mPtr,i) = null();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameBoard_obj,emptyArray,(void))

Void GameBoard_obj::drawTouchArea( ){
{
		HX_SOURCE_PUSH("GameBoard_obj::drawTouchArea")
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",564)
		if (((null() == this->touchLayer))){
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",565)
			this->touchLayer = ::nme::display::Sprite_obj::__new();
			HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",566)
			this->addChild(this->touchLayer);
		}
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",569)
		this->touchLayer->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",570)
		this->touchLayer->nmeGetGraphics()->beginFill((int)16777215,(int)0);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",572)
		this->touchLayer->nmeGetGraphics()->drawRect((int)0,(int)0,(int)300,(int)360);
		HX_SOURCE_POS("../../../src/com/mybo/gamescene/GameBoard.hx",573)
		this->touchLayer->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameBoard_obj,drawTouchArea,(void))

int GameBoard_obj::gameBoardWidth;

int GameBoard_obj::gameBoardHeight;


GameBoard_obj::GameBoard_obj()
{
}

void GameBoard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameBoard);
	HX_MARK_MEMBER_NAME(map,"map");
	HX_MARK_MEMBER_NAME(flySpeed,"flySpeed");
	HX_MARK_MEMBER_NAME(bubblePool,"bubblePool");
	HX_MARK_MEMBER_NAME(blastNodePool,"blastNodePool");
	HX_MARK_MEMBER_NAME(touchAble,"touchAble");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(bubbleLayer,"bubbleLayer");
	HX_MARK_MEMBER_NAME(bubbleTextureID,"bubbleTextureID");
	HX_MARK_MEMBER_NAME(genBubbleFlag,"genBubbleFlag");
	HX_MARK_MEMBER_NAME(genBubbleCount,"genBubbleCount");
	HX_MARK_MEMBER_NAME(touchLayer,"touchLayer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic GameBoard_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { return map; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		if (HX_FIELD_EQ(inName,"clean") ) { return clean_dyn(); }
		if (HX_FIELD_EQ(inName,"onTap") ) { return onTap_dyn(); }
		if (HX_FIELD_EQ(inName,"blast") ) { return blast_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"resume") ) { return resume_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"disable") ) { return disable_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flySpeed") ) { return flySpeed; }
		if (HX_FIELD_EQ(inName,"nodeSort") ) { return nodeSort_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"touchAble") ) { return touchAble; }
		if (HX_FIELD_EQ(inName,"genBubble") ) { return genBubble_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bubblePool") ) { return bubblePool; }
		if (HX_FIELD_EQ(inName,"startTouch") ) { return startTouch_dyn(); }
		if (HX_FIELD_EQ(inName,"getBubbles") ) { return getBubbles_dyn(); }
		if (HX_FIELD_EQ(inName,"emptyArray") ) { return emptyArray_dyn(); }
		if (HX_FIELD_EQ(inName,"touchLayer") ) { return touchLayer; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bubbleLayer") ) { return bubbleLayer; }
		if (HX_FIELD_EQ(inName,"motionClean") ) { return motionClean_dyn(); }
		if (HX_FIELD_EQ(inName,"cleanTimers") ) { return cleanTimers_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"blastNodePool") ) { return blastNodePool; }
		if (HX_FIELD_EQ(inName,"genBubbleFlag") ) { return genBubbleFlag; }
		if (HX_FIELD_EQ(inName,"drawTouchArea") ) { return drawTouchArea_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gameBoardWidth") ) { return gameBoardWidth; }
		if (HX_FIELD_EQ(inName,"genBubbleCount") ) { return genBubbleCount; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"gameBoardHeight") ) { return gameBoardHeight; }
		if (HX_FIELD_EQ(inName,"bubbleTextureID") ) { return bubbleTextureID; }
		if (HX_FIELD_EQ(inName,"blastChainCheck") ) { return blastChainCheck_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"isLegalBlastNode") ) { return isLegalBlastNode_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setBubbleTextureID") ) { return setBubbleTextureID_dyn(); }
		if (HX_FIELD_EQ(inName,"checkLevelFinished") ) { return checkLevelFinished_dyn(); }
		if (HX_FIELD_EQ(inName,"collisionDetection") ) { return collisionDetection_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"isBlastChainComplete") ) { return isBlastChainComplete_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic GameBoard_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { map=inValue.Cast< ::com::mybo::data::Map >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flySpeed") ) { flySpeed=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"touchAble") ) { touchAble=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bubblePool") ) { bubblePool=inValue.Cast< Array< ::com::mybo::gamescene::Bubble > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchLayer") ) { touchLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bubbleLayer") ) { bubbleLayer=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"blastNodePool") ) { blastNodePool=inValue.Cast< Array< ::com::mybo::gamescene::BlastNode > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"genBubbleFlag") ) { genBubbleFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gameBoardWidth") ) { gameBoardWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"genBubbleCount") ) { genBubbleCount=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"gameBoardHeight") ) { gameBoardHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bubbleTextureID") ) { bubbleTextureID=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameBoard_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("map"));
	outFields->push(HX_CSTRING("flySpeed"));
	outFields->push(HX_CSTRING("bubblePool"));
	outFields->push(HX_CSTRING("blastNodePool"));
	outFields->push(HX_CSTRING("touchAble"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("bubbleLayer"));
	outFields->push(HX_CSTRING("bubbleTextureID"));
	outFields->push(HX_CSTRING("genBubbleFlag"));
	outFields->push(HX_CSTRING("genBubbleCount"));
	outFields->push(HX_CSTRING("touchLayer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("gameBoardWidth"),
	HX_CSTRING("gameBoardHeight"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("map"),
	HX_CSTRING("flySpeed"),
	HX_CSTRING("bubblePool"),
	HX_CSTRING("blastNodePool"),
	HX_CSTRING("touchAble"),
	HX_CSTRING("frames"),
	HX_CSTRING("bubbleLayer"),
	HX_CSTRING("bubbleTextureID"),
	HX_CSTRING("genBubbleFlag"),
	HX_CSTRING("genBubbleCount"),
	HX_CSTRING("init"),
	HX_CSTRING("genBubble"),
	HX_CSTRING("setBubbleTextureID"),
	HX_CSTRING("pause"),
	HX_CSTRING("resume"),
	HX_CSTRING("disable"),
	HX_CSTRING("startTouch"),
	HX_CSTRING("motionClean"),
	HX_CSTRING("clean"),
	HX_CSTRING("cleanTimers"),
	HX_CSTRING("getBubbles"),
	HX_CSTRING("onTap"),
	HX_CSTRING("blast"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("blastChainCheck"),
	HX_CSTRING("nodeSort"),
	HX_CSTRING("isBlastChainComplete"),
	HX_CSTRING("checkLevelFinished"),
	HX_CSTRING("draw"),
	HX_CSTRING("isLegalBlastNode"),
	HX_CSTRING("collisionDetection"),
	HX_CSTRING("emptyArray"),
	HX_CSTRING("touchLayer"),
	HX_CSTRING("drawTouchArea"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameBoard_obj::gameBoardWidth,"gameBoardWidth");
	HX_MARK_MEMBER_NAME(GameBoard_obj::gameBoardHeight,"gameBoardHeight");
};

Class GameBoard_obj::__mClass;

void GameBoard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.gamescene.GameBoard"), hx::TCanCast< GameBoard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameBoard_obj::__boot()
{
	hx::Static(gameBoardWidth) = (int)300;
	hx::Static(gameBoardHeight) = (int)360;
}

} // end namespace com
} // end namespace mybo
} // end namespace gamescene
