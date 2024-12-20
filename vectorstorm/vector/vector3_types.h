#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 3D vector
//-------------------------------------
/// Three dimensional vector of floats
using vector3f  = vector3<float>;
/// Three dimensional vector of doubles
using vector3d  = vector3<double>;
/// Three dimensional vector of long doubles
using vector3ld = vector3<long double>;
/// Three dimensional vector of integers
using vector3i  = vector3<int>;
/// Three dimensional vector of unsigned integers
using vector3ui = vector3<unsigned int>;

// abbreviated aliases
template<typename T>
using vec3   = vector3<T>;
using vec3f  = vector3f;
using vec3d  = vector3d;
using vec3ld = vector3ld;
using vec3i  = vector3i;
using vec3ui = vector3ui;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
