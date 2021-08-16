#Ziyao Gao zg8rw 11/14/2020
#File name: Makefile

CXX=g++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=middleearth.o topological.o
topological: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen
.PHONY: clean
clean:
	-rm -f *.o *~ a.out
middleearth.o:middleearth.cpp middleearth.h
#heap.o:heap.cpp heap.h
topological.o:topological.cpp 

