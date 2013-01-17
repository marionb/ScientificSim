/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 7.2
 * by Jakub Imriska
 */

#ifndef POPULATION_
#define POPULATION_

#include <list>
#include "penna_animal.hpp"

class DeathStatistics {
public:
    DeathStatistics() : sum1_(0.), n_(0) {}
    double mean() const { return sum1_/n_; }
    void reset() { sum1_=0.; n_=0; }
    void operator<<(const Animal& A) { sum1_+=A.age(); ++n_; }
private:
    double sum1_;
    unsigned long n_;
};


class Population : public std::list<Animal> {
public:
  typedef Animal::age_t age_t;
  typedef Animal::count_t count_t;
  typedef std::list<Animal>::size_type population_size_t;
  
  /// constructor
  Population(population_size_t initial_N, population_size_t N_0);
  
  /// classes we derive we from should have a virtual destructor.
  virtual ~Population() {};
  
  /// measurements
  population_size_t at_age(age_t) const;
  double bad_gene_probability(age_t) const;
  const DeathStatistics& death_statistics() const;
  void reset_death_statistics();
  
  /// dynamics
  virtual void age_a_year();
  
private:
  const double N_0_;
  DeathStatistics death_stat_;
};

#endif //POPULATION_
