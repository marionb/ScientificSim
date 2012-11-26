
# Programming Techniques for Scientific Simulations, HS 2012
# Exercise 7
# by Marion Baumgartner

COMPILER = g++
FLAGS = -O3 -funroll-loops

all: benchmarking

benchmarking: benchmarking.cpp
	$(COMPILER) $(FLAGS) benchmarking.cpp -o benchmarking

clean:
	rm -f *.o benchmarking
