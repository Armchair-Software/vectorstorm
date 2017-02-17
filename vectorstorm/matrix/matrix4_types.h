#ifndef VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
#define VECTORSTORM_MATRIX4_TYPES_H_INCLUDED

#include "vectorstorm/deprecated_macros.h"

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 4x4 matrix
//-------------------------------------
/// matrix 4x4 of floats
using matrix4f  = matrix4<float>;
/// matrix 4x4 of doubles
using matrix4d  = matrix4<double>;
/// matrix 4x4 of long doubles
using matrix4ld = matrix4<long double>;
/// matrix 4x4 of int
using matrix4i  = matrix4<int>;

// abbreviated aliases
template<typename T>
using mat4   = matrix4<T>;
using mat4f  = matrix4f;
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

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#endif // VECTORSTORM_MATRIX4_TYPES_H_INCLUDED
