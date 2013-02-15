#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void Serializer_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",52)
	this->buf = ::StringBuf_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",53)
	this->cache = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",54)
	this->useCache = ::haxe::Serializer_obj::USE_CACHE;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",55)
	this->useEnumIndex = ::haxe::Serializer_obj::USE_ENUM_INDEX;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",56)
	this->shash = ::Hash_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",57)
	this->scount = (int)0;
}
;
	return null();
}

Serializer_obj::~Serializer_obj() { }

Dynamic Serializer_obj::__CreateEmpty() { return  new Serializer_obj; }
hx::ObjectPtr< Serializer_obj > Serializer_obj::__new()
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

Dynamic Serializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

::String Serializer_obj::toString( ){
	HX_SOURCE_PUSH("Serializer_obj::toString")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",60)
	return this->buf->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Serializer_obj,toString,return )

Void Serializer_obj::serializeString( ::String s){
{
		HX_SOURCE_PUSH("Serializer_obj::serializeString")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",95)
		Dynamic x = this->shash->get(s);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",96)
		if (((x != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",97)
			{
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",97)
				::StringBuf _this = this->buf;
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",97)
				hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("R");
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",98)
			{
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",98)
				::StringBuf _this = this->buf;
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",98)
				hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = x;
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",99)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",101)
		this->shash->set(s,(this->scount)++);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",106)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",106)
			::StringBuf _this = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",106)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("y");
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",107)
		s = ::StringTools_obj::urlEncode(s);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",108)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",108)
			::StringBuf _this = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",108)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = s.length;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",109)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",109)
			::StringBuf _this = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",109)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(":");
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",110)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",110)
			::StringBuf _this = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",110)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = s;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeString,(void))

bool Serializer_obj::serializeRef( Dynamic v){
	HX_SOURCE_PUSH("Serializer_obj::serializeRef")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",117)
	{
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",117)
		int _g1 = (int)0;
		int _g = this->cache->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",117)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",117)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",122)
			if (((this->cache->__GetItem(i) == v))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",124)
				{
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",124)
					::StringBuf _this = this->buf;
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",124)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("r");
				}
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",125)
				{
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",125)
					::StringBuf _this = this->buf;
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",125)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = i;
				}
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",126)
				return true;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",129)
	this->cache->__Field(HX_CSTRING("push"))(v);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",130)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeRef,return )

Void Serializer_obj::serializeFields( Dynamic v){
{
		HX_SOURCE_PUSH("Serializer_obj::serializeFields")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",151)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",151)
			int _g = (int)0;
			Array< ::String > _g1 = ::Reflect_obj::fields(v);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",151)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",151)
				::String f = _g1->__get(_g);
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",151)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",152)
				this->serializeString(f);
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",153)
				this->serialize(::Reflect_obj::field(v,f));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",155)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",155)
			::StringBuf _this = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",155)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("g");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeFields,(void))

Void Serializer_obj::serialize( Dynamic v){
{
		HX_SOURCE_PUSH("Serializer_obj::serialize")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",158)
		{
::ValueType _switch_1 = (::Type_obj::_typeof(v));
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",161)
					::StringBuf _this = this->buf;
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",161)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("n");
				}
				;break;
				case 1: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",163)
					if (((v == (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",164)
						{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",164)
							::StringBuf _this = this->buf;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",164)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("z");
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",165)
						return null();
					}
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",167)
					{
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",167)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",167)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("i");
					}
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",168)
					{
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",168)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",168)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = v;
					}
				}
				;break;
				case 2: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",169)
					if ((::Math_obj::isNaN(v))){
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",171)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",171)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("k");
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",172)
						if ((!(::Math_obj::isFinite(v)))){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",173)
							::StringBuf _this = this->buf;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",173)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = (  (((v < (int)0))) ? ::String(HX_CSTRING("m")) : ::String(HX_CSTRING("p")) );
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",175)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",175)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",175)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("d");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",176)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",176)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",176)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = v;
							}
						}
					}
				}
				;break;
				case 3: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",179)
					::StringBuf _this = this->buf;
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",179)
					hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = (  ((v)) ? ::String(HX_CSTRING("t")) : ::String(HX_CSTRING("f")) );
				}
				;break;
				case 6: {
					::Class c = _switch_1->__Param(0);
{
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",181)
						if (((c == hx::ClassOf< ::String >()))){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",182)
							this->serializeString(v);
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",183)
							return null();
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",185)
						if (((bool(this->useCache) && bool(this->serializeRef(v))))){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",186)
							return null();
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",187)
						::Class _switch_2 = (c);
						if (  ( _switch_2==hx::ClassOf< Array<int> >())){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",189)
							int ucount = (int)0;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",190)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",190)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",190)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("a");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",194)
							int l = v->__length();
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",195)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",195)
								int _g = (int)0;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",195)
								while(((_g < l))){
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",195)
									int i = (_g)++;
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",196)
									if (((v->__GetItem(i) == null()))){
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",197)
										(ucount)++;
									}
									else{
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",199)
										if (((ucount > (int)0))){
											HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",200)
											if (((ucount == (int)1))){
												HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",201)
												::StringBuf _this = this->buf;
												HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",201)
												hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("n");
											}
											else{
												HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",203)
												{
													HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",203)
													::StringBuf _this = this->buf;
													HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",203)
													hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("u");
												}
												HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",204)
												{
													HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",204)
													::StringBuf _this = this->buf;
													HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",204)
													hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = ucount;
												}
											}
											HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",206)
											ucount = (int)0;
										}
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",208)
										this->serialize(v->__GetItem(i));
									}
								}
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",211)
							if (((ucount > (int)0))){
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",211)
								if (((ucount == (int)1))){
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",213)
									::StringBuf _this = this->buf;
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",213)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("n");
								}
								else{
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",215)
									{
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",215)
										::StringBuf _this = this->buf;
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",215)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("u");
									}
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",216)
									{
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",216)
										::StringBuf _this = this->buf;
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",216)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = ucount;
									}
								}
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",219)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",219)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",219)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::List >())){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",221)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",221)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",221)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("l");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",222)
							::List v1 = v;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",223)
							for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(v1->iterator());  __it->hasNext(); ){
								Dynamic i = __it->next();
								this->serialize(i);
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",225)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",225)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",225)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::Date >())){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",227)
							::Date d = v;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",228)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",228)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",228)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("v");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",229)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",229)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",229)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = d->toString();
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::Hash >())){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",231)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",231)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",231)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("b");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",232)
							::Hash v1 = v;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",233)
							for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(v1->keys());  __it->hasNext(); ){
								::String k = __it->next();
								{
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",234)
									this->serializeString(k);
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",235)
									this->serialize(v1->get(k));
								}
;
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",237)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",237)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",237)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::IntHash >())){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",239)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",239)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",239)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("q");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",240)
							::IntHash v1 = v;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",241)
							for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(v1->keys());  __it->hasNext(); ){
								int k = __it->next();
								{
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",242)
									{
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",242)
										::StringBuf _this = this->buf;
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",242)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(":");
									}
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",243)
									{
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",243)
										::StringBuf _this = this->buf;
										HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",243)
										hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = k;
									}
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",244)
									this->serialize(v1->get(k));
								}
;
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",246)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",246)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",246)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("h");
							}
						}
						else if (  ( _switch_2==hx::ClassOf< ::haxe::io::Bytes >())){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",248)
							::haxe::io::Bytes v1 = v;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",252)
							int i = (int)0;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",253)
							int max = (v1->length - (int)2);
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",254)
							::String chars = HX_CSTRING("");
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",255)
							::String b64 = ::haxe::Serializer_obj::BASE64;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",256)
							while(((i < max))){
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",257)
								int b1 = v1->b->__get((i)++);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",258)
								int b2 = v1->b->__get((i)++);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",259)
								int b3 = v1->b->__get((i)++);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",260)
								hx::AddEq(chars,(((b64.charAt((int(b1) >> int((int)2))) + b64.charAt((int(((int((int(b1) << int((int)4))) | int((int(b2) >> int((int)4)))))) & int((int)63)))) + b64.charAt((int(((int((int(b2) << int((int)2))) | int((int(b3) >> int((int)6)))))) & int((int)63)))) + b64.charAt((int(b3) & int((int)63)))));
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",265)
							if (((i == max))){
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",266)
								int b1 = v1->b->__get((i)++);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",267)
								int b2 = v1->b->__get((i)++);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",268)
								hx::AddEq(chars,((b64.charAt((int(b1) >> int((int)2))) + b64.charAt((int(((int((int(b1) << int((int)4))) | int((int(b2) >> int((int)4)))))) & int((int)63)))) + b64.charAt((int((int(b2) << int((int)2))) & int((int)63)))));
							}
							else{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",271)
								if (((i == (max + (int)1)))){
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",272)
									int b1 = v1->b->__get((i)++);
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",273)
									hx::AddEq(chars,(b64.charAt((int(b1) >> int((int)2))) + b64.charAt((int((int(b1) << int((int)4))) & int((int)63)))));
								}
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",276)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",276)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",276)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("s");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",277)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",277)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",277)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = chars.length;
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",278)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",278)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",278)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(":");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",279)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",279)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",279)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = chars;
							}
						}
						else  {
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",281)
							this->cache->__Field(HX_CSTRING("pop"))();
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",282)
							if (((v->__Field(HX_CSTRING("hxSerialize")) != null()))){
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",283)
								{
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",283)
									::StringBuf _this = this->buf;
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",283)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("C");
								}
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",284)
								this->serializeString(::Type_obj::getClassName(c));
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",285)
								this->cache->__Field(HX_CSTRING("push"))(v);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",286)
								v->__Field(HX_CSTRING("hxSerialize"))(hx::ObjectPtr<OBJ_>(this));
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",287)
								{
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",287)
									::StringBuf _this = this->buf;
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",287)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("g");
								}
							}
							else{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",289)
								{
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",289)
									::StringBuf _this = this->buf;
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",289)
									hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("c");
								}
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",290)
								this->serializeString(::Type_obj::getClassName(c));
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",291)
								this->cache->__Field(HX_CSTRING("push"))(v);
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",295)
								this->serializeFields(v);
							}
						}
