/*
  Header file for course object
*/
#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class course {
private:
  string courseName;
  string courseNumber;
  int courseCredits;
  char courseGrade;

public:
  // default constructor
  course();

  // parametrized constructor
  course(string cName, string cNumber, int cCredits, char cGrade);

  // getter functions
  string getCourseName();
  string getCourseNumber();
  int getCourseCredits();
  char getCourseGrade();

  // setter functions
  void setCourseInfo(string cName, string cNumber, int cCredits,
                     char cGrade);
  void setCourseName(string cName);
  void setCourseNumber(string cNumber);
  void setCourseCredits(int cCredits);
  void setCourseGrade(char cGrade);

  // function for printing course info
  void printCourseInfo() const;

  // destructor
  ~course();
};

#endif
