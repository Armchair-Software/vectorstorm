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
  inline static matrix3<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles()"))) {
    return create_rotation_from_euler_angles(xDeg, yDeg, zDeg);
  }
  inline static matrix3<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles()"))) {
    return create_rotation_from_euler_angles(xDeg, yDeg, zDeg);
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
#ifndef VECTORSTORM_MATRIX3_H_INCLUDED
    // the static cast is to avoid narrowing conversion warnings when used with ints
#define VECTORSTORM_MATRIX3_H_INCLUDED
    T sin_xRads = static_cast<T>(0);

    T cos_xRads = static_cast<T>(0);
#include "vectorstorm/epsilon.h"
    T sin_yRads = static_cast<T>(0);
#ifndef VMATH_NO_BOOST
    T cos_yRads = static_cast<T>(0);
  #include <boost/functional/hash_fwd.hpp>
    T sin_zRads = static_cast<T>(0);
#endif // VMATH_NO_BOOST

    T cos_zRads = static_cast<T>(0);
#ifdef VMATH_NAMESPACE
    sincos_any(-xRads, sin_xRads, cos_xRads);
namespace VMATH_NAMESPACE {
    sincos_any(-yRads, sin_yRads, cos_yRads);
#endif
    sincos_any(-zRads, sin_zRads, cos_zRads);

    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
/**
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
 * Class for matrix 3x3.
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
 * @note Data stored in this matrix are in column major order. This arrangement suits OpenGL.
    return matrix3<T>(temp_cos_z_cos_y,
 * If you're using row major matrix, consider using fromRowMajorArray as way for construction
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
 * matrix3<T> instance.
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,
 */

template<typename T>
                      sin_zRads * cos_yRads,
class matrix3 {
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
public:
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,
  /// Data stored in column major order

  std::array<T, 9> data;
                     -temp_cos_z_sin_y,

