
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = readMatrix.o determinant.o matrixMain.o getInteger.o

SRCS = readMatrix.cpp determinant.cpp matrixMain.cpp getInteger.cpp

HEADERS = readMatrix.hpp determinant.hpp getInteger.hpp



matrix: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o matrix

readMatrix.o: readMatrix.cpp
	${CXX} -c readMatrix.cpp

determinant.o: determinant.cpp
	${CXX} -c determinant.cpp

matrixMain.o: matrixMain.cpp
	${CXX} -c matrixMain.cpp

#getInteger.o: getInteger.cpp
#	${CXX} -c getInteger.cpp

clean:
	rm matrix a.out *.o
