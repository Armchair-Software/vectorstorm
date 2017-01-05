    return matrix3<T>::create_rotation_around_axis_rad(axis, angle).get_transform();
  }
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
    return create_rotation_around_axis_rad(axis, angle);
  }

  /// Creates translation matrix
  /**
   * Creates translation matrix.
   * @param x X-direction translation
   * @param y Y-direction translation
   * @param z Z-direction translation
   * @param w for W-coordinate translation (implicitly set to 1)
   */
  inline static matrix4<T> constexpr create_translation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
                      x,                 y,                 z,                 w);
  }
  inline static matrix4<T> constexpr createTranslation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_translation()"))) {
    return create_translation(x, y, z, w);
  }

  /**
   * Create scale matrix with @a sx, @a sy, and @a sz
   * being values of matrix main diagonal.
   * @param sx Scale in X-axis
   * @param sy Scale in Y-axis
   * @param sz Scale in Z-axis
   * @return Transform matrix 4x4 with scale transformation.
   */
  inline static matrix4<T> constexpr create_scale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(sx,                static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), sy,                static_cast<T>(0), static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), sz,                static_cast<T>(0),
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
  }
  inline static matrix4<T> constexpr createScale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_scale()"))) {
    return create_scale(sx, sy, sz);
  }

  /**
   * Creates rotation matrix by aligning one vector to another.
   * @param from Vector to rotate from.
   * @param to Vector to rotate to.
   * @return An instance of matrix4<T> representing rotation between the two vectors.
   */
  inline static matrix4<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>::create_rotation_between_vectors(from, to).get_transform();
  }

  /**
   * Creates a rotation matrix to align with a target vector direction @a target
   * @param target Vector that the rotation should point at
   * @param up_dir Direction of up vector
   * @return Resulting matrix that's oriented to the target vector
   */
#ifndef VECTORSTORM_MATRIX4_H_INCLUDED
  inline static matrix4<T> constexpr create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
#define VECTORSTORM_MATRIX4_H_INCLUDED
    return matrix3<T>::create_rotation_aligned_to_vector(target, up_dir).get_transform();

  }
#include <cstring>

