#include <iostream>  // Include the iostream library for input and output operations
#include <cmath>     // Include the cmath library for mathematical functions like sqrt

using namespace std; // Use the standard namespace to avoid prefixing std:: to standard library names

// Class definition for Vector
class Vector {
private:
    double x, y, z; // Private member variables to store the x, y, and z components of the vector

public:
    // Default constructor initializing x, y, and z to 0
    Vector() : x(0), y(0), z(0) {} // Initialization list sets x, y, and z to 0

    // Parameterized constructor initializing x, y, and z with the given values
    Vector(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {} // Initialization list sets x, y, and z to xVal, yVal, and zVal respectively

    // Getter function to retrieve the x component
    double getX() const { return x; }

    // Getter function to retrieve the y component
    double getY() const { return y; }

    // Getter function to retrieve the z component
    double getZ() const { return z; }

    // Setter function to set the x component
    void setX(double xVal) { x = xVal; }

    // Setter function to set the y component
    void setY(double yVal) { y = yVal; }

    // Setter function to set the z component
    void setZ(double zVal) { z = zVal; }

    // Function to calculate and return the magnitude of the vector
    double getMagnitude() const {
        // Magnitude is calculated as the square root of the sum of the squares of the components
        return sqrt(x * x + y * y + z * z);
    }
};

// Function to calculate the dot product of two vectors
double dotProduct(const Vector& v1, const Vector& v2) {
    // Dot product is calculated as the sum of the products of the corresponding components
    return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

// Function to calculate the cross product of two vectors
Vector crossProduct(const Vector& v1, const Vector& v2) {
    // Cross product is calculated using the determinant of a 3x3 matrix formed by the components of the vectors
    double x = v1.getY() * v2.getZ() - v1.getZ() * v2.getY(); // Calculate the x component of the resulting vector
    double y = v1.getZ() * v2.getX() - v1.getX() * v2.getZ(); // Calculate the y component of the resulting vector
    double z = v1.getX() * v2.getY() - v1.getY() * v2.getX(); // Calculate the z component of the resulting vector
    return Vector(x, y, z); // Return the resulting vector
}

int main() {
    // Initialize an object of class Vector called v1 using the default constructor
    Vector v1;

    // Initialize an object of class Vector called v2 using the parameterized constructor
    Vector v2(1.0, 2.0, 3.0); // Set the initial values to (1.0, 2.0, 3.0)

    // Set the x-component of v1 to -0.5
    v1.setX(-0.5); // This sets the private member variable x of v1 to -0.5

    // Set the y-component of v1 to 2.3
    v1.setY(2.3); // This sets the private member variable y of v1 to 2.3

    // Set the z-component of v1 to -3.0
    v1.setZ(-3.0); // This sets the private member variable z of v1 to -3.0

    // Compute and print the magnitudes of v1 and v2
    cout << "Magnitude of v1: " << v1.getMagnitude() << endl; // Call getMagnitude on v1 and print the result; should be about 3.81
    cout << "Magnitude of v2: " << v2.getMagnitude() << endl; // Call getMagnitude on v2 and print the result; should be about 3.74

    // Compute and print the dot product of v1 and v2
    cout << "Dot product of v1 and v2: " << dotProduct(v1, v2) << endl; // Call dotProduct with v1 and v2 and print the result; should be about -4.9

    // Compute and print the cross product of v1 and v2
    Vector v3 = crossProduct(v1, v2); // Call crossProduct with v1 and v2 and store the result in v3
    cout << "Cross product of v1 and v2: (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << endl; // Print the components of v3; should be about (12.9, -1.5, -3.3)

    return 0; // Return 0 to indicate successful execution
}
