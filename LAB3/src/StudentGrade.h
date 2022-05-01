#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H

#include <iostream>

using namespace std;

class StudentGrade{

	public:
		string id;
		string courseNum;
		string instructorID;
		string termID;
		string sectionID;
		string grade;

		StudentGrade();

		StudentGrade(string id, string courseNumber, string instructorId, string termID, string sectionID, string grade = "");

		string trim_grade(string the_grade);

		void updateGrade(string grade);

};

#endif