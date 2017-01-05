    return vector2<T>(x / rhs, y / rhs);
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

#ifndef VECTORSTORM_VECTOR2_H_INCLUDED
  //--------------[ equality operator ]------------------------
#define VECTORSTORM_VECTOR2_H_INCLUDED
  /**

   * Equality test operator
#include <cmath>
   * @param rhs Right hand side argument of binary operator.
#include <sstream>
   * @note Test of equality is based of threshold epsilon value. To be two
#include "vectorstorm/epsilon.h"
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
#include "vectorstorm/sincos.h"
   * same for y-coordinate.
#include "vectorstorm/deg2rad.h"
   */
#include "vector3_forward.h"
#include "vector4_forward.h"
  inline bool constexpr operator==(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
#ifndef VMATH_NO_BOOST
    #ifdef VMATH_SOFT_COMPARE
  #include <boost/functional/hash_fwd.hpp>
      return (std::abs(x - rhs.x) < epsilon<T>) &&
#endif // VMATH_NO_BOOST
             (std::abs(y - rhs.y) < epsilon<T>);

    #else
#ifdef VMATH_NAMESPACE
      return x == rhs.x &&
namespace VMATH_NAMESPACE {
             y == rhs.y;
#endif
    #endif

  }
/**

 * Class for two dimensional vector.
  /**
 * There are three ways of accessing vector components.
   * Inequality test operator
 * Let's have <code>vector2f v</code>, you can either:
   * @param rhs Right hand side argument of binary operator.
 * <ul>
   * @return not (lhs == rhs) :-P
 *  <li>access as position(x,y) &mdash; <code>v.x = v.y = 3;</code></li>
   */
 *  <li>access as texture coordinate (s,t) &mdash; <code>v.s = v.t = 3;</code></li>
  inline bool constexpr operator!=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
 *  <li>access via operator[] &mdash; <code>v[0] = v[1] = 3;</code></li>
    return !(*this == rhs);
 * </ul>
  }
 */

