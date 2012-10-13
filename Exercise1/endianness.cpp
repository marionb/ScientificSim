
/**
*   Exercise 1:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           01/10/2012
*
*   Problem 1:      Endianness

*   Description:    Determine if the endianness of the computer is large or smal
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    int num = 1;
    if(*(char *)&num == 1)
    {
        printf("\nLittle-Endian\n");
    }
    else
    {
        printf("Big-Endian\n");
    }
    return 0;
}
