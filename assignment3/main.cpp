/*
  This is the main function that will call different functions to make
  sure your program is working as intended. DO NOT ALTER THE CONTENTS OF
  THIS FILE. For the assignment, you should ONLY create the *.cpp files
  corresponding to the header files *.h. This file defines the `main`
  function and tests whether the classes and functions are defined
  correctly or not.
*/

#include <cassert>
#include <iostream>
#include <cmath>
#include "student.h"
#include "course.h"
#include "cs135.h"
#include "cs202.h"
#include "cs677.h"
#include "undergraduateStudent.h"
#include "graduateStudent.h"

using namespace std;

int main() {
  // test making students with constructors
  student baseStudent1;
  student baseStudent2("ug95smi", "Richard", "Smith");
  assert(baseStudent2.getStudentID() == "ug95smi");
  assert(baseStudent2.getFirstName() == "Richard");
  assert(baseStudent2.getLastName() == "Smith");
  baseStudent2.printStudentInfo();
  baseStudent2.setStudentID("foo");
  assert(baseStudent2.getStudentID() == "foo");
  baseStudent2.setFirstName("John");
  assert(baseStudent2.getFirstName() == "John");
  baseStudent2.setLastName("Wick");
  assert(baseStudent2.getLastName() == "Wick");
  baseStudent2.setStudentInfo("ug95smi", "Richard", "Smith");
  assert(baseStudent2.getStudentID() == "ug95smi");
  assert(baseStudent2.getFirstName() == "Richard");
  assert(baseStudent2.getLastName() == "Smith");

  // test making courses with constructors
  course baseCourse1;
  course baseCourse2("Data Science I", "CS 138", 3, 'F');
  assert(baseCourse2.getCourseName() == "Data Science I");
  assert(baseCourse2.getCourseNumber() == "CS 138");
  assert(baseCourse2.getCourseCredits() == 3);
  assert(baseCourse2.getCourseGrade() == 'F');
  baseCourse2.printCourseInfo();
  baseCourse1.setCourseInfo("Data Science II", "CS 238", 3, 'A');
  assert(baseCourse1.getCourseName() == "Data Science II");
  assert(baseCourse1.getCourseNumber() == "CS 238");
  assert(baseCourse1.getCourseCredits() == 3);
  assert(baseCourse1.getCourseGrade() == 'A');
  baseCourse1.setCourseGrade('H');
  assert(baseCourse1.getCourseGrade() == 'A');

  // cs135
  // test making cs135 with constructors
  cs135 cs135_1;
  cs135 cs135_2(86, 89, 93, 85, 96, 92, 99);
  // default constructor tests
  assert(cs135_1.getCourseName() == "Computer Science I");
  assert(cs135_1.getCourseNumber() == "CS 135");
  assert(cs135_1.getCourseCredits() == 3);
  assert(cs135_1.getCourseGrade() == 'F');

  // parametrized constructor tests
  assert(cs135_2.getCourseName() == "Computer Science I");
  assert(cs135_2.getCourseNumber() == "CS 135");
  assert(cs135_2.getCourseCredits() == 3);
  assert(cs135_2.getCourseGrade() == 'F');
  assert(cs135_2.getAsst1() == 86);
  assert(cs135_2.getAsst2() == 89);
  assert(cs135_2.getAsst3() == 93);
  assert(cs135_2.getAsst4() == 85);
  assert(cs135_2.getMidtermExam1() == 96);
  assert(cs135_2.getMidtermExam2() == 92);
  assert(cs135_2.getFinalExam() == 99);

  // setter functions
  cs135_2.setAsst1(23);
  assert(cs135_2.getAsst1() == 23);
  cs135_2.setAsst2(24);
  assert(cs135_2.getAsst2() == 24);
  cs135_2.setAsst3(25);
  assert(cs135_2.getAsst3() == 25);
  cs135_2.setAsst4(26);
  assert(cs135_2.getAsst4() == 26);
  cs135_2.setMidtermExam1(88);
  assert(cs135_2.getMidtermExam1() == 88);
  cs135_2.setMidtermExam2(90);
  assert(cs135_2.getMidtermExam2() == 90);
  cs135_2.setGrades(91, 92, 93, 94, 95, 96, 97);
  assert(cs135_2.getAsst1() == 91);
  assert(cs135_2.getAsst2() == 92);
  assert(cs135_2.getAsst3() == 93);
  assert(cs135_2.getAsst4() == 94);
  assert(cs135_2.getMidtermExam1() == 95);
  assert(cs135_2.getMidtermExam2() == 96);
  assert(cs135_2.getFinalExam() == 97);
  cs135_2.calculateLetterGrade();
  assert(cs135_2.getCourseGrade() == 'A');
  cs135_2.setCourseGrade('I');
  assert(cs135_2.getCourseGrade() == 'A');

  // cs202
  // test constructors
  cs202 cs202_1;
  cs202 cs202_2(85, 88, 19, 23, 55);
  // default constructor tests
  assert(cs202_1.getCourseName() == "Computer Science II");
  assert(cs202_1.getCourseNumber() == "CS 202");
  assert(cs202_1.getCourseCredits() == 3);
  assert(cs202_1.getCourseGrade() == 'F');

  // parametrized constructor tests
  assert(cs202_2.getCourseName() == "Computer Science II");
  assert(cs202_2.getCourseNumber() == "CS 202");
  assert(cs202_2.getCourseCredits() == 3);
  assert(cs202_2.getCourseGrade() == 'F');
  assert(cs202_2.getAsst1() == 85);
  assert(cs202_2.getAsst2() == 88);
  assert(cs202_2.getAsst3() == 19);
  assert(cs202_2.getMidtermExam() == 23);
  assert(cs202_2.getFinalExam() == 55);

  // setter functions
  cs202_1.setAsst1(12);
  assert(cs202_1.getAsst1() == 12);
  cs202_1.setAsst2(13);
  assert(cs202_1.getAsst2() == 13);
  cs202_1.setAsst3(14);
  assert(cs202_1.getAsst3() == 14);
  cs202_1.setMidtermExam(15);
  assert(cs202_1.getMidtermExam() == 15);
  cs202_1.setFinalExam(16);
  assert(cs202_1.getFinalExam() == 16);
  cs202_2.setGrades(81, 82, 83, 84, 85);
  assert(cs202_2.getAsst1() == 81);
  assert(cs202_2.getAsst2() == 82);
  assert(cs202_2.getAsst3() == 83);
  assert(cs202_2.getMidtermExam() == 84);
  assert(cs202_2.getFinalExam() == 85);
  cs202_2.calculateLetterGrade();
  assert(cs202_2.getCourseGrade() == 'B');
  cs202_2.setCourseGrade('J');
  assert(cs202_2.getCourseGrade() == 'B');

  // cs677
  // test constructors
  cs677 cs677_1;
  cs677 cs677_2(85);
  // default constructor tests
  assert(cs677_1.getCourseName() == "Analysis of Algorithms");
  assert(cs677_1.getCourseNumber() == "CS 677");
  assert(cs677_1.getCourseCredits() == 4);
  assert(cs677_1.getCourseGrade() == 'F');

  // parametrized constructor tests
  assert(cs677_2.getCourseName() == "Analysis of Algorithms");
  assert(cs677_2.getCourseNumber() == "CS 677");
  assert(cs677_2.getCourseCredits() == 4);
  assert(cs677_2.getCourseGrade() == 'F');
  assert(cs677_2.getFinalExam() == 85);

  // test setters
  cs677_1.setFinalExam(90);
  assert(cs677_1.getFinalExam() == 90);
  cs677_1.setGrades(78);
  assert(cs677_1.getFinalExam() == 78);
  cs677_1.calculateLetterGrade();
  assert(cs677_1.getCourseGrade() == 'C');
  cs677_1.setCourseGrade('K');
  assert(cs677_1.getCourseGrade() == 'C');

  // undergraduateStudent -- default constructor
  undergraduateStudent ug1;
  ug1.setCS135Grades(65, 66, 67, 68, 69, 70, 71);
  ug1.setCS202Grades(71, 72, 73, 74, 75);
  assert(ug1.getCS135LetterGrade() == 'D');
  assert(ug1.getCS202LetterGrade() == 'C');
  ug1.calculateGPA();
  assert(fabs(ug1.getGPA() - 1.5) < 1e-2);

  // undergraduateStudent -- parametrized constructor
  undergraduateStudent ug2("ug87gar", "Steven", "Garcia");
  ug2.setCS135Grades(99, 97, 92, 95, 90, 99, 100);
  ug2.setCS202Grades(99, 88, 90, 91, 92);
  assert(ug2.getStudentID() == "ug87gar");
  assert(ug2.getFirstName() == "Steven");
  assert(ug2.getLastName() == "Garcia");
  assert(ug2.getCS135LetterGrade() == 'A');
  assert(ug2.getCS202LetterGrade() == 'A');
  ug2.calculateGPA();
  assert(fabs(ug2.getGPA() - 4.0) < 1e-2);

  // graduateStudent -- default constructor
  graduateStudent gr1;
  gr1.setCS677Grades(87);
  assert(gr1.getCS677LetterGrade() == 'B');
  gr1.calculateGPA();
  assert(fabs(gr1.getGPA() - 3.0) < 1e-2);

  // graduateStudent -- parametrized constructor
  graduateStudent gr2("gr93gon", "Raul", "Gonzales");
  gr2.setCS677Grades(78);
  assert(gr2.getStudentID() == "gr93gon");
  assert(gr2.getFirstName() == "Raul");
  assert(gr2.getLastName() == "Gonzales");
  assert(gr2.getCS677LetterGrade() == 'C');
  gr2.calculateGPA();
  assert(fabs(gr2.getGPA() - 2.0) < 1e-2);

  cout << "All tests successfully passed!" << endl;
  return 0;
}