#include <array>
  /**
#include <sstream>
   * Creates view matrix to look from specified position @a eye_pos to specified position @a target_pos
#include "vectorstorm/epsilon.h"
   * @param eye_pos Position of the thing doing the looking
#include "vectorstorm/vector/vector3_forward.h"
   * @param target_pos Position that the view should be aligned to
#include "vectorstorm/vector/vector4_forward.h"
   * @param up_dir Direction of up vector
#include "matrix3_forward.h"
   * @return Resulting view matrix that's looking at the target point
#ifndef VMATH_NO_BOOST
   */
  #include <boost/functional/hash_fwd.hpp>
  inline static matrix4<T> constexpr create_look_at(vector3<T> const &eye_pos, vector3<T> const &target_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
#endif // VMATH_NO_BOOST

    vector3<T> forward(target_pos - eye_pos);
#ifdef VMATH_NAMESPACE
    forward.normalise();
namespace VMATH_NAMESPACE {

#endif
    // Side = forward x up

    vector3<T> side(forward.cross(up_dir));
/**
    side.normalise();
 * Class for matrix 4x4

 * @note Data stored in this matrix are in column major order. This arrangement suits OpenGL.
    // Recompute up as: up = side x forward
 * If you're using row major matrix, consider using fromRowMajorArray as way for construction
    vector3<T> const up = side.cross(forward);
 * matrix4<T> instance.

 */
    return matrix4<T>(static_cast<T>(side.x),
template<typename T>
                      static_cast<T>(up.x),
class matrix4 {
                      static_cast<T>(-forward.x),
public:
                      static_cast<T>(0),
  /// Data stored in column major order

  std::array<T, 16> data;
                      static_cast<T>(side.y),

                      static_cast<T>(up.y),
  //--------------------------[ constructors ]-------------------------------
                      static_cast<T>(-forward.y),
  /**
                      static_cast<T>(0),
   *Creates identity matrix

   */
                      static_cast<T>(side.z),
  inline constexpr matrix4() noexcept __attribute__((__always_inline__))
                      static_cast<T>(up.z),
    : data{1, 0, 0, 0,
                      static_cast<T>(-forward.z),
           0, 1, 0, 0,
                      static_cast<T>(0),
           0, 0, 1, 0,

           0, 0, 0, 1} {
  }
                      static_cast<T>(0),

                      static_cast<T>(0),
  /**
                      static_cast<T>(0),
   * Copy matrix values from array (these data must be in column
                      static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
   * major order!)
  }
   */
  inline static matrix4<T> constexpr createLookAt(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_look_at()"))) {
  inline constexpr explicit matrix4(T const *dt) noexcept __attribute__((__always_inline__))
    return create_look_at(eye_pos, centre_pos, up_dir);
    : data{dt[ 0], dt[ 1], dt[ 2], dt[ 3],
  }
           dt[ 4], dt[ 5], dt[ 6], dt[ 7],

           dt[ 8], dt[ 9], dt[10], dt[11],
  /**
           dt[12], dt[13], dt[14], dt[15]} {
  }
   * Creates OpenGL compatible perspective projection according to specified frustum parameters.
  inline constexpr explicit matrix4(T *dt) noexcept __attribute__((__always_inline__))
   *
    : data{dt[ 0], dt[ 1], dt[ 2], dt[ 3],
   * @param left Specify the coordinate for the left vertical clipping plane,
           dt[ 4], dt[ 5], dt[ 6], dt[ 7],
   * @param right Specify the coordinate for the right vertical clipping plane.
           dt[ 8], dt[ 9], dt[10], dt[11],
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
           dt[12], dt[13], dt[14], dt[15]} {
   * @param top Specify the coordinate for the top horizontal clipping plane.
  }
   * @param near Specify the distance to the near clipping plane.  Distance must be positive.

   * @param far Specify the distance to the far depth clipping plane.  Distance must be positive.
  /**
   * Copy constructor.
   * @return Projection matrix for specified frustum.
   * @param src Data source for new created instance of matrix4.
   */
   */
  inline static matrix4<T> constexpr create_frustum(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) {
  inline constexpr explicit matrix4(matrix4<T> const &src) noexcept __attribute__((__always_inline__))
    /*
    : data{src.data[ 0], src.data[ 1], src.data[ 2], src.data[ 3],
     *    2 near
           src.data[ 4], src.data[ 5], src.data[ 6], src.data[ 7],
     *  ------------       0              A              0
           src.data[ 8], src.data[ 9], src.data[10], src.data[11],
     *  right - left
           src.data[12], src.data[13], src.data[14], src.data[15]} {
     *
  }
     *                  2 near

     *      0         ------------        B              0
  /**
     *                top - bottom
   * Copy casting constructor.
     *
   * @param src Data source for new created instance of matrix4.
   */
     *      0              0              C              D
  template<typename FromT> __attribute__((__always_inline__))
     *
  inline constexpr explicit matrix4(matrix4<FromT> const &src) noexcept
     *      0              0              -1             0
    : data{static_cast<T>(src.data[ 0]), static_cast<T>(src.data[ 1]), static_cast<T>(src.data[ 2]), static_cast<T>(src.data[ 3]),
     *
           static_cast<T>(src.data[ 4]), static_cast<T>(src.data[ 5]), static_cast<T>(src.data[ 6]), static_cast<T>(src.data[ 7]),
     *  A =   (right + left) / (right - left)
           static_cast<T>(src.data[ 8]), static_cast<T>(src.data[ 9]), static_cast<T>(src.data[10]), static_cast<T>(src.data[11]),
     *  B =   (top + bottom) / (top - bottom)
           static_cast<T>(src.data[12]), static_cast<T>(src.data[13]), static_cast<T>(src.data[14]), static_cast<T>(src.data[15])} {
     *  C = - (far + near) / (far - near)
  }
     *  D = - (2 far near) / (far - near)

     */
  /**
    return matrix4<T>((static_cast<T>(2) * near) / (right - left),
   * Move constructor.
                      static_cast<T>(0),
   * @param src Data source for new created instance of matrix4.
                      static_cast<T>(0),
   */
                      static_cast<T>(0),
  inline constexpr matrix4(matrix4<T> &&src) noexcept __attribute__((__always_inline__))

    : data(std::move(src.data)) {
                      static_cast<T>(0),
  }
                      (static_cast<T>(2) * near) / (top - bottom),

                      static_cast<T>(0),
  /**
                      static_cast<T>(0),
   * Move casting constructor.

   * @param src Data source for new created instance of matrix4.
                       (right + left)   / (right - left),
   */
                       (top   + bottom) / (top   - bottom),
  template<typename FromT> __attribute__((__always_inline__))
                      -(far   + near)   / (far   - near),
  inline constexpr matrix4(matrix4<FromT> &&src) noexcept
                      static_cast<T>(-1),
    : data{static_cast<T>(std::move(src.data[ 0])), static_cast<T>(std::move(src.data[ 1])), static_cast<T>(std::move(src.data[ 2])), static_cast<T>(std::move(src.data[ 3])),

           static_cast<T>(std::move(src.data[ 4])), static_cast<T>(std::move(src.data[ 5])), static_cast<T>(std::move(src.data[ 6])), static_cast<T>(std::move(src.data[ 7])),
                      static_cast<T>(0),
           static_cast<T>(std::move(src.data[ 8])), static_cast<T>(std::move(src.data[ 9])), static_cast<T>(std::move(src.data[10])), static_cast<T>(std::move(src.data[11])),
                      static_cast<T>(0),
           static_cast<T>(std::move(src.data[12])), static_cast<T>(std::move(src.data[13])), static_cast<T>(std::move(src.data[14])), static_cast<T>(std::move(src.data[15]))} {
                      (static_cast<T>(-2) * far * near) / (far - near),
  }
                      static_cast<T>(0));

  }
  /**
   * Copy constructor from matrix3.
  inline static matrix4<T> constexpr createFrustum(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_frustum()"))) {
   * @param src Data source for new created instance of matrix4.
    return create_frustum(left, right, bottom, top, near, far);
   */
  }
  /*

  inline constexpr explicit matrix4(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
  /**
    : data{src.data[0],       src.data[1],       src.data[2],       static_cast<T>(0),
   * Creates OpenGL compatible orthographic projection matrix.
           src.data[3],       src.data[4],       src.data[5],       static_cast<T>(0),
   * @param left Specify the coordinate for the left vertical clipping plane,
           src.data[6],       src.data[7],       src.data[8],       static_cast<T>(0),
   * @param right Specify the coordinate for the right vertical clipping plane.
           static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)} {
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane.
  }
   * @param top Specify the coordinate for the top horizontal clipping plane.
  */
   * @param near Specify the distance to the nearer depth clipping plane. This value is negative if the plane is to be behind the viewer.

   * @param far Specify the distance to the farther depth clipping plane. This value is negative if the plane is to be behind the viewer.
  /**
   * @return Othrographic projection matrix.
   * Copy casting constructor from matrix3.
   */
   * @param src Data source for new created instance of matrix4.
  inline static matrix4<T> constexpr create_ortho(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) {
   */
  /*
    /*      2
  template<typename FromT> __attribute__((__always_inline__))
     *  ------------       0              0              tx
  inline constexpr explicit matrix4(matrix3<FromT> const &src) noexcept
     *  right - left
    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]), static_cast<T>(0),
     *                     2
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]), static_cast<T>(0),
     *      0         ------------        0              ty
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8]), static_cast<T>(0),
     *                top - bottom
           static_cast<T>(0),           static_cast<T>(0),           static_cast<T>(0),           static_cast<T>(1)} {
     *                                    -2
  }
     *      0              0         ------------        tz
  */
     *                                far - near

     *
  /**
     *      0              0              0              1
   * Move constructor from matrix3.
     *
   * @param src Data source for new created instance of matrix4.
     *    tx = - (right + left) / (right - left)
   */
     *    ty = - (top + bottom) / (top - bottom)
  /*
     *    tz = - (far + near) / (far - near)
  inline constexpr matrix4(matrix3<T> &&src) noexcept __attribute__((__always_inline__))
     */
    : data{std::move(src.data[0]), std::move(src.data[1]), std::move(src.data[2]), static_cast<T>(0),
    return matrix4<T>(static_cast<T>(2) / (right - left),
           std::move(src.data[3]), std::move(src.data[4]), std::move(src.data[5]), static_cast<T>(0),
                      static_cast<T>(0),
           std::move(src.data[6]), std::move(src.data[7]), std::move(src.data[8]), static_cast<T>(0),
                      static_cast<T>(0),
           static_cast<T>(0),      static_cast<T>(0),      static_cast<T>(0),      static_cast<T>(1)} {
  }
                      static_cast<T>(0),
  */


                      static_cast<T>(0),
  /**
                      static_cast<T>(2) / (top - bottom),
   * Move casting constructor from matrix3.
                      static_cast<T>(0),
   * @param src Data source for new created instance of matrix4.
                      static_cast<T>(0),
   */

  /*
                      static_cast<T>(0),
  template<typename FromT> __attribute__((__always_inline__))
                      static_cast<T>(0),
  inline constexpr matrix4(matrix3<FromT> &&src) noexcept
                      static_cast<T>(-2) / (far - near),
    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])), static_cast<T>(0),
                      static_cast<T>(0),
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])), static_cast<T>(0),

           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8])), static_cast<T>(0),
                      -(right + left)   / (right - left),
           static_cast<T>(0),                      static_cast<T>(0),                      static_cast<T>(0),                      static_cast<T>(1)} {
                      -(top   + bottom) / (top   - bottom),
  }
                      -(far   + near)   / (far   - near),
  */
                      static_cast<T>(1));

  }
  /**
  inline static matrix4<T> constexpr createOrtho(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_ortho()"))) {
   * Variadic initialisation constructor
    return create_ortho(left, right, bottom, top, near, far);
   * @param dt Initialiser list containing raw data for each element in order.
  }
   */

  //inline constexpr explicit matrix4(std::initializer_list<T> dt)
  /**
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
  //}
   * Creates new matrix 4x4 from array that represents such matrix 4x4
  // see http://stackoverflow.com/a/5549918/1678468
   * as array of tightly packed elements in row major order.
  template<typename... FromT> __attribute__((__always_inline__))
   * @param arr An array of elements for 4x4 matrix in row major order.
  inline constexpr explicit matrix4(FromT... dt) noexcept
   * @return An instance of matrix4<T> representing @a arr
    : data{dt...} {
   */
  }
  template<typename FromT> __attribute__((__always_inline__))
  //template<typename... FromT>  __attribute__((__always_inline__))
  inline static matrix4<T> constexpr from_row_major_array(FromT const *arr) noexcept {
  //inline constexpr explicit matrix4(FromT&&... dt)
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(arr[12]),
  //  : data{std::forward<FromT>(dt)...} {
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(arr[13]),
  //}

                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(arr[14]),
  /**
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(arr[15]));
   * Resets matrix to be identity matrix
  }
   */
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
  inline static matrix4<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
    data = {1, 0, 0, 0,
    return from_row_major_array(arr);
            0, 1, 0, 0,
  }
            0, 0, 1, 0,

            0, 0, 0, 1};
  /**
  }
   * Creates new matrix 4x4 from array that represents such matrix 4x4

  /**
   * as array of tightly packed elements in column major order.
   * Creates rotation matrix by rotation around three axes.
   * @param arr An array of elements for 4x4 matrix in column major order.
   * @param xDeg Angle (in degrees) of rotation around axis X.
   * @return An instance of matrix4<T> representing @a arr
   * @param yDeg Angle (in degrees) of rotation around axis Y.
   */
   * @param zDeg Angle (in degrees) of rotation around axis Z.
  template<typename FromT> __attribute__((__always_inline__))
   */
  inline static matrix4<T> constexpr from_column_major_array(FromT const *arr) noexcept {
  inline static matrix4<T> constexpr create_rotation_from_euler_angles(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(static_cast<T>(arr[ 0]), static_cast<T>(arr[ 1]), static_cast<T>(arr[ 2]), static_cast<T>(arr[ 3]),
    return create_rotation_from_euler_angles_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
                      static_cast<T>(arr[ 4]), static_cast<T>(arr[ 5]), static_cast<T>(arr[ 6]), static_cast<T>(arr[ 7]),
  }
                      static_cast<T>(arr[ 8]), static_cast<T>(arr[ 9]), static_cast<T>(arr[10]), static_cast<T>(arr[11]),
  inline static matrix4<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles()"))) {
                      static_cast<T>(arr[12]), static_cast<T>(arr[13]), static_cast<T>(arr[14]), static_cast<T>(arr[15]));
    return create_rotation_from_euler_angles(xDeg, yDeg, zDeg);
  }
  }
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
  inline static matrix4<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles()"))) {
  inline static matrix4<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
    return create_rotation_from_euler_angles(xDeg, yDeg, zDeg);
    return from_column_major_array(arr);
  }
  }


  /**
  /**
   * Creates rotation matrix by rotation around three axes, radian version.
   * Creates new matrix 4x4 from array that represents such matrix 3x4
   * @param xRads Angle (in radians) of rotation around axis X.
   * as array of tightly packed elements in row major order.
   * @param yRads Angle (in radians) of rotation around axis Y.
   * @param arr An array of elements for 3x4 matrix in row major order.
   * @param zRads Angle (in radians) of rotation around axis Z.
   * @return An instance of matrix4<T> representing @a arr
   */
   */
  inline static matrix4<T> constexpr create_rotation_from_euler_angles_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return matrix3<T>::create_rotation_from_euler_angles_rad(xRads, yRads, zRads).get_transform();
  inline static matrix4<T> constexpr from_row_major_34_array(FromT const *arr) noexcept {
  }
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(0),
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles_rad()"))) {
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(0),
    return create_rotation_from_euler_angles_rad(xRads, yRads, zRads);
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(0),
  }
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(1));
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles_rad()"))) {
  }
    return create_rotation_from_euler_angles_rad(xRads, yRads, zRads);

  }

  //---------------------[ Equality operators ]------------------------------
  /**
  /**
   * Creates rotation matrix by rotation around an axis.
   * Equality test operator
   * @param axis Axis to rotate around.
   * @param rhs Right hand side argument of binary operator.
   * @param angle Angle (in degrees) of rotation around axis.
   * @note Test of equality is based of threshold epsilon value. To be two
   */
   * values equal, must satisfy this condition all elements of matrix
  inline static matrix4<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
   * | lhs[i] - rhs[i] | < epsilon,
    return create_rotation_around_axis_rad(axis, deg2rad(angle));
   * same for y-coordinate, z-coordinate, and w-coordinate.
  }
   */
  inline static matrix4<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
  inline bool constexpr operator==(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return create_rotation_around_axis(axis, angle);
    #ifdef VMATH_SOFT_COMPARE
  }
      return std::abs(data[ 0] - rhs.data[ 0]) < epsilon<T> &&

             std::abs(data[ 1] - rhs.data[ 1]) < epsilon<T> &&
  /**
             std::abs(data[ 2] - rhs.data[ 2]) < epsilon<T> &&
   * Creates rotation matrix by rotation around an axis, radian version.
             std::abs(data[ 3] - rhs.data[ 3]) < epsilon<T> &&
   * @param axis Axis to rotate around.
             std::abs(data[ 4] - rhs.data[ 4]) < epsilon<T> &&
   * @param angle Angle (in radians) of rotation around axis.
   */
             std::abs(data[ 5] - rhs.data[ 5]) < epsilon<T> &&
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
             std::abs(data[ 6] - rhs.data[ 6]) < epsilon<T> &&
    return matrix3<T>::create_rotation_around_axis_rad(axis, angle).get_transform();
             std::abs(data[ 7] - rhs.data[ 7]) < epsilon<T> &&
  }
             std::abs(data[ 8] - rhs.data[ 8]) < epsilon<T> &&
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
             std::abs(data[ 9] - rhs.data[ 9]) < epsilon<T> &&
    return create_rotation_around_axis_rad(axis, angle);
             std::abs(data[10] - rhs.data[10]) < epsilon<T> &&
  }
             std::abs(data[11] - rhs.data[11]) < epsilon<T> &&

             std::abs(data[12] - rhs.data[12]) < epsilon<T> &&
  /// Creates translation matrix
             std::abs(data[13] - rhs.data[13]) < epsilon<T> &&
  /**
             std::abs(data[14] - rhs.data[14]) < epsilon<T> &&
   * Creates translation matrix.
             std::abs(data[15] - rhs.data[15]) < epsilon<T>;
   * @param x X-direction translation
    #else
   * @param y Y-direction translation
      return data[ 0] == rhs.data[ 0] &&
   * @param z Z-direction translation
             data[ 1] == rhs.data[ 1] &&
   * @param w for W-coordinate translation (implicitly set to 1)
             data[ 2] == rhs.data[ 2] &&
   */
             data[ 3] == rhs.data[ 3] &&
  inline static matrix4<T> constexpr create_translation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) {
             data[ 4] == rhs.data[ 4] &&
    return matrix4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
             data[ 5] == rhs.data[ 5] &&
                      static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
             data[ 6] == rhs.data[ 6] &&
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
             data[ 7] == rhs.data[ 7] &&
                      x,                 y,                 z,                 w);
             data[ 8] == rhs.data[ 8] &&
  }
             data[ 9] == rhs.data[ 9] &&
  inline static matrix4<T> constexpr createTranslation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_translation()"))) {
             data[10] == rhs.data[10] &&
    return create_translation(x, y, z, w);
             data[11] == rhs.data[11] &&
  }

             data[12] == rhs.data[12] &&
  /**
             data[13] == rhs.data[13] &&
   * Create scale matrix with @a sx, @a sy, and @a sz
             data[14] == rhs.data[14] &&
   * being values of matrix main diagonal.
             data[15] == rhs.data[15];
   * @param sx Scale in X-axis
    #endif // VMATH_SOFT_COMPARE
   * @param sy Scale in Y-axis
  }
   * @param sz Scale in Z-axis

   * @return Transform matrix 4x4 with scale transformation.
  /**
   */
   * Inequality test operator
  inline static matrix4<T> constexpr create_scale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return matrix4<T>(sx,                static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
   * @return not (lhs == rhs) :-P
                      static_cast<T>(0), sy,                static_cast<T>(0), static_cast<T>(0),
   */
                      static_cast<T>(0), static_cast<T>(0), sz,                static_cast<T>(0),
  inline bool constexpr operator!=(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
    return !(*this == rhs);
  }
  }
  inline static matrix4<T> constexpr createScale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_scale()"))) {

    return create_scale(sx, sy, sz);
  //---------------------[ access operators ]---------------------------------
  }
  /**

   * Get reference to element at postion (x,y).
  /**
   * @param x Number of column (0..3)
   * Creates rotation matrix by aligning one vector to another.
   * @param y Number of row (0..3)
   * @param from Vector to rotate from.
   */
   * @param to Vector to rotate to.
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
   * @return An instance of matrix4<T> representing rotation between the two vectors.
    return data[x * 4 + y];
   */
  }
  inline static matrix4<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {

    return matrix3<T>::create_rotation_between_vectors(from, to).get_transform();
  /**
  }
   * Get constant reference to element at position (x,y).

   * @param x Number of column (0..3)
  /**
   * @param y Number of row (0..3)
   * Creates a rotation matrix to align with a target vector direction @a target
   */
   * @param target Vector that the rotation should point at
   * @param up_dir Direction of up vector
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
   * @return Resulting matrix that's oriented to the target vector
    return data[x * 4 + y];
   */
  }
  inline static matrix4<T> constexpr create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {

    return matrix3<T>::create_rotation_aligned_to_vector(target, up_dir).get_transform();
  /**
  }
   * Get reference to element at position (i,j), with math matrix notation

   * @param i Number of row (1..4)
  /**
   * @param j Number of column (1..4)
   * Creates view matrix to look from specified position @a eye_pos to specified position @a target_pos
   */
   * @param eye_pos Position of the thing doing the looking
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
   * @param target_pos Position that the view should be aligned to
    return data[(j - 1) * 4 + i - 1];
   * @param up_dir Direction of up vector
  }
   * @return Resulting view matrix that's looking at the target point

   */
  /**
  inline static matrix4<T> constexpr create_look_at(vector3<T> const &eye_pos, vector3<T> const &target_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
   * Get constant reference to element at position (i,j), with math matrix notation
    vector3<T> forward(target_pos - eye_pos);
   * @param i Number of row (1..4)
    forward.normalise();
   * @param j Number of column (1..4)

   */
    // Side = forward x up
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
    vector3<T> side(forward.cross(up_dir));
    return data[(j - 1) * 4 + i - 1];
    side.normalise();
  }


    // Recompute up as: up = side x forward
  /**
    vector3<T> const up = side.cross(forward);

   * Sets translation part of matrix.
    return matrix4<T>(static_cast<T>(side.x),
   *
                      static_cast<T>(up.x),
   * @param v Vector of translation to be set.
                      static_cast<T>(-forward.x),
   */
                      static_cast<T>(0),
  inline void constexpr set_translation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {

    data[12] = v.x;
                      static_cast<T>(side.y),
    data[13] = v.y;
                      static_cast<T>(up.y),
    data[14] = v.z;
                      static_cast<T>(-forward.y),
    data[15] = 1;
                      static_cast<T>(0),
  }

  inline void constexpr setTranslation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_translation()"))) {
                      static_cast<T>(side.z),
    set_translation(v);
                      static_cast<T>(up.z),
  }
                      static_cast<T>(-forward.z),

                      static_cast<T>(0),

  /**
                      static_cast<T>(0),
   * Returns translation part of matrix.
                      static_cast<T>(0),
   */
                      static_cast<T>(0),
  inline vector3<T> constexpr get_translation() const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
    return vector3<T>(data[12], data[13], data[14]);
  }
  }
  inline static matrix4<T> constexpr createLookAt(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_look_at()"))) {
  inline vector3<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_translation()"))) {
    return create_look_at(eye_pos, centre_pos, up_dir);
    return get_translation();
  }
  }


  /**
  /**
   * Creates OpenGL compatible perspective projection according to specified frustum parameters.
   * Sets rotation part (matrix 3x3) of matrix.
   *
   *
   * @param left Specify the coordinate for the left vertical clipping plane,
   * @param m Rotation part of matrix
   * @param right Specify the coordinate for the right vertical clipping plane.
   */
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
  inline void constexpr set_rotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
   * @param top Specify the coordinate for the top horizontal clipping plane.
    data[ 0] = m.data[0];
   * @param near Specify the distance to the near clipping plane.  Distance must be positive.
    data[ 1] = m.data[1];
   * @param far Specify the distance to the far depth clipping plane.  Distance must be positive.
    data[ 2] = m.data[2];
   * @return Projection matrix for specified frustum.
    data[ 4] = m.data[3];
   */
    data[ 5] = m.data[4];
  inline static matrix4<T> constexpr create_frustum(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) {
    data[ 6] = m.data[5];
    /*
    data[ 8] = m.data[6];
     *    2 near
    data[ 9] = m.data[7];
     *  ------------       0              A              0
    data[10] = m.data[8];
     *  right - left
  }
     *
  inline void constexpr setRotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_rotation()"))) {
     *                  2 near
    set_rotation(m);
     *      0         ------------        B              0
  }
     *                top - bottom

     *
  /**
     *      0              0              C              D
     *
   * Returns rotation (matrix 3x3) part of matrix.
     *      0              0              -1             0
   */
     *
  inline matrix3<T> constexpr get_rotation() const noexcept __attribute__((__always_inline__)) {
     *  A =   (right + left) / (right - left)
    return matrix3<T>(data[ 0], data[ 1], data[ 2],
     *  B =   (top + bottom) / (top - bottom)
                      data[ 4], data[ 5], data[ 6],
     *  C = - (far + near) / (far - near)
                      data[ 8], data[ 9], data[10]);
     *  D = - (2 far near) / (far - near)
  }
     */
  inline matrix3<T> constexpr getRotation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_rotation()"))) {
    return matrix4<T>((static_cast<T>(2) * near) / (right - left),
    return get_rotation();
                      static_cast<T>(0),
  }
                      static_cast<T>(0),

                      static_cast<T>(0),
  /**

   * Copy operator
                      static_cast<T>(0),
   * @param rhs Right hand side argument of binary operator.
                      (static_cast<T>(2) * near) / (top - bottom),
   */
                      static_cast<T>(0),
                      static_cast<T>(0),
  inline matrix4<T> constexpr &operator=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    //std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 16);
                       (right + left)   / (right - left),
    data = rhs.data;
                       (top   + bottom) / (top   - bottom),
    return *this;
                      -(far   + near)   / (far   - near),
  }
                      static_cast<T>(-1),


  /**
                      static_cast<T>(0),
   * Copy casting operator
                      static_cast<T>(0),
   * @param rhs Right hand side argument of binary operator.
                      (static_cast<T>(-2) * far * near) / (far - near),
   */
                      static_cast<T>(0));
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline matrix4<T> constexpr &operator=(matrix4<FromT> const &rhs) noexcept {
  inline static matrix4<T> constexpr createFrustum(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_frustum()"))) {
    data[ 0] = static_cast<T>(rhs.data[ 0]);
    return create_frustum(left, right, bottom, top, near, far);
    data[ 1] = static_cast<T>(rhs.data[ 1]);
  }
    data[ 2] = static_cast<T>(rhs.data[ 2]);

    data[ 3] = static_cast<T>(rhs.data[ 3]);
  /**
    data[ 4] = static_cast<T>(rhs.data[ 4]);
   * Creates OpenGL compatible orthographic projection matrix.
    data[ 5] = static_cast<T>(rhs.data[ 5]);
   * @param left Specify the coordinate for the left vertical clipping plane,
    data[ 6] = static_cast<T>(rhs.data[ 6]);
   * @param right Specify the coordinate for the right vertical clipping plane.
    data[ 7] = static_cast<T>(rhs.data[ 7]);
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane.
    data[ 8] = static_cast<T>(rhs.data[ 8]);
   * @param top Specify the coordinate for the top horizontal clipping plane.
    data[ 9] = static_cast<T>(rhs.data[ 9]);
   * @param near Specify the distance to the nearer depth clipping plane. This value is negative if the plane is to be behind the viewer.
    data[10] = static_cast<T>(rhs.data[10]);
   * @param far Specify the distance to the farther depth clipping plane. This value is negative if the plane is to be behind the viewer.
    data[11] = static_cast<T>(rhs.data[11]);
   * @return Othrographic projection matrix.
    data[12] = static_cast<T>(rhs.data[12]);
   */
    data[13] = static_cast<T>(rhs.data[13]);
  inline static matrix4<T> constexpr create_ortho(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) {
    data[14] = static_cast<T>(rhs.data[14]);
    /*      2
    data[15] = static_cast<T>(rhs.data[15]);
     *  ------------       0              0              tx
    return *this;
     *  right - left
  }
     *                     2

     *      0         ------------        0              ty
  /**
     *                top - bottom
   * Copy operator
     *                                    -2
   * @param rhs Right hand side argument of binary operator.
     *      0              0         ------------        tz
   */
     *                                far - near
     *
  inline matrix4<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
     *      0              0              0              1
    /*
     *
    for(int i = 0; i != 16; ++i) {
     *    tx = - (right + left) / (right - left)
      data[i] = (T)rhs[i];
     *    ty = - (top + bottom) / (top - bottom)
    }
     *    tz = - (far + near) / (far - near)
    */
     */
    std::memcpy(data.data(), rhs, sizeof(T) * 16);
    return matrix4<T>(static_cast<T>(2) / (right - left),
    return *this;
                      static_cast<T>(0),
  }
                      static_cast<T>(0),

                      static_cast<T>(0),
  /**

   * Move assignment operator
                      static_cast<T>(0),
   * @param rhs Right hand side argument of binary operator.
                      static_cast<T>(2) / (top - bottom),
   */
                      static_cast<T>(0),
  inline matrix4<T> constexpr &operator=(matrix4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0),
    data = std::move(rhs.data);

    return *this;
                      static_cast<T>(0),
  }
                      static_cast<T>(0),

                      static_cast<T>(-2) / (far - near),
  /**
                      static_cast<T>(0),

   * Move assignment casting operator
                      -(right + left)   / (right - left),
   * @param rhs Right hand side argument of binary operator.
                      -(top   + bottom) / (top   - bottom),
   */
                      -(far   + near)   / (far   - near),
  template<typename FromT> __attribute__((__always_inline__))
                      static_cast<T>(1));
  inline matrix4<T> constexpr &operator=(matrix4<FromT> &&rhs) noexcept {
  }
    data[ 0] = static_cast<T>(std::move(rhs.data[ 0]));
  inline static matrix4<T> constexpr createOrtho(T left, T right, T bottom, T top, T near, T far) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_ortho()"))) {
    data[ 1] = static_cast<T>(std::move(rhs.data[ 1]));
    return create_ortho(left, right, bottom, top, near, far);
    data[ 2] = static_cast<T>(std::move(rhs.data[ 2]));
  }
    data[ 3] = static_cast<T>(std::move(rhs.data[ 3]));

    data[ 4] = static_cast<T>(std::move(rhs.data[ 4]));
  /**
    data[ 5] = static_cast<T>(std::move(rhs.data[ 5]));
   * Creates new matrix 4x4 from array that represents such matrix 4x4
    data[ 6] = static_cast<T>(std::move(rhs.data[ 6]));
   * as array of tightly packed elements in row major order.
    data[ 7] = static_cast<T>(std::move(rhs.data[ 7]));
   * @param arr An array of elements for 4x4 matrix in row major order.
    data[ 8] = static_cast<T>(std::move(rhs.data[ 8]));
   * @return An instance of matrix4<T> representing @a arr
    data[ 9] = static_cast<T>(std::move(rhs.data[ 9]));
   */
    data[10] = static_cast<T>(std::move(rhs.data[10]));
  template<typename FromT> __attribute__((__always_inline__))
    data[11] = static_cast<T>(std::move(rhs.data[11]));
  inline static matrix4<T> constexpr from_row_major_array(FromT const *arr) noexcept {
    data[12] = static_cast<T>(std::move(rhs.data[12]));
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(arr[12]),
    data[13] = static_cast<T>(std::move(rhs.data[13]));
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(arr[13]),
    data[14] = static_cast<T>(std::move(rhs.data[14]));
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(arr[14]),
    data[15] = static_cast<T>(std::move(rhs.data[15]));
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(arr[15]));
    return *this;
  }
  }
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))

  inline static matrix4<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
  //--------------------[ matrix with matrix operations ]---------------------
    return from_row_major_array(arr);
  /**
  }
   * Addition operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Creates new matrix 4x4 from array that represents such matrix 4x4
  inline matrix4<T> constexpr operator+(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * as array of tightly packed elements in column major order.
   * @param arr An array of elements for 4x4 matrix in column major order.
    return matrix4<T>(data[ 0] + rhs.data[ 0], data[ 1] + rhs.data[ 1], data[ 2] + rhs.data[ 2], data[ 3] + rhs.data[ 3],
   * @return An instance of matrix4<T> representing @a arr
                      data[ 4] + rhs.data[ 4], data[ 5] + rhs.data[ 5], data[ 6] + rhs.data[ 6], data[ 7] + rhs.data[ 7],
   */
                      data[ 8] + rhs.data[ 8], data[ 9] + rhs.data[ 9], data[10] + rhs.data[10], data[11] + rhs.data[11],
  template<typename FromT> __attribute__((__always_inline__))
                      data[12] + rhs.data[12], data[13] + rhs.data[13], data[14] + rhs.data[14], data[15] + rhs.data[15]);
  inline static matrix4<T> constexpr from_column_major_array(FromT const *arr) noexcept {
  }
    return matrix4<T>(static_cast<T>(arr[ 0]), static_cast<T>(arr[ 1]), static_cast<T>(arr[ 2]), static_cast<T>(arr[ 3]),

                      static_cast<T>(arr[ 4]), static_cast<T>(arr[ 5]), static_cast<T>(arr[ 6]), static_cast<T>(arr[ 7]),
  /**
                      static_cast<T>(arr[ 8]), static_cast<T>(arr[ 9]), static_cast<T>(arr[10]), static_cast<T>(arr[11]),
   * Subtraction operator
                      static_cast<T>(arr[12]), static_cast<T>(arr[13]), static_cast<T>(arr[14]), static_cast<T>(arr[15]));
   * @param rhs Right hand side argument of binary operator.
  }
   */
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
  inline matrix4<T> constexpr operator-(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline static matrix4<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
    return matrix4<T>(data[ 0] - rhs.data[ 0], data[ 1] - rhs.data[ 1], data[ 2] - rhs.data[ 2], data[ 3] - rhs.data[ 3],
    return from_column_major_array(arr);
                      data[ 4] - rhs.data[ 4], data[ 5] - rhs.data[ 5], data[ 6] - rhs.data[ 6], data[ 7] - rhs.data[ 7],
  }
                      data[ 8] - rhs.data[ 8], data[ 9] - rhs.data[ 9], data[10] - rhs.data[10], data[11] - rhs.data[11],

  /**
                      data[12] - rhs.data[12], data[13] - rhs.data[13], data[14] - rhs.data[14], data[15] - rhs.data[15]);
   * Creates new matrix 4x4 from array that represents such matrix 3x4
  }
   * as array of tightly packed elements in row major order.

   * @param arr An array of elements for 3x4 matrix in row major order.
  //--------------------[ matrix with scalar operations ]---------------------
   * @return An instance of matrix4<T> representing @a arr
  /**
   */
   * Addition operator
  template<typename FromT> __attribute__((__always_inline__))
   * @param rhs Right hand side argument of binary operator.
  inline static matrix4<T> constexpr from_row_major_34_array(FromT const *arr) noexcept {
   */
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(0),
  inline matrix4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(0),
    return matrix4<T>(data[ 0] + rhs, data[ 1] + rhs, data[ 2] + rhs, data[ 3] + rhs,
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(0),
                      data[ 4] + rhs, data[ 5] + rhs, data[ 6] + rhs, data[ 7] + rhs,
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(1));
                      data[ 8] + rhs, data[ 9] + rhs, data[10] + rhs, data[11] + rhs,
  }
                      data[12] + rhs, data[13] + rhs, data[14] + rhs, data[15] + rhs);

  }
  //---------------------[ Equality operators ]------------------------------

  /**
  /**
   * Equality test operator
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   * @note Test of equality is based of threshold epsilon value. To be two
   */
   * values equal, must satisfy this condition all elements of matrix
  inline matrix4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
   * | lhs[i] - rhs[i] | < epsilon,
    return matrix4<T>(data[ 0] - rhs, data[ 1] - rhs, data[ 2] - rhs, data[ 3] - rhs,
   * same for y-coordinate, z-coordinate, and w-coordinate.
   */
                      data[ 4] - rhs, data[ 5] - rhs, data[ 6] - rhs, data[ 7] - rhs,
  inline bool constexpr operator==(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                      data[ 8] - rhs, data[ 9] - rhs, data[10] - rhs, data[11] - rhs,
    #ifdef VMATH_SOFT_COMPARE
                      data[12] - rhs, data[13] - rhs, data[14] - rhs, data[15] - rhs);
      return std::abs(data[ 0] - rhs.data[ 0]) < epsilon<T> &&
  }
             std::abs(data[ 1] - rhs.data[ 1]) < epsilon<T> &&

             std::abs(data[ 2] - rhs.data[ 2]) < epsilon<T> &&
  /**
             std::abs(data[ 3] - rhs.data[ 3]) < epsilon<T> &&
   * Multiplication operator
             std::abs(data[ 4] - rhs.data[ 4]) < epsilon<T> &&
   * @param rhs Right hand side argument of binary operator.
             std::abs(data[ 5] - rhs.data[ 5]) < epsilon<T> &&
   */
             std::abs(data[ 6] - rhs.data[ 6]) < epsilon<T> &&
  inline matrix4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
             std::abs(data[ 7] - rhs.data[ 7]) < epsilon<T> &&
    return matrix4<T>(data[ 0] * rhs, data[ 1] * rhs, data[ 2] * rhs, data[ 3] * rhs,
             std::abs(data[ 8] - rhs.data[ 8]) < epsilon<T> &&
                      data[ 4] * rhs, data[ 5] * rhs, data[ 6] * rhs, data[ 7] * rhs,
             std::abs(data[ 9] - rhs.data[ 9]) < epsilon<T> &&
                      data[ 8] * rhs, data[ 9] * rhs, data[10] * rhs, data[11] * rhs,
             std::abs(data[10] - rhs.data[10]) < epsilon<T> &&
                      data[12] * rhs, data[13] * rhs, data[14] * rhs, data[15] * rhs);
             std::abs(data[11] - rhs.data[11]) < epsilon<T> &&
  }
             std::abs(data[12] - rhs.data[12]) < epsilon<T> &&

             std::abs(data[13] - rhs.data[13]) < epsilon<T> &&
  /**
             std::abs(data[14] - rhs.data[14]) < epsilon<T> &&
   * Division operator
             std::abs(data[15] - rhs.data[15]) < epsilon<T>;
   * @param rhs Right hand side argument of binary operator.
    #else
   */
      return data[ 0] == rhs.data[ 0] &&
  inline matrix4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
             data[ 1] == rhs.data[ 1] &&
             data[ 2] == rhs.data[ 2] &&
    return matrix4<T>(data[ 0] / rhs, data[ 1] / rhs, data[ 2] / rhs, data[ 3] / rhs,
             data[ 3] == rhs.data[ 3] &&
                      data[ 4] / rhs, data[ 5] / rhs, data[ 6] / rhs, data[ 7] / rhs,
             data[ 4] == rhs.data[ 4] &&
                      data[ 8] / rhs, data[ 9] / rhs, data[10] / rhs, data[11] / rhs,
             data[ 5] == rhs.data[ 5] &&
                      data[12] / rhs, data[13] / rhs, data[14] / rhs, data[15] / rhs);
             data[ 6] == rhs.data[ 6] &&
  }
             data[ 7] == rhs.data[ 7] &&

             data[ 8] == rhs.data[ 8] &&
  /**
             data[ 9] == rhs.data[ 9] &&
   * Addition operator
             data[10] == rhs.data[10] &&
   * @param rhs Right hand side argument of binary operator.
             data[11] == rhs.data[11] &&
   */
             data[12] == rhs.data[12] &&
  inline matrix4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
             data[13] == rhs.data[13] &&
    *this = *this + rhs;
             data[14] == rhs.data[14] &&
    return *this;
             data[15] == rhs.data[15];
  }
    #endif // VMATH_SOFT_COMPARE

  }

  /**
  /**
   * Subtraction operator
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   * @return not (lhs == rhs) :-P
  inline matrix4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    *this = *this - rhs;
  inline bool constexpr operator!=(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return *this;
    return !(*this == rhs);
  }
  }


  /**
  //---------------------[ access operators ]---------------------------------
   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Get reference to element at postion (x,y).
   */
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
  inline matrix4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    *this = *this * rhs;
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
    return *this;
    return data[x * 4 + y];
  }
  }


  /**
  /**
   * Division operator
   * Get constant reference to element at position (x,y).
   * @param rhs Right hand side argument of binary operator.
   * @param x Number of column (0..3)
   */
   * @param y Number of row (0..3)
  inline matrix4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    *this = *this / rhs;
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
    return *this;
    return data[x * 4 + y];
  }
  }


  /**
  //--------------------[ multiply operators ]--------------------------------
   * Get reference to element at position (i,j), with math matrix notation
  /**
   * @param i Number of row (1..4)
   * Multiplication operator
   * @param j Number of column (1..4)
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 4 + i - 1];
    return vector4<T>(data[0] * rhs.x + data[4] * rhs.y + data[ 8] * rhs.z + data[12] * rhs.w,
  }
                      data[1] * rhs.x + data[5] * rhs.y + data[ 9] * rhs.z + data[13] * rhs.w,

                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z + data[14] * rhs.w,
  /**
                      data[3] * rhs.x + data[7] * rhs.y + data[11] * rhs.z + data[15] * rhs.w);
   * Get constant reference to element at position (i,j), with math matrix notation
  }
   * @param i Number of row (1..4)

   * @param j Number of column (1..4)
  /**
   */
   * Multiplication operator
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return data[(j - 1) * 4 + i - 1];
   */
  }

  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return vector3<T>(data[0] * rhs.x + data[4] * rhs.y + data[8]  * rhs.z,
   * Sets translation part of matrix.
                      data[1] * rhs.x + data[5] * rhs.y + data[9]  * rhs.z,
   *
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z);
   * @param v Vector of translation to be set.
  }
   */

  inline void constexpr set_translation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {
  /**
    data[12] = v.x;
   * Multiplication operator
    data[13] = v.y;
   * @param rhs Right hand side argument of binary operator.
    data[14] = v.z;
   */
    data[15] = 1;
  inline matrix4<T> constexpr operator*(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return matrix4<T>(rhs.data[ 0] * data[ 0] + rhs.data[ 1] * data[ 4] + rhs.data[ 2] * data[ 8] + rhs.data[ 3] * data[12],
  inline void constexpr setTranslation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_translation()"))) {
    set_translation(v);
                      rhs.data[ 0] * data[ 1] + rhs.data[ 1] * data[ 5] + rhs.data[ 2] * data[ 9] + rhs.data[ 3] * data[13],
  }
                      rhs.data[ 0] * data[ 2] + rhs.data[ 1] * data[ 6] + rhs.data[ 2] * data[10] + rhs.data[ 3] * data[14],

                      rhs.data[ 0] * data[ 3] + rhs.data[ 1] * data[ 7] + rhs.data[ 2] * data[11] + rhs.data[ 3] * data[15],
  /**

   * Returns translation part of matrix.
                      rhs.data[ 4] * data[ 0] + rhs.data[ 5] * data[ 4] + rhs.data[ 6] * data[ 8] + rhs.data[ 7] * data[12],
   */
  inline vector3<T> constexpr get_translation() const noexcept __attribute__((__always_inline__)) {
                      rhs.data[ 4] * data[ 1] + rhs.data[ 5] * data[ 5] + rhs.data[ 6] * data[ 9] + rhs.data[ 7] * data[13],
    return vector3<T>(data[12], data[13], data[14]);
                      rhs.data[ 4] * data[ 2] + rhs.data[ 5] * data[ 6] + rhs.data[ 6] * data[10] + rhs.data[ 7] * data[14],
  }
                      rhs.data[ 4] * data[ 3] + rhs.data[ 5] * data[ 7] + rhs.data[ 6] * data[11] + rhs.data[ 7] * data[15],
  inline vector3<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_translation()"))) {

    return get_translation();
                      rhs.data[ 8] * data[ 0] + rhs.data[ 9] * data[ 4] + rhs.data[10] * data[ 8] + rhs.data[11] * data[12],
  }
                      rhs.data[ 8] * data[ 1] + rhs.data[ 9] * data[ 5] + rhs.data[10] * data[ 9] + rhs.data[11] * data[13],

                      rhs.data[ 8] * data[ 2] + rhs.data[ 9] * data[ 6] + rhs.data[10] * data[10] + rhs.data[11] * data[14],
  /**
                      rhs.data[ 8] * data[ 3] + rhs.data[ 9] * data[ 7] + rhs.data[10] * data[11] + rhs.data[11] * data[15],
   * Sets rotation part (matrix 3x3) of matrix.

   *
   * @param m Rotation part of matrix
                      rhs.data[12] * data[ 0] + rhs.data[13] * data[ 4] + rhs.data[14] * data[ 8] + rhs.data[15] * data[12],
   */
                      rhs.data[12] * data[ 1] + rhs.data[13] * data[ 5] + rhs.data[14] * data[ 9] + rhs.data[15] * data[13],
  inline void constexpr set_rotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
                      rhs.data[12] * data[ 2] + rhs.data[13] * data[ 6] + rhs.data[14] * data[10] + rhs.data[15] * data[14],
    data[ 0] = m.data[0];
                      rhs.data[12] * data[ 3] + rhs.data[13] * data[ 7] + rhs.data[14] * data[11] + rhs.data[15] * data[15]);
    data[ 1] = m.data[1];
  }
    data[ 2] = m.data[2];

    data[ 4] = m.data[3];
  /**
    data[ 5] = m.data[4];
   * Multiplication operator
    data[ 6] = m.data[5];
   * @param rhs Right hand side argument of binary operator.
    data[ 8] = m.data[6];
   */
    data[ 9] = m.data[7];
    data[10] = m.data[8];
  inline matrix4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    *this = *this * rhs;
  inline void constexpr setRotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_rotation()"))) {
    return *this;
    set_rotation(m);
  }
  }


  //---------------------------[ misc operations ]----------------------------
  /**

   * Returns rotation (matrix 3x3) part of matrix.
  /**
   */
   * Computes determinant of matrix
  inline matrix3<T> constexpr get_rotation() const noexcept __attribute__((__always_inline__)) {
   * @return Determinant of matrix
    return matrix3<T>(data[ 0], data[ 1], data[ 2],
   * @note This function does 3 * 4 * 6 mul, 3 * 6 add.
                      data[ 4], data[ 5], data[ 6],
   */
                      data[ 8], data[ 9], data[10]);
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
  }
    return   data[12] * data[9] * data[6]  * data[3]  - data[8] * data[13] * data[6]  * data[3]
  inline matrix3<T> constexpr getRotation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_rotation()"))) {
           - data[12] * data[5] * data[10] * data[3]  + data[4] * data[13] * data[10] * data[3]
    return get_rotation();

  }

           + data[8]  * data[5] * data[14] * data[3]  - data[4] * data[9]  * data[14] * data[3]
  /**
           - data[12] * data[9] * data[2]  * data[7]  + data[8] * data[13] * data[2]  * data[7]
   * Copy operator

   * @param rhs Right hand side argument of binary operator.
           + data[12] * data[1] * data[10] * data[7]  - data[0] * data[13] * data[10] * data[7]
   */
           - data[8]  * data[1] * data[14] * data[7]  + data[0] * data[9]  * data[14] * data[7]
  inline matrix4<T> constexpr &operator=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {

    //std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 16);
           + data[12] * data[5] * data[2]  * data[11] - data[4] * data[13] * data[2]  * data[11]
    data = rhs.data;
           - data[12] * data[1] * data[6]  * data[11] + data[0] * data[13] * data[6]  * data[11]
    return *this;

  }

           + data[4]  * data[1] * data[14] * data[11] - data[0] * data[5]  * data[14] * data[11]
  /**
           - data[8]  * data[5] * data[2]  * data[15] + data[4] * data[9]  * data[2]  * data[15]
   * Copy casting operator

   * @param rhs Right hand side argument of binary operator.
           + data[8]  * data[1] * data[6]  * data[15] - data[0] * data[9]  * data[6]  * data[15]
   */
           - data[4]  * data[1] * data[10] * data[15] + data[0] * data[5]  * data[10] * data[15];
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline matrix4<T> constexpr &operator=(matrix4<FromT> const &rhs) noexcept {

    data[ 0] = static_cast<T>(rhs.data[ 0]);
  /**
    data[ 1] = static_cast<T>(rhs.data[ 1]);
   * Computes inverse matrix
    data[ 2] = static_cast<T>(rhs.data[ 2]);
   * @return Inverse matrix of this matrix.
    data[ 3] = static_cast<T>(rhs.data[ 3]);
   * @note This is a little bit time consuming operation
    data[ 4] = static_cast<T>(rhs.data[ 4]);
   * (16 * 6 * 3 mul, 16 * 5 add + det() + mul() functions)
    data[ 5] = static_cast<T>(rhs.data[ 5]);
   */
    data[ 6] = static_cast<T>(rhs.data[ 6]);
    data[ 7] = static_cast<T>(rhs.data[ 7]);
  inline matrix4<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
    data[ 8] = static_cast<T>(rhs.data[ 8]);
    return matrix4<T>(data[9]  * data[14] * data[7]  - data[13] * data[10] * data[7]  + data[13] * data[6]  * data[11] -
    data[ 9] = static_cast<T>(rhs.data[ 9]);
                      data[5]  * data[14] * data[11] - data[9]  * data[6]  * data[15] + data[5]  * data[10] * data[15],
    data[10] = static_cast<T>(rhs.data[10]);
                      data[13] * data[10] * data[3]  - data[9]  * data[14] * data[3]  - data[13] * data[2]  * data[11] +
    data[11] = static_cast<T>(rhs.data[11]);
                      data[1]  * data[14] * data[11] + data[9]  * data[2]  * data[15] - data[1]  * data[10] * data[15],
    data[12] = static_cast<T>(rhs.data[12]);
                      data[5]  * data[14] * data[3]  - data[13] * data[6]  * data[3]  + data[13] * data[2]  * data[7] -
    data[13] = static_cast<T>(rhs.data[13]);
    data[14] = static_cast<T>(rhs.data[14]);
                      data[1]  * data[14] * data[7]  - data[5]  * data[2]  * data[15] + data[1]  * data[6]  * data[15],
    data[15] = static_cast<T>(rhs.data[15]);
                      data[9]  * data[6]  * data[3]  - data[5]  * data[10] * data[3]  - data[9]  * data[2]  * data[7] +
    return *this;
                      data[1]  * data[10] * data[7]  + data[5]  * data[2]  * data[11] - data[1]  * data[6]  * data[11],
  }
                      data[12] * data[10] * data[7]  - data[8]  * data[14] * data[7]  - data[12] * data[6]  * data[11] +

                      data[4]  * data[14] * data[11] + data[8]  * data[6]  * data[15] - data[4]  * data[10] * data[15],
  /**
                      data[8]  * data[14] * data[3]  - data[12] * data[10] * data[3]  + data[12] * data[2]  * data[11] -
   * Copy operator
                      data[0]  * data[14] * data[11] - data[8]  * data[2]  * data[15] + data[0]  * data[10] * data[15],
   * @param rhs Right hand side argument of binary operator.
   */
                      data[12] * data[6]  * data[3]  - data[4]  * data[14] * data[3]  - data[12] * data[2]  * data[7] +
  inline matrix4<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
                      data[0]  * data[14] * data[7]  + data[4]  * data[2]  * data[15] - data[0]  * data[6]  * data[15],
    /*
                      data[4]  * data[10] * data[3]  - data[8]  * data[6]  * data[3]  + data[8]  * data[2]  * data[7] -
    for(int i = 0; i != 16; ++i) {
                      data[0]  * data[10] * data[7]  - data[4]  * data[2]  * data[11] + data[0]  * data[6]  * data[11],
      data[i] = (T)rhs[i];
                      data[8]  * data[13] * data[7]  - data[12] * data[9]  * data[7]  + data[12] * data[5]  * data[11] -
    }
                      data[4]  * data[13] * data[11] - data[8]  * data[5]  * data[15] + data[4]  * data[9]  * data[15],
    */
                      data[12] * data[9]  * data[3]  - data[8]  * data[13] * data[3]  - data[12] * data[1]  * data[11] +
    std::memcpy(data.data(), rhs, sizeof(T) * 16);
                      data[0]  * data[13] * data[11] + data[8]  * data[1]  * data[15] - data[0]  * data[9]  * data[15],
    return *this;
  }
                      data[4]  * data[13] * data[3]  - data[12] * data[5]  * data[3]  + data[12] * data[1]  * data[7] -

                      data[0]  * data[13] * data[7]  - data[4]  * data[1]  * data[15] + data[0]  * data[5]  * data[15],
  /**
                      data[8]  * data[5]  * data[3]  - data[4]  * data[9]  * data[3]  - data[8]  * data[1]  * data[7] +
   * Move assignment operator
                      data[0]  * data[9]  * data[7]  + data[4]  * data[1]  * data[11] - data[0]  * data[5]  * data[11],
   * @param rhs Right hand side argument of binary operator.
                      data[12] * data[9]  * data[6]  - data[8]  * data[13] * data[6]  - data[12] * data[5]  * data[10] +
   */
                      data[4]  * data[13] * data[10] + data[8]  * data[5]  * data[14] - data[4]  * data[9]  * data[14],
  inline matrix4<T> constexpr &operator=(matrix4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
                      data[8]  * data[13] * data[2]  - data[12] * data[9]  * data[2]  + data[12] * data[1]  * data[10] -
    data = std::move(rhs.data);
                      data[0]  * data[13] * data[10] - data[8]  * data[1]  * data[14] + data[0]  * data[9]  * data[14],
    return *this;
  }
                      data[12] * data[5]  * data[2]  - data[4]  * data[13] * data[2]  - data[12] * data[1]  * data[6] +

                      data[0]  * data[13] * data[6]  + data[4]  * data[1]  * data[14] - data[0]  * data[5]  * data[14],
  /**
                      data[4]  * data[9]  * data[2]  - data[8]  * data[5]  * data[2]  + data[8]  * data[1]  * data[6] -
   * Move assignment casting operator
                      data[0]  * data[9]  * data[6]  - data[4]  * data[1]  * data[10] + data[0]  * data[5]  * data[10]) / det();
   * @param rhs Right hand side argument of binary operator.
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline matrix4<T> constexpr &operator=(matrix4<FromT> &&rhs) noexcept {
   * Transpose matrix.
    data[ 0] = static_cast<T>(std::move(rhs.data[ 0]));
   */
    data[ 1] = static_cast<T>(std::move(rhs.data[ 1]));
  inline matrix4<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
    data[ 2] = static_cast<T>(std::move(rhs.data[ 2]));
    return matrix4<T>(data[0], data[4], data[8],  data[12],
    data[ 3] = static_cast<T>(std::move(rhs.data[ 3]));
    data[ 4] = static_cast<T>(std::move(rhs.data[ 4]));
                      data[1], data[5], data[9],  data[13],
    data[ 5] = static_cast<T>(std::move(rhs.data[ 5]));
                      data[2], data[6], data[10], data[14],
    data[ 6] = static_cast<T>(std::move(rhs.data[ 6]));
                      data[3], data[7], data[11], data[15]);
    data[ 7] = static_cast<T>(std::move(rhs.data[ 7]));
  }
    data[ 8] = static_cast<T>(std::move(rhs.data[ 8]));

    data[ 9] = static_cast<T>(std::move(rhs.data[ 9]));
  /**
    data[10] = static_cast<T>(std::move(rhs.data[10]));
   * Linear interpolation of two matrices
    data[11] = static_cast<T>(std::move(rhs.data[11]));
   * @param fact Factor of interpolation. For translation from positon
    data[12] = static_cast<T>(std::move(rhs.data[12]));
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.
    data[13] = static_cast<T>(std::move(rhs.data[13]));
   * @param rhs Second matrix for interpolation
    data[14] = static_cast<T>(std::move(rhs.data[14]));
   * @note However values of fact parameter are reasonable only in interval
    data[15] = static_cast<T>(std::move(rhs.data[15]));
   * [0.0 , 1.0], you can pass also values outside of this interval and you
    return *this;
   * can get result (extrapolation?)
  }
   */

  inline matrix4<T> constexpr lerp(T fact, matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  //--------------------[ matrix with matrix operations ]---------------------
  /**
    return (*this) + (rhs - (*this)) * fact;
   * Addition operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  //-------------[ conversion ]-----------------------------
  inline matrix4<T> constexpr operator+(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return matrix4<T>(data[ 0] + rhs.data[ 0], data[ 1] + rhs.data[ 1], data[ 2] + rhs.data[ 2], data[ 3] + rhs.data[ 3],
   * Conversion to pointer operator
                      data[ 4] + rhs.data[ 4], data[ 5] + rhs.data[ 5], data[ 6] + rhs.data[ 6], data[ 7] + rhs.data[ 7],
   * @return Pointer to internally stored (in management of class matrix4<T>)
                      data[ 8] + rhs.data[ 8], data[ 9] + rhs.data[ 9], data[10] + rhs.data[10], data[11] + rhs.data[11],
   * used for passing matrix4<T> values to gl*[fd]v functions.
                      data[12] + rhs.data[12], data[13] + rhs.data[13], data[14] + rhs.data[14], data[15] + rhs.data[15]);
   */
  }
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {

    return reinterpret_cast<T*>(data.data());
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Conversion to pointer operator
  inline matrix4<T> constexpr operator-(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @return Constant Pointer to internally stored (in management of class matrix4<T>)
    return matrix4<T>(data[ 0] - rhs.data[ 0], data[ 1] - rhs.data[ 1], data[ 2] - rhs.data[ 2], data[ 3] - rhs.data[ 3],
   * used for passing matrix4<T> values to gl*[fd]v functions.
                      data[ 4] - rhs.data[ 4], data[ 5] - rhs.data[ 5], data[ 6] - rhs.data[ 6], data[ 7] - rhs.data[ 7],
   */
                      data[ 8] - rhs.data[ 8], data[ 9] - rhs.data[ 9], data[10] - rhs.data[10], data[11] - rhs.data[11],
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
                      data[12] - rhs.data[12], data[13] - rhs.data[13], data[14] - rhs.data[14], data[15] - rhs.data[15]);
    return reinterpret_cast<T const*>(data.data());
  }
  }


  //--------------------[ matrix with scalar operations ]---------------------
  //----------[ output operator ]----------------------------
  /**
   * Addition operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Output to stream operator
   */
   * @param lhs Left hand side argument of operator (commonly ostream instance).
  inline matrix4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of operator.
    return matrix4<T>(data[ 0] + rhs, data[ 1] + rhs, data[ 2] + rhs, data[ 3] + rhs,
   * @return Left hand side argument - the ostream object passed to operator.
                      data[ 4] + rhs, data[ 5] + rhs, data[ 6] + rhs, data[ 7] + rhs,
   */
                      data[ 8] + rhs, data[ 9] + rhs, data[10] + rhs, data[11] + rhs,
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
                      data[12] + rhs, data[13] + rhs, data[14] + rhs, data[15] + rhs);
    for(int i = 0; i != 4; ++i) {
  }
      lhs << "|\t";

      for(int j = 0; j != 4; ++j) {
  /**
        lhs << rhs.at(j, i) << "\t";
   * Subtraction operator
      }
   * @param rhs Right hand side argument of binary operator.
      lhs << "|" << std::endl;
   */
    }
  inline matrix4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return lhs;
    return matrix4<T>(data[ 0] - rhs, data[ 1] - rhs, data[ 2] - rhs, data[ 3] - rhs,
  }
                      data[ 4] - rhs, data[ 5] - rhs, data[ 6] - rhs, data[ 7] - rhs,

                      data[ 8] - rhs, data[ 9] - rhs, data[10] - rhs, data[11] - rhs,
  /**
                      data[12] - rhs, data[13] - rhs, data[14] - rhs, data[15] - rhs);
   * Gets string representation.
  }
   */

  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
  /**
    std::ostringstream oss;
   * Multiplication operator
    oss << *this;
   * @param rhs Right hand side argument of binary operator.
    return oss.str();
   */
  }
  inline matrix4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
    return matrix4<T>(data[ 0] * rhs, data[ 1] * rhs, data[ 2] * rhs, data[ 3] * rhs,
    return to_string();
                      data[ 4] * rhs, data[ 5] * rhs, data[ 6] * rhs, data[ 7] * rhs,
  }
                      data[ 8] * rhs, data[ 9] * rhs, data[10] * rhs, data[11] * rhs,
};
                      data[12] * rhs, data[13] * rhs, data[14] * rhs, data[15] * rhs);

  }

