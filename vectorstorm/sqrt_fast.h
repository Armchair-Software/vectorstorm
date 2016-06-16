#ifndef VECTORSTORM_SQRT_FAST_H_INCLUDED
#define VECTORSTORM_SQRT_FAST_H_INCLUDED

#include <xmmintrin.h>

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
inline static float constexpr sqrt_inv_fast(float number) __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
inline static float constexpr sqrt_inv_fast(float number) {
  /// Adapted from Quake III's fast inverse square root approximation
  float constexpr const threehalfs = 1.5f;

  float x = number * 0.5f;
  float y = number;
  uint32_t i  = *(uint32_t*)&y;                                                 // evil floating point bit level hacking
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  y = *(float*)&i;
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  return y;
}
inline static double constexpr sqrt_inv_fast(double number) __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
inline static double constexpr sqrt_inv_fast(double number) {
  /// Similar to the Quake III fast inverse square root but for doubles
  double constexpr const threehalfs = 1.5;

  double x = number * 0.5;
  double y = number;
  uint64_t i  = *(uint64_t*)&y;                                                 // evil floating point bit level hacking
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
  uint64_t constexpr const magic = (uint64_t(0x5fe6eb50) << (8 * 4)) + uint64_t(0xc7b537a9); // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  i = magic - (i >> 1);
  y = *(double*)&i;
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  return y;
}
#pragma GCC diagnostic pop
template<typename T>
inline static T constexpr sqrt_fast(T number) __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sqrt_fast(T number) {
  return sqrt_inv_fast(number) * number;
}
inline static long double constexpr sqrt_fast(long double number) __attribute__((__always_inline__));
inline static long double constexpr sqrt_fast(long double number) {
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
  return static_cast<long double>(sqrt_inv_fast(static_cast<double>(number))) * number;
}
inline static int constexpr sqrt_fast(int number) __attribute__((__always_inline__));
inline static int constexpr sqrt_fast(int number) {
  // convert ints to floats and back
  return static_cast<int>(sqrt_inv_fast(static_cast<float>(number)) * static_cast<float>(number));
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
inline static float constexpr sqrt_inv_faster(float number) __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
inline static float constexpr sqrt_inv_faster(float number) {
  /// Adapted from Quake III's fast inverse square root approximation - one iteration version
  float constexpr const threehalfs = 1.5f;

  float x = number * 0.5f;
  float y = number;
  uint32_t i  = *(uint32_t*)&y;                                                 // evil floating point bit level hacking
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  y = *(float*)&i;
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  //y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  return y;
}
inline static double constexpr sqrt_inv_faster(double number) __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
inline static double constexpr sqrt_inv_faster(double number) {
  /// Similar to the Quake III fast inverse square root but for doubles
  double constexpr const threehalfs = 1.5;

  double x = number * 0.5;
  double y = number;
  uint64_t i  = *(uint64_t*)&y;                                                 // evil floating point bit level hacking
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
  uint64_t constexpr const magic = (uint64_t(0x5fe6eb50) << (8 * 4)) + uint64_t(0xc7b537a9); // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  i = magic - (i >> 1);
  y = *(double*)&i;
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  //y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  return y;
}
#pragma GCC diagnostic pop
template<typename T>
inline static T constexpr sqrt_faster(T number) __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sqrt_faster(T number) {
  return sqrt_inv_faster(number) * number;
}
inline static long double constexpr sqrt_faster(long double number) __attribute__((__always_inline__));
inline static long double constexpr sqrt_faster(long double number) {
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
  return static_cast<long double>(sqrt_inv_faster(static_cast<double>(number))) * number;
}
inline static int constexpr sqrt_faster(int number) __attribute__((__always_inline__));
inline static int constexpr sqrt_faster(int number) {
  // convert ints to floats and back
  return static_cast<int>(sqrt_inv_faster(static_cast<float>(number)) * static_cast<float>(number));
}

inline static float sqrt_inv_sse(float number) __attribute__((__always_inline__));
inline static float sqrt_inv_sse(float number) {
  /// Scalar SSE inverse square root approximation
  float result;
  _mm_store_ss(&result, _mm_rsqrt_ss(_mm_load_ss(&number)));
  return result;
}
inline static float sqrt_sse(float number) __attribute__((__always_inline__));
inline static float sqrt_sse(float number) {
  /// Scalar SSE square root approximation
  return sqrt_inv_sse(number) * number;
}

#ifdef VMATH_NAMESPACE
}
#endif

#endif // VECTORSTORM_SQRT_FAST_H_INCLUDED
