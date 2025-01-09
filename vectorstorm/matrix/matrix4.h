#pragma once

#include <cstring>
#include <array>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/vector/vector3_forward.h"
#include "vectorstorm/vector/vector4_forward.h"
#include "matrix3_forward.h"
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
 * Class for matrix 4x4
 * @note Data stored in this matrix are in column major order. This arrangement suits OpenGL.
 * If you're using row major matrix, consider using fromRowMajorArray as way for construction
 * matrix4<T> instance.
 */
template<typename T>
class matrix4 {
public:
  /// Data stored in column major order
  std::array<T, 16> data;

  //--------------------------[ constructors ]-------------------------------
  /**
   *Creates identity matrix
   */
  inline constexpr matrix4() noexcept __attribute__((__always_inline__))
    : data{1, 0, 0, 0,
           0, 1, 0, 0,
           0, 0, 1, 0,
           0, 0, 0, 1} {
  }

  /**
   * Copy matrix values from array (these data must be in column
   * major order!)
   */
  inline constexpr explicit matrix4(T const *dt) noexcept __attribute__((__always_inline__))
    : data{dt[ 0], dt[ 1], dt[ 2], dt[ 3],
           dt[ 4], dt[ 5], dt[ 6], dt[ 7],
           dt[ 8], dt[ 9], dt[10], dt[11],
           dt[12], dt[13], dt[14], dt[15]} {
  }
  inline constexpr explicit matrix4(T *dt) noexcept __attribute__((__always_inline__))
    : data{dt[ 0], dt[ 1], dt[ 2], dt[ 3],
           dt[ 4], dt[ 5], dt[ 6], dt[ 7],
           dt[ 8], dt[ 9], dt[10], dt[11],
           dt[12], dt[13], dt[14], dt[15]} {
  }

  /**
   * Copy constructor.
   * @param src Data source for new created instance of matrix4.
   */
  inline constexpr explicit matrix4(matrix4<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[ 0], src.data[ 1], src.data[ 2], src.data[ 3],
           src.data[ 4], src.data[ 5], src.data[ 6], src.data[ 7],
           src.data[ 8], src.data[ 9], src.data[10], src.data[11],
           src.data[12], src.data[13], src.data[14], src.data[15]} {
  }

  /**
   * Copy casting constructor.
   * @param src Data source for new created instance of matrix4.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix4(matrix4<FromT> const &src) noexcept
    : data{static_cast<T>(src.data[ 0]), static_cast<T>(src.data[ 1]), static_cast<T>(src.data[ 2]), static_cast<T>(src.data[ 3]),
           static_cast<T>(src.data[ 4]), static_cast<T>(src.data[ 5]), static_cast<T>(src.data[ 6]), static_cast<T>(src.data[ 7]),
           static_cast<T>(src.data[ 8]), static_cast<T>(src.data[ 9]), static_cast<T>(src.data[10]), static_cast<T>(src.data[11]),
           static_cast<T>(src.data[12]), static_cast<T>(src.data[13]), static_cast<T>(src.data[14]), static_cast<T>(src.data[15])} {
  }

  /**
   * Move constructor.
   * @param src Data source for new created instance of matrix4.
   */
  inline constexpr matrix4(matrix4<T> &&src) noexcept __attribute__((__always_inline__))
    : data(std::move(src.data)) {
  }

  /**
   * Move casting constructor.
   * @param src Data source for new created instance of matrix4.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr matrix4(matrix4<FromT> &&src) noexcept
    : data{static_cast<T>(std::move(src.data[ 0])), static_cast<T>(std::move(src.data[ 1])), static_cast<T>(std::move(src.data[ 2])), static_cast<T>(std::move(src.data[ 3])),
           static_cast<T>(std::move(src.data[ 4])), static_cast<T>(std::move(src.data[ 5])), static_cast<T>(std::move(src.data[ 6])), static_cast<T>(std::move(src.data[ 7])),
           static_cast<T>(std::move(src.data[ 8])), static_cast<T>(std::move(src.data[ 9])), static_cast<T>(std::move(src.data[10])), static_cast<T>(std::move(src.data[11])),
           static_cast<T>(std::move(src.data[12])), static_cast<T>(std::move(src.data[13])), static_cast<T>(std::move(src.data[14])), static_cast<T>(std::move(src.data[15]))} {
  }

  /**
   * Copy constructor from matrix3.
   * @param src Data source for new created instance of matrix4.
   */
  /*
  inline constexpr explicit matrix4(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[0],       src.data[1],       src.data[2],       static_cast<T>(0),
           src.data[3],       src.data[4],       src.data[5],       static_cast<T>(0),
           src.data[6],       src.data[7],       src.data[8],       static_cast<T>(0),
           static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)} {
  }
  */

  /**
   * Copy casting constructor from matrix3.
   * @param src Data source for new created instance of matrix4.
   */
  /*
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix4(matrix3<FromT> const &src) noexcept
    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]), static_cast<T>(0),
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]), static_cast<T>(0),
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8]), static_cast<T>(0),
           static_cast<T>(0),           static_cast<T>(0),           static_cast<T>(0),           static_cast<T>(1)} {
  }
  */

