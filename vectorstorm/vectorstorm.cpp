#include "vectorstorm.h"

#ifdef VECTORSTORM_NAMESPACE
namespace VECTORSTORM_NAMESPACE {
#endif

#ifdef VECTORSTORM_PREINSTANTIATE
  template class vector2<float>;
  template class vector2<double>;
  template class vector2<long double>;
  template class vector2<int>;
  template class vector2<unsigned int>;
  template class vector3<float>;
  template class vector3<double>;
  template class vector3<long double>;
  template class vector3<int>;
  template class vector3<unsigned int>;
  template class vector4<float>;
  template class vector4<double>;
  template class vector4<long double>;
  template class vector4<int>;
  template class vector4<unsigned int>;
  template class matrix3<float>;
  template class matrix3<double>;
  template class matrix3<long double>;
  template class matrix3<int>;
  template class matrix3<unsigned int>;
  template class matrix4<float>;
  template class matrix4<double>;
  template class matrix4<long double>;
  template class matrix4<int>;
  template class matrix4<unsigned int>;
  template class quaternion<float>;
  template class quaternion<double>;
  template class quaternion<long double>;
  template class aabb2<float>;
  template class aabb2<double>;
  template class aabb2<long double>;
  template class aabb2<int>;
  template class aabb2<unsigned int>;
  template class aabb3<float>;
  template class aabb3<double>;
  template class aabb3<long double>;
  template class aabb3<int>;
  template class aabb3<unsigned int>;
#endif // VECTORSTORM_PREINSTANTIATE

#ifdef VECTORSTORM_NAMESPACE
}
#endif
