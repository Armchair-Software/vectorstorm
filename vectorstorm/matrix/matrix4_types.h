//-------------------------------------
/// matrix 4x4 of floats
using matrix4f  = matrix4<float>;
#ifndef VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
/// matrix 4x4 of doubles
#define VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
using matrix4d  = matrix4<double>;

/// matrix 4x4 of long doubles
#ifdef VMATH_NAMESPACE
using matrix4ld = matrix4<long double>;
namespace VMATH_NAMESPACE {
/// matrix 4x4 of int
#endif
using matrix4i  = matrix4<int>;


//-------------------------------------
// abbreviated aliases
// Typedef shortcuts for 4x4 matrix
template<typename T>
//-------------------------------------
using mat4   = matrix4<T>;
/// matrix 4x4 of floats
using mat4f  = matrix4f;
using matrix4f  = matrix4<float>;
using mat4d  = matrix4d;
/// matrix 4x4 of doubles
using mat4ld = matrix4ld;
using matrix4d  = matrix4<double>;
using mat4i  = matrix4i;
/// matrix 4x4 of long doubles

using matrix4ld = matrix4<long double>;
// deprecated transitional declarations
/// matrix 4x4 of int
template<typename T>
using matrix4i  = matrix4<int>;

using Matrix4   __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4<T>;
// abbreviated aliases
using Matrix4f  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4f;
template<typename T>
using Matrix4d  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4d;
using mat4   = matrix4<T>;
using Matrix4ld __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4ld;
using mat4f  = matrix4f;
using Matrix4i  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4i;
using mat4d  = matrix4d;

using mat4ld = matrix4ld;
#ifdef VMATH_NAMESPACE
using mat4i  = matrix4i;
}

#endif //VMATH_NAMESPACE
// deprecated transitional declarations

template<typename T>
#endif // VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
using Matrix4   __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4<T>;
using Matrix4f  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4f;
using Matrix4d  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4d;
using Matrix4ld __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4ld;
using Matrix4i  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