#ifdef VMATH_NAMESPACE
  /**
}
   * Division operator
#endif //VMATH_NAMESPACE
   * @param rhs Right hand side argument of binary operator.

   */
#include "matrix4_types.h"
  inline matrix4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {

    return matrix4<T>(data[ 0] / rhs, data[ 1] / rhs, data[ 2] / rhs, data[ 3] / rhs,
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      data[ 4] / rhs, data[ 5] / rhs, data[ 6] / rhs, data[ 7] / rhs,
//
                      data[ 8] / rhs, data[ 9] / rhs, data[10] / rhs, data[11] / rhs,
// Standard C++ library extensions
                      data[12] / rhs, data[13] / rhs, data[14] / rhs, data[15] / rhs);
//
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  /**
namespace std {
   * Addition operator

   * @param rhs Right hand side argument of binary operator.
/**
   */
 * Gets matrix containing minimal values of @a a and @a b coordinates.
  inline matrix4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
 * @return Matrix of minimal coordinates.
    *this = *this + rhs;
 */
    return *this;
template<typename T>
  }

inline constexpr matrix4<T> min(matrix4<T> const &a, const matrix4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
  /**
template<typename T>
   * Subtraction operator
inline constexpr matrix4<T> min(matrix4<T> const &a, const matrix4<T> &b) noexcept {
   * @param rhs Right hand side argument of binary operator.
  return {::std::min(a.data[0], b.data[0]),
   */
          ::std::min(a.data[1], b.data[1]),
  inline matrix4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
          ::std::min(a.data[2], b.data[2]),
    *this = *this - rhs;

    return *this;
          ::std::min(a.data[3], b.data[3]),
  }
          ::std::min(a.data[4], b.data[4]),

          ::std::min(a.data[5], b.data[5]),
  /**

   * Multiplication operator
          ::std::min(a.data[6], b.data[6]),
   * @param rhs Right hand side argument of binary operator.
          ::std::min(a.data[7], b.data[7]),
   */
          ::std::min(a.data[8], b.data[8])};
  inline matrix4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
}
    *this = *this * rhs;

    return *this;
