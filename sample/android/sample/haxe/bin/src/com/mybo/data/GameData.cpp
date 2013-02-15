#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_mybo_data_GameData
#include <com/mybo/data/GameData.h>
#endif
namespace com{
namespace mybo{
namespace data{

Void GameData_obj::__construct()
{
	return null();
}

GameData_obj::~GameData_obj() { }

Dynamic GameData_obj::__CreateEmpty() { return  new GameData_obj; }
hx::ObjectPtr< GameData_obj > GameData_obj::__new()
{  hx::ObjectPtr< GameData_obj > result = new GameData_obj();
	result->__construct();
	return result;}

Dynamic GameData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameData_obj > result = new GameData_obj();
	result->__construct();
	return result;}

int GameData_obj::PUZZLE_TIP_VALUE;

int GameData_obj::MASTER_TIP_VALUE;

int GameData_obj::MASTER_UNLOCK_VALUE;

int GameData_obj::PUZZLE_PACK_VALUE;

::String GameData_obj::bubbleTextureID;

int GameData_obj::getMasterReward( ){
	HX_SOURCE_PUSH("GameData_obj::getMasterReward")
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",13)
	double random = ::Math_obj::random();
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",14)
	int rs = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",16)
	{
		HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",16)
		int _g = (int)1;
		HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",16)
		while(((_g < (int)8))){
			HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",16)
			int i = (_g)++;
			HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",17)
			if (((bool((random >= ::Math_obj::pow(0.5,i))) && bool((random < ::Math_obj::pow(0.5,(i - (int)1))))))){
				HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",18)
				rs = (i + (int)1);
				HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",19)
				break;
			}
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",23)
	return (rs * (int)10);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GameData_obj,getMasterReward,return )

int GameData_obj::getClassicReward( int score){
	HX_SOURCE_PUSH("GameData_obj::getClassicReward")
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",27)
	int rs = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",28)
	if (((score >= (int)50000))){
		HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",28)
		rs = (int)5;
	}
	else{
		HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",30)
		if (((score >= (int)35000))){
			HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",30)
			rs = (int)4;
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",32)
			if (((score >= (int)25000))){
				HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",32)
				rs = (int)3;
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",34)
				if (((score >= (int)18000))){
					HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",34)
					rs = (int)2;
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",36)
					if (((score >= (int)10000))){
						HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",36)
						rs = (int)1;
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/GameData.hx",40)
	return rs;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GameData_obj,getClassicReward,return )


GameData_obj::GameData_obj()
{
}

void GameData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameData);
	HX_MARK_END_CLASS();
}

Dynamic GameData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"bubbleTextureID") ) { return bubbleTextureID; }
		if (HX_FIELD_EQ(inName,"getMasterReward") ) { return getMasterReward_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"PUZZLE_TIP_VALUE") ) { return PUZZLE_TIP_VALUE; }
		if (HX_FIELD_EQ(inName,"MASTER_TIP_VALUE") ) { return MASTER_TIP_VALUE; }
		if (HX_FIELD_EQ(inName,"getClassicReward") ) { return getClassicReward_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"PUZZLE_PACK_VALUE") ) { return PUZZLE_PACK_VALUE; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"MASTER_UNLOCK_VALUE") ) { return MASTER_UNLOCK_VALUE; }
	}
	return super::__Field(inName);
}

Dynamic GameData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"bubbleTextureID") ) { bubbleTextureID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"PUZZLE_TIP_VALUE") ) { PUZZLE_TIP_VALUE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MASTER_TIP_VALUE") ) { MASTER_TIP_VALUE=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"PUZZLE_PACK_VALUE") ) { PUZZLE_PACK_VALUE=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"MASTER_UNLOCK_VALUE") ) { MASTER_UNLOCK_VALUE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void GameData_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PUZZLE_TIP_VALUE"),
	HX_CSTRING("MASTER_TIP_VALUE"),
	HX_CSTRING("MASTER_UNLOCK_VALUE"),
	HX_CSTRING("PUZZLE_PACK_VALUE"),
	HX_CSTRING("bubbleTextureID"),
	HX_CSTRING("getMasterReward"),
	HX_CSTRING("getClassicReward"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameData_obj::PUZZLE_TIP_VALUE,"PUZZLE_TIP_VALUE");
	HX_MARK_MEMBER_NAME(GameData_obj::MASTER_TIP_VALUE,"MASTER_TIP_VALUE");
	HX_MARK_MEMBER_NAME(GameData_obj::MASTER_UNLOCK_VALUE,"MASTER_UNLOCK_VALUE");
	HX_MARK_MEMBER_NAME(GameData_obj::PUZZLE_PACK_VALUE,"PUZZLE_PACK_VALUE");
	HX_MARK_MEMBER_NAME(GameData_obj::bubbleTextureID,"bubbleTextureID");
};

Class GameData_obj::__mClass;

void GameData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.data.GameData"), hx::TCanCast< GameData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void GameData_obj::__boot()
{
	hx::Static(PUZZLE_TIP_VALUE) = (int)10;
	hx::Static(MASTER_TIP_VALUE) = (int)70;
	hx::Static(MASTER_UNLOCK_VALUE) = (int)10;
	hx::Static(PUZZLE_PACK_VALUE) = (int)50;
	hx::Static(bubbleTextureID) = HX_CSTRING("pp");
}

} // end namespace com
} // end namespace mybo
} // end namespace data
