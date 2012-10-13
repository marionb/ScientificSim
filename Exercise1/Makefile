# simple Makefile

COMPILER = g++
FLAGS = -O2

all: endianness epsilon simpson

endinness: endianness.cpp
	$(COMPILER) $(FLAGS) -o endianness endianness.cpp

epsilon: epsilon.cpp
	$(COMPILER) $(FLAGS) -o epsilon epsilon.cpp

simpson: simpson.cpp
	$(COMPILER) $(FLAGS) -o simpson simpson.cpp

clean: 
	rm endianness epsilon simpson
