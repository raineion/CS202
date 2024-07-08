/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation of the
 *              student class, which is a base class for
 *              different types of students.
 * Input: The input includes student details such as ID,
 *        first name, and last name.
 * Output: The output includes the student details.
 */

#include <iostream>  // for cout
#include "student.h" // for student class

using namespace std;

// Default constructor
/*
 * function_identifier: student - Default
 *                      constructor for the student class
 * parameters: none
 * return value: none
 */
student::student() : studentID(""), firstName(""), lastName("") {}

// Parametrized constructor
/*
 * function_identifier: student - Parameterized
 *                      constructor for the student class
 * parameters: string ID, string fName, string lName - ID,
 *             first name, and last name of the student
 * return value: none
 */
student::student(string ID, string fName, string lName)
    : studentID(ID), firstName(fName), lastName(lName) {}

// Getter functions
/*
 * function_identifier: Getters and Setters for the student class
 * parameters: various types for student details
 * return value: various types representing student details
 */
string student::getStudentID() { return studentID; }
string student::getFirstName() { return firstName; }
string student::getLastName() { return lastName; }

// Setter functions
void student::setStudentInfo(string ID,
                             string fName, string lName)
{
    studentID = ID;
    firstName = fName;
    lastName = lName;
}

void student::setStudentID(string ID) { studentID = ID; }
void student::setFirstName(string fName) { firstName = fName; }
void student::setLastName(string lName) { lastName = lName; }

// Print student information
/*
 * function_identifier: printStudentInfo - Prints student information
 * parameters: none
 * return value: none
 */
void student::printStudentInfo() const
{
    cout << "Student ID: " << studentID << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
}

// Destructor
/*
 * function_identifier: ~student - Destructor for the student class
 * parameters: none
 * return value: none
 */

student::~student() {}
