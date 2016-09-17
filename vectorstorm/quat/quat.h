#ifndef VECTORSTORM_QUAT_H_INCLUDED
#define VECTORSTORM_QUAT_H_INCLUDED

#include "vectorstorm/epsilon.h"
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
#include "vectorstorm/vector/vector3.h"
#include "vectorstorm/matrix/matrix3_forward.h"
#include "vectorstorm/matrix/matrix4_forward.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/**
#ifndef VECTORSTORM_QUAT_H_INCLUDED
 * quaternion class implementing some quaternion algebra operations.
#define VECTORSTORM_QUAT_H_INCLUDED
 * quaternion is kind of complex number it consists of its real part (w)

 * and its complex part v. This complex part has three elements, so we
#include "vectorstorm/epsilon.h"
 * can express it as xi + yj + zk . Note that coordinates of (x,y,z) are
#include "vectorstorm/sincos.h"
 * hold inside v field.
#include "vectorstorm/deg2rad.h"
 */
#include "vectorstorm/vector/vector3.h"
template<typename T>
#include "vectorstorm/matrix/matrix3_forward.h"
class quaternion {
#include "vectorstorm/matrix/matrix4_forward.h"
public:

  union {
#ifdef VMATH_NAMESPACE
    /**
namespace VMATH_NAMESPACE {
     * Real part of quaternion.
#endif
     */

    T w;
/**
    T real;
 * quaternion class implementing some quaternion algebra operations.
    T scalar;
 * quaternion is kind of complex number it consists of its real part (w)
  };
 * and its complex part v. This complex part has three elements, so we

 * can express it as xi + yj + zk . Note that coordinates of (x,y,z) are
  union {
 * hold inside v field.
    /**
 */
     * Imaginary part of quaternion.
template<typename T>
     */
class quaternion {
    vector3<T> v;
public:
    vector3<T> imaginary;
  union {
    vector3<T> vector;
    /**
  };
     * Real part of quaternion.

     */
  /**
    T w;
   * quaternion constructor, sets quaternion to (0 + 0i + 0j + 0k).
    T real;
   */
    T scalar;
  inline constexpr quaternion() noexcept __attribute__((__always_inline__))
  };
    : w(0),

      v(0, 0, 0) {
  union {
  }
    /**

     * Imaginary part of quaternion.
  /**
     */
   * Copy constructor.
    vector3<T> v;
   */
    vector3<T> imaginary;
  inline constexpr explicit quaternion(quaternion<T> const &q) noexcept __attribute__((__always_inline__))
    vector3<T> vector;
    : w(q.w),
  };
      v(q.v) {

  }
  /**

   * quaternion constructor, sets quaternion to (0 + 0i + 0j + 0k).
  /**
   */
   * Copy casting constructor.
  inline constexpr quaternion() noexcept __attribute__((__always_inline__))
   */
    : w(0),
  template<typename FromT>  __attribute__((__always_inline__))
      v(0, 0, 0) {
  inline constexpr explicit quaternion(quaternion<FromT> const &q) noexcept
  }
    : w(static_cast<T>(q.w)),

