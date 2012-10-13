/**
*   Exercise 2:     Programing Techniques for Scientific Simulations
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
double simpson(double (*func)(double), double a, double b, int N)
{
    if(N%2!=0)
    {
        std::cout<<"Error Number of bins N has to be even!\n";
        return 0;
    }

    double h=(b-a)/double(N);
    double xOld=a;
    double xNew=a;
    double sum1=0;
    double sum2=0;
    double sim;

    for(int i=1;i<=N;i++)
    {
        xNew=a+(i-1)*h;
        xOld=a+i*h;

        sum2+=(*func)((xNew+xOld)/2.0);
        if(i>1)
        {
            sum1+=func(xOld);
        }
    }
    sim=h/3.0*(0.5*(*func)(a)+sum1+2*sum2+0.5*(*func)(b));
    return sim;
}
