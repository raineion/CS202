/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation of
 *              the undergraduateStudent
 *              class, which inherits from the student
 *              class and includes composition
 *              with cs135 and cs202 classes.
 * Input: The input includes various grades for the
 *        cs135 and cs202 courses.
 * Output: The output includes the computed GPA
 *         based on the grades provided.
 */

#include <iostream>               // for cout
#include "undergraduateStudent.h" // for undergraduateStudent class

using namespace std;

// Default constructor
/*
 * function_identifier: undergraduateStudent -
 *                      Default constructor for the
 *                      undergraduateStudent class
 * parameters: none
 * return value: none
 */
undergraduateStudent::undergraduateStudent() {}

// Parametrized constructor
/*
 * function_identifier: undergraduateStudent - Parameterized
 *                      constructor for the undergraduateStudent class
 * parameters: string ID, string fName, string lName - ID, first name,
 *             and last name of the student
 * return value: none
 */
undergraduateStudent::undergraduateStudent(string ID,
                                           string fName, string lName)
    : student(ID, fName, lName) {}

// Functions to set grades for member classes
/*
 * function_identifier: setCS135Grades - Sets grades for CS135
 * parameters: int a1, int a2, int a3, int a4, int mE1, int mE2, int fE -
 *             grades for assignments, midterms, and final exam
 * return value: none
 */
void undergraduateStudent::setCS135Grades(int a1, int a2, int a3,
                                          int a4, int mE1, int mE2, int fE)
{
    ugCS135.setGrades(a1, a2, a3, a4, mE1, mE2, fE);
}

/*
* function_identifier: setCS202Grades - Sets grades for CS202
* parameters: int a1, int a2, int a3, int mE, int fE -
              grades for assignments, midterm, and final exam
* return value: none
*/
void undergraduateStudent::setCS202Grades(int a1, int a2, int a3,
                                          int mE, int fE)
{
    ugCS202.setGrades(a1, a2, a3, mE, fE);
}

// Functions to get letter grades from classes
/*
 * function_identifier: getCS135LetterGrade - Gets the
 *                      letter grade for CS135
 * parameters: none
 * return value: char - letter grade for CS135
 */
char undergraduateStudent::getCS135LetterGrade()
{
    ugCS135.calculateLetterGrade();
    return ugCS135.getCourseGrade();
}

/*
 * function_identifier: getCS202LetterGrade - Gets the
 *                      letter grade for CS202
 * parameters: none
 * return value: char - letter grade for CS202
 */
char undergraduateStudent::getCS202LetterGrade()
{
    ugCS202.calculateLetterGrade();
    return ugCS202.getCourseGrade();
}

// Functions to handle gpa
/*
 * function_identifier: getGPA - Gets the GPA
 * parameters: none
 * return value: double - GPA
 */

double undergraduateStudent::getGPA()
{
    calculateGPA();
    return gpa;
}

/*
 * function_identifier: calculateGPA - Calculates the GPA
 * parameters: none
 * return value: none
 */
void undergraduateStudent::calculateGPA()
{
    double cs135GradePoint = 0.0, cs202GradePoint = 0.0;

    switch (getCS135LetterGrade())
    {
    case 'A':
        cs135GradePoint = 4.0;
        break;
    case 'B':
        cs135GradePoint = 3.0;
        break;
    case 'C':
        cs135GradePoint = 2.0;
        break;
    case 'D':
        cs135GradePoint = 1.0;
        break;
    case 'F':
        cs135GradePoint = 0.0;
        break;
    }

    switch (getCS202LetterGrade())
    {
    case 'A':
        cs202GradePoint = 4.0;
        break;
    case 'B':
        cs202GradePoint = 3.0;
        break;
    case 'C':
        cs202GradePoint = 2.0;
        break;
    case 'D':
        cs202GradePoint = 1.0;
        break;
    case 'F':
        cs202GradePoint = 0.0;
        break;
    }

    gpa = (cs135GradePoint * 3 + cs202GradePoint * 3) / 6.0;
}
