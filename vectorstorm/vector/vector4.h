   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    w = std::move(rhs.w);
    return *this;
  }

  /**
   * Move assignment casting operator.
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    w = static_cast<T>(std::move(rhs.w));
    return *this;
  }

  /**
   * Move assignment operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    w = static_cast<T>(0);
    return *this;
  }

  /**
   * Move assignment casting operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    z = static_cast<T>(std::move(rhs.z));
    w = static_cast<T>(0);
    return *this;
  }

  /**
   * Array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y coordinate, n = 2 reference to z,
   * else reference to w coordinate.
   */
#ifndef VECTORSTORM_VECTOR4_H_INCLUDED
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
#define VECTORSTORM_VECTOR4_H_INCLUDED
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));

  }
#include <cmath>

#include <sstream>
  /**
#include "vectorstorm/epsilon.h"
   * Array access operator
#include "vector2_forward.h"
   * @param n Array index
#include "vector3_forward.h"
   * @return For n = 0, reference to x coordinate, n = 1
#include "vectorstorm/matrix/matrix3_forward.h"
   * reference to y coordinate, n = 2 reference to z,
#include "vectorstorm/matrix/matrix4_forward.h"
   * else reference to w coordinate.
#ifndef VMATH_NO_BOOST
   */
  #include <boost/functional/hash_fwd.hpp>
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
#endif // VMATH_NO_BOOST
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));

  }
#ifdef VMATH_NAMESPACE

namespace VMATH_NAMESPACE {
#endif
  //---------------[ vector aritmetic operator ]--------------

  /**
/**
   * Addition operator
 * Class for four dimensional vector.
   * @param rhs Right hand side argument of binary operator.
 * There are four ways of accessing vector components.
   */
 * Let's have <code>vector4f v</code>, you can either:
  inline vector4<T> constexpr operator+(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
 * <ul>
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
 *  <li>access as position in projective space (x,y,z,w) &mdash; <code>v.x = v.y = v.z = v.w = 1;</code></li>
  }
 *  <li>access as texture coordinate (s,t,u,v) &mdash; <code>v.s = v.t = v.u = v.v = 1;</code></li>

 *  <li>access as colour (r,g,b,a) &mdash; <code>v.r = v.g = v.b = v.a = 1;</code></li>
  /**
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = v[3] = 1;</code></li>
   * Subtraction operator
 * </ul>
   * @param rhs Right hand side argument of binary operator.
 */
   */
template<typename T>
  inline vector4<T> constexpr operator-(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
class vector4 {
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
public:
  }
  union {

    /**
  /**
     * First element of vector, alias for R-coordinate.
   * Multiplication operator
     * For colour notation.
   * @param rhs Right hand side argument of binary operator.
     */
   */
    T r

  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    /**
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
     * First element of vector, alias for X-coordinate.
  }
     */;

    T x;
  /**
  };
   * Division operator

   * @param rhs Right hand side argument of binary operator.
  union {
   */
    /**
  inline vector4<T> constexpr operator/(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
     * Second element of vector, alias for G-coordinate.
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
     * For colour notation.
  }
     */

    T g;

  /**
    /**
   * Addition operator
     * Second element of vector, alias for Y-coordinate.
   * @param rhs Right hand side argument of binary operator.
     */
   */
    T y;
  inline vector4<T> constexpr &operator+=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  };
    x += rhs.x;

    y += rhs.y;
  union {
    z += rhs.z;
    /**
    w += rhs.w;
     * Third element of vector, alias for B-coordinate.
    return *this;
     * For colour notation.
  }
     */

    T b;

  /**
    /**
   * Subtraction operator
     * Third element of vector, alias for Z-coordinate.
   * @param rhs Right hand side argument of binary operator.
     */
   */
    T z;
  inline vector4<T> constexpr &operator-=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  };
    x -= rhs.x;

    y -= rhs.y;
  union {
    z -= rhs.z;
    /**
    w -= rhs.w;
     * Fourth element of vector, alias for A-coordinate.
    return *this;
     * For colour notation. This represnt aplha channel
  }
     */

    T a;

  /**
    /**
   * Multiplication operator
     * Fourth element of vector, alias for W-coordinate.
   * @param rhs Right hand side argument of binary operator.
     * @note For vectors (such as normals) should be set to 0.0
   */
     * For vertices should be set to 1.0
  inline vector4<T> constexpr &operator*=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
     */
    x *= rhs.x;
    T w;
    y *= rhs.y;
  };
    z *= rhs.z;

    w *= rhs.w;
  //----------------[ constructors ]--------------------------
    return *this;
  /**
  }
   * Creates and sets to (0,0,0,0)

   */
  /**
  inline constexpr vector4() noexcept __attribute__((__always_inline__))
   * Division operator
    : x(0),
   * @param rhs Right hand side argument of binary operator.
      y(0),
   */
      z(0),
      w(0) {
  inline vector4<T> constexpr &operator/=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x /= rhs.x;

    y /= rhs.y;
  /**
    z /= rhs.z;
   * Creates and sets to (x,y,z,z)
    w /= rhs.w;
   * @param nx initial x-coordinate value (R)
    return *this;
   * @param ny initial y-coordinate value (G)
  }
   * @param nz initial z-coordinate value (B)

   * @param nw initial w-coordinate value (Alpha)
  /**
   */
   * Addition operator with 3-vector
  inline constexpr vector4(T nx, T ny, T nz, T nw) noexcept __attribute__((__always_inline__))
   * @param rhs Right hand side argument of binary operator.
    : x(nx),
   */
      y(ny),
  inline vector4<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
      z(nz),
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);
      w(nw) {
  }
  }


