CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++11
OBJ      = accounts.o

all: main.x

main.x: $(OBJ) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.o main.x
