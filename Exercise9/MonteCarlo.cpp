
/**
*   Exercise 9:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           09/10/2012
*
*   Description:    Draw random Numbers and chsck wether tey are within th unit circle
*/



#include <stdlib.h>
//#include <boost/random.hpp>
#include <cmath>
#include <iostream>


double drand(const int N)
{
    int hit=0;
    double x;
    double y;
    for(int i=0;i<N; i++)
    {
        x=drand48();
        y=drand48();

        double r=x*x+y*y;

        if(sqrt(r)<1)
        {
            ++hit;
        }
    }
    double pi=4*hit/double(N);
    std::cout<<"estimate with "<<N<<" points; pi="<<pi<<std::endl;
    return pi;
}

double boost_rand(const int N)
{

    /*
            int hit=0;
    double x;
    double y;
    for(int i=0;i<N; i++)
    {
        -> creat with different RNG x=...;
                                    y=...;
        //std::cout<<"x:"<<x<<"y:"<<y<<std::endl;
        double r=x*x+y*y;
        //std::cout<<"r:"<<r<<std::endl;
        if(sqrt(r)<1)
        {
            ++hit;
        }
    }
    double pi=4*hit/double(N);
    std::cout<<"estimate with "<<N<<" points; pi="<<pi<<std::endl;
    return pi;
    */

    std::cout<<"not jet completed due to lak of instalde pakages on my computer (could not instal it properly)";
    return 0;
}

int main()
{
    drand(100000);
    return 0;
}
