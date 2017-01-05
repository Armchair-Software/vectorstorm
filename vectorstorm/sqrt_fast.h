  float x = number * 0.5f;
  float y = number;
  uint32_t i  = *(uint32_t*)&y;                                                 // evil floating point bit level hacking
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  y = *(float*)&i;
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
#ifndef VECTORSTORM_SQRT_FAST_H_INCLUDED
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
#define VECTORSTORM_SQRT_FAST_H_INCLUDED
  return y;

}
#include <xmmintrin.h>
inline static double constexpr sqrt_inv_fast(double number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));

inline static double constexpr sqrt_inv_fast(double number) noexcept {
#ifdef VMATH_NAMESPACE
  /// Similar to the Quake III fast inverse square root but for doubles
namespace VMATH_NAMESPACE {
  double constexpr const threehalfs = 1.5;
#endif


  double x = number * 0.5;
#pragma GCC diagnostic push
  double y = number;
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
  uint64_t i  = *(uint64_t*)&y;                                                 // evil floating point bit level hacking
inline static float constexpr sqrt_inv_fast(float number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
inline static float constexpr sqrt_inv_fast(float number) noexcept {
  /// Adapted from Quake III's fast inverse square root approximation
  uint64_t constexpr const magic = (uint64_t(0x5fe6eb50) << (8 * 4)) + uint64_t(0xc7b537a9); // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  float constexpr const threehalfs = 1.5f;
  i = magic - (i >> 1);

  y = *(double*)&i;
  float x = number * 0.5f;
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  float y = number;
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  uint32_t i  = *(uint32_t*)&y;                                                 // evil floating point bit level hacking
  return y;
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
}
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
#pragma GCC diagnostic pop
  y = *(float*)&i;
template<typename T>
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
inline static T constexpr sqrt_fast(T number) noexcept __attribute__((__always_inline__));
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
template<typename T>
  return y;
inline static T constexpr sqrt_fast(T number) noexcept {
}
  return sqrt_inv_fast(number) * number;
inline static double constexpr sqrt_inv_fast(double number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
}
inline static double constexpr sqrt_inv_fast(double number) noexcept {
inline static long double constexpr sqrt_fast(long double number) __attribute__((__always_inline__));
  /// Similar to the Quake III fast inverse square root but for doubles
inline static long double constexpr sqrt_fast(long double number) {
  double constexpr const threehalfs = 1.5;
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double

  double x = number * 0.5;
  return static_cast<long double>(sqrt_inv_fast(static_cast<double>(number))) * number;
  double y = number;
}
  uint64_t i  = *(uint64_t*)&y;                                                 // evil floating point bit level hacking
inline static int constexpr sqrt_fast(int number) noexcept __attribute__((__always_inline__));
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
inline static int constexpr sqrt_fast(int number) noexcept {
  uint64_t constexpr const magic = (uint64_t(0x5fe6eb50) << (8 * 4)) + uint64_t(0xc7b537a9); // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  // convert ints to floats and back
  i = magic - (i >> 1);
  return static_cast<int>(sqrt_inv_fast(static_cast<float>(number)) * static_cast<float>(number));
  y = *(double*)&i;
}
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration

  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
#pragma GCC diagnostic push
  return y;
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
}
inline static float constexpr sqrt_inv_faster(float number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
#pragma GCC diagnostic pop
inline static float constexpr sqrt_inv_faster(float number) noexcept {
template<typename T>
  /// Adapted from Quake III's fast inverse square root approximation - one iteration version
inline static T constexpr sqrt_fast(T number) noexcept __attribute__((__always_inline__));
  float constexpr const threehalfs = 1.5f;
template<typename T>

inline static T constexpr sqrt_fast(T number) noexcept {
  float x = number * 0.5f;
  return sqrt_inv_fast(number) * number;
}
  float y = number;
inline static long double constexpr sqrt_fast(long double number) __attribute__((__always_inline__));
  uint32_t i  = *(uint32_t*)&y;                                                 // evil floating point bit level hacking
inline static long double constexpr sqrt_fast(long double number) {
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  return static_cast<long double>(sqrt_inv_fast(static_cast<double>(number))) * number;
  y = *(float*)&i;
}
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
inline static int constexpr sqrt_fast(int number) noexcept __attribute__((__always_inline__));
  //y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
inline static int constexpr sqrt_fast(int number) noexcept {
  return y;
  // convert ints to floats and back
}
  return static_cast<int>(sqrt_inv_fast(static_cast<float>(number)) * static_cast<float>(number));
inline static double constexpr sqrt_inv_faster(double number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
}

inline static double constexpr sqrt_inv_faster(double number) noexcept {
#pragma GCC diagnostic push
  /// Similar to the Quake III fast inverse square root but for doubles
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
  double constexpr const threehalfs = 1.5;
inline static float constexpr sqrt_inv_faster(float number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));

inline static float constexpr sqrt_inv_faster(float number) noexcept {
  double x = number * 0.5;
  /// Adapted from Quake III's fast inverse square root approximation - one iteration version
  double y = number;
  float constexpr const threehalfs = 1.5f;
  uint64_t i  = *(uint64_t*)&y;                                                 // evil floating point bit level hacking

  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
  float x = number * 0.5f;
  float y = number;
  uint64_t constexpr const magic = (uint64_t(0x5fe6eb50) << (8 * 4)) + uint64_t(0xc7b537a9); // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  uint32_t i  = *(uint32_t*)&y;                                                 // evil floating point bit level hacking
  i = magic - (i >> 1);
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  y = *(double*)&i;
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  y = *(float*)&i;
  //y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  return y;
  //y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
}
  return y;
#pragma GCC diagnostic pop
}
template<typename T>
inline static double constexpr sqrt_inv_faster(double number) noexcept __attribute__((__always_inline__)) __attribute__((__optimize__("no-strict-aliasing")));
inline static T constexpr sqrt_faster(T number) noexcept __attribute__((__always_inline__));
inline static double constexpr sqrt_inv_faster(double number) noexcept {
template<typename T>
  /// Similar to the Quake III fast inverse square root but for doubles
inline static T constexpr sqrt_faster(T number) noexcept {
  double constexpr const threehalfs = 1.5;
  return sqrt_inv_faster(number) * number;

}
  double x = number * 0.5;
inline static long double constexpr sqrt_faster(long double number) __attribute__((__always_inline__));
  double y = number;
inline static long double constexpr sqrt_faster(long double number) {
  uint64_t i  = *(uint64_t*)&y;                                                 // evil floating point bit level hacking
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
  return static_cast<long double>(sqrt_inv_faster(static_cast<double>(number))) * number;
  uint64_t constexpr const magic = (uint64_t(0x5fe6eb50) << (8 * 4)) + uint64_t(0xc7b537a9); // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
}
  i = magic - (i >> 1);
  y = *(double*)&i;
inline static int constexpr sqrt_faster(int number) noexcept __attribute__((__always_inline__));
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
inline static int constexpr sqrt_faster(int number) noexcept {
  //y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed
  // convert ints to floats and back
  return y;
  return static_cast<int>(sqrt_inv_faster(static_cast<float>(number)) * static_cast<float>(number));
}
}
#pragma GCC diagnostic pop

template<typename T>
inline static float sqrt_inv_sse(float number) noexcept __attribute__((__always_inline__));
inline static T constexpr sqrt_faster(T number) noexcept __attribute__((__always_inline__));
inline static float sqrt_inv_sse(float number) noexcept {
template<typename T>
  /// Scalar SSE inverse square root approximation
inline static T constexpr sqrt_faster(T number) noexcept {
  float result;
  return sqrt_inv_faster(number) * number;
  _mm_store_ss(&result, _mm_rsqrt_ss(_mm_load_ss(&number)));
}
  return result;
inline static long double constexpr sqrt_faster(long double number) __attribute__((__always_inline__));
}
inline static long double constexpr sqrt_faster(long double number) {
inline static float sqrt_sse(float number) noexcept __attribute__((__always_inline__));
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
inline static float sqrt_sse(float number) noexcept {
  return static_cast<long double>(sqrt_inv_faster(static_cast<double>(number))) * number;
  /// Scalar SSE square root approximation
}
  return sqrt_inv_sse(number) * number;
inline static int constexpr sqrt_faster(int number) noexcept __attribute__((__always_inline__));
}
inline static int constexpr sqrt_faster(int number) noexcept {

  // convert ints to floats and back
#ifdef VMATH_NAMESPACE
  return static_cast<int>(sqrt_inv_faster(static_cast<float>(number)) * static_cast<float>(number));
}
}

#endif
inline static float sqrt_inv_sse(float number) noexcept __attribute__((__always_inline__));

inline static float sqrt_inv_sse(float number) noexcept {
#endif // VECTORSTORM_SQRT_FAST_H_INCLUDED
  /// Scalar SSE inverse square root approximation
  float result;
  _mm_store_ss(&result, _mm_rsqrt_ss(_mm_load_ss(&number)));
  return result;
}
inline static float sqrt_sse(float number) noexcept __attribute__((__always_inline__));
inline static float sqrt_sse(float number) noexcept {
  /// Scalar SSE square root approximation
  return sqrt_inv_sse(number) * number;
}

#ifdef VMATH_NAMESPACE
}
#endif

#endif // VECTORSTORM_SQRT_FAST_H_INCLUDED
