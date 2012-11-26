/*
Implementaition of simpson integration with the function
    f(x)=x*(1-x) and an interval of [0,1], using 6 bins
*/
#include <iostream>
#include "simpson.h"
#include <cmath>

double square(double x)
{
	return x*(1-x);
}


int main()
{
	std::cout <<"integral(from 0 to 1) x*(1-x); with 6 bins: "<<simpson(sin,0,1,6)<<"\n";
	return 0;
}
