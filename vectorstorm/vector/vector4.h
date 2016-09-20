#ifndef VECTORSTORM_VECTOR4_H_INCLUDED
#define VECTORSTORM_VECTOR4_H_INCLUDED

#include <cmath>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vector2_forward.h"
#include "vector3_forward.h"
#include "vectorstorm/matrix/matrix3_forward.h"
#include "vectorstorm/matrix/matrix4_forward.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/**
 * Class for four dimensional vector.
 * There are four ways of accessing vector components.
 * Let's have <code>vector4f v</code>, you can either:
 * <ul>
 *  <li>access as position in projective space (x,y,z,w) &mdash; <code>v.x = v.y = v.z = v.w = 1;</code></li>
 *  <li>access as texture coordinate (s,t,u,v) &mdash; <code>v.s = v.t = v.u = v.v = 1;</code></li>
 *  <li>access as colour (r,g,b,a) &mdash; <code>v.r = v.g = v.b = v.a = 1;</code></li>
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = v[2] = v[3] = 1;</code></li>
 * </ul>
 */
template<typename T>
class vector4 {
public:
  union {
    /**
     * First element of vector, alias for R-coordinate.
     * For colour notation.
     */
    T r

    /**
     * First element of vector, alias for X-coordinate.
     */;
    T x;
  };

  union {
    /**
     * Second element of vector, alias for G-coordinate.
     * For colour notation.
     */
    T g;

    /**
     * Second element of vector, alias for Y-coordinate.
     */
    T y;
  };

  union {
    /**
     * Third element of vector, alias for B-coordinate.
     * For colour notation.
     */
    T b;

    /**
     * Third element of vector, alias for Z-coordinate.
     */
    T z;
  };

  union {
    /**
     * Fourth element of vector, alias for A-coordinate.
     * For colour notation. This represnt aplha channel
     */
    T a;

    /**
     * Fourth element of vector, alias for W-coordinate.
     * @note For vectors (such as normals) should be set to 0.0
     * For vertices should be set to 1.0
     */
    T w;
  };

  //----------------[ constructors ]--------------------------
  /**
   * Creates and sets to (0,0,0,0)
   */
  inline constexpr vector4() noexcept __attribute__((__always_inline__))
    : x(0),
      y(0),
      z(0),
      w(0) {
  }

  /**
   * Creates and sets to (x,y,z,z)
   * @param nx initial x-coordinate value (R)
   * @param ny initial y-coordinate value (G)
   * @param nz initial z-coordinate value (B)
   * @param nw initial w-coordinate value (Alpha)
   */
  inline constexpr vector4(T nx, T ny, T nz, T nw) noexcept __attribute__((__always_inline__))
    : x(nx),
      y(ny),
      z(nz),
      w(nw) {
  }

