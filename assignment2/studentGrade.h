/*
  Header file for studentGrade object
*/
#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H

#include <string>

using namespace std;

class studentGrade {
private:
  string studentID;
  string firstName;
  string lastName;
  int asst1;
  int asst2;
  int asst3;
  int midtermExam;
  int finalExam;

public:
  studentGrade(); // default constructor

  // Parametrized constructor
  studentGrade(string ID, string fName, string lName, int a1,
               int a2, int a3, int midE, int finE);

  // setter function for all member variables
  void setStudentGrade(string ID, string fName, string lName, int a1,
                       int a2, int a3, int midE, int finE);

  // setter function for studentID
  void setStudentID(string);

  // getter function for studentID
  string getStudentID() const;
  // getter function for firstName
  string getFirstName() const;
  // getter function for lastName
  string getLastName() const;
  // getter function for asst1
  int getAsst1() const;
  // getter function for asst2
  int getAsst2() const;
  // getter function for asst3
  int getAsst3() const;
  // getter function for midtermExam
  int getMidtermExam() const;
  // getter function for finalExam
  int getFinalExam() const;

  // function for checking whether grades are valid
  bool checkScores();

  // function for calculating a student's letter grade
  char calculateLetterGrade();

  // function for printing student grade to stdout
  void printStudentGrade() const;

  // destructor
  ~studentGrade();
};

#endif
