/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 2.2
 * by Jakub Imriska
 */

#include <cstdlib>
#include <cassert>
#include "simpson.hpp"

double Simpson_integrate(double (*f)(double), double a, double b, unsigned N) {
    assert( f != NULL );
    assert( N > 0 );

    double half_bin_size = (b-a)/static_cast<double>(2*N);
    double x_ = a+half_bin_size;
    double sum_odd = f(x_);
    double sum_even(0);

    for (unsigned i=1; i<N; i++) {
        x_=a+2*i*half_bin_size;
        sum_even+=f(x_);
        sum_odd+=f(x_+half_bin_size);
    }

    return (4.*sum_odd+2.*sum_even+f(a)+f(b))*half_bin_size/3.;
}
