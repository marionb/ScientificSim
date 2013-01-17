#include <iostream>

#include "penna_genome.hpp"
#include "penna_animal.hpp"

using namespace std;

int main()
{
    Genome::age_t cloning=Genome::max_age/4;
    Genome::set_mutations_at_cloning(cloning);
    Animal::set_birth_rate(0.75);
    Animal::set_mutations_threshold(Genome::max_age/3);
    Animal::set_reproduction_age(5);
    Genome gene;

    cout<<"ideal gene \n";
    cout<<gene;
    cout<<"\n";
    for(Genome::age_t i=0; i<Genome::max_age; i+=8)
    {
        cout<< gene.bad_mutations(i);
        cout<<"\n";
    }

    Genome gene2=gene.clone();
    cout<<"clone of ideal \n";
    cout<<gene2;
    cout<<"\n";
    for(Genome::age_t i=0; i<Genome::max_age; i+=8)
    {
        cout<< gene2.bad_mutations(i);
        cout<<"\n";
    }

    Genome gene3=gene2.clone();
    cout<<"clone of clone \n";
    cout<<gene3;
    cout<<"\n";
    for(Genome::age_t i=0; i<Genome::max_age; i+=8)
    {
        cout<< gene3.bad_mutations(i);
        cout<<"\n";
    }

    //----------------------------------//

    Animal animal0;
    Animal animal1;
    Animal animal2;
    Animal animal[]={animal0, animal1, animal2};
    for(unsigned i=0;i<=100;i++)
    {

        for(unsigned j=0;j<3;j++)
        {
            std::cout<<animal[j];
            std::cout<<"\n";
            if(animal[j].alive())
            {

                if(animal[j].pregnant())
                {
                std::cout<<"animal gave birth to: \n";
                std::cout<<animal[j].give_birth();
                std::cout<<"\n";
                }
                animal[j].age_a_year();
            }
        }

    }







}
