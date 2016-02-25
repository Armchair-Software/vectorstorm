#ifndef VECTORSTORM_MATRIX3_H_INCLUDED
#define VECTORSTORM_MATRIX3_H_INCLUDED

#include "vectorstorm/epsilon.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

/**
 * Class for matrix 3x3.
 * @note Data stored in this matrix are in column major order. This arrangement suits OpenGL.
 * If you're using row major matrix, consider using fromRowMajorArray as way for construction
 * matrix3<T> instance.
 */
template<typename T>
class matrix3 {
public:
  /// Data stored in column major order
  std::array<T, 9> data;

  //--------------------------[ constructors ]-------------------------------
  /**
   * Creates identity matrix
   */
  inline constexpr matrix3() __attribute__((__always_inline__))
    : data{1, 0, 0,
           0, 1, 0,
           0, 0, 1} {
  }

  /**
   * Copy matrix values from array (these data must be in column
   * major order!)
   */
  inline constexpr matrix3(T const *dt) __attribute__((__always_inline__))
    : data{dt[0], dt[1], dt[2],
           dt[3], dt[4], dt[5],
           dt[6], dt[7], dt[8]} {
  }
  inline constexpr matrix3(T *dt) __attribute__((__always_inline__))
    : data{dt[0], dt[1], dt[2],
           dt[3], dt[4], dt[5],
           dt[6], dt[7], dt[8]} {
  }

