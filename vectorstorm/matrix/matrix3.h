#pragma once

#include "vectorstorm/epsilon.h"
#include "matrix3_forward.h"
#include "matrix4_forward.h"
#include "vectorstorm/quat/quat_forward.h"
#include "vectorstorm/vector/vector3_forward.h"
#include "vectorstorm/vector/vector4_forward.h"
#ifdef VECTORSTORM_NO_BOOST
  #include <array>
  #include <cstring>
#else
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
  inline constexpr matrix3() noexcept __attribute__((__always_inline__))
    : data{1, 0, 0,
           0, 1, 0,
           0, 0, 1} {
  }

  /**
   * Copy matrix values from array (these data must be in column
   * major order!)
   */
  inline constexpr explicit matrix3(T const *dt) noexcept __attribute__((__always_inline__))
    : data{dt[0], dt[1], dt[2],
           dt[3], dt[4], dt[5],
           dt[6], dt[7], dt[8]} {
  }
  inline constexpr explicit matrix3(T *dt) noexcept __attribute__((__always_inline__))
    : data{dt[0], dt[1], dt[2],
           dt[3], dt[4], dt[5],
           dt[6], dt[7], dt[8]} {
  }

  /**
   * Copy constructor.
   * @param src Data source for new created instance of matrix3
   */
  inline constexpr explicit matrix3(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2],
           src.data[3], src.data[4], src.data[5],
           src.data[6], src.data[7], src.data[8]} {
  }

  /**
   * Copy constructor from matrix3wgpu.
   * @param src Data source matrix3wgpu for new created instance of matrix3
   */
  inline constexpr explicit matrix3(matrix3wgpu<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2], /* drop padding 3 */
           src.data[4], src.data[5], src.data[6], /* drop padding 7 */
           src.data[8], src.data[9], src.data[10] /* drop padding 11 */} {
  }

  /**
   * Copy casting constructor.
   * @param src Data source for new created instance of matrix3
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix3(matrix3<FromT> const &src) noexcept
    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]),
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]),
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8])} {
  }

  /**
   * Move constructor.
   * @param src Data source for new created instance of matrix3
   */
  inline constexpr matrix3(matrix3<T> &&src) noexcept __attribute__((__always_inline__))
    : data(std::move(src.data)) {
  }

  /**
   * Move casting constructor.
   * @param src Data source for new created instance of matrix3
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr matrix3(matrix3<FromT> &&src) noexcept
    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])),
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])),
           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8]))} {
  }

  /**
   * Variadic initialisation constructor
   * @param dt Initialiser list containing raw data for each element in order.
   */
  //inline constexpr matrix3(std::initializer_list<T> dt)
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
  //}
  // see http://stackoverflow.com/a/5549918/1678468
  template<typename... FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix3(FromT... dt) noexcept
    : data{dt...} {
  }

  /**
   * Resets matrix to be identity matrix
   */
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
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
  inline static matrix3<T> constexpr create_rotation_from_euler_angles(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
    return create_rotation_from_euler_angles_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
  }

  /**
   * Creates rotation matrix by rotation around three axes, radian version.
   * @param xRads Angle (in radians) of rotation around axis X.
   * @param yRads Angle (in radians) of rotation around axis Y.
   * @param zRads Angle (in radians) of rotation around axis Z.
   */
  inline static matrix3<T> constexpr create_rotation_from_euler_angles_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    // the static cast is to avoid narrowing conversion warnings when used with ints
    T sin_xRads = static_cast<T>(0);
    T cos_xRads = static_cast<T>(0);
    T sin_yRads = static_cast<T>(0);
    T cos_yRads = static_cast<T>(0);
    T sin_zRads = static_cast<T>(0);
    T cos_zRads = static_cast<T>(0);
    sincos_any(-xRads, sin_xRads, cos_xRads);
    sincos_any(-yRads, sin_yRads, cos_yRads);
    sincos_any(-zRads, sin_zRads, cos_zRads);
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
  inline static matrix3<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    return create_rotation_around_axis_rad(axis, deg2rad(angle));
  }

  /**
   * Creates rotation matrix by rotation around an axis, radian version.
   * @param axis Axis to rotate around.
   * @param angle Angle (in radians) of rotation around axis.
   */
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    // the static cast is to avoid narrowing conversion warnings when used with ints
    T sin_a = static_cast<T>(0);
    T cos_a = static_cast<T>(0);
    sincos_any(-angle, sin_a, cos_a);
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
  inline static matrix3<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
    // the static cast is to avoid narrowing conversion warnings when used with ints
    vector3<T> const cross(to.cross(from));
    T const dot = from.dot(to);
    T temp1 = static_cast<T>(1) + dot;
    if(temp1 == static_cast<T>(0)) {                                            // a safety check is required to avoid a divide by zero
      temp1 = epsilon<T>;
    }
    T const temp_k = static_cast<T>(1) / temp1;
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
   * Creates a rotation matrix to align with a target vector direction @a target
   * @param target Vector that the rotation should point at
   * @param up_dir Direction of up vector
   * @return Resulting matrix that's oriented to the target vector
   */
  inline static matrix3<T> constexpr create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
    vector3<T> const forward{target.normalise_copy()};
    vector3<T> const side{forward.cross(up_dir).normalise_safe_copy()};         // Side = forward x up
    vector3<T> const up{side.cross(forward)};                                   // Recompute up as: up = side x forward

    return matrix3<T>(static_cast<T>(side.x),
                      static_cast<T>(up.x),
                      static_cast<T>(forward.x),

                      static_cast<T>(side.y),
                      static_cast<T>(up.y),
                      static_cast<T>(forward.y),

                      static_cast<T>(side.z),
                      static_cast<T>(up.z),
                      static_cast<T>(forward.z));
  }

  /**
   * Creates rotation matrix from ODE matrix.
   */
  template<typename It> __attribute__((__always_inline__))
  inline static matrix3<T> constexpr from_ode(It const *mat) noexcept {
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
  inline static matrix3<T> constexpr from_row_major_array(FromT const *arr) noexcept {
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
  inline static matrix3<T> constexpr from_column_major_array(FromT const *arr) noexcept {
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[1]), static_cast<T>(arr[2]),
                      static_cast<T>(arr[3]), static_cast<T>(arr[4]), static_cast<T>(arr[5]),
                      static_cast<T>(arr[6]), static_cast<T>(arr[7]), static_cast<T>(arr[8]));
  }

  //---------------------[ equality operators ]------------------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition all elements of matrix
   * | lhs[i] - rhs[i] | < epsilon,
   * same for y-coordinate, z-coordinate, and w-coordinate.
   */
  inline bool constexpr operator==(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VECTORSTORM_SOFT_COMPARE
      return std::abs(data[0] - rhs.data[0]) < epsilon<T> &&
             std::abs(data[1] - rhs.data[1]) < epsilon<T> &&
             std::abs(data[2] - rhs.data[2]) < epsilon<T> &&
             std::abs(data[3] - rhs.data[3]) < epsilon<T> &&
             std::abs(data[4] - rhs.data[4]) < epsilon<T> &&
             std::abs(data[5] - rhs.data[5]) < epsilon<T> &&
             std::abs(data[6] - rhs.data[6]) < epsilon<T> &&
             std::abs(data[7] - rhs.data[7]) < epsilon<T> &&
             std::abs(data[8] - rhs.data[8]) < epsilon<T>;
    #else
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wfloat-equal"
      return data[0] == rhs.data[0] &&
             data[1] == rhs.data[1] &&
             data[2] == rhs.data[2] &&
             data[3] == rhs.data[3] &&
             data[4] == rhs.data[4] &&
             data[5] == rhs.data[5] &&
             data[6] == rhs.data[6] &&
             data[7] == rhs.data[7] &&
             data[8] == rhs.data[8];
      #pragma GCC diagnostic pop
    #endif // VECTORSTORM_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //---------------------[ access operators ]---------------------------------
  /**
   * Get reference to element at position (x,y).
   * @param x Number of column (0..2)
   * @param y Number of row (0..2)
   */
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
    return data[x * 3 + y];
  }

  /**
   * Get constant reference to element at position (x,y).
   * @param x Number of column (0..2)
   * @param y Number of row (0..2)
   */
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
    return data[x * 3 + y];
  }

  /**
   * Get reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..3)
   * @param j Number of column (1..3)
   */
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 3 + i - 1];
  }

  /**
   * Get constant reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..3)
   * @param j Number of column (1..3)
   */
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 3 + i - 1];
  }

  /**
   * Returns transform (4x4) matrix including this as the rotation component.
   */
  inline matrix4<T> constexpr get_transform() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[0],           data[1],           data[2],           static_cast<T>(0),
                      data[3],           data[4],           data[5],           static_cast<T>(0),
                      data[6],           data[7],           data[8],           static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 9);
    return *this;
  }

  /**
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline matrix3<T> constexpr &operator=(matrix3<FromT> const &rhs) noexcept {
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
  inline matrix3<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
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
  inline matrix3<T> constexpr &operator=(matrix3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    data = std::move(rhs.data);
    return *this;
  }

  /**
   * Move assignment casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline matrix3<T> constexpr &operator=(matrix3<FromT> &&rhs) noexcept {
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
  inline matrix3<T> constexpr operator+(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],
                      data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
                      data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator-(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
                      data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
                      data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
  }

  //--------------------[ matrix with scalar operations ]---------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] + rhs, data[1] + rhs, data[2] + rhs,
                      data[3] + rhs, data[4] + rhs, data[5] + rhs,
                      data[6] + rhs, data[7] + rhs, data[8] + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] - rhs, data[1] - rhs, data[2] - rhs,
                      data[3] - rhs, data[4] - rhs, data[5] - rhs,
                      data[6] - rhs, data[7] - rhs, data[8] - rhs);

  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] * rhs, data[1] * rhs, data[2] * rhs,
                      data[3] * rhs, data[4] * rhs, data[5] * rhs,
                      data[6] * rhs, data[7] * rhs, data[8] * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] / rhs, data[1] / rhs, data[2] / rhs,
                      data[3] / rhs, data[4] / rhs, data[5] / rhs,
                      data[6] / rhs, data[7] / rhs, data[8] / rhs);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this + rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this - rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this * rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this / rhs;
    return *this;
  }

  //--------------------[ multiply operators ]--------------------------------
  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * Enabling vector4 rotation as if it's a vector3, maintaining W
   */
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z,
                      rhs.w);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3<T> constexpr operator*(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
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
  inline matrix3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this * rhs;
    return *this;
  }

  //---------------------------[ misc operations ]----------------------------
  /**
   * Transpose matrix.
   */
  inline matrix3<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
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
  inline matrix3<T> constexpr lerp(T fact, matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (rhs - (*this)) * fact;
  }

  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
    return   data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
           - data[0] * data[5] * data[7] - data[1] * data[3] * data[8] - data[2] * data[4] * data[6];
  }

  /**
   * Computes inverse matrix
   * @return Inverse matrix of this matrix.
   */
  inline matrix3<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
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
   * Orthonormalises the matrix.
   * 1. normalises the normal.
   * 2. normalises the tangent and makes sure it is orthogonal to normal.
   * 3. normalises binormal and makes sure it is orthogonal to both normal and tangent.
   */
  inline void constexpr orthonormalise() noexcept __attribute__((__always_inline__)) {
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

  /**
   * Returns a quaternion such that its corresponding matrix can be used to diagonalise the input matrix.
   * Must be called on a symmetrical matrix.
   * @return Diagonalising quaternion.
   */
  inline quaternion<T> constexpr diagonaliser() {
    // Based loosely on Jacobi Transformations of a Symmetric Matrix, via S Melax.
    // Adapted from http://melax.github.io/diag.html
    // Diagonal matrix D = Q * A * Transpose(Q);  and  A = QT*D*Q
    // The rows of q are the eigenvectors D's diagonal is the eigenvalues
    // As per 'row' convention if float3x3 Q = q.getmatrix(); then v*Q = q*v*conj(q)
    unsigned int constexpr maxsteps = 24;                                       // certainly wont need that many.
    quaternion<T> q(1, 0, 0, 0);
    for(unsigned int i = 0; i != maxsteps; ++i) {
      matrix3<T> const Q{q.rotmatrix()};                                        // v*Q == q*v*conj(q)
      matrix3<T> const D{Q * *this * Q.transpose()};                            // A = Q^T*D*Q
      vector3<T> offdiag(D.at(1, 2), D.at(0, 2), D.at(0, 1));                   // elements not on the diagonal
      vector3<T> om(std::fabs(offdiag.x), std::fabs(offdiag.y), std::fabs(offdiag.z)); // mag of each offdiag elem
      unsigned int const k = (om.x > om.y && om.x > om.z) ? 0 : (om.y > om.z) ? 1 : 2; // index of largest element of offdiag
      unsigned int const k1 = (k + 1) % 3;
      unsigned int const k2 = (k + 2) % 3;
      if(offdiag[k] == 0.0f) {
        break;                                                                  // diagonal already
      }
      T thet = (D.at(k2, k2) - D.at(k1, k1)) / (2 * offdiag[k]);
      T const sgn = std::signbit(thet) ? -1 : 1;
      thet *= sgn;                                                              // make it positive
      T const t = sgn / (thet + ((thet < 1.E6) ? std::sqrt((thet * thet) + 1) : thet)); // sign(T)/(|T|+sqrt(T^2+1))
      T const c = 1 / std::sqrt((t * t) + 1);                                   //  c= 1/(t^2+1) , t=s/c
      if(c == 1.0f) {
        break;
      }                                                                         // no room for improvement - reached machine precision.
      quaternion<T> jr(0, 0, 0, 0);                                             // jacobi rotation for this iteration.
      jr.vector[k] = sgn * std::sqrt((1.0f - c) / 2.0f);                        // using 1/2 angle identity sin(a/2) = sqrt((1-cos(a))/2)
      jr.vector[k] *= -1.0f;                                                    // since our quat-to-matrix convention was for v*M instead of M*v
      jr.w  = std::sqrt(1.0f - (jr.vector[k] * jr.vector[k]));
      if(jr.w == 1.0f) {
        break;                                                                  // reached limits of floating point precision
      }
      q =  q * jr;
      q.normalise();
    }
    return q;
  }

  //-------------[ conversion ]-----------------------------

  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class matrix3<T>)
   * used for passing matrix3<T> values to gl*[fd]v functions.
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(data.data());
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class matrix3<T>)
   * used for passing matrix3<T> values to gl*[fd]v functions.
   */
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T const*>(data.data());
  }

  //----------[ output operator ]----------------------------
  /**
   * Output to stream operator
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    for(int i = 0; i != 3; ++i) {
      lhs << "|\t";
      for(int j = 0; j != 3; ++j) {
        lhs << +rhs.at(j, i) << "\t";
      }
      lhs << "|" << std::endl;
    }
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
};

/**
 * Class for WebGPU matrix 3x3, which is padded to 4x3.
 * @note This is a special case for WebGPU which expects 3x3 matrices to be padded to 16 bytes.
 * This is only an inter-operation type, so it can only transform implicitly from matrix3, and can
 * produce a matrix3 only by explicit request.
 */