  /**
   * Move constructor from matrix3.
   * @param src Data source for new created instance of matrix4.
   */
  /*
  inline constexpr explicit matrix4(matrix3<T> &&src) noexcept __attribute__((__always_inline__))
    : data{std::move(src.data[0]), std::move(src.data[1]), std::move(src.data[2]), static_cast<T>(0),
           std::move(src.data[3]), std::move(src.data[4]), std::move(src.data[5]), static_cast<T>(0),
           std::move(src.data[6]), std::move(src.data[7]), std::move(src.data[8]), static_cast<T>(0),
           static_cast<T>(0),      static_cast<T>(0),      static_cast<T>(0),      static_cast<T>(1)} {
  }
  */

  /**
   * Move casting constructor from matrix3.
   * @param src Data source for new created instance of matrix4.
   */
  /*
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix4(matrix3<FromT> &&src) noexcept
    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])), static_cast<T>(0),
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])), static_cast<T>(0),
           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8])), static_cast<T>(0),
           static_cast<T>(0),                      static_cast<T>(0),                      static_cast<T>(0),                      static_cast<T>(1)} {
  }
  */

  /**
   * Variadic initialisation constructor
   * @param dt Initialiser list containing raw data for each element in order.
   */
  //inline constexpr explicit matrix4(std::initializer_list<T> dt) noexcept __attribute__((__always_inline__))
  //  : data(dt) {
  //}
  // see http://stackoverflow.com/a/5549918/1678468
  template<typename... FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix4(FromT... dt) noexcept
    : data{dt...} {
  }
  //template<typename... FromT> __attribute__((__always_inline__))
  //inline constexpr explicit matrix4(FromT&&... dt)
  //  : data{std::forward<FromT>(dt)...} {
  //}

