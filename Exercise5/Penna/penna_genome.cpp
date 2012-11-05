
#include <iostream>
#include <assert.h>
#include <bitset>
#include <stdlib.h> //Load this Librari for --> rand()
#include <time.h> //to create a seet the time is udes; other wise it will always give me the tame random number
#include "penna_genome.hpp"

Genome::Genome()
{
    srand(time(NULL));
    std::bitset<max_age> temp(rand()*rand());//the last slots in my bitset are allwas 0. dont'realy know how to make it better unless i use a for loop
    genome_= temp;

}

Genome Genome::clone() const
{
    // cloning a genome -> creating a new Genome with the idential mutations as this one
    Genome gen;
    gen=*this;

    return gen;
}

Genome::count_t Genome::bad_mutations(age_t t) const
{
    count_t mutations=0;
    for(age_t i=0;i<t;i++)
    {
        mutations+=(count_t)genome_[i]; //don't know if this is legal, might be dangerous as well
    }
    return mutations;
}

Genome::count_t Genome::mutations_at_cloning = 0;

void Genome::set_mutations_at_cloning(count_t N)
{
    assert(N<=max_age);
    mutations_at_cloning=N;
}

std::ostream& operator<<(std::ostream& out, const Genome& g)
{
    return(out<< " Genom with genes: "<<g.genome_<<std::endl);
}
