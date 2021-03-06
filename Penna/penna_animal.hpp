/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 7.2
 * by Jakub Imriska
 */

#ifndef ANIMAL_
#define ANIMAL_

#include "penna_genome.hpp"
#include <iostream>

class Animal {
public:
  typedef Genome::age_t age_t;
  typedef Genome::count_t count_t;
  
  Animal();
  
  Animal give_birth() const;
  bool pregnant() const;
  bool alive() const;
  age_t age() const;
  void age_a_year();
  
  static void set_birth_rate(double p);
  static void set_reproduction_age(age_t r);
  static void set_mutations_threshold(count_t m);
  
  const Genome & genome() const;
  friend std::ostream& operator<<(std::ostream&, Animal const&);
private:
  Animal(const Genome &);
  
  static double birth_rate_;
  static age_t reproduction_age_;
  static count_t mutations_threshold_;
  
  Genome genome_;
  age_t age_;
};

#endif //ANIMAL_
