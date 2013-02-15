#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_mybo_data_Map
#include <com/mybo/data/Map.h>
#endif
#ifndef INCLUDED_com_mybo_data_MapFactory
#include <com/mybo/data/MapFactory.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
namespace com{
namespace mybo{
namespace data{

Void MapFactory_obj::__construct()
{
	return null();
}

MapFactory_obj::~MapFactory_obj() { }

Dynamic MapFactory_obj::__CreateEmpty() { return  new MapFactory_obj; }
hx::ObjectPtr< MapFactory_obj > MapFactory_obj::__new()
{  hx::ObjectPtr< MapFactory_obj > result = new MapFactory_obj();
	result->__construct();
	return result;}

Dynamic MapFactory_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MapFactory_obj > result = new MapFactory_obj();
	result->__construct();
	return result;}

int MapFactory_obj::difficulty;

Array< int > MapFactory_obj::difficultyFactor;

int MapFactory_obj::MAX_ITEM;

int MapFactory_obj::mapRows;

int MapFactory_obj::mapCols;

int MapFactory_obj::packID;

Array< Array< ::com::mybo::data::Map > > MapFactory_obj::puzzleMaps;

::com::mybo::data::Map MapFactory_obj::getClassicModeMap( int level){
	HX_SOURCE_PUSH("MapFactory_obj::getClassicModeMap")
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",23)
	::com::mybo::data::Map map = ::com::mybo::data::Map_obj::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",25)
	Array< int > temp = Array_obj< int >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",26)
	{
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",26)
		int _g1 = (int)0;
		int _g = ::com::mybo::data::MapFactory_obj::difficultyFactor->length;
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",26)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",26)
			int i = (_g1)++;
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",27)
			{
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",27)
				int _g3 = (int)0;
				int _g2 = ::com::mybo::data::MapFactory_obj::difficultyFactor->__get(i);
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",27)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",27)
					int j = (_g3)++;
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",28)
					temp->push(i);
				}
			}
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",32)
	map->data = Array_obj< Array< int > >::__new();
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",33)
	Array< int > row;
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",34)
	{
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",34)
		int _g = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",34)
		while(((_g < (int)6))){
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",34)
			int i = (_g)++;
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",35)
			row = Array_obj< int >::__new();
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",36)
			{
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",36)
				int _g1 = (int)0;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",36)
				while(((_g1 < (int)5))){
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",36)
					int j = (_g1)++;
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",37)
					row->push(temp->splice(::Std_obj::random(temp->length),(int)1)->pop());
				}
			}
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",39)
			map->data->push(row);
		}
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",42)
	::com::mybo::data::MapFactory_obj::raiseDifficulty();
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",44)
	return map;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MapFactory_obj,getClassicModeMap,return )

Void MapFactory_obj::resetClassicModeMap( ){
{
		HX_SOURCE_PUSH("MapFactory_obj::resetClassicModeMap")
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",48)
		::com::mybo::data::MapFactory_obj::difficulty = (int)0;
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",49)
		::com::mybo::data::MapFactory_obj::difficultyFactor = Array_obj< int >::__new().Add((int)4).Add((int)4).Add((int)8).Add((int)8).Add((int)6);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MapFactory_obj,resetClassicModeMap,(void))

Void MapFactory_obj::raiseDifficulty( ){
{
		HX_SOURCE_PUSH("MapFactory_obj::raiseDifficulty")
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",54)
		(::com::mybo::data::MapFactory_obj::difficulty)++;
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",56)
		double rad = ::Math_obj::random();
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",63)
		if (((rad < 0.25))){
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",64)
			hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)3],(int)1);
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",65)
			hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)4],(int)1);
		}
		else{
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",66)
			if (((rad < 0.3))){
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",67)
				hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)4],(int)1);
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",68)
				hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)3],(int)1);
			}
			else{
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",69)
				if (((rad < 0.55))){
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",70)
					hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)3],(int)1);
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",71)
					hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)2],(int)1);
				}
				else{
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",72)
					if (((rad < 0.6))){
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",73)
						hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)3],(int)1);
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",74)
						hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)2],(int)1);
					}
					else{
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",75)
						if (((rad < 0.8))){
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",76)
							hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)2],(int)1);
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",77)
							hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)1],(int)1);
						}
						else{
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",78)
							if (((rad < 0.85))){
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",79)
								hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)1],(int)1);
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",80)
								hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)2],(int)1);
							}
							else{
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",81)
								if (((rad < 0.90))){
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",82)
									hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)0],(int)1);
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",83)
									hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)1],(int)1);
								}
								else{
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",84)
									if (((rad < 0.95))){
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",85)
										hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)1],(int)1);
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",86)
										hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)0],(int)1);
									}
									else{
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",88)
										hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)1],(int)1);
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",89)
										hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(int)4],(int)1);
									}
								}
							}
						}
					}
				}
			}
		}
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",92)
		while((true)){
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",93)
			bool breakFlag = true;
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",94)
			{
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",94)
				int _g1 = (int)0;
				int _g = ::com::mybo::data::MapFactory_obj::difficultyFactor->length;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",94)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",94)
					int i = (_g1)++;
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",95)
					if (((::com::mybo::data::MapFactory_obj::difficultyFactor->__get(i) <= (int)1))){
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",96)
						breakFlag = false;
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",97)
						if (((i == (int)0))){
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",98)
							hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[i],(int)1);
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",99)
							hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(i + (int)1)],(int)1);
						}
						else{
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",101)
							hx::AddEq(::com::mybo::data::MapFactory_obj::difficultyFactor[i],(int)1);
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",102)
							hx::SubEq(::com::mybo::data::MapFactory_obj::difficultyFactor[(i - (int)1)],(int)1);
						}
					}
				}
			}
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",107)
			if ((breakFlag)){
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",107)
				break;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MapFactory_obj,raiseDifficulty,(void))

