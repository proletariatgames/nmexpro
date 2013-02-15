#ifndef INCLUDED_com_mybo_gamescene_BlastNode
#define INCLUDED_com_mybo_gamescene_BlastNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,gamescene,BlastNode)
namespace com{
namespace mybo{
namespace gamescene{


class BlastNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BlastNode_obj OBJ_;
		BlastNode_obj();
		Void __construct(int inDir,double inX,double inY);

	public:
		static hx::ObjectPtr< BlastNode_obj > __new(int inDir,double inX,double inY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlastNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlastNode"); }

		int dir; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace gamescene

#endif /* INCLUDED_com_mybo_gamescene_BlastNode */ 
