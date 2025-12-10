#pragma once

#include <cmath>
#include <type_traits>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
#include "vector2_forward.h"
#include "vector4_forward.h"
#include "vectorstorm/quat/quat_forward.h"
#include "vectorstorm/quat/quat.h"
#include "vectorstorm/matrix/matrix3.h"
#include "vectorstorm/matrix/matrix4.h"
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
  inline constexpr vector3() noexcept __attribute__((__always_inline__))
    : x{T{}},
      y{T{}},
      z{T{}} {
  }

  /**
   * Creates and sets to (x,y,z)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   * @param nz initial z-coordinate value
   */
  inline constexpr vector3(T nx, T ny, T nz) noexcept __attribute__((__always_inline__))
    : x(nx),
      y(ny),
      z(nz) {
  }

  /**
   * Copy constructor.
   * @param src Source of data for new created vector3 instance.
   */
  inline constexpr explicit vector3(vector3<T> const &src) noexcept __attribute__((__always_inline__)) = default;

  /**
   * Copy casting constructor.
   * @param src Source of data for new created vector3 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector3(vector3<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)) {
  }

  /**
   * Copy constructor from a vector2.
   * @param src Source of x,y data for new created vector3 instance.
   * @param new_z Source of data for z element.
   */
  inline constexpr explicit vector3(vector2<T> const &src, T new_z) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y),
      z(new_z) {
  }

  /**
   * Copy casting constructor from a vector2.
   * @param src Source of x,y,z data for new created vector3 instance.
   * @param new_z Source of data for z element.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector3(vector2<FromT> const &src, FromT new_z) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(new_z)) {
  }

  /**
   * Copy constructor from a vector4.
   * @param src Source of x,y,z data for new created vector3 instance.
   */
  inline constexpr explicit vector3(vector4<T> const &src) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y),
      z(src.z) {
  }

  /**
   * Copy casting constructor from a vector4.
   * @param src Source of x,y,z data for new created vector3 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector3(vector4<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)) {
  }

  /**
   * Move constructor.
   * @param src Source of data for new created vector3 instance.
   */
  inline constexpr vector3(vector3<T> &&src) noexcept __attribute__((__always_inline__)) = default;

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

  /**
   * Move constructor from a vector2.
   * @param src Source of x,y data for new created vector3 instance.
   * @param new_z Source of data for z element.
   */
  inline constexpr explicit vector3(vector2<T> &&src, T new_z) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
      y(std::move(src.y)),
      z(std::move(new_z)) {
  }

  /**
   * Move casting constructor from a vector2.
   * @param src Source of x,y data for new created vector3 instance.
   * @param new_z Source of data for z element.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector3(vector2<FromT> &&src, FromT new_z) noexcept
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
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0) noexcept __attribute__((__always_inline__)) {
    x = nx;
    y = ny;
    z = nz;
  }

  //----------------[ access operators ]-------------------
  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) = default;

  /**
   * Copy casting operator.
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    return *this;
  }

  /**
   * Copy operator to vector3 from vector4
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
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
  inline vector3<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) = default;

  /**
   * Move assignment casting operator.
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    return *this;
  }

  /**
   * Move assignment operator to vector3 from vector4
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
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
  inline vector3<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
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
  [[nodiscard]]
  inline constexpr T &operator[](unsigned int n) noexcept __attribute__((__always_inline__)) {
    return n == 0u ? x : (n == 1u ? y : z);
  }

  /**
   * Constant array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y, else reference to z
   * y coordinate.
   */
  [[nodiscard]]
  inline constexpr T const &operator[](unsigned int n) const noexcept __attribute__((__always_inline__)) {
    return n == 0u ? x : (n == 1u ? y : z);
  }

  //---------------[ vector arithmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator%(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x % rhs.x, y % rhs.y, z % rhs.z);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }
  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator%=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x %= rhs.x;
    y %= rhs.y;
    z %= rhs.z;
    return *this;
  }

  /**
   * Addition operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs.x, y + rhs.y, z);
  }

  /**
   * Subtraction operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs.x, y - rhs.y, z);
  }

  /**
   * Multiplication operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs.x, y * rhs.y, z);
  }

  /**
   * Division operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs.x, y / rhs.y, z);
  }

  /**
   * Modulo operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator%(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x % rhs.x, y % rhs.y, z);
  }

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
  [[nodiscard]]
  inline T constexpr dot(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x * rhs.x) +
           (y * rhs.y) +
           (z * rhs.z);
  }

  /**
   * Cross product of two vectors
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr cross(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return {(y * rhs.z) - (rhs.y * z),
            (z * rhs.x) - (rhs.z * x),
            (x * rhs.y) - (rhs.x * y)};
  }

  //--------------[ rotation with quaternions ]-----------------
  // see http://mollyrocket.com/forums/viewtopic.php?t=833&sid=3a84e00a70ccb046cfc87ac39881a3d0
  /**
   * Multiplication by quaternion operator (rotation by quaternion)
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return *this + (rhs.v.cross(*this) * static_cast<T>(2) * rhs.w) + rhs.v.cross(rhs.v.cross(*this) * static_cast<T>(2));
  }

  /**
   * Multiplication by quaternion operator (rotation by quaternion)
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    vector3<T> const temp = rhs.v.cross(*this) * static_cast<T>(2);
    *this += (temp * rhs.w) + rhs.v.cross(temp);
    return *this;
  }

  //--------------[ scalar vector operator ]--------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs, y + rhs, z + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs, y - rhs, z - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs, y * rhs, z * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs, y / rhs, z / rhs);
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator%(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x % rhs, y % rhs, z % rhs);
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

  //-------------[ comparison operators ]----------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note If VECTORSTORM_SOFT_COMPARE is defined, the test of equality is based
   * on the threshold epsilon value. For two values to be equal, the condition
   * | lhs.x - rhs.y | < epsilon must be satisfied for each coordinate.
   * Otherwise, direct equality comparison is used.
   */
  [[nodiscard]]
  inline bool constexpr operator==(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VECTORSTORM_SOFT_COMPARE
      return std::abs(x - rhs.x) < epsilon<T> &&
             std::abs(y - rhs.y) < epsilon<T> &&
             std::abs(z - rhs.z) < epsilon<T>;
    #else
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wfloat-equal"
      return x == rhs.x &&
             y == rhs.y &&
             z == rhs.z;
      #pragma GCC diagnostic pop
    #endif // VECTORSTORM_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  [[nodiscard]]
  inline bool constexpr operator!=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  /**
   * Less than test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are less than rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator<(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x < rhs.x) &&
           (y < rhs.y) &&
           (z < rhs.z);
  }

  /**
   * Greater than test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are greater than rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator>(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x > rhs.x) &&
           (y > rhs.y) &&
           (z > rhs.z);
  }

  /**
   * Less than or equal test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are less than or equal to rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator<=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x <= rhs.x) &&
           (y <= rhs.y) &&
           (z <= rhs.z);
  }

  /**
   * Greater than or equal test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are greater than or equal to rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator>=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x >= rhs.x) &&
           (y >= rhs.y) &&
           (z >= rhs.z);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary plus operator
   * @return vector with unary + applied to its components
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator+() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(+x, +y, +z);
  }
  /**
   * Unary negate operator
   * @return negated vector
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(-x, -y, -z);
  }

  //-------------[ data operations ]---------------------------
  /**
   * Data access
   * @return pointer to the first element in the vector
   */
  [[nodiscard]]
  inline T constexpr *data() noexcept __attribute__((__always_inline__)) {
    return &x;
  }
  /**
   * Data access
   * @return pointer to the first element in the vector, const version
   */
  [[nodiscard]]
  inline T constexpr const *data() const noexcept __attribute__((__always_inline__)) {
    return &x;
  }

  /**
   * Iteration helpers for range-based for
   */
  [[nodiscard]]
  inline T constexpr *begin() noexcept __attribute__((__always_inline__)) {
    return data();
  }
  [[nodiscard]]
  inline T constexpr *end() noexcept __attribute__((__always_inline__)) {
    return data() + size();
  }
  [[nodiscard]]
  inline T constexpr const *begin() const noexcept __attribute__((__always_inline__)) {
    return data();
  }
  [[nodiscard]]
  inline T constexpr const *end() const noexcept __attribute__((__always_inline__)) {
    return data() + size();
  }
  [[nodiscard]]
  inline T constexpr const *cbegin() const noexcept __attribute__((__always_inline__)) {
    return begin();
  }
  [[nodiscard]]
  inline T constexpr const *cend() const noexcept __attribute__((__always_inline__)) {
    return end();
  }

  /**
   * Get number of elements in the vector.
   * @return number of elements (will always return 3)
   */
  [[nodiscard]]
  static inline unsigned int constexpr size() noexcept __attribute__((__always_inline__)) __attribute__((__const__)) {
    return 3u;
  }

  //-------------[ size operations ]---------------------------
  /**
   * Return square of length.
   * @return length ^ 2
   * @note This method is faster then length(). For comparison
   * of length of two vector can be used just this value, instead
   * of more expensive length() method.
   */
  [[nodiscard]]
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
    return x * x + y * y + z * z;
  }

  /**
   * Get length of vector.
   * @return length of vector
   */
  template<sqrt_mode mode = sqrt_mode::std> [[nodiscard]]
  inline T __attribute__((__always_inline__)) constexpr length() const noexcept {
    return sqrt_switchable<mode>(length_sq());
  }
  /**
   * Get length of vector, fast approximation.
   * @return length of vector
   */
  [[nodiscard]] [[deprecated("Use length<vector3<T>::sqrt_mode::fast>()")]]
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return length<sqrt_mode::fast>();
  }
  /**
   * Get length of vector, rougher fast approximation.
   * @return length of vector
   */
  [[nodiscard]] [[deprecated("Use length<vector3<T>::sqrt_mode::coarse>()")]]
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return length<sqrt_mode::coarse>();
  }
  /**
   * Return whether the vector is zero length - this is much faster than a full length calculation
   * @return whether vector is zero length
   */
  [[nodiscard]]
  inline bool constexpr length_zero() const noexcept __attribute__((__always_inline__)) {
    /*
    #ifdef VECTORSTORM_SOFT_COMPARE
      ...
    #else
      return x == static_cast<T>(0) &&
             y == static_cast<T>(0) &&
             z == static_cast<T>(0);
    #endif //VECTORSTORM_SOFT_COMPARE
    */
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
    return std::abs(x) < epsilon<T> &&
           std::abs(y) < epsilon<T> &&
           std::abs(z) < epsilon<T>;
  }

  /**
   * normalise vector
   */
  template<sqrt_mode mode = sqrt_mode::std>
  inline void __attribute__((__always_inline__)) constexpr normalise() noexcept {
    *this /= length<mode>();
  }
  [[deprecated("Use normalise<vector3<T>::sqrt_mode::fast>()")]]
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    normalise<sqrt_mode::fast>();
  }
  [[deprecated("Use normalise<vector3<T>::sqrt_mode::coarse>()")]]
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    normalise<sqrt_mode::coarse>();
  }
  template<sqrt_mode mode = sqrt_mode::std> [[nodiscard]]
  inline vector3<T> __attribute__((__always_inline__)) constexpr normalise_copy() const noexcept {
    return *this / length<mode>();
  }
  [[nodiscard]] [[deprecated("Use normalise_copy<vector3<T>::sqrt_mode::fast>()")]]
  inline vector3<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy<sqrt_mode::fast>();
  }
  [[nodiscard]] [[deprecated("Use normalise_copy<vector3<T>::sqrt_mode::coarse>()")]]
  inline vector3<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy<sqrt_mode::coarse>();
  }
  /**
   * normalise vector, with added zero safety check
   */
  template<sqrt_mode mode = sqrt_mode::std>
  inline void __attribute__((__always_inline__)) constexpr normalise_safe() noexcept {
    if(length_zero()) {
      assign();
    } else {
      normalise<mode>();
    }
  }
  template<sqrt_mode mode = sqrt_mode::std> [[nodiscard]]
  inline vector3<T> __attribute__((__always_inline__)) constexpr normalise_safe_copy() const noexcept {
    if(length_zero()) {
      return {};
    } else {
      return normalise_copy<mode>();
    }
  }

  /**
   * Absolute vector (make all values positive)
   */
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
    x = std::abs(x);
    y = std::abs(y);
    z = std::abs(z);
  }
  [[nodiscard]]
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
   * @param rhs quaternion to rotate by.
   */
  inline void constexpr rotate(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this *= rhs;
  }

  /**
   * Linear interpolation of two vectors
   * @param fact Factor of interpolation. For translation from positon
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
   * @param new_r Second Vector for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  [[nodiscard("Interpolation does not modify the input vectors")]]
  inline vector3<T> constexpr lerp(T fact, vector3<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (new_r - (*this)) * fact;
  }

  //-------------[ conversion ]--------------------------------

  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector3<T>)
   * used for passing vector3<T> values to gl*3[fd] functions.
   */
  [[nodiscard]]
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector3<T>)
   * used for passing vector3<T> values to gl*3[fd] functions.
   */
  [[nodiscard]]
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
    lhs << "[" << +rhs.x << "," << +rhs.y << "," << +rhs.z << "]";
    return lhs;
  }

  /**
   * Gets string representation.
   */
  [[nodiscard]]
  inline std::string CONSTEXPR_IF_NO_CLANG to_string() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }

  /**
   * Gets a 2D vector equivalent using the X and Y axes
   */
  [[nodiscard]]
  inline vector2<T> constexpr to_2d_xy() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x, y);
  }

  /**
   * Gets a 2D vector equivalent using the X and Z axes
   */
  [[nodiscard]]
  inline vector2<T> constexpr to_2d_xz() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x, z);
  }
};

