/**
*   Exercise 2:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           09/10/2012
*
*   Description:    Simpson numerical integration.
*                   Numerical integration of f(x) with x in [a,b] and N bins
                    Using a class definig the Function type for f(x)
*/

#include <cmath>

#ifndef SIMPSON_INTEGRATION_
#define SIMPSON_INTEGRATION_

class Function {
  const double lamb;
public:
/*
* Constructor takin a double l and initializing the variable lamb=l
*/
  Function(double l) : lamb(l) {}

/*
* overload the operator () which takes a double x and the returns sin(lamb * x)
*/
  double operator() (double x)
  {return sin(lamb*x);}
  };

double simpson_int(Function &f,const double &a,const double &b, unsigned N);
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

#endif  //SIMPSON_INTEGRATION_
