
  /**
   * Addition operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  /**
   * Subtraction operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  /**
   * Multiplication operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  /**
   * Division operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  /**
   * Dot product of two vectors.
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr dot(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x * rhs.x) +
           (y * rhs.y) +
           (z * rhs.z);
  }
  inline T constexpr dotProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use dot()"))) {
    return dot(rhs);
  }

  /**
   * Cross product of two vectors
   * @param rhs Right hand side argument of binary operator.
#ifndef VECTORSTORM_VECTOR3_H_INCLUDED
   */
#define VECTORSTORM_VECTOR3_H_INCLUDED
  inline vector3<T> constexpr cross(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return {(y * rhs.z) - (rhs.y * z),
#include <cmath>
            (z * rhs.x) - (rhs.z * x),
#include <sstream>
            (x * rhs.y) - (rhs.x * y)};
#include "vectorstorm/epsilon.h"
  }
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
  inline vector3<T> constexpr crossProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use cross()"))) {
#include "vector2_forward.h"
    return cross(rhs);
#include "vector4_forward.h"
  }
#include "vectorstorm/quat/quat_forward.h"

#include "vectorstorm/matrix/matrix3_forward.h"
  //--------------[ rotation with quaternions ]-----------------
#include "vectorstorm/matrix/matrix4_forward.h"
  // see http://mollyrocket.com/forums/viewtopic.php?t=833&sid=3a84e00a70ccb046cfc87ac39881a3d0
#ifndef VMATH_NO_BOOST
  /**
  #include <boost/functional/hash_fwd.hpp>
   * Multiplication by quaternion operator (rotation by quaternion)
#endif // VMATH_NO_BOOST

   * @param rhs Right hand side argument of binary operator.
#ifdef VMATH_NAMESPACE
   */
namespace VMATH_NAMESPACE {
  inline vector3<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
#endif
    return *this + (rhs.v.cross(*this) * static_cast<T>(2) * rhs.w) + rhs.v.cross(rhs.v.cross(*this) * static_cast<T>(2));

  }
/**

 * Class for three dimensional vector.
  /**
 * There are four ways of accessing vector components.
   * Multiplication by quaternion operator (rotation by quaternion)
 * Let's have <code>vector3f v</code>, you can either:
   * @param rhs Right hand side argument of binary operator.
 * <ul>
   */
 *  <li>access as position (x,y,z) &mdash; <code>v.x = v.y = v.z = 1;</code></li>
  inline vector3<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
 *  <li>access as texture coordinate (s,t,u) &mdash; <code>v.s = v.t = v.u = 1;</code></li>
    vector3<T> const temp = rhs.v.cross(*this) * static_cast<T>(2);
 *  <li>access as colour (r,g,b) &mdash; <code>v.r = v.g = v.b = 1;</code></li>
    *this += (temp * rhs.w) + rhs.v.cross(temp);
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = 1;</code></li>
    return *this;
 * </ul>
 */
  }
template<typename T>

