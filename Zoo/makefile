
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Zoo.o Animal.o Penguin.o Tiger.o Turtle.o zooMain.o getInteger.o

SRCS = Zoo.cpp Animal.cpp Penguin.cpp Tiger.cpp Turtle.cpp zooMain.cpp getInteger.cpp

HEADERS = Zoo.hpp Animal.hpp Penguin.hpp Tiger.hpp Turtle.hpp getInteger.hpp

zoo: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o zoo

Zoo.o: Zoo.cpp
	${CXX} -c Zoo.cpp

Animal.o: Animal.cpp
	${CXX} -c Animal.cpp

Penguin.o: Penguin.cpp
	${CXX} -c Penguin.cpp

Tiger.o: Tiger.cpp
	${CXX} -c Tiger.cpp

Turtle.o: Turtle.cpp
	${CXX} -c Turtle.cpp

zooMain.o: zooMain.cpp
	${CXX} -c zooMain.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm zoo *.o
