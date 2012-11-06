/**
*   Exercise 1:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           5/11/2012
*
*   Problem 1:      Cache Effects
*
*   Description:    Determine the cache size of your computer
*
*   Annotation:     This program gives as a result the time to access n elements in an given array size.
                    The output can be further used with the program Plots1b.py
                    -> pipe the data form this program in to the file named "dataTask1b.dat" and the run Plots1b.py (this code has to be adjusted for more data)
*/


#include <iostream>
#include <sys/time.h> //to be able to use getttimeofday()


/**
*   PRE:    N is an integer giving the size of the array which will be accessed.
*
*   POST:   the function returnes the access time for K (at the moment set to 64) elements in the array
*/
inline double cacheEffect(int N)
{
    int *array=new int[N];
    struct timeval tim;


    gettimeofday(&tim, NULL);
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    for(int i=0;i<64*1024+1023;i+=64)
    {

        array[(i*64)%N]++;

    }
    gettimeofday(&tim, NULL);
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);


    std::cout<<t2-t1<<" "<< N<<std::endl;
    return t2-t1;

}

int main()
{
    std::cout<<"# time array_size "<<std::endl;


    for (int sz = 1024; sz <= 16 * 1024 * 1024; sz <<= 1)
    {
        cacheEffect(sz);
    }
    return 0;
}
