#ifndef READWRITE_H
#define READWRITE_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class ReadWrite{

	public:
		/**
		 * Helper function to print out csv 2D Vector
		 */
		void printVectorCSV( vector<vector<string>> parsedCSV );

		/**
		 * Given a csv file path, this function will return a 2 dimension vector
		 * With the first dimension being a row and the second dimension of array being columns
		 */
		vector<vector<string>> parseCSV(string csv_file_path);

};

#endif