template<typename T>
class vector2 {
  //-------------[ unary operations ]--------------------------
public:
  /**
  union {
   * Unary negate operator
    /**
   * @return negated vector
     * First element of vector, alias for X-coordinate.
   */
     */
  inline vector2<T> constexpr operator-() const noexcept __attribute__((__always_inline__)) {
    T x;
    return vector2<T>(-x, -y);

  }
    /**

     * First element of vector, alias for S-coordinate.
  //-------------[ size operations ]---------------------------
     * For textures notation.
  /**
     */
    T s;
   * Return square of length.
  };
   * @return length ^ 2

   * @note This method is faster then length(). For comparison
  union {
   * of length of two vector can be used just this value, instead
    /**
   * of more expensive length() method.
     * Second element of vector, alias for Y-coordinate.
   */
     */
  inline T constexpr length_sq() const noexcept __attribute__((__always_inline__)) {
    T y;
    return x * x + y * y;

  }
    /**
     * Second element of vector, alias for Z-coordinate (for x-z 2D grids).
  inline T constexpr lengthSq() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use length_sq()"))) {
     */
    return length_sq();
    T z;
  }


    /**
  /**
     * Second element of vector, alias for T-coordinate.
   * Get length of vector.
     * For textures notation.
   * @return length of vector
     */
   */
    T t;
  inline T constexpr length() const noexcept __attribute__((__always_inline__)) {
  };
    return static_cast<T>(std::sqrt(length_sq()));

  }
  //----------------[ constructors ]--------------------------
  /**
  /**
   * Get length of vector, fast approximation.
   * Creates and sets to (0,0)
   * @return length of vector
   */
   */
  inline constexpr vector2() noexcept __attribute__((__always_inline__))
  inline T constexpr length_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
    : x(0),
      y(0) {
    return static_cast<T>(sqrt_fast(length_sq()));
  }
  }

  /**
  /**
   * Get length of vector, rougher fast approximation.
   * Creates and sets to (x,y)
   * @return length of vector
   * @param nx initial x-coordinate value
   */
   * @param ny initial y-coordinate value
  inline T constexpr length_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__pure__)) {
   */
    return static_cast<T>(sqrt_faster(length_sq()));
  inline constexpr vector2(T nx, T ny) noexcept __attribute__((__always_inline__))
  }
    : x(nx),
  /**
      y(ny) {
   * Return whether the vector is zero length - this is much faster than a full length calculation
  }

   * @return whether vector is zero length
  /**
   */
   * Copy constructor.
  inline bool constexpr length_zero() const noexcept __attribute__((__always_inline__)) {
   * @param src Source of data for new created instance.
    /*
   */
    return x == static_cast<T>(0) &&
  inline constexpr explicit vector2(vector2<T> const &src) noexcept __attribute__((__always_inline__))
           y == static_cast<T>(0);
    : x(src.x),
    */
      y(src.y) {
    // the above may fail to detect cases where the sqrt of three tiny numbers would be zero
  }
    return std::abs(x) < epsilon<T> &&

           std::abs(y) < epsilon<T>;
  /**
  }
   * Copy casting constructor.

   * @param src Source of data for new created instance.
  /**
   */
   * normalise vector
  template<typename FromT> __attribute__((__always_inline__))
   */
  inline constexpr explicit vector2(vector2<FromT> const &src) noexcept
    : x(static_cast<T>(src.x)),
  inline void constexpr normalise() noexcept __attribute__((__always_inline__)) {
      y(static_cast<T>(src.y)) {
    T const temp = length();
  }
    x /= temp;

    y /= temp;
  /**
  }
   * Copy constructor from a vector3.
  inline void constexpr normalise_fast() noexcept __attribute__((__always_inline__)) {
   * @param src Source of x,y data for new created vector2 instance.
    T const temp = length_fast();
   */
    x /= temp;
  inline constexpr vector2(vector3<T> const &src) noexcept __attribute__((__always_inline__))
    y /= temp;
    : x(src.x),
  }
      y(src.y) {
  inline void constexpr normalise_faster() noexcept __attribute__((__always_inline__)) {
  }
    T const temp = length_faster();

    x /= temp;
  /**
    y /= temp;
   * Copy casting constructor from a vector3.
  }
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  template<typename FromT> __attribute__((__always_inline__))
    normalise();
  inline constexpr vector2(vector3<FromT> const &src) noexcept
  }
    : x(static_cast<T>(src.x)),
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
      y(static_cast<T>(src.y)) {
    normalise_fast();
  }
  }

  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  /**
    normalise_faster();
   * Copy constructor from a vector4.
  }
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  inline vector2<T> constexpr normalise_copy() const noexcept __attribute__((__always_inline__)) {
  inline constexpr vector2(vector4<T> const &src) noexcept __attribute__((__always_inline__))
    T const temp(length());
    : x(src.x),
    return vector2<T>(x / temp, y / temp);
      y(src.y) {
  }
  }
  inline vector2<T> constexpr normalise_copy_fast() const noexcept __attribute__((__always_inline__)) {

    T const temp(length_fast());
  /**
    return vector2<T>(x / temp, y / temp);
   * Copy casting constructor from a vector4.
  }
   * @param src Source of x,y,z data for new created vector2 instance.
   */
  inline vector2<T> constexpr normalise_copy_faster() const noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    T const temp(length_faster());
  inline constexpr vector2(vector4<FromT> const &src) noexcept
    return vector2<T>(x / temp, y / temp);
    : x(static_cast<T>(src.x)),
  }
      y(static_cast<T>(src.y)) {
  inline vector2<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  }
    return normalise_copy();

  }
  /**
  inline vector2<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * Move constructor.
    return normalise_copy_fast();
   * @param src Source of data for new created vector2 instance.
  }
   */
  inline vector2<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
  inline constexpr vector2(vector2<T> &&src) noexcept __attribute__((__always_inline__))
    return normalise_copy_faster();
    : x(std::move(src.x)),
  }
      y(std::move(src.y)) {
  /**
  }

   * normalise vector. with added zero safety check
  /**
   */
   * Move casting constructor.
  inline void constexpr normalise_safe() noexcept __attribute__((__always_inline__)) {
   * @param src Source of data for new created vector2 instance.
    if(length_zero()) {
   */
      assign();
  template<typename FromT> __attribute__((__always_inline__))
    } else {
  inline constexpr vector2(vector2<FromT> &&src) noexcept
      *this /= length();
    : x(static_cast<T>(std::move(src.x))),
    }
      y(static_cast<T>(std::move(src.y))) {
  }
  }
  inline void constexpr normalize_safe() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {

    normalise_safe();
  /**
  }
   * Move constructor from a vector3.
   * @param src Source of x,y data for new created vector2 instance.
  inline vector2<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
   */
    if(length_zero()) {
  inline constexpr vector2(vector3<T> const &&src) noexcept __attribute__((__always_inline__))
      return vector2<T>();
    : x(std::move(src.x)),
    } else {
      y(std::move(src.y)) {
      return *this / length();
  }
    }

  }
  /**
  inline vector2<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
   * Move casting constructor from a vector3.
    return normalise_safe_copy();
   * @param src Source of x,y,z data for new created vector2 instance.
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline constexpr vector2(vector3<FromT> const &&src) noexcept
   * Absolute vector (make all values positive)
    : x(static_cast<T>(std::move(src.x))),
   */
      y(static_cast<T>(std::move(src.y))) {
  }
  inline void constexpr abs() noexcept __attribute__((__always_inline__)) {

    x = std::abs(x);
  /**
    y = std::abs(y);
   * Move constructor from a vector4.
  }
   * @param src Source of x,y,z data for new created vector2 instance.
  inline vector2<T> constexpr abs_copy() const __attribute__((__always_inline__)) {
   */
    return vector2<T>(std::abs(x), std::abs(y));
  inline constexpr vector2(vector4<T> const &&src) noexcept __attribute__((__always_inline__))
  }
    : x(std::move(src.x)),

      y(std::move(src.y)) {
  //-------------[ other operations ]--------------------------
  }
  /**

   * Rotate 2D vector clockwise.
  /**
   * @param aa Angle (in degrees) to be rotated.
   * Move casting constructor from a vector4.
   */
   * @param src Source of x,y,z data for new created vector2 instance.
  inline void constexpr rotate(T aa) noexcept __attribute__((__always_inline__)) {
   */
    rotate_rad(deg2rad(aa));
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline constexpr vector2(vector4<FromT> const &&src) noexcept

    : x(static_cast<T>(std::move(src.x))),
  /**
      y(static_cast<T>(std::move(src.y))) {
  }
   * Rotate 2D vector clockwise, radian version.

   * @param aa Angle (in radians) to be rotated.
  //----------------[ assignment ]-------------------------
   */
  /**
  inline void constexpr rotate_rad(T aa) noexcept __attribute__((__always_inline__)) {
   * Sets to (x,y)
    T temp_sin = static_cast<T>(0);
   * @param nx initial x-coordinate value
    T temp_cos = static_cast<T>(0);
   * @param ny initial y-coordinate value
    sincos_any(-aa, temp_sin, temp_cos);
   */
    T const nx = static_cast<T>((temp_cos * x) - (temp_sin * y));
  inline void constexpr assign(T nx = 0, T ny = 0) noexcept __attribute__((__always_inline__)) {
    T const ny = static_cast<T>((temp_cos * y) + (temp_sin * x));
    x = nx;
    x = nx;
    y = ny;
    y = ny;
  }
  }


  //----------------[ access operators ]-------------------
  /**
  /**
   * Linear interpolation of two vectors
   * Copy casting operator
   * @param fact Factor of interpolation. For translation from position
   * @param rhs Right hand side argument of binary operator.
   */
   * of this vector to vector r, values of factor goes from 0.0 to 1.0.
  template<typename FromT> __attribute__((__always_inline__))
   * @param r Second vector for interpolation
  inline vector2<T> constexpr &operator=(vector2<FromT> const &rhs) noexcept {
   * @note However values of fact parameter are reasonable only in interval
    x = static_cast<T>(rhs.x);
   * [0.0 , 1.0], you can pass also values outside of this interval and you
    y = static_cast<T>(rhs.y);
   * can get result (extrapolation?)
    return *this;
   */
  }
  inline vector2<T> constexpr lerp(T fact, vector2<T> const &r) const noexcept __attribute__((__always_inline__)) {

    return (*this) + (r - (*this)) * fact;
  /**
  }
   * Copy operator

   * @param rhs Right hand side argument of binary operator.
   */
  //-------------[ conversion ]-----------------------------
  inline vector2<T> constexpr &operator=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    x = rhs.x;
   * Conversion to pointer operator
    y = rhs.y;
   * @return Pointer to internally stored (in management of class vector2<T>)
    return *this;
   * used for passing vector2<T> values to gl*2[fd] functions.
  }
   */

  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
  /**
    return reinterpret_cast<T*>(this);
   * Move assignment operator
  }
   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Conversion to pointer operator
  inline vector2<T> constexpr &operator=(vector2<T> &&rhs) noexcept __attribute__((__always_inline__)) {
   * @return Constant Pointer to internally stored (in management of class vector2<T>)
    x = std::move(rhs.x);
    y = std::move(rhs.y);
   * used for passing vector2<T> values to gl*2[fd] functions.
    return *this;
   */
  }
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {

    return reinterpret_cast<T const*>(this);
  /**
  }
   * Move assignment casting operator.

   * @param rhs Right hand side argument of binary operator.
  //-------------[ output operator ]------------------------
   */
  /**
  template<typename FromT> __attribute__((__always_inline__))
   * Output to stream operator
  inline vector2<T> constexpr &operator=(vector2<FromT> &&rhs) noexcept {
   * @param lhs Left hand side argument of operator (commonly ostream instance).
    x = static_cast<T>(std::move(rhs.x));
   * @param rhs Right hand side argument of operator.
    y = static_cast<T>(std::move(rhs.y));
   * @return Left hand side argument - the ostream object passed to operator.
    return *this;
   */
  }

  inline friend std::ostream &operator<<(std::ostream &lhs, vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    lhs << "[" << rhs.x << "," << rhs.y << "]";
   * Array access operator
    return lhs;
   * @param n Array index
  }
   * @return For n = 0, reference to x coordinate, else reference to y

   * y coordinate.
  /**
   */
   * Gets string representation.
  inline T constexpr &operator[](int n) noexcept __attribute__((__always_inline__)) {
   */
    return n == 0 ? x : y;
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) {
  }
    std::ostringstream oss;

    oss << *this;
  /**
    return oss.str();
   * Constant array access operator
  }
   * @param n Array index

   * @return For n = 0, reference to x coordinate, else reference to y
  /**
   * y coordinate.
   * Check whether two lines intersect, and if so obtain the intersection point
   */
   * and store it in this vector.
  inline T constexpr const &operator[](int n) const noexcept __attribute__((__always_inline__)) {
   * @param line1start The start coordinates of the first line
    return n == 0 ? x : y;
   * @param line1end The end coordinates of the first line
  }
   * @param line2start The start coordinates of the first line

   * @param line2end The end coordinates of the first line
  //---------------[ vector aritmetic operator ]--------------
   */
  /**
   * Addition operator
  template<typename FromT> __attribute__((__always_inline__))
   * @param rhs Right hand side argument of binary operator.
  inline bool constexpr get_line_intersection(vector2<FromT> const &line1start,
   */
                                              vector2<FromT> const &line1end,
  inline vector2<T> constexpr operator+(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                                              vector2<FromT> const &line2start,
    return vector2<T>(x + rhs.x, y + rhs.y);
                                              vector2<FromT> const &line2end) noexcept {
  }
    vector2<T> const temp_s1(line1end.x - line1start.x,

                             line1end.y - line1start.y);
  /**
    vector2<T> const temp_s2(line2end.x - line2start.x,
   * Subtraction operator
                             line2end.y - line2start.y);
   * @param rhs Right hand side argument of binary operator.
    T const temp_s = (-temp_s1.y * (line1start.x - line2start.x) + temp_s1.x * (line1start.y - line2start.y)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
   */
    T const temp_t = ( temp_s2.x * (line1start.y - line2start.y) - temp_s2.y * (line1start.x - line2start.x)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
  inline vector2<T> constexpr operator-(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    if(temp_s >= 0 && temp_s <= 1 && temp_t >= 0 && temp_t <= 1) {
    return vector2<T>(x - rhs.x, y - rhs.y);
  }
      x = line1start.x + (temp_t * temp_s1.x);

      y = line1start.y + (temp_t * temp_s1.y);
  /**
      return true;
   * Multiplication operator
    }
   * @param rhs Right hand side argument of binary operator.
    return false;
   */
  }
  inline vector2<T> constexpr operator*(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return vector2<T>(x * rhs.x, y * rhs.y);
  /**
  }
   * Free function to check whether two lines intersect.

   * @param line1start The start coordinates of the first line
  /**
   * @param line1end The end coordinates of the first line
   * Division operator
   * @param line2start The start coordinates of the first line
   * @param rhs Right hand side argument of binary operator.
   * @param line2end The end coordinates of the first line
   */
   */
  inline vector2<T> constexpr operator/(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return vector2<T>(x / rhs.x, y / rhs.y);
  inline static bool constexpr do_lines_intersect(vector2<FromT> const &line1start,
  }

                                                  vector2<FromT> const &line1end,
  /**
                                                  vector2<FromT> const &line2start,
   * Addition operator
                                                  vector2<FromT> const &line2end) noexcept {
   * @param rhs Right hand side argument of binary operator.
    vector2<T> constexpr temp_s1(line1end.x - line1start.x,
   */
                            line1end.y - line1start.y);
  inline vector2<T> constexpr &operator+=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    vector2<T> constexpr temp_s2(line2end.x - line2start.x,
    x += rhs.x;
                            line2end.y - line2start.y);
    y += rhs.y;
    T constexpr temp_s = (-temp_s1.y * (line1start.x - line2start.x) + temp_s1.x * (line1start.y - line2start.y)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);
    return *this;
  }
    T constexpr temp_t = ( temp_s2.x * (line1start.y - line2start.y) - temp_s2.y * (line1start.x - line2start.x)) / (-temp_s2.x * temp_s1.y + temp_s1.x * temp_s2.y);

    if(temp_s >= 0 && temp_s <= 1 && temp_t >= 0 && temp_t <= 1) {
  /**
      return true;
   * Substraction operator
    }
   * @param rhs Right hand side argument of binary operator.
    return false;
   */
  }
  inline vector2<T> constexpr &operator-=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    x -= rhs.x;
  /**
    y -= rhs.y;
   * Gets a 3D vector equivalent populating the X and Y axes
    return *this;
   */
  }
  inline vector3<T> constexpr to_3d_xy() const noexcept __attribute__((__always_inline__)) {

  /**
    return vector3<T>(x, y, 0);
   * Multiplication operator
  }
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr to_3D_XY() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
   */
    return to_3d_xy();
  inline vector2<T> constexpr &operator*=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    x *= rhs.x;

    y *= rhs.y;
  /**
    return *this;
   * Gets a 3D vector equivalent populating the X and Z axes
  }
   */

  inline vector3<T> constexpr to_3d_xz() const noexcept __attribute__((__always_inline__)) {
  /**
    return vector3<T>(x, 0, z);
   * Division operator
  }
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr to_3D_XZ() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
  inline vector2<T> constexpr &operator/=(vector2<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return to_3d_xz();
    x /= rhs.x;
  }
    y /= rhs.y;
};
    return *this;

  }
#ifdef VMATH_NAMESPACE

}
  /**
#endif //VMATH_NAMESPACE
   * Dot product of two vectors.

   * @param rhs Right hand side argument of binary operator.
#include "vector2_types.h"
   */

  inline T constexpr dot(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return (x * rhs.x) +
//
           (y * rhs.y);
  }
// Standard C++ library extensions
//
  inline T constexpr dotProduct(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use dot()"))) {
    return dot(rhs);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }


namespace std {
  /**

   * Cross product of two vectors
/**
   * @param rhs Right hand side argument of binary operator.
 * Gets vector containing minimal values of @a a and @a b coordinates.
   */
 * @return Vector of minimal coordinates.
  inline T constexpr cross(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
 */
    return (x * rhs.y) -
template<typename T>
           (y * rhs.x);
inline constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
  }
template<typename T>
  inline T constexpr crossProduct(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use cross()"))) {
inline constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) noexcept {
    return cross(rhs);
  return vector2<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y));
  }
}


  //--------------[ scalar vector operator ]--------------------
