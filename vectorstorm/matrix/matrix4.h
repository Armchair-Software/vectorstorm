#ifndef VECTORSTORM_MATRIX4_H_INCLUDED
#define VECTORSTORM_MATRIX4_H_INCLUDED

#include <cstring>
#include <array>
#include <sstream>
#include "vectorstorm/epsilon.h"
#include "vectorstorm/vector/vector3_forward.h"
#include "vectorstorm/vector/vector4_forward.h"
#include "matrix3_forward.h"

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
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
   * Variadic initialisation constructor
   * @param dt Initialiser list containing raw data for each element in order.
   */
  //inline constexpr explicit matrix4(std::initializer_list<T> dt)
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
  //}
  // see http://stackoverflow.com/a/5549918/1678468
  template<class... FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix4(FromT... dt) noexcept
    : data{dt...} {
  }
  //template<class... FromT>  __attribute__((__always_inline__))
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
  inline static matrix4<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
    return create_rotation_around_axis_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
  }
  inline static matrix4<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
    return create_rotation_around_axis(xDeg, yDeg, zDeg);
  }

  /**
   * Creates rotation matrix by rotation around three axes, radian version.
   * @param xRads Angle (in radians) of rotation around axis X.
   * @param yRads Angle (in radians) of rotation around axis Y.
   * @param zRads Angle (in radians) of rotation around axis Z.
   */
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
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
    sincos_any(xRads, sin_xRads, cos_xRads);
    sincos_any(yRads, sin_yRads, cos_yRads);
    sincos_any(zRads, sin_zRads, cos_zRads);
    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
    return matrix4<T>(temp_cos_z_cos_y,
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,
                      static_cast<T>(0),

                      sin_zRads * cos_yRads,
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,
                      static_cast<T>(0),

                     -temp_cos_z_sin_y,
                      temp_cos_z_cos_y * sin_xRads,
                      temp_cos_z_cos_y * cos_xRads,
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(1));
  }
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
    return create_rotation_around_axis_rad(xRads, yRads, zRads);
  }

  /**
   * Creates rotation matrix by rotation around an axis.
   * @param axis Axis to rotate around.
   * @param angle Angle (in degrees) of rotation around axis.
   */
  inline static matrix4<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    return create_rotation_around_axis_rad(axis, angle);
  }
  inline static matrix4<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
    return create_rotation_around_axis(axis, angle);
  }

  /**
   * Creates rotation matrix by rotation around an axis, radian version.
   * @param axis Axis to rotate around.
   * @param angle Angle (in radians) of rotation around axis.
   */
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    // the static cast is to avoid narrowing conversion warnings when used with ints
    T sin_a = static_cast<T>(0);
    T cos_a = static_cast<T>(0);
    sincos_any(angle, sin_a, cos_a);
    T const cos_a_inv = static_cast<T>(1) - cos_a;
    return matrix4<T>(axis.x * axis.x * cos_a_inv + cos_a,
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
                      static_cast<T>(0),

                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
                      axis.y * axis.y * cos_a_inv + cos_a,
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,
                      static_cast<T>(0),

                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,
                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
                      axis.z * axis.z * cos_a_inv + cos_a,
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(1));
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
   * Creates new view matrix to look from specified position @a eye_pos to specified position @a centre_pos
   * @param eye_pos A position of camera
   * @param centre_pos A position where camera looks-at
   * @param up_dir Direction of up vector
   * @return Resulting view matrix that looks from and at specific position.
   */
  inline static matrix4<T> constexpr create_look_at(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
    vector3<T> forward = centre_pos - eye_pos;
    forward.normalise();

    // Side = forward x up
    vector3<T> side = forward.crossProduct(up_dir);
    side.normalise();

    // Recompute up as: up = side x forward
    vector3<T> const up = side.crossProduct(forward);

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
    // constexpr-suitable return-only alternative, may turn out much slower when computed at runtime:
    /*
    return matrix4<T>( (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().x,
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).x,
                      -(centre_pos - eye_pos).normalise_copy().x,
                       static_cast<T>(0),

                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().y,
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).y,
                      -(centre_pos - eye_pos).normalise_copy().y,
                       static_cast<T>(0),

                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().z,
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).z,
                      -(centre_pos - eye_pos).normalise_copy().z,
                       static_cast<T>(0),

                       static_cast<T>(0),
                       static_cast<T>(0),
                       static_cast<T>(0),
                       static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
    */
  }
  inline static matrix4<T> constexpr createLookAt(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_look_at()"))) {
    return create_look_at(eye_pos, centre_pos, up_dir);
  }

  /**
   * Creates OpenGL compatible perspective projection according to specified frustum parameters.
   *
   * @param left Specify the coordinate for the left vertical clipping plane,
   * @param right Specify the coordinate for the right vertical clipping plane.
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
   * @param top Specify the coordinate for the top horizontal clipping plane.
   * @param zNear Specify the distance to the near clipping plane.  Distance must be positive.
   * @param zFar Specify the distance to the far depth clipping plane.  Distance must be positive.
   *
   * @return Projection matrix for specified frustum.
   */
  inline static matrix4<T> constexpr create_frustum(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) {
    /*
     *    2 zNear
     *  ------------       0              A              0
     *  right - left
     *
     *                  2 zNear
     *      0         ------------        B              0
     *                top - bottom
     *
     *      0              0              C              D
     *
     *      0              0              -1             0
     *
     *  A =   (right + left) / (right - left)
     *  B =   (top + bottom) / (top - bottom)
     *  C = - (zFar + zNear) / (zFar - zNear)
     *  D = - (2 zFar zNear) / (zFar - zNear)
     */
    return matrix4<T>(static_cast<T>(2) * zNear / (right - left),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),

                      static_cast<T>(0),
                      static_cast<T>(2) * zNear / (top - bottom),
                      static_cast<T>(0),
                      static_cast<T>(0),

                       (right + left) / (right - left),
                       (top + bottom) / (top - bottom),
                      -(zFar + zNear) / (zFar - zNear),
                      static_cast<T>(-1),

                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(-2) * zNear * zFar / (zFar - zNear),
                      static_cast<T>(1));
  }
  inline static matrix4<T> constexpr createFrustum(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_frustum()"))) {
    return create_frustum(left, right, bottom, top, zNear, zFar);
  }

  /**
   * Creates OpenGL compatible orthographic projection matrix.
   * @param left Specify the coordinate for the left vertical clipping plane,
   * @param right Specify the coordinate for the right vertical clipping plane.
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
   * @param top Specify the coordinate for the top horizontal clipping plane.
   * @param zNear Specify the distance to the nearer depth clipping plane.
   *       This value is negative if the plane is to be behind the viewer,
   * @param zFar Specify the distance to the farther depth clipping plane.
   *       This value is negative if the plane is to be behind the viewer.
   * @return Othrographic projection matrix.
   */
  inline static matrix4<T> constexpr create_ortho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) {
    /*      2
     *  ------------       0              0              tx
     *  right - left
     *                     2
     *      0         ------------        0              ty
     *                top - bottom
     *                                    -2
     *      0              0         ------------        tz
     *                                zFar-zNear
     *
     *      0              0              0              1
     *
     *    tx = - (right + left) / (right - left)
     *    ty = - (top + bottom) / (top - bottom)
     *    tz = - (zFar + zNear) / (zFar - zNear)
     */
    return matrix4<T>(static_cast<T>(2) / (right - left), static_cast<T>(0),                  static_cast<T>(0),                   static_cast<T>(0),
                      static_cast<T>(0),                  static_cast<T>(2) / (top - bottom), static_cast<T>(0),                   static_cast<T>(0),
                      static_cast<T>(0),                  static_cast<T>(0),                  static_cast<T>(-2) / (zFar - zNear), static_cast<T>(0),
                      -(right + left)   / (right - left), -(top + bottom)   / (top - bottom), -(zFar + zNear)    / (zFar - zNear), static_cast<T>(1));
  }
  inline static matrix4<T> constexpr createOrtho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_ortho()"))) {
    return create_ortho(left, right, bottom, top, zNear, zFar);
  }

  /**
   * Creates new matrix 4x4 from array that represents such matrix 4x4
   * as array of tightly packed elements in row major order.
   * @param arr An array of elements for 4x4 matrix in row major order.
   * @return An instance of matrix4<T> representing @a arr
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline static matrix4<T> constexpr from_row_major_array(FromT const *arr) noexcept {
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[ 8]), static_cast<T>(arr[12]),
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[ 9]), static_cast<T>(arr[13]),
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(arr[14]),
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(arr[15]));
  }
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
  inline static matrix4<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
    return from_row_major_array(arr);
  }

  /**
   * Creates new matrix 4x4 from array that represents such matrix 4x4
   * as array of tightly packed elements in column major order.
   * @param arr An array of elements for 4x4 matrix in column major order.
   * @return An instance of matrix4<T> representing @a arr
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline static matrix4<T> constexpr from_column_major_array(FromT const *arr) noexcept {
    return matrix4<T>(static_cast<T>(arr[ 0]), static_cast<T>(arr[ 1]), static_cast<T>(arr[ 2]), static_cast<T>(arr[ 3]),
                      static_cast<T>(arr[ 4]), static_cast<T>(arr[ 5]), static_cast<T>(arr[ 6]), static_cast<T>(arr[ 7]),
                      static_cast<T>(arr[ 8]), static_cast<T>(arr[ 9]), static_cast<T>(arr[10]), static_cast<T>(arr[11]),
                      static_cast<T>(arr[12]), static_cast<T>(arr[13]), static_cast<T>(arr[14]), static_cast<T>(arr[15]));
  }
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
  inline static matrix4<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
    return from_column_major_array(arr);
  }

  /**
   * Creates new matrix 4x4 from array that represents such matrix 3x4
   * as array of tightly packed elements in row major order.
   * @param arr An array of elements for 3x4 matrix in row major order.
   * @return An instance of matrix4<T> representing @a arr
   */
  template<typename FromT> __attribute__((__always_inline__))
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
  inline bool constexpr operator==(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
      return std::abs(data[ 0] - rhs.data[ 0]) < static_cast<T>(epsilon) &&
             std::abs(data[ 1] - rhs.data[ 1]) < static_cast<T>(epsilon) &&
             std::abs(data[ 2] - rhs.data[ 2]) < static_cast<T>(epsilon) &&
             std::abs(data[ 3] - rhs.data[ 3]) < static_cast<T>(epsilon) &&
             std::abs(data[ 4] - rhs.data[ 4]) < static_cast<T>(epsilon) &&
             std::abs(data[ 5] - rhs.data[ 5]) < static_cast<T>(epsilon) &&
             std::abs(data[ 6] - rhs.data[ 6]) < static_cast<T>(epsilon) &&
             std::abs(data[ 7] - rhs.data[ 7]) < static_cast<T>(epsilon) &&
             std::abs(data[ 8] - rhs.data[ 8]) < static_cast<T>(epsilon) &&
             std::abs(data[ 9] - rhs.data[ 9]) < static_cast<T>(epsilon) &&
             std::abs(data[10] - rhs.data[10]) < static_cast<T>(epsilon) &&
             std::abs(data[11] - rhs.data[11]) < static_cast<T>(epsilon) &&
             std::abs(data[12] - rhs.data[12]) < static_cast<T>(epsilon) &&
             std::abs(data[13] - rhs.data[13]) < static_cast<T>(epsilon) &&
             std::abs(data[14] - rhs.data[14]) < static_cast<T>(epsilon) &&
             std::abs(data[15] - rhs.data[15]) < static_cast<T>(epsilon);
    #else
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
    #endif // VMATH_SOFT_COMPARE
  }

  /**
   * Inequality test operator
   * @param rhs Right hand side argument of binary operator.
   * @return not (lhs == rhs) :-P
   */
  inline bool constexpr operator!=(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  }

  //---------------------[ access operators ]---------------------------------
  /**
   * Get reference to element at postion (x,y).
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
   */
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
    return data[x * 4 + y];
  }

  /**
   * Get constant reference to element at position (x,y).
   * @param x Number of column (0..3)
   * @param y Number of row (0..3)
   */
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
    return data[x * 4 + y];
  }

  /**
   * Get reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..4)
   * @param j Number of column (1..4)
   */
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 4 + i - 1];
  }

  /**
   * Get constant reference to element at position (i,j), with math matrix notation
   * @param i Number of row (1..4)
   * @param j Number of column (1..4)
   */
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 4 + i - 1];
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
  inline void constexpr setTranslation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_translation()"))) {
    set_translation(v);
  }

  /**
   * Returns translation part of matrix.
   */
  inline vector3<T> constexpr get_translation() const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(data[12], data[13], data[14]);
  }
  inline vector3<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_translation()"))) {
    return get_translation();
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
  inline void constexpr setRotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_rotation()"))) {
    set_rotation(m);
  }

  /**
   * Returns rotation (matrix 3x3) part of matrix.
   */
  inline matrix3<T> constexpr get_rotation() const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[ 0], data[ 1], data[ 2],
                      data[ 4], data[ 5], data[ 6],
                      data[ 8], data[ 9], data[10]);
  }
  inline matrix3<T> constexpr getRotation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_rotation()"))) {
    return get_rotation();
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
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return vector3<T>(data[0] * rhs.x + data[4] * rhs.y + data[8]  * rhs.z,
                      data[1] * rhs.x + data[5] * rhs.y + data[9]  * rhs.z,
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z);
  }

  /**
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   */
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

#endif // VECTORSTORM_MATRIX4_H_INCLUDED
