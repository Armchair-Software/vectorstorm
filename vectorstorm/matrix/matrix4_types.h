using matrix4d  = matrix4<double>;
/// matrix 4x4 of long doubles
using matrix4ld = matrix4<long double>;
/// matrix 4x4 of int
#ifndef VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
using matrix4i  = matrix4<int>;
#define VECTORSTORM_MATRIX4_TYPES_H_INCLUDED


// abbreviated aliases
#ifdef VMATH_NAMESPACE
template<typename T>
namespace VMATH_NAMESPACE {
using mat4   = matrix4<T>;
#endif
using mat4f  = matrix4f;

using mat4d  = matrix4d;
//-------------------------------------
using mat4ld = matrix4ld;
// Typedef shortcuts for 4x4 matrix
using mat4i  = matrix4i;
//-------------------------------------

/// matrix 4x4 of floats
// deprecated transitional declarations
using matrix4f  = matrix4<float>;
template<typename T>
/// matrix 4x4 of doubles
using Matrix4   __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4<T>;
using matrix4d  = matrix4<double>;
using Matrix4f  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4f;
/// matrix 4x4 of long doubles
using Matrix4d  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4d;
using matrix4ld = matrix4<long double>;
using Matrix4ld __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4ld;
/// matrix 4x4 of int
using Matrix4i  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4i;
using matrix4i  = matrix4<int>;


#ifdef VMATH_NAMESPACE
// abbreviated aliases
}
template<typename T>
#endif //VMATH_NAMESPACE
using mat4   = matrix4<T>;

using mat4f  = matrix4f;
#endif // VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
using mat4d  = matrix4d;
using mat4ld = matrix4ld;
using mat4i  = matrix4i;

// deprecated transitional declarations
template<typename T>
using Matrix4   __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4<T>;
using Matrix4f  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4f;
using Matrix4d  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4d;
using Matrix4ld __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4ld;
using Matrix4i  __attribute__((deprecated("Use matrix4 or mat4 instead."))) = matrix4i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
