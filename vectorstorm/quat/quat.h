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
    #ifdef VMATH_SOFT_COMPARE
      return (std::abs(w - rhs.w) < epsilon<T>) && v == rhs.v;
    #else
      return w == rhs.w && v == rhs.v;
    #endif // VMATH_SOFT_COMPARE
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
#ifndef VECTORSTORM_QUAT_H_INCLUDED
   * Unary negate operator
#define VECTORSTORM_QUAT_H_INCLUDED
   * @return negated quaternion

   */
#include "vectorstorm/epsilon.h"
  inline quaternion<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
#include "vectorstorm/sincos.h"
    return quaternion<T>(-w, -v);
#include "vectorstorm/deg2rad.h"
  }
#include "vectorstorm/vector/vector3.h"

#include "vectorstorm/matrix/matrix3_forward.h"
  /**
#include "vectorstorm/matrix/matrix4_forward.h"

   * Unary conjugate operator
#ifdef VMATH_NAMESPACE
   * @return conjugated quaternion
namespace VMATH_NAMESPACE {
   */
#endif
  inline quaternion<T> constexpr operator~() const noexcept __attribute__((__always_inline__)) {

    return quaternion<T>(w, -v);
/**
  }
 * quaternion class implementing some quaternion algebra operations.

 * quaternion is kind of complex number it consists of its real part (w)
  /**
 * and its complex part v. This complex part has three elements, so we
   * Get length of quaternion.
 * can express it as xi + yj + zk . Note that coordinates of (x,y,z) are
   * @return Length of quaternion.
 * hold inside v field.
   */
 */
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
template<typename T>
    return static_cast<T>(std::sqrt(length_sq()));
class quaternion {
  }
public:
  /**
  union {
    /**
   * Get length of quaternion, fast approximation.
     * Real part of quaternion.
   * @return Length of quaternion.
     */
   */
    T w;
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) {
    T real;
    return static_cast<T>(sqrt_fast(length_sq()));
    T scalar;
  }
  };
  /**

   * Get length of quaternion, rougher fast approximation.
  union {
   * @return Length of quaternion.
    /**
   */
     * Imaginary part of quaternion.
     */
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) {
    vector3<T> v;
    return static_cast<T>(sqrt_faster(length_sq()));
    vector3<T> imaginary;
  }
    vector3<T> vector;

  };
  /**

   * Return square of length.
  /**
   * @return length ^ 2
   * quaternion constructor, sets quaternion to (0 + 0i + 0j + 0k).
   * @note This method is faster then length(). For comparison
   */
   * of length of two quaternion can be used just this value, instead
  inline constexpr quaternion() noexcept __attribute__((__always_inline__))
   * of more expensive length() method.
    : w(0),
   */
      v(0, 0, 0) {
  }
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {

    return w * w + v.length_sq();
  /**
  }
   * Copy constructor.
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
   */
    return length_sq();
  inline constexpr explicit quaternion(quaternion<T> const &q) noexcept __attribute__((__always_inline__))
  }
    : w(q.w),

      v(q.v) {
  /**
  }
   * normalise quaternion

   */
  /**
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
   * Copy casting constructor.
    T const len = length();
   */
    w /= len;
  template<typename FromT>  __attribute__((__always_inline__))
    v /= len;
  inline constexpr explicit quaternion(quaternion<FromT> const &q) noexcept
  }
    : w(static_cast<T>(q.w)),
      v(q.v) {
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
  }
    T const len = length_fast();

    w /= len;
  /**
    v /= len;
   * Move constructor.
  }
   */
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
  inline constexpr quaternion(quaternion<T> &&q) noexcept __attribute__((__always_inline__))
    T const len = length_faster();
    : w(std::move(q.w)),
    w /= len;
      v(std::move(q.v)) {
    v /= len;
  }
  }

  /**
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * Move casting constructor.
    normalise();
   */
  }
  template<typename FromT>  __attribute__((__always_inline__))
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline constexpr quaternion(quaternion<FromT> &&q) noexcept
    normalise_fast();
    : w(static_cast<T>(std::move(q.w))),
  }
      v(std::move(q.v)) {
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    normalise_faster();

  }
  /**
  inline quaternion<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
   * Creates quaternion object from real part w_ and complex part v_.
    T const len(length());
   * @param w_ Real part of quaternion.
    return {w / len, v / len};
   * @param v_ Complex part of quaternion (xi + yj + zk).
  }
   */
  inline quaternion<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
  inline constexpr quaternion(T w_, vector3<T> const &v_) noexcept __attribute__((__always_inline__))
    T const len(length_fast());
    : w(w_),
    return {w / len, v / len};
      v(v_) {
  }
  }

  inline quaternion<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
  /**
    T const len(length_faster());
   * Creates quaternion object from value (w_ + xi + yj + zk).
    return {w / len, v / len};
   * @param w_ Real part of quaternion.
  }
   * @param x Complex coefficient for i complex constant.
  inline quaternion<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * @param y Complex coefficient for j complex constant.
    return normalise_copy();
   * @param z Complex coefficient for k complex constant.
  }
   */
  inline quaternion<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline constexpr quaternion(T w_, T x, T y, T z) noexcept __attribute__((__always_inline__))
    return normalise_copy_fast();
    : w(w_), v(x, y, z) {
  }
  }
  inline quaternion<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {

    return normalise_copy_faster();
  /**
  }
   * Construct quaternion from rotation matrix.

   * @return Rotation matrix expressing this quaternion.
   */
  inline void constexpr conjugate() noexcept __attribute__((__always_inline__)) {
    v = -v;
  inline constexpr explicit quaternion(matrix3<T> const &matrix) noexcept __attribute__((__always_inline__)) {
  }
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes

    // article "quaternion Calculus and Fast Animation".
  inline quaternion<T> constexpr conjugate_copy() const noexcept __attribute__((__always_inline__)) {
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
    if(trace > 0) {
    return quaternion<T>(w, -v);
      // |w| > 1/2, may as well choose w > 1/2
  }
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w

      w = static_cast<T>(0.5) * root;
  /**
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
   * @brief Computes the inverse of this quaternion.
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;
   *
      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
   * @note This is a general inverse.  If you know a priori
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
   * that you're using a unit quaternion (i.e., norm() == 1),
    } else {
   * it will be significantly faster to use conjugate() instead.
      // |w| <= 1/2
   *
      unsigned int constexpr next[3] = {1, 2, 0};
   * @return The quaternion q such that q * (*this) == (*this) * q

   * == [ 0 0 0 1 ]<sup>T</sup>.
      unsigned int i = 0;
   */
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
        i = 1;
  inline void constexpr invert() noexcept __attribute__((__always_inline__)) {
      }
    T l = length();
      if(matrix.at(2, 2) > matrix.at(i, i)) {
    conjugate();
        i = 2;
    (*this) /= l;
      }
  }
      unsigned int j = next[i];

      unsigned int k = next[j];
  inline quaternion<T> constexpr invert_copy() const noexcept __attribute__((__always_inline__)) {

    return conjugate_copy() / length();
      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
  }
      T *q[3] = {&v.x, &v.y, &v.z};

      *q[i] = static_cast<T>(0.5) * root;
  /**
      root = static_cast<T>(0.5) / root;
   * Creates quaternion for Euler angles.
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;
   * @param x Rotation around x axis (in degrees).
      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
   * @param y Rotation around y axis (in degrees).
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
   * @param z Rotation around z axis (in degrees).
    }
  }
   * @return quaternion object representing transformation.
  inline constexpr explicit quaternion(matrix4<T> const &matrix) noexcept __attribute__((__always_inline__)) {
   */
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
  inline static quaternion<T> constexpr from_euler_angles(T x, T y, T z) noexcept __attribute__((__always_inline__)) {
    // article "quaternion Calculus and Fast Animation".
    return quaternion<T>(from_axis_rot(vector3<T>(1, 0, 0), x) *
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
                         from_axis_rot(vector3<T>(0, 1, 0), y) *
    if(trace > 0) {
                         from_axis_rot(vector3<T>(0, 0, 1), z));
      // |w| > 1/2, may as well choose w > 1/2
  }
      T root = std::sqrt(trace + static_cast<T>(1.0));                          // 2w
  inline static quaternion<T> constexpr fromEulerAngles(T x, T y, T z) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles()"))) {
      w = static_cast<T>(0.5) * root;
    return from_euler_angles(x, y, z);
      root = static_cast<T>(0.5) / root;                                        // 1/(4w)
  }
      v.x = (matrix.at(2, 1) - matrix.at(1, 2)) * root;

      v.y = (matrix.at(0, 2) - matrix.at(2, 0)) * root;
  /**
      v.z = (matrix.at(1, 0) - matrix.at(0, 1)) * root;
   * Creates quaternion for Euler angles, rad version.
    } else {
   * @param x Rotation around x axis (in radians).
      // |w| <= 1/2
   * @param y Rotation around y axis (in radians).
      unsigned int constexpr next[3] = {1, 2, 0};

   * @param z Rotation around z axis (in radians).
      unsigned int i = 0;
   * @return quaternion object representing transformation.
      if(matrix.at(1, 1) > matrix.at(0, 0)) {
   */
        i = 1;
  inline static quaternion<T> constexpr from_euler_angles_rad(T x, T y, T z) noexcept __attribute__((__always_inline__)) {
      }
    return quaternion<T>(from_axis_rot_rad(vector3<T>(1, 0, 0), x) *
      if(matrix.at(2, 2) > matrix.at(i, i)) {
                         from_axis_rot_rad(vector3<T>(0, 1, 0), y) *
        i = 2;
      }
                         from_axis_rot_rad(vector3<T>(0, 0, 1), z));
      unsigned int j = next[i];
  }
      unsigned int k = next[j];
  inline static quaternion<T> constexpr fromEulerAngles_rad(T x, T y, T z) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles_rad()"))) {

    return from_euler_angles_rad(x, y, z);
      T root = std::sqrt(matrix.at(i, i) - matrix.at(j, j) - matrix.at(k, k) + static_cast<T>(1.0));
  }
      T *q[3] = {&v.x, &v.y, &v.z};

      *q[i] = static_cast<T>(0.5) * root;
  /**
      root = static_cast<T>(0.5) / root;
   * Creates quaternion as rotation around axis.
      w = (matrix.at(k, j) - matrix.at(j, k)) * root;
   * @param axis Unit vector expressing axis of rotation.
      *q[j] = (matrix.at(j, i) + matrix.at(i, j)) * root;
   * @param angleDeg Angle of rotation around axis (in degrees).
      *q[k] = (matrix.at(k, i) + matrix.at(i, k)) * root;
   */
    }
  inline static quaternion<T> constexpr from_axis_rot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) {
  }

    return from_axis_rot_rad(axis, deg2rad(angleDeg));
  //----------------[ assignment ]-------------------------
  }
  /**
  inline static quaternion<T> constexpr fromAxisRot(vector3<T> const &axis, T angleDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot()"))) {
   * Sets to (w_ + xi + yj + zk).
    return from_axis_rot(axis, angleDeg);
   * @param w_ Real part of quaternion.
  }
   * @param x Complex coefficient for i complex constant.

   * @param y Complex coefficient for j complex constant.
  /**
   * @param z Complex coefficient for k complex constant.
   * Creates quaternion as rotation around axis, rad version.
   */
   * @param axis Unit vector expressing axis of rotation.
  inline void constexpr assign(T w_ = 0, T x = 0, T y = 0, T z = 0) noexcept __attribute__((__always_inline__)) {
   * @param angleDeg Angle of rotation around axis (in radians).
    w = w_;
   */
    v.assign(x, y, z);
  inline static quaternion<T> constexpr from_axis_rot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) {
  }

    T temp_sin = static_cast<T>(0);
  /**
    T temp_cos = static_cast<T>(0);
   * Copy operator
    sincos_any(angleRad / static_cast<T>(2.0), temp_sin, temp_cos);
   * @param rhs Right hand side argument of binary operator.
    return quaternion<T>(temp_cos, axis * temp_sin);
   */
  }
  inline quaternion<T> constexpr &operator=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline static quaternion<T> constexpr fromAxisRot_rad(vector3<T> const &axis, T angleRad) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot_rad()"))) {
    v = rhs.v;
    return from_axis_rot_rad(axis, angleRad);
    w = rhs.w;
  }
    return *this;

  }
  /**

   * Converts this quaternion to an axis and angle combination
  /**
   * @param angle The angle of rotation
   * Copy convert operator
   * @param axis The axis around which the rotation is
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline void constexpr to_angle_axis(T &angle, vector3<T> &axis) const noexcept __attribute__((__always_inline__)) {
  inline quaternion<T> constexpr &operator=(quaternion<FromT> const &rhs) noexcept {
    T const squareLength = v.length_sq();
    v = rhs.v;
    if(squareLength != 0) {
    w = static_cast<T>(rhs.w);
      angle = static_cast<T>(2) * std::acos(w);
    return *this;
      axis = v / std::pow(squareLength, static_cast<T>(0.5));
  }
    } else {

      angle = static_cast<T>(0);
  /**
      axis.assign(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
   * Move assignment operator
    }
   * @param rhs Right hand side argument of binary operator.
  }
   */
  inline void constexpr toAngleAxis(T &angle, vector3<T> &axis) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_angle_axis()"))) {
  inline quaternion<T> constexpr &operator=(quaternion<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    to_angle_axis(angle, axis);
    v = std::move(rhs.v);
  }
    w = std::move(rhs.w);

    return *this;
  }
  /**

   * Converts quaternion into rotation matrix.
  /**
   * @return Rotation matrix expressing this quaternion.
   * Move assignment convert operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr rotmatrix() const noexcept __attribute__((__always_inline__)) {
   */
    return matrix3<T>(static_cast<T>(1) - static_cast<T>(2) * (v.y * v.y + v.z * v.z),
  template<typename FromT> __attribute__((__always_inline__))
                      static_cast<T>(2)                     * (v.x * v.y + v.z * w),
  inline quaternion<T> constexpr &operator=(quaternion<FromT> &&rhs) noexcept {
                      static_cast<T>(2)                     * (v.x * v.z - v.y * w),
    v = std::move(rhs.v);

    w = static_cast<T>(std::move(rhs.w));
                      static_cast<T>(2)                     * (v.x * v.y - v.z * w),
    return *this;
  }
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.z * v.z),

                      static_cast<T>(2)                     * (v.y * v.z + v.x * w),
  /**

   * Addition operator
                      static_cast<T>(2)                     * (v.x * v.z + v.y * w),
   * @param rhs Right hand side argument of binary operator.
                      static_cast<T>(2)                     * (v.y * v.z - v.x * w),
   */
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.y * v.y));
  inline quaternion<T> constexpr operator+(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return quaternion<T>(w + rhs.w, v + rhs.v);

  }
  /**

   * Converts quaternion into transformation matrix.
  /**
   * @note This method performs same operation as rotmatrix()
   * Multiplication operator
   * conversion method. But returns matrix of 4x4 elements.
   * @param rhs Right hand side argument of binary operator.
   */
   * @return Transformation matrix expressing this quaternion.
  inline quaternion<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return quaternion<T>(w * rhs.w   - v.x * rhs.v.x - v.y * rhs.v.y - v.z * rhs.v.z,
  inline matrix4<T> constexpr transform() const noexcept __attribute__((__always_inline__)) {
                         w * rhs.v.x + v.x * rhs.w   + v.y * rhs.v.z - v.z * rhs.v.y,
    return matrix4<T>(static_cast<T>(1) - static_cast<T>(2) * (v.y * v.y + v.z * v.z),
                         w * rhs.v.y - v.x * rhs.v.z + v.y * rhs.w   + v.z * rhs.v.x,
                      static_cast<T>(2)                     * (v.x * v.y + v.z * w),
                         w * rhs.v.z + v.x * rhs.v.y - v.y * rhs.v.x + v.z * rhs.w);
                      static_cast<T>(2)                     * (v.x * v.z - v.y * w),
  }
                      static_cast<T>(0),


  /**
                      static_cast<T>(2)                     * (v.x * v.y - v.z * w),
   * Multiplication operator
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.z * v.z),
   * @param rhs Right hand side argument of binary operator.
                      static_cast<T>(2)                     * (v.y * v.z + v.x * w),
   */
                      static_cast<T>(0),
  inline quaternion<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {

    return quaternion<T>(w * rhs, v * rhs);
  }
                      static_cast<T>(2)                     * (v.x * v.z + v.y * w),

                      static_cast<T>(2)                     * (v.y * v.z - v.x * w),
  /**
                      static_cast<T>(1) - static_cast<T>(2) * (v.x * v.x + v.y * v.y),
   * Division operator
                      static_cast<T>(0),
   * @param rhs Right hand side argument of binary operator.

   */
                      static_cast<T>(0),
  inline quaternion<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0),
    return quaternion<T>(w / rhs, v / rhs);
                      static_cast<T>(0),
  }

                      static_cast<T>(1));
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Linear interpolation of two quaternions
  inline quaternion<T> constexpr operator-(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param fact Factor of interpolation. For translation from position
    return quaternion<T>(w - rhs.w, v - rhs.v);
   * of this vector to quaternion rhs, values of factor goes from 0.0 to 1.0.
  }
   * @param rhs Second quaternion for interpolation

   * @note However values of fact parameter are reasonable only in interval
  /**
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * Addition operator
   * can get result (extrapolation?)
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline quaternion<T> constexpr lerp(T fact, quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline quaternion<T> constexpr &operator+=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    w += rhs.w;
    return quaternion<T>((1 - fact) * w + fact * rhs.w, v.lerp(fact, rhs.v));
    v += rhs.v;
  }
    return *this;

  }
  /**

   * Computes spherical interpolation between quaternions (this, q2)
  /**
   * using coefficient of interpolation r (in [0, 1]).
   * Subtraction operator
   *
   * @param rhs Right hand side argument of binary operator.
   * @param r The ratio of interpolation form this (r = 0) to q2 (r = 1).
   */
   * @param q2 Second quaternion for interpolation.
  inline quaternion<T> constexpr &operator-=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @return Result of interpolation.
    w -= rhs.w;
   */
    v -= rhs.v;
    return *this;
  inline quaternion<T> constexpr slerp(T r, quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    T cos_theta = std::max(std::min(dot(rhs), static_cast<T>(1)), static_cast<T>(-1)); // clamp the dot product, as it can sometimes exceed 1.0 and cause acos to return NaN

    quaternion<T> rhs_temp(rhs);
  /**
    if(cos_theta < static_cast<T>(0)) {                                         // dot(lhs, rhs) must be positive for smooth interpolation around poles; if not, flip rhs
   * Multiplication operator
      cos_theta = -cos_theta;
   * @param rhs Right hand side argument of binary operator.
      rhs_temp = -rhs_temp;
   */
    }
  inline quaternion<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    T const theta = static_cast<T>(std::acos(cos_theta));
    quaternion q = (*this) * rhs;
    if(std::abs(theta) <= epsilon<T>) {
    v = q.v;
      return quaternion<T>{*this};
    w = q.w;
    } else {
    return *this;
  }
      T const sin_theta = static_cast<T>(std::sqrt(static_cast<T>(1) - cos_theta * cos_theta));

      //if(std::abs(sin_theta) <= epsilon<T>) {
  /**
      if(sin_theta == static_cast<T>(0)) {                                      // we only need to avoid division by zero, no need to check for epsilon
   * Multiplication operator
        // this point may only be reached extremely rarely?
   * @param rhs Right hand side argument of binary operator.
        return quaternion<T>{static_cast<T>(0.5) * w + static_cast<T>(0.5) * rhs_temp.w, v.lerp(static_cast<T>(0.5), rhs_temp.v)};
   */
      } else {
  inline quaternion<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
        T const temp_a = static_cast<T>(std::sin((static_cast<T>(1) - r) * theta)) / sin_theta;
    w *= rhs;
        T const temp_b = static_cast<T>(std::sin(r * theta)) / sin_theta;
    v *= rhs;
    return *this;
        return quaternion<T>{(w * temp_a) + (rhs_temp.w * temp_b),
  }
                             (v * temp_a) + (rhs_temp.v * temp_b)};

      }
  /**
    }
   * Division operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline quaternion<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
   * Provides output to standard output stream.
    w /= rhs;
   */
    v /= rhs;
  inline friend std::ostream &operator <<(std::ostream &oss, quaternion<T> const &q) noexcept __attribute__((__always_inline__)) {
    return *this;
    oss << "Re: " << q.w << " Im: " << q.v;
  }

    return oss;
  /**
  }
   * Equality test operator

   * @param rhs Right hand side argument of binary operator.
  /**
   * @note Test of equality is based of threshold epsilon value. To be two
   * Gets string representation.
   * values equal, must satisfy this condition | lhs - rhs | < epsilon,
   */
   * for all quaternion coordinates.
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
   */
    std::ostringstream oss;
  inline bool constexpr operator==(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    oss << *this;
    #ifdef VMATH_SOFT_COMPARE
    return oss.str();
      return (std::abs(w - rhs.w) < epsilon<T>) && v == rhs.v;
  }
    #else
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
      return w == rhs.w && v == rhs.v;
    return to_string();
    #endif // VMATH_SOFT_COMPARE
  }
  }


  /**
  /**
   * Creates quaternion from transform matrix.
   * Inequality test operator
   *
   * @param rhs Right hand side argument of binary operator.
   * @param m Transform matrix used to compute quaternion.
   * @return not (lhs == rhs) :-P
   */
   * @return quaternion representing rotation of matrix m.
  inline bool constexpr operator!=(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return !(*this == rhs);
  // matrix4 is convertible to matrix3 so the below is not useful
  }
  /*
  /**
  inline static quaternion<T> constexpr from_matrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) {
   * Dot product of two quaternions.
    return from_matrix(m.get_rotation());
   * @param rhs Right hand side argument of binary operator.
  }
   */
  inline T constexpr dot(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline static quaternion<T> constexpr fromMatrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
    return (w * rhs.w) + v.dot(rhs.v);
    return from_matrix(m);
  }
  }

  */
  //-------------[ unary operations ]--------------------------

  /**
  /**
   * Unary negate operator
   * Creates quaternion from rotation matrix.
   * @return negated quaternion
   *
   */
   * @param m Rotation matrix used to compute quaternion.
  inline quaternion<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
   * @return quaternion representing rotation of matrix m.
    return quaternion<T>(-w, -v);
   */
  }

  inline static quaternion<T> constexpr from_matrix(matrix3<T> const &mat) noexcept __attribute__((__always_inline__)) {
  /**
    T const tr = mat(1, 1) + mat(2, 2) + mat(3, 3);
   * Unary conjugate operator
    if(tr >= epsilon<T>) {
   * @return conjugated quaternion
      T const s = static_cast<T>(0.5) / static_cast<T>(std::sqrt(tr + static_cast<T>(1.0)));
   */
      return quaternion<T>(static_cast<T>(0.25)    / s,
  inline quaternion<T> constexpr operator~() const noexcept __attribute__((__always_inline__)) {
                           (mat(3, 2) - mat(2, 3)) * s,
    return quaternion<T>(w, -v);
                           (mat(1, 3) - mat(3, 1)) * s,
  }
                           (mat(2, 1) - mat(1, 2)) * s);

    } else {
  /**
      if(mat(1, 1) > mat(2, 2)) {
   * Get length of quaternion.
        if(mat(1, 1) > mat(3, 3)) {
   * @return Length of quaternion.
          T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + mat(1, 1) - mat(2, 2) - mat(3, 3)));
   */
          return quaternion<T>((mat(3, 2) - mat(2, 3)) / s,
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
                               static_cast<T>(0.25)    * s,
    return static_cast<T>(std::sqrt(length_sq()));
  }
                               (mat(1, 2) + mat(2, 1)) / s,
  /**
                               (mat(1, 3) + mat(3, 1)) / s);
   * Get length of quaternion, fast approximation.
        }
   * @return Length of quaternion.
      } else {
   */
        if(mat(2, 2) > mat(3, 3)) {
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) {
          T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + mat(2, 2) - mat(1, 1) - mat(3, 3)));
    return static_cast<T>(sqrt_fast(length_sq()));
          return quaternion<T>((mat(1, 3) - mat(3, 1)) / s,
  }
                               (mat(1, 2) + mat(2, 1)) / s,
  /**
                               static_cast<T>(0.25)    * s,
   * Get length of quaternion, rougher fast approximation.
                               (mat(2, 3) + mat(3, 2)) / s);
   * @return Length of quaternion.
        }
   */
      }
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) {
    return static_cast<T>(sqrt_faster(length_sq()));
      T const s = static_cast<T>(2.0) * static_cast<T>(std::sqrt(static_cast<T>(1.0) + mat(3, 3) - mat(1, 1) - mat(2, 2)));
  }
      return quaternion<T>((mat(2, 1) - mat(1, 2)) / s,

                           (mat(1, 3) + mat(3, 1)) / s,
  /**
                           (mat(2, 3) + mat(3, 2)) / s,
   * Return square of length.
                           static_cast<T>(0.25)    * s);
   * @return length ^ 2
    }
   * @note This method is faster then length(). For comparison
  }
   * of length of two quaternion can be used just this value, instead
  inline static quaternion<T> constexpr fromMatrix(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
   * of more expensive length() method.
    return from_matrix(m);
   */
  }
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
};
    return w * w + v.length_sq();

  }
