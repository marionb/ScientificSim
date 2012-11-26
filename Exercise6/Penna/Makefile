# Programming Techniques for Scientific Simulations, HS 2012
# Exercise 5
# by Jakub Imriska

COMPILER = g++
FLAGS = -O0

all: test

test: genome_test animal_test

genome_test: penna_genome_test.cpp penna_genome.o
	$(COMPILER) $(FLAGS) penna_genome_test.cpp -o genome_test penna_genome.o

penna_genome.o: penna_genome.cpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c penna_genome.cpp

animal_test: penna_animal_test.cpp penna_animal.o penna_genome.o
	$(COMPILER) $(FLAGS) penna_animal_test.cpp -o animal_test penna_animal.o penna_genome.o

penna_animal.o: penna_animal.cpp penna_animal.hpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c penna_animal.cpp


clean:
	rm -f *.o genome_test animal_test
