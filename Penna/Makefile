# Programming Techniques for Scientific Simulations, HS 2012
# Exercise 7
# by Jakub Imriska

COMPILER = g++
FLAGS = -O3 -funroll-loops

all: penna

penna: penna_main.o penna_population.o penna_animal.o penna_genome.o
	$(COMPILER) $(FLAGS) -o penna penna_main.o penna_population.o penna_animal.o penna_genome.o

penna_genome.o: penna_genome.cpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c penna_genome.cpp

penna_animal.o: penna_animal.cpp penna_animal.hpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c penna_animal.cpp

penna_population.o: penna_population.cpp penna_population.hpp penna_animal.hpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c penna_population.cpp

penna_main.o: penna_main.cpp penna_population.hpp penna_animal.hpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c penna_main.cpp

clean:
	rm -f *.o containers penna
