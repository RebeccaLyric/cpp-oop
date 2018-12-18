
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = fileMain.o count_letters.o output_letters.o 

SRCS = fileMain.cpp count_letters.cpp output_letters.cpp 

HEADERS = count_letters.hpp output_letters.hpp 

file_io: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o file_io

fileMain.o: fileMain.cpp
	${CXX} -c fileMain.cpp

count_letters.o: count_letters.cpp
	${CXX} -c count_letters.cpp

output_letters.o: output_letters.cpp
	${CXX} -c output_letters.cpp

clean:
	rm file_io *.o
