  inline constexpr vector3(vector2<FromT> const &src, FromT new_z) noexcept
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
  inline vector3<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
#ifndef VECTORSTORM_VECTOR3_H_INCLUDED
  }
#define VECTORSTORM_VECTOR3_H_INCLUDED


  /**
#include <cmath>
   * Copy casting operator.
#include <sstream>
   * @param rhs Right hand side argument of binary operator.
#include "vectorstorm/epsilon.h"
   */
#include "vectorstorm/sincos.h"
  template<typename FromT> __attribute__((__always_inline__))
#include "vectorstorm/deg2rad.h"
  inline vector3<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
#include "vector2_forward.h"
    x = static_cast<T>(rhs.x);
#include "vector4_forward.h"
    y = static_cast<T>(rhs.y);
#include "vectorstorm/quat/quat_forward.h"
    z = static_cast<T>(rhs.z);
#include "vectorstorm/matrix/matrix3_forward.h"
    return *this;
#include "vectorstorm/matrix/matrix4_forward.h"
  }


#ifdef VMATH_NAMESPACE
  /**
namespace VMATH_NAMESPACE {
   * Copy operator to vector3 from vector4
#endif
   * @param rhs Right hand side argument of binary operator.

   */
/**
  inline vector3<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
 * Class for three dimensional vector.
    x = rhs.x;
 * There are four ways of accessing vector components.
    y = rhs.y;
 * Let's have <code>vector3f v</code>, you can either:
    z = rhs.z;
 * <ul>
    return *this;
 *  <li>access as position (x,y,z) &mdash; <code>v.x = v.y = v.z = 1;</code></li>
  }
 *  <li>access as texture coordinate (s,t,u) &mdash; <code>v.s = v.t = v.u = 1;</code></li>

 *  <li>access as colour (r,g,b) &mdash; <code>v.r = v.g = v.b = 1;</code></li>
  /**
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = 1;</code></li>
   * Copy casting operator to vector3 from vector4
 * </ul>
   * @param rhs Right hand side argument of binary operator.
 */
   */
template<typename T>
  template<typename FromT> __attribute__((__always_inline__))
class vector3 {
  inline vector3<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
public:
    x = static_cast<T>(rhs.x);
  union {
    y = static_cast<T>(rhs.y);
    /**
    z = static_cast<T>(rhs.z);
     * First element of vector, alias for X-coordinate.
    return *this;
     */
  }
    T x;


