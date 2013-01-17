/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 4.2
 * by Marion Baumgartner
 */
#include <cassert>
#include <cstdlib>
#include "penna_genome.hpp"

Genome::Genome():genome_()
{}

Genome Genome::clone() const
{
 // he maximum amount of mutation si mutation_at_cloning, ther might be less
    Genome newG(*this);
    for(Genome::count_t i=0; i< mutations_at_cloning; i++)
    {
           Genome::age_t numb=Genome::age_t(std::rand()%max_age);
           newG.genome_.flip(numb); //why can I access this private member?

    }
    return newG;
}

Genome::count_t Genome::bad_mutations(Genome::age_t t) const
{
    assert(t<=max_age);
    Genome::count_t temp=0;
    for(age_t i=0;i<t;i++)
    {
        if(genome_[i]==true)
        {
            ++temp;
        }
    }
    return temp;
}

void Genome::set_mutations_at_cloning(count_t N) {
    Genome::mutations_at_cloning=N;
}
std::ostream& operator<<(std::ostream& out, const Genome& G)
{
    out << "[";
    for(Genome::age_t i=0; i<Genome::max_age; i++)
    {
        out<<(G.genome_[i]? "+": "-");
    }
    out << "]";
    return out;
}

/*private:
  static count_t mutations_at_cloning;

  std::bitset<max_age> genome_;
*/

Genome::count_t Genome::mutations_at_cloning=0;