::com::mybo::data::Map MapFactory_obj::getMasterMap( ){
	HX_SOURCE_PUSH("MapFactory_obj::getMasterMap")
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",112)
	if (((::com::mybo::data::MapFactory_obj::puzzleMaps == null()))){
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",112)
		::com::mybo::data::MapFactory_obj::loadMap();
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",114)
	Array< ::com::mybo::data::Map > masterPack = ::com::mybo::data::MapFactory_obj::puzzleMaps->__get((::com::mybo::data::MapFactory_obj::puzzleMaps->length - (int)1));
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",115)
	int random = ::Std_obj::random((masterPack->length - (int)1));
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",116)
	return masterPack->__get(random);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MapFactory_obj,getMasterMap,return )

::com::mybo::data::Map MapFactory_obj::getPuzzleMap( int pack,int index){
	HX_SOURCE_PUSH("MapFactory_obj::getPuzzleMap")
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",122)
	if (((::com::mybo::data::MapFactory_obj::puzzleMaps == null()))){
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",122)
		::com::mybo::data::MapFactory_obj::loadMap();
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",126)
	::com::mybo::data::Map map = ::com::mybo::data::MapFactory_obj::puzzleMaps->__get((pack - (int)1))->__get((index - (int)1));
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",128)
	return map;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(MapFactory_obj,getPuzzleMap,return )

int MapFactory_obj::getPuzzlePackConut( ){
	HX_SOURCE_PUSH("MapFactory_obj::getPuzzlePackConut")
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",132)
	if (((::com::mybo::data::MapFactory_obj::puzzleMaps == null()))){
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",132)
		::com::mybo::data::MapFactory_obj::loadMap();
	}
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",135)
	return (::com::mybo::data::MapFactory_obj::puzzleMaps->length - (int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MapFactory_obj,getPuzzlePackConut,return )

int MapFactory_obj::getPackMapCount( int pack){
	HX_SOURCE_PUSH("MapFactory_obj::getPackMapCount")
	HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",138)
	return ::com::mybo::data::MapFactory_obj::puzzleMaps->__get(pack)->length;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MapFactory_obj,getPackMapCount,return )

Void MapFactory_obj::loadMap( ){
{
		HX_SOURCE_PUSH("MapFactory_obj::loadMap")
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",143)
		::com::mybo::data::MapFactory_obj::puzzleMaps = Array_obj< Array< ::com::mybo::data::Map > >::__new();
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",145)
		::nme::utils::ByteArray bytes = ::nme::utils::ByteArray_obj::readFile((HX_CSTRING("") + HX_CSTRING("maps")));
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",146)
		::String content = ::haxe::Unserializer_obj::run(bytes->readUTFBytes(bytes->length));
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",148)
		Array< ::String > arr0 = content.split(HX_CSTRING("@"));
		HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",155)
		{
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",155)
			int _g1 = (int)0;
			int _g = arr0->length;
			HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",155)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",155)
				int i = (_g1)++;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",156)
				Array< ::com::mybo::data::Map > maps = Array_obj< ::com::mybo::data::Map >::__new();
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",158)
				Array< ::String > arr = arr0->__get(i).split(HX_CSTRING("."));
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",159)
				Array< ::String > arr2;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",160)
				Array< ::String > arr3;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",161)
				Array< ::String > arr4;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",163)
				::com::mybo::data::Map map;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",164)
				Array< Array< ::String > > mapData;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",165)
				Array< Array< ::String > > solution;
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",167)
				{
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",167)
					int _g3 = (int)0;
					int _g2 = arr->length;
					HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",167)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",167)
						int i1 = (_g3)++;
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",168)
						map = ::com::mybo::data::Map_obj::__new();
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",170)
						mapData = Array_obj< Array< ::String > >::__new();
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",171)
						arr2 = arr->__get(i1).split(HX_CSTRING("#"));
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",172)
						arr3 = arr2->__get((int)0).split(HX_CSTRING("|"));
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",173)
						{
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",173)
							int _g5 = (int)0;
							int _g4 = arr3->length;
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",173)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",173)
								int j = (_g5)++;
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",174)
								mapData->push(arr3->__get(j).split(HX_CSTRING(",")));
							}
						}
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",177)
						solution = Array_obj< Array< ::String > >::__new();
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",178)
						arr4 = arr2->__get((int)1).split(HX_CSTRING("|"));
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",179)
						{
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",179)
							int _g5 = (int)0;
							int _g4 = arr4->length;
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",179)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",179)
								int j = (_g5)++;
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",180)
								solution->push(arr4->__get(j).split(HX_CSTRING(",")));
							}
						}
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",183)
						{
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",183)
							int _g5 = (int)0;
							int _g4 = mapData->length;
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",183)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",183)
								int j = (_g5)++;
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",184)
								map->data[j] = Array_obj< int >::__new();
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",185)
								{
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",185)
									int _g7 = (int)0;
									int _g6 = mapData->__get(j)->length;
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",185)
									while(((_g7 < _g6))){
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",185)
										int k = (_g7)++;
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",186)
										map->data->__get(j)[k] = ::Std_obj::parseInt(mapData->__get(j)->__get(k));
									}
								}
							}
						}
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",189)
						{
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",189)
							int _g5 = (int)0;
							int _g4 = solution->length;
							HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",189)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",189)
								int j = (_g5)++;
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",190)
								map->solution[j] = Array_obj< int >::__new();
								HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",191)
								{
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",191)
									int _g7 = (int)0;
									int _g6 = solution->__get(j)->length;
									HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",191)
									while(((_g7 < _g6))){
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",191)
										int k = (_g7)++;
										HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",192)
										map->solution->__get(j)[k] = ::Std_obj::parseInt(solution->__get(j)->__get(k));
									}
								}
							}
						}
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",196)
						map->solutionStep = map->solution->length;
						HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",197)
						maps->push(map);
					}
				}
				HX_SOURCE_POS("../../../src/com/mybo/data/MapFactory.hx",199)
				::com::mybo::data::MapFactory_obj::puzzleMaps->push(maps);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MapFactory_obj,loadMap,(void))