  /**
    /**
   * Move assignment operator
     * First element of vector, alias for S-coordinate.
   * @param rhs Right hand side argument of binary operator.
     * For textures notation.
   */
     */
    T s;
  inline vector3<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {

    x = std::move(rhs.x);
    /**
    y = std::move(rhs.y);
     * First element of vector, alias for R-coordinate.
    z = std::move(rhs.z);
     * For colour notation.
    return *this;
     */
  }
    T r;

  };
  /**

   * Move assignment casting operator.
  union {
   * @param rhs Right hand side argument of binary operator.
    /**
   */
     * Second element of vector, alias for Y-coordinate.
  template<typename FromT> __attribute__((__always_inline__))
     */
  inline vector3<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
    T y;
    x = static_cast<T>(std::move(rhs.x));

    y = static_cast<T>(std::move(rhs.y));
    /**
    z = static_cast<T>(std::move(rhs.z));
     * Second element of vector, alias for T-coordinate.
    return *this;
     * For textures notation.
  }
     */

    T t;
  /**

   * Move assignment operator to vector3 from vector4
    /**
   * @param rhs Right hand side argument of binary operator.
     * Second element of vector, alias for G-coordinate.
   */
     * For colour notation.
     */
  inline vector3<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    T g;
    x = std::move(rhs.x);
  };
    y = std::move(rhs.y);

    z = std::move(rhs.z);
  union {
    return *this;
    /**
  }
     * Third element of vector, alias for Z-coordinate.

     */
  /**
    T z;
   * Move assignment casting operator to vector3 from vector4

   * @param rhs Right hand side argument of binary operator.
    /**
   */
     * Third element of vector, alias for U-coordinate.
  template<typename FromT> __attribute__((__always_inline__))
     * For textures notation.
  inline vector3<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
     */
    x = static_cast<T>(std::move(rhs.x));
    T u;
    y = static_cast<T>(std::move(rhs.y));

    z = static_cast<T>(std::move(rhs.z));
    /**
    return *this;
     * Third element of vector, alias for B-coordinate.
  }
     * For colour notation.

     */
  /**
    T b;
   * Array access operator
  };

   * @param n Array index
  //----------------[ constructors ]--------------------------
   * @return For n = 0, reference to x coordinate, n = 1
  /**
   * reference to y, else reference to z
   * Creates and sets to (0,0,0)
   * y coordinate.
   */
   */
  inline constexpr vector3() noexcept __attribute__((__always_inline__))
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
    : x(0),
    return n == 0 ? x : (n == 1 ? y : z);
      y(0),
  }
      z(0) {

  }
  /**

   * Constant array access operator
  /**
   * @param n Array index
   * Creates and sets to (x,y,z)
   * @return For n = 0, reference to x coordinate, n = 1
   * @param nx initial x-coordinate value
   * reference to y, else reference to z
   * @param ny initial y-coordinate value
   * y coordinate.
   * @param nz initial z-coordinate value
   */
   */
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
  inline constexpr vector3(T nx, T ny, T nz) noexcept __attribute__((__always_inline__))
    return n == 0 ? x : (n == 1 ? y : z);
    : x(nx),
  }
      y(ny),

      z(nz) {
  //---------------[ vector arithmetic operator ]--------------
  }
  /**

   * Addition operator
  /**
   * Copy constructor.
   * @param rhs Right hand side argument of binary operator.
   * @param src Source of data for new created vector3 instance.
   */
   */
  inline vector3<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline constexpr explicit vector3(vector3<T> const &src) noexcept __attribute__((__always_inline__))
    return vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
    : x(src.x),
  }
      y(src.y),

      z(src.z) {
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Copy casting constructor.
  inline vector3<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param src Source of data for new created vector3 instance.
    return vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
   */
  }
  template<typename FromT> __attribute__((__always_inline__))

  inline constexpr explicit vector3(vector3<FromT> const &src) noexcept
  /**
    : x(static_cast<T>(src.x)),
   * Multiplication operator
      y(static_cast<T>(src.y)),
   * @param rhs Right hand side argument of binary operator.
      z(static_cast<T>(src.z)) {
   */
  }
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
  inline constexpr vector3(vector2<T> const &src, T new_z) noexcept __attribute__((__always_inline__))
  }
    : x(src.x),

      y(src.y),
  /**
      z(new_z) {
   * Division operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector3<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline constexpr vector3(vector2<FromT> const &src, FromT new_z) noexcept
    return vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
    : x(static_cast<T>(src.x)),
  }
      y(static_cast<T>(src.y)), z(static_cast<T>(new_z)) {

  }
  /**

   * Addition operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Move constructor.
   */
   * @param src Source of data for new created vector3 instance.
  inline vector3<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x += rhs.x;
  inline constexpr vector3(vector3<T> &&src) noexcept __attribute__((__always_inline__))
    y += rhs.y;
    : x(std::move(src.x)),
    z += rhs.z;
      y(std::move(src.y)),
    return *this;
      z(std::move(src.z)) {
  }
  }


  /**
  /**
   * Subtraction operator
   * Move casting constructor.
   * @param rhs Right hand side argument of binary operator.
   * @param src Source of data for new created vector3 instance.
   */
   */
  inline vector3<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    x -= rhs.x;
  inline constexpr vector3(vector3<FromT> &&src) noexcept
    y -= rhs.y;
    : x(static_cast<T>(std::move(src.x))),
    z -= rhs.z;
      y(static_cast<T>(std::move(src.y))),
    return *this;
      z(static_cast<T>(std::move(src.z))) {
  }
  }


  /**
  inline constexpr vector3(vector2<T> &&src, T new_z) noexcept __attribute__((__always_inline__))
   * Multiplication operator
    : x(std::move(src.x)),
   * @param rhs Right hand side argument of binary operator.
      y(std::move(src.y)),
   */
      z(std::move(new_z)) {
  }
  inline vector3<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x *= rhs.x;
  template<typename FromT> __attribute__((__always_inline__))
    y *= rhs.y;
  inline constexpr vector3(vector2<FromT> &&src, FromT new_z) noexcept
    z *= rhs.z;
    : x(static_cast<T>(std::move(src.x))),
    return *this;
      y(static_cast<T>(std::move(src.y))),
  }
      z(static_cast<T>(std::move(new_z))) {

  }
  /**

   * Division operator
  //----------------[ assignment ]-------------------------
   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Sets to (x,y,z)
  inline vector3<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param nx initial x-coordinate value
    x /= rhs.x;
   * @param ny initial y-coordinate value
    y /= rhs.y;
   * @param nz initial z-coordinate value
    z /= rhs.z;
   */
    return *this;
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0) noexcept __attribute__((__always_inline__)) {
  }
    x = nx;

    y = ny;
  /**
    z = nz;
   * Addition operator with a 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //----------------[ access operators ]-------------------
  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
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
  inline vector3<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
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
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : z);
  }

  /**
   * Constant array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y, else reference to z
   * y coordinate.
   */
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : z);
  }

  //---------------[ vector arithmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
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

  inline vector3<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
   * Multiplication operator
    return vector3<T>(x + rhs.x, y + rhs.y, z);
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x *= rhs.x;
   * Subtraction operator with a 2-vector
    y *= rhs.y;
   * @param rhs Right hand side argument of binary operator.
    z *= rhs.z;
   */
    return *this;
  inline vector3<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector3<T>(x - rhs.x, y - rhs.y, z);

  }
  /**

   * Division operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator with a 2-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x /= rhs.x;
    y /= rhs.y;
  inline vector3<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    z /= rhs.z;
    return vector3<T>(x * rhs.x, y * rhs.y, z);
    return *this;
  }
  }


  /**
  /**
   * Division operator with a 2-vector
   * Addition operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector3<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x / rhs.x, y / rhs.y, z);
    return vector3<T>(x + rhs.x, y + rhs.y, z);
  }
  }


  /**
  /**
   * Addition operator with a 2-vector
   * Subtraction operator with a 2-vector
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector3<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    return vector3<T>(x - rhs.x, y - rhs.y, z);
    y += rhs.y;
  }
    return *this;

  }
  /**

   * Multiplication operator with a 2-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Subtraction operator with a 2-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector3<T>(x * rhs.x, y * rhs.y, z);
  inline vector3<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }

    x -= rhs.x;
  /**
    y -= rhs.y;
   * Division operator with a 2-vector
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector3<T>(x / rhs.x, y / rhs.y, z);
   * Multiplication operator with a 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector3<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Addition operator with a 2-vector
    x *= rhs.x;
   * @param rhs Right hand side argument of binary operator.
    y *= rhs.y;
   */
    return *this;
  inline vector3<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x += rhs.x;

    y += rhs.y;
  /**
    return *this;
   * Division operator with a 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector3<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Subtraction operator with a 2-vector
    x /= rhs.x;
   * @param rhs Right hand side argument of binary operator.
    y /= rhs.y;
   */
    return *this;
  inline vector3<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x -= rhs.x;

    y -= rhs.y;
  /**
    return *this;
   * Dot product of two vectors.
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
   * Multiplication operator with a 2-vector
  inline T constexpr dotProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return x * rhs.x + y * rhs.y + z * rhs.z;
   */
  }

  inline vector3<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x *= rhs.x;
   * Cross product of two vectors
    y *= rhs.y;
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr crossProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector3<T>(y * rhs.z - rhs.y * z, z * rhs.x - rhs.z * x, x * rhs.y - rhs.x * y);
   * Division operator with a 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //--------------[ rotation with quaternions ]-----------------
  inline vector3<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  // see http://mollyrocket.com/forums/viewtopic.php?t=833&sid=3a84e00a70ccb046cfc87ac39881a3d0
    x /= rhs.x;
  /**
    y /= rhs.y;
   * Multiplication by quaternion operator (rotation by quaternion)
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return *this + (rhs.v.crossProduct(*this) * static_cast<T>(2) * rhs.w) + rhs.v.crossProduct(rhs.v.crossProduct(*this) * static_cast<T>(2));
   * Dot product of two vectors.
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline T constexpr dotProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Multiplication by quaternion operator (rotation by quaternion)
    return x * rhs.x + y * rhs.y + z * rhs.z;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  /**
  inline vector3<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Cross product of two vectors
    vector3<T> const temp = rhs.v.crossProduct(*this) * static_cast<T>(2);
   * @param rhs Right hand side argument of binary operator.
    *this += (temp * rhs.w) + rhs.v.crossProduct(temp);
   */
    return *this;
  inline vector3<T> constexpr crossProduct(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }

    return vector3<T>(y * rhs.z - rhs.y * z, z * rhs.x - rhs.z * x, x * rhs.y - rhs.x * y);
  }
  //--------------[ scalar vector operator ]--------------------

  /**
  //--------------[ rotation with quaternions ]-----------------
   * Addition operator
  // see http://mollyrocket.com/forums/viewtopic.php?t=833&sid=3a84e00a70ccb046cfc87ac39881a3d0
   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Multiplication by quaternion operator (rotation by quaternion)
  inline vector3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector3<T>(x + rhs, y + rhs, z + rhs);
   */
  }
  inline vector3<T> constexpr operator*(quaternion<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return *this + (rhs.v.crossProduct(*this) * static_cast<T>(2) * rhs.w) + rhs.v.crossProduct(rhs.v.crossProduct(*this) * static_cast<T>(2));
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Multiplication by quaternion operator (rotation by quaternion)
  inline vector3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector3<T>(x - rhs, y - rhs, z - rhs);
   */
  }
  inline vector3<T> constexpr &operator*=(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    vector3<T> const temp = rhs.v.crossProduct(*this) * static_cast<T>(2);
  /**
    *this += (temp * rhs.w) + rhs.v.crossProduct(temp);
   * Multiplication operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  //--------------[ scalar vector operator ]--------------------
    return vector3<T>(x * rhs, y * rhs, z * rhs);
  /**
  }
   * Addition operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Division operator
  inline vector3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector3<T>(x + rhs, y + rhs, z + rhs);
   */
  }
  inline vector3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {

    return vector3<T>(x / rhs, y / rhs, z / rhs);
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Addition operator
  inline vector3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector3<T>(x - rhs, y - rhs, z - rhs);
   */
  }

  inline vector3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x += rhs;
   * Multiplication operator
    y += rhs;
   * @param rhs Right hand side argument of binary operator.
    z += rhs;
   */
    return *this;
  inline vector3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector3<T>(x * rhs, y * rhs, z * rhs);

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Division operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    x -= rhs;
  inline vector3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    y -= rhs;
    return vector3<T>(x / rhs, y / rhs, z / rhs);
    z -= rhs;
  }
    return *this;

  }
  /**

   * Addition operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    x += rhs;
  inline vector3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    y += rhs;
    x *= rhs;
    z += rhs;
    y *= rhs;
    return *this;
    z *= rhs;
  }
    return *this;

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Division operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    x -= rhs;
  inline vector3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    y -= rhs;
    x /= rhs;
    z -= rhs;
    y /= rhs;
    return *this;
    z /= rhs;
  }
    return *this;

  }
  /**

   * Multiplication operator
  //-------------[ matrix operations ]-------------------------
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   * Multiplication by 3x3 matrix operator
    x *= rhs;
   * @param rhs Right hand side argument of binary operator.
    y *= rhs;
   */
    z *= rhs;
    return *this;
  inline vector3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    *this = rhs * *this;

    return *this;
  /**
  }
   * Division operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Multiplication by 4x4 matrix operator
  inline vector3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    x /= rhs;
   */
    y /= rhs;
  inline vector3<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    z /= rhs;
    *this = rhs * *this;
    return *this;
    return *this;
  }
  }


  //-------------[ matrix operations ]-------------------------
  //-------------[ equality operator ]-------------------------

  /**
  /**
   * Equality test operator
   * Multiplication by 3x3 matrix operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   */
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
  inline vector3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * same for y-coordinate, and z-coordinate.
    *this = rhs * *this;
   */
    return *this;
  }
  inline bool constexpr operator==(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    #ifdef VMATH_SOFT_COMPARE
  /**
      return std::abs(x - rhs.x) < static_cast<T>(epsilon) &&
   * Multiplication by 4x4 matrix operator
             std::abs(y - rhs.y) < static_cast<T>(epsilon) &&
   * @param rhs Right hand side argument of binary operator.
             std::abs(z - rhs.z) < static_cast<T>(epsilon);
   */
    #else
  inline vector3<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
      return x == rhs.x &&
    *this = rhs * *this;
             y == rhs.y &&
    return *this;
             z == rhs.z;
  }
    #endif // VMATH_SOFT_COMPARE

  }
  //-------------[ equality operator ]-------------------------

  /**
  /**
   * Equality test operator
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * @return not (lhs == rhs) :-P
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
   */
   * same for y-coordinate, and z-coordinate.
  inline bool constexpr operator!=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return !(*this == rhs);
  inline bool constexpr operator==(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    #ifdef VMATH_SOFT_COMPARE

      return std::abs(x - rhs.x) < static_cast<T>(epsilon) &&
  //-------------[ unary operations ]--------------------------
             std::abs(y - rhs.y) < static_cast<T>(epsilon) &&
  /**
             std::abs(z - rhs.z) < static_cast<T>(epsilon);
   * Unary negate operator
    #else
   * @return negated vector
      return x == rhs.x &&
   */
             y == rhs.y &&
  inline vector3<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
             z == rhs.z;
    return vector3<T>(-x, -y, -z);
    #endif // VMATH_SOFT_COMPARE
  }
  }


  //-------------[ size operations ]---------------------------
  /**
  /**
   * Inequality test operator
   * Return square of length.
   * @param rhs Right hand side argument of binary operator.
   * @return length ^ 2
   * @return not (lhs == rhs) :-P
   * @note This method is faster then length(). For comparison
   */
   * of length of two vector can be used just this value, instead
  inline bool constexpr operator!=(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * of more expensive length() method.
    return !(*this == rhs);
   */
  }
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {

    return x * x + y * y + z * z;
  //-------------[ unary operations ]--------------------------
  }
  /**
   * Unary negate operator
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
   * @return negated vector
    return length_sq();
   */
  }
  inline vector3<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {

    return vector3<T>(-x, -y, -z);
  /**
  }
   * Get length of vector.

   * @return length of vector
  //-------------[ size operations ]---------------------------
   */
  /**
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
   * Return square of length.
    return static_cast<T>(std::sqrt(length_sq()));
   * @return length ^ 2
  }
   * @note This method is faster then length(). For comparison
  /**
   * of length of two vector can be used just this value, instead
   * Get length of vector, fast approximation.
   * of more expensive length() method.
   * @return length of vector
   */
   */
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return x * x + y * y + z * z;
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  }
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
  /**
    return length_sq();
   * Get length of vector, rougher fast approximation.
  }
   * @return length of vector

   */
  /**
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
   * Get length of vector.
    return static_cast<T>(sqrt_faster(length_sq()));
   * @return length of vector
  }
   */

  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
  /**
    return static_cast<T>(std::sqrt(length_sq()));
   * normalise vector
  }
   */
  /**
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
   * Get length of vector, fast approximation.
    T const temp = length();
   * @return length of vector
    x /= temp;
   */
    y /= temp;
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    z /= temp;
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  }
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
  /**
    T const temp = length_fast();
   * Get length of vector, rougher fast approximation.
    x /= temp;
   * @return length of vector
    y /= temp;
   */
    z /= temp;
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
  }
    return static_cast<T>(sqrt_faster(length_sq()));
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
  }
    T const temp = length_faster();

    x /= temp;
  /**
    y /= temp;
   * normalise vector
    z /= temp;
   */
  }
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    T const temp = length();
    normalise();
    x /= temp;
  }
    y /= temp;
    z /= temp;
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    normalise_fast();
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
  }
    T const temp = length_fast();
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    x /= temp;
    normalise_faster();
    y /= temp;
  }
    z /= temp;
  inline vector3<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
  }
    T const temp(length());
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x / temp, y / temp, z / temp);
    T const temp = length_faster();
  }
    x /= temp;
  inline vector3<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    y /= temp;
    T const temp(length_fast());
    z /= temp;
    return vector3<T>(x / temp, y / temp, z / temp);
  }
  }
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline vector3<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    normalise();
    T const temp(length_faster());
  }
    return vector3<T>(x / temp, y / temp, z / temp);
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    normalise_fast();
  inline vector3<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    return normalise_copy();
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    normalise_faster();
  inline vector3<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    return normalise_copy_fast();
  inline vector3<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
  }
    T const temp(length());
  inline vector3<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return vector3<T>(x / temp, y / temp, z / temp);
    return normalise_copy_faster();
  }
  }
  inline vector3<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
  /**
    T const temp(length_fast());
   * normalise vector. with added zero safety check
    return vector3<T>(x / temp, y / temp, z / temp);
   */
  }
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    T const temp = length();
    T const temp(length_faster());
    if(temp == static_cast<T>(0)) {
    return vector3<T>(x / temp, y / temp, z / temp);
      x = static_cast<T>(0);
  }
      y = static_cast<T>(0);
  inline vector3<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      z = static_cast<T>(0);
    return normalise_copy();
    } else {
  }
      x /= temp;
  inline vector3<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      y /= temp;
    return normalise_copy_fast();
      z /= temp;
  }
    }
  inline vector3<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    return normalise_copy_faster();
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    normalise_safe();
  /**
  }
   * normalise vector. with added zero safety check
  inline vector3<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
   */
    T const temp(length());
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
    if(temp == static_cast<T>(0)) {
    T const temp = length();
      return vector3<T>();
    if(temp == static_cast<T>(0)) {
    } else {
      x = static_cast<T>(0);
      return vector3<T>(x / temp, y / temp, z / temp);
      y = static_cast<T>(0);
    }
      z = static_cast<T>(0);
  }
    } else {
      x /= temp;
  inline vector3<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      y /= temp;
    return normalise_safe_copy();
      z /= temp;
  }
    }

  }
  /**
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * Absolute vector (make all values positive)
    normalise_safe();
   */
  }
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    x = std::abs(x);
    T const temp(length());
    y = std::abs(y);
    if(temp == static_cast<T>(0)) {
    z = std::abs(z);
      return vector3<T>();
  }
    } else {
  inline vector3<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
      return vector3<T>(x / temp, y / temp, z / temp);
    return vector3<T>(std::abs(x), std::abs(y), std::abs(z));
    }
  }
  }

  inline vector3<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  //-------------[ other operations ]--------------------------
    return normalise_safe_copy();
  /**
  }
   * Rotate vector around three axis.

   * @param ax Angle (in degrees) to be rotated around X-axis.
  /**
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   * Absolute vector (make all values positive)
   * @param az Angle (in degrees) to be rotated around Z-axis.
   */
   */
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
  inline void constexpr rotate(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
    x = std::abs(x);
    rotate_rad(deg2rad(ax), deg2rad(ay), deg2rad(az));
    y = std::abs(y);
  }
    z = std::abs(z);
  /**
  }
   * Rotate vector around three axis, radian version.
  inline vector3<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
   * @param ax Angle (in radians) to be rotated around X-axis.
    return vector3<T>(std::abs(x), std::abs(y), std::abs(z));
   * @param ay Angle (in radians) to be rotated around Y-axis.
  }

   * @param az Angle (in radians) to be rotated around Z-axis.
  //-------------[ other operations ]--------------------------
   */
  /**
  inline void constexpr rotate_rad(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
   * Rotate vector around three axis.
    T cos_x = static_cast<T>(0);
   * @param ax Angle (in degrees) to be rotated around X-axis.
    T sin_x = static_cast<T>(0);
   * @param ay Angle (in degrees) to be rotated around Y-axis.
    T cos_y = static_cast<T>(0);
   * @param az Angle (in degrees) to be rotated around Z-axis.
    T sin_y = static_cast<T>(0);
   */
    T cos_z = static_cast<T>(0);
  inline void constexpr rotate(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
    T sin_z = static_cast<T>(0);
    rotate_rad(deg2rad(ax), deg2rad(ay), deg2rad(az));
    sincos_any(ax, sin_x, cos_x);
  }
    sincos_any(ay, sin_y, cos_y);
  /**
    sincos_any(az, sin_z, cos_z);
   * Rotate vector around three axis, radian version.
    T const nx = static_cast<T>(((cos_y *                         cos_z) * x) - ((cos_y *                         sin_z) * y) + (sin_y *         z));
   * @param ax Angle (in radians) to be rotated around X-axis.
    T const ny = static_cast<T>(((cos_x * sin_z + sin_x * sin_y * cos_z) * x) + ((cos_x * cos_z - sin_x * sin_y * sin_z) * y) - (sin_x * cos_y * z));
   * @param ay Angle (in radians) to be rotated around Y-axis.
    T const nz = static_cast<T>(((sin_x * sin_z - cos_x * sin_y * cos_z) * x) + ((cos_x * sin_y * sin_z + sin_x * cos_z) * y) + (cos_x * cos_y * z));
   * @param az Angle (in radians) to be rotated around Z-axis.
    x = nx;
   */
    y = ny;
  inline void constexpr rotate_rad(T ax, T ay, T az) noexcept __attribute__((__always_inline__)) {
    z = nz;
    T cos_x = static_cast<T>(0);
  }
    T sin_x = static_cast<T>(0);
  /**
    T cos_y = static_cast<T>(0);
   * Rotate vector around the X axis.
    T sin_y = static_cast<T>(0);
   * @param ax Angle (in degrees) to be rotated around X-axis.
    T cos_z = static_cast<T>(0);
   */
    T sin_z = static_cast<T>(0);
  inline void constexpr rotate_x(T ax) noexcept __attribute__((__always_inline__)) {
    sincos_any(ax, sin_x, cos_x);
    rotate_rad_x(deg2rad(ax));
    sincos_any(ay, sin_y, cos_y);
  }
    sincos_any(az, sin_z, cos_z);
  /**
    T const nx = static_cast<T>(((cos_y *                         cos_z) * x) - ((cos_y *                         sin_z) * y) + (sin_y *         z));
   * Rotate vector around the Y axis.
    T const ny = static_cast<T>(((cos_x * sin_z + sin_x * sin_y * cos_z) * x) + ((cos_x * cos_z - sin_x * sin_y * sin_z) * y) - (sin_x * cos_y * z));
   * @param ay Angle (in degrees) to be rotated around Y-axis.
    T const nz = static_cast<T>(((sin_x * sin_z - cos_x * sin_y * cos_z) * x) + ((cos_x * sin_y * sin_z + sin_x * cos_z) * y) + (cos_x * cos_y * z));
   */
    x = nx;
  inline void constexpr rotate_y(T ay) noexcept __attribute__((__always_inline__)) {
    y = ny;
    rotate_rad_y(deg2rad(ay));
    z = nz;
  }
  }
  /**
  /**
   * Rotate vector around the Z axis.
   * Rotate vector around the X axis.
   * @param az Angle (in degrees) to be rotated around Z-axis.
   * @param ax Angle (in degrees) to be rotated around X-axis.
   */
   */
  inline void constexpr rotate_z(T az) noexcept __attribute__((__always_inline__)) {
  inline void constexpr rotate_x(T ax) noexcept __attribute__((__always_inline__)) {
    rotate_rad_z(deg2rad(az));
    rotate_rad_x(deg2rad(ax));
  }
  }
  /**
  /**
   * Rotate vector around the X axis, radian version.
   * Rotate vector around the Y axis.
   * @param ax Angle (in radians) to be rotated around X-axis.
   * @param ay Angle (in degrees) to be rotated around Y-axis.
   */
   */
  inline void constexpr rotate_rad_x(T ax) noexcept __attribute__((__always_inline__)) {
  inline void constexpr rotate_y(T ay) noexcept __attribute__((__always_inline__)) {
    T cos_x = static_cast<T>(0);
    rotate_rad_y(deg2rad(ay));
    T sin_x = static_cast<T>(0);
  }
    sincos_any(ax, sin_x, cos_x);
  /**
    T const ny = static_cast<T>((cos_x * y) - (sin_x * z));
   * Rotate vector around the Z axis.
    T const nz = static_cast<T>((cos_x * z) + (sin_x * y));
   * @param az Angle (in degrees) to be rotated around Z-axis.
    y = ny;
   */
    z = nz;
  inline void constexpr rotate_z(T az) noexcept __attribute__((__always_inline__)) {
  }
    rotate_rad_z(deg2rad(az));
  /**
  }
  /**
   * Rotate vector around the Y axis, radian version.
   * Rotate vector around the X axis, radian version.
   * @param ay Angle (in radians) to be rotated around Y-axis.
   * @param ax Angle (in radians) to be rotated around X-axis.
   */
   */
  inline void constexpr rotate_rad_y(T ay) noexcept __attribute__((__always_inline__)) {
  inline void constexpr rotate_rad_x(T ax) noexcept __attribute__((__always_inline__)) {
    T cos_y = static_cast<T>(0);
    T cos_x = static_cast<T>(0);
    T sin_y = static_cast<T>(0);
    T sin_x = static_cast<T>(0);
    sincos_any(ay, sin_y, cos_y);
    sincos_any(ax, sin_x, cos_x);
    T const nx = static_cast<T>((cos_y * x) + (sin_y * z));
    T const ny = static_cast<T>((cos_x * y) - (sin_x * z));
    T const nz = static_cast<T>((cos_y * z) - (sin_y * x));
    T const nz = static_cast<T>((cos_x * z) + (sin_x * y));
    x = nx;
    y = ny;
    z = nz;
    z = nz;
  }
  }
  /**
  /**
   * Rotate vector around the Z axis, radian version.
   * Rotate vector around the Y axis, radian version.
   * @param az Angle (in radians) to be rotated around Z-axis.
   * @param ay Angle (in radians) to be rotated around Y-axis.
   */
   */
  inline void constexpr rotate_rad_z(T az) noexcept __attribute__((__always_inline__)) {
  inline void constexpr rotate_rad_y(T ay) noexcept __attribute__((__always_inline__)) {
    T cos_z = static_cast<T>(0);
    T cos_y = static_cast<T>(0);
    T sin_z = static_cast<T>(0);
    T sin_y = static_cast<T>(0);
    sincos_any(az, sin_z, cos_z);
    sincos_any(ay, sin_y, cos_y);
    T const nx = static_cast<T>((cos_z * x) - (sin_z * y));
    T const nx = static_cast<T>((cos_y * x) + (sin_y * z));
    T const ny = static_cast<T>((cos_z * y) + (sin_z * x));
    T const nz = static_cast<T>((cos_y * z) - (sin_y * x));
    x = nx;
    x = nx;
    y = ny;
    z = nz;
  }
  }
  /**
  /**
   * Rotate vector by a quaternion.
   * Rotate vector around the Z axis, radian version.
   * @param ax quaternion to rotate by.
   * @param az Angle (in radians) to be rotated around Z-axis.
   */
   */
  inline void constexpr rotate(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline void constexpr rotate_rad_z(T az) noexcept __attribute__((__always_inline__)) {
    *this *= rhs;
    T cos_z = static_cast<T>(0);
  }
    T sin_z = static_cast<T>(0);

    sincos_any(az, sin_z, cos_z);
  /**
    T const nx = static_cast<T>((cos_z * x) - (sin_z * y));
   * Linear interpolation of two vectors
    T const ny = static_cast<T>((cos_z * y) + (sin_z * x));
    x = nx;
   * @param fact Factor of interpolation. For translation from positon
    y = ny;
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
  }
   * @param r Second Vector for interpolation
  /**
   * @note However values of fact parameter are reasonable only in interval
   * Rotate vector by a quaternion.
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * @param ax quaternion to rotate by.
   * can get result (extrapolation?)
   */
   */
  inline void constexpr rotate(quaternion<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr lerp(T fact, vector3<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
    *this *= rhs;
    return (*this) + (new_r - (*this)) * fact;
  }
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
constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept {
  return vector3<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept {
  return vector3<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z));
}


}
#endif // VECTORSTORM_VECTOR3_H_INCLUDED

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
constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) noexcept {
  return vector3<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) noexcept {
  return vector3<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z));
}


}
#endif // VECTORSTORM_VECTOR3_H_INCLUDED