  /**
   * Copy constructor.
   * @param src Source of data for new created vector4 instance.
   */
  inline constexpr explicit vector4(vector4<T> const &src) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y),
      z(src.z),
      w(src.w) {
  }

  /**
   * Copy casting constructor.
   * @param src Source of data for new created vector4 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector4(vector4<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)),
      w(static_cast<T>(src.w)) {
  }

  inline constexpr vector4(vector3<T> const &src, T new_w) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y),
      z(src.z),
      w(new_w) {
  }

  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector4(vector3<FromT> const &src, FromT new_w) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)),
      z(static_cast<T>(src.z)),
      w(static_cast<T>(new_w)) {
  }

  /**
   * Move constructor.
   * @param src Source of data for new created vector4 instance.
   */
  inline constexpr vector4(vector4<T> &&src) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
      y(std::move(src.y)),
      z(std::move(src.z)),
      w(std::move(src.w)) {
  }

  /**
   * Move casting constructor.
   * @param src Source of data for new created vector4 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector4(vector4<FromT> &&src) noexcept
    : x(static_cast<T>(std::move(src.x))),
      y(static_cast<T>(std::move(src.y))),
      z(static_cast<T>(std::move(src.z))),
      w(static_cast<T>(std::move(src.w))) {
  }

  //----------------[ assignment ]-------------------------
  /**
   * Sets to (x,y,z)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   * @param nz initial z-coordinate value
   * @param nz initial w-coordinate value
   */
  inline void constexpr assign(T nx = 0, T ny = 0, T nz = 0, T nw = 0) noexcept __attribute__((__always_inline__)) {
    x = nx;
    y = ny;
    z = nz;
    w = nw;
  }

  //----------------[ access operators ]-------------------
  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
    return *this;
  }

  /**
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector4<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    w = static_cast<T>(rhs.w);
    return *this;
  }

  /**
   * Copy operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = static_cast<T>(0);
    return *this;
  }

  /**
   * Copy casting operator to vector4 from vector3
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector4<T> constexpr &operator=(vector3<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    z = static_cast<T>(rhs.z);
    w = static_cast<T>(0);
    return *this;
  }


  /**
   * Move assignment operator
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
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
  }

  /**
   * Array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, n = 1
   * reference to y coordinate, n = 2 reference to z,
   * else reference to w coordinate.
   */
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : (n == 1 ? y : (n == 2 ? z : w));
  }

  //---------------[ vector aritmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator+(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator-(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator/(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator+=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator-=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator*=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    w *= rhs.w;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator/=(vector4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    w /= rhs.w;
    return *this;
  }

  /**
   * Addition operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator+(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);
  }

  /**
   * Subtraction operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator-(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w);
  }

  /**
   * Multiplication operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w);
  }

  /**
   * Division operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator/(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w);
  }

  /**
   * Addition operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator+=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  /**
   * Subtraction operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator-=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  /**
   * Multiplication operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator*=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }

  /**
   * Division operator with 3-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator/=(vector3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }

  /**
   * Addition operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x + rhs.x, y + rhs.y, z, w);
  }

  /**
   * Subtraction operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x - rhs.x, y - rhs.y, z, w);
  }

  /**
   * Multiplication operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs.x, y * rhs.y, z, w);
  }

  /**
   * Division operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / rhs.x, y / rhs.y, z, w);
  }

  /**
   * Addition operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  /**
   * Subtraction operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  /**
   * Multiplication operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  /**
   * Division operator with 2-vector
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  //-------------[ matrix operations ]-------------------------

  /**
   * Multiplication by 3x3 matrix operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this = rhs * *this;
    return *this;
  }

  /**
   * Multiplication by 4x4 matrix operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this = rhs * *this;
    return *this;
  }

  //--------------[ equality operator ]------------------------

  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
   * same for y-coordinate, z-coordinate, and w-coordinate.
   */
  inline bool constexpr operator==(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return std::abs(x - rhs.x) < static_cast<T>(epsilon) &&
             std::abs(y - rhs.y) < static_cast<T>(epsilon) &&
             std::abs(z - rhs.z) < static_cast<T>(epsilon) &&
             std::abs(w - rhs.w) < static_cast<T>(epsilon);
    #else
      return x == rhs.x &&
             y == rhs.y &&
             z == rhs.z &&
             w == rhs.w;
    #endif // VMATH_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated vector
   */
  inline vector4<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(-x, -y, -z, -w);
  }

  //--------------[ scalar vector operator ]--------------------

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
  }

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
    T const temp = length();
    if(temp == static_cast<T>(0)) {
      x = static_cast<T>(0);
      y = static_cast<T>(0);
      z = static_cast<T>(0);
      w = static_cast<T>(0);
    } else {
      x /= temp;
      y /= temp;
      z /= temp;
      w /= temp;
    }
  }
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_safe();
  }
  inline vector4<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    T const temp(length());
    if(temp == static_cast<T>(0)) {
      return vector4<T>();
    } else {
      return vector4<T>(x / temp, y / temp, z / temp, w / temp);
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

}

#endif // VECTORSTORM_VECTOR4_H_INCLUDED