MapFactory_obj::MapFactory_obj()
{
}

void MapFactory_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MapFactory);
	HX_MARK_MEMBER_NAME(packCount,"packCount");
	HX_MARK_END_CLASS();
}

Dynamic MapFactory_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"packID") ) { return packID; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mapRows") ) { return mapRows; }
		if (HX_FIELD_EQ(inName,"mapCols") ) { return mapCols; }
		if (HX_FIELD_EQ(inName,"loadMap") ) { return loadMap_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MAX_ITEM") ) { return MAX_ITEM; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"packCount") ) { return packCount; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"difficulty") ) { return difficulty; }
		if (HX_FIELD_EQ(inName,"puzzleMaps") ) { return puzzleMaps; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getMasterMap") ) { return getMasterMap_dyn(); }
		if (HX_FIELD_EQ(inName,"getPuzzleMap") ) { return getPuzzleMap_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"raiseDifficulty") ) { return raiseDifficulty_dyn(); }
		if (HX_FIELD_EQ(inName,"getPackMapCount") ) { return getPackMapCount_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"difficultyFactor") ) { return difficultyFactor; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getClassicModeMap") ) { return getClassicModeMap_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getPuzzlePackConut") ) { return getPuzzlePackConut_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"resetClassicModeMap") ) { return resetClassicModeMap_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MapFactory_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"packID") ) { packID=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mapRows") ) { mapRows=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mapCols") ) { mapCols=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MAX_ITEM") ) { MAX_ITEM=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"packCount") ) { packCount=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"difficulty") ) { difficulty=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"puzzleMaps") ) { puzzleMaps=inValue.Cast< Array< Array< ::com::mybo::data::Map > > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"difficultyFactor") ) { difficultyFactor=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MapFactory_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("packCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("difficulty"),
	HX_CSTRING("difficultyFactor"),
	HX_CSTRING("MAX_ITEM"),
	HX_CSTRING("mapRows"),
	HX_CSTRING("mapCols"),
	HX_CSTRING("packID"),
	HX_CSTRING("puzzleMaps"),
	HX_CSTRING("getClassicModeMap"),
	HX_CSTRING("resetClassicModeMap"),
	HX_CSTRING("raiseDifficulty"),
	HX_CSTRING("getMasterMap"),
	HX_CSTRING("getPuzzleMap"),
	HX_CSTRING("getPuzzlePackConut"),
	HX_CSTRING("getPackMapCount"),
	HX_CSTRING("loadMap"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("packCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MapFactory_obj::difficulty,"difficulty");
	HX_MARK_MEMBER_NAME(MapFactory_obj::difficultyFactor,"difficultyFactor");
	HX_MARK_MEMBER_NAME(MapFactory_obj::MAX_ITEM,"MAX_ITEM");
	HX_MARK_MEMBER_NAME(MapFactory_obj::mapRows,"mapRows");
	HX_MARK_MEMBER_NAME(MapFactory_obj::mapCols,"mapCols");
	HX_MARK_MEMBER_NAME(MapFactory_obj::packID,"packID");
	HX_MARK_MEMBER_NAME(MapFactory_obj::puzzleMaps,"puzzleMaps");
};

Class MapFactory_obj::__mClass;

void MapFactory_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.mybo.data.MapFactory"), hx::TCanCast< MapFactory_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MapFactory_obj::__boot()
{
	hx::Static(difficulty) = (int)0;
	hx::Static(difficultyFactor) = Array_obj< int >::__new().Add((int)4).Add((int)4).Add((int)8).Add((int)8).Add((int)6);
	hx::Static(MAX_ITEM) = (int)30;
	hx::Static(mapRows) = (int)6;
	hx::Static(mapCols) = (int)5;
	hx::Static(packID);
	hx::Static(puzzleMaps);
}

} // end namespace com
} // end namespace mybo
} // end namespace data
