/*
  Header file for cs677 object
*/

#ifndef CS677_H
#define CS677_H

#include <string>
#include "course.h"

using namespace std;

class cs677: public course {
private:
  int finalExam;

  // function for checking grades
  bool checkGrades();

public:
  // default constructor
  cs677();

  // parametrized constructor
  cs677(int fE);

  // getter functions
  int getFinalExam();

  // setter functions
  void setFinalExam(int fE);
  void setGrades(int fE);

  // function for calculating letter grade
  void calculateLetterGrade();
};

#endif
