COMPILER = g++
FLAGS  = -O0

all: simpson


simpson: simpson.o main.o 
	$(COMPILER) $(FLAGS) simpson.o main.o -o simpson

main.o: main.cpp simpson.h
	$(COMPILER) $(FLAGS) -c main.cpp

simpson.o: simpson.h simpson.cpp
	$(COMPILER) $(FLAGS) -c simpson.cpp

clean:
	rm -f *.o *.a simpson
