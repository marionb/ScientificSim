/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 7.2
 * by Jakub Imriska
 */
 
#include <cstdlib>
#include <cassert>
#include "penna_animal.hpp"


double Animal::birth_rate_=1.;
Animal::age_t Animal::reproduction_age_=7;
Animal::count_t Animal::mutations_threshold_=3;

Animal::Animal()
    : genome_()
    , age_(0)
    {}

Animal::Animal(const Genome& G)
    : genome_(G)
    , age_(0)
    {}

Animal Animal::give_birth() const {
    assert(alive() && age_>=reproduction_age_);
    return Animal(genome_.clone());
}

bool Animal::pregnant() const {
    return alive() && age_>=reproduction_age_ && drand48()<birth_rate_;
}

bool Animal::alive() const {
    return (age_<=Genome::max_age && genome_.bad_mutations(age_)<mutations_threshold_);
}

Animal::age_t Animal::age() const {
    return age_;
}

void Animal::age_a_year() {
    ++age_;
}

void Animal::set_birth_rate(double p) {
    birth_rate_=p;
}

void Animal::set_reproduction_age(age_t r) {
    reproduction_age_=r;
}

void Animal::set_mutations_threshold(count_t m) {
    mutations_threshold_=m;
}

const Genome & Animal::genome() const {
    return genome_;
}

std::ostream& operator<<(std::ostream& out, Animal const& A) {
    std::cout<<"Age="<<A.age()<<"; "<<(A.alive()?"alive":"dead")<<"; "<<(A.pregnant()?"is":"not")<<" pregnant"<<std::endl;
    std::cout<<A.genome_;
    return out;
}
