#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Controller
#include <com/mybo/framework/core/Controller.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Facade
#include <com/mybo/framework/core/Facade.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_Scene
#include <com/mybo/framework/core/Scene.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_SceneNode
#include <com/mybo/framework/core/SceneNode.h>
#endif
#ifndef INCLUDED_com_mybo_framework_core_View
#include <com/mybo/framework/core/View.h>
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
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nmex_display_DisplayObject
#include <nmex/display/DisplayObject.h>
#endif
namespace com{
namespace mybo{
namespace framework{
namespace core{

Void Controller_obj::__construct()
{
{
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",19)
	this->nodes = Array_obj< ::com::mybo::framework::core::SceneNode >::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",20)
	this->sleepScenes = ::Hash_obj::__new();
	HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",21)
	this->backStatus = false;
}
;
	return null();
}

Controller_obj::~Controller_obj() { }

Dynamic Controller_obj::__CreateEmpty() { return  new Controller_obj; }
hx::ObjectPtr< Controller_obj > Controller_obj::__new()
{  hx::ObjectPtr< Controller_obj > result = new Controller_obj();
	result->__construct();
	return result;}

Dynamic Controller_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Controller_obj > result = new Controller_obj();
	result->__construct();
	return result;}

Void Controller_obj::run( ::Class classRef,Dynamic args){
{
		HX_SOURCE_PUSH("Controller_obj::run")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",24)
		this->nextSceneClassRef = classRef;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",25)
		this->nextSceneArgs = args;
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",26)
		if (((null() == this->currentScene))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",27)
			this->currentScene = ::Type_obj::createInstance(classRef,args);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",28)
			::com::mybo::framework::core::Facade_obj::getInstance()->getView()->addPage(this->currentScene);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",29)
			this->currentScene->sceneDidAppear();
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",31)
			::com::mybo::framework::core::Facade_obj::getInstance()->getView()->runPageMotion();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Controller_obj,run,(void))

Void Controller_obj::back( Dynamic args){
{
		HX_SOURCE_PUSH("Controller_obj::back")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",37)
		::com::mybo::framework::core::SceneNode preNode = this->nodes->shift();
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",39)
		if (((null() != preNode))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",40)
			::String preClassName = ::Type_obj::getClassName(preNode->sceneRef);
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",42)
			if ((this->sleepScenes->exists(preClassName))){
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",44)
				if ((this->currentScene->sleepAble)){
					HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",44)
					this->currentScene->sleep();
				}
				else{
					HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",46)
					this->currentScene->destroy();
				}
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",50)
				::com::mybo::framework::core::Scene scene = this->sleepScenes->get(preClassName);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",51)
				this->sleepScenes->remove(preClassName);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",52)
				this->currentScene = scene;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",53)
				::com::mybo::framework::core::Facade_obj::getInstance()->getView()->switchPage(this->currentScene);
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",54)
				this->currentScene->wakeup();
			}
			else{
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",56)
				this->backStatus = true;
				HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",57)
				this->run(preNode->sceneRef,args);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Controller_obj,back,(void))

Void Controller_obj::updateCurrentScene( ){
{
		HX_SOURCE_PUSH("Controller_obj::updateCurrentScene")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",63)
		if ((this->backStatus)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",63)
			this->backStatus = false;
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",65)
			this->markNode(::Type_obj::getClass(this->currentScene),this->nextSceneArgs);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",68)
		if ((this->currentScene->sleepAble)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",68)
			this->currentScene->sleep();
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",70)
			this->currentScene->destroy();
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",74)
		if (((this->nextSceneArgs == null()))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",74)
			this->currentScene = ::Type_obj::createInstance(this->nextSceneClassRef,Dynamic( Array_obj<Dynamic>::__new()));
		}
		else{
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",76)
			this->currentScene = ::Type_obj::createInstance(this->nextSceneClassRef,this->nextSceneArgs);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Controller_obj,updateCurrentScene,(void))

Void Controller_obj::runCurrentScene( ){
{
		HX_SOURCE_PUSH("Controller_obj::runCurrentScene")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",82)
		this->currentScene->sceneDidAppear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Controller_obj,runCurrentScene,(void))

Void Controller_obj::markNode( ::Class classRef,Dynamic args){
{
		HX_SOURCE_PUSH("Controller_obj::markNode")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",88)
		if ((this->currentScene->sleepAble)){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",88)
			this->sleepScenes->set(::Type_obj::getClassName(classRef),this->currentScene);
		}
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",91)
		::com::mybo::framework::core::SceneNode currentNode = ::com::mybo::framework::core::SceneNode_obj::__new(classRef,args);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",92)
		this->nodes->unshift(currentNode);
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",93)
		if (((this->nodes->length > (int)9))){
			HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",93)
			this->nodes->pop();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Controller_obj,markNode,(void))

Void Controller_obj::addSleepScene( ::com::mybo::framework::core::Scene scene){
{
		HX_SOURCE_PUSH("Controller_obj::addSleepScene")
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",96)
		::String name = ::Type_obj::getClassName(::Type_obj::getClass(scene));
		HX_SOURCE_POS("../../../framework/com/mybo/framework/core/Controller.hx",97)
		this->sleepScenes->set(name,scene);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Controller_obj,addSleepScene,(void))

int Controller_obj::NODE_LENGTH;


Controller_obj::Controller_obj()
{
}

void Controller_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Controller);
	HX_MARK_MEMBER_NAME(currentScene,"currentScene");
	HX_MARK_MEMBER_NAME(nextSceneClassRef,"nextSceneClassRef");
	HX_MARK_MEMBER_NAME(nextSceneArgs,"nextSceneArgs");
	HX_MARK_MEMBER_NAME(nodes,"nodes");
	HX_MARK_MEMBER_NAME(sleepScenes,"sleepScenes");
	HX_MARK_MEMBER_NAME(backStatus,"backStatus");
	HX_MARK_END_CLASS();
}

Dynamic Controller_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"back") ) { return back_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nodes") ) { return nodes; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"markNode") ) { return markNode_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"backStatus") ) { return backStatus; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NODE_LENGTH") ) { return NODE_LENGTH; }
		if (HX_FIELD_EQ(inName,"sleepScenes") ) { return sleepScenes; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentScene") ) { return currentScene; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nextSceneArgs") ) { return nextSceneArgs; }
		if (HX_FIELD_EQ(inName,"addSleepScene") ) { return addSleepScene_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"runCurrentScene") ) { return runCurrentScene_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nextSceneClassRef") ) { return nextSceneClassRef; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"updateCurrentScene") ) { return updateCurrentScene_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Controller_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"nodes") ) { nodes=inValue.Cast< Array< ::com::mybo::framework::core::SceneNode > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"backStatus") ) { backStatus=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NODE_LENGTH") ) { NODE_LENGTH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sleepScenes") ) { sleepScenes=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentScene") ) { currentScene=inValue.Cast< ::com::mybo::framework::core::Scene >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nextSceneArgs") ) { nextSceneArgs=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nextSceneClassRef") ) { nextSceneClassRef=inValue.Cast< ::Class >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Controller_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentScene"));
	outFields->push(HX_CSTRING("nextSceneClassRef"));
	outFields->push(HX_CSTRING("nextSceneArgs"));
	outFields->push(HX_CSTRING("nodes"));
	outFields->push(HX_CSTRING("sleepScenes"));
	outFields->push(HX_CSTRING("backStatus"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NODE_LENGTH"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("currentScene"),
	HX_CSTRING("nextSceneClassRef"),
	HX_CSTRING("nextSceneArgs"),
	HX_CSTRING("nodes"),
	HX_CSTRING("sleepScenes"),
	HX_CSTRING("backStatus"),
	HX_CSTRING("run"),
	HX_CSTRING("back"),
	HX_CSTRING("updateCurrentScene"),
	HX_CSTRING("runCurrentScene"),
	HX_CSTRING("markNode"),
	HX_CSTRING("addSleepScene"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Controller_obj::NODE_LENGTH,"NODE_LENGTH");
};

Class Controller_obj::__mClass;

void Controller_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.framework.core.Controller"), hx::TCanCast< Controller_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Controller_obj::__boot()
{
	hx::Static(NODE_LENGTH) = (int)10;
}

} // end namespace com
} // end namespace mybo
} // end namespace framework
} // end namespace core