  /**
  /**
   * Copy constructor.
   * Subtraction operator with 3-vector
   * @param src Source of data for new created vector4 instance.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline constexpr explicit vector4(vector4<T> const &src) noexcept __attribute__((__always_inline__))
  inline vector4<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    : x(src.x),
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w);
      y(src.y),
  }
      z(src.z),

      w(src.w) {
  /**
  }
   * Multiplication operator with 3-vector

  /**
   * @param rhs Right hand side argument of binary operator.
   * Copy casting constructor.
   */
   * @param src Source of data for new created vector4 instance.
  inline vector4<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w);
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline constexpr explicit vector4(vector4<FromT> const &src) noexcept

    : x(static_cast<T>(src.x)),
  /**
      y(static_cast<T>(src.y)),
   * Division operator with 3-vector
      z(static_cast<T>(src.z)),
   * @param rhs Right hand side argument of binary operator.
      w(static_cast<T>(src.w)) {
   */
  }
  inline vector4<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w);
  /**
  }
   * Copy constructor from a vector3.

   * @param src Source of x,y,z data for new created vector4 instance.
  /**
   * @param new_w Source of data for w element.
   * Addition operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  inline constexpr vector4(vector3<T> const &src, T new_w) noexcept __attribute__((__always_inline__))
   */
    : x(src.x),
      y(src.y),
  inline vector4<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
      z(src.z),
    x += rhs.x;
      w(new_w) {
    y += rhs.y;
  }
    z += rhs.z;

    return *this;
  /**
  }
   * Copy casting constructor from a vector3.

   * @param src Source of x,y,z data for new created vector4 instance.
  /**
   * @param new_w Source of data for w element.
   * Subtraction operator with 3-vector
   */
   * @param rhs Right hand side argument of binary operator.
  template<typename FromT> __attribute__((__always_inline__))
   */
  inline constexpr vector4(vector3<FromT> const &src, FromT new_w) noexcept
  inline vector4<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    : x(static_cast<T>(src.x)),
    x -= rhs.x;
      y(static_cast<T>(src.y)),
    y -= rhs.y;
      z(static_cast<T>(src.z)),
    z -= rhs.z;
      w(static_cast<T>(new_w)) {
    return *this;
  }
  }


  /**
  /**
   * Copy constructor from a vector2.
   * Multiplication operator with 3-vector
   * @param src Source of x,y data for new created vector4 instance.
   * @param rhs Right hand side argument of binary operator.
   * @param new_z Source of data for z element.
   */
   * @param new_w Source of data for w element.
   */
  inline vector4<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline constexpr vector4(vector2<T> const &src, T new_z, T new_w) noexcept __attribute__((__always_inline__))
    x *= rhs.x;
    : x(src.x),
    y *= rhs.y;
      y(src.y),
    z *= rhs.z;
      z(new_z),
    return *this;
      w(new_w) {
  }
  }


  /**
  /**
   * Division operator with 3-vector
   * Copy casting constructor from a vector2.
   * @param rhs Right hand side argument of binary operator.
   * @param src Source of x,y data for new created vector4 instance.
   */
   * @param new_z Source of data for z element.
  inline vector4<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param new_w Source of data for w element.
    x /= rhs.x;
   */
  template<typename FromT> __attribute__((__always_inline__))
    y /= rhs.y;
  inline constexpr vector4(vector2<FromT> const &src, FromT new_z, FromT new_w) noexcept
    z /= rhs.z;
    : x(static_cast<T>(src.x)),
    return *this;
      y(static_cast<T>(src.y)),
  }
      z(static_cast<T>(new_z)),

      w(static_cast<T>(new_w)) {
  /**
  }
   * Addition operator with 2-vector

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Move constructor.
  inline vector4<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param src Source of data for new created vector4 instance.
    return vector4<T>(x + rhs.x, y + rhs.y, z, w);
   */
  }
  inline constexpr vector4(vector4<T> &&src) noexcept __attribute__((__always_inline__))

    : x(std::move(src.x)),
  /**
      y(std::move(src.y)),
   * Subtraction operator with 2-vector
      z(std::move(src.z)),
   * @param rhs Right hand side argument of binary operator.
      w(std::move(src.w)) {
   */
  }

  inline vector4<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector4<T>(x - rhs.x, y - rhs.y, z, w);
   * Move casting constructor.
  }
   * @param src Source of data for new created vector4 instance.

   */
  /**
  template<typename FromT> __attribute__((__always_inline__))
   * Multiplication operator with 2-vector
  inline constexpr vector4(vector4<FromT> &&src) noexcept
   * @param rhs Right hand side argument of binary operator.
    : x(static_cast<T>(std::move(src.x))),
   */
      y(static_cast<T>(std::move(src.y))),
  inline vector4<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
      z(static_cast<T>(std::move(src.z))),
    return vector4<T>(x * rhs.x, y * rhs.y, z, w);
      w(static_cast<T>(std::move(src.w))) {
  }
  }


  /**
  /**
   * Division operator with 2-vector
   * Move constructor from a vector3.
   * @param rhs Right hand side argument of binary operator.
   * @param src Source of x,y,z data for new created vector4 instance.
   */
   * @param new_w Source of data for w element.
   */
  inline vector4<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline constexpr vector4(vector3<T> &&src, T new_w) noexcept __attribute__((__always_inline__))
    return vector4<T>(x / rhs.x, y / rhs.y, z, w);
    : x(std::move(src.x)),
  }
      y(std::move(src.y)),

      z(std::move(src.z)),
  /**
      w(std::move(new_w)) {
   * Addition operator with 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Move casting constructor from a vector3.
    x += rhs.x;
   * @param src Source of x,y,z data for new created vector4 instance.
    y += rhs.y;
   * @param new_w Source of data for w element.
    return *this;
   */
  }
  template<typename FromT> __attribute__((__always_inline__))

  inline constexpr vector4(vector3<FromT> &&src, FromT new_w) noexcept
  /**
    : x(static_cast<T>(std::move(src.x))),
   * Subtraction operator with 2-vector
      y(static_cast<T>(std::move(src.y))),
      z(static_cast<T>(std::move(src.z))),
   * @param rhs Right hand side argument of binary operator.
      w(static_cast<T>(std::move(new_w))) {
   */
  }
  inline vector4<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x -= rhs.x;
  /**
    y -= rhs.y;
   * Move constructor from a vector2.
    return *this;
   * @param src Source of x,y data for new created vector4 instance.
  }
   * @param new_z Source of data for z element.

   * @param new_w Source of data for w element.
  /**
   */
   * Multiplication operator with 2-vector
  inline constexpr vector4(vector2<T> &&src, T new_z, T new_w) noexcept __attribute__((__always_inline__))
   * @param rhs Right hand side argument of binary operator.
    : x(std::move(src.x)),
   */
      y(std::move(src.y)),
      z(std::move(new_z)),
  inline vector4<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
      w(std::move(new_w)) {
    x *= rhs.x;
  }
    y *= rhs.y;

    return *this;
  /**
  }
   * Move casting constructor from a vector2.

   * @param src Source of x,y data for new created vector4 instance.
  /**
   * @param new_z Source of data for z element.
   * Division operator with 2-vector
   * @param new_w Source of data for w element.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline constexpr vector4(vector2<FromT> &&src, FromT new_z, FromT new_w) noexcept
    x /= rhs.x;
    : x(static_cast<T>(std::move(src.x))),
    y /= rhs.y;
      y(static_cast<T>(std::move(src.y))),
    return *this;
      z(static_cast<T>(std::move(new_z))),
  }
      w(static_cast<T>(std::move(new_w))) {

  }
  /**

   * Dot product of two vectors.
  //----------------[ assignment ]-------------------------
  /**
   * @param rhs Right hand side argument of binary operator.
   * Sets to (x,y,z)
   */
   * @param nx initial x-coordinate value
  inline T constexpr dot(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param ny initial y-coordinate value
    return (x * rhs.x) +
   * @param nz initial z-coordinate value
           (y * rhs.y) +
   * @param nz initial w-coordinate value
           (z * rhs.z) +
   */
           (w * rhs.w);
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0, T nw = 0) noexcept __attribute__((__always_inline__)) {
  }
    x = nx;

    y = ny;
  //-------------[ matrix operations ]-------------------------
    z = nz;

    w = nw;
  /**
  }
   * Multiplication by 3x3 matrix operator

   * @param rhs Right hand side argument of binary operator.
  //----------------[ access operators ]-------------------
   */
  /**
   * Copy operator
  inline vector4<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    *this = rhs * *this;
   */
    return *this;
  inline vector4<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x = rhs.x;

    y = rhs.y;
  /**
    z = rhs.z;
   * Multiplication by 4x4 matrix operator
    w = rhs.w;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }
  inline vector4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    *this = rhs * *this;
  /**
    return *this;
   * Copy casting operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //--------------[ equality operator ]------------------------
  template<typename FromT> __attribute__((__always_inline__))

  inline vector4<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
  /**
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
   * Equality test operator
    z = static_cast<T>(rhs.z);
   * @param rhs Right hand side argument of binary operator.
    w = static_cast<T>(rhs.w);
   * @note Test of equality is based of threshold epsilon value. To be two
    return *this;
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
  }
   * same for y-coordinate, z-coordinate, and w-coordinate.

   */
  /**
  inline bool constexpr operator==(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Copy operator to vector4 from vector3
    #ifdef VMATH_SOFT_COMPARE
   * @param rhs Right hand side argument of binary operator.
   */
      return std::abs(x - rhs.x) < epsilon<T> &&
  inline vector4<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
             std::abs(y - rhs.y) < epsilon<T> &&
    x = rhs.x;
             std::abs(z - rhs.z) < epsilon<T> &&
    y = rhs.y;
             std::abs(w - rhs.w) < epsilon<T>;
    z = rhs.z;
    #else
    w = static_cast<T>(0);
      return x == rhs.x &&
    return *this;
             y == rhs.y &&
  }
             z == rhs.z &&

             w == rhs.w;
  /**
    #endif // VMATH_SOFT_COMPARE
   * Copy casting operator to vector4 from vector3
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  template<typename FromT> __attribute__((__always_inline__))
   * Inequality test operator
  inline vector4<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
   * @param rhs Right hand side argument of binary operator.
    x = static_cast<T>(rhs.x);
   * @return not (lhs == rhs) :-P
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
   */
    w = static_cast<T>(0);
  inline bool constexpr operator!=(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return *this;
    return !(*this == rhs);
  }
  }



  //-------------[ unary operations ]--------------------------
  /**
  /**
   * Move assignment operator
   * Unary negate operator
   * @param rhs Right hand side argument of binary operator.
   * @return negated vector
   */
   */
  inline vector4<T> constexpr &operator=(vector4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    return vector4<T>(-x, -y, -z, -w);
    y = std::move(rhs.y);
  }
    z = std::move(rhs.z);

    w = std::move(rhs.w);
    return *this;
  //--------------[ scalar vector operator ]--------------------
  }


  /**
  /**
   * Addition operator
   * Move assignment casting operator.
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return vector4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
  inline vector4<T> constexpr &operator=(vector4<FromT> &&rhs) noexcept {
  }
    x = static_cast<T>(std::move(rhs.x));

    y = static_cast<T>(std::move(rhs.y));
  /**
    z = static_cast<T>(std::move(rhs.z));
   * Subtraction operator
    w = static_cast<T>(std::move(rhs.w));
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }

  inline vector4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
   * Move assignment operator to vector4 from vector3
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr &operator=(vector3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
   * Multiplication operator
    x = std::move(rhs.x);
   * @param rhs Right hand side argument of binary operator.
    y = std::move(rhs.y);
   */
    z = std::move(rhs.z);
  inline vector4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    w = static_cast<T>(0);
    return vector4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
    return *this;
  }
  }


  /**
  /**
   * Move assignment casting operator to vector4 from vector3
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator=(vector3<FromT> &&rhs) noexcept {
    return vector4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
    x = static_cast<T>(std::move(rhs.x));
  }
    y = static_cast<T>(std::move(rhs.y));

    z = static_cast<T>(std::move(rhs.z));
  /**
    w = static_cast<T>(0);
   * Addition operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline vector4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x += rhs;
   * Array access operator
    y += rhs;
   * @param n Array index
    z += rhs;
   * @return For n = 0, reference to x coordinate, n = 1
    w += rhs;
   * reference to y coordinate, n = 2 reference to z,
    return *this;
   * else reference to w coordinate.
   */
  }
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {

    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Array access operator
  inline vector4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   * @param n Array index
    x -= rhs;
   * @return For n = 0, reference to x coordinate, n = 1
    y -= rhs;
   * reference to y coordinate, n = 2 reference to z,
    z -= rhs;
   * else reference to w coordinate.
   */
    w -= rhs;
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
    return *this;
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
  }
  }


  /**
  //---------------[ vector aritmetic operator ]--------------
   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Addition operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    x *= rhs;
  inline vector4<T> constexpr operator+(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    y *= rhs;
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    z *= rhs;
  }
    w *= rhs;

    return *this;
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Division operator
  inline vector4<T> constexpr operator-(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
   */
  }

  inline vector4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x /= rhs;
   * Multiplication operator
    y /= rhs;
   * @param rhs Right hand side argument of binary operator.
    z /= rhs;
   */
    w /= rhs;
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return *this;
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
  }
  }


  //-------------[ size operations ]---------------------------
  /**
  /**
   * Division operator
   * Return square of length.
   * @param rhs Right hand side argument of binary operator.
   * @return length ^ 2
   */
   * @note This method is faster then length(). For comparison
  inline vector4<T> constexpr operator/(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * of length of two vector can be used just this value, instead
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
   * of more expensive length() method.
  }

   */
  /**
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
   * Addition operator
    return x * x + y * y + z * z + w * w;
   * @param rhs Right hand side argument of binary operator.
  }
   */
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
  inline vector4<T> constexpr &operator+=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return length_sq();
    x += rhs.x;
  }
    y += rhs.y;

    z += rhs.z;
  /**
    w += rhs.w;
   * Get length of vector.
    return *this;
   * @return length of vector
  }

   */
  /**
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
   * Subtraction operator
    return static_cast<T>(std::sqrt(length_sq()));
  }
   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Get length of vector, fast approximation.
  inline vector4<T> constexpr &operator-=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * @return length of vector
    x -= rhs.x;
   */
    y -= rhs.y;
    z -= rhs.z;
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    w -= rhs.w;
    return static_cast<T>(sqrt_fast(length_sq()));
    return *this;
  }
  }
  /**

   * Get length of vector, rougher fast approximation.
  /**
   * @return length of vector
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
   */
    return static_cast<T>(sqrt_faster(length_sq()));
  inline vector4<T> constexpr &operator*=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x *= rhs.x;

    y *= rhs.y;
  /**
    z *= rhs.z;
    w *= rhs.w;
   * Return whether the vector is zero length - this is much faster than a full length calculation
    return *this;
   * @return whether vector is zero length
  }
   */

  inline bool constexpr length_zero() const noexcept __attribute__((__always_inline__)) {
  /**
    /*
   * Division operator
    return x == static_cast<T>(0) &&
   * @param rhs Right hand side argument of binary operator.
           y == static_cast<T>(0) &&
   */
           z == static_cast<T>(0) &&
  inline vector4<T> constexpr &operator/=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
           w == static_cast<T>(0);
    x /= rhs.x;
    */
    y /= rhs.y;
    z /= rhs.z;
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
    w /= rhs.w;
    return std::abs(x) < epsilon<T> &&
    return *this;
           std::abs(y) < epsilon<T> &&
  }
           std::abs(z) < epsilon<T> &&

           std::abs(w) < epsilon<T>;
  /**
  }
   * Addition operator with 3-vector

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * normalise vector
  inline vector4<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
  }
    T const temp = length();

    x /= temp;
  /**
    y /= temp;
   * Subtraction operator with 3-vector
    z /= temp;
   * @param rhs Right hand side argument of binary operator.
   */
    w /= temp;
  inline vector4<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w);
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
  }
    T const temp = length_fast();

    x /= temp;
  /**
    y /= temp;
   * Multiplication operator with 3-vector
    z /= temp;
   * @param rhs Right hand side argument of binary operator.
    w /= temp;
   */
  }
  inline vector4<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w);
    T const temp = length_faster();
  }
    x /= temp;

    y /= temp;
  /**
    z /= temp;
   * Division operator with 3-vector
    w /= temp;
   * @param rhs Right hand side argument of binary operator.
  }
   */
  inline vector4<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w);
    normalise();
  }
  }

  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  /**
    normalise_fast();
   * Addition operator with 3-vector
  }
   * @param rhs Right hand side argument of binary operator.
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   */
    normalise_faster();
  inline vector4<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x += rhs.x;
  inline vector4<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    y += rhs.y;
    T const temp(length());
    z += rhs.z;
    return *this;
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  }
  }

  inline vector4<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
  /**
    T const temp(length_fast());
   * Subtraction operator with 3-vector
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
   * @param rhs Right hand side argument of binary operator.
  }
   */
  inline vector4<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    T const temp(length_faster());
    x -= rhs.x;
    y -= rhs.y;
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
    z -= rhs.z;
  }
    return *this;
  inline vector4<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    return normalise_copy();

  }
  /**
  inline vector4<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * Multiplication operator with 3-vector
    return normalise_copy_fast();
   * @param rhs Right hand side argument of binary operator.
  }
   */
  inline vector4<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline vector4<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return normalise_copy_faster();
    x *= rhs.x;
  }
    y *= rhs.y;
  /**
    z *= rhs.z;
    return *this;
   * normalise vector. with added zero safety check
  }
   */

  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
  /**
    if(length_zero()) {
   * Division operator with 3-vector
      assign();
   * @param rhs Right hand side argument of binary operator.
    } else {
   */
      *this /= length();
  inline vector4<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    }
    x /= rhs.x;
  }
    y /= rhs.y;
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    z /= rhs.z;
    return *this;
    normalise_safe();
  }
  }

  inline vector4<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
  /**
    if(length_zero()) {
   * Addition operator with 2-vector
      return vector4<T>();
   * @param rhs Right hand side argument of binary operator.
    } else {
   */
      return *this / length();
  inline vector4<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    }
    return vector4<T>(x + rhs.x, y + rhs.y, z, w);
  }
  }
  inline vector4<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {

  /**
    return normalise_safe_copy();
   * Subtraction operator with 2-vector
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector4<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Absolute vector (make all values positive)
    return vector4<T>(x - rhs.x, y - rhs.y, z, w);
   */
  }
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {

    x = std::abs(x);
  /**
    y = std::abs(y);
   * Multiplication operator with 2-vector
    z = std::abs(z);
   * @param rhs Right hand side argument of binary operator.
    w = std::abs(w);
   */
  }
  inline vector4<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs.x, y * rhs.y, z, w);
    return vector4<T>(std::abs(x), std::abs(y), std::abs(z), std::abs(w));
  }

  }
  /**

   * Division operator with 2-vector
  //--------------[ misc. operations ]-----------------------
   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Linear interpolation of two vectors
  inline vector4<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param fact Factor of interpolation. For translation from position
    return vector4<T>(x / rhs.x, y / rhs.y, z, w);
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
  }
   * @param r Second Vector for interpolation

   * @note However values of fact parameter are reasonable only in interval
  /**
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * Addition operator with 2-vector
   * can get result (extrapolation?)
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline vector4<T> constexpr lerp(T fact, vector4<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return (*this) + (new_r - (*this)) * fact;
    x += rhs.x;
  }
    y += rhs.y;

    return *this;
  }
  //-------------[ conversion ]-----------------------------


  /**
  /**
   * Subtraction operator with 2-vector
   * Conversion to pointer operator
   * @param rhs Right hand side argument of binary operator.
   * @return Pointer to internally stored (in management of class vector4<T>)
   */
   * used for passing vector4<T> values to gl*4[fd] functions.
  inline vector4<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x -= rhs.x;
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    y -= rhs.y;
    return reinterpret_cast<T*>(this);
    return *this;
  }
  }


  /**
  /**
   * Conversion to pointer operator
   * Multiplication operator with 2-vector
   * @return Constant Pointer to internally stored (in management of class vector4<T>)
   * @param rhs Right hand side argument of binary operator.
   */
   * used for passing vector4<T> values to gl*4[fd] functions.
  inline vector4<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    x *= rhs.x;
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
    y *= rhs.y;
    return reinterpret_cast<T const*>(this);
    return *this;
  }
  }


  /**
  /**
   * Gets 3D vector. Note that the output is divided by w coordinate to apply projection
   * Division operator with 2-vector
   * transform. If the w coordinate is equal to zero, the result is not divided.
   * @param rhs Right hand side argument of binary operator.
   * @return (x/w, y/w, z/w) iff w != 0 otherwise (x,y,z)
   */
   */
  inline vector4<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
  inline vector3<T> constexpr xyz() const noexcept __attribute__((__always_inline__)) {
    y /= rhs.y;
    return w == 0 ? vector3<T>(x, y, z) : vector3<T>(x / w, y / w, z / w);
    return *this;
  }
  }


  //-------------[ output operator ]------------------------
  /**
  /**
   * Dot product of two vectors.
   * Output to stream operator
   * @param rhs Right hand side argument of binary operator.
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   */
   * @param rhs Right hand side argument of operator.
  inline T constexpr dot(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @return Left hand side argument - the ostream object passed to operator.
    return (x * rhs.x) +
   */
           (y * rhs.y) +
           (z * rhs.z) +
  inline friend std::ostream &operator<<(std::ostream &lhs, vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
           (w * rhs.w);
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.w << "]";
  }
    return lhs;

  }
  //-------------[ matrix operations ]-------------------------


  /**
  /**
   * Gets string representation.
   * Multiplication by 3x3 matrix operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) {
   */
    std::ostringstream oss;
  inline vector4<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this = rhs * *this;
    oss << *this;
    return *this;
    return oss.str();
  }
  }

};
  /**

   * Multiplication by 4x4 matrix operator
#ifdef VMATH_NAMESPACE
   * @param rhs Right hand side argument of binary operator.
}
   */
