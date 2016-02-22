#ifndef VECTORSTORM_VECTOR2_H_INCLUDED
#define VECTORSTORM_VECTOR2_H_INCLUDED

#include <cmath>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/sincos.h"
#include "vectorstorm/deg2rad.h"
#include "vector3_forward.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
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
  inline constexpr vector2() __attribute__((__always_inline__))
    : x(0), y(0) {
  }

  /**
   * Creates and sets to (x,y)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   */
  inline constexpr vector2(T nx, T ny) __attribute__((__always_inline__))
    : x(nx), y(ny) {
  }

  /**
   * Copy constructor.
   * @param src Source of data for new created instance.
   */
  inline constexpr vector2(vector2<T> const &src) __attribute__((__always_inline__))
    : x(src.x), y(src.y) {
  }

  /**
   * Copy casting constructor.
   * @param src Source of data for new created instance.
   */
  template<typename FromT>
  inline constexpr vector2(vector2<FromT> const &src)
    : x(static_cast<T>(src.x)), y(static_cast<T>(src.y)) {
  }

  //----------------[ assignment ]-------------------------
  /**
   * Sets to (x,y)
   * @param nx initial x-coordinate value
   * @param ny initial y-coordinate value
   */
  inline void constexpr assign(T nx = 0, T ny = 0) __attribute__((__always_inline__)) {
    x = nx;
    y = ny;
  }

  //----------------[ access operators ]-------------------
  /**
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT>
  inline vector2<T> constexpr &operator=(vector2<FromT> const &rhs) {
    x = static_cast<T>(rhs.x);
    y = static_cast<T>(rhs.y);
    return *this;
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }

  /**
   * Array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, else reference to y
   * y coordinate.
   */
  inline T constexpr &operator[](int n) __attribute__((__always_inline__)) {
    return n == 0 ? x : y;
  }

  /**
   * Constant array access operator
   * @param n Array index
   * @return For n = 0, reference to x coordinate, else reference to y
   * y coordinate.
   */
  inline T constexpr const &operator[](int n) const __attribute__((__always_inline__)) {
    return n == 0 ? x : y;
  }

  //---------------[ vector aritmetic operator ]--------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator+(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs.x, y + rhs.y);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator-(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x - rhs.x, y - rhs.y);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator*(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x * rhs.x, y * rhs.y);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator/(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x / rhs.x, y / rhs.y);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator+=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  /**
   * Substraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator-=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator*=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator/=(vector2<T> const &rhs) __attribute__((__always_inline__)) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  /**
   * Dot product of two vectors.
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr dotProduct(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return x * rhs.x + y * rhs.y;
  }

  /**
   * Cross product of two vectors
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr crossProduct(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return x * rhs.y - y * rhs.x;
  }

  //--------------[ scalar vector operator ]--------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator+(T rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs, y + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator-(T rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x - rhs, y - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator*(T rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x * rhs, y * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr operator/(T rhs) const __attribute__((__always_inline__)) {
    return vector2<T>(x / rhs, y / rhs);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator+=(T rhs) __attribute__((__always_inline__)) {
    x += rhs;
    y += rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator-=(T rhs) __attribute__((__always_inline__)) {
    x -= rhs;
    y -= rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator*=(T rhs) __attribute__((__always_inline__)) {
    x *= rhs;
    y *= rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector2<T> constexpr &operator/=(T rhs) __attribute__((__always_inline__)) {
    x /= rhs;
    y /= rhs;
    return *this;
  }

  //--------------[ equality operator ]------------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
   * same for y-coordinate.
   */
  inline bool constexpr operator==(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return (std::abs(x - rhs.x) < static_cast<T>(epsilon)) &&
             (std::abs(y - rhs.y) < static_cast<T>(epsilon));
    #else
      return x == rhs.x &&
             y == rhs.y;
    #endif
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(vector2<T> const &rhs) const __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //-------------[ unary operations ]--------------------------
  /**
   * Unary negate operator
   * @return negated vector
   */
  inline vector2<T> constexpr operator-() const __attribute__((__always_inline__)) {
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
  inline T constexpr lengthSq() const __attribute__((__always_inline__)) {
    return x * x + y * y;
  }

  /**
   * Get length of vector.
   * @return length of vector
   */
  inline T constexpr length() const __attribute__((__always_inline__)) {
    return static_cast<T>(std::sqrt(lengthSq()));
  }
  /**
   * Get length of vector, fast approximation.
   * @return length of vector
   */
  inline T constexpr length_fast() const __attribute__((__always_inline__)) {
    return static_cast<T>(sqrt_fast(lengthSq()));
  }
  /**
   * Get length of vector, rougher fast approximation.
   * @return length of vector
   */
  inline T constexpr length_faster() const __attribute__((__always_inline__)) {
    return static_cast<T>(sqrt_faster(lengthSq()));
  }

  /**
   * normalise vector
   */
  inline void constexpr normalise() __attribute__((__always_inline__)) {
    T const temp = length();
    x /= temp;
    y /= temp;
  }
  inline void constexpr normalise_fast() __attribute__((__always_inline__)) {
    T const temp = length_fast();
    x /= temp;
    y /= temp;
  }
  inline void constexpr normalise_faster() __attribute__((__always_inline__)) {
    T const temp = length_faster();
    x /= temp;
    y /= temp;
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
  inline vector2<T> constexpr normalise_copy() const __attribute__((__always_inline__)) {
    T const temp(length());
    return vector2<T>(x / temp, y / temp);
  }
  inline vector2<T> constexpr normalise_copy_fast() const __attribute__((__always_inline__)) {
    T const temp(length_fast());
    return vector2<T>(x / temp, y / temp);
  }
  inline vector2<T> constexpr normalise_copy_faster() const __attribute__((__always_inline__)) {
    T const temp(length_faster());
    return vector2<T>(x / temp, y / temp);
  }
  inline vector2<T> constexpr normalize_copy() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline vector2<T> constexpr normalize_copy_fast() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline vector2<T> constexpr normalize_copy_faster() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
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
    } else {
      x /= temp;
      y /= temp;
    }
  }
  inline void constexpr normalize_safe() __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_safe();
  }
  inline vector2<T> constexpr normalise_safe_copy() const __attribute__((__always_inline__)) {
    T const temp(length());
    if(temp == static_cast<T>(0)) {
      return vector2<T>();
    } else {
      return vector2<T>(x / temp, y / temp);
    }
  }
  inline vector2<T> constexpr normalize_safe_copy() const __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_safe_copy();
  }

  /**
   * Absolute vector (make all values positive)
   */
  inline void constexpr abs() __attribute__((__always_inline__)) {
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
  inline void constexpr rotate(T aa) __attribute__((__always_inline__)) {
    rotate_rad(deg2rad(aa));
  }

  /**
   * Rotate 2D vector clockwise, radian version.
   * @param aa Angle (in radians) to be rotated.
   */
  inline void constexpr rotate_rad(T aa) __attribute__((__always_inline__)) {
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
  inline vector2<T> constexpr lerp(T fact, vector2<T> const &r) const __attribute__((__always_inline__)) {
    return (*this) + (r - (*this)) * fact;
  }

  //-------------[ conversion ]-----------------------------
  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class vector2<T>)
   * used for passing vector2<T> values to gl*2[fd] functions.
   */
  inline constexpr operator T*() __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(this);
  }
  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class vector2<T>)
   * used for passing vector2<T> values to gl*2[fd] functions.
   */
  inline constexpr operator const T*() const __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(this);
  }

  //-------------[ output operator ]------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator<<(std::ostream &lhs, vector2<T> const &rhs) __attribute__((__always_inline__)) {
    lhs << "[" << rhs.x << "," << rhs.y << "]";
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
   * Check whether two lines intersect, and if so obtain the intersection point
   * and store it in this vector.
   * @param line1start The start coordinates of the first line
   * @param line1end The end coordinates of the first line
   * @param line2start The start coordinates of the first line
   * @param line2end The end coordinates of the first line
   */
  template<typename FromT>
  inline bool constexpr get_line_intersection(vector2<FromT> const &line1start,
                                              vector2<FromT> const &line1end,
                                              vector2<FromT> const &line2start,
                                              vector2<FromT> const &line2end) {
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
  template<typename FromT>
  inline static bool constexpr do_lines_intersect(vector2<FromT> const &line1start,
                                                  vector2<FromT> const &line1end,
                                                  vector2<FromT> const &line2start,
                                                  vector2<FromT> const &line2end) {
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
  inline vector3<T> constexpr to_3D_XY() const __attribute__((__always_inline__)) {
    return vector3<T>(x, y, 0);
  }
  inline vector3<T> constexpr to_3d_xy() const __attribute__((__always_inline__)) {
    return vector3<T>(x, y, 0);
  }

  /**
   * Gets a 3D vector equivalent populating the X and Z axes
   */
  inline vector3<T> constexpr to_3D_XZ() const __attribute__((__always_inline__)) {
    return vector3<T>(x, 0, z);
  }
  inline vector3<T> constexpr to_3d_xz() const __attribute__((__always_inline__)) {
    return vector3<T>(x, 0, z);
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector2_types.h"

#endif // VECTORSTORM_VECTOR2_H_INCLUDED
