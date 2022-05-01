#include "GradeRate.h"
#include "InstructorTermCourse.h"
#include "StudentGrade.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector< string > GradeRate::springTerms = {"T02", "T06", "T10", "T14", "T18", "T21"};

vector< string > GradeRate::fallTerms = {"T04", "T08", "T12", "T16", "T20", "T23"};

vector< string > GradeRate::passingGrades = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "P" };

vector < StudentGrade > GradeRate::GradeRate::StudentGrades;
map <string, InstructorTermCourse> GradeRate::Instructors;
map <string, InstructorTermCourse> GradeRate::Terms;
map <string, InstructorTermCourse> GradeRate::Courses;

/**
 * Will record the student grade and add to its correct categories ("Instructor", "Term", "Course")
 */
void GradeRate::recordStudentGrade(string id, string courseNum, string instructorId, string termID, string sectionID, string grade){

	StudentGrade studentGrade = StudentGrade(id, courseNum, instructorId, termID, sectionID, grade);

	/* ----- The following if statements will check if the course num, instructor id, term id are set, if not then we add them ----- */

	// Course not found in Courses Mape, so we add the course to Courses
	if ( GradeRate::Courses.find(courseNum) == GradeRate::Courses.end() ) {
		GradeRate::Courses.insert( {courseNum, InstructorTermCourse( courseNum, "Course" )} );
	}

	// Instructor not found in Instructors Map, so we add the Instructor to Instructors
	if ( GradeRate::Instructors.find(instructorId) == GradeRate::Instructors.end() ) {
		GradeRate::Instructors.insert( {instructorId, InstructorTermCourse( instructorId, "Instructor" )} );
	}

	// Instructor not found in Instructors Map, so we add the Instructor to Instructors
	if ( GradeRate::Terms.find(termID) == GradeRate::Terms.end() ) {
		GradeRate::Terms.insert( {termID, InstructorTermCourse( termID, "Term" )} );
	}

	/* ----- By now we 100% should have the Instructors, Terms, Courses set so we just simply push the student grade object into each corresponding category ----- */

	InstructorTermCourse & the_instructor = GradeRate::Instructors.at(instructorId);

	InstructorTermCourse & the_course = GradeRate::Courses.at(courseNum);

	InstructorTermCourse & the_term = GradeRate::Terms.at(termID);

	the_instructor.addStudentGrade( studentGrade );
	the_course.addStudentGrade( studentGrade );
	the_term.addStudentGrade( studentGrade );

	GradeRate::StudentGrades.push_back(studentGrade);

}

/**
 * Given a category ("Instructor", "Term", "Course") along with category id or the id of the ("Instructor", "Term", "Course")
 * this function will return the pass rate
 */
string GradeRate::getPassRate(string category, string categoryId){

	// Will keep track of all passing grades we find for category
	int passingGradesCount = 0;

	// The total number of grades recorded for category
	double totalGradesCount = GradeRate::getInstructorTermOrCourseGradesCount(category, categoryId);

	// Records the count of passing grades for category
	for( int i = 0; i < GradeRate::passingGrades.size(); i++ ){
		passingGradesCount = passingGradesCount + stoi(GradeRate::getGradeOccurence(category, categoryId, GradeRate::passingGrades[i]));
	}

	// Returns the string representation of the calculated grade rate percentage
	return GradeRate::calculateGradeRate(passingGradesCount, totalGradesCount);

}


/**
 * Given a category ("Instructor", "Term", "Course") along with category id or the id of the ("Instructor", "Term", "Course")
 * and a grade, this function will return the grade rate
 */
string GradeRate::getGradeRate(string category, string categoryId, string grade){

	// The total number of grades recorded for category
	double totalGradesCount = GradeRate::getInstructorTermOrCourseGradesCount(category, categoryId);

	// The amount of times the grade appeared for the given category with category id
	double gradeCount = stoi(GradeRate::getGradeOccurence(category, categoryId, grade));

	// Returns the string representation of the calculated grade rate percentage
	return GradeRate::calculateGradeRate(gradeCount, totalGradesCount);

}

/**
 * Returns fall pass rate for a course
 */
