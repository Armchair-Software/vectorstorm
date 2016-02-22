#ifndef VECTORSTORM_STL_EXTENSIONS_H_INCLUDED
#define VECTORSTORM_STL_EXTENSIONS_H_INCLUDED

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Standard C++ library extensions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace std {

/**
 * Gets vector containing minimal values of @a a and @a b coordinates.
 * @return Vector of minimal coordinates.
 */
template<typename T>
constexpr vector2<T> min(vector2<T> const &a, const vector2<T> &b) {
  return vector2<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y));
}

/**
 * Gets vector containing minimal values of @a a and @a b coordinates.
 * @return Vector of minimal coordinates.
 */
template<typename T>
constexpr vector3<T> min(vector3<T> const &a, const vector3<T> &b) {
  return vector3<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z));
}

/**
 * Gets vector containing minimal values of @a a and @a b coordinates.
 * @return Vector of minimal coordinates.
 */
template<typename T>
constexpr vector4<T> min(vector4<T> const &a, const vector4<T> &b) {
  return vector4<T>(::std::min(a.x, b.x), ::std::min(a.y, b.y), ::std::min(a.z, b.z), ::std::min(a.w, b.w));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
constexpr vector2<T> max(vector2<T> const &a, const vector2<T> &b) {
  return vector2<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
constexpr vector3<T> max(vector3<T> const &a, const vector3<T> &b) {
  return vector3<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z));
}

/**
 * Gets vector containing maximal values of @a a and @a b coordinates.
 * @return Vector of maximal coordinates.
 */
template<typename T>
constexpr vector4<T> max(vector4<T> const &a, const vector4<T> &b) {
  return vector4<T>(::std::max(a.x, b.x), ::std::max(a.y, b.y), ::std::max(a.z, b.z), ::std::max(a.w, b.w));
}

}

#endif // VECTORSTORM_STL_EXTENSIONS_H_INCLUDED
