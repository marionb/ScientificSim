/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 4.2
 * by Marion Baumgartner
 */

#include "penna_genome.hpp"
#include "penna_animal.hpp"
#include <cassert>
#include <iostream>
#include <cstdlib>

Animal::Animal():genome_(), age_(0)
{}
Animal Animal::give_birth() const
{
    Animal baby(genome_.clone());
    return baby;
}

bool Animal::pregnant() const
{
    if(age_<reproduction_age_)
    {
        return false;
    }
    double prob=(std::rand()%100)/1.0;
    return prob<birth_rate_;
}

bool Animal::alive() const
{
   if(age_>Genome::max_age)
   {
       return false;
   }
   if(genome_.bad_mutations(age_)>mutations_threshold_)
   {
       return false;
   }

   return true;
}

Animal::age_t Animal::age() const
{
    return age_;
}
void Animal::age_a_year()
{
    ++age_;
}

void Animal::set_birth_rate(double p)
{
    assert(p<=1 and p>=0);
    birth_rate_=p;
}
void Animal::set_reproduction_age(age_t r)
{
    assert(r<=Genome::max_age);
    reproduction_age_=r;
}
void Animal::set_mutations_threshold(count_t m)
{
    mutations_threshold_=m;
}

std::ostream& operator<<(std::ostream& out, Animal const& A)
{
    out<<"age = ";
    out<<A.age_;
    out<<" animal alive: ";
    out<<A.alive();
    out<<"\n";
    out <<A.genome_;
    return out;
}

Animal::Animal(const Genome & gene):genome_(gene), age_(0)
{}


//set static variables
double Animal::birth_rate_=0;
Animal::age_t Animal::reproduction_age_=0;
Animal::count_t Animal::mutations_threshold_=0;

