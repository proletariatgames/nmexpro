#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_com_mybo_data_Map
#include <com/mybo/data/Map.h>
#endif
#ifndef INCLUDED_com_mybo_data_MapFactory
#include <com/mybo/data/MapFactory.h>
#endif
#ifndef INCLUDED_com_mybo_data_UserData
#include <com/mybo/data/UserData.h>
#endif
#ifndef INCLUDED_com_mybo_framework_utils_FileAction
#include <com/mybo/framework/utils/FileAction.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
namespace com{
namespace mybo{
namespace data{

Void UserData_obj::__construct()
{
{
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",31)
	this->paidTips = Array_obj< Array< int > >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",32)
	this->unlockedPacks = Array_obj< int >::__new().Add((int)1);
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",34)
	this->bestScore = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",35)
	this->music = true;
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",36)
	this->stars = (int)5;
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",38)
	this->puzzleTotalScore = (int)0;
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",39)
	this->levelScoreHash = ::Hash_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",41)
	this->completedOfPack = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",42)
	this->packAmount = ::com::mybo::data::MapFactory_obj::getPuzzlePackConut();
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",43)
	{
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",43)
		int _g1 = (int)0;
		int _g = this->packAmount;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",43)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",43)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",44)
			this->completedOfPack[i] = (int)0;
		}
	}
}
;
	return null();
}

UserData_obj::~UserData_obj() { }

Dynamic UserData_obj::__CreateEmpty() { return  new UserData_obj; }
hx::ObjectPtr< UserData_obj > UserData_obj::__new()
{  hx::ObjectPtr< UserData_obj > result = new UserData_obj();
	result->__construct();
	return result;}

Dynamic UserData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UserData_obj > result = new UserData_obj();
	result->__construct();
	return result;}

