#ifndef VECTORSTORM_VECTOR4_H_INCLUDED
#ifndef VECTORSTORM_VECTOR4_H_INCLUDED
#define VECTORSTORM_VECTOR4_H_INCLUDED
#define VECTORSTORM_VECTOR4_H_INCLUDED


#include <cmath>
#include <cmath>
#include <sstream>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/epsilon.h"
#include "vector2_forward.h"
#include "vector2_forward.h"
#include "vector3_forward.h"
#include "vector3_forward.h"
#include "vectorstorm/matrix/matrix3_forward.h"
#include "vectorstorm/matrix/matrix3_forward.h"
#include "vectorstorm/matrix/matrix4_forward.h"
#include "vectorstorm/matrix/matrix4_forward.h"


#ifdef VMATH_NAMESPACE
#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
namespace VMATH_NAMESPACE {
#endif
#endif


/**
/**
 * Class for four dimensional vector.
 * Class for four dimensional vector.
 * There are four ways of accessing vector components.
 * There are four ways of accessing vector components.
 * Let's have <code>vector4f v</code>, you can either:
 * Let's have <code>vector4f v</code>, you can either:
 * <ul>
 * <ul>
 *  <li>access as position in projective space (x,y,z,w) &mdash; <code>v.x = v.y = v.z = v.w = 1;</code></li>
 *  <li>access as position in projective space (x,y,z,w) &mdash; <code>v.x = v.y = v.z = v.w = 1;</code></li>
 *  <li>access as texture coordinate (s,t,u,v) &mdash; <code>v.s = v.t = v.u = v.v = 1;</code></li>
 *  <li>access as texture coordinate (s,t,u,v) &mdash; <code>v.s = v.t = v.u = v.v = 1;</code></li>
 *  <li>access as colour (r,g,b,a) &mdash; <code>v.r = v.g = v.b = v.a = 1;</code></li>
 *  <li>access as colour (r,g,b,a) &mdash; <code>v.r = v.g = v.b = v.a = 1;</code></li>
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = v[3] = 1;</code></li>
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = v[3] = 1;</code></li>
 * </ul>
 * </ul>
 */
 */
template<typename T>
template<typename T>
class vector4 {
class vector4 {
public:
public:
  union {
  union {
    /**
    /**
     * First element of vector, alias for R-coordinate.
     * First element of vector, alias for R-coordinate.
     * For colour notation.
     * For colour notation.
     */
     */
    T r
    T r


    /**
    /**
     * First element of vector, alias for X-coordinate.
     * First element of vector, alias for X-coordinate.
     */;
     */;
    T x;
    T x;
  };
  };


  union {
  union {
    /**
    /**
     * Second element of vector, alias for G-coordinate.
     * Second element of vector, alias for G-coordinate.
     * For colour notation.
     * For colour notation.
     */
     */
    T g;
    T g;


    /**
    /**
     * Second element of vector, alias for Y-coordinate.
     * Second element of vector, alias for Y-coordinate.
     */
     */
    T y;
    T y;
  };
  };


  union {
  union {
    /**
    /**
     * Third element of vector, alias for B-coordinate.
     * Third element of vector, alias for B-coordinate.
     * For colour notation.
     * For colour notation.
     */
     */
    T b;
    T b;


    /**
    /**
     * Third element of vector, alias for Z-coordinate.
     * Third element of vector, alias for Z-coordinate.
     */
     */
    T z;
    T z;
  };
  };


  union {
  union {
    /**
    /**
     * Fourth element of vector, alias for A-coordinate.
     * Fourth element of vector, alias for A-coordinate.
     * For colour notation. This represnt aplha channel
     * For colour notation. This represnt aplha channel
     */
     */
    T a;
    T a;


    /**
    /**
     * Fourth element of vector, alias for W-coordinate.
     * Fourth element of vector, alias for W-coordinate.
     * @note For vectors (such as normals) should be set to 0.0
     * @note For vectors (such as normals) should be set to 0.0
     * For vertices should be set to 1.0
     * For vertices should be set to 1.0
     */
     */
    T w;
    T w;
  };
  };