/**
  }
 * Gets matrix containing maximal values of @a a and @a b coordinates.

  /**
 * @return Matrix of maximal coordinates.
   * Division operator
 */
   * @param rhs Right hand side argument of binary operator.
template<typename T>
   */
inline constexpr matrix4<T> max(matrix4<T> const &a, const matrix4<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
  inline matrix4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
template<typename T>
    *this = *this / rhs;
inline constexpr matrix4<T> max(matrix4<T> const &a, const matrix4<T> &b) noexcept {
    return *this;
  return {::std::max(a.data[0], b.data[0]),
  }
          ::std::max(a.data[1], b.data[1]),

          ::std::max(a.data[2], b.data[2]),
  //--------------------[ multiply operators ]--------------------------------

  /**
          ::std::max(a.data[3], b.data[3]),
   * Multiplication operator
          ::std::max(a.data[4], b.data[4]),
   * @param rhs Right hand side argument of binary operator.
          ::std::max(a.data[5], b.data[5]),
   */

  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
          ::std::max(a.data[6], b.data[6]),
    return vector4<T>(data[0] * rhs.x + data[4] * rhs.y + data[ 8] * rhs.z + data[12] * rhs.w,
          ::std::max(a.data[7], b.data[7]),
                      data[1] * rhs.x + data[5] * rhs.y + data[ 9] * rhs.z + data[13] * rhs.w,
          ::std::max(a.data[8], b.data[8])};
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z + data[14] * rhs.w,
}
                      data[3] * rhs.x + data[7] * rhs.y + data[11] * rhs.z + data[15] * rhs.w);

  }
