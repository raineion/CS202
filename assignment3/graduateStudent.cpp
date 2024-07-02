/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation
 *              of the graduateStudent
 *              class, which inherits from the
 *              student class and includes
 *              composition with the cs677 class.
 * Input: The input includes the grade for the cs677 course.
 * Output: The output includes the computed
 *         GPA based on the grade provided.
 */

#include <iostream>          // for cout
#include "graduateStudent.h" // for graduateStudent class

using namespace std;

// Default constructor
/*
 * function_identifier: graduateStudent - Default
 *                      constructor for the graduateStudent class
 * parameters: none
 * return value: none
 */
graduateStudent::graduateStudent() {}

// Parametrized constructor
/*
 * function_identifier: graduateStudent - Parameterized
 *                      constructor for the graduateStudent class
 * parameters: string ID, string fName, string lName -
 *             ID, first name, and last name of the student
 * return value: none
 */
graduateStudent::graduateStudent(string ID, string fName,
                                 string lName)
    : student(ID, fName, lName) {}

// Functions to set grades for cs677
/*
 * function_identifier: setCS677Grades - Sets grades for CS677
 * parameters: int fE - grade for the final exam
 * return value: none
 */
void graduateStudent::setCS677Grades(int fE)
{
    grCS677.setGrades(fE);
}

// Functions to get letter grades from classes
/*
 * function_identifier: getCS677LetterGrade - Gets
 *                      the letter grade for CS677
 * parameters: none
 * return value: char - letter grade for CS677
 */
char graduateStudent::getCS677LetterGrade()
{
    grCS677.calculateLetterGrade();
    return grCS677.getCourseGrade();
}

// Functions to handle gpa
/*
 * function_identifier: getGPA - Gets the GPA
 * parameters: none
 * return value: double - GPA
 */
double graduateStudent::getGPA()
{
    calculateGPA();
    return gpa;
}

/*
 * function_identifier: calculateGPA - Calculates the GPA
 * parameters: none
 * return value: none
 */
void graduateStudent::calculateGPA()
{
    double cs677GradePoint = 0.0;

    switch (getCS677LetterGrade())
    {
    case 'A':
        cs677GradePoint = 4.0;
        break;
    case 'B':
        cs677GradePoint = 3.0;
        break;
    case 'C':
        cs677GradePoint = 2.0;
        break;
    case 'D':
        cs677GradePoint = 1.0;
        break;
    case 'F':
        cs677GradePoint = 0.0;
        break;
    }

    gpa = cs677GradePoint;
}
