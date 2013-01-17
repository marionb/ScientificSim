OBJS =main.o penna_genome.o penna_animal.o
CC = g++
DEBUG = -g
CFLAG = -c $(DEBUG)

all: penna

penna: $(OBJS)
	$(CC) $(OBJS) -o penna

main.o: main.cpp penna_genome.hpp
	$(CC) main.cpp $(CFLAG)

penna_genome.o: penna_genome.cpp penna_genome.hpp
	$(CC) penna_genome.cpp $(CFLAG)

penna_animal.o: penna_animal.cpp penna_animal.hpp penna_genome.hpp
	$(CC) penna_animal.cpp $(CFLAG)	

clean:
	\rm *.o penna
