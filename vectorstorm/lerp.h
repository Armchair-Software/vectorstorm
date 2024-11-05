#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

template<typename T, typename F>
inline static constexpr T lerp(T const a, T const b, F factor) noexcept __attribute__((__always_inline__));

template<typename T, typename F>
inline static constexpr T lerp(T const a, T const b, F factor) noexcept {
  /// Linear interpolation helper
  return ((decltype(a){1.0} - factor) * a) + (factor * b);
};

#ifdef VECTORSTORM_NAMESPACE
}
#endif
