/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 6
 * Description: Implementation of Complex class
 * Input: None
 * Output: None
 */

#include "complex.h" // for Complex information
#include <cmath>     // for sqrt, atan2

/*
 * Complex::Complex
 * Description: Default constructor for Complex
 * Input: None
 * Output: None
 */
Complex::Complex() : a(0), b(0) {}

/*
 * Complex::Complex
 * Description: Parametrized constructor for Complex
 * Input: double re - real part, double im - imaginary part
 * Output: None
 */
Complex::Complex(double re, double im) : a(re), b(im) {}

/*
 * Complex::real
 * Description: Getter for the real part of the complex number
 * Input: None
 * Output: double - real part
 */
double Complex::real() const
{
    return a;
}

/*
 * Complex::imag
 * Description: Getter for the imaginary part of the complex number
 * Input: None
 * Output: double - imaginary part
 */
double Complex::imag() const
{
    return b;
}

/*
 * Complex::setReal
 * Description: Setter for the real part of the complex number
 * Input: double re - real part
 * Output: None
 */
void Complex::setReal(double re)
{
    a = re;
}

/*
 * Complex::setImag
 * Description: Setter for the imaginary part of the complex number
 * Input: double im - imaginary part
 * Output: None
 */
void Complex::setImag(double im)
{
    b = im;
}

/*
 * Complex::conj
 * Description: Conjugates the complex number (in-place)
 * Input: None
 * Output: None
 */
void Complex::conj()
{
    b = -b;
}

/*
 * conj
 * Description: Returns the conjugate of a given complex number
 * Input: const Complex &c - complex number
 * Output: Complex - conjugated complex number
 */
Complex conj(const Complex &c)
{
    return Complex(c.a, -c.b);
}

/*
 * Complex::abs
 * Description: Computes the magnitude/
 *              absolute value of the complex number
 * Input: None
 * Output: double - magnitude
 */
double Complex::abs() const
{
    return std::sqrt(a * a + b * b);
}

/*
 * Complex::arg
 * Description: Computes the argument/angle of the complex number
 * Input: None
 * Output: double - argument in the interval (-π, π]
 */
double Complex::arg() const
{
    return std::atan2(b, a);
}

/*
 * Complex::operator+
 * Description: Overloaded addition operator with a double
 * Input: double d - real number
 * Output: Complex - result of addition
 */
Complex Complex::operator+(double d)
{
    return Complex(a + d, b);
}

/*
 * Complex::operator+
 * Description: Overloaded addition operator with a Complex number
 * Input: const Complex &otherC - complex number
 * Output: Complex - result of addition
 */
Complex Complex::operator+(const Complex &otherC)
{
    return Complex(a + otherC.a, b + otherC.b);
}

/*
 * Complex::operator-
 * Description: Overloaded subtraction operator with a double
 * Input: double d - real number
 * Output: Complex - result of subtraction
 */
Complex Complex::operator-(double d)
{
    return Complex(a - d, b);
}

/*
 * Complex::operator-
 * Description: Overloaded subtraction operator with a Complex number
 * Input: const Complex &otherC - complex number
 * Output: Complex - result of subtraction
 */
Complex Complex::operator-(const Complex &otherC)
{
    return Complex(a - otherC.a, b - otherC.b);
}

/*
 * Complex::operator*
 * Description: Overloaded multiplication operator with a double
 * Input: double d - real number
 * Output: Complex - result of multiplication
 */
Complex Complex::operator*(double d)
{
    return Complex(a * d, b * d);
}

/*
 * Complex::operator*
 * Description: Overloaded multiplication operator with a Complex number
 * Input: const Complex &otherC - complex number
 * Output: Complex - result of multiplication
 */
Complex Complex::operator*(const Complex &otherC)
{
    return Complex(a * otherC.a - b * otherC.b, a *
                                                        otherC.b +
                                                    b * otherC.a);
}

/*
 * Complex::operator/
 * Description: Overloaded division operator with a double
 * Input: double d - real number
 * Output: Complex - result of division
 */
Complex Complex::operator/(double d)
{
    return Complex(a / d, b / d);
}

/*
 * Complex::operator/
 * Description: Overloaded division operator with a Complex number
 * Input: const Complex &otherC - complex number
 * Output: Complex - result of division
 */
Complex Complex::operator/(const Complex &otherC)
{
    double denominator = otherC.a * otherC.a + otherC.b * otherC.b;
    return Complex((a * otherC.a + b * otherC.b) / denominator,
                   (b * otherC.a - a * otherC.b) / denominator);
}

/*
 * Complex::operator==
 * Description: Overloaded equality operator
 * Input: const Complex &otherC - complex number
 * Output: bool - true if equal, false otherwise
 */
bool Complex::operator==(const Complex &otherC)
{
    return std::fabs(a - otherC.a) < 1e-2 && std::fabs(b - otherC.b) < 1e-2;
}

/*
 * Complex::operator!=
 * Description: Overloaded inequality operator
 * Input: const Complex &otherC - complex number
 * Output: bool - true if not equal, false otherwise
 */
bool Complex::operator!=(const Complex &otherC)
{
    return !(*this == otherC);
}

/*
 * operator<<
 * Description: Overloaded stream extraction operator
 * Input: ostream &out - output stream, const Complex &c - complex number
 * Output: ostream& - output stream
 */
std::ostream &operator<<(std::ostream &out, const Complex &c)
{
    if (c.b < 0)
        out << c.a << c.b << 'i';
    else
        out << c.a << '+' << c.b << 'i';
    return out;
}

/*
 * operator>>
 * Description: Overloaded stream insertion operator
 * Input: istream &in - input stream, Complex &c - complex number
 * Output: istream& - input stream
 */
std::istream &operator>>(std::istream &in, Complex &c)
{
    in >> c.a >> c.b;
    return in;
}

/*
 * operator+
 * Description: Overloaded addition operator with double as first operand
 * Input: double d - real number, const Complex &c - complex number
 * Output: Complex - result of addition
 */
Complex operator+(double d, const Complex &c)
{
    return Complex(d + c.a, c.b);
}

/*
 * operator-
 * Description: Overloaded operator with double as first operand
 * Input: double d - real number, const Complex &c - complex number
 * Output: Complex - result of subtraction
 */
Complex operator-(double d, const Complex &c)
{
    return Complex(d - c.a, -c.b);
}

/*
 * operator*
 * Description: Overloaded operator with double as first operand
 * Input: double d - real number, const Complex &c - complex number
 * Output: Complex - result of multiplication
 */
Complex operator*(double d, const Complex &c)
{
    return Complex(d * c.a, d * c.b);
}

/*
 * operator/
 * Description: Overloaded division operator with double as first operand
 * Input: double d - real number, const Complex &c - complex number
 * Output: Complex - result of division
 */
Complex operator/(double d, const Complex &c)
{
    double denominator = c.a * c.a + c.b * c.b;
    return Complex((d * c.a) / denominator, (-d * c.b) / denominator);
}