                      temp_cos_z_cos_y * sin_xRads,
  //--------------------------[ constructors ]-------------------------------
                      temp_cos_z_cos_y * cos_xRads);
  /**
  }
   * Creates identity matrix
   */
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles_rad()"))) {
  inline constexpr matrix3() noexcept __attribute__((__always_inline__))
    return create_rotation_from_euler_angles_rad(xRads, yRads, zRads);
    : data{1, 0, 0,
  }
           0, 1, 0,
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles_rad()"))) {
           0, 0, 1} {
    return create_rotation_from_euler_angles_rad(xRads, yRads, zRads);
  }
  }


  /**
  /**
   * Copy matrix values from array (these data must be in column
   * Creates rotation matrix by rotation around an axis.
   * major order!)
   * @param axis Axis to rotate around.
   */
   * @param angle Angle (in degrees) of rotation around axis.
  inline constexpr explicit matrix3(T const *dt) noexcept __attribute__((__always_inline__))
   */
    : data{dt[0], dt[1], dt[2],
           dt[3], dt[4], dt[5],
  inline static matrix3<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
           dt[6], dt[7], dt[8]} {
    return create_rotation_around_axis_rad(axis, deg2rad(angle));
  }
  }
  inline constexpr explicit matrix3(T *dt) noexcept __attribute__((__always_inline__))
  inline static matrix3<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {
    : data{dt[0], dt[1], dt[2],
    return create_rotation_around_axis(axis, angle);
           dt[3], dt[4], dt[5],
  }
           dt[6], dt[7], dt[8]} {

  }
  /**

   * Creates rotation matrix by rotation around an axis, radian version.
  /**
   * @param axis Axis to rotate around.
   * Copy constructor.
   * @param angle Angle (in radians) of rotation around axis.
   * @param src Data source for new created instance of matrix3
   */
   */
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
  inline constexpr explicit matrix3(matrix3<T> const &src) noexcept __attribute__((__always_inline__))
    : data{src.data[0], src.data[1], src.data[2],
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
           src.data[3], src.data[4], src.data[5],
    // zero-initialisation is required for gcc not to complain when the function is constexpr
           src.data[6], src.data[7], src.data[8]} {
    // the static cast is to avoid narrowing conversion warnings when used with ints
  }
    T sin_a = static_cast<T>(0);

    T cos_a = static_cast<T>(0);
  /**
    sincos_any(-angle, sin_a, cos_a);
   * Copy casting constructor.
    T const cos_a_inv = static_cast<T>(1) - cos_a;
   * @param src Data source for new created instance of matrix3
    return matrix3<T>(axis.x * axis.x * cos_a_inv + cos_a,
   */
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,
  template<typename FromT> __attribute__((__always_inline__))
                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
  inline constexpr explicit matrix3(matrix3<FromT> const &src) noexcept

    : data{static_cast<T>(src.data[0]), static_cast<T>(src.data[1]), static_cast<T>(src.data[2]),
                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
           static_cast<T>(src.data[3]), static_cast<T>(src.data[4]), static_cast<T>(src.data[5]),
                      axis.y * axis.y * cos_a_inv + cos_a,
           static_cast<T>(src.data[6]), static_cast<T>(src.data[7]), static_cast<T>(src.data[8])} {
  }
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,


  /**
                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,
   * Move constructor.
                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
   * @param src Data source for new created instance of matrix3
                      axis.z * axis.z * cos_a_inv + cos_a);
   */
  }
  inline constexpr matrix3(matrix3<T> &&src) noexcept __attribute__((__always_inline__))
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
    : data(std::move(src.data)) {
  }
    return create_rotation_around_axis_rad(axis, angle);

  }
  /**

   * Move casting constructor.
  /**
   * @param src Data source for new created instance of matrix3
   * Creates rotation matrix by aligning one vector to another.
   */
   * Adapted from http://www.iquilezles.org/www/articles/noacos/noacos.htm
  template<typename FromT> __attribute__((__always_inline__))
   * @param from Vector to rotate from.
  inline constexpr matrix3(matrix3<FromT> &&src) noexcept
   * @param to Vector to rotate to.
    : data{static_cast<T>(std::move(src.data[0])), static_cast<T>(std::move(src.data[1])), static_cast<T>(std::move(src.data[2])),
   * @return An instance of matrix3<T> representing rotation between the two vectors.
           static_cast<T>(std::move(src.data[3])), static_cast<T>(std::move(src.data[4])), static_cast<T>(std::move(src.data[5])),
   */
           static_cast<T>(std::move(src.data[6])), static_cast<T>(std::move(src.data[7])), static_cast<T>(std::move(src.data[8]))} {
  inline static matrix3<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
  }
    // the static cast is to avoid narrowing conversion warnings when used with ints

    vector3<T> const cross(to.cross(from));
  /**
    T const dot = from.dot(to);
   * Variadic initialisation constructor
    T temp1 = static_cast<T>(1) + dot;
   * @param dt Initialiser list containing raw data for each element in order.
   */
    if(temp1 == static_cast<T>(0)) {                                            // a safety check is required to avoid a divide by zero
  //inline constexpr matrix3(std::initializer_list<T> dt)
      temp1 = epsilon<T>;
  //  : data(dt) noexcept __attribute__((__always_inline__)) {
    }
  //}
    T const temp_k = static_cast<T>(1) / temp1;
  // see http://stackoverflow.com/a/5549918/1678468
    return matrix3<T>(cross.x * cross.x * temp_k + dot,
  template<typename... FromT> __attribute__((__always_inline__))
                      cross.y * cross.x * temp_k - cross.z,
  inline constexpr explicit matrix3(FromT... dt) noexcept
                      cross.z * cross.x * temp_k + cross.y,
    : data{dt...} {

  }
                      cross.x * cross.y * temp_k + cross.z,

                      cross.y * cross.y * temp_k + dot,
  /**
                      cross.z * cross.y * temp_k - cross.x,
   * Resets matrix to be identity matrix

   */
                      cross.x * cross.z * temp_k - cross.y,
  inline void constexpr identity() noexcept __attribute__((__always_inline__)) {
                      cross.y * cross.z * temp_k + cross.x,
    data = {1, 0, 0,
            0, 1, 0,
                      cross.z * cross.z * temp_k + dot);
            0, 0, 1};

  }
  }

  inline static matrix3<T> constexpr createRotationBetweenVectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_between_vectors()"))) {
  /**
    return create_rotation_between_vectors(from, to);
   * Creates rotation matrix by rotation around three axes.
  }
   * @param xDeg Angle (in degrees) of rotation around axis X.

   * @param yDeg Angle (in degrees) of rotation around axis Y.
  /**
   * @param zDeg Angle (in degrees) of rotation around axis Z.
   * Creates a rotation matrix to align with a target vector direction @a target
   */
   * @param target Vector that the rotation should point at
  inline static matrix3<T> constexpr create_rotation_from_euler_angles(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) {
   * @param up_dir Direction of up vector
    return create_rotation_from_euler_angles_rad(deg2rad(xDeg), deg2rad(yDeg), deg2rad(zDeg));
   * @return Resulting matrix that's oriented to the target vector
  }
   */
  inline static matrix3<T> constexpr create_rotation_around_axis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles()"))) {
  inline static matrix3<T> constexpr create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {
    return create_rotation_from_euler_angles(xDeg, yDeg, zDeg);
    vector3<T> forward(target);
  }
    forward.normalise();
  inline static matrix3<T> constexpr createRotationAroundAxis(T xDeg, T yDeg, T zDeg) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles()"))) {

    return create_rotation_from_euler_angles(xDeg, yDeg, zDeg);
    // Side = forward x up
  }
    vector3<T> side = forward.cross(up_dir);

    side.normalise();
  /**

   * Creates rotation matrix by rotation around three axes, radian version.
    // Recompute up as: up = side x forward
   * @param xRads Angle (in radians) of rotation around axis X.
    vector3<T> const up = side.cross(forward);
   * @param yRads Angle (in radians) of rotation around axis Y.

   * @param zRads Angle (in radians) of rotation around axis Z.
    return matrix3<T>(static_cast<T>(side.x),
   */
                      static_cast<T>(up.x),
  inline static matrix3<T> constexpr create_rotation_from_euler_angles_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) {
                      static_cast<T>(forward.x),
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm

    //T sin_xRads, cos_xRads, sin_yRads, cos_yRads, sin_zRads, cos_zRads;
                      static_cast<T>(side.y),
    // zero-initialisation is required for gcc not to complain when the function is constexpr
                      static_cast<T>(up.y),
    // the static cast is to avoid narrowing conversion warnings when used with ints
                      static_cast<T>(forward.y),
    T sin_xRads = static_cast<T>(0);

    T cos_xRads = static_cast<T>(0);
                      static_cast<T>(side.z),
    T sin_yRads = static_cast<T>(0);
    T cos_yRads = static_cast<T>(0);
                      static_cast<T>(up.z),
    T sin_zRads = static_cast<T>(0);
                      static_cast<T>(forward.z));
    T cos_zRads = static_cast<T>(0);
  }
    sincos_any(-xRads, sin_xRads, cos_xRads);

    sincos_any(-yRads, sin_yRads, cos_yRads);
  /**
    sincos_any(-zRads, sin_zRads, cos_zRads);
   * Creates rotation matrix from ODE matrix.
    T const temp_sin_z_sin_y = sin_zRads * sin_yRads;
   */
    T const temp_cos_z_sin_y = cos_zRads * sin_yRads;
  template<typename It> __attribute__((__always_inline__))
    T const temp_cos_z_cos_y = cos_zRads * cos_yRads;
  inline static matrix3<T> constexpr from_ode(It const *mat) noexcept {
    return matrix3<T>(temp_cos_z_cos_y,
    return matrix3<T>(static_cast<T>(mat[0]), static_cast<T>(mat[4]), static_cast<T>(mat[8]),
                      temp_cos_z_sin_y * sin_xRads - sin_zRads * cos_xRads,
                      static_cast<T>(mat[1]), static_cast<T>(mat[5]), static_cast<T>(mat[9]),
                      temp_cos_z_sin_y * cos_xRads + sin_zRads * sin_xRads,

                      static_cast<T>(mat[2]), static_cast<T>(mat[6]), static_cast<T>(mat[10]));
                      sin_zRads * cos_yRads,
  }
                      temp_sin_z_sin_y * sin_xRads + cos_zRads * cos_xRads,
  template<typename It> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_ode()")))
                      temp_sin_z_sin_y * cos_xRads - cos_zRads * sin_xRads,
  inline static matrix3<T> constexpr fromOde(It const *mat) noexcept {

    return from_ode(mat);
                     -temp_cos_z_sin_y,
  }
                      temp_cos_z_cos_y * sin_xRads,

                      temp_cos_z_cos_y * cos_xRads);
  /**
  }
   * Creates new matrix 3x3 from array that represents such matrix 3x3
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles_rad()"))) {
   * as array of tightly packed elements in row major order.
    return create_rotation_from_euler_angles_rad(xRads, yRads, zRads);
   * @param arr An array of elements for 3x3 matrix in row major order.
  }
   * @return An instance of matrix3<T> representing @a arr
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(T xRads, T yRads, T zRads) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_from_euler_angles_rad()"))) {
   */
    return create_rotation_from_euler_angles_rad(xRads, yRads, zRads);
  template<typename FromT> __attribute__((__always_inline__))
  }
  inline static matrix3<T> constexpr from_row_major_array(FromT const *arr) noexcept {

    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[3]), static_cast<T>(arr[6]),
  /**
                      static_cast<T>(arr[1]), static_cast<T>(arr[4]), static_cast<T>(arr[7]),
   * Creates rotation matrix by rotation around an axis.
   * @param axis Axis to rotate around.
                      static_cast<T>(arr[2]), static_cast<T>(arr[5]), static_cast<T>(arr[8]));
   * @param angle Angle (in degrees) of rotation around axis.
  }
   */
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
  inline static matrix3<T> constexpr create_rotation_around_axis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
  inline static matrix3<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
    return create_rotation_around_axis_rad(axis, deg2rad(angle));
    return from_row_major_array(arr);
  }
  }
  inline static matrix3<T> constexpr createRotationAroundAxis(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis()"))) {

    return create_rotation_around_axis(axis, angle);
  /**
  }
   * Creates new matrix 3x3 from array that represents such matrix 3x3

   * as array of tightly packed elements in column major order.
  /**
   * @param arr An array of elements for 3x3 matrix in column major order.
   * Creates rotation matrix by rotation around an axis, radian version.
   * @return An instance of matrix3<T> representing @a arr
   * @param axis Axis to rotate around.
   */
   * @param angle Angle (in radians) of rotation around axis.
  template<typename FromT> __attribute__((__always_inline__))
   */
  inline static matrix3<T> constexpr from_column_major_array(FromT const *arr) noexcept {
  inline static matrix3<T> constexpr create_rotation_around_axis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[1]), static_cast<T>(arr[2]),
    // adapted from Inigo Quilez: http://www.iquilezles.org/www/articles/noacos/noacos.htm
                      static_cast<T>(arr[3]), static_cast<T>(arr[4]), static_cast<T>(arr[5]),
    // zero-initialisation is required for gcc not to complain when the function is constexpr
                      static_cast<T>(arr[6]), static_cast<T>(arr[7]), static_cast<T>(arr[8]));
    // the static cast is to avoid narrowing conversion warnings when used with ints
  }
    T sin_a = static_cast<T>(0);
    T cos_a = static_cast<T>(0);
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
    sincos_any(-angle, sin_a, cos_a);
  inline static matrix3<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
    T const cos_a_inv = static_cast<T>(1) - cos_a;
    return from_column_major_array(arr);
    return matrix3<T>(axis.x * axis.x * cos_a_inv + cos_a,
  }
                      axis.y * axis.x * cos_a_inv - sin_a * axis.z,

                      axis.z * axis.x * cos_a_inv + sin_a * axis.y,
  //---------------------[ equiality operators ]------------------------------

  /**
                      axis.x * axis.y * cos_a_inv + sin_a * axis.z,
   * Equality test operator
                      axis.y * axis.y * cos_a_inv + cos_a,
   * @param rhs Right hand side argument of binary operator.
                      axis.z * axis.y * cos_a_inv - sin_a * axis.x,
   * @note Test of equality is based of threshold epsilon value. To be two

   * values equal, must satisfy this condition all elements of matrix
                      axis.x * axis.z * cos_a_inv - sin_a * axis.y,
   * | lhs[i] - rhs[i] | < epsilon,
                      axis.y * axis.z * cos_a_inv + sin_a * axis.x,
   * same for y-coordinate, z-coordinate, and w-coordinate.
                      axis.z * axis.z * cos_a_inv + cos_a);
   */
  }
  inline bool constexpr operator==(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  inline static matrix3<T> constexpr createRotationAroundAxis_rad(vector3<T> const &axis, T angle) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_around_axis_rad()"))) {
    #ifdef VMATH_SOFT_COMPARE
    return create_rotation_around_axis_rad(axis, angle);
      return std::abs(data[0] - rhs.data[0]) < epsilon<T> &&
  }

             std::abs(data[1] - rhs.data[1]) < epsilon<T> &&
  /**
             std::abs(data[2] - rhs.data[2]) < epsilon<T> &&
   * Creates rotation matrix by aligning one vector to another.
             std::abs(data[3] - rhs.data[3]) < epsilon<T> &&
   * Adapted from http://www.iquilezles.org/www/articles/noacos/noacos.htm
             std::abs(data[4] - rhs.data[4]) < epsilon<T> &&
   * @param from Vector to rotate from.
             std::abs(data[5] - rhs.data[5]) < epsilon<T> &&
   * @param to Vector to rotate to.
             std::abs(data[6] - rhs.data[6]) < epsilon<T> &&
   * @return An instance of matrix3<T> representing rotation between the two vectors.
             std::abs(data[7] - rhs.data[7]) < epsilon<T> &&
   */
             std::abs(data[8] - rhs.data[8]) < epsilon<T>;
  inline static matrix3<T> constexpr create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) {
    #else
    // the static cast is to avoid narrowing conversion warnings when used with ints
      return data[0] == rhs.data[0] &&
    vector3<T> const cross(to.cross(from));
             data[1] == rhs.data[1] &&
    T const dot = from.dot(to);
             data[2] == rhs.data[2] &&
    T temp1 = static_cast<T>(1) + dot;
             data[3] == rhs.data[3] &&
    if(temp1 == static_cast<T>(0)) {                                            // a safety check is required to avoid a divide by zero
             data[4] == rhs.data[4] &&
      temp1 = epsilon<T>;
             data[5] == rhs.data[5] &&
    }
             data[6] == rhs.data[6] &&
    T const temp_k = static_cast<T>(1) / temp1;
             data[7] == rhs.data[7] &&
    return matrix3<T>(cross.x * cross.x * temp_k + dot,
             data[8] == rhs.data[8];
                      cross.y * cross.x * temp_k - cross.z,
    #endif // VMATH_SOFT_COMPARE
                      cross.z * cross.x * temp_k + cross.y,

  }
                      cross.x * cross.y * temp_k + cross.z,

                      cross.y * cross.y * temp_k + dot,
  /**
                      cross.z * cross.y * temp_k - cross.x,
   * Inequality test operator

   * @param rhs Right hand side argument of binary operator.
                      cross.x * cross.z * temp_k - cross.y,
   * @return not (lhs == rhs) :-P
                      cross.y * cross.z * temp_k + cross.x,
   */
                      cross.z * cross.z * temp_k + dot);
  inline bool constexpr operator!=(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {

    return !(*this == rhs);
  }
  }
  inline static matrix3<T> constexpr createRotationBetweenVectors(vector3<T> const &from, vector3<T> const &to) noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use create_rotation_between_vectors()"))) {

    return create_rotation_between_vectors(from, to);
  //---------------------[ access operators ]---------------------------------
  }
  /**

   * Get reference to element at position (x,y).
  /**
   * @param x Number of column (0..2)
   * Creates a rotation matrix to align with a target vector direction @a target
   * @param y Number of row (0..2)
   * @param target Vector that the rotation should point at
   */
   * @param up_dir Direction of up vector
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
   * @return Resulting matrix that's oriented to the target vector
    return data[x * 3 + y];
   */
  }
  inline static matrix3<T> constexpr create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir) noexcept __attribute__((__always_inline__)) {

    vector3<T> forward(target);
  /**
    forward.normalise();

   * Get constant reference to element at position (x,y).
    // Side = forward x up
   * @param x Number of column (0..2)
    vector3<T> side = forward.cross(up_dir);
   * @param y Number of row (0..2)
    side.normalise();
   */

  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
    // Recompute up as: up = side x forward
    return data[x * 3 + y];
    vector3<T> const up = side.cross(forward);
  }


    return matrix3<T>(static_cast<T>(side.x),
  /**
                      static_cast<T>(up.x),
   * Get reference to element at position (i,j), with math matrix notation
                      static_cast<T>(forward.x),
   * @param i Number of row (1..3)

                      static_cast<T>(side.y),
   * @param j Number of column (1..3)
                      static_cast<T>(up.y),
   */
                      static_cast<T>(forward.y),
  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {

    return data[(j - 1) * 3 + i - 1];
                      static_cast<T>(side.z),
  }
                      static_cast<T>(up.z),

                      static_cast<T>(forward.z));
  /**
  }
   * Get constant reference to element at position (i,j), with math matrix notation

   * @param i Number of row (1..3)
  /**
   * @param j Number of column (1..3)
   * Creates rotation matrix from ODE matrix.
   */
   */
  template<typename It> __attribute__((__always_inline__))
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
  inline static matrix3<T> constexpr from_ode(It const *mat) noexcept {
    return data[(j - 1) * 3 + i - 1];
    return matrix3<T>(static_cast<T>(mat[0]), static_cast<T>(mat[4]), static_cast<T>(mat[8]),
  }
                      static_cast<T>(mat[1]), static_cast<T>(mat[5]), static_cast<T>(mat[9]),

                      static_cast<T>(mat[2]), static_cast<T>(mat[6]), static_cast<T>(mat[10]));
  /**
  }
   * Returns transform (4x4) matrix including this as the rotation component.
  template<typename It> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_ode()")))
   */
  inline static matrix3<T> constexpr fromOde(It const *mat) noexcept {
  inline matrix4<T> constexpr get_transform() const noexcept __attribute__((__always_inline__)) {
    return from_ode(mat);
    return matrix4<T>(data[0],           data[1],           data[2],           static_cast<T>(0),
  }
                      data[3],           data[4],           data[5],           static_cast<T>(0),

                      data[6],           data[7],           data[8],           static_cast<T>(0),
  /**
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
   * Creates new matrix 3x3 from array that represents such matrix 3x3
  }
   * as array of tightly packed elements in row major order.
  inline matrix4<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_transform()"))) {
   * @param arr An array of elements for 3x3 matrix in row major order.
     return get_transform();
   * @return An instance of matrix3<T> representing @a arr
  }
   */

  template<typename FromT> __attribute__((__always_inline__))
  /**
  inline static matrix3<T> constexpr from_row_major_array(FromT const *arr) noexcept {
   * Copy operator
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[3]), static_cast<T>(arr[6]),
   * @param rhs Right hand side argument of binary operator.
                      static_cast<T>(arr[1]), static_cast<T>(arr[4]), static_cast<T>(arr[7]),
   */
                      static_cast<T>(arr[2]), static_cast<T>(arr[5]), static_cast<T>(arr[8]));
  inline matrix3<T> constexpr &operator=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  }
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 9);
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_row_major_array()")))
    return *this;
  inline static matrix3<T> constexpr fromRowMajorArray(FromT const *arr) noexcept {
  }
    return from_row_major_array(arr);

  }

  /**
  /**
   * Copy casting operator
   * Creates new matrix 3x3 from array that represents such matrix 3x3
   * @param rhs Right hand side argument of binary operator.
   * as array of tightly packed elements in column major order.
   */
   * @param arr An array of elements for 3x3 matrix in column major order.
  template<typename FromT> __attribute__((__always_inline__))
   * @return An instance of matrix3<T> representing @a arr
  inline matrix3<T> constexpr &operator=(matrix3<FromT> const &rhs) noexcept {
   */
    data[0] = static_cast<T>(rhs.data[0]);
  template<typename FromT> __attribute__((__always_inline__))
    data[1] = static_cast<T>(rhs.data[1]);
  inline static matrix3<T> constexpr from_column_major_array(FromT const *arr) noexcept {
    data[2] = static_cast<T>(rhs.data[2]);
    return matrix3<T>(static_cast<T>(arr[0]), static_cast<T>(arr[1]), static_cast<T>(arr[2]),
    data[3] = static_cast<T>(rhs.data[3]);
                      static_cast<T>(arr[3]), static_cast<T>(arr[4]), static_cast<T>(arr[5]),
    data[4] = static_cast<T>(rhs.data[4]);
                      static_cast<T>(arr[6]), static_cast<T>(arr[7]), static_cast<T>(arr[8]));
    data[5] = static_cast<T>(rhs.data[5]);
  }
    data[6] = static_cast<T>(rhs.data[6]);
  template<typename FromT> __attribute__((__always_inline__)) __attribute__((__deprecated__("Use from_column_major_array()")))
    data[7] = static_cast<T>(rhs.data[7]);
  inline static matrix3<T> constexpr fromColumnMajorArray(FromT const *arr) noexcept {
    data[8] = static_cast<T>(rhs.data[8]);
    return from_column_major_array(arr);
    return *this;
  }
  }


  //---------------------[ equiality operators ]------------------------------
  /**
  /**
   * Copy operator
   * Equality test operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   * @note Test of equality is based of threshold epsilon value. To be two
  inline matrix3<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
   * values equal, must satisfy this condition all elements of matrix
   * | lhs[i] - rhs[i] | < epsilon,
    /*
   * same for y-coordinate, z-coordinate, and w-coordinate.
    for(int i = 0; i != 9; ++i) {
   */
      data[i] = (T)rhs[i];
  inline bool constexpr operator==(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    }
    #ifdef VMATH_SOFT_COMPARE
    */
      return std::abs(data[0] - rhs.data[0]) < epsilon<T> &&
    std::memcpy(data.data(), rhs, sizeof(T) * 9);
             std::abs(data[1] - rhs.data[1]) < epsilon<T> &&
    return *this;
             std::abs(data[2] - rhs.data[2]) < epsilon<T> &&
  }
             std::abs(data[3] - rhs.data[3]) < epsilon<T> &&

             std::abs(data[4] - rhs.data[4]) < epsilon<T> &&
  /**
             std::abs(data[5] - rhs.data[5]) < epsilon<T> &&
   * Move assignment operator
             std::abs(data[6] - rhs.data[6]) < epsilon<T> &&
   * @param rhs Right hand side argument of binary operator.
             std::abs(data[7] - rhs.data[7]) < epsilon<T> &&
   */
             std::abs(data[8] - rhs.data[8]) < epsilon<T>;
  inline matrix3<T> constexpr &operator=(matrix3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
    #else
    data = std::move(rhs.data);
      return data[0] == rhs.data[0] &&
    return *this;
             data[1] == rhs.data[1] &&
  }
             data[2] == rhs.data[2] &&

             data[3] == rhs.data[3] &&
  /**
             data[4] == rhs.data[4] &&
   * Move assignment casting operator
             data[5] == rhs.data[5] &&
   * @param rhs Right hand side argument of binary operator.
             data[6] == rhs.data[6] &&
   */
             data[7] == rhs.data[7] &&
  template<typename FromT> __attribute__((__always_inline__))
             data[8] == rhs.data[8];
    #endif // VMATH_SOFT_COMPARE
  inline matrix3<T> constexpr &operator=(matrix3<FromT> &&rhs) noexcept {
  }
    data[0] = static_cast<T>(std::move(rhs.data[0]));

    data[1] = static_cast<T>(std::move(rhs.data[1]));
  /**
    data[2] = static_cast<T>(std::move(rhs.data[2]));
   * Inequality test operator
    data[3] = static_cast<T>(std::move(rhs.data[3]));
   * @param rhs Right hand side argument of binary operator.
    data[4] = static_cast<T>(std::move(rhs.data[4]));
   * @return not (lhs == rhs) :-P
    data[5] = static_cast<T>(std::move(rhs.data[5]));
   */
    data[6] = static_cast<T>(std::move(rhs.data[6]));
  inline bool constexpr operator!=(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    data[7] = static_cast<T>(std::move(rhs.data[7]));
    return !(*this == rhs);
    data[8] = static_cast<T>(std::move(rhs.data[8]));
  }
    return *this;

  }
  //---------------------[ access operators ]---------------------------------

  /**
  //--------------------[ matrix with matrix operations ]---------------------
   * Get reference to element at position (x,y).
  /**
   * @param x Number of column (0..2)
   * Addition operator
   * @param y Number of row (0..2)
   */
   * @param rhs Right hand side argument of binary operator.
  inline T constexpr &at(int x, int y) noexcept __attribute__((__always_inline__)) {
   */
    return data[x * 3 + y];
  inline matrix3<T> constexpr operator+(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],

                      data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
  /**
                      data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
   * Get constant reference to element at position (x,y).
  }
   * @param x Number of column (0..2)

   * @param y Number of row (0..2)
  /**
   */
   * Subtraction operator
  inline T constexpr const &at(int x, int y) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    return data[x * 3 + y];
   */
  }

  inline matrix3<T> constexpr operator-(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  /**
    return matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
   * Get reference to element at position (i,j), with math matrix notation
                      data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
   * @param i Number of row (1..3)
                      data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
   * @param j Number of column (1..3)
  }
   */

  inline T constexpr &operator()(int i, int j) noexcept __attribute__((__always_inline__)) {
  //--------------------[ matrix with scalar operations ]---------------------
    return data[(j - 1) * 3 + i - 1];
  /**
  }
   * Addition operator

  /**
   * @param rhs Right hand side argument of binary operator.
   * Get constant reference to element at position (i,j), with math matrix notation
   */
   * @param i Number of row (1..3)
  inline matrix3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param j Number of column (1..3)
    return matrix3<T>(data[0] + rhs, data[1] + rhs, data[2] + rhs,
   */
                      data[3] + rhs, data[4] + rhs, data[5] + rhs,
  inline T constexpr const &operator()(int i, int j) const noexcept __attribute__((__always_inline__)) {
                      data[6] + rhs, data[7] + rhs, data[8] + rhs);
    return data[(j - 1) * 3 + i - 1];
  }
  }


  /**
  /**
   * Subtraction operator
   * Returns transform (4x4) matrix including this as the rotation component.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix4<T> constexpr get_transform() const noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
    return matrix4<T>(data[0],           data[1],           data[2],           static_cast<T>(0),
    return matrix3<T>(data[0] - rhs, data[1] - rhs, data[2] - rhs,
                      data[3],           data[4],           data[5],           static_cast<T>(0),
                      data[3] - rhs, data[4] - rhs, data[5] - rhs,
                      data[6],           data[7],           data[8],           static_cast<T>(0),
                      data[6] - rhs, data[7] - rhs, data[8] - rhs);
                      static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));

  }
  }
  inline matrix4<T> constexpr getTranslation() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use get_transform()"))) {

     return get_transform();
  /**
  }
   * Multiplication operator

  /**
   * @param rhs Right hand side argument of binary operator.
   * Copy operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix3<T>(data[0] * rhs, data[1] * rhs, data[2] * rhs,
  inline matrix3<T> constexpr &operator=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
                      data[3] * rhs, data[4] * rhs, data[5] * rhs,
    std::memcpy(data.data(), rhs.data.data(), sizeof(T) * 9);
                      data[6] * rhs, data[7] * rhs, data[8] * rhs);
    return *this;
  }
  }


  /**
  /**
   * Division operator
   * Copy casting operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   */
  inline matrix3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
  template<typename FromT> __attribute__((__always_inline__))
    return matrix3<T>(data[0] / rhs, data[1] / rhs, data[2] / rhs,
  inline matrix3<T> constexpr &operator=(matrix3<FromT> const &rhs) noexcept {
                      data[3] / rhs, data[4] / rhs, data[5] / rhs,
    data[0] = static_cast<T>(rhs.data[0]);
    data[1] = static_cast<T>(rhs.data[1]);
                      data[6] / rhs, data[7] / rhs, data[8] / rhs);
    data[2] = static_cast<T>(rhs.data[2]);
  }
    data[3] = static_cast<T>(rhs.data[3]);

    data[4] = static_cast<T>(rhs.data[4]);
  /**
    data[5] = static_cast<T>(rhs.data[5]);
   * Addition operator
    data[6] = static_cast<T>(rhs.data[6]);
   * @param rhs Right hand side argument of binary operator.
    data[7] = static_cast<T>(rhs.data[7]);
   */
    data[8] = static_cast<T>(rhs.data[8]);
  inline matrix3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
    return *this;
    *this = *this + rhs;
  }
    return *this;

  }
  /**

   * Copy operator
  /**
   * @param rhs Right hand side argument of binary operator.
   */
   * Subtraction operator
  inline matrix3<T> constexpr &operator=(T const *rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    /*
   */
    for(int i = 0; i != 9; ++i) {
  inline matrix3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
      data[i] = (T)rhs[i];
    *this = *this - rhs;
    }
    return *this;
    */
  }
    std::memcpy(data.data(), rhs, sizeof(T) * 9);

    return *this;
  /**
  }
   * Multiplication operator

   * @param rhs Right hand side argument of binary operator.
  /**
   */
   * Move assignment operator
  inline matrix3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
   * @param rhs Right hand side argument of binary operator.
    *this = *this * rhs;
   */
    return *this;
  inline matrix3<T> constexpr &operator=(matrix3<T> &&rhs) noexcept __attribute__((__always_inline__)) {
  }
    data = std::move(rhs.data);

    return *this;
  /**
  }

   * Division operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Move assignment casting operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    *this = *this / rhs;
  template<typename FromT> __attribute__((__always_inline__))
    return *this;
  inline matrix3<T> constexpr &operator=(matrix3<FromT> &&rhs) noexcept {
  }
    data[0] = static_cast<T>(std::move(rhs.data[0]));

    data[1] = static_cast<T>(std::move(rhs.data[1]));
  //--------------------[ multiply operators ]--------------------------------
    data[2] = static_cast<T>(std::move(rhs.data[2]));
  /**
    data[3] = static_cast<T>(std::move(rhs.data[3]));
   * Multiplication operator
    data[4] = static_cast<T>(std::move(rhs.data[4]));
   * @param rhs Right hand side argument of binary operator.
    data[5] = static_cast<T>(std::move(rhs.data[5]));
   */
    data[6] = static_cast<T>(std::move(rhs.data[6]));
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    data[7] = static_cast<T>(std::move(rhs.data[7]));
    data[8] = static_cast<T>(std::move(rhs.data[8]));
    return vector3<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
    return *this;
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
  }
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z);

  }
  //--------------------[ matrix with matrix operations ]---------------------

  /**
  /**
   * Addition operator
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
   * @param rhs Right hand side argument of binary operator.
   */
   * Enabling vector4 rotation as if it's a vector3, maintaining W
  inline matrix3<T> constexpr operator+(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix3<T>(data[0] + rhs.data[0], data[1] + rhs.data[1], data[2] + rhs.data[2],
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
                      data[3] + rhs.data[3], data[4] + rhs.data[4], data[5] + rhs.data[5],
    return vector4<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
                      data[6] + rhs.data[6], data[7] + rhs.data[7], data[8] + rhs.data[8]);
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
  }
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z,

  /**
                      rhs.w);
   * Subtraction operator
  }
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline matrix3<T> constexpr operator-(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Multiplication operator
    return matrix3<T>(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2],
   * @param rhs Right hand side argument of binary operator.
                      data[3] - rhs.data[3], data[4] - rhs.data[4], data[5] - rhs.data[5],
   */
                      data[6] - rhs.data[6], data[7] - rhs.data[7], data[8] - rhs.data[8]);
  inline matrix3<T> constexpr operator*(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
  }
    return matrix3<T>(rhs.data[0] * data[0] + rhs.data[1] * data[3] + rhs.data[2] * data[6],

                      rhs.data[0] * data[1] + rhs.data[1] * data[4] + rhs.data[2] * data[7],
  //--------------------[ matrix with scalar operations ]---------------------
                      rhs.data[0] * data[2] + rhs.data[1] * data[5] + rhs.data[2] * data[8],
  /**

   * Addition operator
                      rhs.data[3] * data[0] + rhs.data[4] * data[3] + rhs.data[5] * data[6],
   * @param rhs Right hand side argument of binary operator.
   */
                      rhs.data[3] * data[1] + rhs.data[4] * data[4] + rhs.data[5] * data[7],
  inline matrix3<T> constexpr operator+(T rhs) const noexcept __attribute__((__always_inline__)) {
                      rhs.data[3] * data[2] + rhs.data[4] * data[5] + rhs.data[5] * data[8],
    return matrix3<T>(data[0] + rhs, data[1] + rhs, data[2] + rhs,

                      data[3] + rhs, data[4] + rhs, data[5] + rhs,
                      rhs.data[6] * data[0] + rhs.data[7] * data[3] + rhs.data[8] * data[6],
                      data[6] + rhs, data[7] + rhs, data[8] + rhs);
                      rhs.data[6] * data[1] + rhs.data[7] * data[4] + rhs.data[8] * data[7],
  }
                      rhs.data[6] * data[2] + rhs.data[7] * data[5] + rhs.data[8] * data[8]);

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Multiplication operator
   */
   * @param rhs Right hand side argument of binary operator.
  inline matrix3<T> constexpr operator-(T rhs) const noexcept __attribute__((__always_inline__)) {
   */
    return matrix3<T>(data[0] - rhs, data[1] - rhs, data[2] - rhs,
  inline matrix3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
                      data[3] - rhs, data[4] - rhs, data[5] - rhs,
    *this = *this * rhs;
                      data[6] - rhs, data[7] - rhs, data[8] - rhs);
    return *this;

  }
  }


  /**
  //---------------------------[ misc operations ]----------------------------
   * Multiplication operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Transpose matrix.
   */
   */
  inline matrix3<T> constexpr operator*(T rhs) const noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
    return matrix3<T>(data[0] * rhs, data[1] * rhs, data[2] * rhs,
    return matrix3<T>(data[0], data[3], data[6],
                      data[3] * rhs, data[4] * rhs, data[5] * rhs,
                      data[1], data[4], data[7],
                      data[6] * rhs, data[7] * rhs, data[8] * rhs);
                      data[2], data[5], data[8]);
  }
  }


  /**
  /**
   * Division operator
   * Linear interpolation of two matrices
   * @param rhs Right hand side argument of binary operator.
   * @param fact Factor of interpolation. For translation from positon
   */
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.
  inline matrix3<T> constexpr operator/(T rhs) const noexcept __attribute__((__always_inline__)) {
   * @param rhs Second matrix for interpolation
    return matrix3<T>(data[0] / rhs, data[1] / rhs, data[2] / rhs,
   * @note However values of fact parameter are reasonable only in interval
                      data[3] / rhs, data[4] / rhs, data[5] / rhs,
   * [0.0 , 1.0], you can pass also values outside of this interval and you
                      data[6] / rhs, data[7] / rhs, data[8] / rhs);
  }
   * can get result (extrapolation?)

   */
  /**
  inline matrix3<T> constexpr lerp(T fact, matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Addition operator
    return (*this) + (rhs - (*this)) * fact;
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline matrix3<T> constexpr &operator+=(T rhs) noexcept __attribute__((__always_inline__)) {
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
    *this = *this + rhs;
    return   data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
    return *this;
           - data[0] * data[5] * data[7] - data[1] * data[3] * data[8] - data[2] * data[4] * data[6];
  }

  }
  /**

   * Subtraction operator
  /**
   * @param rhs Right hand side argument of binary operator.
   * Computes inverse matrix
   */
   * @return Inverse matrix of this matrix.
  inline matrix3<T> constexpr &operator-=(T rhs) noexcept __attribute__((__always_inline__)) {
   */
    *this = *this - rhs;
  inline matrix3<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {
    return *this;
    return matrix3<T>(data[4] * data[8] - data[7] * data[5],
  }
                      data[7] * data[2] - data[1] * data[8],

                      data[1] * data[5] - data[4] * data[2],
  /**
                      data[6] * data[5] - data[3] * data[8],
   * Multiplication operator
                      data[0] * data[8] - data[6] * data[2],
   * @param rhs Right hand side argument of binary operator.
                      data[3] * data[2] - data[0] * data[5],
   */
                      data[3] * data[7] - data[6] * data[4],
  inline matrix3<T> constexpr &operator*=(T rhs) noexcept __attribute__((__always_inline__)) {
    *this = *this * rhs;
                      data[6] * data[1] - data[0] * data[7],
    return *this;
                      data[0] * data[4] - data[3] * data[1]) / det();
  }
  }


  /**
  /**
   * Division operator
   * Orthonormalizes the matrix.
   * @param rhs Right hand side argument of binary operator.
   * 1. normalizes the normal.
   */
   * 2. normalizes the tangent and makes sure it is orthogonal to normal.
  inline matrix3<T> constexpr &operator/=(T rhs) noexcept __attribute__((__always_inline__)) {
   * 3. normalizes binormal and makes sure it is orthogonal to both normal and tangent.
    *this = *this / rhs;
   */
    return *this;
  inline void constexpr orthonormalise() noexcept __attribute__((__always_inline__)) {
  }
    // normalize x:

    T const x_length = static_cast<T>(std::sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]));
  //--------------------[ multiply operators ]--------------------------------
    data[0] /= x_length;
  /**
    data[1] /= x_length;
   * Multiplication operator
   * @param rhs Right hand side argument of binary operator.
    data[2] /= x_length;
   */
    // z -= z * (x dot z):
  inline vector3<T> constexpr operator*(vector3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    T const x_dot_z = data[0] * data[6] + data[1] * data[7] + data[2] * data[8];
    return vector3<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
    data[6] -= data[6] * x_dot_z;
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
    data[7] -= data[7] * x_dot_z;
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z);
    data[8] -= data[8] * x_dot_z;
  }
    // normalize z:

    T const z_length = static_cast<T>(std::sqrt(data[6] * data[6] + data[7] * data[7] + data[8] * data[8]));
  /**
    data[6] /= z_length;
   * Multiplication operator
    data[7] /= z_length;
   * @param rhs Right hand side argument of binary operator.
    data[8] /= z_length;
   * Enabling vector4 rotation as if it's a vector3, maintaining W
    // y = z cross x:
   */
    data[3] = data[7] * data[2] - data[1] * data[8];
  inline vector4<T> constexpr operator*(vector4<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    data[4] = data[8] * data[0] - data[2] * data[6];
    return vector4<T>(data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z,
    data[5] = data[6] * data[1] - data[0] * data[7];
                      data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z,
  }
                      data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z,
  /// Proper English
                      rhs.w);
  inline void constexpr orthonormalize() noexcept __attribute__((__always_inline__)) {
  }
    orthonormalise();

  }
  /**

   * Multiplication operator
  //-------------[ conversion ]-----------------------------
   * @param rhs Right hand side argument of binary operator.

   */
  /**
  inline matrix3<T> constexpr operator*(matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
   * Conversion to pointer operator
    return matrix3<T>(rhs.data[0] * data[0] + rhs.data[1] * data[3] + rhs.data[2] * data[6],
   * @return Pointer to internally stored (in management of class matrix3<T>)
                      rhs.data[0] * data[1] + rhs.data[1] * data[4] + rhs.data[2] * data[7],
   * used for passing matrix3<T> values to gl*[fd]v functions.
                      rhs.data[0] * data[2] + rhs.data[1] * data[5] + rhs.data[2] * data[8],
   */

  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
                      rhs.data[3] * data[0] + rhs.data[4] * data[3] + rhs.data[5] * data[6],
    return reinterpret_cast<T*>(data.data());
                      rhs.data[3] * data[1] + rhs.data[4] * data[4] + rhs.data[5] * data[7],
  }
                      rhs.data[3] * data[2] + rhs.data[4] * data[5] + rhs.data[5] * data[8],


  /**
                      rhs.data[6] * data[0] + rhs.data[7] * data[3] + rhs.data[8] * data[6],
   * Conversion to pointer operator
                      rhs.data[6] * data[1] + rhs.data[7] * data[4] + rhs.data[8] * data[7],
   * @return Constant Pointer to internally stored (in management of class matrix3<T>)
                      rhs.data[6] * data[2] + rhs.data[7] * data[5] + rhs.data[8] * data[8]);
  }
   * used for passing matrix3<T> values to gl*[fd]v functions.

   */
  /**
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
   * Multiplication operator
    return reinterpret_cast<T const*>(data.data());
   * @param rhs Right hand side argument of binary operator.
  }
   */

  inline matrix3<T> constexpr &operator*=(matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  //----------[ output operator ]----------------------------
    *this = *this * rhs;
  /**
    return *this;
   * Output to stream operator
  }
   * @param lhs Left hand side argument of operator (commonly ostream instance).

   * @param rhs Right hand side argument of operator.
  //---------------------------[ misc operations ]----------------------------
   * @return Left hand side argument - the ostream object passed to operator.
  /**
   */
   * Transpose matrix.
   */
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
  inline matrix3<T> constexpr transpose() const noexcept __attribute__((__always_inline__)) {
    for(int i = 0; i != 3; ++i) {
    return matrix3<T>(data[0], data[3], data[6],
      lhs << "|\t";
                      data[1], data[4], data[7],
      for(int j = 0; j != 3; ++j) {
                      data[2], data[5], data[8]);
        lhs << rhs.at(j, i) << "\t";
  }
      }

      lhs << "|" << std::endl;
  /**
    }
   * Linear interpolation of two matrices
    return lhs;
   * @param fact Factor of interpolation. For translation from positon
  }
   * of this matrix (lhs) to matrix rhs, values of factor goes from 0.0 to 1.0.

   * @param rhs Second matrix for interpolation
  /**
   * @note However values of fact parameter are reasonable only in interval
   * Gets string representation.
   * [0.0 , 1.0], you can pass also values outside of this interval and you
   */
   * can get result (extrapolation?)
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
   */
    std::ostringstream oss;
  inline matrix3<T> constexpr lerp(T fact, matrix3<T> const &rhs) const noexcept __attribute__((__always_inline__)) {
    oss << *this;
    return (*this) + (rhs - (*this)) * fact;
    return oss.str();
  }
  }

  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
  inline T constexpr det() const noexcept __attribute__((__always_inline__)) {
    return to_string();
    return   data[0] * data[4] * data[8] + data[1] * data[5] * data[6] + data[2] * data[3] * data[7]
  }
           - data[0] * data[5] * data[7] - data[1] * data[3] * data[8] - data[2] * data[4] * data[6];
};
  }


