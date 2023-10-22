CPP = gcc
CPPFLAGS = -g -c -W -Wall -ansi -pedantic -std=c++11

all: main

main: main.o CPU.o  Memory.o SO.o FIFO.o LRU.o OPT.o
	$(CPP) -o main main.o CPU.o Memory.o SO.o FIFO.o  LRU.o OPT.o -lstdc++
	rm -rf *.o 

main.o: src/main.cpp src/CPU.h src/Memory.h src/SO.h src/FIFO.h src/LRU.h src/OPT.h 
	$(CPP) -o main.o src/main.cpp $(CPPFLAGS)

CPU.o: src/CPU.cpp  src/CPU.h
	$(CPP) -o CPU.o src/CPU.cpp $(CPPFLAGS)

Memory.o: src/Memory.cpp  src/Memory.h 
	$(CPP) -o Memory.o src/Memory.cpp $(CPPFLAGS)

SO.o: src/SO.cpp  src/SO.h 
	$(CPP) -o SO.o src/SO.cpp $(CPPFLAGS)


FIFO.o: src/FIFO.cpp  src/FIFO.h
	$(CPP) -o FIFO.o src/FIFO.cpp $(CPPFLAGS)

LRU.o: src/LRU.cpp  src/LRU.h
	$(CPP) -o LRU.o src/LRU.cpp $(CPPFLAGS)

OPT.o: src/OPT.cpp  src/OPT.h
	$(CPP) -o OPT.o src/OPT.cpp $(CPPFLAGS)

clean:
	rm -rf *.o *~ main