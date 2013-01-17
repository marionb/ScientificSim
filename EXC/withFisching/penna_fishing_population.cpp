/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 8.3
 * by Jakub Imriska
 */

#include "penna_fishing_population.hpp"
#include <cstdlib>
 

FishingPopulation::FishingPopulation(population_size_t initial_N, population_size_t N_0, double fishing_rate, age_t min_age_for_fishing)
  : Population(initial_N, N_0),
    fishing_rate_(fishing_rate),
    min_age_for_fishing_(min_age_for_fishing),
    number_of_caught_fish_in_current_year_(0)
  {}

void FishingPopulation::set_fishing_rate(double fishing_rate) {
    fishing_rate_=fishing_rate;
}

void FishingPopulation::set_min_age_for_fishing(age_t t) {
    min_age_for_fishing_=t;
}

FishingPopulation::population_size_t FishingPopulation::number_of_caught_fish_in_current_year() const {
    return number_of_caught_fish_in_current_year_;
}

class FishingPredicate {
public:
    FishingPredicate(double probability, Animal::age_t min_age) : probability_(probability), min_age_(min_age) {}
    
    bool operator()( Animal const& A ) const {
        if (A.age()>=min_age_ && drand48()<probability_) {
            return true;
        }
        return false;
    }
private:
    double probability_;
    Animal::age_t min_age_;
};

void FishingPopulation::age_a_year() {
    Population::age_a_year();
    
    if (fishing_rate_>0) {
        population_size_t size_before_fishing=size();
        remove_if(FishingPredicate(fishing_rate_,min_age_for_fishing_));
        number_of_caught_fish_in_current_year_=size_before_fishing-size();
    } else {
        number_of_caught_fish_in_current_year_=0;
    }
}
