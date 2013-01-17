
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
#include <sys/time.h> //to be able to use getttimeofday()

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*double func1(double x)
{
    return 0;
}

double func2(double x)
{
    return 1;
}

double func3(double x)
{
    return x;
}

double func4(double x)
{
    return x*x;
}

double func5(double x)
{
    return sin(x);
}*/

double func(double x)
{
    return sin(5*x);
}

/**
*   Function to numericaly integrate with the Simpson rule
*   @param N amount of bins used for the integration; Has to be even!
*   @param a stat value of integration intervall
*   @param b end value of integration intervall
*/
double simpson(double a, double b, int N)
{
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

    struct timeval tim;

    gettimeofday(&tim, NULL);
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double f1=simpson(0,M_PI,n);
    gettimeofday(&tim, NULL);
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"\nNumerical integration of sin(x); x in [0,PI] is "<< f1<<" using "<<n<<" bins:\n";
    std::cout<< "tiem to integrate "<<t2-t1<<" seconds\n";
    return 0;

}
