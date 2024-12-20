#pragma once

#include "vectorstorm/epsilon.h"
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
#include "vectorstorm/vector/vector3_forward.h"
#include "vectorstorm/vector/vector3.h"
#include "vectorstorm/matrix/matrix3_forward.h"
#include "vectorstorm/matrix/matrix4_forward.h"
#include "vectorstorm/sqrt_fast.h"
#ifndef VECTORSTORM_NO_BOOST
  #include <boost/functional/hash_fwd.hpp>
#endif // VECTORSTORM_NO_BOOST

#ifdef __clang__
  #define CONSTEXPR_IF_NO_CLANG
#else
  #define CONSTEXPR_IF_NO_CLANG constexpr
#endif // __clang__ - see https://stackoverflow.com/questions/46576847/clang-vs-gcc-crtp-constexpr-variable-cannot-have-non-literal-type

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

/**
 * quaternion class implementing some quaternion algebra operations.
 * quaternion is kind of complex number it consists of its real part (w)
 * and its complex part v. This complex part has three elements, so we
 * can express it as xi + yj + zk . Note that coordinates of (x,y,z) are
 * hold inside v field.
 */
template<typename T>
class quaternion {
public:
  union {
    /**
     * Real part of quaternion.
     */
    T w;
    T real;
    T scalar;
  };

  union {
    /**
     * Imaginary part of quaternion.
     */
    vector3<T> v;
    vector3<T> imaginary;
    vector3<T> vector;
  };

  /**
   * What square root mode to use, passed as a template parameter to functions like length()
   */
  enum class sqrt_mode {
    /**
     * Use standard library std::sqrt
     */
    std,
    /**
     * Use fast approximation from sqrt_fast.h
     */
    fast,
    /**
     * Use rough version of fast approximation from sqrt_fast.h, with one step instead of two
     */
    coarse,
  };


  /**
   * quaternion constructor, sets quaternion to (0 + 0i + 0j + 0k).
   */
  inline constexpr quaternion() noexcept __attribute__((__always_inline__))
    : w(1),
      v(0, 0, 0) {
  }

  /**
   * Copy constructor.
   */
  inline constexpr explicit quaternion(quaternion<T> const &q) noexcept __attribute__((__always_inline__))
    : w(q.w),
      v(q.v) {
  }

  /**
   * Copy casting constructor.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit quaternion(quaternion<FromT> const &q) noexcept
    : w(static_cast<T>(q.w)),
      v(q.v) {
  }

  /**
   * Move constructor.
   */
  inline constexpr quaternion(quaternion<T> &&q) noexcept __attribute__((__always_inline__))
    : w(std::move(q.w)),
      v(std::move(q.v)) {
  }

  /**
   * Move casting constructor.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr quaternion(quaternion<FromT> &&q) noexcept
    : w(static_cast<T>(std::move(q.w))),
      v(std::move(q.v)) {
  }

  /**
   * Creates quaternion object from real part w_ and complex part v_.
   * @param w_ Real part of quaternion.
   * @param v_ Complex part of quaternion (xi + yj + zk).
   */
  inline constexpr quaternion(T w_, vector3<T> const &v_) noexcept __attribute__((__always_inline__))
    : w(w_),
      v(v_) {
  }

  /**
   * Creates quaternion object from value (w_ + xi + yj + zk).
   * @param w_ Real part of quaternion.
   * @param x Complex coefficient for i complex constant.
   * @param y Complex coefficient for j complex constant.
   * @param z Complex coefficient for k complex constant.
   */
  inline constexpr quaternion(T w_, T x, T y, T z) noexcept __attribute__((__always_inline__))
    : w(w_), v(x, y, z) {
  }