#endif //VMATH_NAMESPACE
  inline vector4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    *this = rhs * *this;
#include "vector4_types.h"
    return *this;

  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
  //--------------[ equality operator ]------------------------

// Standard C++ library extensions
  /**
//
   * Equality test operator
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   * @param rhs Right hand side argument of binary operator.

   * @note Test of equality is based of threshold epsilon value. To be two
namespace std {
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,

   * same for y-coordinate, z-coordinate, and w-coordinate.
/**
   */
 * Gets vector containing minimal values of @a a and @a b coordinates.
  inline bool constexpr operator==(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
 * @return Vector of minimal coordinates.
    #ifdef VMATH_SOFT_COMPARE
 */
      return std::abs(x - rhs.x) < epsilon<T> &&
template<typename T>
             std::abs(y - rhs.y) < epsilon<T> &&
inline constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
             std::abs(z - rhs.z) < epsilon<T> &&
template<typename T>
             std::abs(w - rhs.w) < epsilon<T>;
inline constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept {
    #else
      return x == rhs.x &&
  return vector4<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z), ::std::min(a.w, b.w));
             y == rhs.y &&
}
             z == rhs.z &&

             w == rhs.w;
/**
    #endif // VMATH_SOFT_COMPARE
 * Gets vector containing maximal values of @a a and @a b coordinates.
  }
 * @return Vector of maximal coordinates.

 */
  /**
template<typename T>
   * Inequality test operator
inline constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
   * @param rhs Right hand side argument of binary operator.
template<typename T>
   * @return not (lhs == rhs) :-P
inline constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept {
   */
  return vector4<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z), ::std::max(a.w, b.w));
  inline bool constexpr operator!=(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
}
    return !(*this == rhs);

  }

