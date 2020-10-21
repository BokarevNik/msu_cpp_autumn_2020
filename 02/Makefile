CC=g++
FLAGS=-std=c++17

all: test

test: test_
	./test
test_: test.o parser.o
	$(CC) $(FLAGS) test.o parser.o -o test

alloc.o: alloc.cpp
	$(CC) $(FLAGS) -c parser.cpp -o parser.o

test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp -o test.o

clean:
	rm -f test parser.o test.o