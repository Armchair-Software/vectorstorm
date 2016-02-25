#ifndef VECTORSTORM_AABB3_H_INCLUDED
#define VECTORSTORM_AABB3_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/**
 * Three-dimensional axis-aligned bounding-box (aka AABB) class.
 *
 * This class provides functionality for:
 * - creating an AABB from a point, or another AABB,
 * - testing if a point of other AABB intersects with it,
 * - getting result of intersection with other AABB,
 * - transforming AABB with 4x4 matrix.
 *
 * There are also overloaded couple of operators to shorten common operations.
 * For instance you can use  @c operator<< on AABB to extend it with a passed point or other AABB.
 * @code
 * aabb3f aabb;
 * aabb << vector3f(1, 1, 2) << aabb3f(-3,-3,-3, 2, 2, 2);
 * @endcode
 */
template<typename T>
class aabb3 {
public:
  /**
   * Position of Min corner of bounding box.
   */
  vector3<T> min;

  /**
   * Position of Max corner of bounding box
   */
  vector3<T> max;

  /**
   * Constructs invalid axes-aligned bounding-box.
   * @see valid() for explanation of invalid bounding-box usage.
   */
  inline constexpr aabb3() __attribute__((__always_inline__))
    : min( 1,  1,  1),
      max(-1, -1, -1) {
  }

  /**
   * Constructs axes-aligned bound-box containing one point @a point
   * @param point
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3(vector3<SrcT> const &point)
    : min(point),
      max(point) {
  }

  /**
   * Constructs axes-aligned bounding-box from two corner points (@a x0, @a y0, @a z0)
   * and (@a x1, @a y1, @a z1)
   * @param x0 X-coordinate of first point
   * @param y0 Y-coordinate of first point
   * @param z0 Z-coordinate of first point
   * @param x1 X-coordinate of second point
   * @param y1 Y-coordinate of second point
   * @param z1 Z-coordinate of second point
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3(SrcT x0, SrcT y0, SrcT z0, SrcT x1, SrcT y1, SrcT z1)
    : min(std::min(x0, x1), std::min(y0, y1), std::min(z0, z1)),
      max(std::max(x0, x1), std::max(y0, y1), std::max(z0, z1)) {
  }

  /**
   * Constructs axes-aligned bounding-box from @a min and @b max
   * @param min X-coordinate of first point
   * @param max X-coordinate of second point
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3(vector3<SrcT> const &new_min, vector3<SrcT> const &new_max)
    : min(new_min),
      max(new_max) {
  }

  /**
   * Constructs axes-aligned bounding-box containing point (@a x, @a y, @a z)
   * @param x X-coordinate of point
   * @param y Y-coordinate of point
   * @param z Z-coordinate of point
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3(SrcT x, SrcT y, SrcT z)
    : min(x, y, z),
      max(x, y, z) {
  }

  /**
   * Creates copy of axis-aligned bounding-box
   * @param src Source bounding-box
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3(aabb3<SrcT> const &src)
    : min(src.min),
      max(src.max) {
  }

  /**
   * Move constructor from another axis-aligned bounding-box
   * @param src Source bounding-box
   */
  template<typename SrcT> __attribute__((__always_inline__))
  inline constexpr aabb3(aabb3<SrcT> &&src)
    : min(std::move(src.min)),
      max(std::move(src.max)) {
  }

  /**
   * Assignment operator
   * @param rhs source bounding-box
   * @return reference to this
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline aabb3<T> constexpr &operator=(aabb3<SrcT> const &rhs) {
    min = rhs.min;
    max = rhs.max;
    return *this;
  }

  /**
   * Copy assignment operator
   * @param rhs source bounding-box
   * @return reference to this
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline aabb3<T> constexpr &operator=(aabb3<SrcT> &&rhs) {
    min = std::move(rhs.min);
    max = std::move(rhs.max);
    return *this;
  }

  /**
   * Checks if bounding-box is valid. Valid bounding-box has non-negative size.
   * If an invalid bounding-box is extended by point or another bounding-box, the target
   * bounding box becomes valid and contains solely the source point or bounding-box respectively.
   * @return True if box is valid, otherwise false
   */
  inline bool constexpr valid() const __attribute__((__always_inline__)) {
    return min.x <= max.x && min.y <= max.y && min.z <= max.z;
  }

  /**
   * Makes this bounding-box invalid. So calling valid() gets false.
   * @see valid() method for more info on usage of invalid bounding-boxes.
   */
  inline void constexpr invalidate() __attribute__((__always_inline__)) {
    min = vector3<T>(1, 1, 1);
    max = vector3<T>(-1, -1, -1);
  }

