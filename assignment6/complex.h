/*
  Header for complex class
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

// define class for handling complex numbers
class Complex {
  // friend functions
  friend ostream& operator<<(ostream &out, const Complex &c);
  friend istream& operator>>(istream &in, Complex &c);
  friend Complex conj(const Complex &c);
  friend Complex operator+(double d, const Complex &c);
  friend Complex operator-(double d, const Complex &c);
  friend Complex operator*(double d, const Complex &c);
  friend Complex operator/(double d, const Complex &c);
private:
  double a, b;
public:
  // constructors
  Complex();
  Complex(double re, double im);
  // getters
  double real() const;
  double imag() const;
  // setters
  void setReal(double re);
  void setImag(double im);
  // miscellaneous functions
  void conj();
  double abs() const;
  double arg() const;
  // overloaded arithmetic operators with real arguments
  Complex operator+(double d);
  Complex operator-(double d);
  Complex operator*(double d);
  Complex operator/(double d);
  // overloaded arithmetic operators with complex arguments
  Complex operator+(const Complex &otherC);
  Complex operator-(const Complex &otherC);
  Complex operator*(const Complex &otherC);
  Complex operator/(const Complex &otherC);
  // overloaded relational operators
  bool operator==(const Complex &otherC);
  bool operator!=(const Complex &otherC);
};

#endif
