# simple Makefile

COMPILER = gcc
FLAGS = -O0

#all: penna

runn: main.o animal.o genome.o
	$(COMPILER) $(FLAGS) -c -o runn main.o animal.o genome.o 

main.o: main.cpp  penna_animal.hpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c -o main.o main.cpp

animal.o: penna_animal.cpp penna_animal.hpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c -o animal.o penna_animal.cpp 

genome.o: penna_genome.cpp penna_genome.hpp
	$(COMPILER) $(FLAGS) -c -o genome.o penna_genome.cpp

clean: 
	rm -f main.o animal.o genome.o runn
