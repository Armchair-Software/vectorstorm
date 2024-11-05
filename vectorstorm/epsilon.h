#pragma once

#include <limits>

// note: use VECTORSTORM_SOFT_COMPARE to enable fuzzy matching for different types,
// with epsilon used to match within a range of rounding error - but doing this
// can be very expensive in some cases.
// old version: double constexpr epsilon = 4.37114e-05;
template<class T>
constexpr T epsilon{std::numeric_limits<T>::epsilon()};
#define EPSILON epsilon
