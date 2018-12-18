
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Character.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o \
main.o tourneyMenu.o playTourney.o getInteger.o tourneyQueue.o

SRCS = Character.cpp Barbarian.cpp BlueMen.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp \
main.cpp tourneyMenu.cpp playTourney.cpp getInteger.cpp tourneyQueue.cpp

HEADERS = Character.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp \
tourneyMenu.hpp playTourney.hpp getInteger.hpp tourneyQueue.hpp

tourney: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o tourney

Character.o: Character.cpp
	${CXX} -c Character.cpp

Barbarian.o: Barbarian.cpp
	${CXX} -c Barbarian.cpp

BlueMen.o: BlueMen.cpp
	${CXX} -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp
	${CXX} -c HarryPotter.cpp

Medusa.o: Medusa.cpp
	${CXX} -c Medusa.cpp

Vampire.o: Vampire.cpp
	${CXX} -c Vampire.cpp

main.o: main.cpp
	${CXX} -c main.cpp

tourneyMenu.o: tourneyMenu.cpp
	${CXX} -c tourneyMenu.cpp

playTourney.o: playTourney.cpp
	${CXX} -c playTourney.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

tourneyQueue.o: tourneyQueue.cpp
	${CXX} -c tourneyQueue.cpp
clean:
	rm tourney *.o
