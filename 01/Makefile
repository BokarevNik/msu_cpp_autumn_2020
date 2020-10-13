CC=g++
FLAGS=-std=c++17

all: test

test: test.o alloc.o
	$(CC) $(FLAGS) test.o alloc.o -o test

alloc: alloc.cpp
	$(CC) $(FLAGS) -c alloc.cpp -o alloc

test_: test.cpp
	$(CC) $(FLAGS) test.cpp -o test

clean:
	rm -f test alloc