#ifdef VMATH_NAMESPACE
  /**
}
   * Computes inverse matrix
#endif //VMATH_NAMESPACE
   * @return Inverse matrix of this matrix.

   */
#include "matrix3_types.h"
  inline matrix3<T> constexpr inverse() const noexcept __attribute__((__always_inline__)) {

    return matrix3<T>(data[4] * data[8] - data[7] * data[5],
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      data[7] * data[2] - data[1] * data[8],
//
                      data[1] * data[5] - data[4] * data[2],
// Standard C++ library extensions
                      data[6] * data[5] - data[3] * data[8],
//
                      data[0] * data[8] - data[6] * data[2],
                      data[3] * data[2] - data[0] * data[5],
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                      data[3] * data[7] - data[6] * data[4],

                      data[6] * data[1] - data[0] * data[7],
namespace std {
                      data[0] * data[4] - data[3] * data[1]) / det();

  }
/**

 * Gets matrix containing minimal values of @a a and @a b coordinates.
  /**
 * @return Matrix of minimal coordinates.
   * Orthonormalizes the matrix.
 */
   * 1. normalizes the normal.
template<typename T>
   * 2. normalizes the tangent and makes sure it is orthogonal to normal.
inline constexpr matrix3<T> min(matrix3<T> const &a, const matrix3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
   * 3. normalizes binormal and makes sure it is orthogonal to both normal and tangent.
template<typename T>
   */
inline constexpr matrix3<T> min(matrix3<T> const &a, const matrix3<T> &b) noexcept {
  inline void constexpr orthonormalise() noexcept __attribute__((__always_inline__)) {
  return {::std::min(a.data[0], b.data[0]),
    // normalize x:
          ::std::min(a.data[1], b.data[1]),
    T const x_length = static_cast<T>(std::sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]));
          ::std::min(a.data[2], b.data[2]),
    data[0] /= x_length;

    data[1] /= x_length;
          ::std::min(a.data[3], b.data[3]),
    data[2] /= x_length;
          ::std::min(a.data[4], b.data[4]),
    // z -= z * (x dot z):
          ::std::min(a.data[5], b.data[5]),
    T const x_dot_z = data[0] * data[6] + data[1] * data[7] + data[2] * data[8];

    data[6] -= data[6] * x_dot_z;
          ::std::min(a.data[6], b.data[6]),
    data[7] -= data[7] * x_dot_z;
          ::std::min(a.data[7], b.data[7]),
    data[8] -= data[8] * x_dot_z;
          ::std::min(a.data[8], b.data[8])};
    // normalize z:
}
    T const z_length = static_cast<T>(std::sqrt(data[6] * data[6] + data[7] * data[7] + data[8] * data[8]));

    data[6] /= z_length;
/**
    data[7] /= z_length;
 * Gets matrix containing maximal values of @a a and @a b coordinates.
    data[8] /= z_length;
 * @return Matrix of maximal coordinates.
    // y = z cross x:
 */
    data[3] = data[7] * data[2] - data[1] * data[8];
template<typename T>
    data[4] = data[8] * data[0] - data[2] * data[6];
    data[5] = data[6] * data[1] - data[0] * data[7];
inline constexpr matrix3<T> max(matrix3<T> const &a, const matrix3<T> &b) noexcept __attribute__((__always_inline__)) __attribute__ ((pure));
  }
