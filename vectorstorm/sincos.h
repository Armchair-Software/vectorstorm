#pragma once

#include "pi.h"

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

template<typename T>
inline static void constexpr sincos_any(T const angle_rad, T &out_sin, T &out_cos) __attribute__((__always_inline__));
template<typename T>
inline static void constexpr sincos_any(T const angle_rad, T &out_sin, T &out_cos) {
  #if defined(__EMSCRIPTEN__)
    sincos(angle_rad, &out_sin, &out_cos);
  #else
    __builtin_sincos(angle_rad, &out_sin, &out_cos);
  #endif
}
inline static void constexpr sincos_any(int const angle_rad, int &out_sin, int &out_cos) __attribute__((__always_inline__));
inline static void constexpr sincos_any(int const angle_rad, int &out_sin, int &out_cos) {
  // if we're only working with integers, assume single precision is enough
  #if defined(__EMSCRIPTEN__)
    float out_sin_temp;
    float out_cos_temp;
    sincosf(static_cast<float>(angle_rad), &out_sin_temp, &out_cos_temp);
    out_sin = static_cast<int>(out_sin_temp);
    out_cos = static_cast<int>(out_cos_temp);
  #elif defined(__GNUC__) && !defined(__clang__)
    float out_sin_temp;
    float out_cos_temp;
    __builtin_sincosf(static_cast<float>(angle_rad), &out_sin_temp, &out_cos_temp);
    out_sin = static_cast<int>(out_sin_temp);
    out_cos = static_cast<int>(out_cos_temp);
  #else
    out_sin = static_cast<int>(std::sin(static_cast<float>(angle_rad)));
    out_cos = static_cast<int>(std::cos(static_cast<float>(angle_rad)));
  #endif
}
inline static void constexpr sincos_any(float const angle_rad, float &out_sin, float &out_cos) __attribute__((__always_inline__));
inline static void constexpr sincos_any(float const angle_rad, float &out_sin, float &out_cos) {
  #if defined(__EMSCRIPTEN__)
    sincosf(angle_rad, &out_sin, &out_cos);
  #elif defined(__GNUC__) && !defined(__clang__)
    __builtin_sincosf(angle_rad, &out_sin, &out_cos);
  #else
    out_sin = std::sin(angle_rad);
    out_cos = std::cos(angle_rad);
  #endif
}
inline static void constexpr sincos_any(long double const angle_rad, long double &out_sin, long double &out_cos) __attribute__((__always_inline__));
inline static void constexpr sincos_any(long double const angle_rad, long double &out_sin, long double &out_cos) {
  #if defined(__EMSCRIPTEN__)
    sincosl(angle_rad, &out_sin, &out_cos);
  #elif defined(__GNUC__) && !defined(__clang__)
    __builtin_sincosl(angle_rad, &out_sin, &out_cos);
  #else
    out_sin = std::sin(angle_rad);
    out_cos = std::cos(angle_rad);
  #endif
}

#ifdef VECTORSTORM_NAMESPACE
}
#endif
