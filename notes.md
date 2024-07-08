# CS202 Concepts Overview

## Class Templates
Class templates allow for the creation of generic and reusable code that can work with any data type.
Example:
```cpp
template <typename T>
class Stack {
    std::vector<T> elems;
public:
    void push(T const& elem) { elems.push_back(elem); }
    void pop() { elems.pop_back(); }
    T top() const { return elems.back(); }
};
```

## Dynamic Memory
Manages memory allocation during runtime using `new` and `delete` operators. This is essential for creating dynamic data structures.
Example:
```cpp
int* array = new int[10]; // Allocate memory
delete[] array;           // Deallocate memory
```

## Exception Handling
Handles runtime errors using `try`, `catch`, and `throw` blocks to ensure the program can manage unexpected situations without crashing.
Example:
```cpp
try {
    if (something_went_wrong) {
        throw std::runtime_error("Error occurred");
    }
} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

## Function Overloading
Allows multiple functions to have the same name but different parameter lists, enabling the handling of different types or numbers of inputs.
Example:
```cpp
void print(int i) { std::cout << i << std::endl; }
void print(double f) { std::cout << f << std::endl; }
void print(std::string s) { std::cout << s << std::endl; }
```

## Linked Lists
A data structure consisting of nodes where each node contains data and a pointer to the next node, useful for efficient insertions and deletions.
Example:
```cpp
struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}
```

## Makefiles
A script for compiling and linking programs, defining rules and dependencies for building executables. Makefiles are essential in managing large projects with multiple files.
Example:
```cpp
all: main

main: main.o helper.o
    g++ -o main main.o helper.o

main.o: main.cpp
    g++ -c main.cpp

helper.o: helper.cpp
    g++ -c helper.cpp

clean:
    rm -f *.o main
```


## Function Templates
Allows functions to operate with generic types, enabling code reuse for different data types.
Example:
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

## Inheritance and Composition
Inheritance allows a class to inherit properties and behavior from another class. Composition involves including objects of other classes as members to build more complex functionality.
Example:
```cpp
class Base {
public:
    void show() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived class\n"; }
};
```

## Operator Overloading
Allows custom implementation of operators for user-defined types.
Example:
```cpp
class Complex {
    int real, imag;
public:
    Complex(int r, int i) : real(r), imag(i) {}
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
};
```

## Pointers
Pointers store memory addresses of variables and are used for dynamic memory management and array manipulation.
Example:
```cpp
int var = 10;
int* ptr = &var;
std::cout << *ptr; // Output: 10
```

## Recursion
A function calls itself to solve smaller instances of the same problem, useful in algorithms like factorial calculation and tree traversals.
Example:
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## Stacks and Queues
Stacks follow LIFO (Last In, First Out) and queues follow FIFO (First In, First Out) principles for data storage and retrieval.
Example (Stack):

```cpp
std::stack<int> s;
s.push(1);
s.push(2);
s.pop(); // Removes 2
```

## Virtual Functions
Allow derived classes to override methods in a base class to provide specific implementations.
Example:

```cpp
class Base {
public:
    virtual void show() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class\n"; }
};
```

## Sample Programs
Example code demonstrating the implementation of various concepts in C++. These programs provide practical applications of the topics covered in the course, such as sorting algorithms, data structures, and memory management.
Example (Sorting Algorithm):
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    std::sort(data.begin(), data.end());
    
    for (int n : data) {
        std::cout << n << " ";
    }
    
    return 0;
}
```

## Sample Input Data
Test data used to run sample programs, helping to verify that the implemented algorithms and data structures work correctly with different inputs.
Example (for a sorting program):
```bash
5 2 9 1 5 6
```

This detailed overview includes explanations and examples for each concept covered in the CS202 course.