template<typename T>
  /// Proper English
inline constexpr matrix3<T> max(matrix3<T> const &a, const matrix3<T> &b) noexcept {
  inline void constexpr orthonormalize() noexcept __attribute__((__always_inline__)) {
  return {::std::max(a.data[0], b.data[0]),
    orthonormalise();
          ::std::max(a.data[1], b.data[1]),
  }
          ::std::max(a.data[2], b.data[2]),


  //-------------[ conversion ]-----------------------------
          ::std::max(a.data[3], b.data[3]),

          ::std::max(a.data[4], b.data[4]),
  /**
          ::std::max(a.data[5], b.data[5]),
   * Conversion to pointer operator

   * @return Pointer to internally stored (in management of class matrix3<T>)
          ::std::max(a.data[6], b.data[6]),
   * used for passing matrix3<T> values to gl*[fd]v functions.
   */
          ::std::max(a.data[7], b.data[7]),
  inline constexpr operator T*() noexcept __attribute__((__always_inline__)) {
          ::std::max(a.data[8], b.data[8])};
    return reinterpret_cast<T*>(data.data());
}
  }


#ifndef VMATH_NO_BOOST
  /**
/**
   * Conversion to pointer operator
 * Gets a hash value taking account of all dimensions of this matrix, for use
   * @return Constant Pointer to internally stored (in management of class matrix3<T>)
 * in standard container maps etc.
   * used for passing matrix3<T> values to gl*[fd]v functions.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
   */
 * @return Hash value
  inline constexpr operator const T*() const noexcept __attribute__((__always_inline__)) {
 */
    return reinterpret_cast<T const*>(data.data());
template<typename T>
  }