      v(q.v) {
  /**
  }
   * Copy constructor.

   */
  /**
  inline constexpr explicit quaternion(quaternion<T> const &q) noexcept __attribute__((__always_inline__))
   * Move constructor.
    : w(q.w),
   */
      v(q.v) {
  inline constexpr quaternion(quaternion<T> &&q) noexcept __attribute__((__always_inline__))
  }
    : w(std::move(q.w)),

      v(std::move(q.v)) {
  /**
  }
   * Copy casting constructor.

   */
  /**
  template<typename FromT>  __attribute__((__always_inline__))
   * Move casting constructor.
   */
  inline constexpr explicit quaternion(quaternion<FromT> const &q) noexcept
  template<typename FromT>  __attribute__((__always_inline__))
    : w(static_cast<T>(q.w)),
  inline constexpr quaternion(quaternion<FromT> &&q) noexcept
      v(q.v) {
    : w(static_cast<T>(std::move(q.w))),
  }
      v(std::move(q.v)) {

  }
  /**

   * Move constructor.
  /**
   */
   * Creates quaternion object from real part w_ and complex part v_.
  inline constexpr quaternion(quaternion<T> &&q) noexcept __attribute__((__always_inline__))
   * @param w_ Real part of quaternion.
    : w(std::move(q.w)),
   * @param v_ Complex part of quaternion (xi + yj + zk).
      v(std::move(q.v)) {
   */
  }
  inline constexpr quaternion(T w_, vector3<T> const &v_) noexcept __attribute__((__always_inline__))

    : w(w_),
  /**
      v(v_) {
   * Move casting constructor.
  }
   */

  template<typename FromT>  __attribute__((__always_inline__))
  /**
  inline constexpr quaternion(quaternion<FromT> &&q) noexcept
   * Creates quaternion object from value (w_ + xi + yj + zk).
    : w(static_cast<T>(std::move(q.w))),
   * @param w_ Real part of quaternion.
      v(std::move(q.v)) {
   * @param x Complex coefficient for i complex constant.
  }
   * @param y Complex coefficient for j complex constant.

   * @param z Complex coefficient for k complex constant.
  /**
   */
   * Creates quaternion object from real part w_ and complex part v_.
  inline constexpr quaternion(T w_, T x, T y, T z) noexcept __attribute__((__always_inline__))
   * @param w_ Real part of quaternion.
    : w(w_), v(x, y, z) {
   * @param v_ Complex part of quaternion (xi + yj + zk).
  }
   */

  inline constexpr quaternion(T w_, vector3<T> const &v_) noexcept __attribute__((__always_inline__))
  /**
    : w(w_),
   * Construct quaternion from rotation matrix.
      v(v_) {
   * @return Rotation matrix expressing this quaternion.
  }
   */

  inline constexpr explicit quaternion(matrix3<T> const &matrix) noexcept __attribute__((__always_inline__)) {
  /**
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
   * Creates quaternion object from value (w_ + xi + yj + zk).
    // article "quaternion Calculus and Fast Animation".
   * @param w_ Real part of quaternion.
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
   * @param x Complex coefficient for i complex constant.
    if(trace > 0) {
   * @param y Complex coefficient for j complex constant.
      // |w| > 1/2, may as well choose w > 1/2
   * @param z Complex coefficient for k complex constant.
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
   */
      w = static_cast<T>(0.5) * root;
  inline constexpr quaternion(T w_, T x, T y, T z) noexcept __attribute__((__always_inline__))
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
    : w(w_), v(x, y, z) {
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;
  }
      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;

      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
  /**
    } else {
   * Construct quaternion from rotation matrix.
      // |w| <= 1/2
   * @return Rotation matrix expressing this quaternion.
      unsigned int constexpr next[3] = {1, 2, 0};
   */

  inline constexpr explicit quaternion(matrix3<T> const &matrix) noexcept __attribute__((__always_inline__)) {
      unsigned int i = 0;
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
    // article "quaternion Calculus and Fast Animation".
        i = 1;
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
      }
    if(trace > 0) {
      if(matrix.at(2, 2) > matrix.at(i, i)) {
      // |w| > 1/2, may as well choose w > 1/2
        i = 2;
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
      }
      w = static_cast<T>(0.5) * root;
      unsigned int j = next[i];
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
      unsigned int k = next[j];
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;

      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
      T *q[3] = {&v.x, &v.y, &v.z};
    } else {
      *q[i] = static_cast<T>(0.5) * root;
      // |w| <= 1/2
      root = static_cast<T>(0.5) / root;
      unsigned int constexpr next[3] = {1, 2, 0};
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;

      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
      unsigned int i = 0;
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
    }
        i = 1;
  }
      }
  inline constexpr explicit quaternion(matrix4<T> const &matrix) noexcept __attribute__((__always_inline__)) {
      if(matrix.at(2, 2) > matrix.at(i, i)) {
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
        i = 2;
    // article "quaternion Calculus and Fast Animation".
      }
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
      unsigned int j = next[i];
    if(trace > 0) {
      unsigned int k = next[j];
      // |w| > 1/2, may as well choose w > 1/2

      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
      w = static_cast<T>(0.5) * root;
      T *q[3] = {&v.x, &v.y, &v.z};
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
      *q[i] = static_cast<T>(0.5) * root;
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;
      root = static_cast<T>(0.5) / root;
      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
    } else {
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
      // |w| <= 1/2
    }
      unsigned int constexpr next[3] = {1, 2, 0};
  }

  inline constexpr explicit quaternion(matrix4<T> const &matrix) noexcept __attribute__((__always_inline__)) {
      unsigned int i = 0;
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
    // article "quaternion Calculus and Fast Animation".
        i = 1;
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
      }
    if(trace > 0) {
      if(matrix.at(2, 2) > matrix.at(i, i)) {
      // |w| > 1/2, may as well choose w > 1/2
        i = 2;
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
      }
      w = static_cast<T>(0.5) * root;
      unsigned int j = next[i];
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
      unsigned int k = next[j];
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;

      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
      T *q[3] = {&v.x, &v.y, &v.z};
    } else {
      *q[i] = static_cast<T>(0.5) * root;
      // |w| <= 1/2
      root = static_cast<T>(0.5) / root;
      unsigned int constexpr next[3] = {1, 2, 0};
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;

      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
      unsigned int i = 0;
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
    }
        i = 1;
  }
      }