/**
  /**
 * Gets vector containing maximal values of @a a and @a b coordinates.
   * Addition operator
 * @return Vector of maximal coordinates.
   * @param rhs Right hand side argument of binary operator.
 */
   */
template<typename T>
  inline vector2<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return vector2<T>(x + rhs, y + rhs);
inline constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
  }
template<typename T>

inline constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) noexcept {
  /**
  return vector2<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y));
   * Subtraction operator
}
   * @param rhs Right hand side argument of binary operator.

   */
#ifndef VMATH_NO_BOOST
  inline vector2<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
/**
    return vector2<T>(x - rhs, y - rhs);
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
struct hash<vector2<T>> {
  inline vector2<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  size_t operator()(const vector2<T> &value) const {
    return vector2<T>(x * rhs, y * rhs);
  }
    size_t hashvalue = 0;

    boost::hash_combine(hashvalue, value.x);
  /**
    boost::hash_combine(hashvalue, value.y);
   * Division operator
    return hashvalue;
   * @param rhs Right hand side argument of binary operator.
  }
   */
};
  inline vector2<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
#endif // VMATH_NO_BOOST
    return vector2<T>(x / rhs, y / rhs);

  }
}


  /**
#ifndef VMATH_NO_BOOST
   * Addition operator
/**
   * @param rhs Right hand side argument of binary operator.
 * Gets a hash value taking account of all dimensions of this vector, for use
   */
 * in standard container maps etc.
  inline vector2<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
    x += rhs;
 * @return Hash value
    y += rhs;
 */
    return *this;
