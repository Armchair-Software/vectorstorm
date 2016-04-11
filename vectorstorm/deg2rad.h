#ifndef VECTORSTORM_DEG2RAD_H_INCLUDED
#define VECTORSTORM_DEG2RAD_H_INCLUDED

#include "pi.h"

#define DEG2RAD deg2rad

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

template<typename T>
inline static T constexpr const deg2rad(T const angle_deg) __attribute__((__always_inline__));
template<typename T>
inline static T constexpr const deg2rad(T const angle_deg) {
  #ifndef VMATH_NO_BOOST
    //return (angle_deg * boost::math::constants::pi<T>()) / 180.0;
    return angle_deg * boost::math::constants::degree<T>();
  #else  // VMATH_NO_BOOST
    return (angle_deg * M_PI) / 180.0;
  #endif // VMATH_NO_BOOST
}

#ifdef VMATH_NAMESPACE
}
#endif

#endif // VECTORSTORM_DEG2RAD_H_INCLUDED
