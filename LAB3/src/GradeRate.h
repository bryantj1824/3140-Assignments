#ifndef GRADERATE_H
#define GRADERATE_H

#include "InstructorTermCourse.h"
#include "StudentGrade.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class GradeRate{

	public:

		// This variable will define which terms are spring terms
		static vector< string > springTerms;

		// This variable will define which terms are fall terms
		static vector< string > fallTerms;

		// This variable will define which grades are considered passing
		static vector< string > passingGrades;

		// These variables will be refered to as categorys ("Instructor", "Term", "Course")
		static map<string, InstructorTermCourse> Instructors;
		static map<string, InstructorTermCourse> Terms;
		static map<string, InstructorTermCourse> Courses;

		// For saving all recorded StudentGrades
		static vector< StudentGrade > StudentGrades;

		// For recording students grades under correct category ("Instructor", "Term", "Course")
		static void recordStudentGrade(string id, string courseNum, string instructorId, string termID, string sectionID, string grade = "");

		// Retrieves pass rate for category with id
		static string getPassRate(string category, string categoryId);

		// Retrieves grade rate for category with id
		static string getGradeRate(string category, string categoryId, string grade);

		// Returns pass rate for a fall course
		static string getFallPassRateForCourse(string courseID);

		// Returns pass rate for a spring course
		static string getSpringPassRateForCourse(string courseID);

		// Retrieves the number of times a grade occured in the category with id
		static string getGradeOccurence(string category, string categoryId, string grade);

		// Returns the number of recorded grades for a category
		static int getInstructorTermOrCourseGradesCount(string category, string categoryId);

		// Function that calculates a/b to get the percentage and formats it and returns it as a string
		static string calculateGradeRate(double a, double b);

};

#endif