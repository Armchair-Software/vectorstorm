#pragma once

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
/// matrix 4x4 of integers
using matrix4i  = matrix4<int>;
/// matrix 4x4 of unsigned integers
using matrix4ui = matrix4<unsigned int>;

// abbreviated aliases
template<typename T>
using mat4   = matrix4<T>;
using mat4f  = matrix4f;
using mat4d  = matrix4d;
using mat4ld = matrix4ld;
using mat4i  = matrix4i;
using mat4ui = matrix4ui;

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
