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
#ifndef VECTORSTORM_MATRIX4_H_INCLUDED
   * @param zRads Angle (in radians) of rotation around axis Z.
#define VECTORSTORM_MATRIX4_H_INCLUDED
   */

  inline static matrix4<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
#include <cstring>
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
#include <array>
    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
#include <sstream>
    // zero-initialisation is required for gcc not to complain when the function is constexpr
#include "vectorstorm/epsilon.h"
    // the static cast is to avoid narrowing conversion warnings when used with ints
#include "vectorstorm/vector/vector3_forward.h"
    T sin_xRads = static_cast<T>(0);
#include "vectorstorm/vector/vector4_forward.h"
    T cos_xRads = static_cast<T>(0);
#include "matrix3_forward.h"
    T sin_yRads = static_cast<T>(0);

    T cos_yRads = static_cast<T>(0);
#ifdef VMATH_NAMESPACE
    T sin_zRads = static_cast<T>(0);
namespace VMATH_NAMESPACE {
    T cos_zRads = static_cast<T>(0);
#endif
    sincos_any(xRads, sin_xRads, cos_xRads);

    sincos_any(yRads, sin_yRads, cos_yRads);
/**
    sincos_any(zRads, sin_zRads, cos_zRads);
 * Class for matrix 4x4
    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
 * @note Data stored in this matrix are in column major order. This arrangement suits OpenGL.
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
 * If you're using row major matrix, consider using fromRowMajorArray as way for construction
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
 * matrix4<T> instance.
    return matrix4<T>(temp_cos_z_cos_y,
 */
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
template<typename T>
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,
class matrix4 {
                      static_cast<T>(0),
public:

  /// Data stored in column major order
                      sin_zRads * cos_yRads,
  std::array<T, 16> data;
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,

                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,
  //--------------------------[ constructors ]-------------------------------
                      static_cast<T>(0),
  /**

   *Creates identity matrix
                     -temp_cos_z_sin_y,
   */
                      temp_cos_z_cos_y * sin_xRads,
  inline constexpr matrix4() noexcept __attribute__((__always_inline__))
                      temp_cos_z_cos_y * cos_xRads,
    : data{1, 0, 0, 0,
                      static_cast<T>(0),
           0, 1, 0, 0,

           0, 0, 1, 0,
                      static_cast<T>(0),
           0, 0, 0, 1} {
                      static_cast<T>(0),
  }
                      static_cast<T>(0),

