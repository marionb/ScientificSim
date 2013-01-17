#include <iostream>
#include <cmath>
#include "simpson.h"
#include <exception>
#include <stdexcept>
#include <sys/time.h> //to be able to use getttimeofday()

Integrate * integrateFactory(std::string algorithm)
{
    // Complete me!
    Integrate *srt;
    if(algorithm=="sinus")
    {
        srt=new Sinus();
    }
    else if(algorithm=="sinus5")
    {
        srt= new Sinus5();
    }

    else if(algorithm=="poly")
    {
        int deg=0;
        std::cout<<"degree of the poly (integer): ";
        std::cin>>deg;
        srt=new Poly(deg);
        std::cout<<std::endl;
    }
    else
    {
        throw std::runtime_error("I don't know this function.");
    }

    return srt;



}

int main() {

    struct timeval tim;
    Integrate * f;
    double a;
    double b;
    int step;
    std::string funType;

    std::cout<<"Integrator for x^n, sin(x), sin(5*x), from a to b."<<std::endl;
    std::cout<<"type poly, sinus or sinus5 ";
    std::cin >> funType;

    f=integrateFactory(funType);
    std::cout<< "determine the interval to be integrated over"<<std::endl;

    /*std::cout<<"lower bound"<<std::endl;
    std::cin>>a;
    std::cout<<"upperbound"<<std::endl;
    std::cin>>b;
    std::cout<<"amount of integration stepps:"<<std::endl;
    std::cin>>step;*/
    const double INTERVAL_MIN=0;
    const double INTERVAL_MAX=M_PI;
    const unsigned BINS=100;

    std::cout.precision(15);
    gettimeofday(&tim, NULL);
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    double F=f->simpson_int(INTERVAL_MIN,INTERVAL_MAX,BINS);
    gettimeofday(&tim, NULL);
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    std::cout << "int_"<<INTERVAL_MIN<<"^"<<INTERVAL_MAX<<" dx f(x) = "
	<< F <<"\nfunction ran in  "<<t2-t1<<" seconds"<< std::endl;

	delete f;
    return 0;
}
