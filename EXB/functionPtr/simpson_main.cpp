/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 2.2
 * by Jakub Imriska
 * I Used the solutions given and modified them as I could not get my own program runing again
 */

#include <iostream>
#include <cmath>
#include "simpson.hpp"
#include <sys/time.h> //to be able to use getttimeofday()

double f1(double x) {
    return 0;
}
double f2(double x)
{
    return 1;
}
double f3(double x)
{
    return x;
}
double f4(double x)
{
    return x*x;
}

double f6(double x)
{
    return sin(5*x);
}

int main() {
    unsigned N;
    struct timeval tim;
    std::cout<<"Set number of bins: ";
    std::cin>>N;

    const double lower_boundary=0.0;
    const double upper_boundary=M_PI;
    std::cout.precision(15);


//F1(x)=0
    gettimeofday(&tim, NULL);
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F1=Simpson_integrate(f1,lower_boundary, upper_boundary,N);
    gettimeofday(&tim, NULL);
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"F(X)=int_"<<lower_boundary<<"^"<<upper_boundary<<" f(x), in "<<N <<"stepps\n";
    std::cout<<"F1(x)="<<F1<<" time to integrate: "<<t2-t1<<std::endl;

//F2(x)=1
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F2=Simpson_integrate(f2,lower_boundary, upper_boundary,N);
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"F2(x)="<<F2<<" time to integrate: "<<t2-t1<<std::endl;

//F3(x)=x
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F3=Simpson_integrate(f3,lower_boundary, upper_boundary,N);
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"F3(x)="<<F3<<" time to integrate: "<<t2-t1<<std::endl;

//F4(x)=x*x
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F4=Simpson_integrate(f4,lower_boundary, upper_boundary,N);
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"F4(x)="<<F4<<" time to integrate: "<<t2-t1<<std::endl;

//F5(x)=sin(x)
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F5=Simpson_integrate(sin,lower_boundary, upper_boundary,N);
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"F5(x)="<<F5<<" time to integrate: "<<t2-t1<<std::endl;

//F6(x)=sin(5x)
    gettimeofday(&tim, NULL);
    t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F6=Simpson_integrate(f6,lower_boundary, upper_boundary,N);
    gettimeofday(&tim, NULL);
    t2=tim.tv_sec+(tim.tv_usec/1000000.0);

    std::cout<<"F6(x)="<<F6<<" time to integrate: "<<t2-t1<<std::endl;
    return 0;
}
