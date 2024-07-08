CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++11

all: main.x

main.x: main.cpp linkedList.h queueLL.h queueADT.h
	$(CXX) $(CXXFLAGS) -o main.x main.cpp

clean:
	rm -rf *.x
