
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = recursion.o recursionMenu.o main.o getInteger.o
 
SRCS = recursion.cpp recursionMenu.cpp main.cpp getInteger.cpp

HEADERS = recursion.hpp recursionMenu.hpp getInteger.hpp

recursion: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o recursion

recursion.o: recursion.cpp
	${CXX} -c recursion.cpp

recursionMenu.o: recursionMenu.cpp
	${CXX} -c recursionMenu.cpp

main.o: main.cpp
	${CXX} -c main.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm recursion *.o
