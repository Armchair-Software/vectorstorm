#ifndef VECTORSTORM_EPSILON_H_INCLUDED
#define VECTORSTORM_EPSILON_H_INCLUDED

// note: use VMATH_SOFT_COMPARE to enable fuzzy matching for different types,
// with epsilon used to match within a range of rounding error - but doing this
// can be very expensive in some cases.
double constexpr epsilon = 4.37114e-05;
#define EPSILON epsilon


#endif // VECTORSTORM_EPSILON_H_INCLUDED
