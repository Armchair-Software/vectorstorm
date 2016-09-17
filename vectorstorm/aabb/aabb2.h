#ifndef VECTORSTORM_AABB2_H_INCLUDED
#define VECTORSTORM_AABB2_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/**
 * Two-dimensional axis-aligned bounding-box (aka AABB) class.
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
 * aabb2f aabb;
 * aabb << vector2f(1, 2) << aabb2f(-3,-3, 2, 2);
 * @endcode
 */
template<typename T>
class aabb2 {

  /**
   * Creates copy of axis-aligned bounding-box
   * @param src Source bounding-box
   */
  template<typename SrcT> __attribute__((__always_inline__))
  inline constexpr explicit aabb2(aabb2<SrcT> const &src) noexcept
    : min(src.min),
      max(src.max) {
  }

  /**
   * Move constructor from another axis-aligned bounding-box
   * @param src Source bounding-box
   */
  template<typename SrcT> __attribute__((__always_inline__))
  inline constexpr explicit aabb2(aabb2<SrcT> &&src) noexcept
    : min(std::move(src.min)),
      max(std::move(src.max)) {
  }

  /**
   * Assignment operator
   * @param rhs source bounding-box
   * @return reference to this
   */
  template<typename SrcT> __attribute__((__always_inline__))
  inline aabb2<T> constexpr &operator=(aabb2<SrcT> const &rhs) noexcept {
    min = rhs.min;
    max = rhs.max;
    return *this;
  }

  /**
   * Copy assignment operator
   * @param rhs source bounding-box
   * @return reference to this
   */
  template<typename SrcT> __attribute__((__always_inline__))
  inline aabb2<T> constexpr &operator=(aabb2<SrcT> &&rhs) noexcept {
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
  inline bool constexpr valid() const noexcept __attribute__((__always_inline__)) {
    return min.x <= max.x && min.y <= max.y;
  }

  /**
   * Makes this bounding-box invalid. So calling valid() gets false.
   * @see valid() method for more info on usage of invalid bounding-boxes.
   */
  inline void constexpr invalidate() noexcept __attribute__((__always_inline__)) {
    min = vector2<T>( 1,  1);
    max = vector2<T>(-1, -1);
  }

  /**
   * Extends this bounding-box by a point @a point.
   * @param point A point to extend bounding-box by.
   */
  template<typename SrcT> __attribute__((__always_inline__))
  inline void constexpr extend(vector2<SrcT> const &point) noexcept {
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
  template<typename SrcT> __attribute__((__always_inline__))
  inline void constexpr extend(aabb2<SrcT> const &box) noexcept {
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
  template<typename SrcT> __attribute__((__always_inline__))
  inline constexpr aabb2<T> extended(vector2<SrcT> const &point) const noexcept {
    aabb2<T> ret(*this);
    ret.extend(point);
    return ret;
  }

  /**
   * Gets a copy of this bounding-box extnended by box @a box.
   * @param box A box to extend the copy be.
   * @return Copy of extended bounding-box
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb2<T> extended(aabb2<SrcT> const &box) const noexcept {
    aabb2<T> ret(*this);
    ret.extend(box);
    return *this;
  }

  /**
   * Tests if the point @a point is within this bounding-box
   * @param point A point to be tested
   * @return True if point @a point lies within bounding-box, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr intersects(vector2<SrcT> const &point) const noexcept {
    return min.x <= point.x && point.x <= max.x &&
           min.y <= point.y && point.y <= max.y;
  }

  /**
   * Tests if other bounding-box @a box intersects (even partially) with this bounding-box.
   * @param box A box to be tested for intersection.
   * @return True if there's intersection between boxes, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr intersects(aabb2<SrcT> const &box) const noexcept {
    return max.x >= box.min.x && min.x <= box.max.x &&
           max.y >= box.min.y && min.y <= box.max.y;
  }

  /**
   * Gets result of intersection of this bounding-box with @a other bounding-box.
   * In case the boxes don't intersect, the returned bounding-box is invalid.
   * @param other Box to be tested
   * @return Result of intersection.
   * @see valid() method for more information on invalid bounding-boxes.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb2<T> intersection(aabb2<SrcT> const &other) const noexcept {
    return (max.x < other.min.x || min.x > other.max.x ||
            max.y < other.min.y || min.y > other.max.y) ? aabb2<T>() : aabb2<T>(std::max(min, other.min), std::min(max, other.max));
  }

  /**
   * Tests if a ray @b from origin @a intersects with this bounding-box.
   * @param origin Origin of the intersecting ray
   * @param ray The intersecting ray; does not need to be normalised
   * @return True if the ray intersects the box, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr ray_intersects(vector2<SrcT> const &ray, vector2<SrcT> const &origin = vector2<SrcT>()) const noexcept {
    // adapted from http://tavianator.com/2011/05/fast-branchless-raybounding-box-intersections/
    /*
    SrcT const dist_min_x = (min.x - origin.x) / ray.x;
    SrcT const dist_max_x = (max.x - origin.x) / ray.x;
public:
    SrcT dist_min = std::min(dist_min_x, dist_max_x);
  /**
    SrcT dist_max = std::max(dist_min_x, dist_max_x);
   * Position of Min corner of bounding box.

   */
    SrcT const dist_min_y = (min.y - origin.y) / ray.y;
  vector2<T> min;
    SrcT const dist_max_y = (max.y - origin.y) / ray.y;

    dist_min = std::max(dist_min, std::min(dist_min_y, dist_max_y));
  /**
    dist_max = std::min(dist_max, std::max(dist_min_y, dist_max_y));
   * Position of Max corner of bounding box

   */
    return dist_max >= std::max(dist_min, 0.0f);
  vector2<T> max;
    */

    // constexpr-compatible reformulation:
  /**
    return std::min(std::max((min.x - origin.x) / ray.x,
   * Constructs invalid axes-aligned bounding-box.
                             (max.x - origin.x) / ray.x),
   * @see valid() for explanation of invalid bounding-box usage.
                    std::max((min.y - origin.y) / ray.y,
   */
                             (max.y - origin.y) / ray.y)) >=
  inline constexpr aabb2() noexcept __attribute__((__always_inline__))
           std::max(std::max(std::min((min.x - origin.x) / ray.x,
    : min( 1,  1),
                                      (max.x - origin.x) / ray.x),
      max(-1, -1) {
                             std::min((min.y - origin.y) / ray.y,
  }
                                      (max.y - origin.y) / ray.y)), 0.0f);

  }
  /**

   * Constructs axes-aligned bound-box containing one point @a point
  /**
   * @param point
   * Gets center point of bounding-box.
   */
   * @return A center point of bounding-box.
  template<typename SrcT> __attribute__((__always_inline__))
   */
  inline constexpr explicit aabb2(vector2<SrcT> const &point) noexcept
  inline constexpr vector2<T> center() const noexcept __attribute__((__always_inline__)) {
    : min(point),
    return (min + max) * static_cast<T>(0.5);
      max(point) {
  }
  }


