#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 2D vector
//-------------------------------------
/// Two dimensional vector of floats
using vector2f  = vector2<float>;
/// Two dimensional vector of doubles
using vector2d  = vector2<double>;
/// Two dimensional vector of long doubles
using vector2ld = vector2<long double>;
/// Two dimensional vector of integers
using vector2i  = vector2<int>;
/// Two dimensional vector of unsigned integers
using vector2ui = vector2<unsigned int>;

// abbreviated aliases
template<typename T>
using vec2   = vector2<T>;
using vec2f  = vector2f;
using vec2d  = vector2d;
using vec2ld = vector2ld;
using vec2i  = vector2i;
using vec2ui = vector2ui;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
