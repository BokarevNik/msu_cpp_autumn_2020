CC=g++
FLAGS=-std=c++17 -c

all: alloc test

alloc: alloc.cpp
	$(CC) $(FLAGS) alloc.cpp -o alloc

test: test.cpp
	$(CC) $(FLAGS) test.cpp -o test

clean:
	rm -f test alloc