  //----------------[ constructors ]--------------------------
  //----------------[ constructors ]--------------------------
  /**
  /**
   * Creates and sets to (0,0,0,0)
   * Creates and sets to (0,0,0,0)
   */
   */
  inline constexpr vector4() noexcept __attribute__((__always_inline__))
  inline constexpr vector4() noexcept __attribute__((__always_inline__))
    : x(0),
    : x(0),
      y(0),
      y(0),
      z(0),
      z(0),
      w(0) {
      w(0) {
  }
  }


  /**
  /**
   * Creates and sets to (x,y,z,z)
   * Creates and sets to (x,y,z,z)
   * @param nx initial x-coordinate value (R)
   * @param nx initial x-coordinate value (R)
   * @param ny initial y-coordinate value (G)
   * @param ny initial y-coordinate value (G)
   * @param nz initial z-coordinate value (B)
   * @param nz initial z-coordinate value (B)
   * @param nw initial w-coordinate value (Alpha)
   * @param nw initial w-coordinate value (Alpha)
   */
   */
  inline constexpr vector4(T nx, T ny, T nz, T nw) noexcept __attribute__((__always_inline__))
  inline constexpr vector4(T nx, T ny, T nz, T nw) noexcept __attribute__((__always_inline__))
    : x(nx),
    : x(nx),
      y(ny),
      y(ny),
      z(nz),
      z(nz),
      w(nw) {
      w(nw) {
  }
  }


  /**
  /**
   * Copy constructor.
   * Copy constructor.
   * @param src Source of data for new created vector4 instance.
   * @param src Source of data for new created vector4 instance.
   */
   */
  inline constexpr explicit vector4(vector4<T> const &src) noexcept __attribute__((__always_inline__))
  inline constexpr explicit vector4(vector4<T> const &src) noexcept __attribute__((__always_inline__))
    : x(src.x),
    : x(src.x),
      y(src.y),
      y(src.y),
      z(src.z),
      z(src.z),
      w(src.w) {
      w(src.w) {
  }
  }


  /**
  /**
   * Copy casting constructor.
   * Copy casting constructor.
   * @param src Source of data for new created vector4 instance.
   * @param src Source of data for new created vector4 instance.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector4(vector4<FromT> const &src) noexcept
  inline constexpr explicit vector4(vector4<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)),
      z(static_cast<T>(src.z)),
      w(static_cast<T>(src.w)) {
      w(static_cast<T>(src.w)) {
  }
  }


  inline constexpr vector4(vector3<T> const &src, T new_w) noexcept __attribute__((__always_inline__))
  inline constexpr vector4(vector3<T> const &src, T new_w) noexcept __attribute__((__always_inline__))
    : x(src.x),
    : x(src.x),
      y(src.y),
      y(src.y),
      z(src.z),
      z(src.z),
      w(new_w) {
      w(new_w) {
  }
  }


  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector4(vector3<FromT> const &src, FromT new_w) noexcept
  inline constexpr vector4(vector3<FromT> const &src, FromT new_w) noexcept
    : x(static_cast<T>(src.x)),
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)),
      z(static_cast<T>(src.z)),
      w(static_cast<T>(new_w)) {
      w(static_cast<T>(new_w)) {
  }
  }


  /**
  /**
   * Move constructor.
   * Move constructor.
   * @param src Source of data for new created vector4 instance.
   * @param src Source of data for new created vector4 instance.
   */
   */
  inline constexpr vector4(vector4<T> &&src) noexcept __attribute__((__always_inline__))
  inline constexpr vector4(vector4<T> &&src) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
    : x(std::move(src.x)),
      y(std::move(src.y)),
      y(std::move(src.y)),
      z(std::move(src.z)),
      z(std::move(src.z)),
      w(std::move(src.w)) {
      w(std::move(src.w)) {
  }
  }


