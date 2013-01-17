/**
*   Exercise 5:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           09/10/2012
*
*   Description:    Simpson numerical integration.
*                   Numerical integration of f(x) with x in [a,b] and N bins
*/

#include <iostream>
#include "simpson.h"


//Base class Integrator
double Integrate::simpson_int(const double a,const double b,const unsigned N)
{

    double h=(b-a)/static_cast<double>(N);
    unsigned N_half=N/2;
    double xOld=a;
    //double xNew=a;
    double sum_even=0;
    double sum_odd=0;
    double sim;

    for(unsigned i=1;i<N_half;i++)
    {
        xOld+=h;
        sum_odd+=(*this)(xOld);
        xOld+=h;
        sum_even+=(*this)(xOld);

    }
    //sum goes only up to N/2-1 and we want to go up to N/2 for the odd summ so we add one mor
    xOld+=h;
    sum_odd+=(*this)(xOld);

    //sum up the whole thing
    sim=h/3.0*((*this)(xOld)+2*sum_even+4*sum_odd+(*this)(xOld));
    return sim;
}
