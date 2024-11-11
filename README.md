# VectorStorm

Modern C++ vector mathematics for computer graphics - [Armchair Software](https://github.com/Armchair-Software) version, formerly developed by [VoxelStorm](https://github.com/VoxelStorm-Ltd).

This library loosely follows the structure of the popular `vmath.h` library by Jan Bartipan for familiarity and ease of back-porting, but provides optimised algorithms, modern C++, extensive constexpr compatibility, explicit control over copy operations, SSE and platform-specific optimisations, and a GLSL-style altenative short syntax.

Designed for lean game applications, you only pay for what you use - there is no cruft or overhead, all types are templated and you may include only the headers you need.  Forward declaration headers are provided for all types.

The VectorStorm library is intended to easily interface with OpenGL and similar libraries, and its vector and matrix types can be passed to OpenGL functions directly - see below.  Conversion operators are also easily written for other common vector types in popular libraries - see below for example conversion operators to interoperate with ImGui::Vec2 types and other examples.

The VectorStorm library is used by most [VoxelStorm](https://github.com/VoxelStorm-Ltd) and [Armchair Software](https://github.com/Armchair-Software) libraries.

The library provides the following primitives:
- [Vector](#vector): 2D, 3D and 4D
- [Quaternion](#quaternion)
- [Matrix](#matrix): 3x3 and 4x4
- [Axis-aligned Bounding Box (AABB)](axis-aligned-bounding-box-aabb): 2D and 3D

Additionally, it provides [stand-alone functionality](#stand-alone-functionality) for interpolation, conversion, and fast floor and square root algorithms, which can be used with VectorStorm types or primitive or external types.

Each primitive provides a set of operators to perform arithmetic operations on VectorStorm primitives as if you were performing them on basic numerical types.

## Requirements

- Optional: Boost headers, for math constants and hash_combine.  This requirement can be overruled with the `VECTORSTORM_NO_BOOST` define, but will fall back to functionality that may introduce a performance penalty.  Alternatively, if you don't use the related functionality, Boost is not required.  For this reason, you may need to include the Boost headers yourself, only when instantiating the relevant templates.
  - boost/functional/hash.hpp
  - boost/math/constants/constants.hpp
  - boost/math/special_functions/erf.hpp

## Core features
The following feature concepts apply to all of the primitive VectorStorm types:

### Use with any underlying types
The VectorStorm primitives are templated and intended to be maximally flexible.  They can store any numerical or custom type, as long as the mathematical operators you intend to use are defined for that type.  Non-numerical types can also be used as long as you don't attempt to call any undefined mathematical operators, and no restrictions are placed on types you use.  All VectorStorm types can hold all other VectorStorm types, including themselves.  You can have a four-dimensional vector of floats to represent a colour, and then have a 4x4 matrix of colours, encapsulate those in your own object, and then create a three-dimensional vector of your own object if you like.

### Multiple methods of access
Members can be accessed by name (`my_vector.x`, `my_vector.y` or `my_vector.s`, `my_vector.t`), by index (`my_vector[0]`, `my_vector[1]`), by cast to array, or by direct access to the underlying data (`*my_vector`).  This means VectorStorm types work with most third party libraries with no adaptation required.  The second element in a 2D vector can be accessed either by "y" or "z" identifier, for easier expression of intent when working with mixed 2D and 3D types.

### Easy debugging & printing
All types have string conversion and stream operators, and can simply be streamed to stdout as long as the type they hold is also streamable.  This makes debugging and pretty-printing extremely simple.

### Mathematical operators on all types
All sensible mathematical operations are supported on all types.  You can add and subtract vectors and matrices.  You can multiply vectors, matrices and quaternions.  You can move bounding boxes by adding numeric values to them.  You can compare VectorStorm types using exact comparison or soft floating point (epsilon) comparison.  

### Convertability
Higher dimension vectors and matrices can easily be converted to specific lower dimensions with a single call, for example `my_vector3.to_2d_xz()` to quickly flatten the X and Z dimensions of a 3D XYZ vector into the X and Y dimensions of a 2D vector.

### Seamless use with standard library containers
All VectorStorm types, containing any types of your own, can be stored in std containers and boost containers without modification.  Hash functions are provided for VectorStorm types to operate inside hash-based containers such as `std::unordered_set` and `std::unordered_map`.

### Interoperability with common third party libraries
No conversions are required to use VectorStorm types directly with OpenGL, or any other library that accepts vector or matrix data as a plain array or a pointer to a range of values.  Simple conversion operators can be provided for interoperation with other libraries' vector types, and examples are provided [below](#interoperability).

## Structure
### Top level includes
- [vectorstorm.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm.h) - Include this to pull in all other headers.  For finer grained control, only include the required headers below.
- [vectorstorm_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm_forward.h) - Forward declaration for all types.
- [vectorstorm.cpp](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm.cpp) - Optionally build this file in your project, with `VECTORSTORM_PREINSTANTIATE` enabled, if you wish to instantiate all templates with common numerical types.  Not normally required.  Without this, the library is header-only.
 
### Primary types
#### Vector
Vectors may be two, three or four dimensional, with the same type stored in each dimension.

The members can be accessed as spacial coordinates `.x`, `.y`, `.z`, `.w`, or texture coordinates `.s`, `.t`, `.u`, or colours `.r`, `.g`, `.b`, `.a`, to clearly express the intention in a given use case.

All dimensions of vectors have the following operations in common, the below examples use `vector2` for consistency:

- Default constructor `vector2()` Creates and sets to (0,0) .
- Piecewise contructor `vector2(T x, T y)` Creates and sets to (x, y).
- Copy and move constructors, including copy and move constructors from vector3 and vector4, and copy casting constructors from other underlying types.
- `assign(T nx = 0, T ny = 0)` Assigns all component values in a single operation (or resets to identity if no values specified).
- `operator[]` Array access operator.
- Mathematical operators: Addition, subtraction, multiplication, division, modulo, for scalar and vector values.
- `dot(vector2<T> const &rhs)` Dot product with other vector.
- `cross(vector2<T> const &rhs)` Cross product with other vector.
- Comparison operators: Equality, inequality, less than, greater than, less than or equal, greater than or equal.
- Unary operations: Unary negate.
- `size_t consteval size()` number of elements of the vector (2 for `vector2` etc).
- `T length()` length of the vector.
- `T length_fast()` length of the vector, using fast square root approximation (see below).
- `T length_faster()` length of the vector, using faster square root with a single iteration (see below).
- `T length_sq()` returns the square of the length of the vector, useful to avoid square root - use when comparing two distances, for example.
- `bool length_zero()` test whether a vector is zero length - much faster than calculating the length and testing for approximate equality to zero.
- `void normalise()` normalise the vector, setting its unit length to 1.  Not safe to call on zero length vectors.
- `void normalise_fast()` normalise the vector, using fast square root approximation (see below)
- `void normalise_faster()` normalise the vector, using faster square root approximation with a single iteration (see below).
- `vector2<T> normalise_copy()` returns a normalised copy of the vector, setting its unit length to 1.  Not safe to call on zero length vectors.
- `vector2<T> normalise_copy_fast()` returns a normalised copy of the vector, using fast square root approximation (see below)
- `vector2<T> normalise_copy_faster()` returns a normalised copy of the vector, using faster square root approximation with a single iteration (see below).
- `void normalise_safe()` as per `normalise`, but with an added zero safety check to avoid division by zero.
- `vector2<T> normalise_safe()` as per `normalise_copy`, but with an added zero safety check to avoid division by zero.
- `void abs()` make the vector absolute - set all values to positive using `std::abs` on each component.
- `vector2<T> abs_copy()` return an absolute copy of the vector
- `void rotate(T angle)` rotate the vector clockwise by the given angle in degrees
- `void rotate_rad(T angle)` rotate the vector clockwise by the given angle in radians
- `vector2<T> lerp(T factor, vector2<T> const &other)` return an interpolated vector, between this vector and another.  Factor is 0 for this vector and 1 for `other`.  The range is not limited to 0-1, values outside of the range can be used to extrapolate.
- Output to stream operator and `std::string to_string()` for stream or string output.
- `bool get_line_intersection(vector2<FromT> const &line1start, vector2<FromT> const &line1end, vector2<FromT> const &line2start, vector2<FromT> const &line2end)` - get the intersection of two lines (defined by two pairs of vectors) and store the result in this vector, returning true, or leaving the vector unchanged and returning false if there is no intersection.
- `static bool do_lines_intersect(vector2<FromT> const &line1start, vector2<FromT> const &line1end, vector2<FromT> const &line2start, vector2<FromT> const &line2end)` - determine whether two lines intersect (as defined by two pairs of vectors), just returning true or false.  Prefer this version when you only care about whether there is an intersection or not, but prefer the version above to avoid duplicating calculations if you care about the resulting intersection point as well.
- `to_2d_xy()`, `to_3d_xy()`, `to_2d_xz()`, `to_2d_yz()` etc - convert between dimensions of vectors, dropping dimensions or adding them as per the specified function.
- `std::min()` and `std::max()` overrides.

Two-dimensional vectors:
- [vector/vector2.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector2.h)
- [vector/vector2_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector2_forward.h) - forward declarations
- [vector/vector2_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector2_types.h) - shortcut type definitions
  - `using vector2f  = vector2<float>;` Two dimensional vector of floats
  - `using vector2d  = vector2<double>;` Two dimensional vector of doubles
  - `using vector2ld = vector2<long double>;` Two dimensional vector of long doubles
  - `using vector2i  = vector2<int>;` Two dimensional vector of integers
  - `using vector2ui = vector2<unsigned int>;` Two dimensional vector of unsigned integers
  - `using vec2   = vector2<T>;`
  - `using vec2f  = vector2f;`
  - `using vec2d  = vector2d;`
  - `using vec2ld = vector2ld;`
  - `using vec2i  = vector2i;`
  - `using vec2ui = vector2ui;`

Three-dimensional vectors:
- [vector/vector3.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector3.h)
- [vector/vector3_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector3_forward.h) - forward declarations
- [vector/vector3_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector3_types.h) - shortcut type definitions
  - `using vector3f  = vector3<float>;` Three dimensional vector of floats
  - `using vector3d  = vector3<double>;` Three dimensional vector of doubles
  - `using vector3ld = vector3<long double>;` Three dimensional vector of long doubles
  - `using vector3i  = vector3<int>;` Three dimensional vector of integers
  - `using vector3ui = vector3<unsigned int>;` Three dimensional vector of unsigned integers  
  - `using vec3   = vector3<T>;`
  - `using vec3f  = vector3f;`
  - `using vec3d  = vector3d;`
  - `using vec3ld = vector3ld;`
  - `using vec3i  = vector3i;`
  - `using vec3ui = vector3ui;`
  
Four-dimensional vectors:
- [vector/vector4.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector4.h)
- [vector/vector4_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector4_forward.h) - forward declarations
- [vector/vector4_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector4_types.h) - shortcut type definitions
  - `using vector4f  = vector4<float>;` Four dimensional vector of floats
  - `using vector4d  = vector4<double>;` Four dimensional vector of doubles
  - `using vector4ld = vector4<long double>;` Four dimensional vector of long doubles
  - `using vector4i  = vector4<int>;` Four dimensional vector of integers
  - `using vector4ui = vector4<unsigned int>;` Four dimensional vector of unsigned integers
  - `using vec4   = vector4<T>;`
  - `using vec4f  = vector4f;`
  - `using vec4d  = vector4d;`
  - `using vec4ld = vector4ld;`
  - `using vec4i  = vector4i;`
  - `using vec4ui = vector4ui;`

Utility functionality for vectors:
- [vector/hash_combine.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/hash_combine.h) - defines HASH_COMBINE which uses Boost's hash_combine if available, or falls back to the internal hasher - used in vector hash functions called by standard containers:
  - `void hash_combine(std::size_t &seed, T const &v)`

#### Quaternion
A `quaternion<T>` consists of a `T` real component and a `vector3<T>` imaginary component.  There is only one quaternion type, there are no dimensional variations.

The pair of members can be accessed as `.w`, `.v`, or `.real`, `.imaginary`, or `.scalar`, `.vector`.

Quaternions have the following operations:
- `quaternion()` constructs quaternion (0 + 0i + 0j + 0k).
- `quaternion(T w, vector3<T> const &v)` constructs quaternion from real part `w` and complex part `v`.
- `quaternion(T w, T i, T j, T k)` constructs quaternion from real part `w` and complex coefficients `i`, `j` and `k`.
- `quaternion(matrix3<T> const &matrix)` and `quaternion(matrix4<T> const &matrix)` Constructs a quaternion from a 3x3 or 4x4 matrix. 
- Copy and move constructors, including copy and move constructors from vector3 and vector4, and copy casting constructors from other underlying types.
- `assign(T w = 0, T i = 0, T j = 0, T k = 0)` Assigns all component values in a single operation (or resets to identity if no values specified).
- Mathematical operators: Addition, subtraction, multiplication, division, modulo, for scalar and vector values.
- `dot(quaternion<T> const &rhs)` Dot product with other quaternion.
- Comparison operators: Equality, inequality, less than, greater than, less than or equal, greater than or equal.
- Unary operations: Unary negate, unary conjugate.
- `length` and `normalise` functions as per vectors - see above.
- `void conjugate()` and `quaternion<T> conjugate_copy()` to conjugate (unary negate) this quaternion, or to return a conjugated copy.  Only valid for unit (normalised) quaternions, otherwise use `inverse()`.
- `void invert()` and `quaternion<T> invert_copy()` - compute the inverse of this quaternion.  This is a general inverse - if you know that your quaternion is a unit quaternion, that is already normalised to 1.0, then it will be much faster to use `conjugate()` above.
- `quaternion<T> from_euler_angles(T x, T y, T z)` Construct a quaternion from three Euler angles: rotation around the x, y and z axis in degrees.
- `quaternion<T> from_euler_angles_rad(T x, T y, T z)` Construct a quaternion from three Euler angles: rotation around the x, y and z axis in radians.
- `quaternion<T> from_axis_rot(vector3<T> const &axis, T angleDeg)` Construct a quaternion as a rotation around an axis, in degrees.
- `quaternion<T> from_axis_rot_rad(vector3<T> const &axis, T angleDeg)` Construct a quaternion as a rotation around an axis, in radians.
- `void to_angle_axis(T &angle, vector3<T> &axis)` Convert this quaternion to an axis and angle combination.
- `matrix3<T> rotmatrix()` Converts this quaternion into a rotation matrix.
- `matrix4<T> transform()` Converts this quaternion into a transformation matrix.  This is identical to `rotmatrix()` above but produces a 4x4 matrix.
- `quaternion<T> lerp(T factor, quaternion<T> const &other)` return a linearly interpolated quaternion, between this quaternion and another.  Factor is 0 for this quaternion and 1 for `other`.  The range is not limited to 0-1, values outside of the range can be used to extrapolate.
- `quaternion<T> slerp(T factor, quaternion<T> const &other)` return a spherically interpolated quaternion, between this quaternion and another.  Factor is 0 for this quaternion and 1 for `other`.  The range must be 0-1.
- Output to stream operator and `std::string to_string()` for stream or string output.
- `quaternion<T> from_matrix(matrix3<T> const &mat)` Construct a quaternion from a rotation matrix.

- [quat/quat.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/quat/quat.h)
- [quat/quat_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/quat/quat_forward.h) - forward declarations
- [quat/quat_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/quat/quat_types.h) - shortcut type definitions
  - `using quaternionf  = quaternion<float>;` Quaternion of floats
  - `using quaterniond  = quaternion<double>;` Quaternion of doubles
  - `using quaternionld = quaternion<long double>;` Quaternion of long doubles
  - `using quat   = quaternion<T>;`
  - `using quatf  = quaternionf;`
  - `using quatd  = quaterniond;`
  - `using quatld = quaternionld;`

#### Matrix
Matrices are three-dimensional (3x3 - rotation matrix) or four-dimensional (4x4 - translation matrix).

Access to members is via conversion to pointer operator, or with `T at(int x, int y)`, or the function call operator `(int x, int y)`.

The following functions are common to both matrix types, the following examples use `matrix3` for consistency:
- `matrix3()` Construct an identity matrix (values of 1 on a diagonal).
- `matrix3(T *dt)` Construct a matrix from values in an array - these must be in column major order.
- Copy and move constructors.
- `matrix3(T... dt)` Variadic constructor, accepting an initialiser list containing raw data for each element to construct in order.
- `void identity()` Reset the matrix to identity (values of 1 on a diagonal).
- `matrix3<T> create_rotation_from_euler_angles(T xDeg, T yDeg, T zDeg)` Create a rotation matrix from rotation around the x, y and z axes, in degrees.
- `matrix3<T> create_rotation_from_euler_angles_rad(T xRads, T yRads, T zRads)` Create a rotation matrix from clockwise rotation around the x, y and z axes, in radians.
- `matrix3<T> create_rotation_around_axis(vector3<T> const &axis, T angle)` Create a rotation matrix by clockwise rotation around an axis, in degrees.
- `matrix3<T> create_rotation_around_axis(vector3<T> const &axis, T angle)` Create a rotation matrix by clockwise rotation around an axis, in radians.
- `matrix3<T> create_rotation_between_vectors(vector3<T> const &from, vector3<T> const &to)` Create rotation matrix representing the rotation required to align one vector to another.  Much more efficient than computing angles and creating a matrix from those.
- `matrix3<T> create_rotation_aligned_to_vector(vector3<T> const &target, vector3<T> const &up_dir)` Creates a rotation matrix to align with a target vector direction.  Accepts a vector that the rotation should point to, the direction of the up vector, and returns a matrix that is oriented to the target vector.
- `matrix3<T> from_row_major_array(FromT const *arr)` Create a matrix from an array representing an equivalent dimension matrix in row major order.
- `matrix3<T> from_column_major_array(FromT const *arr)` Create a matrix from an array representing an equivalent dimension matrix in column major order.
- Mathematical operators: Addition, subtraction, multiplication, division, modulo, for scalar, vector and matrix values.
- Comparison operators: Equality, inequality.
- `T det()` Compute the determinant of the matrix.
- `matrix3<T> inverse()` Compute the inverse of the matrix.
- `matrix3<T> transpose()` Transpose the matrix.
- `matrix3<T> lerp(T fact, matrix3<T> const &rhs)` Linear interpolation of two matrices.  Factor runs from 0 (this matrix) to 1 (other matrix), but is not limited to this range, allowing extrapolation.
- `void orthonormalise()` Orthonormalises the matrix: normalises the normal, normalises the tangent and makes sure it's orthogonal to the normal, then normalises binormal and makes sure it is orthogonal to both the normal and the tangent.
- Output to stream operator and `std::string to_string()` for stream or string output.
- `std::min()` and `std::max()` overrides.

The following functions are specific to 3x3 matrices only:
- `matrix3<T> from_ode(It const *mat)` Create rotation matrix from ODE matrix.
- `matrix4<T> get_transform()` Return a transform matrix with this matrix as the rotation component.

The following functions are specific to 4x4 matrices only:
- `matrix4<T> createTranslation(T x, T y, T z, T w = 1)` Creates a translation matrix from x, y, and z direction translation values, and an optional w translation.
- `matrix4<T> create_scale(T sx, T sy, T sz)` Create scale matrix with sx, sy, and sz being scale values for each axis.
- `matrix4<T> create_look_at(vector3<T> const &eye_pos, vector3<T> const &target_pos, vector3<T> const &up_dir)` Create a view matrix to look from the eye position to the target position, with a specified up vector.
- `matrix4<T> create_frustum(T left, T right, T bottom, T top, T near_plane, T far_plane)` Create an OpenGL compatible perspective projection according to the specified frustum clipping planes.
- `matrix4<T> create_ortho(T left, T right, T bottom, T top, T near_plane, T far_plane)` Create an OpenGL compatible orthographic projection matrix according to the specified clipping planes.
- `void set_translation(vector3<T> const &v)` Set the translation part of this matrix to the specified translation.
- `vector3<T> get_translation()` Return the translation part of this matrix.
- `void set_rotation(matrix3<T> const &m)` Set the rotation part of this matrix.
- `matrix3<T> get_rotation()` Return the rotation part of this matrix.
- `void set_scale(vector3<T> const &v)` Sets the scale part of this matrix.
- `vector3<T> get_scale()` Returns the scale part of this matrix.

Three-dimensional matrix types (3x3 matrices)
- [matrix/matrix3.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix3.h)
- [matrix/matrix3_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix3_forward.h) - forward declarations
- [matrix/matrix3_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix3_types.h) - shortcut type definitions
  - `using matrix3f  = matrix3<float>;` matrix 3x3 of floats
  - `using matrix3d  = matrix3<double>;` matrix 3x3 of doubles
  - `using matrix3ld = matrix3<long double>;` matrix 3x3 of long doubles
  - `using matrix3i  = matrix3<int>;` matrix 3x3 of integers
  - `using matrix3ui = matrix3<unsigned int>;` matrix 3x3 of unsigned integers
  - `using mat3   = matrix3<T>;`
  - `using mat3f  = matrix3f;`
  - `using mat3d  = matrix3d;`
  - `using mat3ld = matrix3ld;`
  - `using mat3i  = matrix3i;`
  - `using mat3ui = matrix3ui;`

Four-dimensional matrix types (4x4 matrices)
- [matrix/matrix4.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix4.h)
- [matrix/matrix4_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix4_forward.h) - forward declarations
- [matrix/matrix4_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix4_types.h) - shortcut type definitions
  - `using matrix4f  = matrix4<float>;` matrix 4x4 of floats
  - `using matrix4d  = matrix4<double>;` matrix 4x4 of doubles
  - `using matrix4ld = matrix4<long double>;` matrix 4x4 of long doubles
  - `using matrix4i  = matrix4<int>;` matrix 4x4 of integers
  - `using matrix4ui = matrix4<unsigned int>;` matrix 4x4 of unsigned integers
  - `using mat4   = matrix4<T>;`
  - `using mat4f  = matrix4f;`
  - `using mat4d  = matrix4d;`
  - `using mat4ld = matrix4ld;`
  - `using mat4i  = matrix4i;`
  - `using mat4ui = matrix4ui;`

#### Axis-aligned Bounding Box (AABB)
Two and three dimensional axis aligned bounding boxes, which can be constructed to include any number of points they must surround, can test whether another point or other AABB intersects with it, and can be transformed with matrixes, and intuitively queried and modified with boolean operators.

Access is via `vector2<T> min` and `vector2<T> max` members, which represent the minimum and maximum corner of the bounding box.

The following functionality is common to all dimensions of bounding box types, and these examples use `aabb2` for consistency:
- `aabb2()` Construct a default AABB, which is considered to be in an "invalid" state (negative size) until at least one point is added to it.
- `aabb2(vector2<SrcT> const &point)` Construct an AABB containing one point.
- `aabb2(SrcT x0, SrcT y0, SrcT x1, SrcT y1)` Construct an AABB from piecewise definitions of the x, y, (z) elements of min and max coordinates.
- `aabb2(vector2<SrcT> const &min, vector2<SrcT> const &max)` Construct an AABB from vector min and max coordinates.
- Copy and move constructors and assignment operators.
- `bool valid()` Checks if a bounding box is valid.  A valid bounding box has a non-negative size.  Default-constructed bounding boxes are invalid until made valid by an extend operation.
- `void invalidate()` Renders this bounding box invalid (gives it a negative size).  Future calls to `valid()` will return false until an extend operation makes it valid again.
- `void extend(vector2<SrcT> const &point)` Extend the bounding box to include the specified point.
- `void extend(aabb2<SrcT> const &box)` Extend this bounding box to include another AABB.
- `aabb2<T> extended(vector2<SrcT> const &point)` Gets a copy of this bounding box, extended to include the specified point.
- `aabb2<T> extended(aabb2<SrcT> const &box)` Gets a copy of this bounding box extended to include another AABB.
- `bool intersects(vector2<SrcT> const &point)` Test if the point is within this bounding box.
- `bool intersects(aabb2<SrcT> const &box)` Test if the other bounding box intersects (even partially) with this AABB.
- `aabb2<T> intersection(aabb2<SrcT> const &other)` Return the intersection of this bounding box with another AABB, or return a default-constructed (invalid) AABB if there is no intersection.  There is no need to separately check `intersects()` before calling this - instead, just check whether the result is `valid()`.
- `bool ray_intersects(vector2<SrcT> const &ray, vector2<SrcT> const &origin = vector2<SrcT>())` Tests if a ray intersects this bounding box.  The ray does not need to be normalised.  If the origin is specified, the ray runs from the origin, otherwise it runs from the default constructed vector of the given type - with numeric types, the origin (0, 0).
- `vector2<T> centre()` Calculates the centre coordinates of the bounding box.
- `vector2<T> extent()` Calculates the extent of the bounding box from the centre (i.e. half of the diagonal size).
- `vector2<T> size()` Calculates the diagonal size of the bounding box.
- `vector2<T> point(unsigned int i)` Gets a corner of the bounding box by index, with 0 representing (max.x, max.y) and incrementing clockwise.
- Mathematical operators: Addition and subtraction, for scalar and vector values.  Addition and subtraction by vectors moves a bounding box in space.
- Comparison operators: Equality, inequality.
- `<<` operator to extend a bounding box by a point or another AABB, as per the `extend` functions.
- `|` operator to return an extended bounding box, as per the `extended` functions.
- `&` operator to return an intersection between this and another bounding box, as per the `intersection` function.
- Output to stream operator and `std::string to_string()` for stream or string output.

Two-dimensional bounding box types
- [aabb/aabb2.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb2.h)
- [aabb/aabb2_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb2_forward.h) - forward declarations
- [aabb/aabb2_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb2_types.h) - shortcut type definitions
  - `using aabb2f  = aabb2<float>;` 2D axis-aligned bounding box of floats
  - `using aabb2d  = aabb2<double>;` 2D axis-aligned bounding box of doubles
  - `using aabb2ld = aabb2<long double>;` 2D axis-aligned bounding box of long doubles
  - `using aabb2i  = aabb2<int>; `2D axis-aligned bounding box of integers
  - `using aabb2ui = aabb2<unsigned int>; `2D axis-aligned bounding box of unsigned integers

Three-dimensional bounding box types
- [aabb/aabb3.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb3.h)
- [aabb/aabb3_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb3_forward.h) - forward declarations
- [aabb/aabb3_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb3_types.h) - shortcut type definitions
  - `using aabb3f  = aabb3<float>;` 3D axis-aligned bounding box of floats
  - `using aabb3d  = aabb3<double>;` 3D axis-aligned bounding box of doubles
  - `using aabb3ld = aabb3<long double>;` 3D axis-aligned bounding box of long doubles
  - `using aabb3i  = aabb3<int>;` 2D axis-aligned bounding box of integers
  - `using aabb3ui = aabb3<unsigned int>;` 2D axis-aligned bounding box of unsigned integers

### Stand-alone functionality
Interpolation
- [lerp.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/lerp.h)
  - `T lerp(T const a, T const b, F factor)` linear interpolation between `a` and `b` by factor `f` - result is equal to `a` when `f == 0` and to `b` when `f == 1`.  Usable with VectorStorm types as well as primitive types.  The range is not limited to 0-1, values outside of the range can be used to extrapolate.
- [sigmoid.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/sigmoid.h)

Conversion
- [deg2rad.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/deg2rad.h)
  - `T deg2rad(T const angle_deg)` convert angles in degrees to radians.
- [rad2deg.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/rad2deg.h)
  - `T rad2deg(T const angle_rad)` convert angles in radians to degrees.

Optimised algorithms
- [floor_fast.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/floor_fast.h) - Fast floor algorithms for floating types, returning an integer rather than the same floating type.  These should be faster than `std::floor` on most implementations.
  - `int floor_fast(float value)` Fast floor of a float to an integer
  - `int floor_fast(double value)` Fast floor of a double to an integer
- [sqrt_fast.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/sqrt_fast.h) - Various optimised approximations for fast square root and inverse square root calculations.  Performance of each may differ by platform - benchmarking is advised to select the appropriate algorithm for a specific situation.
  - `float sqrt_inv_fast(float number)` Adapted from Quake III's fast inverse square root approximation
  - `sqrt_inv_fast(double number)` Similar to the Quake III fast inverse square root but for doubles
  - `long double sqrt_fast(long double number)` This is sped up by simply casting the long double to a double for the fast sqrt operation.
  - `int sqrt_fast(int number)` Fast integer square root, through the float path
  - `float sqrt_inv_faster(float number)` Adapted from Quake III's fast inverse square root approximation - one iteration version
  - `double sqrt_inv_faster(double number)` Similar to the Quake III fast inverse square root but for doubles - one iteration version
  - `long double sqrt_faster(long double number)` This is sped up by simply casting the long double to a double for the faster sqrt operation.
  - `int sqrt_faster(int number)` Faster integer square root, through the float path with one iteration
  - `float sqrt_inv_sse(float number)` Scalar SSE inverse square root approximation
  - `float sqrt_sse(float number)` Scalar SSE square root approximation
- [sincos.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/sincos.h) - Provides a platform-independent single `sincos` implementation, to return a sine and a cosine of a value in a single call.  Will use platform-optimised builtins when available, and fall back to separate sin and cos computation otherwise, so you don't have to worry about calling builtins directly when you need to use both sin and cos results at the same time.
- `void sincos_any(T const angle_rad, T &out_sin, T &out_cos)`
- `void sincos_any(int const angle_rad, int &out_sin, int &out_cos)`
- `void sincos_any(float const angle_rad, float &out_sin, float &out_cos)`
- `sincos_any(long double const angle_rad, long double &out_sin, long double &out_cos)`

### Miscellaneous
- [pi.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/pi.h) - provides a definition of PI based on Boost if available, or an internal fallback if not
- [epsilon.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/epsilon.h) - provides a definition of epsilon value for use in soft float comparison when `VECTORSTORM_SOFT_COMPARE` is defined
- [deprecated_macros.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/deprecated_macros.h) - "deprecated" macros for porting compatibility with the vmath library

## Optimisation-safety
VectorStorm types use explicit constructors in a bid to aid the user in avoiding unexpected or unintended copies.  For instance, when constructing a new VectorStorm vector as a copy of an existing vector, you will need to explicitly copy the object so it is clear in the code when such copies take place.  You are then able to assume other operations with vectors will be copy-free.  Use of `std::move` is encouraged wherever possible.

## Interoperability

### Use with OpenGL
Float, double, signed and unsigned integer vector, quaternion and matrix types can all be passed to OpenGL directly without any casting, for any function that accepts array representations of the equivalent types.  Individual components can also be passed to functions that accept separate components.  For example:
```cpp
vec4f my_colour{1.0f, 0.5f, 0.0f, 1.0f};
// set as vector:
glColor4fv(my_colour);
// which is functionally equivalent to:
glColor4f(my_colour.r, my_colour.g, my_colour.b, my_colour.a);
// and shares identical behaviour with any of:
glColor4fv(my_colour[0]);
glColor4fv(my_colour.x);
glColor4fv(*my_colour);
```

### Use with GLFW
Most GLFW functions take separate arguments for width and height, so simply pass the relevant components to each - for example:
```cpp
vec2i my_viewport_size{1024, 768};
glfwSetWindowSize(my_window, my_viewport_size.x, my_viewport_size.y);
```

### Use with ImGUI
VectorStorm vector types can easily be used natively with [Dear ImGui](https://github.com/ocornut/imgui), and offer a lot of power relative to ImGui's simple Vec2 and Vec4 types.

To use VectorStorm with ImGui, edit your `imconfig.h` file as follows:
```cpp
//---- Define constructor and implicit cast operators to convert back<>forth between your math types and ImVec2/ImVec4.
// This will be inlined as part of ImVec2 and ImVec4 class declarations.
#include <vectorstorm/vector/vector2.h>
#include <vectorstorm/vector/vector4.h>

#define IM_VEC2_CLASS_EXTRA                                                    \
        constexpr ImVec2(const vector2<float> &f) : x(f.x), y(f.y) {}          \
        constexpr ImVec2(const vector2<int> &f) : x(static_cast<float>(f.x)), y(static_cast<float>(f.y)) {} \
        constexpr ImVec2(const vector2<unsigned int> &f) : x(static_cast<float>(f.x)), y(static_cast<float>(f.y)) {} \
        operator vector2<float>() const {return vector2<float>{x, y};}

#define IM_VEC4_CLASS_EXTRA                                                    \
        constexpr ImVec4(const vector4<float> &f) : x(f.x), y(f.y), z(f.z), w(f.w) {} \
        constexpr ImVec4(const vector4<int> &f) : x(static_cast<float>(f.x)), y(static_cast<float>(f.y)), z(static_cast<float>(f.z)), w(static_cast<float>(f.w)) {} \
        constexpr ImVec4(const vector4<unsigned int> &f) : x(static_cast<float>(f.x)), y(static_cast<float>(f.y)), z(static_cast<float>(f.z)), w(static_cast<float>(f.w)) {} \
        operator vector4<float>() const {return vector4<float>{x, y, z, w};}
```

## Defines

- `VECTORSTORM_NAMESPACE` - What namespace to use, if any. Defaults to none. 
- `VECTORSTORM_NO_BOOST` - Avoid using boost headers - may have some performance penalty.
- `VECTORSTORM_SOFT_COMPARE` - Enable fuzzy matching for different types, with epsilon used to match within a range of rounding error.  This is needed for accurate comparisons between floating point types on most architectures, but as this is relatively expensive, it is not enabled by default.
- `VECTORSTORM_PREINSTANTIATE` - Instantiate all templates with common numerical types. 
