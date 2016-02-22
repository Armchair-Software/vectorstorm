#ifndef VECTORSTORM_VECTOR4_TYPES_H_INCLUDED
#define VECTORSTORM_VECTOR4_TYPES_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 4D vector
//-------------------------------------
/// Four dimensional vector of floats
using vector4f  = vector4<float>;
/// Four dimensional vector of doubles
using vector4d  = vector4<double>;
/// Four dimensional vector of long doubles
using vector4ld = vector4<long double>;
/// Four dimensional vector of ints
using vector4i  = vector4<int>;

// abbreviated aliases
template<typename T>
using vec4   = vector4<T>;
using vec4f  = vector4f;
using vec4d  = vector4d;
using vec4ld = vector4ld;
using vec4i  = vector4i;

// deprecated transitional declarations
template<typename T>
using Vector4   __attribute__((deprecated("Use vector4 or vec4 instead."))) = vector4<T>;
using Vector4f  __attribute__((deprecated("Use vector4 or vec4 instead."))) = vector4f;
using Vector4d  __attribute__((deprecated("Use vector4 or vec4 instead."))) = vector4d;
using Vector4ld __attribute__((deprecated("Use vector4 or vec4 instead."))) = vector4ld;
using Vector4i  __attribute__((deprecated("Use vector4 or vec4 instead."))) = vector4i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_VECTOR4_TYPES_H_INCLUDED
