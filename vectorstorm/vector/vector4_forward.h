#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

template<typename T> class vector4;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "vector4_types.h"

namespace std {

template<typename T> constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept;
template<typename T> constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept;

}
