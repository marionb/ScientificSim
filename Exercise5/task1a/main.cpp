#include <iostream>
#include <cmath>
#include "simpson.h"


int main() {

    Function f(1);

    const unsigned BINS=128;
    const double INTERVAL_MIN=0.0;

    const double INTERVAL_MAX=M_PI;

    std::cout.precision(15);
    std::cout << "int_"<<INTERVAL_MIN<<"^"<<INTERVAL_MAX<<" dx sin(lx) = "
	<< simpson_int(f,INTERVAL_MIN,INTERVAL_MAX,BINS) << std::endl;
    return 0;
}
