/*
  DO NOT ALTER
*/

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <math.h>
#include "complex.h"

using namespace std;

// global function for testing closeness of floating point numbers
bool isclose(double d1, double d2, double atol=1e-5, double rtol=1e-5) {
  // absolute tolerance test
  if (fabs(d1 - d2) < atol) {
    // relative tolerance test
    // skip if we're close to 0 to avoid division by 0
    if (fabs(d1) < rtol) {
      return true;
    } else if (fabs(d1 - d2) / fabs(d1) < rtol) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

int main() {
  // extra variables
  double d;

  // test default constructor
  Complex z1;
  assert(isclose(z1.real(), 0.0));
  assert(isclose(z1.imag(), 0.0));

  // test parametrized constructor
  Complex z2(2.0, 3.0);
  assert(isclose(z2.real(), 2.0));
  assert(isclose(z2.imag(), 3.0));

  // test setters
  z1.setReal(-1.5);
  z1.setImag(-0.5);
  assert(isclose(z1.real(), -1.5));
  assert(isclose(z1.imag(), -0.5));

  // test overloaded addition
  Complex z3;
  d = 2.0;
  z3 = z1 + z2;
  assert(isclose(z3.real(), 0.5));
  assert(isclose(z3.imag(), 2.5));
  z3 = d + z1;
  assert(isclose(z3.real(), 0.5));
  assert(isclose(z3.imag(), -0.5));
  z3 = z1 + d;
  assert(isclose(z3.real(), 0.5));
  assert(isclose(z3.imag(), -0.5));

  // test subtraction
  d = 3.0;
  z3 = z1 - z2;
  assert(isclose(z3.real(), -3.5));
  assert(isclose(z3.imag(), -3.5));
  z3 = d - z1;
  assert(isclose(z3.real(), 4.5));
  assert(isclose(z3.imag(), 0.5));
  z3 = z1 - d;
  assert(isclose(z3.real(), -4.5));
  assert(isclose(z3.imag(), -0.5));

  // test multiplication
  z3 = z1 * z2;
  assert(isclose(z3.real(), -1.5));
  assert(isclose(z3.imag(), -5.5));
  z3 = d * z1;
  assert(isclose(z3.real(), -4.5));
  assert(isclose(z3.imag(), -1.5));
  z3 = z1 * d;
  assert(isclose(z3.real(), -4.5));
  assert(isclose(z3.imag(), -1.5));

  // test division
  d = 2.0;
  z3 = z1 / z2;
  assert(isclose(z3.real(), -0.346153846));
  assert(isclose(z3.imag(), 0.269230769));
  z3 = z1 / d;
  assert(isclose(z3.real(), -0.75));
  assert(isclose(z3.imag(), -0.25));
  z3 = d / z1;
  assert(isclose(z3.real(), -1.2));
  assert(isclose(z3.imag(), 0.4));

  // test conjugation member function
  z3 = z2;
  z3.conj();
  assert(isclose(z3.real(), z2.real()));
  assert(isclose(z3.imag(), -z2.imag()));

  // test conj friend function + multiplication
  z2 = z1 * conj(z1);
  assert(isclose(z2.real(), pow(z1.abs(), 2.0)));
  assert(isclose(z2.imag(), 0.0));

  // test abs
  z1.setReal(-3.0);
  z1.setImag(4.0);
  assert(isclose(z1.abs(), 5.0));
  z1.setImag(-4.0);
  assert(isclose(z1.abs(), 5.0));

  // test arg
  z1.setReal(-1.0);
  z1.setImag(0.0);
  assert(isclose(z1.arg(), M_PI));
  z1.setImag(-1e-7);
  assert(isclose(z1.arg(), -M_PI));
  z1.setReal(3.0);
  z1.setImag(3.0);
  assert(isclose(z1.arg(), M_PI/4));
  z1.setImag(-3.0);
  assert(isclose(z1.arg(), -M_PI/4));

  // test equality operators
  z1.setReal(1.3);
  z1.setImag(-0.2);
  z2.setReal(1.3);
  z2.setImag(-0.2);
  assert(z1 == z2);
  assert(!(z1 != z2));
  z2.setReal(1.301);
  assert(z1 == z2);
  assert(!(z1 != z2));
  z2.setReal(1.299);
  assert(z1 == z2);
  assert(!(z1 != z2));
  z2.setImag(-0.1);
  assert(z1 != z2);
  assert(!(z1 == z2));
  z2.setReal(1.4);
  z2.setImag(-0.2);
  assert(z1 != z2);
  assert(!(z1 == z2));

  // test outstream overloading
  z1.setReal(1.5);
  z1.setImag(2.5);
  cout << z1 << endl;
  z1.setImag(-2.5);
  cout << z1 << endl;

  // test instream overloading
  cin >> z1;
  assert(isclose(z1.real(), -1.5));
  assert(isclose(z1.imag(), 3.5));

  cout << "All tests successfully passed!" << endl;
  return 0;
}
