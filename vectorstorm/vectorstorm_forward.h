#ifndef VECTORSTORM_FORWARD_H_INCLUDED
#define VECTORSTORM_FORWARD_H_INCLUDED

/// Cut-down header alternative for vectorstorm.h including only forward declarations
/// Include this in other headers instead of vectorstorm.h wherever possible

#include "vectorstorm/deprecated_macros.h"
#define _USE_MATH_DEFINES

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

/// Forward declarations
#include "vector/vector2_forward.h"
#include "vector/vector3_forward.h"
#include "vector/vector4_forward.h"
#include "matrix/matrix3_forward.h"
#include "matrix/matrix4_forward.h"
#include "quat/quat_forward.h"
#include "aabb/aabb2_forward.h"
#include "aabb/aabb3_forward.h"

#ifdef VECTORSTORM_NAMESPACE
}
#endif

#endif // VECTORSTORM_FORWARD_H_INCLUDED
