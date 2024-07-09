#include <iostream>  // Include the iostream library for input and output
using namespace std; // Use the standard namespace to avoid prefixing std:: to standard library names

// Class definition for Customer
class Customer {
private:
  int index; // Private member variable to store the index of the customer

public:
  // Default constructor initializing index to 0
  Customer() {
    index = 0; // Initialize index to 0
  }

  // Parameterized constructor initializing index with the given value
  Customer(int idx) {
    index = idx; // Initialize index with the provided value idx
  }

  // Getter function to retrieve the index
  int getIndex() const {
    return index; // Return the value of the index
  }

  // Setter function to set the index
  void setIndex(int idx) {
    index = idx; // Set the index to the provided value idx
  }
};

int main() {
  int N_CUSTOMER; // Declare a variable to store the number of customers

  // Prompt the user for the number of customers
  cout << "How many customers are in line? ";
  cin >> N_CUSTOMER; // Read the number of customers from the user

  // Allocate array of Customer objects
  Customer* customers = new Customer[N_CUSTOMER]; // Dynamically allocate an array of N_CUSTOMER Customer objects

  // Set the index for each Customer
  for (int i = 0; i < N_CUSTOMER; ++i) { // Loop through each element in the array
    // Set the index to (i + 1) to make it 1-indexed
    // i starts at 0, so i + 1 ensures the first customer has an index of 1, the second has an index of 2, etc.
    customers[i].setIndex(i + 1); // Set the index of the ith customer
  }

  // Display the index of each Customer (optional for verification)
  for (int i = 0; i < N_CUSTOMER; ++i) { // Loop through each element in the array
    cout << "Customer " << (i + 1) << " has index: " << customers[i].getIndex() << endl; // Print the index of the ith customer
  }

  // Deallocate the array to prevent memory leaks
  delete[] customers; // Use delete[] to deallocate the dynamically allocated array

  return 0; // Return 0 to indicate successful execution
}
