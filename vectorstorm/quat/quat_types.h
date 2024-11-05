#pragma once

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
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

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