template<typename T>
  }
size_t hash_value(vector2<T> const &value) {

  /**
  size_t hashvalue = 0;
   * Subtraction operator
  boost::hash_combine(hashvalue, value.x);
   * @param rhs Right hand side argument of binary operator.
  boost::hash_combine(hashvalue, value.y);
   */
  return hashvalue;
  inline vector2<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
}
    x -= rhs;
#endif // VMATH_NO_BOOST
    y -= rhs;

    return *this;
#endif // VECTORSTORM_VECTOR2_H_INCLUDED
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

  //--------------[ equality operator ]------------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition | lhs.x - rhs.y | < epsilon,
   * same for y-coordinate.
   */
  inline bool constexpr operator==(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return (std::abs(x - rhs.x) < epsilon<T>) &&
             (std::abs(y - rhs.y) < epsilon<T>);
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
  inline bool constexpr operator!=(vector2<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
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
  inline void constexpr normalize() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise();
  }
  inline void constexpr normalize_fast() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    normalise_fast();
  }
  inline void constexpr normalize_faster() noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
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
  inline vector2<T> constexpr normalize_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy();
  }
  inline vector2<T> constexpr normalize_copy_fast() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
    return normalise_copy_fast();
  }
  inline vector2<T> constexpr normalize_copy_faster() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
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
  inline vector2<T> constexpr normalise_safe_copy() const noexcept __attribute__((__always_inline__)) {
    if(length_zero()) {
      return vector2<T>();
    } else {
      return *this / length();
    }
  }
  inline vector2<T> constexpr normalize_safe_copy() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Proper English, please!"))) {
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
    lhs << "[" << rhs.x << "," << rhs.y << "]";
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
  inline vector3<T> constexpr to_3D_XY() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
    return to_3d_xy();
  }

  /**
   * Gets a 3D vector equivalent populating the X and Z axes
   */
  inline vector3<T> constexpr to_3d_xz() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(x, 0, z);
  }
  inline vector3<T> constexpr to_3D_XZ() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use lowercase version."))) {
    return to_3d_xz();
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "vector2_types.h"

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
inline constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) noexcept {
  return vector2<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
inline constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) noexcept {
  return vector2<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y));
}

#ifndef VMATH_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this vector, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
struct hash<vector2<T>> {
  size_t operator()(const vector2<T> &value) const {
    size_t hashvalue = 0;
    boost::hash_combine(hashvalue, value.x);
    boost::hash_combine(hashvalue, value.y);
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
size_t hash_value(vector2<T> const &value) {
  size_t hashvalue = 0;
  boost::hash_combine(hashvalue, value.x);
  boost::hash_combine(hashvalue, value.y);
  return hashvalue;
}
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_VECTOR2_H_INCLUDED