class vector3 {
  //--------------[ scalar vector operator ]--------------------
public:
  /**
  union {
   * Addition operator
    /**
   * @param rhs Right hand side argument of binary operator.
     * First element of vector, alias for X-coordinate.
   */
     */
  inline vector3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    T x;
    return vector3<T>(x + rhs, y + rhs, z + rhs);

  }
    /**

     * First element of vector, alias for S-coordinate.
  /**
     * For textures notation.
     */
   * Subtraction operator
    T s;
   * @param rhs Right hand side argument of binary operator.

   */
    /**
  inline vector3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
     * First element of vector, alias for R-coordinate.
    return vector3<T>(x - rhs, y - rhs, z - rhs);
     * For colour notation.
  }
     */

    T r;
  /**
  };
   * Multiplication operator

  union {
   * @param rhs Right hand side argument of binary operator.
    /**
   */
     * Second element of vector, alias for Y-coordinate.
  inline vector3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
     */
    return vector3<T>(x * rhs, y * rhs, z * rhs);
    T y;
  }


    /**
  /**
     * Second element of vector, alias for T-coordinate.
   * Division operator
     * For textures notation.
   * @param rhs Right hand side argument of binary operator.
     */
   */
    T t;

  inline vector3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    /**
    return vector3<T>(x / rhs, y / rhs, z / rhs);
     * Second element of vector, alias for G-coordinate.
  }
     * For colour notation.

     */
  /**
    T g;
   * Addition operator
  };
   * @param rhs Right hand side argument of binary operator.

   */
  union {
  inline vector3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    /**
    x += rhs;
     * Third element of vector, alias for Z-coordinate.
     */
    y += rhs;
    T z;
    z += rhs;

    return *this;
    /**
  }
     * Third element of vector, alias for U-coordinate.

     * For textures notation.
  /**
     */
   * Subtraction operator
    T u;
   * @param rhs Right hand side argument of binary operator.

   */
    /**
     * Third element of vector, alias for B-coordinate.
  inline vector3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
     * For colour notation.
    x -= rhs;
     */
    y -= rhs;
    T b;
    z -= rhs;
  };
    return *this;

  }
  //----------------[ constructors ]--------------------------

  /**
  /**
   * Creates and sets to (0,0,0)
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline constexpr vector3() noexcept __attribute__((__always_inline__))
   */
    : x(0),
  inline vector3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
      y(0),
    x *= rhs;
      z(0) {
    y *= rhs;
  }
    z *= rhs;

    return *this;
  /**
  }
   * Creates and sets to (x,y,z)

   * @param nx initial x-coordinate value
  /**
   * @param ny initial y-coordinate value
   * Division operator
   * @param nz initial z-coordinate value
   */
   * @param rhs Right hand side argument of binary operator.
  inline constexpr vector3(T nx, T ny, T nz) noexcept __attribute__((__always_inline__))
   */
    : x(nx),
  inline vector3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
      y(ny),
    x /= rhs;
      z(nz) {
    y /= rhs;
  }
    z /= rhs;

    return *this;
  /**
  }
   * Copy constructor.

   * @param src Source of data for new created vector3 instance.
  //-------------[ matrix operations ]-------------------------
   */

  inline constexpr explicit vector3(vector3<T> const &src) noexcept __attribute__((__always_inline__))
  /**
    : x(src.x),
      y(src.y),
   * Multiplication by 3x3 matrix operator
      z(src.z) {
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    *this = rhs * *this;
   * Copy casting constructor.
    return *this;
   * @param src Source of data for new created vector3 instance.
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline constexpr explicit vector3(vector3<FromT> const &src) noexcept
   * Multiplication by 4x4 matrix operator
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
   * @param rhs Right hand side argument of binary operator.
      z(static_cast<T>(src.z)) {
   */
  }
  inline vector3<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    *this = rhs * *this;
  /**
    return *this;
   * Copy constructor from a vector2.
  }
   * @param src Source of x,y data for new created vector3 instance.

   * @param new_z Source of data for z element.
  //-------------[ equality operator ]-------------------------
   */
  /**
  inline constexpr vector3(vector2<T> const &src, T new_z) noexcept __attribute__((__always_inline__))
   * Equality test operator
    : x(src.x),
   * @param rhs Right hand side argument of binary operator.
      y(src.y),
   * @note Test of equality is based of threshold epsilon value. To be two
      z(new_z) {
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
  }

   * same for y-coordinate, and z-coordinate.
  /**
   */
   * Copy casting constructor from a vector2.
  inline bool constexpr operator==(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param src Source of x,y,z data for new created vector3 instance.
    #ifdef VMATH_SOFT_COMPARE
   * @param new_z Source of data for z element.
      return std::abs(x - rhs.x) < epsilon<T> &&
   */
             std::abs(y - rhs.y) < epsilon<T> &&
  template<typename FromT> __attribute__((__always_inline__))
             std::abs(z - rhs.z) < epsilon<T>;
  inline constexpr vector3(vector2<FromT> const &src, FromT new_z) noexcept
    #else
    : x(static_cast<T>(src.x)),
      return x == rhs.x &&
      y(static_cast<T>(src.y)),
             y == rhs.y &&
      z(static_cast<T>(new_z)) {
             z == rhs.z;
  }

    #endif // VMATH_SOFT_COMPARE
  /**
  }
   * Copy constructor from a vector4.

   * @param src Source of x,y,z data for new created vector3 instance.
  /**
   */
   * Inequality test operator
  inline constexpr vector3(vector4<T> const &src) noexcept __attribute__((__always_inline__))
   * @param rhs Right hand side argument of binary operator.
    : x(src.x),
   * @return not (lhs == rhs) :-P
      y(src.y),
   */
      z(src.y) {
  inline bool constexpr operator!=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return !(*this == rhs);

  }
  /**

   * Copy casting constructor from a vector4.
  //-------------[ unary operations ]--------------------------
   * @param src Source of x,y,z data for new created vector3 instance.
  /**
   */
   * Unary negate operator
  template<typename FromT> __attribute__((__always_inline__))
   * @return negated vector
  inline constexpr vector3(vector4<FromT> const &src) noexcept
   */
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
  inline vector3<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
      z(static_cast<T>(src.y)) {
    return vector3<T>(-x, -y, -z);
  }
  }


  /**
  //-------------[ size operations ]---------------------------
   * Move constructor.
  /**
   * @param src Source of data for new created vector3 instance.
   * Return square of length.
   */
   * @return length ^ 2
  inline constexpr vector3(vector3<T> &&src) noexcept __attribute__((__always_inline__))
   * @note This method is faster then length(). For comparison
    : x(std::move(src.x)),
   * of length of two vector can be used just this value, instead
      y(std::move(src.y)),
   * of more expensive length() method.
      z(std::move(src.z)) {
   */
  }

  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
  /**
    return x * x + y * y + z * z;
   * Move casting constructor.
  }
   * @param src Source of data for new created vector3 instance.
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
   */
    return length_sq();
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline constexpr vector3(vector3<FromT> &&src) noexcept

    : x(static_cast<T>(std::move(src.x))),
  /**
      y(static_cast<T>(std::move(src.y))),
   * Get length of vector.
      z(static_cast<T>(std::move(src.z))) {
   * @return length of vector
  }
   */

  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
  /**
   * Move constructor from a vector2.
    return static_cast<T>(std::sqrt(length_sq()));
   * @param src Source of x,y data for new created vector3 instance.
  }
   * @param new_z Source of data for z element.
  /**
   */
   * Get length of vector, fast approximation.
  inline constexpr vector3(vector2<T> &&src, T new_z) noexcept __attribute__((__always_inline__))
   * @return length of vector
    : x(std::move(src.x)),
   */
      y(std::move(src.y)),
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
      z(std::move(new_z)) {
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  }

  /**
  /**
   * Move casting constructor from a vector2.
   * Get length of vector, rougher fast approximation.
   * @param src Source of x,y data for new created vector3 instance.
   * @return length of vector
   * @param new_z Source of data for z element.
   */
   */
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return static_cast<T>(sqrt_faster(length_sq()));
  inline constexpr vector3(vector2<FromT> &&src, FromT new_z) noexcept
  }
    : x(static_cast<T>(std::move(src.x))),
  /**
      y(static_cast<T>(std::move(src.y))),
   * Return whether the vector is zero length - this is much faster than a full length calculation
      z(static_cast<T>(std::move(new_z))) {
   * @return whether vector is zero length
  }
   */

  inline bool constexpr length_zero() const noexcept __attribute__((__always_inline__)) {
  /**
    /*
   * Move constructor from a vector4.
    return x == static_cast<T>(0) &&
   * @param src Source of x,y,z data for new created vector3 instance.
           y == static_cast<T>(0) &&
   * @param new_z Source of data for z element.
   */
           z == static_cast<T>(0);
  inline constexpr vector3(vector4<T> &&src) noexcept __attribute__((__always_inline__))
    */
    : x(std::move(src.x)),
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
      y(std::move(src.y)),
    return std::abs(x) < epsilon<T> &&
      z(std::move(src.z)) {
           std::abs(y) < epsilon<T> &&
  }
           std::abs(z) < epsilon<T>;

  }
  /**

   * Move casting constructor from a vector4.
  /**
   * @param src Source of x,y,z data for new created vector3 instance.
   * normalise vector
   * @param new_z Source of data for z element.
   */
   */
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    T const temp = length();
  inline constexpr vector3(vector4<FromT> &&src) noexcept
    x /= temp;
    : x(static_cast<T>(std::move(src.x))),
    y /= temp;
      y(static_cast<T>(std::move(src.y))),
    z /= temp;
      z(static_cast<T>(std::move(src.z))) {
  }
  }

  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
  //----------------[ assignment ]-------------------------
    T const temp = length_fast();
  /**
    x /= temp;
   * Sets to (x,y,z)
    y /= temp;
   * @param nx initial x-coordinate value
    z /= temp;
   * @param ny initial y-coordinate value
  }
   * @param nz initial z-coordinate value
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
   */
    T const temp = length_faster();
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0) noexcept __attribute__((__always_inline__)) {
    x /= temp;
    x = nx;
    y /= temp;
    y = ny;
    z /= temp;
    z = nz;
  }
  }

  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  //----------------[ access operators ]-------------------
    normalise();
  /**
  }
   * Copy operator
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * @param rhs Right hand side argument of binary operator.
    normalise_fast();
   */
  }
  inline vector3<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    x = rhs.x;
    normalise_faster();
    y = rhs.y;
  }
    z = rhs.z;
  inline vector3<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    return *this;
    T const temp(length());
  }

    return vector3<T>(x / temp, y / temp, z / temp);
  /**
  }
   * Copy casting operator.
  inline vector3<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    T const temp(length_fast());
   */
    return vector3<T>(x / temp, y / temp, z / temp);
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline vector3<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
  inline vector3<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    x = static_cast<T>(rhs.x);
    T const temp(length_faster());
    y = static_cast<T>(rhs.y);
    return vector3<T>(x / temp, y / temp, z / temp);
    z = static_cast<T>(rhs.z);
  }
    return *this;
  }
  inline vector3<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {

    return normalise_copy();
  /**
  }
   * Copy operator to vector3 from vector4
  inline vector3<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * @param rhs Right hand side argument of binary operator.
    return normalise_copy_fast();
   */
  }
  inline vector3<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    x = rhs.x;
    return normalise_copy_faster();
    y = rhs.y;
  }
    z = rhs.z;
  /**
    return *this;
  }
   * normalise vector. with added zero safety check

   */
  /**
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
   * Copy casting operator to vector3 from vector4
    if(length_zero()) {
   * @param rhs Right hand side argument of binary operator.
      assign();
   */
    } else {
  template<typename FromT> __attribute__((__always_inline__))
      *this /= length();
  inline vector3<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
    }
    x = static_cast<T>(rhs.x);
  }
    y = static_cast<T>(rhs.y);
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    z = static_cast<T>(rhs.z);
    normalise_safe();
    return *this;
  }
  }

  inline vector3<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
  /**
    if(length_zero()) {
   * Move assignment operator
      return {};
   * @param rhs Right hand side argument of binary operator.
    } else {
   */
      return *this / length();
  inline vector3<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    }
    x = std::move(rhs.x);
  }
    y = std::move(rhs.y);
  inline vector3<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    z = std::move(rhs.z);
    return normalise_safe_copy();
    return *this;
  }
  }


  /**
  /**
   * Absolute vector (make all values positive)
   * Move assignment casting operator.
   */
   * @param rhs Right hand side argument of binary operator.
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
   */
    x = std::abs(x);
  template<typename FromT> __attribute__((__always_inline__))
    y = std::abs(y);
  inline vector3<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
    z = std::abs(z);
    x = static_cast<T>(std::move(rhs.x));
  }
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
  inline vector3<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
    return *this;
    return vector3<T>(std::abs(x), std::abs(y), std::abs(z));
  }
  }


  /**
  //-------------[ other operations ]--------------------------
   * Move assignment operator to vector3 from vector4
  /**
   * @param rhs Right hand side argument of binary operator.
   * Rotate vector around three axis.
   */
   * @param ax Angle (in degrees) to be rotated around X-axis.
  inline vector3<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
   * @param ay Angle (in degrees) to be rotated around Y-axis.
    x = std::move(rhs.x);
    y = std::move(rhs.y);
   * @param az Angle (in degrees) to be rotated around Z-axis.
    z = std::move(rhs.z);
   */
    return *this;
  inline void constexpr rotate(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
  }
    rotate_rad(deg2rad(ax), deg2rad(ay), deg2rad(az));

  }
  /**
  /**
   * Move assignment casting operator to vector3 from vector4
   * Rotate vector around three axis, radian version.
   * @param rhs Right hand side argument of binary operator.
   * @param ax Angle (in radians) to be rotated around X-axis.
   */
   * @param ay Angle (in radians) to be rotated around Y-axis.
  template<typename FromT> __attribute__((__always_inline__))
   * @param az Angle (in radians) to be rotated around Z-axis.
  inline vector3<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
   */
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
  inline void constexpr rotate_rad(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
    z = static_cast<T>(std::move(rhs.z));
    T cos_x = static_cast<T>(0);
    return *this;
    T sin_x = static_cast<T>(0);
  }
    T cos_y = static_cast<T>(0);

    T sin_y = static_cast<T>(0);
  /**
    T cos_z = static_cast<T>(0);
   * Array access operator
    T sin_z = static_cast<T>(0);
   * @param n Array index
    sincos_any(ax, sin_x, cos_x);
   * @return For n = 0, reference to x coordinate, n = 1
    sincos_any(ay, sin_y, cos_y);
   * reference to y, else reference to z
    sincos_any(az, sin_z, cos_z);
   * y coordinate.
   */
    T const nx = static_cast<T>(((cos_y *                         cos_z) * x) - ((cos_y *                         sin_z) * y) + (sin_y *         z));
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
    T const ny = static_cast<T>(((cos_x * sin_z + sin_x * sin_y * cos_z) * x) + ((cos_x * cos_z - sin_x * sin_y * sin_z) * y) - (sin_x * cos_y * z));
    return n == 0 ? x : (n == 1 ? y : z);
    T const nz = static_cast<T>(((sin_x * sin_z - cos_x * sin_y * cos_z) * x) + ((cos_x * sin_y * sin_z + sin_x * cos_z) * y) + (cos_x * cos_y * z));
  }
    x = nx;

    y = ny;
  /**
    z = nz;
   * Constant array access operator
  }
   * @param n Array index
  /**
   * @return For n = 0, reference to x coordinate, n = 1
   * Rotate vector around the X axis.
   * reference to y, else reference to z
   * @param ax Angle (in degrees) to be rotated around X-axis.
   * y coordinate.
   */
   */
  inline void constexpr rotate_x(T ax) noexcept __attribute__((__always_inline__)) {
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
    rotate_rad_x(deg2rad(ax));
    return n == 0 ? x : (n == 1 ? y : z);
  }
  }

  /**
  //---------------[ vector arithmetic operator ]--------------
   * Rotate vector around the Y axis.
  /**
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   * Addition operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline void constexpr rotate_y(T ay) noexcept __attribute__((__always_inline__)) {
   */
    rotate_rad_y(deg2rad(ay));
  inline vector3<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
  /**
  }
   * Rotate vector around the Z axis.

   * @param az Angle (in degrees) to be rotated around Z-axis.
  /**
   */
   * Subtraction operator
  inline void constexpr rotate_z(T az) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
   */
    rotate_rad_z(deg2rad(az));
  inline vector3<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  /**
  }
   * Rotate vector around the X axis, radian version.

   * @param ax Angle (in radians) to be rotated around X-axis.
  /**
   */
   * Multiplication operator
  inline void constexpr rotate_rad_x(T ax) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    T cos_x = static_cast<T>(0);
   */
    T sin_x = static_cast<T>(0);
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    sincos_any(ax, sin_x, cos_x);
    return vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
    T const ny = static_cast<T>((cos_x * y) - (sin_x * z));
  }

    T const nz = static_cast<T>((cos_x * z) + (sin_x * y));
  /**
    y = ny;
   * Division operator
    z = nz;
   * @param rhs Right hand side argument of binary operator.
  }
   */
  /**
  inline vector3<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Rotate vector around the Y axis, radian version.
    return vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
   * @param ay Angle (in radians) to be rotated around Y-axis.
  }
   */

  inline void constexpr rotate_rad_y(T ay) noexcept __attribute__((__always_inline__)) {
  /**
    T cos_y = static_cast<T>(0);
   * Addition operator
    T sin_y = static_cast<T>(0);
   * @param rhs Right hand side argument of binary operator.
   */
    sincos_any(ay, sin_y, cos_y);
  inline vector3<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    T const nx = static_cast<T>((cos_y * x) + (sin_y * z));
    x += rhs.x;
    T const nz = static_cast<T>((cos_y * z) - (sin_y * x));
    y += rhs.y;
    x = nx;
    z += rhs.z;
    z = nz;
    return *this;
  }
  }
  /**

   * Rotate vector around the Z axis, radian version.
  /**
   * @param az Angle (in radians) to be rotated around Z-axis.
   * Subtraction operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline void constexpr rotate_rad_z(T az) noexcept __attribute__((__always_inline__)) {
   */
    T cos_z = static_cast<T>(0);
  inline vector3<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    T sin_z = static_cast<T>(0);
    x -= rhs.x;
    sincos_any(az, sin_z, cos_z);
    y -= rhs.y;
    z -= rhs.z;
    T const nx = static_cast<T>((cos_z * x) - (sin_z * y));
    return *this;
    T const ny = static_cast<T>((cos_z * y) + (sin_z * x));
  }
    x = nx;

    y = ny;
  /**
  }
   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Rotate vector by a quaternion.
   */
   * @param ax quaternion to rotate by.
  inline vector3<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x *= rhs.x;
  inline void constexpr rotate(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    y *= rhs.y;
    *this *= rhs;
    z *= rhs.z;
  }
    return *this;

  }
  /**

  /**
   * Linear interpolation of two vectors
   * Division operator
   * @param fact Factor of interpolation. For translation from positon
   * @param rhs Right hand side argument of binary operator.
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
   */
   * @param r Second Vector for interpolation
  inline vector3<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @note However values of fact parameter are reasonable only in interval
    x /= rhs.x;
   * [0.0 , 1.0], you can pass also values outside of this interval and you
    y /= rhs.y;
   * can get result (extrapolation?)
    z /= rhs.z;
   */
    return *this;
  inline vector3<T> constexpr lerp(T fact, vector3<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
  }

    return (*this) + (new_r - (*this)) * fact;
  /**
  }
   * Addition operator with a 2-vector

   * @param rhs Right hand side argument of binary operator.
  //-------------[ conversion ]--------------------------------
   */

  inline vector3<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector3<T>(x + rhs.x, y + rhs.y, z);
   * Conversion to pointer operator
  }
   * @return Pointer to internally stored (in management of class vector3<T>)

   * used for passing vector3<T> values to gl*3[fd] functions.
  /**
   */
   * Subtraction operator with a 2-vector
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
   */
    return reinterpret_cast<T*>(this);
  inline vector3<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector3<T>(x - rhs.x, y - rhs.y, z);

  }
  /**

   * Conversion to pointer operator
  /**
   * @return Constant Pointer to internally stored (in management of class vector3<T>)
   * Multiplication operator with a 2-vector
   * used for passing vector3<T> values to gl*3[fd] functions.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(this);
    return vector3<T>(x * rhs.x, y * rhs.y, z);
  }
  }


  /**
  //-------------[ output ]------------------------------------
   * Division operator with a 2-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Output to stream operator
   */
   * @param lhs Left hand side argument of operator (commonly ostream instance).
  inline vector3<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of operator.
    return vector3<T>(x / rhs.x, y / rhs.y, z);
   * @return Left hand side argument - the ostream object passed to operator.
  }
   */

  inline friend std::ostream &operator<<(std::ostream &lhs, vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
   * Addition operator with a 2-vector
    return lhs;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x += rhs.x;
   * Gets string representation.
    y += rhs.y;
   */
    return *this;
  }
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) {

    std::ostringstream oss;
  /**
    oss << *this;
   * Subtraction operator with a 2-vector
    return oss.str();
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x -= rhs.x;
   * Gets a 2D vector equivalent using the X and Y axes
    y -= rhs.y;
   */
    return *this;
  inline vector2<T> constexpr to_2d_xy() const noexcept __attribute__((__always_inline__)) {
  }
    return vector2<T>(x, y);

  }
  /**
  inline vector2<T> constexpr to_2D_XY() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
   * Multiplication operator with a 2-vector
    return to_2d_xy();
   * @param rhs Right hand side argument of binary operator.
   */
  }
  inline vector3<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x *= rhs.x;
  /**
    y *= rhs.y;
   * Gets a 2D vector equivalent using the X and Z axes
    return *this;
   */
  }
  inline vector2<T> constexpr to_2d_xz() const noexcept __attribute__((__always_inline__)) {

    return vector2<T>(x, z);
  /**
  }
   * Division operator with a 2-vector
  inline vector2<T> constexpr to_2D_XZ() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
   * @param rhs Right hand side argument of binary operator.
    return to_2d_xz();
   */
  }
  inline vector3<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
};
    x /= rhs.x;

    y /= rhs.y;
