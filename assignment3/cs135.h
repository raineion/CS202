/*
  Header file for cs135 object
*/
#ifndef CS135_H
#define CS135_H

#include <string>
#include "course.h"

using namespace std;

class cs135: public course {
private:
  int asst1;
  int asst2;
  int asst3;
  int asst4;
  int midtermExam1;
  int midtermExam2;
  int finalExam;

  // method for checking grades
  bool checkGrades();

public:
  // default constructor
  cs135();

  // parametrized constructor
  cs135(int a1, int a2, int a3, int a4, int mE1, int mE2, int fE);

  // getter functions
  int getAsst1();
  int getAsst2();
  int getAsst3();
  int getAsst4();
  int getMidtermExam1();
  int getMidtermExam2();
  int getFinalExam();

  // setter functions
  void setAsst1(int a1);
  void setAsst2(int a2);
  void setAsst3(int a3);
  void setAsst4(int a4);
  void setMidtermExam1(int mE1);
  void setMidtermExam2(int mE2);
  void setFinalExam(int fE);
  void setGrades(int a1, int a2, int a3, int a4, int mE1, int mE2, int fE);

  // function for calculating letter grade
  void calculateLetterGrade();
};

#endif