#ifdef VMATH_NAMESPACE
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
}
    return length_sq();
#endif //VMATH_NAMESPACE
  }


  /**
#include "quat_types.h"
   * normalise quaternion

   */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
//
    T const len = length();
// Standard C++ library extensions
    w /= len;
//
    v /= len;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }

  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
#ifndef VMATH_NO_BOOST
    T const len = length_fast();
namespace std {
    w /= len;

    v /= len;
/**
  }
 * Gets a hash value taking account of all dimensions of this quaternion, for use
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
 * in standard container maps etc.
    T const len = length_faster();
    w /= len;
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
    v /= len;
 * @return Hash value
  }
 */
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
template<typename T>
    normalise();
struct hash<quaternion<T>> {
  }
  size_t operator()(const quaternion<T> &value) const {
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    size_t hashvalue = 0;
    normalise_fast();
    boost::hash_combine(hashvalue, value.v.x);
  }
    boost::hash_combine(hashvalue, value.v.y);
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    boost::hash_combine(hashvalue, value.v.z);
    normalise_faster();
    boost::hash_combine(hashvalue, value.w);
  }
    return hashvalue;
  inline quaternion<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
  }
    T const len(length());
};
    return {w / len, v / len};

  }
}
  inline quaternion<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {

    T const len(length_fast());
/**
    return {w / len, v / len};
 * Gets a hash value taking account of all dimensions of this quaternion, for use
  }
 * in standard container maps etc.
  inline quaternion<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
    T const len(length_faster());
 * @return Hash value
    return {w / len, v / len};
 */
  }
