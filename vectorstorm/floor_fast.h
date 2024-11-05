#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

inline int constexpr floor_fast(float value) noexcept __attribute__((__const__)) __attribute__((__always_inline__));
inline int constexpr floor_fast(float value) noexcept {
  /// Fast floor of a float to an integer - this should be faster than std::floor
  // see http://stackoverflow.com/a/15341154/1678468
  int const i{static_cast<int>(value)};                                         // truncate
  return i - (static_cast<float>(i) > value);                                   // convert truncation to floor
}

inline int constexpr floor_fast(double value) noexcept __attribute__((__const__)) __attribute__((__always_inline__));
inline int constexpr floor_fast(double value) noexcept {
  /// Fast floor of a double to an integer - this should be faster than std::floor
  // see http://stackoverflow.com/a/15341154/1678468
  int const i{static_cast<int>(value)};                                         // truncate
  return i - (static_cast<double>(i) > value);                                  // convert truncation to floor
}

#ifdef VECTORSTORM_NAMESPACE
}
#endif
