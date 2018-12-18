
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Die.o LoadedDie.o Game.o dieMain.o getInteger.o

SRCS = Die.cpp LoadedDie.cpp Game.cpp Main.cpp getInteger.cpp

HEADERS = Die.hpp LoadedDie.hpp Game.hpp getInteger.hpp

dice: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o dice

Die.o: Die.cpp
	${CXX} -c Die.cpp

LoadedDie.o: LoadedDie.cpp
	${CXX} -c LoadedDie.cpp

Game.o: Game.cpp
	${CXX} -c Game.cpp

dieMain.o: dieMain.cpp
	${CXX} -c dieMain.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm dice *.o
