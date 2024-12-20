#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
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
/// Four dimensional vector of integers
using vector4i  = vector4<int>;
/// Four dimensional vector of unsigned integers
using vector4ui = vector4<unsigned int>;

// abbreviated aliases
template<typename T>
using vec4   = vector4<T>;
using vec4f  = vector4f;
using vec4d  = vector4d;
using vec4ld = vector4ld;
using vec4i  = vector4i;
using vec4ui = vector4ui;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