#ifdef VMATH_NAMESPACE
    return *this;
  }
}

#endif //VMATH_NAMESPACE
  /**

   * Dot product of two vectors.
#include "vector3_types.h"
   * @param rhs Right hand side argument of binary operator.

   */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  inline T constexpr dot(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
//
    return (x * rhs.x) +
// Standard C++ library extensions
           (y * rhs.y) +
//
           (z * rhs.z);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }

  inline T constexpr dotProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use dot()"))) {
namespace std {
    return dot(rhs);
  }


/**
  /**
 * Gets vector containing minimal values of @a a and @a b coordinates.
   * Cross product of two vectors
 * @return Vector of minimal coordinates.
   * @param rhs Right hand side argument of binary operator.
 */
   */
template<typename T>
  inline vector3<T> constexpr cross(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
inline constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
    return {(y * rhs.z) - (rhs.y * z),
template<typename T>
            (z * rhs.x) - (rhs.z * x),
inline constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept {
            (x * rhs.y) - (rhs.x * y)};
  return vector3<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z));
  }
}
  inline vector3<T> constexpr crossProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use cross()"))) {

    return cross(rhs);
/**
  }

 * Gets vector containing maximal values of @a a and @a b coordinates.
  //--------------[ rotation with quaternions ]-----------------
 * @return Vector of maximal coordinates.
  // see http://mollyrocket.com/forums/viewtopic.php?t=833&sid=3a84e00a70ccb046cfc87ac39881a3d0
 */
  /**
template<typename T>
   * Multiplication by quaternion operator (rotation by quaternion)
inline constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
   * @param rhs Right hand side argument of binary operator.
template<typename T>
   */
