# Lab 3 Assignment Overview

To create a program that will take various CSV files with the following fields:
- Student ID
- Course Number
- Instructor ID
- Term ID
- Section ID
- Grade

Using those fields the goal is to create an object oriented program that will parse the csv files and create an output file with 

1. Pass rate per instructor
2. Pass rate per course number
3. W rate per instructor
4. W rate per course number
5. Fall pass rate for each course 
6. Fall pass rate for each term
7. Spring pass rate for each course
8. Spring pass rate for each term


# Program Overview

The main goal is to generate the pass and w rates for instructors, courses, and terms.

## GradeRate Class

We can do so by creating a class called GradeRate.

The class GradeRate will have the following static properties:
- Students - a map of Student objects
- Instructors - a map of Instructor objects 
- Courses - a map of Course objects
- Terms - a map of Term Objects

The class GradeRate will have the following methods:
- getGradeRate( String category, String grade )
	- Parameters:
		- category - will decide which of the Instructors, Courses, and Terms we want to get the grade rate for
		- grade - which letter grade are we getting the rate for
	- Function Goal:
		- To retrieve the grade rate for a specific category

- recordStudentGrade(String id, String courseNumber, String instructorId, String termID, String sectionID, String grade = null)
	- Parameters: all parameters will be populated from csv file and will be strings);
	- Function Goal:
		- To add Instructor, Course, and Term to corresponding map if not already added
		- To add the studentGrade object in the correct categories (Instructors, Courses, Terms)

- addInstructor(String id)
	- Parameters: 
		- id - instructors id
	- Function Goal:
		- To create instructor object and add to Instructors map

- addCourse(String id)
	- Parameters: 
		- id - course id
	- Function Goal:
		- To create course object and add to Courses map

- addTerm(String id)
	- Parameters: 
		- id - term id
	- Function Goal:
		- To create term object and add to Term map

## Instructor, Course, and Term Structs
Each Instructor, Course, and Terms Structs will also have the following properties:
- Id - the id of instructor, course, or term
- StudentGrades - a map of StudentGrade Objects

Each Instructor, Course, and Terms Structs will also have the following constructor:
- ClassName(id)
	- Parameters: ID - unique id of class
	- Function Goal: Constructor function to initiate object

## StudentGrade Class
Finally the StudentGrade class will have the following public properties:
- id
- courseNum
- instructorID
- termID
- sectionID
- grade

The StudentGrade will also have the following methods

- StudentGrade(String id, String courseNumber, String instructorId, String termID, String sectionID, String grade = null)
	- Parameters: all parameters will be strings and are pretty self-explanatory
	- Function Goal:
		- Constructor function to "Enroll student"

- updateGrade(string grade)
	- Parameters:
		- grade - letter grade to update students grade
	- Function Goal:
		- Will update student grade

## ReadWrite Class

This class will be responsible for reading and writing to files 