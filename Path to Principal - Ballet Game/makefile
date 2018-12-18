
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Play.o DanceSpace.o PracticeStudio.o Physio.o Stage.o Menu.o \
Space.o Dancer.o main.o getInteger.o
 
SRCS = Play.cpp DanceSpace.cpp PracticeStudio.cpp Physio.cpp Stage.cpp Menu.cpp \
Space.cpp Dancer.cpp main.cpp getInteger.cpp

HEADERS = Play.hpp DanceSpace.hpp PracticeStudio.hpp Physio.hpp Stage.hpp Menu.hpp \
Space.hpp Dancer.hpp getInteger.hpp

ballet: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ballet

Play.o: Play.cpp
	${CXX} -c Play.cpp

DanceSpace.o: DanceSpace.cpp
	${CXX} -c DanceSpace.cpp

PracticeStudio.o: PracticeStudio.cpp
	${CXX} -c PracticeStudio.cpp

Physio.o: Physio.cpp
	${CXX} -c Physio.cpp

Stage.o: Stage.cpp
	${CXX} -c Stage.cpp

Space.o: Space.cpp
	${CXX} -c Space.cpp

Menu.o: Menu.cpp
	${CXX} -c Menu.cpp

Dancer.o: Dancer.cpp
	${CXX} -c Dancer.cpp

main.o: main.cpp
	${CXX} -c main.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm ballet *.o
