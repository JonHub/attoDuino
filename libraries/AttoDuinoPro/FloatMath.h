#ifndef FloatMathInline_h
#define FloatMathInline_h

#include "driverlib/fpu.h"

// note, these would normally all be declared "inline,"
// but compiler optomizations already take care of this.

// to test for speed, make sure that the speed is the same as using
// #define sin(arg) (sinf(arg))
// #define exp(arg) (expf(arg))
// ... this is an alternative implementation,
// but does not allow for type checking (in mixed float / double environments)

// floating point library reference is here:
// http://www.nongnu.org/avr-libc/user-manual/group__avr__math.html

// or better, the arm math library here
// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0282b/BABBIAFH.html

void testFloatMath() { Serial.println( "TestMathCalled"); }

//jd ... weird I forgot sin, what else did I forget?  Need to check this ...
//float sin( float x ) { return sinf( x ); }
float cos( float x ) { return cosf( x ); }
//float tan( float x ) { return tanf( x ); }

float acos( float x ) { return acosf( x ); }
float asin( float x ) { return asinf( x ); }
float atan( float x ) { return atanf( x ); }
float atan2( float y, float x ) { return atan2f( y, x ); } // note, the arguments are y,x, since this returns atan(y/x)
float ceil( float x ) { return ceilf( x ); }
float exp( float x ) { return expf( x ); }
//float abs( float x ) { return fabsf( x ); }  // this conflicts with something
float floor( float x ) { return floorf( x ); }
float mod( float x, float y ) { return fmodf( x, y ); }

// breaks a floating-point number into a normalized fraction and an integral power of 2,
// and stores the integer the value pointed to by *pexp
//the int object pointed to by __pexp.
//If __x is a normal float point number, the frexp() function returns the value v, such that v has a magnitude in the interval [1/2, 1) or zero, and __x equals v times 2 raised to the power __pexp. If __x is zero, both parts of the result are zero. If __x is not a finite number, the frexp() returns __x as is and stores 0 by __pexp.
// Note:
// This implementation permits a zero pointer as a directive to skip a storing the exponent.
//jd - ceck
float frexp( float x, int* pexp ) { return frexpf( x, pexp); }

// returns x * 2^exp
float ldexp( float x, int exp ) { return ldexpf( x, exp ); }

// breaks the argument __x into integral and fractional parts, each of which has the same sign as the argument. It stores the integral part as a double in the object pointed to by __iptr.
// returns the signed fractional part of __x.

// Note:
//This implementation skips writing by zero pointer. However, the GCC 4.3 can replace this function with inline code that does not permit to use NULL address for the avoiding of storing.
//jd check
float mod( float x, float *y ) { return modff( x, y); }
float pow( float x, float y ) { return powf( x,  y ); }
float sqrt( float x ) { return sqrtf( x ); }
float tan( float x ) { return tanf( x ); }
float tanh( float x ) { return tanhf( x ); }
float acosh( float x ) { return acoshf( x ); }
float asinh( float x ) { return asinhf( x ); }
float atanh( float x ) { return atanhf( x ); }
float cbrt( float x ) { return cbrtf( x ); }     // cube root
float copysign( float x, float y ) { return copysignf( x, y ); } // returnsn x but with the sign of y, works with zero and NaN
float erf( float x ) { return erff( x ); }       // the ordinary error function of x
float erfc( float x ) { return erfcf( x ); }     // 1-erf(x), more accurate when x is large
float expm1( float x ) { return expm1f( x ); }   // exp(x)-1, more accurate when x is near zero
float exp2( float x ) { return exp2f( x ); }     // 2^x
float fdim( float x, float y ) { return fdimf( x, y ); }  // max(x-y,0), or NaN if x and y are Nan
float fma( float x, float y, float z ) { return fmaf( x, y, z ); }  // floating-point multiply-add, returns x*y+z
//float max( float x, float y ) { return fmaxf( x, y ); }
//float min( float x, float y ) { return fminf( x, y ); }
float hypot( float x, float y ) { return hypotf( x, y ); }  // returns sqrt( x*x + y*y )
int ilogb( float x ) { return ilogbf( x ); }
float lgamma( float x ) { return lgammaf( x ); }

// typedef for _Longlong needed ...
//_Longlong llrintf( x ); }
//_Longlong llroundf( x ); }
float log1p( float x ) { return log1pf( x ); }   // natural logarithm of x+1, more accurate when x is near zero
float logb( float x ) { return logbf( x ); }     // returns exponent of x
//long lrintf( x ); } // rounds x to the nearest integer, rounding the halfway cases to the even integer direction. (That is both 1.5 and 2.5 values are rounded to 2). This function is similar to rint() function, but it differs in type of return value and in that an overflow is possible.
//long lroundf( x ); }
//float nanf(const char * x ); }
float nearbyint( float x ) { return nearbyintf( x ); }
float nextafter( float x, float y ) { return nextafterf( x, y); }

// not declared in this scope
//float nexttoward( float x, long double y ) { return nexttowardf( x, y ); }
float remainder( float x, float y ) { return remainderf( x, y ); }
float remquo( float x, float y, int* z ) { return remquof( x, y, z ); }
float rint( float x ) { return rintf( x ); }
//float round( float x ) { return roundf( x ); }
float scalbn( float x, int y) { return scalbnf( x, y ); }    // x * (FLT_RADIX ** n)
float scalbln( float x, long y ) { return scalblnf(x, y ); }
float tgamma( float x ) { return tgammaf( x ); }
float trunc( float x ) { return truncf( x ); }

#endif



