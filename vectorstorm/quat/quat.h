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
   * quaternion constructor, sets quaternion to (0 + 0i + 0j + 0k).
   */
  inline constexpr quaternion() __attribute__((__always_inline__))
    : w(0),
      v(0, 0, 0) {
  }

  /**
   * Copy constructor.
   */
  inline constexpr explicit quaternion(quaternion<T> const &q) __attribute__((__always_inline__))
    : w(q.w),
      v(q.v) {
  }

  /**
   * Copy casting constructor.
   */
  template<typename FromT>  __attribute__((__always_inline__))
  inline constexpr explicit quaternion(quaternion<FromT> const &q)
    : w(static_cast<T>(q.w)),
      v(q.v) {
  }

  /**
   * Move constructor.
   */
  inline constexpr quaternion(quaternion<T> &&q) __attribute__((__always_inline__))
    : w(std::move(q.w)),
      v(std::move(q.v)) {
  }

  /**
   * Move casting constructor.
   */
  template<typename FromT>  __attribute__((__always_inline__))
  inline constexpr quaternion(quaternion<FromT> &&q)
    : w(static_cast<T>(std::move(q.w))),
      v(std::move(q.v)) {
  }

  /**
   * Creates quaternion object from real part w_ and complex part v_.
   * @param w_ Real part of quaternion.
   * @param v_ Complex part of quaternion (xi + yj + zk).
   */
  inline constexpr quaternion(T w_, vector3<T> const &v_) __attribute__((__always_inline__))
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
  inline constexpr quaternion(T w_, T x, T y, T z) __attribute__((__always_inline__))
    : w(w_), v(x, y, z) {
  }

  /**
   * Construct quaternion from rotation matrix.
   * @return Rotation matrix expressing this quaternion.
   */
  inline constexpr explicit quaternion(matrix3<T> const &matrix) __attribute__((__always_inline__)) {
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
    // article "quaternion Calculus and Fast Animation".
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
    if(trace > 0) {
      // |w| > 1/2, may as well choose w > 1/2
      T root = std::sqrt(trace + static_cast<T>(1.0));  // 2w
      w = static_cast<T>(0.5) * root;
      root = static_cast<T>(0.5) / root;  // 1/(4w)
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
  inline constexpr explicit quaternion(matrix4<T> const &matrix) __attribute__((__always_inline__)) {
    // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
    // article "quaternion Calculus and Fast Animation".
    T const trace = matrix.at(0, 0) + matrix.at(1, 1) + matrix.at(2, 2);
    if(trace > 0) {
      // |w| > 1/2, may as well choose w > 1/2
      T root = std::sqrt(trace + static_cast<T>(1.0));  // 2w
      w = static_cast<T>(0.5) * root;
      root = static_cast<T>(0.5) / root;  // 1/(4w)
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
  inline void constexpr assign(T w_ = 0, T x = 0, T y = 0, T z = 0) __attribute__((__always_inline__)) {
    w = w_;
    v.assign(x, y, z);
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator=(quaternion<T> const &rhs) __attribute__((__always_inline__)) {
    v = rhs.v;
    w = rhs.w;
    return *this;
  }

  /**
   * Copy convert operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline quaternion<T> constexpr &operator=(quaternion<FromT> const &rhs) {
    v = rhs.v;
    w = static_cast<T>(rhs.w);
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator=(quaternion<T> &&rhs) __attribute__((__always_inline__)) {
    v = std::move(rhs.v);
    w = std::move(rhs.w);
    return *this;
  }

  /**
   * Move assignment convert operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline quaternion<T> constexpr &operator=(quaternion<FromT> &&rhs) {
    v = std::move(rhs.v);
    w = static_cast<T>(std::move(rhs.w));
    return *this;
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator+(quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    return quaternion<T>(w + rhs.w, v + rhs.v);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator*(quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    return quaternion<T>(w * rhs.w   - v.x * rhs.v.x - v.y * rhs.v.y - v.z * rhs.v.z,
                         w * rhs.v.x + v.x * rhs.w   + v.y * rhs.v.z - v.z * rhs.v.y,
                         w * rhs.v.y - v.x * rhs.v.z + v.y * rhs.w   + v.z * rhs.v.x,
                         w * rhs.v.z + v.x * rhs.v.y - v.y * rhs.v.x + v.z * rhs.w);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator*(T rhs) const __attribute__((__always_inline__)) {
    return quaternion<T>(w * rhs, v * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator/(T rhs) const __attribute__((__always_inline__)) {
    return quaternion<T>(w / rhs, v / rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr operator-(quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    return quaternion<T>(w - rhs.w, v - rhs.v);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator+=(quaternion<T> const &rhs) __attribute__((__always_inline__)) {
    w += rhs.w;
    v += rhs.v;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator-=(quaternion<T> const &rhs) __attribute__((__always_inline__)) {
    w -= rhs.w;
    v -= rhs.v;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator*=(quaternion<T> const &rhs) __attribute__((__always_inline__)) {
    quaternion q = (*this) * rhs;
    v = q.v;
    w = q.w;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator*=(T rhs) __attribute__((__always_inline__)) {
    w *= rhs;
    v *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline quaternion<T> constexpr &operator/=(T rhs) __attribute__((__always_inline__)) {
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
  inline bool constexpr operator==(quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return (std::abs(w - rhs.w) < static_cast<T>(epsilon)) && v == rhs.v;
    #else
      return w == rhs.w && v == rhs.v;
    #endif // VMATH_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated quaternion
   */
  inline quaternion<T> constexpr operator-() const __attribute__((__always_inline__)) {
    return quaternion<T>(-w, -v);
  }

  /**
   * Unary conjugate operator
   * @return conjugated quaternion
   */
  inline quaternion<T> constexpr operator~() const __attribute__((__always_inline__)) {
    return quaternion<T>(w, -v);
  }

  /**
   * Get length of quaternion.
   * @return Length of quaternion.
   */
  inline T constexpr length() const __attribute__((__always_inline__)) {
    return static_cast<T>(std::sqrt(length_sq()));
  }
  /**
   * Get length of quaternion, fast approximation.
   * @return Length of quaternion.
   */
  inline T constexpr length_fast() const __attribute__((__always_inline__)) {
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  /**
   * Get length of quaternion, rougher fast approximation.
   * @return Length of quaternion.
   */
  inline T constexpr length_faster() const __attribute__((__always_inline__)) {
    return static_cast<T>(sqrt_faster(length_sq()));
  }

  /**
   * Return square of length.
   * @return length ^ 2
   * @note This method is faster then length(). For comparison
   * of length of two quaternion can be used just this value, instead
   * of more expensive length() method.
   */
  inline T constexpr length_sq() const __attribute__((__always_inline__)) {
    return w * w + v.length_sq();
  }
  inline T constexpr lengthSq() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
    return length_sq();
  }

  /**
   * normalise quaternion
   */
  inline void constexpr normalise() __attribute__((__always_inline__)) {
    T len = length();
    w /= len;
    v /= len;
  }
  inline void constexpr normalise_fast() __attribute__((__always_inline__)) {
    T len = length_fast();
    w /= len;
    v /= len;
  }
  inline void constexpr normalise_faster() __attribute__((__always_inline__)) {
    T len = length_faster();
    w /= len;
    v /= len;
  }
  inline void constexpr normalize() __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise();
  }
  inline void constexpr normalize_fast() __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_fast();
  }
  inline void constexpr normalize_faster() __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_faster();
  }
  inline quaternion<T> constexpr normalise_copy() const __attribute__((__always_inline__)) {
    T const temp(length());
    return quaternion<T>(w / temp, v / temp);
  }
  inline quaternion<T> constexpr normalise_copy_fast() const __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return quaternion<T>(w / temp, v / temp);
  }
  inline quaternion<T> constexpr normalise_copy_faster() const __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return quaternion<T>(w / temp, v / temp);
  }
  inline quaternion<T> constexpr normalize_copy() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline quaternion<T> constexpr normalize_copy_fast() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline quaternion<T> constexpr normalize_copy_faster() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_faster();
  }

  inline void constexpr conjugate() __attribute__((__always_inline__)) {
    v = -v;
  }

  inline quaternion<T> constexpr conjugate_copy() const __attribute__((__always_inline__)) {
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
  inline void constexpr invert() __attribute__((__always_inline__)) {
    T l = length();
    conjugate();
    (*this) /= l;
  }

  inline quaternion<T> constexpr invert_copy() const __attribute__((__always_inline__)) {
    return conjugate_copy() / length();
  }

  /**
   * Creates quaternion for Euler angles.
   * @param x Rotation around x axis (in degrees).
   * @param y Rotation around y axis (in degrees).
   * @param z Rotation around z axis (in degrees).
   * @return quaternion object representing transformation.
   */
  inline static quaternion<T> constexpr from_euler_angles(T x, T y, T z) __attribute__((__always_inline__)) {
    return quaternion<T>(from_axis_rot(vector3<T>(1, 0, 0), x) *
                         from_axis_rot(vector3<T>(0, 1, 0), y) *
                         from_axis_rot(vector3<T>(0, 0, 1), z));
  }
  inline static quaternion<T> constexpr fromEulerAngles(T x, T y, T z) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles()"))) {
    return from_euler_angles(x, y, z);
  }

  /**
   * Creates quaternion for Euler angles, rad version.
   * @param x Rotation around x axis (in radians).
   * @param y Rotation around y axis (in radians).
   * @param z Rotation around z axis (in radians).
   * @return quaternion object representing transformation.
   */
  inline static quaternion<T> constexpr from_euler_angles_rad(T x, T y, T z) __attribute__((__always_inline__)) {
    return quaternion<T>(from_axis_rot_rad(vector3<T>(1, 0, 0), x) *
                         from_axis_rot_rad(vector3<T>(0, 1, 0), y) *
                         from_axis_rot_rad(vector3<T>(0, 0, 1), z));
  }
  inline static quaternion<T> constexpr fromEulerAngles_rad(T x, T y, T z) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_euler_angles_rad()"))) {
    return from_euler_angles_rad(x, y, z);
  }

  /**
   * Creates quaternion as rotation around axis.
   * @param axis Unit vector expressing axis of rotation.
   * @param angleDeg Angle of rotation around axis (in degrees).
   */
  inline static quaternion<T> constexpr from_axis_rot(vector3<T> const &axis, T angleDeg) __attribute__((__always_inline__)) {
    return from_axis_rot_rad(axis, deg2rad(angleDeg));
  }
  inline static quaternion<T> constexpr fromAxisRot(vector3<T> const &axis, T angleDeg) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot()"))) {
    return from_axis_rot(axis, angleDeg);
  }

  /**
   * Creates quaternion as rotation around axis, rad version.
   * @param axis Unit vector expressing axis of rotation.
   * @param angleDeg Angle of rotation around axis (in radians).
   */
  inline static quaternion<T> constexpr from_axis_rot_rad(vector3<T> const &axis, T angleRad) __attribute__((__always_inline__)) {
    T temp_sin = static_cast<T>(0);
    T temp_cos = static_cast<T>(0);
    sincos_any(angleRad / static_cast<T>(2.0), temp_sin, temp_cos);
    return quaternion<T>(temp_cos, axis * temp_sin);
  }
  inline static quaternion<T> constexpr fromAxisRot_rad(vector3<T> const &axis, T angleRad) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_axis_rot_rad()"))) {
    return from_axis_rot_rad(axis, angleRad);
  }

  /**
   * Converts this quaternion to an axis and angle combination
   * @param angle The angle of rotation
   * @param axis The axis around which the rotation is
   */
  inline void constexpr to_angle_axis(T &angle, vector3<T> &axis) __attribute__((__always_inline__)) {
    T const squareLength = v.length_sq();
    if(squareLength != 0) {
      angle = static_cast<T>(2.0) * std::acos(w);
      axis = v / std::pow(squareLength, static_cast<T>(0.5));
    } else {
      angle = static_cast<T>(0.0);
      axis.assign(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0));
    }
  }
  inline void constexpr toAngleAxis(T &angle, vector3<T> &axis) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_angle_axis()"))) {
    to_angle_axis(angle, axis);
  }

  /**
   * Converts quaternion into rotation matrix.
   * @return Rotation matrix expressing this quaternion.
   */
  inline matrix3<T> constexpr rotmatrix() __attribute__((__always_inline__)) {
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
  inline matrix4<T> constexpr transform() const __attribute__((__always_inline__)) {
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
  inline quaternion<T> constexpr lerp(T fact, quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    return quaternion<T>((1 - fact) * w + fact * rhs.w, v.lerp(fact, rhs.v));
  }

  /**
   * Provides output to standard output stream.
   */
  inline friend std::ostream &operator <<(std::ostream &oss, quaternion<T> const &q) __attribute__((__always_inline__)) {
    oss << "Re: " << q.w << " Im: " << q.v;
    return oss;
  }

  /**
   * Gets string representation.
   */
  inline std::string constexpr to_string() const __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }
  inline std::string constexpr toString() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
    return to_string();
  }

  /**
   * Creates quaternion from transform matrix.
   *
   * @param m Transform matrix used to compute quaternion.
   * @return quaternion representing rotation of matrix m.
   */
  // 2011-07-02: Davide Bacchet: changed formula to fix degenerate cases
  inline static quaternion<T> constexpr from_matrix(matrix4<T> const &m) __attribute__((__always_inline__)) {
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
  inline static quaternion<T> constexpr frommatrix(matrix4<T> const &m) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
    return from_matrix(m);
  }

  /**
   * Creates quaternion from rotation matrix.
   *
   * @param m Rotation matrix used to compute quaternion.
   * @return quaternion representing rotation of matrix m.
   */
  // 2011-07-02: Davide Bacchet: changed formula to fix degenerate cases
  inline static quaternion<T> constexpr from_matrix(matrix3<T> const &m) __attribute__((__always_inline__)) {
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
  inline static quaternion<T> constexpr frommatrix(matrix3<T> const &m) __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_matrix()"))) {
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
  inline quaternion<T> constexpr slerp(T r, quaternion<T> const &q2) const __attribute__((__always_inline__)) {
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
