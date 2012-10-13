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
#include <iostream>


int main (int argc, const char * argv[])
{
    int n=10;
    double array [n];
    double num=0;
    double summ=0;
    int count=0; //count is always one too much so we start with -1 to compensate
    std::cout<<"type a sequence of 10 max numbers (to end the input press anithing that is not a number e.g Crlt + D):\n";

    while(count<n)
    {
        std::cout<<"and the next nuber is:";
        std::cin>>num;
        if(std::cin.good())
        {
            count++;
            array[count]=num;
            summ+=array[count];

        }
        else
        {
            break;
        }



    }
    std::cout<<"\n The normalized sequence in reverse order is:\n"<<count<<"\n";
    for (int i=count-1;i>=0;i--)
    {

        std::cout<<array[i]<<"; ";
        std::cout<<array[i]/summ<<"; \n";

    }
    return 0;

}
