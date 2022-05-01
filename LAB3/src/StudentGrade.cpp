#include "StudentGrade.h"
#include <iostream>

using namespace std;

StudentGrade::StudentGrade(){}

StudentGrade::StudentGrade(string id, string courseNum, string instructorID, string termID, string sectionID, string grade){
	this->id = id;
	this->courseNum = courseNum;
	this->instructorID = instructorID;
	this->termID = termID;
	this->sectionID = sectionID;

	if (grade.size() > 0){
		this->grade = this->trim_grade(grade);
	}

}

/**
 * Helper functions to remove white space from front and end of string
 */
string StudentGrade::trim_grade(string the_grade){
	auto start = the_grade.begin();

	while (start != the_grade.end() && isspace(*start)) { start++; }

	auto end = the_grade.end();

	do { end--; } 
	while (distance(start, end) > 0 && isspace(*end));

	return string(start, end + 1);
}

void StudentGrade::updateGrade(string grade){
	if (grade.size() > 0){
		this->grade = grade;
	}
}