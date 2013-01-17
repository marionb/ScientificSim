/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 5.2
 * by Jakub Imriska
 */
 
#include "penna_genome.hpp"
 
int main() {
    const unsigned mutations=2;
    Genome::set_mutations_at_cloning(mutations);
    std::cout<<"[Cloning with "<<mutations<<" mutations.]"<<std::endl;
    
    Genome A;
    std::cout<<"HEALTHY GENOME: "<<std::endl<<" "<<A<<std::endl;
    std::cout<<" Bad mutations within first 10 years = "<<A.bad_mutations(10)<<std::endl;
    Genome B=A.clone();
    std::cout<<"AFTER 1st CLONING: "<<std::endl<<" "<<B<<std::endl;
    std::cout<<" Bad mutations within the whole Genome = "<<B.bad_mutations(Genome::max_age-1)<<std::endl;
    for (unsigned i=0; i<5; ++i) {
        A=B.clone();
        B=A.clone();
    }
    std::cout<<"AFTER 10 MORE CLONINGS: "<<std::endl<<" "<<A<<std::endl;
    std::cout<<" Bad mutations within first 5 years = "<<A.bad_mutations(5)<<std::endl;
    std::cout<<"AFTER 1 MORE CLONING: "<<std::endl<<" "<<B<<std::endl;
    std::cout<<" Bad mutations within first 10 years = "<<A.bad_mutations(10)<<std::endl;
    for (unsigned i=0; i<50; ++i) {
        A=B.clone();
        B=A.clone();
    }
    std::cout<<"AFTER 100 MORE CLONINGS: "<<std::endl<<" "<<A<<std::endl;
    std::cout<<" Bad mutations within first 2 years = "<<A.bad_mutations(2)<<std::endl;
    std::cout<<"AFTER 1 MORE CLONING: "<<std::endl<<" "<<B<<std::endl;
    std::cout<<" Bad mutations within first 2 years = "<<A.bad_mutations(2)<<std::endl;
    
    return 0;
}
