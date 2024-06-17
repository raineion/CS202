/*
  Header file for student object
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class student {
private:
  string studentID;
  string firstName;
  string lastName;

public:
  student(); // default constructor
  student(string ID, string fName, string lName); // parametrized constructor

  // getter functions
  string getStudentID();
  string getFirstName();
  string getLastName();

  // setter functions
  void setStudentInfo(string ID, string fName, string lName);
  void setStudentID(string ID);
  void setFirstName(string fName);
  void setLastName(string lName);

  // print student information
  void printStudentInfo() const;

  // destructor
  ~student();
};

#endif