struct hash<matrix3<T>> {

  size_t operator()(const matrix3<T> &value) const {
  //----------[ output operator ]----------------------------
    size_t hashvalue = 0;
  /**
    boost::hash_combine(hashvalue, value.data[0]);
   * Output to stream operator
    boost::hash_combine(hashvalue, value.data[1]);
   * @param lhs Left hand side argument of operator (commonly ostream instance).
    boost::hash_combine(hashvalue, value.data[2]);
   * @param rhs Right hand side argument of operator.

   * @return Left hand side argument - the ostream object passed to operator.
    boost::hash_combine(hashvalue, value.data[3]);
   */
    boost::hash_combine(hashvalue, value.data[4]);
  inline friend std::ostream &operator <<(std::ostream &lhs, matrix3<T> const &rhs) noexcept __attribute__((__always_inline__)) {
    boost::hash_combine(hashvalue, value.data[5]);
    for(int i = 0; i != 3; ++i) {

      lhs << "|\t";
    boost::hash_combine(hashvalue, value.data[6]);
      for(int j = 0; j != 3; ++j) {
    boost::hash_combine(hashvalue, value.data[7]);
        lhs << rhs.at(j, i) << "\t";
    boost::hash_combine(hashvalue, value.data[8]);
      }
    return hashvalue;
      lhs << "|" << std::endl;
  }
    }
};
    return lhs;
#endif // VMATH_NO_BOOST
  }


}
  /**

   * Gets string representation.
#ifndef VMATH_NO_BOOST
   */
