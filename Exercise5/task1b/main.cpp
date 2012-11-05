#include <iostream>
#include <cmath>
#include "simpson.h"



/**
*   @param N amount of bins used for the integration; Has to be even!
*   @param a stat value of integration intervall
*   @param b end value of integration intervall
*   @param (*func) is a pointer to a function to be be integrated
*
*   Pre Condition:
*       N has to be even and of type int
*       a and b are of type double and a<b
*       (*func) is a pointer to a function taking a double and returning a double
*
*   Post Condition:
*       Return the numerical integration using the Simpson rule of the function func
*       in the intervall [a,b]
*/
template <class F, class T>
T simpson_int(F &f,const T &a, const T &b, unsigned N)
{
    T h=(b-a)/static_cast<double>(N);
    unsigned N_half=N/2;
    T xOld=a;
    T sum_even=0;
    T sum_odd=0;
    T sim;

    for(unsigned i=1;i<N_half;i++)
    {
        xOld+=h;
        sum_odd+=f(xOld);
        xOld+=h;
        sum_even+=f(xOld);

    }
    //sum goes only up to N/2-1 and we want to go up to N/2 for the odd summ so we add one mor
    xOld+=h;
    sum_odd+=f(xOld);

    //sum up the whole thing
    sim=h/3.0*(f(a)+2*sum_even+4*sum_odd+f(b));
    return sim;
}

int main() {

   // Function f(1);

    const unsigned BINS=128;
  /*  const double INTERVAL_MIN=0.0;

    const double INTERVAL_MAX=M_PI;

    std::cout.precision(15);
    std::cout << "int_"<<INTERVAL_MIN<<"^"<<INTERVAL_MAX<<" dx sin(lx) = "
	<< simpson_int(f,INTERVAL_MIN,INTERVAL_MAX,BINS) << std::endl;
    */


    Function func_obj(1);

    const double INTERVAL_MIN2=5;

    const double INTERVAL_MAX2=10;

    std::cout.precision(15);
    std::cout << "int_"<<INTERVAL_MIN2<<"^"<<INTERVAL_MAX2<<" dx sin(lx) = "
	<< simpson_int(func_obj,INTERVAL_MIN2,INTERVAL_MAX2,BINS) << std::endl;
    return 0;
}