  /**
   * Construct quaternion from rotation matrix.
   */
  inline constexpr explicit quaternion(matrix3<T> const &matrix) noexcept __attribute__((__always_inline__)) {
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
    // article "quaternion Calculus and Fast Animation".
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
    if(trace > 0) {
      // |w| > 1/2, may as well choose w > 1/2
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
      w = static_cast<T>(0.5) * root;
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;
      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
    } else {
      // |w| <= 1/2
      unsigned int constexpr next[3] = {1, 2, 0};

      unsigned int i = 0;
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
        i = 1;
      }
      if(matrix.at(2, 2) > matrix.at(i, i)) {
        i = 2;
      }
      unsigned int j = next[i];
      unsigned int k = next[j];

      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
      T *q[3] = {&v.x, &v.y, &v.z};
      *q[i] = static_cast<T>(0.5) * root;
      root = static_cast<T>(0.5) / root;
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;
      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
    }
  }
  inline constexpr explicit quaternion(matrix4<T> const &matrix) noexcept __attribute__((__always_inline__)) {
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
    // article "quaternion Calculus and Fast Animation".
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
    if(trace > 0) {
      // |w| > 1/2, may as well choose w > 1/2
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
      w = static_cast<T>(0.5) * root;
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;
      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
    } else {
      // |w| <= 1/2
      unsigned int constexpr next[3] = {1, 2, 0};

      unsigned int i = 0;
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
        i = 1;
      }
      if(matrix.at(2, 2) > matrix.at(i, i)) {
        i = 2;
      }
      unsigned int j = next[i];
      unsigned int k = next[j];

      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
      T *q[3] = {&v.x, &v.y, &v.z};
      *q[i] = static_cast<T>(0.5) * root;
      root = static_cast<T>(0.5) / root;
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;
      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
    }
  }

  //----------------[ assignment ]-------------------------
  /**
   * Sets to (w_ + xi + yj + zk).
   * @param w_ Real part of quaternion.
   * @param x Complex coefficient for i complex constant.
   * @param y Complex coefficient for j complex constant.
   * @param z Complex coefficient for k complex constant.
   */
  inline void constexpr assign(T w_ = 0, T x = 0, T y = 0, T z = 0) noexcept __attribute__((__always_inline__)) {
    w = w_;
    v.assign(x, y, z);
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    v = rhs.v;
    w = rhs.w;
    return *this;
  }

  /**
   * Copy convert operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline quaternion<T> constexpr &operator=(quaternion<FromT> const &rhs) noexcept {
    v = rhs.v;
    w = static_cast<T>(rhs.w);
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator=(quaternion<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    v = std::move(rhs.v);
    w = std::move(rhs.w);
    return *this;
  }

  /**
   * Move assignment convert operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline quaternion<T> constexpr &operator=(quaternion<FromT> &&rhs) noexcept {
    v = std::move(rhs.v);
    w = static_cast<T>(std::move(rhs.w));
    return *this;
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator+(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w + rhs.w, v + rhs.v);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w * rhs.w   - v.x * rhs.v.x - v.y * rhs.v.y - v.z * rhs.v.z,
                         w * rhs.v.x + v.x * rhs.w   + v.y * rhs.v.z - v.z * rhs.v.y,
                         w * rhs.v.y - v.x * rhs.v.z + v.y * rhs.w   + v.z * rhs.v.x,
                         w * rhs.v.z + v.x * rhs.v.y - v.y * rhs.v.x + v.z * rhs.w);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w * rhs, v * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w / rhs, v / rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator-(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w - rhs.w, v - rhs.v);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator+=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    w += rhs.w;
    v += rhs.v;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator-=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    w -= rhs.w;
    v -= rhs.v;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    quaternion q = (*this) * rhs;
    v = q.v;
    w = q.w;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    w *= rhs;
    v *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    w /= rhs;
    v /= rhs;
    return *this;
  }

  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition | lhs - rhs | < epsilon,
   * for all quaternion coordinates.
   */
  inline bool constexpr operator==(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VECTORSTORM_SOFT_COMPARE
      return (std::abs(w - rhs.w) < epsilon<T>) && v == rhs.v;
    #else
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wfloat-equal"
      return w == rhs.w && v == rhs.v;
      #pragma GCC diagnostic pop
    #endif // VECTORSTORM_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }
  /**
   * Dot product of two quaternions.
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr dot(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (w * rhs.w) + v.dot(rhs.v);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated quaternion
   */
  inline quaternion<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(-w, -v);
  }

  /**
   * Unary conjugate operator
   * @return conjugated quaternion
   */
  inline quaternion<T> constexpr operator~() const noexcept __attribute__((__always_inline__)) {
    return quaternion<T>(w, -v);
  }

  /**
   * Return square of length.
   * @return length ^ 2
   * @note This method is faster then length(). For comparison
   * of length of two quaternion can be used just this value, instead
   * of more expensive length() method.
   */
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
    return w * w + v.length_sq();
  }

  /**
   * Get length of quaternion.
   * @return Length of quaternion.
   */
  template<sqrt_mode mode = sqrt_mode::std>
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
    if constexpr(mode == sqrt_mode::std) {
      return std::sqrt(length_sq());
    } else if constexpr(mode == sqrt_mode::fast) {
      return sqrt_fast(length_sq());
    } else if constexpr(mode == sqrt_mode::coarse) {
      return sqrt_coarse(length_sq());
    } else {
      static_assert(always_false_v<sqrt_mode>, "Unsupported sqrt_mode");
    }
  }
  /**
   * Get length of quaternion, fast approximation.
   * @return Length of quaternion.
   */
  [[deprecated("Use length<quat<T>::sqrt_mode::fast>()")]]
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) {
    return length<sqrt_mode::fast>();
  }
  /**
   * Get length of quaternion, rougher fast approximation.
   * @return Length of quaternion.
   */
  [[deprecated("Use length<quat<T>::sqrt_mode::coarse>()")]]
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) {
    return length<sqrt_mode::coarse>();
  }

  /**
   * normalise quaternion
   */
  template<sqrt_mode mode = sqrt_mode::std>
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
    *this /= length<mode>();
  }
  [[deprecated("Use normalise<quat<T>::sqrt_mode::fast>()")]]
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    normalise<sqrt_mode::fast>();
  }
  [[deprecated("Use normalise<quat<T>::sqrt_mode::coarse>()")]]
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    normalise<sqrt_mode::coarse>();
  }
  template<sqrt_mode mode = sqrt_mode::std>
  inline quaternion<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    return *this / length<mode>();
  }
  [[deprecated("Use normalise_copy<quat<T>::sqrt_mode::fast>()")]]
  inline quaternion<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy<sqrt_mode::fast>();
  }
  [[deprecated("Use normalise_copy<quat<T>::sqrt_mode::coarse>()")]]
  inline quaternion<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy<sqrt_mode::coarse>();
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
   * The quaternion q such that q * (*this) == (*this) * q
   * == [ 0 0 0 1 ]<sup>T</sup>.
   *
   * @note This is a general inverse.  If you know a priori
   * that you're using a unit quaternion (i.e., norm() == 1),
   * it will be significantly faster to use conjugate() instead.
   */
  inline void constexpr invert() noexcept __attribute__((__always_inline__)) {
    T l = length();
    conjugate();
    *this /= l;
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

  /**
   * Creates quaternion as rotation around axis.
   * @param axis Unit vector expressing axis of rotation.
   * @param angleDeg Angle of rotation around axis (in degrees).
   */
  inline static quaternion<T> constexpr from_axis_rot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) {
    return from_axis_rot_rad(axis, deg2rad(angleDeg));
  }

  /**
   * Creates quaternion as rotation around axis, rad version.
   * @param axis Unit vector expressing axis of rotation.
   * @param angleRad Angle of rotation around axis (in radians).
   */
  inline static quaternion<T> constexpr from_axis_rot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) {
    T temp_sin = static_cast<T>(0);
    T temp_cos = static_cast<T>(0);
    sincos_any(angleRad / static_cast<T>(2.0), temp_sin, temp_cos);
    return quaternion<T>(temp_cos, axis * temp_sin);
  }

  /**
   * Converts this quaternion to an axis and angle combination
   * @param angle The angle of rotation
   * @param axis The axis around which the rotation is
   */
  inline void constexpr to_angle_axis(T &angle, vector3<T> &axis) const noexcept __attribute__((__always_inline__)) {
    T const squareLength = v.length_sq();
    if(squareLength != 0) {
      angle = static_cast<T>(2) * std::acos(w);
      axis = v / std::pow(squareLength, static_cast<T>(0.5));
    } else {
      angle = static_cast<T>(0);
      axis.assign(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
    }
  }

  /**
   * Converts quaternion into rotation matrix.
   * @return Rotation matrix expressing this quaternion.
   */
  inline matrix3<T> constexpr rotmatrix() const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(static_cast<T>(1) - static_cast<T>(2) * (v.y * v.y + v.z * v.z),
                      static_cast<T>(2)                     * (v.x * v.y + v.z * w),
                      static_cast<T>(2)                     * (v.x * v.z - v.y * w),

                      static_cast<T>(2)                     * (v.x * v.y - v.z * w),
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.z * v.z),
                      static_cast<T>(2)                     * (v.y * v.z + v.x * w),

                      static_cast<T>(2)                     * (v.x * v.z + v.y * w),
                      static_cast<T>(2)                     * (v.y * v.z - v.x * w),
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.y * v.y));
  }

  /**
   * Converts quaternion into transformation matrix.
   * @note This method performs same operation as rotmatrix()
   * conversion method. But returns matrix of 4x4 elements.
   * @return Transformation matrix expressing this quaternion.
   */
  inline matrix4<T> constexpr transform() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(static_cast<T>(1) - static_cast<T>(2) * (v.y * v.y + v.z * v.z),
                      static_cast<T>(2)                     * (v.x * v.y + v.z * w),
                      static_cast<T>(2)                     * (v.x * v.z - v.y * w),
                      static_cast<T>(0),

                      static_cast<T>(2)                     * (v.x * v.y - v.z * w),
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.z * v.z),
                      static_cast<T>(2)                     * (v.y * v.z + v.x * w),
                      static_cast<T>(0),

                      static_cast<T>(2)                     * (v.x * v.z + v.y * w),
                      static_cast<T>(2)                     * (v.y * v.z - v.x * w),
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.y * v.y),
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(1));
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
   * Computes spherical interpolation between quaternions (this, q2)
   * using coefficient of interpolation fact (in [0, 1]).
   *
   * @param fact The ratio of interpolation form this (fact = 0) to q2 (fact = 1).
   * @param rhs Second quaternion for interpolation.
   * @return Result of interpolation.
   */
  inline quaternion<T> constexpr slerp(T fact, quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    T cos_theta = std::clamp(dot(rhs), static_cast<T>(-1), static_cast<T>(1));  // clamp the dot product, as it can sometimes exceed 1.0 and cause acos to return NaN
    quaternion<T> rhs_temp(rhs);
    if(cos_theta < static_cast<T>(0)) {                                         // dot(lhs, rhs) must be positive for smooth interpolation around poles; if not, flip rhs
      cos_theta = -cos_theta;
      rhs_temp = -rhs_temp;
    }
    T const theta = static_cast<T>(std::acos(cos_theta));
    if(std::abs(theta) <= epsilon<T>) {
      return quaternion<T>{*this};
    } else {
      T const sin_theta = static_cast<T>(std::sqrt(static_cast<T>(1) - cos_theta * cos_theta));
      //if(std::abs(sin_theta) <= epsilon<T>) {
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wfloat-equal"
      if(sin_theta == static_cast<T>(0)) {                                      // we only need to avoid division by zero, no need to check for epsilon
      #pragma GCC diagnostic pop
        // this point may only be reached extremely rarely?
        return quaternion<T>{static_cast<T>(0.5) * w + static_cast<T>(0.5) * rhs_temp.w, v.lerp(static_cast<T>(0.5), rhs_temp.v)};
      } else {
        T const temp_a = static_cast<T>(std::sin((static_cast<T>(1) - fact) * theta)) / sin_theta;
        T const temp_b = static_cast<T>(std::sin(fact * theta)) / sin_theta;
        return quaternion<T>{(w * temp_a) + (rhs_temp.w * temp_b),
                             (v * temp_a) + (rhs_temp.v * temp_b)};
      }
    }
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
  inline std::string CONSTEXPR_IF_NO_CLANG to_string() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }

  /**
   * Creates quaternion from transform matrix.
   *
   * @param m Transform matrix used to compute quaternion.
   * @return quaternion representing rotation of matrix m.
   */
  // matrix4 is convertible to matrix3 so the below is not useful
  /*
  inline static quaternion<T> constexpr from_matrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) {
    return from_matrix(m.get_rotation());
  }
  */

  /**
   * Creates quaternion from rotation matrix.
   *
   * @param mat Rotation matrix used to compute quaternion.
   * @return quaternion representing rotation of matrix m.
   */
  inline static quaternion<T> constexpr from_matrix(matrix3<T> const &mat) noexcept __attribute__((__always_inline__)) {
    T const tr = mat(1, 1) + mat(2, 2) + mat(3, 3);
    if(tr >= epsilon<T>) {
      T const s = static_cast<T>(0.5) / static_cast<T>(std::sqrt(tr + static_cast<T>(1.0)));
      return quaternion<T>(static_cast<T>(0.25)    / s,
                           (mat(3, 2) - mat(2, 3)) * s,
                           (mat(1, 3) - mat(3, 1)) * s,
                           (mat(2, 1) - mat(1, 2)) * s);
    } else {
      if(mat(1, 1) > mat(2, 2)) {
        if(mat(1, 1) > mat(3, 3)) {
          T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + mat(1, 1) - mat(2, 2) - mat(3, 3)));
          return quaternion<T>((mat(3, 2) - mat(2, 3)) / s,
                               static_cast<T>(0.25)    * s,
                               (mat(1, 2) + mat(2, 1)) / s,
                               (mat(1, 3) + mat(3, 1)) / s);
        }
      } else {
        if(mat(2, 2) > mat(3, 3)) {
          T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + mat(2, 2) - mat(1, 1) - mat(3, 3)));
          return quaternion<T>((mat(1, 3) - mat(3, 1)) / s,
                               (mat(1, 2) + mat(2, 1)) / s,
                               static_cast<T>(0.25)    * s,
                               (mat(2, 3) + mat(3, 2)) / s);
        }
      }
      T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + mat(3, 3) - mat(1, 1) - mat(2, 2)));
      return quaternion<T>((mat(2, 1) - mat(1, 2)) / s,
                           (mat(1, 3) + mat(3, 1)) / s,
                           (mat(2, 3) + mat(3, 2)) / s,
                           static_cast<T>(0.25)    * s);
    }
  }

private:
  template<typename> static constexpr bool always_false_v{false};
};

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "quat_types.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Standard C++ library extensions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VECTORSTORM_NO_BOOST
namespace std {

template<typename T>
struct hash<quaternion<T>> {
  /**
   * Gets a hash value taking account of all dimensions of this quaternion, for use
   * in standard container maps etc.
   * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
   * @return Hash value
   */
  size_t operator()(const quaternion<T> &value) const {
    size_t hashvalue = 0;
    boost::hash_combine(hashvalue, value.v.x);
    boost::hash_combine(hashvalue, value.v.y);
    boost::hash_combine(hashvalue, value.v.z);
    boost::hash_combine(hashvalue, value.w);
    return hashvalue;
  }
};

}

/**
 * Gets a hash value taking account of all dimensions of this quaternion, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
size_t hash_value(quaternion<T> const &value) {
  size_t hashvalue = 0;
  boost::hash_combine(hashvalue, value.v.x);
  boost::hash_combine(hashvalue, value.v.y);
  boost::hash_combine(hashvalue, value.v.z);
  boost::hash_combine(hashvalue, value.w);
  return hashvalue;
}
#endif // VECTORSTORM_NO_BOOST
