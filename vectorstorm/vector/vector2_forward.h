#ifndef VECTORSTORM_VECTOR2_FORWARD_H_INCLUDED
#define VECTORSTORM_VECTOR2_FORWARD_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

template<typename T> class vector2;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector2_types.h"

namespace std {

template<typename T> constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) noexcept;
template<typename T> constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) noexcept;

}

#endif // VECTORSTORM_VECTOR2_FORWARD_H_INCLUDED
