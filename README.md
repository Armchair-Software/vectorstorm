# VectorStorm

Vector mathematics for computer graphics - VoxelStorm version.

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

## Structure
### Top level includes
- [vectorstorm.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm.h) - Include this to pull in all other headers.  For finer grained control, only include the required headers below.
- [vectorstorm_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm_forward.h) - Forward declaration for all types.
- [vectorstorm.cpp](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm.cpp) - Optionally build this in your project, with `VECTORSTORM_PREINSTANTIATE` enabled, if you wish to instantiate all templates with common numerical types.  Not normally required.
 
### Primary types
#### Vector
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
  - `T lerp(T const a, T const b, F factor)` linear interpolation between `a` and `b` by factor `f` - result is equal to `a` when `f == 0` and to `b` when `f == 1`.  Usable with VectorStorm types as well as primitive types.  
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

 
## Interoperability

### Use with OpenGL

### Use with GLFW

### Use with ImGUI

## Defines

- `VECTORSTORM_NAMESPACE` - What namespace to use, if any. Defaults to none. 
- `VECTORSTORM_NO_BOOST` - Avoid using boost headers - may have some performance penalty.
- `VECTORSTORM_SOFT_COMPARE` - Enable fuzzy matching for different types, with epsilon used to match within a range of rounding error.  This is needed for accurate comparisons between floating point types on most architectures, but as this is relatively expensive, it is not enabled by default.
- `VECTORSTORM_PREINSTANTIATE` - Instantiate all templates with common numerical types. 
