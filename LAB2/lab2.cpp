/**
 * Problem Description: To create a simple calculator program which will
 * recieve the operation from the user, and two numbers to perform the 
 * calculations with
 * 
 * Problem Solving Technique Description:
 * This program has a calculator struct which handles all 5 operations: 
 * (Addition, Subtraction. Multiplication, Division, and Square Root)
 * 
 * The calculator struct has a do_the_math function which will take 3 doubles
 * The first double will specify which operation to do the next two doubles 
 * are the numbers we want to perform the operations on
 * 
 * The main function will handle all of the user logic and use the calculator struct
 * to handle the correct operations
 * 
 */
#include <iostream>
#include <cmath>

using namespace std;

/**
 * calculator struct used to simplify the performance of various calculations
 */
struct calculator{

	enum Operator{addition = 1, subtraction = 2, multiplication = 3, division = 4, square_root = 5};

	/**
	 * This function will perform the requested operation given parameter values
	 * a and b
	 * 
	 * @param operation - double 1 - 5
	 * @param double a - first number for operation
	 * @param double b - second number for operation
	 * 
	 */
	double do_the_math( double operation, double a, double b = 0 ){

		Operator the_operator = (Operator)operation;

		switch (the_operator){
			case addition 			: return add(a,b);
			case subtraction 		: return subtract(a,b);
			case multiplication 	: return multiply(a,b);
			case division 			: return divide(a,b);
			case square_root 		: return sq_rt(a);
			default : 
      			printf("Error, invalid operator.");
      			return 0;
		}

	}

	double add( double a, double b){
		return a + b;
	}

	double subtract( double a, double b){
		return a - b;
	}

	double multiply( double a, double b){
		return a * b;
	}

	double divide( double a, double b){
		if (b == 0){
			printf("\nCan not divide by %.6g\n", b);
			return 0;	
		}

		return a / b;
	}

	double sq_rt(double a){
		return sqrt(a);
	}


};

/**
 * Main Program
 */
int main(){

	// Inititalizing variables

	double a, b, answer, operation;

	calculator the_calculator;

	// Simple introductory message

	printf("\nCalculator Program\n");
	printf("------------------\n");
	printf("This program will continously do math operations, until specified to stop\n");
	printf("To end the program, simply enter 0 when asked to specify the operation.\n");
	printf("\nHere is a list of all integer values for the operations to perform.\n");
	printf("(1 = add, 2 = subtract, 3 = multiply, 4 = divide, 5 = square_root)\n\n");

	// Requesting the first operation to begin with

	printf("Select an Operation: ");

	cin >> operation;

	// Continues to request operation until user enters number 
	// less than 0 when asked to enter operation
	while( operation > 0 ){

		// User entered number from 1-4 (inclusive)
		// This means user wants to perform one of the first 4 operations
		// First four operations require two numbers so we enter the loop
		if (operation < 5 && operation > 0){
			
			printf("\nEnter first number: ");	

			cin >> a;

			// If user entered wrong input, will repeatedly ask user to try again
			// Until user provides correct number
			if (!cin.good()){
				printf("\n Invalid number provided. Try again.\n");	
				cin.clear();
	  			while (cin.get() != '\n') ; // empty loop
				continue;
			}

			printf("\nEnter second number: ");	

			cin >> b;

			// If user entered wrong input, will repeatedly ask user to try again
			// Until user provides correct number
			if (!cin.good()){
				printf("\n Invalid number provided. Try again.\n");	
				cin.clear();
	  			while (cin.get() != '\n') ; // empty loop
				continue;
			}

			answer = the_calculator.do_the_math(operation, a, b);

			printf("\nThe answer is %.6g\n", answer);
		}
		// User requested square root operation
		// Square root operation only requires one number
		else if( operation == 5 ){

			printf("\nEnter a number: ");	

			// If user entered wrong input, will repeatedly ask user to try again
			// Until user provides correct number
			if (!cin.good()){
				printf("\n Invalid number provided. Try again.\n");	
				cin.clear();
	  			while (cin.get() != '\n') ; // empty loop
				continue;
			}

			cin >> a;

			answer = the_calculator.do_the_math(operation, a);

			printf("\nThe answer is %.6g\n", answer);

		}else{ // User entered invalid operator
			printf("\nInvalid Operator! To exit program enter 0.\n");
		}


		printf("\nSelect an Operation (0 to end program): ");

		cin >> operation;

	}


	printf("Thanks for using this calculator program! Goodbye.\n\n");

	return 0;
}