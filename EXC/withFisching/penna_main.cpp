/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 8.3
 * by Jakub Imriska
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "penna_fishing_population.hpp"

//#define DEBUG

void simulate(FishingPopulation& population, unsigned years, unsigned output_period) {
    for (unsigned generation=0; generation<years; ++generation) {
        population.age_a_year();
        if (generation%output_period==0) {
            std::cout<<population.size()<<" "
                     <<population.number_of_caught_fish_in_current_year()<<" "
                     <<population.at_age(8)<<" "
                     <<population.bad_gene_probability(1)<<" "
                     <<population.bad_gene_probability(6)<<" "
                     <<population.bad_gene_probability(12)<<" "
                     <<population.bad_gene_probability(30)<<" "
                     <<population.death_statistics().mean()<<std::endl;
            population.reset_death_statistics();
        }
    }
}

int main() {
#ifndef DEBUG
    srand48(static_cast<unsigned>(std::time(NULL)));
    std::srand(static_cast<unsigned>(std::time(NULL)));
#endif

    Genome::set_mutations_at_cloning(1);
    Animal::set_birth_rate(1.0);
    Animal::set_reproduction_age(7);
    Animal::set_mutations_threshold(3);

    FishingPopulation population_of_fish(100000,1000000);
    std::cout<<"#Population size"<<" "<<"Caught fish"<<" "<<"Population at age 8"<<" "
             <<"Bad gene probability at age: 1, 6, 12, 30"<<" : "<<"Average death age"<<std::endl;
    simulate(population_of_fish, 500, 10);
    std::cout<<"Fishing starts : phase 1"<<std::endl;
    population_of_fish.set_fishing_rate(0.17);
    simulate(population_of_fish, 500, 10);
    std::cout<<"Fishing starts : phase 2"<<std::endl;
    population_of_fish.set_fishing_rate(0.22);
    simulate(population_of_fish, 250, 10);

    return 0;
}
