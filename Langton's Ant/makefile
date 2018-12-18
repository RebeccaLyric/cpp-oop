
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Ant.o menu.o antMain.o getInteger.o

SRCS = Ant.cpp menu.cpp antMain.cpp getInteger.cpp

HEADERS = Ant.hpp menu.hpp getInteger.hpp

ant: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ant

Ant.o: Ant.cpp
	${CXX} -c Ant.cpp

menu.o: menu.cpp
	${CXX} -c menu.cpp

main.o: antMain.cpp
	${CXX} -c antMain.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm ant *.o
