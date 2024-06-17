/*
  Header file for graduateStudent object
*/

#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include <string>
#include "student.h"
#include "cs677.h"

using namespace std;

class graduateStudent: public student {
private:
  // contains a class as a member variable!
  cs677 grCS677;
  double gpa;

public:
  // default constructor
  graduateStudent();

  // parametrized constructor
  graduateStudent(string ID, string fName, string lName);

  // functions to set grades for cs677
  void setCS677Grades(int fE);

  // functions to get letter grades from classes
  char getCS677LetterGrade();

  // functions to handle gpa
  double getGPA();
  void calculateGPA();
};

#endif