      if(matrix.at(2, 2) > matrix.at(i, i)) {
  //----------------[ assignment ]-------------------------
        i = 2;
  /**
      }
   * Sets to (w_ + xi + yj + zk).
      unsigned int j = next[i];
   * @param w_ Real part of quaternion.
      unsigned int k = next[j];
   * @param x Complex coefficient for i complex constant.

   * @param y Complex coefficient for j complex constant.
      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
   * @param z Complex coefficient for k complex constant.
      T *q[3] = {&v.x, &v.y, &v.z};
   */
      *q[i] = static_cast<T>(0.5) * root;
  inline void constexpr assign(T w_ = 0, T x = 0, T y = 0, T z = 0) noexcept __attribute__((__always_inline__)) {
      root = static_cast<T>(0.5) / root;
    w = w_;
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;
    v.assign(x, y, z);
  }
      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;

      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
  /**
    }
   * Copy operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //----------------[ assignment ]-------------------------
  inline quaternion<T> constexpr &operator=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    v = rhs.v;
   * Sets to (w_ + xi + yj + zk).
    w = rhs.w;
   * @param w_ Real part of quaternion.
    return *this;
   * @param x Complex coefficient for i complex constant.
  }
   * @param y Complex coefficient for j complex constant.

   * @param z Complex coefficient for k complex constant.
  /**
   */
   * Copy convert operator
  inline void constexpr assign(T w_ = 0, T x = 0, T y = 0, T z = 0) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    w = w_;
   */
    v.assign(x, y, z);
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline quaternion<T> constexpr &operator=(quaternion<FromT> const &rhs) noexcept {

    v = rhs.v;
  /**
    w = static_cast<T>(rhs.w);
   * Copy operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline quaternion<T> constexpr &operator=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    v = rhs.v;
   * Move assignment operator
    w = rhs.w;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }
  inline quaternion<T> constexpr &operator=(quaternion<T> &&rhs) noexcept __attribute__((__always_inline__)) {

    v = std::move(rhs.v);
  /**
    w = std::move(rhs.w);
   * Copy convert operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline quaternion<T> constexpr &operator=(quaternion<FromT> const &rhs) noexcept {
   * Move assignment convert operator
    v = rhs.v;
   * @param rhs Right hand side argument of binary operator.
    w = static_cast<T>(rhs.w);
   */
    return *this;
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline quaternion<T> constexpr &operator=(quaternion<FromT> &&rhs) noexcept {

    v = std::move(rhs.v);
  /**
    w = static_cast<T>(std::move(rhs.w));
   * Move assignment operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  /**
  inline quaternion<T> constexpr &operator=(quaternion<T> &&rhs) noexcept __attribute__((__always_inline__)) {
   * Addition operator
    v = std::move(rhs.v);
   * @param rhs Right hand side argument of binary operator.
    w = std::move(rhs.w);
   */
    return *this;
  inline quaternion<T> constexpr operator+(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return quaternion<T>(w + rhs.w, v + rhs.v);

  }
  /**

   * Move assignment convert operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  template<typename FromT> __attribute__((__always_inline__))
   */
  inline quaternion<T> constexpr &operator=(quaternion<FromT> &&rhs) noexcept {
  inline quaternion<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    v = std::move(rhs.v);
    return quaternion<T>(w * rhs.w   - v.x * rhs.v.x - v.y * rhs.v.y - v.z * rhs.v.z,
    w = static_cast<T>(std::move(rhs.w));
                         w * rhs.v.x + v.x * rhs.w   + v.y * rhs.v.z - v.z * rhs.v.y,
    return *this;
                         w * rhs.v.y - v.x * rhs.v.z + v.y * rhs.w   + v.z * rhs.v.x,
  }

                         w * rhs.v.z + v.x * rhs.v.y - v.y * rhs.v.x + v.z * rhs.w);
  /**
  }
   * Addition operator

  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline quaternion<T> constexpr operator+(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return quaternion<T>(w + rhs.w, v + rhs.v);
  inline quaternion<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return quaternion<T>(w * rhs, v * rhs);

  }
  /**

   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Division operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline quaternion<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return quaternion<T>(w * rhs.w   - v.x * rhs.v.x - v.y * rhs.v.y - v.z * rhs.v.z,
  inline quaternion<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
                         w * rhs.v.x + v.x * rhs.w   + v.y * rhs.v.z - v.z * rhs.v.y,
    return quaternion<T>(w / rhs, v / rhs);
                         w * rhs.v.y - v.x * rhs.v.z + v.y * rhs.w   + v.z * rhs.v.x,
  }
                         w * rhs.v.z + v.x * rhs.v.y - v.y * rhs.v.x + v.z * rhs.w);

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline quaternion<T> constexpr operator-(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return quaternion<T>(w - rhs.w, v - rhs.v);
  inline quaternion<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return quaternion<T>(w * rhs, v * rhs);

  }
  /**

   * Addition operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Division operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline quaternion<T> constexpr &operator+=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    w += rhs.w;
  inline quaternion<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    v += rhs.v;
    return quaternion<T>(w / rhs, v / rhs);
    return *this;
  }
  }


  /**
  /**
   * Subtraction operator
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline quaternion<T> constexpr operator-(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline quaternion<T> constexpr &operator-=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w - rhs.w, v - rhs.v);
    w -= rhs.w;
  }
    v -= rhs.v;

    return *this;
  /**
  }
   * Addition operator

  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline quaternion<T> constexpr &operator+=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    w += rhs.w;
  inline quaternion<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    v += rhs.v;
    quaternion q = (*this) * rhs;
    return *this;
    v = q.v;
  }
    w = q.w;

    return *this;
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Multiplication operator
  inline quaternion<T> constexpr &operator-=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    w -= rhs.w;
   */
    v -= rhs.v;
  inline quaternion<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    return *this;
    w *= rhs;
  }
    v *= rhs;

    return *this;
  /**
  }
   * Multiplication operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Division operator
  inline quaternion<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    quaternion q = (*this) * rhs;
   */
    v = q.v;
  inline quaternion<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    w = q.w;
    w /= rhs;
    return *this;
    v /= rhs;
  }
    return *this;

  }
  /**

   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Equality test operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline quaternion<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   * @note Test of equality is based of threshold epsilon value. To be two
    w *= rhs;
   * values equal, must satisfy this condition | lhs - rhs | < epsilon,
    v *= rhs;
   * for all quaternion coordinates.
    return *this;
   */
  }
  inline bool constexpr operator==(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    #ifdef VMATH_SOFT_COMPARE
  /**
      return (std::abs(w - rhs.w) < static_cast<T>(epsilon)) && v == rhs.v;
   * Division operator
    #else
   * @param rhs Right hand side argument of binary operator.
      return w == rhs.w && v == rhs.v;
   */
    #endif // VMATH_SOFT_COMPARE
  inline quaternion<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
  }
    w /= rhs;

    v /= rhs;
  /**
    return *this;
   * Inequality test operator
  }
   * @param rhs Right hand side argument of binary operator.

   * @return not (lhs == rhs) :-P
  /**
   */
   * Equality test operator
  inline bool constexpr operator!=(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return !(*this == rhs);
   * @note Test of equality is based of threshold epsilon value. To be two
  }
   * values equal, must satisfy this condition | lhs - rhs | < epsilon,