#ifndef VMATH_NO_BOOST
  //-------------[ unary operations ]--------------------------
/**
  /**
 * Gets a hash value taking account of all dimensions of this vector, for use
   * Unary negate operator
 * in standard container maps etc.
   * @return negated vector
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
   */
 * @return Hash value
  inline vector4<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
 */
    return vector4<T>(-x, -y, -z, -w);
template<typename T>
  }
struct hash<vector4<T>> {

  size_t operator()(const vector4<T> &value) const {
  //--------------[ scalar vector operator ]--------------------
    size_t hashvalue = 0;

  /**
    boost::hash_combine(hashvalue, value.x);
   * Addition operator
    boost::hash_combine(hashvalue, value.y);
   * @param rhs Right hand side argument of binary operator.
    boost::hash_combine(hashvalue, value.z);
   */
    boost::hash_combine(hashvalue, value.w);
  inline vector4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return hashvalue;
    return vector4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
  }
  }
};

#endif // VMATH_NO_BOOST
  /**

   * Subtraction operator
}
   * @param rhs Right hand side argument of binary operator.

   */
#ifndef VMATH_NO_BOOST
  inline vector4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
/**
    return vector4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
 * Gets a hash value taking account of all dimensions of this vector, for use
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
size_t hash_value(vector4<T> const &value) {
  inline vector4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  size_t hashvalue = 0;
    return vector4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
  boost::hash_combine(hashvalue, value.x);
  }

  boost::hash_combine(hashvalue, value.y);
  /**
  boost::hash_combine(hashvalue, value.z);
   * Division operator
  boost::hash_combine(hashvalue, value.w);
   * @param rhs Right hand side argument of binary operator.
  return hashvalue;
   */
}
  inline vector4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
