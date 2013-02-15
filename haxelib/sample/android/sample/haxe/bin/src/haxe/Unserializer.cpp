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
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void Unserializer_obj::__construct(::String buf)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",65)
	this->buf = buf;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",66)
	this->length = buf.length;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",67)
	this->pos = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",71)
	this->scache = Array_obj< ::String >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",72)
	this->cache = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",73)
	Dynamic r = ::haxe::Unserializer_obj::DEFAULT_RESOLVER;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",74)
	if (((r == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",75)
		r = hx::ClassOf< ::Type >();
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",76)
		::haxe::Unserializer_obj::DEFAULT_RESOLVER = r;
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",78)
	this->setResolver(r);
}
;
	return null();
}

Unserializer_obj::~Unserializer_obj() { }

Dynamic Unserializer_obj::__CreateEmpty() { return  new Unserializer_obj; }
hx::ObjectPtr< Unserializer_obj > Unserializer_obj::__new(::String buf)
{  hx::ObjectPtr< Unserializer_obj > result = new Unserializer_obj();
	result->__construct(buf);
	return result;}

Dynamic Unserializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Unserializer_obj > result = new Unserializer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Unserializer_obj::setResolver( Dynamic r){
{
		HX_SOURCE_PUSH("Unserializer_obj::setResolver")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",81)
		if (((r == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();

					HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_1)
					::Class run(::String _){
{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",84)
							return null();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1(return)

					__result->Add(HX_CSTRING("resolveClass") ,  Dynamic(new _Function_3_1()),true);

					HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_2)
					::Enum run(::String _){
{
							HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",85)
							return null();
						}
						return null();
					}
					HX_END_LOCAL_FUNC1(return)

					__result->Add(HX_CSTRING("resolveEnum") ,  Dynamic(new _Function_3_2()),true);
					return __result;
				}
			};
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",83)
			this->resolver = _Function_2_1::Block();
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",88)
			this->resolver = r;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,setResolver,(void))

Dynamic Unserializer_obj::getResolver( ){
	HX_SOURCE_PUSH("Unserializer_obj::getResolver")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",91)
	return this->resolver;
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,getResolver,return )

int Unserializer_obj::get( int p){
	HX_SOURCE_PUSH("Unserializer_obj::get")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",95)
	return this->buf.cca(p);
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,get,return )

int Unserializer_obj::readDigits( ){
	HX_SOURCE_PUSH("Unserializer_obj::readDigits")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",100)
	int k = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",101)
	bool s = false;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",102)
	int fpos = this->pos;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",103)
	while((true)){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",104)
		int c = this->buf.cca(this->pos);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",105)
		if (((c == (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",106)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",107)
		if (((c == (int)45))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",108)
			if (((this->pos != fpos))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",109)
				break;
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",110)
			s = true;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",111)
			(this->pos)++;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",112)
			continue;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",114)
		if (((bool((c < (int)48)) || bool((c > (int)57))))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",115)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",116)
		k = ((k * (int)10) + ((c - (int)48)));
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",117)
		(this->pos)++;
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",119)
	if ((s)){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",120)
		hx::MultEq(k,(int)-1);
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",121)
	return k;
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,readDigits,return )

Void Unserializer_obj::unserializeObject( Dynamic o){
{
		HX_SOURCE_PUSH("Unserializer_obj::unserializeObject")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",125)
		while((true)){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",126)
			if (((this->pos >= this->length))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",127)
				hx::Throw (HX_CSTRING("Invalid object"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",128)
			if (((this->buf.cca(this->pos) == (int)103))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",129)
				break;
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",130)
			::String k = this->unserialize();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",131)
			if ((!(::Std_obj::is(k,hx::ClassOf< ::String >())))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",132)
				hx::Throw (HX_CSTRING("Invalid object key"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",133)
			Dynamic v = this->unserialize();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",134)
			if (((o != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",134)
				o->__SetField(k,v);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",136)
		(this->pos)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,unserializeObject,(void))

Dynamic Unserializer_obj::unserializeEnum( ::Enum edecl,::String tag){
	HX_SOURCE_PUSH("Unserializer_obj::unserializeEnum")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",140)
	Dynamic constr = ::Reflect_obj::field(edecl,tag);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",141)
	if (((constr == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",142)
		hx::Throw ((((HX_CSTRING("Unknown enum tag ") + ::Type_obj::getEnumName(edecl)) + HX_CSTRING(".")) + tag));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",143)
	if (((this->buf.cca((this->pos)++) != (int)58))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",144)
		hx::Throw (HX_CSTRING("Invalid enum format"));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",145)
	int nargs = this->readDigits();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",146)
	if (((nargs == (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",147)
		this->cache->__Field(HX_CSTRING("push"))(constr);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",148)
		return constr;
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",150)
	Dynamic args = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",151)
	while(((nargs > (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",152)
		args->__Field(HX_CSTRING("push"))(this->unserialize());
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",153)
		hx::SubEq(nargs,(int)1);
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",155)
	Dynamic e = ::Reflect_obj::callMethod(edecl,constr,args);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",156)
	this->cache->__Field(HX_CSTRING("push"))(e);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",157)
	return e;
}


HX_DEFINE_DYNAMIC_FUNC2(Unserializer_obj,unserializeEnum,return )

Dynamic Unserializer_obj::unserialize( ){
	HX_SOURCE_PUSH("Unserializer_obj::unserialize")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",161)
	switch( (int)(this->buf.cca((this->pos)++))){
		case (int)110: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",162)
			return null();
		}
		;break;
		case (int)116: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",164)
			return true;
		}
		;break;
		case (int)102: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",166)
			return false;
		}
		;break;
		case (int)122: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",168)
			return (int)0;
		}
		;break;
		case (int)105: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",170)
			return this->readDigits();
		}
		;break;
		case (int)100: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",173)
			int p1 = this->pos;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",174)
			while((true)){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",175)
				int c = this->buf.cca(this->pos);
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",177)
				if (((bool((bool((bool((c >= (int)43)) && bool((c < (int)58)))) || bool((c == (int)101)))) || bool((c == (int)69))))){
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",178)
					(this->pos)++;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",180)
					break;
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",182)
			return ::Std_obj::parseFloat(this->buf.substr(p1,(this->pos - p1)));
		}
		;break;
		case (int)121: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",184)
			int len = this->readDigits();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",185)
			if (((bool((this->buf.cca((this->pos)++) != (int)58)) || bool(((this->length - this->pos) < len))))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",186)
				hx::Throw (HX_CSTRING("Invalid string length"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",187)
			::String s = this->buf.substr(this->pos,len);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",188)
			hx::AddEq(this->pos,len);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",189)
			s = ::StringTools_obj::urlDecode(s);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",190)
			this->scache->push(s);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",191)
			return s;
		}
		;break;
		case (int)107: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",192)
			return ::Math_obj::NaN;
		}
		;break;
		case (int)109: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",194)
			return ::Math_obj::NEGATIVE_INFINITY;
		}
		;break;
		case (int)112: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",196)
			return ::Math_obj::POSITIVE_INFINITY;
		}
		;break;
		case (int)97: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",199)
			::String buf = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",200)
			Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",201)
			this->cache->__Field(HX_CSTRING("push"))(a);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",202)
			while((true)){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",203)
				int c = this->buf.cca(this->pos);
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",204)
				if (((c == (int)104))){
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",205)
					(this->pos)++;
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",206)
					break;
				}
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",208)
				if (((c == (int)117))){
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",209)
					(this->pos)++;
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",210)
					int n = this->readDigits();
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",211)
					hx::IndexRef((a).mPtr,((a->__Field(HX_CSTRING("length")) + n) - (int)1)) = null();
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",213)
					a->__Field(HX_CSTRING("push"))(this->unserialize());
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",215)
			return a;
		}
		;break;
		case (int)111: {
			struct _Function_2_1{
				inline static Dynamic Block( ){
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
			};
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",217)
			Dynamic o = _Function_2_1::Block();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",218)
			this->cache->__Field(HX_CSTRING("push"))(o);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",219)
			this->unserializeObject(o);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",220)
			return o;
		}
		;break;
		case (int)114: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",222)
			int n = this->readDigits();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",223)
			if (((bool((n < (int)0)) || bool((n >= this->cache->__Field(HX_CSTRING("length"))))))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",224)
				hx::Throw (HX_CSTRING("Invalid reference"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",225)
			return this->cache->__GetItem(n);
		}
		;break;
		case (int)82: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",227)
			int n = this->readDigits();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",228)
			if (((bool((n < (int)0)) || bool((n >= this->scache->length))))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",229)
				hx::Throw (HX_CSTRING("Invalid string reference"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",230)
			return this->scache->__get(n);
		}
		;break;
		case (int)120: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",231)
			hx::Throw (this->unserialize());
		}
		;break;
		case (int)99: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",234)
			::String name = this->unserialize();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",235)
			::Class cl = this->resolver->__Field(HX_CSTRING("resolveClass"))(name);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",236)
			if (((cl == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",237)
				hx::Throw ((HX_CSTRING("Class not found ") + name));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",238)
			Dynamic o = ::Type_obj::createEmptyInstance(cl);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",239)
			this->cache->__Field(HX_CSTRING("push"))(o);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",240)
			this->unserializeObject(o);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",241)
			return o;
		}
		;break;
		case (int)119: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",243)
			::String name = this->unserialize();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",244)
			::Enum edecl = this->resolver->__Field(HX_CSTRING("resolveEnum"))(name);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",245)
			if (((edecl == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",246)
				hx::Throw ((HX_CSTRING("Enum not found ") + name));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",247)
			return this->unserializeEnum(edecl,this->unserialize());
		}
		;break;
		case (int)106: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",249)
			::String name = this->unserialize();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",250)
			::Enum edecl = this->resolver->__Field(HX_CSTRING("resolveEnum"))(name);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",251)
			if (((edecl == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",252)
				hx::Throw ((HX_CSTRING("Enum not found ") + name));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",253)
			(this->pos)++;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",254)
			int index = this->readDigits();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",255)
			::String tag = ::Type_obj::getEnumConstructs(edecl)->__get(index);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",256)
			if (((tag == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",257)
				hx::Throw ((((HX_CSTRING("Unknown enum index ") + name) + HX_CSTRING("@")) + index));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",258)
			return this->unserializeEnum(edecl,tag);
		}
		;break;
		case (int)108: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",260)
			::List l = ::List_obj::__new();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",261)
			this->cache->__Field(HX_CSTRING("push"))(l);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",262)
			::String buf = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",263)
			while(((this->buf.cca(this->pos) != (int)104))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",264)
				l->add(this->unserialize());
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",265)
			(this->pos)++;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",266)
			return l;
		}
		;break;
		case (int)98: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",268)
			::Hash h = ::Hash_obj::__new();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",269)
			this->cache->__Field(HX_CSTRING("push"))(h);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",270)
			::String buf = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",271)
			while(((this->buf.cca(this->pos) != (int)104))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",272)
				::String s = this->unserialize();
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",273)
				h->set(s,this->unserialize());
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",275)
			(this->pos)++;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",276)
			return h;
		}
		;break;
		case (int)113: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",278)
			::IntHash h = ::IntHash_obj::__new();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",279)
			this->cache->__Field(HX_CSTRING("push"))(h);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",280)
			::String buf = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",281)
			int c = this->buf.cca((this->pos)++);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",282)
			while(((c == (int)58))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",283)
				int i = this->readDigits();
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",284)
				h->set(i,this->unserialize());
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",285)
				c = this->buf.cca((this->pos)++);
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",287)
			if (((c != (int)104))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",288)
				hx::Throw (HX_CSTRING("Invalid IntHash format"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",289)
			return h;
		}
		;break;
		case (int)118: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",291)
			::Date d = ::Date_obj::fromString(this->buf.substr(this->pos,(int)19));
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",292)
			this->cache->__Field(HX_CSTRING("push"))(d);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",293)
			hx::AddEq(this->pos,(int)19);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",294)
			return d;
		}
		;break;
		case (int)115: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",296)
			int len = this->readDigits();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",297)
			::String buf = this->buf;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",298)
			if (((bool((this->buf.cca((this->pos)++) != (int)58)) || bool(((this->length - this->pos) < len))))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",299)
				hx::Throw (HX_CSTRING("Invalid bytes length"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",303)
			Array< int > codes = ::haxe::Unserializer_obj::CODES;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",304)
			if (((codes == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",305)
				codes = ::haxe::Unserializer_obj::initCodes();
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",306)
				::haxe::Unserializer_obj::CODES = codes;
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",308)
			int i = this->pos;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",309)
			int rest = (int(len) & int((int)3));
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",310)
			int size = ((((int(len) >> int((int)2))) * (int)3) + ((  (((rest >= (int)2))) ? int((rest - (int)1)) : int((int)0) )));
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",311)
			int max = (i + ((len - rest)));
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",312)
			::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::alloc(size);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",313)
			int bpos = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",314)
			while(((i < max))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",315)
				int c1 = codes->__get(buf.cca((i)++));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",316)
				int c2 = codes->__get(buf.cca((i)++));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",317)
				bytes->b[(bpos)++] = (int((int(c1) << int((int)2))) | int((int(c2) >> int((int)4))));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",318)
				int c3 = codes->__get(buf.cca((i)++));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",319)
				bytes->b[(bpos)++] = (int((int(c2) << int((int)4))) | int((int(c3) >> int((int)2))));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",320)
				int c4 = codes->__get(buf.cca((i)++));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",321)
				bytes->b[(bpos)++] = (int((int(c3) << int((int)6))) | int(c4));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",323)
			if (((rest >= (int)2))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",324)
				int c1 = codes->__get(buf.cca((i)++));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",325)
				int c2 = codes->__get(buf.cca((i)++));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",326)
				bytes->b[(bpos)++] = (int((int(c1) << int((int)2))) | int((int(c2) >> int((int)4))));
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",327)
				if (((rest == (int)3))){
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",328)
					int c3 = codes->__get(buf.cca((i)++));
					HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",329)
					bytes->b[(bpos)++] = (int((int(c2) << int((int)4))) | int((int(c3) >> int((int)2))));
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",333)
			hx::AddEq(this->pos,len);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",334)
			this->cache->__Field(HX_CSTRING("push"))(bytes);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",335)
			return bytes;
		}
		;break;
		case (int)67: {
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",337)
			::String name = this->unserialize();
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",338)
			::Class cl = this->resolver->__Field(HX_CSTRING("resolveClass"))(name);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",339)
			if (((cl == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",340)
				hx::Throw ((HX_CSTRING("Class not found ") + name));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",341)
			Dynamic o = ::Type_obj::createEmptyInstance(cl);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",342)
			this->cache->__Field(HX_CSTRING("push"))(o);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",343)
			o->__Field(HX_CSTRING("hxUnserialize"))(hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",344)
			if (((this->buf.cca((this->pos)++) != (int)103))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",345)
				hx::Throw (HX_CSTRING("Invalid custom data"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",346)
			return o;
		}
		;break;
		default: {
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",349)
	(this->pos)--;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",350)
	hx::Throw ((((HX_CSTRING("Invalid char ") + this->buf.charAt(this->pos)) + HX_CSTRING(" at position ")) + this->pos));
}


HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,unserialize,return )

Dynamic Unserializer_obj::DEFAULT_RESOLVER;

::String Unserializer_obj::BASE64;

Array< int > Unserializer_obj::CODES;

Array< int > Unserializer_obj::initCodes( ){
	HX_SOURCE_PUSH("Unserializer_obj::initCodes")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",42)
	Array< int > codes = Array_obj< int >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",48)
	{
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",48)
		int _g1 = (int)0;
		int _g = ::haxe::Unserializer_obj::BASE64.length;
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",48)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",48)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",49)
			codes[::haxe::Unserializer_obj::BASE64.cca(i)] = i;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",50)
	return codes;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Unserializer_obj,initCodes,return )

Dynamic Unserializer_obj::run( ::String v){
	HX_SOURCE_PUSH("Unserializer_obj::run")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/Unserializer.hx",356)
	return ::haxe::Unserializer_obj::__new(v)->unserialize();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Unserializer_obj,run,return )


Unserializer_obj::Unserializer_obj()
{
}

void Unserializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Unserializer);
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(cache,"cache");
	HX_MARK_MEMBER_NAME(scache,"scache");
	HX_MARK_MEMBER_NAME(resolver,"resolver");
	HX_MARK_END_CLASS();
}

Dynamic Unserializer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CODES") ) { return CODES; }
		if (HX_FIELD_EQ(inName,"cache") ) { return cache; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { return BASE64; }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"scache") ) { return scache; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"resolver") ) { return resolver; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initCodes") ) { return initCodes_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readDigits") ) { return readDigits_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setResolver") ) { return setResolver_dyn(); }
		if (HX_FIELD_EQ(inName,"getResolver") ) { return getResolver_dyn(); }
		if (HX_FIELD_EQ(inName,"unserialize") ) { return unserialize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"unserializeEnum") ) { return unserializeEnum_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"DEFAULT_RESOLVER") ) { return DEFAULT_RESOLVER; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"unserializeObject") ) { return unserializeObject_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Unserializer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CODES") ) { CODES=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cache") ) { cache=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scache") ) { scache=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"resolver") ) { resolver=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"DEFAULT_RESOLVER") ) { DEFAULT_RESOLVER=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Unserializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buf"));
	outFields->push(HX_CSTRING("pos"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("cache"));
	outFields->push(HX_CSTRING("scache"));
	outFields->push(HX_CSTRING("resolver"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DEFAULT_RESOLVER"),
	HX_CSTRING("BASE64"),
	HX_CSTRING("CODES"),
	HX_CSTRING("initCodes"),
	HX_CSTRING("run"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("buf"),
	HX_CSTRING("pos"),
	HX_CSTRING("length"),
	HX_CSTRING("cache"),
	HX_CSTRING("scache"),
	HX_CSTRING("resolver"),
	HX_CSTRING("setResolver"),
	HX_CSTRING("getResolver"),
	HX_CSTRING("get"),
	HX_CSTRING("readDigits"),
	HX_CSTRING("unserializeObject"),
	HX_CSTRING("unserializeEnum"),
	HX_CSTRING("unserialize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Unserializer_obj::DEFAULT_RESOLVER,"DEFAULT_RESOLVER");
	HX_MARK_MEMBER_NAME(Unserializer_obj::BASE64,"BASE64");
	HX_MARK_MEMBER_NAME(Unserializer_obj::CODES,"CODES");
};

Class Unserializer_obj::__mClass;

void Unserializer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Unserializer"), hx::TCanCast< Unserializer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Unserializer_obj::__boot()
{
	hx::Static(DEFAULT_RESOLVER) = hx::ClassOf< ::Type >();
	hx::Static(BASE64) = HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:");
	hx::Static(CODES) = null();
}

} // end namespace haxe