   * for all quaternion coordinates.
  //-------------[ unary operations ]--------------------------
   */
  /**
  inline bool constexpr operator==(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Unary negate operator
    #ifdef VMATH_SOFT_COMPARE
   * @return negated quaternion
      return (std::abs(w - rhs.w) < static_cast<T>(epsilon)) && v == rhs.v;
   */
    #else
  inline quaternion<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
      return w == rhs.w && v == rhs.v;
    return quaternion<T>(-w, -v);
    #endif // VMATH_SOFT_COMPARE
  }
  }


  /**
  /**
   * Unary conjugate operator
   * Inequality test operator
   * @return conjugated quaternion
   * @param rhs Right hand side argument of binary operator.
   */
   * @return not (lhs == rhs) :-P
  inline quaternion<T> constexpr operator~() const noexcept __attribute__((__always_inline__)) {
   */
    return quaternion<T>(w, -v);
  inline bool constexpr operator!=(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return !(*this == rhs);

  }
  /**

   * Get length of quaternion.
  //-------------[ unary operations ]--------------------------
   * @return Length of quaternion.
  /**
   */
   * Unary negate operator
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
   * @return negated quaternion
    return static_cast<T>(std::sqrt(length_sq()));
   */
  }
  inline quaternion<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
  /**
    return quaternion<T>(-w, -v);
   * Get length of quaternion, fast approximation.
  }
   * @return Length of quaternion.

   */
  /**
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) {
   * Unary conjugate operator
    return static_cast<T>(sqrt_fast(length_sq()));
   * @return conjugated quaternion
  }
   */
  /**
  inline quaternion<T> constexpr operator~() const noexcept __attribute__((__always_inline__)) {
   * Get length of quaternion, rougher fast approximation.
    return quaternion<T>(w, -v);
   * @return Length of quaternion.
  }
   */

  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) {
  /**
    return static_cast<T>(sqrt_faster(length_sq()));
   * Get length of quaternion.
  }
   * @return Length of quaternion.

   */
  /**
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
   * Return square of length.
    return static_cast<T>(std::sqrt(length_sq()));
   * @return length ^ 2
  }
   * @note This method is faster then length(). For comparison
  /**
   * of length of two quaternion can be used just this value, instead
   * Get length of quaternion, fast approximation.
   * of more expensive length() method.
   * @return Length of quaternion.
   */
   */
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) {
    return w * w + v.length_sq();
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  }
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
  /**
    return length_sq();
   * Get length of quaternion, rougher fast approximation.
  }
   * @return Length of quaternion.

   */
  /**
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) {
   * normalise quaternion
    return static_cast<T>(sqrt_faster(length_sq()));
   */
  }
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {

    T len = length();
  /**
    w /= len;
   * Return square of length.
    v /= len;
   * @return length ^ 2
  }
   * @note This method is faster then length(). For comparison
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
   * of length of two quaternion can be used just this value, instead
    T len = length_fast();
   * of more expensive length() method.
    w /= len;
   */
    v /= len;
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
  }
    return w * w + v.length_sq();
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
  }
    T len = length_faster();
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
    w /= len;
    return length_sq();
    v /= len;
  }
  }

  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  /**
    normalise();
   * normalise quaternion
  }
   */
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_fast();
  }
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_faster();
  }
  inline quaternion<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    T const temp(length());
    return quaternion<T>(w / temp, v / temp);
  }
  inline quaternion<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return quaternion<T>(w / temp, v / temp);
  }
  inline quaternion<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return quaternion<T>(w / temp, v / temp);
  }
  inline quaternion<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline quaternion<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline quaternion<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_faster();
  }

  inline void constexpr conjugate() noexcept __attribute__((__always_inline__)) {
    v = -v;
  }

  inline quaternion<T> constexpr conjugate_copy() const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w, -v);
  }

  /**
   * @brief Computes the inverse of this quaternion.
   *
   * @note This is a general inverse.  If you know a priori
   * that you're using a unit quaternion (i.e., norm() == 1),
   * it will be significantly faster to use conjugate() instead.
   *
   * @return The quaternion q such that q * (*this) == (*this) * q
   * == [ 0 0 0 1 ]<sup>T</sup>.
   */
  inline void constexpr invert() noexcept __attribute__((__always_inline__)) {
    T l = length();
    conjugate();
    (*this) /= l;
  }

  inline quaternion<T> constexpr invert_copy() const noexcept __attribute__((__always_inline__)) {
    return conjugate_copy() / length();
  }

  /**
   * Creates quaternion for Euler angles.
   * @param x Rotation around x axis (in degrees).
   * @param y Rotation around y axis (in degrees).
   * @param z Rotation around z axis (in degrees).
   * @return quaternion object representing transformation.
   */
  inline static quaternion<T> constexpr from_euler_angles(T x, T y, T z) noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(from_axis_rot(vector3<T>(1, 0, 0), x) *
                         from_axis_rot(vector3<T>(0, 1, 0), y) *
                         from_axis_rot(vector3<T>(0, 0, 1), z));
  }
  inline static quaternion<T> constexpr fromEulerAngles(T x, T y, T z) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles()"))) {
    return from_euler_angles(x, y, z);
  }

  /**
   * Creates quaternion for Euler angles, rad version.
   * @param x Rotation around x axis (in radians).
   * @param y Rotation around y axis (in radians).
   * @param z Rotation around z axis (in radians).
   * @return quaternion object representing transformation.
   */
  inline static quaternion<T> constexpr from_euler_angles_rad(T x, T y, T z) noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(from_axis_rot_rad(vector3<T>(1, 0, 0), x) *
                         from_axis_rot_rad(vector3<T>(0, 1, 0), y) *
                         from_axis_rot_rad(vector3<T>(0, 0, 1), z));
  }
  inline static quaternion<T> constexpr fromEulerAngles_rad(T x, T y, T z) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles_rad()"))) {
    return from_euler_angles_rad(x, y, z);
  }

  /**
   * Creates quaternion as rotation around axis.
   * @param axis Unit vector expressing axis of rotation.
   * @param angleDeg Angle of rotation around axis (in degrees).
   */
  inline static quaternion<T> constexpr from_axis_rot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) {
    return from_axis_rot_rad(axis, deg2rad(angleDeg));
  }
  inline static quaternion<T> constexpr fromAxisRot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot()"))) {
    return from_axis_rot(axis, angleDeg);
  }

  /**
   * Creates quaternion as rotation around axis, rad version.
   * @param axis Unit vector expressing axis of rotation.
   * @param angleDeg Angle of rotation around axis (in radians).
   */
  inline static quaternion<T> constexpr from_axis_rot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) {
    T temp_sin = static_cast<T>(0);
    T temp_cos = static_cast<T>(0);
    sincos_any(angleRad / static_cast<T>(2.0), temp_sin, temp_cos);
    return quaternion<T>(temp_cos, axis * temp_sin);
  }
  inline static quaternion<T> constexpr fromAxisRot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot_rad()"))) {
    return from_axis_rot_rad(axis, angleRad);
  }

  /**
   * Converts this quaternion to an axis and angle combination
   * @param angle The angle of rotation
   * @param axis The axis around which the rotation is
   */
  inline void constexpr to_angle_axis(T &angle, vector3<T> &axis) noexcept __attribute__((__always_inline__)) {
    T const squareLength = v.length_sq();
    if(squareLength != 0) {
      angle = static_cast<T>(2.0) * std::acos(w);
      axis = v / std::pow(squareLength, static_cast<T>(0.5));
    } else {
      angle = static_cast<T>(0.0);
      axis.assign(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
    }
  }
  inline void constexpr toAngleAxis(T &angle, vector3<T> &axis) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_angle_axis()"))) {
    to_angle_axis(angle, axis);
  }

  /**
   * Converts quaternion into rotation matrix.
   * @return Rotation matrix expressing this quaternion.
   */
  inline matrix3<T> constexpr rotmatrix() noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(1 - 2 * (v.y * v.y + v.z * v.z),     2 * (v.x * v.y + v.z * w),       2 * (v.x * v.z - v.y * w),
                          2 * (v.x * v.y - v.z * w),   1 - 2 * (v.x * v.x + v.z * v.z),     2 * (v.y * v.z + v.x * w),
                          2 * (v.x * v.z + v.y * w),       2 * (v.y * v.z - v.x * w),   1 - 2 * (v.x * v.x + v.y * v.y));
  }

  /**
   * Converts quaternion into transformation matrix.
   * @note This method performs same operation as rotmatrix()
   * conversion method. But returns matrix of 4x4 elements.
   * @return Transformation matrix expressing this quaternion.
   */
  inline matrix4<T> constexpr transform() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(1 - 2 * (v.y * v.y + v.z * v.z),     2 * (v.x * v.y + v.z * w),       2 * (v.x * v.z - v.y * w),   0.0f,
                          2 * (v.x * v.y - v.z * w),   1 - 2 * (v.x * v.x + v.z * v.z),     2 * (v.y * v.z + v.x * w),   0.0f,
                          2 * (v.x * v.z + v.y * w),       2 * (v.y * v.z - v.x * w),   1 - 2 * (v.x * v.x + v.y * v.y), 0.0f,
                      0.0f,                            0.0f,                            0.0f,                            1.0f);
  }

  /**
   * Linear interpolation of two quaternions
   * @param fact Factor of interpolation. For translation from position
   * of this vector to quaternion rhs, values of factor goes from 0.0 to 1.0.
   * @param rhs Second quaternion for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  inline quaternion<T> constexpr lerp(T fact, quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
    return quaternion<T>((1 - fact) * w + fact * rhs.w, v.lerp(fact, rhs.v));
    T len = length();
  }
    w /= len;

    v /= len;
  /**
  }
   * Provides output to standard output stream.
   */
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    T len = length_fast();
  inline friend std::ostream &operator <<(std::ostream &oss, quaternion<T> const &q) noexcept __attribute__((__always_inline__)) {
    w /= len;
    oss << "Re: " << q.w << " Im: " << q.v;
    v /= len;
    return oss;
  }
  }

  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
  /**
    T len = length_faster();
   * Gets string representation.
    w /= len;
   */
    v /= len;
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
  }
    std::ostringstream oss;
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    oss << *this;
    normalise();
    return oss.str();
  }
  }
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
    normalise_fast();
    return to_string();
  }
  }
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {

    normalise_faster();
  /**
  }
   * Creates quaternion from transform matrix.
  inline quaternion<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
   *
    T const temp(length());
   * @param m Transform matrix used to compute quaternion.
    return quaternion<T>(w / temp, v / temp);
   * @return quaternion representing rotation of matrix m.
  }
   */
  inline quaternion<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
  // 2011-07-02: Davide Bacchet: changed formula to fix degenerate cases
    T const temp(length_fast());
  inline static quaternion<T> constexpr from_matrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w / temp, v / temp);
    quaternion<T> q;
  }

  inline quaternion<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    T const tr = m(1, 1) + m(2, 2) + m(3, 3);
    T const temp(length_faster());
    if(tr >= static_cast<T>(epsilon)) {
    return quaternion<T>(w / temp, v / temp);
      T const s = static_cast<T>(0.5) / static_cast<T>(std::sqrt(tr + static_cast<T>(1.0)));
  }
      q.w = static_cast<T>(0.25) / s;
  inline quaternion<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      q.v.x = (m(3, 2) - m(2, 3)) * s;
    return normalise_copy();
      q.v.y = (m(1, 3) - m(3, 1)) * s;
  }
      q.v.z = (m(2, 1) - m(1, 2)) * s;
  inline quaternion<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    } else {
    return normalise_copy_fast();
      T d0 = m(1, 1);
  }
      T d1 = m(2, 2);
  inline quaternion<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      T d2 = m(3, 3);
    return normalise_copy_faster();

  }
      char bigIdx = (d0 > d1) ? ((d0 > d2) ? 0 : 2) : ((d1 > d2) ? 1 : 2);


  inline void constexpr conjugate() noexcept __attribute__((__always_inline__)) {
      if(bigIdx == 0) {
    v = -v;
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(1, 1) - m(2, 2) - m(3, 3)));
  }
        q.w = (m(3, 2) - m(2, 3)) / s;

        q.v.x = static_cast<T>(0.25) * s;
  inline quaternion<T> constexpr conjugate_copy() const noexcept __attribute__((__always_inline__)) {
        q.v.y = (m(1, 2) + m(2, 1)) / s;
    return quaternion<T>(w, -v);
        q.v.z = (m(1, 3) + m(3, 1)) / s;
  }
      } else if(bigIdx == 1) {

        T s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(2, 2) - m(1, 1) - m(3, 3)));
  /**
        q.w = (m(1, 3) - m(3, 1)) / s;
   * @brief Computes the inverse of this quaternion.
        q.v.x = (m(1, 2) + m(2, 1)) / s;
   *
        q.v.y = static_cast<T>(0.25) * s;
   * @note This is a general inverse.  If you know a priori
        q.v.z = (m(2, 3) + m(3, 2)) / s;
   * that you're using a unit quaternion (i.e., norm() == 1),
      } else {
   * it will be significantly faster to use conjugate() instead.
        T s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(3, 3) - m(1, 1) - m(2, 2)));
   *
        q.w = (m(2, 1) - m(1, 2)) / s;
   * @return The quaternion q such that q * (*this) == (*this) * q
        q.v.x = (m(1, 3) + m(3, 1)) / s;
   * == [ 0 0 0 1 ]<sup>T</sup>.
        q.v.y = (m(2, 3) + m(3, 2)) / s;
   */
        q.v.z = static_cast<T>(0.25) * s;
      }
  inline void constexpr invert() noexcept __attribute__((__always_inline__)) {
    }
    T l = length();

    conjugate();
    return q;
    (*this) /= l;
  }
  }

  inline static quaternion<T> constexpr fromMatrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
  inline quaternion<T> constexpr invert_copy() const noexcept __attribute__((__always_inline__)) {
    return from_matrix(m);
    return conjugate_copy() / length();
  }
  }


  /**
  /**
   * Creates quaternion from rotation matrix.
   * Creates quaternion for Euler angles.
   *
   * @param x Rotation around x axis (in degrees).
   * @param m Rotation matrix used to compute quaternion.
   * @param y Rotation around y axis (in degrees).
   * @return quaternion representing rotation of matrix m.
   * @param z Rotation around z axis (in degrees).
   */
   * @return quaternion object representing transformation.
  // 2011-07-02: Davide Bacchet: changed formula to fix degenerate cases
   */
  inline static quaternion<T> constexpr from_matrix(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
  inline static quaternion<T> constexpr from_euler_angles(T x, T y, T z) noexcept __attribute__((__always_inline__)) {
    quaternion<T> q;
    return quaternion<T>(from_axis_rot(vector3<T>(1, 0, 0), x) *

                         from_axis_rot(vector3<T>(0, 1, 0), y) *
    T const tr = m(1, 1) + m(2, 2) + m(3, 3);
                         from_axis_rot(vector3<T>(0, 0, 1), z));
    if(tr >= static_cast<T>(epsilon)) {
  }
      T const s = static_cast<T>(0.5) / static_cast<T>(std::sqrt(tr + static_cast<T>(1.0)));
  inline static quaternion<T> constexpr fromEulerAngles(T x, T y, T z) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles()"))) {
      q.w = static_cast<T>(0.25) / s;
    return from_euler_angles(x, y, z);
      q.v.x = (m(3, 2) - m(2, 3)) * s;
  }
      q.v.y = (m(1, 3) - m(3, 1)) * s;

      q.v.z = (m(2, 1) - m(1, 2)) * s;
  /**
    } else {
   * Creates quaternion for Euler angles, rad version.
      T d0 = m(1, 1);
   * @param x Rotation around x axis (in radians).
      T d1 = m(2, 2);
   * @param y Rotation around y axis (in radians).
      T d2 = m(3, 3);
   * @param z Rotation around z axis (in radians).

   * @return quaternion object representing transformation.
      char bigIdx = (d0 > d1) ? ((d0 > d2) ? 0 : 2) : ((d1 > d2) ? 1 : 2);
   */

      if(bigIdx == 0) {
  inline static quaternion<T> constexpr from_euler_angles_rad(T x, T y, T z) noexcept __attribute__((__always_inline__)) {
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(1, 1) - m(2, 2) - m(3, 3)));
    return quaternion<T>(from_axis_rot_rad(vector3<T>(1, 0, 0), x) *
        q.w = (m(3, 2) - m(2, 3)) / s;
                         from_axis_rot_rad(vector3<T>(0, 1, 0), y) *
        q.v.x = static_cast<T>(0.25) * s;
                         from_axis_rot_rad(vector3<T>(0, 0, 1), z));
        q.v.y = (m(1, 2) + m(2, 1)) / s;
  }
        q.v.z = (m(1, 3) + m(3, 1)) / s;
  inline static quaternion<T> constexpr fromEulerAngles_rad(T x, T y, T z) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles_rad()"))) {
      } else if(bigIdx == 1) {
    return from_euler_angles_rad(x, y, z);
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(2, 2) - m(1, 1) - m(3, 3)));
  }
        q.w = (m(1, 3) - m(3, 1)) / s;

        q.v.x = (m(1, 2) + m(2, 1)) / s;
  /**
        q.v.y = static_cast<T>(0.25) * s;
   * Creates quaternion as rotation around axis.
        q.v.z = (m(2, 3) + m(3, 2)) / s;
   * @param axis Unit vector expressing axis of rotation.
      } else {
   * @param angleDeg Angle of rotation around axis (in degrees).
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(3, 3) - m(1, 1) - m(2, 2)));
   */
        q.w = (m(2, 1) - m(1, 2)) / s;
  inline static quaternion<T> constexpr from_axis_rot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) {
        q.v.x = (m(1, 3) + m(3, 1)) / s;
    return from_axis_rot_rad(axis, deg2rad(angleDeg));
        q.v.y = (m(2, 3) + m(3, 2)) / s;
  }
        q.v.z = static_cast<T>(0.25) * s;
  inline static quaternion<T> constexpr fromAxisRot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot()"))) {
      }
    return from_axis_rot(axis, angleDeg);
    }
  }
    return q;

  }
  /**
  inline static quaternion<T> constexpr fromMatrix(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
   * Creates quaternion as rotation around axis, rad version.
    return from_matrix(m);
   * @param axis Unit vector expressing axis of rotation.
  }
   * @param angleDeg Angle of rotation around axis (in radians).

   */
  /**
  inline static quaternion<T> constexpr from_axis_rot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) {
   * Computes spherical interpolation between quaternions (this, q2)
    T temp_sin = static_cast<T>(0);
   * using coefficient of interpolation r (in [0, 1]).
    T temp_cos = static_cast<T>(0);
   *
    sincos_any(angleRad / static_cast<T>(2.0), temp_sin, temp_cos);
   * @param r The ratio of interpolation form this (r = 0) to q2 (r = 1).
    return quaternion<T>(temp_cos, axis * temp_sin);
   * @param q2 Second quaternion for interpolation.
  }
   * @return Result of interpolation.
  inline static quaternion<T> constexpr fromAxisRot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot_rad()"))) {
   */
    return from_axis_rot_rad(axis, angleRad);
  inline quaternion<T> constexpr slerp(T r, quaternion<T> const &q2) const noexcept __attribute__((__always_inline__)) {
  }
    quaternion<T> ret;

    T const cosTheta = w * q2.w + v.x * q2.v.x + v.y * q2.v.y + v.z * q2.v.z;
  /**
    T const theta = static_cast<T>(std::acos(cosTheta));
   * Converts this quaternion to an axis and angle combination
    if(std::abs(theta) < static_cast<T>(epsilon)) {
   * @param angle The angle of rotation
      ret = *this;
   * @param axis The axis around which the rotation is
    } else {
   */
      T sinTheta = static_cast<T>(std::sqrt(static_cast<T>(1.0) - cosTheta * cosTheta));
  inline void constexpr to_angle_axis(T &angle, vector3<T> &axis) noexcept __attribute__((__always_inline__)) {
      if(std::abs(sinTheta) < static_cast<T>(epsilon)) {
    T const squareLength = v.length_sq();
        ret.w = static_cast<T>(0.5) * w + static_cast<T>(0.5) * q2.w;
    if(squareLength != 0) {
        ret.v = v.lerp(static_cast<T>(0.5), q2.v);
      angle = static_cast<T>(2.0) * std::acos(w);
      } else {
      axis = v / std::pow(squareLength, static_cast<T>(0.5));
        T rA = static_cast<T>(std::sin((static_cast<T>(1.0) - r) * theta)) / sinTheta;
    } else {
        T rB = static_cast<T>(std::sin(r * theta)) / sinTheta;
      angle = static_cast<T>(0.0);

      axis.assign(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
        ret.w = w * rA + q2.w * rB;
    }
        ret.v.x = v.x * rA + q2.v.x * rB;
  }
        ret.v.y = v.y * rA + q2.v.y * rB;
  inline void constexpr toAngleAxis(T &angle, vector3<T> &axis) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_angle_axis()"))) {
        ret.v.z = v.z * rA + q2.v.z * rB;
    to_angle_axis(angle, axis);
      }
  }
    }

    return ret;
  /**
  }
   * Converts quaternion into rotation matrix.
};
   * @return Rotation matrix expressing this quaternion.

   */
