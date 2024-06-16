#include <cassert> // assert
#include <iostream> // cout, endl
#include "studentGrade.h"
#include "fileInputOutput.h"

using namespace std;

int main(int argc, char **argv) {
  // define variables
  string fn_in, fn_out;
  studentGrade studentData[100];
  unsigned int totalStudents;

  // make sure we have at least one argument
  if (argc < 3) {
    cout << "Error! Need to pass in the names of input and output files"
         << endl;
    return 0;
  } else {
    fn_in = argv[1];
    fn_out = argv[2];
  }

  fileInputOutput fileHandler(fn_in, fn_out);

  // test reading students from file
  totalStudents = getStudentGradesFromFile(fileHandler.inFile, studentData);

  // test writing students to file
  writeStudentGradesToFile(fileHandler.outFile, studentData, totalStudents);

  // test making a studentGrade with the default constructor
  studentGrade sg1;

  // set values
  sg1.setStudentGrade("doe07ug", "John", "Doe", 82, 89, 92, 78, 98);

  // confirm that methods work
  assert(sg1.getStudentID() == "doe07ug");
  assert(sg1.getFirstName() == "John");
  assert(sg1.getLastName() == "Doe");
  assert(sg1.getAsst1() == 82);
  assert(sg1.getAsst2() == 89);
  assert(sg1.getMidtermExam() == 78);
  assert(sg1.getFinalExam() == 98);
  assert(sg1.checkScores());
  assert(sg1.calculateLetterGrade() == 'B');

  // test using the overloaded constructor
  studentGrade sg2("doe08ug", "Jane", "Doe", 87, 93, 91, 85, 95);

  // confirm methods work
  assert(sg2.getStudentID() == "doe08ug");
  assert(sg2.getFirstName() == "Jane");
  assert(sg2.getLastName() == "Doe");
  assert(sg2.getAsst1() == 87);
  assert(sg2.getAsst2() == 93);
  assert(sg2.getAsst3() == 91);
  assert(sg2.getMidtermExam() == 85);
  assert(sg2.getFinalExam() == 95);
  assert(sg2.checkScores());
  assert(sg2.calculateLetterGrade() == 'A');

  // test the studentID setter works
  sg1.setStudentID("foo");
  assert(sg1.getStudentID() == "foo");

  // test that we get errors for non-existent input files
  fileInputOutput bad_handle("foo.txt", "bar.txt");
  assert(bad_handle.fileError);

  return 0;
}