;
;
					}
				}
				;break;
				case 4: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",300)
					if (((bool(this->useCache) && bool(this->serializeRef(v))))){
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",301)
						return null();
					}
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",302)
					{
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",302)
						::StringBuf _this = this->buf;
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",302)
						hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("o");
					}
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",303)
					this->serializeFields(v);
				}
				;break;
				case 7: {
					::Enum e = _switch_1->__Param(0);
{
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",305)
						if (((bool(this->useCache) && bool(this->serializeRef(v))))){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",306)
							return null();
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",307)
						this->cache->__Field(HX_CSTRING("pop"))();
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",308)
						{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",308)
							::StringBuf _this = this->buf;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",308)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = (  ((this->useEnumIndex)) ? ::String(HX_CSTRING("j")) : ::String(HX_CSTRING("w")) );
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",309)
						this->serializeString(::Type_obj::getEnumName(e));
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",341)
						if ((this->useEnumIndex)){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",342)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",342)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",342)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(":");
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",343)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",343)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",343)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = v->__Index();
							}
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",345)
							this->serializeString(v->__Tag());
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",346)
						{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",346)
							::StringBuf _this = this->buf;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",346)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(":");
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",347)
						Dynamic pl = v->__EnumParams();
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",348)
						if (((pl == null()))){
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",349)
							::StringBuf _this = this->buf;
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",349)
							hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = (int)0;
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",351)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",351)
								::StringBuf _this = this->buf;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",351)
								hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = pl->__Field(HX_CSTRING("length"));
							}
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",352)
							{
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",352)
								int _g = (int)0;
								HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",352)
								while(((_g < pl->__Field(HX_CSTRING("length"))))){
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",352)
									Dynamic p = pl->__GetItem(_g);
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",352)
									++(_g);
									HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",353)
									this->serialize(p);
								}
							}
						}
						HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",382)
						this->cache->__Field(HX_CSTRING("push"))(v);
					}
				}
				;break;
				case 5: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",383)
					hx::Throw (HX_CSTRING("Cannot serialize function"));
				}
				;break;
				default: {
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",385)
					hx::Throw ((HX_CSTRING("Cannot serialize ") + ::Std_obj::string(v)));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serialize,(void))

