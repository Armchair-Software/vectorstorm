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

#ifdef VECTORSTORM_NAMESPACE
}
#endif //VECTORSTORM_NAMESPACE