template<typename T>
class matrix3wgpu {
public:
  /// Data stored in column major order, including padding
  std::array<T, 12> data;

  //--------------------------[ constructors ]-------------------------------
  /**
   * Creates identity matrix with padding
   */
  inline constexpr matrix3wgpu() noexcept __attribute__((__always_inline__))
    : data{1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, 1, 0} {
  }

  /**
   * Copy constructor
   * @param src Data source for new created instance of matrix3wgpu - note padding is always zeroed
   */
  inline constexpr explicit matrix3wgpu(matrix3wgpu<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2],  T{0},
           src.data[4], src.data[6], src.data[7],  T{0},
           src.data[8], src.data[9], src.data[10], T{0}} {
  }

  /**
   * Move constructor
   * @param src Data source for new created instance of matrix3wgpu
   */
  inline constexpr matrix3wgpu(matrix3wgpu<T> &&src) noexcept __attribute__((__always_inline__))
    : data(std::move(src.data)) {
  }

  /**
   * Copy constructor from matrix3
   * @param src Data source matrix3 for new created instance of matrix3wgpu
   */
  inline constexpr explicit matrix3wgpu(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2], T{0},
           src.data[3], src.data[4], src.data[5], T{0},
           src.data[6], src.data[7], src.data[8], T{0}} {
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix3wgpu<T> constexpr &operator=(matrix3wgpu<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 12);
    return *this;
  }
};

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "matrix3_types.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Standard C++ library extensions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace std {

