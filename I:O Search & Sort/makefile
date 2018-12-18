
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = read_write.o search.o main.o getInteger.o
 
SRCS = read_write.cpp search.cpp main.cpp getInteger.cpp

HEADERS = read_write.hpp search.hpp getInteger.hpp

search: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o search

read_write.o: read_write.cpp
	${CXX} -c read_write.cpp

search.o: search.cpp
	${CXX} -c search.cpp

main.o: main.cpp
	${CXX} -c main.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm search *.o
