/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 4.2
 * by Jakub Imriska
 */

#include "penna_animal.hpp"
#include "penna_genome.hpp"
#include <stdlib.h> //Load this Librari for --> rand()
#include <iostream>
#include <time.h> //to create a seet the time is udes; other wise it will always give me the tame random number


Animal::Animal():genome_(Genome()) //: age_t(0)
{
    //construct an animal
    age_=0;
    //this->genome_=new Genome::Genome();
}

Animal* Animal::give_birth() const //ban give_birth in Class from being anything which can attempt to alter any member variables in the object.
{
    //create a new animal if this animal is pregnant else return NULL
    if(this->pregnant())
    {
            Animal* baby=new Animal(this->genome_);
            return baby;
    }
    return NULL;

}

bool Animal::pregnant() const
{
    srand(time(NULL));
    double f = (double)rand() / RAND_MAX;
    f=0 + f;

    if(age_<reproduction_age_ || f<birth_rate_)
    {
        return false;
    }
    return true;


}

bool Animal::alive() const
{
    //the animal can only die from too many bad mutations or age. But not due to environmental influences
    if(genome_.bad_mutations(age_)>=mutations_threshold_ || age_>genome_.max_age)
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

/*
*   PRE: p is a double and should be within 0 and 1. If it is 1 the all the animals aging the reproduction_age or older will constantly be pregnant
*
*   POST: return nothing; set the birth rate to p.
*/
void Animal::set_birth_rate(double p)
{
    birth_rate_=p;
}

void Animal::set_reproduction_age(age_t r)
{
    reproduction_age_=r;
}


void Animal::set_mutations_threshold(count_t m)
{
    mutations_threshold_=m;
}

std::ostream& operator<<(std::ostream& out, Animal const& p)
{
    out << "\n age " << p.age()<< ";\n mutations till now "<< p.genome_.bad_mutations(p.age())<<";\n live state (1=true; 0=false) "<<p.alive()<<"; \n animal is pregnant "<<p.pregnant()<<std::endl;
    return out;
}
//in Private
Animal::Animal(const Genome & gen):genome_(gen)// age(0)
{
    age_=0;
}

//initialize static variables out side of class
double Animal::birth_rate_=0;
Animal::age_t Animal::reproduction_age_=0;
Animal::count_t Animal::mutations_threshold_=0;