  /**
   * Copy constructor.
   * @param src Data source for new created instance of matrix3
   */
  inline constexpr matrix3(matrix3<T> const &src) __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2],
           src.data[3], src.data[4], src.data[5],
           src.data[6], src.data[7], src.data[8]} {
  }

  /**
   * Copy casting constructor.
   * @param src Data source for new created instance of matrix3
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr matrix3(matrix3<FromT> const &src)
    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]),
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]),
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8])} {
  }

  /**
   * Move constructor.
   * @param src Data source for new created instance of matrix3
   */
  inline constexpr matrix3(matrix3<T> &&src) __attribute__((__always_inline__))
    : data(std::move(src.data)) {
  }

  /**
   * Move casting constructor.
   * @param src Data source for new created instance of matrix3
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr matrix3(matrix3<FromT> &&src)
    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])),
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])),
           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8]))} {
  }

  /**
   * Variadic initialisation constructor
   * @param dt Initialiser list containing raw data for each element in order.
   */
  //inline constexpr matrix3(std::initializer_list<T> dt)
  //  : data(dt) __attribute__((__always_inline__)) {
  //}
  // see http://stackoverflow.com/a/5549918/1678468
  template<class... FromT> __attribute__((__always_inline__))
  inline constexpr matrix3(FromT... dt)
    : data{dt...} {
  }

  /**
   * Resets matrix to be identity matrix
   */
  inline void constexpr identity() __attribute__((__always_inline__)) {
    data = {1, 0, 0,
            0, 1, 0,
            0, 0, 1};
  }

  /**
   * Creates rotation matrix by rotation around three axes.
   * @param xDeg Angle (in degrees) of rotation around axis X.
   * @param yDeg Angle (in degrees) of rotation around axis Y.
   * @param zDeg Angle (in degrees) of rotation around axis Z.
   */
  inline static matrix3<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) __attribute__((__always_inline__)) {
    return createRotationAroundAxis_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
  }

  /**
   * Creates rotation matrix by rotation around three axes, radian version.
   * @param xRads Angle (in radians) of rotation around axis X.
   * @param yRads Angle (in radians) of rotation around axis Y.
   * @param zRads Angle (in radians) of rotation around axis Z.
   */
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) __attribute__((__always_inline__)) {
    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    // the static cast is to avoid narrowing conversion warnings when used with ints
    T sin_xRads = static_cast<T>(0);
    T cos_xRads = static_cast<T>(0);
    T sin_yRads = static_cast<T>(0);
    T cos_yRads = static_cast<T>(0);
    T sin_zRads = static_cast<T>(0);
    T cos_zRads = static_cast<T>(0);
    sincos_any(xRads, sin_xRads, cos_xRads);
    sincos_any(yRads, sin_yRads, cos_yRads);
    sincos_any(zRads, sin_zRads, cos_zRads);
    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
    return matrix3<T>(temp_cos_z_cos_y,
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,

                      sin_zRads * cos_yRads,
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,

                     -temp_cos_z_sin_y,
                      temp_cos_z_cos_y * sin_xRads,
                      temp_cos_z_cos_y * cos_xRads);
  }

  /**
   * Creates rotation matrix by rotation around an axis.
   * @param axis Axis to rotate around.
   * @param angle Angle (in degrees) of rotation around axis.
   */
  inline static matrix3<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) __attribute__((__always_inline__)) {
    return createRotationAroundAxis_rad(axis, angle);
  }

  /**
   * Creates rotation matrix by rotation around an axis, radian version.
   * @param axis Axis to rotate around.
   * @param angle Angle (in radians) of rotation around axis.
   */
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) __attribute__((__always_inline__)) {
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    // the static cast is to avoid narrowing conversion warnings when used with ints
    T sin_a = static_cast<T>(0);
    T cos_a = static_cast<T>(0);
    sincos_any(angle, sin_a, cos_a);
    T const cos_a_inv = static_cast<T>(1) - cos_a;
    return matrix3<T>(axis.x * axis.x * cos_a_inv + cos_a,
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,

                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
                      axis.y * axis.y * cos_a_inv + cos_a,
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,

                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,
                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
                      axis.z * axis.z * cos_a_inv + cos_a);
  }

  /**
   * Creates rotation matrix by aligning one vector to another.
   * Adapted from http://www.iquilezles.org/www/articles/noacos/noacos.htm
   * @param from Vector to rotate from.
   * @param to Vector to rotate to.
   * @return An instance of matrix3<T> representing rotation between the two vectors.
   */
  inline static matrix3<T> constexpr createRotationBetweenVectors(vector3<T> from, vector3<T> to) __attribute__((__always_inline__)) {
    // the static cast is to avoid narrowing conversion warnings when used with ints
    vector3<T> const cross(to.crossProduct(from));
    T const dot = from.dotProduct(to);
    T const temp_k = static_cast<T>(1) / (static_cast<T>(1) + dot);
    return matrix3<T>(cross.x * cross.x * temp_k + dot,
                      cross.y * cross.x * temp_k - cross.z,
                      cross.z * cross.x * temp_k + cross.y,

                      cross.x * cross.y * temp_k + cross.z,
                      cross.y * cross.y * temp_k + dot,
                      cross.z * cross.y * temp_k - cross.x,

                      cross.x * cross.z * temp_k - cross.y,
                      cross.y * cross.z * temp_k + cross.x,
                      cross.z * cross.z * temp_k + dot);

  }

  /**
   * Creates rotation matrix from ODE matrix.
   */
  template<typename It> __attribute__((__always_inline__))
  inline static matrix3<T> constexpr fromOde(It const *mat) {
    return matrix3<T>(static_cast<T>(mat[0]), static_cast<T>(mat[4]), static_cast<T>(mat[8]),
                      static_cast<T>(mat[1]), static_cast<T>(mat[5]), static_cast<T>(mat[9]),
                      static_cast<T>(mat[2]), static_cast<T>(mat[6]), static_cast<T>(mat[10]));
  }

  /**
   * Creates new matrix 3x3 from array that represents such matrix 3x3
   * as array of tightly packed elements in row major order.
   * @param arr An array of elements for 3x3 matrix in row major order.
   * @return An instance of matrix3<T> representing @a arr
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline static matrix3<T> constexpr fromRowMajorArray(FromT const *arr) {
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[3]), static_cast<T>(arr[6]),
                      static_cast<T>(arr[1]), static_cast<T>(arr[4]), static_cast<T>(arr[7]),
                      static_cast<T>(arr[2]), static_cast<T>(arr[5]), static_cast<T>(arr[8]));
  }

  /**
   * Creates new matrix 3x3 from array that represents such matrix 3x3
   * as array of tightly packed elements in column major order.
   * @param arr An array of elements for 3x3 matrix in column major order.
   * @return An instance of matrix3<T> representing @a arr
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline static matrix3<T> constexpr fromColumnMajorArray(FromT const *arr) {
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[1]), static_cast<T>(arr[2]),
                      static_cast<T>(arr[3]), static_cast<T>(arr[4]), static_cast<T>(arr[5]),
                      static_cast<T>(arr[6]), static_cast<T>(arr[7]), static_cast<T>(arr[8]));
  }

  //---------------------[ equiality operators ]------------------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition all elements of matrix
   * | lhs[i] - rhs[i] | < epsilon,
   * same for y-coordinate, z-coordinate, and w-coordinate.
   */
  inline bool constexpr operator==(matrix3<T> const &rhs) const __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return std::abs(data[0] - rhs.data[0]) < static_cast<T>(epsilon) &&
             std::abs(data[1] - rhs.data[1]) < static_cast<T>(epsilon) &&
             std::abs(data[2] - rhs.data[2]) < static_cast<T>(epsilon) &&
             std::abs(data[3] - rhs.data[3]) < static_cast<T>(epsilon) &&
             std::abs(data[4] - rhs.data[4]) < static_cast<T>(epsilon) &&
             std::abs(data[5] - rhs.data[5]) < static_cast<T>(epsilon) &&
             std::abs(data[6] - rhs.data[6]) < static_cast<T>(epsilon) &&
             std::abs(data[7] - rhs.data[7]) < static_cast<T>(epsilon) &&
             std::abs(data[8] - rhs.data[8]) < static_cast<T>(epsilon);
    #else
      return data[0] == rhs.data[0] &&
             data[1] == rhs.data[1] &&
             data[2] == rhs.data[2] &&
             data[3] == rhs.data[3] &&
             data[4] == rhs.data[4] &&
             data[5] == rhs.data[5] &&
             data[6] == rhs.data[6] &&
             data[7] == rhs.data[7] &&
             data[8] == rhs.data[8];
    #endif // VMATH_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(matrix3<T> const &rhs) const __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //---------------------[ access operators ]---------------------------------
  /**
   * Get reference to element at position (x,y).
   * @param x Number of column (0..2)
   * @param y Number of row (0..2)
   */
  inline T constexpr &at(int x, int y) __attribute__((__always_inline__)) {
    return data[x * 3 + y];
  }

  /**
   * Get constant reference to element at position (x,y).
   * @param x Number of column (0..2)
   * @param y Number of row (0..2)
   */
  inline T constexpr const &at(int x, int y) const __attribute__((__always_inline__)) {
    return data[x * 3 + y];
  }

  /**
   * Get reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..3)
   * @param j Number of column (1..3)
   */
  inline T constexpr &operator()(int i, int j) __attribute__((__always_inline__)) {
    return data[(j - 1) * 3 + i - 1];
  }

  /**
   * Get constant reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..3)
   * @param j Number of column (1..3)
   */
  inline T constexpr const &operator()(int i, int j) const __attribute__((__always_inline__)) {
    return data[(j - 1) * 3 + i - 1];
  }

  /**
   * Returns transform (4x4) matrix including this as the rotationc component.
   */
  inline matrix4<T> constexpr getTranslation() const __attribute__((__always_inline__)) {
    return matrix4<T>(data[0],           data[1],           data[2],           static_cast<T>(0),
                      data[3],           data[4],           data[5],           static_cast<T>(0),
                      data[6],           data[7],           data[8],           static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator=(matrix3<T> const &rhs) __attribute__((__always_inline__)) {
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 9);
    return *this;
  }

  /**
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline matrix3<T> constexpr &operator=(matrix3<FromT> const &rhs) {
    data[0] = static_cast<T>(rhs.data[0]);
    data[1] = static_cast<T>(rhs.data[1]);
    data[2] = static_cast<T>(rhs.data[2]);
    data[3] = static_cast<T>(rhs.data[3]);
    data[4] = static_cast<T>(rhs.data[4]);
    data[5] = static_cast<T>(rhs.data[5]);
    data[6] = static_cast<T>(rhs.data[6]);
    data[7] = static_cast<T>(rhs.data[7]);
    data[8] = static_cast<T>(rhs.data[8]);
    return *this;
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator=(T const *rhs) __attribute__((__always_inline__)) {
    /*
    for(int i = 0; i != 9; ++i) {
      data[i] = (T)rhs[i];
    }
    */
    std::memcpy(data.data(), rhs, sizeof(T) * 9);
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator=(matrix3<T> &&rhs) __attribute__((__always_inline__)) {
    data = std::move(rhs.data);
    return *this;
  }

  /**
   * Move assignment casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline matrix3<T> constexpr &operator=(matrix3<FromT> &&rhs) {
    data[0] = static_cast<T>(std::move(rhs.data[0]));
    data[1] = static_cast<T>(std::move(rhs.data[1]));
    data[2] = static_cast<T>(std::move(rhs.data[2]));
    data[3] = static_cast<T>(std::move(rhs.data[3]));
    data[4] = static_cast<T>(std::move(rhs.data[4]));
    data[5] = static_cast<T>(std::move(rhs.data[5]));
    data[6] = static_cast<T>(std::move(rhs.data[6]));
    data[7] = static_cast<T>(std::move(rhs.data[7]));
    data[8] = static_cast<T>(std::move(rhs.data[8]));
    return *this;
  }

  //--------------------[ matrix with matrix operations ]---------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator+(matrix3<T> const &rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],
                      data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
                      data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator-(matrix3<T> const &rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
                      data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
                      data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
  }

  //--------------------[ matrix with scalar operations ]---------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator+(T rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] + rhs, data[1] + rhs, data[2] + rhs,
                      data[3] + rhs, data[4] + rhs, data[5] + rhs,
                      data[6] + rhs, data[7] + rhs, data[8] + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator-(T rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] - rhs, data[1] - rhs, data[2] - rhs,
                      data[3] - rhs, data[4] - rhs, data[5] - rhs,
                      data[6] - rhs, data[7] - rhs, data[8] - rhs);

  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator*(T rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] * rhs, data[1] * rhs, data[2] * rhs,
                      data[3] * rhs, data[4] * rhs, data[5] * rhs,
                      data[6] * rhs, data[7] * rhs, data[8] * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator/(T rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] / rhs, data[1] / rhs, data[2] / rhs,
                      data[3] / rhs, data[4] / rhs, data[5] / rhs,
                      data[6] / rhs, data[7] / rhs, data[8] / rhs);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator+=(T rhs) __attribute__((__always_inline__)) {
    *this = *this + rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator-=(T rhs) __attribute__((__always_inline__)) {
    *this = *this - rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator*=(T rhs) __attribute__((__always_inline__)) {
    *this = *this * rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator/=(T rhs) __attribute__((__always_inline__)) {
    *this = *this / rhs;
    return *this;
  }

  //--------------------[ multiply operators ]--------------------------------
  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector3<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * Enabling vector4 rotation as if it's a vector3, maintaining W
   */
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const __attribute__((__always_inline__)) {
    return vector4<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z,
                      rhs.w);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator*(matrix3<T> rhs) const __attribute__((__always_inline__)) {
    return matrix3<T>(rhs.data[0] * data[0] + rhs.data[1] * data[3] + rhs.data[2] * data[6],
                      rhs.data[0] * data[1] + rhs.data[1] * data[4] + rhs.data[2] * data[7],
                      rhs.data[0] * data[2] + rhs.data[1] * data[5] + rhs.data[2] * data[8],

                      rhs.data[3] * data[0] + rhs.data[4] * data[3] + rhs.data[5] * data[6],
                      rhs.data[3] * data[1] + rhs.data[4] * data[4] + rhs.data[5] * data[7],
                      rhs.data[3] * data[2] + rhs.data[4] * data[5] + rhs.data[5] * data[8],

                      rhs.data[6] * data[0] + rhs.data[7] * data[3] + rhs.data[8] * data[6],
                      rhs.data[6] * data[1] + rhs.data[7] * data[4] + rhs.data[8] * data[7],
                      rhs.data[6] * data[2] + rhs.data[7] * data[5] + rhs.data[8] * data[8]);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator*=(matrix3<T> rhs) __attribute__((__always_inline__)) {
    *this = *this * rhs;
    return *this;
  }

  //---------------------------[ misc operations ]----------------------------
  /**
   * Transpose matrix.
   */
  inline matrix3<T> constexpr transpose() const __attribute__((__always_inline__)) {
    return matrix3<T>(data[0], data[3], data[6],
                      data[1], data[4], data[7],
                      data[2], data[5], data[8]);
  }

  /**
   * Linear interpolation of two matrices
   * @param fact Factor of interpolation. For translation from positon
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.
   * @param rhs Second matrix for interpolation
   * @note However values of fact parameter are reasonable only in interval
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * can get result (extrapolation?)
   */
  inline matrix3<T> constexpr lerp(T fact, matrix3<T> const &rhs) const __attribute__((__always_inline__)) {
    return (*this) + (rhs - (*this)) * fact;
  }

  inline T constexpr det() const __attribute__((__always_inline__)) {
    return   data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
           - data[0] * data[5] * data[7] - data[1] * data[3] * data[8] - data[2] * data[4] * data[6];
  }

  /**
   * Computes inverse matrix
   * @return Inverse matrix of this matrix.
   */
  inline matrix3<T> constexpr inverse() const __attribute__((__always_inline__)) {
    return matrix3<T>(data[4] * data[8] - data[7] * data[5],
                      data[7] * data[2] - data[1] * data[8],
                      data[1] * data[5] - data[4] * data[2],
                      data[6] * data[5] - data[3] * data[8],
                      data[0] * data[8] - data[6] * data[2],
                      data[3] * data[2] - data[0] * data[5],
                      data[3] * data[7] - data[6] * data[4],
                      data[6] * data[1] - data[0] * data[7],
                      data[0] * data[4] - data[3] * data[1]) / det();
  }

  /**
   * Orthonormalizes the matrix.
   * 1. normalizes the normal.
   * 2. normalizes the tangent and makes sure it is orthogonal to normal.
   * 3. normalizes binormal and makes sure it is orthogonal to both normal and tangent.
   */
  inline void constexpr orthonormalise() __attribute__((__always_inline__)) {
    // normalize x:
    T const x_length = static_cast<T>(std::sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]));
    data[0] /= x_length;
    data[1] /= x_length;
    data[2] /= x_length;
    // z -= z * (x dot z):
    T const x_dot_z = data[0] * data[6] + data[1] * data[7] + data[2] * data[8];
    data[6] -= data[6] * x_dot_z;
    data[7] -= data[7] * x_dot_z;
    data[8] -= data[8] * x_dot_z;
    // normalize z:
    T const z_length = static_cast<T>(std::sqrt(data[6] * data[6] + data[7] * data[7] + data[8] * data[8]));
    data[6] /= z_length;
    data[7] /= z_length;
    data[8] /= z_length;
    // y = z cross x:
    data[3] = data[7] * data[2] - data[1] * data[8];
    data[4] = data[8] * data[0] - data[2] * data[6];
    data[5] = data[6] * data[1] - data[0] * data[7];
  }
  /// Proper English
  inline void constexpr orthonormalize() __attribute__((__always_inline__)) {
    orthonormalise();
  }

  //-------------[ conversion ]-----------------------------

  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class matrix3<T>)
   * used for passing matrix3<T> values to gl*[fd]v functions.
   */
  inline constexpr operator T*() __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(data.data());
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class matrix3<T>)
   * used for passing matrix3<T> values to gl*[fd]v functions.
   */
  inline constexpr operator const T*() const __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(data.data());
  }

  //----------[ output operator ]----------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix3<T> const &rhs) __attribute__((__always_inline__)) {
    for(int i = 0; i != 3; ++i) {
      lhs << "|\t";
      for(int j = 0; j != 3; ++j) {
        lhs << rhs.at(j, i) << "\t";
      }
      lhs << "|" << std::endl;
    }
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
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#include "matrix3_types.h"

#endif // VECTORSTORM_MATRIX3_H_INCLUDED