Void Serializer_obj::serializeException( Dynamic e){
{
		HX_SOURCE_PUSH("Serializer_obj::serializeException")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",398)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",398)
			::StringBuf _this = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",398)
			hx::IndexRef((_this->b).mPtr,_this->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("x");
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",410)
		this->serialize(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeException,(void))

bool Serializer_obj::USE_CACHE;

bool Serializer_obj::USE_ENUM_INDEX;

::String Serializer_obj::BASE64;

::String Serializer_obj::run( Dynamic v){
	HX_SOURCE_PUSH("Serializer_obj::run")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",417)
	::haxe::Serializer s = ::haxe::Serializer_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",418)
	s->serialize(v);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Serializer.hx",419)
	return s->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,run,return )


Serializer_obj::Serializer_obj()
{
}

void Serializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Serializer);
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_MEMBER_NAME(cache,"cache");
	HX_MARK_MEMBER_NAME(shash,"shash");
	HX_MARK_MEMBER_NAME(scount,"scount");
	HX_MARK_MEMBER_NAME(useCache,"useCache");
	HX_MARK_MEMBER_NAME(useEnumIndex,"useEnumIndex");
	HX_MARK_END_CLASS();
}

Dynamic Serializer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"cache") ) { return cache; }
		if (HX_FIELD_EQ(inName,"shash") ) { return shash; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { return BASE64; }
		if (HX_FIELD_EQ(inName,"scount") ) { return scount; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"useCache") ) { return useCache; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"USE_CACHE") ) { return USE_CACHE; }
		if (HX_FIELD_EQ(inName,"serialize") ) { return serialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"useEnumIndex") ) { return useEnumIndex; }
		if (HX_FIELD_EQ(inName,"serializeRef") ) { return serializeRef_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"USE_ENUM_INDEX") ) { return USE_ENUM_INDEX; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"serializeString") ) { return serializeString_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeFields") ) { return serializeFields_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"serializeException") ) { return serializeException_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Serializer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::StringBuf >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"cache") ) { cache=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shash") ) { shash=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scount") ) { scount=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"useCache") ) { useCache=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"USE_CACHE") ) { USE_CACHE=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"useEnumIndex") ) { useEnumIndex=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"USE_ENUM_INDEX") ) { USE_ENUM_INDEX=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Serializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buf"));
	outFields->push(HX_CSTRING("cache"));
	outFields->push(HX_CSTRING("shash"));
	outFields->push(HX_CSTRING("scount"));
	outFields->push(HX_CSTRING("useCache"));
	outFields->push(HX_CSTRING("useEnumIndex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("USE_CACHE"),
	HX_CSTRING("USE_ENUM_INDEX"),
	HX_CSTRING("BASE64"),
	HX_CSTRING("run"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("buf"),
	HX_CSTRING("cache"),
	HX_CSTRING("shash"),
	HX_CSTRING("scount"),
	HX_CSTRING("useCache"),
	HX_CSTRING("useEnumIndex"),
	HX_CSTRING("toString"),
	HX_CSTRING("serializeString"),
	HX_CSTRING("serializeRef"),
	HX_CSTRING("serializeFields"),
	HX_CSTRING("serialize"),
	HX_CSTRING("serializeException"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Serializer_obj::USE_CACHE,"USE_CACHE");
	HX_MARK_MEMBER_NAME(Serializer_obj::USE_ENUM_INDEX,"USE_ENUM_INDEX");
	HX_MARK_MEMBER_NAME(Serializer_obj::BASE64,"BASE64");
};

Class Serializer_obj::__mClass;

void Serializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Serializer"), hx::TCanCast< Serializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Serializer_obj::__boot()
{
	hx::Static(USE_CACHE) = false;
	hx::Static(USE_ENUM_INDEX) = false;
	hx::Static(BASE64) = HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:");
}

} // end namespace haxe
