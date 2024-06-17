/*
  Header file for undergraduateStudent object
*/

#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H

#include <string>
#include "student.h"
#include "cs135.h"
#include "cs202.h"

using namespace std;

class undergraduateStudent: public student {
private:
  // contains classes as member values!
  cs135 ugCS135;
  cs202 ugCS202;
  double gpa;

public:
  // default constructor
  undergraduateStudent();

  // parametrized constructor
  undergraduateStudent(string ID, string fName, string lName);

  // functions to set grades for member classes
  void setCS135Grades(int a1, int a2, int a3, int a4, int mE1, int mE2, int fE);
  void setCS202Grades(int a1, int a2, int a3, int mE, int fE);

  // functions to get letter grades from classes
  char getCS135LetterGrade();
  char getCS202LetterGrade();

  // functions to handle gpa
  double getGPA();
  void calculateGPA();
};

#endif
