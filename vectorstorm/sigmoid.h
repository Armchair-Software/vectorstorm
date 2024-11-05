#pragma once

#include <cmath>
#include "pi.h"
#ifndef VERTORSTORM_NO_BOOST
  #include <boost/math/special_functions/erf.hpp>
#endif // VERTORSTORM_NO_BOOST

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

/// Multiple sigmoid functions: http://www.wolframalpha.com/input/?i=plot+of+y%3D0.5+-+%280.5+*+cos%28x+*+pi%29%29+and+y%3D0.5+%2B+%28%280.5+%2F+tanh%282.0%29%29+*+tanh%28%28x+*+4.0%29+-+2.0%29%29+and+y%3D%28%28%281+%2F+%281+%2B+e^%28%280.5+-+x%29+*+8%29%29+-+0.5%29+*+%281+%2F+%281+%2F+%281+%2B+e^%28-4%29%29+-+0.5%29%29%29+*+0.5%29+%2B+0.5++for+x%3D0+to1+
// default sigmoid:
#define sigmoid sigmoid_sin

template<typename T>
inline static T constexpr sigmoid_sin(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_sin(T value) noexcept {
  /// Scale a 0-1 value to a sinusoidal sigmoid - https://www.wolframalpha.com/input/?i=plot+0.5+-+%280.5+*+cos%28x+*+pi%29%29+from+0+to+1
  constexpr T half{static_cast<T>(0.5)};
  #ifndef VECTORSTORM_NO_BOOST
    return half - (half * std::cos(value * boost::math::constants::pi<T>()));
  #else  // VECTORSTORM_NO_BOOST
    return half - (half * std::cos(value * static_cast<T>(M_PI)));
  #endif // VECTORSTORM_NO_BOOST
};

template<typename T>
inline static T constexpr sigmoid_tanh(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_tanh(T value) noexcept {
  /// Scale a 0-1 value to a hyperbolic tangent function - https://www.wolframalpha.com/input/?i=plot+0.5+%2B+%280.5+*+tanh%28%28x+*+4.0%29+-+2.0%29%29+from+0+to+1
  T constexpr half{static_cast<T>(0.5)};
  //return half + (half * std::tanh((value * static_cast<T>(4)) - static_cast<T>(2)));
  // this ensures that we scale from exactly 0 to 1: https://www.wolframalpha.com/input/?i=plot+0.5+%2B+%28%280.5+%2F+tanh%282.0%29%29+*+tanh%28%28x+*+4.0%29+-+2.0%29%29+from+0+to+1
  T constexpr scale{half / std::tanh(static_cast<T>(2))};
  return half + (scale * std::tanh((value * static_cast<T>(4)) - static_cast<T>(2)));
};

template<typename T>
inline static T constexpr sigmoid_log(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_log(T value) noexcept {
  /// Scale a 0-1 value to a logistic function - https://www.wolframalpha.com/input/?i=plot+1+%2F+%281+%2B+e^%28%280.5+-+x%29+*+8%29%29+from+0+to+1
  constexpr T half{static_cast<T>(0.5)};
  //return static_cast<T>(1) / (static_cast<T>(1) + std::exp((half - value) * static_cast<T>(8)));
  // this ensures that we scale from exactly 0 to 1: https://www.wolframalpha.com/input/?i=plot+%28%28%281+%2F+%281+%2B+e^%28%280.5+-+x%29+*+8%29%29+-+0.5%29+*+%281+%2F+%281+%2F+%281+%2B+e^%28-4%29%29+-+0.5%29%29%29+*+0.5%29+%2B+0.5+from+x%3D0+to+1
  T constexpr scale{static_cast<T>(1) / (static_cast<T>(1) / (static_cast<T>(1) + std::exp(static_cast<T>(-4))) - half)};
  return ((((static_cast<T>(1) / (static_cast<T>(1) + std::exp((half - value) * static_cast<T>(8)))) - half) * scale) * half) + half;
};

#ifndef VERTORSTORM_NO_BOOST

template<typename T>
inline static T constexpr sigmoid_erf(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_erf(T value) noexcept {
  /// Scale a 0-1 value to an error function - https://www.wolframalpha.com/input/?i=plot+0.5+%2B+(0.5+*+erf((x+*+4)+-+2))+from+0+to+1
  constexpr T half{static_cast<T>(0.5)};
  //return half + (half * boost::math::erf((value * static_cast<T>(4)) - static_cast<T>(2)));
  // this ensures that we scale from exactly 0 to 1: https://www.wolframalpha.com/input/?i=plot+0.5+%2B+((0.5+%2F+erf(2.0))+*+erf((x+*+4.0)+-+2.0))+from+0+to+1
  T const scale{half / boost::math::erf(static_cast<T>(2))};
  return half + (scale * boost::math::erf((value * static_cast<T>(4)) - static_cast<T>(2)));
};

#endif // VERTORSTORM_NO_BOOST

#ifdef VECTORSTORM_NAMESPACE
}
#endif
