#ifndef POPULATION_H
#define POPULATION_H

#include "penna_animal.hpp"
#include "penna_genome.hpp"
#include <iostream>
#include <algorithm>

class Population
{
    public:
        typedef unsigned int age_t;
        typedef int psize_t
        typedef Animal animal_t
        Population(psize_t N);
        virtual ~Population();

        void give_birth();
        void death();
        void age_animal();
    private:
        psize_t popu_size;
        vector<animal_t> population;


};

#endif // POPULATION_H
