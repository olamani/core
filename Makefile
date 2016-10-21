TARGET=core
CC=clang++
CSTD=c++11
CSTDLIB=libc++
CFLAGS=-I./include -I/usr/local/include

core: test.cpp \
	src/Body.cpp include/Body.hpp \
	src/Configs.cpp include/Configs.hpp \
	src/Connection.cpp include/Connection.hpp \
	src/DSL.cpp include/DSL.hpp \
	src/Parser.cpp include/Parser.hpp \
	src/Server.cpp include/Server.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o $(TARGET) test.cpp src/Connection.cpp $(CFLAGS)

testDSL: src/DSL.cpp test/DSLTest.cpp include/DSL.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testDSL test/DSLTest.cpp src/DSL.cpp $(CFLAGS)

testServer: src/Server.cpp src/DSL.cpp test/ServerTest.cpp include/Server.hpp include/DSL.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testServer src/Server.cpp test/ServerTest.cpp src/DSL.cpp $(CFLAGS)

testBody: src/Body.cpp src/DSL.cpp test/BodyTest.cpp include/Body.hpp include/DSL.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testBody src/Body.cpp test/BodyTest.cpp src/DSL.cpp $(CFLAGS)

testFlag: src/Flag.cpp test/FlagTest.cpp include/Flag.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testFlag src/Flag.cpp test/FlagTest.cpp $(CFLAGS)

testTrainer: src/Trainer.cpp test/TrainerTest.cpp include/Trainer.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testTrainer src/Trainer.cpp test/TrainerTest.cpp $(CFLAGS)

testLexer: src/Lexer.cpp test/LexerTest.cpp include/Lexer.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testLexer src/Lexer.cpp test/LexerTest.cpp $(CFLAGS)

testParser: src/Lexer.cpp src/Parser.cpp test/ParserTest.cpp include/Lexer.hpp include/Parser.hpp
	$(CC) -std=$(CSTD) -stdlib=$(CSTDLIB) -o testParser src/Lexer.cpp src/Parser.cpp test/ParserTest.cpp $(CFLAGS)