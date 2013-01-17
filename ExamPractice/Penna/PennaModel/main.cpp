#include <iostream>

#include "../penna_genome.hpp"

using namespace std;

int main()
{

    Genome::set_mutations_at_cloning(Genome::max_age-Genome::max_age/4);
    Genome gene;
    Genome gene2=gene.clone();

    cout<<gene;
    cout<<gene2;


}
