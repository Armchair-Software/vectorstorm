#ifndef VECTORSTORM_VECTOR2_H_INCLUDED
#define VECTORSTORM_VECTOR2_H_INCLUDED

#include "vectorstorm/deprecated_macros.h"
#include <cmath>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
#include "vector3_forward.h"
#include "vector4_forward.h"
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
 * Class for two dimensional vector.
 * There are three ways of accessing vector components.
 * Let's have <code>vector2f v</code>, you can either:
 * <ul>
 *  <li>access as position(x,y) &mdash; <code>v.x = v.y = 3;</code></li>
 *  <li>access as texture coordinate (s,t) &mdash; <code>v.s = v.t = 3;</code></li>
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = 3;</code></li>
 * </ul>
 */
template<typename T>
class vector2 {
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
  };

  union {
    /**
     * Second element of vector, alias for Y-coordinate.
     */
    T y;

    /**
     * Second element of vector, alias for Z-coordinate (for x-z 2D grids).
     */
    T z;

    /**
     * Second element of vector, alias for T-coordinate.
     * For textures notation.
     */
    T t;
  };

  //----------------[ constructors ]--------------------------
  /**
   * Creates and sets to (0,0)
   */
  inline constexpr vector2() noexcept __attribute__((__always_inline__))
    : x{T{}},
      y{T{}} {
  }

  /**
   * Creates and sets to (x,y)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   */
  inline constexpr vector2(T nx, T ny) noexcept __attribute__((__always_inline__))
    : x(nx),
      y(ny) {
  }

  /**
   * Copy constructor.
   * @param src Source of data for new created instance.
   */
  inline constexpr explicit vector2(vector2<T> const &src) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y) {
  }

  /**
   * Copy casting constructor.
   * @param src Source of data for new created instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector2(vector2<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)) {
  }

  /**
   * Copy constructor from a vector3.
   * @param src Source of x,y data for new created vector2 instance.
   */
  inline constexpr explicit vector2(vector3<T> const &src) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y) {
  }

  /**
   * Copy casting constructor from a vector3.
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector2(vector3<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)) {
  }

  /**
   * Copy constructor from a vector4.
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  inline constexpr explicit vector2(vector4<T> const &src) noexcept __attribute__((__always_inline__))
    : x(src.x),
      y(src.y) {
  }

  /**
   * Copy casting constructor from a vector4.
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector2(vector4<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
      y(static_cast<T>(src.y)) {
  }

  /**
   * Move constructor.
   * @param src Source of data for new created vector2 instance.
   */
  inline constexpr vector2(vector2<T> &&src) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
      y(std::move(src.y)) {
  }

  /**
   * Move casting constructor.
   * @param src Source of data for new created vector2 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr vector2(vector2<FromT> &&src) noexcept
    : x(static_cast<T>(std::move(src.x))),
      y(static_cast<T>(std::move(src.y))) {
  }

  /**
   * Move constructor from a vector4.
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  inline constexpr explicit vector2(vector4<T> const &&src) noexcept __attribute__((__always_inline__))
    : x(std::move(src.x)),
      y(std::move(src.y)) {
  }

  /**
   * Move casting constructor from a vector4.
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit vector2(vector4<FromT> const &&src) noexcept
    : x(static_cast<T>(std::move(src.x))),
      y(static_cast<T>(std::move(src.y))) {
  }

  //----------------[ assignment ]-------------------------
  /**
   * Sets to (x,y)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   */
  inline void constexpr assign(T nx = 0, T ny = 0) noexcept __attribute__((__always_inline__)) {
    x = nx;
    y = ny;
  }

  //----------------[ access operators ]-------------------
  /**
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector2<T> constexpr &operator=(vector2<FromT> const &rhs) noexcept {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    return *this;
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator=(vector2<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    x = std::move(rhs.x);
    y = std::move(rhs.y);
    return *this;
  }

  /**
   * Move assignment casting operator.
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline vector2<T> constexpr &operator=(vector2<FromT> &&rhs) noexcept {
    x = static_cast<T>(std::move(rhs.x));
    y = static_cast<T>(std::move(rhs.y));
    return *this;
  }

  /**
   * Array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, else reference to y
   * y coordinate.
   */
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : y;
  }

  /**
   * Constant array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, else reference to y
   * y coordinate.
   */
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
    return n == 0 ? x : y;
  }

  //---------------[ vector aritmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs.x, y + rhs.y);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x - rhs.x, y - rhs.y);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x * rhs.x, y * rhs.y);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x / rhs.x, y / rhs.y);
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator%(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x % rhs.x, y % rhs.y);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  /**
   * Substraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator%=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    x %= rhs.x;
    y %= rhs.y;
    return *this;
  }

  /**
   * Dot product of two vectors.
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr dot(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x * rhs.x) +
           (y * rhs.y);
  }
  [[deprecated("Use dot()")]]
  inline T constexpr dotProduct(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return dot(rhs);
  }

  /**
   * Cross product of two vectors
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr cross(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x * rhs.y) -
           (y * rhs.x);
  }
  [[deprecated("Use cross()")]]
  inline T constexpr crossProduct(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return cross(rhs);
  }

  //--------------[ scalar vector operator ]--------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs, y + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x - rhs, y - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x * rhs, y * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x / rhs, y / rhs);
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator%(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x % rhs, y % rhs);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    x += rhs;
    y += rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
    x -= rhs;
    y -= rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    x *= rhs;
    y *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    x /= rhs;
    y /= rhs;
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
  inline bool constexpr operator==(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VECTORSTORM_SOFT_COMPARE
      return (std::abs(x - rhs.x) < epsilon<T>) &&
             (std::abs(y - rhs.y) < epsilon<T>);
    #else
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wfloat-equal"
      return x == rhs.x &&
             y == rhs.y;
      #pragma GCC diagnostic pop
    #endif
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }
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
   * Less than test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are less than rhs' components.
   */
  inline bool constexpr operator<(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x < rhs.x) &&
           (y < rhs.y);
  }

  /**
   * Greater than test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are greater than rhs' components.
   */
  inline bool constexpr operator>(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x > rhs.x) &&
           (y > rhs.y);
  }

  /**
   * Less than or equal test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are less than or equal to rhs' components.
   */
  inline bool constexpr operator<=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x <= rhs.x) &&
           (y <= rhs.y);
  }

  /**
   * Greater than or equal test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are greater than or equal to rhs' components.
   */
  inline bool constexpr operator>=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x >= rhs.x) &&
           (y >= rhs.y);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated vector
   */
  inline vector2<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(-x, -y);
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
    return x * x + y * y;
  }
  [[deprecated("Use length_sq()")]]
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) {
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
           y == static_cast<T>(0);
    */
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
    return std::abs(x) < epsilon<T> &&
           std::abs(y) < epsilon<T>;
  }

  /**
   * normalise vector
   */
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
    T const temp = length();
    x /= temp;
    y /= temp;
  }
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    T const temp = length_fast();
    x /= temp;
    y /= temp;
  }
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    T const temp = length_faster();
    x /= temp;
    y /= temp;
  }
  [[deprecated("Proper English, please!")]]
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) {
    normalise();
  }
  [[deprecated("Proper English, please!")]]
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) {
    normalise_fast();
  }
  [[deprecated("Proper English, please!")]]
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) {
    normalise_faster();
  }
  inline vector2<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
    T const temp(length());
    return vector2<T>(x / temp, y / temp);
  }
  inline vector2<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return vector2<T>(x / temp, y / temp);
  }
  inline vector2<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return vector2<T>(x / temp, y / temp);
  }
  [[deprecated("Proper English, please!")]]
  inline vector2<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy();
  }
  [[deprecated("Proper English, please!")]]
  inline vector2<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy_fast();
  }
  [[deprecated("Proper English, please!")]]
  inline vector2<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) {
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
  [[deprecated("Proper English, please!")]]
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) {
    normalise_safe();
  }
  inline vector2<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    if(length_zero()) {
      return vector2<T>();
    } else {
      return *this / length();
    }
  }
  [[deprecated("Proper English, please!")]]
  inline vector2<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) {
    return normalise_safe_copy();
  }

  /**
   * Absolute vector (make all values positive)
   */
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {
    x = std::abs(x);
    y = std::abs(y);
  }
  inline vector2<T> constexpr abs_copy() const __attribute__((__always_inline__)) {
    return vector2<T>(std::abs(x), std::abs(y));
  }

  //-------------[ other operations ]--------------------------
  /**
   * Rotate 2D vector clockwise.
   * @param aa Angle (in degrees) to be rotated.
   */
  inline void constexpr rotate(T aa) noexcept __attribute__((__always_inline__)) {
    rotate_rad(deg2rad(aa));
  }

  /**
   * Rotate 2D vector clockwise, radian version.
   * @param aa Angle (in radians) to be rotated.
   */
  inline void constexpr rotate_rad(T aa) noexcept __attribute__((__always_inline__)) {
    T temp_sin = static_cast<T>(0);
    T temp_cos = static_cast<T>(0);
    sincos_any(-aa, temp_sin, temp_cos);
    T const nx = static_cast<T>((temp_cos * x) - (temp_sin * y));
    T const ny = static_cast<T>((temp_cos * y) + (temp_sin * x));
    x = nx;
    y = ny;
  }

  /**
   * Linear interpolation of two vectors
   * @param fact Factor of interpolation. For translation from position
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
   * @param r Second vector for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  inline vector2<T> constexpr lerp(T fact, vector2<T> const &r) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (r - (*this)) * fact;
  }

  //-------------[ conversion ]-----------------------------
  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector2<T>)
   * used for passing vector2<T> values to gl*2[fd] functions.
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }
  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector2<T>)
   * used for passing vector2<T> values to gl*2[fd] functions.
   */
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(this);
  }

  //-------------[ output operator ]------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    lhs << "[" << +rhs.x << "," << +rhs.y << "]";
    return lhs;
  }

  /**
   * Gets string representation.
   */
  inline std::string CONSTEXPR_IF_NO_CLANG to_string() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }
  inline std::string CONSTEXPR_IF_NO_CLANG toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
    return to_string();
  }

  /**
   * Check whether two lines intersect, and if so obtain the intersection point
   * and store it in this vector.
   * @param line1start The start coordinates of the first line
   * @param line1end The end coordinates of the first line
   * @param line2start The start coordinates of the first line
   * @param line2end The end coordinates of the first line
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline bool constexpr get_line_intersection(vector2<FromT> const &line1start,
                                              vector2<FromT> const &line1end,
                                              vector2<FromT> const &line2start,
                                              vector2<FromT> const &line2end) noexcept {
    vector2<T> const temp_s1(line1end.x - line1start.x,
                             line1end.y - line1start.y);
    vector2<T> const temp_s2(line2end.x - line2start.x,
                             line2end.y - line2start.y);
    T const temp_s = (-temp_s1.y * (line1start.x - line2start.x) + temp_s1.x * (line1start.y - line2start.y)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
    T const temp_t = ( temp_s2.x * (line1start.y - line2start.y) - temp_s2.y * (line1start.x - line2start.x)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
    if(temp_s >= 0 && temp_s <= 1 && temp_t >= 0 && temp_t <= 1) {
      x = line1start.x + (temp_t * temp_s1.x);
      y = line1start.y + (temp_t * temp_s1.y);
      return true;
    }
    return false;
  }

  /**
   * Free function to check whether two lines intersect.
   * @param line1start The start coordinates of the first line
   * @param line1end The end coordinates of the first line
   * @param line2start The start coordinates of the first line
   * @param line2end The end coordinates of the first line
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline static bool constexpr do_lines_intersect(vector2<FromT> const &line1start,
                                                  vector2<FromT> const &line1end,
                                                  vector2<FromT> const &line2start,
                                                  vector2<FromT> const &line2end) noexcept {
    vector2<T> constexpr temp_s1(line1end.x - line1start.x,
                            line1end.y - line1start.y);
    vector2<T> constexpr temp_s2(line2end.x - line2start.x,
                            line2end.y - line2start.y);
    T constexpr temp_s = (-temp_s1.y * (line1start.x - line2start.x) + temp_s1.x * (line1start.y - line2start.y)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
    T constexpr temp_t = ( temp_s2.x * (line1start.y - line2start.y) - temp_s2.y * (line1start.x - line2start.x)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
    if(temp_s >= 0 && temp_s <= 1 && temp_t >= 0 && temp_t <= 1) {
      return true;
    }
    return false;
  }

  /**
   * Gets a 3D vector equivalent populating the X and Y axes
   */
  inline vector3<T> constexpr to_3d_xy() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x, y, 0);
  }
  [[deprecated("Use lowercase version.")]]
  inline vector3<T> constexpr to_3D_XY() const noexcept __attribute__((__always_inline__)) {
    return to_3d_xy();
  }

  /**
   * Gets a 3D vector equivalent populating the X and Z axes
   */
  inline vector3<T> constexpr to_3d_xz() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x, 0, z);
  }
  [[deprecated("Use lowercase version.")]]
  inline vector3<T> constexpr to_3D_XZ() const noexcept __attribute__((__always_inline__)) {
    return to_3d_xz();
  }
};

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "vector2_types.h"

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
inline constexpr vector2<T> min(vector2<T> const &a, vector2<T> const &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector2<T> min(vector2<T> const &a, vector2<T> const &b) noexcept {
  return vector2<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
inline constexpr vector2<T> max(vector2<T> const &a, vector2<T> const &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector2<T> max(vector2<T> const &a, vector2<T> const &b) noexcept {
  return vector2<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y));
}

template<typename T>
struct hash<vector2<T>> {
  /**
   * Gets a hash value taking account of all dimensions of this vector, for use
   * in standard container maps etc.
   * Note: You need to #include <boost/functional/hash.hpp> before instantiating this if VECTORSTORM_NO_BOOST is not defined.
   * @return Hash value
   */
  size_t operator()(vector2<T> const &value) const {
    size_t hashvalue = 0;
    HASH_COMBINE(hashvalue, value.x);
    HASH_COMBINE(hashvalue, value.y);
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
size_t hash_value(vector2<T> const &value) {
  size_t hashvalue = 0;
  HASH_COMBINE(hashvalue, value.x);
  HASH_COMBINE(hashvalue, value.y);
  return hashvalue;
}

#endif // VECTORSTORM_VECTOR2_H_INCLUDED
