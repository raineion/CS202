/*
 * Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 3
 * Description: This file contains the implementation of the cs202 class,
 *              which inherits from the course class and adds specific
 *              functionality related to the CS202 course.
 * Input: The input includes various grades for
 *        assignments, midterms, and final exams.
 * Output: The output includes the computed letter
 *         grade based on the grades provided.
 */

#include <iostream> // for cout
#include "cs202.h"  // for cs202 class

using namespace std;

// Default constructor
/*
 * function_identifier: cs202 - Default constructor for the cs202 class
 * parameters: none
 * return value: none
 */
cs202::cs202() : asst1(0), asst2(0), asst3(0),
                 midtermExam(0), finalExam(0)
{
    setCourseName("Computer Science II");
    setCourseNumber("CS 202");
    setCourseCredits(3);
    setCourseGrade('F');
}

// Parameterized constructor
/*
 * function_identifier: cs202 - Parameterized
 *                      constructor for the cs202 class
 * parameters: int a1, int a2, int a3, int mE, int fE -
 *             grades for assignments, midterms, and final exam
 * return value: none
 */
cs202::cs202(int a1, int a2, int a3, int mE, int fE)
    : asst1(a1), asst2(a2), asst3(a3),
      midtermExam(mE), finalExam(fE)
{
    setCourseName("Computer Science II");
    setCourseNumber("CS 202");
    setCourseCredits(3);
    setCourseGrade('F');
}

// Getters
/*
 * function_identifier: Getters and Setters for the cs202 class
 * parameters: various integers for assignments,
 *             midterms, and final exam
 * return value: various integers representing grades
 */
int cs202::getAsst1() { return asst1; }
int cs202::getAsst2() { return asst2; }
int cs202::getAsst3() { return asst3; }
int cs202::getMidtermExam() { return midtermExam; }
int cs202::getFinalExam() { return finalExam; }

// Setters
void cs202::setAsst1(int a1) { asst1 = a1; }
void cs202::setAsst2(int a2) { asst2 = a2; }
void cs202::setAsst3(int a3) { asst3 = a3; }
void cs202::setMidtermExam(int mE) { midtermExam = mE; }
void cs202::setFinalExam(int fE) { finalExam = fE; }

void cs202::setGrades(int a1, int a2,
                      int a3, int mE, int fE)
{
    asst1 = a1;
    asst2 = a2;
    asst3 = a3;
    midtermExam = mE;
    finalExam = fE;
}

/*
 * function_identifier: checkGrades - Checks if all grades are valid
 * parameters: none
 * return value: bool - true if all grades are valid, false otherwise
 */

bool cs202::checkGrades()
{
    return (asst1 >= 0 && asst1 <= 100) &&
           (asst2 >= 0 && asst2 <= 100) &&
           (asst3 >= 0 && asst3 <= 100) &&
           (midtermExam >= 0 && midtermExam <= 100) &&
           (finalExam >= 0 && finalExam <= 100);
}

/*
 * function_identifier: calculateLetterGrade - Calculates
 *                      the letter grade based on all grades
 * parameters: none
 * return value: none
 */
void cs202::calculateLetterGrade()
{
    if (checkGrades())
    {
        double assignmentAvg = (asst1 + asst2 + asst3) / 3.0;
        double midtermScore = midtermExam;
        double finalScore = finalExam;
        double overallScore = (assignmentAvg * 0.5) +
                              (midtermScore * 0.25) + (finalScore * 0.25);

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
