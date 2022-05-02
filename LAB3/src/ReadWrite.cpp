#include "ReadWrite.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;
/**
 * Helper function to print out csv 2D Vector
 */
void ReadWrite::printVectorCSV( vector<vector<string>> parsedCSV ){

    printf("TEsting\n");

	for (int i = 0; i < parsedCSV.size(); i++){
    	for (int j = 0; j < parsedCSV[i].size(); j++){
        	cout << parsedCSV[i][j] << " ";
    	}
    	cout << endl;
	}
}

/**
 * Given a csv file path, this function will return a 2 dimension vector
 * With the first dimension being a row and the second dimension of array being columns
 */
vector<vector<string>> ReadWrite::parseCSV(string csv_file_path){

    ifstream data( csv_file_path );
    string line;
    vector<vector<string>> parsedCSV;
    while(getline(data,line)){

        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while(getline(lineStream,cell,',')){
            parsedRow.push_back(cell);
        }

        parsedCSV.push_back(parsedRow);
    }

    return parsedCSV;

};


void ReadWrite::writeToFile(string filename, string output){

    string output_file_path = "./output/";

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    // Formatting File Name
    filename += "(";
    filename += dt;
    filename += ")";
    filename += ".txt";

    output_file_path += filename;

    ofstream file(output_file_path);

    file << output << endl;

    file.close();

}