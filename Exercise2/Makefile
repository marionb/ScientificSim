# simple Makefile
#buggy !!!
COMPILER = g++
FLAGS = -O0

all: simpson task2 task1

simpson: libintegrate.a task3.o
	 $(COMPILER) $(FLAG) task3.o -o simpson -L. -lintegrate

libintegrate.a: simpson.o
	 ar ruc libintegrate.a simpson.o
	 ranlib libintegrate.a

simpson.o: simpson.h simpson.cpp
	   $(COMPILER) $(FLAG) -c simpson.cpp

task3.o: task3.cpp simpson.h
	$(COMPILER) $(FLAGS) -c task3.cpp

task2: task2.cpp
	$(COMPILER) $(FLAGS) -o task2 task2.cpp

task1: task1.cpp
	$(COMPILER) $(FLAGS) -o task1 task1.cpp
clean: 
	rm task3.o task2.o task1.o
