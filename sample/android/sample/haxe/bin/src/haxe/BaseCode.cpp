#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_BaseCode
#include <haxe/BaseCode.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{

Void BaseCode_obj::__construct(::haxe::io::Bytes base)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",34)
	int len = base->length;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",35)
	int nbits = (int)1;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",36)
	while(((len > (int((int)1) << int(nbits))))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",37)
		(nbits)++;
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",38)
	if (((bool((nbits > (int)8)) || bool((len != (int((int)1) << int(nbits))))))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",39)
		hx::Throw (HX_CSTRING("BaseCode : base length must be a power of two."));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",40)
	this->base = base;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",41)
	this->nbits = nbits;
}
;
	return null();
}

BaseCode_obj::~BaseCode_obj() { }

Dynamic BaseCode_obj::__CreateEmpty() { return  new BaseCode_obj; }
hx::ObjectPtr< BaseCode_obj > BaseCode_obj::__new(::haxe::io::Bytes base)
{  hx::ObjectPtr< BaseCode_obj > result = new BaseCode_obj();
	result->__construct(base);
	return result;}

Dynamic BaseCode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseCode_obj > result = new BaseCode_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxe::io::Bytes BaseCode_obj::encodeBytes( ::haxe::io::Bytes b){
	HX_SOURCE_PUSH("BaseCode_obj::encodeBytes")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",48)
	int nbits = this->nbits;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",49)
	::haxe::io::Bytes base = this->base;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",50)
	int size = ::Std_obj::_int((double((b->length * (int)8)) / double(nbits)));
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",51)
	::haxe::io::Bytes out = ::haxe::io::Bytes_obj::alloc((size + ((  (((hx::Mod((b->length * (int)8),nbits) == (int)0))) ? int((int)0) : int((int)1) ))));
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",52)
	int buf = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",53)
	int curbits = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",54)
	int mask = (((int((int)1) << int(nbits))) - (int)1);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",55)
	int pin = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",56)
	int pout = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",57)
	while(((pout < size))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",58)
		while(((curbits < nbits))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",59)
			hx::AddEq(curbits,(int)8);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",60)
			hx::ShlEq(buf,(int)8);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",61)
			hx::OrEq(buf,b->b->__get((pin)++));
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",63)
		hx::SubEq(curbits,nbits);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",64)
		out->b[(pout)++] = base->b->__get((int((int(buf) >> int(curbits))) & int(mask)));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",66)
	if (((curbits > (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",67)
		out->b[(pout)++] = base->b->__get((int((int(buf) << int((nbits - curbits)))) & int(mask)));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",68)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseCode_obj,encodeBytes,return )

Void BaseCode_obj::initTable( ){
{
		HX_SOURCE_PUSH("BaseCode_obj::initTable")
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",73)
		Array< int > tbl = Array_obj< int >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",74)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",74)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",74)
			while(((_g < (int)256))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",74)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",75)
				tbl[i] = (int)-1;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",76)
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",76)
			int _g1 = (int)0;
			int _g = this->base->length;
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",76)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",76)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",77)
				tbl[this->base->b->__get(i)] = i;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",78)
		this->tbl = tbl;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseCode_obj,initTable,(void))

::haxe::io::Bytes BaseCode_obj::decodeBytes( ::haxe::io::Bytes b){
	HX_SOURCE_PUSH("BaseCode_obj::decodeBytes")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",85)
	int nbits = this->nbits;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",86)
	::haxe::io::Bytes base = this->base;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",87)
	if (((this->tbl == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",87)
		this->initTable();
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",88)
	Array< int > tbl = this->tbl;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",89)
	int size = (int((b->length * nbits)) >> int((int)3));
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",90)
	::haxe::io::Bytes out = ::haxe::io::Bytes_obj::alloc(size);
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",91)
	int buf = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",92)
	int curbits = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",93)
	int pin = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",94)
	int pout = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",95)
	while(((pout < size))){
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",96)
		while(((curbits < (int)8))){
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",97)
			hx::AddEq(curbits,nbits);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",98)
			hx::ShlEq(buf,nbits);
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",99)
			int i = tbl->__get(b->b->__get((pin)++));
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",100)
			if (((i == (int)-1))){
				HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",101)
				hx::Throw (HX_CSTRING("BaseCode : invalid encoded char"));
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",102)
			hx::OrEq(buf,i);
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",104)
		hx::SubEq(curbits,(int)8);
		HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",105)
		out->b[(pout)++] = (int((int(buf) >> int(curbits))) & int((int)255));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",107)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseCode_obj,decodeBytes,return )

::String BaseCode_obj::encodeString( ::String s){
	HX_SOURCE_PUSH("BaseCode_obj::encodeString")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",111)
	return this->encodeBytes(::haxe::io::Bytes_obj::ofString(s))->toString();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseCode_obj,encodeString,return )

::String BaseCode_obj::decodeString( ::String s){
	HX_SOURCE_PUSH("BaseCode_obj::decodeString")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",119)
	return this->decodeBytes(::haxe::io::Bytes_obj::ofString(s))->toString();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseCode_obj,decodeString,return )

::String BaseCode_obj::encode( ::String s,::String base){
	HX_SOURCE_PUSH("BaseCode_obj::encode")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",128)
	::haxe::BaseCode b = ::haxe::BaseCode_obj::__new(::haxe::io::Bytes_obj::ofString(base));
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",129)
	return b->encodeString(s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BaseCode_obj,encode,return )

::String BaseCode_obj::decode( ::String s,::String base){
	HX_SOURCE_PUSH("BaseCode_obj::decode")
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",133)
	::haxe::BaseCode b = ::haxe::BaseCode_obj::__new(::haxe::io::Bytes_obj::ofString(base));
	HX_SOURCE_POS("/usr/lib/haxe/std/haxe/BaseCode.hx",134)
	return b->decodeString(s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BaseCode_obj,decode,return )


BaseCode_obj::BaseCode_obj()
{
}

void BaseCode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseCode);
	HX_MARK_MEMBER_NAME(base,"base");
	HX_MARK_MEMBER_NAME(nbits,"nbits");
	HX_MARK_MEMBER_NAME(tbl,"tbl");
	HX_MARK_END_CLASS();
}

Dynamic BaseCode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tbl") ) { return tbl; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"base") ) { return base; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nbits") ) { return nbits; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		if (HX_FIELD_EQ(inName,"decode") ) { return decode_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initTable") ) { return initTable_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"encodeBytes") ) { return encodeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"decodeBytes") ) { return decodeBytes_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"encodeString") ) { return encodeString_dyn(); }
		if (HX_FIELD_EQ(inName,"decodeString") ) { return decodeString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BaseCode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tbl") ) { tbl=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"base") ) { base=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nbits") ) { nbits=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BaseCode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("base"));
	outFields->push(HX_CSTRING("nbits"));
	outFields->push(HX_CSTRING("tbl"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("encode"),
	HX_CSTRING("decode"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("base"),
	HX_CSTRING("nbits"),
	HX_CSTRING("tbl"),
	HX_CSTRING("encodeBytes"),
	HX_CSTRING("initTable"),
	HX_CSTRING("decodeBytes"),
	HX_CSTRING("encodeString"),
	HX_CSTRING("decodeString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BaseCode_obj::__mClass;

void BaseCode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.BaseCode"), hx::TCanCast< BaseCode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BaseCode_obj::__boot()
{
}

} // end namespace haxe
