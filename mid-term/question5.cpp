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

// Function definition for setting the width
void Rectangle::setWidth(double w) {
    // This line checks if the provided width (w) is greater than or equal to 0.
    // The condition (w >= 0) is evaluated first.
    // If the condition is true, the expression (w >= 0) ? w : 0 will result in w.
    // If the condition is false (i.e., w is negative), the expression will result in 0.
    // Therefore, width is set to w if w is non-negative, and set to 0 if w is negative.
    width = (w >= 0) ? w : 0;
}
