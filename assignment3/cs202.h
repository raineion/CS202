/*
  Header file for cs202 object
*/

#ifndef CS202_H
#define CS202_H

#include <string>
#include "course.h"

using namespace std;

class cs202: public course {
private:
  int asst1;
  int asst2;
  int asst3;
  int midtermExam;
  int finalExam;

  // function for checking grades
  bool checkGrades();

public:
  // default constructor
  cs202();

  // parametrized constructor
  cs202(int a1, int a2, int a3, int mE, int fE);

  // getter functions
  int getAsst1();
  int getAsst2();
  int getAsst3();
  int getMidtermExam();
  int getFinalExam();

  // setter functions
  void setAsst1(int a1);
  void setAsst2(int a2);
  void setAsst3(int a3);
  void setMidtermExam(int mE);
  void setFinalExam(int fE);
  void setGrades(int a1, int a2, int a3, int mE, int fE);

  // function for calculating letter grade
  void calculateLetterGrade();
};

#endif