/**
  inline std::string constexpr to_string() const noexcept __attribute__((__always_inline__)) {
 * Gets a hash value taking account of all dimensions of this matrix, for use
    std::ostringstream oss;
 * in standard container maps etc.
    oss << *this;
    return oss.str();
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
  }
 * @return Hash value
  inline std::string constexpr toString() const noexcept __attribute__((__always_inline__)) __attribute__((__deprecated__("Use to_string()"))) {
 */
    return to_string();
template<typename T>
  }
size_t hash_value(matrix3<T> const &value) {
};
  size_t hashvalue = 0;

  boost::hash_combine(hashvalue, value.data[0]);
#ifdef VMATH_NAMESPACE
  boost::hash_combine(hashvalue, value.data[1]);
}
  boost::hash_combine(hashvalue, value.data[2]);
#endif //VMATH_NAMESPACE


  boost::hash_combine(hashvalue, value.data[3]);
#include "matrix3_types.h"
  boost::hash_combine(hashvalue, value.data[4]);

  boost::hash_combine(hashvalue, value.data[5]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
  boost::hash_combine(hashvalue, value.data[6]);
// Standard C++ library extensions
  boost::hash_combine(hashvalue, value.data[7]);
//
  boost::hash_combine(hashvalue, value.data[8]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  return hashvalue;

}
namespace std {
#endif // VMATH_NO_BOOST

/**

 * Gets matrix containing minimal values of @a a and @a b coordinates.
#endif // VECTORSTORM_MATRIX3_H_INCLUDED
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

#ifndef VMATH_NO_BOOST
/**
 * Gets a hash value taking account of all dimensions of this matrix, for use
 * in standard container maps etc.
 * Note: You need to #include <boost/functional/hash.hpp> before instantiating this.
 * @return Hash value
 */
template<typename T>
struct hash<matrix3<T>> {
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
#endif // VMATH_NO_BOOST

#endif // VECTORSTORM_MATRIX3_H_INCLUDED
