TARGET=test
CC=clang++
CSTD=c++11
CSTDLIB=libc++
CFLAGS=-I./include

test: test.cpp \
	src/Parser.cpp include/Parser.hpp \
	src/Connection.cpp include/Connection.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o $(TARGET) test.cpp src/Parser.cpp src/Connection.cpp $(CFLAGS)
