
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Queue.o linkMenu.o main.o getInteger.o
 
SRCS = Queue.cpp linkMenu.cpp main.cpp getInteger.cpp

HEADERS = Queue.hpp linkMenu.hpp getInteger.hpp

queue: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o queue

Queue.o: Queue.cpp
	${CXX} -c Queue.cpp

linkMenu.o: linkMenu.cpp
	${CXX} -c linkMenu.cpp

main.o: main.cpp
	${CXX} -c main.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm queue *.o
