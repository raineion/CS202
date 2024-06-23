/*
  Header for pizza class
*/

#ifndef PIZZA_H
#define PIZZA_H

#include <string>

using namespace std;

// define class for holding information about pizzas
class Pizza {
private:
  string customerName;
  string size;
  int nToppings;
  string *toppings;

public:
  // default constructor
  Pizza();

  // parametrized constructor
  Pizza(string cName, string sz, int n_top, string top[]);

  // getters
  string getCustomerName();
  string getSize();
  int getNtoppings();
  double getPrice();

  // setters
  void setCustomerName(string cName);
  void setSize(string sz);
  void setToppings(int n_top, string top[]);

  // other functions
  void printInfo();

  // destructor
  ~Pizza();
};

// define function for reading pizza information from file
unsigned int readPizzasFromFile(string fileName, Pizza *pizzaList[]);

#endif
