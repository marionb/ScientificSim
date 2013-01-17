#include "Population.h"

Population::Population(Population::psize_t N):popu_size(N)
{
    population(popu_size);
    animal_t animal();
    for(vector<animal_t>::iterator i = population.begin(); i !=population.end(); i++)
    {
        *i=animal();
    }
}

Population::~Population()
{
    population.clear();
}

Population::age_animal()
{
    for(vector<Animal>::iterator i=population.begin(); i!=population.end();++i)
    {
        if(i->alive())
        {
            i->age_a_year();//don't klow if this realy works
        }
    }
}
Population::dea
{
    Anima
}
