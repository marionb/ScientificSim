/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 5.2
 * by Jakub Imriska
 */
 
#include "penna_animal.hpp"
 
int main() {
    Genome::set_mutations_at_cloning(4);
    Animal::set_birth_rate(1.0);
    Animal::set_reproduction_age(5);
    Animal::set_mutations_threshold(3);
    
    Animal A;
    std::cout<<"PERFECT ANIMAL BORN: "<<std::endl<<A<<std::endl;
    for (unsigned i=0; i<5; ++i)
        A.age_a_year();
    std::cout<<"5 YEARS LATER: "<<std::endl<<A<<std::endl;
    Animal B=A.give_birth();
    std::cout<<"BABY BORN: "<<std::endl<<B<<std::endl;
    for (unsigned i=0; i<Genome::max_age-1; ++i) {
        B.age_a_year();
        std::cout<<"AT AGE "<<B.age()<<": "<<std::endl<<B<<std::endl;
    }
    
    return 0;
}
