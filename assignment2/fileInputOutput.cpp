/*
* Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 2
* Description: This file implements the 
*              fileInputOutput class, which handles
*              reading student grades from an input file 
*              and writing student grades to an output file.
* Input: Input file containing student grades, 
*        output file to write student grades.
* Output: Student grades and letter grades written to the output file.
*/

#include "fileInputOutput.h" // for fileInputOutput class
#include <iostream> // for cout

using namespace std; // avoid using `std::`

// Constructor
/*
 * fileInputOutput: Constructor to open input and output files.
 * parameters: string inputFile - name of the input file, 
 *             string outputFile - name of the output file.
 * return value: None.
 */
fileInputOutput::fileInputOutput(string inputFile, string outputFile) {
    inFile.open(inputFile);
    outFile.open(outputFile);
    fileError = !inFile.is_open() || !outFile.is_open();
    if (fileError) {
        if (!inFile.is_open()) {
            cout << "Could not open input file " 
                 << inputFile << "!" << endl;
        }
        if (!outFile.is_open()) {
            cout << "Could not open input file " 
                 << outputFile << "!" << endl;
        }
    }
}

// Destructor
/*
 * ~fileInputOutput: Destructor to close input and output files.
 * parameters: None.
 * return value: None.
 */
fileInputOutput::~fileInputOutput() {
    if (inFile.is_open()) {
        inFile.close();
    }
    if (outFile.is_open()) {
        outFile.close();
    }
}

// Function to read student grades from file
/*
 * getStudentGradesFromFile: Reads student grades from the 
 *                           input file and stores them in an array.
 * parameters: ifstream &inFile - input file stream, studentGrade 
 *                                studentList[100] - array to store 
 *                                student grades.
 * return value: unsigned int - 
 *               the number of students read from the file.
 */
unsigned int getStudentGradesFromFile(ifstream &inFile, 
                                     studentGrade studentList[100]) {
    unsigned int count = 0;
    string studentID, firstName, lastName;
    int asst1, asst2, asst3, midtermExam, finalExam;

    // Skip header line
    string header;
    getline(inFile, header);

    // Read data from file
    while (inFile >> studentID >> firstName >> lastName >> asst1 
          >> asst2 >> asst3 >> midtermExam >> finalExam) {
        studentList[count].setStudentGrade(studentID, firstName, 
                                          lastName, asst1, asst2, 
                                          asst3, midtermExam, finalExam);
        count++;
    }
    return count;
}

// Function to write student grades to file
/*
 * writeStudentGradesToFile: Writes student grades 
 *                           and their letter grades to the output file.
 * parameters: ofstream &outFile - output file stream, 
 *             studentGrade studentList[100] - array 
 *             of student grades, unsigned int totalStudents - 
 *             total number of students.
 * return value: None.
 */
void writeStudentGradesToFile(ofstream &outFile, 
                              studentGrade studentList[100], 
                              unsigned int totalStudents) {
    outFile << "studentID firstName lastName letterGrade\n";
    for (unsigned int i = 0; i < totalStudents; ++i) {
        outFile << studentList[i].getStudentID() << " "
                << studentList[i].getFirstName() << " "
                << studentList[i].getLastName() << " ";
        if (studentList[i].checkScores()) {
            outFile << studentList[i].calculateLetterGrade();
        } else {
            outFile << "Invalid scores";
        }
        outFile << endl;
    }
}
