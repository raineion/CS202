/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 4
 * Description: Implementation of the Pizza class and a 
 *              function to read pizza orders from a file.
 * Input: Pizza order data from a file.
 * Output: Pizza information printed to the console.
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include "pizza.h"

using namespace std;

/*
 * function_identifier: Pizza::Pizza
 * parameters: None
 * return value: None
 * Description: Default constructor
 */
Pizza::Pizza() : customerName(""), size(""), 
                 nToppings(0), toppings(nullptr) {}

/*
 * function_identifier: Pizza::Pizza
 * parameters: string cName, string sz, int n_top, string top[]
 * return value: None
 * Description: Parametrized constructor
 */
Pizza::Pizza(string cName, string sz, int n_top, string top[]) : 
             customerName(cName), size(sz), nToppings(n_top) {
    toppings = new string[nToppings];
    for (int i = 0; i < nToppings; i++) {
        toppings[i] = top[i];
    }
}

/*
 * function_identifier: Pizza::getCustomerName
 * parameters: None
 * return value: string
 * Description: Returns the customer name
 */
string Pizza::getCustomerName() {
    return customerName;
}

/*
 * function_identifier: Pizza::getSize
 * parameters: None
 * return value: string
 * Description: Returns the size of the pizza
 */
string Pizza::getSize() {
    return size;
}

/*
 * function_identifier: Pizza::getNtoppings
 * parameters: None
 * return value: int
 * Description: Returns the number of toppings
 */
int Pizza::getNtoppings() {
    return nToppings;
}

/*
 * function_identifier: Pizza::getPrice
 * parameters: None
 * return value: double
 * Description: Calculates and returns the price of the pizza
 */
double Pizza::getPrice() {
    double basePrice = 0.0;
    if (size == "small") basePrice = 12.0;
    else if (size == "medium") basePrice = 14.0;
    else if (size == "large") basePrice = 16.0;
    else if (size == "x-large") basePrice = 18.0;
    return basePrice + (nToppings * 1.50);
}

/*
 * function_identifier: Pizza::setCustomerName
 * parameters: string cName
 * return value: void
 * Description: Sets the customer name
 */
void Pizza::setCustomerName(string cName) {
    customerName = cName;
}

/*
 * function_identifier: Pizza::setSize
 * parameters: string sz
 * return value: void
 * Description: Sets the size of the pizza
 */
void Pizza::setSize(string sz) {
    size = sz;
}

/*
 * function_identifier: Pizza::setToppings
 * parameters: int n_top, string top[]
 * return value: void
 * Description: Sets the toppings of the pizza
 */
void Pizza::setToppings(int n_top, string top[]) {
    if (toppings != nullptr) {
        delete[] toppings;
    }
    nToppings = n_top;
    toppings = new string[nToppings];
    for (int i = 0; i < nToppings; i++) {
        toppings[i] = top[i];
    }
}

/*
 * function_identifier: Pizza::printInfo
 * parameters: None
 * return value: void
 * Description: Prints the pizza information in the expected format
 */
void Pizza::printInfo() {
    cout << "Customer name: " << customerName << endl;
    cout << "Size: " << size << endl;
    if (nToppings > 0) {
        cout << "Toppings:" << endl;
        for (int i = 0; i < nToppings; i++) {
            cout << toppings[i] << endl;
        }
    }
    cout << "Cost: " << getPrice() << endl;
}

/*
 * function_identifier: Pizza::~Pizza
 * parameters: None
 * return value: None
 * Description: Destructor that frees allocated memory
 */
Pizza::~Pizza() {
    if (toppings != nullptr) {
        delete[] toppings;
    }
}

/*
 * function_identifier: isValidSize
 * parameters: const string& size
 * return value: bool
 * Description: Checks if the pizza size is valid
 */
bool isValidSize(const string& size) {
    return (size == "small" || size == "medium" || 
            size == "large" || size == "x-large");
}

/*
 * function_identifier: isValidTopping
 * parameters: const string& topping
 * return value: bool
 * Description: Checks if the topping is valid
 */
bool isValidTopping(const string& topping) {
    string validToppings[] = {"pepperoni", "sausage", "ham", 
                              "peppers", "onions", "olives", 
                              "pineapple"};
    for (const string& validTopping : validToppings) {
        if (topping == validTopping) {
            return true;
        }
    }
    return false;
}

/*
 * function_identifier: readPizzasFromFile
 * parameters: string fileName, Pizza *pizzaList[]
 * return value: unsigned int
 * Description: Reads pizzas from a file and 
 *              returns the number of valid pizzas read
 */
unsigned int readPizzasFromFile(string fileName, Pizza *pizzaList[]) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Unable to open file " << fileName << endl;
        exit(1);
    }

    cout << "opened file" << endl;

    unsigned int n_pizzas = 0;
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string cName, sz, topping;
        ss >> cName >> sz;

        if (!isValidSize(sz)) {
            continue; // Skip invalid pizza size
        }

        string tempToppings[100];
        int n_top = 0;
        while (ss >> topping) {
            if (isValidTopping(topping)) {
                tempToppings[n_top++] = topping;
            }
        }

        pizzaList[n_pizzas++] = new Pizza(cName, sz, 
                                          n_top, tempToppings);
    }

    file.close();
    return n_pizzas;
}
