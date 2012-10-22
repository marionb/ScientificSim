/**
*   Exercise 3:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           12/10/2012
*
*   Problem 2:      Machine Epsilon Revised

*   Description:    determines the numerical machine precicion for float, double and long double-> using Templates
*
*   Comyright:      Free software
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "epsilon.hpp"



int main()
{
    std::cout << "Float epsilon= " << epsilon<float>() <<"\n"; //<< "  compare with  " << numeric_limits<float>::epsilon() << endl;
    std::cout << "Double epsilon= " << epsilon<double>() <<"\n";
    std::cout << "Int epsilon= " << epsilon<int>() <<"\n";
    std::cout << "Unsigned int epsilon= " << epsilon<unsigned int>() <<"\n";
}
