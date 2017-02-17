#ifndef VECTORSTORM_RAD2DEG_H_INCLUDED
#define VECTORSTORM_RAD2DEG_H_INCLUDED

#include "vectorstorm/deprecated_macros.h"
#include "pi.h"

#define RAD2DEG rad2deg

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

template<typename T>
inline static T constexpr const rad2deg(T const angle_rad) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr const rad2deg(T const angle_rad) noexcept {
  #ifndef VECTORSTORM_NO_BOOST
    return angle_rad * boost::math::constants::radian<T>();
  #else  // VECTORSTORM_NO_BOOST
    return (angle_rad * static_cast<T>(180.0)) / static_cast<T>(M_PI);
  #endif // VECTORSTORM_NO_BOOST
}

#ifdef VECTORSTORM_NAMESPACE
}
#endif

#endif // VECTORSTORM_RAD2DEG_H_INCLUDED
