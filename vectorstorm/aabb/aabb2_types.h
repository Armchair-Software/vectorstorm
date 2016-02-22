#ifndef VECTORSTORM_AABB2_TYPES_H_INCLUDED
#define VECTORSTORM_AABB2_TYPES_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/// 2D axis-aligned bounding box of floats
using aabb2f  = aabb2<float>;
/// 2D axis-aligned bounding box of doubles
using aabb2d  = aabb2<double>;
/// 2D axis-aligned bounding box of long doubles
using aabb2ld = aabb2<long double>;
/// 2D axis-aligned bounding box of integers
using aabb2i  = aabb2<int>;

// deprecated transitional declarations
template<typename T>
using Aabb2   __attribute__((deprecated("Use aabb2 instead."))) = aabb2<T>;
using Aabb2f  __attribute__((deprecated("Use aabb2 instead."))) = aabb2f;
using Aabb2d  __attribute__((deprecated("Use aabb2 instead."))) = aabb2d;
using Aabb2ld __attribute__((deprecated("Use aabb2 instead."))) = aabb2ld;
using Aabb2i  __attribute__((deprecated("Use aabb2 instead."))) = aabb2i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_AABB2_TYPES_H_INCLUDED
