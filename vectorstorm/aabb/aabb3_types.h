#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

/// 3D axis-aligned bounding box of floats
using aabb3f  = aabb3<float>;
/// 3D axis-aligned bounding box of doubles
using aabb3d  = aabb3<double>;
/// 3D axis-aligned bounding box of long doubles
using aabb3ld = aabb3<long double>;
/// 2D axis-aligned bounding box of integers
using aabb3i  = aabb3<int>;
/// 2D axis-aligned bounding box of unsigned integers
using aabb3ui = aabb3<unsigned int>;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
