
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Node.o NumberList.o linkMenu.o main.o getInteger.o
 
SRCS = Node.cpp NumberList.cpp linkMenu.cpp main.cpp getInteger.cpp

HEADERS = Node.hpp NumberList.hpp linkMenu.hpp getInteger.hpp

linklist: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o linklist

Node.o: Node.cpp
	${CXX} -c Node.cpp

NumberList.o: NumberList.cpp
	${CXX} -c NumberList.cpp

linkMenu.o: linkMenu.cpp
	${CXX} -c linkMenu.cpp

main.o: main.cpp
	${CXX} -c main.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm linklist *.o
