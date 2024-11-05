#pragma once

#include "pi.h"

#define DEG2RAD deg2rad

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

template<typename T>
inline static constexpr T deg2rad(T const angle_deg) noexcept __attribute__((__always_inline__));
template<typename T>
inline static constexpr T deg2rad(T const angle_deg) noexcept {
  #ifndef VECTORSTORM_NO_BOOST
    //return (angle_deg * boost::math::constants::pi<T>()) / 180.0;
    return angle_deg * boost::math::constants::degree<T>();
  #else
    return (angle_deg * static_cast<T>(M_PI)) / static_cast<T>(180);
  #endif // VECTORSTORM_NO_BOOST
}

#ifdef VECTORSTORM_NAMESPACE
}
#endif
