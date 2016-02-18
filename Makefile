TARGET=test
CC=g++
CFLAGS=-I./include

test: test.cpp src/Connection.cpp include/Connection.hpp
	$(CC) -o $(TARGET) test.cpp src/Connection.cpp $(CFLAGS)
