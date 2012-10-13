/**
*   Exercise 1:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           09/10/2012
*
*   Description:    Dynamicaly allocating an array of initial size 10 which the user can fill with as many doubles as he wants
*                   (maximum numbers is defined by the memory of the computer).
*                   The program then normalizes the given number so that the summ of the numbers in the array is 1 and prints
*                    them out in reverse order.
*/

#include <iostream>


int main (int argc, const char * argv[])
{
    int n=10;
    double* array =new double [n];
    double num=0;
    double summ=0;
    int count=0;
    std::cout<<"type a sequence of 10 max numbers (to end the input press anithing that is not a number e.g Crlt + D):\n";

    while(true)
    {
        if(count>=n)
        {
            std::cout<<"in if"<<n<<"\n";
            int temp=2*n;
            double *new_array=new double [temp];
            for(int i=0;i<n;i++)
            {
                new_array[i]=array[i];
            }
            n=temp;
            array=new_array;
            delete new_array; //carbage collection
        }
        std::cout<<"and the next nuber is:";
        std::cin>>num;
        if(std::cin.good())
        {
            array[count]=num;
            summ+=array[count];
            count++;
        }
        else
        {
            break;
        }
    }
    std::cout<<"\n The normalized sequence in reverse order is:\n";
    for (int i=count-1;i>=0;i--)
    {
        std::cout<<array[i]/summ<<"; ";
    }
    return 0;
}
