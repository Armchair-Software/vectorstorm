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
  inline constexpr matrix3() noexcept __attribute__((__always_inline__))
#ifndef VECTORSTORM_MATRIX3_H_INCLUDED
    : data{1, 0, 0,
#define VECTORSTORM_MATRIX3_H_INCLUDED
           0, 1, 0,

           0, 0, 1} {
#include "vectorstorm/epsilon.h"
  }


#ifdef VMATH_NAMESPACE
  /**
namespace VMATH_NAMESPACE {
   * Copy matrix values from array (these data must be in column
#endif
   * major order!)

   */
/**
  inline constexpr explicit matrix3(T const *dt) noexcept __attribute__((__always_inline__))
 * Class for matrix 3x3.
    : data{dt[0], dt[1], dt[2],
 * @note Data stored in this matrix are in column major order. This arrangement suits OpenGL.
           dt[3], dt[4], dt[5],
 * If you're using row major matrix, consider using fromRowMajorArray as way for construction
           dt[6], dt[7], dt[8]} {
 * matrix3<T> instance.
  }
 */
  inline constexpr explicit matrix3(T *dt) noexcept __attribute__((__always_inline__))
template<typename T>
    : data{dt[0], dt[1], dt[2],
class matrix3 {
           dt[3], dt[4], dt[5],
public:
           dt[6], dt[7], dt[8]} {
  /// Data stored in column major order
  }
  std::array<T, 9> data;


  /**
  //--------------------------[ constructors ]-------------------------------
   * Copy constructor.
  /**
   * @param src Data source for new created instance of matrix3
   * Creates identity matrix
   */
   */
  inline constexpr explicit matrix3(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
  inline constexpr matrix3() noexcept __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2],
    : data{1, 0, 0,
           src.data[3], src.data[4], src.data[5],
           0, 1, 0,
           src.data[6], src.data[7], src.data[8]} {
           0, 0, 1} {
  }
  }


  /**
  /**
   * Copy casting constructor.
   * Copy matrix values from array (these data must be in column
   * @param src Data source for new created instance of matrix3
   * major order!)
   */
   */
  template<typename FromT> __attribute__((__always_inline__))
  inline constexpr explicit matrix3(T const *dt) noexcept __attribute__((__always_inline__))
  inline constexpr explicit matrix3(matrix3<FromT> const &src) noexcept
    : data{dt[0], dt[1], dt[2],
    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]),
           dt[3], dt[4], dt[5],
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]),
           dt[6], dt[7], dt[8]} {
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8])} {
  }
  }
  inline constexpr explicit matrix3(T *dt) noexcept __attribute__((__always_inline__))

    : data{dt[0], dt[1], dt[2],
  /**
           dt[3], dt[4], dt[5],
   * Move constructor.
           dt[6], dt[7], dt[8]} {
   * @param src Data source for new created instance of matrix3
  }
   */

  inline constexpr matrix3(matrix3<T> &&src) noexcept __attribute__((__always_inline__))
  /**
    : data(std::move(src.data)) {
   * Copy constructor.
  }
   * @param src Data source for new created instance of matrix3

   */
  /**
  inline constexpr explicit matrix3(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
   * Move casting constructor.
    : data{src.data[0], src.data[1], src.data[2],
   * @param src Data source for new created instance of matrix3
           src.data[3], src.data[4], src.data[5],
   */
           src.data[6], src.data[7], src.data[8]} {
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline constexpr matrix3(matrix3<FromT> &&src) noexcept

    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])),
  /**
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])),
   * Copy casting constructor.
           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8]))} {
   * @param src Data source for new created instance of matrix3
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline constexpr explicit matrix3(matrix3<FromT> const &src) noexcept
   * Variadic initialisation constructor
    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]),
   * @param dt Initialiser list containing raw data for each element in order.
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]),
   */
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8])} {
  //inline constexpr matrix3(std::initializer_list<T> dt)
  }
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
  //}

  // see http://stackoverflow.com/a/5549918/1678468
  /**
  template<class... FromT> __attribute__((__always_inline__))
   * Move constructor.
  inline constexpr explicit matrix3(FromT... dt) noexcept
   * @param src Data source for new created instance of matrix3
    : data{dt...} {
   */
  }
  inline constexpr matrix3(matrix3<T> &&src) noexcept __attribute__((__always_inline__))

    : data(std::move(src.data)) {
  /**
  }
   * Resets matrix to be identity matrix

   */
  /**
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
   * Move casting constructor.
    data = {1, 0, 0,
   * @param src Data source for new created instance of matrix3
            0, 1, 0,
   */
            0, 0, 1};
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline constexpr matrix3(matrix3<FromT> &&src) noexcept

    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])),
  /**
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])),
   * Creates rotation matrix by rotation around three axes.
           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8]))} {
   * @param xDeg Angle (in degrees) of rotation around axis X.
  }
   * @param yDeg Angle (in degrees) of rotation around axis Y.

   * @param zDeg Angle (in degrees) of rotation around axis Z.
  /**
   */
   * Variadic initialisation constructor
  inline static matrix3<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
   * @param dt Initialiser list containing raw data for each element in order.
    return create_rotation_around_axis_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
   */
  }
  //inline constexpr matrix3(std::initializer_list<T> dt)
  inline static matrix3<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
  //}
    return create_rotation_around_axis(xDeg, yDeg, zDeg);
  // see http://stackoverflow.com/a/5549918/1678468
  }

  template<class... FromT> __attribute__((__always_inline__))
  /**
  inline constexpr explicit matrix3(FromT... dt) noexcept
   * Creates rotation matrix by rotation around three axes, radian version.
    : data{dt...} {
   * @param xRads Angle (in radians) of rotation around axis X.
  }
   * @param yRads Angle (in radians) of rotation around axis Y.

   * @param zRads Angle (in radians) of rotation around axis Z.
  /**
   */
   * Resets matrix to be identity matrix
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
   */
    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    data = {1, 0, 0,
    // the static cast is to avoid narrowing conversion warnings when used with ints
            0, 1, 0,
    T sin_xRads = static_cast<T>(0);
            0, 0, 1};
    T cos_xRads = static_cast<T>(0);
  }
    T sin_yRads = static_cast<T>(0);

    T cos_yRads = static_cast<T>(0);
  /**
    T sin_zRads = static_cast<T>(0);
   * Creates rotation matrix by rotation around three axes.
    T cos_zRads = static_cast<T>(0);
   * @param xDeg Angle (in degrees) of rotation around axis X.
    sincos_any(xRads, sin_xRads, cos_xRads);
   * @param yDeg Angle (in degrees) of rotation around axis Y.
    sincos_any(yRads, sin_yRads, cos_yRads);
   * @param zDeg Angle (in degrees) of rotation around axis Z.
    sincos_any(zRads, sin_zRads, cos_zRads);
   */
    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
  inline static matrix3<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
    return create_rotation_around_axis_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
  }
    return matrix3<T>(temp_cos_z_cos_y,
  inline static matrix3<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
    return create_rotation_around_axis(xDeg, yDeg, zDeg);
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,
  }


                      sin_zRads * cos_yRads,
  /**
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
   * Creates rotation matrix by rotation around three axes, radian version.
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,
   * @param xRads Angle (in radians) of rotation around axis X.

   * @param yRads Angle (in radians) of rotation around axis Y.
                     -temp_cos_z_sin_y,
   * @param zRads Angle (in radians) of rotation around axis Z.
                      temp_cos_z_cos_y * sin_xRads,
   */
                      temp_cos_z_cos_y * cos_xRads);
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
  }
    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
    // zero-initialisation is required for gcc not to complain when the function is constexpr
    return create_rotation_around_axis_rad(xRads, yRads, zRads);
    // the static cast is to avoid narrowing conversion warnings when used with ints
  }
    T sin_xRads = static_cast<T>(0);

    T cos_xRads = static_cast<T>(0);
  /**
    T sin_yRads = static_cast<T>(0);
   * Creates rotation matrix by rotation around an axis.
    T cos_yRads = static_cast<T>(0);
   * @param axis Axis to rotate around.
    T sin_zRads = static_cast<T>(0);
   * @param angle Angle (in degrees) of rotation around axis.
    T cos_zRads = static_cast<T>(0);
   */
    sincos_any(xRads, sin_xRads, cos_xRads);
  inline static matrix3<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    sincos_any(yRads, sin_yRads, cos_yRads);
    return create_rotation_around_axis_rad(axis, angle);
    sincos_any(zRads, sin_zRads, cos_zRads);
  }
    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
  inline static matrix3<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
    return create_rotation_around_axis(axis, angle);
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
  }
    return matrix3<T>(temp_cos_z_cos_y,

                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
  /**
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,
   * Creates rotation matrix by rotation around an axis, radian version.

   * @param axis Axis to rotate around.
                      sin_zRads * cos_yRads,
   * @param angle Angle (in radians) of rotation around axis.
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
   */
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {

    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
                     -temp_cos_z_sin_y,
    // zero-initialisation is required for gcc not to complain when the function is constexpr
                      temp_cos_z_cos_y * sin_xRads,
    // the static cast is to avoid narrowing conversion warnings when used with ints
                      temp_cos_z_cos_y * cos_xRads);
    T sin_a = static_cast<T>(0);
  }
    T cos_a = static_cast<T>(0);
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
    sincos_any(angle, sin_a, cos_a);
    return create_rotation_around_axis_rad(xRads, yRads, zRads);
    T const cos_a_inv = static_cast<T>(1) - cos_a;
  }
    return matrix3<T>(axis.x * axis.x * cos_a_inv + cos_a,

                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
  /**
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
   * Creates rotation matrix by rotation around an axis.

   * @param axis Axis to rotate around.
                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
   * @param angle Angle (in degrees) of rotation around axis.
                      axis.y * axis.y * cos_a_inv + cos_a,
   */
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,
  inline static matrix3<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {

    return create_rotation_around_axis_rad(axis, angle);
                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,
  }
                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
  inline static matrix3<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
                      axis.z * axis.z * cos_a_inv + cos_a);
    return create_rotation_around_axis(axis, angle);
  }
  }
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {

    return create_rotation_around_axis_rad(axis, angle);
  /**
  }
   * Creates rotation matrix by rotation around an axis, radian version.

   * @param axis Axis to rotate around.
  /**
   * @param angle Angle (in radians) of rotation around axis.
   * Creates rotation matrix by aligning one vector to another.
   */
   * Adapted from http://www.iquilezles.org/www/articles/noacos/noacos.htm
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
   * @param from Vector to rotate from.
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
   * @param to Vector to rotate to.
    // zero-initialisation is required for gcc not to complain when the function is constexpr
   * @return An instance of matrix3<T> representing rotation between the two vectors.
   */
    // the static cast is to avoid narrowing conversion warnings when used with ints
    T sin_a = static_cast<T>(0);
  inline static matrix3<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
    T cos_a = static_cast<T>(0);
    // the static cast is to avoid narrowing conversion warnings when used with ints
    sincos_any(angle, sin_a, cos_a);
    vector3<T> const cross(to.crossProduct(from));
    T const cos_a_inv = static_cast<T>(1) - cos_a;
    T const dot = from.dotProduct(to);
    return matrix3<T>(axis.x * axis.x * cos_a_inv + cos_a,
    T const temp_k = static_cast<T>(1) / (static_cast<T>(1) + dot);
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
    return matrix3<T>(cross.x * cross.x * temp_k + dot,
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
                      cross.y * cross.x * temp_k - cross.z,

                      cross.z * cross.x * temp_k + cross.y,
                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,

                      axis.y * axis.y * cos_a_inv + cos_a,
                      cross.x * cross.y * temp_k + cross.z,
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,
                      cross.y * cross.y * temp_k + dot,

                      cross.z * cross.y * temp_k - cross.x,
                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,

                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
                      cross.x * cross.z * temp_k - cross.y,
                      axis.z * axis.z * cos_a_inv + cos_a);
                      cross.y * cross.z * temp_k + cross.x,
  }
                      cross.z * cross.z * temp_k + dot);

  inline static matrix3<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
  }
    return create_rotation_around_axis_rad(axis, angle);
  }
  inline static matrix3<T> constexpr createRotationBetweenVectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_between_vectors()"))) {

    return create_rotation_between_vectors(from, to);
  /**
  }
   * Creates rotation matrix by aligning one vector to another.

   * Adapted from http://www.iquilezles.org/www/articles/noacos/noacos.htm
  /**
   * @param from Vector to rotate from.
   * Creates rotation matrix from ODE matrix.
   * @param to Vector to rotate to.
   */
   * @return An instance of matrix3<T> representing rotation between the two vectors.
  template<typename It> __attribute__((__always_inline__))
   */
  inline static matrix3<T> constexpr from_ode(It const *mat) noexcept {
  inline static matrix3<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(static_cast<T>(mat[0]), static_cast<T>(mat[4]), static_cast<T>(mat[8]),
    // the static cast is to avoid narrowing conversion warnings when used with ints
                      static_cast<T>(mat[1]), static_cast<T>(mat[5]), static_cast<T>(mat[9]),
    vector3<T> const cross(to.crossProduct(from));
                      static_cast<T>(mat[2]), static_cast<T>(mat[6]), static_cast<T>(mat[10]));
    T const dot = from.dotProduct(to);
  }
    T const temp_k = static_cast<T>(1) / (static_cast<T>(1) + dot);
  template<typename It> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_ode()")))
    return matrix3<T>(cross.x * cross.x * temp_k + dot,
  inline static matrix3<T> constexpr fromOde(It const *mat) noexcept {
                      cross.y * cross.x * temp_k - cross.z,
    return from_ode(mat);
  }
                      cross.z * cross.x * temp_k + cross.y,


  /**
                      cross.x * cross.y * temp_k + cross.z,
   * Creates new matrix 3x3 from array that represents such matrix 3x3
                      cross.y * cross.y * temp_k + dot,
   * as array of tightly packed elements in row major order.
                      cross.z * cross.y * temp_k - cross.x,
   * @param arr An array of elements for 3x3 matrix in row major order.

   * @return An instance of matrix3<T> representing @a arr
                      cross.x * cross.z * temp_k - cross.y,
   */
                      cross.y * cross.z * temp_k + cross.x,
  template<typename FromT> __attribute__((__always_inline__))
                      cross.z * cross.z * temp_k + dot);
  inline static matrix3<T> constexpr from_row_major_array(FromT const *arr) noexcept {

    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[3]), static_cast<T>(arr[6]),
  }
                      static_cast<T>(arr[1]), static_cast<T>(arr[4]), static_cast<T>(arr[7]),
  inline static matrix3<T> constexpr createRotationBetweenVectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_between_vectors()"))) {
                      static_cast<T>(arr[2]), static_cast<T>(arr[5]), static_cast<T>(arr[8]));
    return create_rotation_between_vectors(from, to);
  }
  }
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))

  inline static matrix3<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
  /**
    return from_row_major_array(arr);
   * Creates rotation matrix from ODE matrix.
  }
   */

  template<typename It> __attribute__((__always_inline__))
  /**
  inline static matrix3<T> constexpr from_ode(It const *mat) noexcept {
   * Creates new matrix 3x3 from array that represents such matrix 3x3
    return matrix3<T>(static_cast<T>(mat[0]), static_cast<T>(mat[4]), static_cast<T>(mat[8]),
   * as array of tightly packed elements in column major order.
                      static_cast<T>(mat[1]), static_cast<T>(mat[5]), static_cast<T>(mat[9]),
   * @param arr An array of elements for 3x3 matrix in column major order.
                      static_cast<T>(mat[2]), static_cast<T>(mat[6]), static_cast<T>(mat[10]));
   * @return An instance of matrix3<T> representing @a arr
  }
   */
  template<typename It> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_ode()")))
  template<typename FromT> __attribute__((__always_inline__))
  inline static matrix3<T> constexpr fromOde(It const *mat) noexcept {
  inline static matrix3<T> constexpr from_column_major_array(FromT const *arr) noexcept {
    return from_ode(mat);
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[1]), static_cast<T>(arr[2]),
  }
                      static_cast<T>(arr[3]), static_cast<T>(arr[4]), static_cast<T>(arr[5]),

                      static_cast<T>(arr[6]), static_cast<T>(arr[7]), static_cast<T>(arr[8]));
  /**
  }
   * Creates new matrix 3x3 from array that represents such matrix 3x3
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
   * as array of tightly packed elements in row major order.
  inline static matrix3<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
   * @param arr An array of elements for 3x3 matrix in row major order.
    return from_column_major_array(arr);
   * @return An instance of matrix3<T> representing @a arr
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  //---------------------[ equiality operators ]------------------------------
  inline static matrix3<T> constexpr from_row_major_array(FromT const *arr) noexcept {
  /**
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[3]), static_cast<T>(arr[6]),
   * Equality test operator
                      static_cast<T>(arr[1]), static_cast<T>(arr[4]), static_cast<T>(arr[7]),
   * @param rhs Right hand side argument of binary operator.
                      static_cast<T>(arr[2]), static_cast<T>(arr[5]), static_cast<T>(arr[8]));
   * @note Test of equality is based of threshold epsilon value. To be two
  }
   * values equal, must satisfy this condition all elements of matrix
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
   * | lhs[i] - rhs[i] | < epsilon,
  inline static matrix3<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
   * same for y-coordinate, z-coordinate, and w-coordinate.
    return from_row_major_array(arr);
   */
  }
  inline bool constexpr operator==(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    #ifdef VMATH_SOFT_COMPARE
  /**
      return std::abs(data[0] - rhs.data[0]) < static_cast<T>(epsilon) &&
   * Creates new matrix 3x3 from array that represents such matrix 3x3
             std::abs(data[1] - rhs.data[1]) < static_cast<T>(epsilon) &&
   * as array of tightly packed elements in column major order.
             std::abs(data[2] - rhs.data[2]) < static_cast<T>(epsilon) &&
   * @param arr An array of elements for 3x3 matrix in column major order.
             std::abs(data[3] - rhs.data[3]) < static_cast<T>(epsilon) &&
   * @return An instance of matrix3<T> representing @a arr
             std::abs(data[4] - rhs.data[4]) < static_cast<T>(epsilon) &&
   */
             std::abs(data[5] - rhs.data[5]) < static_cast<T>(epsilon) &&
  template<typename FromT> __attribute__((__always_inline__))
             std::abs(data[6] - rhs.data[6]) < static_cast<T>(epsilon) &&
  inline static matrix3<T> constexpr from_column_major_array(FromT const *arr) noexcept {
             std::abs(data[7] - rhs.data[7]) < static_cast<T>(epsilon) &&
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[1]), static_cast<T>(arr[2]),
             std::abs(data[8] - rhs.data[8]) < static_cast<T>(epsilon);
                      static_cast<T>(arr[3]), static_cast<T>(arr[4]), static_cast<T>(arr[5]),
    #else
                      static_cast<T>(arr[6]), static_cast<T>(arr[7]), static_cast<T>(arr[8]));
      return data[0] == rhs.data[0] &&
  }
             data[1] == rhs.data[1] &&
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
             data[2] == rhs.data[2] &&
  inline static matrix3<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
             data[3] == rhs.data[3] &&
    return from_column_major_array(arr);
             data[4] == rhs.data[4] &&
  }
             data[5] == rhs.data[5] &&

             data[6] == rhs.data[6] &&
  //---------------------[ equiality operators ]------------------------------
             data[7] == rhs.data[7] &&
  /**
             data[8] == rhs.data[8];
   * Equality test operator
    #endif // VMATH_SOFT_COMPARE
   * @param rhs Right hand side argument of binary operator.
  }
   * @note Test of equality is based of threshold epsilon value. To be two

  /**
   * values equal, must satisfy this condition all elements of matrix
   * Inequality test operator
   * | lhs[i] - rhs[i] | < epsilon,
   * @param rhs Right hand side argument of binary operator.
   * same for y-coordinate, z-coordinate, and w-coordinate.
   * @return not (lhs == rhs) :-P
   */
   */
  inline bool constexpr operator==(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline bool constexpr operator!=(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    #ifdef VMATH_SOFT_COMPARE
    return !(*this == rhs);
      return std::abs(data[0] - rhs.data[0]) < static_cast<T>(epsilon) &&
  }
             std::abs(data[1] - rhs.data[1]) < static_cast<T>(epsilon) &&

             std::abs(data[2] - rhs.data[2]) < static_cast<T>(epsilon) &&
  //---------------------[ access operators ]---------------------------------
             std::abs(data[3] - rhs.data[3]) < static_cast<T>(epsilon) &&
  /**
             std::abs(data[4] - rhs.data[4]) < static_cast<T>(epsilon) &&
   * Get reference to element at position (x,y).
             std::abs(data[5] - rhs.data[5]) < static_cast<T>(epsilon) &&
   * @param x Number of column (0..2)
             std::abs(data[6] - rhs.data[6]) < static_cast<T>(epsilon) &&
   * @param y Number of row (0..2)
             std::abs(data[7] - rhs.data[7]) < static_cast<T>(epsilon) &&
   */
             std::abs(data[8] - rhs.data[8]) < static_cast<T>(epsilon);
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
    #else
    return data[x * 3 + y];
      return data[0] == rhs.data[0] &&
  }
             data[1] == rhs.data[1] &&

             data[2] == rhs.data[2] &&
  /**
             data[3] == rhs.data[3] &&
   * Get constant reference to element at position (x,y).
             data[4] == rhs.data[4] &&
   * @param x Number of column (0..2)
             data[5] == rhs.data[5] &&
   * @param y Number of row (0..2)
             data[6] == rhs.data[6] &&
   */
             data[7] == rhs.data[7] &&
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
             data[8] == rhs.data[8];
    return data[x * 3 + y];
    #endif // VMATH_SOFT_COMPARE
  }
  }


  /**
  /**
   * Get reference to element at position (i,j), with math matrix notation
   * Inequality test operator
   * @param i Number of row (1..3)
   * @param rhs Right hand side argument of binary operator.
   * @param j Number of column (1..3)
   * @return not (lhs == rhs) :-P
   */
   */
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
  inline bool constexpr operator!=(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 3 + i - 1];
    return !(*this == rhs);
  }
  }


  /**
  //---------------------[ access operators ]---------------------------------
   * Get constant reference to element at position (i,j), with math matrix notation
  /**
   * @param i Number of row (1..3)
   * Get reference to element at position (x,y).
   * @param j Number of column (1..3)
   * @param x Number of column (0..2)
   */
   * @param y Number of row (0..2)
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
   */
    return data[(j - 1) * 3 + i - 1];
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
  }
    return data[x * 3 + y];

  }
  /**

   * Returns transform (4x4) matrix including this as the rotation component.
  /**
   */
   * Get constant reference to element at position (x,y).
  inline matrix4<T> constexpr get_transform() const noexcept __attribute__((__always_inline__)) {
   * @param x Number of column (0..2)
    return matrix4<T>(data[0],           data[1],           data[2],           static_cast<T>(0),
   * @param y Number of row (0..2)
                      data[3],           data[4],           data[5],           static_cast<T>(0),
   */
                      data[6],           data[7],           data[8],           static_cast<T>(0),
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
    return data[x * 3 + y];
  }
  }
  inline matrix4<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_transform()"))) {

     return get_transform();
  /**
  }
   * Get reference to element at position (i,j), with math matrix notation

   * @param i Number of row (1..3)
  /**
   * @param j Number of column (1..3)
   * Copy operator
   */
   * @param rhs Right hand side argument of binary operator.
   */
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr &operator=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    return data[(j - 1) * 3 + i - 1];
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 9);
  }
    return *this;

  }
  /**

   * Get constant reference to element at position (i,j), with math matrix notation
  /**
   * @param i Number of row (1..3)
   * Copy casting operator
   * @param j Number of column (1..3)
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return data[(j - 1) * 3 + i - 1];
  inline matrix3<T> constexpr &operator=(matrix3<FromT> const &rhs) noexcept {
  }
    data[0] = static_cast<T>(rhs.data[0]);

    data[1] = static_cast<T>(rhs.data[1]);
  /**
    data[2] = static_cast<T>(rhs.data[2]);
   * Returns transform (4x4) matrix including this as the rotation component.
    data[3] = static_cast<T>(rhs.data[3]);
   */
    data[4] = static_cast<T>(rhs.data[4]);
  inline matrix4<T> constexpr get_transform() const noexcept __attribute__((__always_inline__)) {
    data[5] = static_cast<T>(rhs.data[5]);
    return matrix4<T>(data[0],           data[1],           data[2],           static_cast<T>(0),
    data[6] = static_cast<T>(rhs.data[6]);
                      data[3],           data[4],           data[5],           static_cast<T>(0),
    data[7] = static_cast<T>(rhs.data[7]);
                      data[6],           data[7],           data[8],           static_cast<T>(0),
    data[8] = static_cast<T>(rhs.data[8]);
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
    return *this;
  }
  }

  inline matrix4<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_transform()"))) {
  /**
     return get_transform();
   * Copy operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline matrix3<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
   * Copy operator
    /*
   * @param rhs Right hand side argument of binary operator.
    for(int i = 0; i != 9; ++i) {
   */
      data[i] = (T)rhs[i];
  inline matrix3<T> constexpr &operator=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    }
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 9);
    */
    return *this;
    std::memcpy(data.data(), rhs, sizeof(T) * 9);
  }
    return *this;

  }
  /**

   * Copy casting operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Move assignment operator
   */
   * @param rhs Right hand side argument of binary operator.
  template<typename FromT> __attribute__((__always_inline__))
   */
  inline matrix3<T> constexpr &operator=(matrix3<FromT> const &rhs) noexcept {
  inline matrix3<T> constexpr &operator=(matrix3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    data[0] = static_cast<T>(rhs.data[0]);
    data = std::move(rhs.data);
    data[1] = static_cast<T>(rhs.data[1]);
    return *this;
    data[2] = static_cast<T>(rhs.data[2]);
  }
    data[3] = static_cast<T>(rhs.data[3]);

    data[4] = static_cast<T>(rhs.data[4]);
  /**
    data[5] = static_cast<T>(rhs.data[5]);
   * Move assignment casting operator
    data[6] = static_cast<T>(rhs.data[6]);
   * @param rhs Right hand side argument of binary operator.
    data[7] = static_cast<T>(rhs.data[7]);
   */
    data[8] = static_cast<T>(rhs.data[8]);
  template<typename FromT> __attribute__((__always_inline__))
    return *this;
  inline matrix3<T> constexpr &operator=(matrix3<FromT> &&rhs) noexcept {
  }
    data[0] = static_cast<T>(std::move(rhs.data[0]));

    data[1] = static_cast<T>(std::move(rhs.data[1]));
  /**
    data[2] = static_cast<T>(std::move(rhs.data[2]));
   * Copy operator
    data[3] = static_cast<T>(std::move(rhs.data[3]));
   * @param rhs Right hand side argument of binary operator.
    data[4] = static_cast<T>(std::move(rhs.data[4]));
   */
    data[5] = static_cast<T>(std::move(rhs.data[5]));
  inline matrix3<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
    data[6] = static_cast<T>(std::move(rhs.data[6]));
    /*
    data[7] = static_cast<T>(std::move(rhs.data[7]));
    for(int i = 0; i != 9; ++i) {
    data[8] = static_cast<T>(std::move(rhs.data[8]));
      data[i] = (T)rhs[i];
    return *this;
    }
  }
    */

    std::memcpy(data.data(), rhs, sizeof(T) * 9);
  //--------------------[ matrix with matrix operations ]---------------------
    return *this;
  /**
  }
   * Addition operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Move assignment operator
  inline matrix3<T> constexpr operator+(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],
   */
                      data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
  inline matrix3<T> constexpr &operator=(matrix3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
                      data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
    data = std::move(rhs.data);
  }
    return *this;

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Move assignment casting operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr operator-(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
  template<typename FromT> __attribute__((__always_inline__))
                      data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
  inline matrix3<T> constexpr &operator=(matrix3<FromT> &&rhs) noexcept {
                      data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
    data[0] = static_cast<T>(std::move(rhs.data[0]));
  }
    data[1] = static_cast<T>(std::move(rhs.data[1]));

    data[2] = static_cast<T>(std::move(rhs.data[2]));
  //--------------------[ matrix with scalar operations ]---------------------
    data[3] = static_cast<T>(std::move(rhs.data[3]));
  /**
    data[4] = static_cast<T>(std::move(rhs.data[4]));
   * Addition operator
    data[5] = static_cast<T>(std::move(rhs.data[5]));
   * @param rhs Right hand side argument of binary operator.
    data[6] = static_cast<T>(std::move(rhs.data[6]));
   */
    data[7] = static_cast<T>(std::move(rhs.data[7]));
  inline matrix3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
    data[8] = static_cast<T>(std::move(rhs.data[8]));
    return matrix3<T>(data[0] + rhs, data[1] + rhs, data[2] + rhs,
    return *this;
                      data[3] + rhs, data[4] + rhs, data[5] + rhs,
  }
                      data[6] + rhs, data[7] + rhs, data[8] + rhs);

  }
  //--------------------[ matrix with matrix operations ]---------------------

  /**
  /**
   * Addition operator
   * Subtraction operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix3<T> constexpr operator+(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],
    return matrix3<T>(data[0] - rhs, data[1] - rhs, data[2] - rhs,
                      data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
                      data[3] - rhs, data[4] - rhs, data[5] - rhs,
                      data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
                      data[6] - rhs, data[7] - rhs, data[8] - rhs);
  }


  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr operator-(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
  inline matrix3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
                      data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
    return matrix3<T>(data[0] * rhs, data[1] * rhs, data[2] * rhs,
                      data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
                      data[3] * rhs, data[4] * rhs, data[5] * rhs,
  }
                      data[6] * rhs, data[7] * rhs, data[8] * rhs);

  }
  //--------------------[ matrix with scalar operations ]---------------------

  /**
  /**
   * Addition operator
   * Division operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] + rhs, data[1] + rhs, data[2] + rhs,
    return matrix3<T>(data[0] / rhs, data[1] / rhs, data[2] / rhs,
                      data[3] + rhs, data[4] + rhs, data[5] + rhs,
                      data[3] / rhs, data[4] / rhs, data[5] / rhs,
                      data[6] + rhs, data[7] + rhs, data[8] + rhs);
                      data[6] / rhs, data[7] / rhs, data[8] / rhs);
  }
  }


  /**
  /**
   * Subtraction operator
   * Addition operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] - rhs, data[1] - rhs, data[2] - rhs,
    *this = *this + rhs;
                      data[3] - rhs, data[4] - rhs, data[5] - rhs,
    return *this;
  }
                      data[6] - rhs, data[7] - rhs, data[8] - rhs);


  /**
  }
   * Subtraction operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Multiplication operator
  inline matrix3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    *this = *this - rhs;
   */
    return *this;
  inline matrix3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return matrix3<T>(data[0] * rhs, data[1] * rhs, data[2] * rhs,

                      data[3] * rhs, data[4] * rhs, data[5] * rhs,
  /**
                      data[6] * rhs, data[7] * rhs, data[8] * rhs);
   * Multiplication operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline matrix3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   * Division operator
    *this = *this * rhs;
   * @param rhs Right hand side argument of binary operator.
    return *this;
   */
  }
  inline matrix3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {

    return matrix3<T>(data[0] / rhs, data[1] / rhs, data[2] / rhs,
  /**
                      data[3] / rhs, data[4] / rhs, data[5] / rhs,
   * Division operator
                      data[6] / rhs, data[7] / rhs, data[8] / rhs);
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline matrix3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
  /**
    *this = *this / rhs;
   * Addition operator
    return *this;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline matrix3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
  //--------------------[ multiply operators ]--------------------------------
    *this = *this + rhs;
  /**
    return *this;
   * Multiplication operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Subtraction operator
    return vector3<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
   * @param rhs Right hand side argument of binary operator.
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
   */
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z);
  inline matrix3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
  }
    *this = *this - rhs;

    return *this;
  /**
  }
   * Multiplication operator

   * @param rhs Right hand side argument of binary operator.
  /**
   * Enabling vector4 rotation as if it's a vector3, maintaining W
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return vector4<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
  inline matrix3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
    *this = *this * rhs;
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z,
    return *this;
                      rhs.w);
  }
  }


  /**
  /**
   * Division operator
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr operator*(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    *this = *this / rhs;
    return matrix3<T>(rhs.data[0] * data[0] + rhs.data[1] * data[3] + rhs.data[2] * data[6],
    return *this;
                      rhs.data[0] * data[1] + rhs.data[1] * data[4] + rhs.data[2] * data[7],
  }
                      rhs.data[0] * data[2] + rhs.data[1] * data[5] + rhs.data[2] * data[8],


  //--------------------[ multiply operators ]--------------------------------
                      rhs.data[3] * data[0] + rhs.data[4] * data[3] + rhs.data[5] * data[6],
  /**
                      rhs.data[3] * data[1] + rhs.data[4] * data[4] + rhs.data[5] * data[7],
   * Multiplication operator
                      rhs.data[3] * data[2] + rhs.data[4] * data[5] + rhs.data[5] * data[8],
   * @param rhs Right hand side argument of binary operator.

   */
                      rhs.data[6] * data[0] + rhs.data[7] * data[3] + rhs.data[8] * data[6],
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                      rhs.data[6] * data[1] + rhs.data[7] * data[4] + rhs.data[8] * data[7],
    return vector3<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
                      rhs.data[6] * data[2] + rhs.data[7] * data[5] + rhs.data[8] * data[8]);
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
  }
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z);

  }
  /**

   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
   * Enabling vector4 rotation as if it's a vector3, maintaining W
    *this = *this * rhs;
   */
    return *this;
  }
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return vector4<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
  //---------------------------[ misc operations ]----------------------------
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
  /**
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z,
   * Transpose matrix.
                      rhs.w);
   */
  }
  inline matrix3<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {

    return matrix3<T>(data[0], data[3], data[6],
  /**
                      data[1], data[4], data[7],
   * Multiplication operator
                      data[2], data[5], data[8]);
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline matrix3<T> constexpr operator*(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return matrix3<T>(rhs.data[0] * data[0] + rhs.data[1] * data[3] + rhs.data[2] * data[6],
   * Linear interpolation of two matrices
                      rhs.data[0] * data[1] + rhs.data[1] * data[4] + rhs.data[2] * data[7],
   * @param fact Factor of interpolation. For translation from positon
                      rhs.data[0] * data[2] + rhs.data[1] * data[5] + rhs.data[2] * data[8],
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.

   * @param rhs Second matrix for interpolation
                      rhs.data[3] * data[0] + rhs.data[4] * data[3] + rhs.data[5] * data[6],
   * @note However values of fact parameter are reasonable only in interval
                      rhs.data[3] * data[1] + rhs.data[4] * data[4] + rhs.data[5] * data[7],
   * [0.0 , 1.0], you can pass also values outside of this interval and you
                      rhs.data[3] * data[2] + rhs.data[4] * data[5] + rhs.data[5] * data[8],
   * can get result (extrapolation?)

   */
                      rhs.data[6] * data[0] + rhs.data[7] * data[3] + rhs.data[8] * data[6],
  inline matrix3<T> constexpr lerp(T fact, matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                      rhs.data[6] * data[1] + rhs.data[7] * data[4] + rhs.data[8] * data[7],
    return (*this) + (rhs - (*this)) * fact;
                      rhs.data[6] * data[2] + rhs.data[7] * data[5] + rhs.data[8] * data[8]);
  }
  }


  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
  /**
    return   data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
   * Multiplication operator
           - data[0] * data[5] * data[7] - data[1] * data[3] * data[8] - data[2] * data[4] * data[6];
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline matrix3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  /**
    *this = *this * rhs;
   * Computes inverse matrix
    return *this;
   * @return Inverse matrix of this matrix.
  }
   */

  inline matrix3<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
  //---------------------------[ misc operations ]----------------------------
    return matrix3<T>(data[4] * data[8] - data[7] * data[5],
  /**
                      data[7] * data[2] - data[1] * data[8],
   * Transpose matrix.
                      data[1] * data[5] - data[4] * data[2],
   */
                      data[6] * data[5] - data[3] * data[8],
  inline matrix3<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
                      data[0] * data[8] - data[6] * data[2],
    return matrix3<T>(data[0], data[3], data[6],
                      data[3] * data[2] - data[0] * data[5],
                      data[1], data[4], data[7],
                      data[3] * data[7] - data[6] * data[4],
                      data[2], data[5], data[8]);
                      data[6] * data[1] - data[0] * data[7],
  }
                      data[0] * data[4] - data[3] * data[1]) / det();

  }
  /**

   * Linear interpolation of two matrices
  /**
   * @param fact Factor of interpolation. For translation from positon
   * Orthonormalizes the matrix.
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.
   * 1. normalizes the normal.
   * @param rhs Second matrix for interpolation
   * 2. normalizes the tangent and makes sure it is orthogonal to normal.
   * @note However values of fact parameter are reasonable only in interval
   * 3. normalizes binormal and makes sure it is orthogonal to both normal and tangent.
   */
   * [0.0 , 1.0], you can pass also values outside of this interval and you
  inline void constexpr orthonormalise() noexcept __attribute__((__always_inline__)) {
   * can get result (extrapolation?)
    // normalize x:
   */
    T const x_length = static_cast<T>(std::sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]));
  inline matrix3<T> constexpr lerp(T fact, matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    data[0] /= x_length;
    return (*this) + (rhs - (*this)) * fact;
    data[1] /= x_length;
  }
    data[2] /= x_length;

    // z -= z * (x dot z):
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
    T const x_dot_z = data[0] * data[6] + data[1] * data[7] + data[2] * data[8];
    return   data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
    data[6] -= data[6] * x_dot_z;
           - data[0] * data[5] * data[7] - data[1] * data[3] * data[8] - data[2] * data[4] * data[6];
    data[7] -= data[7] * x_dot_z;
  }
    data[8] -= data[8] * x_dot_z;

    // normalize z:
  /**
    T const z_length = static_cast<T>(std::sqrt(data[6] * data[6] + data[7] * data[7] + data[8] * data[8]));
   * Computes inverse matrix
    data[6] /= z_length;
   * @return Inverse matrix of this matrix.
    data[7] /= z_length;
   */
    data[8] /= z_length;
  inline matrix3<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
    // y = z cross x:
    return matrix3<T>(data[4] * data[8] - data[7] * data[5],
    data[3] = data[7] * data[2] - data[1] * data[8];
                      data[7] * data[2] - data[1] * data[8],
    data[4] = data[8] * data[0] - data[2] * data[6];
                      data[1] * data[5] - data[4] * data[2],
    data[5] = data[6] * data[1] - data[0] * data[7];
                      data[6] * data[5] - data[3] * data[8],
  }
                      data[0] * data[8] - data[6] * data[2],
  /// Proper English
                      data[3] * data[2] - data[0] * data[5],
  inline void constexpr orthonormalize() noexcept __attribute__((__always_inline__)) {
                      data[3] * data[7] - data[6] * data[4],
    orthonormalise();
                      data[6] * data[1] - data[0] * data[7],
  }
                      data[0] * data[4] - data[3] * data[1]) / det();

  }
  //-------------[ conversion ]-----------------------------


  /**
  /**
   * Orthonormalizes the matrix.
   * Conversion to pointer operator
   * 1. normalizes the normal.
   * @return Pointer to internally stored (in management of class matrix3<T>)
   * 2. normalizes the tangent and makes sure it is orthogonal to normal.
   * used for passing matrix3<T> values to gl*[fd]v functions.
   * 3. normalizes binormal and makes sure it is orthogonal to both normal and tangent.
   */
   */
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
  inline void constexpr orthonormalise() noexcept __attribute__((__always_inline__)) {
    return reinterpret_cast<T*>(data.data());
    // normalize x:
  }

    T const x_length = static_cast<T>(std::sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]));
  /**
    data[0] /= x_length;
   * Conversion to pointer operator
    data[1] /= x_length;
   * @return Constant Pointer to internally stored (in management of class matrix3<T>)
    data[2] /= x_length;
   * used for passing matrix3<T> values to gl*[fd]v functions.
    // z -= z * (x dot z):
   */
    T const x_dot_z = data[0] * data[6] + data[1] * data[7] + data[2] * data[8];
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
    data[6] -= data[6] * x_dot_z;
    return reinterpret_cast<T const*>(data.data());
    data[7] -= data[7] * x_dot_z;
  }
    data[8] -= data[8] * x_dot_z;

    // normalize z:
  //----------[ output operator ]----------------------------
    T const z_length = static_cast<T>(std::sqrt(data[6] * data[6] + data[7] * data[7] + data[8] * data[8]));
  /**
    data[6] /= z_length;
   * Output to stream operator
    data[7] /= z_length;
   * @param lhs Left hand side argument of operator (commonly ostream instance).
    data[8] /= z_length;
   * @param rhs Right hand side argument of operator.
    // y = z cross x:
   * @return Left hand side argument - the ostream object passed to operator.
    data[3] = data[7] * data[2] - data[1] * data[8];
   */
    data[4] = data[8] * data[0] - data[2] * data[6];
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    data[5] = data[6] * data[1] - data[0] * data[7];
    for(int i = 0; i != 3; ++i) {
  }
      lhs << "|\t";
  /// Proper English
      for(int j = 0; j != 3; ++j) {
  inline void constexpr orthonormalize() noexcept __attribute__((__always_inline__)) {
        lhs << rhs.at(j, i) << "\t";
    orthonormalise();
      }
  }
      lhs << "|" << std::endl;

    }
  //-------------[ conversion ]-----------------------------
    return lhs;

  }
  /**

   * Conversion to pointer operator
  /**
   * @return Pointer to internally stored (in management of class matrix3<T>)
   * Gets string representation.
   * used for passing matrix3<T> values to gl*[fd]v functions.
   */
   */
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
    std::ostringstream oss;
    return reinterpret_cast<T*>(data.data());
    oss << *this;
  }
    return oss.str();

  }
  /**
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
   * Conversion to pointer operator
    return to_string();
   * @return Constant Pointer to internally stored (in management of class matrix3<T>)
  }
   * used for passing matrix3<T> values to gl*[fd]v functions.
};
   */

  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
#ifdef VMATH_NAMESPACE
    return reinterpret_cast<T const*>(data.data());
}
  }
#endif //VMATH_NAMESPACE


  //----------[ output operator ]----------------------------
#include "matrix3_types.h"
  /**

   * Output to stream operator
#endif // VECTORSTORM_MATRIX3_H_INCLUDED
   * @param lhs Left hand side argument of operator (commonly ostream instance).
   * @param rhs Right hand side argument of operator.
   * @return Left hand side argument - the ostream object passed to operator.
   */
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
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

#include "matrix3_types.h"

#endif // VECTORSTORM_MATRIX3_H_INCLUDED
