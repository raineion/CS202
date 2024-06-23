/*
  DO NOT ALTER
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "pizza.h"

int main() {
  string toppings[3];
  unsigned int n_pizzas;
  Pizza firstPizza;
  Pizza *pizzaList[100];

  toppings[0] = "pepperoni";
  toppings[1] = "sausage";
  toppings[2] = "peppers";

  Pizza secondPizza("Steve", "small", 3, toppings);
  assert(fabs(secondPizza.getPrice() - 16.5) < 1e-2);
  assert(secondPizza.getCustomerName() == "Steve");
  assert(secondPizza.getSize() == "small");
  assert(secondPizza.getNtoppings() == 3);
  secondPizza.printInfo();

  toppings[0] = "olives";

  Pizza thirdPizza("Chris", "x-large", 1, toppings);
  assert(fabs(thirdPizza.getPrice() - 19.5) < 1e-2);
  assert(thirdPizza.getCustomerName() == "Chris");
  assert(thirdPizza.getSize() == "x-large");
  assert(thirdPizza.getNtoppings() == 1);
  thirdPizza.printInfo();

  // read from file
  n_pizzas = readPizzasFromFile("pizza_orders.txt", pizzaList);
  cout << "n_pizzas: " << n_pizzas << endl;
  cout << endl << endl << endl;
  assert(n_pizzas == 8);

  // pizza1
  assert(pizzaList[0]->getCustomerName() == "Maria");
  assert(pizzaList[0]->getSize() == "medium");
  assert(pizzaList[0]->getNtoppings() == 3);
  assert(fabs(pizzaList[0]->getPrice() - 18.5) < 1e-2);

  // pizza2
  assert(pizzaList[1]->getCustomerName() == "Chris");
  assert(pizzaList[1]->getSize() == "x-large");
  assert(pizzaList[1]->getNtoppings() == 0);
  assert(fabs(pizzaList[1]->getPrice() - 18) < 1e-2);

  // pizza3
  assert(pizzaList[2]->getCustomerName() == "Stephanie");
  assert(pizzaList[2]->getSize() == "small");
  assert(pizzaList[2]->getNtoppings() == 2);
  assert(fabs(pizzaList[2]->getPrice() - 15) < 1e-2);

  // pizza4
  assert(pizzaList[3]->getCustomerName() == "Jose");
  assert(pizzaList[3]->getSize() == "large");
  assert(pizzaList[3]->getNtoppings() == 2);
  assert(fabs(pizzaList[3]->getPrice() - 19) < 1e-2);

  // pizza5
  assert(pizzaList[4]->getCustomerName() == "Bill");
  assert(pizzaList[4]->getSize() == "small");
  assert(pizzaList[4]->getNtoppings() == 4);
  assert(fabs(pizzaList[4]->getPrice() - 18) < 1e-2);

  // pizza6
  assert(pizzaList[5]->getCustomerName() == "Alyssa");
  assert(pizzaList[5]->getSize() == "x-large");
  assert(pizzaList[5]->getNtoppings() == 2);
  assert(fabs(pizzaList[5]->getPrice() - 21) < 1e-2);

  // pizza7
  assert(pizzaList[6]->getCustomerName() == "Ying");
  assert(pizzaList[6]->getSize() == "small");
  assert(pizzaList[6]->getNtoppings() == 0);
  assert(fabs(pizzaList[6]->getPrice() - 12) < 1e-2);

  // pizza8
  assert(pizzaList[7]->getCustomerName() == "Karen");
  assert(pizzaList[7]->getSize() == "medium");
  assert(pizzaList[7]->getNtoppings() == 0);
  assert(fabs(pizzaList[7]->getPrice() - 14) < 1e-2);

  for (unsigned int i=0; i<n_pizzas; i++) {
    pizzaList[i]->printInfo();
    delete pizzaList[i];
  }

  cout << "All tests successfully passed!" << endl;

  return 0;
}
