#include <iostream>
using namespace std;

class Rectangle {
private:
  double corner_x;  // x-coordinate of upper-left corner
  double corner_y;  // y-coordinate of upper-left corner
  double width;     // x-extent of rectangle
  double height;    // y-extent of rectangle

public:
  Rectangle();  // Default constructor
  Rectangle(double x, double y, double w, double h);  // Parameterized constructor
  void setCorner(double x, double y);
  void setWidth(double w);
  void setHeight(double h);
  double getXCorner();
  double getYCorner();
  double getWidth();
  double getHeight();
  double getArea();
};

// Function definition for calculating and returning the area of the rectangle
double Rectangle::getArea() {
    // The area of a rectangle is calculated as width multiplied by height.
    // This line simply returns the result of width * height.
    // No additional checks are needed here because width and height should
    // always be non-negative due to constraints enforced by other methods.
    return width * height;
}
