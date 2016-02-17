CC=g++

test: test.cpp src/Connection.cpp
	$(CC) -o test test.cpp
