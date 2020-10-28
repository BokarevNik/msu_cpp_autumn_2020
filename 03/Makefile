CC=g++
FLAGS=-std=c++17

all: test

test: test_
	./test
test_: test.o matrix.o
	$(CC) $(FLAGS) test.o matrix.o -o test

matrix.o: matrix.cpp
	$(CC) $(FLAGS) -c matrix.cpp -o matrix.o

test.o: test.cpp
	$(CC) $(FLAGS) -c test.cpp -o test.o

clean:
	rm -f test matrix.o test.o