#ifdef VMATH_NAMESPACE
  inline matrix3<T> constexpr rotmatrix() noexcept __attribute__((__always_inline__)) {
}
    return matrix3<T>(1 - 2 * (v.y * v.y + v.z * v.z),     2 * (v.x * v.y + v.z * w),       2 * (v.x * v.z - v.y * w),
#endif //VMATH_NAMESPACE

                          2 * (v.x * v.y - v.z * w),   1 - 2 * (v.x * v.x + v.z * v.z),     2 * (v.y * v.z + v.x * w),
#include "quat_types.h"
                          2 * (v.x * v.z + v.y * w),       2 * (v.y * v.z - v.x * w),   1 - 2 * (v.x * v.x + v.y * v.y));

  }
#endif // VECTORSTORM_QUAT_H_INCLUDED

  /**
   * Converts quaternion into transformation matrix.
   * @note This method performs same operation as rotmatrix()
   * conversion method. But returns matrix of 4x4 elements.
   * @return Transformation matrix expressing this quaternion.
   */
  inline matrix4<T> constexpr transform() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(1 - 2 * (v.y * v.y + v.z * v.z),     2 * (v.x * v.y + v.z * w),       2 * (v.x * v.z - v.y * w),   0.0f,
                          2 * (v.x * v.y - v.z * w),   1 - 2 * (v.x * v.x + v.z * v.z),     2 * (v.y * v.z + v.x * w),   0.0f,
                          2 * (v.x * v.z + v.y * w),       2 * (v.y * v.z - v.x * w),   1 - 2 * (v.x * v.x + v.y * v.y), 0.0f,
                      0.0f,                            0.0f,                            0.0f,                            1.0f);
  }

  /**
   * Linear interpolation of two quaternions
   * @param fact Factor of interpolation. For translation from position
   * of this vector to quaternion rhs, values of factor goes from 0.0 to 1.0.
   * @param rhs Second quaternion for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  inline quaternion<T> constexpr lerp(T fact, quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>((1 - fact) * w + fact * rhs.w, v.lerp(fact, rhs.v));
  }

  /**
   * Provides output to standard output stream.
   */
  inline friend std::ostream &operator <<(std::ostream &oss, quaternion<T> const &q) noexcept __attribute__((__always_inline__)) {
    oss << "Re: " << q.w << " Im: " << q.v;
    return oss;
  }

  /**
   * Gets string representation.
   */
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
    return to_string();
  }

  /**
   * Creates quaternion from transform matrix.
   *
   * @param m Transform matrix used to compute quaternion.
   * @return quaternion representing rotation of matrix m.
   */
  // 2011-07-02: Davide Bacchet: changed formula to fix degenerate cases
  inline static quaternion<T> constexpr from_matrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) {
    quaternion<T> q;

    T const tr = m(1, 1) + m(2, 2) + m(3, 3);
    if(tr >= static_cast<T>(epsilon)) {
      T const s = static_cast<T>(0.5) / static_cast<T>(std::sqrt(tr + static_cast<T>(1.0)));
      q.w = static_cast<T>(0.25) / s;
      q.v.x = (m(3, 2) - m(2, 3)) * s;
      q.v.y = (m(1, 3) - m(3, 1)) * s;
      q.v.z = (m(2, 1) - m(1, 2)) * s;
    } else {
      T d0 = m(1, 1);
      T d1 = m(2, 2);
      T d2 = m(3, 3);

      char bigIdx = (d0 > d1) ? ((d0 > d2) ? 0 : 2) : ((d1 > d2) ? 1 : 2);

      if(bigIdx == 0) {
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(1, 1) - m(2, 2) - m(3, 3)));
        q.w = (m(3, 2) - m(2, 3)) / s;
        q.v.x = static_cast<T>(0.25) * s;
        q.v.y = (m(1, 2) + m(2, 1)) / s;
        q.v.z = (m(1, 3) + m(3, 1)) / s;
      } else if(bigIdx == 1) {
        T s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(2, 2) - m(1, 1) - m(3, 3)));
        q.w = (m(1, 3) - m(3, 1)) / s;
        q.v.x = (m(1, 2) + m(2, 1)) / s;
        q.v.y = static_cast<T>(0.25) * s;
        q.v.z = (m(2, 3) + m(3, 2)) / s;
      } else {
        T s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(3, 3) - m(1, 1) - m(2, 2)));
        q.w = (m(2, 1) - m(1, 2)) / s;
        q.v.x = (m(1, 3) + m(3, 1)) / s;
        q.v.y = (m(2, 3) + m(3, 2)) / s;
        q.v.z = static_cast<T>(0.25) * s;
      }
    }

    return q;
  }
  inline static quaternion<T> constexpr fromMatrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
    return from_matrix(m);
  }

  /**
   * Creates quaternion from rotation matrix.
   *
   * @param m Rotation matrix used to compute quaternion.
   * @return quaternion representing rotation of matrix m.
   */
  // 2011-07-02: Davide Bacchet: changed formula to fix degenerate cases
  inline static quaternion<T> constexpr from_matrix(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
    quaternion<T> q;

    T const tr = m(1, 1) + m(2, 2) + m(3, 3);
    if(tr >= static_cast<T>(epsilon)) {
      T const s = static_cast<T>(0.5) / static_cast<T>(std::sqrt(tr + static_cast<T>(1.0)));
      q.w = static_cast<T>(0.25) / s;
      q.v.x = (m(3, 2) - m(2, 3)) * s;
      q.v.y = (m(1, 3) - m(3, 1)) * s;
      q.v.z = (m(2, 1) - m(1, 2)) * s;
    } else {
      T d0 = m(1, 1);
      T d1 = m(2, 2);
      T d2 = m(3, 3);

      char bigIdx = (d0 > d1) ? ((d0 > d2) ? 0 : 2) : ((d1 > d2) ? 1 : 2);

      if(bigIdx == 0) {
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(1, 1) - m(2, 2) - m(3, 3)));
        q.w = (m(3, 2) - m(2, 3)) / s;
        q.v.x = static_cast<T>(0.25) * s;
        q.v.y = (m(1, 2) + m(2, 1)) / s;
        q.v.z = (m(1, 3) + m(3, 1)) / s;
      } else if(bigIdx == 1) {
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(2, 2) - m(1, 1) - m(3, 3)));
        q.w = (m(1, 3) - m(3, 1)) / s;
        q.v.x = (m(1, 2) + m(2, 1)) / s;
        q.v.y = static_cast<T>(0.25) * s;
        q.v.z = (m(2, 3) + m(3, 2)) / s;
      } else {
        T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + m(3, 3) - m(1, 1) - m(2, 2)));
        q.w = (m(2, 1) - m(1, 2)) / s;
        q.v.x = (m(1, 3) + m(3, 1)) / s;
        q.v.y = (m(2, 3) + m(3, 2)) / s;
        q.v.z = static_cast<T>(0.25) * s;
      }
    }
    return q;
  }
  inline static quaternion<T> constexpr fromMatrix(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
    return from_matrix(m);
  }

  /**
   * Computes spherical interpolation between quaternions (this, q2)
   * using coefficient of interpolation r (in [0, 1]).
   *
   * @param r The ratio of interpolation form this (r = 0) to q2 (r = 1).
   * @param q2 Second quaternion for interpolation.
   * @return Result of interpolation.
   */
  inline quaternion<T> constexpr slerp(T r, quaternion<T> const &q2) const noexcept __attribute__((__always_inline__)) {
    quaternion<T> ret;
    T const cosTheta = w * q2.w + v.x * q2.v.x + v.y * q2.v.y + v.z * q2.v.z;
    T const theta = static_cast<T>(std::acos(cosTheta));
    if(std::abs(theta) < static_cast<T>(epsilon)) {
      ret = *this;
    } else {
      T sinTheta = static_cast<T>(std::sqrt(static_cast<T>(1.0) - cosTheta * cosTheta));
      if(std::abs(sinTheta) < static_cast<T>(epsilon)) {
        ret.w = static_cast<T>(0.5) * w + static_cast<T>(0.5) * q2.w;
        ret.v = v.lerp(static_cast<T>(0.5), q2.v);
      } else {
        T rA = static_cast<T>(std::sin((static_cast<T>(1.0) - r) * theta)) / sinTheta;
        T rB = static_cast<T>(std::sin(r * theta)) / sinTheta;

        ret.w = w * rA + q2.w * rB;
        ret.v.x = v.x * rA + q2.v.x * rB;
        ret.v.y = v.y * rA + q2.v.y * rB;
        ret.v.z = v.z * rA + q2.v.z * rB;
      }
    }
    return ret;
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "quat_types.h"

#endif // VECTORSTORM_QUAT_H_INCLUDED