  /**
  /**
   * Move casting constructor.
   * Move casting constructor.
   * @param src Source of data for new created vector4 instance.
   * @param src Source of data for new created vector4 instance.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector4(vector4<FromT> &&src) noexcept
  inline constexpr vector4(vector4<FromT> &&src) noexcept
    : x(static_cast<T>(std::move(src.x))),
    : x(static_cast<T>(std::move(src.x))),
      y(static_cast<T>(std::move(src.y))),
      y(static_cast<T>(std::move(src.y))),
      z(static_cast<T>(std::move(src.z))),
      z(static_cast<T>(std::move(src.z))),
      w(static_cast<T>(std::move(src.w))) {
      w(static_cast<T>(std::move(src.w))) {
  }
  }


  //----------------[ assignment ]-------------------------
  //----------------[ assignment ]-------------------------
  /**
  /**
   * Sets to (x,y,z)
   * Sets to (x,y,z)
   * @param nx initial x-coordinate value
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   * @param ny initial y-coordinate value
   * @param nz initial z-coordinate value
   * @param nz initial z-coordinate value
   * @param nz initial w-coordinate value
   * @param nz initial w-coordinate value
   */
   */
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0, T nw = 0) noexcept __attribute__((__always_inline__)) {
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0, T nw = 0) noexcept __attribute__((__always_inline__)) {
    x = nx;
    x = nx;
    y = ny;
    y = ny;
    z = nz;
    z = nz;
    w = nw;
    w = nw;
  }
  }


