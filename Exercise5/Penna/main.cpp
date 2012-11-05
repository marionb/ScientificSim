/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 4.2
 *
 * by Marion Baumgartner
 *
 * My Program has a problem with the initialisation it initialises all of the genoms in an new animal the same.
 * I am not shure wether this is because of the random number generatot I am using or wether I made a mistake
 * in the Constructor of the Animal class. I had some problems with the const in the genome_.
 */


#include "penna_animal.hpp"
#include "penna_genome.hpp"
#include <iostream>


int main()
{

    unsigned time=0;
    //also here the Genome objects initializes in one run are the same.
    Genome Gen;
    Genome::set_mutations_at_cloning(5);
    Genome gen_clone = Gen.clone();
    std::cout << std::endl<< Gen << "bad gens up to the 4th year: " << Gen.bad_mutations(5);
    std::cout << std::endl<< gen_clone << "bad gens up to the 4th year: " << gen_clone.bad_mutations(5);
    std::cout << std::endl;
    std::cout << std::endl;
    //set static variables
    Animal::set_birth_rate(0.56);
    Animal::set_mutations_threshold(4);
    Animal::set_reproduction_age(2);

    //create a herd of some 10 animals.
    Animal* animals=new Animal[10];

    for(Animal* itter=animals;itter!=animals+10;itter++)
    {
        std::cout<<" animal is"<<*itter<<std::endl;
    }

    //take 10 time stepps
    for(;time<10;time++)
    {
            for(unsigned i=0; i<10;i++)
            {
                animals[i].age_a_year();
            }
    }

    for(Animal* itter=animals;itter!=animals+10;itter++)
    {
        std::cout<<" animal is"<<*itter<<std::endl;
    }
    return 0;



}
