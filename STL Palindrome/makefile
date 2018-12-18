
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = STL_functions.o STLMenu.o main.o getInteger.o
 
SRCS = STL_functions.cpp STLMenu.cpp main.cpp getInteger.cpp

HEADERS = STL_functions.hpp STLMenu.hpp getInteger.hpp

stl: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o stl

STL_functions.o: STL_functions.cpp
	${CXX} -c STL_functions.cpp

STLMenu.o: STLMenu.cpp
	${CXX} -c STLMenu.cpp

main.o: main.cpp
	${CXX} -c main.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm stl *.o