  //----------------[ access operators ]-------------------
  //----------------[ access operators ]-------------------
  /**
  /**
   * Copy operator
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x = rhs.x;
    x = rhs.x;
    y = rhs.y;
    y = rhs.y;
    z = rhs.z;
    z = rhs.z;
    w = rhs.w;
    w = rhs.w;
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Copy casting operator
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
  inline vector4<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    z = static_cast<T>(rhs.z);
    w = static_cast<T>(rhs.w);
    w = static_cast<T>(rhs.w);
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Copy operator to vector4 from vector3
   * Copy operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x = rhs.x;
    x = rhs.x;
    y = rhs.y;
    y = rhs.y;
    z = rhs.z;
    z = rhs.z;
    w = static_cast<T>(0);
    w = static_cast<T>(0);
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Copy casting operator to vector4 from vector3
   * Copy casting operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
  inline vector4<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    z = static_cast<T>(rhs.z);
    w = static_cast<T>(0);
    w = static_cast<T>(0);
    return *this;
    return *this;
  }
  }




  /**
  /**
   * Move assignment operator
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    z = std::move(rhs.z);
    w = std::move(rhs.w);
    w = std::move(rhs.w);
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Move assignment casting operator.
   * Move assignment casting operator.
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
  inline vector4<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
    x = static_cast<T>(std::move(rhs.x));
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    z = static_cast<T>(std::move(rhs.z));
    w = static_cast<T>(std::move(rhs.w));
    w = static_cast<T>(std::move(rhs.w));
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Move assignment operator to vector4 from vector3
   * Move assignment operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    z = std::move(rhs.z);
    w = static_cast<T>(0);
    w = static_cast<T>(0);
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Move assignment casting operator to vector4 from vector3
   * Move assignment casting operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
  inline vector4<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
    x = static_cast<T>(std::move(rhs.x));
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    z = static_cast<T>(std::move(rhs.z));
    w = static_cast<T>(0);
    w = static_cast<T>(0);
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Array access operator
   * Array access operator
   * @param n Array index
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y coordinate, n = 2 reference to z,
   * reference to y coordinate, n = 2 reference to z,
   * else reference to w coordinate.
   * else reference to w coordinate.
   */
   */
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
  }
  }


  /**
  /**
   * Array access operator
   * Array access operator
   * @param n Array index
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y coordinate, n = 2 reference to z,
   * reference to y coordinate, n = 2 reference to z,
   * else reference to w coordinate.
   * else reference to w coordinate.
   */
   */
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
  }
  }


  //---------------[ vector aritmetic operator ]--------------
  //---------------[ vector aritmetic operator ]--------------
  /**
  /**
   * Addition operator
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator+(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator+(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
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
  inline vector4<T> constexpr operator-(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator-(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
  }
  }


  /**
  /**
   * Multiplication operator
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
  }
  }


  /**
  /**
   * Division operator
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator/(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator/(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
  }
  }


  /**
  /**
   * Addition operator
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr &operator+=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator+=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    x += rhs.x;
    y += rhs.y;
    y += rhs.y;
    z += rhs.z;
    z += rhs.z;
    w += rhs.w;
    w += rhs.w;
    return *this;
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
  inline vector4<T> constexpr &operator-=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator-=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    x -= rhs.x;
    y -= rhs.y;
    y -= rhs.y;
    z -= rhs.z;
    z -= rhs.z;
    w -= rhs.w;
    w -= rhs.w;
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Multiplication operator
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr &operator*=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator*=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    x *= rhs.x;
    y *= rhs.y;
    y *= rhs.y;
    z *= rhs.z;
    z *= rhs.z;
    w *= rhs.w;
    w *= rhs.w;
    return *this;
    return *this;
  }
  }


  /**
   * Division operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Division operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr &operator/=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x /= rhs.x;
  inline vector4<T> constexpr &operator/=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    y /= rhs.y;
    x /= rhs.x;
    z /= rhs.z;
    y /= rhs.y;
    w /= rhs.w;
    z /= rhs.z;
    return *this;
    w /= rhs.w;
  }
    return *this;

  }
  /**

   * Addition operator with 3-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Addition operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);
  inline vector4<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);

  }
  /**

   * Subtraction operator with 3-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Subtraction operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w);
  inline vector4<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w);

  }
  /**

   * Multiplication operator with 3-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w);
  inline vector4<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w);

  }
  /**

   * Division operator with 3-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Division operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w);
  inline vector4<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w);

  }
  /**

   * Addition operator with 3-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Addition operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x += rhs.x;
  inline vector4<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    y += rhs.y;
    x += rhs.x;
    z += rhs.z;
    y += rhs.y;
    return *this;
    z += rhs.z;
  }
    return *this;

  }
  /**

   * Subtraction operator with 3-vector
  /**
   * @param rhs Right hand side argument of binary operator.
   * Subtraction operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x -= rhs.x;
  inline vector4<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    y -= rhs.y;
    z -= rhs.z;
    x -= rhs.x;
    return *this;
    y -= rhs.y;
  }
    z -= rhs.z;

    return *this;
  /**
  }
   * Multiplication operator with 3-vector

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Multiplication operator with 3-vector
  inline vector4<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    x *= rhs.x;
   */
    y *= rhs.y;
  inline vector4<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    z *= rhs.z;
    x *= rhs.x;
    return *this;
    y *= rhs.y;
  }
    z *= rhs.z;

    return *this;
  /**
  }
   * Division operator with 3-vector

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Division operator with 3-vector
  inline vector4<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    x /= rhs.x;
   */
    y /= rhs.y;
  inline vector4<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    z /= rhs.z;
    x /= rhs.x;
    return *this;
    y /= rhs.y;
  }
    z /= rhs.z;

    return *this;
  /**
  }
   * Addition operator with 2-vector

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Addition operator with 2-vector
  inline vector4<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector4<T>(x + rhs.x, y + rhs.y, z, w);
   */
  }
  inline vector4<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

  /**
    return vector4<T>(x + rhs.x, y + rhs.y, z, w);
   * Subtraction operator with 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Subtraction operator with 2-vector
    return vector4<T>(x - rhs.x, y - rhs.y, z, w);
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector4<T>(x - rhs.x, y - rhs.y, z, w);
   * Multiplication operator with 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Multiplication operator with 2-vector
    return vector4<T>(x * rhs.x, y * rhs.y, z, w);
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector4<T>(x * rhs.x, y * rhs.y, z, w);
   * Division operator with 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Division operator with 2-vector
    return vector4<T>(x / rhs.x, y / rhs.y, z, w);
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector4<T>(x / rhs.x, y / rhs.y, z, w);
   * Addition operator with 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Addition operator with 2-vector
    x += rhs.x;
   * @param rhs Right hand side argument of binary operator.
    y += rhs.y;
   */
    return *this;
  }
  inline vector4<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x += rhs.x;
  /**
    y += rhs.y;
   * Subtraction operator with 2-vector
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x -= rhs.x;
   * Subtraction operator with 2-vector
    y -= rhs.y;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }
  inline vector4<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x -= rhs.x;
  /**
    y -= rhs.y;
   * Multiplication operator with 2-vector
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x *= rhs.x;
   * Multiplication operator with 2-vector
    y *= rhs.y;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }
  inline vector4<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x *= rhs.x;
  /**
    y *= rhs.y;
   * Division operator with 2-vector
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x /= rhs.x;
   * Division operator with 2-vector
    y /= rhs.y;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }

  inline vector4<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  //-------------[ matrix operations ]-------------------------
    x /= rhs.x;

    y /= rhs.y;
  /**
    return *this;
   * Multiplication by 3x3 matrix operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //-------------[ matrix operations ]-------------------------
  inline vector4<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    *this = rhs * *this;
  /**
    return *this;
   * Multiplication by 3x3 matrix operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Multiplication by 4x4 matrix operator
    *this = rhs * *this;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }
  inline vector4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    *this = rhs * *this;
  /**
    return *this;
   * Multiplication by 4x4 matrix operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //--------------[ equality operator ]------------------------
  inline vector4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    *this = rhs * *this;
  /**
    return *this;
   * Equality test operator
  }
   * @param rhs Right hand side argument of binary operator.

   * @note Test of equality is based of threshold epsilon value. To be two
  //--------------[ equality operator ]------------------------
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,

   * same for y-coordinate, z-coordinate, and w-coordinate.
  /**
   */
   * Equality test operator
  inline bool constexpr operator==(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    #ifdef VMATH_SOFT_COMPARE
   * @note Test of equality is based of threshold epsilon value. To be two
      return std::abs(x - rhs.x) < static_cast<T>(epsilon) &&
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
             std::abs(y - rhs.y) < static_cast<T>(epsilon) &&
   * same for y-coordinate, z-coordinate, and w-coordinate.
             std::abs(z - rhs.z) < static_cast<T>(epsilon) &&
   */
             std::abs(w - rhs.w) < static_cast<T>(epsilon);
  inline bool constexpr operator==(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #else
    #ifdef VMATH_SOFT_COMPARE
      return x == rhs.x &&
      return std::abs(x - rhs.x) < static_cast<T>(epsilon) &&
             y == rhs.y &&
             std::abs(y - rhs.y) < static_cast<T>(epsilon) &&
             z == rhs.z &&
             std::abs(z - rhs.z) < static_cast<T>(epsilon) &&
             w == rhs.w;
             std::abs(w - rhs.w) < static_cast<T>(epsilon);
    #endif // VMATH_SOFT_COMPARE
    #else
  }
      return x == rhs.x &&

             y == rhs.y &&
  /**
   * Inequality test operator
             z == rhs.z &&
   * @param rhs Right hand side argument of binary operator.
             w == rhs.w;
   * @return not (lhs == rhs) :-P
    #endif // VMATH_SOFT_COMPARE
   */
  }
  inline bool constexpr operator!=(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return !(*this == rhs);
  /**
  }
   * Inequality test operator

   * @param rhs Right hand side argument of binary operator.
  //-------------[ unary operations ]--------------------------
   * @return not (lhs == rhs) :-P
  /**
   */
   * Unary negate operator
  inline bool constexpr operator!=(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @return negated vector
    return !(*this == rhs);
   */
  }
  inline vector4<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {

    return vector4<T>(-x, -y, -z, -w);
  //-------------[ unary operations ]--------------------------
  }
  /**

   * Unary negate operator
  //--------------[ scalar vector operator ]--------------------
   * @return negated vector

   */
  /**
   * Addition operator
  inline vector4<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector4<T>(-x, -y, -z, -w);
   */
  }
  inline vector4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {

    return vector4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
  //--------------[ scalar vector operator ]--------------------
  }


  /**
  /**
   * Addition operator
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
    return vector4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
  }
  }


  /**
  /**
   * Subtraction operator
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
    return vector4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
  }
  }


  /**
  /**
   * Multiplication operator
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
    return vector4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
  }
  }


  /**
  /**
   * Division operator
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
    x += rhs;
  }
    y += rhs;

    z += rhs;
  /**
    w += rhs;
   * Addition operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x += rhs;
   * Subtraction operator
    y += rhs;
   * @param rhs Right hand side argument of binary operator.
    z += rhs;
   */
    w += rhs;
  inline vector4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
    return *this;
    x -= rhs;
  }
    y -= rhs;

    z -= rhs;
  /**
    w -= rhs;
   * Subtraction operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  /**
  inline vector4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   * Multiplication operator
    x -= rhs;
   * @param rhs Right hand side argument of binary operator.
    y -= rhs;
   */
    z -= rhs;
  inline vector4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    w -= rhs;
    x *= rhs;
    return *this;
    y *= rhs;
  }
    z *= rhs;

    w *= rhs;
  /**
    return *this;
   * Multiplication operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   * Division operator
    x *= rhs;
   * @param rhs Right hand side argument of binary operator.
    y *= rhs;
   */
    z *= rhs;
  inline vector4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    w *= rhs;
    x /= rhs;
    return *this;
    y /= rhs;
  }
    z /= rhs;

    w /= rhs;
  /**
    return *this;
   * Division operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //-------------[ size operations ]---------------------------
  inline vector4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x /= rhs;
   * Return square of length.
    y /= rhs;
   * @return length ^ 2
    z /= rhs;
   * @note This method is faster then length(). For comparison
    w /= rhs;
   * of length of two vector can be used just this value, instead
    return *this;
   * of more expensive length() method.
  }
   */

  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
  //-------------[ size operations ]---------------------------
    return x * x + y * y + z * z + w * w;
  /**
  }
   * Return square of length.
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
   * @return length ^ 2
    return length_sq();
   * @note This method is faster then length(). For comparison
  }
   * of length of two vector can be used just this value, instead

   * of more expensive length() method.
  /**
   */
   * Get length of vector.
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
   * @return length of vector
    return x * x + y * y + z * z + w * w;
   */
  }
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
    return static_cast<T>(std::sqrt(length_sq()));
    return length_sq();
  }
  }
  /**

   * Get length of vector, fast approximation.
  /**
   * @return length of vector
   * Get length of vector.
   */
   * @return length of vector
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
   */
    return static_cast<T>(sqrt_fast(length_sq()));
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
  }
    return static_cast<T>(std::sqrt(length_sq()));
  /**
  }
   * Get length of vector, rougher fast approximation.
  /**
   * @return length of vector
   * Get length of vector, fast approximation.
   */
   * @return length of vector
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
   */
    return static_cast<T>(sqrt_faster(length_sq()));
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
  }

    return static_cast<T>(sqrt_fast(length_sq()));
  /**
  }
   * normalise vector
  /**
   */
   * Get length of vector, rougher fast approximation.
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
   * @return length of vector
    T const temp = length();
   */
    x /= temp;
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    y /= temp;
    return static_cast<T>(sqrt_faster(length_sq()));
    z /= temp;
  }
    w /= temp;

  }
  /**
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
   * normalise vector
    T const temp = length_fast();
   */
    x /= temp;
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
    y /= temp;
    T const temp = length();
    z /= temp;
    x /= temp;
    w /= temp;
    y /= temp;
  }
    z /= temp;
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    w /= temp;
    T const temp = length_faster();
  }
    x /= temp;
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    y /= temp;
    T const temp = length_fast();
    z /= temp;
    x /= temp;
    w /= temp;
    y /= temp;
  }
    z /= temp;
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    w /= temp;
    normalise();
  }
  }
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    T const temp = length_faster();
    normalise_fast();
    x /= temp;
  }
    y /= temp;
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    z /= temp;
    normalise_faster();
    w /= temp;
  }
  }
  inline vector4<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    T const temp(length());
    normalise();
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  }
  }
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline vector4<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    normalise_fast();
    T const temp(length_fast());
  }
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    normalise_faster();
  inline vector4<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
  }
    T const temp(length_faster());
  inline vector4<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
    T const temp(length());
  }
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  inline vector4<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    return normalise_copy();
  inline vector4<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
  }
    T const temp(length_fast());
  inline vector4<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
    return normalise_copy_fast();
  }
  }
  inline vector4<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    T const temp(length_faster());
    return normalise_copy_faster();
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  }
  }
  /**
  inline vector4<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * normalise vector. with added zero safety check
    return normalise_copy();
   */
  }
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    T const temp = length();
    return normalise_copy_fast();
    if(temp == static_cast<T>(0)) {
  }
      x = static_cast<T>(0);
  inline vector4<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      y = static_cast<T>(0);
    return normalise_copy_faster();
      z = static_cast<T>(0);
  }
      w = static_cast<T>(0);
  /**
    } else {
   * normalise vector. with added zero safety check
      x /= temp;
   */
      y /= temp;
      z /= temp;
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
      w /= temp;
    T const temp = length();
    }
    if(temp == static_cast<T>(0)) {
  }
      x = static_cast<T>(0);
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      y = static_cast<T>(0);
    normalise_safe();
      z = static_cast<T>(0);
  }
      w = static_cast<T>(0);
  inline vector4<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    } else {
    T const temp(length());
      x /= temp;
    if(temp == static_cast<T>(0)) {
      y /= temp;
      return vector4<T>();
      z /= temp;
    } else {
      w /= temp;
      return vector4<T>(x / temp, y / temp, z / temp, w / temp);
    }
    }
  }
  }
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline vector4<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_safe();
    return normalise_safe_copy();
  }
  }
  inline vector4<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {

    T const temp(length());
  /**
    if(temp == static_cast<T>(0)) {
   * Absolute vector (make all values positive)
      return vector4<T>();
   */
    } else {
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
      return vector4<T>(x / temp, y / temp, z / temp, w / temp);
    x = std::abs(x);
    }
    y = std::abs(y);
  }
    z = std::abs(z);
  inline vector4<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    w = std::abs(w);
    return normalise_safe_copy();
  }
  }
  inline vector4<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {

    return vector4<T>(std::abs(x), std::abs(y), std::abs(z), std::abs(w));
  /**
  }
   * Absolute vector (make all values positive)

   */
  //--------------[ misc. operations ]-----------------------
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
  /**
    x = std::abs(x);
   * Linear interpolation of two vectors
    y = std::abs(y);
   * @param fact Factor of interpolation. For translation from position
    z = std::abs(z);
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
    w = std::abs(w);
   * @param r Second Vector for interpolation
  }
   * @note However values of fact parameter are reasonable only in interval
  inline vector4<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
   * [0.0 , 1.0], you can pass also values outside of this interval and you
    return vector4<T>(std::abs(x), std::abs(y), std::abs(z), std::abs(w));
   * can get result (extrapolation?)
  }
   */

  inline vector4<T> constexpr lerp(T fact, vector4<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
  //--------------[ misc. operations ]-----------------------
    return (*this) + (new_r - (*this)) * fact;
  /**
  }
   * Linear interpolation of two vectors

   * @param fact Factor of interpolation. For translation from position
  //-------------[ conversion ]-----------------------------
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.

   * @param r Second Vector for interpolation
  /**
   * @note However values of fact parameter are reasonable only in interval
   * Conversion to pointer operator
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * @return Pointer to internally stored (in management of class vector4<T>)
   * can get result (extrapolation?)
   * used for passing vector4<T> values to gl*4[fd] functions.
   */
   */
  inline vector4<T> constexpr lerp(T fact, vector4<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return (*this) + (new_r - (*this)) * fact;
    return reinterpret_cast<T*>(this);
  }
  }


  //-------------[ conversion ]-----------------------------
  /**

   * Conversion to pointer operator
  /**
   * @return Constant Pointer to internally stored (in management of class vector4<T>)
   * Conversion to pointer operator
   * used for passing vector4<T> values to gl*4[fd] functions.
   * @return Pointer to internally stored (in management of class vector4<T>)
   */
   * used for passing vector4<T> values to gl*4[fd] functions.
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
   */
    return reinterpret_cast<T const*>(this);
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
  }
    return reinterpret_cast<T*>(this);

  }
  /**

   * Gets 3D vector. Note that the output is divided by w coordinate to apply projection
  /**
   * transform. If the w coordinate is equal to zero, the result is not divided.
   * Conversion to pointer operator
   * @return (x/w, y/w, z/w) iff w != 0 otherwise (x,y,z)
   * @return Constant Pointer to internally stored (in management of class vector4<T>)
   */
   * used for passing vector4<T> values to gl*4[fd] functions.
  inline vector3<T> constexpr xyz() const noexcept __attribute__((__always_inline__)) {
   */
    return w == 0 ? vector3<T>(x, y, z) : vector3<T>(x / w, y / w, z / w);
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
  }
    return reinterpret_cast<T const*>(this);

  }
  //-------------[ output operator ]------------------------

  /**
  /**
   * Output to stream operator
   * Gets 3D vector. Note that the output is divided by w coordinate to apply projection
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * transform. If the w coordinate is equal to zero, the result is not divided.
   * @param rhs Right hand side argument of operator.
   * @return (x/w, y/w, z/w) iff w != 0 otherwise (x,y,z)
   * @return Left hand side argument - the ostream object passed to operator.
   */
   */
  inline vector3<T> constexpr xyz() const noexcept __attribute__((__always_inline__)) {
  inline friend std::ostream &operator<<(std::ostream &lhs, vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return w == 0 ? vector3<T>(x, y, z) : vector3<T>(x / w, y / w, z / w);
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.w << "]";
  }
    return lhs;

  }
  //-------------[ output operator ]------------------------

  /**
  /**
   * Output to stream operator
   * Gets string representation.
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   */
   * @param rhs Right hand side argument of operator.
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) {
   * @return Left hand side argument - the ostream object passed to operator.
    std::ostringstream oss;
   */
    oss << *this;
  inline friend std::ostream &operator<<(std::ostream &lhs, vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return oss.str();
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.w << "]";
  }
    return lhs;
};
  }