#ifndef VMATH_NO_BOOST

/**
  /**
 * Gets a hash value taking account of all dimensions of this matrix, for use
   * Multiplication operator
 * in standard container maps etc.
   * @param rhs Right hand side argument of binary operator.
   */
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
 * @return Hash value
    return vector3<T>(data[0] * rhs.x + data[4] * rhs.y + data[8]  * rhs.z,
 */
                      data[1] * rhs.x + data[5] * rhs.y + data[9]  * rhs.z,
template<typename T>
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z);
struct hash<matrix4<T>> {
  }
  size_t operator()(const matrix4<T> &value) const {

    size_t hashvalue = 0;
  /**
    boost::hash_combine(hashvalue, value.data[0]);
   * Multiplication operator
    boost::hash_combine(hashvalue, value.data[1]);
   * @param rhs Right hand side argument of binary operator.
    boost::hash_combine(hashvalue, value.data[2]);
   */

  inline matrix4<T> constexpr operator*(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    boost::hash_combine(hashvalue, value.data[3]);
    return matrix4<T>(rhs.data[ 0] * data[ 0] + rhs.data[ 1] * data[ 4] + rhs.data[ 2] * data[ 8] + rhs.data[ 3] * data[12],
    boost::hash_combine(hashvalue, value.data[4]);
                      rhs.data[ 0] * data[ 1] + rhs.data[ 1] * data[ 5] + rhs.data[ 2] * data[ 9] + rhs.data[ 3] * data[13],
    boost::hash_combine(hashvalue, value.data[5]);
                      rhs.data[ 0] * data[ 2] + rhs.data[ 1] * data[ 6] + rhs.data[ 2] * data[10] + rhs.data[ 3] * data[14],

                      rhs.data[ 0] * data[ 3] + rhs.data[ 1] * data[ 7] + rhs.data[ 2] * data[11] + rhs.data[ 3] * data[15],
    boost::hash_combine(hashvalue, value.data[6]);

    boost::hash_combine(hashvalue, value.data[7]);
                      rhs.data[ 4] * data[ 0] + rhs.data[ 5] * data[ 4] + rhs.data[ 6] * data[ 8] + rhs.data[ 7] * data[12],
    boost::hash_combine(hashvalue, value.data[8]);
                      rhs.data[ 4] * data[ 1] + rhs.data[ 5] * data[ 5] + rhs.data[ 6] * data[ 9] + rhs.data[ 7] * data[13],
    return hashvalue;
                      rhs.data[ 4] * data[ 2] + rhs.data[ 5] * data[ 6] + rhs.data[ 6] * data[10] + rhs.data[ 7] * data[14],
  }
                      rhs.data[ 4] * data[ 3] + rhs.data[ 5] * data[ 7] + rhs.data[ 6] * data[11] + rhs.data[ 7] * data[15],
};

#endif // VMATH_NO_BOOST
                      rhs.data[ 8] * data[ 0] + rhs.data[ 9] * data[ 4] + rhs.data[10] * data[ 8] + rhs.data[11] * data[12],

                      rhs.data[ 8] * data[ 1] + rhs.data[ 9] * data[ 5] + rhs.data[10] * data[ 9] + rhs.data[11] * data[13],
}
                      rhs.data[ 8] * data[ 2] + rhs.data[ 9] * data[ 6] + rhs.data[10] * data[10] + rhs.data[11] * data[14],

                      rhs.data[ 8] * data[ 3] + rhs.data[ 9] * data[ 7] + rhs.data[10] * data[11] + rhs.data[11] * data[15],
