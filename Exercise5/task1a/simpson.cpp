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
double simpson_int(Function &f,const double &a,const double &b, unsigned N)
{
    double h=(b-a)/double(N);
    unsigned N_half=N/2;
    double xOld=a;
    //double xNew=a;
    double sum_even=0;
    double sum_odd=0;
    double sim;

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
