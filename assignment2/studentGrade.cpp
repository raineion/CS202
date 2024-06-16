/*
* Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 2
* Description: Implements the studentGrade class for 
               managing student grades.
* Input: N/A (information is set using the setStudentGrade method).
* Output: Student ID, first name, last name, assignment grades, 
*         midterm exam grade, final exam grade.
*/

#include "studentGrade.h" // for studentGrade class
#include <iostream> // for cout

using namespace std; // avoid using `std::`

// Default constructor
/*
 * studentGrade: Default constructor to initialize member variables.
 * parameters: None.
 * return value: None.
 */
studentGrade::studentGrade() {
    studentID = "";
    firstName = "";
    lastName = "";
    asst1 = 0;
    asst2 = 0;
    asst3 = 0;
    midtermExam = 0;
    finalExam = 0;
}

// Parametrized constructor
/*
 * studentGrade: Constructor to initialize member 
 *               variables with provided values.
 * parameters: string ID, string fName, string lName, int a1, 
 *             int a2, int a3, int midE, int finE.
 * return value: None.
 */
studentGrade::studentGrade(string ID, string fName, string lName, 
                          int a1, int a2, int a3, int midE, int finE) {
    setStudentGrade(ID, fName, lName, a1, a2, a3, midE, finE);
}

// Setter function for all member variables
/*
 * setStudentGrade: Sets all member variables.
 * parameters: string ID, string fName, string lName, int a1, 
 *             int a2, int a3, int midE, int finE.
 * return value: None.
 */
void studentGrade::setStudentGrade(string ID, string fName, 
                                  string lName, int a1, 
                                  int a2, int a3, int midE, int finE) {
    studentID = ID;
    firstName = fName;
    lastName = lName;
    asst1 = a1;
    asst2 = a2;
    asst3 = a3;
    midtermExam = midE;
    finalExam = finE;
}

// Setter function for studentID
/*
 * setStudentID: Sets the student ID.
 * parameters: string ID.
 * return value: None.
 */
void studentGrade::setStudentID(string ID) {
    studentID = ID;
}

// Getter functions
/*
 * Getter functions: Returns the corresponding member variable values.
 * parameters: None.
 * return value: string/int - the value of the 
 *                            corresponding member variable.
 */
string studentGrade::getStudentID() const { return studentID; }
string studentGrade::getFirstName() const { return firstName; }
string studentGrade::getLastName() const { return lastName; }
int studentGrade::getAsst1() const { return asst1; }
int studentGrade::getAsst2() const { return asst2; }
int studentGrade::getAsst3() const { return asst3; }
int studentGrade::getMidtermExam() const { return midtermExam; }
int studentGrade::getFinalExam() const { return finalExam; }

// Function for checking whether grades are valid
/*
 * checkScores: Checks if all scores are within the valid range (0-100).
 * parameters: None.
 * return value: bool - true if all scores are valid, false otherwise.
 */
bool studentGrade::checkScores() {
    return (asst1 >= 0 && asst1 <= 100 && asst2 >= 0 && 
           asst2 <= 100 && asst3 >= 0 && asst3 <= 100 &&
           midtermExam >= 0 && midtermExam <= 100 && 
           finalExam >= 0 && finalExam <= 100);
}

// Function for calculating a student's letter grade
/*
 * calculateLetterGrade: Calculates the letter grade 
 *                       based on weighted scores.
 * parameters: None.
 * return value: char - the letter grade.
 */
char studentGrade::calculateLetterGrade() {
    double average = (asst1 + asst2 + asst3) / 3.0 * 0.5 + 
                     midtermExam * 0.25 + finalExam * 0.25;
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Function for printing student grade to stdout
/*
 * printStudentGrade: Prints the student's grade information.
 * parameters: None.
 * return value: None.
 */
void studentGrade::printStudentGrade() const {
    cout << "Student ID: " << studentID << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Assignment 1: " << asst1 << endl;
    cout << "Assignment 2: " << asst2 << endl;
    cout << "Assignment 3: " << asst3 << endl;
    cout << "Midterm Exam: " << midtermExam << endl;
    cout << "Final Exam: " << finalExam << endl;
}

// Destructor
/*
 * ~studentGrade: Destructor to clean up resources.
 * parameters: None.
 * return value: None.
 */
studentGrade::~studentGrade() {
    // Nothing to destruct
}
