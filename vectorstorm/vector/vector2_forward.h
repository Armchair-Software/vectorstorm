#ifndef VECTORSTORM_VECTOR2_FORWARD_H_INCLUDED
#define VECTORSTORM_VECTOR2_FORWARD_H_INCLUDED

#include "vectorstorm/deprecated_macros.h"

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

template<typename T> class vector2;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "vector2_types.h"

namespace std {

template<typename T> constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) noexcept;
template<typename T> constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) noexcept;

}

#endif // VECTORSTORM_VECTOR2_FORWARD_H_INCLUDED
