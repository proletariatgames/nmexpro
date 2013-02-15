#ifndef INCLUDED_com_mybo_effects_BubbleCell
#define INCLUDED_com_mybo_effects_BubbleCell

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,mybo,effects,BubbleCell)
namespace com{
namespace mybo{
namespace effects{


class BubbleCell_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BubbleCell_obj OBJ_;
		BubbleCell_obj();
		Void __construct(double xx,double yy,double scale,double a,double vx,double vy);

	public:
		static hx::ObjectPtr< BubbleCell_obj > __new(double xx,double yy,double scale,double a,double vx,double vy);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BubbleCell_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BubbleCell"); }

		double xx; /* REM */ 
		double yy; /* REM */ 
		double scale; /* REM */ 
		double a; /* REM */ 
		double vx; /* REM */ 
		double vy; /* REM */ 
};

} // end namespace com
} // end namespace mybo
} // end namespace effects

#endif /* INCLUDED_com_mybo_effects_BubbleCell */ 
