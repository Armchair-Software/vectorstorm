#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 3x3 matrix
//-------------------------------------
/// matrix 3x3 of floats
using matrix3f  = matrix3<float>;
/// matrix 3x3 of doubles
using matrix3d  = matrix3<double>;
/// matrix 3x3 of long doubles
using matrix3ld = matrix3<long double>;
/// matrix 3x3 of integers
using matrix3i  = matrix3<int>;
/// matrix 3x3 of unsigned integers
using matrix3ui = matrix3<unsigned int>;

// abbreviated aliases
template<typename T>
using mat3   = matrix3<T>;
using mat3f  = matrix3f;
using mat3d  = matrix3d;
using mat3ld = matrix3ld;
using mat3i  = matrix3i;
using mat3ui = matrix3ui;

// Special WebGPU padded 3x3 matrix - only float is needed
using mat3fwgpu = matrix3wgpu<float>;

// deprecated transitional declarations
template<typename T>
using Matrix3   __attribute__((deprecated("Use matrix3 or mat3 instead."))) = matrix3<T>;
using Matrix3f  __attribute__((deprecated("Use matrix3 or mat3 instead."))) = matrix3f;
using Matrix3d  __attribute__((deprecated("Use matrix3 or mat3 instead."))) = matrix3d;
using Matrix3ld __attribute__((deprecated("Use matrix3 or mat3 instead."))) = matrix3ld;
using Matrix3i  __attribute__((deprecated("Use matrix3 or mat3 instead."))) = matrix3i;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
