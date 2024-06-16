/*
  Header file for fileInputOutput object
*/
#ifndef FILEINPUTOUTPUT_H
#define FILEINPUTOUTPUT_H

#include <fstream>
#include "studentGrade.h"

using namespace std;

class fileInputOutput {
public:
  ifstream inFile;
  ofstream outFile;
  bool fileError;

  // Open the input and output files in the constructor;
  // print appropriate error messages if the files are not present.
  fileInputOutput(string inputFile, string outputFile);

  // Define the destructor, which will close open file handles
  ~fileInputOutput();
};

// global functions that read and write data
unsigned int getStudentGradesFromFile(ifstream &inFile,
                                      studentGrade studentList[100]);

void writeStudentGradesToFile(ofstream &outFile,
                              studentGrade studentList[100],
                              unsigned int totalStudents);

#endif
