#ifndef VECTORSTORM_VECTOR3_H_INCLUDED
#define VECTORSTORM_VECTOR3_H_INCLUDED

#include <cmath>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
#include "vector2_forward.h"
#include "vector4_forward.h"
#include "vectorstorm/quat/quat_forward.h"
#include "vectorstorm/matrix/matrix3_forward.h"
#include "vectorstorm/matrix/matrix4_forward.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/**
 * Class for three dimensional vector.
 * There are four ways of accessing vector components.
 * Let's have <code>vector3f v</code>, you can either:
 * <ul>
 *  <li>access as position (x,y,z) &mdash; <code>v.x = v.y = v.z = 1;</code></li>
 *  <li>access as texture coordinate (s,t,u) &mdash; <code>v.s = v.t = v.u = 1;</code></li>
 *  <li>access as colour (r,g,b) &mdash; <code>v.r = v.g = v.b = 1;</code></li>
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = 1;</code></li>
 * </ul>
 */
template<typename T>
class vector3 {
public:
  union {
    /**
     * First element of vector, alias for X-coordinate.
     */
    T x;

    /**
     * First element of vector, alias for S-coordinate.
     * For textures notation.
     */
    T s;

    /**
     * First element of vector, alias for R-coordinate.
     * For colour notation.
     */
    T r;
  };

  union {
    /**
     * Second element of vector, alias for Y-coordinate.
     */
    T y;

    /**
     * Second element of vector, alias for T-coordinate.
     * For textures notation.
     */
    T t;

    /**
     * Second element of vector, alias for G-coordinate.
     * For colour notation.
     */
    T g;
  };

  union {
    /**
     * Third element of vector, alias for Z-coordinate.
     */
    T z;

    /**
     * Third element of vector, alias for U-coordinate.
     * For textures notation.
     */
    T u;

    /**
     * Third element of vector, alias for B-coordinate.
     * For colour notation.
     */
    T b;
  };

  //----------------[ constructors ]--------------------------
  /**
   * Creates and sets to (0,0,0)
   */
  inline constexpr vector3() __attribute__((__always_inline__))
    : x(0),
      y(0),
      z(0) {
  }

  /**
   * Creates and sets to (x,y,z)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   * @param nz initial z-coordinate value
   */
  inline constexpr vector3(T nx, T ny, T nz) __attribute__((__always_inline__))
    : x(nx),
      y(ny),
      z(nz) {
  }

  /**
   * Copy constructor.
   * @param src Source of data for new created vector3 instance.
   */
  inline constexpr explicit vector3(vector3<T> const &src) __attribute__((__always_inline__))
    : x(src.x),
      y(src.y),
      z(src.z) {
  }

  /**
   * Copy casting constructor.
   * @param src Source of data for new created vector3 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector3(vector3<FromT> const &src)
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)) {
  }

  inline constexpr vector3(vector2<T> const &src, T new_z) __attribute__((__always_inline__))
    : x(src.x),
      y(src.y),
      z(new_z) {
  }

  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector3(vector2<FromT> const &src, FromT new_z)
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)), z(static_cast<T>(new_z)) {
  }

  /**
   * Move constructor.
   * @param src Source of data for new created vector3 instance.
   */
  inline constexpr vector3(vector3<T> &&src) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
      y(std::move(src.y)),
      z(std::move(src.z)) {
  }