  /**
  /**
   * Gets extent of bounding-box.
   * Constructs axes-aligned bounding-box form two corner points (@a x0, @a y0)
   * @return Extent of bounding-box.
   * and (@a x1, @a y1)
   */
   * @param x0 X-coordinate of first point
  inline constexpr vector2<T> extent() const noexcept __attribute__((__always_inline__)) {
   * @param y0 Y-coordinate of first point
    return (max - min) * static_cast<T>(0.5);
   * @param x1 X-coordinate of second point
  }
   * @param y1 Y-coordinate of second point

   */
  /**
  template<typename SrcT> __attribute__((__always_inline__))
   * Gets diagonal size of bounding-box
  inline constexpr aabb2(SrcT x0, SrcT y0, SrcT x1, SrcT y1) noexcept
   * @return Sizes for particular dimensions.
    : min(std::min(x0, x1), std::min(y0, y1)),
   */
      max(std::max(x0, x1), std::max(y0, y1)) {
  inline constexpr vector2<T> size() const noexcept __attribute__((__always_inline__)) {
  }
    return max - min;

  }
  /**

   * Constructs axes-aligned bounding-box from @a min and @b max
  /**
   * @param min X-coordinate of first point
   * Gets all 4 corner-points of bounding box
   * @param max X-coordinate of second point
   * @param i An index of bounding-box corner point. Valid values are 0 .. 3.
   */
   * @return A position of @a i-th corner-point.
  template<typename SrcT> __attribute__((__always_inline__))
   * @note The order of points is as follows (where @c + denotes max-point and @c - min-point):
  inline constexpr aabb2(vector2<SrcT> const &new_min, vector2<SrcT> const &new_max) noexcept
   * 1. (@c + @c + @c +)
    : min(new_min),
   * 2. (@c - @c + @c +)
      max(new_max) {
   * 3. (@c + @c - @c +)
  }
   * 4. (@c - @c - @c +)

