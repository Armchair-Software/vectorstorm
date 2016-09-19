#ifndef VECTORSTORM_VECTOR3_FORWARD_H_INCLUDED
#define VECTORSTORM_VECTOR3_FORWARD_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

template<typename T> class vector3;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector3_types.h"

namespace std {

template<typename T> constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept;
template<typename T> constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept;

}

#endif // VECTORSTORM_VECTOR3_FORWARD_H_INCLUDED