static_assert(std::is_trivially_copyable_v<vector3<int>>);
static_assert(std::is_trivially_copyable_v<vector3<float>>);

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "vector3_types.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Standard C++ library extensions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "hash_combine.h"

namespace std {

/**
 * Gets vector containing minimal values of @a a and @a b coordinates.
 * @return Vector of minimal coordinates.
 */
template<typename T>
inline constexpr vector3<T> min(vector3<T> const &a, vector3<T> const &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector3<T> min(vector3<T> const &a, vector3<T> const &b) noexcept {
  return vector3<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
inline constexpr vector3<T> max(vector3<T> const &a, vector3<T> const &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector3<T> max(vector3<T> const &a, vector3<T> const &b) noexcept {
  return vector3<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z));
}

template<typename T>
struct hash<vector3<T>> {
  /**
   * Gets a hash value taking account of all dimensions of this vector, for use
   * in standard container maps etc.
   * Note: You need to #include <boost/functional/hash.hpp> before instantiating this if VECTORSTORM_NO_BOOST is not defined.
   * @return Hash value
   */
  size_t operator()(vector3<T> const &value) const {
    size_t hashvalue = 0;
    HASH_COMBINE(hashvalue, value.x);
    HASH_COMBINE(hashvalue, value.y);
    HASH_COMBINE(hashvalue, value.z);
    return hashvalue;
  }
};

}

/**
 * Gets a hash value taking account of all dimensions of this vector, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this if VECTORSTORM_NO_BOOST is not defined.
 * @return Hash value
 */
template<typename T>
size_t hash_value(vector3<T> const &value) {
  size_t hashvalue = 0;
  HASH_COMBINE(hashvalue, value.x);
  HASH_COMBINE(hashvalue, value.y);
  HASH_COMBINE(hashvalue, value.z);
  return hashvalue;
}
