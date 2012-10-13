# simple Makefile

COMPILER = g++
FLAGS = -O2

#all: task3 simpson out
all: library task3 task2 task1

library: simpson.cpp
	 ar ruc libintegrate.a simpson.o
	 ranlib libintegrate.a

task3: task3.cpp
	$(COMPILER) $(FLAGS) -o task3 task3.cpp -L. -lintegrate
task2: task2.cpp
	$(COMPILER) $(FLAGS) -o task2 task2.cpp
task1: task1.cpp
	$(COMPILER) $(FLAGS) -o task1 task1.cpp
clean: 
	rm task3.o task2.o task1.o