string GradeRate::getFallPassRateForCourse(string courseID){

	int passingGradesCount = 0;

	InstructorTermCourse course = GradeRate::Courses.at(courseID);

	int totalGradesCount = course.StudentGrades.size();

	for(int i = 0; i < totalGradesCount; i++ ){ // loops through student grades

		for( int x = 0; x < GradeRate::fallTerms.size(); x++ ){ // Loops through fall terms

			if (course.StudentGrades[i].termID == GradeRate::fallTerms[x]){ // if student grade term id matches fall term id

				for( int y = 0; y < GradeRate::passingGrades.size(); y++){ // Looping through list of passing grades

					if (GradeRate::passingGrades[y] == course.StudentGrades[i].grade){ // Check if student grade matches a passing grade

						// If student passed we increment passingGradesCount
						passingGradesCount = passingGradesCount + 1;

					}					

				}

				break;
			}
		}		

	}

	cout << GradeRate::calculateGradeRate(passingGradesCount, totalGradesCount) << endl;

	return GradeRate::calculateGradeRate(passingGradesCount, totalGradesCount);

}

/**
 * Returns pass rate for a spring course
 */
string GradeRate::getSpringPassRateForCourse(string courseID){

	int passingGradesCount = 0;

	InstructorTermCourse course = GradeRate::Courses.at(courseID);

	int totalGradesCount = course.StudentGrades.size();

	for(int i = 0; i < totalGradesCount; i++ ){ // loops through student grades

		for( int x = 0; x < GradeRate::springTerms.size(); x++ ){ // Loops through spring terms

			if (course.StudentGrades[i].termID == GradeRate::springTerms[x]){ // if student grade term id matches spring term id

				for( int y = 0; y < GradeRate::passingGrades.size(); y++){ // Looping through list of passing grades

					if (GradeRate::passingGrades[y] == course.StudentGrades[i].grade){ // Check if student grade matches a passing grade

						// If student passed we increment passingGradesCount
						passingGradesCount = passingGradesCount + 1;

					}					

				}

				break;
			}
		}		

	}

	cout << GradeRate::calculateGradeRate(passingGradesCount, totalGradesCount) << endl;

	return GradeRate::calculateGradeRate(passingGradesCount, totalGradesCount);

}



/**
 * Given a category ("Instructor", "Term", "Course") along with category id or the id of the ("Instructor", "Term", "Course")
 * and a grade, this function will return the percentage/rate that a grade appears in the provided "Instructor", "Term", or "Course"
 * 
 */
string GradeRate::getGradeOccurence(string category, string categoryId, string grade){

	int gradeOccurence = 0;

	StudentGrade studentGrade;
	InstructorTermCourse instructorTermOrCourse;

	if (category == "Instructor"){
		instructorTermOrCourse = GradeRate::Instructors.at(categoryId);
	}
	else if(category == "Term"){
		instructorTermOrCourse = GradeRate::Terms.at(categoryId);
	}else if(category == "Course"){
		instructorTermOrCourse = GradeRate::Courses.at(categoryId);
	}else{
		return "No correct category provided";
	}

	for( int i = 0; i < instructorTermOrCourse.StudentGrades.size(); i++ ){

		studentGrade = instructorTermOrCourse.StudentGrades[i];

		if (studentGrade.grade == grade){
			gradeOccurence = gradeOccurence +1;	
		}

	}


	return to_string(gradeOccurence);

}

/**
 * Given a category ("Instructor", "Term", "Course") along with category id or the id of the ("Instructor", "Term", "Course")
 * this function will return the Number of grades entered for a ("Instructor", "Term", "Course")
 */
int GradeRate::getInstructorTermOrCourseGradesCount(string category, string categoryId){

	InstructorTermCourse instructorTermOrCourse;

	if (category == "Instructor"){

		instructorTermOrCourse = GradeRate::Instructors.at(categoryId);

	}
	else if(category == "Term"){

		instructorTermOrCourse = GradeRate::Terms.at(categoryId);

	}else if(category == "Course"){

		instructorTermOrCourse = GradeRate::Courses.at(categoryId);

	}else{
		return 0;
	}

	return instructorTermOrCourse.StudentGrades.size();

}

/**
 * Given two numbers, this function will return the calculated percentage between a/b as a string
 */
string GradeRate::calculateGradeRate(double a, double b){

	// Return 0 if a or b are 0
	if (a == 0 || b == 0 ){ return "0"; }

	// Gets the grade rate percent
	double gradeRatePercent =  (a / b) * 100;

	// Returns value as string formatted as first two digits with . followed by next two decimals
	// If rate is 100 then it will just be 100.0
	return to_string(gradeRatePercent).substr(0,5);

}