  /**
   * Extends this bounding-box by a point @a point.
   * @param point A point to extend bounding-box by.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline void constexpr extend(vector3<SrcT> const &point) {
    if(!valid()) {
      min = max = point;
    } else {
      min = std::min(min, point);
      max = std::max(max, point);
    }
  }

  /**
   * Extends this bounding-box by a box @a box.
   * @param box A box to extend this bounding-box by.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline void constexpr extend(aabb3<SrcT> const &box) {
    if(!valid()) {
      min = box.min;
      max = box.max;
    } else {
      min = std::min(min, box.min);
      max = std::max(max, box.max);
    }
  }

  /**
   * Gets a copy of this bounding-box extend by a point @a point.
   * @param point A point to extend the box by
   * @return Copy of extended bounding-box
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3<T> extended(vector3<SrcT> const &point) const {
    aabb3<T> ret(*this);
    ret.extend(point);
    return ret;
  }

  /**
   * Gets a copy of this bounding-box extnended by box @a box.
   * @param box A box to extend the copy be.
   * @return Copy of extended bounding-box
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3<T> extended(aabb3<SrcT> const &box) const {
    aabb3<T> ret(*this);
    ret.extend(box);
    return *this;
  }

  /**
   * Tests if the point @a point is within this bounding-box
   * @param point A point to be tested
   * @return True if point @a point lies within bounding-box, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr intersects(vector3<SrcT> const &point) const {
    return min.x <= point.x && point.x <= max.x &&
           min.y <= point.y && point.y <= max.y &&
           min.z <= point.z && point.z <= max.z;
  }

  /**
   * Tests if other bounding-box @a box intersects (even partially) with this bounding-box.
   * @param box A box to be tested for intersection.
   * @return True if there's intersection between boxes, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr intersects(aabb3<SrcT> const &box) const {
    return max.x >= box.min.x && min.x <= box.max.x &&
           max.y >= box.min.y && min.y <= box.max.y &&
           max.z >= box.min.z && min.z <= box.max.z;
  }

  /**
   * Gets result of intersection of this bounding-box with @a other bounding-box.
   * In case the boxes don't intersect, the returned bounding-box is invalid.
   * @param other Box to be tested
   * @return Result of intersection.
   * @see valid() method for more information on invalid bounding-boxes.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb3<T> intersection(aabb3<SrcT> const &other) const {
    return (max.x < other.min.x || min.x > other.max.x ||
            max.y < other.min.y || min.y > other.max.y ||
            max.z < other.min.z || min.z > other.max.z) ? aabb3<T>() : aabb3<T>(std::max(min, other.min), std::min(max, other.max));
  }

  /**
   * Tests if a ray @b from origin @a intersects with this bounding-box.
   * @param ray The intersecting ray; does not need to be normalised
   * @param origin Origin of the intersecting ray
   * @return True if the ray intersects the box, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr ray_intersects(vector3<SrcT> const &ray, vector3<SrcT> const &origin = vector3<SrcT>()) const {
    // adapted from http://tavianator.com/2011/05/fast-branchless-raybounding-box-intersections/
    /*
    SrcT const dist_min_x = (min.x - origin.x) / ray.x;
    SrcT const dist_max_x = (max.x - origin.x) / ray.x;
    SrcT dist_min = std::min(dist_min_x, dist_max_x);
    SrcT dist_max = std::max(dist_min_x, dist_max_x);

    SrcT const dist_min_y = (min.y - origin.y) / ray.y;
    SrcT const dist_max_y = (max.y - origin.y) / ray.y;
    dist_min = std::max(dist_min, std::min(dist_min_y, dist_max_y));
    dist_max = std::min(dist_max, std::max(dist_min_y, dist_max_y));

    SrcT const dist_min_z = (min.z - origin.z) / ray.z;
    SrcT const dist_max_z = (max.z - origin.z) / ray.z;
    dist_min = std::max(dist_min, std::min(dist_min_z, dist_max_z));
    dist_max = std::min(dist_max, std::max(dist_min_z, dist_max_z));

    return dist_max >= std::max(dist_min, 0.0f);
    */
    // constexpr-compatible reformulation:
    return std::min(std::min(std::max((min.x - origin.x) / ray.x,
                                      (max.x - origin.x) / ray.x),
                             std::max((min.y - origin.y) / ray.y,
                                      (max.y - origin.y) / ray.y)),
                    std::max((min.z - origin.z) / ray.z,
                             (max.z - origin.z) / ray.z)) >=
           std::max(std::max(std::max(std::min((min.x - origin.x) / ray.x,
                                               (max.x - origin.x) / ray.x),
                                      std::min((min.y - origin.y) / ray.y,
                                               (max.y - origin.y) / ray.y)),
                             std::min((min.z - origin.z) / ray.z,
                                      (max.z - origin.z) / ray.z)), 0.0f);
  }

  /**
   * Gets center point of bounding-box.
   * @return A center point of bounding-box.
   */
  inline vector3<T> constexpr center() const __attribute__((__always_inline__)) {
    return (min + max) * static_cast<T>(0.5);
  }

  /**
   * Gets extent of bounding-box.
   * @return Extent of bounding-box.
   */
  inline vector3<T> constexpr extent() const __attribute__((__always_inline__)) {
    return (max - min) * static_cast<T>(0.5);
  }

  /**
   * Gets diagonal size of bounding-box
   * @return Sizes for particular dimensions.
   */
  inline vector3<T> constexpr size() const __attribute__((__always_inline__)) {
    return max - min;
  }

  /**
   * Gets all 8 corner-points of bounding box
   * @param i An index of bounding-box corner point. Valid values are 0 .. 7.
   * @return A position of @a i-th corner-point.
   * @note The order of points is as follows (where @c + denotes max-point and @c - min-point):
   * 1. (@c + @c + @c +)
   * 2. (@c - @c + @c +)
   * 3. (@c + @c - @c +)
   * 4. (@c - @c - @c +)
   * 5. (@c + @c + @c -)
   * 6. (@c - @c + @c -)
   * 7. (@c + @c - @c -)
   * 8. (@c - @c - @c -)
   *
   */
  inline vector3<T> constexpr point(unsigned int i) const __attribute__((__always_inline__)) {
    return vector3<T>(i & 1 ? min.x : max.x, i & 2 ? min.y : max.y, i & 4 ? min.z : max.z);
  }

  /**
   * Gets transformed bounding-box by transform @a t
   * @param t A transform matrix
   * @return Transformed bounding-box
   */
  inline aabb3<T> constexpr transformed(matrix4<T> const &t) const __attribute__((__always_inline__)) {
    aabb3<T> ret;
    for(unsigned int i = 0; i != 8; ++i) {
      const vector4<T> p(point(i), 1);
      ret.extend((t * p).xyz());
    }
    return ret;
  }

  //-------------------------------------------------------------------------------------------------------------
  // operators
  //-------------------------------------------------------------------------------------------------------------
  /**
   * Tests if @a rhs is equal to this bounding-box
   * @param rhs Right-hand side
   * @return True if @a rhs and this bounding-boxes are equal, otherwise false
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline bool constexpr operator==(aabb3<RhsT> const &rhs) const {
    return min == rhs.min && max == rhs.max;
  }

  /**
   * Tests if @a rhs is not equal to this bounding-box
   * @param rhs Right-hand side
   * @return True if @a rhs and this bounding-boxes are not equal, otherwise false
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline bool constexpr operator!=(aabb3<RhsT> const &rhs) const {
    return min != rhs.min || max != rhs.max;
  }

  /**
   * Gets transformed bounding-box by transform @a rhs.
   * @param rhs matrix 4x4 representing the transform
   * @return Transformed bounding-box
   */
  inline aabb3<T> constexpr operator*(matrix4<T> const &rhs) const __attribute__((__always_inline__)) {
    return transformed(rhs);
  }

  /**
   * Apply transform @a rhs to this bounding-box
   * @param rhs A transform to be applied
   * @return Reference to this
   */
  inline aabb3<T> constexpr &operator*=(matrix4<T> const &rhs) __attribute__((__always_inline__)) {
    *this = transformed(rhs);
    return *this;
  }

  /**
   * Extends this bounding-box by point @a rhs.
   * @param rhs A point to extend this bounding-box by
   * @return Reference to this
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline aabb3<T> constexpr &operator<<(vector3<SrcT> const &rhs) {
    extend(rhs);
    return *this;
  }

  /**
   * Extends this bounding-box by box @a rhs.
   * @param rhs A box to extend this bounding-box by
   * @return Reference to this
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline aabb3<T> constexpr &operator<<(aabb3<SrcT> const &rhs) {
    extend(rhs);
    return *this;
  }

  /**
   * Union of this and @a rhs bounding-boxes
   * @param rhs Right-hand side of union
   * @return A resulting bounding-box representing union
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline aabb3<T> constexpr operator|(aabb3<RhsT> const &rhs) const {
    return extended(rhs);
  }

  /**
   * Intersection of this and @a rhs bounding-boxed
   * @param rhs Right-hand side
   * @return Resulting bounding-box representing the intersection.
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline aabb3<T> constexpr operator&(aabb3<RhsT> const &rhs) const {
    return intersection(rhs);
  }

  /**
   * Outputs string representation of bounding-box @a rhs to output stream @a lhs
   * @param lhs Output stream to write to
   * @param rhs Bounding-box to write to output stream.
   * @return Reference to output stream @a lhs
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, const aabb3<T> &rhs) __attribute__((__always_inline__)) {
    lhs << rhs.min << " x " << rhs.max;
    return lhs;
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "aabb3_types.h"

#endif // VECTORSTORM_AABB3_H_INCLUDED