#ifndef VMATH_NO_BOOST

/**
                      rhs.data[12] * data[ 0] + rhs.data[13] * data[ 4] + rhs.data[14] * data[ 8] + rhs.data[15] * data[12],
 * Gets a hash value taking account of all dimensions of this matrix, for use
                      rhs.data[12] * data[ 1] + rhs.data[13] * data[ 5] + rhs.data[14] * data[ 9] + rhs.data[15] * data[13],
 * in standard container maps etc.
                      rhs.data[12] * data[ 2] + rhs.data[13] * data[ 6] + rhs.data[14] * data[10] + rhs.data[15] * data[14],
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
                      rhs.data[12] * data[ 3] + rhs.data[13] * data[ 7] + rhs.data[14] * data[11] + rhs.data[15] * data[15]);
 * @return Hash value
  }
 */

template<typename T>
  /**
size_t hash_value(matrix4<T> const &value) {
   * Multiplication operator
  size_t hashvalue = 0;
   * @param rhs Right hand side argument of binary operator.
  boost::hash_combine(hashvalue, value.data[0]);
   */
  boost::hash_combine(hashvalue, value.data[1]);
  inline matrix4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  boost::hash_combine(hashvalue, value.data[2]);
    *this = *this * rhs;

    return *this;
  boost::hash_combine(hashvalue, value.data[3]);
  }
  boost::hash_combine(hashvalue, value.data[4]);

  boost::hash_combine(hashvalue, value.data[5]);
  //---------------------------[ misc operations ]----------------------------


  boost::hash_combine(hashvalue, value.data[6]);
  /**
  boost::hash_combine(hashvalue, value.data[7]);
   * Computes determinant of matrix
  boost::hash_combine(hashvalue, value.data[8]);
   * @return Determinant of matrix
  return hashvalue;
   * @note This function does 3 * 4 * 6 mul, 3 * 6 add.
}
   */
#endif // VMATH_NO_BOOST
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {

    return   data[12] * data[9] * data[6]  * data[3]  - data[8] * data[13] * data[6]  * data[3]
#endif // VECTORSTORM_MATRIX4_H_INCLUDED
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
        lhs << rhs.at(j, i) << "\t";
      }
      lhs << "|" << std::endl;
    }
    return lhs;
  }

  /**
   * Gets string representation.
   */
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
  }
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
    return to_string();
  }
};

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

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
template<typename T>
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
template<typename T>
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

#ifndef VMATH_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this matrix, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
struct hash<matrix4<T>> {
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
#endif // VMATH_NO_BOOST

}

#ifndef VMATH_NO_BOOST
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
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_MATRIX4_H_INCLUDED
