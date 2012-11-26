#include <iostream>
#include <cmath>
#include "simpson.h"
#include <exception>
#include <stdexcept>

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

    else if(algorithm=="exp")
    {
        srt=new EXP();
    }
    else
    {
        throw std::runtime_error("I don't know this function.");
    }

    return srt;



}

int main() {



    const unsigned BINS=128;

    Integrate * f;
    std::string funType;

    std::cout<<"Integrator for exp(x), sin(x), sin(5*x), from a to b."<<std::endl;
    std::cout<<"type exp, sinus or sinus5 ";
    std::cin >> funType;
    f=integrateFactory(funType);
    std::cout<< "determine the interval to be integrated over"<<std::endl;
    double INTERVAL_MIN;
    double INTERVAL_MAX;
    std::cout<<"a"<<std::endl;
    std::cin>>INTERVAL_MIN;
    double b;
    std::cout<<"b"<<std::endl;
    std::cin>>INTERVAL_MAX;


    std::cout.precision(15);
    std::cout << "int_"<<INTERVAL_MIN<<"^"<<INTERVAL_MAX<<" dx f(x) = "
	<< f->simpson_int(INTERVAL_MIN,INTERVAL_MAX,BINS) << std::endl;

	delete f;
    return 0;
}
