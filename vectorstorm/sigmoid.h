#ifndef VECTORSTORM_SIGMOID_H_INCLUDED
#define VECTORSTORM_SIGMOID_H_INCLUDED

#include <cmath>
#include "pi.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/// Multiple sigmoid functions: http://www.wolframalpha.com/input/?i=plot+of+y%3D0.5+-+%280.5+*+cos%28x+*+pi%29%29+and+y%3D0.5+%2B+%28%280.5+%2F+tanh%282.0%29%29+*+tanh%28%28x+*+4.0%29+-+2.0%29%29+and+y%3D%28%28%281+%2F+%281+%2B+e^%28%280.5+-+x%29+*+8%29%29+-+0.5%29+*+%281+%2F+%281+%2F+%281+%2B+e^%28-4%29%29+-+0.5%29%29%29+*+0.5%29+%2B+0.5++for+x%3D0+to1+
// default sigmoid:
#define sigmoid sigmoid_sin

template<typename T>
inline static T constexpr sigmoid_sin(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_sin(T value) noexcept {
  /// Scale a 0-1 value to a sinusoidal sigmoid - https://www.wolframalpha.com/input/?i=plot+0.5+-+%280.5+*+cos%28x+*+pi%29%29+from+0+to+1
  #ifndef VMATH_NO_BOOST
    return static_cast<T>(0.5) - (static_cast<T>(0.5) * std::cos(value * boost::math::constants::pi<T>()));
  #else  // VMATH_NO_BOOST
    return static_cast<T>(0.5) - (static_cast<T>(0.5) * std::cos(value * M_PI));
  #endif // VMATH_NO_BOOST
};

template<typename T>
inline static T constexpr sigmoid_tanh(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_tanh(T value) noexcept {
  /// Scale a 0-1 value to a hyperbolic tangent function - https://www.wolframalpha.com/input/?i=plot+0.5+%2B+%280.5+*+tanh%28%28x+*+4.0%29+-+2.0%29%29+from+0+to+1
  //return static_cast<T>(0.5) + (static_cast<T>(0.5) * std::tanh((value * static_cast<T>(4)) - static_cast<T>(2)));
  // this ensures that we scale from exactly 0 to 1: https://www.wolframalpha.com/input/?i=plot+0.5+%2B+%28%280.5+%2F+tanh%282.0%29%29+*+tanh%28%28x+*+4.0%29+-+2.0%29%29+from+0+to+1
  T constexpr const scale = static_cast<T>(0.5) / std::tanh(static_cast<T>(2));
  return static_cast<T>(0.5) + (scale * std::tanh((value * static_cast<T>(4)) - static_cast<T>(2)));
};

template<typename T>
inline static T constexpr sigmoid_log(T value) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr sigmoid_log(T value) noexcept {
  /// Scale a 0-1 value to a logistic function - https://www.wolframalpha.com/input/?i=plot+1+%2F+%281+%2B+e^%28%280.5+-+x%29+*+8%29%29+from+0+to+1
  //return static_cast<T>(1) / (static_cast<T>(1) + std::exp((static_cast<T>(0.5) - value) * static_cast<T>(8)));
  // this ensures that we scale from exactly 0 to 1: https://www.wolframalpha.com/input/?i=plot+%28%28%281+%2F+%281+%2B+e^%28%280.5+-+x%29+*+8%29%29+-+0.5%29+*+%281+%2F+%281+%2F+%281+%2B+e^%28-4%29%29+-+0.5%29%29%29+*+0.5%29+%2B+0.5+from+x%3D0+to+1
  T constexpr const scale = (static_cast<T>(1) / (static_cast<T>(1) / (static_cast<T>(1) + std::exp(static_cast<T>(-4))) - static_cast<T>(0.5)));
  return ((((static_cast<T>(1) / (static_cast<T>(1) + std::exp((static_cast<T>(0.5) - value) * static_cast<T>(8)))) - static_cast<T>(0.5)) * scale) * static_cast<T>(0.5)) + static_cast<T>(0.5);
};

#ifdef VMATH_NAMESPACE
}
#endif

#endif // VECTORSTORM_SIGMOID_H_INCLUDED