
/**
*   Exercise 1:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           01/10/2012
*
*   Problem 3:      Simpson numerical integration

*   Description:    Numerical integration of f(x)=sin(x) with x in [0,PI]
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double func(double x)
{
    #ifdef Debug
    return x*(1-x);
    #endif
    return sin(x);
}

/**
*   Function to numericaly integrate with the Simpson rule
*   @param N amount of bins used for the integration; Has to be even!
*   @param a stat value of integration intervall
*   @param b end value of integration intervall
*/
double simpson(double a, double b, int N)
{
    /*if(N%2!=0)
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
        xNew=a+(i+1)*h;
        xOld=a+i*h;

        sum2+=func((xNew+xOld)/2.0);
        if(i<N)
        {
            sum1+=func(xOld);
        }
    }
    sim=h/3.0*(0.5*func(a)+sum1+2*sum2+0.5*func(b));
    return sim;*/

    double h=(b-a)/double(N);
    unsigned N_half=N/2;
    double x_Old=a;
    //double xNew=a;
    double sum_even=0;
    double sum_odd=0;
    double sim;

    for(unsigned i=1;i<N_half;i++)
    {
        x_Old+=h;
        sum_odd+=func(x_Old);
        x_Old+=h;
        sum_even+=func(x_Old);

    }
    //sum goes only up to N/2-1 and we want to go up to N/2 for the odd summ so we add one more
    x_Old+=h;
    sum_odd+=func(x_Old);

    //sum up the whole thing
    sim=h/3.0*(func(a)+2*sum_even+4*sum_odd+func(b));
    return sim;
}

int main()
{
    int n=100;
    #ifdef Debug
    std::cout<<"\nNumerical integration of x*(1-x); x in [0,1] using "<<n<<" bins:\n";
    std::cout<< simpson(0,M_PI,n);
    #endif
    std::cout<<"\nNumerical integration of sin(x); x in [0,PI] using "<<n<<" bins:\n";
    std::cout<< simpson(0,M_PI,n);
    return 0;

}
