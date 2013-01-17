/* Programming Techniques for Scientific Simulations, HS 2012
 * Exercise 7.2
 * by Jakub Imriska
 */

#include "penna_population.hpp"
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>

class AgePredicate {
public:
    AgePredicate(Animal::age_t t) : age_(t) {}
    bool operator()(const Animal& A) const { return age_==A.age(); }
private:
    const Animal::age_t age_;
};

class BadGeneAtGivenAgePredicate {
public:
    BadGeneAtGivenAgePredicate(Genome::age_t t) : age_(t) {}
    bool operator()(const Animal& A) const { return A.genome().bad_gene(age_); }
private:
    const Genome::age_t age_;
};

Population::population_size_t Population::at_age(age_t t) const {
    return std::count_if(begin(), end(), AgePredicate(t));
}

double Population::bad_gene_probability(age_t t) const {
    return std::count_if(begin(), end(), BadGeneAtGivenAgePredicate(t)) / static_cast<double>(size());
}

const DeathStatistics& Population::death_statistics() const {
    return death_stat_;
}

DeathStatistics& Population::death_statistics() {
    return death_stat_;
}

Population::Population(population_size_t initial_N, population_size_t N_0)
  : std::list<Animal>(initial_N),
    N_0_(static_cast<double>(N_0)),
    death_stat_()
  {}


class DeathPredicate {
public:
    DeathPredicate(double probability, DeathStatistics& death_stat) : probability_(probability), death_stat_(death_stat) {}
    bool operator()( Animal const& A ) const {
        if (!A.alive() || drand48()<probability_) {
            death_stat_<<A;
            return true;
        }
        return false;
    }    
private:
    double probability_;
    DeathStatistics& death_stat_;
};


void Population::age_a_year() {
    // Age all animals
    std::for_each(begin(), end(), std::mem_fun_ref(&Animal::age_a_year));
    
    // Remove dead ones
    remove_if(DeathPredicate(static_cast<double>(size()) / N_0_, death_stat_));

    // Generate offsprings
    std::vector<Animal> parents;
    std::remove_copy_if(begin(), end(), std::back_inserter(parents), std::not1(std::mem_fun_ref(&Animal::pregnant)));
    std::transform(parents.begin(), parents.end(), std::back_inserter(*this), std::mem_fun_ref(&Animal::give_birth));
}