/**
 * Gets matrix containing minimal values of @a a and @a b coordinates.
 * @return Matrix of minimal coordinates.
 */
template<typename T>
inline constexpr matrix3<T> min(matrix3<T> const &a, const matrix3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr matrix3<T> min(matrix3<T> const &a, const matrix3<T> &b) noexcept {
  return {::std::min(a.data[0], b.data[0]),
          ::std::min(a.data[1], b.data[1]),
          ::std::min(a.data[2], b.data[2]),

          ::std::min(a.data[3], b.data[3]),
          ::std::min(a.data[4], b.data[4]),
          ::std::min(a.data[5], b.data[5]),

          ::std::min(a.data[6], b.data[6]),
          ::std::min(a.data[7], b.data[7]),
          ::std::min(a.data[8], b.data[8])};
}

/**
 * Gets matrix containing maximal values of @a a and @a b coordinates.
 * @return Matrix of maximal coordinates.
 */
template<typename T>
inline constexpr matrix3<T> max(matrix3<T> const &a, const matrix3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr matrix3<T> max(matrix3<T> const &a, const matrix3<T> &b) noexcept {
  return {::std::max(a.data[0], b.data[0]),
          ::std::max(a.data[1], b.data[1]),
          ::std::max(a.data[2], b.data[2]),

          ::std::max(a.data[3], b.data[3]),
          ::std::max(a.data[4], b.data[4]),
          ::std::max(a.data[5], b.data[5]),

          ::std::max(a.data[6], b.data[6]),
          ::std::max(a.data[7], b.data[7]),
          ::std::max(a.data[8], b.data[8])};
}

#ifndef VECTORSTORM_NO_BOOST
template<typename T>
struct hash<matrix3<T>> {
  /**
   * Gets a hash value taking account of all dimensions of this matrix, for use
   * in standard container maps etc.
   * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
   * @return Hash value
   */
  size_t operator()(const matrix3<T> &value) const {
    size_t hashvalue = 0;
    boost::hash_combine(hashvalue, value.data[0]);
    boost::hash_combine(hashvalue, value.data[1]);
    boost::hash_combine(hashvalue, value.data[2]);

    boost::hash_combine(hashvalue, value.data[3]);
    boost::hash_combine(hashvalue, value.data[4]);
    boost::hash_combine(hashvalue, value.data[5]);

    boost::hash_combine(hashvalue, value.data[6]);
    boost::hash_combine(hashvalue, value.data[7]);
    boost::hash_combine(hashvalue, value.data[8]);
    return hashvalue;
  }
};
#endif // VECTORSTORM_NO_BOOST

}

#ifndef VECTORSTORM_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this matrix, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
size_t hash_value(matrix3<T> const &value) {
  size_t hashvalue = 0;
  boost::hash_combine(hashvalue, value.data[0]);
  boost::hash_combine(hashvalue, value.data[1]);
  boost::hash_combine(hashvalue, value.data[2]);

  boost::hash_combine(hashvalue, value.data[3]);
  boost::hash_combine(hashvalue, value.data[4]);
  boost::hash_combine(hashvalue, value.data[5]);

  boost::hash_combine(hashvalue, value.data[6]);
  boost::hash_combine(hashvalue, value.data[7]);
  boost::hash_combine(hashvalue, value.data[8]);
  return hashvalue;
}
#endif // VECTORSTORM_NO_BOOST
