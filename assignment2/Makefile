OBJ      = studentGrade.o fileInputOutput.o
CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g
INC      = studentGrade.h fileInputOutput.h

all: main.x

main.x: $(OBJ) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJ) main.cpp -o $@

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -rf *.o main.x