bool UserData_obj::isFirstRun( ){
	HX_SOURCE_PUSH("UserData_obj::isFirstRun")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",58)
	return (this->puzzleTotalScore == (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,isFirstRun,return )

int UserData_obj::getLevelScore( int pack,int level){
	HX_SOURCE_PUSH("UserData_obj::getLevelScore")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",65)
	::String id = this->creatID(pack,level);
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",66)
	int score = this->levelScoreHash->get(id);
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",67)
	score = (  (((score == null()))) ? int((int)0) : int(score) );
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",69)
	return score;
}


HX_DEFINE_DYNAMIC_FUNC2(UserData_obj,getLevelScore,return )

Void UserData_obj::setLevelScore( int pack,int level,int score){
{
		HX_SOURCE_PUSH("UserData_obj::setLevelScore")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",73)
		::String id = this->creatID(pack,level);
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",74)
		this->levelScoreHash->set(id,score);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(UserData_obj,setLevelScore,(void))

int UserData_obj::getPuzzleTotalScore( ){
	HX_SOURCE_PUSH("UserData_obj::getPuzzleTotalScore")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",77)
	return this->puzzleTotalScore;
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,getPuzzleTotalScore,return )

Void UserData_obj::setPuzzleTotalScore( int score){
{
		HX_SOURCE_PUSH("UserData_obj::setPuzzleTotalScore")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",82)
		this->puzzleTotalScore = score;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",83)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,setPuzzleTotalScore,(void))

::com::mybo::data::Map UserData_obj::getMasterMap( ){
	HX_SOURCE_PUSH("UserData_obj::getMasterMap")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",87)
	return this->masterMap;
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,getMasterMap,return )

Void UserData_obj::setMasterMap( ::com::mybo::data::Map map){
{
		HX_SOURCE_PUSH("UserData_obj::setMasterMap")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",92)
		this->masterMap = map;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",93)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,setMasterMap,(void))

bool UserData_obj::useStar( int star){
	HX_SOURCE_PUSH("UserData_obj::useStar")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",100)
	if (((this->stars >= star))){
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",101)
		this->setStar((this->stars - star));
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",102)
		return true;
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",104)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,useStar,return )

Void UserData_obj::addStar( int star){
{
		HX_SOURCE_PUSH("UserData_obj::addStar")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",107)
		this->setStar((this->stars + star));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,addStar,(void))

Void UserData_obj::setStar( int value){
{
		HX_SOURCE_PUSH("UserData_obj::setStar")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",112)
		this->stars = value;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",113)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,setStar,(void))

int UserData_obj::getStar( ){
	HX_SOURCE_PUSH("UserData_obj::getStar")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",116)
	return this->stars;
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,getStar,return )

int UserData_obj::getPackCompleted( int pack){
	HX_SOURCE_PUSH("UserData_obj::getPackCompleted")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",123)
	return this->completedOfPack->__get(pack);
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,getPackCompleted,return )

Void UserData_obj::setPackCompleted( int pack,int value){
{
		HX_SOURCE_PUSH("UserData_obj::setPackCompleted")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",128)
		if (((this->completedOfPack->__get(pack) < value))){
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",128)
			this->completedOfPack[pack] = value;
		}
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",131)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UserData_obj,setPackCompleted,(void))

Void UserData_obj::unlockPack( int pack){
{
		HX_SOURCE_PUSH("UserData_obj::unlockPack")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",135)
		if (((bool(!(this->isPackUnlocked(pack))) && bool((this->unlockedPacks->length < this->packAmount))))){
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",135)
			this->unlockedPacks->push(pack);
		}
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",138)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,unlockPack,(void))

Void UserData_obj::unlockNextPack( ){
{
		HX_SOURCE_PUSH("UserData_obj::unlockNextPack")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",142)
		if (((this->unlockedPacks->length < this->packAmount))){
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",142)
			this->unlockedPacks->push((this->unlockedPacks->length + (int)1));
		}
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",145)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,unlockNextPack,(void))

bool UserData_obj::isPackUnlocked( int pack){
	HX_SOURCE_PUSH("UserData_obj::isPackUnlocked")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",149)
	int len = this->unlockedPacks->length;
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",154)
	if (((pack <= this->unlockedPacks->__get((len - (int)1))))){
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",154)
		return true;
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",156)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,isPackUnlocked,return )

bool UserData_obj::isTipPaid( int pack,int level){
	HX_SOURCE_PUSH("UserData_obj::isTipPaid")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",161)
	{
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",161)
		int _g1 = (int)0;
		int _g = this->paidTips->length;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",161)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",161)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",162)
			if (((bool((this->paidTips->__get(i)->__get((int)0) == pack)) && bool((this->paidTips->__get(i)->__get((int)1) == level))))){
				HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",163)
				return true;
			}
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",166)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(UserData_obj,isTipPaid,return )

Void UserData_obj::setTipPaid( int pack,int level){
{
		HX_SOURCE_PUSH("UserData_obj::setTipPaid")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",170)
		if ((!(this->isTipPaid(pack,level)))){
			HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",170)
			this->paidTips->push(Array_obj< int >::__new().Add(pack).Add(level));
		}
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",174)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UserData_obj,setTipPaid,(void))

int UserData_obj::getBestScore( ){
	HX_SOURCE_PUSH("UserData_obj::getBestScore")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",180)
	return this->bestScore;
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,getBestScore,return )

Void UserData_obj::setBestScore( int value){
{
		HX_SOURCE_PUSH("UserData_obj::setBestScore")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",185)
		this->bestScore = value;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",186)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,setBestScore,(void))

bool UserData_obj::getMusic( ){
	HX_SOURCE_PUSH("UserData_obj::getMusic")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",192)
	return this->music;
}


HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,getMusic,return )

Void UserData_obj::setMusic( bool value){
{
		HX_SOURCE_PUSH("UserData_obj::setMusic")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",197)
		this->music = value;
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",198)
		::com::mybo::data::UserData_obj::saveToLocal();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,setMusic,(void))

::String UserData_obj::creatID( int pack,int level){
	HX_SOURCE_PUSH("UserData_obj::creatID")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",202)
	return ((pack + HX_CSTRING("-")) + level);
}


HX_DEFINE_DYNAMIC_FUNC2(UserData_obj,creatID,return )

::String UserData_obj::name;

::com::mybo::data::UserData UserData_obj::instance;

::com::mybo::data::UserData UserData_obj::getInstance( Dynamic reload){
	HX_SOURCE_PUSH("UserData_obj::getInstance")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",49)
	if (((bool((::com::mybo::data::UserData_obj::instance == null())) && bool(!(::com::mybo::data::UserData_obj::loadFromLocal()))))){
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",49)
		::com::mybo::data::UserData_obj::instance = ::com::mybo::data::UserData_obj::__new();
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",52)
	if ((reload)){
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",52)
		::com::mybo::data::UserData_obj::loadFromLocal();
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",55)
	return ::com::mybo::data::UserData_obj::instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UserData_obj,getInstance,return )

bool UserData_obj::loadFromLocal( ){
	HX_SOURCE_PUSH("UserData_obj::loadFromLocal")
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",210)
	bool flag = false;
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",211)
	::String content = ::com::mybo::framework::utils::FileAction_obj::read((HX_CSTRING("/data/data/com.mybogame.bbx2/") + HX_CSTRING("UserData")));
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",212)
	if (((null() != content))){
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",213)
		::com::mybo::data::UserData_obj::instance = ::haxe::Unserializer_obj::run(content);
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",214)
		flag = true;
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",216)
	return flag;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,loadFromLocal,return )

Void UserData_obj::saveToLocal( ){
{
		HX_SOURCE_PUSH("UserData_obj::saveToLocal")
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",220)
		::String content = ::haxe::Serializer_obj::run(::com::mybo::data::UserData_obj::instance);
		HX_SOURCE_POS("../../../src/com/mybo/data/UserData.hx",221)
		::com::mybo::framework::utils::FileAction_obj::write((HX_CSTRING("/data/data/com.mybogame.bbx2/") + HX_CSTRING("UserData")),content);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(UserData_obj,saveToLocal,(void))


UserData_obj::UserData_obj()
{
}

void UserData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UserData);
	HX_MARK_MEMBER_NAME(packAmount,"packAmount");
	HX_MARK_MEMBER_NAME(bestScore,"bestScore");
	HX_MARK_MEMBER_NAME(paidTips,"paidTips");
	HX_MARK_MEMBER_NAME(completedOfPack,"completedOfPack");
	HX_MARK_MEMBER_NAME(unlockedPacks,"unlockedPacks");
	HX_MARK_MEMBER_NAME(stars,"stars");
	HX_MARK_MEMBER_NAME(music,"music");
	HX_MARK_MEMBER_NAME(masterMap,"masterMap");
	HX_MARK_MEMBER_NAME(levelScoreHash,"levelScoreHash");
	HX_MARK_MEMBER_NAME(puzzleTotalScore,"puzzleTotalScore");
	HX_MARK_END_CLASS();
}

Dynamic UserData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stars") ) { return stars; }
		if (HX_FIELD_EQ(inName,"music") ) { return music; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"useStar") ) { return useStar_dyn(); }
		if (HX_FIELD_EQ(inName,"addStar") ) { return addStar_dyn(); }
		if (HX_FIELD_EQ(inName,"setStar") ) { return setStar_dyn(); }
		if (HX_FIELD_EQ(inName,"getStar") ) { return getStar_dyn(); }
		if (HX_FIELD_EQ(inName,"creatID") ) { return creatID_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance; }
		if (HX_FIELD_EQ(inName,"paidTips") ) { return paidTips; }
		if (HX_FIELD_EQ(inName,"getMusic") ) { return getMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"setMusic") ) { return setMusic_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bestScore") ) { return bestScore; }
		if (HX_FIELD_EQ(inName,"masterMap") ) { return masterMap; }
		if (HX_FIELD_EQ(inName,"isTipPaid") ) { return isTipPaid_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"packAmount") ) { return packAmount; }
		if (HX_FIELD_EQ(inName,"isFirstRun") ) { return isFirstRun_dyn(); }
		if (HX_FIELD_EQ(inName,"unlockPack") ) { return unlockPack_dyn(); }
		if (HX_FIELD_EQ(inName,"setTipPaid") ) { return setTipPaid_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		if (HX_FIELD_EQ(inName,"saveToLocal") ) { return saveToLocal_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getMasterMap") ) { return getMasterMap_dyn(); }
		if (HX_FIELD_EQ(inName,"setMasterMap") ) { return setMasterMap_dyn(); }
		if (HX_FIELD_EQ(inName,"getBestScore") ) { return getBestScore_dyn(); }
		if (HX_FIELD_EQ(inName,"setBestScore") ) { return setBestScore_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"loadFromLocal") ) { return loadFromLocal_dyn(); }
		if (HX_FIELD_EQ(inName,"unlockedPacks") ) { return unlockedPacks; }
		if (HX_FIELD_EQ(inName,"getLevelScore") ) { return getLevelScore_dyn(); }
		if (HX_FIELD_EQ(inName,"setLevelScore") ) { return setLevelScore_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"levelScoreHash") ) { return levelScoreHash; }
		if (HX_FIELD_EQ(inName,"unlockNextPack") ) { return unlockNextPack_dyn(); }
		if (HX_FIELD_EQ(inName,"isPackUnlocked") ) { return isPackUnlocked_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"completedOfPack") ) { return completedOfPack; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"puzzleTotalScore") ) { return puzzleTotalScore; }
		if (HX_FIELD_EQ(inName,"getPackCompleted") ) { return getPackCompleted_dyn(); }
		if (HX_FIELD_EQ(inName,"setPackCompleted") ) { return setPackCompleted_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getPuzzleTotalScore") ) { return getPuzzleTotalScore_dyn(); }
		if (HX_FIELD_EQ(inName,"setPuzzleTotalScore") ) { return setPuzzleTotalScore_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic UserData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stars") ) { stars=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"music") ) { music=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { instance=inValue.Cast< ::com::mybo::data::UserData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paidTips") ) { paidTips=inValue.Cast< Array< Array< int > > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bestScore") ) { bestScore=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"masterMap") ) { masterMap=inValue.Cast< ::com::mybo::data::Map >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"packAmount") ) { packAmount=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"unlockedPacks") ) { unlockedPacks=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"levelScoreHash") ) { levelScoreHash=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"completedOfPack") ) { completedOfPack=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"puzzleTotalScore") ) { puzzleTotalScore=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void UserData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("packAmount"));
	outFields->push(HX_CSTRING("bestScore"));
	outFields->push(HX_CSTRING("paidTips"));
	outFields->push(HX_CSTRING("completedOfPack"));
	outFields->push(HX_CSTRING("unlockedPacks"));
	outFields->push(HX_CSTRING("stars"));
	outFields->push(HX_CSTRING("music"));
	outFields->push(HX_CSTRING("masterMap"));
	outFields->push(HX_CSTRING("levelScoreHash"));
	outFields->push(HX_CSTRING("puzzleTotalScore"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("instance"),
	HX_CSTRING("getInstance"),
	HX_CSTRING("loadFromLocal"),
	HX_CSTRING("saveToLocal"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("packAmount"),
	HX_CSTRING("bestScore"),
	HX_CSTRING("paidTips"),
	HX_CSTRING("completedOfPack"),
	HX_CSTRING("unlockedPacks"),
	HX_CSTRING("stars"),
	HX_CSTRING("music"),
	HX_CSTRING("masterMap"),
	HX_CSTRING("levelScoreHash"),
	HX_CSTRING("puzzleTotalScore"),
	HX_CSTRING("isFirstRun"),
	HX_CSTRING("getLevelScore"),
	HX_CSTRING("setLevelScore"),
	HX_CSTRING("getPuzzleTotalScore"),
	HX_CSTRING("setPuzzleTotalScore"),
	HX_CSTRING("getMasterMap"),
	HX_CSTRING("setMasterMap"),
	HX_CSTRING("useStar"),
	HX_CSTRING("addStar"),
	HX_CSTRING("setStar"),
	HX_CSTRING("getStar"),
	HX_CSTRING("getPackCompleted"),
	HX_CSTRING("setPackCompleted"),
	HX_CSTRING("unlockPack"),
	HX_CSTRING("unlockNextPack"),
	HX_CSTRING("isPackUnlocked"),
	HX_CSTRING("isTipPaid"),
	HX_CSTRING("setTipPaid"),
	HX_CSTRING("getBestScore"),
	HX_CSTRING("setBestScore"),
	HX_CSTRING("getMusic"),
	HX_CSTRING("setMusic"),
	HX_CSTRING("creatID"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UserData_obj::name,"name");
	HX_MARK_MEMBER_NAME(UserData_obj::instance,"instance");
};

Class UserData_obj::__mClass;

void UserData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.data.UserData"), hx::TCanCast< UserData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void UserData_obj::__boot()
{
	hx::Static(name) = HX_CSTRING("UserData");
	hx::Static(instance);
}

} // end namespace com
} // end namespace mybo
} // end namespace data
