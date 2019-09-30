CC = g++
CFLAG = -c
OFLAG = -o

test_heap: test_heap.o
	$(CC) $(OFLAG) test_heap test_heap.o

timesort: timesort.o
	$(CC) $(OFLAG) timesort timesort.o

test_heap.o: test_heap.cpp
	$(CC) $(CFLAG) test_heap.cpp

timesort.o: timesort.cpp
	$(CC) $(CFLAG) timesort.cpp
