#ifndef VECTORSTORM_SINCOS_H_INCLUDED
#define VECTORSTORM_SINCOS_H_INCLUDED

#include "pi.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

template<typename T>
inline static void constexpr sincos_any(T const angle_rad, T &out_sin, T &out_cos) __attribute__((__always_inline__));
template<typename T>
inline static void constexpr sincos_any(T const angle_rad, T &out_sin, T &out_cos) {
  __builtin_sincos(angle_rad, &out_sin, &out_cos);
}
inline static void constexpr sincos_any(int const angle_rad, int &out_sin, int &out_cos) __attribute__((__always_inline__));
inline static void constexpr sincos_any(int const angle_rad, int &out_sin, int &out_cos) {
  // if we're only working with integers, assume single precision is enough
  float out_sin_temp = 0.0f;
  float out_cos_temp = 0.0f;
  __builtin_sincosf(static_cast<float>(angle_rad), &out_sin_temp, &out_cos_temp);
  out_sin = static_cast<int>(out_sin_temp);
  out_cos = static_cast<int>(out_cos_temp);
}
inline static void constexpr sincos_any(float const angle_rad, float &out_sin, float &out_cos) __attribute__((__always_inline__));
inline static void constexpr sincos_any(float const angle_rad, float &out_sin, float &out_cos) {
  __builtin_sincosf(angle_rad, &out_sin, &out_cos);
}
inline static void constexpr sincos_any(long double const angle_rad, long double &out_sin, long double &out_cos) __attribute__((__always_inline__));
inline static void constexpr sincos_any(long double const angle_rad, long double &out_sin, long double &out_cos) {
  __builtin_sincosl(angle_rad, &out_sin, &out_cos);
}

#ifdef VMATH_NAMESPACE
}
#endif

#endif // VECTORSTORM_SINCOS_H_INCLUDED
