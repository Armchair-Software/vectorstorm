#ifndef VECTORSTORM_VECTOR4_FORWARD_H_INCLUDED
#define VECTORSTORM_VECTOR4_FORWARD_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

template<typename T> class vector4;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector4_types.h"

namespace std {

template<typename T> constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept;
template<typename T> constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept;

}

#endif // VECTORSTORM_VECTOR4_FORWARD_H_INCLUDED
