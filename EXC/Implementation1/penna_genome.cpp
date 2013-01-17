/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 5.2
 * by Jakub Imriska
 */

#include <cstdlib> 
#include <cassert>
#include "penna_genome.hpp"


Genome::count_t Genome::mutations_at_cloning=1;

Genome::Genome()
    : genome_()
    {}
 
Genome Genome::clone() const {
    Genome g(*this);
    for (count_t i=0; i<mutations_at_cloning; ++i)
      g.genome_.flip(static_cast<age_t>(std::rand() % max_age));
    return g;
}
 
Genome::count_t Genome::bad_mutations(age_t t) const {
    assert(t<max_age);
    return (genome_<<(max_age-t-1)).count();
}
 
void Genome::set_mutations_at_cloning(count_t N) {
    mutations_at_cloning=N;
}

std::ostream& operator<<(std::ostream& out, const Genome& G) {
  out<<"[";
  for (Genome::age_t i=0; i<Genome::max_age; i++)
    out << (G.genome_[i] ? "X" : "-");
  out<<"]";
  return out;
}
