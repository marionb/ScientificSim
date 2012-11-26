/**
*   Exercise 7:     Programing Techniques for Scientific Simulations
*
*   Author:         Marion Baumgartner (marion.baumgartner@uzh.ch)
*   Date:           12/11/2012
*
*   Description:    Benchmarking standart containers
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <sys/time.h> //to be able to use getttimeofday()
#include <cstdlib>


typedef int BType;

/**this function is just for debuging
*   PRE: the variable container is of the cont and should be of a std container class such as list vector or set
*        it needs to have a forward itterator
*
*   POST: the function returnes nothing but prints out the contents of the container
*/
template <class cont>
void print(cont& container)
{
    std::cout<<"the container holds the following contentce: "<<std::endl;

    for(typename cont::iterator iter=container.begin();iter!=container.end();iter++)
    {
        std::cout<<*iter<<std::endl;
    }
}

/**
*   PRE:    the variable container is of the cont and should be of a std container class such as list vector or set;
*           it needs to have a forward itterator
*
*   POST:   the function returnes the time it takes to insert an element at a random position in the container
*            as well as the time it takes to remove a random element in the container.
*/
template <class cont>
double* insert_remove(cont& list)
{

    struct timeval tim;

    srand(tim.tv_usec);

    double* run_time=new double(2);
    int len=distance(list.begin(), list.end());//determine lenght of the container

    typename cont::iterator vecIt;//create a ittereator pointing to the begining of the list


    //a) insert new element in rand. position
    int rnd=rand()%len;

    vecIt=list.begin();
    std::advance(vecIt, rnd);
    gettimeofday(&tim, NULL);
    double t1vec=tim.tv_sec*1000000.0+tim.tv_usec*1.0;
    list.insert( vecIt,(BType)rand()%50);
    gettimeofday(&tim, NULL);
    double t2vec=tim.tv_sec*1000000.0+tim.tv_usec*1.0;

    run_time[0]=t2vec-t1vec;
    std::cout<<t2vec-t1vec<<" ";



    //b) erase
    len=distance(list.begin(), list.end());
    vecIt=list.begin();
    rnd=rand()%len;
    std::advance(vecIt, rnd);
    gettimeofday(&tim, NULL);
    t1vec=tim.tv_sec*1000000.0+tim.tv_usec*1.0;
    list.erase(vecIt);
    gettimeofday(&tim, NULL);
    t2vec=tim.tv_sec*1000000.0+tim.tv_usec*1.0;
    run_time[0]=t2vec-t1vec;
    std::cout<<t2vec-t1vec<<" ";


    return run_time;
}

int main()
{

    unsigned n=10;


    //Step 1:
    //create a vector
    std::vector<BType> benchVec;
    //assigne incremental values
    for(unsigned i=0;i<n;i++)
    {
        benchVec.push_back(i);
    }


    //Sep 2:
    //copy contence of vector to list and set
    std::list<BType> benchList(benchVec.begin(),benchVec.end());
    std::set<BType> benchSet(benchVec.begin(),benchVec.end());

    //Step 3:
    //for each continer record the time to
    int k=1000000;

    std::cout<<"#times in 10e-6*sec"<<std::endl;
    std::cout<<"#inList rmList inVec rmVec inSet rmSet"<<std::endl;
    for(int i=0;i<k;i++)
    {
        insert_remove(benchList);
        insert_remove(benchVec);
        insert_remove(benchSet);    // here I am not sure if this is realy allowed for stes the way I programed it. because sets have a special internal order.
                                    // but I am not sure how to solve it so that I can use one function for all of the containers.

        std::cout<<std::endl;

    }











    return 0;
}
