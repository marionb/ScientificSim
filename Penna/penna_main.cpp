/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 7.2
 * by Jakub Imriska
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "penna_population.hpp"
 
//#define DEBUG

int main() {
#ifndef DEBUG
    srand48(static_cast<unsigned>(std::time(NULL)));
    std::srand(static_cast<unsigned>(std::time(NULL)));
#endif

    Genome::set_mutations_at_cloning(2);
    Animal::set_birth_rate(1.0);
    Animal::set_reproduction_age(8);
    Animal::set_mutations_threshold(4);
    
    Population population_of_fish(1000000,10000000);
    for (unsigned generation=0; generation<500; ++generation) {
        population_of_fish.age_a_year();
        if (generation%10==0) {
            std::cout<<population_of_fish.size()<<" : "
                     <<population_of_fish.at_age(8)<<" : "
                     <<population_of_fish.bad_gene_probability(1)<<", "
                     <<population_of_fish.bad_gene_probability(6)<<", "
                     <<population_of_fish.bad_gene_probability(12)<<", "
                     <<population_of_fish.bad_gene_probability(30)<<" : "
                     <<population_of_fish.death_statistics().mean()<<std::endl;
        }
        population_of_fish.death_statistics().reset();
    }
    
    return 0;
}
