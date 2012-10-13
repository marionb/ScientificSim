/**
*   Exercise 1:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           01/10/2012
*
*   Problem 2:      Machine Epsilon

*   Description:    determines the numerical machine precicion for float, double and long double
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/**
*   @param type specifies the type of which the machine epsilon is to be detemined
*               'd': double
*               'f': float
*               'l': longlouble
*/
void epsilon(char type)
{
    if(type=='d')
    {
        double eps=1.0;
        double epsOld=eps;
        while(eps+1.0!=1.0)
        {
            epsOld=eps;
            eps=eps/2.0;
        }
        std::cout<<"the precicion is "<< epsOld<<"\n";
    }else if(type=='f')
    {
        float eps=1.0f;
        float epsOld=eps;
        while(eps+1.0!=1.0)
        {
            epsOld=eps;
            eps=eps/2.0f;
        }
        std::cout<<"the precicion is "<< epsOld<<"\n";
    }else if(type=='l')
    {
        long double eps=1.0;
        long double epsOld=eps;
        while(eps+1.0!=1.0)
        {
            epsOld=eps;
            eps=eps/2;
        }
        std::cout<<"the precicion is "<< epsOld<<"\n";

    }else
    {
        std::cout<< "\n character has no mach please choos l, d, or f\n";
    }
}


int main()
{

    epsilon('d');
    epsilon('f');
    epsilon('l');

}