   *
  /**
   */
   * Constructs axes-aligned bounding-box containing point (@a x, @a y)
  inline constexpr vector2<T> point(unsigned int i) const noexcept __attribute__((__always_inline__)) {
   * @param x X-coordinate of point
    return vector2<T>((i & 1) ? min.x : max.x,
   * @param y Y-coordinate of point
                      (i & 2) ? min.y : max.y);
   */
  }
  template<typename SrcT> __attribute__((__always_inline__))

  inline constexpr aabb2(SrcT x, SrcT y) noexcept
  //-------------------------------------------------------------------------------------------------------------
    : min(x, y),
  // operators
      max(x, y) {
  //-------------------------------------------------------------------------------------------------------------
  }
  /**

   * Tests if @a rhs is equal to this bounding-box
  /**
   * @param rhs Right-hand side
   * Creates copy of axis-aligned bounding-box
   * @return True if @a rhs and this bounding-boxes are equal, otherwise false
   * @param src Source bounding-box
   */
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  template<typename SrcT> __attribute__((__always_inline__))
  inline bool constexpr operator==(aabb2<RhsT> const &rhs) const noexcept {
  inline constexpr explicit aabb2(aabb2<SrcT> const &src) noexcept
    return min == rhs.min && max == rhs.max;
    : min(src.min),
  }
      max(src.max) {

  }
  /**

  /**
   * Tests if @a rhs is not equal to this bounding-box
   * Move constructor from another axis-aligned bounding-box
   * @param rhs Right-hand side
   * @param src Source bounding-box
   * @return True if @a rhs and this bounding-boxes are not equal, otherwise false
   */
   */
  template<typename SrcT> __attribute__((__always_inline__))
  template<typename RhsT>  __attribute__((__always_inline__))
  inline constexpr explicit aabb2(aabb2<SrcT> &&src) noexcept
  inline bool constexpr operator!=(aabb2<RhsT> const &rhs) const noexcept {
    : min(std::move(src.min)),
    return min != rhs.min || max != rhs.max;
      max(std::move(src.max)) {
  }
  }