  /**
   * Move casting constructor.
   * @param src Source of data for new created vector3 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector3(vector3<FromT> &&src) noexcept
    : x(static_cast<T>(std::move(src.x))),
      y(static_cast<T>(std::move(src.y))),
      z(static_cast<T>(std::move(src.z))) {
  }

  inline constexpr vector3(vector2<T> &&src, T new_z) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
      y(std::move(src.y)),
      z(std::move(new_z)) {
  }

  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector3(vector2<FromT> &&src, FromT new_z) noexcept
    : x(static_cast<T>(std::move(src.x))),
      y(static_cast<T>(std::move(src.y))),
      z(static_cast<T>(std::move(new_z))) {
  }

  //----------------[ assignment ]-------------------------
  /**
   * Sets to (x,y,z)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   * @param nz initial z-coordinate value
   */
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0) __attribute__((__always_inline__)) {
    x = nx;
    y = ny;
    z = nz;
  }

  //----------------[ access operators ]-------------------
  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector3<T> const &rhs) __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
  }

  /**
   * Copy casting operator.
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr &operator=(vector3<FromT> const &rhs) {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    return *this;
  }

  /**
   * Copy operator to vector3 from vector4
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector4<T> const &rhs) __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
  }

  /**
   * Copy casting operator to vector3 from vector4
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr &operator=(vector4<FromT> const &rhs) {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector3<T> &&rhs) __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    return *this;
  }

  /**
   * Move assignment casting operator.
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr &operator=(vector3<FromT> &&rhs) {
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    return *this;
  }

  /**
   * Move assignment operator to vector3 from vector4
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector4<T> &&rhs) __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    return *this;
  }

  /**
   * Move assignment casting operator to vector3 from vector4
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr &operator=(vector4<FromT> &&rhs) {
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    return *this;
  }

  /**
   * Array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y, else reference to z
   * y coordinate.
   */
  inline T constexpr &operator[](int n) __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : z);
  }

  /**
   * Constant array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y, else reference to z
   * y coordinate.
   */
  inline T constexpr const &operator[](int n) const __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : z);
  }

  //---------------[ vector arithmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator+(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator-(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator/(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator+=(vector3<T> const &rhs) __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator-=(vector3<T> const &rhs) __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(vector3<T> const &rhs) __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator/=(vector3<T> const &rhs) __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }

  /**
   * Addition operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator+(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs.x, y + rhs.y, z);
  }

  /**
   * Subtraction operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator-(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs.x, y - rhs.y, z);
  }

  /**
   * Multiplication operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs.x, y * rhs.y, z);
  }

  /**
   * Division operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator/(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs.x, y / rhs.y, z);
  }

  /**
   * Addition operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator+=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  /**
   * Subtraction operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator-=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  /**
   * Multiplication operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  /**
   * Division operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator/=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  /**
   * Dot product of two vectors.
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr dotProduct(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return x * rhs.x + y * rhs.y + z * rhs.z;
  }

  /**
   * Cross product of two vectors
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr crossProduct(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(y * rhs.z - rhs.y * z, z * rhs.x - rhs.z * x, x * rhs.y - rhs.x * y);
  }

  //--------------[ rotation with quaternions ]-----------------
  // see http://mollyrocket.com/forums/viewtopic.php?t=833&sid=3a84e00a70ccb046cfc87ac39881a3d0
  /**
   * Multiplication by quaternion operator (rotation by quaternion)
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(quaternion<T> const &rhs) const __attribute__((__always_inline__)) {
    return *this + (rhs.v.crossProduct(*this) * static_cast<T>(2) * rhs.w) + rhs.v.crossProduct(rhs.v.crossProduct(*this) * static_cast<T>(2));
  }

  /**
   * Multiplication by quaternion operator (rotation by quaternion)
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(quaternion<T> const &rhs) __attribute__((__always_inline__)) {
    vector3<T> const temp = rhs.v.crossProduct(*this) * static_cast<T>(2);
    *this += (temp * rhs.w) + rhs.v.crossProduct(temp);
    return *this;
  }

  //--------------[ scalar vector operator ]--------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator+(T rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs, y + rhs, z + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator-(T rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs, y - rhs, z - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(T rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs, y * rhs, z * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator/(T rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs, y / rhs, z / rhs);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator+=(T rhs) __attribute__((__always_inline__)) {
    x += rhs;
    y += rhs;
    z += rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator-=(T rhs) __attribute__((__always_inline__)) {
    x -= rhs;
    y -= rhs;
    z -= rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(T rhs) __attribute__((__always_inline__)) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator/=(T rhs) __attribute__((__always_inline__)) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
  }

  //-------------[ matrix operations ]-------------------------

  /**
   * Multiplication by 3x3 matrix operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(matrix3<T> const &rhs) __attribute__((__always_inline__)) {
    *this = rhs * *this;
    return *this;
  }

  /**
   * Multiplication by 4x4 matrix operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(matrix4<T> const &rhs) __attribute__((__always_inline__)) {
    *this = rhs * *this;
    return *this;
  }

  //-------------[ equality operator ]-------------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
   * same for y-coordinate, and z-coordinate.
   */
  inline bool constexpr operator==(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return std::abs(x - rhs.x) < static_cast<T>(epsilon) &&
             std::abs(y - rhs.y) < static_cast<T>(epsilon) &&
             std::abs(z - rhs.z) < static_cast<T>(epsilon);
    #else
      return x == rhs.x &&
             y == rhs.y &&
             z == rhs.z;
    #endif // VMATH_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated vector
   */
  inline vector3<T> constexpr operator-() const __attribute__((__always_inline__)) {
    return vector3<T>(-x, -y, -z);
  }

  //-------------[ size operations ]---------------------------
  /**
   * Return square of length.
   * @return length ^ 2
   * @note This method is faster then length(). For comparison
   * of length of two vector can be used just this value, instead
   * of more expensive length() method.
   */
  inline T constexpr length_sq() const __attribute__((__always_inline__)) {
    return x * x + y * y + z * z;
  }
  inline T constexpr lengthSq() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
    return length_sq();
  }

  /**
   * Get length of vector.
   * @return length of vector
   */
  inline T constexpr length() const __attribute__((__always_inline__)) {
    return static_cast<T>(std::sqrt(length_sq()));
  }
  /**
   * Get length of vector, fast approximation.
   * @return length of vector
   */
  inline T constexpr length_fast() const __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  /**
   * Get length of vector, rougher fast approximation.
   * @return length of vector
   */
  inline T constexpr length_faster() const __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return static_cast<T>(sqrt_faster(length_sq()));
  }

  /**
   * normalise vector
   */
  inline void constexpr normalise() __attribute__((__always_inline__)) {
    T const temp = length();
    x /= temp;
    y /= temp;
    z /= temp;
  }
  inline void constexpr normalise_fast() __attribute__((__always_inline__)) {
    T const temp = length_fast();
    x /= temp;
    y /= temp;
    z /= temp;
  }
  inline void constexpr normalise_faster() __attribute__((__always_inline__)) {
    T const temp = length_faster();
    x /= temp;
    y /= temp;
    z /= temp;
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
  inline vector3<T> constexpr normalise_copy() const __attribute__((__always_inline__)) {
    T const temp(length());
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  inline vector3<T> constexpr normalise_copy_fast() const __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  inline vector3<T> constexpr normalise_copy_faster() const __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  inline vector3<T> constexpr normalize_copy() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline vector3<T> constexpr normalize_copy_fast() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline vector3<T> constexpr normalize_copy_faster() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_faster();
  }
  /**
   * normalise vector. with added zero safety check
   */
  inline void constexpr normalise_safe() __attribute__((__always_inline__)) {
    T const temp = length();
    if(temp == static_cast<T>(0)) {
      x = static_cast<T>(0);
      y = static_cast<T>(0);
      z = static_cast<T>(0);
    } else {
      x /= temp;
      y /= temp;
      z /= temp;
    }
  }
  inline void constexpr normalize_safe() __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_safe();
  }
  inline vector3<T> constexpr normalise_safe_copy() const __attribute__((__always_inline__)) {
    T const temp(length());
    if(temp == static_cast<T>(0)) {
      return vector3<T>();
    } else {
      return vector3<T>(x / temp, y / temp, z / temp);
    }
  }
  inline vector3<T> constexpr normalize_safe_copy() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_safe_copy();
  }

  /**
   * Absolute vector (make all values positive)
   */
  inline void constexpr abs() __attribute__((__always_inline__)) {
    x = std::abs(x);
    y = std::abs(y);
    z = std::abs(z);
  }
  inline vector3<T> constexpr abs_copy() const __attribute__((__always_inline__)) {
    return vector3<T>(std::abs(x), std::abs(y), std::abs(z));
  }

  //-------------[ other operations ]--------------------------
  /**
   * Rotate vector around three axis.
   * @param ax Angle (in degrees) to be rotated around X-axis.
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   * @param az Angle (in degrees) to be rotated around Z-axis.
   */
  inline void constexpr rotate(T ax, T ay, T az) __attribute__((__always_inline__)) {
    rotate_rad(deg2rad(ax), deg2rad(ay), deg2rad(az));
  }
  /**
   * Rotate vector around three axis, radian version.
   * @param ax Angle (in radians) to be rotated around X-axis.
   * @param ay Angle (in radians) to be rotated around Y-axis.
   * @param az Angle (in radians) to be rotated around Z-axis.
   */
  inline void constexpr rotate_rad(T ax, T ay, T az) __attribute__((__always_inline__)) {
    T cos_x = static_cast<T>(0);
    T sin_x = static_cast<T>(0);
    T cos_y = static_cast<T>(0);
    T sin_y = static_cast<T>(0);
    T cos_z = static_cast<T>(0);
    T sin_z = static_cast<T>(0);
    sincos_any(ax, sin_x, cos_x);
    sincos_any(ay, sin_y, cos_y);
    sincos_any(az, sin_z, cos_z);
    T const nx = static_cast<T>(((cos_y *                         cos_z) * x) - ((cos_y *                         sin_z) * y) + (sin_y *         z));
    T const ny = static_cast<T>(((cos_x * sin_z + sin_x * sin_y * cos_z) * x) + ((cos_x * cos_z - sin_x * sin_y * sin_z) * y) - (sin_x * cos_y * z));
    T const nz = static_cast<T>(((sin_x * sin_z - cos_x * sin_y * cos_z) * x) + ((cos_x * sin_y * sin_z + sin_x * cos_z) * y) + (cos_x * cos_y * z));
    x = nx;
    y = ny;
    z = nz;
  }
  /**
   * Rotate vector around the X axis.
   * @param ax Angle (in degrees) to be rotated around X-axis.
   */
  inline void constexpr rotate_x(T ax) __attribute__((__always_inline__)) {
    rotate_rad_x(deg2rad(ax));
  }
  /**
   * Rotate vector around the Y axis.
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   */
  inline void constexpr rotate_y(T ay) __attribute__((__always_inline__)) {
    rotate_rad_y(deg2rad(ay));
  }
  /**
   * Rotate vector around the Z axis.
   * @param az Angle (in degrees) to be rotated around Z-axis.
   */
  inline void constexpr rotate_z(T az) __attribute__((__always_inline__)) {
    rotate_rad_z(deg2rad(az));
  }
  /**
   * Rotate vector around the X axis, radian version.
   * @param ax Angle (in radians) to be rotated around X-axis.
   */
  inline void constexpr rotate_rad_x(T ax) __attribute__((__always_inline__)) {
    T cos_x = static_cast<T>(0);
    T sin_x = static_cast<T>(0);
    sincos_any(ax, sin_x, cos_x);
    T const ny = static_cast<T>((cos_x * y) - (sin_x * z));
    T const nz = static_cast<T>((cos_x * z) + (sin_x * y));
    y = ny;
    z = nz;
  }
  /**
   * Rotate vector around the Y axis, radian version.
   * @param ay Angle (in radians) to be rotated around Y-axis.
   */
  inline void constexpr rotate_rad_y(T ay) __attribute__((__always_inline__)) {
    T cos_y = static_cast<T>(0);
    T sin_y = static_cast<T>(0);
    sincos_any(ay, sin_y, cos_y);
    T const nx = static_cast<T>((cos_y * x) + (sin_y * z));
    T const nz = static_cast<T>((cos_y * z) - (sin_y * x));
    x = nx;
    z = nz;
  }
  /**
   * Rotate vector around the Z axis, radian version.
   * @param az Angle (in radians) to be rotated around Z-axis.
   */
  inline void constexpr rotate_rad_z(T az) __attribute__((__always_inline__)) {
    T cos_z = static_cast<T>(0);
    T sin_z = static_cast<T>(0);
    sincos_any(az, sin_z, cos_z);
    T const nx = static_cast<T>((cos_z * x) - (sin_z * y));
    T const ny = static_cast<T>((cos_z * y) + (sin_z * x));
    x = nx;
    y = ny;
  }
  /**
   * Rotate vector by a quaternion.
   * @param ax quaternion to rotate by.
   */
  inline void constexpr rotate(quaternion<T> const &rhs) __attribute__((__always_inline__)) {
    *this *= rhs;
  }

  /**
   * Linear interpolation of two vectors
   * @param fact Factor of interpolation. For translation from positon
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
   * @param r Second Vector for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  inline vector3<T> constexpr lerp(T fact, vector3<T> const &new_r) const __attribute__((__always_inline__)) {
    return (*this) + (new_r - (*this)) * fact;
  }

  //-------------[ conversion ]--------------------------------

  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector3<T>)
   * used for passing vector3<T> values to gl*3[fd] functions.
   */
  inline constexpr operator T*() __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector3<T>)
   * used for passing vector3<T> values to gl*3[fd] functions.
   */
  inline constexpr operator const T*() const __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(this);
  }

  //-------------[ output ]------------------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, vector3<T> const &rhs) __attribute__((__always_inline__)) {
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
    return lhs;
  }

  /**
   * Gets string representation.
   */
  inline std::string constexpr toString() const __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }

  /**
   * Gets a 2D vector equivalent using the X and Y axes
   */
  inline vector2<T> constexpr to_2d_xy() const __attribute__((__always_inline__)) {
    return vector2<T>(x, y);
  }
  inline vector2<T> constexpr to_2D_XY() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
    return to_2d_xy();
  }

  /**
   * Gets a 2D vector equivalent using the X and Z axes
   */
  inline vector2<T> constexpr to_2d_xz() const __attribute__((__always_inline__)) {
    return vector2<T>(x, z);
  }
  inline vector2<T> constexpr to_2D_XZ() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
    return to_2d_xz();
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector3_types.h"

#endif // VECTORSTORM_VECTOR3_H_INCLUDED
