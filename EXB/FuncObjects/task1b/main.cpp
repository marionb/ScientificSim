#include <iostream>
#include <cmath>
#include "simpson.h"
#include <sys/time.h> //to be able to use getttimeofday()



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

    struct timeval tim;
    unsigned N;
    //std::cout<<"Set number of bins: ";
    //std::cin>>N;
    const unsigned BINS=100;

    Function func_obj1(0);
    Function func_obj2(1);
    Function func_obj3(2);

    const double INTERVAL_MIN2=0;

    const double INTERVAL_MAX2=M_PI;

    std::cout.precision(15);

    gettimeofday(&tim, NULL);
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double f1=simpson_int(func_obj1,INTERVAL_MIN2,INTERVAL_MAX2,BINS);
    gettimeofday(&tim, NULL);
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    gettimeofday(&tim, NULL);
    double t3=tim.tv_sec+(tim.tv_usec/1000000.0);
    double f2=simpson_int(func_obj2,INTERVAL_MIN2,INTERVAL_MAX2,BINS);
    gettimeofday(&tim, NULL);
    double t4=tim.tv_sec+(tim.tv_usec/1000000.0);

    gettimeofday(&tim, NULL);
    double t5=tim.tv_sec+(tim.tv_usec/1000000.0);
    double f3=simpson_int(func_obj3,INTERVAL_MIN2,INTERVAL_MAX2,BINS);
    gettimeofday(&tim, NULL);
    double t6=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout << "int_"<<INTERVAL_MIN2<<"^"<<INTERVAL_MAX2<<" dx sin(lx) = "<< std::endl;
    std::cout << "l=0:"<< f1<<" funcion call in "<<t2-t1<<"seconds"<<std::endl;
    std::cout << "l=1:"<< f2<<" funcion call in "<<t4-t3<<"seconds"<<std::endl;
    std::cout << "l=2:"<< f3<<" funcion call in "<<t6-t5<<"seconds"<<std::endl;
    return 0;
}