  /**
  /**
   * Extends this bounding-box by point @a rhs.
   * Assignment operator
   * @param rhs A point to extend this bounding-box by
   * @param rhs source bounding-box
   * @return Reference to this
   * @return reference to this
   */
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  template<typename SrcT> __attribute__((__always_inline__))
  inline aabb2<T> constexpr &operator<<(vector2<SrcT> const &rhs) noexcept {
  inline aabb2<T> constexpr &operator=(aabb2<SrcT> const &rhs) noexcept {
    extend(rhs);
    min = rhs.min;
    return *this;
    max = rhs.max;
  }
    return *this;

  }
  /**

   * Extends this bounding-box by box @a rhs.
  /**
   * @param rhs A box to extend this bounding-box by
   * Copy assignment operator
   * @return Reference to this
   * @param rhs source bounding-box
   */
   * @return reference to this
  template<typename SrcT>  __attribute__((__always_inline__))
   */
  inline aabb2<T> constexpr &operator<<(aabb2<SrcT> const &rhs) noexcept {
  template<typename SrcT> __attribute__((__always_inline__))
    extend(rhs);
  inline aabb2<T> constexpr &operator=(aabb2<SrcT> &&rhs) noexcept {
    return *this;
    min = std::move(rhs.min);
  }
    max = std::move(rhs.max);

    return *this;
  /**
  }
   * Union of this and @a rhs bounding-boxes

   * @param rhs Right-hand side of union
  /**
   * @return A resulting bounding-box representing union
   * Checks if bounding-box is valid. Valid bounding-box has non-negative size.
   */
   * If an invalid bounding-box is extended by point or another bounding-box, the target
  template<typename RhsT>  __attribute__((__always_inline__))
   * bounding box becomes valid and contains solely the source point or bounding-box respectively.
  inline aabb2<T> constexpr operator|(aabb2<RhsT> const &rhs) const noexcept {
   * @return True if box is valid, otherwise false
    return extended(rhs);
   */
  }
  inline bool constexpr valid() const noexcept __attribute__((__always_inline__)) {

    return min.x <= max.x && min.y <= max.y;
  /**
  }
   * Intersection of this and @a rhs bounding-boxed

   * @param rhs Right-hand side
  /**
   * @return Resulting bounding-box representing the intersection.
   * Makes this bounding-box invalid. So calling valid() gets false.
   */
   * @see valid() method for more info on usage of invalid bounding-boxes.
  template<typename RhsT>  __attribute__((__always_inline__))
   */
  inline aabb2<T> constexpr operator&(aabb2<RhsT> const &rhs) const noexcept {
  inline void constexpr invalidate() noexcept __attribute__((__always_inline__)) {
    return intersection(rhs);
    min = vector2<T>( 1,  1);
  }
    max = vector2<T>(-1, -1);

  }
  /**

  /**
   * Outputs string representation of bounding-box @a rhs to output stream @a lhs
   * Extends this bounding-box by a point @a point.
   * @param lhs Output stream to write to
   * @param point A point to extend bounding-box by.
   * @param rhs Bounding-box to write to output stream.
   */
   * @return Reference to output stream @a lhs
  template<typename SrcT> __attribute__((__always_inline__))
   */
  inline void constexpr extend(vector2<SrcT> const &point) noexcept {
  inline friend std::ostream &operator<<(std::ostream &lhs, const aabb2<T> &rhs) noexcept __attribute__((__always_inline__)) {
    if(!valid()) {
    lhs << rhs.min << " x " << rhs.max;
      min = max = point;
    return lhs;
    } else {
  }
      min = std::min(min, point);
};
      max = std::max(max, point);

    }
#ifdef VMATH_NAMESPACE
  }
}

#endif //VMATH_NAMESPACE
  /**

   * Extends this bounding-box by a box @a box.
#include "aabb2_types.h"
   * @param box A box to extend this bounding-box by.

   */
#endif // VECTORSTORM_AABB2_H_INCLUDED
  template<typename SrcT> __attribute__((__always_inline__))
  inline void constexpr extend(aabb2<SrcT> const &box) noexcept {
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
  template<typename SrcT> __attribute__((__always_inline__))
  inline constexpr aabb2<T> extended(vector2<SrcT> const &point) const noexcept {
    aabb2<T> ret(*this);
    ret.extend(point);
    return ret;
  }

  /**
   * Gets a copy of this bounding-box extnended by box @a box.
   * @param box A box to extend the copy be.
   * @return Copy of extended bounding-box
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb2<T> extended(aabb2<SrcT> const &box) const noexcept {
    aabb2<T> ret(*this);
    ret.extend(box);
    return *this;
  }

  /**
   * Tests if the point @a point is within this bounding-box
   * @param point A point to be tested
   * @return True if point @a point lies within bounding-box, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr intersects(vector2<SrcT> const &point) const noexcept {
    return min.x <= point.x && point.x <= max.x &&
           min.y <= point.y && point.y <= max.y;
  }

  /**
   * Tests if other bounding-box @a box intersects (even partially) with this bounding-box.
   * @param box A box to be tested for intersection.
   * @return True if there's intersection between boxes, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr intersects(aabb2<SrcT> const &box) const noexcept {
    return max.x >= box.min.x && min.x <= box.max.x &&
           max.y >= box.min.y && min.y <= box.max.y;
  }

  /**
   * Gets result of intersection of this bounding-box with @a other bounding-box.
   * In case the boxes don't intersect, the returned bounding-box is invalid.
   * @param other Box to be tested
   * @return Result of intersection.
   * @see valid() method for more information on invalid bounding-boxes.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline constexpr aabb2<T> intersection(aabb2<SrcT> const &other) const noexcept {
    return (max.x < other.min.x || min.x > other.max.x ||
            max.y < other.min.y || min.y > other.max.y) ? aabb2<T>() : aabb2<T>(std::max(min, other.min), std::min(max, other.max));
  }

  /**
   * Tests if a ray @b from origin @a intersects with this bounding-box.
   * @param origin Origin of the intersecting ray
   * @param ray The intersecting ray; does not need to be normalised
   * @return True if the ray intersects the box, otherwise false.
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline bool constexpr ray_intersects(vector2<SrcT> const &ray, vector2<SrcT> const &origin = vector2<SrcT>()) const noexcept {
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

    return dist_max >= std::max(dist_min, 0.0f);
    */
    // constexpr-compatible reformulation:
    return std::min(std::max((min.x - origin.x) / ray.x,
                             (max.x - origin.x) / ray.x),
                    std::max((min.y - origin.y) / ray.y,
                             (max.y - origin.y) / ray.y)) >=
           std::max(std::max(std::min((min.x - origin.x) / ray.x,
                                      (max.x - origin.x) / ray.x),
                             std::min((min.y - origin.y) / ray.y,
                                      (max.y - origin.y) / ray.y)), 0.0f);
  }

