/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 4.2
 * by Jakub Imriska
 * modified by Marion Baumgartner
 */

#ifndef GENOME_
#define GENOME_

#include <iostream>
#include <bitset>
#include <stdlib.h> //Load this Librari for --> rand()
#include <time.h> //to create a seet the time is udes; other wise it will always give me the tame random number
class Genome {
public:
  typedef unsigned age_t;
  typedef age_t count_t;
  static const age_t max_age=64;

  Genome();

  Genome clone() const;
  count_t bad_mutations(age_t t) const;

  static void set_mutations_at_cloning(count_t N);

  friend std::ostream& operator<<(std::ostream&, const Genome&);

private:
  static count_t mutations_at_cloning;
  std::bitset<max_age> genome_;
};


#endif //GENOME_