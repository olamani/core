TARGET=test
CC=clang++
CSTD=c++11
CSTDLIB=libc++
CFLAGS=-I./include

test: test.cpp \
	src/Body.cpp include/Body.hpp \
	src/Configs.cpp include/Configs.hpp \
	src/Connection.cpp include/Connection.hpp \
	src/DSL.cpp include/DSL.hpp \
	src/Locks.cpp include/Locks.hpp \
	src/Parser.cpp include/Parser.hpp \
	src/Server.cpp include/Server.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o $(TARGET) test.cpp src/DSL.cpp $(CFLAGS)