inline constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept {
  inline vector3<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  return vector3<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z));
    return *this + (rhs.v.cross(*this) * static_cast<T>(2) * rhs.w) + rhs.v.cross(rhs.v.cross(*this) * static_cast<T>(2));
}
  }


#ifndef VMATH_NO_BOOST
  /**
/**
   * Multiplication by quaternion operator (rotation by quaternion)
 * Gets a hash value taking account of all dimensions of this vector, for use
   * @param rhs Right hand side argument of binary operator.
 * in standard container maps etc.
   */
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
  inline vector3<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
 * @return Hash value
    vector3<T> const temp = rhs.v.cross(*this) * static_cast<T>(2);
 */
    *this += (temp * rhs.w) + rhs.v.cross(temp);
template<typename T>
    return *this;
struct hash<vector3<T>> {
  }

  size_t operator()(const vector3<T> &value) const {
  //--------------[ scalar vector operator ]--------------------
    size_t hashvalue = 0;
  /**
    boost::hash_combine(hashvalue, value.x);
   * Addition operator
    boost::hash_combine(hashvalue, value.y);
   * @param rhs Right hand side argument of binary operator.
    boost::hash_combine(hashvalue, value.z);
   */
    return hashvalue;
  inline vector3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector3<T>(x + rhs, y + rhs, z + rhs);
};
  }
