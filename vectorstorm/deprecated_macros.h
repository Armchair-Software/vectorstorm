/// Backwards-compatible conversions of deprecated macro names and warnings if they're used

#ifdef VMATH_NAMESPACE
  #warning "The VMATH_NAMESPACE macro is deprecated, use VECTORSTORM_NAMESPACE."
  #define VECTORSTORM_NAMESPACE VECTORSTORM_NAMESPACE
#endif // VMATH_NAMESPACE

#ifdef VMATH_NO_BOOST
  #warning "The VMATH_NO_BOOST macro is deprecated, use VECTORSTORM_NO_BOOST."
  #define VECTORSTORM_NO_BOOST
#endif // VMATH_NO_BOOST

#ifdef VMATH_SOFT_COMPARE
  #warning "The VMATH_SOFT_COMPARE macro is deprecated, use VECTORSTORM_SOFT_COMPARE."
  #define VECTORSTORM_SOFT_COMPARE
#endif // VMATH_SOFT_COMPARE
