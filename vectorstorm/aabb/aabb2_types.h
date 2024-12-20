#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

/// 2D axis-aligned bounding box of floats
using aabb2f  = aabb2<float>;
/// 2D axis-aligned bounding box of doubles
using aabb2d  = aabb2<double>;
/// 2D axis-aligned bounding box of long doubles
using aabb2ld = aabb2<long double>;
/// 2D axis-aligned bounding box of integers
using aabb2i  = aabb2<int>;
/// 2D axis-aligned bounding box of unsigned integers
using aabb2ui = aabb2<unsigned int>;

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
