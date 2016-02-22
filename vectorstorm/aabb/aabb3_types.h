#ifndef VECTORSTORM_AABB3_TYPES_H_INCLUDED
#define VECTORSTORM_AABB3_TYPES_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/// 3D axis-aligned bounding box of floats
using aabb3f  = aabb3<float>;
/// 3D axis-aligned bounding box of doubles
using aabb3d  = aabb3<double>;
/// 3D axis-aligned bounding box of long doubles
using aabb3ld = aabb3<long double>;
/// 2D axis-aligned bounding box of integers
using aabb3i  = aabb3<int>;

// deprecated transitional declarations
template<typename T>
using Aabb3   __attribute__((deprecated("Use aabb3 instead."))) = aabb3<T>;
using Aabb3f  __attribute__((deprecated("Use aabb3 instead."))) = aabb3f;
using Aabb3d  __attribute__((deprecated("Use aabb3 instead."))) = aabb3d;
using Aabb3ld __attribute__((deprecated("Use aabb3 instead."))) = aabb3ld;
using Aabb3i  __attribute__((deprecated("Use aabb3 instead."))) = aabb3i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_AABB3_TYPES_H_INCLUDED