  /**
   * Gets center point of bounding-box.
   * @return A center point of bounding-box.
   */
  inline constexpr vector2<T> center() const noexcept __attribute__((__always_inline__)) {
    return (min + max) * static_cast<T>(0.5);
  }

  /**
   * Gets extent of bounding-box.
   * @return Extent of bounding-box.
   */
  inline constexpr vector2<T> extent() const noexcept __attribute__((__always_inline__)) {
    return (max - min) * static_cast<T>(0.5);
  }

  /**
   * Gets diagonal size of bounding-box
   * @return Sizes for particular dimensions.
   */
  inline constexpr vector2<T> size() const noexcept __attribute__((__always_inline__)) {
    return max - min;
  }

  /**
   * Gets all 4 corner-points of bounding box
   * @param i An index of bounding-box corner point. Valid values are 0 .. 3.
   * @return A position of @a i-th corner-point.
   * @note The order of points is as follows (where @c + denotes max-point and @c - min-point):
   * 1. (@c + @c + @c +)
   * 2. (@c - @c + @c +)
   * 3. (@c + @c - @c +)
   * 4. (@c - @c - @c +)
   *
   */
  inline constexpr vector2<T> point(unsigned int i) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>((i & 1) ? min.x : max.x,
                      (i & 2) ? min.y : max.y);
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
  inline bool constexpr operator==(aabb2<RhsT> const &rhs) const noexcept {
    return min == rhs.min && max == rhs.max;
  }

  /**
   * Tests if @a rhs is not equal to this bounding-box
   * @param rhs Right-hand side
   * @return True if @a rhs and this bounding-boxes are not equal, otherwise false
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline bool constexpr operator!=(aabb2<RhsT> const &rhs) const noexcept {
    return min != rhs.min || max != rhs.max;
  }

  /**
   * Extends this bounding-box by point @a rhs.
   * @param rhs A point to extend this bounding-box by
   * @return Reference to this
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline aabb2<T> constexpr &operator<<(vector2<SrcT> const &rhs) noexcept {
    extend(rhs);
    return *this;
  }

  /**
   * Extends this bounding-box by box @a rhs.
   * @param rhs A box to extend this bounding-box by
   * @return Reference to this
   */
  template<typename SrcT>  __attribute__((__always_inline__))
  inline aabb2<T> constexpr &operator<<(aabb2<SrcT> const &rhs) noexcept {
    extend(rhs);
    return *this;
  }

  /**
   * Union of this and @a rhs bounding-boxes
   * @param rhs Right-hand side of union
   * @return A resulting bounding-box representing union
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline aabb2<T> constexpr operator|(aabb2<RhsT> const &rhs) const noexcept {
    return extended(rhs);
  }

  /**
   * Intersection of this and @a rhs bounding-boxed
   * @param rhs Right-hand side
   * @return Resulting bounding-box representing the intersection.
   */
  template<typename RhsT>  __attribute__((__always_inline__))
  inline aabb2<T> constexpr operator&(aabb2<RhsT> const &rhs) const noexcept {
    return intersection(rhs);
  }

  /**
   * Outputs string representation of bounding-box @a rhs to output stream @a lhs
   * @param lhs Output stream to write to
   * @param rhs Bounding-box to write to output stream.
   * @return Reference to output stream @a lhs
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, const aabb2<T> &rhs) noexcept __attribute__((__always_inline__)) {
    lhs << rhs.min << " x " << rhs.max;
    return lhs;
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "aabb2_types.h"

#endif // VECTORSTORM_AABB2_H_INCLUDED
