/**
*   Exercise 3:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           12/10/2012
*
*   Problem 2:      Machine Epsilon Revised
*
*   Description:    determines the numerical machine precicion for float, double and long double-> using Templates
*
*   Comyright:      Free software
*
*/
#ifndef EPSILON_H__
#define EPSILON_H__

#include <iostream>

/**
*   Pre-Condition:
*       There are no special pre condition as this function does not take anything.
*       The only thing we needis that assignement, comparison and division operator are defined
*
*   Post-Condition:
*       function retunes the machine prscision of the type T
*/
template <class T>
T epsilon()
{
    T eps=1.0;
    T epsOld=eps;
    while(eps+1.0!=1.0)
    {
        epsOld=eps;
        eps=eps/2.0;
    }
    return epsOld;
}
#endif
