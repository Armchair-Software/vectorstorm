#pragma once

#include <cstdint>
#ifdef __SSE__
  #include <xmmintrin.h>
#endif // __SSE__

#ifdef __clang__
  #define CONSTEXPR_IF_NO_CLANG
#else
  #define CONSTEXPR_IF_NO_CLANG constexpr
#endif // __clang__ - see https://stackoverflow.com/questions/46576847/clang-vs-gcc-crtp-constexpr-variable-cannot-have-non-literal-type

#if __has_cpp_attribute(__optimise__)
  #define OPTIMISE_NO_STRICT_ALIASING __attribute__((__optimize__("no-strict-aliasing"))
#else
  #define OPTIMISE_NO_STRICT_ALIASING
#endif

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#ifdef __clang__
  #pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
#endif // __clang__
inline static float CONSTEXPR_IF_NO_CLANG sqrt_inv_fast(float number) noexcept __attribute__((__always_inline__)) OPTIMISE_NO_STRICT_ALIASING;
inline static float CONSTEXPR_IF_NO_CLANG sqrt_inv_fast(float number) noexcept {
  /// Adapted from Quake III's fast inverse square root approximation
  float constexpr threehalfs = 1.5f;

  float x{number * 0.5f};
  float y{number};
  uint32_t i{*reinterpret_cast<uint32_t*>(&y)};                                 // evil floating point bit level hacking
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  y = *reinterpret_cast<float*>(&i);
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed - see sqrt_inv_coarse below
  return y;
}
inline static double CONSTEXPR_IF_NO_CLANG sqrt_inv_fast(double number) noexcept __attribute__((__always_inline__)) OPTIMISE_NO_STRICT_ALIASING;
inline static double CONSTEXPR_IF_NO_CLANG sqrt_inv_fast(double number) noexcept {
  /// Similar to the Quake III fast inverse square root but for doubles
  double constexpr threehalfs = 1.5;

  double x{number * 0.5};
  double y{number};
  uint64_t i{*reinterpret_cast<uint64_t*>(&y)};                                 // evil floating point bit level hacking
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
  uint64_t constexpr magic{(uint64_t{0x5fe6eb50} << (8 * 4)) + uint64_t{0xc7b537a9}}; // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  i = magic - (i >> 1);
  y = *reinterpret_cast<double*>(&i);
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  y = y * (threehalfs - (x * y * y));                                           // 2nd iteration, this can be removed - see sqrt_inv_coarse below
  return y;
}
#pragma GCC diagnostic pop
template<typename T>
inline static T constexpr sqrt_fast(T number) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sqrt_fast(T number) noexcept {
  return sqrt_inv_fast(number) * number;
}
inline static long double constexpr sqrt_fast(long double number) __attribute__((__always_inline__));
inline static long double constexpr sqrt_fast(long double number) {
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
  return static_cast<long double>(sqrt_inv_fast(static_cast<double>(number))) * number;
}
inline static int constexpr sqrt_fast(int number) noexcept __attribute__((__always_inline__));
inline static int constexpr sqrt_fast(int number) noexcept {
  // convert ints to floats and back
  return static_cast<int>(sqrt_inv_fast(static_cast<float>(number)) * static_cast<float>(number));
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#ifdef __clang__
  #pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
#endif // __clang__
inline static float CONSTEXPR_IF_NO_CLANG sqrt_inv_coarse(float number) noexcept __attribute__((__always_inline__)) OPTIMISE_NO_STRICT_ALIASING;
inline static float CONSTEXPR_IF_NO_CLANG sqrt_inv_coarse(float number) noexcept {
  /// Adapted from Quake III's fast inverse square root approximation - one iteration version
  float constexpr threehalfs = 1.5f;

  float x{number * 0.5f};
  float y{number};
  uint32_t i{*reinterpret_cast<uint32_t*>(&y)};                                 // evil floating point bit level hacking
  //i = 0x5f3759df - (i >> 1);                                                    // what the fuck?
  i = 0x5f375a84 - (i >> 1);                                                    // improved magic number from http://jheriko-rtw.blogspot.co.uk/2009/04/understanding-and-improving-fast.html
  y = *reinterpret_cast<float*>(&i);
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  // 2nd iteration omitted
  return y;
}
inline static double CONSTEXPR_IF_NO_CLANG sqrt_inv_coarse(double number) noexcept __attribute__((__always_inline__)) OPTIMISE_NO_STRICT_ALIASING;
inline static double CONSTEXPR_IF_NO_CLANG sqrt_inv_coarse(double number) noexcept {
  /// Similar to the Quake III fast inverse square root but for doubles
  double constexpr threehalfs = 1.5;

  double x{number * 0.5};
  double y{number};
  uint64_t i{*reinterpret_cast<uint64_t*>(&y)};                                 // evil floating point bit level hacking
  //i = 0x5fe6eb50c7b537a9ll - (i >> 1);                                          // even more magic than "what the fuck" number
  uint64_t constexpr magic{(uint64_t{0x5fe6eb50} << (8 * 4)) + uint64_t{0xc7b537a9}}; // hack to produce 0x5fe6eb50c7b537a9ll without triggering -Wlong-long warning
  i = magic - (i >> 1);
  y = *reinterpret_cast<double*>(&i);
  y = y * (threehalfs - (x * y * y));                                           // 1st iteration
  // 2nd iteration omitted
  return y;
}
#pragma GCC diagnostic pop
template<typename T>
inline static T constexpr sqrt_coarse(T number) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sqrt_coarse(T number) noexcept {
  return sqrt_inv_coarse(number) * number;
}
inline static long double constexpr sqrt_coarse(long double number) __attribute__((__always_inline__));
inline static long double constexpr sqrt_coarse(long double number) {
  // we don't have a way to handle long doubles with the fast approximation, so just cast to double
  return static_cast<long double>(sqrt_inv_coarse(static_cast<double>(number))) * number;
}
inline static int constexpr sqrt_coarse(int number) noexcept __attribute__((__always_inline__));
inline static int constexpr sqrt_coarse(int number) noexcept {
  // convert ints to floats and back
  return static_cast<int>(sqrt_inv_coarse(static_cast<float>(number)) * static_cast<float>(number));
}

#ifdef __SSE__
inline static float sqrt_inv_sse(float number) noexcept __attribute__((__always_inline__));
inline static float sqrt_inv_sse(float number) noexcept {
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
#else
#warning "SSE is not available, performance may be impacted - check your compilation flags."
#endif // __SSE__

#ifdef VECTORSTORM_NAMESPACE
}
#endif
