/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 8.3
 * by Jakub Imriska
 */

#ifndef FISHING_POPULATION_
#define FISHING_POPULATION_

#include "penna_population.hpp"

class FishingPopulation : public Population {
public:  
  /// constructor
  FishingPopulation(population_size_t initial_N, population_size_t N_0, double fishing_rate=0.0, age_t min_age_for_fishing=0);
  
  void set_fishing_rate(double);
  void set_min_age_for_fishing(age_t);
  
  /// measurements
  population_size_t number_of_caught_fish_in_current_year() const;
  
  /// dynamics
  void age_a_year();
  
private:
  double fishing_rate_;
  age_t min_age_for_fishing_;
  population_size_t number_of_caught_fish_in_current_year_;
};

#endif //FISHING_POPULATION_
