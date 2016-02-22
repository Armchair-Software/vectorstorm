#ifndef VECTORSTORM_PI_H_INCLUDED
#define VECTORSTORM_PI_H_INCLUDED

// use boost's constants if available
#ifndef VMATH_NO_BOOST
#include <boost/math/constants/constants.hpp>
#else  // VMATH_NO_BOOST
#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif // M_PI
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_PI_H_INCLUDED