  /**
   * Resets matrix to be identity matrix
   */
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
    data = {1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1};
  }

  /**
   * Creates rotation matrix by rotation around three axes.
   * @param xDeg Angle (in degrees) of rotation around axis X.
   * @param yDeg Angle (in degrees) of rotation around axis Y.
   * @param zDeg Angle (in degrees) of rotation around axis Z.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_rotation_from_euler_angles(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
    return create_rotation_from_euler_angles_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
  }

  /**
   * Creates rotation matrix by rotation around three axes, radian version.
   * @param xRads Angle (in radians) of rotation around axis X.
   * @param yRads Angle (in radians) of rotation around axis Y.
   * @param zRads Angle (in radians) of rotation around axis Z.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_rotation_from_euler_angles_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>::create_rotation_from_euler_angles_rad(xRads, yRads, zRads).get_transform();
  }

  /**
   * Creates rotation matrix by rotation around an axis.
   * @param axis Axis to rotate around.
   * @param angle Angle (in degrees) of rotation around axis.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    return create_rotation_around_axis_rad(axis, deg2rad(angle));
  }

  /**
   * Creates rotation matrix by rotation around an axis, radian version.
   * @param axis Axis to rotate around.
   * @param angle Angle (in radians) of rotation around axis.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>::create_rotation_around_axis_rad(axis, angle).get_transform();
  }

  /**
   * Creates translation matrix.
   * @param x X-direction translation
   * @param y Y-direction translation
   * @param z Z-direction translation
   * @param w for W-coordinate translation (implicitly set to 1)
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_translation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
                      x,                 y,                 z,                 w);
  }

  /**
   * Creates translation matrix from a vector3
   *
   * @param v Vector of translation to be set.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_translation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {
    return create_translation(v.x, v.y, v.z);
  }

  /**
   * Creates translation matrix from a vector4
   *
   * @param v Vector of translation to be set.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_translation(vector4<T> const &v) noexcept __attribute__((__always_inline__)) {
    return create_translation(v.x, v.y, v.z, v.w);
  }

  /**
   * Create scale matrix with @a sx, @a sy, and @a sz
   * being values of matrix main diagonal.
   * @param sx Scale in X-axis
   * @param sy Scale in Y-axis
   * @param sz Scale in Z-axis
   * @return Transform matrix 4x4 with scale transformation.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_scale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(sx,                static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), sy,                static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), sz,                static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
  }

  /**
   * Creates rotation matrix by aligning one vector to another.
   * @param from Vector to rotate from.
   * @param to Vector to rotate to.
   * @return An instance of matrix4<T> representing rotation between the two vectors.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>::create_rotation_between_vectors(from, to).get_transform();
  }

  /**
   * Creates a rotation matrix to align with a target vector direction @a target
   * @param target Vector that the rotation should point at
   * @param up_dir Direction of up vector
   * @return Resulting matrix that's oriented to the target vector
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>::create_rotation_aligned_to_vector(target, up_dir).get_transform();
  }

  /**
   * Creates view matrix to look from specified position @a eye_pos to specified position @a target_pos
   * @param eye_pos Position of the thing doing the looking
   * @param target_pos Position that the view should be aligned to
   * @param up_dir Direction of up vector
   * @return Resulting view matrix that's looking at the target point
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_look_at(vector3<T> const &eye_pos, vector3<T> const &target_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
    vector3<T> const forward((target_pos - eye_pos).normalise_copy());
    vector3<T> const side(forward.cross(up_dir).normalise_safe_copy());         // Side = forward x up
    vector3<T> const up = side.cross(forward);                                  // Recompute up as: up = side x forward

    return matrix4<T>(static_cast<T>(side.x),
                      static_cast<T>(up.x),
                      static_cast<T>(-forward.x),
                      static_cast<T>(0),

                      static_cast<T>(side.y),
                      static_cast<T>(up.y),
                      static_cast<T>(-forward.y),
                      static_cast<T>(0),

                      static_cast<T>(side.z),
                      static_cast<T>(up.z),
                      static_cast<T>(-forward.z),
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
  }

  /**
   * Creates OpenGL compatible perspective projection according to specified frustum parameters.
   *
   * @param left Specify the coordinate for the left vertical clipping plane,
   * @param right Specify the coordinate for the right vertical clipping plane.
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
   * @param top Specify the coordinate for the top horizontal clipping plane.
   * @param near_plane Specify the distance to the near clipping plane.  Distance must be positive.
   * @param far_plane Specify the distance to the far depth clipping plane.  Distance must be positive.
   * @return Projection matrix for specified frustum.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_frustum(T left, T right, T bottom, T top, T near_plane, T far_plane) noexcept __attribute__((__always_inline__)) {
    /*
     *    2 near
     *  ------------       0              A              0
     *  right - left
     *
     *                  2 near
     *      0         ------------        B              0
     *                top - bottom
     *
     *      0              0              C              D
     *
     *      0              0              -1             0
     *
     *  A =   (right + left) / (right - left)
     *  B =   (top + bottom) / (top - bottom)
     *  C = - (far + near) / (far - near)
     *  D = - (2 far near) / (far - near)
     */
    return matrix4<T>((static_cast<T>(2) * near_plane) / (right - left),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),

                      static_cast<T>(0),
                      (static_cast<T>(2) * near_plane) / (top - bottom),
                      static_cast<T>(0),
                      static_cast<T>(0),

                       (right     + left)       / (right     - left),
                       (top       + bottom)     / (top       - bottom),
                      -(far_plane + near_plane) / (far_plane - near_plane),
                      static_cast<T>(-1),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      (static_cast<T>(-2) * far_plane * near_plane) / (far_plane - near_plane),
                      static_cast<T>(0));
  }

  /**
   * Creates OpenGL compatible orthographic projection matrix.
   * @param left Specify the coordinate for the left vertical clipping plane,
   * @param right Specify the coordinate for the right vertical clipping plane.
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane.
   * @param top Specify the coordinate for the top horizontal clipping plane.
   * @param near_plane Specify the distance to the nearer depth clipping plane. This value is negative if the plane is to be behind the viewer.
   * @param far_plane Specify the distance to the farther depth clipping plane. This value is negative if the plane is to be behind the viewer.
   * @return Othrographic projection matrix.
   */
  [[nodiscard]]
  inline static matrix4<T> constexpr create_ortho(T left, T right, T bottom, T top, T near_plane, T far_plane) noexcept __attribute__((__always_inline__)) {
    /*      2
     *  ------------       0              0              tx
     *  right - left
     *                     2
     *      0         ------------        0              ty
     *                top - bottom
     *                                    -2
     *      0              0         ------------        tz
     *                                far - near
     *
     *      0              0              0              1
     *
     *    tx = - (right + left) / (right - left)
     *    ty = - (top + bottom) / (top - bottom)
     *    tz = - (far + near) / (far - near)
     */
    return matrix4<T>(static_cast<T>(2) / (right - left),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(2) / (top - bottom),
                      static_cast<T>(0),
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(-2) / (far_plane - near_plane),
                      static_cast<T>(0),

                      -(right     + left)       / (right     - left),
                      -(top       + bottom)     / (top       - bottom),
                      -(far_plane + near_plane) / (far_plane - near_plane),
                      static_cast<T>(1));
  }

  /**
   * Creates new matrix 4x4 from array that represents such matrix 4x4
   * as array of tightly packed elements in row major order.
   * @param arr An array of elements for 4x4 matrix in row major order.
   * @return An instance of matrix4<T> representing @a arr
   */
  template<typename FromT> [[nodiscard]] __attribute__((__always_inline__))
  inline static matrix4<T> constexpr from_row_major_array(FromT const *arr) noexcept {
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(arr[12]),
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(arr[13]),
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(arr[14]),
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(arr[15]));
  }

  /**
   * Creates new matrix 4x4 from array that represents such matrix 4x4
   * as array of tightly packed elements in column major order.
   * @param arr An array of elements for 4x4 matrix in column major order.
   * @return An instance of matrix4<T> representing @a arr
   */
  template<typename FromT> [[nodiscard]] __attribute__((__always_inline__))
  inline static matrix4<T> constexpr from_column_major_array(FromT const *arr) noexcept {
    return matrix4<T>(static_cast<T>(arr[ 0]), static_cast<T>(arr[ 1]), static_cast<T>(arr[ 2]), static_cast<T>(arr[ 3]),
                      static_cast<T>(arr[ 4]), static_cast<T>(arr[ 5]), static_cast<T>(arr[ 6]), static_cast<T>(arr[ 7]),
                      static_cast<T>(arr[ 8]), static_cast<T>(arr[ 9]), static_cast<T>(arr[10]), static_cast<T>(arr[11]),
                      static_cast<T>(arr[12]), static_cast<T>(arr[13]), static_cast<T>(arr[14]), static_cast<T>(arr[15]));
  }

  /**
   * Creates new matrix 4x4 from array that represents such matrix 3x4
   * as array of tightly packed elements in row major order.
   * @param arr An array of elements for 3x4 matrix in row major order.
   * @return An instance of matrix4<T> representing @a arr
   */
  template<typename FromT> [[nodiscard]] __attribute__((__always_inline__))
  inline static matrix4<T> constexpr from_row_major_34_array(FromT const *arr) noexcept {
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(0),
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(0),
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(0),
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(1));
  }

  //---------------------[ Equality operators ]------------------------------
  /**
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   * values equal, must satisfy this condition all elements of matrix
   * | lhs[i] - rhs[i] | < epsilon,
   * same for y-coordinate, z-coordinate, and w-coordinate.
   */
  [[nodiscard]]
  inline bool constexpr operator==(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VECTORSTORM_SOFT_COMPARE
      return std::abs(data[ 0] - rhs.data[ 0]) < epsilon<T> &&
             std::abs(data[ 1] - rhs.data[ 1]) < epsilon<T> &&
             std::abs(data[ 2] - rhs.data[ 2]) < epsilon<T> &&
             std::abs(data[ 3] - rhs.data[ 3]) < epsilon<T> &&
             std::abs(data[ 4] - rhs.data[ 4]) < epsilon<T> &&
             std::abs(data[ 5] - rhs.data[ 5]) < epsilon<T> &&
             std::abs(data[ 6] - rhs.data[ 6]) < epsilon<T> &&
             std::abs(data[ 7] - rhs.data[ 7]) < epsilon<T> &&
             std::abs(data[ 8] - rhs.data[ 8]) < epsilon<T> &&
             std::abs(data[ 9] - rhs.data[ 9]) < epsilon<T> &&
             std::abs(data[10] - rhs.data[10]) < epsilon<T> &&
             std::abs(data[11] - rhs.data[11]) < epsilon<T> &&
             std::abs(data[12] - rhs.data[12]) < epsilon<T> &&
             std::abs(data[13] - rhs.data[13]) < epsilon<T> &&
             std::abs(data[14] - rhs.data[14]) < epsilon<T> &&
             std::abs(data[15] - rhs.data[15]) < epsilon<T>;
    #else
      #pragma GCC diagnostic push
      #pragma GCC diagnostic ignored "-Wfloat-equal"
      return data[ 0] == rhs.data[ 0] &&
             data[ 1] == rhs.data[ 1] &&
             data[ 2] == rhs.data[ 2] &&
             data[ 3] == rhs.data[ 3] &&
             data[ 4] == rhs.data[ 4] &&
             data[ 5] == rhs.data[ 5] &&
             data[ 6] == rhs.data[ 6] &&
             data[ 7] == rhs.data[ 7] &&
             data[ 8] == rhs.data[ 8] &&
             data[ 9] == rhs.data[ 9] &&
             data[10] == rhs.data[10] &&
             data[11] == rhs.data[11] &&
             data[12] == rhs.data[12] &&
             data[13] == rhs.data[13] &&
             data[14] == rhs.data[14] &&
             data[15] == rhs.data[15];
      #pragma GCC diagnostic pop
    #endif // VECTORSTORM_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  [[nodiscard]]
  inline bool constexpr operator!=(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //---------------------[ access operators ]---------------------------------
  /**
   * Get reference to element at position (x,y).
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
   */
  [[nodiscard]]
  inline T constexpr &operator[](unsigned int x, unsigned int y) noexcept __attribute__((__always_inline__)) {
    return data[x * 4 + y];
  }
  /**
   * Get reference to element at position (x,y).
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
   */
  [[nodiscard]]
  inline T constexpr const &operator[](unsigned int x, unsigned int y) const noexcept __attribute__((__always_inline__)) {
    return data[x * 4 + y];
  }

  /**
   * Get reference to element at postion (x,y).  Throws an exception if out of range.
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
   */
  [[nodiscard]]
  inline T constexpr &at(unsigned int x, unsigned int y) noexcept __attribute__((__always_inline__)) {
    if(x > 2 || y > 2) throw std::out_of_range("Matrix access at() function accepts x and y values 0..3, given " + std::to_string(x) + ", " + std::to_string(y));
    return data[x * 4 + y];
  }

  /**
   * Get constant reference to element at position (x,y).  Throws an exception if out of range.
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
   */
  [[nodiscard]]
  inline T constexpr const &at(unsigned int x, unsigned int y) const noexcept __attribute__((__always_inline__)) {
    if(x > 2 || y > 2) throw std::out_of_range("Matrix access at() function accepts x and y values 0..3, given " + std::to_string(x) + ", " + std::to_string(y));
    return data[x * 4 + y];
  }

  /**
   * Get reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..4)
   * @param j Number of column (1..4)
   */
  [[nodiscard]] [[deprecated("Use either multidimensional operator[] or .at(), counting from 0")]]
  inline T constexpr &operator()(unsigned int i, unsigned int j) noexcept __attribute__((__always_inline__)) {
    assert(j != 0 && j < 5);
    return operator[](j - 1, i - 1);
  }

  /**
   * Get constant reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..4)
   * @param j Number of column (1..4)
   */
  [[nodiscard]] [[deprecated("Use either multidimensional operator[] or .at(), counting from 0")]]
  inline T constexpr const &operator()(unsigned int i, unsigned int j) const noexcept __attribute__((__always_inline__)) {
    assert(j != 0 && j < 5);
    return operator[](j - 1, i - 1);
  }

  /**
   * Sets translation part of matrix.
   *
   * @param v Vector of translation to be set.
   */
  inline void constexpr set_translation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {
    data[12] = v.x;
    data[13] = v.y;
    data[14] = v.z;
    data[15] = 1;
  }

  /**
   * Returns translation part of matrix.
   */
  [[nodiscard]]
  inline vector3<T> constexpr get_translation() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>{data[12], data[13], data[14]};
  }

  /**
   * Sets rotation part (matrix 3x3) of matrix.
   *
   * @param m Rotation part of matrix
   */
  inline void constexpr set_rotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
    data[ 0] = m.data[0];
    data[ 1] = m.data[1];
    data[ 2] = m.data[2];
    data[ 4] = m.data[3];
    data[ 5] = m.data[4];
    data[ 6] = m.data[5];
    data[ 8] = m.data[6];
    data[ 9] = m.data[7];
    data[10] = m.data[8];
  }

  /**
   * Returns rotation (matrix 3x3) part of matrix.
   */
  [[nodiscard]]
  inline matrix3<T> constexpr get_rotation() const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>{data[ 0], data[ 1], data[ 2],
                      data[ 4], data[ 5], data[ 6],
                      data[ 8], data[ 9], data[10]};
  }

  /**
   * Sets scale part of matrix.
   *
   * @param v Vector of scale to be set.
   */
  inline void constexpr set_scale(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {
    data[ 0] = v.x;
    data[ 5] = v.y;
    data[10] = v.z;
    data[15] = 1;
  }

  /**
   * Returns scale part of matrix.
   */
  [[nodiscard]]
  inline vector3<T> constexpr get_scale() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>{data[0], data[5], data[10]};
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    //std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 16);
    data = rhs.data;
    return *this;
  }

  /**
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline matrix4<T> constexpr &operator=(matrix4<FromT> const &rhs) noexcept {
    data[ 0] = static_cast<T>(rhs.data[ 0]);
    data[ 1] = static_cast<T>(rhs.data[ 1]);
    data[ 2] = static_cast<T>(rhs.data[ 2]);
    data[ 3] = static_cast<T>(rhs.data[ 3]);
    data[ 4] = static_cast<T>(rhs.data[ 4]);
    data[ 5] = static_cast<T>(rhs.data[ 5]);
    data[ 6] = static_cast<T>(rhs.data[ 6]);
    data[ 7] = static_cast<T>(rhs.data[ 7]);
    data[ 8] = static_cast<T>(rhs.data[ 8]);
    data[ 9] = static_cast<T>(rhs.data[ 9]);
    data[10] = static_cast<T>(rhs.data[10]);
    data[11] = static_cast<T>(rhs.data[11]);
    data[12] = static_cast<T>(rhs.data[12]);
    data[13] = static_cast<T>(rhs.data[13]);
    data[14] = static_cast<T>(rhs.data[14]);
    data[15] = static_cast<T>(rhs.data[15]);
    return *this;
  }

  /**
   * Copy operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
    /*
    for(int i = 0; i != 16; ++i) {
      data[i] = (T)rhs[i];
    }
    */
    std::memcpy(data.data(), rhs, sizeof(T) * 16);
    return *this;
  }

  /**
   * Move assignment operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator=(matrix4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    data = std::move(rhs.data);
    return *this;
  }

  /**
   * Move assignment casting operator
   * @param rhs Right hand side argument of binary operator.
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline matrix4<T> constexpr &operator=(matrix4<FromT> &&rhs) noexcept {
    data[ 0] = static_cast<T>(std::move(rhs.data[ 0]));
    data[ 1] = static_cast<T>(std::move(rhs.data[ 1]));
    data[ 2] = static_cast<T>(std::move(rhs.data[ 2]));
    data[ 3] = static_cast<T>(std::move(rhs.data[ 3]));
    data[ 4] = static_cast<T>(std::move(rhs.data[ 4]));
    data[ 5] = static_cast<T>(std::move(rhs.data[ 5]));
    data[ 6] = static_cast<T>(std::move(rhs.data[ 6]));
    data[ 7] = static_cast<T>(std::move(rhs.data[ 7]));
    data[ 8] = static_cast<T>(std::move(rhs.data[ 8]));
    data[ 9] = static_cast<T>(std::move(rhs.data[ 9]));
    data[10] = static_cast<T>(std::move(rhs.data[10]));
    data[11] = static_cast<T>(std::move(rhs.data[11]));
    data[12] = static_cast<T>(std::move(rhs.data[12]));
    data[13] = static_cast<T>(std::move(rhs.data[13]));
    data[14] = static_cast<T>(std::move(rhs.data[14]));
    data[15] = static_cast<T>(std::move(rhs.data[15]));
    return *this;
  }

  //--------------------[ matrix with matrix operations ]---------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator+(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] + rhs.data[ 0], data[ 1] + rhs.data[ 1], data[ 2] + rhs.data[ 2], data[ 3] + rhs.data[ 3],
                      data[ 4] + rhs.data[ 4], data[ 5] + rhs.data[ 5], data[ 6] + rhs.data[ 6], data[ 7] + rhs.data[ 7],
                      data[ 8] + rhs.data[ 8], data[ 9] + rhs.data[ 9], data[10] + rhs.data[10], data[11] + rhs.data[11],
                      data[12] + rhs.data[12], data[13] + rhs.data[13], data[14] + rhs.data[14], data[15] + rhs.data[15]);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator-(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] - rhs.data[ 0], data[ 1] - rhs.data[ 1], data[ 2] - rhs.data[ 2], data[ 3] - rhs.data[ 3],
                      data[ 4] - rhs.data[ 4], data[ 5] - rhs.data[ 5], data[ 6] - rhs.data[ 6], data[ 7] - rhs.data[ 7],
                      data[ 8] - rhs.data[ 8], data[ 9] - rhs.data[ 9], data[10] - rhs.data[10], data[11] - rhs.data[11],
                      data[12] - rhs.data[12], data[13] - rhs.data[13], data[14] - rhs.data[14], data[15] - rhs.data[15]);
  }

  //--------------------[ matrix with scalar operations ]---------------------
  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] + rhs, data[ 1] + rhs, data[ 2] + rhs, data[ 3] + rhs,
                      data[ 4] + rhs, data[ 5] + rhs, data[ 6] + rhs, data[ 7] + rhs,
                      data[ 8] + rhs, data[ 9] + rhs, data[10] + rhs, data[11] + rhs,
                      data[12] + rhs, data[13] + rhs, data[14] + rhs, data[15] + rhs);
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] - rhs, data[ 1] - rhs, data[ 2] - rhs, data[ 3] - rhs,
                      data[ 4] - rhs, data[ 5] - rhs, data[ 6] - rhs, data[ 7] - rhs,
                      data[ 8] - rhs, data[ 9] - rhs, data[10] - rhs, data[11] - rhs,
                      data[12] - rhs, data[13] - rhs, data[14] - rhs, data[15] - rhs);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] * rhs, data[ 1] * rhs, data[ 2] * rhs, data[ 3] * rhs,
                      data[ 4] * rhs, data[ 5] * rhs, data[ 6] * rhs, data[ 7] * rhs,
                      data[ 8] * rhs, data[ 9] * rhs, data[10] * rhs, data[11] * rhs,
                      data[12] * rhs, data[13] * rhs, data[14] * rhs, data[15] * rhs);
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] / rhs, data[ 1] / rhs, data[ 2] / rhs, data[ 3] / rhs,
                      data[ 4] / rhs, data[ 5] / rhs, data[ 6] / rhs, data[ 7] / rhs,
                      data[ 8] / rhs, data[ 9] / rhs, data[10] / rhs, data[11] / rhs,
                      data[12] / rhs, data[13] / rhs, data[14] / rhs, data[15] / rhs);
  }

  /**
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this + rhs;
    return *this;
  }

  /**
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this - rhs;
    return *this;
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this * rhs;
    return *this;
  }

  /**
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this / rhs;
    return *this;
  }

  //--------------------[ multiply operators ]--------------------------------
  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector4<T>(data[0] * rhs.x + data[4] * rhs.y + data[ 8] * rhs.z + data[12] * rhs.w,
                      data[1] * rhs.x + data[5] * rhs.y + data[ 9] * rhs.z + data[13] * rhs.w,
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z + data[14] * rhs.w,
                      data[3] * rhs.x + data[7] * rhs.y + data[11] * rhs.z + data[15] * rhs.w);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(data[0] * rhs.x + data[4] * rhs.y + data[ 8] * rhs.z + data[12],
                      data[1] * rhs.x + data[5] * rhs.y + data[ 9] * rhs.z + data[13],
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z + data[14]);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  [[nodiscard]]
  inline matrix4<T> constexpr operator*(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(rhs.data[ 0] * data[ 0] + rhs.data[ 1] * data[ 4] + rhs.data[ 2] * data[ 8] + rhs.data[ 3] * data[12],
                      rhs.data[ 0] * data[ 1] + rhs.data[ 1] * data[ 5] + rhs.data[ 2] * data[ 9] + rhs.data[ 3] * data[13],
                      rhs.data[ 0] * data[ 2] + rhs.data[ 1] * data[ 6] + rhs.data[ 2] * data[10] + rhs.data[ 3] * data[14],
                      rhs.data[ 0] * data[ 3] + rhs.data[ 1] * data[ 7] + rhs.data[ 2] * data[11] + rhs.data[ 3] * data[15],

                      rhs.data[ 4] * data[ 0] + rhs.data[ 5] * data[ 4] + rhs.data[ 6] * data[ 8] + rhs.data[ 7] * data[12],
                      rhs.data[ 4] * data[ 1] + rhs.data[ 5] * data[ 5] + rhs.data[ 6] * data[ 9] + rhs.data[ 7] * data[13],
                      rhs.data[ 4] * data[ 2] + rhs.data[ 5] * data[ 6] + rhs.data[ 6] * data[10] + rhs.data[ 7] * data[14],
                      rhs.data[ 4] * data[ 3] + rhs.data[ 5] * data[ 7] + rhs.data[ 6] * data[11] + rhs.data[ 7] * data[15],

                      rhs.data[ 8] * data[ 0] + rhs.data[ 9] * data[ 4] + rhs.data[10] * data[ 8] + rhs.data[11] * data[12],
                      rhs.data[ 8] * data[ 1] + rhs.data[ 9] * data[ 5] + rhs.data[10] * data[ 9] + rhs.data[11] * data[13],
                      rhs.data[ 8] * data[ 2] + rhs.data[ 9] * data[ 6] + rhs.data[10] * data[10] + rhs.data[11] * data[14],
                      rhs.data[ 8] * data[ 3] + rhs.data[ 9] * data[ 7] + rhs.data[10] * data[11] + rhs.data[11] * data[15],

                      rhs.data[12] * data[ 0] + rhs.data[13] * data[ 4] + rhs.data[14] * data[ 8] + rhs.data[15] * data[12],
                      rhs.data[12] * data[ 1] + rhs.data[13] * data[ 5] + rhs.data[14] * data[ 9] + rhs.data[15] * data[13],
                      rhs.data[12] * data[ 2] + rhs.data[13] * data[ 6] + rhs.data[14] * data[10] + rhs.data[15] * data[14],
                      rhs.data[12] * data[ 3] + rhs.data[13] * data[ 7] + rhs.data[14] * data[11] + rhs.data[15] * data[15]);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
  inline matrix4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this * rhs;
    return *this;
  }

  //---------------------------[ misc operations ]----------------------------

  /**
   * Computes determinant of matrix
   * @return Determinant of matrix
   * @note This function does 3 * 4 * 6 mul, 3 * 6 add.
   */
  [[nodiscard]]
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
    return   data[12] * data[9] * data[6]  * data[3]  - data[8] * data[13] * data[6]  * data[3]
           - data[12] * data[5] * data[10] * data[3]  + data[4] * data[13] * data[10] * data[3]

           + data[8]  * data[5] * data[14] * data[3]  - data[4] * data[9]  * data[14] * data[3]
           - data[12] * data[9] * data[2]  * data[7]  + data[8] * data[13] * data[2]  * data[7]

           + data[12] * data[1] * data[10] * data[7]  - data[0] * data[13] * data[10] * data[7]
           - data[8]  * data[1] * data[14] * data[7]  + data[0] * data[9]  * data[14] * data[7]

           + data[12] * data[5] * data[2]  * data[11] - data[4] * data[13] * data[2]  * data[11]
           - data[12] * data[1] * data[6]  * data[11] + data[0] * data[13] * data[6]  * data[11]

           + data[4]  * data[1] * data[14] * data[11] - data[0] * data[5]  * data[14] * data[11]
           - data[8]  * data[5] * data[2]  * data[15] + data[4] * data[9]  * data[2]  * data[15]

           + data[8]  * data[1] * data[6]  * data[15] - data[0] * data[9]  * data[6]  * data[15]
           - data[4]  * data[1] * data[10] * data[15] + data[0] * data[5]  * data[10] * data[15];
  }

  /**
   * Computes inverse matrix
   * @return Inverse matrix of this matrix.
   * @note This is a little bit time consuming operation
   * (16 * 6 * 3 mul, 16 * 5 add + det() + mul() functions)
   */
  [[nodiscard("Inverse does not modify the input matrix")]]
  inline matrix4<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[9]  * data[14] * data[7]  - data[13] * data[10] * data[7]  + data[13] * data[6]  * data[11] -
                      data[5]  * data[14] * data[11] - data[9]  * data[6]  * data[15] + data[5]  * data[10] * data[15],
                      data[13] * data[10] * data[3]  - data[9]  * data[14] * data[3]  - data[13] * data[2]  * data[11] +
                      data[1]  * data[14] * data[11] + data[9]  * data[2]  * data[15] - data[1]  * data[10] * data[15],
                      data[5]  * data[14] * data[3]  - data[13] * data[6]  * data[3]  + data[13] * data[2]  * data[7] -
                      data[1]  * data[14] * data[7]  - data[5]  * data[2]  * data[15] + data[1]  * data[6]  * data[15],
                      data[9]  * data[6]  * data[3]  - data[5]  * data[10] * data[3]  - data[9]  * data[2]  * data[7] +
                      data[1]  * data[10] * data[7]  + data[5]  * data[2]  * data[11] - data[1]  * data[6]  * data[11],
                      data[12] * data[10] * data[7]  - data[8]  * data[14] * data[7]  - data[12] * data[6]  * data[11] +
                      data[4]  * data[14] * data[11] + data[8]  * data[6]  * data[15] - data[4]  * data[10] * data[15],
                      data[8]  * data[14] * data[3]  - data[12] * data[10] * data[3]  + data[12] * data[2]  * data[11] -
                      data[0]  * data[14] * data[11] - data[8]  * data[2]  * data[15] + data[0]  * data[10] * data[15],
                      data[12] * data[6]  * data[3]  - data[4]  * data[14] * data[3]  - data[12] * data[2]  * data[7] +
                      data[0]  * data[14] * data[7]  + data[4]  * data[2]  * data[15] - data[0]  * data[6]  * data[15],
                      data[4]  * data[10] * data[3]  - data[8]  * data[6]  * data[3]  + data[8]  * data[2]  * data[7] -
                      data[0]  * data[10] * data[7]  - data[4]  * data[2]  * data[11] + data[0]  * data[6]  * data[11],
                      data[8]  * data[13] * data[7]  - data[12] * data[9]  * data[7]  + data[12] * data[5]  * data[11] -
                      data[4]  * data[13] * data[11] - data[8]  * data[5]  * data[15] + data[4]  * data[9]  * data[15],
                      data[12] * data[9]  * data[3]  - data[8]  * data[13] * data[3]  - data[12] * data[1]  * data[11] +
                      data[0]  * data[13] * data[11] + data[8]  * data[1]  * data[15] - data[0]  * data[9]  * data[15],
                      data[4]  * data[13] * data[3]  - data[12] * data[5]  * data[3]  + data[12] * data[1]  * data[7] -
                      data[0]  * data[13] * data[7]  - data[4]  * data[1]  * data[15] + data[0]  * data[5]  * data[15],
                      data[8]  * data[5]  * data[3]  - data[4]  * data[9]  * data[3]  - data[8]  * data[1]  * data[7] +
                      data[0]  * data[9]  * data[7]  + data[4]  * data[1]  * data[11] - data[0]  * data[5]  * data[11],
                      data[12] * data[9]  * data[6]  - data[8]  * data[13] * data[6]  - data[12] * data[5]  * data[10] +
                      data[4]  * data[13] * data[10] + data[8]  * data[5]  * data[14] - data[4]  * data[9]  * data[14],
                      data[8]  * data[13] * data[2]  - data[12] * data[9]  * data[2]  + data[12] * data[1]  * data[10] -
                      data[0]  * data[13] * data[10] - data[8]  * data[1]  * data[14] + data[0]  * data[9]  * data[14],
                      data[12] * data[5]  * data[2]  - data[4]  * data[13] * data[2]  - data[12] * data[1]  * data[6] +
                      data[0]  * data[13] * data[6]  + data[4]  * data[1]  * data[14] - data[0]  * data[5]  * data[14],
                      data[4]  * data[9]  * data[2]  - data[8]  * data[5]  * data[2]  + data[8]  * data[1]  * data[6] -
                      data[0]  * data[9]  * data[6]  - data[4]  * data[1]  * data[10] + data[0]  * data[5]  * data[10]) / det();
  }

  /**
   * Transpose matrix.
   */
  [[nodiscard("Transpose does not modify the input matrix")]]
  inline matrix4<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[0], data[4], data[8],  data[12],
                      data[1], data[5], data[9],  data[13],
                      data[2], data[6], data[10], data[14],
                      data[3], data[7], data[11], data[15]);
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
  [[nodiscard("Interpolation does not modify the input matrix")]]
  inline matrix4<T> constexpr lerp(T fact, matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return (*this) + (rhs - (*this)) * fact;
  }

  //-------------[ conversion ]-----------------------------
  /**
   * Conversion to pointer operator
   * @return Pointer to internally stored (in management of class matrix4<T>)
   * used for passing matrix4<T> values to gl*[fd]v functions.
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(data.data());
  }

  /**
   * Conversion to pointer operator
   * @return Constant Pointer to internally stored (in management of class matrix4<T>)
   * used for passing matrix4<T> values to gl*[fd]v functions.
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
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    for(int i = 0; i != 4; ++i) {
      lhs << "|\t";
      for(int j = 0; j != 4; ++j) {
        lhs << +rhs.at(j, i) << "\t";
      }
      lhs << "|" << std::endl;
    }
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
};

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE

#include "matrix4_types.h"

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
template<typename T> [[nodiscard]]
inline constexpr matrix4<T> min(matrix4<T> const &a, const matrix4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr matrix4<T> min(matrix4<T> const &a, const matrix4<T> &b) noexcept {
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
template<typename T> [[nodiscard]]
inline constexpr matrix4<T> max(matrix4<T> const &a, const matrix4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
template<typename T>
inline constexpr matrix4<T> max(matrix4<T> const &a, const matrix4<T> &b) noexcept {
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
struct hash<matrix4<T>> {
  /**
   * Gets a hash value taking account of all dimensions of this matrix, for use
   * in standard container maps etc.
   * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
   * @return Hash value
   */
  size_t operator()(const matrix4<T> &value) const {
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
size_t hash_value(matrix4<T> const &value) {
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
