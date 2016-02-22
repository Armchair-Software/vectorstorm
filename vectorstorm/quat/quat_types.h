#ifndef VECTORSTORM_QUAT_TYPES_H_INCLUDED
#define VECTORSTORM_QUAT_TYPES_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for quaternion
//-------------------------------------
/// Quaternion of floats
using quaternionf  = quaternion<float>;
/// Quaternion of doubles
using quaterniond  = quaternion<double>;
/// Quaternion of long doubles
using quaternionld = quaternion<long double>;

// abbreviated aliases
template<typename T>
using quat   = quaternion<T>;
using quatf  = quaternionf;
using quatd  = quaterniond;
using quatld = quaternionld;

// deprecated transitional declarations
template<typename T>
using Quaternion   __attribute__((deprecated("Use quaternion or quat instead."))) = quaternion<T>;
template<typename T>
using Quat   __attribute__((deprecated("Use quaternion or quat instead."))) = quaternion<T>;
using Quatf  __attribute__((deprecated("Use quaternion or quat instead."))) = quaternionf;
using Quatd  __attribute__((deprecated("Use quaternion or quat instead."))) = quaterniond;
using Quatld __attribute__((deprecated("Use quaternion or quat instead."))) = quaternionld;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_QUAT_TYPES_H_INCLUDED
