#pragma once

#include <cmath>
#include <type_traits>
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
  inline constexpr explicit vector2(vector2<T> const &src) noexcept __attribute__((__always_inline__)) = default;

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
  inline constexpr vector2(vector2<T> &&src) noexcept __attribute__((__always_inline__)) = default;

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
  inline vector2<T> constexpr &operator=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) = default;

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator=(vector2<T> &&rhs) noexcept __attribute__((__always_inline__)) = default;

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
  [[nodiscard]]
  inline constexpr T &operator[](unsigned int n) noexcept __attribute__((__always_inline__)) {
    return n == 0u ? x : y;
  }

  /**
   * Constant array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, else reference to y
   * y coordinate.
   */
  [[nodiscard]]
  inline constexpr T const &operator[](unsigned int n) const noexcept __attribute__((__always_inline__)) {
    return n == 0u ? x : y;
  }

  //---------------[ vector aritmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs.x, y + rhs.y);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x - rhs.x, y - rhs.y);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x * rhs.x, y * rhs.y);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x / rhs.x, y / rhs.y);
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
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
  [[nodiscard]]
  inline T constexpr dot(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x * rhs.x) +
           (y * rhs.y);
  }

  /**
   * Cross product of two vectors
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline T constexpr cross(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x * rhs.y) -
           (y * rhs.x);
  }

  //--------------[ scalar vector operator ]--------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs, y + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x - rhs, y - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x * rhs, y * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x / rhs, y / rhs);
  }

  /**
   * Modulo operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
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
  [[nodiscard]]
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
  [[nodiscard]]
  inline bool constexpr operator!=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  /**
   * Less than test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are less than rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator<(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x < rhs.x) &&
           (y < rhs.y);
  }

  /**
   * Greater than test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are greater than rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator>(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x > rhs.x) &&
           (y > rhs.y);
  }

  /**
   * Less than or equal test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are less than or equal to rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator<=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x <= rhs.x) &&
           (y <= rhs.y);
  }

  /**
   * Greater than or equal test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Returns true if all components are greater than or equal to rhs' components.
   */
  [[nodiscard]]
  inline bool constexpr operator>=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (x >= rhs.x) &&
           (y >= rhs.y);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary plus operator
   * @return vector with unary + applied to its components
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator+() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(+x, +y);
  }
  /**
   * Unary negate operator
   * @return negated vector
   */
  [[nodiscard]]
  inline vector2<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(-x, -y);
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
   * @return number of elements (will always return 2)
   */
  [[nodiscard]]
  static inline unsigned int constexpr size() noexcept __attribute__((__always_inline__)) __attribute__((__const__)) {
    return 2u;
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
    return x * x + y * y;
  }

  /**
   * Get length of vector.
   * @return length of vector
   */
  template<sqrt_mode mode = sqrt_mode::std> [[nodiscard]]
  inline T  __attribute__((__always_inline__))constexpr length() const noexcept {
    return sqrt_switchable<mode>(length_sq());
  }
  /**
   * Get length of vector, fast approximation.
   * @return length of vector
   */
  [[nodiscard]] [[deprecated("Use length<vector2<T>::sqrt_mode::fast>()")]]
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    return length<sqrt_mode::fast>();
  }
  /**
   * Get length of vector, rougher fast approximation.
   * @return length of vector
   */
  [[nodiscard]] [[deprecated("Use length<vector2<T>::sqrt_mode::coarse>()")]]
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
             y == static_cast<T>(0);
    #endif //VECTORSTORM_SOFT_COMPARE
    */
    // the above may fail to detect cases where the sqrt of two tiny numbers would be zero
    return std::abs(x) < epsilon<T> &&
           std::abs(y) < epsilon<T>;
  }

  /**
   * normalise vector
   */
  template<sqrt_mode mode = sqrt_mode::std>
  inline void __attribute__((__always_inline__)) constexpr normalise() noexcept {
    *this /= length<mode>();
  }
  [[deprecated("Use normalise<vector2<T>::sqrt_mode::fast>()")]]
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
    normalise<sqrt_mode::fast>();
  }
  [[deprecated("Use normalise<vector2<T>::sqrt_mode::coarse>()")]]
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
    normalise<sqrt_mode::coarse>();
  }
  template<sqrt_mode mode = sqrt_mode::std> [[nodiscard]]
  inline vector2<T> __attribute__((__always_inline__)) constexpr normalise_copy() const noexcept {
    return *this / length<mode>();
  }
  [[nodiscard]] [[deprecated("Use normalise_copy<vector2<T>::sqrt_mode::fast>()")]]
  inline vector2<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {
    return normalise_copy<sqrt_mode::fast>();
  }
  [[nodiscard]] [[deprecated("Use normalise_copy<vector2<T>::sqrt_mode::coarse>()")]]
  inline vector2<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
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
  inline vector2<T> __attribute__((__always_inline__)) constexpr normalise_safe_copy() const noexcept {
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
  }
  [[nodiscard]]
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
  [[nodiscard("Interpolation does not modify the input vectors")]]
  inline vector2<T> constexpr lerp(T fact, vector2<T> const &r) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (r - (*this)) * fact;
  }

  //-------------[ conversion ]-----------------------------
  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector2<T>)
   * used for passing vector2<T> values to gl*2[fd] functions.
   */
  [[nodiscard]]
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }
  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector2<T>)
   * used for passing vector2<T> values to gl*2[fd] functions.
   */
  [[nodiscard]]
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
  [[nodiscard]]
  inline std::string CONSTEXPR_IF_NO_CLANG to_string() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }

  /**
   * Check whether two lines intersect, and if so obtain the intersection point
   * and store it in this vector.
   * @param line1start The start coordinates of the first line
   * @param line1end The end coordinates of the first line
   * @param line2start The start coordinates of the first line
   * @param line2end The end coordinates of the first line
   */
  template<typename FromT> [[nodiscard]] __attribute__((__always_inline__))
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
  template<typename FromT> [[nodiscard]] __attribute__((__always_inline__))
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
  [[nodiscard]]
  inline vector3<T> constexpr to_3d_xy() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x, y, 0);
  }

  /**
   * Gets a 3D vector equivalent populating the X and Z axes
   */
  [[nodiscard]]
  inline vector3<T> constexpr to_3d_xz() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x, 0, z);
  }
};

static_assert(std::is_trivially_copyable_v<vector2<int>>);
static_assert(std::is_trivially_copyable_v<vector2<float>>);

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
