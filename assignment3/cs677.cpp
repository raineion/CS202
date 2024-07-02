/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation of the cs677 class,
 *              which inherits from the course class and adds specific
 *              functionality related to the CS677 course.
 * Input: The input includes the grade for the final exam.
 * Output: The output includes the computed letter grade
 *         based on the final exam grade.
 */

#include <iostream> // for cout
#include "cs677.h"  // for cs677 class

using namespace std;

// Default constructor
/*
 * function_identifier: cs677 - Default constructor
 *                      for the cs677 class
 * parameters: none
 * return value: none
 */
cs677::cs677() : finalExam(0)
{
    setCourseName("Analysis of Algorithms");
    setCourseNumber("CS 677");
    setCourseCredits(4);
    setCourseGrade('F');
}

// Parametrized constructor
/*
 * function_identifier: cs677 - Parameterized
 *                      constructor for the cs677 class
 * parameters: int fE - grade for the final exam
 * return value: none
 */
cs677::cs677(int fE) : finalExam(fE)
{
    setCourseName("Analysis of Algorithms");
    setCourseNumber("CS 677");
    setCourseCredits(4);
    setCourseGrade('F');
}

// Getter
/*
 * function_identifier: Getters and Setters for the cs677 class
 * parameters: various integers for final exam
 * return value: various integers representing grades
 */
int cs677::getFinalExam() { return finalExam; }

// Setter
void cs677::setFinalExam(int fE) { finalExam = fE; }
void cs677::setGrades(int fE) { finalExam = fE; }

/*
 * function_identifier: checkGrades - Checks
 *                      if the final exam grade is valid
 * parameters: none
 * return value: bool - true if the final exam grade
 *               is valid, false otherwise
 */
bool cs677::checkGrades()
{
    return (finalExam >= 0 && finalExam <= 100);
}

/*
 * function_identifier: calculateLetterGrade -
 *                      Calculates the letter grade based on
 *                      the final exam grade
 * parameters: none
 * return value: none
 */
void cs677::calculateLetterGrade()
{
    if (checkGrades())
    {
        double overallScore = finalExam;

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