template<typename T>
  inline quaternion<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
size_t hash_value(quaternion<T> const &value) {
    return normalise_copy();
  }
  size_t hashvalue = 0;
  inline quaternion<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  boost::hash_combine(hashvalue, value.v.x);
    return normalise_copy_fast();
  boost::hash_combine(hashvalue, value.v.y);
  }
  boost::hash_combine(hashvalue, value.v.z);
  inline quaternion<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  boost::hash_combine(hashvalue, value.w);
    return normalise_copy_faster();
  return hashvalue;
  }
}

#endif // VMATH_NO_BOOST
  inline void constexpr conjugate() noexcept __attribute__((__always_inline__)) {

    v = -v;
#endif // VECTORSTORM_QUAT_H_INCLUDED
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
  inline void constexpr toAngleAxis(T &angle, vector3<T> &axis) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_angle_axis()"))) {
    to_angle_axis(angle, axis);
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
   * using coefficient of interpolation r (in [0, 1]).
   *
   * @param r The ratio of interpolation form this (r = 0) to q2 (r = 1).
   * @param q2 Second quaternion for interpolation.
   * @return Result of interpolation.
   */
  inline quaternion<T> constexpr slerp(T r, quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    T cos_theta = std::max(std::min(dot(rhs), static_cast<T>(1)), static_cast<T>(-1)); // clamp the dot product, as it can sometimes exceed 1.0 and cause acos to return NaN
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
      if(sin_theta == static_cast<T>(0)) {                                      // we only need to avoid division by zero, no need to check for epsilon
        // this point may only be reached extremely rarely?
        return quaternion<T>{static_cast<T>(0.5) * w + static_cast<T>(0.5) * rhs_temp.w, v.lerp(static_cast<T>(0.5), rhs_temp.v)};
      } else {
        T const temp_a = static_cast<T>(std::sin((static_cast<T>(1) - r) * theta)) / sin_theta;
        T const temp_b = static_cast<T>(std::sin(r * theta)) / sin_theta;
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
  // matrix4 is convertible to matrix3 so the below is not useful
  /*
  inline static quaternion<T> constexpr from_matrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) {
    return from_matrix(m.get_rotation());
  }
  inline static quaternion<T> constexpr fromMatrix(matrix4<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
    return from_matrix(m);
  }
  */

  /**
   * Creates quaternion from rotation matrix.
   *
   * @param m Rotation matrix used to compute quaternion.
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
  inline static quaternion<T> constexpr fromMatrix(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
    return from_matrix(m);
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "quat_types.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Standard C++ library extensions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VMATH_NO_BOOST
namespace std {

/**
 * Gets a hash value taking account of all dimensions of this quaternion, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
struct hash<quaternion<T>> {
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
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_QUAT_H_INCLUDED