#endif // VMATH_NO_BOOST
    return vector4<T>(x / rhs, y / rhs, z / rhs, w / rhs);

  }
#endif // VECTORSTORM_VECTOR4_H_INCLUDED

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs;
    y += rhs;
    z += rhs;
    w += rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs;
    y -= rhs;
    z -= rhs;
    w -= rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return *this;
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
    return x * x + y * y + z * z + w * w;
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
           z == static_cast<T>(0) &&
           w == static_cast<T>(0);
    */
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
    return std::abs(x) < epsilon<T> &&
           std::abs(y) < epsilon<T> &&
           std::abs(z) < epsilon<T> &&
           std::abs(w) < epsilon<T>;
  }

  /**
   * normalise vector
   */
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
    T const temp = length();
    x /= temp;
    y /= temp;
    z /= temp;
    w /= temp;
  }
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    T const temp = length_fast();
    x /= temp;
    y /= temp;
    z /= temp;
    w /= temp;
  }
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    T const temp = length_faster();
    x /= temp;
    y /= temp;
    z /= temp;
    w /= temp;
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
  inline vector4<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    T const temp(length());
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  }
  inline vector4<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  }
  inline vector4<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return vector4<T>(x / temp, y / temp, z / temp, w / temp);
  }
  inline vector4<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline vector4<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline vector4<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
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
  inline vector4<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    if(length_zero()) {
      return vector4<T>();
    } else {
      return *this / length();
    }
  }
  inline vector4<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_safe_copy();
  }

  /**
   * Absolute vector (make all values positive)
   */
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
    x = std::abs(x);
    y = std::abs(y);
    z = std::abs(z);
    w = std::abs(w);
  }
  inline vector4<T> constexpr abs_copy() const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(std::abs(x), std::abs(y), std::abs(z), std::abs(w));
  }

  //--------------[ misc. operations ]-----------------------
  /**
   * Linear interpolation of two vectors
   * @param fact Factor of interpolation. For translation from position
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
   * @param r Second Vector for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  inline vector4<T> constexpr lerp(T fact, vector4<T> const &new_r) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (new_r - (*this)) * fact;
  }

  //-------------[ conversion ]-----------------------------

  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector4<T>)
   * used for passing vector4<T> values to gl*4[fd] functions.
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector4<T>)
   * used for passing vector4<T> values to gl*4[fd] functions.
   */
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(this);
  }

  /**
   * Gets 3D vector. Note that the output is divided by w coordinate to apply projection
   * transform. If the w coordinate is equal to zero, the result is not divided.
   * @return (x/w, y/w, z/w) iff w != 0 otherwise (x,y,z)
   */
  inline vector3<T> constexpr xyz() const noexcept __attribute__((__always_inline__)) {
    return w == 0 ? vector3<T>(x, y, z) : vector3<T>(x / w, y / w, z / w);
  }

  //-------------[ output operator ]------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.w << "]";
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
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector4_types.h"

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
inline constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) noexcept {
  return vector4<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z), ::std::min(a.w, b.w));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
inline constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) noexcept {
  return vector4<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z), ::std::max(a.w, b.w));
}

#ifndef VMATH_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this vector, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
struct hash<vector4<T>> {
  size_t operator()(const vector4<T> &value) const {
    size_t hashvalue = 0;
    boost::hash_combine(hashvalue, value.x);
    boost::hash_combine(hashvalue, value.y);
    boost::hash_combine(hashvalue, value.z);
    boost::hash_combine(hashvalue, value.w);
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
size_t hash_value(vector4<T> const &value) {
  size_t hashvalue = 0;
  boost::hash_combine(hashvalue, value.x);
  boost::hash_combine(hashvalue, value.y);
  boost::hash_combine(hashvalue, value.z);
  boost::hash_combine(hashvalue, value.w);
  return hashvalue;
}
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_VECTOR4_H_INCLUDED
