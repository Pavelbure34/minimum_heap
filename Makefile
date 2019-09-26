CC = g++
CFLAG = -c
OFLAG = -o

run: test_heap
	./test_heap

test_heap: test_heap.o
	$(CC) $(OFLAG) test_heap test_heap.o

test_heap.o: test_heap.cpp
	$(CC) $(CFLAG) test_heap.cpp