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

// Parameterized constructor definition
Rectangle::Rectangle(double x, double y, double w, double h) {
    corner_x = x;  // Set the x-coordinate of the upper-left corner
    corner_y = y;  // Set the y-coordinate of the upper-left corner
    // Check if the provided width is greater than or equal to 0
    // If true, set width to w; otherwise, set width to 0
    width = (w >= 0) ? w : 0;
    // Check if the provided height is greater than or equal to 0
    // If true, set height to h; otherwise, set height to 0
    height = (h >= 0) ? h : 0;
}
