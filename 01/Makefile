CC=g++
FLAGS=-std=c++17

all: test

test: test_
	./test
test_: test.o alloc.o
	$(CC) $(FLAGS) test.o alloc.o -o test

alloc.o: alloc.cpp
	$(CC) $(FLAGS) -c alloc.cpp -o alloc.o

test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp -o test.o

clean:
	rm -f test alloc.o test.o