#endif // VMATH_NO_BOOST


  /**
}
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
#ifndef VMATH_NO_BOOST
   */
/**
  inline vector3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
 * Gets a hash value taking account of all dimensions of this vector, for use
    return vector3<T>(x - rhs, y - rhs, z - rhs);
  }
 * in standard container maps etc.

 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
  /**
 * @return Hash value
   * Multiplication operator
 */
   * @param rhs Right hand side argument of binary operator.
template<typename T>
   */
size_t hash_value(vector3<T> const &value) {
  inline vector3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  size_t hashvalue = 0;
    return vector3<T>(x * rhs, y * rhs, z * rhs);
  boost::hash_combine(hashvalue, value.x);
  }
  boost::hash_combine(hashvalue, value.y);

  boost::hash_combine(hashvalue, value.z);
  /**
  return hashvalue;
   * Division operator
}
   * @param rhs Right hand side argument of binary operator.
   */
#endif // VMATH_NO_BOOST
  inline vector3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {

    return vector3<T>(x / rhs, y / rhs, z / rhs);
#endif // VECTORSTORM_VECTOR3_H_INCLUDED
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs;
    y += rhs;
    z += rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs;
    y -= rhs;
    z -= rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
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
  inline vector3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this = rhs * *this;
    return *this;
  }

  /**
   * Multiplication by 4x4 matrix operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
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
  inline bool constexpr operator==(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return std::abs(x - rhs.x) < epsilon<T> &&
             std::abs(y - rhs.y) < epsilon<T> &&
             std::abs(z - rhs.z) < epsilon<T>;
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
  inline bool constexpr operator!=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated vector
   */
  inline vector3<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
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
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
    return x * x + y * y + z * z;
  }
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
    return length_sq();
  }

  /**
   * Get length of vector.
   * @return length of vector
   */
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
    return static_cast<T>(std::sqrt(length_sq()));
  }
  /**
   * Get length of vector, fast approximation.
   * @return length of vector
   */
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  /**
   * Get length of vector, rougher fast approximation.
   * @return length of vector
   */
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return static_cast<T>(sqrt_faster(length_sq()));
  }
  /**
   * Return whether the vector is zero length - this is much faster than a full length calculation
   * @return whether vector is zero length
   */
  inline bool constexpr length_zero() const noexcept __attribute__((__always_inline__)) {
    /*
    return x == static_cast<T>(0) &&
           y == static_cast<T>(0) &&
           z == static_cast<T>(0);
    */
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
    return std::abs(x) < epsilon<T> &&
           std::abs(y) < epsilon<T> &&
           std::abs(z) < epsilon<T>;
  }

  /**
   * normalise vector
   */
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
    T const temp = length();
    x /= temp;
    y /= temp;
    z /= temp;
  }
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    T const temp = length_fast();
    x /= temp;
    y /= temp;
    z /= temp;
  }
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    T const temp = length_faster();
    x /= temp;
    y /= temp;
    z /= temp;
  }
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise();
  }
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_fast();
  }
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_faster();
  }
  inline vector3<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    T const temp(length());
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  inline vector3<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  inline vector3<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  inline vector3<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline vector3<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline vector3<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_faster();
  }
  /**
   * normalise vector. with added zero safety check
   */
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
    if(length_zero()) {
      assign();
    } else {
      *this /= length();
    }
  }
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_safe();
  }
  inline vector3<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    if(length_zero()) {
      return {};
    } else {
      return *this / length();
    }
  }
  inline vector3<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_safe_copy();
  }

  /**
   * Absolute vector (make all values positive)
   */
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
    x = std::abs(x);
    y = std::abs(y);
    z = std::abs(z);
  }
  inline vector3<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(std::abs(x), std::abs(y), std::abs(z));
  }

  //-------------[ other operations ]--------------------------
  /**
   * Rotate vector around three axis.
   * @param ax Angle (in degrees) to be rotated around X-axis.
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   * @param az Angle (in degrees) to be rotated around Z-axis.
   */
  inline void constexpr rotate(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
    rotate_rad(deg2rad(ax), deg2rad(ay), deg2rad(az));
  }
  /**
   * Rotate vector around three axis, radian version.
   * @param ax Angle (in radians) to be rotated around X-axis.
   * @param ay Angle (in radians) to be rotated around Y-axis.
   * @param az Angle (in radians) to be rotated around Z-axis.
   */
  inline void constexpr rotate_rad(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
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
  inline void constexpr rotate_x(T ax) noexcept __attribute__((__always_inline__)) {
    rotate_rad_x(deg2rad(ax));
  }
  /**
   * Rotate vector around the Y axis.
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   */
  inline void constexpr rotate_y(T ay) noexcept __attribute__((__always_inline__)) {
    rotate_rad_y(deg2rad(ay));
  }
  /**
   * Rotate vector around the Z axis.
   * @param az Angle (in degrees) to be rotated around Z-axis.
   */
  inline void constexpr rotate_z(T az) noexcept __attribute__((__always_inline__)) {
    rotate_rad_z(deg2rad(az));
  }
  /**
   * Rotate vector around the X axis, radian version.
   * @param ax Angle (in radians) to be rotated around X-axis.
   */
  inline void constexpr rotate_rad_x(T ax) noexcept __attribute__((__always_inline__)) {
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
  inline void constexpr rotate_rad_y(T ay) noexcept __attribute__((__always_inline__)) {
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
  inline void constexpr rotate_rad_z(T az) noexcept __attribute__((__always_inline__)) {
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
  inline void constexpr rotate(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
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
  inline vector3<T> constexpr lerp(T fact, vector3<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (new_r - (*this)) * fact;
  }

  //-------------[ conversion ]--------------------------------

  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector3<T>)
   * used for passing vector3<T> values to gl*3[fd] functions.
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector3<T>)
   * used for passing vector3<T> values to gl*3[fd] functions.
   */
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(this);
  }

  //-------------[ output ]------------------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
    return lhs;
  }

  /**
   * Gets string representation.
   */
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }

  /**
   * Gets a 2D vector equivalent using the X and Y axes
   */
  inline vector2<T> constexpr to_2d_xy() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x, y);
  }
  inline vector2<T> constexpr to_2D_XY() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
    return to_2d_xy();
  }

  /**
   * Gets a 2D vector equivalent using the X and Z axes
   */
  inline vector2<T> constexpr to_2d_xz() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x, z);
  }
  inline vector2<T> constexpr to_2D_XZ() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
    return to_2d_xz();
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector3_types.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Standard C++ library extensions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace std {

/**
 * Gets vector containing minimal values of @a a and @a b coordinates.
 * @return Vector of minimal coordinates.
 */
template<typename T>
inline constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept {
  return vector3<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
inline constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept {
  return vector3<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z));
}

#ifndef VMATH_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this vector, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
struct hash<vector3<T>> {
  size_t operator()(const vector3<T> &value) const {
    size_t hashvalue = 0;
    boost::hash_combine(hashvalue, value.x);
    boost::hash_combine(hashvalue, value.y);
    boost::hash_combine(hashvalue, value.z);
    return hashvalue;
  }
};
#endif // VMATH_NO_BOOST

}

#ifndef VMATH_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this vector, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
size_t hash_value(vector3<T> const &value) {
  size_t hashvalue = 0;
  boost::hash_combine(hashvalue, value.x);
  boost::hash_combine(hashvalue, value.y);
  boost::hash_combine(hashvalue, value.z);
  return hashvalue;
}
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_VECTOR3_H_INCLUDED
