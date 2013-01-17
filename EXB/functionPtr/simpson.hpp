/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 2.2
 * by Jakub Imriska
 */

#ifndef SIMPSON_INTEGRATION_
#define SIMPSON_INTEGRATION_

double Simpson_integrate(double (*f)(double), double a, double b, unsigned N);
/* PRECONDITIONS: 
 *      the domain of the function f(x) has to be at least the interval <min(a,b),max(a,b)>
 *      N > 0
 *      boundary values a,b are convertible to double
 *      N convertible to unsigned
 *
 * POSTCONDITIONS: 
 *      the return value will approximate the integral of the function f(x) over the interval 
 *       <min(a,b),max(a,b)> by the use of the Simpson rule with N equally sized bins
 *
 * COMPLEXITY: 
 *      the number of function calls f(x) will be exactly 2*N+1
 * 
 * DOCUMENTATION:
 *      the interval given by the boundaries 'a' and 'b' will be divided to 'N' equally sized bins,
 *      the function 'f' will be aproximated by a parabola using the function values at bin-boundaries and in the bin-midpoint
 *      the integral will be approximated by the sum of the integrals over each bin of the corresponding interpolating parabola
 *      the asymptotic convergence is 1/N^4
 */

#endif  //SIMPSON_INTEGRATION_
