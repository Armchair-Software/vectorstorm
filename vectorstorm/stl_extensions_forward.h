#ifndef VECTORSTORM_STL_EXTENSIONS_FORWARD_H_INCLUDED
#define VECTORSTORM_STL_EXTENSIONS_FORWARD_H_INCLUDED

namespace std {

template<typename T> constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b);
template<typename T> constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b);
template<typename T> constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b);
template<typename T> constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b);
template<typename T> constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b);
template<typename T> constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b);

}

#endif // VECTORSTORM_STL_EXTENSIONS_FORWARD_H_INCLUDED
