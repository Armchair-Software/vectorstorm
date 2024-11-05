#pragma once

// use boost's constants if available
#ifndef VECTORSTORM_NO_BOOST
  #include <boost/math/constants/constants.hpp>
  #ifndef M_PI
    #define M_PI boost::math::constants::pi<double>()
  #endif // M_PI
#else  // VECTORSTORM_NO_BOOST
  #ifndef M_PI
    #define M_PI 3.14159265358979323846  /* pi */
  #endif // M_PI
#endif // VECTORSTORM_NO_BOOST
