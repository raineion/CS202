/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation of the
 *              course class, which is a base class for various courses.
 * Input: The input includes course details such as
 *        name, number, credits, and grade.
 * Output: The output includes the course
 *         details and validation of the grade.
 */

#include <iostream> // for cout
#include "course.h" // for course class

using namespace std;

// Default constructor
/*
 * function_identifier: course - Default constructor for the course class
 * parameters: none
 * return value: none
 */
course::course() : courseName(""), courseNumber(""),
                   courseCredits(0), courseGrade('F') {}

// Parametrized constructor
/*
 * function_identifier: course - Parameterized
 *                               constructor for the course class
 * parameters: string cName, string cNumber, int cCredits,
 *             char cGrade - name, number, credits, and
 *             grade of the course
 * return value: none
 */
course::course(string cName, string cNumber, int cCredits, char cGrade)
    : courseName(cName), courseNumber(cNumber), courseCredits(cCredits)
{
    setCourseGrade(cGrade);
}

// Setter for course information
/*
 * function_identifier: Getters and Setters for the course class
 * parameters: various types for course details
 * return value: various types representing course details
 */
void course::setCourseInfo(string cName, string cNumber,
                           int cCredits, char cGrade)
{
    courseName = cName;
    courseNumber = cNumber;
    courseCredits = cCredits;
    setCourseGrade(cGrade);
}

// Getters
string course::getCourseName() { return courseName; }
string course::getCourseNumber() { return courseNumber; }
int course::getCourseCredits() { return courseCredits; }
char course::getCourseGrade() { return courseGrade; }

// Setters
void course::setCourseName(string cName) { courseName = cName; }
void course::setCourseNumber(string cNumber) { courseNumber = cNumber; }
void course::setCourseCredits(int cCredits) { courseCredits = cCredits; }

// Setter for course grade with validation
/*
 * function_identifier: setCourseInfo - Sets course information
 * parameters: string cName, string cNumber, int cCredits,
 *             char cGrade - name, number, credits, and
 *             grade of the course
 * return value: none
 */
void course::setCourseGrade(char cGrade)
{
    if (cGrade == 'A' || cGrade == 'B' || cGrade == 'C' ||
        cGrade == 'D' || cGrade == 'F')
    {
        courseGrade = cGrade;
    }
    else
    {
        cout << "Bad grade character: " << cGrade << endl;
    }
}

// Print course information
/*
 * function_identifier: printCourseInfo - Prints course information
 * parameters: none
 * return value: none
 */
void course::printCourseInfo() const
{
    cout << "Course Name: " << courseName << endl;
    cout << "Course Number: " << courseNumber << endl;
    cout << "Course Credits: " << courseCredits << endl;
    cout << "Course Grade: " << courseGrade << endl;
}

// Destructor
/*
 * function_identifier: ~course - Destructor for the course class
 * parameters: none
 * return value: none
 */
course::~course() {}
