#pragma once

/**
 * @mainpage Intro
 * Vector mathematics for computer graphics - VoxelStorm version
 *
 * @section Features
 * <ul>
 *    <li> basic arithmetic operations - using operators </li>
 *    <li> basic linear algebra operations - such as transpose, dot product, etc. </li>
 *    <li> aliases for vertex coordinates - it means:
 *    <pre>
 *  vector3f v;
 *  // use vertex coordinates
 *  v.x = 1; v.y = 2; v.z = -1;
 *
 *  // use texture coordinates
 *  v.s = 0; v.t = 1; v.u = 0.5;
 *  // use colour coordinates
 *  v.r = 1; v.g = 0.5; v.b = 0;
 *    </pre>
 *    </li>
 *    <li> conversion constructor and assign operators - so you can assign a value of vector3&lt;T1&gt; type
 *    to a variable of vector3&lt;T2&gt; type for any convertible T1, T2 type pairs. In other words, you can do this:
 *    <pre>
 *
 *  vector3f f3; vector3d d3 = f3;
 *  ...
 *  f3 = d3;
 *    </pre>
 *    </li>
 * </ul>
 *
 * @section Predefined types
 * <ul>
 *  <li>(vector2) Two dimensional vector
 *    <ul>
 *      <li>float &mdash; vector2f</li>
 *      <li>double &mdash; vector2d</li>
 *      <li>int &mdash; vector2i</li>
 *    </ul>
 *  </li>
 *  <li>(vector3) Three dimensional vector
 *    <ul>
 *      <li>float &mdash; vector3f</li>
 *      <li>double &mdash; vector3d</li>
 *      <li>int &mdash; vector3i</li>
 *    </ul>
 *  </li>
 *  <li>(vector4) Four dimensional vector
 *    <ul>
 *      <li>float &mdash; vector4f</li>
 *      <li>double &mdash; vector4d</li>
 *      <li>int &mdash; vector4i</li>
 *    </ul>
 *  </li>
 *  <li>(matrix3) matrix 3x3
 *    <ul>
 *      <li>float &mdash; matrix3f</li>
 *      <li>double &mdash; matrix3d</li>
 *      <li>int &mdash; matrix3i</li>
 *    </ul>
 *  </li>
 *  <li>(matrix4) matrix 4x4
 *    <ul>
 *      <li>float &mdash; matrix4f</li>
 *      <li>double &mdash; matrix4d</li>
 *      <li>int &mdash; matrix4i</li>
 *    </ul>
 *  </li>
 *    <li> quaternion
 *    <ul>
 *      <li>float &mdash; quatf</li>
 *      <li>double &mdash; quatd</li>
 *    </ul>
 *    </li>
 *  </li>
 * </ul>
 *
 * Defines:
 *   VECTORSTORM_NAMESPACE - What namespace to use, if any.  Defaults to none.
 *   VECTORSTORM_NO_BOOST - Avoid using boost headers, may have some performance
 *     penalty.
 *   VECTORSTORM_SOFT_COMPARE - Enable fuzzy matching for different types, with
 *     epsilon used to match within a range of rounding error - but doing this
 *     can be very expensive in some cases.
 *   VECTORSTORM_PREINSTANTIATE - Instantiate all templates with common
 *     numerical types.
 *
 */

#include "deg2rad.h"
#include "rad2deg.h"

#include "sincos.h"
#include "sigmoid.h"

#include "sqrt_fast.h"
#include "floor_fast.h"

#include "lerp.h"

#include "vectorstorm_forward.h"

#include "vector/vector2.h"
#include "vector/vector3.h"
#include "vector/vector4.h"

#include "matrix/matrix3.h"
#include "matrix/matrix4.h"

#include "quat/quat.h"

#include "aabb/aabb2.h"
#include "aabb/aabb3.h"
