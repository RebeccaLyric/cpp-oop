
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = Building.o Person.o Student.o Instructor.o University.o \
uniMenu.o uniMain.o getInteger.o
 
SRCS = Building.cpp Person.cpp Student.cpp Instructor.cpp University.cpp \
uniMenu.cpp uniMain.cpp getInteger.cpp

HEADERS = Building.hpp Person.hpp Student.hpp Instructor.hpp University.hpp \
uniMenu.hpp getInteger.hpp

uni: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o uni

Building.o: Building.cpp
	${CXX} -c Building.cpp

Person.o: Person.cpp
	${CXX} -c Person.cpp

Student.o: Student.cpp
	${CXX} -c Student.cpp

Instructor.o: Instructor.cpp
	${CXX} -c Instructor.cpp

University.o: University.cpp
	${CXX} -c University.cpp

uniMain.o: uniMain.cpp
	${CXX} -c uniMain.cpp

getInteger.o: getInteger.cpp
	${CXX} -c getInteger.cpp

clean:
	rm uni *.o
