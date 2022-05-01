#include "GradeRate.h"
#include "ReadWrite.h"
#include "StudentGrade.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

int main(){

	// String variables that will be used/reused throughout program
	string emplID, courseID, instructorID, termID, sectionID, grade, passRate, wRate;

	// Vector of file paths
	vector <string> csv_file_paths = {"./data/1115.csv", "./data/3115.csv", "./data/3130.csv"};

	// A two dimension vector of rows and columns, csv data will be read into this
	vector<vector<string>> parsedCSV;

	// Read Write class that will handle all input / output
	ReadWrite read_and_write;

	// Iterateor to loop through Instructors, Terms and Courses
	map<string, InstructorTermCourse>::iterator it;

	// Will loop through csv_file_paths and parse and record student grades
	for( int x = 0; x < csv_file_paths.size() ; x++ ){

		parsedCSV = read_and_write.parseCSV(csv_file_paths[x]);

		for (int i = 1; i < parsedCSV.size(); i++){ // Loop through parsedCSV rows, first row is the headers so we start at index 1

			// Because we know the order of the csv columns 
			// we assign the string variables in that same order
			// If order changes this should be updated
			emplID = parsedCSV[i][0];
			courseID = parsedCSV[i][1];
			instructorID = parsedCSV[i][2];
			termID = parsedCSV[i][3];
			sectionID = parsedCSV[i][4];
			grade = parsedCSV[i][5];
			GradeRate::recordStudentGrade(emplID, courseID, instructorID, termID, sectionID, grade);

		}

	}		


	// Loops through all Courses
	// Outputs pass rate and w rate for each course
	for (it = GradeRate::Courses.begin(); it != GradeRate::Courses.end(); it++){

		courseID = it->first;

		passRate = GradeRate::getPassRate("Course", courseID);

		cout << "The pass rate for course " << courseID << " is " << passRate << endl;

		wRate = GradeRate::getGradeRate("Course", courseID, "W");

		cout << "The W rate for course " << courseID << " is " << wRate << endl;

	}

	cout << endl;

	// Loops through all Instructors
	// Outputs pass rate and w rate for each instructor 
	for (it = GradeRate::Instructors.begin(); it != GradeRate::Instructors.end(); it++){

		instructorID = it->first;

		passRate = GradeRate::getPassRate("Instructor", instructorID);

		cout << "The pass rate for instructor " << instructorID << " is " << passRate << endl;

		wRate = GradeRate::getGradeRate("Instructor", instructorID, "W");

		cout << "The W rate for instructor " << instructorID << " is " << wRate << endl;

	}

	cout << endl;

	// Loops through all Terms
	// Outputs the spring/fall pass rate for each term
	for (it = GradeRate::Terms.begin(); it != GradeRate::Terms.end(); it++){

		termID = it->first;

		passRate = GradeRate::getPassRate("Term", termID);

		cout << "The pass rate for term " << termID << " is " << passRate << endl;

	}

	cout << endl;

	// Outputs the spring pass rate for each course

	cout << "The pass rate for course 1115 spring term is: " << GradeRate::getSpringPassRateForCourse("1115") << endl;

	cout << "The pass rate for course 3115 spring term is: " << GradeRate::getSpringPassRateForCourse("3115") << endl;

	cout << "The pass rate for course 3115 spring term is: " << GradeRate::getSpringPassRateForCourse("3130") << endl;


	cout << endl;

	// Outputs the fall pass rate for each course

	cout << "The pass rate for course 1115 fall term is: " << GradeRate::getFallPassRateForCourse("1115") << endl;

	cout << "The pass rate for course 3115 fall term is: " << GradeRate::getFallPassRateForCourse("3115") << endl;

	cout << "The pass rate for course 3115 fall term is: " << GradeRate::getFallPassRateForCourse("3130") << endl;


	return 0;
};