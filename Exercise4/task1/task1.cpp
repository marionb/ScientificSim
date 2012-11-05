/**
*   Exercise 1:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           09/10/2012
*
*   Description:    Allocating an array of size 10 which the user can fill with a maximum of 10 doubles.
*                   The program then normalizes the given number so that the summ of the numbers in the array is 1 and prints
*                    them out in reverse order.
*/

#include "task1.h"
using namespace std;

Z2 operator *(Z2 a , Z2 b )
{
    if(a==b)
    {
        return Plus;
    }
    return Minus;
}


/*ostream& operator<<(ostream& os , Z2 a )
{
    if(a==Plus)
    {
        out<<" + ";
    }
    else{ out<<" - ";}

    return out;
}

/**
* Over loaded mulipication operator
*   PRE COND:   the function takes an object b of the class Z2 and an object T a. a has to be multiplicable by minus 1
*   POST COND:  the function returnes -b if a is Minus and b if a is Plus
*/
/*inline template<clas s T> T operator*(T a , Z2 b )
{
    if(b==Plus)
    {
        return a
    }
    return -a;
}

/**
* Over loaded mulipication operator
*   PRE COND:   the function takes an object a of the class Z2 and an obkect T a. a has to be multiplicable by minus 1
*   POST COND:  the function returnes -a if a is Minus and a if b is Plus
*
*   General remark: this function uses the function operator*(T a , Z2 b ) in orger not to copy and paste code. I am not shure it the first function is to be inlined as it is a very short function and would safe time to inline?
*                   The also is this function to be inlined as it is qite short?
*/
/*template<clas s T> T operator*(Z2 a , T b )
{
    return b*a
}*/