                      static_cast<T>(1));
  /**
  }
   * Copy matrix values from array (these data must be in column
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
   * major order!)
    return create_rotation_around_axis_rad(xRads, yRads, zRads);
   */
  }
  inline constexpr explicit matrix4(T const *dt) noexcept __attribute__((__always_inline__))

    : data{dt[ 0], dt[ 1], dt[ 2], dt[ 3],
  /**
           dt[ 4], dt[ 5], dt[ 6], dt[ 7],
   * Creates rotation matrix by rotation around an axis.
           dt[ 8], dt[ 9], dt[10], dt[11],
   * @param axis Axis to rotate around.
           dt[12], dt[13], dt[14], dt[15]} {
   * @param angle Angle (in degrees) of rotation around axis.
  }
   */
  inline constexpr explicit matrix4(T *dt) noexcept __attribute__((__always_inline__))
  inline static matrix4<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    : data{dt[ 0], dt[ 1], dt[ 2], dt[ 3],
    return create_rotation_around_axis_rad(axis, angle);
           dt[ 4], dt[ 5], dt[ 6], dt[ 7],
  }
           dt[ 8], dt[ 9], dt[10], dt[11],
  inline static matrix4<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
           dt[12], dt[13], dt[14], dt[15]} {
    return create_rotation_around_axis(axis, angle);
  }
  }


  /**
  /**
   * Copy constructor.
   * Creates rotation matrix by rotation around an axis, radian version.
   * @param src Data source for new created instance of matrix4.
   * @param axis Axis to rotate around.
   */
   * @param angle Angle (in radians) of rotation around axis.
  inline constexpr explicit matrix4(matrix4<T> const &src) noexcept __attribute__((__always_inline__))
   */
    : data{src.data[ 0], src.data[ 1], src.data[ 2], src.data[ 3],
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
           src.data[ 4], src.data[ 5], src.data[ 6], src.data[ 7],
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
           src.data[ 8], src.data[ 9], src.data[10], src.data[11],
    // zero-initialisation is required for gcc not to complain when the function is constexpr
           src.data[12], src.data[13], src.data[14], src.data[15]} {
    // the static cast is to avoid narrowing conversion warnings when used with ints
  }
    T sin_a = static_cast<T>(0);

    T cos_a = static_cast<T>(0);
  /**
    sincos_any(angle, sin_a, cos_a);
   * Copy casting constructor.
    T const cos_a_inv = static_cast<T>(1) - cos_a;
   * @param src Data source for new created instance of matrix4.
    return matrix4<T>(axis.x * axis.x * cos_a_inv + cos_a,
   */
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
  template<typename FromT> __attribute__((__always_inline__))
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
  inline constexpr explicit matrix4(matrix4<FromT> const &src) noexcept
                      static_cast<T>(0),
    : data{static_cast<T>(src.data[ 0]), static_cast<T>(src.data[ 1]), static_cast<T>(src.data[ 2]), static_cast<T>(src.data[ 3]),

           static_cast<T>(src.data[ 4]), static_cast<T>(src.data[ 5]), static_cast<T>(src.data[ 6]), static_cast<T>(src.data[ 7]),
                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
                      axis.y * axis.y * cos_a_inv + cos_a,
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,
           static_cast<T>(src.data[ 8]), static_cast<T>(src.data[ 9]), static_cast<T>(src.data[10]), static_cast<T>(src.data[11]),
                      static_cast<T>(0),
           static_cast<T>(src.data[12]), static_cast<T>(src.data[13]), static_cast<T>(src.data[14]), static_cast<T>(src.data[15])} {

  }
                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,

                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
  /**
                      axis.z * axis.z * cos_a_inv + cos_a,
   * Move constructor.
                      static_cast<T>(0),
   * @param src Data source for new created instance of matrix4.

   */
                      static_cast<T>(0),
  inline constexpr matrix4(matrix4<T> &&src) noexcept __attribute__((__always_inline__))
                      static_cast<T>(0),
    : data(std::move(src.data)) {
                      static_cast<T>(0),
  }
                      static_cast<T>(1));

  }
  /**
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
   * Move casting constructor.
    return create_rotation_around_axis_rad(axis, angle);
   * @param src Data source for new created instance of matrix4.
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /// Creates translation matrix
  inline constexpr matrix4(matrix4<FromT> &&src) noexcept
  /**
    : data{static_cast<T>(std::move(src.data[ 0])), static_cast<T>(std::move(src.data[ 1])), static_cast<T>(std::move(src.data[ 2])), static_cast<T>(std::move(src.data[ 3])),
   * Creates translation matrix.
   * @param x X-direction translation
           static_cast<T>(std::move(src.data[ 4])), static_cast<T>(std::move(src.data[ 5])), static_cast<T>(std::move(src.data[ 6])), static_cast<T>(std::move(src.data[ 7])),
   * @param y Y-direction translation
           static_cast<T>(std::move(src.data[ 8])), static_cast<T>(std::move(src.data[ 9])), static_cast<T>(std::move(src.data[10])), static_cast<T>(std::move(src.data[11])),
   * @param z Z-direction translation
           static_cast<T>(std::move(src.data[12])), static_cast<T>(std::move(src.data[13])), static_cast<T>(std::move(src.data[14])), static_cast<T>(std::move(src.data[15]))} {
   * @param w for W-coordinate translation (implicitly set to 1)
  }
   */

  inline static matrix4<T> constexpr create_translation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) {
  /**
    return matrix4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
   * Variadic initialisation constructor
                      static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
   * @param dt Initialiser list containing raw data for each element in order.
   */
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
  //inline constexpr explicit matrix4(std::initializer_list<T> dt)
                      x,                 y,                 z,                 w);
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
  }
  //}
  inline static matrix4<T> constexpr createTranslation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_translation()"))) {
  // see http://stackoverflow.com/a/5549918/1678468
    return create_translation(x, y, z, w);
  template<class... FromT> __attribute__((__always_inline__))
  }
  inline constexpr explicit matrix4(FromT... dt) noexcept

    : data{dt...} {
  /**
  }
   * Create scale matrix with @a sx, @a sy, and @a sz
  //template<class... FromT>  __attribute__((__always_inline__))
   * being values of matrix main diagonal.
  //inline constexpr explicit matrix4(FromT&&... dt)
   * @param sx Scale in X-axis
  //  : data{std::forward<FromT>(dt)...} {
   * @param sy Scale in Y-axis
  //}
   * @param sz Scale in Z-axis

   * @return Transform matrix 4x4 with scale transformation.
  /**
   */
   * Resets matrix to be identity matrix
  inline static matrix4<T> constexpr create_scale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) {
   */
    return matrix4<T>(sx,                static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0), sy,                static_cast<T>(0), static_cast<T>(0),
    data = {1, 0, 0, 0,
                      static_cast<T>(0), static_cast<T>(0), sz,                static_cast<T>(0),
            0, 1, 0, 0,
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
            0, 0, 1, 0,
  }
            0, 0, 0, 1};
  inline static matrix4<T> constexpr createScale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_scale()"))) {
  }
    return create_scale(sx, sy, sz);

  }
  /**

   * Creates rotation matrix by rotation around three axes.
  /**
   * @param xDeg Angle (in degrees) of rotation around axis X.
   * Creates new view matrix to look from specified position @a eye_pos to specified position @a centre_pos
   * @param yDeg Angle (in degrees) of rotation around axis Y.
   * @param eye_pos A position of camera
   * @param zDeg Angle (in degrees) of rotation around axis Z.
   * @param centre_pos A position where camera looks-at
   */
   * @param up_dir Direction of up vector
  inline static matrix4<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
   * @return Resulting view matrix that looks from and at specific position.
    return create_rotation_around_axis_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
   */
  }
  inline static matrix4<T> constexpr create_look_at(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
  inline static matrix4<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
    vector3<T> forward = centre_pos - eye_pos;
    return create_rotation_around_axis(xDeg, yDeg, zDeg);
    forward.normalise();
  }


    // Side = forward x up
  /**
    vector3<T> side = forward.crossProduct(up_dir);
   * Creates rotation matrix by rotation around three axes, radian version.
    side.normalise();
   * @param xRads Angle (in radians) of rotation around axis X.

   * @param yRads Angle (in radians) of rotation around axis Y.
    // Recompute up as: up = side x forward
   * @param zRads Angle (in radians) of rotation around axis Z.
    vector3<T> const up = side.crossProduct(forward);
   */

    return matrix4<T>(static_cast<T>(side.x),
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(up.x),
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
                      static_cast<T>(-forward.x),
    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
                      static_cast<T>(0),
    // zero-initialisation is required for gcc not to complain when the function is constexpr

    // the static cast is to avoid narrowing conversion warnings when used with ints
                      static_cast<T>(side.y),
    T sin_xRads = static_cast<T>(0);
                      static_cast<T>(up.y),
    T cos_xRads = static_cast<T>(0);
                      static_cast<T>(-forward.y),
    T sin_yRads = static_cast<T>(0);
                      static_cast<T>(0),
    T cos_yRads = static_cast<T>(0);

    T sin_zRads = static_cast<T>(0);
                      static_cast<T>(side.z),
    T cos_zRads = static_cast<T>(0);
                      static_cast<T>(up.z),
    sincos_any(xRads, sin_xRads, cos_xRads);
                      static_cast<T>(-forward.z),
    sincos_any(yRads, sin_yRads, cos_yRads);
                      static_cast<T>(0),
    sincos_any(zRads, sin_zRads, cos_zRads);

    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
                      static_cast<T>(0),
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
                      static_cast<T>(0),
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
                      static_cast<T>(0),
    return matrix4<T>(temp_cos_z_cos_y,
                      static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
    // constexpr-suitable return-only alternative, may turn out much slower when computed at runtime:
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,
    /*
                      static_cast<T>(0),
    return matrix4<T>( (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().x,

                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).x,
                      sin_zRads * cos_yRads,
                      -(centre_pos - eye_pos).normalise_copy().x,
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
                       static_cast<T>(0),
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,

                      static_cast<T>(0),
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().y,

                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).y,
                     -temp_cos_z_sin_y,
                      -(centre_pos - eye_pos).normalise_copy().y,
                      temp_cos_z_cos_y * sin_xRads,
                       static_cast<T>(0),
                      temp_cos_z_cos_y * cos_xRads,

                      static_cast<T>(0),
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().z,

                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).z,
                      static_cast<T>(0),
                      -(centre_pos - eye_pos).normalise_copy().z,
                      static_cast<T>(0),
                       static_cast<T>(0),
                      static_cast<T>(0),

                      static_cast<T>(1));
                       static_cast<T>(0),
  }
                       static_cast<T>(0),
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
                       static_cast<T>(0),
    return create_rotation_around_axis_rad(xRads, yRads, zRads);
                       static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
  }
    */

  }
  /**
  inline static matrix4<T> constexpr createLookAt(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_look_at()"))) {
   * Creates rotation matrix by rotation around an axis.
    return create_look_at(eye_pos, centre_pos, up_dir);
   * @param axis Axis to rotate around.
  }
   * @param angle Angle (in degrees) of rotation around axis.

   */
  /**
  inline static matrix4<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
   * Creates OpenGL compatible perspective projection according to specified frustum parameters.
    return create_rotation_around_axis_rad(axis, angle);
   *
  }
   * @param left Specify the coordinate for the left vertical clipping plane,
  inline static matrix4<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
   * @param right Specify the coordinate for the right vertical clipping plane.
    return create_rotation_around_axis(axis, angle);
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
  }
   * @param top Specify the coordinate for the top horizontal clipping plane.

   * @param zNear Specify the distance to the near clipping plane.  Distance must be positive.
  /**
   * @param zFar Specify the distance to the far depth clipping plane.  Distance must be positive.
   * Creates rotation matrix by rotation around an axis, radian version.
   *
   * @param axis Axis to rotate around.
   * @return Projection matrix for specified frustum.
   * @param angle Angle (in radians) of rotation around axis.
   */
   */
  inline static matrix4<T> constexpr create_frustum(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) {
  inline static matrix4<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    /*
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
     *    2 zNear
    // zero-initialisation is required for gcc not to complain when the function is constexpr
     *  ------------       0              A              0
    // the static cast is to avoid narrowing conversion warnings when used with ints
     *  right - left
    T sin_a = static_cast<T>(0);
     *
    T cos_a = static_cast<T>(0);
     *                  2 zNear
    sincos_any(angle, sin_a, cos_a);
     *      0         ------------        B              0
    T const cos_a_inv = static_cast<T>(1) - cos_a;
     *                top - bottom
    return matrix4<T>(axis.x * axis.x * cos_a_inv + cos_a,
     *
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
     *      0              0              C              D
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
     *
                      static_cast<T>(0),
     *      0              0              -1             0

     *
                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
     *  A =   (right + left) / (right - left)
                      axis.y * axis.y * cos_a_inv + cos_a,
     *  B =   (top + bottom) / (top - bottom)
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,
     *  C = - (zFar + zNear) / (zFar - zNear)
                      static_cast<T>(0),
     *  D = - (2 zFar zNear) / (zFar - zNear)

     */
                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,
    return matrix4<T>(static_cast<T>(2) * zNear / (right - left),
                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
                      static_cast<T>(0),
                      axis.z * axis.z * cos_a_inv + cos_a,
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),


                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(2) * zNear / (top - bottom),
                      static_cast<T>(0),
                      static_cast<T>(0),
                      static_cast<T>(1));
                      static_cast<T>(0),
  }

                       (right + left) / (right - left),
  inline static matrix4<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
                       (top + bottom) / (top - bottom),
    return create_rotation_around_axis_rad(axis, angle);
                      -(zFar + zNear) / (zFar - zNear),
  }
                      static_cast<T>(-1),


  /// Creates translation matrix
                      static_cast<T>(0),
  /**
                      static_cast<T>(0),
   * Creates translation matrix.
                      static_cast<T>(-2) * zNear * zFar / (zFar - zNear),
   * @param x X-direction translation
                      static_cast<T>(1));
   * @param y Y-direction translation
  }
   * @param z Z-direction translation
  inline static matrix4<T> constexpr createFrustum(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_frustum()"))) {
   * @param w for W-coordinate translation (implicitly set to 1)
    return create_frustum(left, right, bottom, top, zNear, zFar);
   */
  }
  inline static matrix4<T> constexpr create_translation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) {

    return matrix4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
  /**
                      static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
   * Creates OpenGL compatible orthographic projection matrix.
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
   * @param left Specify the coordinate for the left vertical clipping plane,
                      x,                 y,                 z,                 w);
   * @param right Specify the coordinate for the right vertical clipping plane.
  }
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
  inline static matrix4<T> constexpr createTranslation(T x, T y, T z, T w = 1) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_translation()"))) {
   * @param top Specify the coordinate for the top horizontal clipping plane.
    return create_translation(x, y, z, w);
   * @param zNear Specify the distance to the nearer depth clipping plane.
  }
   *       This value is negative if the plane is to be behind the viewer,

   * @param zFar Specify the distance to the farther depth clipping plane.
  /**
   *       This value is negative if the plane is to be behind the viewer.
   * Create scale matrix with @a sx, @a sy, and @a sz
   * @return Othrographic projection matrix.
   * being values of matrix main diagonal.
   */
   * @param sx Scale in X-axis
  inline static matrix4<T> constexpr create_ortho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) {
   * @param sy Scale in Y-axis
    /*      2
   * @param sz Scale in Z-axis
     *  ------------       0              0              tx
   * @return Transform matrix 4x4 with scale transformation.
     *  right - left
   */
     *                     2
  inline static matrix4<T> constexpr create_scale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) {
     *      0         ------------        0              ty
    return matrix4<T>(sx,                static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
     *                top - bottom
                      static_cast<T>(0), sy,                static_cast<T>(0), static_cast<T>(0),
     *                                    -2
                      static_cast<T>(0), static_cast<T>(0), sz,                static_cast<T>(0),
     *      0              0         ------------        tz
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
     *                                zFar-zNear
  }
     *
  inline static matrix4<T> constexpr createScale(T sx, T sy, T sz) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_scale()"))) {
     *      0              0              0              1
    return create_scale(sx, sy, sz);
     *
  }
     *    tx = - (right + left) / (right - left)

     *    ty = - (top + bottom) / (top - bottom)
  /**
     *    tz = - (zFar + zNear) / (zFar - zNear)
   * Creates new view matrix to look from specified position @a eye_pos to specified position @a centre_pos
     */
   * @param eye_pos A position of camera
    return matrix4<T>(static_cast<T>(2) / (right - left), static_cast<T>(0),                  static_cast<T>(0),                   static_cast<T>(0),
   * @param centre_pos A position where camera looks-at
                      static_cast<T>(0),                  static_cast<T>(2) / (top - bottom), static_cast<T>(0),                   static_cast<T>(0),
   * @param up_dir Direction of up vector
                      static_cast<T>(0),                  static_cast<T>(0),                  static_cast<T>(-2) / (zFar - zNear), static_cast<T>(0),
   * @return Resulting view matrix that looks from and at specific position.
                      -(right + left)   / (right - left), -(top + bottom)   / (top - bottom), -(zFar + zNear)    / (zFar - zNear), static_cast<T>(1));
   */
  }
  inline static matrix4<T> constexpr create_look_at(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
  inline static matrix4<T> constexpr createOrtho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_ortho()"))) {
    vector3<T> forward = centre_pos - eye_pos;
    return create_ortho(left, right, bottom, top, zNear, zFar);
    forward.normalise();
  }


    // Side = forward x up
  /**
    vector3<T> side = forward.crossProduct(up_dir);
   * Creates new matrix 4x4 from array that represents such matrix 4x4
    side.normalise();
   * as array of tightly packed elements in row major order.

   * @param arr An array of elements for 4x4 matrix in row major order.
    // Recompute up as: up = side x forward
   * @return An instance of matrix4<T> representing @a arr
    vector3<T> const up = side.crossProduct(forward);
   */

  template<typename FromT> __attribute__((__always_inline__))
    return matrix4<T>(static_cast<T>(side.x),
  inline static matrix4<T> constexpr from_row_major_array(FromT const *arr) noexcept {
                      static_cast<T>(up.x),
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[8]),  static_cast<T>(arr[12]),
                      static_cast<T>(-forward.x),
                      static_cast<T>(0),
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[9]),  static_cast<T>(arr[13]),

                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(arr[14]),
                      static_cast<T>(side.y),
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(arr[15]));
                      static_cast<T>(up.y),
  }
                      static_cast<T>(-forward.y),
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
                      static_cast<T>(0),
  inline static matrix4<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {

    return from_row_major_array(arr);
                      static_cast<T>(side.z),
  }
                      static_cast<T>(up.z),

                      static_cast<T>(-forward.z),
  /**
                      static_cast<T>(0),
   * Creates new matrix 4x4 from array that represents such matrix 4x4

   * as array of tightly packed elements in column major order.
                      static_cast<T>(0),
   * @param arr An array of elements for 4x4 matrix in column major order.
                      static_cast<T>(0),
   * @return An instance of matrix4<T> representing @a arr
                      static_cast<T>(0),
   */
                      static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
  template<typename FromT> __attribute__((__always_inline__))
    // constexpr-suitable return-only alternative, may turn out much slower when computed at runtime:
  inline static matrix4<T> constexpr from_column_major_array(FromT const *arr) noexcept {
    /*
    return matrix4<T>(static_cast<T>(arr[0]),  static_cast<T>(arr[1]),  static_cast<T>(arr[2]),  static_cast<T>(arr[3]),
    return matrix4<T>( (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().x,
                      static_cast<T>(arr[4]),  static_cast<T>(arr[5]),  static_cast<T>(arr[6]),  static_cast<T>(arr[7]),
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).x,
                      static_cast<T>(arr[8]),  static_cast<T>(arr[9]),  static_cast<T>(arr[10]), static_cast<T>(arr[11]),
                      -(centre_pos - eye_pos).normalise_copy().x,
                      static_cast<T>(arr[12]), static_cast<T>(arr[13]), static_cast<T>(arr[14]), static_cast<T>(arr[15]));
                       static_cast<T>(0),
  }

  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().y,
  inline static matrix4<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).y,
    return from_column_major_array(arr);
                      -(centre_pos - eye_pos).normalise_copy().y,
  }
                       static_cast<T>(0),


  //---------------------[ Equality operators ]------------------------------
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().z,
  /**
                       (centre_pos - eye_pos).normalise_copy().crossProduct(up_dir).normalise_copy().crossProduct((centre_pos - eye_pos).normalise_copy()).z,
   * Equality test operator
                      -(centre_pos - eye_pos).normalise_copy().z,
   * @param rhs Right hand side argument of binary operator.
                       static_cast<T>(0),
   * @note Test of equality is based of threshold epsilon value. To be two

   * values equal, must satisfy this condition all elements of matrix
                       static_cast<T>(0),
   * | lhs[i] - rhs[i] | < epsilon,
                       static_cast<T>(0),
   * same for y-coordinate, z-coordinate, and w-coordinate.
                       static_cast<T>(0),
   */
                       static_cast<T>(1)) * matrix4<T>::create_translation(-eye_pos.x, -eye_pos.y, -eye_pos.z);
  inline bool constexpr operator==(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    */
    #ifdef VMATH_SOFT_COMPARE
  }
      return std::abs(data[ 0] - rhs.data[ 0]) < static_cast<T>(epsilon) &&
  inline static matrix4<T> constexpr createLookAt(vector3<T> const &eye_pos, vector3<T> const &centre_pos, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_look_at()"))) {
             std::abs(data[ 1] - rhs.data[ 1]) < static_cast<T>(epsilon) &&
    return create_look_at(eye_pos, centre_pos, up_dir);
             std::abs(data[ 2] - rhs.data[ 2]) < static_cast<T>(epsilon) &&
  }
             std::abs(data[ 3] - rhs.data[ 3]) < static_cast<T>(epsilon) &&

             std::abs(data[ 4] - rhs.data[ 4]) < static_cast<T>(epsilon) &&
  /**
             std::abs(data[ 5] - rhs.data[ 5]) < static_cast<T>(epsilon) &&
   * Creates OpenGL compatible perspective projection according to specified frustum parameters.
             std::abs(data[ 6] - rhs.data[ 6]) < static_cast<T>(epsilon) &&
   *
             std::abs(data[ 7] - rhs.data[ 7]) < static_cast<T>(epsilon) &&
   * @param left Specify the coordinate for the left vertical clipping plane,
             std::abs(data[ 8] - rhs.data[ 8]) < static_cast<T>(epsilon) &&
   * @param right Specify the coordinate for the right vertical clipping plane.
             std::abs(data[ 9] - rhs.data[ 9]) < static_cast<T>(epsilon) &&
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
             std::abs(data[10] - rhs.data[10]) < static_cast<T>(epsilon) &&
   * @param top Specify the coordinate for the top horizontal clipping plane.
             std::abs(data[11] - rhs.data[11]) < static_cast<T>(epsilon) &&
   * @param zNear Specify the distance to the near clipping plane.  Distance must be positive.
             std::abs(data[12] - rhs.data[12]) < static_cast<T>(epsilon) &&
   * @param zFar Specify the distance to the far depth clipping plane.  Distance must be positive.
             std::abs(data[13] - rhs.data[13]) < static_cast<T>(epsilon) &&
   *
             std::abs(data[14] - rhs.data[14]) < static_cast<T>(epsilon) &&
   * @return Projection matrix for specified frustum.
             std::abs(data[15] - rhs.data[15]) < static_cast<T>(epsilon);
   */
    #else
  inline static matrix4<T> constexpr create_frustum(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) {
      return data[ 0] == rhs.data[ 0] &&
    /*
             data[ 1] == rhs.data[ 1] &&
     *    2 zNear
             data[ 2] == rhs.data[ 2] &&
     *  ------------       0              A              0
             data[ 3] == rhs.data[ 3] &&
     *  right - left
             data[ 4] == rhs.data[ 4] &&
     *
             data[ 5] == rhs.data[ 5] &&
     *                  2 zNear
             data[ 6] == rhs.data[ 6] &&
             data[ 7] == rhs.data[ 7] &&
     *      0         ------------        B              0
             data[ 8] == rhs.data[ 8] &&
     *                top - bottom
             data[ 9] == rhs.data[ 9] &&
     *
             data[10] == rhs.data[10] &&
     *      0              0              C              D
             data[11] == rhs.data[11] &&
     *
             data[12] == rhs.data[12] &&
     *      0              0              -1             0
             data[13] == rhs.data[13] &&
     *
             data[14] == rhs.data[14] &&
     *  A =   (right + left) / (right - left)
             data[15] == rhs.data[15];
     *  B =   (top + bottom) / (top - bottom)
    #endif // VMATH_SOFT_COMPARE
     *  C = - (zFar + zNear) / (zFar - zNear)
  }
     *  D = - (2 zFar zNear) / (zFar - zNear)

     */
  /**
    return matrix4<T>(static_cast<T>(2) * zNear / (right - left),
   * Inequality test operator
                      static_cast<T>(0),
   * @param rhs Right hand side argument of binary operator.
                      static_cast<T>(0),
   * @return not (lhs == rhs) :-P
                      static_cast<T>(0),
   */

  inline bool constexpr operator!=(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0),
    return !(*this == rhs);
                      static_cast<T>(2) * zNear / (top - bottom),
  }
                      static_cast<T>(0),

                      static_cast<T>(0),
  //---------------------[ access operators ]---------------------------------

  /**
                       (right + left) / (right - left),
   * Get reference to element at postion (x,y).
                       (top + bottom) / (top - bottom),
   * @param x Number of column (0..3)
                      -(zFar + zNear) / (zFar - zNear),
   * @param y Number of row (0..3)
                      static_cast<T>(-1),
   */

  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0),
    return data[x * 4 + y];
                      static_cast<T>(0),
  }
                      static_cast<T>(-2) * zNear * zFar / (zFar - zNear),

                      static_cast<T>(1));
  /**
  }
   * Get constant reference to element at position (x,y).
  inline static matrix4<T> constexpr createFrustum(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_frustum()"))) {
   * @param x Number of column (0..3)
    return create_frustum(left, right, bottom, top, zNear, zFar);
   * @param y Number of row (0..3)
  }
   */

  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
  /**
    return data[x * 4 + y];
   * Creates OpenGL compatible orthographic projection matrix.
  }

   * @param left Specify the coordinate for the left vertical clipping plane,
  /**
   * @param right Specify the coordinate for the right vertical clipping plane.
   * Get reference to element at position (i,j), with math matrix notation
   * @param bottom Specify the coordinate for the bottom horizontal clipping plane,
   * @param i Number of row (1..4)
   * @param top Specify the coordinate for the top horizontal clipping plane.
   * @param j Number of column (1..4)
   * @param zNear Specify the distance to the nearer depth clipping plane.
   */
   *       This value is negative if the plane is to be behind the viewer,
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
   * @param zFar Specify the distance to the farther depth clipping plane.
    return data[(j - 1) * 4 + i - 1];
   *       This value is negative if the plane is to be behind the viewer.
  }
   * @return Othrographic projection matrix.

   */
  /**
  inline static matrix4<T> constexpr create_ortho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) {
   * Get constant reference to element at position (i,j), with math matrix notation
    /*      2
   * @param i Number of row (1..4)
     *  ------------       0              0              tx
   * @param j Number of column (1..4)
     *  right - left
   */
     *                     2
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
     *      0         ------------        0              ty
    return data[(j - 1) * 4 + i - 1];
     *                top - bottom
  }
     *                                    -2

     *      0              0         ------------        tz
  /**
     *                                zFar-zNear
   * Sets translation part of matrix.
     *
   *
     *      0              0              0              1
   * @param v Vector of translation to be set.
     *
   */
     *    tx = - (right + left) / (right - left)
  inline void constexpr set_translation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {
     *    ty = - (top + bottom) / (top - bottom)
    data[12] = v.x;
     *    tz = - (zFar + zNear) / (zFar - zNear)
    data[13] = v.y;
     */
    data[14] = v.z;
    data[15] = 1;
    return matrix4<T>(static_cast<T>(2) / (right - left), static_cast<T>(0),                  static_cast<T>(0),                   static_cast<T>(0),
  }
                      static_cast<T>(0),                  static_cast<T>(2) / (top - bottom), static_cast<T>(0),                   static_cast<T>(0),
  inline void constexpr setTranslation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_translation()"))) {
                      static_cast<T>(0),                  static_cast<T>(0),                  static_cast<T>(-2) / (zFar - zNear), static_cast<T>(0),
    set_translation(v);
                      -(right + left)   / (right - left), -(top + bottom)   / (top - bottom), -(zFar + zNear)    / (zFar - zNear), static_cast<T>(1));
  }
  }

  inline static matrix4<T> constexpr createOrtho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_ortho()"))) {
  /**
    return create_ortho(left, right, bottom, top, zNear, zFar);
   * Returns translation part of matrix.
  }
   */

  inline vector3<T> constexpr get_translation() const noexcept __attribute__((__always_inline__)) {
  /**
    return vector3<T>(data[12], data[13], data[14]);
   * Creates new matrix 4x4 from array that represents such matrix 4x4
  }
   * as array of tightly packed elements in row major order.
  inline vector3<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_translation()"))) {
   * @param arr An array of elements for 4x4 matrix in row major order.
    return get_translation();
   * @return An instance of matrix4<T> representing @a arr
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline static matrix4<T> constexpr from_row_major_array(FromT const *arr) noexcept {
   * Sets rotation part (matrix 3x3) of matrix.
    return matrix4<T>(static_cast<T>(arr[0]), static_cast<T>(arr[4]), static_cast<T>(arr[8]),  static_cast<T>(arr[12]),
   *
                      static_cast<T>(arr[1]), static_cast<T>(arr[5]), static_cast<T>(arr[9]),  static_cast<T>(arr[13]),
   * @param m Rotation part of matrix
   */
                      static_cast<T>(arr[2]), static_cast<T>(arr[6]), static_cast<T>(arr[10]), static_cast<T>(arr[14]),
  inline void constexpr set_rotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(arr[3]), static_cast<T>(arr[7]), static_cast<T>(arr[11]), static_cast<T>(arr[15]));
    data[ 0] = m.data[0];
  }
    data[ 1] = m.data[1];
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
    data[ 2] = m.data[2];
  inline static matrix4<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
    data[ 4] = m.data[3];
    return from_row_major_array(arr);
    data[ 5] = m.data[4];
  }
    data[ 6] = m.data[5];

    data[ 8] = m.data[6];
  /**
    data[ 9] = m.data[7];
   * Creates new matrix 4x4 from array that represents such matrix 4x4
    data[10] = m.data[8];
   * as array of tightly packed elements in column major order.
  }
   * @param arr An array of elements for 4x4 matrix in column major order.
  inline void constexpr setRotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_rotation()"))) {
   * @return An instance of matrix4<T> representing @a arr
    set_rotation(m);
   */
  }
  template<typename FromT> __attribute__((__always_inline__))

  inline static matrix4<T> constexpr from_column_major_array(FromT const *arr) noexcept {
  /**
    return matrix4<T>(static_cast<T>(arr[0]),  static_cast<T>(arr[1]),  static_cast<T>(arr[2]),  static_cast<T>(arr[3]),
   * Returns rotation (matrix 3x3) part of matrix.
   */
                      static_cast<T>(arr[4]),  static_cast<T>(arr[5]),  static_cast<T>(arr[6]),  static_cast<T>(arr[7]),
  inline matrix3<T> constexpr get_rotation() const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(arr[8]),  static_cast<T>(arr[9]),  static_cast<T>(arr[10]), static_cast<T>(arr[11]),
    return matrix3<T>(data[ 0], data[ 1], data[ 2],
                      static_cast<T>(arr[12]), static_cast<T>(arr[13]), static_cast<T>(arr[14]), static_cast<T>(arr[15]));
                      data[ 4], data[ 5], data[ 6],
  }
                      data[ 8], data[ 9], data[10]);
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
  }
  inline static matrix4<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
  inline matrix3<T> constexpr getRotation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_rotation()"))) {
    return from_column_major_array(arr);
    return get_rotation();
  }
  }


  //---------------------[ Equality operators ]------------------------------
  /**
  /**
   * Copy operator
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   * @note Test of equality is based of threshold epsilon value. To be two
  inline matrix4<T> constexpr &operator=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * values equal, must satisfy this condition all elements of matrix
    //std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 16);
   * | lhs[i] - rhs[i] | < epsilon,
    data = rhs.data;
   * same for y-coordinate, z-coordinate, and w-coordinate.
    return *this;
   */
  }
  inline bool constexpr operator==(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    #ifdef VMATH_SOFT_COMPARE
  /**
      return std::abs(data[ 0] - rhs.data[ 0]) < static_cast<T>(epsilon) &&
   * Copy casting operator
             std::abs(data[ 1] - rhs.data[ 1]) < static_cast<T>(epsilon) &&
   * @param rhs Right hand side argument of binary operator.
             std::abs(data[ 2] - rhs.data[ 2]) < static_cast<T>(epsilon) &&
   */
             std::abs(data[ 3] - rhs.data[ 3]) < static_cast<T>(epsilon) &&
  template<typename FromT> __attribute__((__always_inline__))
             std::abs(data[ 4] - rhs.data[ 4]) < static_cast<T>(epsilon) &&
  inline matrix4<T> constexpr &operator=(matrix4<FromT> const &rhs) noexcept {
             std::abs(data[ 5] - rhs.data[ 5]) < static_cast<T>(epsilon) &&
    data[ 0] = static_cast<T>(rhs.data[ 0]);
             std::abs(data[ 6] - rhs.data[ 6]) < static_cast<T>(epsilon) &&
    data[ 1] = static_cast<T>(rhs.data[ 1]);
             std::abs(data[ 7] - rhs.data[ 7]) < static_cast<T>(epsilon) &&
    data[ 2] = static_cast<T>(rhs.data[ 2]);
             std::abs(data[ 8] - rhs.data[ 8]) < static_cast<T>(epsilon) &&
    data[ 3] = static_cast<T>(rhs.data[ 3]);
             std::abs(data[ 9] - rhs.data[ 9]) < static_cast<T>(epsilon) &&
    data[ 4] = static_cast<T>(rhs.data[ 4]);
             std::abs(data[10] - rhs.data[10]) < static_cast<T>(epsilon) &&
    data[ 5] = static_cast<T>(rhs.data[ 5]);
             std::abs(data[11] - rhs.data[11]) < static_cast<T>(epsilon) &&
    data[ 6] = static_cast<T>(rhs.data[ 6]);
             std::abs(data[12] - rhs.data[12]) < static_cast<T>(epsilon) &&
    data[ 7] = static_cast<T>(rhs.data[ 7]);
             std::abs(data[13] - rhs.data[13]) < static_cast<T>(epsilon) &&
    data[ 8] = static_cast<T>(rhs.data[ 8]);
             std::abs(data[14] - rhs.data[14]) < static_cast<T>(epsilon) &&
    data[ 9] = static_cast<T>(rhs.data[ 9]);
             std::abs(data[15] - rhs.data[15]) < static_cast<T>(epsilon);
    data[10] = static_cast<T>(rhs.data[10]);
    #else
    data[11] = static_cast<T>(rhs.data[11]);
      return data[ 0] == rhs.data[ 0] &&
    data[12] = static_cast<T>(rhs.data[12]);
             data[ 1] == rhs.data[ 1] &&
    data[13] = static_cast<T>(rhs.data[13]);
             data[ 2] == rhs.data[ 2] &&
    data[14] = static_cast<T>(rhs.data[14]);
             data[ 3] == rhs.data[ 3] &&
    data[15] = static_cast<T>(rhs.data[15]);
             data[ 4] == rhs.data[ 4] &&
    return *this;
             data[ 5] == rhs.data[ 5] &&
  }
             data[ 6] == rhs.data[ 6] &&

             data[ 7] == rhs.data[ 7] &&
  /**
             data[ 8] == rhs.data[ 8] &&
   * Copy operator
             data[ 9] == rhs.data[ 9] &&
   * @param rhs Right hand side argument of binary operator.
             data[10] == rhs.data[10] &&
   */
             data[11] == rhs.data[11] &&
  inline matrix4<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
             data[12] == rhs.data[12] &&
    /*
             data[13] == rhs.data[13] &&
    for(int i = 0; i != 16; ++i) {
             data[14] == rhs.data[14] &&
      data[i] = (T)rhs[i];
             data[15] == rhs.data[15];
    }
    #endif // VMATH_SOFT_COMPARE
    */
  }
    std::memcpy(data.data(), rhs, sizeof(T) * 16);

    return *this;
  /**
  }

   * Inequality test operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Move assignment operator
   * @return not (lhs == rhs) :-P
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline bool constexpr operator!=(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return !(*this == rhs);
  inline matrix4<T> constexpr &operator=(matrix4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
  }
    data = std::move(rhs.data);

    return *this;
  //---------------------[ access operators ]---------------------------------
  }
  /**

   * Get reference to element at postion (x,y).
  /**
   * @param x Number of column (0..3)
   * Move assignment casting operator
   * @param y Number of row (0..3)
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return data[x * 4 + y];
  inline matrix4<T> constexpr &operator=(matrix4<FromT> &&rhs) noexcept {
  }
    data[ 0] = static_cast<T>(std::move(rhs.data[ 0]));

    data[ 1] = static_cast<T>(std::move(rhs.data[ 1]));
  /**
    data[ 2] = static_cast<T>(std::move(rhs.data[ 2]));
   * Get constant reference to element at position (x,y).
    data[ 3] = static_cast<T>(std::move(rhs.data[ 3]));
   * @param x Number of column (0..3)
    data[ 4] = static_cast<T>(std::move(rhs.data[ 4]));
   * @param y Number of row (0..3)
    data[ 5] = static_cast<T>(std::move(rhs.data[ 5]));
   */
    data[ 6] = static_cast<T>(std::move(rhs.data[ 6]));
    data[ 7] = static_cast<T>(std::move(rhs.data[ 7]));
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
    data[ 8] = static_cast<T>(std::move(rhs.data[ 8]));
    return data[x * 4 + y];
    data[ 9] = static_cast<T>(std::move(rhs.data[ 9]));
  }
    data[10] = static_cast<T>(std::move(rhs.data[10]));

    data[11] = static_cast<T>(std::move(rhs.data[11]));
  /**
    data[12] = static_cast<T>(std::move(rhs.data[12]));
   * Get reference to element at position (i,j), with math matrix notation
    data[13] = static_cast<T>(std::move(rhs.data[13]));
   * @param i Number of row (1..4)
    data[14] = static_cast<T>(std::move(rhs.data[14]));
   * @param j Number of column (1..4)
    data[15] = static_cast<T>(std::move(rhs.data[15]));
   */
    return *this;
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
  }
    return data[(j - 1) * 4 + i - 1];

  }
  //--------------------[ matrix with matrix operations ]---------------------

  /**
  /**
   * Addition operator
   * Get constant reference to element at position (i,j), with math matrix notation
   * @param rhs Right hand side argument of binary operator.
   * @param i Number of row (1..4)
   */
   * @param j Number of column (1..4)
  inline matrix4<T> constexpr operator+(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix4<T>(data[ 0] + rhs.data[ 0], data[ 1] + rhs.data[ 1], data[ 2] + rhs.data[ 2], data[ 3] + rhs.data[ 3],
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
                      data[ 4] + rhs.data[ 4], data[ 5] + rhs.data[ 5], data[ 6] + rhs.data[ 6], data[ 7] + rhs.data[ 7],
    return data[(j - 1) * 4 + i - 1];
                      data[ 8] + rhs.data[ 8], data[ 9] + rhs.data[ 9], data[10] + rhs.data[10], data[11] + rhs.data[11],
  }
                      data[12] + rhs.data[12], data[13] + rhs.data[13], data[14] + rhs.data[14], data[15] + rhs.data[15]);

  }
  /**

   * Sets translation part of matrix.
  /**
   *
   * Subtraction operator
   * @param v Vector of translation to be set.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline void constexpr set_translation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) {
  inline matrix4<T> constexpr operator-(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    data[12] = v.x;
    return matrix4<T>(data[ 0] - rhs.data[ 0], data[ 1] - rhs.data[ 1], data[ 2] - rhs.data[ 2], data[ 3] - rhs.data[ 3],
    data[13] = v.y;
                      data[ 4] - rhs.data[ 4], data[ 5] - rhs.data[ 5], data[ 6] - rhs.data[ 6], data[ 7] - rhs.data[ 7],
    data[14] = v.z;
    data[15] = 1;
                      data[ 8] - rhs.data[ 8], data[ 9] - rhs.data[ 9], data[10] - rhs.data[10], data[11] - rhs.data[11],
  }
                      data[12] - rhs.data[12], data[13] - rhs.data[13], data[14] - rhs.data[14], data[15] - rhs.data[15]);
  }
  inline void constexpr setTranslation(vector3<T> const &v) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_translation()"))) {

    set_translation(v);
  //--------------------[ matrix with scalar operations ]---------------------
  }
  /**

   * Addition operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Returns translation part of matrix.
   */
   */
  inline matrix4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline vector3<T> constexpr get_translation() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] + rhs, data[ 1] + rhs, data[ 2] + rhs, data[ 3] + rhs,
    return vector3<T>(data[12], data[13], data[14]);
                      data[ 4] + rhs, data[ 5] + rhs, data[ 6] + rhs, data[ 7] + rhs,
  }
                      data[ 8] + rhs, data[ 9] + rhs, data[10] + rhs, data[11] + rhs,
  inline vector3<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_translation()"))) {
                      data[12] + rhs, data[13] + rhs, data[14] + rhs, data[15] + rhs);
    return get_translation();
  }
  }


  /**
  /**
   * Subtraction operator
   * Sets rotation part (matrix 3x3) of matrix.
   * @param rhs Right hand side argument of binary operator.
   *
   */
   * @param m Rotation part of matrix
  inline matrix4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix4<T>(data[ 0] - rhs, data[ 1] - rhs, data[ 2] - rhs, data[ 3] - rhs,
  inline void constexpr set_rotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) {
                      data[ 4] - rhs, data[ 5] - rhs, data[ 6] - rhs, data[ 7] - rhs,
    data[ 0] = m.data[0];
                      data[ 8] - rhs, data[ 9] - rhs, data[10] - rhs, data[11] - rhs,
    data[ 1] = m.data[1];
                      data[12] - rhs, data[13] - rhs, data[14] - rhs, data[15] - rhs);
    data[ 2] = m.data[2];
  }
    data[ 4] = m.data[3];

    data[ 5] = m.data[4];
  /**
    data[ 6] = m.data[5];
   * Multiplication operator
    data[ 8] = m.data[6];
   * @param rhs Right hand side argument of binary operator.
    data[ 9] = m.data[7];
   */
    data[10] = m.data[8];
  inline matrix4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return matrix4<T>(data[ 0] * rhs, data[ 1] * rhs, data[ 2] * rhs, data[ 3] * rhs,
  inline void constexpr setRotation(matrix3<T> const &m) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use set_rotation()"))) {
                      data[ 4] * rhs, data[ 5] * rhs, data[ 6] * rhs, data[ 7] * rhs,
    set_rotation(m);
                      data[ 8] * rhs, data[ 9] * rhs, data[10] * rhs, data[11] * rhs,
  }
                      data[12] * rhs, data[13] * rhs, data[14] * rhs, data[15] * rhs);

  }
  /**

   * Returns rotation (matrix 3x3) part of matrix.
  /**
   */
   * Division operator
  inline matrix3<T> constexpr get_rotation() const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return matrix3<T>(data[ 0], data[ 1], data[ 2],
   */
                      data[ 4], data[ 5], data[ 6],
  inline matrix4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
                      data[ 8], data[ 9], data[10]);
    return matrix4<T>(data[ 0] / rhs, data[ 1] / rhs, data[ 2] / rhs, data[ 3] / rhs,
  }
                      data[ 4] / rhs, data[ 5] / rhs, data[ 6] / rhs, data[ 7] / rhs,
  inline matrix3<T> constexpr getRotation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_rotation()"))) {
                      data[ 8] / rhs, data[ 9] / rhs, data[10] / rhs, data[11] / rhs,
    return get_rotation();
                      data[12] / rhs, data[13] / rhs, data[14] / rhs, data[15] / rhs);
  }
  }


  /**
  /**
   * Copy operator
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix4<T> constexpr &operator=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline matrix4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    //std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 16);
    *this = *this + rhs;
    data = rhs.data;
    return *this;
    return *this;
  }
  }


  /**
  /**
   * Subtraction operator
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    *this = *this - rhs;
    return *this;
  inline matrix4<T> constexpr &operator=(matrix4<FromT> const &rhs) noexcept {
  }
    data[ 0] = static_cast<T>(rhs.data[ 0]);

    data[ 1] = static_cast<T>(rhs.data[ 1]);
  /**
    data[ 2] = static_cast<T>(rhs.data[ 2]);
   * Multiplication operator
    data[ 3] = static_cast<T>(rhs.data[ 3]);
   * @param rhs Right hand side argument of binary operator.
    data[ 4] = static_cast<T>(rhs.data[ 4]);
   */
    data[ 5] = static_cast<T>(rhs.data[ 5]);
  inline matrix4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    data[ 6] = static_cast<T>(rhs.data[ 6]);
    *this = *this * rhs;
    data[ 7] = static_cast<T>(rhs.data[ 7]);
    return *this;
    data[ 8] = static_cast<T>(rhs.data[ 8]);
  }
    data[ 9] = static_cast<T>(rhs.data[ 9]);

    data[10] = static_cast<T>(rhs.data[10]);
  /**
    data[11] = static_cast<T>(rhs.data[11]);
   * Division operator
    data[12] = static_cast<T>(rhs.data[12]);
   * @param rhs Right hand side argument of binary operator.
    data[13] = static_cast<T>(rhs.data[13]);
   */
    data[14] = static_cast<T>(rhs.data[14]);
  inline matrix4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    data[15] = static_cast<T>(rhs.data[15]);
    *this = *this / rhs;
    return *this;
    return *this;
  }
  }


  /**
  //--------------------[ multiply operators ]--------------------------------
   * Copy operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix4<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
   */
    /*
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    for(int i = 0; i != 16; ++i) {
    return vector4<T>(data[0] * rhs.x + data[4] * rhs.y + data[ 8] * rhs.z + data[12] * rhs.w,
      data[i] = (T)rhs[i];
                      data[1] * rhs.x + data[5] * rhs.y + data[ 9] * rhs.z + data[13] * rhs.w,
    }
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z + data[14] * rhs.w,
    */
                      data[3] * rhs.x + data[7] * rhs.y + data[11] * rhs.z + data[15] * rhs.w);
    std::memcpy(data.data(), rhs, sizeof(T) * 16);
  }
    return *this;

  }
  /**

   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Move assignment operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector3<T>(data[0] * rhs.x + data[4] * rhs.y + data[8]  * rhs.z,
  inline matrix4<T> constexpr &operator=(matrix4<T> &&rhs) noexcept __attribute__((__always_inline__)) {
                      data[1] * rhs.x + data[5] * rhs.y + data[9]  * rhs.z,
    data = std::move(rhs.data);
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z);
    return *this;
  }
  }


  /**
  /**
   * Multiplication operator
   * Move assignment casting operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix4<T> constexpr operator*(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return matrix4<T>(rhs.data[ 0] * data[ 0] + rhs.data[ 1] * data[ 4] + rhs.data[ 2] * data[ 8] + rhs.data[ 3] * data[12],
  inline matrix4<T> constexpr &operator=(matrix4<FromT> &&rhs) noexcept {
                      rhs.data[ 0] * data[ 1] + rhs.data[ 1] * data[ 5] + rhs.data[ 2] * data[ 9] + rhs.data[ 3] * data[13],
    data[ 0] = static_cast<T>(std::move(rhs.data[ 0]));
                      rhs.data[ 0] * data[ 2] + rhs.data[ 1] * data[ 6] + rhs.data[ 2] * data[10] + rhs.data[ 3] * data[14],
    data[ 1] = static_cast<T>(std::move(rhs.data[ 1]));
                      rhs.data[ 0] * data[ 3] + rhs.data[ 1] * data[ 7] + rhs.data[ 2] * data[11] + rhs.data[ 3] * data[15],
    data[ 2] = static_cast<T>(std::move(rhs.data[ 2]));

    data[ 3] = static_cast<T>(std::move(rhs.data[ 3]));
                      rhs.data[ 4] * data[ 0] + rhs.data[ 5] * data[ 4] + rhs.data[ 6] * data[ 8] + rhs.data[ 7] * data[12],
    data[ 4] = static_cast<T>(std::move(rhs.data[ 4]));
                      rhs.data[ 4] * data[ 1] + rhs.data[ 5] * data[ 5] + rhs.data[ 6] * data[ 9] + rhs.data[ 7] * data[13],
    data[ 5] = static_cast<T>(std::move(rhs.data[ 5]));
                      rhs.data[ 4] * data[ 2] + rhs.data[ 5] * data[ 6] + rhs.data[ 6] * data[10] + rhs.data[ 7] * data[14],
    data[ 6] = static_cast<T>(std::move(rhs.data[ 6]));
                      rhs.data[ 4] * data[ 3] + rhs.data[ 5] * data[ 7] + rhs.data[ 6] * data[11] + rhs.data[ 7] * data[15],
    data[ 7] = static_cast<T>(std::move(rhs.data[ 7]));

    data[ 8] = static_cast<T>(std::move(rhs.data[ 8]));
                      rhs.data[ 8] * data[ 0] + rhs.data[ 9] * data[ 4] + rhs.data[10] * data[ 8] + rhs.data[11] * data[12],
    data[ 9] = static_cast<T>(std::move(rhs.data[ 9]));
                      rhs.data[ 8] * data[ 1] + rhs.data[ 9] * data[ 5] + rhs.data[10] * data[ 9] + rhs.data[11] * data[13],
    data[10] = static_cast<T>(std::move(rhs.data[10]));
    data[11] = static_cast<T>(std::move(rhs.data[11]));
                      rhs.data[ 8] * data[ 2] + rhs.data[ 9] * data[ 6] + rhs.data[10] * data[10] + rhs.data[11] * data[14],
    data[12] = static_cast<T>(std::move(rhs.data[12]));
                      rhs.data[ 8] * data[ 3] + rhs.data[ 9] * data[ 7] + rhs.data[10] * data[11] + rhs.data[11] * data[15],
    data[13] = static_cast<T>(std::move(rhs.data[13]));

    data[14] = static_cast<T>(std::move(rhs.data[14]));
                      rhs.data[12] * data[ 0] + rhs.data[13] * data[ 4] + rhs.data[14] * data[ 8] + rhs.data[15] * data[12],
    data[15] = static_cast<T>(std::move(rhs.data[15]));
                      rhs.data[12] * data[ 1] + rhs.data[13] * data[ 5] + rhs.data[14] * data[ 9] + rhs.data[15] * data[13],
    return *this;
                      rhs.data[12] * data[ 2] + rhs.data[13] * data[ 6] + rhs.data[14] * data[10] + rhs.data[15] * data[14],
  }
                      rhs.data[12] * data[ 3] + rhs.data[13] * data[ 7] + rhs.data[14] * data[11] + rhs.data[15] * data[15]);

  }
  //--------------------[ matrix with matrix operations ]---------------------

  /**
  /**
   * Addition operator
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix4<T> constexpr operator+(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline matrix4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] + rhs.data[ 0], data[ 1] + rhs.data[ 1], data[ 2] + rhs.data[ 2], data[ 3] + rhs.data[ 3],
    *this = *this * rhs;
                      data[ 4] + rhs.data[ 4], data[ 5] + rhs.data[ 5], data[ 6] + rhs.data[ 6], data[ 7] + rhs.data[ 7],
    return *this;
  }
                      data[ 8] + rhs.data[ 8], data[ 9] + rhs.data[ 9], data[10] + rhs.data[10], data[11] + rhs.data[11],

                      data[12] + rhs.data[12], data[13] + rhs.data[13], data[14] + rhs.data[14], data[15] + rhs.data[15]);
  //---------------------------[ misc operations ]----------------------------
  }


  /**
  /**
   * Computes determinant of matrix
   * Subtraction operator
   * @return Determinant of matrix
   * @param rhs Right hand side argument of binary operator.
   * @note This function does 3 * 4 * 6 mul, 3 * 6 add.
   */
   */
  inline matrix4<T> constexpr operator-(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[ 0] - rhs.data[ 0], data[ 1] - rhs.data[ 1], data[ 2] - rhs.data[ 2], data[ 3] - rhs.data[ 3],
    return   data[12] * data[9] * data[6]  * data[3]  - data[8] * data[13] * data[6]  * data[3]
                      data[ 4] - rhs.data[ 4], data[ 5] - rhs.data[ 5], data[ 6] - rhs.data[ 6], data[ 7] - rhs.data[ 7],
           - data[12] * data[5] * data[10] * data[3]  + data[4] * data[13] * data[10] * data[3]
                      data[ 8] - rhs.data[ 8], data[ 9] - rhs.data[ 9], data[10] - rhs.data[10], data[11] - rhs.data[11],

                      data[12] - rhs.data[12], data[13] - rhs.data[13], data[14] - rhs.data[14], data[15] - rhs.data[15]);
           + data[8]  * data[5] * data[14] * data[3]  - data[4] * data[9]  * data[14] * data[3]
  }
           - data[12] * data[9] * data[2]  * data[7]  + data[8] * data[13] * data[2]  * data[7]


  //--------------------[ matrix with scalar operations ]---------------------
           + data[12] * data[1] * data[10] * data[7]  - data[0] * data[13] * data[10] * data[7]
  /**
           - data[8]  * data[1] * data[14] * data[7]  + data[0] * data[9]  * data[14] * data[7]
   * Addition operator

   * @param rhs Right hand side argument of binary operator.
           + data[12] * data[5] * data[2]  * data[11] - data[4] * data[13] * data[2]  * data[11]
   */
           - data[12] * data[1] * data[6]  * data[11] + data[0] * data[13] * data[6]  * data[11]
  inline matrix4<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {

    return matrix4<T>(data[ 0] + rhs, data[ 1] + rhs, data[ 2] + rhs, data[ 3] + rhs,
           + data[4]  * data[1] * data[14] * data[11] - data[0] * data[5]  * data[14] * data[11]
                      data[ 4] + rhs, data[ 5] + rhs, data[ 6] + rhs, data[ 7] + rhs,
           - data[8]  * data[5] * data[2]  * data[15] + data[4] * data[9]  * data[2]  * data[15]
                      data[ 8] + rhs, data[ 9] + rhs, data[10] + rhs, data[11] + rhs,

                      data[12] + rhs, data[13] + rhs, data[14] + rhs, data[15] + rhs);
           + data[8]  * data[1] * data[6]  * data[15] - data[0] * data[9]  * data[6]  * data[15]
  }
           - data[4]  * data[1] * data[10] * data[15] + data[0] * data[5]  * data[10] * data[15];

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Computes inverse matrix
   */
   * @return Inverse matrix of this matrix.
  inline matrix4<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @note This is a little bit time consuming operation
    return matrix4<T>(data[ 0] - rhs, data[ 1] - rhs, data[ 2] - rhs, data[ 3] - rhs,
   * (16 * 6 * 3 mul, 16 * 5 add + det() + mul() functions)
                      data[ 4] - rhs, data[ 5] - rhs, data[ 6] - rhs, data[ 7] - rhs,
   */
                      data[ 8] - rhs, data[ 9] - rhs, data[10] - rhs, data[11] - rhs,
  inline matrix4<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
                      data[12] - rhs, data[13] - rhs, data[14] - rhs, data[15] - rhs);
    return matrix4<T>(data[9]  * data[14] * data[7]  - data[13] * data[10] * data[7]  + data[13] * data[6]  * data[11] -
  }
                      data[5]  * data[14] * data[11] - data[9]  * data[6]  * data[15] + data[5]  * data[10] * data[15],

                      data[13] * data[10] * data[3]  - data[9]  * data[14] * data[3]  - data[13] * data[2]  * data[11] +
  /**
                      data[1]  * data[14] * data[11] + data[9]  * data[2]  * data[15] - data[1]  * data[10] * data[15],
   * Multiplication operator
                      data[5]  * data[14] * data[3]  - data[13] * data[6]  * data[3]  + data[13] * data[2]  * data[7] -
   * @param rhs Right hand side argument of binary operator.
                      data[1]  * data[14] * data[7]  - data[5]  * data[2]  * data[15] + data[1]  * data[6]  * data[15],
   */
                      data[9]  * data[6]  * data[3]  - data[5]  * data[10] * data[3]  - data[9]  * data[2]  * data[7] +
  inline matrix4<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
                      data[1]  * data[10] * data[7]  + data[5]  * data[2]  * data[11] - data[1]  * data[6]  * data[11],
    return matrix4<T>(data[ 0] * rhs, data[ 1] * rhs, data[ 2] * rhs, data[ 3] * rhs,
                      data[12] * data[10] * data[7]  - data[8]  * data[14] * data[7]  - data[12] * data[6]  * data[11] +
                      data[ 4] * rhs, data[ 5] * rhs, data[ 6] * rhs, data[ 7] * rhs,
                      data[4]  * data[14] * data[11] + data[8]  * data[6]  * data[15] - data[4]  * data[10] * data[15],
                      data[ 8] * rhs, data[ 9] * rhs, data[10] * rhs, data[11] * rhs,
                      data[8]  * data[14] * data[3]  - data[12] * data[10] * data[3]  + data[12] * data[2]  * data[11] -
                      data[12] * rhs, data[13] * rhs, data[14] * rhs, data[15] * rhs);
                      data[0]  * data[14] * data[11] - data[8]  * data[2]  * data[15] + data[0]  * data[10] * data[15],
  }

                      data[12] * data[6]  * data[3]  - data[4]  * data[14] * data[3]  - data[12] * data[2]  * data[7] +
  /**
                      data[0]  * data[14] * data[7]  + data[4]  * data[2]  * data[15] - data[0]  * data[6]  * data[15],
   * Division operator
                      data[4]  * data[10] * data[3]  - data[8]  * data[6]  * data[3]  + data[8]  * data[2]  * data[7] -
   * @param rhs Right hand side argument of binary operator.
                      data[0]  * data[10] * data[7]  - data[4]  * data[2]  * data[11] + data[0]  * data[6]  * data[11],
   */
                      data[8]  * data[13] * data[7]  - data[12] * data[9]  * data[7]  + data[12] * data[5]  * data[11] -
  inline matrix4<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
                      data[4]  * data[13] * data[11] - data[8]  * data[5]  * data[15] + data[4]  * data[9]  * data[15],
    return matrix4<T>(data[ 0] / rhs, data[ 1] / rhs, data[ 2] / rhs, data[ 3] / rhs,
                      data[12] * data[9]  * data[3]  - data[8]  * data[13] * data[3]  - data[12] * data[1]  * data[11] +
                      data[ 4] / rhs, data[ 5] / rhs, data[ 6] / rhs, data[ 7] / rhs,
                      data[0]  * data[13] * data[11] + data[8]  * data[1]  * data[15] - data[0]  * data[9]  * data[15],
                      data[ 8] / rhs, data[ 9] / rhs, data[10] / rhs, data[11] / rhs,
                      data[4]  * data[13] * data[3]  - data[12] * data[5]  * data[3]  + data[12] * data[1]  * data[7] -
                      data[12] / rhs, data[13] / rhs, data[14] / rhs, data[15] / rhs);
                      data[0]  * data[13] * data[7]  - data[4]  * data[1]  * data[15] + data[0]  * data[5]  * data[15],
  }
                      data[8]  * data[5]  * data[3]  - data[4]  * data[9]  * data[3]  - data[8]  * data[1]  * data[7] +

                      data[0]  * data[9]  * data[7]  + data[4]  * data[1]  * data[11] - data[0]  * data[5]  * data[11],
  /**
   * Addition operator
                      data[12] * data[9]  * data[6]  - data[8]  * data[13] * data[6]  - data[12] * data[5]  * data[10] +
   * @param rhs Right hand side argument of binary operator.
                      data[4]  * data[13] * data[10] + data[8]  * data[5]  * data[14] - data[4]  * data[9]  * data[14],
   */
                      data[8]  * data[13] * data[2]  - data[12] * data[9]  * data[2]  + data[12] * data[1]  * data[10] -
  inline matrix4<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
                      data[0]  * data[13] * data[10] - data[8]  * data[1]  * data[14] + data[0]  * data[9]  * data[14],
    *this = *this + rhs;
                      data[12] * data[5]  * data[2]  - data[4]  * data[13] * data[2]  - data[12] * data[1]  * data[6] +
    return *this;
                      data[0]  * data[13] * data[6]  + data[4]  * data[1]  * data[14] - data[0]  * data[5]  * data[14],
  }
                      data[4]  * data[9]  * data[2]  - data[8]  * data[5]  * data[2]  + data[8]  * data[1]  * data[6] -

                      data[0]  * data[9]  * data[6]  - data[4]  * data[1]  * data[10] + data[0]  * data[5]  * data[10]) / det();
  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Transpose matrix.
  inline matrix4<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    *this = *this - rhs;
  inline matrix4<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
    return *this;
    return matrix4<T>(data[0], data[4], data[8],  data[12],
  }
                      data[1], data[5], data[9],  data[13],

                      data[2], data[6], data[10], data[14],
  /**
                      data[3], data[7], data[11], data[15]);
   * Multiplication operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline matrix4<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   * Linear interpolation of two matrices
    *this = *this * rhs;
   * @param fact Factor of interpolation. For translation from positon
    return *this;
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.
  }
   * @param rhs Second matrix for interpolation

   * @note However values of fact parameter are reasonable only in interval
  /**
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   * Division operator
   * can get result (extrapolation?)
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix4<T> constexpr lerp(T fact, matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline matrix4<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
    return (*this) + (rhs - (*this)) * fact;
    *this = *this / rhs;
  }
    return *this;

  }
  //-------------[ conversion ]-----------------------------

  /**
  //--------------------[ multiply operators ]--------------------------------
   * Conversion to pointer operator
  /**
   * @return Pointer to internally stored (in management of class matrix4<T>)
   * Multiplication operator
   * used for passing matrix4<T> values to gl*[fd]v functions.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(data.data());
    return vector4<T>(data[0] * rhs.x + data[4] * rhs.y + data[ 8] * rhs.z + data[12] * rhs.w,
  }
                      data[1] * rhs.x + data[5] * rhs.y + data[ 9] * rhs.z + data[13] * rhs.w,

                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z + data[14] * rhs.w,
  /**
                      data[3] * rhs.x + data[7] * rhs.y + data[11] * rhs.z + data[15] * rhs.w);
   * Conversion to pointer operator
  }
   * @return Constant Pointer to internally stored (in management of class matrix4<T>)

   * used for passing matrix4<T> values to gl*[fd]v functions.
  /**
   */
   * Multiplication operator
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return reinterpret_cast<T const*>(data.data());
   */
  }
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return vector3<T>(data[0] * rhs.x + data[4] * rhs.y + data[8]  * rhs.z,
  //----------[ output operator ]----------------------------
                      data[1] * rhs.x + data[5] * rhs.y + data[9]  * rhs.z,
  /**
                      data[2] * rhs.x + data[6] * rhs.y + data[10] * rhs.z);
   * Output to stream operator
  }
   * @param lhs Left hand side argument of operator (commonly ostream instance).

   * @param rhs Right hand side argument of operator.
  /**
   * @return Left hand side argument - the ostream object passed to operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   */
    for(int i = 0; i != 4; ++i) {
  inline matrix4<T> constexpr operator*(matrix4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
      lhs << "|\t";
    return matrix4<T>(rhs.data[ 0] * data[ 0] + rhs.data[ 1] * data[ 4] + rhs.data[ 2] * data[ 8] + rhs.data[ 3] * data[12],
      for(int j = 0; j != 4; ++j) {
                      rhs.data[ 0] * data[ 1] + rhs.data[ 1] * data[ 5] + rhs.data[ 2] * data[ 9] + rhs.data[ 3] * data[13],
        lhs << rhs.at(j, i) << "\t";
                      rhs.data[ 0] * data[ 2] + rhs.data[ 1] * data[ 6] + rhs.data[ 2] * data[10] + rhs.data[ 3] * data[14],
      }
                      rhs.data[ 0] * data[ 3] + rhs.data[ 1] * data[ 7] + rhs.data[ 2] * data[11] + rhs.data[ 3] * data[15],
      lhs << "|" << std::endl;

    }
    return lhs;
                      rhs.data[ 4] * data[ 0] + rhs.data[ 5] * data[ 4] + rhs.data[ 6] * data[ 8] + rhs.data[ 7] * data[12],
  }
                      rhs.data[ 4] * data[ 1] + rhs.data[ 5] * data[ 5] + rhs.data[ 6] * data[ 9] + rhs.data[ 7] * data[13],

                      rhs.data[ 4] * data[ 2] + rhs.data[ 5] * data[ 6] + rhs.data[ 6] * data[10] + rhs.data[ 7] * data[14],
  /**
                      rhs.data[ 4] * data[ 3] + rhs.data[ 5] * data[ 7] + rhs.data[ 6] * data[11] + rhs.data[ 7] * data[15],
   * Gets string representation.

   */
                      rhs.data[ 8] * data[ 0] + rhs.data[ 9] * data[ 4] + rhs.data[10] * data[ 8] + rhs.data[11] * data[12],
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
                      rhs.data[ 8] * data[ 1] + rhs.data[ 9] * data[ 5] + rhs.data[10] * data[ 9] + rhs.data[11] * data[13],
    std::ostringstream oss;
                      rhs.data[ 8] * data[ 2] + rhs.data[ 9] * data[ 6] + rhs.data[10] * data[10] + rhs.data[11] * data[14],
    oss << *this;
                      rhs.data[ 8] * data[ 3] + rhs.data[ 9] * data[ 7] + rhs.data[10] * data[11] + rhs.data[11] * data[15],
    return oss.str();

  }
                      rhs.data[12] * data[ 0] + rhs.data[13] * data[ 4] + rhs.data[14] * data[ 8] + rhs.data[15] * data[12],
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
                      rhs.data[12] * data[ 1] + rhs.data[13] * data[ 5] + rhs.data[14] * data[ 9] + rhs.data[15] * data[13],
    return to_string();
  }
                      rhs.data[12] * data[ 2] + rhs.data[13] * data[ 6] + rhs.data[14] * data[10] + rhs.data[15] * data[14],
};
                      rhs.data[12] * data[ 3] + rhs.data[13] * data[ 7] + rhs.data[14] * data[11] + rhs.data[15] * data[15]);

  }
#ifdef VMATH_NAMESPACE

}
  /**
#endif //VMATH_NAMESPACE
   * Multiplication operator

   * @param rhs Right hand side argument of binary operator.
#include "matrix4_types.h"
   */

  inline matrix4<T> constexpr &operator*=(matrix4<T> const &rhs) noexcept __attribute__((__always_inline__)) {
#endif // VECTORSTORM_MATRIX4_H_INCLUDED
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
