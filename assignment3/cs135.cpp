/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation of the cs135 class,
 *              which inherits from the course class and adds specific
 *              functionality related to the CS135 course.
 * Input: The input includes various grades for assignments,
 *        midterms, and final exams.
 * Output: The output includes the computed letter grade
 *         based on the grades provided.
 */

#include <iostream> // for cout
#include "cs135.h"  // for cs135 class

using namespace std;

// Default constructor
/*
 * function_identifier: cs135 - Default constructor for the cs135 class
 * parameters: none
 * return value: none
 */
cs135::cs135() : asst1(0), asst2(0), asst3(0), asst4(0),
                 midtermExam1(0), midtermExam2(0), finalExam(0)
{
    setCourseName("Computer Science I");
    setCourseNumber("CS 135");
    setCourseCredits(3);
    setCourseGrade('F');
}

// Parameterized constructor
/*
 * function_identifier: cs135 - Parameterized constructor
 *                      for the cs135 class
 * parameters: int a1, int a2, int a3, int a4, int mE1, int mE2, int fE -
 *             grades for assignments, midterms, and final exam
 * return value: none
 */
cs135::cs135(int a1, int a2, int a3, int a4,
             int mE1, int mE2, int fE)
    : asst1(a1), asst2(a2), asst3(a3), asst4(a4), midtermExam1(mE1),
      midtermExam2(mE2), finalExam(fE)
{
    setCourseName("Computer Science I");
    setCourseNumber("CS 135");
    setCourseCredits(3);
    setCourseGrade('F');
}

// Getters
/*
 * function_identifier: Getters and Setters for the cs135 class
 * parameters: various integers for assignments, midterms, and final exam
 * return value: various integers representing grades
 */
int cs135::getAsst1() { return asst1; }
int cs135::getAsst2() { return asst2; }
int cs135::getAsst3() { return asst3; }
int cs135::getAsst4() { return asst4; }
int cs135::getMidtermExam1() { return midtermExam1; }
int cs135::getMidtermExam2() { return midtermExam2; }
int cs135::getFinalExam() { return finalExam; }

// Setters
void cs135::setAsst1(int a1) { asst1 = a1; }
void cs135::setAsst2(int a2) { asst2 = a2; }
void cs135::setAsst3(int a3) { asst3 = a3; }
void cs135::setAsst4(int a4) { asst4 = a4; }
void cs135::setMidtermExam1(int mE1) { midtermExam1 = mE1; }
void cs135::setMidtermExam2(int mE2) { midtermExam2 = mE2; }
void cs135::setFinalExam(int fE) { finalExam = fE; }

void cs135::setGrades(int a1, int a2, int a3,
                      int a4, int mE1, int mE2, int fE)
{
    asst1 = a1;
    asst2 = a2;
    asst3 = a3;
    asst4 = a4;
    midtermExam1 = mE1;
    midtermExam2 = mE2;
    finalExam = fE;
}

/*
 * function_identifier: checkGrades - Checks if all grades are valid
 * parameters: none
 * return value: bool - true if all grades are valid, false otherwise
 */
bool cs135::checkGrades()
{
    return (asst1 >= 0 && asst1 <= 100) &&
           (asst2 >= 0 && asst2 <= 100) &&
           (asst3 >= 0 && asst3 <= 100) &&
           (asst4 >= 0 && asst4 <= 100) &&
           (midtermExam1 >= 0 && midtermExam1 <= 100) &&
           (midtermExam2 >= 0 && midtermExam2 <= 100) &&
           (finalExam >= 0 && finalExam <= 100);
}

/*
 * function_identifier: calculateLetterGrade -
 *                      Calculates the letter grade based on all grades
 * parameters: none
 * return value: none
 */
void cs135::calculateLetterGrade()
{
    if (checkGrades())
    {
        double assignmentAvg = (asst1 + asst2 + asst3 + asst4) / 4.0;
        double midtermAvg = (midtermExam1 + midtermExam2) / 2.0;
        double finalScore = finalExam;
        double overallScore = (assignmentAvg * 0.5) +
                              (midtermAvg * 0.25) + (finalScore * 0.25);

        if (overallScore >= 90)
        {
            setCourseGrade('A');
        }
        else if (overallScore >= 80)
        {
            setCourseGrade('B');
        }
        else if (overallScore >= 70)
        {
            setCourseGrade('C');
        }
        else if (overallScore >= 60)
        {
            setCourseGrade('D');
        }
        else
        {
            setCourseGrade('F');
        }
    }
}
