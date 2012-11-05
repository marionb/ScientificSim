COMPILER = g++
FLAGS  = -O0

all: simpson


simpson: main.o 
	$(COMPILER) $(FLAGS) main.o -o simpson

main.o: main.cpp simpson.h
	$(COMPILER) $(FLAGS) -c main.cpp

clean:
	rm -f *.o *.a simpson
