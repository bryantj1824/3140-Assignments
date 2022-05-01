#ifndef INSTRUCTORTERMCOURSE_H
#define INSTRUCTORTERMCOURSE_H

#include "StudentGrade.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Simple struct for Instructor terms and courses
 */
struct InstructorTermCourse{
	string id;
	string type;
	vector< StudentGrade > StudentGrades;

	InstructorTermCourse(){}

	InstructorTermCourse(string id, string type){
		this->id = id;
		this->type = type;
	}

	void addStudentGrade(StudentGrade studentGrade){
		this->StudentGrades.push_back( studentGrade );
	}

};

#endif