#ifdef VMATH_NAMESPACE
  /**
}
   * Gets string representation.
#endif //VMATH_NAMESPACE

   */
#include "vector4_types.h"
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) {

    std::ostringstream oss;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    oss << *this;
//
    return oss.str();
// Standard C++ library extensions
  }
//
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef VMATH_NAMESPACE
namespace std {
}

#endif //VMATH_NAMESPACE
/**

 * Gets vector containing minimal values of @a a and @a b coordinates.
#include "vector4_types.h"
 * @return Vector of minimal coordinates.

 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
//
constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept {
// Standard C++ library extensions
  return vector4<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z), ::std::min(a.w, b.w));
//
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
namespace std {
 * Gets vector containing maximal values of @a a and @a b coordinates.

 * @return Vector of maximal coordinates.
/**
 */
 * Gets vector containing minimal values of @a a and @a b coordinates.
template<typename T>
 * @return Vector of minimal coordinates.
constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept {
 */
  return vector4<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z), ::std::max(a.w, b.w));
template<typename T>
}
constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept {

  return vector4<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z), ::std::min(a.w, b.w));
}
}


#endif // VECTORSTORM_VECTOR4_H_INCLUDED
/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept {
  return vector4<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z), ::std::max(a.w, b.w));
}

}

#endif // VECTORSTORM_VECTOR4_H_INCLUDED
